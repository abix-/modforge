//! Research: the stops on a floor that are not fights (shop, fuse,
//! campsite and the rest, encounter_overlay.gd Kind). Run at any
//! stop: the test finds the stop's node by its script and prints its
//! state, methods and buttons. Read-only.

mod common;

use serde_json::json;

const SCENE: &str = "/root/@Control@65/CurrentScene";

/// Every node under the scene whose script is a stop
/// (`*_encounter.gd`).
fn stops(api: &modforge::client::Api<serde_json::Value>) -> Vec<serde_json::Value> {
    let tree = common::op(api, "tree", json!({"node": SCENE, "depth": 8}));
    tree["nodes"]
        .as_array()
        .into_iter()
        .flatten()
        .filter(|n| {
            n["script"]
                .as_str()
                .is_some_and(|s| s.ends_with("_encounter.gd"))
        })
        .cloned()
        .collect()
}

#[test]
fn research_stop_on_screen() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let found = stops(&api);
    if found.is_empty() {
        eprintln!("SKIP: no stop on screen");
        return;
    }
    for stop in &found {
        println!("== {} ({})", stop["path"], stop["script"]);
        for v in common::script_vars(&api, &stop["id"], 2) {
            if common::is_default(&v["value"]) {
                continue;
            }
            let text = v["value"].to_string();
            println!(
                "  {} = {}",
                v["name"].as_str().unwrap_or("?"),
                &text[..text.floor_char_boundary(400)]
            );
        }
        common::print_methods(&api, "methods", &stop["id"]);
    }
}

/// The curse stop's bargain for each equipped item, through the
/// game's own preview (CurseEncounter `bargain`, which works on a copy
/// of the item), and what using the stop costs.
#[test]
fn research_curse_offer() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let Some(curse) = stops(&api).into_iter().find(|n| {
        n["script"]
            .as_str()
            .is_some_and(|s| s.ends_with("curse_encounter.gd"))
    }) else {
        eprintln!("SKIP: no curse stop on screen");
        return;
    };
    let call = |id: &serde_json::Value, method: &str, args: serde_json::Value| {
        common::op(
            &api,
            "call_method",
            json!({"id": id, "method": method, "args": args, "depth": 6}),
        )["result"]
            .clone()
    };
    let offer = common::op(
        &api,
        "get_property",
        json!({"id": curse["id"], "property": "_offer", "depth": 6}),
    )["value"]
        .clone();
    println!("offer {offer}");
    println!("cost {}", call(&curse["id"], "use_cost", json!([])));
    let inv = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "inventory", "depth": 0}),
    )["value"]["id"]
        .clone();
    for item in call(&inv, "get_equipped_list", json!([]))
        .as_array()
        .into_iter()
        .flatten()
    {
        let name = common::op(
            &api,
            "get_property",
            json!({"id": item["id"], "property": "id", "depth": 0}),
        )["value"]
            .clone();
        let deal = call(&curse["id"], "bargain", json!([offer, {"id": item["id"]}]));
        println!("  {name}: {deal}");
    }
}

/// The shop's wares (ShopEncounter `_cards`): item, price, sold.
#[test]
fn research_shop_wares() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let Some(shop) = stops(&api).into_iter().find(|n| {
        n["script"]
            .as_str()
            .is_some_and(|s| s.ends_with("shop_encounter.gd"))
    }) else {
        eprintln!("SKIP: no shop on screen");
        return;
    };
    let cards = common::op(
        &api,
        "get_property",
        json!({"id": shop["id"], "property": "_cards", "depth": 1}),
    );
    for card in cards["value"].as_array().into_iter().flatten() {
        let get = |p: &str| {
            common::op(
                &api,
                "get_property",
                json!({"id": card["id"], "property": p, "depth": 1}),
            )["value"]
                .clone()
        };
        let item = get("item");
        let name = common::op(
            &api,
            "get_property",
            json!({"id": item["id"], "property": "id", "depth": 0}),
        );
        println!(
            "  {} price {} sold {}",
            name["value"],
            get("price"),
            get("sold")
        );
    }
    let gold = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "current_run", "depth": 0}),
    );
    let gold = common::op(
        &api,
        "get_property",
        json!({"id": gold["value"]["id"], "property": "gold", "depth": 0}),
    );
    println!("gold {}", gold["value"]);
}
