//! What a kept area's Game_Logic holds (docs/kept-areas.md, rule 1, which
//! copy): each direct child of Game_Logic, and the one-copy classes on
//! Game_Logic itself and under each child. Read-only. Needs an area kept
//! loaded besides the current one.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_game_logic -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::BTreeMap;

use common::{api, call, call_static, handle_of, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn id(api: &Api<Value>, h: i64) -> Option<i64> {
    call(api, h, "GetInstanceID", json!([])).as_i64()
}

fn name(api: &Api<Value>, h: i64) -> String {
    call(api, h, "get_name", json!([])).as_str().unwrap_or("?").to_string()
}

#[test]
fn game_logic() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let kept = op(&api, "load_alongside", json!({}));
    let current = kept["current"].as_str().unwrap_or("").to_string();
    let area = kept["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()).find(|a| *a != current).expect("an area kept loaded");
    let arr = handle_of(&call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]))).expect("roots");
    let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
    let game_logic = (0..n).filter_map(|i| handle_of(&call(&api, arr, "GetValue", json!([i])))).find(|r| name(&api, *r) == "Game_Logic").expect("Game_Logic");
    let gl_transform = handle_of(&call(&api, game_logic, "get_transform", json!([]))).expect("transform");
    println!("{area}: Game_Logic on {}", call(&api, game_logic, "get_activeSelf", json!([])));

    // Child of Game_Logic (by transform id) -> name; Game_Logic itself as "(itself)".
    let mut child_of: BTreeMap<i64, String> = BTreeMap::new();
    let count = call(&api, gl_transform, "get_childCount", json!([])).as_i64().unwrap_or(0);
    for i in 0..count {
        if let Some(c) = handle_of(&call(&api, gl_transform, "GetChild", json!([i]))) {
            if let Some(cid) = id(&api, c) {
                child_of.insert(cid, name(&api, c));
            }
        }
    }
    let gl_id = id(&api, gl_transform).unwrap_or(0);

    let mut classes = Vec::new();
    if let Some(list) = handle_of(&call_static(&api, "Unityforge.Shim.FirstCopyGuard", "OneCopyClasses", json!(["Inventory, Assembly-CSharp"]))) {
        let len = api.op("read_field", json!({"handle": list, "field": "Length"})).result.as_i64().unwrap_or(0);
        for i in 0..len {
            if let Some(c) = call(&api, list, "GetValue", json!([i])).as_str() {
                classes.push(c.to_string());
            }
        }
    }
    let mut under: BTreeMap<String, Vec<String>> = BTreeMap::new();
    for class in &classes {
        let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
        for c in r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of) {
            if call_static(&api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": c}])).as_str() != Some(area.as_str()) {
                continue;
            }
            // Walk up to the child of Game_Logic it is under.
            let mut t = handle_of(&call(&api, c, "get_transform", json!([])));
            while let Some(h) = t {
                let hid = id(&api, h).unwrap_or(0);
                if hid == gl_id {
                    under.entry("(Game_Logic itself)".into()).or_default().push(class.clone());
                    break;
                }
                if let Some(child) = child_of.get(&hid) {
                    under.entry(child.clone()).or_default().push(class.clone());
                    break;
                }
                t = handle_of(&call(&api, h, "get_parent", json!([])));
            }
        }
    }
    println!("children of Game_Logic: {}", child_of.len());
    for (child, cs) in &under {
        println!("  {child}: {}", cs.join(", "));
    }
}
