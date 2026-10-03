//! Doors between areas kept loaded (operator 2026-10-02): load the area
//! a door of the current area leads to alongside (`load_alongside`,
//! src/kept_loaded.rs), then the player walks through that door and back.
//! Each trip must move the player with no save and load: the game's
//! SaveController.Loading never goes true, and the mod's trip list grows.
//!
//! Start with one area loaded (load a save). Waits up to 10 minutes for
//! the player's two trips.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_doors -- --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area (default "Open Sewer Tenement",
//! where the player's apartment building's front door leads). SKIPs (prints
//! why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{api, call_static, op, ping_or_skip, scenes_loaded};
use serde_json::json;

#[test]
fn doors_move_between_loaded_areas() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Open Sewer Tenement".into());
    assert_eq!(scenes_loaded(&api), 1, "start with one area loaded (load a save)");
    let first = call_static(&api, "UnityEngine.Application", "get_loadedLevelName", json!([]));

    let start = Instant::now();
    op(&api, "load_alongside", json!({"area": second}));
    let state = loop {
        let s = op(&api, "load_alongside", json!({}));
        if s["loading"].as_array().is_some_and(|a| a.is_empty()) {
            break s;
        }
        assert!(start.elapsed() < Duration::from_secs(180), "{second} did not load in 180s");
        std::thread::sleep(Duration::from_millis(200));
    };
    println!("{second} loaded alongside {first} in {:.2}s: {}", start.elapsed().as_secs_f64(), state);
    op(&api, "errors", json!({"mark": true}));

    println!("now walk through the door to {second}, then back through a door to {first}");
    let wait = Instant::now();
    let mut seen = 0;
    let mut loading_seen = false;
    while seen < 2 && wait.elapsed() < Duration::from_secs(600) {
        loading_seen |= call_static(&api, "SaveController", "get_Loading", json!([])).as_bool() == Some(true);
        let trips = op(&api, "load_alongside", json!({}))["trips"].as_array().cloned().unwrap_or_default();
        for t in trips.iter().skip(seen) {
            println!("trip: {t}");
        }
        seen = trips.len();
        std::thread::sleep(Duration::from_millis(200));
    }
    let errors = op(&api, "errors", json!({}));
    println!("errors since the load: {}", errors["total"]);
    for g in errors["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }
    assert!(!loading_seen, "a door did a save and load");
    assert_eq!(seen, 2, "two trips in 10 minutes");
}
