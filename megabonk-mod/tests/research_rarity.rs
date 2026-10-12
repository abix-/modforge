//! Where Megabonk rolls the rarity of the upgrades it offers.
//!
//! Read-only. Run while an upgrade offer is on screen. Lists every
//! Assembly-CSharp type named after rarity, upgrades, level ups,
//! choices, offers or chests, then for each one prints its live
//! instances' fields (an enum has none, so an enum shows its values
//! through walk_class instead).
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_rarity -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, game_type_names, ping_or_skip};
use serde_json::{Value, json};

const WORDS: [&str; 6] = ["rarity", "upgrade", "levelup", "choice", "offer", "chest"];

/// Which method rolls the rarity an UpgradeButton shows
/// (2026-10-03: the live offer had buttons at rarity 0 and 1).
/// Prints the declared methods of the rarity and offer classes and
/// the rarity enums' values. walk_class wants the Il2Cpp-prefixed
/// name (the bare name returned null).
#[test]
fn rarity_methods() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Rarity",
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Upgrades.EncounterUtility",
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Interactables.ChestUtility",
        "Il2Cpp.UpgradePicker",
        "Il2Cpp.MyButtonOffersUtility",
        "Il2Cpp.UpgradeButton",
    ] {
        println!("\n== {class}");
        common::print_declared_methods(&api, class);
    }
    for class in [
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.ERarity",
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Items.EItemRarity",
    ] {
        println!("\n== {class} (walk_class)");
        let r = api.op("walk_class", json!({"class": class}));
        println!("ok={} {}", r.ok, serde_json::to_string(&r.result).unwrap_or_default());
    }
}

#[test]
fn rarity_and_offers() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names: Vec<String> = game_type_names(&api)
        .into_iter()
        .filter(|n| {
            let lower = n.to_ascii_lowercase();
            WORDS.iter().any(|w| lower.contains(w))
        })
        .collect();
    names.sort_unstable();
    println!("\nmatching types ({}):", names.len());
    for n in &names {
        println!("  {n}");
    }

    for n in &names {
        let list = find_instances(&api, n, true).unwrap_or_default();
        if list.is_empty() {
            if n.to_ascii_lowercase().contains("rarity") {
                println!("\n== {n} (no live instances; walk_class)");
                let r = api.op("walk_class", json!({"class": n}));
                println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
            }
            continue;
        }
        println!("\n== {n}: {} live instance(s)", list.len());
        for v in list.iter().take(2) {
            let Some(h) = v.get("handle").and_then(Value::as_i64) else {
                continue;
            };
            let r = api.op("inspect_object", json!({"handle": h}));
            println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
        }
        for v in &list {
            if let Some(h) = v.get("handle").and_then(Value::as_i64) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
}
