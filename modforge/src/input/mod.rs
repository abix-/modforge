//! Synthetic input: mouse + keyboard.
//!
//! Three-layer architecture (validated by prior art in
//! [`../../docs/input-prior-art.md`](../../docs/input-prior-art.md)):
//!
//! - **L1** (`l1::send_input`): OS-global `SendInput`. Goes through the
//!   Windows raw-input pipeline; works on every app but steals focus
//!   and requires the target window to be foreground.
//! - **L2** (`l2::window_message`): per-window `PostMessage` /
//!   `SendMessage` to a target HWND. No focus theft, works on hidden
//!   windows. Some games (raw-input only) ignore these messages.
//! - **L3** (`InputSurface` trait): per-game internal pokes. Consumer
//!   mods (horsey-mod, grounded2-mod, ...) implement this trait against
//!   their engine's input subsystem (UE `APlayerController::InputKey`,
//!   Unity `Input.GetKey*` hook, raw-Win32 mouse-state poke).
//!
//! First-slice scope: L1 + L2 backends, mouse move/click, keyboard
//! down/up/press. Drag/scroll/combo/replay deferred. The HTTP cmdlets
//! in [`ops`] expose these primitives over the modforge op registry.

pub mod l1;
pub mod l2;
pub mod ops;

use serde::{Deserialize, Serialize};

/// Which input dispatch path to use for one call.
#[derive(Copy, Clone, Debug, Eq, PartialEq, Serialize, Deserialize, Default)]
#[serde(rename_all = "lowercase")]
pub enum Backend {
    /// `SendInput` (OS-global). Default.
    #[default]
    L1,
    /// `PostMessage`/`SendMessage` to a target HWND.
    L2,
}

impl Backend {
    pub fn parse(s: &str) -> Result<Backend, String> {
        match s.to_ascii_lowercase().as_str() {
            "l1" | "sendinput" | "send_input" => Ok(Backend::L1),
            "l2" | "postmessage" | "post_message" | "windowmessage" => Ok(Backend::L2),
            other => Err(format!(
                "unknown input backend '{other}' (expected l1|l2)"
            )),
        }
    }
}

/// Logical mouse buttons. Maps to Win32 `MOUSEEVENTF_*` / `MK_*`.
#[derive(Copy, Clone, Debug, Eq, PartialEq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
pub enum Button {
    Left,
    Right,
    Middle,
    XButton1,
    XButton2,
}

impl Button {
    pub fn parse(s: &str) -> Result<Button, String> {
        match s.to_ascii_lowercase().as_str() {
            "left" | "l" | "lmb" => Ok(Button::Left),
            "right" | "r" | "rmb" => Ok(Button::Right),
            "middle" | "m" | "mmb" => Ok(Button::Middle),
            "x1" | "xbutton1" => Ok(Button::XButton1),
            "x2" | "xbutton2" => Ok(Button::XButton2),
            other => Err(format!(
                "unknown mouse button '{other}' (expected left|right|middle|x1|x2)"
            )),
        }
    }
}

/// Virtual-key code (Windows VK_*). 0..=0xFF.
///
/// Construct via [`Key::parse`] (accepts friendly names like `"shift"`,
/// `"a"`, `"f4"`, or a hex like `"0x10"`).
#[derive(Copy, Clone, Debug, Eq, PartialEq, Serialize, Deserialize)]
pub struct Key(pub u16);

impl Key {
    /// Friendly-name parser. Recognized:
    /// - Modifiers: `shift`/`ctrl`/`control`/`alt`/`menu`/`win`/`lwin`/`rwin`
    /// - Whitespace: `space`/`tab`/`enter`/`return`/`backspace`/`esc`/`escape`
    /// - Navigation: `up`/`down`/`left`/`right`/`home`/`end`/`pageup`/`pagedown`/`insert`/`delete`
    /// - Letters: `a`..=`z` (case insensitive) -> VK_A..VK_Z (0x41..0x5A)
    /// - Digits: `0`..=`9` -> VK_0..VK_9 (0x30..0x39)
    /// - Function: `f1`..=`f24` -> VK_F1..VK_F24 (0x70..0x87)
    /// - Numeric: leading `0x` parsed as hex; otherwise as decimal
    pub fn parse(s: &str) -> Result<Key, String> {
        let s = s.trim();
        let lower = s.to_ascii_lowercase();
        let vk: u16 = match lower.as_str() {
            "shift" | "lshift" => 0xA0,
            "rshift" => 0xA1,
            "ctrl" | "control" | "lctrl" | "lcontrol" => 0xA2,
            "rctrl" | "rcontrol" => 0xA3,
            "alt" | "menu" | "lalt" | "lmenu" => 0xA4,
            "ralt" | "rmenu" => 0xA5,
            "win" | "lwin" | "lsuper" | "meta" => 0x5B,
            "rwin" | "rsuper" => 0x5C,
            "space" => 0x20,
            "tab" => 0x09,
            "enter" | "return" => 0x0D,
            "backspace" | "back" => 0x08,
            "esc" | "escape" => 0x1B,
            "up" => 0x26,
            "down" => 0x28,
            "left" => 0x25,
            "right" => 0x27,
            "home" => 0x24,
            "end" => 0x23,
            "pageup" | "pgup" => 0x21,
            "pagedown" | "pgdn" => 0x22,
            "insert" | "ins" => 0x2D,
            "delete" | "del" => 0x2E,
            "capslock" => 0x14,
            _ => {
                if let Some(hex) = lower.strip_prefix("0x") {
                    u16::from_str_radix(hex, 16)
                        .map_err(|e| format!("bad hex vk '{s}': {e}"))?
                } else if let Some(rest) = lower.strip_prefix('f') {
                    let n: u16 = rest
                        .parse()
                        .map_err(|_| format!("bad function key '{s}'"))?;
                    if !(1..=24).contains(&n) {
                        return Err(format!("function key {n} out of range 1..=24"));
                    }
                    0x70 + (n - 1)
                } else if lower.len() == 1 {
                    let c = lower.chars().next().unwrap();
                    if c.is_ascii_alphabetic() {
                        0x41 + (c as u16 - 'a' as u16)
                    } else if c.is_ascii_digit() {
                        0x30 + (c as u16 - '0' as u16)
                    } else {
                        return Err(format!("unrecognized single-char key '{s}'"));
                    }
                } else {
                    lower.parse::<u16>()
                        .map_err(|_| format!("unrecognized key name '{s}'"))?
                }
            }
        };
        if vk > 0xFF {
            return Err(format!("vk {vk:#x} > 0xFF"));
        }
        Ok(Key(vk))
    }
}

/// Per-game L3 input surface. Consumer mods implement this against
/// their engine's input subsystem; modforge registers it as the
/// optional L3 backend.
pub trait InputSurface: Send + Sync + 'static {
    fn name(&self) -> &'static str;
    fn click(&self, button: Button, x: i32, y: i32) -> Result<(), String>;
    fn move_abs(&self, x: i32, y: i32) -> Result<(), String>;
    fn key(&self, key: Key, down: bool) -> Result<(), String>;
}

/// Tag stamped on `INPUT.mi.dwExtraInfo` / `ki.dwExtraInfo` for L1
/// events so future input listeners can recognize self-sent events.
/// Random nonzero byte string ("modforge synthetic input").
pub const SYNTHETIC_EXTRA_INFO: usize = 0x6D_6F_64_66_69_6E_70_75;

/// Get the foreground window's HWND as a `*mut std::ffi::c_void` (the
/// `windows-sys` HWND type). Used by L2 as the default target when no
/// explicit HWND was supplied. Returns `None` if there is no
/// foreground window (rare, but possible during early process boot).
pub fn foreground_hwnd() -> Option<isize> {
    use windows_sys::Win32::UI::WindowsAndMessaging::GetForegroundWindow;
    let h = unsafe { GetForegroundWindow() };
    if h.is_null() { None } else { Some(h as isize) }
}

/// Enumerate top-level windows; return the first one owned by `pid`
/// that is visible. Useful when the test process and the game process
/// are separate: pass the game PID, get the game window.
///
/// Visibility filter: skips invisible windows (typical message-only
/// or hidden helper windows). If multiple visible top-level windows
/// belong to the same PID (rare for games), returns the first
/// EnumWindows yields.
pub fn find_hwnd_by_pid(pid: u32) -> Option<isize> {
    use std::ffi::c_void;
    use windows_sys::Win32::Foundation::{HWND, LPARAM};
    use windows_sys::Win32::UI::WindowsAndMessaging::{
        EnumWindows, GetWindowThreadProcessId, IsWindowVisible,
    };
    type BOOL = i32;

    struct Ctx {
        wanted_pid: u32,
        found: isize,
    }

    extern "system" fn cb(hwnd: HWND, lparam: LPARAM) -> BOOL {
        let ctx = unsafe { &mut *(lparam as *mut c_void as *mut Ctx) };
        let mut pid: u32 = 0;
        let _tid = unsafe { GetWindowThreadProcessId(hwnd, &mut pid) };
        if pid == ctx.wanted_pid && unsafe { IsWindowVisible(hwnd) } != 0 {
            ctx.found = hwnd as isize;
            return 0; // stop enumeration
        }
        1 // continue
    }

    let mut ctx = Ctx { wanted_pid: pid, found: 0 };
    let _ok = unsafe {
        EnumWindows(
            Some(cb),
            &mut ctx as *mut Ctx as *mut c_void as LPARAM,
        )
    };
    if ctx.found == 0 { None } else { Some(ctx.found) }
}
