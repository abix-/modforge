//! What covers the screen (operator 2026-10-02: the game went black with
//! the player's camera drawing). Reads the game's one LoadingScreen,
//! BlackCanvas and WhiteCanvas: switched on, canvas on, alpha, fading.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_screen -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call, call_static, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn one_copy(api: &Api<Value>, class: &str) -> Option<i64> {
    let t = handle_of(&call_static(api, "System.Type", "GetType", json!([format!("{class}, Assembly-CSharp")])))?;
    let f = handle_of(&call(api, t, "GetField", json!(["instance"])))?;
    handle_of(&call(api, f, "GetValue", json!([null])))
}

fn component(api: &Api<Value>, h: i64, class: &str) -> Option<i64> {
    handle_of(&call(api, h, "GetComponent", json!([class])))
}

#[test]
fn what_covers_the_screen() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in ["LoadingScreen", "BlackCanvas", "WhiteCanvas"] {
        let Some(h) = one_copy(&api, class) else {
            println!("{class}: no live one copy");
            continue;
        };
        let active = handle_of(&call(&api, h, "get_gameObject", json!([]))).map(|g| call(&api, g, "get_activeInHierarchy", json!([])));
        let canvas = component(&api, h, "Canvas").map(|c| call(&api, c, "get_enabled", json!([])));
        // BlackCanvas and WhiteCanvas fade through their canvasGroup field
        // (BlackCanvas.cs:6, ShowBlackCanvas sets its alpha to 1).
        let group = handle_of(&api.op("read_field", json!({"handle": h, "field": "canvasGroup"})).result)
            .or_else(|| component(&api, h, "CanvasGroup"));
        let alpha = group.map(|c| call(&api, c, "get_alpha", json!([])));
        println!("{class}: active {active:?} canvas on {canvas:?} alpha {alpha:?}");
        if class == "LoadingScreen" {
            println!("  Fading {} FadeActive {} LevelLoadDone {}", call(&api, h, "get_Fading", json!([])), call(&api, h, "get_FadeActive", json!([])), api.op("read_field", json!({"handle": h, "field": "LevelLoadDone"})).result);
        }
    }
}
