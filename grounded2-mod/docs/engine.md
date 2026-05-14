# Grounded 2 engine and platform

> **Authoritative on:** Grounded 2's modding surface at the
> platform level. Engine version, container metadata, exe names
> per platform, image-relative offsets per platform build,
> Vortex deployment quirks, the Grounded 2 mod ecosystem.
> Anything that is true of the *game* rather than of UE5 in
> general or of our mod.
>
> Generic UE5 / UE4SS material (pak format, UObject layout,
> shipping-build constraints, UE4SS hooking caveats, cooked
> PropertyTag layout, the standard tool list) lives in
> [`../../ueforge/docs/ue-engine.md`](../../ueforge/docs/ue-engine.md).

## Game baseline

| Property | Value |
| -------- | ----- |
| Engine | UE 5.4+ (confirmed by IoStore TOC version `ReplaceIoChunkHashWithIoHash` and container header `SoftPackageReferencesOffset`) |
| Project name | `Augusta` (Obsidian's internal name) |
| Game version probed | `++Augusta+release-0.4.0.2-CL-2673661` |
| Steam exe | `Grounded2-WinGRTS-Shipping.exe` (the `WinGRTS` platform suffix) |
| Xbox exe | `Grounded2-WinGDK-Shipping.exe` (the `WinGDK` platform suffix) |
| Steam install path | `<Steam>/steamapps/common/Grounded2/` |
| Steam app id | `3104110` |

The Steam binary is the bootstrap shim. UE engine version is
inferred from container metadata on disk (no encrypted boot).

## Container files

```
Augusta\Content\Paks\Augusta-WinGRTS.{pak,ucas,utoc}    ~32 GB base
Augusta\Content\Paks\global.{ucas,utoc}                 engine globals
```

- **No AES key** -- `container_flags = 0x0` / `Indexed`. retoc /
  FModel / UModel read directly with no key configuration.
- **TOC version**: `ReplaceIoChunkHashWithIoHash` (latest)
- **Container header**: `SoftPackageReferencesOffset` (latest)
- Patch paks go under the same `Content/Paks/` path. See
  [`../../ueforge/docs/ue-engine.md`](../../ueforge/docs/ue-engine.md)
  "Patch pak naming" for the `_P` suffix + priority-prefix
  conventions.

## Image-relative offsets (per-platform)

These move across game patches. Re-run Dumper-7 against the new
binary when an update lands.

| Symbol | Steam offset | Xbox offset |
| ------ | ------------ | ----------- |
| `GObjects` | `0x09F67028` | `0x09F36F28` |
| `FName::AppendString` | `0x01252060` | `0x01250F80` |
| `UObject::ProcessEvent` vtable index | `0x4C` | `0x4C` |

Probed against `++Augusta+release-0.4.0.2-CL-2673661`. Live in
`ueforge/src/ue/offsets.rs::{STEAM, XBOX}` const tables.

## Vortex deployment gotcha

Vortex deploys to `<basePath>/Augusta/Content/Paks/<deploymentTarget>/`
where `basePath` is set per-game in Vortex's user config. If
`basePath` points at a sibling folder (a previous Grounded 1
install, an unrelated drive, a copy of the install used for
testing), Vortex deploys mods into a path the running game
never mounts.

Observed in practice: a `basePath` set to a Grounded **1**
install meant Vortex deployed there silently while the user
had Grounded 2 mods deployed. Silently meaning zero of those
mods ever applied. Verifying `basePath` is the correct
Grounded-2 install dir is a 30-second sanity check that should
be the first step on any "mod not loading" debug.

## Community ecosystem (Grounded 2-specific)

No official Obsidian / Grounded 2 modding SDK exists. The
community covers the gap.

### Authoritative Grounded 2 mod pages

- [Player Tweaks](https://www.nexusmods.com/grounded2/mods/13)
 . The primary "AIO + capacity" mod family. Optional Files
  contain the 60-slot data-side bump.
- [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37)
 . UI-side widget mod. Pairs with Player Tweaks. **Broken in
  current shipping** because the host widget it patches
  (`UI_Container_BackpackSide.MaxRows`) is no longer in
  `GObjects`; see [`inventory.md`](inventory.md) for the full
  root-cause.
- [Better Storages](https://www.nexusmods.com/grounded2/mods/25)
 . World chest / storage capacity. Different system from the
  player backpack.
- [MoreInventory_Buggy](https://www.nexusmods.com/grounded2/mods/102)
 . Mount saddlebag size. Different system.
- [Bigger Stacks](https://www.nexusmods.com/grounded2/mods/8)
 . Per-item stack size up to x999.
- [Grounded 2 Command List](https://www.nexusmods.com/grounded2/mods/19)
 . Console command reference.
- [Cheat Manager and Console Unlocker](https://www.nexusmods.com/grounded2/mods/70)
 . Runtime console / cheat manager unlock for shipping.
- [`x0reaxeax/Grounded2Minimal`](https://github.com/x0reaxeax/Grounded2Minimal)
 . DLL-based debug / cheat tool. Source available; useful as
  reference for SDK class names, struct layouts, and offsets.

For the generic UE5 modding ecosystem (retoc, FModel, UAssetGUI,
Dumper-7, etc.) see
[`../../ueforge/docs/ue-engine.md`](../../ueforge/docs/ue-engine.md)
"General UE5 modding tools".

## See also

- [damage.md](damage.md). Grounded 2 damage internals
  (combat / fall / environmental, status-effect data table)
- [inventory.md](inventory.md). Grounded 2 inventory specifics
  (Maine InventoryComponent, WBP_InventoryInterface_C)
- [rpg.md](rpg.md). The RPG mod itself
- [`../../ueforge/docs/ue-engine.md`](../../ueforge/docs/ue-engine.md)
 . Generic UE5 platform reference
- [`../../ueforge/docs/inspection.md`](../../ueforge/docs/inspection.md)
 . Worked examples on inspecting UE5 mods
