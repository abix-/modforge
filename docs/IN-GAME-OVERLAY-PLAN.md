# In-game ImGui overlay via hudhook: implementation plan

> **Authoritative on:** how native-PE modforge consumers (horsey-mod first,
> then grounded2-mod and outworld-station-mod when they need it) get a true
> in-game ImGui overlay drawn inside the host game's swap chain. We use
> [hudhook](https://github.com/veeenu/hudhook). See
> [`UI-CENTRALIZATION.md`](UI-CENTRALIZATION.md) for the broader cross-engine
> API story.

Status: **WORKING END-TO-END 2026-05-15.** Hudhook overlay renders inside
Horsey.exe. Live test `tests/overlay_lifecycle.rs` green: frame counter
advances at game framerate. All 5 plan steps shipped:

- Step 1 (spike): generic `modforge::ui::overlay` module behind
  `overlay-ui` Cargo feature.
- Step 2 (port tabs): Overview / Horses / Debug ported to imgui-rs RAII
  tokens in `horsey-mod/src/overlay.rs`.
- Step 3 (HTTP ops): `ui.overlay.arm`, `ui.overlay.disarm`,
  `ui.overlay.stats` registered.
- Step 4 (decommission `native-ui`): `modforge/cpp/`,
  `modforge/src/ui/{api,native}.rs`, `modforge/build.rs`, and the
  `native-ui` Cargo feature all deleted. modforge is pure Rust rlib.
- Step 5 (docs): this file, `UI-CENTRALIZATION.md`,
  `horsey-mod/docs/todo.md`, project_state.md all updated.

Additional unplanned fix landed: **vendored hudhook fork at
`vendor/hudhook/` with an added `IDXGISwapChain1::Present1` hook**.
Required because SDL3's D3D11 path (used by Horsey) calls Present1, not
Present. Without it, hudhook installs hooks successfully but never
intercepts a frame. Documented in
[`vendor/hudhook/PRESENT1-PATCH.md`](../vendor/hudhook/PRESENT1-PATCH.md);
upstream PR pending.

## Decision summary

We adopt **hudhook** as the overlay engine. The wrapper lives in
**modforge** under the `overlay-ui` Cargo feature so every native-PE mod
adopts it by flipping one feature flag. UE4SS-host mods (ueforge /
grounded2-mod / outworld-station-mod) keep their existing C++ ImGui shim
against UE4SS's bridge (UE4SS owns its ImGui context; we do not control
it). The two stacks never share a process.

This retires the previous draft's "lift hudhook's hook layer and keep our
C++ shim" plan and additionally retires modforge's `native-ui` surface
(Phase A separate-window backend), since hudhook bundles imgui-sys and
cannot coexist with modforge's own vendored C++ ImGui in one cdylib
(LNK2005 multiply-defined symbols at link time). See "Migration off C++
ImGui" below.

## Generic consumer API (shipped Step 1, 2026-05-15)

```rust
// Cargo.toml
modforge = { path = "../modforge", features = ["overlay-ui"] }

// any mod source file
use modforge::ui::overlay::{self, Condition, ImguiRenderLoop, Ui};

struct MyOverlay;
impl ImguiRenderLoop for MyOverlay {
    fn render(&mut self, ui: &mut Ui) {
        ui.window("My Mod")
            .size([400.0, 200.0], Condition::FirstUseEver)
            .build(|| { ui.text("Hello, in-game!"); });
    }
}

// During init:
overlay::arm(MyOverlay)?;
```

That is the entire surface. `modforge::ui::overlay` re-exports
`ImguiRenderLoop`, `Ui`, and `Condition` so consumers do not need to depend
on `hudhook` or `imgui` directly. The wrapper handles idempotent arm,
frame counting, and disarm via `hudhook::eject`.

Public API:

- `arm<R: ImguiRenderLoop + Send + Sync + 'static>(render_loop: R) -> Result<(), String>`
- `disarm()`
- `is_armed() -> bool`
- `frame_count() -> u64`

## Goal

A native-PE consumer registers an `ImguiRenderLoop` implementation and gets
an ImGui panel that:

1. Renders **inside the game's window**, on top of the game's frame, before
   the game's `Present` flips the back buffer.
2. Receives mouse and keyboard from the game's HWND. When ImGui wants the
   cursor or keys, the game does not see them.
3. Survives swap-chain resizes, alt-tab, fullscreen toggle, and resolution
   changes.
4. Costs no measurable frame time when no panel is visible, a few hundred
   microseconds per frame when a panel is open.
5. Crashes in the render callback do not kill the game (hudhook itself
   provides panic isolation around the callback; we additionally SEH-guard
   our own code that runs inside it).

## Why hudhook

[hudhook](https://github.com/veeenu/hudhook) v0.9.0 (Andrea Venuta, MIT,
March 2026) is a mature Rust crate that already does the entire job for
DX9 / DX11 / DX12 / OpenGL3:

- Dummy-device vtable scan for `IDXGISwapChain::Present` and
  `IDXGISwapChain::ResizeBuffers`.
- Vendored MinHook for the vtable patches.
- ImGui DX11 render engine + first-frame init on first Present call.
- WndProc subclass for input.
- Correct ResizeBuffers + display-size handling.
- Wine / Proton support.

License (MIT) is fully compatible with our GPL v3.

Smarter engineers have solved this. We use their work.

## Why Path A (use hudhook directly) over the lift-and-port alternative

The earlier draft of this plan worried that hudhook owns the ImGui context
via imgui-rs and our existing UI surface (`modforge::ui::api`) routes
through a vendored C++ ImGui shim. Per ocornut/imgui #586, two statically
linked ImGui copies in one process is broken. That worry conflated two
different scopes:

- **Per process:** correct. One ImGui binary per process. Mixing imgui-rs
  and a separately-linked C++ ImGui in one process breaks atlas state,
  IO, draw lists.
- **Per codebase:** irrelevant. horsey-mod (native PE), grounded2-mod
  (UE4SS host), and outworld-station-mod (UE4SS host) load into three
  separate game processes. None of them share an address space. Each
  picks whichever ImGui binding fits its host runtime.

So native-PE mods use imgui-rs + hudhook; UE4SS mods stay on the C++ shim
+ UE4SS bridge. Two API surfaces in the modforge tree, idiomatic to their
hosts. Phase B's "single Rust API across every backend" was a
nice-to-have, not a requirement. We retire it.

## Architecture

```
hudhook 0.9          imgui 0.12               <- crates.io
   |
   v
horsey-mod/
  Cargo.toml           +hudhook, +imgui
  src/
    overlay.rs         NEW. ImguiRenderLoop impl + tab routing.
    ui.rs              EDIT. Tab render fns take &mut imgui::Ui.
    lib.rs             EDIT. ui.overlay.arm/disarm/stats ops.

modforge/
  src/ui/
    api.rs             UNCHANGED. UE4SS-bridge consumers still use it.
    native.rs          UNCHANGED. Available as fallback.
  cpp/
    modforge_ui_native.cpp   UNCHANGED.

ueforge / grounded2-mod / outworld-station-mod   UNCHANGED.
```

The hudhook docs minimum example for DX11:

```rust
use hudhook::*;
use hudhook::hooks::dx11::ImguiDx11Hooks;

pub struct HorseyOverlay { /* ... */ }

impl ImguiRenderLoop for HorseyOverlay {
    fn render(&mut self, ui: &mut imgui::Ui) {
        ui.window("horsey-mod")
            .size([400.0, 600.0], imgui::Condition::FirstUseEver)
            .build(|| {
                ui.text("Hello from in-game overlay");
            });
    }
}

// Called from our worker_main / DllMain attach path:
unsafe {
    Hudhook::builder()
        .with::<ImguiDx11Hooks>(HorseyOverlay::new())
        .build()
        .apply()
        .expect("hudhook apply failed");
}
```

That is the full overlay wiring. hudhook handles vtable scan, MinHook on
Present and ResizeBuffers, ImGui DX11 init on first frame, WndProc
subclass, swap-chain resize. We write none of it.

### Crate boundaries

| Crate | Change |
|---|---|
| `horsey-mod` | adds `hudhook = "=0.9.0"`, `imgui = "=0.12"`; new `src/overlay.rs`; tab fns in `src/ui.rs` take `&mut imgui::Ui`; new `ui.overlay.*` HTTP ops |
| `modforge` | unchanged. Both `ui::api` (C++ shim) and `ui::native` (separate window) stay for ueforge consumers and as fallback |
| `ueforge`, `grounded2-mod`, `outworld-station-mod` | unchanged |

### Threading

hudhook's render callback runs on the game's render thread (same thread
that calls `Present`). All imgui-rs calls happen there. We must not call
imgui-rs from any other thread.

State read by the callback (gamestate snapshots, horse rosters) comes
from our existing `crate::gamestate::*` and `crate::horse::*` accessors,
which already handle cross-thread reads via raw pointer derefs guarded by
`is_addr_readable`. Same posture Phase A uses.

### Lifecycle: arm / disarm

hudhook's `Hudhook::apply()` installs the hooks and returns. There is no
explicit `unapply` on a `Hudhook` instance, but hudhook does ship an
`eject()` path used by its `inject` feature for graceful unload. For our
purposes:

- **Arm:** call `Hudhook::builder()...apply()` once at attach.
- **Disarm:** call hudhook's `eject()` (verify exact name in spike).
  Fall back to leaving hooks armed until DLL unload if `eject` proves
  fiddly; this matches what most overlay mods do.

Hot-reload (the `horsey-inject.exe --reload` path) already disposes of
helper threads as part of `_shutdown`. The hook teardown joins that
flow.

## Migration off C++ ImGui (modforge side)

The `overlay-ui` feature pulls in `imgui-sys`, which bundles its own
copy of the C++ ImGui library. `native-ui` compiles modforge's own
vendored C++ ImGui via `cc`. Two static copies of ImGui in one cdylib
produce LNK2005 multiply-defined-symbols errors at link time. Cargo
does not surface this conflict because features are additive and the
two are not declared mutually exclusive in the manifest; it only blows
up when the linker actually runs against both.

Therefore modforge's `native-ui` surface is being deleted. Files
slated for removal:

| Path | Reason |
|---|---|
| `modforge/cpp/modforge_ui_native.cpp` | separate-window C++ |
| `modforge/src/ui/api.rs` | Rust wrappers around C++ shim |
| `modforge/src/ui/native.rs` | separate-window Rust wrapper |
| `modforge/build.rs` (the `cc` section + vendored-ImGui reuse) | only used by `native-ui` |
| `Cargo.toml` `native-ui` feature + `cc` build dep | dead |
| `horsey-mod/tests/native_ui_lifecycle.rs` | Phase A lifecycle test |

What is NOT removed:

- `ueforge/cpp/imgui/` (the vendored ImGui submodule). It is REQUIRED
  by ueforge's UE4SS-bridge shim (`ueforge/cpp/ueforge_ui.cpp` +
  `ueforge_shim.cpp`), which shares UE4SS's ImGui context via
  `get_current_imgui_context` + `get_current_imgui_allocator_functions`.
  UE4SS owns its ImGui; we just bind against it.
- `ueforge::ui::*` Rust API. Unchanged. UE4SS-host mods keep using it.

Future work (separate from this overlay plan): migrate ueforge itself
to imgui-rs by building imgui-sys against UE4SS's existing ImGui
context rather than its bundled one. That is genuine custom-build
infrastructure work and is OUT OF SCOPE here.

## Implementation steps

All steps test-first. Step 1 done.

### Step 1. Spike. SHIPPED 2026-05-15

- Added `hudhook = "=0.9.0"` and `imgui = "=0.12"` to **modforge** under
  the new `overlay-ui` Cargo feature (not horsey-mod, so any consumer
  flips one feature flag to adopt).
- New `modforge/src/ui/overlay.rs`: generic `arm` / `disarm` /
  `is_armed` / `frame_count` API + `FrameCountingLoop` wrapper +
  re-exports of `ImguiRenderLoop`, `Ui`, `Condition`.
- horsey-mod enables `features = ["overlay-ui"]`; new ~40 LOC
  `horsey-mod/src/overlay.rs` defines `HorseyOverlay` impl drawing one
  window with a frame counter.
- New HTTP ops: `ui.overlay.arm`, `ui.overlay.disarm`, `ui.overlay.stats`.
- horsey-mod's `worker_main` calls `crate::overlay::arm()` after HTTP
  server start.
- horsey-mod's old `ui.native.*` ops removed; `crate::ui` module deleted.
- `cargo build -p horsey-mod --lib --release` clean.
- **Not yet done:** live verification against running Horsey.exe. That
  is part of Step 2's manual test gate.

### Step 2. Port tab bodies to imgui-rs

Goal: every tab in `horsey-mod/src/ui.rs` runs through hudhook instead of
the C++ shim.

- Change tab fn signatures from `fn()` to `fn(ui: &imgui::Ui)`.
- Mechanical translation:
  - `modforge::ui::api::text(s)` becomes `ui.text(s)`.
  - `modforge::ui::api::text_disabled(s)` becomes `ui.text_disabled(s)`.
  - `modforge::ui::api::separator()` becomes `ui.separator()`.
  - `modforge::ui::api::button(s)` becomes `ui.button(s)`.
- `HorseyOverlay::render` builds a tab bar and dispatches to each tab.

Test: `tests/overlay_tabs.rs`. Each tab's render fn increments a per-tab
atomic. After arming overlay and switching tabs (synthetic mouse click via
`SendMessageW`), assert per-tab counters advanced.

### Step 3. HTTP ops

Goal: parity with the existing `ui.native.*` surface.

- `ui.overlay.arm` (idempotent; second call is a no-op).
- `ui.overlay.disarm` (best-effort; documented behavior if hudhook's
  unhook is incomplete).
- `ui.overlay.stats` returns `{ armed: bool, frames: u64, last_present_us: u64 }`.

Test: `tests/overlay_lifecycle.rs`. arm -> wait for frames>60 -> disarm,
assert game still alive via `_alive` ping. Loop 3 times if `disarm` is
reliable, else single-shot and document the constraint.

### Step 4. Decommission `ui.native.*` for horsey-mod

Once the overlay has shipped against Horsey for at least one week of
dogfooding:

- Remove the `ui.native.spawn/shutdown/is_visible/stats` HTTP ops from
  horsey-mod. The separate-window backend in modforge stays in tree
  (other future native-PE mods may want it).
- Remove horsey-mod's `native-ui` Cargo feature.
- Update `horsey-mod/docs/todo.md` to mark the overlay item shipped and
  link this doc as the implementation reference.

### Step 5. Documentation

- Update `UI-CENTRALIZATION.md`:
  - Phase A: SHIPPED (separate window in modforge, available as fallback).
  - Phase B (unified Rust API across backends): RETIRED. Each backend
    stays idiomatic to its host. Document the rationale.
  - New section "Native-PE overlay via hudhook" linking this doc.
- Update `modforge/src/ui/native.rs` module docs to clarify it is the
  fallback / debug path; the recommended native-PE backend is hudhook
  (linked from horsey-mod).

## Risks

| Risk | Probability | Mitigation |
|---|---|---|
| Steam overlay also hooks Present, collision | medium | hudhook docs cover hook stacking. Steam loads first; ours stacks on top. Test with Steam overlay enabled vs disabled. |
| `hudhook::eject` flow not as clean as `apply` | medium | If disarm is fiddly, ship arm-only and accept "overlay lives until DLL unload" as a known limitation. Most overlay mods work this way. |
| Upstream hudhook breaks our build on `cargo update` | low | Pin `hudhook = "=0.9.0"` and `imgui = "=0.12"`. Bump deliberately, not via `cargo update`. |
| `windows 0.62` (hudhook) vs `windows-sys 0.61` (us) version skew | low | Different crates with different feature surfaces. Both can coexist in the dependency graph. Confirm in Step 1 cargo build. |
| Wine / Proton corner cases | low (Horsey is Windows-only today) | hudhook supports Wine. Defer until anyone reports a Linux player. |
| Game ships a debug build with no DXGI, or uses a custom present path | low | Horsey is verified DX11 via HLT prior art (same swap chain hooks work for them). If a future target diverges, drop to the lift-and-port fallback below. |

## Test strategy

Three new harness tests under `horsey-mod/tests/`:

- `overlay_spike.rs` (Step 1): asserts hudhook applies and frames advance.
- `overlay_tabs.rs` (Step 2): asserts per-tab render fns execute.
- `overlay_lifecycle.rs` (Step 3): arm / disarm lifecycle, game survival.

Manual visual verification stays the source of truth for "the panel looks
right." Automated tests cover lifecycle, frame counters, tab routing.

## Open questions for Step 1

None block starting. Things to verify during the spike:

- Exact hudhook API for unapplying hooks (`eject` vs other name in
  v0.9.0).
- Cargo build with `windows 0.62` alongside our existing `windows-sys 0.61`
  is clean.
- Steam overlay coexistence is well-behaved.

## Attribution

This plan adopts [hudhook](https://github.com/veeenu/hudhook) v0.9.0 by
Andrea Venuta, MIT license. No code lifting required; hudhook is consumed
as a crates.io dependency. License compatibility is unidirectional and
trivial: MIT-licensed dependency, GPL v3 combined work.

---

## Fallback plan: lift hudhook's hook layer (if upstream churn becomes painful)

Kept here for the record. Use only if maintaining `cargo update` against
hudhook becomes a recurring burden, OR if a future requirement forces us
back onto the C++ ImGui shim for native-PE consumers.

Port `hudhook/src/hooks/dx11.rs` (~250 LOC) + `hudhook/src/mh.rs` (~100
LOC) + minimal `util.rs` subset into `modforge/src/ui/overlay/`. Replace
hudhook's `D3D11RenderEngine` (imgui-rs based) with `extern "C"` calls
into our existing C++ vendored `ImGui_ImplDX11_*` backends at
`ueforge/cpp/imgui/backends/imgui_impl_{dx11,win32}.{h,cpp}` (both files
verified present 2026-05-15). Vendor MinHook as a git submodule under
`modforge/cpp/minhook/`. License (MIT) lifts cleanly into GPL v3 with
attribution.

This path is concrete and viable but strictly more work than Path A. We
go here only if forced.
