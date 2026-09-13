//! First contact with Alchemy Factory (UE 5.7) over the control plane.
//!
//! Answers, from the live game:
//! - do the patternsleuth resolvers find GObjects, GNames and
//!   FName::AppendString on this exe (resolve_offsets)
//! - how many classes, structs and data tables discovery sees
//! - which vtable slot holds UObject::ProcessEvent, measured by
//!   scanning a plain UObject's vtable (the GameInstance) for the
//!   address UE4SS logs at startup. lib.rs PROCESS_EVENT_IDX must
//!   match this number.
//!
//! ```text
//! k3sc cargo-lock test -p alchemyfactory-mod --test research_engine -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip, UE4SS_LOG};
use modforge::client;
use serde_json::json;

#[test]
fn resolve_offsets() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op("resolve_offsets", json!({}));
    println!("resolve_offsets ok={} result={}", r.ok, r.result);
}

#[test]
fn discovery_counts() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (op, array_key, count_key) in [
        ("discover_classes", "classes", "classes_found"),
        ("discover_structs", "structs", "structs_found"),
        ("discover_data_tables", "data_tables", "tables_found"),
    ] {
        let r = api.op(op, json!({"refresh": true}));
        println!(
            "{op}: ok={} {count_key}={}",
            r.ok,
            r.result.get(count_key).unwrap_or(&json!(null))
        );
        if op == "discover_classes" {
            // Words a potion-making factory game would use in its
            // own class names. Refine once the real names are seen.
            let words = [
                "Alchemy", "Potion", "Cauldron", "Ingredient", "Recipe", "Brew", "Conveyor",
                "Machine", "Herb", "Essence",
            ];
            let mut names: Vec<&str> = r
                .result
                .get(array_key)
                .and_then(|v| v.as_array())
                .map(|a| {
                    a.iter()
                        .filter_map(|e| e.get("name").and_then(|n| n.as_str()))
                        .filter(|n| words.iter().any(|w| n.contains(w)))
                        .collect()
                })
                .unwrap_or_default();
            names.sort_unstable();
            println!("game-named classes ({}):", names.len());
            for n in &names {
                println!("  {n}");
            }
        }
    }
}

#[test]
fn process_event_slot() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let log = std::fs::read_to_string(UE4SS_LOG).unwrap_or_default();
    let pe_addr = log
        .lines()
        .filter_map(|l| l.split("ProcessEvent address 0x").nth(1))
        .last()
        .and_then(|h| u64::from_str_radix(h.trim(), 16).ok());
    let Some(pe) = pe_addr else {
        println!("no 'ProcessEvent address' line in {UE4SS_LOG}");
        return;
    };
    println!("ue4ss ProcessEvent = {pe:#x}");

    // A plain UObject keeps the base ProcessEvent at its slot;
    // AActor overrides it, so do not use an actor here.
    let gi = client::walk_class_chain_instances(&api, "GameInstance", 4);
    let Some(g) = gi.iter().find(|i| !i.name.contains("Default__")) else {
        println!("no live GameInstance instance");
        return;
    };
    let vt = client::read_bytes(&api, g.addr, 0, 8);
    if vt.len() != 8 {
        println!("could not read vtable pointer of {}", g.name);
        return;
    }
    let vtable = client::from_le_u64(&vt, 0);
    println!("gameinstance {} @ {:#x} vtable {vtable:#x}", g.name, g.addr);
    let table = client::read_bytes(&api, vtable, 0, 0x100 * 8);
    let mut found = None;
    for i in 0..(table.len() / 8) {
        let v = client::from_le_u64(&table, i * 8);
        if (0x40..0x60).contains(&i) {
            println!("  slot[{i:#x}] = {v:#x}");
        }
        if v == pe {
            found = Some(i);
        }
    }
    match found {
        Some(i) => println!("ProcessEvent vtable index = {i:#x}"),
        None => println!("ProcessEvent not found in first 0x100 slots"),
    }
}
