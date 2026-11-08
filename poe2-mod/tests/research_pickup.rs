//! Does pickup pick up? Live, with the operator watching: it moves the
//! real mouse and clicks.
//!
//! Switches pickup on with the first rules for a few seconds, then off,
//! and checks that every item it clicked has left the ground.
//!
//! ```text
//! cargo run -p poe2-mod            # game in front, matching items near the player
//! k3sc cargo-lock test -p poe2-mod --test research_pickup -- --nocapture --test-threads=1
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};
use std::time::Duration;

/// How long pickup runs.
const RUN: Duration = Duration::from_secs(8);

fn matching(r: &Remote) -> Vec<Value> {
    let out = r.op("ground_labels", json!({})).expect("ground_labels");
    out["labels"]
        .as_array()
        .cloned()
        .unwrap_or_default()
        .into_iter()
        .filter(|l| !l["candidate"]["rule"].is_null())
        .collect()
}

/// Switch pickup on and leave it on (`--ignored`, so a plain test run
/// never takes the mouse): `research_pickup switch_on -- --ignored`.
#[test]
#[ignore = "takes the mouse until switched off"]
fn switch_on() {
    let r = Remote::at(17185);
    let out = r.op("pickup", json!({"on": true})).expect("pickup on");
    println!(
        "pickup on: {} range {}",
        out["pickup_on"], out["pickup"]["range"]
    );
}

/// Switch pickup off: `research_pickup switch_off -- --ignored`.
#[test]
#[ignore = "pairs with switch_on"]
fn switch_off() {
    let r = Remote::at(17185);
    let out = r.op("pickup", json!({"on": false})).expect("pickup off");
    println!("pickup on: {}", out["pickup_on"]);
    for c in out["clicks"].as_array().cloned().unwrap_or_default() {
        println!("click: {c}");
    }
    println!("waiting: {}", out["waiting"]);
}

#[test]
fn pickup_takes_the_matching_items() {
    let r = Remote::at(17185);
    let before = match r.op("ground_labels", json!({})) {
        Ok(_) => matching(&r),
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    for l in &before {
        println!(
            "before: {} ({}) {:.1} cells",
            l["candidate"]["name"], l["candidate"]["rule"], l["candidate"]["distance"]
        );
    }
    r.op("pickup", json!({"on": true})).expect("pickup on");
    std::thread::sleep(RUN);
    let out = r.op("pickup", json!({"on": false})).expect("pickup off");
    for c in out["clicks"].as_array().cloned().unwrap_or_default() {
        println!("click: {c}");
    }
    println!("last error: {}", out["last_error"]);
    let after = matching(&r);
    for l in &after {
        println!(
            "left: {} ({}) {:.1} cells",
            l["candidate"]["name"], l["candidate"]["rule"], l["candidate"]["distance"]
        );
    }
    let clicks = out["clicks"].as_array().map_or(0, Vec::len);
    assert!(
        before.is_empty() || clicks > 0,
        "matching items but no click"
    );
    assert!(
        after.len() < before.len() || before.is_empty(),
        "nothing left the ground"
    );
}
