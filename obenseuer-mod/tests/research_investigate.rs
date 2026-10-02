//! The investigation ops work (operator 2026-10-02: stop relaunching the
//! game after every try): `errors` counts what the game logged since a
//! mark, and `reload_save` gets back one clean area by loading the save
//! last loaded (src/investigate.rs).
//!
//! Loads a save: the game goes through a loading screen.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_investigate -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{api, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn op(api: &Api<Value>, name: &str, args: Value) -> Value {
    let r = api.op(name, args);
    assert!(r.ok, "{name} failed: {:?}", r.error);
    r.result
}

fn static_get(api: &Api<Value>, class: &str, method: &str) -> Value {
    api.op("invoke_static", json!({"class": class, "method": method, "args": []})).result
}

#[test]
fn reload_save_gets_back_one_clean_area() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    println!("before: scenes loaded {}", static_get(&api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCount"));
    op(&api, "errors", json!({"mark": true}));
    std::thread::sleep(Duration::from_secs(3));
    let broken = op(&api, "errors", json!({}));
    println!("errors in 3 s before the reload: {}", broken["total"]);

    println!("reload_save: {}", op(&api, "reload_save", json!({})));
    let start = Instant::now();
    std::thread::sleep(Duration::from_secs(2));
    while static_get(&api, "SaveController", "get_Loading").as_bool() != Some(false) {
        assert!(start.elapsed() < Duration::from_secs(120), "save did not finish loading in 120s");
        std::thread::sleep(Duration::from_millis(500));
    }
    println!("loaded in {:.1}s", start.elapsed().as_secs_f64());
    std::thread::sleep(Duration::from_secs(3));

    let scenes = static_get(&api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCount");
    let area = static_get(&api, "UnityEngine.Application", "get_loadedLevelName");
    println!("after: {area}, scenes loaded {scenes}");

    op(&api, "errors", json!({"mark": true}));
    std::thread::sleep(Duration::from_secs(3));
    let clean = op(&api, "errors", json!({}));
    println!("errors in 3 s after the reload: {}", clean["total"]);
    for g in clean["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }

    assert_eq!(scenes.as_i64(), Some(1), "one area after the reload");
    assert_eq!(clean["total"].as_i64(), Some(0), "no errors after the reload");
}
