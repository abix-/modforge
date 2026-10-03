//! first_copy_wins stays on through a normal load (operator 2026-10-02:
//! patch once at mod start instead of on every save load, which froze the
//! game 0.62 s). A normal load (a save load; a door into an area not kept
//! loaded goes through the same SaveController.LoadGameWithMigration)
//! must not have any of its managers skipped as a "second copy", and every
//! watched one-copy field must point at a live object afterwards, with no
//! new errors.
//!
//! Loads a save (`reload_save`): one loading screen. The skipped list is
//! read right as the load finishes, before kept_loaded starts loading
//! areas alongside (those skips are expected).
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_always_on -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{WATCHED, api, instance_now, op, ping_or_skip};
use serde_json::json;

#[test]
fn normal_load_with_first_copy_wins_on() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let state = op(&api, "first_copy_wins", json!({}));
    println!("first_copy_wins patches: {}", state["patches"]);
    assert!(state["patches"].as_i64().unwrap_or(0) > 0, "first_copy_wins is not on");
    let skipped_before = state["skipped"].as_object().map_or(0, |m| m.values().filter_map(|v| v.as_u64()).sum::<u64>());

    // A save load replaces the area, so the game's one GameController is a
    // new object afterwards. (Polling SaveController.Loading from here did
    // not see the load: two runs, the game's log shows both loads.)
    let old = instance_now(&api, "GameController");
    op(&api, "errors", json!({"mark": true}));
    op(&api, "reload_save", json!({}));
    let start = Instant::now();
    loop {
        let now = instance_now(&api, "GameController");
        if now != old && now.parse::<i64>().is_ok() {
            break;
        }
        assert!(start.elapsed() < Duration::from_secs(120), "no new GameController in 120s (still {now})");
        std::thread::sleep(Duration::from_millis(100));
    }
    // Read at once: the area's managers start in the same frame as its
    // GameController, and kept_loaded's loads alongside start later (their
    // skips are expected and would muddle this list).
    let after = op(&api, "first_copy_wins", json!({}));
    let skipped_after = after["skipped"].as_object().map_or(0, |m| m.values().filter_map(|v| v.as_u64()).sum::<u64>());
    println!("loaded in {:.1}s; skipped during the load: {}", start.elapsed().as_secs_f64(), skipped_after - skipped_before);
    // Which: the count each "Class.Method" gained during the load.
    let count = |s: &serde_json::Value, k: &str| s["skipped"][k].as_u64().unwrap_or(0);
    let mut gained: Vec<String> = after["skipped"]
        .as_object()
        .into_iter()
        .flatten()
        .filter_map(|(k, _)| {
            let d = count(&after, k) - count(&state, k);
            (d > 0).then(|| format!("{k} +{d}"))
        })
        .collect();
    gained.sort();
    println!("skipped during the load: {gained:?}");

    let mut bad = Vec::new();
    for class in WATCHED {
        let now = instance_now(&api, class);
        if now.parse::<i64>().is_err() {
            bad.push(format!("{class}: {now}"));
        }
    }
    println!("one-copy fields not on a live object: {bad:?}");
    std::thread::sleep(Duration::from_secs(3));
    let errors = op(&api, "errors", json!({}));
    println!("errors since the load: {}", errors["total"]);
    for g in errors["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }
    // An old area's OnDestroy skipped is right: the new copy is already the
    // one copy, and the old one's OnDestroy would empty the field. A
    // skipped Awake in a normal load is a manager wrongly kept from starting.
    let awake: Vec<_> = gained.iter().filter(|g| g.contains(".Awake")).collect();
    assert!(awake.is_empty(), "a normal load had managers kept from starting: {awake:?}");
    assert!(bad.is_empty(), "one-copy fields not on a live object: {bad:?}");
}
