//! Research: can the game's GDScript source be read at runtime?
//!
//! An exported Godot 4 game may keep script text (`source_code`) or
//! strip it to tokens. Prints what the inventory script gives.
//! Read-only.

mod common;

use serde_json::json;

#[test]
fn research_script_source() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let inv = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "inventory", "depth": 0}),
    );
    let script = common::op(
        &api,
        "get_property",
        json!({"id": inv["value"]["id"], "property": "script", "depth": 0}),
    );
    println!("inventory script {}", script["value"]);
    let source = common::op(
        &api,
        "call_method",
        json!({"id": script["value"]["id"], "method": "get_source_code"}),
    );
    let text = source["result"].as_str().unwrap_or("");
    println!("source_code: {} chars", text.len());
    println!("{}", &text[..text.floor_char_boundary(3000)]);
}
