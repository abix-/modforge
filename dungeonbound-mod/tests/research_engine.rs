//! Research: is the mod loaded in place of GodotSteam, and do ops
//! reach Godot's main thread?

mod common;

use serde_json::json;

#[test]
fn research_engine() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let data = common::op(&api, "engine", json!({}));
    println!(
        "{}",
        serde_json::to_string_pretty(&data).unwrap_or_default()
    );
    assert_eq!(
        data["main_thread"],
        json!(true),
        "op did not run on the main thread"
    );
    assert!(
        data["version"].as_str().is_some_and(|v| v.contains("4.7")),
        "not Godot 4.7: {data}"
    );
    assert!(data["frames_drawn"].as_u64().is_some_and(|n| n > 0));
}
