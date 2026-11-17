//! Research: watch a real fight. The operator starts the fight; the
//! mod only listens to the signals the game emits.
//!
//! Run `research_watch_start` before the fight, then
//! `research_watch_read` after it. Read-only.

mod common;

use std::collections::BTreeMap;

use serde_json::json;

const SCENE: &str = "/root/@Control@65/CurrentScene";

#[test]
#[ignore = "run by hand before a fight"]
fn research_watch_start() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let mut targets = vec![
        json!({"node": "/root/EventBus"}),
        json!({"node": "/root/CombatLog"}),
    ];
    if let Some(r) = common::node_with_script(&api, SCENE, "combat_resolver.gd", 3) {
        targets.push(json!({"id": r["id"]}));
    }
    for t in targets {
        let w = common::op(&api, "watch_signals", t);
        println!(
            "{}: {} signals, failed {}",
            w["source"],
            w["connected"].as_array().map_or(0, Vec::len),
            w["failed"]
        );
    }
}

#[test]
#[ignore = "run by hand after a fight"]
fn research_watch_read() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let got = common::op(&api, "watch_events", json!({"since": 0, "max": 20000}));
    let events = got["events"].as_array().expect("events");
    let mut counts: BTreeMap<String, usize> = BTreeMap::new();
    for e in events {
        *counts
            .entry(format!("{} {}", e["source"], e["signal"]))
            .or_default() += 1;
    }
    println!("{} events", events.len());
    for (k, n) in &counts {
        println!("  {n:5} {k}");
    }
    // Animation and sound: thousands a fight, nothing about the hits.
    let noise = ["equip_sweep_moved", "play_sfx"];
    println!("first 300 without {noise:?}:");
    for e in events
        .iter()
        .filter(|e| !noise.iter().any(|n| e["signal"] == json!(n)))
        .take(300)
    {
        let args = e["args"].to_string();
        let args = &args[..args.floor_char_boundary(300)];
        println!("  {} {} {} {}", e["ms"], e["signal"], e["source"], args);
    }
}
