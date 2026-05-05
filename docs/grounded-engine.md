# Grounded 2 engine and platform

> **Authoritative on:** Grounded 2's modding surface at the platform
> level. Engine version, container format, AES, exe names per
> platform, GObjects layout, shipping-build constraints, Vortex
> deployment quirks. Anything that is true of the *game* rather than
> of *our mod*.
>
> For damage internals see [`damage.md`](damage.md). For inventory
> internals see [`inventory.md`](inventory.md). For RPG mechanics see
> [`rpg.md`](rpg.md). For our build / loader story see
> [`building.md`](building.md) and [`ue4ss-port.md`](ue4ss-port.md).

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

The Steam binary is the bootstrap shim. UE engine version is inferred
from container metadata on disk (no encrypted boot).

## Pak / IoStore container

Grounded 2 ships a single monolithic base pak with no patch paks
shipped to date.

| File | Role |
| ---- | ---- |
| `Augusta\Content\Paks\Augusta-WinGRTS.{pak,ucas,utoc}` | Base game (~32 GB, 61,449 packages, 100,196 chunks) |
| `Augusta\Content\Paks\global.{ucas,utoc}` | Engine-side global container |

Container metadata:

- **`container_flags = 0x0` / `Indexed`** -- the Encrypted flag is
  absent. **No AES key is needed**. retoc / FModel / UModel can read
  everything directly with no key configuration.
- **TOC version**: `ReplaceIoChunkHashWithIoHash` (latest IoStore TOC
  schema)
- **Container header version**: `SoftPackageReferencesOffset`
  (latest)
- **Mod mount point** for patch paks: `../../../` (standard UE
  relative-from-Paks path; resolves into `/Game/...`)

Pak naming convention (e.g. `AIOPlayerTweaks_00012_P`):

- `_P` suffix flags the file as a **patch pak**. UE loads patch paks
  last so they shadow base-game assets at the same path.
- Numeric prefix is the load priority. Higher numbers win when
  multiple mods touch the same asset.
- Must mirror the project's `Augusta/Content/Paks/` path or UE will
  not mount the pak.

A mod pak only contains the assets it overrides; the base game is not
duplicated. The file tree IS the change set.

## Image-relative offsets (per-platform)

Required for any DLL-based mod that walks `GObjects` or resolves
`FName` strings without going through UE4SS. Values are
image-relative; the mod fetches `image_base` at runtime via
`GetModuleHandle(NULL)` and adds the offset.

| Symbol | Steam offset | Xbox offset |
| ------ | ------------ | ----------- |
| `GObjects` | `0x09F67028` | `0x09F36F28` |
| `FName::AppendString` | `0x01252060` | `0x01250F80` |
| `UObject::ProcessEvent` vtable index | `0x4C` | `0x4C` |

Probed against `++Augusta+release-0.4.0.2-CL-2673661`. These move
across game patches when the binary changes; refresh by re-running
Dumper-7 or by signature-scanning.

## UObject layout (UE5 standard, confirmed)

| Field | Offset | Notes |
| ----- | ------ | ----- |
| vtable | `0x00` | First field, gives ProcessEvent slot |
| flags | `0x08` | `EObjectFlags` |
| index | `0x0C` | Slot in `GObjects` |
| class | `0x10` | `UClass*` |
| name | `0x18` | `FName` (8 bytes) |
| outer | `0x20` | `UObject*` |
| total size | `0x28` | -- |

`UClass` extends `UObject` and adds:

| Field | Offset (in UClass) | Notes |
| ----- | ------------------ | ----- |
| `ClassDefaultObject` | `+0x110` | The class's CDO |

`UFunction` extends `UStruct` (which extends `UField`) and adds:

| Field | Offset (in UFunction) | Notes |
| ----- | --------------------- | ----- |
| `FunctionFlags` | `+0xB0` | `EFunctionFlags` bitmask |

## Shipping-build constraints

UE5 shipping builds strip a lot of dev-time infrastructure but leave
the reflection metadata behind. This is misleading: classes and
methods that look available in the SDK are often not runtime-callable
in the shipping binary.

### Console / cheats stripped

`ALLOW_CONSOLE_IN_SHIPPING = 0` is the UE5 default and Grounded 2 ships
that way. Confirmed inert in the shipping binary:

- `-log`, `-LogCmds=`, `-ExecCmds=`, `-EnableCheats`, `-cheats`,
  `-console` command-line flags do nothing.
- `Augusta.log` is never created, even though `FString ProjectLogDir()`
  is reflected and `<game>/Augusta/Saved/Logs/` would be the resolved
  path.
- Tilde / backtick keys do not open a console even though
  `UInputSettings::ConsoleKeys` is populated in `DefaultInput.ini`.

The `UConsole` class survives in `GObjects` (reflection is preserved
across shipping config) but the runtime handlers are compiled out.
Same for `USurvivalCheatManager` -- the reflection metadata exists,
the wiring does not, because UE only instantiates `UCheatManager` on
the player controller in non-shipping builds or with
`ALLOW_CHEAT_CHEATS_IN_SHIPPING` defined.

Practical implication: do not rely on a class existing in the SDK as
proof that it is wired up at runtime. Test the behaviour, or hook a
known-fired UFunction on the class to confirm reachability.

### Re-enabling the console (third-party tools)

Any of these surface a console / cheat manager at runtime in a
shipping build. They do not ship with our mod; documented here as
reference:

- **Universal UE5 Unlocker (UUU)** -- generic across UE5 games
- **[Cheat Manager and Console Unlocker](https://www.nexusmods.com/grounded2/mods/70)**
  on Nexus -- Grounded 2-specific
- **[`x0reaxeax/Grounded2Minimal`](https://github.com/x0reaxeax/Grounded2Minimal)**
  -- debug DLL with its own embedded console; we modeled our injector
  after this pattern

## Vortex deployment gotcha

Vortex's Grounded 2 extension has been observed misidentifying the
game's base path on user machines. Sanity check before debugging
"my mod is not loading" in earnest:

```bash
cat "$APPDATA/Vortex/<game>/snapshots/snapshot.json"
```

The `basePath` field is where Vortex thinks the game's `Paks` folder
is. We have seen Vortex point at *Schedule 1's* path while claiming
the user had Grounded 2 mods deployed -- silently meaning zero of
those mods ever applied. Verifying `basePath` is the correct
Grounded-2 install dir is a 30-second sanity check that should be the
first step on any "mod not loading" debug.

## UE4SS hooking caveats observed in Grounded 2

These are concrete failures encountered while building this mod.
Relevant whenever a new mod tries to ProcessEvent-hook a Maine SDK
function.

### Issue #626 (`Final + BlueprintCallable` UFunctions)

[GitHub issue #626](https://github.com/UE4SS-RE/RE-UE4SS/issues/626)
applies to Grounded 2 / UE5. UE4SS's `RegisterPreHook` /
`RegisterPostHook` register cleanly (logs report
`[RegisterHook] Registered native hook (N, N+1) for ...`) but the
callbacks silently never fire when the engine calls the C++
implementation directly from a native frame. The hook only swaps
`UFunction::native_func`, which is consulted by BP / ProcessEvent
calls -- not by direct C++ dispatch.

Confirmed broken in Grounded 2 for:

- `/Script/Maine.SurvivalCharacter:ApplyFallDamage`
- `/Script/Maine.HealthComponent:ApplyDamage`

Likely also broken for any other `Final + Native + BlueprintCallable`
UFunction the engine calls from its own native code. Probe with a
Lua RegisterHook + log before assuming the hook is wired.

### Concrete-BP class hooks vs base-class hooks

Per-vtable `ProcessEventHook` matches exact live vtables. Player
pawns are concrete `BP_SurvivalPlayerCharacter_*` subclasses
(`_Female02_C`, `_Gellarde_C`, etc), so a hook installed on the base
`SurvivalCharacter` or `Character` class never matches a real player
instance. Mods must enumerate known concrete subclasses by name and
install on each.

### CDO patches don't reach pre-spawned instances

Class Default Object writes propagate to *new* instances, not to
already-spawned ones. The active player pawn at session-start
typically exists before the mod loads, so any field write that needs
to take effect immediately must also walk live instances and patch
them in place. Movement skills, fall-damage skill, and inventory
slot count all do this -- see the per-skill arms in `apply.rs`.

## Mod inspection methodology (reference)

For diffing or root-causing third-party Grounded 2 mods at the asset
level, the standard generic-UE5 toolchain works because Grounded 2
has no encryption / no custom container format / no anti-mod measures.
Tools we have used:

- **retoc** -- reads `.utoc/.ucas` and converts back to legacy
  `.uasset/.uexp/.umap`. Used for vanilla baseline extraction and for
  reading mod-pak content without launching the game.
- **FModel** / **UModel** -- GUI explorers for `.utoc/.ucas`. Useful
  for spot-checking what an asset references.
- **UAssetGUI** -- legacy `.uasset` editor. The only tool we have
  found that surfaces Kismet bytecode in mod paks.
- **Dumper-7** -- generates the C++ SDK headers from a running game
  process. Source of every `*_classes.hpp` / `*_structs.hpp` /
  `*_parameters.hpp` we cite. Headers checked in under
  `C:\tools\work\sdk\` on the dev machine.

The seven-phase inspection methodology used during reverse-engineering
sessions (tooling -> inventory -> bulk extract -> vanilla baseline ->
diff -> interpret -> sanity-check) is generic UE5 modding. None of
the steps are Grounded-2-specific; once you have the asset paths and
property names that matter for the behaviour you want to change, the
flow is the same as for any other UE 5.x game.
