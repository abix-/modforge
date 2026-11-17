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

/// The tray now: placements, counts, weapon slots, equip rows, and
/// for each owned item its copies, family, merge and level state.
#[test]
fn research_tray_state() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let inv = global_object(&api, "inventory");
    let call = |id: &Value, method: &str, args: Value| {
        common::op(
            &api,
            "call_method",
            json!({"id": id, "method": method, "args": args, "depth": 3}),
        )["result"]
            .clone()
    };
    let run = global_object(&api, "current_run");
    let hero = common::op(
        &api,
        "get_property",
        json!({"id": run, "property": "character_id"}),
    )["value"]
        .clone();
    let global =
        common::op(&api, "inspect", json!({"node": "/root/Global", "depth": 0}))["id"].clone();
    println!("hero {hero}");
    for grid in 0..4 {
        println!(
            "grid {grid}: size {} open {} free cells {}",
            call(&inv, "grid_size", json!([grid])),
            call(&inv, "open_size", json!([grid])),
            call(&inv, "free_cells", json!([grid, {}])),
        );
    }
    println!("weapon_count {}", call(&inv, "weapon_count", json!([])));
    println!(
        "weapon slots {}",
        call(&global, "get_weapon_slot_count", json!([hero]))
    );
    println!(
        "equip rows open {}",
        call(&global, "equip_rows_open", json!([hero]))
    );
    println!(
        "next equip row cost {}",
        call(&global, "next_equip_row_cost", json!([hero]))
    );
    println!("has_any_merge {}", call(&inv, "has_any_merge", json!([])));
    println!(
        "owned counts {}",
        call(&inv, "get_owned_item_counts", json!([]))
    );
    let placements = common::op(
        &api,
        "get_property",
        json!({"id": inv, "property": "placements", "depth": 3}),
    )["value"]
        .clone();
    println!("placements {placements}");

    let owned = common::op(
        &api,
        "get_property",
        json!({"id": inv, "property": "owned_items", "depth": 1}),
    );
    for (id, item) in owned["value"].as_object().expect("owned_items") {
        let o = &item["id"];
        println!(
            "{id}: count {} equipped {} loose {} family {:?} can_merge {} can_level {} level x{} max level {} sell {} market {} weapon {} class {:?} usable {}",
            call(&inv, "get_count", json!([id])),
            call(&inv, "equipped_copies_of", json!([id])),
            call(&inv, "loose_count", json!([id])),
            call(&inv, "family_id", json!([{"id": o}])),
            call(&inv, "can_merge", json!([id])),
            call(o, "can_level", json!([])),
            call(o, "level_multiplier", json!([])),
            call(o, "effective_max_level", json!([])),
            call(o, "sell_value", json!([])),
            call(o, "market_value", json!([])),
            call(o, "is_weapon", json!([])),
            call(o, "needed_weapon_class", json!([])),
            call(o, "usable_by", json!([hero, true])),
        );
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
