//! How does map size work in Sintopia?
//!
//! Map descriptors in the pak come in Small / Medium / Large
//! (Content/Descriptors/Maps/ChallengeMode) plus campaign maps and
//! a GD_Map_Testing_SizeMap. Hell has HellExpansionDescriptor and a
//! GD_HellExpansions settings asset. This test asks the live game
//! which classes describe a map, what fields they carry, and what
//! the loaded map descriptors hold.
//!
//! ```text
//! k3sc cargo-lock test -p sintopia-mod --test research_map_size -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::{json, Value};

const WORDS: [&str; 4] = ["Map", "Expansion", "Grid", "SubLevel"];

fn class_names(api: &modforge::client::Api<Value>) -> Vec<String> {
    let r = api.op("discover_classes", json!({}));
    r.result
        .get("classes")
        .and_then(|v| v.as_array())
        .map(|a| {
            a.iter()
                .filter_map(|e| e.get("name").and_then(|n| n.as_str()))
                .filter(|n| WORDS.iter().any(|w| n.contains(w)))
                .filter(|n| !n.contains("Datasmith") && !n.contains("Import"))
                .map(str::to_string)
                .collect()
        })
        .unwrap_or_default()
}

#[test]
fn map_classes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names = class_names(&api);
    names.sort_unstable();
    println!("classes naming Map/Expansion/Grid/SubLevel ({}):", names.len());
    for n in &names {
        println!("  {n}");
    }
}

#[test]
fn map_class_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in ["MapDescriptor", "HellExpansionDescriptor", "HellSubLevelDescriptor", "HellGridElementDescriptor"] {
        let r = api.op("discover_class_detail", json!({"name": class}));
        println!("== {class}: ok={}", r.ok);
        match r.result.get("properties").and_then(|v| v.as_array()) {
            Some(props) => {
                for p in props {
                    println!(
                        "  +{:<5} {:<40} {}",
                        p.get("offset").unwrap_or(&json!("?")),
                        p.get("name").and_then(|n| n.as_str()).unwrap_or("?"),
                        p.get("type").and_then(|t| t.as_str()).unwrap_or("?")
                    );
                }
            }
            None => println!("  {}", r.result),
        }
    }
}

#[test]
fn map_instances() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in ["MapDescriptor", "HellExpansionDescriptor"] {
        let r = api.op("walk_class_chain", json!({"needle": class, "max": 200}));
        let insts = r.result.get("instances").and_then(|v| v.as_array());
        println!("== live {class}: ok={} count={}", r.ok, insts.map(|a| a.len()).unwrap_or(0));
        if let Some(insts) = insts {
            for i in insts {
                println!(
                    "  {} ({})",
                    i.get("name").and_then(|n| n.as_str()).unwrap_or("?"),
                    i.get("class").and_then(|n| n.as_str()).unwrap_or("?")
                );
            }
        }
    }
}
