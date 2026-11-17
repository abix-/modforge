//! Research: the loot after a fight. Drops land in the tray, and a
//! choice of two sits in the pick grids (inventory.gd PICK_A 4,
//! PICK_B 5): take one, the other goes (`settle_picks`). Run while
//! the loot is on screen. Read-only.

mod common;

use serde_json::{Value, json};

const TRAY: i64 = 2;
const PICK_A: i64 = 4;
const PICK_B: i64 = 5;

/// Nodes anywhere in the game whose path or script names loot or a
/// choice, to find the screen the choice is shown on.
#[test]
fn research_loot_screen() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let tree = common::op(&api, "tree", json!({"node": "/root", "depth": 12}));
    let words = [
        "loot", "pick", "relic", "reward", "card", "choice", "choose", "dice", "drop",
    ];
    for n in tree["nodes"].as_array().expect("nodes") {
        let text = format!("{} {}", n["path"], n["script"]).to_lowercase();
        if words.iter().any(|w| text.contains(w)) {
            println!("{} [{}] {}", n["path"], n["class"], n["script"]);
        }
    }
}

#[test]
fn research_loot_choice() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let call = |id: &Value, method: &str, args: Value| {
        common::op(
            &api,
            "call_method",
            json!({"id": id, "method": method, "args": args, "depth": 2}),
        )["result"]
            .clone()
    };
    let inv = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "inventory", "depth": 0}),
    )["value"]["id"]
        .clone();
    println!(
        "has_pick {} has_drops {}",
        call(&inv, "has_pick", json!([])),
        call(&inv, "has_drops", json!([]))
    );
    for (label, grid) in [("pick A", PICK_A), ("pick B", PICK_B), ("tray", TRAY)] {
        let placements = call(&inv, "placements_in", json!([grid]));
        for p in placements.as_array().into_iter().flatten() {
            let item = &p["item"];
            let get = |prop: &str| {
                common::op(
                    &api,
                    "get_property",
                    json!({"id": item["id"], "property": prop, "depth": 0}),
                )["value"]
                    .clone()
            };
            println!(
                "{label}: {} \"{}\" type {} rarity {} level {} score {} drop {}",
                get("id"),
                get("display_name"),
                get("item_type"),
                get("rarity"),
                get("level"),
                call(&item["id"], "stat_score", json!([])),
                p["drop"]
            );
            println!("    {}", call(&item["id"], "format_description", json!([])));
            for v in common::script_vars(&api, &item["id"], 0) {
                let name = v["name"].as_str().unwrap_or("");
                if name.starts_with("bonus_") && !common::is_default(&v["value"]) {
                    println!("    {name} = {}", v["value"]);
                }
            }
        }
    }
}
