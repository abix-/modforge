//! Does roll go the right way? Live, with the operator watching:
//! switch_on presses real keys.
//!
//! close_enemies lists, without pressing anything, the enemies within
//! config.yaml's danger distance that would set a roll off.
//!
//! ```text
//! cargo run -p poe2-mod            # game in front
//! k3sc cargo-lock test -p poe2-mod --test research_roll close -- --nocapture
//! k3sc cargo-lock test -p poe2-mod --test research_roll switch_on -- --ignored --nocapture
//! k3sc cargo-lock test -p poe2-mod --test research_roll switch_off -- --ignored --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::json;

#[test]
fn close_enemies() {
    let r = Remote::at(17185);
    let state = match r.op("roll", json!({})) {
        Ok(s) => s,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let danger = state["roll"]["danger"].as_f64().unwrap_or(0.0);
    let out = r.op("enemies", json!({})).expect("enemies");
    let all = out["enemies"].as_array().cloned().unwrap_or_default();
    println!("danger {danger} cells; {} enemies on screen", all.len());
    for e in &all {
        let d = e["distance"].as_f64().unwrap_or(f64::MAX);
        println!(
            "{} {} {d:.1} cells",
            if d <= danger { "CLOSE" } else { "     " },
            e["name"]
        );
    }
}

/// Switch roll on and leave it on (`--ignored`, so a plain test run
/// never presses keys).
#[test]
#[ignore = "presses keys until switched off"]
fn switch_on() {
    let r = Remote::at(17185);
    let out = r.op("roll", json!({"on": true})).expect("roll on");
    println!(
        "roll on: {} danger {} key {}",
        out["roll_on"], out["roll"]["danger"], out["roll"]["key"]
    );
    println!("config error {}", out["config_error"]);
}

#[test]
#[ignore = "pairs with switch_on"]
fn switch_off() {
    let r = Remote::at(17185);
    let out = r.op("roll", json!({"on": false})).expect("roll off");
    println!("roll on: {}", out["roll_on"]);
    for c in out["clicks"].as_array().cloned().unwrap_or_default() {
        if c["what"] == "roll" {
            println!("roll: {c}");
        }
    }
    println!("waiting: {}", out["waiting"]);
}
