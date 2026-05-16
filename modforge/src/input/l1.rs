//! L1 backend: OS-global synthetic input via `SendInput`.
//!
//! Mirrors enigo/winput/rdev shape but hand-rolled over the existing
//! `windows-sys` dep so modforge picks up zero new crates.
//!
//! All events are tagged with [`super::SYNTHETIC_EXTRA_INFO`] so a
//! future input listener can ignore our own synthesized events.
//!
//! Coordinate space: `move_abs` accepts physical screen pixels in the
//! 0..65535 normalized space required by `MOUSEEVENTF_ABSOLUTE`; the
//! conversion is internal.

use windows_sys::Win32::Foundation::POINT;
use windows_sys::Win32::UI::Input::KeyboardAndMouse::{
    INPUT, INPUT_0, INPUT_KEYBOARD, INPUT_MOUSE, KEYBDINPUT, KEYEVENTF_KEYUP, KEYEVENTF_SCANCODE,
    MOUSEEVENTF_ABSOLUTE, MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP, MOUSEEVENTF_MIDDLEDOWN,
    MOUSEEVENTF_MIDDLEUP, MOUSEEVENTF_MOVE, MOUSEEVENTF_RIGHTDOWN, MOUSEEVENTF_RIGHTUP,
    MOUSEEVENTF_VIRTUALDESK, MOUSEEVENTF_XDOWN, MOUSEEVENTF_XUP, MOUSEINPUT, MapVirtualKeyW,
    SendInput,
};
use windows_sys::Win32::UI::WindowsAndMessaging::{
    GetCursorPos, GetSystemMetrics, SM_CXVIRTUALSCREEN, SM_CYVIRTUALSCREEN, SM_XVIRTUALSCREEN,
    SM_YVIRTUALSCREEN,
};

use super::{Button, Key, SYNTHETIC_EXTRA_INFO};

fn send(input: &INPUT) -> Result<(), String> {
    let n = unsafe { SendInput(1, input as *const INPUT, size_of::<INPUT>() as i32) };
    if n == 1 {
        Ok(())
    } else {
        let err = std::io::Error::last_os_error();
        Err(format!("SendInput returned {n} (last_os_error = {err})"))
    }
}

fn screen_to_normalized(x: i32, y: i32) -> (i32, i32) {
    // MOUSEEVENTF_ABSOLUTE expects 0..65535 normalized to the virtual
    // screen (multi-monitor aware via MOUSEEVENTF_VIRTUALDESK).
    let vx = unsafe { GetSystemMetrics(SM_XVIRTUALSCREEN) };
    let vy = unsafe { GetSystemMetrics(SM_YVIRTUALSCREEN) };
    let vw = unsafe { GetSystemMetrics(SM_CXVIRTUALSCREEN) }.max(1);
    let vh = unsafe { GetSystemMetrics(SM_CYVIRTUALSCREEN) }.max(1);
    let nx = ((x - vx) as i64 * 65535 / vw as i64) as i32;
    let ny = ((y - vy) as i64 * 65535 / vh as i64) as i32;
    (nx, ny)
}

/// Read the current OS cursor position in screen pixels.
pub fn cursor_pos() -> Result<(i32, i32), String> {
    let mut p = POINT { x: 0, y: 0 };
    let ok = unsafe { GetCursorPos(&mut p) };
    if ok != 0 {
        Ok((p.x, p.y))
    } else {
        Err(format!("GetCursorPos failed: {}", std::io::Error::last_os_error()))
    }
}

/// Move the cursor to absolute screen coordinates.
pub fn move_abs(x: i32, y: i32) -> Result<(), String> {
    let (nx, ny) = screen_to_normalized(x, y);
    let input = INPUT {
        r#type: INPUT_MOUSE,
        Anonymous: INPUT_0 {
            mi: MOUSEINPUT {
                dx: nx,
                dy: ny,
                mouseData: 0,
                dwFlags: MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK,
                time: 0,
                dwExtraInfo: SYNTHETIC_EXTRA_INFO,
            },
        },
    };
    send(&input)
}

fn button_flags(b: Button, down: bool) -> (u32, u32) {
    match b {
        Button::Left => (
            if down { MOUSEEVENTF_LEFTDOWN } else { MOUSEEVENTF_LEFTUP },
            0,
        ),
        Button::Right => (
            if down { MOUSEEVENTF_RIGHTDOWN } else { MOUSEEVENTF_RIGHTUP },
            0,
        ),
        Button::Middle => (
            if down { MOUSEEVENTF_MIDDLEDOWN } else { MOUSEEVENTF_MIDDLEUP },
            0,
        ),
        Button::XButton1 => (
            if down { MOUSEEVENTF_XDOWN } else { MOUSEEVENTF_XUP },
            0x0001,
        ),
        Button::XButton2 => (
            if down { MOUSEEVENTF_XDOWN } else { MOUSEEVENTF_XUP },
            0x0002,
        ),
    }
}

fn mouse_button_event(b: Button, down: bool) -> Result<(), String> {
    let (flags, data) = button_flags(b, down);
    let input = INPUT {
        r#type: INPUT_MOUSE,
        Anonymous: INPUT_0 {
            mi: MOUSEINPUT {
                dx: 0,
                dy: 0,
                mouseData: data,
                dwFlags: flags,
                time: 0,
                dwExtraInfo: SYNTHETIC_EXTRA_INFO,
            },
        },
    };
    send(&input)
}

/// Click `button` at `(x, y)` screen pixels. Moves cursor first, then
/// presses + releases. The 1ms gap is omitted; most games sample
/// state once per frame so back-to-back down/up still register.
pub fn click(button: Button, x: i32, y: i32) -> Result<(), String> {
    move_abs(x, y)?;
    mouse_button_event(button, true)?;
    mouse_button_event(button, false)?;
    Ok(())
}

fn key_event(key: Key, down: bool) -> Result<(), String> {
    let scan = unsafe { MapVirtualKeyW(key.0 as u32, 0 /* MAPVK_VK_TO_VSC */) } as u16;
    let mut flags = KEYEVENTF_SCANCODE;
    if !down {
        flags |= KEYEVENTF_KEYUP;
    }
    let input = INPUT {
        r#type: INPUT_KEYBOARD,
        Anonymous: INPUT_0 {
            ki: KEYBDINPUT {
                wVk: 0,
                wScan: scan,
                dwFlags: flags,
                time: 0,
                dwExtraInfo: SYNTHETIC_EXTRA_INFO,
            },
        },
    };
    send(&input)
}

/// Press a key (no release).
pub fn key_down(key: Key) -> Result<(), String> {
    key_event(key, true)
}

/// Release a key (no press).
pub fn key_up(key: Key) -> Result<(), String> {
    key_event(key, false)
}

/// Press + release. `hold_ms` (if > 0) sleeps between down and up.
pub fn key_press(key: Key, hold_ms: u32) -> Result<(), String> {
    key_event(key, true)?;
    if hold_ms > 0 {
        std::thread::sleep(std::time::Duration::from_millis(hold_ms as u64));
    }
    key_event(key, false)
}
