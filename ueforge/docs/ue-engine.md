# UE5 engine reference

> **Authoritative on:** the UE5 platform facts every UE4SS mod
> needs that are not game-specific. Pak / IoStore container
> format, UObject memory layout, shipping-build constraints,
> UE4SS hooking caveats, cooked PropertyTag serialisation, the
> community ecosystem and tooling.
>
> For game-specific offsets and exes see each game-side mod's
> `engine.md`. For inspection methodology (worked examples on
> third-party mods) see [`inspection.md`](inspection.md).

## Pak / IoStore container

UE5 ships content in IoStore: paired `.utoc` (table-of-contents)
+ `.ucas` (content) files, sometimes alongside a legacy `.pak`.
The typical UE5 game has:

| File | Role |
| ---- | ---- |
| `<game>/Content/Paks/<game>.{pak,ucas,utoc}` | Base game container |
| `<game>/Content/Paks/global.{ucas,utoc}` | Engine-side global container |

Container metadata to check via `retoc info <utoc>`:

- **`container_flags`** -- presence of `Encrypted` indicates an
  AES key is required; absence (`0x0` / `Indexed` only) means
  every standard UE5 tool reads it directly.
- **TOC version** -- e.g. `ReplaceIoChunkHashWithIoHash` is the
  latest schema.
- **Container header version** -- e.g. `SoftPackageReferencesOffset`
  is the latest.
- **Mod mount point** -- typically `../../../` (standard UE
  relative-from-Paks path; resolves into `/Game/...`).

### Patch pak naming

UE patch paks follow `<name>_<NNN>_P.{pak,ucas,utoc}`:

- `_P` suffix flags the file as a patch pak. UE loads patch
  paks last so they shadow base-game assets at the same path.
- Numeric prefix is the load priority. Higher numbers win when
  multiple mods touch the same asset.
- Patch paks must mirror the project's `<game>/Content/Paks/`
  path or UE will not mount them.

A mod pak only contains the assets it overrides; the base game
is not duplicated. **The file tree IS the change set.**

## UObject layout (UE5 standard)

Stable across UE 5.x:

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

`UFunction` extends `UStruct` (which extends `UField`) and
adds:

| Field | Offset (in UFunction) | Notes |
| ----- | --------------------- | ----- |
| `FunctionFlags` | `+0xB0` | `EFunctionFlags` bitmask |

ueforge models these in
[`ue::offsets`](../src/ue/offsets.rs) and the typed wrappers
in [`ue::uobject`](../src/ue/uobject.rs). For the SDK shim
overview see [`ue-sdk.md`](ue-sdk.md).

## Image-relative offsets (per-platform)

Game-specific. Every UE4SS-Rust mod's per-build offsets land in
a `PlatformOffsets` const (typed by `ueforge::ue::PlatformOffsets`).
Image-base is captured at runtime via `GetModuleHandleW(NULL)`;
each offset is added to it.

The four offsets every mod needs:

| Symbol | Notes |
| ------ | ----- |
| `GObjects` | Walk every UObject |
| `FName::AppendString` | Resolve FName -> string |
| `UObject::ProcessEvent` vtable index | Vtable slot we hook (typically `0x4C` on UE 5.x) |
| `g_world` (optional) | Cached world pointer |

These move across game patches when the binary changes; refresh
by re-running Dumper-7 or by signature-scanning. Each game's
`engine.md` records the current values for its supported
platforms.

## Shipping-build constraints

UE5 shipping builds strip a lot of dev-time infrastructure but
leave the reflection metadata behind. This is misleading:
classes and methods that look available in the SDK are often
not runtime-callable in the shipping binary.

### Console / cheats stripped

`ALLOW_CONSOLE_IN_SHIPPING = 0` is the UE5 default and most
shipping games respect it. Symptoms when shipped this way:

- `-log`, `-LogCmds=`, `-ExecCmds=`, `-EnableCheats`, `-cheats`,
  `-console` command-line flags do nothing.
- `<game>.log` is never created, even though
  `FString ProjectLogDir()` is reflected and
  `<game>/Saved/Logs/` would be the resolved path.
- Tilde / backtick keys do not open a console even though
  `UInputSettings::ConsoleKeys` is populated in
  `DefaultInput.ini`.

The `UConsole` class survives in `GObjects` (reflection is
preserved across shipping config) but the runtime handlers are
compiled out. Same for `UCheatManager` -- UE only instantiates
it on the player controller in non-shipping builds or with
`ALLOW_CHEAT_CHEATS_IN_SHIPPING` defined.

**Practical implication: do not rely on a class existing in
the SDK as proof that it is wired up at runtime.** Test the
behaviour, or hook a known-fired UFunction on the class to
confirm reachability.

### Re-enabling the console (third-party tools)

Any of these surface a console / cheat manager at runtime in a
shipping build. They do not ship with our mods; documented
here as reference:

- **Universal UE5 Unlocker (UUU)** -- generic across UE5 games
- Per-game console-unlocker mods on Nexus (search "console
  unlocker" for the target game)

## UE4SS hooking caveats

These are concrete failures encountered while building mods on
UE4SS. Relevant whenever a new mod tries to ProcessEvent-hook a
UFunction.

### Issue #626 (`Final + BlueprintCallable` UFunctions)

[GitHub issue #626](https://github.com/UE4SS-RE/RE-UE4SS/issues/626).
UE4SS's `RegisterPreHook` / `RegisterPostHook` register cleanly
(logs report `[RegisterHook] Registered native hook (N, N+1)
for ...`) but the callbacks silently never fire when the
engine calls the C++ implementation directly from a native
frame. The hook only swaps `UFunction::native_func`, which is
consulted by BP / ProcessEvent calls -- not by direct C++
dispatch.

Confirmed broken on `Final + Native + BlueprintCallable`
UFunctions the engine calls from its own native code. **Probe
with a Lua RegisterHook + log before assuming the hook is
wired.** ueforge's `ProcessEventHook` uses vtable patching
(not UE4SS's hook surface), so it avoids this caveat -- but
hooks installed via UE4SS's API hit it.

### Concrete-BP class hooks vs base-class hooks

Per-vtable `ProcessEventHook` matches exact live vtables.
Concrete actors are typically `BP_*_C` subclasses, so a hook
installed on the base class never matches a real instance.
Mods must enumerate known concrete subclasses by name and
install on each. ueforge's `ProcessEventHook::install_many`
handles the per-class fan-out.

### CDO patches don't reach pre-spawned instances

Class Default Object writes propagate to *new* instances, not
to already-spawned ones. The active player pawn at
session-start typically exists before the mod loads, so any
field write that needs to take effect immediately must also
walk live instances and patch them in place.

The `ueforge::ue::class_tweak::ClassFieldTweak<T>` primitive +
the framework's `Player::for_each_live` walker handle this
pattern. See [`data-table.md`](data-table.md) for the analogous
data-table-side primitive.

## Cooked PropertyTag layout (legacy serialisation gotcha)

UE's canonical `FPropertyTag` field order is
`Name, Type, Size, ArrayIndex, ...`. The COOKED legacy
serialisation produced by `retoc to-legacy` from a Zen
container actually emits **`ArrayIndex` before `Size`**: 4-byte
ArrayIndex first, then 4-byte Size. Otherwise the property-tag
header is canonical:

```
offset 0   FName Key   (4 bytes nameIndex + 4 bytes nameNumber = 8 bytes)
offset 8   FName Type  (8 bytes)
offset 16  int32 ArrayIndex
offset 20  int32 Size       (= 4 for an IntProperty)
offset 24  uint8 HasPropertyGuid
[offset 25 if HasPropertyGuid is 0, else +16 for FGuid]
           int32 Value      (the actual value)
```

Relevant for any mod tooling that reads `.uexp` bytes directly
(e.g. ueforge's `read-property` CLI /
`ueforge::uasset::find_int_property` lib).

## General UE5 modding tools

| Tool | Purpose | Source |
| ---- | ------- | ------ |
| **retoc** (CLI) | Probe + unpack `.utoc/.ucas`, Zen<->Legacy round-trip | github.com/trumank/retoc |
| **FModel** (GUI) | Browse paks, export properties to JSON | github.com/4sval/FModel |
| **UAssetGUI** | Byte-level uasset inspection / edit | github.com/atenfyr/UAssetGUI |
| **WinMerge** | Folder / file diff for JSON outputs | winmerge.org |
| **Dumper-7** | Generates the C++ SDK by attaching to a running UE process | github.com/Encryqed/Dumper-7 |
| **UnrealReZen** | Alternative Zen packer (if `retoc to-zen` fails) | github.com/rm-NoobInCoding/UnrealReZen |
| **repak** | Legacy pak packer (companion to retoc) | github.com/trumank/repak |
| **Universal UE5 Unlocker (UUU)** | Re-enables console at runtime in shipping | (third-party DLL) |

`retoc` subcommands actually used:

| Subcommand | Purpose |
| ---------- | ------- |
| `info <utoc>` | Container metadata (chunks, packages, version) |
| `list <utoc>` | Chunk IDs (raw, not directory paths) |
| `to-legacy` | Convert Zen-format IoStore to legacy `.uasset` pak |
| `unpack` | Extract chunks to files |

`to-legacy` is the most useful: it produces a legacy `.pak`
with readable `.uasset/.uexp` files that downstream tools
(UAssetGUI, FModel, kismet-analyzer) all understand directly.

### `retoc to-zen --version` gotcha

When *building* a pak mod for a UE 5.x game from a patched
legacy pak, the `--version` flag passed to `retoc to-zen` is
empirically named, not literal:

| `--version` argument | TOC produced | Matches vanilla? |
| -------------------- | ------------ | ---------------- |
| `UE5_4` | `OnDemandMetaData` / `NoExportInfo` (older) | NO on shipping UE 5.4 |
| `UE5_6` | `ReplaceIoChunkHashWithIoHash` / `SoftPackageReferencesOffset` | YES on shipping UE 5.4 |

Pass the value that makes `retoc info` produce the same TOC
and container-header versions as the vanilla pak, not the one
that matches the engine's claimed version. Treat retoc's
version names as opaque labels.

The legacy-round-trip pipeline used to patch cooked bytes:

```
zen .utoc/.ucas
  -> retoc to-legacy -> .pak (legacy)
  -> patch bytes in .uexp
  -> repak pack -> .pak (legacy, repacked)
  -> retoc to-zen --version UE5_6 -> .pak/.ucas/.utoc (zen)
  -> drop into <game>/Content/Paks/
```

## General UE5 modding guides

- [Buckminster's UE Modding dev-guide](https://buckminsterfullerene02.github.io/dev-guide/)
  -- comprehensive intro including pak handling, patching,
  IoStore packing.
- [Unofficial Modding Guide](https://unofficial-modding-guide.com/posts/uassetmodding/)
  -- UAssetGUI walkthrough, applies to any UE 5.x cooked-asset
  target.
- [UE Modding Tools databank](https://github.com/Buckminsterfullerene02/UE-Modding-Tools)
  -- comprehensive list of reverse-engineering and modding
  tools spanning multiple UE games.
- [Dmgvol/UE_Modding](https://github.com/Dmgvol/UE_Modding)
  -- UE4/5 modding guides repo, includes IoStore packing
  instructions.
- [mod.io UGC Best Practices](https://docs.mod.io/unreal/ugc-best-practices)
  -- Epic's ecosystem partner; useful for understanding what
  cooked-asset patching is officially expected to look like.

## What is NOT available (typical for UE5 shipping titles)

- No official studio modding SDK or API documentation.
- No `.usmap` mappings file shipped with the game; must be
  generated via Dumper-7 or sourced from the community.
- No public C++ headers or Unreal Engine project file from
  the studio.
- Gameplay numbers (drain rates, capacity defaults, damage
  multipliers) are typically scattered across forum threads
  and mod descriptions rather than documented.

## See also

- [ue-sdk.md](ue-sdk.md) -- ueforge's UObject wrappers
- [inspection.md](inspection.md) -- worked examples on third-party UE5 mods
- [lifecycle.md](lifecycle.md) -- mod load / unload / hot-reload
- [hooks.md](hooks.md) -- ProcessEvent + vtable patching
