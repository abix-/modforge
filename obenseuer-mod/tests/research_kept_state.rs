//! What the mod's areas kept loaded are doing now (src/kept_loaded.rs):
//! loaded areas with their arrival point counts, the one loading, door
//! trips, and errors since the mark. One call each; returns at once.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_kept_state -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call_static, op, ping_or_skip, scenes_loaded};
use serde_json::json;

#[test]
fn kept_loaded_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    println!("area {}, scenes loaded {}", call_static(&api, "UnityEngine.Application", "get_loadedLevelName", json!([])), scenes_loaded(&api));
    println!("{}", serde_json::to_string_pretty(&op(&api, "load_alongside", json!({}))).unwrap());
    let errors = op(&api, "errors", json!({}));
    println!("errors since the mark: {}", errors["total"]);
    for g in errors["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }
}
