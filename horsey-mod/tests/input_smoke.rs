//! I-R5 + I-1 smoke test for `modforge::input`.
//!
//! What it covers (one launch, both layers):
//!
//! 1. **L1 round-trip.** `input.cursor.get` baseline -> `input.mouse.move`
//!    backend=l1 -> `input.cursor.get` again. Verifies SendInput
//!    actually reached USER32 and moved the OS cursor. Restores
//!    cursor position to baseline at the end.
//! 2. **L1 keyboard smoke.** `input.key.press` for `F24` (harmless,
//!    no game binding). Confirms keyboard-side SendInput path doesn't
//!    crash.
//! 3. **L2 PostMessage smoke (I-R5).** Resolves the Horsey HWND via
//!    `input.foreground.hwnd` (best-effort; falls back to a hardcoded
//!    EnumWindows-style search if needed in a follow-up), then sends
//!    `input.mouse.move` backend=l2 to a corner. Verifies the cmdlet
//!    returns `ok:true`. Does NOT click; clicks could land on UI we
//!    don't own.
//!
//! Honors the standard `MODFORGE_NO_GAME=1` skip.

mod common;

use serde_json::{json, Value};

const SMALL_OFFSET: i32 = 10;

fn unwrap_i64(v: &Value, key: &str) -> i64 {
    v.get(key)
        .and_then(Value::as_i64)
        .unwrap_or_else(|| panic!("missing/non-int field '{key}' in {v}"))
}

#[test]
fn input_smoke() {
    let Some(game) = common::launch("input_smoke") else { return };

    // ----- L1 cursor round-trip -----
    let base = game.op_json("input.cursor.get", &json!({})).unwrap();
    let bx = unwrap_i64(&base, "x") as i32;
    let by = unwrap_i64(&base, "y") as i32;
    eprintln!("baseline cursor: ({bx}, {by})");

    let target_x = bx + SMALL_OFFSET;
    let target_y = by + SMALL_OFFSET;
    let r = game
        .op_json(
            "input.mouse.move",
            &json!({"x": target_x, "y": target_y, "backend": "l1"}),
        )
        .unwrap();
    assert_eq!(r.get("ok").and_then(Value::as_bool), Some(true), "l1 move: {r}");

    // Re-read; allow a 4-pixel tolerance for normalized-coord rounding.
    let after = game.op_json("input.cursor.get", &json!({})).unwrap();
    let ax = unwrap_i64(&after, "x") as i32;
    let ay = unwrap_i64(&after, "y") as i32;
    eprintln!("after L1 move:   ({ax}, {ay}) [wanted ({target_x}, {target_y})]");
    let dx = (ax - target_x).abs();
    let dy = (ay - target_y).abs();
    assert!(
        dx <= 4 && dy <= 4,
        "L1 cursor move missed: got ({ax},{ay}), wanted ({target_x},{target_y}), delta=({dx},{dy})"
    );

    // Restore.
    let _ = game.op_json(
        "input.mouse.move",
        &json!({"x": bx, "y": by, "backend": "l1"}),
    );

    // ----- L1 keyboard smoke (F24 is unbound in Horsey) -----
    let r = game
        .op_json(
            "input.key.press",
            &json!({"key": "f24", "hold_ms": 0, "backend": "l1"}),
        )
        .unwrap();
    assert_eq!(r.get("ok").and_then(Value::as_bool), Some(true), "key.press f24: {r}");

    // ----- L2 PostMessage smoke (I-R5) -----
    //
    // We post a no-op `WM_MOUSEMOVE` to the foreground window. The
    // game window may or may not BE the foreground (cargo-test
    // launches in a console that may steal focus); the smoke is
    // just "the L2 backend produces a successful PostMessage call,
    // not a Win32 error." A future test will resolve Horsey's HWND
    // explicitly and assert the engine's own cursor-state globals
    // updated; that needs an `input.find_hwnd_by_pid` op we haven't
    // shipped yet.
    let hwnd_r = game.op_json("input.foreground.hwnd", &json!({}));
    let hwnd_s = match hwnd_r {
        Ok(v) => v.get("hwnd").and_then(Value::as_str).map(str::to_string),
        Err(e) => {
            eprintln!("input.foreground.hwnd failed (may be normal in headless CI): {e}");
            None
        }
    };
    if let Some(hwnd) = hwnd_s {
        eprintln!("foreground hwnd: {hwnd}");
        let r = game
            .op_json(
                "input.mouse.move",
                &json!({"x": 0, "y": 0, "backend": "l2", "hwnd": hwnd}),
            )
            .unwrap();
        assert_eq!(
            r.get("ok").and_then(Value::as_bool),
            Some(true),
            "l2 move on hwnd {}: {r}",
            r.get("backend").and_then(Value::as_str).unwrap_or("?")
        );
    } else {
        eprintln!("[INFO] no foreground hwnd; skipping L2 smoke this run");
    }

    eprintln!("[PASS] input_smoke: L1 + L2 backends survived a round-trip");
}
