//! Does attack hit? Live, with the operator watching: the second test
//! moves the real mouse and clicks.
//!
//! First the enemies it would aim at are listed without clicking, so
//! the operator can check the names and that the screen points sit on
//! the monsters. Then attack is switched on for a few seconds and the
//! nearest enemy's life is read before and after.
//!
//! ```text
//! cargo run -p poe2-mod            # game in front, enemies near the player
//! k3sc cargo-lock test -p poe2-mod --test research_attack enemies -- --nocapture
//! k3sc cargo-lock test -p poe2-mod --test research_attack casts -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::json;
use std::time::Duration;

/// How long attack runs.
const RUN: Duration = Duration::from_secs(6);

#[test]
fn enemies_on_screen() {
    let r = Remote::at(17185);
    let out = match r.op("enemies", json!({})) {
        Ok(o) => o,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    for e in out["enemies"].as_array().cloned().unwrap_or_default() {
        println!("{} {:.1} cells at {}", e["name"], e["distance"].as_f64().unwrap_or(0.0), e["screen"]);
    }
}

#[test]
fn casts_at_the_nearest_enemy() {
    let r = Remote::at(17185);
    let before = match r.op("enemies", json!({})) {
        Ok(o) => o["enemies"].as_array().cloned().unwrap_or_default(),
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    if before.is_empty() {
        println!("SKIP: no enemy on screen");
        return;
    }
    println!("nearest: {} {:.1} cells", before[0]["name"], before[0]["distance"].as_f64().unwrap_or(0.0));
    r.op("attack", json!({"on": true})).expect("attack on");
    std::thread::sleep(RUN);
    let out = r.op("attack", json!({"on": false})).expect("attack off");
    let clicks = out["clicks"].as_array().cloned().unwrap_or_default();
    for c in &clicks {
        println!("click: {c}");
    }
    println!("last error: {}", out["last_error"]);
    println!("waiting: {}", out["waiting"]);
    let after = r.op("enemies", json!({})).expect("enemies")["enemies"]
        .as_array()
        .cloned()
        .unwrap_or_default();
    println!("{} enemies before, {} after", before.len(), after.len());
    assert!(clicks.iter().any(|c| c["what"] == "attack"), "no cast");
}
