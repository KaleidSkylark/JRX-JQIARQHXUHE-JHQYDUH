#pragma warning disable CA1416

namespace TBH_Trainer;

/// <summary>
/// Applies the "forum" cheats by editing GameAssembly.dll on disk while the
/// game is CLOSED. Every write is guarded: the current bytes must match the
/// expected "original" (or "patched") signature before anything is written,
/// so a wrong game version refuses safely instead of corrupting the file.
/// A one-time .denoiser.bak backup lets the user Restore the pristine DLL.
///
/// Offsets below are 1.00.09 FILE offsets (not RVAs). When the game patches,
/// these will move; the byte-match guard makes a stale offset fail loudly
/// rather than wreck the DLL. Phase 2 (Il2CppDumper) upgrades this to AOB.
/// </summary>
internal sealed class StaticPatcher
{
    public enum FeatureState { Unknown, Original, Patched, Mismatch }

    public sealed class Feature
    {
        public required string Name { get; init; }
        public required string Description { get; init; }
        public required long Offset { get; init; }
        public required byte[] Original { get; init; }
        public required byte[] Patched { get; init; }
        public FeatureState State { get; set; } = FeatureState.Unknown;
    }

    // 1.00.09 file offsets + signatures (validated by byte-match before writing).
    public static List<Feature> BuildFeatures() => new()
    {
        new Feature
        {
            Name = "Unlimited Gold",
            Description = "Forces the gold reward to 1,000,000,000 (mov rdx, 0x3B9ACA00).",
            Offset = 0x95C61F,
            Original = new byte[] { 0x80, 0x3D, 0xE0, 0xA4, 0x18, 0x05, 0x00 },
            Patched  = new byte[] { 0x48, 0xC7, 0xC2, 0x00, 0xCA, 0x9A, 0x3B },
        },
        new Feature
        {
            Name = "Crash Protection",
            Description = "Skips a run-once init that crashes alongside Unlimited Gold (jne -> jmp).",
            Offset = 0x95C62F,
            Original = new byte[] { 0x75 },
            Patched  = new byte[] { 0xEB },
        },
        new Feature
        {
            Name = "DLC Unlocker",
            Description = "DLC ownership check early-returns 1/true (mov eax, 1; ret).",
            Offset = 0xB7C350,
            Original = new byte[] { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20 },
            Patched  = new byte[] { 0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3 },
        },
        new Feature
        {
            Name = "Unlock All Pets",
            Description = "Pet ownership check early-returns 1/true (mov eax, 1; ret).",
            Offset = 0x94C540,
            Original = new byte[] { 0x48, 0x89, 0x5C, 0x24, 0x10, 0x57 },
            Patched  = new byte[] { 0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3 },
        },
    };

    public string DllPath { get; }
    public string BackupPath => DllPath + ".denoiser.bak";

    public StaticPatcher(string dllPath) => DllPath = dllPath;

    public bool DllExists => File.Exists(DllPath);
    public bool BackupExists => File.Exists(BackupPath);

    /// <summary>Best-effort auto-detection of the Steam install; null if not found.</summary>
    public static string? AutoDetectDll()
    {
        string[] candidates =
        {
            @"C:\Program Files (x86)\Steam\steamapps\common\TaskbarHero\GameAssembly.dll",
            @"C:\Program Files\Steam\steamapps\common\TaskbarHero\GameAssembly.dll",
        };
        return candidates.FirstOrDefault(File.Exists);
    }

    /// <summary>True if the DLL is locked (e.g. the game is running).</summary>
    public bool IsFileLocked()
    {
        try
        {
            using var fs = new FileStream(DllPath, FileMode.Open, FileAccess.ReadWrite, FileShare.None);
            return false;
        }
        catch (IOException) { return true; }
        catch (UnauthorizedAccessException) { return true; }
    }

    /// <summary>Reads the bytes at each offset and classifies the feature state.</summary>
    public void Refresh(IReadOnlyList<Feature> features)
    {
        using var fs = new FileStream(DllPath, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
        foreach (var f in features)
            f.State = Classify(fs, f);
    }

    private static FeatureState Classify(FileStream fs, Feature f)
    {
        var buf = new byte[Math.Max(f.Original.Length, f.Patched.Length)];
        fs.Seek(f.Offset, SeekOrigin.Begin);
        int read = fs.Read(buf, 0, buf.Length);
        if (read < f.Original.Length) return FeatureState.Mismatch;
        if (buf.AsSpan(0, f.Original.Length).SequenceEqual(f.Original)) return FeatureState.Original;
        if (buf.AsSpan(0, f.Patched.Length).SequenceEqual(f.Patched)) return FeatureState.Patched;
        return FeatureState.Mismatch;
    }

    private void EnsureBackup()
    {
        if (!BackupExists) File.Copy(DllPath, BackupPath);
    }

    public (bool ok, string msg) Apply(Feature f)  => Write(f, applying: true);
    public (bool ok, string msg) Revert(Feature f) => Write(f, applying: false);

    private (bool ok, string msg) Write(Feature f, bool applying)
    {
        if (!DllExists) return (false, "GameAssembly.dll not found.");
        if (IsFileLocked()) return (false, "GameAssembly.dll is in use. Close the game first.");

        byte[] expect = applying ? f.Original : f.Patched;
        byte[] write  = applying ? f.Patched  : f.Original;

        // Read current bytes (shared read) before taking an exclusive handle.
        var cur = new byte[Math.Max(expect.Length, write.Length)];
        using (var rs = new FileStream(DllPath, FileMode.Open, FileAccess.Read, FileShare.Read))
        {
            rs.Seek(f.Offset, SeekOrigin.Begin);
            rs.ReadExactly(cur, 0, cur.Length);
        }

        if (cur.AsSpan(0, write.Length).SequenceEqual(write))
        {
            f.State = applying ? FeatureState.Patched : FeatureState.Original;
            return (true, applying ? "Already applied." : "Already reverted.");
        }
        if (!cur.AsSpan(0, expect.Length).SequenceEqual(expect))
            return (false,
                $"Bytes at 0x{f.Offset:X} don't match expected [{Hex(expect)}] (found [{Hex(cur.AsSpan(0, expect.Length).ToArray())}]). " +
                "Wrong game version? Aborted — file untouched.");

        // Make the safety backup while no exclusive handle is held.
        try { EnsureBackup(); }
        catch (Exception ex) { return (false, $"Could not create backup: {ex.Message}. Aborted."); }

        using (var ws = new FileStream(DllPath, FileMode.Open, FileAccess.ReadWrite, FileShare.None))
        {
            ws.Seek(f.Offset, SeekOrigin.Begin);
            ws.Write(write, 0, write.Length);
            ws.Flush();

            ws.Seek(f.Offset, SeekOrigin.Begin);
            var check = new byte[write.Length];
            ws.ReadExactly(check, 0, check.Length);
            if (!check.SequenceEqual(write))
                return (false, "Write verification failed — read-back did not match.");
        }

        f.State = applying ? FeatureState.Patched : FeatureState.Original;
        return (true, applying ? "Applied." : "Reverted.");
    }

    public (bool ok, string msg) RestoreBackup()
    {
        if (!BackupExists) return (false, "No backup found (.denoiser.bak).");
        if (IsFileLocked()) return (false, "GameAssembly.dll is in use. Close the game first.");
        try
        {
            File.Copy(BackupPath, DllPath, overwrite: true);
            return (true, "Restored GameAssembly.dll from backup.");
        }
        catch (Exception ex) { return (false, $"Restore failed: {ex.Message}"); }
    }

    private static string Hex(byte[] b) => string.Join(" ", b.Select(x => x.ToString("X2")));
}
