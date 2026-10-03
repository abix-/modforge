//! Which NPCs are active near the player, and which loaded area's scene
//! each belongs to (operator 2026-10-02: after going out the front door and
//! back in, strangers stood in the player's lobby).
//!
//! For every active NPCController within OBENSEUER_NEAR_METRES (default
//! 30) of the main camera: its name, distance, top object path, and the
//! loaded area whose top objects include its top object (SceneTools.RootsOf
//! in the shim), or "kept through loads / none" when no area's do.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_npcs_here -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::BTreeMap;

use common::{api, call, call_static, handle_of, op, ping_or_skip, top_path};
use serde_json::{Value, json};
use unityforge::client::Api;

fn position(api: &Api<Value>, h: i64) -> Option<[f64; 3]> {
    let t = handle_of(&call(api, h, "get_transform", json!([])))?;
    let p = call(api, t, "get_position", json!([]));
    Some([p["x"].as_f64()?, p["y"].as_f64()?, p["z"].as_f64()?])
}

fn id(api: &Api<Value>, h: i64) -> Option<i64> {
    call(api, h, "GetInstanceID", json!([])).as_i64()
}

#[test]
fn npcs_near_the_player() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let metres: f64 = std::env::var("OBENSEUER_NEAR_METRES").ok().and_then(|v| v.parse().ok()).unwrap_or(30.0);
    let state = op(&api, "load_alongside", json!({}));
    println!("current area {}, loaded {}", state["current"], state["loaded"]);

    // Each loaded area's top object ids.
    let mut area_of: BTreeMap<i64, String> = BTreeMap::new();
    for area in state["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()) {
        let roots = call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]));
        let Some(arr) = handle_of(&roots) else { continue };
        let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
        for i in 0..n {
            if let Some(r) = handle_of(&call(&api, arr, "GetValue", json!([i]))) {
                if let Some(rid) = id(&api, r) {
                    area_of.insert(rid, area.clone());
                }
            }
        }
    }

    let camera = handle_of(&call_static(&api, "UnityEngine.Camera", "get_main", json!([]))).expect("main camera");
    let me = position(&api, camera).expect("camera position");
    let r = api.op("walk_class", json!({"class": "NPCController", "include_inactive": false}));
    let list = r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default();
    println!("{} active NPCs in all areas; within {metres} m:", list.len());
    for i in list {
        let Some(h) = handle_of(&i) else { continue };
        let Some(p) = position(&api, h) else { continue };
        let d = (0..3).map(|k| (p[k] - me[k]).powi(2)).sum::<f64>().sqrt();
        if d > metres {
            continue;
        }
        let root = handle_of(&call(&api, h, "get_transform", json!([])))
            .and_then(|t| handle_of(&call(&api, t, "get_root", json!([]))))
            .and_then(|t| handle_of(&call(&api, t, "get_gameObject", json!([]))))
            .and_then(|g| id(&api, g));
        let area = root.and_then(|r| area_of.get(&r).cloned()).unwrap_or_else(|| "kept through loads / none".into());
        println!("  {d:5.1} m  area {area:<32} {}", top_path(&api, h));
    }
}
