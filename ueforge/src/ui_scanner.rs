//! Built-in Cheat-Engine-style scanner ImGui tab. Every game
//! using ueforge gets this for free — just include
//! `ueforge::ui_scanner::tab` in your `ModInfo::tabs` list:
//!
//! ```ignore
//! tabs: &[
//!     Tab { name: "Tweaks", render: render_tweaks_tab },
//!     Tab { name: "Scanner", render: ueforge::ui_scanner::render },
//! ],
//! ```
//!
//! UI flow:
//! 1. Pick a value type (i32 default — most game state).
//! 2. Type a value (signed; works for u/i types up to i32 range).
//! 3. Click Scan → opens a session, shows match count + first
//!    addresses.
//! 4. Manipulate the value in-game (drop an item, take damage,
//!    spend currency...).
//! 5. Type the new value → click "Rescan: exact" (or "changed",
//!    "decreased", "increased") to narrow.
//! 6. Repeat until a handful of addresses remain.
//! 7. Click Freeze on a row to lock that address at the current
//!    value (or set explicitly).
//!
//! State persists across renders in `static SCANNER_UI`.

use std::sync::Mutex;

use serde_json::json;

use crate::scanner;
use crate::ui;

#[derive(Clone, Copy, PartialEq, Eq)]
enum TyKind {
    I32,
    U32,
    F32,
    I64,
    U64,
    I16,
    U16,
    I8,
    U8,
    F64,
}

impl TyKind {
    fn label(self) -> &'static str {
        match self {
            TyKind::I32 => "i32",
            TyKind::U32 => "u32",
            TyKind::F32 => "f32",
            TyKind::I64 => "i64",
            TyKind::U64 => "u64",
            TyKind::I16 => "i16",
            TyKind::U16 => "u16",
            TyKind::I8 => "i8",
            TyKind::U8 => "u8",
            TyKind::F64 => "f64",
        }
    }
    fn op_str(self) -> &'static str {
        self.label()
    }
    fn is_float(self) -> bool {
        matches!(self, TyKind::F32 | TyKind::F64)
    }
}

struct ScannerUi {
    ty: TyKind,
    int_value: i64,
    float_value: f64,
    last_session: Option<u64>,
    last_match_count: usize,
    last_sample: Vec<String>,
    last_error: Option<String>,
    freeze_addr_text: String, // not used yet (input_text not in ui::*); reserved
}

impl ScannerUi {
    const fn new() -> Self {
        Self {
            ty: TyKind::I32,
            int_value: 0,
            float_value: 0.0,
            last_session: None,
            last_match_count: 0,
            last_sample: Vec::new(),
            last_error: None,
            freeze_addr_text: String::new(),
        }
    }
}

static SCANNER_UI: Mutex<ScannerUi> = Mutex::new(ScannerUi::new());

pub fn render() {
    let mut s = match SCANNER_UI.lock() {
        Ok(g) => g,
        Err(p) => p.into_inner(),
    };

    ui::text("Memory scanner");
    ui::text_disabled(
        "Cheat-Engine-style scan / rescan / freeze. Pick a type \
         and a value the game shows you, click Scan, then \
         change the value in-game and Rescan to narrow.",
    );
    ui::separator();
    ui::spacing();

    // Type selector — radio-button row.
    ui::text("Type:");
    let row1 = [TyKind::I32, TyKind::U32, TyKind::F32, TyKind::I64, TyKind::U64];
    let row2 = [TyKind::I16, TyKind::U16, TyKind::I8, TyKind::U8, TyKind::F64];
    for (i, t) in row1.iter().enumerate() {
        if i > 0 {
            ui::same_line();
        }
        let label = if s.ty == *t {
            format!("[{}]", t.label())
        } else {
            t.label().to_string()
        };
        if ui::small_button(&label) {
            s.ty = *t;
        }
    }
    for (i, t) in row2.iter().enumerate() {
        if i > 0 {
            ui::same_line();
        } else {
            ui::spacing();
        }
        let label = if s.ty == *t {
            format!("[{}]", t.label())
        } else {
            t.label().to_string()
        };
        if ui::small_button(&label) {
            s.ty = *t;
        }
    }
    ui::spacing();

    // Value entry. We ship int input for int types, float for
    // float types. (input_text would let us type any base; punt
    // until the ui crate exposes it.)
    if s.ty.is_float() {
        let mut v = s.float_value as f32;
        ui::set_next_item_width(180.0);
        if ui::slider_f32("Value", &mut v, -1_000_000.0, 1_000_000.0) {
            s.float_value = v as f64;
        }
        ui::text_disabled(&format!("Slider value: {v}"));
    } else {
        // Slider works for typing INT values; lower / upper
        // bound is generous for game state (HP, gold, counts).
        let mut v = s.int_value as i32;
        ui::set_next_item_width(180.0);
        if ui::input_i32("Value", &mut v) {
            s.int_value = v as i64;
        }
    }
    ui::spacing();

    // Scan / rescan buttons.
    if ui::button("Scan (new session)") {
        do_scan(&mut s);
    }
    if let Some(sid) = s.last_session {
        ui::same_line();
        if ui::button("Rescan: exact") {
            do_rescan(&mut s, sid, "exact");
        }
        ui::same_line();
        if ui::button("Rescan: changed") {
            do_rescan(&mut s, sid, "changed");
        }
        ui::same_line();
        if ui::button("Rescan: unchanged") {
            do_rescan(&mut s, sid, "unchanged");
        }
        ui::same_line();
        if ui::button("Rescan: decreased") {
            do_rescan(&mut s, sid, "decreased");
        }
        ui::same_line();
        if ui::button("Rescan: increased") {
            do_rescan(&mut s, sid, "increased");
        }
        ui::spacing();
        if ui::button("Close session") {
            do_close(&mut s, sid);
        }
    }

    ui::spacing();
    ui::separator();
    ui::text_disabled("Status");

    if let Some(err) = &s.last_error {
        ui::text_colored(
            &format!("error: {err}"),
            (1.0, 0.5, 0.5, 1.0),
        );
    } else if let Some(sid) = s.last_session {
        ui::text(&format!(
            "Session {sid} ({}): {} matches",
            s.ty.label(),
            s.last_match_count
        ));
        for addr in s.last_sample.iter().take(20) {
            ui::text(&format!("  {addr}"));
        }
        if s.last_match_count > 20 {
            ui::text_disabled(&format!(
                "  ... + {} more (use op:scan_session to paginate)",
                s.last_match_count - 20
            ));
        }
    } else {
        ui::text_disabled("No active session.");
    }

    ui::spacing();
    ui::separator();
    ui::text_disabled("Active freezes");
    let list = scanner::freeze_list(&json!({})).unwrap_or(json!({"freezes": []}));
    if let Some(arr) = list.get("freezes").and_then(|v| v.as_array()) {
        if arr.is_empty() {
            ui::text_disabled("(none)");
        } else {
            for f in arr {
                let addr = f.get("addr").and_then(|v| v.as_str()).unwrap_or("?");
                let ty = f.get("type").and_then(|v| v.as_str()).unwrap_or("?");
                let bytes_hex = f.get("bytes_hex").and_then(|v| v.as_str()).unwrap_or("");
                let hz = f.get("hz").and_then(|v| v.as_u64()).unwrap_or(0);
                ui::text(&format!("{addr}  {ty}  {bytes_hex}  {hz}Hz"));
                ui::same_line();
                if ui::small_button(&format!("Unfreeze##{addr}")) {
                    let _ = scanner::unfreeze(&json!({"addr": addr}));
                }
            }
        }
    }
}

fn do_scan(s: &mut ScannerUi) {
    let value = if s.ty.is_float() {
        json!(s.float_value)
    } else {
        json!(s.int_value)
    };
    let args = json!({
        "type": s.ty.op_str(),
        "value": value,
    });
    match scanner::scan_memory(&args) {
        Ok(r) => {
            s.last_session = r.get("session_id").and_then(|v| v.as_u64());
            s.last_match_count = r
                .get("matches")
                .and_then(|v| v.as_u64())
                .unwrap_or(0) as usize;
            s.last_sample = r
                .get("sample")
                .and_then(|v| v.as_array())
                .map(|a| {
                    a.iter()
                        .filter_map(|x| x.as_str().map(String::from))
                        .collect()
                })
                .unwrap_or_default();
            s.last_error = None;
        }
        Err(e) => {
            s.last_error = Some(e);
        }
    }
}

fn do_rescan(s: &mut ScannerUi, sid: u64, mode: &str) {
    let value = if s.ty.is_float() {
        json!(s.float_value)
    } else {
        json!(s.int_value)
    };
    let args = json!({
        "session_id": sid,
        "mode": mode,
        "value": value,
    });
    match scanner::scan_rescan(&args) {
        Ok(r) => {
            s.last_match_count = r
                .get("matches")
                .and_then(|v| v.as_u64())
                .unwrap_or(0) as usize;
            s.last_sample = r
                .get("sample")
                .and_then(|v| v.as_array())
                .map(|a| {
                    a.iter()
                        .filter_map(|x| x.as_str().map(String::from))
                        .collect()
                })
                .unwrap_or_default();
            s.last_error = None;
        }
        Err(e) => {
            s.last_error = Some(e);
        }
    }
}

fn do_close(s: &mut ScannerUi, sid: u64) {
    let _ = scanner::scan_close(&json!({"session_id": sid}));
    s.last_session = None;
    s.last_match_count = 0;
    s.last_sample.clear();
}
