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
    // OBENSEUER_READ_ONLY=1: read what is loaded now, load nothing.
    let read_only = std::env::var("OBENSEUER_READ_ONLY").is_ok();
    if !read_only {
        load_save(&api, json!({}));
    }
    println!("right after the load: {}", counts(&api));
    for _ in 0..(if read_only { 0 } else { 60 }) {
        let k = op(&api, "load_alongside", json!({}));
        if k["loaded"].as_object().map_or(0, |m| m.len()) >= 3 && k["loading"].as_array().is_some_and(|l| l.is_empty()) {
            break;
        }
        std::thread::sleep(Duration::from_secs(2));
    }
    println!("after areas loaded alongside: {}", counts(&api));
    // OBENSEUER_ALL_AREAS=1: every area in the build loaded alongside first.
    if !read_only && std::env::var("OBENSEUER_ALL_AREAS").is_ok() {
        let n = call_static(&api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCountInBuildSettings", json!([])).as_i64().unwrap_or(0);
        for i in 0..n {
            let path = call_static(&api, "UnityEngine.SceneManagement.SceneUtility", "GetScenePathByBuildIndex", json!([i]));
            let Some(name) = path.as_str().and_then(|p| p.rsplit('/').next()).map(|f| f.trim_end_matches(".unity").to_string()) else { continue };
            if name.contains("Menu") || name.contains("Test") {
                continue;
            }
            let r = api.op("load_alongside", json!({"area": name}));
            if !r.ok {
                continue; // already loaded or loading
            }
            for _ in 0..60 {
                if op(&api, "load_alongside", json!({}))["loading"].as_array().is_some_and(|l| l.is_empty()) {
                    break;
                }
                std::thread::sleep(Duration::from_secs(1));
            }
        }
        println!("after every area loaded alongside: {}", counts(&api));
    }
    // Bakery's store per area (BakeryRuntimeAssembly ftLightmapsStorage): its
    // lightmaps and directional maps. The game-wide lightmap mode is taken
    // from the last store that woke (ftLightmaps.RefreshScene).
    let r = api.op("walk_class", json!({"class": "ftLightmapsStorage", "include_inactive": true}));
    for s in r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of) {
        let area = call_static(&api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": s}]));
        let count = |field: &str| {
            handle_of(&api.op("read_field", json!({"handle": s, "field": field})).result)
                .map(|l| call(&api, l, "get_Count", json!([])))
                .unwrap_or(Value::Null)
        };
        println!("Bakery store in {area}: lightmaps {}, directional maps {}", count("maps"), count("dirMaps"));
    }
    println!("lightmap mode now: {}", call_static(&api, "UnityEngine.LightmapSettings", "get_lightmapsMode", json!([])));
}
