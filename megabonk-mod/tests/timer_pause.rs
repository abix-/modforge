//! The run timer stands still while paused and runs again after.
//!
//! Pauses through the `timer_pause` op (src/timer.rs; F8 does the same
//! in game), reads `MyTime.stageTimer` (the clock behind the on-screen
//! stage countdown) twice 2 s apart and asserts it did not move, then
//! unpauses and asserts it moves again. Needs a run.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test timer_pause -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn pause_holds_the_timer() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // MyTime.stageTimer drives the on-screen countdown (research_timer.rs).
    let timer = || {
        api.op(
            "invoke_static",
            json!({"class": "Il2CppAssets.Scripts.Utility.MyTime", "method": "get_stageTimer", "args": []}),
        )
        .result
        .as_f64()
        .unwrap_or(f64::NAN)
    };
    let wait = || std::thread::sleep(std::time::Duration::from_secs(2));

    println!("pause: {}", api.op("timer_pause", json!({"paused": true})).result);
    std::thread::sleep(std::time::Duration::from_millis(300));
    let a = timer();
    wait();
    let b = timer();
    println!("paused:  {a} -> {b}");

    println!("resume: {}", api.op("timer_pause", json!({"paused": false})).result);
    let c = timer();
    wait();
    let d = timer();
    println!("running: {c} -> {d}");

    assert!((b - a).abs() < 0.05, "timer moved while paused: {a} -> {b}");
    assert!(d - c > 1.0, "timer did not run after resume: {c} -> {d}");
}
