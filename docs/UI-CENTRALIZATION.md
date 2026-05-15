## Centralizing ImGui across modforge consumers

> **Authoritative on:** the plan to consolidate the Rust ImGui API + C++ shim into modforge so every game-mod (ueforge / horsey-mod / unityforge / outworld-station-mod / grounded2-mod / future) uses the same surface, regardless of which host runtime (UE4SS, BepInEx, none) owns the actual ImGui context.

Status: PROPOSED 2026-05-15. Not yet executed.

## Current state

ImGui is split across three layers today:

1. **Declarative tab shape. Already centralized.** `modforge::ui::TabDef { name, render: fn() }` lives in `modforge/src/ui.rs` and is consumed identically by every game-mod.

2. **Rust ImGui primitives. NOT centralized.** `ueforge::ui::{text, button, slider_f32, checkbox, progress_bar, ...}` (`ueforge/src/ui.rs`, ~250 LOC of safe Rust wrappers) is the API tabs call from their `render: fn()`. Every UE-based mod (grounded2, outworld-station, future) currently imports from `ueforge::ui`. Mods on non-UE engines (horsey-mod) have no equivalent.

3. **C++ shim. NOT centralized.** `ueforge/cpp/ueforge_ui.cpp` defines `extern "C" fn ueforge_ui_text` etc., calls vendored ImGui at `ueforge/cpp/imgui/`. The shim shares UE4SS's ImGui context via the bridge header `ueforge/cpp/ueforge_imgui_bridge.hpp`. horsey-mod has nothing here.

### Per-engine ImGui ownership

| Engine | Runtime | ImGui context owner | Render trigger |
|---|---|---|---|
| UE4SS (ueforge) | host runtime, links UE4SS.lib | UE4SS.dll | UE4SS's per-frame render hook calls the mod's tab render |
| BepInEx / Unity (unityforge) | host runtime, BepInEx ImGui plugin | BepInEx | per-frame OnGUI |
| native PE (horsey-mod) | none | **gap** | **gap** |

For native PE games like Horsey there is no host runtime to provide an ImGui context. The standalone-window approach used by HorseyLiveTweaks (see [`horsey-mod/docs/PRIOR-ART-HorseyLiveTweaks.md`](../horsey-mod/docs/PRIOR-ART-HorseyLiveTweaks.md)) is the right model: the mod opens its own top-level Win32 window with its own D3D11 device + swap chain + ImGui context, sitting beside the game window.

## Target state

```
modforge::ui::TabDef              ← already shared
modforge::ui::{text,button,...}   ← NEW: shared Rust API
modforge_ui_text() etc.           ← NEW: extern C, exported by one of:
                                     - modforge::ui::backend::ue4ss   (Cargo feature)
                                     - modforge::ui::backend::native  (Cargo feature)
                                     - modforge::ui::backend::bepinex (future)
modforge/cpp/imgui/               ← vendored ImGui at workspace level
modforge/cpp/modforge_ui_*.cpp    ← per-backend shim
```

Per-engine crates pick the backend:

- `ueforge` enables the `ue4ss` feature on modforge. Its C++ side compiles `modforge_ui_ue4ss.cpp` linking the UE4SS bridge.
- `horsey-mod` enables the `native` feature. Its C++ side compiles `modforge_ui_native.cpp` which runs its own Win32 + D3D11 + ImGui_Impl_Win32 + ImGui_Impl_DX11.

Tab `render: fn()` bodies in game-mods stay BYTE-IDENTICAL across backends. The same `modforge::ui::text("Hello")` call routes through the chosen shim.

## Migration plan (phased, low-risk)

### Phase A: add the standalone-window backend without touching existing consumers

This is the smallest move that unblocks horsey-mod without disrupting working code in ueforge / grounded2 / outworld-station.

1. **Vendor ImGui at the workspace level.** Add `modforge/cpp/imgui/` as a git submodule (same version as ueforge ships, currently v1.92.1).
2. **Write `modforge/cpp/modforge_ui_native.cpp`.** Owns:
   - `WNDCLASS` + `CreateWindow(WS_OVERLAPPEDWINDOW)` for a top-level window
   - `D3D11CreateDeviceAndSwapChain` + render target view
   - `ImGui::CreateContext`, `ImGui_ImplWin32_Init`, `ImGui_ImplDX11_Init`
   - WndProc that forwards to `ImGui_ImplWin32_WndProcHandler`
   - Background-thread render loop: PeekMessage / Translate / Dispatch, NewFrame, walk registered `TabDef`s calling `render()`, Render, Present.
   - Extern C surface: `modforge_native_ui_spawn(tabs_ptr, tabs_len)`, `modforge_native_ui_shutdown()`, and ImGui-wrapper exports (`modforge_ui_text`, `modforge_ui_button`, etc.) that match the existing `ueforge_ui_*` shapes.
3. **Write `modforge/src/ui/native.rs`.** Safe Rust wrapper over the extern C surface. Takes `&'static [TabDef]`, calls `modforge_native_ui_spawn`.
4. **Write `modforge/src/ui/api.rs`.** Rust wrappers identical to `ueforge::ui::*` (text, button, etc.) that call `modforge_ui_*` extern fns. Initially: linked at runtime only by the `native` feature.
5. **Build infra.** `modforge/build.rs` compiles `modforge_ui_native.cpp` + ImGui sources when the `native` Cargo feature is on.
6. **horsey-mod adopts.** Add `modforge = { features = ["native-ui"] }` to its Cargo.toml; call `modforge::ui::native::spawn(&MY_TABS)` from `worker_main`.
7. **Failing test first.** `tests/native_ui_lifecycle.rs` asserts `spawn` returns OK, the window is detectable via `FindWindowW(L"HorseyImGuiWnd", ...)`, `shutdown` closes cleanly, no leaks. (Harness already supports cross-launch testing.)

Existing ueforge / grounded2-mod / outworld-station-mod stay UNCHANGED. They keep using `ueforge::ui::*` and the UE4SS bridge shim. Zero churn for working code.

### Phase B: unify the Rust API surface

After Phase A is shipped and horsey-mod is using `modforge::ui::native::*`:

1. **Promote `ueforge::ui::*` into `modforge::ui::*`.** Same function signatures, just relocated. Rename extern C fns from `ueforge_ui_*` to `modforge_ui_*`.
2. **Add the UE4SS-bridge backend in modforge.** `modforge/cpp/modforge_ui_ue4ss.cpp` is the relocated `ueforge_ui.cpp`. Same UE4SS bridge header.
3. **Cargo feature `ue4ss-ui`** on modforge selects this backend.
4. **ueforge becomes a thin alias.** `ueforge::ui::*` re-exports `modforge::ui::*` so existing consumers keep compiling without changes.
5. **One per-consumer Cargo.toml flip:** `modforge = { features = ["ue4ss-ui"] }`.

After Phase B every game-mod's `render: fn()` body is identical across engines. Modders can write one tab and ship it everywhere modforge supports.

### Phase C: BepInEx / Unity backend

Future. `modforge/cpp/modforge_ui_bepinex.cpp` or equivalent. Same surface, different render trigger (Unity's OnGUI or BepInEx's ImGui plugin).

## Test strategy

Per the test-first rule:

- **Phase A failing test:** `horsey-mod/tests/native_ui_lifecycle.rs`. Asserts `modforge::ui::native::spawn` opens a discoverable window and `shutdown` closes it cleanly. Window's existence is detectable via `FindWindowW`. Cross-game-launch behavior via the existing harness.
- **Phase B contract test:** `tests/ui_api_parity.rs` (unit). Verifies the `modforge::ui::*` Rust API has the same shape as `ueforge::ui::*` before promotion. Catches accidental signature drift.
- **Phase C contract test:** `tests/bepinex_backend_spawn.rs` once BepInEx games come into scope.

Manual visual verification stays the source of truth for "the window looks right." Automated tests cover lifecycle + API contracts.

## Risk + non-goals

- **NOT replacing UE4SS's ImGui for ueforge.** UE4SS owns the host context for UE games; we share it via the bridge. Don't fight the host.
- **NOT a new ImGui binding crate.** We use vendored ImGui via C++ shim (same pattern ueforge uses today). No `imgui-rs` dependency.
- **NOT touching grounded2-mod / outworld-station-mod source.** Phase B's ueforge alias keeps them working.
- **Risk:** the standalone window backend runs in a SEPARATE process-shared thread. Crashes in the render loop must not propagate to the game's main thread. Use `__try` (or Rust's `catch_unwind` analog at the C++ boundary).
- **Risk:** input focus stealing. The mod window is top-level; players will alt-tab between it and the game. Need to handle minimize/restore + per-game-window topmost behavior.

## When to start

User-approved 2026-05-15. Starting Phase A.
