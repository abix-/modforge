//! Loads a save by name, also from the main menu (the reload_save op,
//! src/investigate.rs), and waits until the game has loaded it.
//!
//! ```text
//! OBENSEUER_CHARACTER=Tom_Tomato OBENSEUER_SAVE=Slot7 k3sc cargo-lock test -p obenseuer-mod --test research_load_save -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{api, call_static, load_save, ping_or_skip};
use serde_json::json;

#[test]
fn load_a_save() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let character = std::env::var("OBENSEUER_CHARACTER").expect("OBENSEUER_CHARACTER");
    let save = std::env::var("OBENSEUER_SAVE").expect("OBENSEUER_SAVE");
    let r = load_save(&api, json!({"save": save, "character": character}));
    let level = call_static(&api, "UnityEngine.Application", "get_loadedLevelName", json!([]));
    println!("loaded {}, now in {level}", r["loading"]);
}
