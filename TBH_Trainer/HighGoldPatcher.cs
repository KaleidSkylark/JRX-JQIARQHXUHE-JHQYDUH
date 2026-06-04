using System;

namespace TBH_Trainer;

/// <summary>
/// Runtime "High Gold on Kill" feature, mimicking HighExpPatcher.
/// Strategy:
///   1. AOB-scan for mov rdx, [rsi+0x3A0] -> 48 8B 96 A0 03 00 00
///   2. Allocate code cave
///   3. Write code to write chosen gold value (int64) to [rsi+0x3A0]
///   4. Clamping and validation
/// </summary>
internal sealed class HighGoldPatcher
{
    private readonly GameMemory _mem;

    // mov rdx, [rsi+0x3A0]
    private static readonly byte[] AobPattern = { 0x48, 0x8B, 0x96, 0xA0, 0x03, 0x00, 0x00 };

    private const int CaveValOffset = 2;   // index of imm64 inside cave
    private const int CaveSize = 32;

    private IntPtr _siteAddress = IntPtr.Zero;
    private IntPtr _caveAddress = IntPtr.Zero;
    private byte[]? _originalBytes;
    private long _currentValue;

    public HighGoldPatcher(GameMemory mem) => _mem = mem;

    public bool IsEnabled => _siteAddress != IntPtr.Zero;
    public long CurrentValue => _currentValue;

    public (bool ok, string msg) Enable(long goldValue)
    {
        if (!_mem.IsAttached) return (false, "Not attached to game.");
        if (_mem.GameAssemblyBase == IntPtr.Zero) return (false, "GameAssembly.dll not located.");

        if (IsEnabled) return UpdateValue(goldValue);

        // 1. AOB scan
        var hits = _mem.ScanGameAssemblyForPattern(AobPattern, maxHits: 4);
        if (hits.Count == 0)
            return (false, "Gold AOB pattern not found in GameAssembly.dll.");
        if (hits.Count > 1)
            return (false, "Gold AOB pattern matched multiple times.");

        IntPtr site = hits[0];

        // 2. Verify bytes
        var original = _mem.ReadBytes(site, 7);
        if (original.Length != 7)
            return (false, "Could not read original site bytes.");
        if (!System.MemoryExtensions.SequenceEqual(original, AobPattern))
            return (false, "Site bytes mismatch.");

        // 3. Allocate cave
        IntPtr cave = _mem.AllocateNear(site, CaveSize);
        if (cave == IntPtr.Zero)
            return (false, "Could not allocate code cave.");

        // 4. Build cave
        byte[] caveBytes = BuildCave(site, cave, goldValue);
        if (!_mem.WriteBytes(cave, caveBytes))
        {
            _mem.FreeRemote(cave);
            return (false, "Failed to write cave.");
        }

        // 5. Patch site (7 bytes: JMP rel32 + 2 NOPs)
        byte[] sitePatch = BuildSitePatch(site, cave);
        if (!_mem.WriteBytes(site, sitePatch))
        {
            _mem.FreeRemote(cave);
            return (false, "Failed to patch site.");
        }

        // Verify
        var readback = _mem.ReadBytes(site, 7);
        if (readback.Length != 7 || !System.MemoryExtensions.SequenceEqual(readback, sitePatch))
        {
            _mem.WriteBytes(site, original);
            _mem.FreeRemote(cave);
            return (false, "Patch verification failed.");
        }

        _siteAddress = site;
        _caveAddress = cave;
        _originalBytes = original;
        _currentValue = goldValue;

        return (true, $"High Gold ENABLED at {goldValue:N0} Gold/kill.");
    }

    public (bool ok, string msg) UpdateValue(long goldValue)
    {
        if (!IsEnabled) return (false, "High Gold is not enabled.");
        byte[] valBytes = BitConverter.GetBytes(goldValue);
        if (!_mem.WriteBytes(_caveAddress + CaveValOffset, valBytes))
            return (false, "Could not update cave value.");
        _currentValue = goldValue;
        return (true, $"High Gold updated to {goldValue:N0}.");
    }

    public (bool ok, string msg) Disable()
    {
        if (!IsEnabled) return (true, "Already disabled.");
        if (_originalBytes == null) return (false, "Original bytes missing.");

        if (!_mem.WriteBytes(_siteAddress, _originalBytes))
            return (false, "Could not restore original bytes.");

        _mem.FreeRemote(_caveAddress);
        _siteAddress = IntPtr.Zero;
        _caveAddress = IntPtr.Zero;
        _originalBytes = null;
        return (true, "High Gold DISABLED.");
    }

    public void ResetWithoutRestore()
    {
        _siteAddress = IntPtr.Zero;
        _caveAddress = IntPtr.Zero;
        _originalBytes = null;
        _currentValue = 0;
    }

    private static byte[] BuildCave(IntPtr site, IntPtr cave, long value)
    {
        // Cave structure (29 bytes):
        // 48 B9 <8 bytes value>       ; mov rcx, value
        // 48 89 8E A0 03 00 00        ; mov [rsi+0x3A0], rcx
        // 48 8B 96 A0 03 00 00        ; mov rdx, [rsi+0x3A0]
        // E9 <4 bytes rel32>          ; jmp site+7
        var buf = new byte[29];
        int p = 0;

        buf[p++] = 0x48; buf[p++] = 0xB9;
        byte[] valBytes = BitConverter.GetBytes(value);
        Array.Copy(valBytes, 0, buf, p, 8);
        p += 8;

        buf[p++] = 0x48; buf[p++] = 0x89; buf[p++] = 0x8E;
        buf[p++] = 0xA0; buf[p++] = 0x03; buf[p++] = 0x00; buf[p++] = 0x00;

        buf[p++] = 0x48; buf[p++] = 0x8B; buf[p++] = 0x96;
        buf[p++] = 0xA0; buf[p++] = 0x03; buf[p++] = 0x00; buf[p++] = 0x00;

        long jmpFrom = cave.ToInt64() + p + 5;
        long jmpTo = site.ToInt64() + 7;
        int rel32 = checked((int)(jmpTo - jmpFrom));
        buf[p++] = 0xE9;
        buf[p++] = (byte)(rel32);
        buf[p++] = (byte)(rel32 >> 8);
        buf[p++] = (byte)(rel32 >> 16);
        buf[p++] = (byte)(rel32 >> 24);

        return buf;
    }

    private static byte[] BuildSitePatch(IntPtr site, IntPtr cave)
    {
        var buf = new byte[7];
        long jmpFrom = site.ToInt64() + 5;
        long jmpTo = cave.ToInt64();
        int rel32 = checked((int)(jmpTo - jmpFrom));
        buf[0] = 0xE9;
        buf[1] = (byte)(rel32);
        buf[2] = (byte)(rel32 >> 8);
        buf[3] = (byte)(rel32 >> 16);
        buf[4] = (byte)(rel32 >> 24);
        buf[5] = 0x90; buf[6] = 0x90;
        return buf;
    }
}
