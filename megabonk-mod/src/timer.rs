//! Pause the run timer on demand (F8).
//!
//! The clocks on screen are static on `Il2CppAssets.Scripts.Utility.MyTime`
//! (tests/research_timer.rs, 2026-10-03): `stageTimer` (the stage
//! countdown is 540 s minus it) and `runTimer` (the run clock); each
//! moved 2.2 s over 2 s of play. `GameManager.gameTimer` is a different
//! clock: holding it still left the on-screen countdown running.
//!
//! F8 flips the pause. While paused, every frame on the main thread (the
//! shim's Update) this writes the values both clocks had when F8 was
//! pressed back through MyTime's static setters, so they stand still.
//! The `timer_pause` op reads or sets the pause.

use std::sync::atomic::{AtomicBool, AtomicU32, Ordering};

use serde_json::{Value as Json, json};
use unityforge::input::{KeyCode, register_key_press};
use unityforge::mono::{LogLevel, invoke_static, log};

const MY_TIME: &str = "Il2CppAssets.Scripts.Utility.MyTime";

/// A clock held while paused: its MyTime property and the value it is
/// held at (f32 bits).
struct Clock {
    name: &'static str,
    frozen: AtomicU32,
}

static CLOCKS: [Clock; 2] = [
    Clock { name: "stageTimer", frozen: AtomicU32::new(0) },
    Clock { name: "runTimer", frozen: AtomicU32::new(0) },
];

static PAUSED: AtomicBool = AtomicBool::new(false);
/// Read the clocks into `frozen` on the next frame (set when pausing).
static CAPTURE: AtomicBool = AtomicBool::new(false);

fn set_paused(paused: bool) {
    if paused && !PAUSED.load(Ordering::Relaxed) {
        CAPTURE.store(true, Ordering::Relaxed);
    }
    PAUSED.store(paused, Ordering::Relaxed);
    log(LogLevel::Info, &format!("megabonk-mod: timer {}", if paused { "paused" } else { "running" }));
}

extern "C" fn on_toggle() {
    set_paused(!PAUSED.load(Ordering::Relaxed));
}

pub fn install() {
    if register_key_press(KeyCode::F8, on_toggle).is_none() {
        log(LogLevel::Error, "megabonk-mod: F8 timer pause binding FAILED");
    }
    modforge::ops::OP_REGISTRY.register_many([modforge::ops::OpDef::new(
        "timer_pause",
        "Read whether the run timer is paused, or set it with paused (F8 toggles it in game)",
        "{paused?: bool}",
        |args| {
            if let Some(p) = args.get("paused").and_then(Json::as_bool) {
                set_paused(p);
            }
            let held: serde_json::Map<String, Json> = CLOCKS
                .iter()
                .map(|c| (c.name.to_string(), json!(f32::from_bits(c.frozen.load(Ordering::Relaxed)))))
                .collect();
            Ok(json!({"paused": PAUSED.load(Ordering::Relaxed), "held_at": held}))
        },
    )]);
}

/// Called every frame from the shim's Update (main thread).
pub fn tick() {
    if !PAUSED.load(Ordering::Relaxed) {
        return;
    }
    let capture = CAPTURE.swap(false, Ordering::Relaxed);
    for c in &CLOCKS {
        if let Err(e) = hold(c, capture) {
            log(LogLevel::Warn, &format!("megabonk-mod: timer {}: {e}", c.name));
        }
    }
}

fn hold(c: &Clock, capture: bool) -> Result<(), String> {
    if capture {
        let now = invoke_static(MY_TIME, &format!("get_{}", c.name), &json!([]))?
            .as_f64()
            .ok_or("not a number")?;
        c.frozen.store((now as f32).to_bits(), Ordering::Relaxed);
        return Ok(());
    }
    invoke_static(MY_TIME, &format!("set_{}", c.name), &json!([f32::from_bits(c.frozen.load(Ordering::Relaxed))]))?;
    Ok(())
}
