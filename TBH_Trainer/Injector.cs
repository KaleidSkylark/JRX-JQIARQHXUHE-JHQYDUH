using System.Text;

namespace TBH_Trainer;

internal static class Injector
{
    /// <summary>
    /// Loads a DLL into the target process via VirtualAllocEx + CreateRemoteThread(LoadLibraryW).
    /// Idempotent: LoadLibraryW on an already-loaded DLL just bumps the refcount and
    /// does NOT re-run DllMain, so calling this twice will not spawn a second worker.
    /// </summary>
    public static (bool ok, string message) Inject(int pid, string dllPath)
    {
        if (!File.Exists(dllPath))
            return (false, $"DLL not found: {dllPath}");

        IntPtr hProc = NativeApi.OpenProcess(NativeApi.PROCESS_ALL_ACCESS, false, pid);
        if (hProc == IntPtr.Zero)
            return (false, "OpenProcess failed (run trainer as Administrator?).");

        IntPtr remote = IntPtr.Zero;
        try
        {
            byte[] pathBytes = Encoding.Unicode.GetBytes(dllPath + "\0");
            remote = NativeApi.VirtualAllocEx(hProc, IntPtr.Zero, pathBytes.Length,
                NativeApi.MEM_COMMIT | NativeApi.MEM_RESERVE, NativeApi.PAGE_READWRITE);
            if (remote == IntPtr.Zero)
                return (false, "VirtualAllocEx failed.");

            if (!NativeApi.WriteProcessMemory(hProc, remote, pathBytes, pathBytes.Length, out _))
                return (false, "WriteProcessMemory failed.");

            IntPtr hKernel = NativeApi.GetModuleHandleW("kernel32.dll");
            IntPtr loadLib = NativeApi.GetProcAddress(hKernel, "LoadLibraryW");
            if (loadLib == IntPtr.Zero)
                return (false, "GetProcAddress(LoadLibraryW) failed.");

            // kernel32 sits at the same base in every process this boot, so loadLib is valid remotely.
            IntPtr hThread = NativeApi.CreateRemoteThread(hProc, IntPtr.Zero, 0, loadLib, remote, 0, out _);
            if (hThread == IntPtr.Zero)
                return (false, "CreateRemoteThread failed.");

            NativeApi.WaitForSingleObject(hThread, 5000);
            
            // Check thread exit code (LoadLibraryW returns the loaded DLL base address, or NULL/0 on failure)
            IntPtr exitCode = IntPtr.Zero;
            string loadError = "";
            if (NativeApi.GetExitCodeThread(hThread, out exitCode))
            {
                if (exitCode == IntPtr.Zero)
                {
                    loadError = "LoadLibraryW returned NULL inside the game process (antivirus block or missing runtime dependencies?).";
                }
            }
            NativeApi.CloseHandle(hThread);
            
            if (!string.IsNullOrEmpty(loadError))
            {
                return (false, loadError);
            }
            return (true, "DLL injected.");
        }
        finally
        {
            if (remote != IntPtr.Zero)
                NativeApi.VirtualFreeEx(hProc, remote, 0, NativeApi.MEM_RELEASE);
            NativeApi.CloseHandle(hProc);
        }
    }
}
