//! First copy wins, tried (operator 2026-10-02): turn on the mod's
//! `first_copy_wins` prefixes (src/first_copy_wins.rs), load a second area
//! alongside, and check that the game's one-copy `instance` fields still
//! point at the first area's live copies, and how many errors the game
//! logs. Then the player checks that the HUD, the view and movement work.
//!
//! Start with only one area loaded (load a save first). Both areas stay
//! loaded and the prefixes stay on when it ends; load a save again
//! afterwards.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_first_copy_wins -- --test-threads=1 --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area (default "Interior Tenement
//! Gatehouse"). SKIPs (prints why and passes) when the game is not running.
//! Results go to output/first-copy-wins.txt.

mod common;
use std::time::{Duration, Instant};

use common::{WATCHED, api, handle_of, instance_now, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn op(api: &Api<Value>, name: &str, args: Value) -> Result<Value, String> {
    let r = api.op(name, args);
    if r.ok { Ok(r.result) } else { Err(r.error.unwrap_or_else(|| "failed".into())) }
}

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Result<Value, String> {
    op(api, "invoke_method", json!({"handle": h, "method": method, "args": args}))
}

#[test]
fn second_area_loaded_with_first_copy_wins() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Interior Tenement Gatehouse".into());
    let scenes = op(&api, "invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "get_sceneCount", "args": []}));
    assert_eq!(scenes.as_ref().ok().and_then(|v| v.as_i64()), Some(1), "need exactly one area loaded (load a save): {scenes:?}");

    let mut out = Vec::new();
    let mut say = |line: String| {
        println!("{line}");
        out.push(line);
    };

    let on = op(&api, "first_copy_wins", json!({"on": true})).expect("first_copy_wins op (is the new mod build loaded?)");
    say(format!("first_copy_wins on: {on}"));
    let before: Vec<String> = WATCHED.iter().map(|c| instance_now(&api, c)).collect();
    op(&api, "errors", json!({"mark": true})).expect("errors op");

    let start = Instant::now();
    let load = op(&api, "invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "LoadSceneAsync", "args": [second, "Additive"]}));
    let load = load.ok().as_ref().and_then(handle_of).expect("LoadSceneAsync gave an AsyncOperation");
    while !call(&api, load, "get_isDone", json!([])).ok().and_then(|v| v.as_bool()).unwrap_or(false) {
        assert!(start.elapsed() < Duration::from_secs(180), "{second} did not load in 180s");
        std::thread::sleep(Duration::from_millis(100));
    }
    say(format!("loaded {second} alongside in {:.2}s", start.elapsed().as_secs_f64()));
    std::thread::sleep(Duration::from_secs(5));

    say("\none-copy fields: before -> after".into());
    let mut kept = 0;
    for (i, class) in WATCHED.iter().enumerate() {
        let after = instance_now(&api, class);
        let same = after == before[i];
        kept += same as usize;
        say(format!("  {class:<30} {} -> {after}{}", before[i], if same { "" } else { "  CHANGED" }));
    }
    say(format!("{kept} of {} unchanged", WATCHED.len()));

    let state = op(&api, "first_copy_wins", json!({})).unwrap_or_default();
    say(format!("\nskipped by first_copy_wins: {}", state["skipped"]));
    say(format!("switched off: {}", state["switched off"]));
    let errors = op(&api, "errors", json!({})).expect("errors op");
    say(format!("errors since the load: {}", errors["total"]));
    for g in errors["groups"].as_array().into_iter().flatten() {
        say(format!("  {}  {}  at {}", g["count"], g["error"], g["at"]));
    }

    let path = common::output_path("first-copy-wins.txt");
    std::fs::write(&path, out.join("\n") + "\n").expect("write the results");
    println!("\nwritten to {path}; check the HUD, the view and moving in the game");
}
