// Better Backpack DLL: live data-side + visible-side patch for the Grounded 2
// player main backpack. Diagnostic dump on first scan; re-patch every 10s.
//
// Goals:
//   1. Allocate a console + a log file the moment we attach.
//   2. Wait for the engine to populate UObject::GObjects.
//   3. Walk every loaded UInventoryComponent (CDOs and live instances) and
//      dump its DefaultMaxSize. This is what the pak override changes.
//   4. Bump player main-backpack DefaultMaxSize up to kSlotCount on every
//      player-owned inventory component below target. Leave 30
//      (mount/saddlebag) alone. This is the runtime equivalent of the Better
//      Backpack pak override.
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
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <array>
#include <algorithm>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "SDK/Basic.hpp"
#include "SDK/CoreUObject_structs.hpp"
#include "SDK/CoreUObject_classes.hpp"
#include "SDK/SlateCore_structs.hpp"

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

constexpr int32_t kSlotCount     = 100;         // target main-backpack DefaultMaxSize
constexpr int32_t kVanillaMain   = 40;          // vanilla main-backpack DefaultMaxSize
constexpr int32_t kVanillaMount  = 30;          // vanilla mount/saddlebag (NEVER touch)
constexpr uint32_t kDefaultMaxSizeOffset = 0x01E0;

// Viewport side: keep the visible inventory at 4x10 and later rebind those 40
// visible slots against different backing indices. The older 6-row growth path
// is intentionally retired.
constexpr int32_t kVanillaMaxColumns = 10;
constexpr int32_t kViewportRows = 4;
constexpr int32_t kViewportColumns = 10;
constexpr int32_t kViewportPageSize = kViewportRows * kViewportColumns;
constexpr int32_t kScrollStepSlots = kViewportColumns;
constexpr uint32_t kInvIfaceItemGridOffset = 0x0430; // UWBP_InventoryInterface_C.ItemGrid
constexpr uint32_t kWidgetManagerWindowStackOffset = 0x0050; // UWidgetManager.WindowStack

constexpr auto kRescanInterval = std::chrono::seconds(10);
constexpr auto kInitRetryDelay = std::chrono::milliseconds(500);
constexpr int  kInitMaxRetries = 60;

// ---- globals --------------------------------------------------------------

static std::atomic<bool> g_running{ true };
static FILE*             g_logFile = nullptr;
static char              g_logPath[MAX_PATH] = {};
static SDK::UClass*      g_invIfaceClass = nullptr;

using ProcessEventFn = void(*)(const SDK::UObject*, SDK::UFunction*, void*);
struct ProcessEventHookSurface {
    const char*    className;
    void**         slot;
    void**         vtable;
    ProcessEventFn original;
};

static std::array<ProcessEventHookSurface, 10> g_processEventHooks{{
    { "Widget", nullptr, nullptr, nullptr },
    { "UserWidget", nullptr, nullptr, nullptr },
    { "GameUserWidget", nullptr, nullptr, nullptr },
    { "InventoryWidget", nullptr, nullptr, nullptr },
    { "WBP_InventoryInterface_C", nullptr, nullptr, nullptr },
    { "InGameMenuWidget", nullptr, nullptr, nullptr },
    { "WidgetManager", nullptr, nullptr, nullptr },
    { "PanelWidget", nullptr, nullptr, nullptr },
    { "GridPanel", nullptr, nullptr, nullptr },
    { "BPF_InventoryFunctions_C", nullptr, nullptr, nullptr },
}};

static bool            g_processEventHooksInstalled = false;
static bool            g_processEventHookFailureLogged = false;
static bool            g_widgetProbeDumped = false;
static bool            g_invIfaceMethodTraceEnabled = true;
static bool            g_inventoryGridTraceEnabled = true;
static bool            g_inventoryBpfTraceEnabled = true;
static bool            g_inventoryMenuTraceEnabled = true;
static std::string     g_lastInventoryWidgetInspection;
static std::string     g_lastWidgetManagerInspection;
static thread_local bool g_inInvIfaceHook = false;
static thread_local bool g_inSyntheticInventoryRefresh = false;
static std::unordered_map<const SDK::UObject*, int32_t> g_inventoryViewportStart;

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

static void WriteVTableSlot(void** slot, void* value) {
    DWORD oldProtect = 0;
    if (VirtualProtect(slot, sizeof(void*), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        *slot = value;
        DWORD ignored = 0;
        VirtualProtect(slot, sizeof(void*), oldProtect, &ignored);
    }
}

template<typename T>
static T ReadObjectField(SDK::UObject* obj, uint32_t offset) {
    return *reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(obj) + offset);
}

static SDK::UObject* ReadObjectPointerField(SDK::UObject* obj, uint32_t offset) {
    return ReadObjectField<SDK::UObject*>(obj, offset);
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

// ---- inventory interface hook --------------------------------------------

static void DumpLoadedObjectsContaining(const char* needle, bool classesOnly = false) {
    if (!SDK::UObject::GObjects) return;

    SDK::UClass* classClass = SDK::UClass::StaticClass();
    int hits = 0;
    int N = SDK::UObject::GObjects->Num();
    for (int i = 0; i < N; ++i) {
        SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);
        if (!obj) continue;
        if (classesOnly && !obj->IsA(classClass)) continue;

        std::string name = classesOnly ? obj->GetName() : obj->GetFullName();
        if (name.find(needle) == std::string::npos) continue;

        Log("  probe[%s] %s", classesOnly ? "class" : "obj", name.c_str());
        if (++hits >= 24) {
            Log("  probe[%s] ... more elided", classesOnly ? "class" : "obj");
            break;
        }
    }
    if (hits == 0) {
        Log("  probe[%s] no matches for '%s'", classesOnly ? "class" : "obj", needle);
    }
}

static void DumpInventoryWidgetProbe() {
    Log("inventory-widget probe: loaded class/object candidates");
    DumpLoadedObjectsContaining("InventoryInterface", true);
    DumpLoadedObjectsContaining("InventoryInterface", false);
    DumpLoadedObjectsContaining("InventoryGrid", true);
    DumpLoadedObjectsContaining("InventoryGrid", false);
    DumpLoadedObjectsContaining("Backpack", true);
    DumpLoadedObjectsContaining("Backpack", false);
}

static SDK::UClass* GetInventoryInterfaceClass() {
    if (g_invIfaceClass) return g_invIfaceClass;
    g_invIfaceClass = SDK::UObject::FindClassFast("WBP_InventoryInterface_C");
    return g_invIfaceClass;
}

static SDK::UClass* g_gridPanelClass = nullptr;
static SDK::UClass* GetGridPanelClass() {
    if (g_gridPanelClass) return g_gridPanelClass;
    g_gridPanelClass = SDK::UObject::FindClassFast("GridPanel");
    return g_gridPanelClass;
}

static SDK::UClass* g_panelWidgetClass = nullptr;
static SDK::UClass* GetPanelWidgetClass() {
    if (g_panelWidgetClass) return g_panelWidgetClass;
    g_panelWidgetClass = SDK::UObject::FindClassFast("PanelWidget");
    return g_panelWidgetClass;
}

static SDK::UClass* g_inventoryBpfClass = nullptr;
static SDK::UClass* GetInventoryBpfClass() {
    if (g_inventoryBpfClass) return g_inventoryBpfClass;
    g_inventoryBpfClass = SDK::UObject::FindClassFast("BPF_InventoryFunctions_C");
    return g_inventoryBpfClass;
}

static SDK::UClass* g_widgetManagerClass = nullptr;
static SDK::UClass* GetWidgetManagerClass() {
    if (g_widgetManagerClass) return g_widgetManagerClass;
    g_widgetManagerClass = SDK::UObject::FindClassFast("WidgetManager");
    return g_widgetManagerClass;
}

static SDK::UClass* g_inGameMenuWidgetClass = nullptr;
static SDK::UClass* GetInGameMenuWidgetClass() {
    if (g_inGameMenuWidgetClass) return g_inGameMenuWidgetClass;
    g_inGameMenuWidgetClass = SDK::UObject::FindClassFast("InGameMenuWidget");
    return g_inGameMenuWidgetClass;
}

struct IntReturnParms {
    int32_t ReturnValue;
};

struct GetChildAtParms {
    int32_t      Index_0;
    SDK::UObject* ReturnValue;
};

struct GetInventoryItemsParms {
    SDK::TArray<SDK::UObject*> Items;
};

struct SelectedIndexParms {
    int32_t Index_0;
};

struct SetSelectedInventorySlotParms {
    int32_t Slot_0;
};

struct RefreshInventoryGridParms {
    SDK::TArray<SDK::UObject*> ItemList;
    SDK::UObject*              GridPanel;
    int32_t                    RowMax;
    int32_t                    ColumnMax;
    int32_t                    ItemStartIndex;
    SDK::UObject*              __WorldContext;
};

struct PointerEventGetWheelDeltaParms {
    SDK::FPointerEvent Input;
    float              ReturnValue;
};

struct GetItemInItemListSlotParms {
    SDK::TArray<SDK::UObject*> ItemList;
    int32_t                    Index_0;
    SDK::UObject*              __WorldContext;
    SDK::UObject*              Item;
};

struct InitializeItemSlotParms {
    SDK::UObject* ItemSlot;
    SDK::UObject* Item;
};

struct OnMouseWheelInputView {
    uint8_t            MyGeometry[0x38];
    SDK::FPointerEvent MouseEvent;
};

static int32_t TryGetPanelChildrenCount(SDK::UObject* panelObj) {
    if (!panelObj) return -1;
    SDK::UFunction* func = panelObj->Class->GetFunction("PanelWidget", "GetChildrenCount");
    if (!func) return -1;
    IntReturnParms parms{};
    panelObj->ProcessEvent(func, &parms);
    return parms.ReturnValue;
}

static SDK::UObject* TryGetPanelChildAt(SDK::UObject* panelObj, int32_t index) {
    if (!panelObj) return nullptr;
    SDK::UFunction* func = panelObj->Class->GetFunction("PanelWidget", "GetChildAt");
    if (!func) return nullptr;
    GetChildAtParms parms{};
    parms.Index_0 = index;
    panelObj->ProcessEvent(func, &parms);
    return parms.ReturnValue;
}

static SDK::UFunction* GetWidgetFunction(SDK::UObject* widget, const char* funcName) {
    if (!widget || !widget->Class) return nullptr;
    return widget->Class->GetFunction("WBP_InventoryInterface_C", funcName);
}

static bool TryGetInventoryItems(SDK::UObject* widget, SDK::TArray<SDK::UObject*>* outItems) {
    if (!widget || !outItems) return false;
    SDK::UFunction* func = GetWidgetFunction(widget, "GetInventoryItems");
    if (!func) {
        Log("scroll debug %s: GetInventoryItems function not found",
            widget ? widget->GetFullName().c_str() : "<null>");
        return false;
    }
    GetInventoryItemsParms parms{};
    widget->ProcessEvent(func, &parms);
    *outItems = std::move(parms.Items);
    Log("scroll debug %s: GetInventoryItems ok, count=%d",
        widget->GetFullName().c_str(),
        outItems->Num());
    return true;
}

static int32_t TryGetSelectedInventorySlotIndex(SDK::UObject* widget, bool* ok = nullptr) {
    if (ok) *ok = false;
    if (!widget) return -1;
    SDK::UFunction* func = GetWidgetFunction(widget, "GetSelectedInventorySlotIndex");
    if (!func) return -1;
    SelectedIndexParms parms{};
    widget->ProcessEvent(func, &parms);
    if (ok) *ok = true;
    return parms.Index_0;
}

static bool TrySetSelectedInventorySlot(SDK::UObject* widget, int32_t slotIndex) {
    if (!widget) return false;
    SDK::UFunction* func = GetWidgetFunction(widget, "SetSelectedInventorySlot");
    if (!func) {
        Log("scroll debug %s: SetSelectedInventorySlot function not found",
            widget->GetFullName().c_str());
        return false;
    }
    SetSelectedInventorySlotParms parms{};
    parms.Slot_0 = slotIndex;
    widget->ProcessEvent(func, &parms);
    Log("scroll debug %s: SetSelectedInventorySlot(%d) ok",
        widget->GetFullName().c_str(),
        slotIndex);
    return true;
}

static bool TryRefreshInventoryGridViewport(SDK::UObject* widget,
                                            SDK::UObject* gridPanel,
                                            int32_t itemStartIndex) {
    SDK::UClass* bpfClass = GetInventoryBpfClass();
    if (!widget || !gridPanel || !bpfClass) {
        Log("scroll debug %s: RefreshInventoryGrid prerequisites failed widget=%d grid=%d bpf=%d",
            widget ? widget->GetFullName().c_str() : "<null>",
            widget != nullptr,
            gridPanel != nullptr,
            bpfClass != nullptr);
        return false;
    }
    SDK::UObject* cdo = bpfClass->ClassDefaultObject;
    if (!cdo) {
        Log("scroll debug %s: RefreshInventoryGrid CDO missing",
            widget->GetFullName().c_str());
        return false;
    }
    SDK::UFunction* func = bpfClass->GetFunction("BPF_InventoryFunctions_C", "RefreshInventoryGrid");
    if (!func) {
        Log("scroll debug %s: RefreshInventoryGrid function not found",
            widget->GetFullName().c_str());
        return false;
    }

    SDK::TArray<SDK::UObject*> items;
    if (!TryGetInventoryItems(widget, &items)) {
        Log("scroll debug %s: RefreshInventoryGrid aborted because GetInventoryItems failed",
            widget->GetFullName().c_str());
        return false;
    }

    RefreshInventoryGridParms parms{};
    parms.ItemList = std::move(items);
    parms.GridPanel = gridPanel;
    parms.RowMax = kViewportRows;
    parms.ColumnMax = kViewportColumns;
    parms.ItemStartIndex = itemStartIndex;
    parms.__WorldContext = widget;
    Log("scroll debug %s: calling RefreshInventoryGrid rows=%d cols=%d start=%d",
        widget->GetFullName().c_str(),
        parms.RowMax,
        parms.ColumnMax,
        parms.ItemStartIndex);
    cdo->ProcessEvent(func, &parms);
    Log("scroll debug %s: RefreshInventoryGrid returned",
        widget->GetFullName().c_str());
    return true;
}

static SDK::UObject* TryGetItemInItemListSlot(SDK::UObject* widget,
                                              const SDK::TArray<SDK::UObject*>& itemList,
                                              int32_t absoluteSlotIndex) {
    SDK::UClass* bpfClass = GetInventoryBpfClass();
    if (!widget || !bpfClass) return nullptr;
    SDK::UObject* cdo = bpfClass->ClassDefaultObject;
    if (!cdo) return nullptr;
    SDK::UFunction* func = bpfClass->GetFunction("BPF_InventoryFunctions_C", "GetItemInItemListSlot");
    if (!func) return nullptr;

    GetItemInItemListSlotParms parms{};
    parms.ItemList = itemList;
    parms.Index_0 = absoluteSlotIndex;
    parms.__WorldContext = widget;
    cdo->ProcessEvent(func, &parms);
    return parms.Item;
}

static bool TryInitializeInventorySlot(SDK::UObject* widget,
                                       SDK::UObject* slotWidget,
                                       SDK::UObject* item) {
    if (!widget || !slotWidget) return false;
    SDK::UFunction* func = GetWidgetFunction(widget, "InitializeItemSlot");
    if (!func) {
        Log("scroll debug %s: InitializeItemSlot function not found",
            widget->GetFullName().c_str());
        return false;
    }
    InitializeItemSlotParms parms{};
    parms.ItemSlot = slotWidget;
    parms.Item = item;
    widget->ProcessEvent(func, &parms);
    return true;
}

static bool RebindInventoryViewportByAbsoluteSlots(SDK::UObject* widget,
                                                   SDK::UObject* itemGrid,
                                                   int32_t itemStartIndex) {
    SDK::TArray<SDK::UObject*> items;
    if (!TryGetInventoryItems(widget, &items)) {
        Log("scroll debug %s: absolute-slot rebind aborted because GetInventoryItems failed",
            widget->GetFullName().c_str());
        return false;
    }

    const int32_t childCount = TryGetPanelChildrenCount(itemGrid);
    if (childCount != kViewportPageSize) {
        Log("scroll debug %s: absolute-slot rebind expected %d visible children, found %d",
            widget->GetFullName().c_str(),
            kViewportPageSize,
            childCount);
        return false;
    }

    for (int32_t visibleIndex = 0; visibleIndex < kViewportPageSize; ++visibleIndex) {
        SDK::UObject* child = TryGetPanelChildAt(itemGrid, visibleIndex);
        if (!child) {
            Log("scroll debug %s: absolute-slot rebind missing child at visible index %d",
                widget->GetFullName().c_str(),
                visibleIndex);
            continue;
        }
        const int32_t absoluteSlot = itemStartIndex + visibleIndex;
        SDK::UObject* item = TryGetItemInItemListSlot(widget, items, absoluteSlot);
        bool bound = TryInitializeInventorySlot(widget, child, item);
        Log("scroll debug %s: bind visible=%d absolute=%d item=%s bound=%d",
            widget->GetFullName().c_str(),
            visibleIndex,
            absoluteSlot,
            item ? item->GetFullName().c_str() : "<empty>",
            bound);
    }
    return true;
}

static float TryGetMouseWheelDelta(const SDK::FPointerEvent& pointerEvent, bool* ok = nullptr) {
    if (ok) *ok = false;

    SDK::UClass* libClass = SDK::UObject::FindClassFast("KismetInputLibrary");
    if (!libClass) return 0.0f;
    SDK::UObject* cdo = libClass->ClassDefaultObject;
    if (!cdo) return 0.0f;
    SDK::UFunction* func = libClass->GetFunction("KismetInputLibrary", "PointerEvent_GetWheelDelta");
    if (!func) return 0.0f;

    PointerEventGetWheelDeltaParms parms{};
    parms.Input = pointerEvent;
    auto savedFlags = func->FunctionFlags;
    func->FunctionFlags |= 0x400;
    cdo->ProcessEvent(func, &parms);
    func->FunctionFlags = savedFlags;
    if (ok) *ok = true;
    return parms.ReturnValue;
}

static int32_t ClampViewportStartIndex(int32_t itemStartIndex) {
    const int32_t maxStart = std::max(0, kSlotCount - kViewportPageSize);
    return std::clamp(itemStartIndex, 0, maxStart);
}

static bool RebindInventoryViewport(SDK::UObject* widget,
                                    int32_t newStartIndex,
                                    const char* reason) {
    if (!widget) return false;

    SDK::UObject* itemGrid = ReadObjectPointerField(widget, kInvIfaceItemGridOffset);
    if (!itemGrid) {
        Log("scroll debug %s: rebind aborted because ItemGrid is null",
            widget->GetFullName().c_str());
        return false;
    }

    int32_t childCount = TryGetPanelChildrenCount(itemGrid);
    if (childCount != kViewportPageSize) {
        Log("scroll refresh skipped for %s: expected %d visible children, found %d",
            widget->GetFullName().c_str(),
            kViewportPageSize,
            childCount);
        return false;
    }

    const int32_t clampedStart = ClampViewportStartIndex(newStartIndex);
    const int32_t oldStart = g_inventoryViewportStart[widget];
    Log("scroll debug %s: rebind request reason=%s oldStart=%d requestedStart=%d clampedStart=%d childCount=%d",
        widget->GetFullName().c_str(),
        reason ? reason : "unknown",
        oldStart,
        newStartIndex,
        clampedStart,
        childCount);

    bool hadSelection = false;
    int32_t selectedVisibleIndex = TryGetSelectedInventorySlotIndex(widget, &hadSelection);
    int32_t absoluteSelectedIndex = -1;
    if (hadSelection && selectedVisibleIndex >= 0 && selectedVisibleIndex < kViewportPageSize) {
        absoluteSelectedIndex = oldStart + selectedVisibleIndex;
    }
    Log("scroll debug %s: selection hadSelection=%d visibleIndex=%d absoluteIndex=%d",
        widget->GetFullName().c_str(),
        hadSelection,
        selectedVisibleIndex,
        absoluteSelectedIndex);

    g_inSyntheticInventoryRefresh = true;
    bool refreshed = RebindInventoryViewportByAbsoluteSlots(widget, itemGrid, clampedStart);
    g_inSyntheticInventoryRefresh = false;
    if (!refreshed) {
        Log("scroll debug %s: rebind failed during absolute-slot viewport bind",
            widget->GetFullName().c_str());
        return false;
    }

    g_inventoryViewportStart[widget] = clampedStart;

    if (absoluteSelectedIndex >= 0) {
        int32_t relative = absoluteSelectedIndex - clampedStart;
        if (relative < 0) relative = 0;
        if (relative >= kViewportPageSize) relative = kViewportPageSize - 1;
        g_inSyntheticInventoryRefresh = true;
        bool restored = TrySetSelectedInventorySlot(widget, relative);
        g_inSyntheticInventoryRefresh = false;
        Log("scroll debug %s: selection restore relative=%d restored=%d",
            widget->GetFullName().c_str(),
            relative,
            restored);
    }

    Log("scroll refresh %s: %s start=%d -> %d",
        widget->GetFullName().c_str(),
        reason ? reason : "unknown",
        oldStart,
        clampedStart);
    return true;
}

static std::string BuildInventoryWidgetInspectionReport() {
    SDK::UClass* invIfaceClass = GetInventoryInterfaceClass();
    if (!invIfaceClass || !SDK::UObject::GObjects) return {};

    std::string report;
    int N = SDK::UObject::GObjects->Num();
    for (int i = 0; i < N; ++i) {
        SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);
        if (!obj || !obj->IsA(invIfaceClass) || obj->IsDefaultObject()) continue;

        SDK::UObject* itemGrid = ReadObjectPointerField(obj, kInvIfaceItemGridOffset);
        int32_t childCount = TryGetPanelChildrenCount(itemGrid);

        report += "widget=" + obj->GetFullName();
        report += " grid=";
        report += itemGrid ? itemGrid->GetFullName() : "<null>";
        report += " children=" + std::to_string(childCount);

        int32_t sampleCount = childCount > 0 ? (childCount < 6 ? childCount : 6) : 0;
        for (int32_t childIdx = 0; childIdx < sampleCount; ++childIdx) {
            SDK::UObject* child = TryGetPanelChildAt(itemGrid, childIdx);
            report += " child[" + std::to_string(childIdx) + "]=";
            report += child ? child->GetFullName() : "<null>";
        }
        report += "\n";
    }
    return report;
}

static std::string BuildWidgetManagerInspectionReport() {
    SDK::UClass* widgetManagerClass = GetWidgetManagerClass();
    if (!widgetManagerClass || !SDK::UObject::GObjects) return {};

    std::string report;
    int N = SDK::UObject::GObjects->Num();
    for (int i = 0; i < N; ++i) {
        SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);
        if (!obj || !obj->IsA(widgetManagerClass) || obj->IsDefaultObject()) continue;

        auto& windowStack = *reinterpret_cast<SDK::TArray<SDK::UObject*>*>(
            reinterpret_cast<uint8_t*>(obj) + kWidgetManagerWindowStackOffset);

        report += "manager=" + obj->GetFullName();
        report += " windows=" + std::to_string(windowStack.Num());
        for (int32_t wi = 0; wi < windowStack.Num(); ++wi) {
            SDK::UObject* window = windowStack[wi];
            report += " window[" + std::to_string(wi) + "]=";
            report += window ? window->GetFullName() : "<null>";
        }
        report += "\n";
    }
    return report;
}

static void InspectLiveInventoryUiState() {
    std::string widgetReport = BuildInventoryWidgetInspectionReport();
    if (!widgetReport.empty() && widgetReport != g_lastInventoryWidgetInspection) {
        Log("inventory inspect: live WBP_InventoryInterface_C state");
        size_t start = 0;
        while (start < widgetReport.size()) {
            size_t end = widgetReport.find('\n', start);
            std::string line = widgetReport.substr(start, end == std::string::npos ? std::string::npos : end - start);
            if (!line.empty()) Log("  %s", line.c_str());
            if (end == std::string::npos) break;
            start = end + 1;
        }
        g_lastInventoryWidgetInspection = widgetReport;
    }

    std::string managerReport = BuildWidgetManagerInspectionReport();
    if (!managerReport.empty() && managerReport != g_lastWidgetManagerInspection) {
        Log("inventory inspect: WidgetManager window stack");
        size_t start = 0;
        while (start < managerReport.size()) {
            size_t end = managerReport.find('\n', start);
            std::string line = managerReport.substr(start, end == std::string::npos ? std::string::npos : end - start);
            if (!line.empty()) Log("  %s", line.c_str());
            if (end == std::string::npos) break;
            start = end + 1;
        }
        g_lastWidgetManagerInspection = managerReport;
    }
}

static ProcessEventFn FindOriginalProcessEventForObject(const SDK::UObject* obj) {
    if (!obj) return nullptr;

    void*** vtablePtr = reinterpret_cast<void***>(const_cast<SDK::UObject*>(obj));
    if (!vtablePtr || !*vtablePtr) return nullptr;

    void** liveVtable = *vtablePtr;
    for (const auto& hook : g_processEventHooks) {
        if (hook.vtable == liveVtable) {
            return hook.original;
        }
    }
    return nullptr;
}

static bool ShouldTraceInventoryInterfaceMethod(const std::string& fnName) {
    if (fnName == "PopulateItemGrid") return true;
    if (fnName == "Construct") return true;
    if (fnName == "OnMouseWheel") return true;
    if (fnName == "OnInventoryChanged") return true;
    if (fnName == "OnInventoryCountChanged") return true;
    if (fnName == "OnWidgetStackChanged") return true;
    if (fnName.find("Populate") != std::string::npos) return true;
    if (fnName.find("Refresh") != std::string::npos) return true;
    return false;
}

static bool ShouldTraceInventoryBpfMethod(const std::string& fnName) {
    if (fnName == "RefreshInventoryGrid") return true;
    if (fnName == "PopulateInventoryGrid") return true;
    if (fnName == "PlaceSlotInGrid") return true;
    if (fnName == "CreateItemSlotForItem") return true;
    if (fnName == "CreateItemSlotForRowHandle") return true;
    if (fnName == "GetItemSlotInPanel") return true;
    return false;
}

static bool ShouldTraceInventoryGridMethod(const std::string& fnName) {
    if (fnName == "AddChildToGrid") return true;
    if (fnName == "ClearChildren") return true;
    if (fnName == "GetChildrenCount") return true;
    if (fnName == "GetChildAt") return true;
    if (fnName == "AddChild") return true;
    return false;
}

static bool ShouldTraceInventoryMenuMethod(const std::string& fnName) {
    if (fnName == "OnPlayerInventoryChanged") return true;
    if (fnName == "ShowInGameMenu") return true;
    if (fnName == "SetInGameMenuActive") return true;
    if (fnName == "ToggleInGameMenu") return true;
    if (fnName == "GetInGameMenuWindow") return true;
    if (fnName == "GetTopWindow") return true;
    if (fnName == "ActivateInGameMenuScreenOfTag") return true;
    if (fnName == "RefreshMenuPage") return true;
    if (fnName == "ShouldRefreshOnOwnerInventoryChange") return true;
    if (fnName == "OnWidgetStackChanged") return true;
    return false;
}

static bool IsInventoryRelatedObjectName(const std::string& fullName) {
    return fullName.find("WBP_InventoryInterface") != std::string::npos
        || fullName.find("InventoryGrid") != std::string::npos
        || fullName.find("HotPouch") != std::string::npos
        || fullName.find("Backpack") != std::string::npos;
}

static void HookedInventoryInterfaceProcessEvent(const SDK::UObject* obj,
                                                 SDK::UFunction* function,
                                                 void* parms) {
    ProcessEventFn original = FindOriginalProcessEventForObject(obj);
    if (!original) return;

    if (!g_inInvIfaceHook && !g_inSyntheticInventoryRefresh && obj && function) {
        g_inInvIfaceHook = true;
        SDK::UClass* invIfaceClass = GetInventoryInterfaceClass();
        std::string fnName = function->GetName();
        if (invIfaceClass && obj->IsA(invIfaceClass)) {
            if (g_invIfaceMethodTraceEnabled && ShouldTraceInventoryInterfaceMethod(fnName)) {
                Log("widget TRACE %s.%s",
                    obj->GetFullName().c_str(),
                    fnName.c_str());
            }
            if (fnName == "Construct") {
                g_inventoryViewportStart[obj] = 0;
            }
        }

        SDK::UClass* inventoryBpfClass = GetInventoryBpfClass();
        if (g_inventoryBpfTraceEnabled && inventoryBpfClass && obj->IsA(inventoryBpfClass)) {
            if (ShouldTraceInventoryBpfMethod(fnName)) {
                Log("inventory BPF TRACE %s.%s",
                    obj->GetFullName().c_str(),
                    fnName.c_str());
            }
        }

        std::string objName = obj->GetFullName();
        SDK::UClass* panelWidgetClass = GetPanelWidgetClass();
        SDK::UClass* gridPanelClass = GetGridPanelClass();
        if (g_inventoryGridTraceEnabled
            && IsInventoryRelatedObjectName(objName)
            && ((gridPanelClass && obj->IsA(gridPanelClass))
                || (panelWidgetClass && obj->IsA(panelWidgetClass)))) {
            if (ShouldTraceInventoryGridMethod(fnName)) {
                Log("inventory GRID TRACE %s.%s",
                    objName.c_str(),
                    fnName.c_str());
            }
        }

        SDK::UClass* widgetManagerClass = GetWidgetManagerClass();
        SDK::UClass* inGameMenuWidgetClass = GetInGameMenuWidgetClass();
        if (g_inventoryMenuTraceEnabled
            && ((widgetManagerClass && obj->IsA(widgetManagerClass))
                || (inGameMenuWidgetClass && obj->IsA(inGameMenuWidgetClass))
                || (invIfaceClass && obj->IsA(invIfaceClass)))) {
            if (ShouldTraceInventoryMenuMethod(fnName)) {
                Log("inventory MENU TRACE %s.%s",
                    obj->GetFullName().c_str(),
                    fnName.c_str());
            }
        }
    }

    original(obj, function, parms);

    if (!g_inSyntheticInventoryRefresh && obj && function) {
        SDK::UClass* invIfaceClass = GetInventoryInterfaceClass();
        if (invIfaceClass && obj->IsA(invIfaceClass)) {
            const std::string fnName = function->GetName();

            if (fnName == "OnMouseWheel" && parms) {
                const auto* wheelParms = reinterpret_cast<const OnMouseWheelInputView*>(parms);
                bool deltaOk = false;
                const float wheelDelta = TryGetMouseWheelDelta(wheelParms->MouseEvent, &deltaOk);
                Log("scroll debug %s: OnMouseWheel currentStart=%d deltaOk=%d delta=%.3f",
                    obj->GetFullName().c_str(),
                    g_inventoryViewportStart[obj],
                    deltaOk,
                    wheelDelta);
                if (kSlotCount > kViewportPageSize) {
                    int32_t currentStart = g_inventoryViewportStart[obj];
                    int32_t nextStart = currentStart;
                    if (deltaOk) {
                        if (wheelDelta > 0.001f) {
                            nextStart = ClampViewportStartIndex(currentStart - kScrollStepSlots);
                        } else if (wheelDelta < -0.001f) {
                            nextStart = ClampViewportStartIndex(currentStart + kScrollStepSlots);
                        }
                    }
                    Log("scroll debug %s: OnMouseWheel computed nextStart=%d",
                        obj->GetFullName().c_str(),
                        nextStart);
                    if (nextStart != currentStart) {
                        RebindInventoryViewport(const_cast<SDK::UObject*>(obj), nextStart, "mouse-wheel");
                    } else {
                        Log("scroll debug %s: OnMouseWheel no-op because nextStart == currentStart",
                            obj->GetFullName().c_str());
                    }
                } else {
                    Log("scroll debug %s: OnMouseWheel blocked because slotCount=%d viewport=%d",
                        obj->GetFullName().c_str(),
                        kSlotCount,
                        kViewportPageSize);
                }
            } else if ((fnName == "OnInventoryChanged"
                     || fnName == "OnInventoryCountChanged"
                     || fnName == "RefreshUI"
                     || fnName == "RefreshMenuPage"
                     || fnName == "PopulateItemGrid")
                    && g_inventoryViewportStart[obj] != 0) {
                RebindInventoryViewport(const_cast<SDK::UObject*>(obj),
                                        g_inventoryViewportStart[obj],
                                        fnName.c_str());
            }
        }
    }

    if (!g_inSyntheticInventoryRefresh) {
        g_inInvIfaceHook = false;
    }
}

static bool TryInstallProcessEventHook(ProcessEventHookSurface& hook) {
    SDK::UClass* cls = SDK::UObject::FindClassFast(hook.className);
    if (!cls) {
        Log("hook install pending: FindClassFast(\"%s\") returned null", hook.className);
        return false;
    }

    SDK::UObject* cdo = cls->ClassDefaultObject;
    if (!cdo) {
        Log("hook install failed: %s has no ClassDefaultObject", hook.className);
        return false;
    }

    void*** vtablePtr = reinterpret_cast<void***>(cdo);
    if (!vtablePtr || !*vtablePtr) {
        Log("hook install failed: %s CDO vtable missing", hook.className);
        return false;
    }

    void** vtable = *vtablePtr;
    void** slot = &vtable[SDK::Offsets::ProcessEventIdx];
    if (!slot || !*slot) {
        Log("hook install failed: ProcessEvent slot %d missing on %s CDO",
            SDK::Offsets::ProcessEventIdx,
            hook.className);
        return false;
    }

    hook.original = reinterpret_cast<ProcessEventFn>(*slot);
    hook.slot = slot;
    hook.vtable = vtable;
    WriteVTableSlot(slot, reinterpret_cast<void*>(&HookedInventoryInterfaceProcessEvent));
    Log("installed %s::ProcessEvent hook at vtable slot %d (vtable=0x%p, original=0x%p)",
        hook.className,
        SDK::Offsets::ProcessEventIdx,
        vtable,
        reinterpret_cast<void*>(hook.original));
    return true;
}

static bool EnsureInventoryInterfaceHookInstalled() {
    if (g_processEventHooksInstalled) return true;

    bool installedAny = false;
    bool allInstalled = true;
    for (auto& hook : g_processEventHooks) {
        if (hook.slot && hook.original && hook.vtable) {
            installedAny = true;
            continue;
        }
        if (!TryInstallProcessEventHook(hook)) {
            allInstalled = false;
            continue;
        }
        installedAny = true;
    }

    if (!installedAny) {
        g_processEventHookFailureLogged = true;
        return false;
    }
    if (g_processEventHookFailureLogged) {
        Log("hook install resumed: at least one widget ProcessEvent surface is now installed");
        g_processEventHookFailureLogged = false;
    }
    g_processEventHooksInstalled = allInstalled;
    return true;
}

static void RemoveInventoryInterfaceHook() {
    for (auto& hook : g_processEventHooks) {
        if (!hook.slot || !hook.original) continue;
        WriteVTableSlot(hook.slot, reinterpret_cast<void*>(hook.original));
        hook.slot = nullptr;
        hook.vtable = nullptr;
        hook.original = nullptr;
    }
    g_processEventHooksInstalled = false;
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

// ---- widget viewport ------------------------------------------------------
//
// Earlier revisions tried to grow the live inventory from 4x10 to 6x10 by
// patching row counts or invoking grid rebuild logic from the worker thread.
// That approach is now intentionally retired. Live inspection proved the
// rendered inventory operates on a fixed pool of 40 UI_ItemSlot_C children.
// The supported path is now to keep the 4x10 viewport and rebind it on the
// game thread with a different ItemStartIndex.

static int PatchPlayerBackpacksToTarget(const std::vector<InventoryFinding>& comps) {
    int patched = 0;
    int skippedNonPlayer = 0;
    for (const auto& f : comps) {
        if (f.defaultMaxSize == kVanillaMount) continue;
        if (f.defaultMaxSize >= kSlotCount) continue;
        if (!f.isPlayer) {
            if (f.defaultMaxSize == kVanillaMain) {
                ++skippedNonPlayer;
            }
            continue;
        }
        int32_t before = f.defaultMaxSize;
        WriteDefaultMaxSize(f.obj, kSlotCount);
        int32_t verify = ReadDefaultMaxSize(f.obj);
        Log("PATCH %s: %d -> %d (verify=%d)",
            f.fullName.c_str(), before, kSlotCount, verify);
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
    EnsureInventoryInterfaceHookInstalled();

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

    int patched = PatchPlayerBackpacksToTarget(comps);
    Log("initial patch round: %d / %zu components patched", patched, comps.size());
    InspectLiveInventoryUiState();

    Log("entering rescan loop (interval = %lld s)",
        static_cast<long long>(std::chrono::duration_cast<std::chrono::seconds>(kRescanInterval).count()));
    size_t lastSize = comps.size();
    while (g_running.load()) {
        std::this_thread::sleep_for(kRescanInterval);
        auto current = ScanInventoryComponents();
        int repatched = 0;
        for (const auto& f : current) {
            if (f.defaultMaxSize == kVanillaMount) continue;
            if (f.defaultMaxSize >= kSlotCount) continue;
            if (!f.isPlayer) continue;
            int32_t before = f.defaultMaxSize;
            WriteDefaultMaxSize(f.obj, kSlotCount);
            Log("RESET DETECTED %s: %d -> %d (re-patched)",
                f.fullName.c_str(), before, kSlotCount);
            ++repatched;
        }
        if (repatched > 0 || current.size() != lastSize) {
            Log("rescan: %zu components (was %zu), %d re-patched",
                current.size(), lastSize, repatched);
            lastSize = current.size();
        }
        if (!g_processEventHooksInstalled) {
            EnsureInventoryInterfaceHookInstalled();
            if (!g_processEventHooksInstalled && !g_widgetProbeDumped) {
                DumpInventoryWidgetProbe();
                g_widgetProbeDumped = true;
            }
        }
        InspectLiveInventoryUiState();
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
        BBD::RemoveInventoryInterfaceHook();
        BBD::g_running.store(false);
    }
    return TRUE;
}
