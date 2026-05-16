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
            "input.mouse.drag",
            "Drag `button` from (x1,y1) to (x2,y2). Generates `steps` intermediate \
moves over `duration_ms`. L1 = screen px; L2 = client-area px of hwnd.",
            "{button: left|right|middle, x1: i32, y1: i32, x2: i32, y2: i32, \
duration_ms?: u32, steps?: u32, backend?: l1|l2, hwnd?: hex, mods?: [shift|ctrl]}",
            |args| {
                let btn_s = arg_str_opt(args, "button").unwrap_or("left");
                let button = Button::parse(btn_s)?;
                let x1 = arg_i32(args, "x1")?;
                let y1 = arg_i32(args, "y1")?;
                let x2 = arg_i32(args, "x2")?;
                let y2 = arg_i32(args, "y2")?;
                let duration_ms = arg_u32(args, "duration_ms", Some(150))?;
                let steps = arg_u32(args, "steps", Some(16))?;
                let backend = parse_backend(args)?;
                let (shift, ctrl) = parse_mods(args);
                match backend {
                    Backend::L1 => {
                        if shift { l1::key_down(Key(0xA0))?; }
                        if ctrl  { l1::key_down(Key(0xA2))?; }
                        let r = l1::drag(button, x1, y1, x2, y2, duration_ms, steps);
                        if ctrl  { let _ = l1::key_up(Key(0xA2)); }
                        if shift { let _ = l1::key_up(Key(0xA0)); }
                        r?
                    }
                    Backend::L2 => {
                        let h = resolve_l2_hwnd(args)?;
                        let mk_extra = l2::modifier_mask(shift, ctrl);
                        l2::drag(h, button, x1, y1, x2, y2, duration_ms, steps, mk_extra)?;
                    }
                }
                Ok(json!({
                    "ok": true, "backend": backend, "button": btn_s,
                    "from": [x1, y1], "to": [x2, y2],
                    "duration_ms": duration_ms, "steps": steps,
                }))
            },
        ),
        OpDef::new(
            "input.mouse.scroll",
            "Scroll the wheel by `dy` ticks (positive = up). `dx` for horizontal. \
L2 requires `hwnd` + `x` + `y` (screen px); L1 scrolls at current cursor.",
            "{dy?: i32, dx?: i32, x?: i32, y?: i32, backend?: l1|l2, hwnd?: hex}",
            |args| {
                let dy = args
                    .get("dy")
                    .and_then(Json::as_i64)
                    .map(|v| v as i32)
                    .unwrap_or(0);
                let dx = args
                    .get("dx")
                    .and_then(Json::as_i64)
                    .map(|v| v as i32)
                    .unwrap_or(0);
                if dx == 0 && dy == 0 {
                    return Err("scroll: at least one of dx, dy must be nonzero".into());
                }
                let backend = parse_backend(args)?;
                match backend {
                    Backend::L1 => l1::scroll(dx, dy)?,
                    Backend::L2 => {
                        let h = resolve_l2_hwnd(args)?;
                        let x = args.get("x").and_then(Json::as_i64).unwrap_or(0) as i32;
                        let y = args.get("y").and_then(Json::as_i64).unwrap_or(0) as i32;
                        l2::scroll(h, x, y, dx, dy)?;
                    }
                }
                Ok(json!({"ok": true, "backend": backend, "dx": dx, "dy": dy}))
            },
        ),
        OpDef::new(
            "input.combo",
            "Hold `keys` (modifiers or any key list) while invoking `then`. \
`then` is another input op envelope: `{op: 'input.mouse.click', args: {...}}` \
or `{op: 'input.key.press', args: {...}}`. Backend on the inner op picks L1/L2; \
combo runs the modifier presses through the SAME backend.",
            "{keys: [str], then: {op: str, args: {...}}}",
            |args| {
                let keys_arr = args
                    .get("keys")
                    .and_then(Json::as_array)
                    .ok_or("missing arg 'keys' (array of str)")?;
                let mut keys: Vec<Key> = Vec::with_capacity(keys_arr.len());
                for (i, k) in keys_arr.iter().enumerate() {
                    let s = k.as_str().ok_or_else(|| format!("keys[{i}] not str"))?;
                    keys.push(Key::parse(s)?);
                }
                let then = args.get("then").ok_or("missing arg 'then'")?;
                let inner_op = then.get("op").and_then(Json::as_str)
                    .ok_or("then.op missing")?;
                let inner_args = then.get("args").cloned().unwrap_or(json!({}));
                let backend = parse_backend(&inner_args)?;

                // Press modifiers through the chosen backend.
                let hwnd_for_l2 = if backend == Backend::L2 {
                    Some(resolve_l2_hwnd(&inner_args)?)
                } else { None };
                for k in &keys {
                    match backend {
                        Backend::L1 => l1::key_down(*k)?,
                        Backend::L2 => l2::key_down(hwnd_for_l2.unwrap(), *k)?,
                    }
                }
                // Dispatch the inner op via the registry. Sibling-call
                // protection: if dispatch panics or errors, we still
                // release the modifiers below.
                let dispatched = crate::ops::OP_REGISTRY.dispatch(inner_op, &inner_args);
                // Release modifiers in REVERSE order (LIFO).
                for k in keys.iter().rev() {
                    let _ = match backend {
                        Backend::L1 => l1::key_up(*k),
                        Backend::L2 => l2::key_up(hwnd_for_l2.unwrap(), *k),
                    };
                }
                match dispatched {
                    Some(Ok(inner_result)) => Ok(json!({
                        "ok": true, "combo_keys": keys_arr, "inner": inner_result,
                    })),
                    Some(Err(e)) => Err(format!("inner op '{inner_op}' failed: {e}")),
                    None => Err(format!("inner op '{inner_op}' not registered")),
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
