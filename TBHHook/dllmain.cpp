// TBHHook.dll - injected into TaskBarHero.exe (Il2Cpp).
// Phase 1: game speed control via UnityEngine.Time::set_timeScale.
// Communicates with the C# trainer through a named shared-memory block.

#include <windows.h>
#include <cstdint>
#include <cstdio>

// ---- Shared state: MUST match SharedState in the C# trainer byte-for-byte ----
#pragma pack(push, 1)
struct SharedState
{
    int32_t magic;        // 0x00  'TBH1' = 0x31484254
    int32_t heartbeat;    // 0x04  DLL increments each loop so trainer knows it's alive
    int32_t speedEnabled; // 0x08  0/1 - enforce timeScale
    float   timeScale;    // 0x0C  desired multiplier (0..500)
    int32_t applyHp;      // 0x10  trainer bumps this counter to request an HP apply
    float   hpValue;      // 0x14
    int32_t applyAtk;     // 0x18
    float   atkValue;     // 0x1C
    int32_t status;       // 0x20  bit0 = il2cpp ready, bit1 = Time resolved
};
#pragma pack(pop)

static const int32_t  kMagic   = 0x31484254; // "TBH1"

// ---- il2cpp export signatures (only what Phase 1 needs) ----
typedef void* (*il2cpp_domain_get_t)();
typedef void* (*il2cpp_thread_attach_t)(void* domain);
typedef void** (*il2cpp_domain_get_assemblies_t)(void* domain, size_t* size);
typedef void* (*il2cpp_assembly_get_image_t)(void* assembly);
typedef void* (*il2cpp_class_from_name_t)(void* image, const char* ns, const char* name);
typedef void* (*il2cpp_class_get_method_from_name_t)(void* klass, const char* name, int argsCount);
typedef void* (*il2cpp_runtime_invoke_t)(void* method, void* obj, void** params, void** exc);

static il2cpp_domain_get_t                 il2cpp_domain_get;
static il2cpp_thread_attach_t              il2cpp_thread_attach;
static il2cpp_domain_get_assemblies_t      il2cpp_domain_get_assemblies;
static il2cpp_assembly_get_image_t         il2cpp_assembly_get_image;
static il2cpp_class_from_name_t            il2cpp_class_from_name;
static il2cpp_class_get_method_from_name_t il2cpp_class_get_method_from_name;
static il2cpp_runtime_invoke_t             il2cpp_runtime_invoke;

extern "C" __declspec(dllexport) SharedState g_shared = { 0x31484254, 0, 0, 1.0f, 0, 0.0f, 0, 0.0f, 0 };

static void*        g_timeClass = nullptr;
static void*        g_setTimeScale = nullptr;

template <typename T>
static T Resolve(HMODULE m, const char* name)
{
    return reinterpret_cast<T>(GetProcAddress(m, name));
}

static bool LoadIl2Cpp()
{
    HMODULE ga = GetModuleHandleW(L"GameAssembly.dll");
    if (!ga) return false;

    il2cpp_domain_get                 = Resolve<il2cpp_domain_get_t>(ga, "il2cpp_domain_get");
    il2cpp_thread_attach              = Resolve<il2cpp_thread_attach_t>(ga, "il2cpp_thread_attach");
    il2cpp_domain_get_assemblies      = Resolve<il2cpp_domain_get_assemblies_t>(ga, "il2cpp_domain_get_assemblies");
    il2cpp_assembly_get_image         = Resolve<il2cpp_assembly_get_image_t>(ga, "il2cpp_assembly_get_image");
    il2cpp_class_from_name            = Resolve<il2cpp_class_from_name_t>(ga, "il2cpp_class_from_name");
    il2cpp_class_get_method_from_name = Resolve<il2cpp_class_get_method_from_name_t>(ga, "il2cpp_class_get_method_from_name");
    il2cpp_runtime_invoke             = Resolve<il2cpp_runtime_invoke_t>(ga, "il2cpp_runtime_invoke");

    return il2cpp_domain_get && il2cpp_thread_attach && il2cpp_domain_get_assemblies &&
           il2cpp_assembly_get_image && il2cpp_class_from_name &&
           il2cpp_class_get_method_from_name && il2cpp_runtime_invoke;
}

static void* FindClass(void* domain, const char* ns, const char* name)
{
    size_t count = 0;
    void** assemblies = il2cpp_domain_get_assemblies(domain, &count);
    for (size_t i = 0; i < count; ++i)
    {
        void* img = il2cpp_assembly_get_image(assemblies[i]);
        if (!img) continue;
        void* klass = il2cpp_class_from_name(img, ns, name);
        if (klass) return klass;
    }
    return nullptr;
}

static void SetTimeScale(float v)
{
    if (!g_setTimeScale) return;
    void* args[1];
    args[0] = &v;
    void* exc = nullptr;
    il2cpp_runtime_invoke(g_setTimeScale, nullptr, args, &exc);
}

static DWORD WINAPI WorkerThread(LPVOID)
{
    // Wait for il2cpp to be ready (the DLL may load before the runtime is up,
    // though normally we inject after the game is running).
    for (int tries = 0; tries < 200; ++tries)
    {
        if (LoadIl2Cpp()) break;
        Sleep(50);
    }
    if (!il2cpp_domain_get) return 0;

    void* domain = il2cpp_domain_get();
    if (!domain) return 0;
    il2cpp_thread_attach(domain);

    DWORD pid = GetCurrentProcessId();

    // Diagnostic logging
    FILE* fLog = nullptr;
    fopen_s(&fLog, "TBHHook_debug.log", "a");
    if (fLog)
    {
        fprintf(fLog, "[%lu] TBHHook DLL loaded. Using direct memory g_shared bridge.\n", pid);
        fclose(fLog);
    }

    int32_t statusFlags = 1; // il2cpp ready

    g_timeClass = FindClass(domain, "UnityEngine", "Time");
    if (g_timeClass)
    {
        g_setTimeScale = il2cpp_class_get_method_from_name(g_timeClass, "set_timeScale", 1);
        if (g_setTimeScale) statusFlags |= 2;
    }
    else
    {
        fopen_s(&fLog, "TBHHook_debug.log", "a");
        if (fLog) { fprintf(fLog, "[%lu] ERROR: FindClass for UnityEngine.Time failed.\n", pid); fclose(fLog); }
    }
    
    if (!g_setTimeScale)
    {
        fopen_s(&fLog, "TBHHook_debug.log", "a");
        if (fLog) { fprintf(fLog, "[%lu] ERROR: Resolve set_timeScale method failed.\n", pid); fclose(fLog); }
    }
    
    g_shared.status = statusFlags;

    bool wasEnabled = false;
    for (;;)
    {
        g_shared.heartbeat++;

        if (g_shared.speedEnabled)
        {
            float ts = g_shared.timeScale;
            if (ts < 0.0f) ts = 0.0f;
            if (ts > 500.0f) ts = 500.0f;
            SetTimeScale(ts);
            wasEnabled = true;
        }
        else if (wasEnabled)
        {
            SetTimeScale(1.0f); // restore normal speed once on disable
            wasEnabled = false;
        }

        Sleep(16); // ~ once per frame
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, WorkerThread, nullptr, 0, nullptr);
    }
    return TRUE;
}
