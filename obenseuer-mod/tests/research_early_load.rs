//! The game's early load of the next area (LoadSceneAsyncTrigger): which
//! doors in the current area have one, which area each loads, and how many
//! scenes are loaded right now (results in docs/doors.md, the game already
//! loads some areas early; operator 2026-10-02).
//!
//! Read-only: walk_class, read_field, invoke_method and invoke_static on
//! getters only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_early_load -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn call(api: &Api<Value>, h: i64, method: &str) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": []})).result
}

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

fn handles(api: &Api<Value>, class: &str) -> Vec<(i64, String)> {
    let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
    r.result
        .get("instances")
        .and_then(Value::as_array)
        .cloned()
        .unwrap_or_default()
        .iter()
        .filter_map(|i| Some((handle_of(i)?, i["name"].as_str().unwrap_or("?").to_string())))
        .collect()
}

fn active(api: &Api<Value>, h: i64) -> bool {
    handle_of(&call(api, h, "get_gameObject"))
        .map(|g| call(api, g, "get_activeInHierarchy").as_bool().unwrap_or(false))
        .unwrap_or(false)
}

/// Every door to another area in the current area, which of them have an
/// early-load trigger, and the scenes loaded now.
#[test]
fn doors_and_early_load_triggers_listed() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let area = api
        .op("invoke_static", json!({"class": "UnityEngine.Application", "method": "get_loadedLevelName", "args": []}))
        .result;
    let scenes = api
        .op("invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "get_sceneCount", "args": []}))
        .result;
    println!("area {area}, scenes loaded now {scenes}");

    let doors = handles(&api, "Changelevel");
    println!("\n{} doors to other areas (Changelevel):", doors.len());
    for (h, name) in &doors {
        println!("  {name:<40} to {:<35} active {}", read(&api, *h, "OtherLevel"), active(&api, *h));
    }

    let triggers = handles(&api, "LoadSceneAsyncTrigger");
    println!("\n{} early-load triggers (LoadSceneAsyncTrigger):", triggers.len());
    for (h, name) in &triggers {
        let door = read(&api, *h, "changelevel");
        let to = handle_of(&door).map(|d| read(&api, d, "OtherLevel")).unwrap_or(Value::Null);
        println!("  {name:<40} door {:<30} to {to:<35} active {}", door["name"], active(&api, *h));
    }

    assert!(!doors.is_empty(), "no Changelevel in {area}");
}
