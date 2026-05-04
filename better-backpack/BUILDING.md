# Better Backpack: build, configure, internals

For developers and anyone modifying the mod or porting it forward to new game versions.

## Contents

- [Prerequisites](#prerequisites)
- [Build](#build)
- [Source layout](#source-layout)
- [What the DLL patches](#what-the-dll-patches)
- [Configuration](#configuration)
- [How the injector works](#how-the-injector-works)
- [After a game update](#after-a-game-update)
- [Why DLL, not pak, not UE4SS](#why-dll-not-pak-not-ue4ss)

## Prerequisites

The build needs:

- **Visual Studio 2022 Community** (C++ workload) at the default install path. The build script calls `vcvars64.bat` and `cl.exe` directly. If yours is at a non-standard path, edit `VCVARS` at the top of `build.bat`.
- **Dumper-7 SDK** at `C:\Tools\work\sdk\` (so `C:\Tools\work\sdk\SDK\Basic.hpp` exists). Source: the Grounded2Minimal-related Dumper-7 release for Grounded 2 v0.4.0.2, or run Dumper-7 yourself against the live game. If the SDK lives elsewhere, edit `SDK_ROOT` at the top of `build.bat`.

The injector needs nothing extra. It uses Win32 only (`CreateToolhelp32Snapshot`, `OpenProcess`, `VirtualAllocEx`, `WriteProcessMemory`, `CreateRemoteThread`).

## Build

```cmd
build.bat
```

Cold build runs ~30 seconds. Output:

```
dist\BetterBackpack.dll
dist\inject.exe
```

The build compiles three translation units into the DLL: `dllmain.cpp`, `basic_impl.cpp`, and the Dumper-7 SDK's `CoreUObject_functions.cpp`. We deliberately do NOT include `Engine_functions.cpp` or `Maine_functions.cpp`. Those are huge generated files that would push the cold build to multiple minutes. See `basic_impl.cpp` for the workaround.

The injector is a single C TU (`inject.c`) and builds in seconds.

## Source layout

```
better-backpack/
  dllmain.cpp        Main DLL: console + log + scan + patch + rescan loop.
                     Uses raw offset arithmetic for UInventoryComponent and
                     reflective FProperty walk for the widget.
  basic_impl.cpp     Slim re-implementation of the SDK's Basic.cpp. Stubs
                     out StringToName-style helpers that would otherwise
                     drag Engine_functions.cpp into the build. Build-time
                     gain: ~minutes -> ~30s.
  inject.c           Standalone external injector. VirtualAllocEx +
                     WriteProcessMemory + CreateRemoteThread(LoadLibraryA).
                     Auto-detects Steam vs Xbox Game Pass exe.
  build.bat          MSVC build script. Compiles DLL, then injector.
  build/             Per-build object files. Safe to delete.
  dist/              Final binaries: BetterBackpack.dll + inject.exe.
  README.md          Landing page with TOC.
  INSTALL.md         User guide (install + verify + uninstall).
  TROUBLESHOOTING.md User-facing failure modes.
  BUILDING.md        This document.
  REQUIREMENTS.md    Design spec, research notes, verification plan.
  SHIPPING-BUILD-NOTES.md  UE5 shipping logging/console notes (extracted
                     from the parent inspection guide).
  inspection-guide.md Generic UE5 modding methodology (moved from repo
                     root). Tooling, phases, worked examples, SDK research.
```

## What the DLL patches

Two patch sites:

### 1. `UInventoryComponent.DefaultMaxSize` (data side)

- Offset: `0x01E0`. Hard-coded from `Maine_classes.hpp:29557`:
  ```cpp
  int32 DefaultMaxSize;   // 0x01E0
  ```
- Filter: only patches components whose value reads vanilla `40`. The mount saddlebag at `30` is left alone by virtue of the filter.
- Scope: every `UInventoryComponent` in `GObjects`. Both class default objects (CDOs) and live instances.
- Cadence: once on first scan after `GObjects` populates, then every 10 s.

### 2. `UWBP_InventoryInterface_C::PopulateItemGrid(6, 10)` (visible side)

- Class: looked up by short name via `SDK::UObject::FindClassFast("WBP_InventoryInterface_C")`.
- Function: `PopulateItemGrid(int32 RowMax, int32 ColumnMax)`, declared at `WBP_InventoryInterface_classes.hpp:205`. The Params struct is at `WBP_InventoryInterface_parameters.hpp` (0xB0 bytes; `RowMax` at offset 0x00, `ColumnMax` at offset 0x04, locals beyond).
- Invoked via `ProcessEvent` on every live instance whose full name does NOT contain `Default__`. We track the set of pointers we've already called it on and skip them on subsequent rescans (re-calling triggers a grid rebuild and flickers the UI).
- Cadence: rescan every 10 s. The very first time a live `WBP_InventoryInterface_C` instance shows up after the inventory has been opened in-game, the next tick fires the call and the visible grid immediately rebuilds at the new row count.

Why this and not `UI_InventoryGrid_C`: empirically, the player inventory in this build does not use `UUI_InventoryGrid_C` at all. The class layout (`WBP_InventoryInterface_classes.hpp:50`) has `class UGridPanel* ItemGrid` instead, populated by the BP-callable `PopulateItemGrid`. Patching `UUI_InventoryGrid_C.MaxRows` had no visible effect; calling `PopulateItemGrid(6, 10)` works on the first try.

The DLL still patches `UUI_InventoryGrid_C.MaxRows` on the CDO (offset `0x0388`) as belt-and-braces in case a future game update reintroduces a grid widget here. That patch is CDO-only; we no longer walk live instances of that class.

The data-side patch uses a hard-coded property offset and is fragile to game updates that reorder fields. The visible-side call is reflective (looks up the function by name) and survives field-layout changes. See [After a game update](#after-a-game-update).

## Configuration

Compile-time constants at the top of `dllmain.cpp`:

```cpp
constexpr int32_t kSlotCount         = 60;     // target main-backpack DefaultMaxSize
constexpr int32_t kVanillaMain       = 40;     // value the DLL looks for; only patches matches
constexpr int32_t kVanillaMount      = 30;     // documented; never touched (we skip non-40 values)
constexpr int32_t kVanillaMaxColumns = 10;     // UI_InventoryGrid.MaxColumns
constexpr int32_t kTargetMaxRows     = 6;      // = ceil(kSlotCount / kVanillaMaxColumns)

constexpr uint32_t kDefaultMaxSizeOffset = 0x01E0; // UInventoryComponent::DefaultMaxSize
constexpr uint32_t kGridMaxRowsOffset    = 0x0388; // UI_InventoryGrid_C::MaxRows
constexpr uint32_t kGridMaxSlotsOffset   = 0x038C; // UI_InventoryGrid_C::MaxSlots
constexpr uint32_t kGridMaxColumnsOffset = 0x0390; // UI_InventoryGrid_C::MaxColumns

constexpr auto kRescanInterval = std::chrono::seconds(10);
constexpr auto kInitRetryDelay = std::chrono::milliseconds(500);
constexpr int  kInitMaxRetries = 60;            // ~30 s before we abort
```

Edit and rebuild for a different slot count. Remember to update `kTargetMaxRows` if you change `kSlotCount` (it should be `ceil(kSlotCount / 10)`).

There is no runtime `settings.json` reader yet. Adding one is straightforward but not done: parse a sibling JSON file in `WorkerEntry` before calling `DiagnosticLoop`, override the constants with read values.

## How the injector works

`inject.c` does the textbook Win32 remote-LoadLibrary trick:

1. `CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS)` -> walk the process list. Match against `Grounded2-WinGRTS-Shipping.exe` (Steam) and `Grounded2-WinGDK-Shipping.exe` (Xbox Game Pass).
2. `OpenProcess(VM_OPERATION | VM_READ | VM_WRITE | CREATE_THREAD)` for the matched PID.
3. `VirtualAllocEx` a buffer in the target the size of our DLL path string.
4. `WriteProcessMemory` the path into that buffer.
5. `GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA")`. Both processes share kernel32 at the same base, so this address is valid in the target.
6. `CreateRemoteThread` with `LoadLibraryA` as the entry and the remote buffer as its argument.
7. `WaitForSingleObject` (5 s) and `GetExitCodeThread` to verify the load returned a non-zero `HMODULE`.
8. `VirtualFreeEx` the buffer; close handles.

Pattern lifted from x0reaxeax/Grounded2Minimal `Injector/main.c` (MIT). We add: dual-build detection (Steam + XGP), an optional `argv[1]` DLL path, slightly clearer error messages.

The injector links no SDK and no third-party code. It is portable across UE5 games: if you change the target process names, it works against any game without anti-cheat.

## After a game update

When Grounded 2 updates, the data-side patch may break because field offsets can shift. Symptoms: the log shows `DefaultMaxSize` reading values like 0, large garbage numbers, or the offset writes are clobbering unrelated fields and crashing the game.

Repair:

1. Re-run Dumper-7 against the new game executable to regenerate `Maine_classes.hpp`.
2. Search for `class UInventoryComponent`:
   ```cmd
   findstr /n /c:"DefaultMaxSize;" Maine_classes.hpp
   ```
3. Read the new offset from the comment (Dumper-7 emits `// 0xNNNN(0x0004)` after each property).
4. Update `kDefaultMaxSizeOffset` in `dllmain.cpp` to the new value.
5. Rebuild.

The widget patch is also offset-based (`UI_InventoryGrid_C::MaxRows` at `0x0388`). If a game update reorders the grid widget's fields, repeat the same Dumper-7 -> findstr workflow against `UI_InventoryGrid_classes.hpp` and update `kGridMaxRowsOffset` (and `kGridMaxSlotsOffset` / `kGridMaxColumnsOffset` if you use them). If the class was renamed, update the literal `"UI_InventoryGrid_C"` in `dllmain.cpp::PatchInventoryGridMaxRows()`.

## Why DLL, not pak, not UE4SS

- **Pak**: cannot be verified at runtime in shipping. UE5 shipping strips file logging (no `Augusta.log`) and the dev console. We chose the DLL path so we have a live readout of what we're patching. See [SHIPPING-BUILD-NOTES.md](SHIPPING-BUILD-NOTES.md).
- **UE4SS**: would work and is the canonical UE4/UE5 mod loader. Adds an external runtime dependency the user has to install separately and a folder layout (`ue4ss/Mods/<name>/dlls/main.dll`) that complicates packaging. For a single-purpose mod with no Lua story, the manual injector is simpler ship-on-ship.
- **Manual remote-thread injection** (chosen): one ~180-line C file. User runs `inject.exe`, mod runs. No third-party dependency, no Vortex extension required. Grounded 2 has no anti-cheat as of 0.4.0.2 so the standard pattern is safe.

If anti-cheat is ever added, switch to the UE4SS-proxy approach (rename our DLL to a system DLL the game loads, e.g. `dwmapi.dll`, forward exports, drop next to the game exe). That gets us back into the loader chain without needing a separate injector process.
