# uespy

**uespy is the base layer for every UE4SS Rust mod in this
workspace.** Every piece of plumbing a UE4SS mod needs — the C++
shim, the imgui bridge, the UObject SDK, hook framework, debug
endpoint, test client, build glue, logger, all of it — lives here
once. Game crates supply only what's actually game-specific:
platform offsets, snapshot shape, op handlers, drain wiring, the
content of their UI tabs.

The rule, codified:

> Always change uespy first. If a need is game-specific, prove it
> first; otherwise it belongs in uespy. Game-specific code goes on
> top of uespy, not in parallel to it.

## Three feature flags, one crate

uespy is a single crate with three feature flags that map to the
three contexts a game crate imports it from:

| Feature | Context | What it pulls in |
|---|---|---|
| `runtime` (default) | `[dependencies]` (cdylib) | server, queue, primitives, selectors, hex, ring, counters, log, hook framework, UE SDK + introspection, Win32 probes, TMap / DataTable mechanics, `ui::*` ImGui bindings, `ModInfo` + `ue4ss_mod!` macro |
| `client` | `[dev-dependencies]` (tests) | `uespy::client::Api<S>`, `uespy::client::perf::PerfLog` |
| `build` | `[build-dependencies]` (build.rs) | `uespy::build::CppShim::new()...compile()`, bundled ImGui v1.92.1 vendor, bundled `UE4SS.lib` |

Cargo's three dep tables exist for a reason — runtime, test, and
build contexts have different dependency surfaces. The feature
flags align with that without forcing the user to think about
three different crates.

## What lives in uespy (do not reinvent)

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
| C++ shim mirror | `uespy/cpp/uespy_cppusermodbase.hpp` |
| ImGui context bridge | `uespy/cpp/uespy_imgui_bridge.hpp` |
| Generic factory + DllMain | `uespy/cpp/uespy_shim.cpp` (compiled into every mod by default) |
| ImGui C++ bridge | `uespy/cpp/uespy_ui.cpp` |
| ImGui vendor | `uespy/cpp/imgui/` (v1.92.1, matches UE4SS) |
| UE4SS import lib | `uespy/ue4ss/UE4SS.lib` |

## What's left for game crates to write

| Concern | Game owns |
|---|---|
| `PlatformOffsets` per build | yes — different per UE version, sometimes per platform of the same game |
| `Snapshot` struct + `build_snapshot` | yes — game-specific state shape |
| Op handler dispatcher (`handle()`) | yes — match arm per op |
| Game-specific selectors (`live_player`, `current_save`) | yes — wrap `selector::resolve_generic` |
| Drain-site PE trampoline | yes — pick a hot UFunction per game |
| Tab render bodies | yes — `fn render_tab() { uespy::ui::text(...); }` |
| `ModInfo` + `ue4ss_mod!` invocation | yes — one static + one macro call |

That's it. Every other UE / UE4SS / ImGui / Win32 / test mechanic
comes from uespy.

## Quickstart for a new mod

### Workspace layout

```
your-mods/
  Cargo.toml         # workspace
  uespy/             # the only base crate
    cpp/imgui/       # vendored ImGui, shared by every mod
    ue4ss/UE4SS.lib  # shared import lib
  your-mod/
    Cargo.toml
    build.rs         # 1 LoC
    src/lib.rs       # ModInfo + ue4ss_mod!
    src/debug.rs     # Snapshot + handle()
    tests/
```

### `your-mod/Cargo.toml`

```toml
[dependencies]
uespy = { path = "../uespy" }                                            # runtime

[build-dependencies]
uespy = { path = "../uespy", default-features = false, features = ["build"] }

[dev-dependencies]
uespy = { path = "../uespy", features = ["client"] }
```

No `cpp/` directory in `your-mod/` unless you have custom C++.
No `ue4ss/UE4SS.lib`. No imgui copy. No DllMain. No factory exports.

### `your-mod/build.rs`

```rust
fn main() {
    uespy::build::CppShim::new().compile();
}
```

That's the whole file.

### `your-mod/src/lib.rs`

```rust
use uespy::ue::PlatformOffsets;

const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x0, append_string: 0x0, g_names: 0x0,
    g_world: 0x0, process_event: 0x0, process_event_idx: 0x4C,
};

const PLATFORMS: &[(&str, &PlatformOffsets)] = &[
    ("YourGame-Win64-Shipping.exe", &STEAM),
];

static MOD_INFO: uespy::ModInfo = uespy::ModInfo {
    name: "YourMod",
    version: "0.1.0",
    log_file: "your_mod.log",
    console_title: "YourMod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    tabs: &[
        uespy::Tab { name: "Tweaks", render: render_tweaks_tab },
    ],
};

uespy::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    let image_base = uespy::ue::platform::host_image_base();
    let offsets = uespy::ue::platform::detect(PLATFORMS).unwrap_or(&STEAM);
    let _rt = unsafe { uespy::ue::init_runtime(image_base, offsets) };
    // ... start worker thread, install hooks, spawn debug server
}

fn on_shutdown() {
    uespy::log::log(format_args!("stopping"));
}

fn render_tweaks_tab() {
    uespy::ui::text("Tweaks");
    uespy::ui::separator();
    if uespy::ui::button("Reload patches") {
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
   `uespy_client::Api<Snapshot>`.
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

## Adding to uespy

Some piece of plumbing every mod needs that's not here yet?
**Add it to uespy first.** Open the relevant module
(`ui` for ImGui calls, `ue` for engine helpers, `ops` for new
generic primitives, etc.), add the surface, validate by either
better-backpack or the next mod referencing it. Then build the
game-specific code on top.

If you find yourself copy-pasting between two game crates —
that copied code belongs in uespy.
