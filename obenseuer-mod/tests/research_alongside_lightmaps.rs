//! The game-wide lighting data, to compare one area against two loaded
//! at once (operator 2026-10-02: lighting still off after the second
//! area's image effects and lights were switched off). Reads the baked
//! light data list (LightmapSettings.lightmaps), the light probes that
//! light moving things, reflection probes, Bakery's per-area lighting
//! stores, and the active scene's ambient, fog and sky.
//!
//! Read-only. Run once with two areas loaded and once after reload_save
//! (one area); each run writes docs/lighting-<scenes loaded>-areas.txt.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_alongside_lightmaps -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn call_static(api: &Api<Value>, class: &str, method: &str) -> Value {
    let r = api.op("invoke_static", json!({"class": class, "method": method, "args": []}));
    if r.ok { r.result } else { json!(format!("failed: {:?}", r.error)) }
}

fn call(api: &Api<Value>, h: i64, method: &str) -> Value {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": []}));
    if r.ok { r.result } else { json!(format!("failed: {:?}", r.error)) }
}

/// (all, switched on) of a component class.
fn count(api: &Api<Value>, class: &str) -> (usize, usize) {
    let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
    let list = r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default();
    let mut on = 0;
    for i in &list {
        if let Some(h) = handle_of(i) {
            on += (call(api, h, "get_isActiveAndEnabled").as_bool() == Some(true)) as usize;
            api.op("release_handle", json!({"handle": h}));
        }
    }
    (list.len(), on)
}

#[test]
fn lighting_data_now() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let scenes = call_static(&api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCount");
    let mut out = vec![format!("scenes loaded {scenes}, active area {}", call_static(&api, "UnityEngine.Application", "get_loadedLevelName"))];

    let maps = call_static(&api, "UnityEngine.LightmapSettings", "get_lightmaps");
    let maps_n = handle_of(&maps).map(|h| api.op("read_field", json!({"handle": h, "field": "Length"})).result);
    out.push(format!("baked light data (LightmapSettings.lightmaps): {maps_n:?}"));
    out.push(format!("lightmap mode: {}", call_static(&api, "UnityEngine.LightmapSettings", "get_lightmapsMode")));

    let probes = call_static(&api, "UnityEngine.LightmapSettings", "get_lightProbes");
    let probes_n = handle_of(&probes).map(|h| call(&api, h, "get_count"));
    out.push(format!("light probes (LightmapSettings.lightProbes count): {probes_n:?}"));

    for class in ["UnityEngine.ReflectionProbe", "ftLightmapsStorage", "UnityEngine.Rendering.PostProcessing.PostProcessVolume", "UnityEngine.Light"] {
        let (all, on) = count(&api, class);
        out.push(format!("{class}: {all} live, {on} switched on"));
    }

    for m in ["get_ambientMode", "get_ambientLight", "get_ambientIntensity", "get_fog", "get_fogColor", "get_fogDensity", "get_skybox", "get_sun"] {
        out.push(format!("RenderSettings.{}: {}", &m[4..], call_static(&api, "UnityEngine.RenderSettings", m)));
    }

    let text = out.join("\n");
    println!("{text}");
    let path = format!("{}/docs/lighting-{}-areas.txt", env!("CARGO_MANIFEST_DIR"), scenes.as_i64().unwrap_or(0));
    std::fs::write(&path, text + "\n").expect("write the results");
    println!("written to {path}");
}
