# Grounded 2 Mods: inspection, reverse-engineering, and DIY notes

Notes, tooling, and worked examples for inspecting, debugging, and authoring mods for Grounded 2 (Obsidian, Unreal Engine 5.4).

This repo started as a focused investigation of why "Bigger Backpack" stopped working and ended up shipping a working replacement (Better Backpack) plus a generic UE5 modding methodology.

## Contents

- [Quick links](#quick-links)
- [Repo layout](#repo-layout)
- [TL;DR for "I want a bigger backpack"](#tldr-for-i-want-a-bigger-backpack)
- [Tooling installed locally for this work](#tooling-installed-locally-for-this-work)
- [Game build referenced in this doc](#game-build-referenced-in-this-doc)
- [Credits](#credits)

## Quick links

| If you want... | Go to |
|---|---|
| To install and use the Better Backpack mod | [better-backpack/INSTALL.md](better-backpack/INSTALL.md) |
| To diagnose a problem with the mod | [better-backpack/TROUBLESHOOTING.md](better-backpack/TROUBLESHOOTING.md) |
| To build, modify, or port the mod | [better-backpack/BUILDING.md](better-backpack/BUILDING.md) |
| The mod's design + research + verification plan | [better-backpack/REQUIREMENTS.md](better-backpack/REQUIREMENTS.md) |
| The generic UE5 mod inspection methodology | [better-backpack/inspection-guide.md](better-backpack/inspection-guide.md) |
| Why UE5 shipping doesn't write log files | [better-backpack/SHIPPING-BUILD-NOTES.md](better-backpack/SHIPPING-BUILD-NOTES.md) |

## Repo layout

```
grounded2mods/
  README.md                 You are here.
  better-backpack/          The mod.
    README.md               Landing page + nav for everything below.
    INSTALL.md              End-user install/use guide.
    TROUBLESHOOTING.md      Failure modes and fixes.
    BUILDING.md             Build, configuration, internals, porting.
    REQUIREMENTS.md         Design spec, research, verification plan.
    SHIPPING-BUILD-NOTES.md UE5 shipping logging/console quirks.
    inspection-guide.md     Generic UE5 modding methodology + worked examples.
    dllmain.cpp             Main DLL source.
    basic_impl.cpp          Slim Dumper-7 Basic.cpp re-implementation.
    inject.c                Standalone external injector source.
    build.bat               MSVC build script.
  scripts/
    dump_strings.py         Pull readable strings out of cooked .uasset/.uexp.
    read_property.py        Decode a specific UE PropertyTag from a legacy .uasset+.uexp.
```

The repo previously shipped a pak-based prototype of Better Backpack at the top level. That was retired in favour of the DLL because shipping-build verification required runtime injection anyway: there is no `Augusta.log` or in-game console to confirm a pak's effect. The DLL gives us live readout + active patch + retry on reset, all from one artifact. The methodology document was moved to `better-backpack/inspection-guide.md` because the worked examples and SDK research are inseparable from the mod's design.

## TL;DR for "I want a bigger backpack"

The player's main backpack capacity is controlled by:

```
Class:     Maine.UInventoryComponent
Property:  int32 DefaultMaxSize  (offset 0x01E0)
```

`BP_SurvivalPlayerCharacter` instantiates a main `InventoryComponent` (40 vanilla) and a `MountInventoryComponent` (saddlebag) as instanced sub-objects. To grow the main backpack, override `DefaultMaxSize` on the main `InventoryComponent` sub-object's CDO defaults.

The plain "AIO Player Tweaks v13.1.6" Nexus mod does NOT do this (verified: main backpack stays at 40, only saddlebag is bumped to 48). The "60-slot" variant in the same mod's Optional Files does this single byte-level override. See [better-backpack/inspection-guide.md](better-backpack/inspection-guide.md) for the byte offset and the exact one-shot patch.

For a working implementation, see [better-backpack/](better-backpack/): a tiny DLL that walks `GObjects` for every `UInventoryComponent` owned by `BP_SurvivalPlayerCharacter*` and patches `DefaultMaxSize` from 40 to 60. It also patches `UUI_InventoryGrid_C.MaxRows` (offset `0x0388`) on every grid CDO and live instance so the visible grid scales to 6 rows. Ships its own injector. Build, launch the game, load a save, run `inject.exe`. Done.

## Tooling installed locally for this work

```
C:\Tools\retoc\retoc.exe                      v0.1.5    (CLI Zen IoStore packer)
C:\Tools\repak\repak.exe                      v0.2.3    (CLI legacy pak packer)
C:\Tools\FModel\FModel.exe                    Dec 2025  (GUI cooked-asset browser)
C:\Tools\work\sdk\                            Dumper-7  (Grounded 2 v0.4.0.2 SDK headers)
C:\Tools\work\sdk_research\Grounded2Minimal\  reference (DLL-injection pattern + logging)
Visual Studio 2022 Community                            (cl.exe v14.x for the DLL build)
```

The first three are portable single-binary downloads from GitHub releases. The Dumper-7 SDK and Grounded2Minimal sources came from the credited repos. VS2022 Community is the standard MSVC toolchain.

## Game build referenced in this doc

```
Grounded 2 Steam build, version ++Augusta+release-0.4.0.2-CL-2673661
UE 5.4 (TOC version ReplaceIoChunkHashWithIoHash,
         container header SoftPackageReferencesOffset)
Unencrypted IoStore. Standard UE5 modding tooling applies as-is.
```

## Credits

This investigation stands on the shoulders of a lot of community work. Where we used something, we cite it.

### Game-specific reverse engineering

- **x0reaxeax** for [Grounded2Minimal](https://github.com/x0reaxeax/Grounded2Minimal) and [G2Dumper](https://github.com/x0reaxeax/G2Dumper). The Dumper-7 SDK release artifact for Grounded 2 (v0.4.0.2) gave us every class, struct, enum, and property name in the game. Without that we would still be guessing.
- **RLGingerBiscuit** for [G2Utils](https://github.com/RLGingerBiscuit/G2Utils), which corroborated class names and inventory component bindings.

### Generic UE5 modding tooling

- **Trumank** for [retoc](https://github.com/trumank/retoc) (Zen IoStore packer/unpacker) and [repak](https://github.com/trumank/repak) (legacy pak packer). These two tools did all the heavy lifting on the pak side. License: MIT.
- **4sval** for [FModel](https://github.com/4sval/FModel), the canonical cooked UE asset browser. Used for visual inspection and JSON property exports.
- **atenfyr** for [UAssetGUI](https://github.com/atenfyr/UAssetGUI), the canonical cooked-uasset editor.
- **Encryqed** for [Dumper-7](https://github.com/Encryqed/Dumper-7), the SDK generator that produced the headers we relied on.
- **rm-NoobInCoding** for [UnrealReZen](https://github.com/rm-NoobInCoding/UnrealReZen), an alternative Zen packer kept on the shelf as a backup if retoc misbehaves.

### Modding guides and methodology

- **Buckminsterfullerene02** for the [UE Modding Tools databank](https://github.com/Buckminsterfullerene02/UE-Modding-Tools) and the [comprehensive UE modding dev guide](https://buckminsterfullerene02.github.io/dev-guide/Basis/DealingWithPaks.html).
- **Dmgvol** for [UE_Modding](https://github.com/Dmgvol/UE_Modding), including the IoStore packing reference.
- The community behind the [Unofficial Modding Guide](https://unofficial-modding-guide.com/posts/uassetmodding/) for the UAssetGUI walkthrough.

### Inspiration

- The Grounded 2 Nexus modding community, in particular the authors of:
  - [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37) (broken in current build, but the inspiration for the "Better Backpack" project here).
  - [Player Tweaks](https://www.nexusmods.com/grounded2/mods/13), whose 60-slot Optional File showed the technique.
  - [Bigger Stacks](https://www.nexusmods.com/grounded2/mods/8), [Better Storages](https://www.nexusmods.com/grounded2/mods/25), and [MoreInventory_Buggy](https://www.nexusmods.com/grounded2/mods/102) for breadth of how the modding community covers different inventory subsystems.

### Game

- [Grounded 2](https://grounded2.obsidian.net/) by Obsidian Entertainment. We modify only what the official game ships under fair-use modding norms; no game assets are redistributed in this repo.
