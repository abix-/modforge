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

## Native (C++) surface

The repo is Rust. The only C++ lives at the UE4SS / ImGui boundary:

| | Files | Lines | Where |
|---|---|---|---|
| Dear ImGui v1.92.1 (third-party, pinned to UE4SS's version) | 10 | 54,645 | git submodule -- not in this repo |
| ueforge shim (CppUserModBase subclass + ImGui extern "C" wrappers) | 4 | 502 | `cpp/` (ours) |

Every mod, every framework subsystem, every test, every tool is
Rust. The 502-line shim is a fixed cost shared by every Rust mod
in the workspace -- it does not grow as we add features. Full
breakdown + doctrine in [`docs/native.md`](docs/native.md).

### Cloning

ImGui v1.92.1 is a git submodule under `cpp/imgui/`, pinned to
[`ocornut/imgui` tag v1.92.1](https://github.com/ocornut/imgui/releases/tag/v1.92.1).
Use one of:

```sh
git clone --recurse-submodules <repo>
# or, if you already cloned:
git submodule update --init --recursive
```

`build.rs` panics with a clear message if the submodule isn't
initialized.

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
`outworld-station-tweaks/docs/research.md` for the canonical shape:

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
  # `cargo deploy ...` CLI is a [[bin]] target inside ueforge itself
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

See `outworld-station-tweaks/docs/research.md` and the existing
`grounded2-rpg/src/debug.rs` for the snapshot + dispatcher
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

Reference implementation: `outworld-station-tweaks/src/stacks.rs`
ships this pattern for the OWS stack-size mod. 4x bump that
matches the existing community "Better Item Stacks" pak mod's
effect — but via runtime DLL, so other features in the same mod
can layer on top dynamically.

## Audit: ueforge vs grounded2-rpg vs ows-tweaks

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

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 1 | `ModInfo` + `ue4ss_mod!` macro | ✅ | · | · | done (g2rpg migrated 2026-05-10) |
| 2 | C++ shim (`CppUserModBase` mirror, factory, `DllMain`) | ✅ (`ueforge_shim.cpp`) | · | · | done — g2rpg's `cpp/shim.cpp` deleted |
| 3 | HMODULE capture + `dll_dir()` | ✅ (`log::set_dll_module`) | · | · | done — g2rpg's `DLL_HMODULE` deleted |
| 4 | File + console logger | ✅ (`ueforge::log`) | · (`ueforge::log!` macro) | · | done — g2rpg's `log.rs` deleted |
| 5 | Settings JSON load / atomic save | ✅ (`Settings<T>`) | · (data struct only, IO via ueforge) | · | done |
| 6 | Counter primitives + macros | ✅ (`counter!`, `peak!`, `time_scope`) | · (uses ueforge primitives + own domain statics) | — | done |
| 7 | Bounded ring buffer | ✅ (`Ring<T>`) | · (uses for `DAMAGE_RING`) | — | done |

### UObject SDK

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 8 | `UObject` / `UClass` / `UFunction` wrappers | ✅ | · | · | done — g2rpg's `sdk/` deleted |
| 9 | `FName` / `FString` | ✅ (with FName→string cache) | · | · | done |
| 10 | `TArray` / `TMap` walkers | ✅ | · | · | done |
| 11 | `GObjectsView` (flat + chunked) | ✅ | · | · | done |
| 12 | `find_class_fast` (now name-cached) | ✅ | · | · | done |
| 13 | `find_by_short_name` (DataTable) | ✅ | — | · | done |
| 14 | `FieldTweak<T>` (DataTable rows) + `ClassFieldTweak<T>` (live UObjects) | ✅ | · (`patch.rs` + `survival.rs` migrated) | · (`stacks.rs`) | done -- Phase 2 |
| 15 | DataTable polling worker (`on_first_sight`) | ✅ | — | · | done |
| 16 | Native-property walker (`UClass::cached_native_properties`) | ✅ | — | · (via `inspect_address`) | done |
| 17 | UE introspection probes (`gobjects_population`, `class_outer_samples`) | ✅ | · | — | done |

### Hooking

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 18 | PE / vtable hook framework | ✅ (`ProcessEventHook`) | · | — | done — g2rpg's `hook/` deleted |
| 19 | Game-thread `Queue` + re-entrance guard | ✅ | · (drained from `kill_hook`) | — | done |
| 20 | **Cached `&UFunction` identity dispatch** (compare ptrs not names on the hot path) | ✅ (`hook::function_ptr` / `function_ptr_required`) | · (own `lookup` helpers; functionally equivalent) | — | done -- Phase 2 |
| 21 | **Trampoline-as-drain-site** pattern (PE trampoline drains `Queue` on every fire) | ✅ (canonical-site doc on `Queue::drain`) | · (drained from `kill_hook`) | — | done -- Phase 2 |

### Control plane (HTTP / TDD)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
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

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 30 | Cheat-Engine-style scanner (scan / rescan / paginate) | ✅ | — | · | done |
| 31 | Address-validated freezes (selector-relative, `VirtualQuery` per write) | ✅ | — | · | done |
| 32 | Built-in **Scanner ImGui tab** | ✅ (`ui_scanner::render`) | — | · | done |
| 33 | `inspect_address` + property name walker | ✅ | — | · | done |
| 34 | Win32 process probes (threads / cpu / regions / module sampler) | ✅ | · | — | done |

### ImGui

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 35 | Vendored ImGui v1.92.1 + bridge | ✅ | · | · | done — g2rpg's `cpp/imgui` deleted |
| 36 | Rust ImGui wrappers (`ui::text`, `button`, `slider_*`, etc.) | ✅ | · (RPG tab is now Rust, see `rpg/tab.rs`) | · | done |
| 37 | Tab registration (`Tab { name, render }`) | ✅ | · | · | done — g2rpg's FFI bridge deleted |

### Build & deploy

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 38 | `CppShim::new().compile()` builder | ✅ | · (1-line `build.rs`) | · | done |
| 39 | `cargo deploy install/uninstall/package` | ✅ (`ueforge` `[[bin]]` target) | · (manifest entry) | · | done |
| 40 | Steam-library auto-detect | ✅ | · | · | done |

### **Pillar 1: RPG framework** (Phase 3 complete)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 41 | `Skill<E>` row + `find_skill` lookup (generic over the game's effect enum) | ✅ (`rpg::Skill<E>`, `rpg::find_skill`) | · (`pub type Skill = ueforge::rpg::Skill<SkillEffect>;`) | — | done |
| 42 | Sqrt level curve (`progress = sqrt(level/max)`) | ✅ (`rpg::progress::sqrt_progress`) | · | — | done |
| 43 | XP curve + cumulative-XP table | ✅ (`rpg::xp::Curve`) | · (`xp::CURVE = Curve::new(100.0, 1.8, 50)`) | — | done |
| 44 | Per-creature XP bestiary (BP-class-name -> XP table) | ✅ (`rpg::Bestiary`) | · (`xp.rs` is just the table data) | — | done |
| 45 | State schema (xp / level / skill_points / skill_levels) | ✅ (`rpg::SkillsState` + `spend` / `refund` / `level_of`) | · | — | done |
| 46 | Per-slot JSON persistence (atomic temp+rename+fsync) | ✅ (`rpg::SlotStore<S>`) | · | — | done |
| 47 | Slot-tracker poller (transitions) | ✅ (`rpg::SlotPoller::spawn`) | · | — | done |
| 48 | Disabled-skills set + per-skill toggle | ✅ (`rpg::DisabledSkills`) | · | — | done |
| 49 | `RpgApplier` trait (game's apply seam) | ✅ (`rpg::RpgApplier`) | · (`GameApplier` impls it) | — | done |
| 50 | `Tracker<A>` (state + store + applier orchestration) | ✅ (`rpg::Tracker<A>` + `XpResult`) | · | — | done |
| 51 | Skill-effect dispatcher + vanilla capture (CDO + live-pawn walks per variant) | ✅ (`rpg::std_effect::StandardEffect::apply` + `VanillaCache<K, V>`) | · (Standard arm via `e.apply`; 3 G2-only composite arms stay) | — | done |
| 52 | `StandardEffect` 8-variant menu (PlayerFloat / PlayerSubcomponentFloat / Additive / U32Mask / Multiply / ClassFieldsMultiply / Runtime / StatusEffect) | ✅ (`rpg::std_effect`) | · (9 of 13 g2rpg catalog skills route through it) | — | done |
| 53 | RPG ImGui tab template (level / XP bar / catalog rows / +1/+10 / -1/-10 / toggle) | ✅ (`rpg::tab::render(tracker, toggle)`) | · (`rpg/tab.rs` is 23 lines) | — | done |
| 54 | Per-skill format strings + diminishing-returns previews | ✅ (`rpg::format::PercentFormat` + `StandardEffect::format`) | · (Standard arm delegates) | — | done |
| 55 | Standard ops catalog (skill_toggle / spend / refund / reload_slot / set_skill_points) | ✅ (`rpg::ops::*` + `debug::dispatch_standard_op`) | · | — | done |

### Pillar 2: Stacks (inventory stack-size tweaks)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 56 | `FieldTweak<T>` (data-table row tweak with vanilla cache) | ✅ (`ue::datatable::FieldTweak<T>`) | · (used by `patch.rs`) | · | done |
| 57 | `StackTweak` opinionated stacks wrapper (multiplier atomic + apply-now / counters) | ✅ (`stacks::StackTweak`) | — | · (`stacks.rs` is 64 lines) | done |
| 58 | DataTable polling worker (`apply_when_ready` on first sight) | ✅ (`ue::datatable::on_first_sight`) | — | · | done |

### Pillar 3: Difficulty (per-class CDO field tweaks)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 59 | `ClassFieldTweak<T>` (live-UObject vanilla cache) | ✅ (`ue::class_tweak::ClassFieldTweak<T>`) | · | · | done |
| 60 | `DifficultyKnob` opinionated difficulty wrapper (f32 multiplier atomic + apply_to_cdos / apply_to_all) | ✅ (`difficulty::DifficultyKnob`) | · (`survival.rs` is 41 lines, two knobs) | — | done |

### Pillar 4: Inventory (viewport paging + future CRUD ops)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 60a | `inventory::viewport` -- fixed-size visible grid over a larger underlying inventory: mouse-wheel scroll, per-widget viewport-start state, synthetic-refresh re-entrance guard, post-refresh rebind, construct reset | ✅ (`inventory::viewport::ViewportHook` + `ViewportConfig` + `ViewportBinder` trait) | · (`inv_hook.rs` is 220 lines: a `ViewportBinder` impl + UFunction wiring; was 396) | — | done |
| 60b | UMG `PanelWidget` `GetChildrenCount` / `GetChildAt` helpers | ✅ (private to viewport hook) | · | — | done |
| 60c | Future: inventory CRUD ops (add / remove / count / list) | (deferred until a second consumer materializes) | — | — | open |

### UE SDK helpers (used by all three pillars)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 61 | UObject byte-level helpers (`read_f32` / `write_f32` / `read_u32` / `write_u32` / `read_i32` / `write_i32` / `read_bool` / `write_bool` / `read_component_ptr`) | ✅ (`ue::field`) | · (re-exported as `apply::read_*`) | · | done |
| 62 | `TypedField<T>` (typed offset wrapper) | ✅ (`ue::typed_field`) | · | · | done |
| 63 | Actor / controller helpers (`class_chain_contains` / `controller_pawn` / `describe` / `is_outer_named` / `outer_class_name` / `A_CONTROLLER_PAWN_OFFSET`) | ✅ (`ue::actor`) | · (kill_hook killer classification) | — | done |
| 64 | `FDamageInfo` reader (`DamageInfoLayout` -> instigator / damage_source / damage_type_class / damage_flags) | ✅ (`ue::damage_info`) | · (g2rpg's Maine layout in `kill_hook`) | — | done |
| 65 | `FWeakObjectPtr::read` + `resolve` (one-shot index + GObjectsView walk) | ✅ (`ue::core_types::FWeakObjectPtr`) | · | — | done |
| 66 | `process_event` UFunction caller (`call_ufunction(target, &class, fn_name, &mut parms)`) | ✅ (`ue::pe_call`) | · (health ops) | — | done |
| 67 | String-keyed CDO / instance lookup (`with_first_instance_of` / `with_first_cdo_of`) | ✅ (`ue::with_first_*_of`) | · (debug snapshot collectors) | — | done |
| 68 | `PlayerRef::first_live_static` (game-thread-only `&'static UObject` of first live pawn) | ✅ (`ue::player::PlayerRef`) | · (debug `live_player_hc` resolver) | — | done |
| 69 | Platform detect + runtime init in one call | ✅ (`ue::platform::detect_and_init`) | · | · | done |
| 70 | `ClassRef::with_first_cdo` (symmetric to `with_first_instance`) | ✅ (`ue::class_ref::ClassRef`) | · | · | done |
| 71 | UE introspection probes (`gobjects_population`, `class_outer_samples`) | ✅ (`ue::probe`) | · (debug snapshot) | — | done |

### Hooks + game-thread queue

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 72 | PE / vtable hook framework | ✅ (`hook::ProcessEventHook`) | · | — | done |
| 73 | Cached `&UFunction` identity dispatch | ✅ (`hook::function_ptr` / `function_table!`) | · (kill_hook + inv_hook) | — | done |
| 74 | `install_with_backoff` (exponential retry until class loads) | ✅ (`hook::install_with_backoff` + `RetryPolicy`) | · (inv_hook) | — | done |
| 75 | `install_immediate_or_log` (install / log / leak triplet) | ✅ (`hook::install_immediate_or_log`) | · (kill_hook in lib.rs) | — | done |
| 76 | Game-thread `Queue` + re-entrance guard + canonical drain-site | ✅ (`pe_queue::Queue` + `DrainSite`) | · (drained from kill_hook) | — | done |

### Debug HTTP endpoint

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 77 | HTTP listener (`server::spawn`) | ✅ | · | · | done |
| 78 | `OpResponse<S>` envelope + `parse_request` | ✅ (`envelope`) | · | · | done |
| 79 | Generic primitives (`read_bytes` / `write_bytes` / `walk_class` / `fname_to_string` / `call` / `inspect_address`) | ✅ (`ops`) | · | · | done |
| 80 | Selector grammar (`addr:` / `class:` / `first_class:` / `singleton:`) | ✅ (`selector::resolve_generic`) | · (+ `live_player`, `live_player_hc`) 📦 | · | done; game-specific selectors stay |
| 81 | Standard-op dispatcher (skill_* / reload_slot / set_skill_points / walk_class / class_outer_samples / sample_thread_modules) | ✅ (`debug::dispatch_standard_op`) | · | — | done |
| 82 | PE-ops dispatcher (call / read_bytes / write_bytes with game resolver) | ✅ (`debug::dispatch_pe_ops`) | · | — | done |
| 83 | PE-queue enqueue helper (timeout + custom hint) | ✅ (`debug::enqueue_pe`) | · | — | done |
| 84 | `PlayerStateView::from_state` (serde view of SkillsState) | ✅ (`debug::PlayerStateView`) | · | — | done |
| 85 | `CatalogEntry` + `catalog_view(&[Skill<E>], kind_fn)` | ✅ (`debug::catalog_view`) | · | — | done |
| 86 | `STANDARD_OPS` op-list metadata | ✅ (`debug::STANDARD_OPS`) | · | — | done |
| 87 | `DamageEvent` + `DamageRing` (bounded ring of PE damage events) | ✅ (`debug::DamageEvent` / `DamageRing`) | · | — | done |
| 88 | `ProcessSnapshot` (counters + memory + cpu + threads + gobjects population + regions) | ✅ (`debug::ProcessSnapshot::collect`) | · | — | done |
| 89 | Win32 process probes (threads / cpu / regions / module sampler) | ✅ (`winproc`) | · | — | done |
| 90 | Test client `Api<S>` (+ `try_op`) | ✅ (`client`) | · | — | done |
| 91 | `perf::PerfLog` writer | ✅ (`client`) | · | — | done |

### Settings + logging + counters

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 92 | `Settings<T>` JSON load + atomic save | ✅ (`settings::Settings`) | · | · | done |
| 93 | `Settings::reload` + `watch(interval, on_reload)` (mtime-poller hot-reload) | ✅ (`settings::WatchHandle`) | — (not yet adopted) | — (not yet adopted) | done |
| 94 | File + console logger (`set_dll_module` HMODULE capture) | ✅ (`log`) | · | · | done |
| 95 | Counter primitives + `time_scope` | ✅ (`counters`) | · | · | done |
| 96 | Bounded `EventRing<T>` | ✅ (`ring::EventRing`) | · (DamageRing wraps it) | — | done |

### Memory tools (built for ows-tweaks research, used by both)

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 97 | Cheat-Engine-style scanner (scan / rescan / paginate / freeze) | ✅ (`scanner`) | — | · | done |
| 98 | Built-in Scanner ImGui tab | ✅ (`ui_scanner::render`) | — | · | done |
| 99 | `inspect_address` + property name walker | ✅ (`ops::inspect_address`) | — | · | done |

### ImGui

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 100 | Vendored ImGui v1.92.1 (git submodule) + bridge | ✅ | · | · | done |
| 101 | Rust ImGui wrappers (`ui::text` / `button` / `slider_*` / `Disabled` / etc.) | ✅ (`ui`) | · | · | done |
| 102 | Tab registration (`Tab { name, render }`) | ✅ (`mod_main`) | · | · | done |

### Build & deploy

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 103 | `CppShim::new().compile()` builder | ✅ (`build`) | · (1-line `build.rs`) | · | done |
| 104 | `cargo deploy install/uninstall/package` | ✅ (`ueforge` `[[bin]]` target) | · | · | done |
| 105 | Steam-library auto-detect | ✅ | · | · | done |

### Lifecycle / loader plumbing

| # | Feature | ueforge | grounded2-rpg | ows-tweaks | Verdict |
|---|---|---|---|---|---|
| 106 | `ModInfo` + `ue4ss_mod!` macro | ✅ (`mod_main`) | · | · | done |
| 107 | C++ shim (`CppUserModBase` mirror, factory, `DllMain`) | ✅ (`ueforge_shim.cpp`) | · | · | done |
| 108 | HMODULE capture + `dll_dir()` | ✅ (`log::set_dll_module`) | · | · | done |
| 109 | Worker thread spawn with panic-catch | ✅ (`worker::spawn`) | · | · | done |
| 110 | Hot-update via UE4SS Ctrl+R (`uninstall_mod` + `~UespyMod` + `ueforge_mod_shutdown` -> our `on_shutdown` callback) | ✅ (shim wired) | · (worker shutdown only; PE hooks still leaked -- Phase B) | · (no PE hooks; safe today) | research done; Phase B (`HookRegistry::shutdown_all` + `active_calls` drain + HTTP `SpawnHandle::stop`) pending |
| 111 | Side-file deploy + on_shutdown swap (`cargo deploy install` writes `main-new.dll`; shim renames `main.dll` <-> `main-new.dll` on Ctrl+R/exit) | ✅ (`ueforge_deploy` + `mod_main::finalize_hot_reload_swap` + `cleanup_old_dll`) | · | · | done -- Phase B0 |

### Game-specific (correctly stays in the game crate)

| # | Feature | grounded2-rpg | ows-tweaks | Notes |
|---|---|---|---|---|
| 200 | `PlatformOffsets` (per-build addresses) | 📦 | 📦 | per game, per platform |
| 201 | Game-specific selectors (`live_player`, `live_player_hc`) | 📦 | — | wraps `selector::resolve_generic` |
| 202 | `inv_hook` Maine UFunction wiring (WBP_InventoryInterface_C class name + grid offset + GetInventoryItems / InitializeItemSlot / GetItemInItemListSlot parm shapes) | 📦 | — | per game; viewport algorithm + state + scroll all framework-side via `inventory::viewport` |
| 203 | `kill_hook` Maine UFunction match + KillerKind classifier (Player / Buggy / Other) | 📦 | — | per UFunction signature; structural shape uses `ue::actor` + `ue::damage_info` from the framework |
| 204 | `fall_hook` (`OnLanded` velocity-stomp on `BP_SurvivalPlayerCharacter`) | 📦 | — | per game |
| 205 | `survival.rs` (G2 hunger/thirst Maine offsets via `DifficultyKnob`) | 📦 | — | offsets stay; framework owns the apply loop |
| 206 | `patch.rs` (UInventoryComponent `DefaultMaxSize` at +0x1E0, player-only filter) | 📦 | — | per game; uses `ClassFieldTweak<i32>` |
| 207 | `stacks.rs` (DT_Materials.MaxCanStack offsets via `StackTweak`) | — | 📦 | offsets stay; framework owns the apply loop |
| 208 | RPG catalog content (Backpack +460 slots, Attack Damage +300%, etc.) | 📦 | — | per gameplay design |
| 209 | XP-per-creature bestiary entries | 📦 | — | per game's bestiary; framework owns `Bestiary` shape |
| 210 | `damage_trace.rs` + `impact_resistance.rs` (Maine multicast parm shapes) | 📦 | — | per UFunction; structural shape generic |
| 211 | Per-feature ImGui tab content (sliders, labels, status text) | 📦 | 📦 | per UX |
| 212 | `KillerKind` classifier (Player / Buggy / Other) + buggy XP multiplier | 📦 | — | per game policy |

## Heterogeneous-pillar adoption

Not every UE5 mod uses every pillar, and not every pillar applies
cleanly to every UE5 game. ueforge supports this: pillars are
independent modules, opt-in via use sites. A pure stack-size
tweak only consumes `stacks`. An RPG-only mod only consumes
`rpg`. A mod that uses all four picks one knob from each menu
and ignores the rest. Game crates carry only game-specific
knowledge (UE class names, field offsets, UFunction parm shapes);
the per-game extension surface is `&'static` config + an opt-in
trait impl.

**The framework's design rule: each universal pattern is defined
ONCE in ueforge.** If you find yourself writing the same
scaffolding in two game crates, that's a missing pillar lift --
file an entry under "Open: more ueforge extraction candidates"
in `docs/todo.md`.

## Migration status

**All four phases complete (2026-05-10):**

- **Phase 1** -- infra dedup. g2rpg lost ~930 lines of duplicated
  loader / SDK / hook / log / FFI plumbing.
- **Phase 2** -- small promotions. `ClassFieldTweak<T>`,
  `function_ptr` / `function_ptr_required`, canonical
  `Queue::drain` doc.
- **Phase 3** -- RPG framework. The 15 rows under "Pillar 1" all
  shipped: `Skill<E>`, `Tracker<A>`, `RpgApplier`, `SlotStore<S>`,
  `SlotPoller`, `DisabledSkills`, `Bestiary`, `StandardEffect`
  8-variant menu + apply + format dispatch, `tab::render`,
  `ops::*`. g2rpg's `apply_skill` collapsed from 11 arms to 4
  (1 framework Standard arm + 3 game-specific composites).
- **Phase 4** -- the rest. `ueforge::stacks` + `ueforge::difficulty`
  (pillars 2 + 3), `ue::field` / `ue::actor` / `ue::damage_info` /
  `ue::pe_call`, `Settings::watch`, `debug::dispatch_*` /
  `DamageRing` / `ProcessSnapshot` / `PlayerStateView`,
  `platform::detect_and_init`, `hook::install_immediate_or_log`,
  kill_hook split into 3 modules.

The rule going forward: a UE5 mod implementing RPG / stacks /
difficulty writes only game-specific knobs (table names, field
offsets, multiplier UI, settings persistence). No
re-implementation of the apply loop, the vanilla cache, the
counter atomics, or the snapshot scaffolding.

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
  `outworld-station-tweaks/docs/research.md`.

## Adding to ueforge

Some piece of plumbing every mod needs that's not here yet?
**Add it to ueforge first.** Open the relevant module
(`ui` for ImGui calls, `ue` for engine helpers, `ops` for new
generic primitives, etc.), add the surface, validate by either
grounded2-rpg or the next mod referencing it. Then build the
game-specific code on top.

If you find yourself copy-pasting between two game crates —
that copied code belongs in ueforge.
