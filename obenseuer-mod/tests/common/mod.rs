//! Shared helpers for the obenseuer-mod research tests: the unityforge
//! client on the mod's port. New research tests reuse them.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{find_instances, handle_of, parse_vec3, ping_or_skip};

use std::time::{Duration, Instant};

use serde_json::{Value, json};
use unityforge::client::Api;

pub fn api() -> Api<Value> {
    let port = std::env::var("OBENSEUER_MOD_PORT").ok().and_then(|p| p.parse().ok()).unwrap_or(17175);
    Api::at(port, "/op")
}

/// One op that must succeed.
pub fn op(api: &Api<Value>, name: &str, args: Value) -> Value {
    let r = api.op(name, args);
    assert!(r.ok, "{name} failed: {:?}", r.error);
    r.result
}

/// A method on a live object; JSON null when it failed.
pub fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

/// A static method; JSON null when it failed.
pub fn call_static(api: &Api<Value>, class: &str, method: &str, args: Value) -> Value {
    api.op("invoke_static", json!({"class": class, "method": method, "args": args})).result
}

/// Live copies of a class: (instance id, handle). The caller releases.
pub fn copies(api: &Api<Value>, class: &str) -> Vec<(i64, i64)> {
    let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
    let list = r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default();
    list.iter()
        .filter_map(handle_of)
        .filter_map(|h| Some((call(api, h, "GetInstanceID", json!([])).as_i64()?, h)))
        .collect()
}

/// What a class's static `instance` holds: its id, "destroyed" or "null".
pub fn instance_now(api: &Api<Value>, class: &str) -> String {
    let t = call_static(api, "System.Type", "GetType", json!([format!("{class}, Assembly-CSharp")]));
    let Some(t) = handle_of(&t) else { return "type not found".into() };
    let Some(f) = handle_of(&call(api, t, "GetField", json!(["instance"]))) else { return "no field".into() };
    let v = call(api, f, "GetValue", json!([null]));
    if v.get("name").and_then(Value::as_str) == Some("<null>") {
        return "destroyed".into();
    }
    match handle_of(&v) {
        Some(h) => call(api, h, "GetInstanceID", json!([])).as_i64().map_or("?".into(), |i| i.to_string()),
        None => "null".into(),
    }
}

/// One-copy classes earlier tests saw switched, emptied, or left on a
/// destroyed object by a second area.
pub const WATCHED: &[&str] = &[
    "PlayerCamera",
    "CameraRotate",
    "SetControls",
    "InteractObjects",
    "ThirdPersonCameraController",
    "FirstPersonHands",
    "PauseMenu",
    "SoundscapeGlobal",
    "info_map",
    "LightsController",
    "GameUIController",
    "GameController",
    "DialogueController",
    "Inventory",
    "PlayerStats",
    "TimeOfDayAzure",
    "Crime",
    "Money",
    "WaitingUI",
    "RadiationController",
];

pub fn scenes_loaded(api: &Api<Value>) -> i64 {
    call_static(api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCount", json!([])).as_i64().unwrap_or(0)
}

/// `reload_save` and wait until the save has loaded (src/investigate.rs).
pub fn reload_save(api: &Api<Value>) {
    op(api, "reload_save", json!({}));
    let start = Instant::now();
    std::thread::sleep(Duration::from_secs(2));
    while call_static(api, "SaveController", "get_Loading", json!([])).as_bool() != Some(false) {
        assert!(start.elapsed() < Duration::from_secs(120), "save did not finish loading in 120s");
        std::thread::sleep(Duration::from_millis(500));
    }
    std::thread::sleep(Duration::from_secs(3));
}

/// Turn on first_copy_wins and load `area` alongside the one area loaded
/// now (src/first_copy_wins.rs, docs/loading-research.md). Returns the
/// seconds the load took.
pub fn load_alongside(api: &Api<Value>, area: &str) -> f64 {
    assert_eq!(scenes_loaded(api), 1, "need exactly one area loaded");
    op(api, "first_copy_wins", json!({"on": true}));
    let start = Instant::now();
    let load = call_static(api, "UnityEngine.SceneManagement.SceneManager", "LoadSceneAsync", json!([area, "Additive"]));
    let load = handle_of(&load).expect("LoadSceneAsync gave an AsyncOperation");
    while call(api, load, "get_isDone", json!([])).as_bool() != Some(true) {
        assert!(start.elapsed() < Duration::from_secs(180), "{area} did not load in 180s");
        std::thread::sleep(Duration::from_millis(100));
    }
    let secs = start.elapsed().as_secs_f64();
    api.op("release_handle", json!({"handle": load}));
    std::thread::sleep(Duration::from_secs(3)); // its Awake and Start, and the switch-offs a frame later
    secs
}

/// A component's object and its parents from the top down: "Top / ... /
/// Object". Releases every handle it takes; not the component's.
pub fn top_path(api: &Api<Value>, component: i64) -> String {
    let call = |h: i64, m: &str| api.op("invoke_method", serde_json::json!({"handle": h, "method": m, "args": []})).result;
    let mut names = Vec::new();
    let mut t = handle_of(&call(component, "get_transform"));
    while let Some(h) = t {
        names.push(call(h, "get_name").as_str().unwrap_or("?").to_string());
        let parent = handle_of(&call(h, "get_parent"));
        api.op("release_handle", serde_json::json!({"handle": h}));
        t = parent;
    }
    names.reverse();
    names.join(" / ")
}
