//! Where each loaded area's Azure sky parts sit (operator 2026-10-02:
//! with two areas loaded the lighting stays too dark after the second
//! area's environment controller was switched off). Every Azure sky part
//! writes game-wide lighting each frame (AzureEnvironmentController.cs:41,
//! AzureSkyRenderController.cs:228 and 339-356), so if each area brings a
//! whole sky setup, the second one fights the first on all of it.
//!
//! Lists every live Azure sky component with its parent objects up to the
//! top, whether it is on, and the scene-wide sun light.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_azure_sky -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running. Results go
//! to docs/azure-sky-<scenes loaded>-areas.txt.

mod common;
use common::{api, handle_of, ping_or_skip, top_path};
use serde_json::{Value, json};

const AZURE: &[&str] = &[
    "UnityEngine.AzureSky.AzureTimeController",
    "UnityEngine.AzureSky.AzureSkyRenderController",
    "UnityEngine.AzureSky.AzureWeatherController",
    "UnityEngine.AzureSky.AzureEnvironmentController",
    "UnityEngine.AzureSky.AzureFogScattering",
    "UnityEngine.AzureSky.AzureEffectsController",
    "UnityEngine.AzureSky.AzureWeatherZone",
    "TimeOfDayAzure",
];

#[test]
fn azure_sky_parts_listed() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let scenes = api.op("invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "get_sceneCount", "args": []})).result;
    let mut out = vec![format!("scenes loaded {scenes}")];
    for class in AZURE {
        let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
        let list = r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default();
        out.push(format!("\n{class}: {}", list.len()));
        for i in &list {
            let Some(h) = handle_of(i) else { continue };
            let on = api.op("invoke_method", json!({"handle": h, "method": "get_isActiveAndEnabled", "args": []})).result;
            out.push(format!("  on {on}  {}", top_path(&api, h)));
            api.op("release_handle", json!({"handle": h}));
        }
    }
    let sun = api.op("invoke_static", json!({"class": "UnityEngine.RenderSettings", "method": "get_sun", "args": []})).result;
    if let Some(h) = handle_of(&sun) {
        let intensity = api.op("invoke_method", json!({"handle": h, "method": "get_intensity", "args": []})).result;
        out.push(format!("\nRenderSettings.sun: {}  intensity {intensity}", top_path(&api, h)));
    }

    let text = out.join("\n");
    println!("{text}");
    let path = format!("{}/docs/azure-sky-{}-areas.txt", env!("CARGO_MANIFEST_DIR"), scenes.as_i64().unwrap_or(0));
    std::fs::write(&path, text + "\n").expect("write the results");
    println!("written to {path}");
}
