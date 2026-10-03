//! Do the area-owned managers sit on their own objects (docs/kept-areas.md,
//! rule 1, which copy)? For DestructibleList, PlayerLevelEntrypoints and
//! SleepEventController in an area kept loaded: the object's path, every
//! script on that object, and how many children it has. Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_area_owned -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{api, call, call_static, handle_of, op, ping_or_skip, top_path};
use serde_json::{Value, json};

#[test]
fn area_owned() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let kept = op(&api, "load_alongside", json!({}));
    let current = kept["current"].as_str().unwrap_or("").to_string();
    let area = kept["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()).find(|a| *a != current).expect("an area kept loaded");
    let mb = handle_of(&call_static(&api, "System.Type", "GetType", json!(["UnityEngine.MonoBehaviour, UnityEngine.CoreModule"]))).expect("MonoBehaviour type");
    println!("area {area}");
    for class in ["DestructibleList", "PlayerLevelEntrypoints", "SleepEventController", "NPCManager", "info_game_logic", "info_map", "info_water_source", "SoundscapeGlobal"] {
        let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
        for c in r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of) {
            if call_static(&api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": c}])).as_str() != Some(area.as_str()) {
                continue;
            }
            let go = handle_of(&call(&api, c, "get_gameObject", json!([]))).expect("object");
            let scripts = handle_of(&call(&api, go, "GetComponents", json!([{"handle": mb}])));
            let mut names = Vec::new();
            if let Some(arr) = scripts {
                let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
                for i in 0..n {
                    if let Some(s) = handle_of(&call(&api, arr, "GetValue", json!([i]))) {
                        let t = handle_of(&call(&api, s, "GetType", json!([])));
                        names.push(t.map(|t| call(&api, t, "get_Name", json!([])).as_str().unwrap_or("?").to_string()).unwrap_or("?".into()));
                    }
                }
            }
            let transform = handle_of(&call(&api, go, "get_transform", json!([]))).expect("transform");
            let children = call(&api, transform, "get_childCount", json!([]));
            println!("{class}: {}\n  scripts on the object: {names:?}\n  children: {children}", top_path(&api, c));
        }
    }
}
