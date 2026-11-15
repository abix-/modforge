//! The game's type tables, read from the installed exe file: the loot
//! event and its fields by name. Needs no running game; SKIPs when the
//! exe is not installed at ENSHROUDED_EXE (default: the Steam path).
//!
//! ```text
//! k3sc cargo-lock test -p enshrouded-mod --test types -- --nocapture
//! ```

use modforge::keen::{TypeRegistry, describe};

const DEFAULT_EXE: &str = r"C:\Games\Steam\steamapps\common\Enshrouded\enshrouded.exe";

#[test]
fn loot_interaction_event_fields() {
    let exe = std::env::var("ENSHROUDED_EXE").unwrap_or_else(|_| DEFAULT_EXE.to_string());
    if !std::path::Path::new(&exe).exists() {
        println!("SKIP: no exe at {exe}");
        return;
    }
    let reg = TypeRegistry::load_from_executable(&exe).expect("read type tables");
    println!("{} types", reg.len());
    let names: Vec<&str> = reg
        .iter()
        .map(|t| t.qualified_name.as_str())
        .filter(|n| n.contains("Loot") && (n.contains("Event") || n.contains("Interact")))
        .collect();
    println!("loot types: {names:#?}");
    for name in names {
        println!("{}", serde_json_pretty(describe(&reg, name).unwrap()));
    }
    let event = describe(&reg, "keen::ecs::LootInteractionEvent").expect("LootInteractionEvent");
    let loot_all = event["fields"]
        .as_array()
        .unwrap()
        .iter()
        .find(|f| f["name"] == "lootAll")
        .expect("lootAll field");
    assert_eq!(loot_all["offset"], "0x14");
    assert_eq!(loot_all["type"], "keen::bool");
    // Opening a corpse (pressing E): the accept event and the corpse's
    // offer, the fields auto loot reads and writes by name.
    for (name, fields) in [
        (
            "keen::ecs::AcceptOfferedInteractionEvent",
            &["guestEntityId", "hostEntityId", "offerId"][..],
        ),
        (
            "keen::ecs::InteractionOfferRuntime",
            &["offerId", "isDisabled"][..],
        ),
    ] {
        let ty = describe(&reg, name).unwrap_or_else(|| panic!("no {name}"));
        println!("{}", serde_json_pretty(ty.clone()));
        for f in fields {
            assert!(
                ty["fields"]
                    .as_array()
                    .unwrap()
                    .iter()
                    .any(|x| x["name"] == *f),
                "{name} has no {f}"
            );
        }
    }
}

fn serde_json_pretty(v: serde_json::Value) -> String {
    serde_json::to_string_pretty(&v).unwrap()
}
