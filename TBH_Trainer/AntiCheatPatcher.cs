namespace TBH_Trainer;

internal sealed class AntiCheatPatcher
{
    private readonly GameMemory _mem;
    private readonly Dictionary<IntPtr, byte[]> _originalBytes = new();

    public AntiCheatPatcher(GameMemory mem) => _mem = mem;

    /// <summary>
    /// A detector entry we neutralize: its name, expected RVA (used as primary
    /// fast lookup), and the function prologue signature. When the RVA matches
    /// the signature, we patch instantly. When the RVA is stale (wrong game
    /// version), we fall back to a full AOB scan of GameAssembly.dll to find
    /// the function dynamically. The 6-byte signatures stop before any
    /// RIP-relative displacement, so they stay stable across micro-rebuilds.
    /// </summary>
    private readonly record struct Target(string Name, int Rva, byte[] Signature);

    private static readonly Target[] Targets =
    {
        new("ObscuredCheatingDetector.Check",       GameOffsets.ObscuredCheatingDetector_Check,      new byte[] { 0x41, 0x56, 0x48, 0x83, 0xEC, 0x20 }),
        new("ObscuredCheatingDetector.Compare",     GameOffsets.ObscuredCheatingDetector_Compare,    new byte[] { 0x48, 0x89, 0x5C, 0x24, 0x10, 0x48 }),
        new("ObscuredCheatingDetector.CompareExt",  GameOffsets.ObscuredCheatingDetector_CompareExt, new byte[] { 0x48, 0x89, 0x5C, 0x24, 0x10, 0x48 }),
        new("InjectionDetector.Check",              GameOffsets.InjectionDetector_Check,             new byte[] { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20 }),
        new("SpeedHackDetector.Update",             GameOffsets.SpeedHackDetector_Update,            new byte[] { 0x40, 0x56, 0x48, 0x83, 0xEC, 0x70 }),
        new("SpeedHackDetector.OnApplicationPause", GameOffsets.SpeedHackDetector_OnAppPause,        new byte[] { 0x48, 0x89, 0x5C, 0x24, 0x08, 0x57 }),
    };

    /// <summary>
    /// Patches every ACTk detector entry to RET immediately. Uses a two-phase
    /// lookup: first tries the hardcoded RVA (fast); if the signature there
    /// doesn't match, falls back to AOB scanning the entire GameAssembly.dll
    /// to find the function dynamically. Returns a per-detector report.
    /// </summary>
    public List<(string name, bool ok, string detail)> PatchDetectors()
    {
        var report = new List<(string, bool, string)>();
        if (!_mem.IsAttached || _mem.GameAssemblyBase == IntPtr.Zero)
        {
            report.Add(("Not connected", false, "Attach to the game first."));
            return report;
        }

        foreach (var t in Targets)
        {
            var (ok, detail) = PatchWithFallback(t);
            report.Add((t.Name, ok, detail));
        }
        return report;
    }

    public bool RestoreDetectors()
    {
        bool allOk = true;
        foreach (var (addr, original) in _originalBytes)
            allOk &= _mem.WriteBytes(addr, original);
        _originalBytes.Clear();
        return allOk;
    }

    /// <summary>
    /// Phase 1: Try the hardcoded RVA. If the prologue matches, patch directly.
    /// Phase 2: If the RVA is stale, AOB-scan for the prologue in the DLL.
    /// </summary>
    private (bool ok, string detail) PatchWithFallback(Target t)
    {
        IntPtr rvaAddr = _mem.GameAssemblyBase + t.Rva;

        // --- Phase 1: Fast RVA-based lookup ---
        byte[] cur = _mem.ReadBytes(rvaAddr, t.Signature.Length);
        if (cur.Length == t.Signature.Length)
        {
            // Already patched at known RVA?
            if (cur[0] == 0xC3)
                return (true, "Already patched (RVA match).");

            // Signature matches at known RVA? Patch directly.
            if (cur.AsSpan().SequenceEqual(t.Signature))
                return WritePatch(rvaAddr, cur, t, "(RVA match)");
        }

        // --- Phase 2: AOB fallback scan ---
        var hits = _mem.ScanGameAssemblyForPattern(t.Signature, maxHits: 64);

        if (hits.Count == 0)
            return (false, $"Signature not found at RVA 0x{t.Rva:X} and AOB scan found 0 matches — wrong game version?");

        if (hits.Count == 1)
        {
            // Unique match — use it
            IntPtr addr = hits[0];
            byte[] live = _mem.ReadBytes(addr, t.Signature.Length);
            if (live.Length == t.Signature.Length && live[0] == 0xC3)
                return (true, "Already patched (AOB match).");
            return WritePatch(addr, live, t, $"(AOB scan, found at 0x{(addr.ToInt64() - _mem.GameAssemblyBase.ToInt64()):X})");
        }

        // Multiple matches — pick the one closest to the expected RVA as a hint
        IntPtr best = PickClosest(hits, rvaAddr);

        // Check if the best candidate is already patched
        byte[] bestBytes = _mem.ReadBytes(best, t.Signature.Length);
        if (bestBytes.Length == t.Signature.Length && bestBytes[0] == 0xC3)
            return (true, $"Already patched (AOB best of {hits.Count} matches).");

        return WritePatch(best, bestBytes, t, $"(AOB scan, best of {hits.Count} matches at 0x{(best.ToInt64() - _mem.GameAssemblyBase.ToInt64()):X})");
    }

    /// <summary>
    /// From multiple AOB hits, picks the one closest to the expected RVA address.
    /// This disambiguates common prologues like "mov [rsp+10h], rbx".
    /// </summary>
    private static IntPtr PickClosest(List<IntPtr> hits, IntPtr expected)
    {
        IntPtr best = hits[0];
        long bestDist = Math.Abs(best.ToInt64() - expected.ToInt64());
        for (int i = 1; i < hits.Count; i++)
        {
            long dist = Math.Abs(hits[i].ToInt64() - expected.ToInt64());
            if (dist < bestDist)
            {
                best = hits[i];
                bestDist = dist;
            }
        }
        return best;
    }

    /// <summary>
    /// Writes 0xC3 (RET) at the resolved address and reads it back to verify.
    /// </summary>
    private (bool ok, string detail) WritePatch(IntPtr addr, byte[] currentBytes, Target t, string source)
    {
        if (!_originalBytes.ContainsKey(addr))
            _originalBytes[addr] = new[] { currentBytes[0] };

        _mem.WriteBytes(addr, new byte[] { 0xC3 });

        byte[] check = _mem.ReadBytes(addr, 1);
        if (check.Length == 1 && check[0] == 0xC3)
            return (true, $"RET written (verified) {source}.");
        return (false, $"Write verification failed {source}.");
    }

    private static string Hex(byte[] b) => string.Join(" ", b.Select(x => x.ToString("X2")));
}
