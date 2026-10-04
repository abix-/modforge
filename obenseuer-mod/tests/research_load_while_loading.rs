//! A save loaded while the mod is still loading areas alongside (the player
//! loads from the menu right after a load or a door): does the game's load
//! finish, and what does it log? A kept areas check once hung 120 s on its
//! first load right after the previous run's load, with a
//! LoadingScreen.LoadAsynchronously NullReferenceException.
//!
//! Loads the save last loaded, waits until areas are loading alongside,
//! loads it again, and reports. Three times.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_load_while_loading -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{api, instance_now, op, ping_or_skip};
use serde_json::json;

#[test]
fn load_while_loading() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    op(&api, "load_alongside", json!({"auto": true}));
    for round in 1..=3 {
        op(&api, "errors", json!({"mark": true}));
        let controller = instance_now(&api, "GameController");
        op(&api, "reload_save", json!({}));
        // Until the new area is in and the mod is loading areas alongside.
        let start = Instant::now();
        let mut loading = Vec::new();
        while start.elapsed() < Duration::from_secs(60) {
            let now = instance_now(&api, "GameController");
            let k = op(&api, "load_alongside", json!({}));
            loading = k["loading"].as_array().cloned().unwrap_or_default();
            if now != controller && now.parse::<i64>().is_ok() && !loading.is_empty() {
                break;
            }
            std::thread::sleep(Duration::from_millis(100));
        }
        println!("round {round}: loading alongside {loading:?} after {:.1}s; loading the save again", start.elapsed().as_secs_f64());
        let controller = instance_now(&api, "GameController");
        op(&api, "reload_save", json!({}));
        let start = Instant::now();
        let mut done = false;
        while start.elapsed() < Duration::from_secs(60) {
            let now = instance_now(&api, "GameController");
            if now != controller && now.parse::<i64>().is_ok() {
                done = true;
                break;
            }
            std::thread::sleep(Duration::from_millis(200));
        }
        println!("  second load finished: {done} ({:.1}s)", start.elapsed().as_secs_f64());
        let errors = op(&api, "errors", json!({}));
        for g in errors["groups"].as_array().into_iter().flatten() {
            println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
        }
        if !done {
            println!("  stuck: stopping here, the game needs F7 or a restart");
            break;
        }
        std::thread::sleep(Duration::from_secs(5));
    }
}
