//! Which loaded area holds the scripts that turn the game's black canvas
//! on (operator 2026-10-02: the game went black; BlackCanvas alpha 1.0).
//! The game turns it on only through level events wired to
//! BlackCanvasTrigger (ShowBlackCanvas, FadeIn) and BlackoutTrigger
//! (StartBlackout), and the TenementController.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_black_triggers -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::BTreeMap;

use common::{api, call, call_static, copies, handle_of, op, ping_or_skip, top_path};
use serde_json::json;

#[test]
fn black_canvas_triggers_by_area() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let state = op(&api, "load_alongside", json!({}));
    println!("current area {}", state["current"]);
    let mut area_of: BTreeMap<i64, String> = BTreeMap::new();
    for area in state["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()) {
        let Some(arr) = handle_of(&call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]))) else { continue };
        let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
        for i in 0..n {
            if let Some(r) = handle_of(&call(&api, arr, "GetValue", json!([i]))) {
                if let Some(id) = call(&api, r, "GetInstanceID", json!([])).as_i64() {
                    area_of.insert(id, area.clone());
                }
            }
        }
    }
    for class in ["BlackCanvasTrigger", "BlackoutTrigger"] {
        let list = copies(&api, class);
        println!("{class}: {}", list.len());
        for (_, h) in list {
            let root = handle_of(&call(&api, h, "get_transform", json!([])))
                .and_then(|t| handle_of(&call(&api, t, "get_root", json!([]))))
                .and_then(|t| handle_of(&call(&api, t, "get_gameObject", json!([]))))
                .and_then(|g| call(&api, g, "GetInstanceID", json!([])).as_i64());
            let area = root.and_then(|r| area_of.get(&r).cloned()).unwrap_or_else(|| "kept through loads / none".into());
            let on = call(&api, h, "get_isActiveAndEnabled", json!([]));
            // The Relay on the parent object: triggerAtStart fires it three
            // frames after its area starts (Relay.cs:83-93).
            let at_start = handle_of(&call(&api, h, "get_transform", json!([])))
                .and_then(|t| handle_of(&call(&api, t, "get_parent", json!([]))))
                .and_then(|p| handle_of(&call(&api, p, "GetComponent", json!(["Relay"]))))
                .map(|r| api.op("read_field", json!({"handle": r, "field": "triggerAtStart"})).result);
            println!("  on {on:<5} at start {at_start:?} area {area:<36} {}", top_path(&api, h));
        }
    }
}
