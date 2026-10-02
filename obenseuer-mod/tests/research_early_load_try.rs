//! Try loading the next area early (operator 2026-10-02): start the
//! nearest door's area loading in the background, held just before it
//! would replace the current area, and hand it to the door the way the
//! game's own LoadSceneAsyncTrigger does.
//!
//! The load is SceneManager.LoadSceneAsync(area, Single) with
//! allowSceneActivation false, so Unity holds it at 0.9 progress. It goes
//! into LoadSceneAsyncTrigger.currentAsyncScenes and currentAsyncOperations;
//! LoadingScreen.LoadAsynchronously (LoadingScreen.cs:207) finds it there
//! and lets it finish instead of starting a new load. After the trip the
//! test takes it out of both lists again: LoadingScreen never does, and a
//! finished load left there would be reused on the next visit.
//!
//! The player must use the door the test names. Unity cannot cancel a
//! scene load, and a held one keeps every later scene load waiting.
//!
//! Compare the game's own line in Player.log after the trip:
//! "Load scene async done (Xs)".
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_early_load_try -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

fn call_static(api: &Api<Value>, class: &str, method: &str, args: Value) -> Value {
    let r = api.op("invoke_static", json!({"class": class, "method": method, "args": args}));
    if !r.ok {
        println!("{class}.{method}: {:?}", r.error);
    }
    r.result
}

fn position(api: &Api<Value>, h: i64) -> Option<[f64; 3]> {
    let t = handle_of(&call(api, h, "get_transform", json!([])))?;
    let p = call(api, t, "get_position", json!([]));
    Some([p["x"].as_f64()?, p["y"].as_f64()?, p["z"].as_f64()?])
}

/// One of LoadSceneAsyncTrigger's static lists.
fn trigger_list(api: &Api<Value>, field: &str) -> i64 {
    let ty = call_static(api, "System.Type", "GetType", json!(["LoadSceneAsyncTrigger, Assembly-CSharp"]));
    let ty = handle_of(&ty).expect("LoadSceneAsyncTrigger type");
    let f = handle_of(&call(api, ty, "GetField", json!([field]))).expect("static list field");
    handle_of(&call(api, f, "GetValue", json!([null]))).expect("static list value")
}

fn loading(api: &Api<Value>) -> bool {
    call_static(api, "SaveController", "get_Loading", json!([])).as_bool().unwrap_or(false)
}

/// The nearest door to another area: (door name, area, metres).
fn nearest_door(api: &Api<Value>) -> Option<(String, String, f64)> {
    let camera = handle_of(&call_static(api, "UnityEngine.Camera", "get_main", json!([])))?;
    let me = position(api, camera)?;
    let r = api.op("walk_class", json!({"class": "Changelevel", "include_inactive": false}));
    let mut best: Option<(String, String, f64)> = None;
    for i in r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default() {
        let Some(h) = handle_of(&i) else { continue };
        let area = read(api, h, "OtherLevel").as_str().unwrap_or("").to_string();
        if area.is_empty() {
            continue;
        }
        let Some(p) = position(api, h) else { continue };
        let d = (0..3).map(|k| (p[k] - me[k]).powi(2)).sum::<f64>().sqrt();
        if best.as_ref().is_none_or(|b| d < b.2) {
            best = Some((i["name"].as_str().unwrap_or("?").to_string(), area, d));
        }
    }
    best
}

#[test]
fn nearest_door_loaded_early() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (door, area, metres) = nearest_door(&api).expect("a door to another area in reach of the camera");
    println!("nearest door {door} to {area}, {metres:.1} m away");

    let start = Instant::now();
    let op = call_static(&api, "UnityEngine.SceneManagement.SceneManager", "LoadSceneAsync", json!([area, "Single"]));
    let op = handle_of(&op).expect("LoadSceneAsync gave an AsyncOperation");
    call(&api, op, "set_allowSceneActivation", json!([false]));
    let scenes = trigger_list(&api, "currentAsyncScenes");
    let ops = trigger_list(&api, "currentAsyncOperations");
    call(&api, scenes, "Add", json!([area]));
    call(&api, ops, "Add", json!([{"handle": op}]));

    loop {
        let progress = call(&api, op, "get_progress", json!([])).as_f64().unwrap_or(0.0);
        if progress >= 0.9 {
            println!("{area} loaded early and held in {:.2}s", start.elapsed().as_secs_f64());
            break;
        }
        assert!(start.elapsed() < Duration::from_secs(120), "early load stuck at {progress}");
        std::thread::sleep(Duration::from_millis(100));
    }

    println!("now go through {door} (to {area}), and only that door");
    let wait = Instant::now();
    while !loading(&api) {
        assert!(wait.elapsed() < Duration::from_secs(600), "no door used in 600s; the held load is still waiting");
        std::thread::sleep(Duration::from_millis(100));
    }
    let trip = Instant::now();
    while loading(&api) {
        assert!(trip.elapsed() < Duration::from_secs(120), "door trip did not finish in 120s");
        std::thread::sleep(Duration::from_millis(100));
    }
    println!("door trip done in {:.2}s (from SaveController.Loading true to false)", trip.elapsed().as_secs_f64());

    call(&api, scenes, "Remove", json!([area]));
    call(&api, ops, "Remove", json!([{"handle": op}]));
    let now = call_static(&api, "UnityEngine.Application", "get_loadedLevelName", json!([]));
    println!("now in {now}; compare Player.log 'Load scene async done'");
    for h in [op, scenes, ops] {
        api.op("release_handle", json!({"handle": h}));
    }
}
