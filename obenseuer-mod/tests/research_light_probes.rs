//! Light probes and lightmaps with areas kept loaded: the game never touches
//! them (no LightProbes or LightmapSettings in its code), so it relies on
//! Unity's own handling of one scene. Counts right after a normal load
//! (only the area loaded) and after areas loaded alongside. Changes the
//! game: loads the save last loaded.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_light_probes -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::Duration;

use common::{api, call, call_static, handle_of, load_save, op, ping_or_skip, scenes_loaded};
use serde_json::{Value, json};
use unityforge::client::Api;

fn counts(api: &Api<Value>) -> String {
    let probes = handle_of(&call_static(api, "UnityEngine.LightmapSettings", "get_lightProbes", json!([])))
        .map(|p| call(api, p, "get_count", json!([])))
        .unwrap_or(Value::Null);
    let lightmaps = handle_of(&call_static(api, "UnityEngine.LightmapSettings", "get_lightmaps", json!([])))
        .map(|a| api.op("read_field", json!({"handle": a, "field": "Length"})).result)
        .unwrap_or(Value::Null);
    format!("scenes loaded {}, light probes {probes}, lightmaps {lightmaps}", scenes_loaded(api))
}

#[test]
fn light_probes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    load_save(&api, json!({}));
    println!("right after the load: {}", counts(&api));
    for _ in 0..60 {
        let k = op(&api, "load_alongside", json!({}));
        if k["loaded"].as_object().map_or(0, |m| m.len()) >= 3 && k["loading"].as_array().is_some_and(|l| l.is_empty()) {
            break;
        }
        std::thread::sleep(Duration::from_secs(2));
    }
    println!("after areas loaded alongside: {}", counts(&api));
}
