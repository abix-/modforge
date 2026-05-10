# Outworld Station - Modding Research

## Stack tweaks shipped (2026-05-09)

First feature live in-game: every `DT_Materials` row's
`MaxCanStack` is bumped 4x at mod load. Verified end-to-end via
the live game — Titanium_Ore goes from 500 to 2000, etc. Pure
runtime DLL injection, no pak.

### How it works

`tweaks/src/stacks.rs` spawns a worker thread from
`on_unreal_init` that polls for `DT_Materials` (up to 30s).
Once present, it walks every row via `ueforge::ue::datatable::iter_rows`
and writes `cur * 4` to `row + 0x48` (the `FSMaterialData::MaxCanStack`
field, layout from the SDK dump's `SpaceSalvageStation.hpp`).
Equipment items at `cur <= 1` are skipped so non-stackable items
stay non-stackable.

### Why timing matters (the cache-propagation finding)

Critical lesson from this game: **DataTable mutations only
propagate cleanly when done before any game code copies from the
DT.** Per UE4SS docs, DataTable reads return *copies* of the row
struct. UI widgets like `UI_Item.MaterialData` (offset 0x3C0,
size 0x170) hold their own copy by value, populated at widget
creation. Mutating the DT after widgets exist leaves them stale.

Concrete behavior we observed:
- Run a test that mutates `DT_Materials.MaxCanStack` 4x AFTER
  loading a save → in-memory DT shows 1000, but in-game
  inventory tooltips still show 250 (UI widgets cached at slot
  spawn).
- Run the same mutation in `on_unreal_init` (before any save
  loads) → inventory shows 1000 from the start. UI widgets cache
  the post-mutation value.

This is why the existing community "Better Item Stacks" mod
chose a `_P` pak: paks override `.uasset` on disk so the
DataTable loads with modded values and there's no caching window.
We achieve the same effect via DLL by mutating early enough that
no widget has copied yet.

### The pattern, reusable

For any DataTable-backed value tweak in any UE game:
1. Find the DataTable + row-struct field offset (SDK dump grep).
2. Spawn a worker from `on_unreal_init` that polls for the DT.
3. On first sight, write all rows.
4. One pass is enough — DT memory persists for the session,
   later widget creations cache the mutated values.

Belt-and-suspenders for cases where polling-on-init isn't enough
(some DTs lazy-load on first use): hook
`UFunctionWeWantToOverride` via UE4SS-style RegisterPostHook and
override the return value directly. Bulletproof against any
caching path. Backlog item — not needed for stacks since on-init
mutation works for OWS.

## Bootstrap status (2026-05-09)

Per-game prerequisites (see `ueforge/README.md` "Bootstrapping a
new game" for what each item means):

| Item | Status | Detail |
|---|---|---|
| Engine version | known | UE 5.4.4 (from exe FileVersion) |
| Anti-cheat | none observed | no EAC / BattlEye folders in install |
| UE4SS installed | yes | `OutworldStation\Binaries\Win64\ue4ss\` — main HEAD commit `06474186`, built 2026-05-08 |
| `UE4SS.lib` regenerated for this DLL | yes | ~4063 exports; commit `6246b90` |
| Mod scaffold | yes | `outworld-station/tweaks/` (multi-mod) |
| `/debug` endpoint live | yes | `127.0.0.1:17172`, smoke test passes 3/3 |
| SDK dump | yes | `OutworldStation\Binaries\Win64\ue4ss\CXXHeaderDump\` (956 .hpp files, 8.4 MB) |
| PlatformOffsets filled in | yes | g_objects=0x07A938D0, append_string=0x010DF9D0, process_event=0x012AF540, layout=WrappedChunked |
| Stack mod (4x via DLL) | **shipped** | `tweaks/src/stacks.rs`, fires from `on_unreal_init` |
| First mod target | done | item stack tweaks live |

Until the SDK dump runs, `walk_class` / `read_bytes` /
`write_bytes` / `call` all error with `"ueforge: ue runtime not
initialized"`. The control plane works; it just can't see
into UE memory yet.

## TODO / research questions

Priority order is **SDK dump first, scanner deferred until we
hit a real wall.** Reasoning logged in chat 2026-05-09: the
dump answers "what's the shape of UE state" with one game
launch + grep; the scanner answers "where is THIS value RIGHT
NOW" but requires repetitive in-game manipulation per field.
Per-field cost: ~30 seconds with the dump vs 20-30 minutes with
the scanner. SDK dump wins on info density by a wide margin for
~95% of UE mod work. Scanner becomes the right tool only for
non-UObject memory (allocator buffers, save blobs, CVars,
bitfields the dumper flattens) — and we don't yet know which of
those OWS will need until we try. So:

1. Active task: SDK dump (procedure below).
2. Deferred until we hit a wall: Cheat-Engine-style scanner
   (sketch below — build it the first time the dump leaves us
   stuck, not before).

### SDK dump procedure (active — do this next)

1. Edit `OutworldStation\Binaries\Win64\ue4ss\UE4SS-settings.ini`:
   in `[CXXHeaderGenerator]` set
   `DumpOffsetsAndSizes = 1`,
   `KeepMemoryLayout = 1`.
2. Launch Outworld Station once, wait for the main menu, quit.
3. UE4SS writes `OutworldStation\Binaries\Win64\ue4ss\UEHeaderDump\`
   (thousands of `.hpp` files) plus an offsets summary file.
4. Copy `g_objects`, `append_string`, `g_names`, `g_world`,
   `process_event` (image-relative addresses) into
   `outworld-station/tweaks/src/lib.rs::STEAM`.
5. Rebuild + redeploy with `outworld-station/tweaks/scripts/deploy.ps1 -Install`.
6. Re-run smoke + run `explore_datatables` — `walk_class`
   should now flip to `ok=true` and print the DataTable list.

### Cheat-Engine-style memory scanner (DEFERRED)

Build only after the SDK dump is done AND we've hit a concrete
case the dump can't answer. Sketch kept here so the work is
ready to start when justified, not now.

Pattern for the stack-mod case (illustrative; we'll do it via
the dump instead):
- Pick up items in-game until inventory shows max = 50
- Test scans memory for `u32 == 50`, gets thousands of addrs
- Drop one item (max becomes 49 in the slot, or stays 50 in
  the row, or some don't change at all)
- Rescan for `u32 == 50` or `decreased_by_1`, narrows the
  survivor list
- Repeat 1-2 more times → handful of addrs left
- For each addr: `read_bytes` 256 bytes either side, eyeball
  the surrounding fields to identify the class membership
- Confirm by writing 200, see which addr changes the in-game
  stack ceiling

Implementation sketch, ~200 LoC in ueforge:
- `ueforge::ops::scan_memory { value_type: "u32"|"f32"|...,
   value, bounds?, regions?: ["private"|"image"|...] }`
   → up to N matched addresses + session_id
- `ueforge::ops::scan_rescan { session_id, mode: "exact"|"changed"
   |"decreased"|"increased", new_value? }`
- `ueforge::ops::freeze { addr, value_type, value, hz }` /
  `unfreeze` / `freeze_list`

Builds on `ueforge::winproc::process_regions_json`'s region
walker. `read_bytes` / `write_bytes` already cover per-addr ops.

Status: backlog. Not blocking; build when actually needed.



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
- First mod crate: `outworld-station/tweaks/` — a multi-mod bundle
  (stack-size adjustments first, more tweaks layered on the same
  scaffold over time)
- Shared shim/injector code from `injector/` and `archive/winhttp-proxy/` may be reusable

## First mod target: stack tweaks (multi-mod foundation)

The first feature in `outworld-station/tweaks/` is item-stack
adjustments — reproduce/extend the existing community "Better Item
Stacks" approach, but as a runtime mod via ueforge instead of a
static `_P` pak. Why: a runtime mod gives us live introspection
+ test-driven development for every subsequent tweak we add.

### Full TDD loop, validated against current ueforge

1. **Find the DataTable** — `ueforge::ue::datatable::find_by_short_name("DT_Materials")`
   or test-side via `walk_class("DataTable") + filter by name`. ✅
2. **Iterate rows** — `ueforge::ue::datatable::iter_rows(table)` yields
   `(FName-u64, row_ptr)`. Test resolves FName u64 -> string via
   `ueforge::ue::FName::to_string`. ✅
3. **Identify stack offset** — parameter sweep via `read_bytes`
   on a known row pointer at small offsets (4, 8, 12, ...). The
   one whose value matches the in-game stack max (50, 100, etc.)
   is the offset. Test code; no ueforge gap. ✅
4. **Mutate** — `write_bytes(addr_of_row, stack_offset, u32_bytes)`. ✅
5. **Verify** — `read_bytes` round-trip + in-game pickup test by
   reading inventory state via `walk_class` / `read_bytes` on the
   player's `UInventoryComponent`. ✅
6. **Persist across world loads** — install a `ProcessEventHook`
   on a hot UFunction (e.g. movement multicast); inside the
   trampoline, drain `PE_QUEUE` and re-apply patches if the
   "applied for this slot" flag is unset. ✅
7. **Test infrastructure** — `ueforge_client::Api<TweaksSnapshot>` for
   the integration tests; `ueforge_client::perf::PerfLog` for any
   timing / leak research. ✅

Every step above maps to a `ueforge::*` or `ueforge_client::*` API
that exists today. The only mod-side code is:
- `Snapshot` struct with the fields tests assert against
- `op_*` handlers for game-specific actions (e.g. `apply_stacks`)
- The drain-site PE trampoline
- Game-specific selector resolvers (`live_player` etc.)
- The `cpp/shim.cpp` (~30 LoC inheriting `RC::CppUserModBase`)
- The `build.rs` (~10 LoC calling `ueforge_build::CppShim`)

### Subsequent tweaks layer on the same scaffold

Once `tweaks` has a working `/debug` endpoint + drain trampoline:
- Hunger / thirst rate tweaks: same pattern, different DataTable / CDO field
- Inventory slot count: write to `UInventoryComponent.DefaultMaxSize`
- Movement / fall-damage tweaks: `write_bytes` to character CDOs
- Anything driven by a UE DataTable is a row-write away
- Anything driven by a UFunction is a `call` op away

No new infrastructure per tweak — they're all test-file changes
plus a snapshot field per observable.

## Shared `ueforge` crate (extracted 2026-05-09, fully populated)

Generic UE-mod control plane factored out into the workspace
so the OWS mod scaffold gets it for free:

- `ueforge` (rlib, ~2030 LoC across 18 files):
  - `server` — tiny_http listener + dispatch
  - `envelope` — `OpResponse<S>` + `parse_request`
  - `args` — JSON arg helpers
  - `pe_queue::Queue` — game-thread job queue with re-entrance guard
  - `selector` — generic `addr:0x...` / `first_class:Foo`
  - `hex` — encode/decode
  - `ops` — `read_bytes`, `write_bytes`, `walk_class`, `exec_call`
  - `counters` — `bump` / `observe_peak` / `time_scope` / `TimeScope`
  - `ring` — bounded drop-oldest ring buffer for hook events
  - `winproc` — Windows process introspection (threads, CPU, regions,
    memory, thread-module sampler)
  - `ue` — UObject/UClass/UFunction/FName/FString/TArray/GObjects/
    Platform offsets, plus `ue::probe` (gobjects_population,
    class_outer_samples)
- `ueforge-client` (rlib, ~240 LoC):
  - `Api<S>` — generic blocking HTTP test client
  - `OpResponse<S>` — wire deserializer
  - `hex` + `parms` — codec + `#[repr(C)]` parm round-trip

OWS mod will only own: a `Snapshot` type, the drain-site PE trampoline
(once we know which UFunction is hot enough to drain on UE 5.4.4 OWS),
and game-specific selector resolvers (`live_player` etc.). Everything
else is `use ueforge::*`.

## Parity audit: research + TDD infrastructure DRY in ueforge

Vision: every research and test capability the
`runtime-control-http` skill describes lives once in
`ueforge` / `ueforge-client`. New UE-game mods bring only game-specific
state shape + handlers.

| Capability                                        | Status | Where                                           |
|---------------------------------------------------|--------|-------------------------------------------------|
| `POST /<endpoint>` command-shaped HTTP            | done   | `ueforge::server`                                 |
| `OpResponse<S>` envelope (full snapshot every reply) | done | `ueforge::envelope`                               |
| Game-thread queue + re-entrance guard + lock-free fast path | done | `ueforge::pe_queue::Queue`                  |
| 5 generic primitives (`snapshot`, `read_bytes`, `write_bytes`, `call`, `walk_class`) | done | `ueforge::ops` |
| Selector grammar (`addr:0x...`, `first_class:...`) | done   | `ueforge::selector`                               |
| Hex codec (mod + test sides)                      | done   | `ueforge::hex`, `ueforge_client::hex`               |
| `#[repr(C)]` parm round-trip helpers              | done   | `ueforge_client::parms`                           |
| Hot-path counters (`bump`, `observe_peak`, `time_scope`, `TimeScope`) | done | `ueforge::counters`           |
| Bounded ring buffer for hook events               | done   | `ueforge::ring`                                   |
| UE SDK (UObject/UClass/UFunction/FName/FString/TArray/GObjects/offsets) | done | `ueforge::ue`                  |
| UE introspection (`gobjects_population`, `class_outer_samples`) | done | `ueforge::ue::probe`                  |
| Win32 process probes (threads, CPU, regions, memory, thread sampler) | done | `ueforge::winproc`                |
| Test client (`Api<S>`, `try_connect`, `op`, `op_ok`, `snapshot`, `call_ufunction`) | done | `ueforge_client::Api`     |
| File + console DLL logger (AllocConsole / GetModuleFileNameW) | done | `ueforge::log`                            |
| PE / vtable hook framework (`vtable::write_slot`, RAII `ProcessEventHook`, lock-free registry) | done | `ueforge::hook` |
| UE4SS C++ shim layout-critical mirror (`CppUserModBase`, `UE4SSProgram` imgui bridge) | done | `ueforge/cpp/ueforge_cppusermodbase.hpp`, `ueforge_imgui_bridge.hpp` |
| `build.rs` glue (`CppShim::new().source(...).imgui_dir(...).ue4ss_lib_dir(...).compile()`) | done | `ueforge-build` (rlib build-dep). Embeds shared headers via `include_str!`, drops them into `OUT_DIR/ueforge_cpp/` at build time. Game's build.rs ~10 LoC. |
| Test perf-log writer (`PerfLog` tee + `perf-runs/<name>-<ts>.txt`) | done | `ueforge_client::perf` |
| `TMap<K,V>` walker (`tmap::slots`, `find_value_by_fname_key`) | done | `ueforge::ue::tmap` |
| `UDataTable` helpers (`find_by_short_name`, `row_value_by_fname`, `iter_rows`) | done | `ueforge::ue::datatable` |
| Settings JSON loader pattern                      | n/a    | game-specific shape — ueforge intentionally doesn't enforce |
| Bench harness                                     | n/a    | not in skill; add when first benchmark exists   |

### What the four gaps would unblock for OWS

- **Slice 9 (PE / vtable hook):** any "intercept UFunction X to capture
  events" research test. Without this OWS would re-derive the
  vtable rewriter under VirtualProtect, the trampoline registry, and
  the `catch_unwind` panic guards from scratch.
- **Slice 10 (UE4SS shim + build glue):** any UE4SS Rust mod has to
  ship `main.dll` exporting `start_mod` / `uninstall_mod` etc. via a
  CppUserModBase mirror. Without slice 10 every mod copy-pastes ~450
  LoC of C++.
- **Slice 11 (perf-log writer):** the leak-research / perf-test
  pattern (`tests/explore_*.rs` tees observations to a gitignored
  per-run file). Without it OWS leak-hunting tests re-derive the
  tee + filename + timestamp mechanics.

### Slices already complete (1-8)

| #  | What                                                            | LoC into ueforge |
|----|-----------------------------------------------------------------|----------------|
| 1  | HTTP server + envelope + arg helpers                           | 174            |
| 2  | PE-thread queue (closures, re-entrance guard, lock-free)       | 150            |
| 3a | Full UE SDK shim                                                | 617            |
| 3b | Selector grammar + 4 generic primitives + hex codec             | 254            |
| 4  | Counter primitives + bounded ring buffer                        | 126            |
| 5  | UE introspection (`gobjects_population`, `class_outer_samples`) | 175            |
| 6  | Win32 process introspection                                     | 812            |
| 7  | Shared test client (`ueforge-client`)                             | 238            |
| 8  | File + console DLL logger                                       | ~140           |

Total reusable infrastructure now: ~2,690 LoC across `ueforge`
(~2,170 LoC, 19 files) and `ueforge-client` (~240 LoC, 3 files).
better-backpack has shed ~2,000 LoC of generic mod plumbing.

### The OWS scaffold once slices 9-11 land

```rust
// outworld-station/<mod>/src/lib.rs
#[unsafe(no_mangle)]
pub extern "C" fn ows_start() {
    ueforge::log::set_dll_module(/* HMODULE captured in DllMain */);
    ueforge::log::init(ueforge::log::Config {
        file_name: "ows.log",
        console_title: "OWS Mod",
        console: cfg!(feature = "console"),
    });
    let settings = load_settings();  // ~10 LoC
    if let Some(port) = settings.debug.http_port {
        ueforge::spawn(
            ueforge::Config { port, endpoint: "/debug", thread_name: "ows-debug" },
            handle_request,
            |msg| ueforge::log::log(format_args!("{msg}")),
        );
    }
    ueforge::hook::install_pe_hook(/* class, function, callback */);  // slice 9
    // ... worker thread spawns ...
}

fn handle_request(body: &str) -> Vec<u8> {
    /* ~30 LoC dispatcher matching ops to ueforge::ops::* + game-specific */
}
```

Plus the C++ shim auto-compiled by ueforge's `build_helpers` (slice 10).
Total mod-side LoC for a working `/debug` endpoint with the full
research surface: ~150-200, not 2,500.

Phase-1 scaffolding plan (when ready):
1. Create `outworld-station/<crate>/` with Cargo manifest + cdylib
   (`name = "main"` for UE4SS Mods/<Name>/dlls/main.dll)
2. Copy/adapt `cpp/shim.cpp` + `build.rs` from better-backpack
3. `src/lib.rs` worker entry; `src/debug.rs` calls `ueforge::spawn(...)`
   with a `Snapshot { /* empty */ }` and `handle()` matching only
   "snapshot" initially
4. `tests/debug_snapshot.rs` smoke test against `OWS_DEBUG_PORT` env var
5. Pick a drain site once UFunctions are dumped via UE4SS
