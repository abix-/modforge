// Better Backpack DLL: live data-side + visible-side patch for the Grounded 2
// player main backpack. Diagnostic dump on first scan; re-patch every 10s.
//
// Goals:
//   1. Allocate a console + a log file the moment we attach.
//   2. Wait for the engine to populate UObject::GObjects.
//   3. Walk every loaded UInventoryComponent (CDOs and live instances) and
//      dump its DefaultMaxSize. This is what the pak override changes.
//   4. Bump DefaultMaxSize from 40 -> kSlotCount on every component that still
//      reads vanilla 40. Leave 30 (mount/saddlebag) alone. This is the runtime
//      equivalent of the Better Backpack pak override.
//   5. Loop forever re-scanning every 10s. If a component's DefaultMaxSize
//      reverts to 40 (engine reset, replication, hot reload of a Blueprint),
//      we re-patch and log it.
//
// Property offset of interest (from SDK header Maine_classes.hpp:29557):
//   class UInventoryComponent final : public UActorComponent {
//       int32 DefaultMaxSize;   // offset 0x01E0
//   };
//
// We deliberately do NOT include Maine_classes.hpp / Engine_classes.hpp here.
// Those pull in ~290k lines of SDK function bodies and balloon compile times.
// Instead we do a runtime FindClassFast("InventoryComponent") and treat the
// matched UObject as bytes, reading/writing at the known offset.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include <atomic>
#include <chrono>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <thread>
#include <vector>

#include "SDK/Basic.hpp"
#include "SDK/CoreUObject_structs.hpp"
#include "SDK/CoreUObject_classes.hpp"

namespace BBD {

// ---- minimal FString-returning UFunction caller --------------------------
//
// UBlueprintPathsLibrary::ProjectLogDir / SavedDir / ModsDir are Native,
// Static, BlueprintCallable, BlueprintPure functions on a
// UBlueprintFunctionLibrary. Their full SDK call site lives in
// Engine_functions.cpp which we skip for compile time. We replicate the call
// here using only CoreUObject reflection.
//
// Layout for the parameter struct: a single FString return value.

struct FStringReturnParms {
    SDK::FString ReturnValue;
};

static SDK::FString CallStaticFStringGetter(const char* className,
                                            const char* funcName) {
    SDK::UClass* libClass = SDK::UObject::FindClassFast(className);
    if (!libClass) return SDK::FString{};
    SDK::UObject* cdo = libClass->ClassDefaultObject;
    if (!cdo) return SDK::FString{};
    SDK::UFunction* func = libClass->GetFunction(className, funcName);
    if (!func) return SDK::FString{};

    FStringReturnParms parms{};
    auto savedFlags = func->FunctionFlags;
    func->FunctionFlags |= 0x400; // FUNC_Native, mirrors what Dumper-7 does
    cdo->ProcessEvent(func, &parms);
    func->FunctionFlags = savedFlags;
    return parms.ReturnValue;
}

static std::string FStringToUtf8(const SDK::FString& fs) {
    const wchar_t* w = fs.CStr();
    if (!w) return {};
    int wlen = lstrlenW(w);
    if (wlen == 0) return {};
    int blen = WideCharToMultiByte(CP_UTF8, 0, w, wlen, nullptr, 0, nullptr, nullptr);
    if (blen <= 0) return {};
    std::string out(static_cast<size_t>(blen), 0);
    WideCharToMultiByte(CP_UTF8, 0, w, wlen, out.data(), blen, nullptr, nullptr);
    return out;
}

// ---- configuration --------------------------------------------------------

constexpr int32_t kSlotCount     = 60;          // target main-backpack DefaultMaxSize
constexpr int32_t kVanillaMain   = 40;          // vanilla main-backpack DefaultMaxSize
constexpr int32_t kVanillaMount  = 30;          // vanilla mount/saddlebag (NEVER touch)
constexpr uint32_t kDefaultMaxSizeOffset = 0x01E0;

// Widget side: UUI_InventoryGrid_C.MaxRows / MaxColumns / MaxSlots control
// how many slot tiles the grid renders. Offsets verified from the SDK header
// UI_InventoryGrid_classes.hpp:30-32 (this file's class IS in Dumper-7's
// output; UI_Container_BackpackSide is NOT, even after opening the inventory
// in-game, so we go straight to the grid). The visible slot count is
//     min(component.MaxSize, grid.MaxRows * grid.MaxColumns).
// We bump MaxRows on every UUI_InventoryGrid_C CDO + instance.
constexpr int32_t kVanillaMaxColumns = 10;
constexpr int32_t kTargetMaxRows = (kSlotCount + kVanillaMaxColumns - 1) / kVanillaMaxColumns; // = 6 for 60
constexpr uint32_t kGridMaxRowsOffset    = 0x0388; // UUI_InventoryGrid_C.MaxRows
constexpr uint32_t kGridMaxSlotsOffset   = 0x038C; // UUI_InventoryGrid_C.MaxSlots
constexpr uint32_t kGridMaxColumnsOffset = 0x0390; // UUI_InventoryGrid_C.MaxColumns

constexpr auto kRescanInterval = std::chrono::seconds(10);
constexpr auto kInitRetryDelay = std::chrono::milliseconds(500);
constexpr int  kInitMaxRetries = 60;

// ---- globals --------------------------------------------------------------

static std::atomic<bool> g_running{ true };
static FILE*             g_logFile = nullptr;
static char              g_logPath[MAX_PATH] = {};

// ---- logging --------------------------------------------------------------

static void Log(const char* fmt, ...) {
    SYSTEMTIME st;
    GetLocalTime(&st);
    char buf[4096];
    int hl = sprintf_s(buf, "[%02d:%02d:%02d.%03d] ",
                       st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    va_list args;
    va_start(args, fmt);
    int n = vsnprintf(buf + hl, sizeof(buf) - hl - 4, fmt, args);
    va_end(args);
    if (n < 0) n = 0;
    int total = hl + n;
    buf[total++] = '\r';
    buf[total++] = '\n';
    buf[total]   = 0;

    fwrite(buf, 1, total, stdout);
    fflush(stdout);
    if (g_logFile) {
        fwrite(buf, 1, total, g_logFile);
        fflush(g_logFile);
    }
}

// ---- inventory scan (offset-only, no SDK class dependency) ---------------

struct InventoryFinding {
    SDK::UObject* obj;
    int32_t       defaultMaxSize;
    std::string   fullName;
    bool          isCDO;
    bool          isPlayer;   // owned (transitively) by BP_SurvivalPlayerCharacter*
};

// We only want to patch the player's main backpack inventory, not chests, not
// loot bags, not death drops. Those all derive from UInventoryComponent and
// also default to 40, so a value-only filter would scoop them up. The string
// match against the outer chain is the cheap reliable filter.
static bool IsPlayerMainInventory(const std::string& fullName) {
    return fullName.find("BP_SurvivalPlayerCharacter") != std::string::npos;
}

static int32_t ReadDefaultMaxSize(SDK::UObject* obj) {
    return *reinterpret_cast<int32_t*>(
        reinterpret_cast<uint8_t*>(obj) + kDefaultMaxSizeOffset);
}

static void WriteDefaultMaxSize(SDK::UObject* obj, int32_t value) {
    *reinterpret_cast<int32_t*>(
        reinterpret_cast<uint8_t*>(obj) + kDefaultMaxSizeOffset) = value;
}

static SDK::UClass* g_invClass = nullptr;

static SDK::UClass* GetInventoryClass() {
    if (g_invClass) return g_invClass;
    g_invClass = SDK::UObject::FindClassFast("InventoryComponent");
    return g_invClass;
}

static std::vector<InventoryFinding> ScanInventoryComponents() {
    std::vector<InventoryFinding> results;
    SDK::UClass* invClass = GetInventoryClass();
    if (!invClass) {
        Log("ERROR: FindClassFast(\"InventoryComponent\") returned null");
        return results;
    }
    if (!SDK::UObject::GObjects) {
        Log("ERROR: GObjects null in ScanInventoryComponents");
        return results;
    }
    int N = SDK::UObject::GObjects->Num();
    results.reserve(64);
    for (int i = 0; i < N; ++i) {
        SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);
        if (!obj) continue;
        if (!obj->IsA(invClass)) continue;

        InventoryFinding f{};
        f.obj            = obj;
        f.defaultMaxSize = ReadDefaultMaxSize(obj);
        f.fullName       = obj->GetFullName();
        f.isCDO          = f.fullName.find("Default__") != std::string::npos;
        f.isPlayer       = IsPlayerMainInventory(f.fullName);
        results.push_back(std::move(f));
    }
    return results;
}

// ---- diagnostic phases ----------------------------------------------------

static bool WaitForGObjects() {
    int retries = 0;
    while (g_running.load() && retries < kInitMaxRetries) {
        if (SDK::UObject::GObjects && SDK::UObject::GObjects->Num() > 0) {
            Log("GObjects populated after %d retries (%d ms)",
                retries,
                retries * static_cast<int>(kInitRetryDelay.count()));
            return true;
        }
        std::this_thread::sleep_for(kInitRetryDelay);
        ++retries;
    }
    return false;
}

static void DumpFindings(const std::vector<InventoryFinding>& comps) {
    Log("found %zu UInventoryComponent objects (* = player main, will be patched):",
        comps.size());
    for (const auto& f : comps) {
        Log("  %s [%s] DefaultMaxSize=%-4d  obj=0x%p  %s",
            f.isPlayer ? "*" : " ",
            f.isCDO ? "CDO " : "inst",
            f.defaultMaxSize,
            f.obj,
            f.fullName.c_str());
    }
}

// ---- inventory interface widget call -------------------------------------

// Call WBP_InventoryInterface_C::PopulateItemGrid(RowMax, ColumnMax) on every
// live instance we haven't called it on yet. The PopulateItemGrid Params
// struct (from WBP_InventoryInterface_parameters.hpp) is 0xB0 bytes; the
// first two int32s at offset 0x00 / 0x04 are the input RowMax / ColumnMax.
// Everything else is BP local state, zero-initialised.
//
// This is the actual visible-rows handle. The class layout
// (WBP_InventoryInterface_classes.hpp) shows ItemGrid is a UGridPanel and
// the SDK exposes PopulateItemGrid(RowMax, ColumnMax) as the BP-callable
// method that fills the grid with slot widgets. Calling it with (6, 10) on
// the live instance after our DefaultMaxSize patch is in place gives us 60
// visible slots laid out as 6 rows of 10.
//
// We track which instance pointers we've already called it on so we don't
// re-fire every rescan tick (re-calling causes the inventory grid to re-
// build and flicker). Pointers are not stable across world reloads, but we
// don't track that; if the user reloads a save and the same pointer is
// reused for a new instance, the worst case is we don't repopulate it. The
// user can re-inject if needed.
static int CallPopulateItemGridOnLiveInstances(int32_t rowMax, int32_t colMax) {
    static std::vector<SDK::UObject*> calledOn;

    SDK::UClass* invIfaceClass = SDK::UObject::FindClassFast("WBP_InventoryInterface_C");
    if (!invIfaceClass) return -1;

    SDK::UFunction* fn = invIfaceClass->GetFunction(
        "WBP_InventoryInterface_C", "PopulateItemGrid");
    if (!fn) {
        Log("widget: PopulateItemGrid UFunction not found on WBP_InventoryInterface_C");
        return -1;
    }

    int called = 0;
    int N = SDK::UObject::GObjects->Num();
    for (int i = 0; i < N; ++i) {
        SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);
        if (!obj) continue;
        if (!obj->IsA(invIfaceClass)) continue;
        std::string fnName = obj->GetFullName();
        // Skip CDO; calling PopulateItemGrid on a default object is meaningless.
        if (fnName.find("Default__") != std::string::npos) continue;
        // Skip if we've already called it on this instance.
        bool already = false;
        for (auto p : calledOn) { if (p == obj) { already = true; break; } }
        if (already) continue;

        // Params buffer 0xB0 bytes, first two int32s are inputs.
        alignas(8) uint8_t parms[0xB0] = {};
        *reinterpret_cast<int32_t*>(&parms[0x00]) = rowMax;
        *reinterpret_cast<int32_t*>(&parms[0x04]) = colMax;

        auto savedFlags = fn->FunctionFlags;
        fn->FunctionFlags |= 0x400;
        obj->ProcessEvent(fn, parms);
        fn->FunctionFlags = savedFlags;

        Log("widget CALL %s.PopulateItemGrid(%d, %d)",
            fnName.c_str(), rowMax, colMax);
        calledOn.push_back(obj);
        ++called;
    }
    return called;
}

// ---- widget patch --------------------------------------------------------

// Patch the UUI_InventoryGrid_C CDO's MaxRows. The player inventory in this
// Grounded 2 build does NOT use UUI_InventoryGrid_C (it uses
// WBP_InventoryInterface_C with a UGridPanel; see
// CallPopulateItemGridOnLiveInstances above). The CDO patch is kept as
// belt-and-braces in case a future game build re-introduces a grid widget
// for the player inventory. We deliberately do NOT walk all live instances
// any more, because that hits unrelated grids (production recipe widgets)
// without affecting the player inventory.
static int PatchInventoryGridMaxRows() {
    SDK::UClass* gridClass = SDK::UObject::FindClassFast("UI_InventoryGrid_C");
    if (!gridClass) {
        // Not loaded yet. Will retry on next rescan; not fatal because the
        // real visible-rows handle is PopulateItemGrid, which we call
        // separately.
        return 0;
    }
    SDK::UObject* cdo = gridClass->ClassDefaultObject;
    if (!cdo) return 0;
    int32_t* rowsAddr = reinterpret_cast<int32_t*>(
        reinterpret_cast<uint8_t*>(cdo) + kGridMaxRowsOffset);
    int32_t before = *rowsAddr;
    if (before == kTargetMaxRows) return 0;
    *rowsAddr = kTargetMaxRows;
    Log("widget PATCH %s.MaxRows: %d -> %d (CDO only)",
        cdo->GetFullName().c_str(), before, kTargetMaxRows);
    return 1;
}

static int PatchVanillaMains(const std::vector<InventoryFinding>& comps) {
    int patched = 0;
    int skippedNonPlayer = 0;
    for (const auto& f : comps) {
        if (f.defaultMaxSize != kVanillaMain) continue;
        if (!f.isPlayer) {
            ++skippedNonPlayer;
            continue;
        }
        WriteDefaultMaxSize(f.obj, kSlotCount);
        int32_t verify = ReadDefaultMaxSize(f.obj);
        Log("PATCH %s: %d -> %d (verify=%d)",
            f.fullName.c_str(), kVanillaMain, kSlotCount, verify);
        ++patched;
    }
    if (skippedNonPlayer > 0) {
        Log("skipped %d non-player components with DefaultMaxSize=40 (chests, loot bags, etc.)",
            skippedNonPlayer);
    }
    return patched;
}

// ---- main worker ----------------------------------------------------------

static void DiagnosticLoop() {
    Log("=== Better Backpack DLL ===");
    Log("target slot_count = %d", kSlotCount);
    Log("vanilla main = %d, vanilla mount = %d (left untouched)",
        kVanillaMain, kVanillaMount);
    HMODULE hExe = GetModuleHandleW(NULL);
    Log("game exe base    = 0x%p", reinterpret_cast<void*>(hExe));

    if (!WaitForGObjects()) {
        Log("FATAL: GObjects never populated after %d retries; aborting",
            kInitMaxRetries);
        return;
    }
    Log("GObjects count   = %d", SDK::UObject::GObjects->Num());

    // Engine-side log/save/mods directory resolution.
    {
        auto logDir   = CallStaticFStringGetter("BlueprintPathsLibrary", "ProjectLogDir");
        auto savedDir = CallStaticFStringGetter("BlueprintPathsLibrary", "ProjectSavedDir");
        auto modsDir  = CallStaticFStringGetter("BlueprintPathsLibrary", "ProjectModsDir");
        Log("ProjectLogDir()   = '%s'", FStringToUtf8(logDir).c_str());
        Log("ProjectSavedDir() = '%s'", FStringToUtf8(savedDir).c_str());
        Log("ProjectModsDir()  = '%s'", FStringToUtf8(modsDir).c_str());
    }

    auto comps = ScanInventoryComponents();
    DumpFindings(comps);

    int patched = PatchVanillaMains(comps);
    Log("initial patch round: %d / %zu components patched", patched, comps.size());

    int widgetPatched = PatchInventoryGridMaxRows();
    Log("initial widget patch round: %d UUI_InventoryGrid_C objects bumped to MaxRows=%d",
        widgetPatched, kTargetMaxRows);

    Log("entering rescan loop (interval = %lld s)",
        static_cast<long long>(std::chrono::duration_cast<std::chrono::seconds>(kRescanInterval).count()));
    size_t lastSize = comps.size();
    while (g_running.load()) {
        std::this_thread::sleep_for(kRescanInterval);
        auto current = ScanInventoryComponents();
        int repatched = 0;
        for (const auto& f : current) {
            if (f.defaultMaxSize != kVanillaMain) continue;
            if (!f.isPlayer) continue;
            WriteDefaultMaxSize(f.obj, kSlotCount);
            Log("RESET DETECTED %s: %d -> %d (re-patched)",
                f.fullName.c_str(), kVanillaMain, kSlotCount);
            ++repatched;
        }
        if (repatched > 0 || current.size() != lastSize) {
            Log("rescan: %zu components (was %zu), %d re-patched",
                current.size(), lastSize, repatched);
            lastSize = current.size();
        }
        // Re-scan grids (CDO + the few stragglers).
        int gridsPatched = PatchInventoryGridMaxRows();
        if (gridsPatched > 0) {
            Log("rescan: %d new/reset UUI_InventoryGrid_C objects patched", gridsPatched);
        }
        // Trigger a re-populate on every live WBP_InventoryInterface_C with
        // (RowMax=6, ColumnMax=10). This is what actually changes the visible
        // slot grid in the player's inventory window.
        int populated = CallPopulateItemGridOnLiveInstances(kTargetMaxRows, kVanillaMaxColumns);
        if (populated > 0) {
            Log("rescan: PopulateItemGrid called on %d live WBP_InventoryInterface_C instances", populated);
        }
    }
    Log("worker thread exiting");
}

static DWORD WINAPI WorkerEntry(LPVOID) {
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr);
    SetConsoleTitleW(L"Better Backpack");

    char temp[MAX_PATH];
    DWORD tlen = GetTempPathA(MAX_PATH, temp);
    if (tlen == 0 || tlen > MAX_PATH) {
        strcpy_s(temp, ".\\");
    }
    sprintf_s(g_logPath, "%sBetterBackpack.log", temp);
    fopen_s(&g_logFile, g_logPath, "wb");

    Log("log file: %s", g_logPath);
    DiagnosticLoop();
    return 0;
}

} // namespace BBD

BOOL APIENTRY DllMain(HMODULE hMod, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hMod);
        HANDLE h = CreateThread(NULL, 0, BBD::WorkerEntry, NULL, 0, NULL);
        if (h) CloseHandle(h);
    } else if (reason == DLL_PROCESS_DETACH) {
        BBD::g_running.store(false);
    }
    return TRUE;
}
