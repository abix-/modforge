//! Which top objects are switched on in each loaded area (operator
//! 2026-10-02: strangers and bank things in the player's lobby; only one
//! NPCController was active). Only the current area's, and the live
//! player's, should be on.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_areas_on -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call, call_static, handle_of, op, ping_or_skip};
use serde_json::json;

#[test]
fn top_objects_on_per_area() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let state = op(&api, "load_alongside", json!({}));
    println!("current area {}", state["current"]);
    for area in state["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()) {
        let roots = call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]));
        let Some(arr) = handle_of(&roots) else {
            println!("{area}: no top objects");
            continue;
        };
        let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
        let mut on = Vec::new();
        for i in 0..n {
            let Some(r) = handle_of(&call(&api, arr, "GetValue", json!([i]))) else { continue };
            if call(&api, r, "get_activeSelf", json!([])).as_bool() == Some(true) {
                on.push(call(&api, r, "get_name", json!([])).as_str().unwrap_or("?").to_string());
            }
        }
        println!("{area}: {n} top objects, {} on: {on:?}", on.len());
    }
}
