//! HTTP cmdlets that expose [`super::l1`] and [`super::l2`] over the
//! modforge op registry.
//!
//! First-slice surface (drag/scroll/combo/replay/state.get deferred):
//!
//! - `input.mouse.move {x, y, backend?, hwnd?}`
//! - `input.mouse.click {button, x, y, backend?, hwnd?, mods?}`
//! - `input.key.down {key, backend?, hwnd?}`
//! - `input.key.up   {key, backend?, hwnd?}`
//! - `input.key.press {key, hold_ms?, backend?, hwnd?}`
//! - `input.cursor.get` -> screen-pixel cursor pos via `GetCursorPos`
//!
//! `backend` defaults to `"l2"` when an `hwnd` arg is supplied OR a
//! foreground window is available; falls back to `"l1"` otherwise.
//!
//! `hwnd` is hex string (e.g. `"0x1234abcd"`). When omitted, L2 uses
//! `GetForegroundWindow`. L2 coords are CLIENT-RELATIVE to that hwnd;
//! L1 coords are SCREEN pixels.

use serde_json::{json, Value as Json};

use crate::ops::OpDef;

use super::{l1, l2, Backend, Button, Key};

fn arg_i32(args: &Json, name: &str) -> Result<i32, String> {
    args.get(name)
        .and_then(Json::as_i64)
        .ok_or_else(|| format!("missing arg '{name}' (i32)"))
        .and_then(|v| {
            i32::try_from(v).map_err(|_| format!("arg '{name}' = {v} out of i32 range"))
        })
}

fn arg_u32(args: &Json, name: &str, default: Option<u32>) -> Result<u32, String> {
    match args.get(name).and_then(Json::as_u64) {
        Some(v) => u32::try_from(v).map_err(|_| format!("arg '{name}' = {v} out of u32 range")),
        None => default.ok_or_else(|| format!("missing arg '{name}' (u32)")),
    }
}

fn arg_str_opt<'a>(args: &'a Json, name: &str) -> Option<&'a str> {
    args.get(name).and_then(Json::as_str)
}

fn parse_hwnd(args: &Json) -> Result<Option<isize>, String> {
    let Some(s) = arg_str_opt(args, "hwnd") else {
        return Ok(None);
    };
    let trimmed = s.trim_start_matches("0x").trim_start_matches("0X");
    let v = u64::from_str_radix(trimmed, 16)
        .map_err(|e| format!("bad hwnd '{s}': {e}"))?;
    Ok(Some(v as isize))
}

fn parse_backend(args: &Json) -> Result<Backend, String> {
    match arg_str_opt(args, "backend") {
        Some(s) => Backend::parse(s),
        None => Ok(Backend::default()),
    }
}

fn resolve_l2_hwnd(args: &Json) -> Result<isize, String> {
    if let Some(h) = parse_hwnd(args)? {
        return Ok(h);
    }
    super::foreground_hwnd()
        .ok_or_else(|| "no hwnd given and GetForegroundWindow returned NULL".into())
}

fn parse_mods(args: &Json) -> (bool, bool) {
    let shift = args
        .get("mods")
        .and_then(Json::as_array)
        .map(|a| a.iter().any(|v| v.as_str() == Some("shift")))
        .unwrap_or(false);
    let ctrl = args
        .get("mods")
        .and_then(Json::as_array)
        .map(|a| a.iter().any(|v| v.as_str() == Some("ctrl") || v.as_str() == Some("control")))
        .unwrap_or(false);
    (shift, ctrl)
}

/// Every op declared in this module. Consumer mods call
/// `OP_REGISTRY.register_many(modforge::input::ops::all())` at attach.
pub fn all() -> Vec<OpDef> {
    vec![
        OpDef::new(
            "input.mouse.move",
            "Move the mouse to (x, y). L1 = screen px; L2 = client-area px of hwnd.",
            "{x: i32, y: i32, backend?: l1|l2, hwnd?: hex}",
            |args| {
                let x = arg_i32(args, "x")?;
                let y = arg_i32(args, "y")?;
                let backend = parse_backend(args)?;
                match backend {
                    Backend::L1 => l1::move_abs(x, y)?,
                    Backend::L2 => {
                        let h = resolve_l2_hwnd(args)?;
                        l2::move_client(h, x, y)?;
                    }
                }
                Ok(json!({"ok": true, "backend": backend, "x": x, "y": y}))
            },
        ),
        OpDef::new(
            "input.mouse.click",
            "Click `button` at (x, y). L1 = screen px; L2 = client-area px of hwnd.",
            "{button: left|right|middle|x1|x2, x: i32, y: i32, backend?: l1|l2, hwnd?: hex, mods?: [shift|ctrl]}",
            |args| {
                let btn_s = arg_str_opt(args, "button").unwrap_or("left");
                let button = Button::parse(btn_s)?;
                let x = arg_i32(args, "x")?;
                let y = arg_i32(args, "y")?;
                let backend = parse_backend(args)?;
                let (shift, ctrl) = parse_mods(args);
                match backend {
                    Backend::L1 => {
                        // For L1 chord-clicks, press the mod keys around the click.
                        if shift { l1::key_down(Key(0xA0))?; }
                        if ctrl  { l1::key_down(Key(0xA2))?; }
                        let r = l1::click(button, x, y);
                        if ctrl  { let _ = l1::key_up(Key(0xA2)); }
                        if shift { let _ = l1::key_up(Key(0xA0)); }
                        r?
                    }
                    Backend::L2 => {
                        let h = resolve_l2_hwnd(args)?;
                        let mk_extra = l2::modifier_mask(shift, ctrl);
                        l2::click(h, button, x, y, mk_extra)?;
                    }
                }
                Ok(json!({"ok": true, "backend": backend, "button": btn_s, "x": x, "y": y}))
            },
        ),
        OpDef::new(
            "input.key.down",
            "Press a key (no release).",
            "{key: str, backend?: l1|l2, hwnd?: hex}",
            |args| {
                let key_s = arg_str_opt(args, "key").ok_or("missing arg 'key' (str)")?;
                let key = Key::parse(key_s)?;
                let backend = parse_backend(args)?;
                match backend {
                    Backend::L1 => l1::key_down(key)?,
                    Backend::L2 => l2::key_down(resolve_l2_hwnd(args)?, key)?,
                }
                Ok(json!({"ok": true, "backend": backend, "key": key_s, "vk": key.0}))
            },
        ),
        OpDef::new(
            "input.key.up",
            "Release a key.",
            "{key: str, backend?: l1|l2, hwnd?: hex}",
            |args| {
                let key_s = arg_str_opt(args, "key").ok_or("missing arg 'key' (str)")?;
                let key = Key::parse(key_s)?;
                let backend = parse_backend(args)?;
                match backend {
                    Backend::L1 => l1::key_up(key)?,
                    Backend::L2 => l2::key_up(resolve_l2_hwnd(args)?, key)?,
                }
                Ok(json!({"ok": true, "backend": backend, "key": key_s, "vk": key.0}))
            },
        ),
        OpDef::new(
            "input.key.press",
            "Press + release a key. Optional `hold_ms` sleeps between down and up.",
            "{key: str, hold_ms?: u32, backend?: l1|l2, hwnd?: hex}",
            |args| {
                let key_s = arg_str_opt(args, "key").ok_or("missing arg 'key' (str)")?;
                let key = Key::parse(key_s)?;
                let hold_ms = arg_u32(args, "hold_ms", Some(0))?;
                let backend = parse_backend(args)?;
                match backend {
                    Backend::L1 => l1::key_press(key, hold_ms)?,
                    Backend::L2 => l2::key_press(resolve_l2_hwnd(args)?, key, hold_ms)?,
                }
                Ok(json!({
                    "ok": true, "backend": backend, "key": key_s, "vk": key.0, "hold_ms": hold_ms
                }))
            },
        ),
        OpDef::new(
            "input.cursor.get",
            "Return the current OS cursor position in screen pixels (GetCursorPos).",
            "",
            |_args| {
                let (x, y) = l1::cursor_pos()?;
                Ok(json!({"x": x, "y": y}))
            },
        ),
        OpDef::new(
            "input.foreground.hwnd",
            "Return the foreground window's HWND (hex). Useful for L2 callers.",
            "",
            |_args| match super::foreground_hwnd() {
                Some(h) => Ok(json!({"hwnd": format!("0x{:x}", h as usize)})),
                None => Err("GetForegroundWindow returned NULL".into()),
            },
        ),
        OpDef::new(
            "input.find_hwnd_by_pid",
            "Return the first visible top-level HWND owned by `pid`. Hex string.",
            "{pid: u32}",
            |args| {
                let pid = arg_u32(args, "pid", None)?;
                match super::find_hwnd_by_pid(pid) {
                    Some(h) => Ok(json!({"hwnd": format!("0x{:x}", h as usize), "pid": pid})),
                    None => Err(format!("no visible top-level window for pid {pid}")),
                }
            },
        ),
        OpDef::new(
            "input.self.hwnd",
            "Return the first visible top-level HWND owned by the current process. \
This is the in-process shortcut for tests / cmdlets running INSIDE the game.",
            "",
            |_args| {
                use windows_sys::Win32::System::Threading::GetCurrentProcessId;
                let pid = unsafe { GetCurrentProcessId() };
                match super::find_hwnd_by_pid(pid) {
                    Some(h) => Ok(json!({"hwnd": format!("0x{:x}", h as usize), "pid": pid})),
                    None => Err(format!("no visible top-level window for self pid {pid}")),
                }
            },
        ),
    ]
}
