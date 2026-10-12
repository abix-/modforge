//! Relays with areas kept loaded (research.md 9.37, relays): per loaded
//! area, how many relays fire their outputs at Start (`triggerAtStart`,
//! Relay.cs:83-97; in the game on every area load) and how many have an
//! output waiting on a delay (`delayLeft`, resumed by OnLoadingGame,
//! 65-81). Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_relays -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::BTreeMap;

use common::{api, call, call_static, handle_of, ping_or_skip};
use serde_json::{Value, json};

#[test]
fn relays() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // Area -> (relays, fire at Start, with a delayed output running).
    let mut per_area: BTreeMap<String, (u32, u32, u32)> = BTreeMap::new();
    // Too many relays for walk_class's reply (64 KB): the array as one
    // handle, read element by element. It also holds prefab assets (no
    // area): skipped.
    let t = handle_of(&call_static(&api, "System.Type", "GetType", json!(["Relay, Assembly-CSharp"]))).expect("Relay type");
    let all = handle_of(&call_static(&api, "UnityEngine.Resources", "FindObjectsOfTypeAll", json!([{"handle": t}]))).expect("relays");
    let n = api.op("read_field", json!({"handle": all, "field": "Length"})).result.as_i64().unwrap_or(0);
    println!("relays found: {n}");
    for i in 0..n {
        let Some(relay) = handle_of(&call(&api, all, "GetValue", json!([i]))) else { continue };
        let area = call_static(&api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": relay}])).as_str().unwrap_or("").to_string();
        if area.is_empty() {
            api.op("release_handle", json!({"handle": relay}));
            continue;
        }
        let at_start = api.op("read_field", json!({"handle": relay, "field": "triggerAtStart"})).result.as_bool() == Some(true);
        let mut delayed = false;
        if let Some(outputs) = handle_of(&api.op("read_field", json!({"handle": relay, "field": "outputs"})).result) {
            let n = api.op("read_field", json!({"handle": outputs, "field": "Length"})).result.as_i64().unwrap_or(0);
            for i in 0..n {
                if let Some(o) = handle_of(&call(&api, outputs, "GetValue", json!([i]))) {
                    if api.op("read_field", json!({"handle": o, "field": "delayLeft"})).result.as_f64().unwrap_or(0.0) > 0.0 {
                        delayed = true;
                    }
                }
            }
        }
        let e = per_area.entry(area).or_default();
        e.0 += 1;
        e.1 += at_start as u32;
        e.2 += delayed as u32;
    }
    for (area, (all, at_start, delayed)) in &per_area {
        println!("{area}: relays {all}, fire at Start {at_start}, delayed output running {delayed}");
    }
}
