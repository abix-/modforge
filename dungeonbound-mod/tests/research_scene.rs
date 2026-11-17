//! Research: can we see everything Godot has on screen, and read,
//! write and call on it?
//!
//! Read-only except `set_property`, which writes the root window's
//! title back to the value it already has, and `move_mouse`, which
//! moves the game's mouse (not the OS cursor) onto a visible node.
//! Moving the real mouse during the test can fail the mouse check.

mod common;

use serde_json::{Value, json};

#[test]
fn research_ops_registered() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let list = common::op(&api, "list_ops", json!({}));
    let names: Vec<&str> = list["ops"]
        .as_array()
        .expect("ops array")
        .iter()
        .filter_map(|o| o["name"].as_str())
        .collect();
    for want in [
        "tree",
        "autoloads",
        "screen",
        "inspect",
        "get_property",
        "set_property",
        "call_method",
        "list_methods",
        "list_signals",
        "list_actions",
        "move_mouse",
        "click",
        "press_key",
        "press_action",
    ] {
        assert!(names.contains(&want), "{want} not registered: {names:?}");
    }
}

#[test]
fn research_tree_and_autoloads() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let tree = common::op(&api, "tree", json!({"depth": 2}));
    let nodes = tree["nodes"].as_array().expect("nodes");
    println!("tree depth 2: {} nodes", nodes.len());
    for n in nodes.iter().take(40) {
        println!(
            "{}{} [{}] {}",
            "  ".repeat(n["depth"].as_u64().unwrap_or(0) as usize),
            n["path"].as_str().unwrap_or("?"),
            n["class"].as_str().unwrap_or("?"),
            n["script"].as_str().unwrap_or("")
        );
    }
    assert_eq!(nodes[0]["path"], json!("/root"));

    let autoloads = common::op(&api, "autoloads", json!({}));
    let rows = autoloads["nodes"].as_array().expect("nodes");
    println!("root children:");
    for n in rows {
        println!(
            "  {} [{}] {} current_scene={}",
            n["path"], n["class"], n["script"], n["current_scene"]
        );
    }
    assert!(
        rows.iter().any(|n| n["current_scene"] == json!(true)),
        "no current scene among root's children"
    );
}

/// Visible nodes with text, and their rects.
fn screen_text(api: &modforge::client::Api<Value>) -> Vec<Value> {
    let screen = common::op(api, "screen", json!({"text_only": true}));
    screen["nodes"].as_array().cloned().unwrap_or_default()
}

#[test]
fn research_screen() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let screen = common::op(&api, "screen", json!({}));
    let nodes = screen["nodes"].as_array().expect("nodes");
    println!("viewport {} mouse {}", screen["viewport"], screen["mouse"]);
    println!("{} visible 2D nodes", nodes.len());
    assert!(!nodes.is_empty(), "nothing visible on screen");

    let text = screen_text(&api);
    println!("{} with text:", text.len());
    for n in &text {
        println!(
            "  {:?} [{}] rect {} window {} clickable {} disabled {}",
            n["text"].as_str().unwrap_or(""),
            n["class"].as_str().unwrap_or("?"),
            n["rect"],
            n["window_rect"],
            n["clickable"],
            n["disabled"]
        );
    }
    assert!(!text.is_empty(), "no visible text on screen");
}

#[test]
fn research_inspect_get_set_call() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let text = screen_text(&api);
    let node = text.first().expect("a visible node with text");
    let id = node["id"].clone();
    println!("inspecting {} [{}]", node["path"], node["class"]);

    let inspected = common::op(&api, "inspect", json!({"id": id}));
    let props = inspected["properties"].as_array().expect("properties");
    println!("{} properties, script {}", props.len(), inspected["script"]);
    let text_prop = props
        .iter()
        .find(|p| p["name"] == json!("text"))
        .expect("text property");
    assert_eq!(text_prop["value"], node["text"]);

    let got = common::op(&api, "get_property", json!({"id": id, "property": "text"}));
    assert_eq!(got["value"], node["text"]);

    let called = common::op(
        &api,
        "call_method",
        json!({"id": id, "method": "get_class"}),
    );
    assert_eq!(called["result"], node["class"]);

    let methods = common::op(&api, "list_methods", json!({"id": id}));
    assert!(
        methods["methods"]
            .as_array()
            .is_some_and(|m| m.iter().any(|x| x["name"] == json!("get_class")))
    );
    let signals = common::op(&api, "list_signals", json!({"id": id}));
    println!(
        "{} signals",
        signals["signals"].as_array().map_or(0, Vec::len)
    );

    // Write the root window's title back to itself.
    let title = common::op(
        &api,
        "get_property",
        json!({"node": "/root", "property": "title"}),
    );
    let set = common::op(
        &api,
        "set_property",
        json!({"node": "/root", "property": "title", "value": title["value"]}),
    );
    println!("title {} -> {}", set["before"], set["after"]);
    assert_eq!(set["before"], set["after"]);
}

#[test]
fn research_actions() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let actions = common::op(&api, "list_actions", json!({}));
    let rows = actions["actions"].as_array().expect("actions");
    for a in rows
        .iter()
        .filter(|a| !a["action"].as_str().unwrap_or("").starts_with("ui_"))
    {
        println!("{} {}", a["action"], a["events"]);
    }
    assert!(rows.iter().any(|a| a["action"] == json!("ui_accept")));
}

/// After `move_mouse` onto a clickable control, Godot's GUI says that
/// control is under the mouse: proves the window pixels `screen`
/// gives are the pixels input events use.
///
/// The viewport's mouse position is no proof: on 2026-11-16 it stayed
/// at the OS cursor (1179, 713) after a move to (204, 400), because
/// the root viewport reads the OS cursor.
#[test]
fn research_move_mouse() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let text = screen_text(&api);
    let node = text
        .iter()
        .find(|n| n["clickable"] == json!(true))
        .expect("a visible clickable control with text");
    let moved = common::op(&api, "move_mouse", json!({"id": node["id"]}));
    std::thread::sleep(std::time::Duration::from_millis(100));
    let hovered = common::op(
        &api,
        "call_method",
        json!({"node": "/root", "method": "gui_get_hovered_control"}),
    );
    println!(
        "moved to {} over {:?} {}; hovered {}",
        moved["at"],
        node["text"].as_str().unwrap_or(""),
        node["path"],
        hovered["result"]
    );
    assert_eq!(hovered["result"]["id"], node["id"], "GUI hover is not the node");
}
