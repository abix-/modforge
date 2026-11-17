//! Research: the equipment rules. How many of one item, what stacks,
//! what buying another copy does, and how the tray takes items.
//!
//! Script source is stripped from the export (research_source), so
//! this reads method names and arguments, and the game's own data.
//! Read-only.

mod common;

use modforge::client::Api;
use serde_json::{Value, json};

fn global_object(api: &Api<Value>, property: &str) -> Value {
    common::op(
        api,
        "get_property",
        json!({"node": "/root/Global", "property": property, "depth": 0}),
    )["value"]["id"]
        .clone()
}

fn print_methods(api: &Api<Value>, label: &str, target: Value) {
    let mut args = target;
    args["script_only"] = json!(true);
    let methods = common::op(api, "list_methods", args);
    println!("{label}:");
    for m in methods["methods"].as_array().expect("methods") {
        let params: Vec<String> = m["args"]
            .as_array()
            .into_iter()
            .flatten()
            .map(|a| {
                format!(
                    "{}: {}",
                    a["name"].as_str().unwrap_or("?"),
                    a["type"].as_str().unwrap_or("?")
                )
            })
            .collect();
        println!(
            "  {}({}) -> {}",
            m["name"].as_str().unwrap_or("?"),
            params.join(", "),
            m["return"]
        );
    }
}

/// Method names of the tray (inventory.gd), the run, the item
/// database, the item resource and the game state.
#[test]
fn research_equipment_methods() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    print_methods(
        &api,
        "inventory.gd",
        json!({"id": global_object(&api, "inventory")}),
    );
    print_methods(
        &api,
        "run_state.gd",
        json!({"id": global_object(&api, "current_run")}),
    );
    print_methods(&api, "EquipmentDB", json!({"node": "/root/EquipmentDB"}));
    print_methods(&api, "Global", json!({"node": "/root/Global"}));

    let inv = global_object(&api, "inventory");
    let owned = common::op(
        &api,
        "get_property",
        json!({"id": inv, "property": "owned_items", "depth": 1}),
    );
    if let Some((_, item)) = owned["value"].as_object().and_then(|m| m.iter().next()) {
        print_methods(&api, "equipment_item.gd", json!({"id": item["id"]}));
    }
}

/// Every script variable of one owned item, including the unset ones:
/// the full list of fields an item can have.
#[test]
fn research_item_fields() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let inv = global_object(&api, "inventory");
    let owned = common::op(
        &api,
        "get_property",
        json!({"id": inv, "property": "owned_items", "depth": 1}),
    );
    let (name, item) = owned["value"]
        .as_object()
        .and_then(|m| m.iter().next())
        .expect("an owned item");
    println!("{name}:");
    for v in common::script_vars(&api, &item["id"], 2) {
        println!("  {} [{}] = {}", v["name"], v["type"], v["value"]);
    }
}
