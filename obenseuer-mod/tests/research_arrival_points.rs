//! Where kept areas' arrival points come from (docs/kept-areas.md, rule 1,
//! which copy): every PlayerLevelEntrypoints copy, its area, whether it is
//! the game's `instance`, how many arrival points its list holds; and the
//! arrival point ids the mod keeps per area. Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_arrival_points -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::BTreeMap;

use common::{api, call, call_static, handle_of, op, ping_or_skip};
use serde_json::{Value, json};

#[test]
fn arrival_points() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let kept = op(&api, "load_alongside", json!({}));
    println!("mod: current {}, arrival point ids per area {}", kept["current"], kept["loaded"]);

    // Top object id -> area.
    let mut area_of_top: BTreeMap<i64, String> = BTreeMap::new();
    for (area, _) in kept["loaded"].as_object().into_iter().flatten() {
        let Some(arr) = handle_of(&call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]))) else { continue };
        let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
        for i in 0..n {
            if let Some(top) = handle_of(&call(&api, arr, "GetValue", json!([i]))) {
                if let Some(id) = call(&api, top, "GetInstanceID", json!([])).as_i64() {
                    area_of_top.insert(id, area.clone());
                }
            }
        }
    }

    let t = handle_of(&call_static(&api, "System.Type", "GetType", json!(["PlayerLevelEntrypoints, Assembly-CSharp"]))).expect("type");
    let f = handle_of(&call(&api, t, "GetField", json!(["instance"]))).expect("field");
    let instance_id = handle_of(&call(&api, f, "GetValue", json!([null]))).and_then(|h| call(&api, h, "GetInstanceID", json!([])).as_i64());

    let r = api.op("walk_class", json!({"class": "PlayerLevelEntrypoints", "include_inactive": true}));
    for c in r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of) {
        let id = call(&api, c, "GetInstanceID", json!([])).as_i64();
        let top = handle_of(&call(&api, c, "get_transform", json!([])))
            .and_then(|t| handle_of(&call(&api, t, "get_root", json!([]))))
            .and_then(|t| handle_of(&call(&api, t, "get_gameObject", json!([]))))
            .and_then(|g| call(&api, g, "GetInstanceID", json!([])).as_i64());
        let area = top.and_then(|t| area_of_top.get(&t).cloned()).unwrap_or_else(|| "?".into());
        let list = handle_of(&api.op("read_field", json!({"handle": c, "field": "Entrypoints"})).result);
        let count = list.and_then(|l| call(&api, l, "get_Count", json!([])).as_i64());
        let enabled = call(&api, c, "get_enabled", json!([]));
        println!("copy in {area}: the game's instance {}, enabled {enabled}, arrival points {count:?}", id == instance_id);
    }
}
