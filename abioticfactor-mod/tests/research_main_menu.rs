//! What sits on screen before the main menu, and which of its functions the
//! "press anything to begin" key press runs. Read-only; run while the game
//! waits on that screen.
//!
//! ```text
//! cargo test -p abioticfactor-mod --test research_main_menu -- --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;
use std::collections::BTreeSet;

#[test]
fn press_anything_screen_widgets_and_functions() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let mut classes = BTreeSet::new();
    for needle in ["Menu", "Title", "Press", "Splash", "Intro", "Start", "Boot", "Loading", "Front"] {
        let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 512}));
        assert!(reply.ok, "{needle}: {:?}", reply.error);
        for instance in reply.result["instances"].as_array().into_iter().flatten() {
            if instance["is_cdo"] == true { continue; }
            let full = instance["full_name"].as_str().unwrap_or("");
            // Live widgets only: their class names end in _C and they are outered to the game instance or a level.
            let class = full.split_whitespace().next().unwrap_or("");
            if class.starts_with("W_") || class.contains("Widget") || class.contains("Menu") {
                classes.insert(class.to_owned());
                println!("live: {full}");
            }
        }
    }
    let words = ["Press", "Continue", "Start", "Begin", "Any", "Input", "Key", "Click", "Dismiss", "Proceed", "Skip", "Construct", "Activate"];
    for class in &classes {
        let functions = api.op("class_functions_by_name", json!({"class": class}));
        if !functions.ok { println!("{class}: {:?}", functions.error); continue; }
        let names: Vec<&str> = functions.result["functions"].as_array().into_iter().flatten()
            .filter_map(|f| f["name"].as_str())
            .filter(|n| words.iter().any(|w| n.contains(w)))
            .collect();
        if !names.is_empty() { println!("{class} functions: {names:?}"); }
    }
    // Live 2026-09-13: the splash handler and the early-access notice both live on W_MainMenu_Master_C.
    for function in ["SplashKeyDown", "SplashKeyDownPS5", "Continue_EarlyAccess", "OnKeyDown"] {
        let reply = api.op("function_parameters", json!({"class": "W_MainMenu_Master_C", "function": function}));
        println!("W_MainMenu_Master_C::{function}: {}", if reply.ok { reply.result.to_string() } else { format!("{:?}", reply.error) });
    }
}
