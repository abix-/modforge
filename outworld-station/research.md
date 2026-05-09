# Outworld Station - Modding Research

## Game basics
- Install: `C:\Games\Steam\steamapps\common\OutworldStation\`
- Shipping exe: `OutworldStation\Binaries\Win64\OutworldStation-Win64-Shipping.exe`
- Engine: **Unreal Engine 5.4.4** (from exe FileVersion / ProductVersion)
- Project name: `OutworldStation`
- Layout: standard UE packaged-game (`Engine/`, `OutworldStation/`, `Manifest_*FSFiles_Win64.txt`)

## Anti-cheat / DRM
- No `EasyAntiCheat*` folder anywhere in install tree
- No `BattlEye*` folder anywhere in install tree
- Steam DRM only (assumed - to confirm by checking exe with a DRM scanner)
- No anti-tamper signing observed
- Implication: dll injection / proxy dll loaders are not blocked at the AC layer

## Asset packaging
- `OutworldStation\Content\Paks\`:
  - `global.utoc` / `global.ucas` (IoStore global)
  - `OutworldStation-Windows.utoc` / `.ucas` (~1.89 GB main IoStore container)
  - `OutworldStation-Windows.pak` (~40 MB legacy pak)
- IoStore is the primary format (UE5 default). Legacy .pak is small, likely shader/config.
- AES key: unknown. May or may not be encrypted - to test by attempting unpack.

## No plugins folder
- `OutworldStation/Plugins/` does not exist - the game ships no third-party plugin slot,
  but UE always loads dlls from `OutworldStation/Binaries/Win64/`, which is what UE4SS uses.

## UE4SS compatibility (vs Grounded 2 workflow)
- UE4SS supports UE 5.0 - 5.4+ despite the "UE4" name
- Drop point: `OutworldStation\Binaries\Win64\` (same pattern as Grounded 2)
- Loader: `dwmapi.dll` proxy (default UE4SS) or `xinput1_3.dll`
- Lua scripting + C++ mod API both supported on 5.4

## Existing mod analysis: "Better Item Stacks" (Nexus mod #1)

Downloaded and unpacked `Better Item Stacks-1-1-1778146880.zip`. Contents:

```
BetterStack_P/
  BetterStack_P.pak    347 B
  BetterStack_P.ucas    77 KB (Oodle-compressed payload)
  BetterStack_P.utoc   457 B (table of contents)
```

### How it works
- Pure **IoStore patch pak** mod. No DLL, no Lua, no UE4SS.
- `.utoc` magic `-==--==--==--==-` = standard UE5 IoStore container
- `.utoc` contains plaintext path: `OutworldStation/Content/Data/DT_Materials.uasset`
  - Single asset modified
  - `DT_` prefix = UE convention for **DataTable**
  - Item stack sizes are rows in this DataTable
- `_P` suffix = UE "patch pak" convention. The IoStore loader loads patch paks last,
  so any asset path that exists in both base and patch is overridden by the patch.
- `.ucas` payload high-entropy = Oodle compression (IoStore default), not encryption
- `.utoc` directory is plaintext = **no AES encryption** on this mod, and base game
  must also be unencrypted (a patch pak must match the base key).

### Workflow the mod author used (inferred)
1. Extract `DT_Materials.uasset` from base game IoStore container with FModel or retoc
2. Edit DataTable values (stack sizes) - probably in UE Editor or a UAsset editor
3. Cook/repack into a new `_P` IoStore container (`.pak` + `.ucas` + `.utoc` triplet)
   using UnrealPak / IoStore / `retoc`
4. Ship the three files. User drops them in `Content/Paks/` (or `~mods/`).

### Install location (no readme shipped)
- Standard: `OutworldStation\Content\Paks\` directly, or
- Cleaner: `OutworldStation\Content\Paks\~mods\BetterStack_P\` if the game's PakLoader
  honors `~mods` subfolder convention (most UE5 games do)

### Implications for our toolchain
- For pure stat/data tweaks: no UE4SS needed, `_P` patch pak is the simplest path
- For behavior changes (logic, hooks, new features): UE4SS still required
- Tools we'll likely want:
  - **FModel** for asset inspection (GUI, read-only)
  - **retoc** (Rust) for IoStore read/write - fits our repo's Rust toolchain
  - **UnrealPak.exe** from a UE 5.4 source/binary build for repacking if retoc gaps exist

## UE4SS compatibility on UE 5.4

- UE4SS officially supports UE 4.12 through UE 5.7 (per deepwiki / GitHub releases)
- UE 5.4 is explicitly listed as supported
- "Goal is not plug-n-play with every game" - per-game tuning may be needed
- Drop point on this game: `OutworldStation\Binaries\Win64\` next to the shipping exe
- Default loader proxy: `dwmapi.dll`

## Open questions / next steps
1. Install UE4SS (latest release) into `OutworldStation\Binaries\Win64\`, launch game,
   check `Output.log` and `UE4SS.log` for successful UObject dump on UE 5.4.4
2. If UObject dump works: dump CXX Headers + AOB templates as starting reference
3. Unpack base game IoStore (`OutworldStation-Windows.utoc`) with retoc to confirm
   no AES encryption and to extract `DT_Materials.uasset` for comparison with the mod
4. Confirm `~mods` subfolder support - drop BetterStack_P there and verify the buff applies
5. Decide first mod target once we've seen what's in the asset tree (could be a value
   tweak doable as a `_P` pak, or could need UE4SS hooks)
6. Check whether game has any online component (multiplayer / leaderboards) - affects
   how invasive we can be

## Folder convention for this repo
- Following the `better-backpack/` pattern from Grounded 2 work
- Once we pick a first mod target, create `outworld-station/<mod-name>/` as the Rust crate
- Shared shim/injector code from `injector/` and `archive/winhttp-proxy/` may be reusable
