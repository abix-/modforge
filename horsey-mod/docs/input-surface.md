# Horsey L3 InputSurface: findings + design

> **Status:** decomp pass done 2026-05-16. Implementation in progress.
> Driving doc for the per-game L3 `InputSurface` impl in
> [`../../modforge/docs/input-prior-art.md`](../../modforge/docs/input-prior-art.md)
> (PR-4 "Raw Win32" lane).

## How Horsey reads input (decomp findings)

Function around `all_functions.c:277800-277900` (callable as
`FUN_14018d160` or similar; the engine's per-frame input pump). It
does THREE things every frame:

1. **Win32 message pump** (lines 277815-277831). Standard
   `PeekMessageW(NULL,NULL,0,0,PM_REMOVE)` + `TranslateMessage` +
   `DispatchMessageW` loop with a 3-message cap per frame. This is
   the path for WndProc-based UI: text input, ImGui-style mouse
   events, etc.

2. **Keyboard modifier reconciliation** (lines 277834-277852).
   Reads `GetKeyState` for VK_LSHIFT (0xA0), VK_RSHIFT (0xA1),
   VK_LWIN (0x5B), VK_RWIN (0x5C). Reconciles against engine-side
   flags at `FUN_140183330(0)+0xe1/+0xe5/+0xe3/+0xe7`. When the
   OS state says "modifier is up" but the engine still has it
   logged as down, calls `FUN_140183990(0, 0, 0, vk_code, ...)` to
   release.

3. **Mouse position + buttons** (lines 277859-277896). Gates on
   `FUN_140183290()` returning a non-null window struct. Then:
   - `GetCursorPos(&p)` -> `ScreenToClient(hwnd, &p)`. Cursor in
     client-area px.
   - `FUN_1401628f0(<mouse_state>, ..., (float)client_x, (float)client_y)`.
     Pushes the new position into the engine's mouse-state struct.
   - `GetAsyncKeyState(VK_LBUTTON|VK_RBUTTON|VK_MBUTTON|VK_XBUTTON1|VK_XBUTTON2)`
     for each of VK 1, 2, 4, 5, 6.
   - `FUN_1401628d0(<mouse_state>, ..., button_idx, (byte)((SVar4 >> 0xf) & 1))`.
     Pushes the per-button down/up bit into the same struct.

The `<mouse_state>` struct pointer is the return value of
`FUN_14018c5c0()` (an accessor that probably hangs off
GameState/InputManager). This is the engine's authoritative mouse
state buffer. Once we identify its address + field offsets, L3
mouse writes go straight there and bypass the pump entirely.

`RegisterRawInputDevices` at lines 370695, 370757 + `GetRawInputData`
at 371225 confirm Horsey opts into raw input for at least one
device (probably for relative-motion in some camera mode). But the
per-frame pump above is the dominant path for cursor + UI clicks.

## Implications for the modforge input axis

- **L1 `SendInput` should work natively.** It updates BOTH the
  Win32 message queue (consumed by line 277825) AND the OS-level
  GetAsyncKeyState / GetCursorPos state (consumed by lines
  277862-277895). Our smoke test confirmed the OS-cursor side; the
  game-side will be confirmed when the recon test runs in-save.
- **L2 `PostMessage` is partially limited.** Mouse-BUTTON messages
  go through the WndProc, but the engine polls `GetAsyncKeyState`
  for button state. A `WM_LBUTTONDOWN` arriving without
  the OS-state bit set will fire the WndProc handler but the
  engine's mouse-state struct won't see "button is held". `move`
  through `WM_MOUSEMOVE` should work because the engine also polls
  cursor via `GetCursorPos` and reconciles. Bottom line: L2 is
  partial; favor L1 or L3 for clicks.
- **L3 is the highest-reliability path** and bypasses all three
  pump branches at once.

## L3 InputSurface impl plan (Horsey)

### Surface 1: cursor position (already viable)

The HK1 work resolved `LOC+0x174`/`+0x178` (client-coord cursor
floats) on the Home Location. Writing these directly is what
`hk1.set_target` already does. L3 `move_abs` reuses that machinery:

```rust
fn move_abs(&self, x: i32, y: i32) -> Result<(), String> {
    // Write the OS cursor too so any other consumer (overlay,
    // debug op) sees a consistent state.
    crate::input::l1::move_abs(x, y)?;
    // Game-side cursor: convert screen -> client -> LOC floats.
    let (cx, cy) = client_coords_from_screen(x, y)?;
    write_loc_cursor(cx as f32, cy as f32);
    Ok(())
}
```

### Surface 2: click (first useful primitive)

Two candidates, in order of preference:

A. **Direct write to mouse-state struct** at `FUN_14018c5c0()`'s
   return. Pattern-resolve the accessor's body to find the struct
   address, then write the button-down byte directly. Bypasses
   ALL three pump branches. Requires one R2 sig-tune session.

B. **Call the click dispatcher** (`FUN_1400d2ab0` for HK1 click
   handling, or the generic UI click router). Same approach HK1
   already uses for transfer. Requires a working LOC + drag_idx
   stage but doesn't need the mouse-state struct address.

v1 ships B (HK1-shaped). v2 swaps to A once the mouse-state struct
is resolved.

### Surface 3: keyboard (deferred)

Skip in v1. Decomp tells us `FUN_140183330(0)+0xe1` etc. are the
modifier flags; writing those bytes simulates "modifier held". But
non-modifier keys are routed differently and need more decomp work
(probably through `FUN_140183990`). Defer to a v2 once a real
consumer needs L3 keyboard.

## Modforge-side wiring

Add to `modforge::input`:

```rust
use std::sync::OnceLock;
static SURFACE: OnceLock<Box<dyn InputSurface>> = OnceLock::new();

pub fn set_input_surface(s: Box<dyn InputSurface>) {
    let _ = SURFACE.set(s); // first wins; second is silently ignored
}

pub fn input_surface() -> Option<&'static dyn InputSurface> {
    SURFACE.get().map(|b| &**b)
}
```

Then `input.mouse.move {backend: "l3"}` dispatches through
`input_surface()`. The trait already exists at
`modforge::input::InputSurface`.

Add `Backend::L3` variant. Default backend selection upgrades:

| Context | Default backend |
|---|---|
| `InputSurface` registered | L3 |
| `hwnd` arg supplied | L2 |
| Otherwise | L1 |

## Open questions

- **What does `FUN_14018c5c0()` return?** Need to disassemble it
  to find which singleton + offset it accesses. This is the gating
  R2 step for "Surface 2 candidate A".
- **`FUN_1401628d0` button-index convention.** From the decomp,
  buttons are mapped {1->LMB?, 3->RMB?, 2->MMB, 4->XBUTTON1,
  5->XBUTTON2} based on the order; the iVar12 conditional
  (line 277871) swaps 1 and 3 conditionally on GetSystemMetrics(0x17)
  (SM_SWAPBUTTON). Worth a closer read before we synthesize clicks.
- **Mouse-state struct lifecycle.** Singleton or per-frame? If
  per-frame, the write window is narrow and we'd need to hook the
  pump to land writes at the right moment.

## Definition of done (v1)

- [ ] `modforge::input::set_input_surface` + `input_surface`
  accessor + `Backend::L3` variant land.
- [ ] `input.mouse.move` and `input.mouse.click` route through L3
  when registered.
- [ ] `horsey-mod::input_surface::HorseyInputSurface` impl ships
  with mouse-move via LOC float writes.
- [ ] A live smoke test asserts that an `input.mouse.move backend=l3`
  causes `hk1.read_cursor` to report the new position
  immediately (no per-frame settle needed; we wrote it directly).
- [ ] Wired at attach via one line in horsey-mod's worker init.
