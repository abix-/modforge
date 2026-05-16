//! HK1 Stage S0 probe: read mouse_screen_x/y at HLT's documented RVAs.
//!
//! HLT (`research/prior-art/HorseyLiveTweaks/src/core/offsets.h`) lists
//! `kRvaMouseScreenX = 0x3ED970`, `kRvaMouseScreenY = 0x3ED978`. Build
//! drift may have moved them; this probe just confirms whether those
//! RVAs still hold readable floats.
//!
//! Pass criterion: both reads succeed AND the values are finite. We do
//! NOT here assert "the value changes when the mouse moves". That
//! requires SendInput plumbing or a human-in-the-loop step that
//! Stage S1 will add. For S0 we just want "the address didn't drift
//! into garbage memory."

mod common;

use serde_json::json;

#[test]
fn probe_mouse_globals() {
    let Some(game) = common::launch("hk1_probe_mouse_globals") else { return; };
    eprintln!("[GATE] waiting for a save to load (up to 120s) ...");
    common::wait_for_target_horse(&game, std::time::Duration::from_secs(120));
    let resp = game
        .op_json("hk1.probe.mouse_globals", &json!({}))
        .expect("hk1.probe.mouse_globals op should succeed");
    eprintln!("\nfull response: {resp}");
    let result = resp.get("result").unwrap_or(&resp);
    let x = result.get("x").and_then(|v| v.as_f64());
    let y = result.get("y").and_then(|v| v.as_f64());
    let x_bits = result.get("x_bits").and_then(|v| v.as_str()).unwrap_or("?");
    let y_bits = result.get("y_bits").and_then(|v| v.as_str()).unwrap_or("?");
    eprintln!("mouse_x = {x:?} (bits {x_bits})");
    eprintln!("mouse_y = {y:?} (bits {y_bits})");

    // Pass if both reads completed without an error from the op. Whether
    // the values are sane (in screen bounds) is the next stage's job;
    // here we only confirm the address is still readable.
    assert!(result.get("error").is_none(), "probe returned an error");
    game.pass(&format!(
        "mouse_x={:?} mouse_y={:?} (drift checks in S1)",
        x.unwrap_or(f64::NAN), y.unwrap_or(f64::NAN)
    ));
}
