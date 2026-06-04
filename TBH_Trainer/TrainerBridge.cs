using System;
using System.IO;
using System.Threading;

namespace TBH_Trainer;

/// <summary>
/// Direct-memory channel to the injected TBHHook.dll using remote process memory.
/// Layout MUST match the SharedState struct in dllmain.cpp (pack=1, 36 bytes).
/// </summary>
internal sealed class TrainerBridge : IDisposable
{
    private const int Magic = 0x31484254; // "TBH1"
    private const int MapSize = 36;

    // Field byte offsets (must match dllmain.cpp).
    private const int OffMagic = 0;
    private const int OffHeartbeat = 4;
    private const int OffSpeedEnabled = 8;
    private const int OffTimeScale = 12;
    private const int OffApplyHp = 16;
    private const int OffHpValue = 20;
    private const int OffApplyAtk = 24;
    private const int OffAtkValue = 28;
    private const int OffStatus = 32;

    private GameMemory? _mem;
    private IntPtr _remoteSharedAddr = IntPtr.Zero;

    public bool IsConnected => _remoteSharedAddr != IntPtr.Zero;

    /// <summary>Finds the exported g_shared state in the remote process.</summary>
    public bool Connect(GameMemory mem, int pid, int timeoutMs = 3000)
    {
        _mem = mem;
        var deadline = DateTime.UtcNow.AddMilliseconds(timeoutMs);
        while (DateTime.UtcNow < deadline)
        {
            IntPtr remoteDllBase = mem.GetModuleBase("TBHHook.dll");
            if (remoteDllBase != IntPtr.Zero)
            {
                string dllPath = Path.Combine(AppContext.BaseDirectory, "TBHHook.dll");
                if (File.Exists(dllPath))
                {
                    IntPtr hLocal = NativeApi.LoadLibraryExW(dllPath, IntPtr.Zero, NativeApi.DONT_RESOLVE_DLL_REFERENCES);
                    if (hLocal != IntPtr.Zero)
                    {
                        IntPtr localSharedAddr = NativeApi.GetProcAddress(hLocal, "g_shared");
                        if (localSharedAddr != IntPtr.Zero)
                        {
                            long offset = localSharedAddr.ToInt64() - hLocal.ToInt64();
                            _remoteSharedAddr = new IntPtr(remoteDllBase.ToInt64() + offset);
                            
                            // Check magic
                            int magic = _mem.ReadInt32(_remoteSharedAddr + OffMagic);
                            if (magic == Magic)
                            {
                                NativeApi.FreeLibrary(hLocal);
                                return true;
                            }
                        }
                        NativeApi.FreeLibrary(hLocal);
                    }
                }
            }
            Thread.Sleep(100);
        }
        _remoteSharedAddr = IntPtr.Zero;
        return false;
    }

    public int Heartbeat => _remoteSharedAddr != IntPtr.Zero ? _mem!.ReadInt32(_remoteSharedAddr + OffHeartbeat) : -1;
    public int Status => _remoteSharedAddr != IntPtr.Zero ? _mem!.ReadInt32(_remoteSharedAddr + OffStatus) : 0;
    public bool Il2CppReady => (Status & 1) != 0;
    public bool TimeResolved => (Status & 2) != 0;

    public void SetSpeed(bool enabled, float timeScale)
    {
        if (_remoteSharedAddr == IntPtr.Zero || _mem == null) return;
        _mem.WriteFloat(_remoteSharedAddr + OffTimeScale, timeScale);
        _mem.WriteInt32(_remoteSharedAddr + OffSpeedEnabled, enabled ? 1 : 0);
    }

    /// <summary>True if the DLL's heartbeat advanced within the wait window (DLL alive).</summary>
    public bool WaitHeartbeat(int waitMs = 500)
    {
        if (_remoteSharedAddr == IntPtr.Zero || _mem == null) return false;
        int start = Heartbeat;
        var deadline = DateTime.UtcNow.AddMilliseconds(waitMs);
        while (DateTime.UtcNow < deadline)
        {
            if (Heartbeat != start) return true;
            Thread.Sleep(30);
        }
        return false;
    }

    public void Dispose()
    {
        _remoteSharedAddr = IntPtr.Zero;
        _mem = null;
    }
}
