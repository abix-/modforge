# ueforge

> *Forge UE mods in Rust.* (Renamed from `uespy` once the
> framework outgrew the "spy" framing — it's not a control plane
> anymore, it's the lifecycle owner. `forge` keeps the
> modder-vernacular feel; `ue` prefix because the framework is
> UE-specific.)

**ueforge is the framework every UE4SS Rust mod in this workspace
builds on.** Game crates declare a `ModInfo` and implement
callbacks; ueforge owns the lifecycle (`on_unreal_init`,
`on_shutdown`, per-tab `render`), generates the `extern "C"`
entry points the bundled C++ shim invokes, and ships every piece
of plumbing a UE4SS mod needs — the C++ shim, imgui bridge,
UObject SDK, hook surface, debug endpoint, test client, build
glue, logger, all of it. Game crates supply only what's actually
game-specific: platform offsets, snapshot shape, op handlers,
drain wiring, the content of their UI tabs.

The rule, codified:

> Always change ueforge first. If a need is game-specific, prove it
> first; otherwise it belongs in ueforge. Game-specific code goes on
> top of ueforge, not in parallel to it.

## One crate. No features.

`ueforge = { path = "../ueforge" }` in every dep table:

```toml
[dependencies]      ueforge = { path = "../ueforge" }
[build-dependencies] ueforge = { path = "../ueforge" }
[dev-dependencies]   ueforge = { path = "../ueforge" }
```

Same line three times. ueforge's own `build.rs` compiles the
always-safe C++ (imgui v1.92.1 + `ueforge_ui.cpp`) into a static
lib that cargo links into every consumer — cdylib, test binary,
and build-script binary alike. The UE4SS-touching pieces
(`ueforge_shim.cpp` + UE4SS.lib link) are opt-in via
`ueforge::build::CppShim::new().compile()` in the game's `build.rs`,
and emitted per-cdylib so test and build-script binaries don't
need UE4SS.dll on PATH.

Standard *-sys crate pattern. Nothing special, nothing clever.

## What lives in ueforge (do not reinvent)

| Concern | Where |
|---|---|
| HTTP control plane | `server::spawn`, `Config` |
| Op envelope | `OpResponse<S>`, `parse_request` |
| 5 generic primitives | `ops::{snapshot, read_bytes, write_bytes, walk_class, exec_call}` |
| Selector grammar | `selector::resolve_generic` (`addr:0x...`, `class:`, `first_class:`, `singleton:`) |
| Game-thread queue | `Queue` (re-entrance guard, lock-free fast path, drain stats) |
| PE / vtable hooking | `hook::vtable::write_slot`, `hook::ProcessEventHook` |
| UE SDK | `ue::{UObject, UClass, UFunction, FName, FString, TArray, GObjectsView, find_class_fast, init_runtime}` |
| TMap / DataTable | `ue::tmap`, `ue::datatable` |
| UE introspection | `ue::probe::{gobjects_population, class_outer_samples}` |
| Platform detection | `ue::platform::{host_image_base, host_exe_name, detect}` |
| Counters / timing | `counters::{bump, observe_peak, time_scope, TimeScope}`, `counter!`, `peak!` macros |
| Bounded ring buffer | `ring::Ring<T>` |
| File + console logger | `log::{init, log, set_dll_module, dll_dir}` |
| Win32 process probes | `winproc::{process_threads_json, process_cpu_json, process_regions_json, sample_thread_modules_json, process_memory_json}` |
| ImGui bindings | `ui::{text, button, checkbox, slider_f32, slider_i32, progress_bar, separator, ...}` |
| Mod entry point + tabs | `mod_main::{ModInfo, Tab}`, `ue4ss_mod!` macro |
| C++ shim mirror | `ueforge/cpp/ueforge_cppusermodbase.hpp` |
| ImGui context bridge | `ueforge/cpp/ueforge_imgui_bridge.hpp` |
| Generic factory + DllMain | `ueforge/cpp/ueforge_shim.cpp` (compiled into every mod by default) |
| ImGui C++ bridge | `ueforge/cpp/ueforge_ui.cpp` |
| ImGui vendor | `ueforge/cpp/imgui/` (v1.92.1, matches UE4SS) |
| UE4SS import lib | `ueforge/ue4ss/UE4SS.lib` |

## What's left for game crates to write

| Concern | Game owns |
|---|---|
| `PlatformOffsets` per build | yes — different per UE version, sometimes per platform of the same game |
| `Snapshot` struct + `build_snapshot` | yes — game-specific state shape |
| Op handler dispatcher (`handle()`) | yes — match arm per op |
| Game-specific selectors (`live_player`, `current_save`) | yes — wrap `selector::resolve_generic` |
| Drain-site PE trampoline | yes — pick a hot UFunction per game |
| Tab render bodies | yes — `fn render_tab() { ueforge::ui::text(...); }` |
| `ModInfo` + `ue4ss_mod!` invocation | yes — one static + one macro call |

That's it. Every other UE / UE4SS / ImGui / Win32 / test mechanic
comes from ueforge.

## Bootstrapping a new game

Before any mod for a new UE game can do real work, three external
artifacts have to exist for that specific game build:

1. **A UE4SS install in the game's `Binaries\Win64\` folder.**
   UE4SS is the loader; without it our cdylib never gets called.
   It is game-agnostic — the same UE4SS works on any UE 4.12 - 5.7
   game — but each game's user has to install it locally.
2. **A `UE4SS.lib` import library matched to the installed
   `UE4SS.dll`.** ueforge ships one in `ueforge/ue4ss/UE4SS.lib`,
   generated from a known UE4SS build. If the installed UE4SS is
   from a different build, the mangled C++ symbols may differ
   and link / load will fail. Verify via `dumpbin /exports` and
   regenerate the `.lib` if needed (procedure below).
3. **An SDK dump for the specific game exe.** Until this exists
   the mod's `/debug` endpoint comes up but `walk_class` /
   `read_bytes` / `call` all return
   `"ueforge: ue runtime not initialized"` because the engine's
   global pointers (GObjects, GNames, AppendString, GWorld,
   ProcessEvent) have unknown addresses.

Without all three, a mod can compile and load — but every
research op requires step 3 done first.

### What an SDK dump gives us

Two distinct pieces of information land in the dump:

| Output | Used for | Lives in |
|---|---|---|
| **Image-base offsets** (5-6 hex numbers) | `g_objects`, `append_string`, `g_names`, `g_world`, `process_event` addresses for THIS exe build. Goes into the game crate's `PlatformOffsets`. | `<game>\Binaries\Win64\ue4ss\UE4SSOutput\Offsets.lua` (or similar; varies by dumper) |
| **Class headers** (thousands of `.hpp` files) | Every `UClass` / `UStruct` in the running game with field offsets, function signatures, sizes, inheritance. We grep these whenever we need to know "what offset on `UInventoryComponent` is `MaxStackSize`?" | `<game>\Binaries\Win64\ue4ss\UEHeaderDump\` |

The offsets unlock the runtime — once filled into
`PlatformOffsets`, `walk_class` works and the mod can enumerate
every UObject. The class headers unlock implementation —
they're the reference manual for what's inside each UObject.

### Generating the dump

Two dumpers can produce this. Either works:

- **UE4SS's CXXHeaderGenerator** (built into UE4SS). Edit
  `<game>\Binaries\Win64\ue4ss\UE4SS-settings.ini`, in
  `[CXXHeaderGenerator]` set
  `DumpOffsetsAndSizes = 1`,
  `KeepMemoryLayout = 1`, then launch the game once. Output
  appears under `<game>\Binaries\Win64\ue4ss\UEHeaderDump\`.
- **Dumper-7** (standalone). Inject its DLL into the game,
  produces a parallel set of headers. We used this for
  Grounded 2 (`C:\Tools\work\sdk\`).

Either way: launch the game, wait for main menu, exit. Files
appear. Commit the `Offsets.*` summary into the game's research
notes; the per-class headers are typically too large for git
and live as a local-only reference path.

### Filling in PlatformOffsets

Once the offset file exists, copy the 5-6 image-base values
into the game crate's `lib.rs::STEAM` (and `XBOX`, etc., if
multi-platform):

```rust
const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x09F6_7028,           // <- from dump
    append_string: 0x0125_2060,       // <- from dump
    g_names: 0x09E4_A7B8,             // <- from dump
    g_world: 0x09C7_A2E0,             // <- from dump
    process_event: 0x0146_E7B0,       // <- from dump
    process_event_idx: 0x4C,          // engine-stable across UE 5.x
};
```

Rebuild + redeploy. `walk_class` flips to working. The TDD
research loop begins.

### Regenerating UE4SS.lib

If the installed UE4SS is a different build than what
`ueforge/ue4ss/UE4SS.lib` was generated from:

```pwsh
$DLL = "<game>\Binaries\Win64\ue4ss\UE4SS.dll"
$DEF = "ueforge\ue4ss\UE4SS.def"
$LIB = "ueforge\ue4ss\UE4SS.lib"

# 1. Dump exports
dumpbin /exports $DLL > exports.txt

# 2. Build .def: "LIBRARY UE4SS\nEXPORTS\n    <symbol>\n..." for
#    every exported symbol. The current ueforge/ue4ss/UE4SS.def is
#    a working reference shape.

# 3. Generate the import lib
lib /def:$DEF /machine:x64 /out:$LIB
```

This was done for Outworld Station (UE4SS main HEAD, ~4063
exports), see commit `6246b90`. ABI compatibility verified by
matching mangled names of the symbols we actually use
(`CppUserModBase` ctor/dtor, all 15 virtuals, `register_tab`,
`UE4SSProgram::get_current_imgui_*`).

### Per-game tracking convention

Each game keeps its bootstrap status in a research-notes
markdown under that game's folder. See
`outworld-station/research.md` for the canonical shape:

- Game / engine version
- UE4SS build installed (commit / version)
- UE4SS.lib regenerated for this DLL? (yes/no)
- SDK dump path + dumper used
- PlatformOffsets known? (yes/no)
- First mod target

That doc is what tells the next reader "is this game ready to
mod, or do we have prerequisites missing?"

## Quickstart for a new mod

### Workspace layout

```
your-mods/
  Cargo.toml         # workspace
  ueforge/             # the framework crate
    cpp/imgui/       # vendored ImGui, shared by every mod
    ue4ss/UE4SS.lib  # shared import lib
  ueforge-deploy/      # `cargo deploy ...` CLI (binary crate)
  your-mod/
    Cargo.toml       # see [package.metadata.ueforge] block below
    build.rs         # 1 LoC
    src/lib.rs       # ModInfo + ue4ss_mod!
    src/debug.rs     # Snapshot + handle()
    tests/
```

### `your-mod/Cargo.toml`

```toml
[dependencies]
ueforge = { path = "../ueforge" }                                            # runtime

[build-dependencies]
ueforge = { path = "../ueforge", default-features = false, features = ["build"] }

[dev-dependencies]
ueforge = { path = "../ueforge", features = ["client"] }
```

No `cpp/` directory in `your-mod/` unless you have custom C++.
No `ue4ss/UE4SS.lib`. No imgui copy. No DllMain. No factory exports.

### `your-mod/build.rs`

```rust
fn main() {
    ueforge::build::CppShim::new().compile();
}
```

That's the whole file.

### `your-mod/src/lib.rs`

```rust
use ueforge::ue::PlatformOffsets;

const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x0, append_string: 0x0, g_names: 0x0,
    g_world: 0x0, process_event: 0x0, process_event_idx: 0x4C,
};

const PLATFORMS: &[(&str, &PlatformOffsets)] = &[
    ("YourGame-Win64-Shipping.exe", &STEAM),
];

static MOD_INFO: ueforge::ModInfo = ueforge::ModInfo {
    name: "YourMod",
    version: "0.1.0",
    log_file: "your_mod.log",
    console_title: "YourMod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    tabs: &[
        ueforge::Tab { name: "Tweaks", render: render_tweaks_tab },
    ],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    let image_base = ueforge::ue::platform::host_image_base();
    let offsets = ueforge::ue::platform::detect(PLATFORMS).unwrap_or(&STEAM);
    let _rt = unsafe { ueforge::ue::init_runtime(image_base, offsets) };
    // ... start worker thread, install hooks, spawn debug server
}

fn on_shutdown() {
    ueforge::log::log(format_args!("stopping"));
}

fn render_tweaks_tab() {
    ueforge::ui::text("Tweaks");
    ueforge::ui::separator();
    if ueforge::ui::button("Reload patches") {
        // ...
    }
}
```

That's the full mod skeleton. ~50 LoC.

### `your-mod/src/debug.rs`

See `outworld-station/research.md` and the existing
`better-backpack/src/debug.rs` for the snapshot + dispatcher
pattern.

## TDD pattern

Every feature, every bug, every research question:

1. Concrete user-observable expectation.
2. Snapshot field for the observable.
3. Failing test in `tests/<scenario>.rs` against
   `ueforge_client::Api<Snapshot>`.
4. Use the endpoint to research (`api.snapshot()`,
   `api.op("read_bytes", ...)`).
5. Implement op or fix.
6. Test goes green. Land the test, the op, and any snapshot field
   in one commit.

The skill at `~/.claude/skills/runtime-control-http/SKILL.md`
spells out the full loop. Headline: **research is code, not curl.**
Every experiment lives as a `tests/explore_*.rs` file using the
same `Api<S>` your assertions use, so observations promote
directly to regressions.

## Op set + selectors

Built-in ops (call from tests via `Api::op` or wrappers):

- `snapshot` — returns just the snapshot
- `read_bytes  { instance_selector, offset, length }`
- `write_bytes { instance_selector, offset, bytes_hex }`
- `walk_class  { class, max?, include_cdo? }` → `{ instances }`
- `call        { class, function, instance_selector, parms_hex }`
  → `{ parms_hex_after }` (engine-mutated OUT params)

Selectors:

- `addr:0x<hex>` — raw object pointer
- `first_class:<Name>` / `class:<Name>` — first non-CDO instance
- `singleton:<Name>` — class default object (CDO)
- game-specific shorthand the game adds in its `resolve` fn
  (`live_player`, `current_save`, ...)

## Pattern: DataTable mutation timing

**DataTable reads return copies, not references.** UE4SS's docs
state this explicitly. Game code calls `GetDataTableRow` (or a
game-specific equivalent) and gets back a struct *by value*. Any
field on that struct is a snapshot.

UI widgets and inventory actors typically cache the entire row
struct at creation (e.g. UI_Item holds its own `FSMaterialData`
copy). Once cached, mutating the source DataTable doesn't
update those copies — they're already disconnected.

**Implication for runtime mod design:** if you want a DataTable
mutation to propagate everywhere, do it BEFORE any actor /
widget caches the row. Practical recipe:

```rust
// In your ue4ss_mod's on_unreal_init:
fn on_unreal_init() {
    // ... ueforge::ue::init_runtime ...

    std::thread::spawn(|| {
        // Poll until the DT exists (it loads with the
        // GameInstance, slightly after on_unreal_init fires).
        loop {
            if let Some(dt) =
                ueforge::ue::datatable::find_by_short_name("DT_Foo")
            {
                for (_fname, row) in unsafe {
                    ueforge::ue::datatable::iter_rows(dt)
                } {
                    // SAFETY: caller owns the cast, knows the row
                    // struct's layout. Read with read_unaligned.
                    unsafe {
                        let field = (row.add(MY_OFFSET)) as *mut i32;
                        field.write_unaligned(field.read_unaligned() * 4);
                    }
                }
                return;
            }
            std::thread::sleep(std::time::Duration::from_millis(250));
        }
    });
}
```

Mutating after a save loads — when slots / UI / actors have
already copied the row — leaves cached widgets stale. The DT
itself shows your value, but in-game still shows vanilla. Two
options when this matters:

1. Mutate from `on_unreal_init` (above). Works for ~95% of
   value-tweak features.
2. Hook the `GetData_Foo` UFunction via UE4SS's
   `UFunction::RegisterPreHook` / `RegisterPostHook` (or our own
   `ueforge::hook::ProcessEventHook` filtered by function name).
   Bulletproof against any cache because we intercept at
   call-site. Worth building when (1) doesn't propagate (rare).

Reference implementation: `outworld-station/tweaks/src/stacks.rs`
ships this pattern for the OWS stack-size mod. 4x bump that
matches the existing community "Better Item Stacks" pak mod's
effect — but via runtime DLL, so other features in the same mod
can layer on top dynamically.

## Audit: ueforge vs better-backpack vs ows-tweaks

Three-way map of every load-bearing feature across the
framework and the two consumer mods. Use this when deciding
"does this belong in ueforge, in the game crate, or somewhere
else?". Update on every major slice.

**Legend (per cell):**

- ✅ = lives here, this is the canonical home
- 📦 = lives here and *should* live here (game-specific)
- 🟡 = duplicates a ueforge facility — **migrate to ueforge** then delete
- 🔵 = doesn't exist in ueforge yet but **should be promoted**
- · = consumes ueforge's version (correct pattern)
- — = not applicable / N/A

**Verdict column:** the work item that gets it to a stable home.

### Lifecycle / loader plumbing

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 1 | `ModInfo` + `ue4ss_mod!` macro | ✅ | 🟡 (own `lib.rs` shim + DllMain) | · | **bbp:** migrate to `ue4ss_mod!`, delete custom shim |
| 2 | C++ shim (`CppUserModBase` mirror, factory, `DllMain`) | ✅ (`ueforge_shim.cpp`) | 🟡 (`better-backpack-cpp`-style shim) | · | **bbp:** drop custom shim, use `CppShim::compile()` |
| 3 | HMODULE capture + `dll_dir()` | ✅ (`log::set_dll_module`) | 🟡 (own `DLL_HMODULE`) | · | **bbp:** delete, route through ueforge |
| 4 | File + console logger | ✅ (`ueforge::log`) | 🟡 (own `log.rs` + `bbp_log!` macro) | · | **bbp:** keep `bbp_log!` as a thin wrapper, delete the sink |
| 5 | Settings JSON load / atomic save | ✅ (`Settings<T>`) | 🟡 (own `settings.rs`) | · | **bbp:** migrate to `Settings<RpgSettings>` |
| 6 | Counter primitives + macros | ✅ (`counter!`, `peak!`, `time_scope`) | 🟡 (own `counters.rs` mirroring this) | · | **bbp:** delete, re-export from ueforge |
| 7 | Bounded ring buffer | ✅ (`Ring<T>`) | · (uses for `DAMAGE_RING`) | — | done |

### UObject SDK

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 8 | `UObject` / `UClass` / `UFunction` wrappers | ✅ | 🟡 (own `sdk/` module) | · | **bbp:** delete `sdk/`, use `ueforge::ue` |
| 9 | `FName` / `FString` | ✅ (with FName→string cache) | 🟡 (own duplicates) | · | **bbp:** delete |
| 10 | `TArray` / `TMap` walkers | ✅ | 🟡 | · | **bbp:** delete |
| 11 | `GObjectsView` (flat + chunked) | ✅ | 🟡 (flat-only, pre-cleanup) | · | **bbp:** delete |
| 12 | `find_class_fast` (now name-cached) | ✅ | 🟡 | · | **bbp:** delete |
| 13 | `find_by_short_name` (DataTable) | ✅ | — | · | done |
| 14 | `FieldTweak<T>` (vanilla snapshot + idempotent re-apply) | ✅ | 🔵 fits `BackpackSlots` apply | · (`stacks.rs`) | **bbp:** rewrite `patch::run` on top |
| 15 | DataTable polling worker (`on_first_sight`) | ✅ | — | · | done |
| 16 | Native-property walker (`UClass::cached_native_properties`) | ✅ | — | · (via `inspect_address`) | done |
| 17 | UE introspection probes (`gobjects_population`, `class_outer_samples`) | ✅ | · | — | done |

### Hooking

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 18 | PE / vtable hook framework | ✅ (`ProcessEventHook`) | 🟡 (own `hook/` mirror) | — | **bbp:** delete `hook/`, use ueforge |
| 19 | Game-thread `Queue` + re-entrance guard | ✅ | · (drained from `kill_hook`) | — | done |
| 20 | **Cached `&UFunction` identity dispatch** (compare ptrs not names on the hot path) | 🔵 | 📦 (used in `inv_hook`) | — | **promote to ueforge:** thin layer on top of `ProcessEventHook` |
| 21 | **Trampoline-as-drain-site** pattern (PE trampoline drains `Queue` on every fire) | 🔵 (docs only) | 📦 (kill_hook acts as drain) | — | **promote to ueforge:** ship a `Queue::drain_in_trampoline` helper + doc the canonical drain-site selection |

### Control plane (HTTP / TDD)

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 22 | HTTP listener (`server::spawn`) | ✅ | · | · | done |
| 23 | `OpResponse<S>` envelope + `parse_request` | ✅ | · | · | done |
| 24 | Generic primitives (`read_bytes`, `write_bytes`, `walk_class`, `fname_to_string`, `call`, `inspect_address`) | ✅ | · | · | done |
| 25 | Selector grammar (`addr:`, `class:`, `first_class:`, `singleton:`) | ✅ | · (+ `live_player_hc`, `live_player_cmc`) 📦 | · | done; game-specific selectors stay |
| 26 | `Snapshot` struct shape | — | 📦 (RPG-specific) | 📦 | correct |
| 27 | Op dispatcher (`handle_builtin` + game match arms) | ✅ (builtin) | · | · | done |
| 28 | Test client `Api<S>` (+ `try_op`) | ✅ | · | · | done |
| 29 | `perf::PerfLog` writer | ✅ | · | — | done |

### Memory tools

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 30 | Cheat-Engine-style scanner (scan / rescan / paginate) | ✅ | — | · | done |
| 31 | Address-validated freezes (selector-relative, `VirtualQuery` per write) | ✅ | — | · | done |
| 32 | Built-in **Scanner ImGui tab** | ✅ (`ui_scanner::render`) | — | · | done |
| 33 | `inspect_address` + property name walker | ✅ | — | · | done |
| 34 | Win32 process probes (threads / cpu / regions / module sampler) | ✅ | · | — | done |

### ImGui

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 35 | Vendored ImGui v1.92.1 + bridge | ✅ | 🟡 (own `cpp/imgui`) | · | **bbp:** drop, use ueforge's |
| 36 | Rust ImGui wrappers (`ui::text`, `button`, `slider_*`, etc.) | ✅ | 🟡 (own subset) | · | **bbp:** delete on shim migration |
| 37 | Tab registration (`Tab { name, render }`) | ✅ | 🟡 (own `register_tab` FFI) | · | **bbp:** delete on shim migration |

### Build & deploy

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 38 | `CppShim::new().compile()` builder | ✅ | 🟡 (own `cc::Build` script) | · | **bbp:** drop, one-line `build.rs` |
| 39 | `cargo deploy install/uninstall/package` | ✅ (`ueforge-deploy`) | · (manifest entry) | · | done |
| 40 | Steam-library auto-detect | ✅ | · | · | done |

### **RPG framework** (currently bbp-only — biggest open promotion)

| # | Feature | ueforge | better-backpack | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 41 | **`SkillEffect` enum + `CATALOG` row pattern** (one row per skill) | 🔵 | 📦 | — | **promote:** ship a generic `SkillEffect<F>` shape; game crates supply the field-write closures |
| 42 | **Sqrt level curve** (`progress = sqrt(level/max)`) | 🔵 | 📦 (`xp.rs`) | — | **promote:** trivial helper |
| 43 | **XP curve + cumulative-XP table** (`100 * N^1.8`, level cap) | 🔵 | 📦 | — | **promote:** generic; xp-per-creature table stays game-specific |
| 44 | **`PlayerState` schema** (`xp / level / skill_points / skill_levels: BTreeMap<id, u32>`) | 🔵 | 📦 | — | **promote:** open-shape `Skills<T>` carrying user `T` for game-specific extras |
| 45 | **Per-slot JSON persistence** (`<DLL_dir>/saves/<slot_key>.json`, atomic write per change) | 🔵 | 📦 (`save_slot` + `state.rs`) | — | **promote:** generic with a `slot_key()` closure plugged in by the game (FGuid resolver in bbp) |
| 46 | **`world_loader` slot-tracker poller** (transitions `None→Some / a→b / Some→None` to drive activate/deactivate) | 🔵 | 📦 | — | **promote:** generic; slot-key resolver is the only game-specific piece |
| 47 | **Disabled-skills set + per-skill toggle** (cheap on-off without refunding) | 🔵 | 📦 | — | **promote:** rides on the `Skills<T>` schema |
| 48 | **`apply_skill` dispatcher** (match-on-`SkillEffect`, vanilla snapshot, live-pawn mirror) | 🔵 | 📦 | — | **promote partially:** the dispatcher shape + vanilla `OnceLock` pattern; per-effect arms stay game-specific |
| 49 | **RPG ImGui tab template** (level / XP bar / catalog rows / +1/+10 / -1/-10 / on-toggle) | 🔵 | 📦 (own `ffi.rs` + tab) | — | **promote:** `RpgTab<S>` widget in `ueforge::ui`; per-skill labels still come from CATALOG |
| 50 | **Per-skill format strings + next-level preview** | 🔵 | 📦 | — | **promote:** part of #41's row shape (`PercentFormat`, `format_word`) |
| 51 | **`set_skill_points` debug op** (mirror of `tracker::debug_grant_skill_points`) | 🔵 | 📦 | — | **promote:** part of the `Skills<T>` schema's debug surface |

### Game-specific (correctly stays in the game crate)

| # | Feature | better-backpack | ows-tweaks | Notes |
|---|---|---|---|---|
| 52 | `PlatformOffsets` (per-build addresses) | 📦 | 📦 | per game, per platform |
| 53 | Game-specific selectors (`live_player`, `live_player_hc`, `live_player_cmc`) | 📦 | — | wraps `selector::resolve_generic` |
| 54 | `inv_hook` viewport rebind (4×10 pages, mouse-wheel scroll) | 📦 | — | extremely G2-specific |
| 55 | `kill_hook` (G2 `MulticastHandleEffectsWithDamageFlags` match + `KillingBlow` mask) | 📦 | — | per UFunction signature |
| 56 | `fall_hook` (`OnLanded` velocity-stomp on `BP_SurvivalPlayerCharacter`) | 📦 | — | per game |
| 57 | `survival.rs` (G2 hunger/thirst CDO writes) | 📦 | — | per game |
| 58 | `patch::run` (UInventoryComponent `DefaultMaxSize` at +0x1E0, player-only filter) | 📦 | — | per game; rewrite atop `FieldTweak` (#14) |
| 59 | `stacks.rs` (FieldTweak<i32> on DT_Materials.MaxCanStack at +0x48) | — | 📦 | per game |
| 60 | RPG catalog content (Backpack +460 slots, Attack Damage +300%, etc.) | 📦 | — | per gameplay design |
| 61 | XP-per-creature lookup table | 📦 | — | per game's bestiary |
| 62 | Per-feature ImGui tab content (sliders, labels, status text) | 📦 | 📦 | per UX |

### Migration order (where to spend the next sessions)

1. **`bbp` → `ue4ss_mod!` shim migration** (rows 1-7, 35-38). One mechanical pass — delete the duplicated infrastructure. ~3h, blocks every other bbp simplification.
2. **Promote the RPG framework** (rows 41-51). Build `ueforge::rpg` containing `SkillEffect`, `Skills<T>`, sqrt curve, JSON persistence with a `slot_key()` closure, the disabled-skill set, the tab template. Then bbp drops half its files. Big lift (~1-2 days) but unlocks RPG mods on any UE game.
3. **Promote cached-UFunction-identity dispatch** (row 20) and **trampoline-as-drain-site helper** (row 21). Small (~2h).
4. **`patch::run` → `ClassFieldTweak<T>`** (the live-UObject sibling of `FieldTweak<T>`). Single primitive replaces every "walk every X, mutate field at offset, filter by X" pattern. ~1h.

After (1)-(2), better-backpack shrinks by roughly 60% — the duplicated SDK/log/settings/hook/imgui surface vanishes, and the RPG-specific code becomes catalog rows + a few hooks. That's the long-term shape.

## Backlog (research questions tracked across games)

- **Cheat-Engine-style memory scanner** (deferred until
  needed). `scan_memory { type, value }` + `scan_rescan
  { session_id, mode }` + `freeze { addr, value, hz }`.
  Walks committed regions (`ueforge::winproc` already has the
  iterator). Build the first time an SDK dump leaves us
  stuck — generally that means non-UObject memory (allocator
  buffers, save blobs, CVars, bitfields the dumper flattens).
  For the ~95% case, dump-driven research is dramatically
  faster (30 sec / field vs 20-30 min / field). Estimated
  ~200 LoC when we get to it. Motivating use case in
  `outworld-station/research.md`.

## Adding to ueforge

Some piece of plumbing every mod needs that's not here yet?
**Add it to ueforge first.** Open the relevant module
(`ui` for ImGui calls, `ue` for engine helpers, `ops` for new
generic primitives, etc.), add the surface, validate by either
better-backpack or the next mod referencing it. Then build the
game-specific code on top.

If you find yourself copy-pasting between two game crates —
that copied code belongs in ueforge.
