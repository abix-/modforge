//! L2 backend: per-window synthetic input via `PostMessage` /
//! `SendMessage`.
//!
//! No focus theft, no cursor visibly moving on the user's desktop.
//! The target window must process the standard `WM_LBUTTONDOWN` /
//! `WM_KEYDOWN` family; raw-input games bypass these messages and
//! will ignore us (use L1 or L3 there).
//!
//! Coordinate convention: all `(x, y)` here are CLIENT-RELATIVE
//! pixels of the target HWND, packed into the `lParam` per the Win32
//! mouse-message convention.

use windows_sys::Win32::Foundation::{HWND, LPARAM, POINT, WPARAM};
use windows_sys::Win32::Graphics::Gdi::ClientToScreen;
use windows_sys::Win32::UI::WindowsAndMessaging::{
    PostMessageW, SendMessageW, WM_KEYDOWN, WM_KEYUP, WM_LBUTTONDOWN, WM_LBUTTONUP, WM_MBUTTONDOWN,
    WM_MBUTTONUP, WM_MOUSEMOVE, WM_RBUTTONDOWN, WM_RBUTTONUP, WM_XBUTTONDOWN, WM_XBUTTONUP,
};

use super::{Button, Key};

// MK_* mouse-modifier bits (stable Win32 constants, not exposed in
// the windows-sys WindowsAndMessaging module).
const MK_LBUTTON: u32 = 0x0001;
const MK_RBUTTON: u32 = 0x0002;
const MK_SHIFT: u32 = 0x0004;
const MK_CONTROL: u32 = 0x0008;
const MK_MBUTTON: u32 = 0x0010;
const MK_XBUTTON1: u32 = 0x0020;
const MK_XBUTTON2: u32 = 0x0040;
// XBUTTON index (HIWORD of wParam in WM_XBUTTONDOWN/UP).
const XBUTTON1: u32 = 0x0001;
const XBUTTON2: u32 = 0x0002;

fn hwnd_from_isize(h: isize) -> HWND {
    h as HWND
}

fn make_lparam(x: i32, y: i32) -> LPARAM {
    // lParam: low word = x, high word = y. Both client-relative.
    (((y as u32 & 0xFFFF) << 16) | (x as u32 & 0xFFFF)) as LPARAM
}

fn post(hwnd: isize, msg: u32, wparam: WPARAM, lparam: LPARAM) -> Result<(), String> {
    let h = hwnd_from_isize(hwnd);
    let ok = unsafe { PostMessageW(h, msg, wparam, lparam) };
    if ok != 0 {
        Ok(())
    } else {
        Err(format!(
            "PostMessageW(msg={msg:#x}) failed: {}",
            std::io::Error::last_os_error()
        ))
    }
}

/// Same as [`post`] but synchronous: blocks until the WndProc returns.
/// Useful when ordering matters (e.g. a click must arrive AFTER a
/// preceding `WM_MOUSEMOVE` has updated the engine's cached cursor).
pub fn send_sync(hwnd: isize, msg: u32, wparam: WPARAM, lparam: LPARAM) -> Result<isize, String> {
    let h = hwnd_from_isize(hwnd);
    // SendMessageW always returns an LRESULT; "failure" surfaces via
    // GetLastError after the call (and only when the post was rejected
    // outright, e.g. invalid HWND). We don't surface that here because
    // legit LRESULTs of 0 are common; callers verify by polling.
    let lr = unsafe { SendMessageW(h, msg, wparam, lparam) };
    Ok(lr as isize)
}

/// Move the mouse over `hwnd` to client-relative `(x, y)`. Sends a
/// single `WM_MOUSEMOVE` with no buttons held.
pub fn move_client(hwnd: isize, x: i32, y: i32) -> Result<(), String> {
    post(hwnd, WM_MOUSEMOVE, 0, make_lparam(x, y))
}

fn mk_for_button(b: Button) -> WPARAM {
    match b {
        Button::Left => MK_LBUTTON as WPARAM,
        Button::Right => MK_RBUTTON as WPARAM,
        Button::Middle => MK_MBUTTON as WPARAM,
        Button::XButton1 => MK_XBUTTON1 as WPARAM,
        Button::XButton2 => MK_XBUTTON2 as WPARAM,
    }
}

/// Click `button` at client-relative `(x, y)` on `hwnd`.
///
/// Sequence: `WM_MOUSEMOVE` (so the game's cached cursor matches),
/// then `WM_*BUTTONDOWN`, then `WM_*BUTTONUP`. Modifier mask
/// (`mk_extra`) ORed into wParam reports e.g. Shift held; pass 0 if
/// not chording.
pub fn click(
    hwnd: isize,
    button: Button,
    x: i32,
    y: i32,
    mk_extra: u32,
) -> Result<(), String> {
    let lparam = make_lparam(x, y);
    let mk_btn = mk_for_button(button) as u32;
    let wparam_down = (mk_btn | mk_extra) as WPARAM;
    let wparam_up = mk_extra as WPARAM;

    move_client(hwnd, x, y)?;

    let (msg_down, msg_up, wparam_xbtn) = match button {
        Button::Left => (WM_LBUTTONDOWN, WM_LBUTTONUP, 0u32),
        Button::Right => (WM_RBUTTONDOWN, WM_RBUTTONUP, 0u32),
        Button::Middle => (WM_MBUTTONDOWN, WM_MBUTTONUP, 0u32),
        Button::XButton1 => (WM_XBUTTONDOWN, WM_XBUTTONUP, XBUTTON1 as u32),
        Button::XButton2 => (WM_XBUTTONDOWN, WM_XBUTTONUP, XBUTTON2 as u32),
    };

    if matches!(button, Button::XButton1 | Button::XButton2) {
        // X-button messages pack the X-button index in the HIGH word
        // of wParam, mod mask in the LOW word.
        let wparam_x_down = ((wparam_xbtn << 16) | (mk_btn | mk_extra)) as WPARAM;
        let wparam_x_up = ((wparam_xbtn << 16) | mk_extra) as WPARAM;
        post(hwnd, msg_down, wparam_x_down, lparam)?;
        post(hwnd, msg_up, wparam_x_up, lparam)?;
    } else {
        post(hwnd, msg_down, wparam_down, lparam)?;
        post(hwnd, msg_up, wparam_up, lparam)?;
    }
    Ok(())
}

/// Press `key` (`WM_KEYDOWN`). No release.
pub fn key_down(hwnd: isize, key: Key) -> Result<(), String> {
    post(hwnd, WM_KEYDOWN, key.0 as WPARAM, 1 /* repeat count */)
}

/// Release `key` (`WM_KEYUP`).
pub fn key_up(hwnd: isize, key: Key) -> Result<(), String> {
    // lParam bits: 0-15 repeat count, 30 previous state, 31 transition.
    // For a key-up we set bit 30 (previous state = down) and bit 31
    // (transition = up). 0xC0000001 is the canonical key-up lParam.
    post(hwnd, WM_KEYUP, key.0 as WPARAM, 0xC0000001u32 as LPARAM)
}

/// Press + release. `hold_ms` (if > 0) sleeps between down and up.
pub fn key_press(hwnd: isize, key: Key, hold_ms: u32) -> Result<(), String> {
    key_down(hwnd, key)?;
    if hold_ms > 0 {
        std::thread::sleep(std::time::Duration::from_millis(hold_ms as u64));
    }
    key_up(hwnd, key)
}

/// Convert client-relative `(x, y)` into screen pixels. Useful for
/// cross-checking L2 against L1 (which uses screen coords) inside a
/// single test.
pub fn client_to_screen(hwnd: isize, x: i32, y: i32) -> Result<(i32, i32), String> {
    let mut p = POINT { x, y };
    let ok = unsafe { ClientToScreen(hwnd_from_isize(hwnd), &mut p) };
    if ok != 0 {
        Ok((p.x, p.y))
    } else {
        Err(format!(
            "ClientToScreen failed: {}",
            std::io::Error::last_os_error()
        ))
    }
}

/// Compose `mk_extra` modifier-mask bits for `Shift`/`Ctrl` held during a click.
pub fn modifier_mask(shift: bool, ctrl: bool) -> u32 {
    let mut m = 0u32;
    if shift {
        m |= MK_SHIFT as u32;
    }
    if ctrl {
        m |= MK_CONTROL as u32;
    }
    m
}
