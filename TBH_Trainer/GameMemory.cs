using System.Diagnostics;
using SysMarshal = System.Runtime.InteropServices.Marshal;

namespace TBH_Trainer;

internal sealed class GameMemory : IDisposable
{
    private IntPtr _handle;
    private Process? _process;

    public bool IsAttached => _handle != IntPtr.Zero && _process is { HasExited: false };
    public IntPtr GameAssemblyBase { get; private set; }
    public int GameAssemblySize { get; private set; }
    public string? ProcessName => _process?.ProcessName;

    public bool Attach()
    {
        Detach();

        foreach (var name in new[] { "Taskbar Hero", "TaskbarHero", "TBH" })
        {
            var procs = Process.GetProcessesByName(name);
            if (procs.Length > 0)
            {
                _process = procs[0];
                break;
            }
        }

        if (_process == null)
        {
            var all = Process.GetProcesses();
            foreach (var p in all)
            {
                try
                {
                    foreach (ProcessModule m in p.Modules)
                    {
                        if (m.ModuleName.Equals("GameAssembly.dll", StringComparison.OrdinalIgnoreCase))
                        {
                            _process = p;
                            break;
                        }
                    }
                }
                catch { }
                if (_process != null) break;
            }
        }

        if (_process == null) return false;

        return OpenAndLocate(_process);
    }

    /// <summary>Attach to a specific process chosen manually by the user (PID).</summary>
    public bool AttachToPid(int pid)
    {
        Detach();
        try { _process = Process.GetProcessById(pid); }
        catch { return false; }
        return OpenAndLocate(_process);
    }

    private bool OpenAndLocate(Process proc)
    {
        _handle = NativeApi.OpenProcess(NativeApi.PROCESS_ALL_ACCESS, false, proc.Id);
        if (_handle == IntPtr.Zero) return false;

        try
        {
            foreach (ProcessModule m in proc.Modules)
            {
                if (m.ModuleName.Equals("GameAssembly.dll", StringComparison.OrdinalIgnoreCase))
                {
                    GameAssemblyBase = m.BaseAddress;
                    GameAssemblySize = m.ModuleMemorySize;
                    break;
                }
            }
        }
        catch { }

        // Still attached even without GameAssembly.dll, but the trainer needs it for patches.
        return GameAssemblyBase != IntPtr.Zero;
    }

    public sealed record ProcessEntry(int Pid, string Name, string Title, bool HasGameAssembly);

    /// <summary>Lists visible-window processes for the manual picker (like CE's "Open Process").</summary>
    public static List<ProcessEntry> ListProcesses()
    {
        var list = new List<ProcessEntry>();
        var processes = Process.GetProcesses();
        foreach (var p in processes)
        {
            try
            {
                // Quick filter: Skip windowless system services immediately!
                // Most games will have a MainWindowHandle or at least match the target name.
                bool isCandidate = p.MainWindowHandle != IntPtr.Zero || 
                                   p.ProcessName.Contains("Taskbar", StringComparison.OrdinalIgnoreCase) ||
                                   p.ProcessName.Contains("TBH", StringComparison.OrdinalIgnoreCase) ||
                                   p.ProcessName.Contains("Hero", StringComparison.OrdinalIgnoreCase);

                if (!isCandidate) continue;

                bool hasGA = false;
                try
                {
                    foreach (ProcessModule m in p.Modules)
                    {
                        if (m.ModuleName.Equals("GameAssembly.dll", StringComparison.OrdinalIgnoreCase))
                        {
                            hasGA = true;
                            break;
                        }
                    }
                }
                catch { }

                list.Add(new ProcessEntry(p.Id, p.ProcessName, p.MainWindowTitle ?? "", hasGA));
            }
            catch { }
        }
        // Games with GameAssembly.dll float to the top.
        return list.OrderByDescending(e => e.HasGameAssembly).ThenBy(e => e.Name, StringComparer.OrdinalIgnoreCase).ToList();
    }

    public void Detach()
    {
        if (_handle != IntPtr.Zero)
        {
            NativeApi.CloseHandle(_handle);
            _handle = IntPtr.Zero;
        }
        _process = null;
        GameAssemblyBase = IntPtr.Zero;
        GameAssemblySize = 0;
    }

    public byte[] ReadBytes(IntPtr address, int size)
    {
        var buf = new byte[size];
        NativeApi.ReadProcessMemory(_handle, address, buf, size, out _);
        return buf;
    }

    public bool WriteBytes(IntPtr address, byte[] data)
    {
        NativeApi.VirtualProtectEx(_handle, address, data.Length, NativeApi.PAGE_EXECUTE_READWRITE, out uint old);
        bool ok = NativeApi.WriteProcessMemory(_handle, address, data, data.Length, out _);
        NativeApi.VirtualProtectEx(_handle, address, data.Length, old, out _);
        return ok;
    }

    public int ReadInt32(IntPtr address)
    {
        var buf = ReadBytes(address, 4);
        return BitConverter.ToInt32(buf, 0);
    }

    public long ReadInt64(IntPtr address)
    {
        var buf = ReadBytes(address, 8);
        return BitConverter.ToInt64(buf, 0);
    }

    public float ReadFloat(IntPtr address)
    {
        var buf = ReadBytes(address, 4);
        return BitConverter.ToSingle(buf, 0);
    }

    public void WriteInt32(IntPtr address, int value)
    {
        WriteBytes(address, BitConverter.GetBytes(value));
    }

    public void WriteInt64(IntPtr address, long value)
    {
        WriteBytes(address, BitConverter.GetBytes(value));
    }

    public void WriteFloat(IntPtr address, float value)
    {
        WriteBytes(address, BitConverter.GetBytes(value));
    }

    private const uint PAGE_READABLE = 0x02 | 0x04 | 0x08 | 0x20 | 0x40 | 0x80; // all readable protections

    /// <summary>
    /// Scans the loaded GameAssembly.dll module memory range for a byte pattern.
    /// Returns all match addresses. Used for AOB-based runtime patches that need
    /// a unique site inside the game DLL.
    /// </summary>
    public List<IntPtr> ScanGameAssemblyForPattern(byte[] pattern, int maxHits = 8)
    {
        var hits = new List<IntPtr>();
        if (!IsAttached || GameAssemblyBase == IntPtr.Zero || GameAssemblySize <= 0)
            return hits;
        if (pattern == null || pattern.Length == 0) return hits;

        const int chunk = 1 * 1024 * 1024; // 1 MB chunks with overlap
        int overlap = pattern.Length - 1;
        var buf = new byte[chunk + overlap];

        long total = GameAssemblySize;
        for (long offset = 0; offset < total; offset += chunk)
        {
            int wanted = (int)Math.Min(chunk + overlap, total - offset);
            if (wanted < pattern.Length) break;

            if (!NativeApi.ReadProcessMemory(_handle, GameAssemblyBase + (int)offset, buf, wanted, out int read))
                continue;
            if (read < pattern.Length) continue;

            int limit = read - pattern.Length;
            for (int i = 0; i <= limit; i++)
            {
                bool match = true;
                for (int j = 0; j < pattern.Length; j++)
                {
                    if (buf[i + j] != pattern[j]) { match = false; break; }
                }
                if (match)
                {
                    var hit = GameAssemblyBase + (int)(offset + i);
                    if (!hits.Contains(hit))
                    {
                        hits.Add(hit);
                        if (hits.Count >= maxHits) return hits;
                    }
                }
            }
        }
        return hits;
    }

    /// <summary>
    /// Allocates RWX memory in the target process inside the ±2 GB window of
    /// <paramref name="hint"/>, so a 5-byte rel32 JMP can reach it. Walks the
    /// hint in 64 KB steps both above and below until VirtualAllocEx succeeds.
    /// Returns IntPtr.Zero if no nearby slot is available.
    /// </summary>
    public IntPtr AllocateNear(IntPtr hint, int size)
    {
        if (!IsAttached) return IntPtr.Zero;

        const long step = 0x10000;                 // 64 KB allocation granularity
        const long maxDistance = 0x40000000;       // 1 GB, well within rel32 range

        long hintAddr = hint.ToInt64();

        // Start close to the hint and walk outward in both directions.
        for (long delta = step; delta < maxDistance; delta += step)
        {
            foreach (long candidate in new[] { hintAddr - delta, hintAddr + delta })
            {
                if (candidate <= 0x10000 || candidate >= 0x7FFFFFFE0000) continue;

                IntPtr p = NativeApi.VirtualAllocEx(_handle, new IntPtr(candidate), size,
                    NativeApi.MEM_RESERVE | NativeApi.MEM_COMMIT, NativeApi.PAGE_EXECUTE_READWRITE);
                if (p != IntPtr.Zero)
                {
                    long distance = Math.Abs(p.ToInt64() - hintAddr);
                    if (distance < 0x7FFF0000) return p; // safe rel32 distance
                    NativeApi.VirtualFreeEx(_handle, p, 0, NativeApi.MEM_RELEASE);
                }
            }
        }
        return IntPtr.Zero;
    }

    /// <summary>Frees memory previously allocated via <see cref="AllocateNear"/>.</summary>
    public bool FreeRemote(IntPtr address)
    {
        if (!IsAttached || address == IntPtr.Zero) return false;
        return NativeApi.VirtualFreeEx(_handle, address, 0, NativeApi.MEM_RELEASE);
    }

    public List<IntPtr> ScanRegions(Func<byte[], int, bool> matcher, int matchSize)
    {
        var results = new List<IntPtr>();
        IntPtr addr = IntPtr.Zero;
        long maxAddr = 0x7FFFFFFFFFFF;

        while (addr.ToInt64() < maxAddr)
        {
            int ret = NativeApi.VirtualQueryEx(_handle, addr, out var mbi, SysMarshal.SizeOf<NativeApi.MEMORY_BASIC_INFORMATION>());
            if (ret == 0) break;

            long regionSize = mbi.RegionSize.ToInt64();

            if (mbi.State == NativeApi.MEM_COMMIT &&
                (mbi.Protect & PAGE_READABLE) != 0 &&
                (mbi.Protect & 0x100) == 0 && // skip PAGE_GUARD
                regionSize > 0 &&
                regionSize <= 512 * 1024 * 1024)
            {
                int size = (int)regionSize;
                var buf = new byte[size];
                if (NativeApi.ReadProcessMemory(_handle, mbi.BaseAddress, buf, size, out int read) && read > matchSize)
                {
                    for (int i = 0; i <= read - matchSize; i += 4)
                    {
                        if (matcher(buf, i))
                        {
                            results.Add(mbi.BaseAddress + i);
                            if (results.Count > 10000) return results;
                        }
                    }
                }
            }

            long next = mbi.BaseAddress.ToInt64() + regionSize;
            if (next <= addr.ToInt64()) break;
            addr = new IntPtr(next);
        }

        return results;
    }

    public IntPtr GetModuleBase(string moduleName)
    {
        if (_process == null || _process.HasExited) return IntPtr.Zero;
        try
        {
            _process.Refresh();
            foreach (ProcessModule m in _process.Modules)
            {
                if (m.ModuleName.Equals(moduleName, StringComparison.OrdinalIgnoreCase))
                {
                    return m.BaseAddress;
                }
            }
        }
        catch { }
        return IntPtr.Zero;
    }

    public void BringToFront()
    {
        if (_process == null || _process.HasExited) return;
        try
        {
            _process.Refresh();
            IntPtr hwnd = _process.MainWindowHandle;
            if (hwnd != IntPtr.Zero)
            {
                NativeApi.ShowWindow(hwnd, 9); // SW_RESTORE = 9
                NativeApi.SetForegroundWindow(hwnd);
            }
        }
        catch { }
    }

    public void Dispose() => Detach();
}
