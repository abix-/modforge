//! Research: is the mod loaded in place of GodotSteam, and do ops
//! reach Godot's main thread?
//!
//! Needs the game running with the mod deployed. Skips otherwise.

use modforge::client::Api;
use serde_json::{Value, json};

fn api() -> Api<Value> {
    Api::at(31330, "/op").with_timeout(std::time::Duration::from_secs(10))
}

#[test]
fn research_engine() {
    let api = api();
    let r = match api.try_op("engine", json!({})) {
        Ok(r) => r,
        Err(e) => {
            eprintln!(
                "SKIP: no control plane on 31330 ({e}); launch the game with the mod deployed"
            );
            return;
        }
    };
    assert!(r.ok, "engine op failed: {:?}", r.error);
    let data = r.result;
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
