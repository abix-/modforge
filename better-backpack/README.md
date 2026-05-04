# Better Backpack

A standalone Grounded 2 mod that increases the player's main backpack from 40 to 60 slots. Implemented as an injected DLL (replaces an earlier pak prototype). Configurable slot count via a compile-time constant. No dependencies on other mods.

## Where to start

Pick the doc that matches what you want to do:

| If you want to... | Read |
|---|---|
| Install and use the mod | [INSTALL.md](INSTALL.md) |
| Diagnose a problem | [TROUBLESHOOTING.md](TROUBLESHOOTING.md) |
| Build, modify, or port to a new game version | [BUILDING.md](BUILDING.md) |
| Understand the design and verification plan | [REQUIREMENTS.md](REQUIREMENTS.md) |
| Understand how UE5 shipping verification works | [SHIPPING-BUILD-NOTES.md](SHIPPING-BUILD-NOTES.md) |
| Learn the broader UE5 mod inspection methodology | [inspection-guide.md](inspection-guide.md) |

## Quickstart

```cmd
:: 1. one-time build
build.bat

:: 2. launch Grounded 2 and load into a save (not just the main menu)

:: 3. from anywhere, run the injector
dist\inject.exe
```

A new console window titled "Better Backpack" appears, the inventory grid grows to 6 rows of 10, and a log opens at `%TEMP%\BetterBackpack.log`. The DLL is unloaded automatically when the game exits.

Full step-by-step is in [INSTALL.md](INSTALL.md).

## Where do the files go?

**Nowhere special.** This is not a Vortex mod and does not get installed into the Grounded 2 folder. The two artifacts (`BetterBackpack.dll` and `inject.exe`) can sit anywhere on disk: the project's `dist/` folder, your desktop, `Downloads\`, a USB stick. Just keep them in the same folder as each other. The injector finds the running game by process name and maps the DLL into the game from wherever the file lives.

## What it patches

Two patch sites:

- `UInventoryComponent.DefaultMaxSize` (offset `0x01E0`): every component reading vanilla 40 gets bumped to 60. The mount saddlebag at vanilla 30 is left alone.
- `UWBP_InventoryInterface_C::PopulateItemGrid(RowMax=6, ColumnMax=10)`: called via `ProcessEvent` on every live inventory-interface instance. The player inventory in this build is a `UWBP_InventoryInterface_C` whose `ItemGrid` is a plain `UGridPanel`, not a `UUI_InventoryGrid_C`. The Blueprint-callable `PopulateItemGrid` method is the surface that actually rebuilds the visible slot grid. We invoke it once per instance after the inventory widget has been constructed in-game. The Params struct is from `WBP_InventoryInterface_parameters.hpp` (0xB0 bytes; first two int32s are the inputs).
- `UUI_InventoryGrid_C.MaxRows` (offset `0x0388`, CDO only): kept as belt-and-braces. Empirically the player inventory does not use this widget class at all; the original Bigger Backpack pak mod targeted a host widget `UI_Container_BackpackSide` that doesn't exist in this build either. We patch the CDO so that any future game update that reintroduces this widget for the player inventory still picks up our value.

Internals, configuration constants, and how to fix the data-side offset after a game update are in [BUILDING.md](BUILDING.md).

## Source layout

```
better-backpack/
  dllmain.cpp        Main DLL: console + log + scan + patch + rescan loop.
  basic_impl.cpp     Slim re-impl of Dumper-7 Basic.cpp (cuts build time).
  inject.c           Standalone external injector.
  build.bat          MSVC build script.
  build/             Per-build object files.
  dist/              Final binaries: BetterBackpack.dll + inject.exe.

  README.md                This file. Landing page + nav.
  INSTALL.md               End-user install/use guide.
  TROUBLESHOOTING.md       Failure modes and fixes.
  BUILDING.md              Build, configuration, internals, porting.
  REQUIREMENTS.md          Design spec, research, verification plan.
  SHIPPING-BUILD-NOTES.md  UE5 shipping logging/console quirks.
  inspection-guide.md      Generic UE5 modding methodology + worked examples.
```
