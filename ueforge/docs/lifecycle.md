# Lifecycle

> **Authoritative on:** how a ueforge-based mod loads, what runs
> in what order, what `ModInfo` controls, what the C++ shim does,
> and how `cargo deploy` ships the result.

A ueforge mod is a Rust cdylib (`main.dll`) that UE4SS loads as a
CPPMod. The cdylib bundles a small C++ shim (compiled in by
ueforge's `build.rs` helper) that satisfies UE4SS's
`RC::CppUserModBase` ABI; the shim forwards every callback into
the Rust side via the extern "C" entry points the
`ue4ss_mod!` macro emits.

You declare three things in your crate:

1. A `static MOD_INFO: ueforge::ModInfo` describing your mod.
2. A one-line `ueforge::ue4ss_mod!(MOD_INFO);` invocation.
3. A one-line `build.rs` that calls
   `ueforge::build::CppShim::new().compile()`.

Everything else is bookkeeping ueforge handles for you.

## ModInfo

`ueforge::mod_main::ModInfo` (re-exported as `ueforge::ModInfo`)
declares your mod to UE4SS:

```rust
static MOD_INFO: ueforge::ModInfo = ueforge::ModInfo {
    name: "Grounded2RPG",                      // shown in UE4SS console
    version: "0.1.0",
    log_file: "grounded2_rpg.log",             // file in DLL dir
    console_title: "Grounded 2 - RPG System",            // console window title
    console: cfg!(feature = "console"),          // gate console alloc
    on_unreal_init: bbp_on_unreal_init,          // fn pointer
    on_shutdown: bbp_on_shutdown,                // fn pointer
    tabs: &[ueforge::Tab {
        name: "RPG",
        render: rpg::tab::render,
    }],
};

ueforge::ue4ss_mod!(MOD_INFO);
```

The `tabs:` array is a `&'static [Tab]`; the ueforge shim
iterates it during ImGui setup and calls each `Tab::render` once
per frame while the tab is visible. See [imgui.md](imgui.md) for
how rendering works.

## Lifecycle order

What runs, in order, when a player launches the game with
ueforge-based mod installed:

1. **DLL load.** UE4SS calls into our cdylib's `DllMain`
   (provided by ueforge's bundled C++ shim). The shim captures
   the `HMODULE` and forwards to ueforge's `log::set_dll_module`
   so `dll_dir()` resolves correctly for log + saves.
2. **Logger init.** `ueforge::log::init` runs from the shim,
   opening `<DLL_dir>/<log_file>` for write-through, line-flushed
   I/O.
3. **`MOD_INFO.on_unreal_init` fires** on UE4SS's mod-init
   thread. This is where you spawn a worker thread (always --
   never block the engine init thread), which then:
   - Loads settings via `ueforge::settings::Settings::<S>::load`.
   - Detects the platform via `ueforge::ue::platform::detect`.
   - Calls `ueforge::ue::init_runtime(image_base, offsets)`.
   - Walks GObjects to install hooks.
   - Spawns the slot poller and HTTP server if configured.
4. **Tab render callbacks fire** on UE4SS's render thread once
   per frame, only while the corresponding tab is visible in the
   ImGui window.
5. **`MOD_INFO.on_shutdown` fires** when the mod is unloaded
   (game close, hot-reload). Use this to stop any pollers /
   servers / workers your mod owns.

## The minimum viable mod skeleton

```rust
// src/lib.rs
use ueforge::ue::{PlatformOffsets, init_runtime, platform};

const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x09F6_7028,
    append_string: 0x0125_2060,
    g_names: 0x09E4_A7B8,
    g_world: 0x09C7_A2E0,
    process_event: 0x0146_E7B0,
    process_event_idx: 0x4C,
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
    tabs: &[ueforge::Tab { name: "Tweaks", render: render_tab }],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("yourmod/init", || unsafe { worker() });
}

fn on_shutdown() {
    ueforge::log!("yourmod: stopping");
}

unsafe fn worker() {
    let image_base = platform::host_image_base();
    let offsets = platform::detect(PLATFORMS).unwrap_or(&STEAM);
    let _rt = unsafe { init_runtime(image_base, offsets) };
    // ... install hooks, spawn pollers / servers ...
}

fn render_tab() {
    ueforge::ui::text("Hello");
}
```

```rust
// build.rs
fn main() {
    ueforge::build::CppShim::new().compile();
}
```

That's a complete mod. ~50 LoC. Everything else in your crate is
domain-specific (skills, hooks, UI bodies, snapshot fields, op
handlers).

## The C++ shim

ueforge ships a generic `RC::CppUserModBase` subclass
(`UespyMod` in `ueforge/cpp/ueforge_shim.cpp`) that provides:

- A `start_mod` factory function UE4SS calls to instantiate the
  mod object.
- A `DllMain` that captures `HMODULE` for `dll_dir()` resolution.
- Forwarding overrides for every `CppUserModBase` virtual
  callback that route into the Rust extern "C" entry points
  emitted by `ueforge::ue4ss_mod!`.

You **do not write a `DllMain`**. You **do not subclass
`CppUserModBase`**. You **do not export `start_mod` /
`uninstall_mod`**. ueforge does all of it, by default, in every
consumer cdylib.

If for some reason you need a custom shim (rare), call
`CppShim::new().skip_default_shim()` in your `build.rs` and
provide your own. grounded2-rpg used to do this; the dedup
work removed the custom shim.

## build.rs

The minimum:

```rust
fn main() {
    ueforge::build::CppShim::new().compile();
}
```

What this does:

- Compiles `ueforge/cpp/imgui/` and `ueforge/cpp/ueforge_ui.cpp`
  into a static lib that cargo links into your cdylib.
- Compiles `ueforge/cpp/ueforge_shim.cpp` (and its dependencies
  `ueforge_cppusermodbase.hpp`, `ueforge_imgui_bridge.hpp`) into
  the same static lib.
- Adds the linker flags needed to find `UE4SS.lib` (the import
  library generated from the user's installed `UE4SS.dll`).

Always-safe C++ (imgui + the UI bridge) is also compiled when
your crate is built as a test or build-script binary, so unit
tests and `cargo deploy` runs don't need UE4SS.dll on PATH.

## Cargo.toml

ueforge requires three identical lines:

```toml
[dependencies]
ueforge = { path = "../ueforge" }

[build-dependencies]
ueforge = { path = "../ueforge" }

[dev-dependencies]
ueforge = { path = "../ueforge" }
```

Same path three times. There are no feature flags. All public
surface is always available (the build script compiles a single
static lib that lands in every binary that links ueforge --
cdylib, test binary, build-script binary alike).

Plus a `[package.metadata.ueforge]` block that the deploy CLI
reads:

```toml
[package.metadata.ueforge]
mod_name        = "Grounded2RPG"
game_name_regex = "^Grounded\\s*2$"
game_sub_path   = "Augusta\\Binaries\\WinGRTS"
target_dir      = "target/grounded2-rpg"
```

`target_dir` keeps two cdylibs in the same workspace from
colliding on `target/release/main.dll`. Per-package target dirs
are required when more than one mod ships from one workspace.

## Deploy

The `ueforge-deploy` binary (a `[[bin]]` target inside `ueforge` itself) exposes `cargo deploy ...` via
the workspace `.cargo/config.toml` alias.

Three modes:

```sh
# Default for distribution: build + package zip in dist/
cargo deploy package -p your-mod

# Dev iteration loop: build + copy DLL into the game install
cargo deploy install -p your-mod

# Remove from local install
cargo deploy uninstall -p your-mod
```

Flags:
- `--game-path '<root>'` -- override autodetect.
- `--skip-build` -- redeploy an already-built DLL.

Autodetect walks every Steam library and matches against
`game_name_regex`. The mod lands in
`<game-install>\<game_sub_path>\ue4ss\Mods\<mod_name>\dlls\`.

`mods.txt` registration (`<mod_name> : 1`) is handled by the
deploy CLI.

## On-disk layout after `cargo deploy install`

```
<game install>\<sub_path>\ue4ss\Mods\<mod_name>\dlls\
  main.dll                # the cdylib
  <mod_log_file>          # ueforge::log writes here
  settings.json           # if your mod uses ueforge::settings
  saves/                  # if you use ueforge::rpg::SlotStore
    <slot>.json
```

`dll_dir()` resolves to the `dlls\` folder; every relative path
in your mod (`Settings::load`, `SlotStore::path`) anchors there.

## Shutdown discipline

`on_shutdown` runs in two scenarios:

1. **Process exit** -- UE shuts down, UE4SS unloads mods. UObjects
   may already be torn down; minimal cleanup is sufficient since
   the OS reclaims the address space anyway.
2. **Hot-reload** (`Ctrl+R` -- see "Hot-reload" below). UE is
   still running, GObjects is still live, and after our
   `on_shutdown` returns UE4SS will call `FreeLibrary` on our
   DLL. This is the strict case.

What `on_shutdown` MUST do (hot-reload-correct):

- **Uninstall every `ProcessEventHook`** before returning. Hooks
  patch UE class vtables; if the DLL is unloaded with patches
  still in place, the next call into the patched slot jumps
  into freed memory and crashes the game.
- **Stop every spawned thread** (HTTP listener, pollers,
  workers, settings watchers) and wait for them to exit. The
  DLL cannot be unloaded while any of its code is on a thread's
  stack.
- **Drain in-flight PE trampolines.** The hook layer's
  `active_calls` counter is checked + spun-on (with a bounded
  timeout) so trampolines that fired before the swap-back
  finish before unload.

What `on_shutdown` should NOT do:

- Touch the engine's UObjects in ways that allocate / hand off
  ownership; the engine may not survive the operation if it's
  also tearing down.
- Write to settings or save files unless already in consistent
  state. Persistence happens transactionally via
  `Tracker<A>::spend_skill_points` etc.
- Call `process_event` from off-thread; the same constraints as
  steady-state apply.

## Hot-reload (Ctrl+R)

UE4SS supports cpp-mod hot-**update** natively. This is not just
"re-run init on the same DLL" -- UE4SS does a full
`FreeLibrary` + fresh `LoadLibraryExW` from disk, so whatever
`main.dll` is on disk at reload time becomes the live image.
Build the new version, deploy it over the running install,
alt-tab to the game, press `Ctrl+R`. The new code is active in
~1-2 seconds with state preserved on disk (save slots, settings,
catalog progress) and re-applied by the new DLL's init.

### Configuration

`UE4SS-settings.ini`, `[General]` section:

```ini
EnableHotReloadSystem = 1
HotReloadKey = R              ; default; binds to Ctrl+<key>
```

Both default-on in modern UE4SS builds. Verify in your install.

### Mechanism

`Ctrl+R` triggers `UE4SSProgram::queue_reinstall_mods()` on
UE4SS's event-loop thread. The flow:

1. `uninstall_mods()` -> calls each cpp mod's exported
   `uninstall_mod(m_mod)` -> `~UespyMod()` -> ueforge's
   `ueforge_mod_shutdown` extern "C" -> the game crate's
   `MOD_INFO.on_shutdown` callback. **This is the cleanup
   window.**
2. `m_mods.clear()` -> `~CppMod()` -> `FreeLibrary(main.dll)`.
   Our DLL detaches from the process.
3. `setup_mods()` rescans `mods.txt` + `LoadLibraryExW`s the
   on-disk `main.dll` (the new one, if you `cargo deploy
   install`-ed in step 0).
4. `start_cpp_mods()` -> `start_mod()` -> fresh `UespyMod` ->
   `on_unreal_init` -> our worker init runs again.

### Dev loop

```sh
# 1. Edit Rust code.
# 2. Build + deploy without closing the game:
cargo deploy install -p grounded2-rpg

# 3. Alt-tab to game, press Ctrl+R.
# 4. Tail the log to confirm the new init ran:
tail -f "<game-install>/.../BetterBackpack/dlls/grounded2_rpg.log"
```

UE4SS's event loop is distinct from the game's UE thread, but
the file-replace works because UE4SS holds the DLL handle, not
the game; deploying overwrites `main.dll` while UE4SS still has
it mapped, then Ctrl+R triggers the FreeLibrary that releases
the old image.

### What survives

- **Cached UE references** (`ClassRef`, `&UFunction` pointers,
  `UClass*` caches): point INTO the game process, not into our
  DLL. New DLL re-resolves on first use; values match (same
  GObjects).
- **Skill state, settings, save files**: live on disk.
  `Tracker<A>` reloads from `<DLL_dir>/<subdir>/<slot>.json`
  on the next slot activation.

### What resets

- Every `static` in our DLL (atomics, OnceLocks, Mutexes) goes
  away with the DLL image. New DLL starts fresh.
- Worker threads exit during `on_shutdown` and are re-spawned
  by the new DLL's init.
- Counter atomics reset to zero. (For perf comparisons across
  reloads, snapshot before + after.)

### What requires care (Phase B work)

The framework's `on_shutdown` plumbing tracks every installed
`ProcessEventHook` in a static registry; reload calls
`HookRegistry::shutdown_all()` before returning to UE4SS. Each
hook drops -> swaps the vtable slot back atomically -> waits
for in-flight trampolines to drain (bounded timeout, typically
500ms). See `ueforge::hook::HookRegistry` (pending) and
`docs/todo.md` "hot-reload" for the implementation plan.

Until Phase B lands, hot-reload of mods that install PE hooks
(kill/fall/inv) is **unsafe** -- the old DLL's vtable patches
remain pointing into freed memory. The reload-as-test cycle
works fine for code paths that don't involve PE hooks; for
hook-touching changes, restart the game.

## Logging

`ueforge::log!` formats and writes one line:

```rust
ueforge::log!("rpg: applying {} at level {}", skill_id, level);
```

Output:
- The configured `log_file` in `dll_dir()`.
- The console (if `console: true` in `ModInfo`).

The logger flushes per line; a crash mid-write does not lose the
preceding lines. Logging is cheap but not free -- gate verbose
trace logging behind `cfg!(debug_assertions)` (release builds
compile out the `format!` entirely).

## Feature flags (Cargo)

ueforge has none. You may use cargo features in your own crate
to opt in/out of:

- `console` -- whether the AllocConsole call runs at startup.
  Recommend `default = ["console"]` for dev and a release variant
  that ships without it.
- Diagnostic surfaces: any `cfg!(debug_assertions)` paths.

Don't use cargo features to gate ueforge functionality. The
framework is one crate, no features, by design -- features lead
to combinatorial test matrices and "doesn't build for me"
issues. Ship one ueforge that works for everyone.

## Cross-references

- [ue-sdk.md](ue-sdk.md) -- the types you'll use inside `worker()`
- [hooks.md](hooks.md) -- how to install hooks from `worker()`
- [imgui.md](imgui.md) -- writing tab render bodies
- [http.md](http.md) -- starting the debug HTTP server
- [worker.md](worker.md) -- thread spawn details
- [settings.md](settings.md) -- the settings JSON pattern
- [native.md](native.md) -- what the C++ shim is doing under the
  hood and why it has to exist
