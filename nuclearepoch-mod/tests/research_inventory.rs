//! Where Nuclear Epoch keeps the number of pocket slots.
//!
//! Answers, from the live game:
//! - which classes, structs and data tables are named after pockets,
//!   inventory, slots, backpacks, bags or containers
//! - the fields of each of those classes and structs whose names
//!   look like a count or a size (slot, pocket, size, capacity,
//!   count, num, max, width, height, grid)
//!
//! ```text
//! k3sc cargo-lock test -p nuclearepoch-mod --test research_inventory -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::{Value, json};

const NAME_WORDS: [&str; 6] = ["pocket", "inventory", "slot", "backpack", "bag", "container"];
const FIELD_WORDS: [&str; 10] = [
    "slot", "pocket", "size", "capacity", "count", "num", "max", "width", "height", "grid",
];

fn matches(name: &str, words: &[&str]) -> bool {
    let lower = name.to_lowercase();
    words.iter().any(|w| lower.contains(w))
}

fn names(result: &Value, array_key: &str, name_key: &str) -> Vec<String> {
    let mut out: Vec<String> = result
        .get(array_key)
        .and_then(|v| v.as_array())
        .map(|a| {
            a.iter()
                .filter_map(|e| e.get(name_key).and_then(|n| n.as_str()))
                .filter(|n| matches(n, &NAME_WORDS))
                .map(str::to_string)
                .collect()
        })
        .unwrap_or_default();
    out.sort_unstable();
    out.dedup();
    out
}

fn print_fields(detail: &Value) {
    let Some(fields) = detail.get("fields").and_then(|v| v.as_array()) else {
        println!("    (no fields: {})", detail.get("error").unwrap_or(&json!(null)));
        return;
    };
    for f in fields {
        let name = f.get("name").and_then(|n| n.as_str()).unwrap_or("");
        if matches(name, &FIELD_WORDS) {
            println!(
                "    {name} offset={} size={} {}",
                f.get("offset").unwrap_or(&json!(null)),
                f.get("element_size").unwrap_or(&json!(null)),
                f.get("class").and_then(|c| c.as_str()).unwrap_or("")
            );
        }
    }
}

#[test]
fn inventory_names_and_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    // In a loaded world the refresh walks 140K+ objects and runs past
    // the 30 s default (measured 2026-10-03), so it gets 5 minutes.
    let slow = common::api().with_timeout(std::time::Duration::from_secs(300));
    let tables = slow.op("discover_data_tables", json!({"refresh": true}));
    let table_names = names(&tables.result, "data_tables", "table_name");
    println!("data tables ({}):", table_names.len());
    for n in &table_names {
        println!("  {n}");
    }

    let classes = api.op("discover_classes", json!({}));
    let class_names = names(&classes.result, "classes", "name");
    println!("classes ({}):", class_names.len());
    for n in &class_names {
        println!("  {n}");
        let detail = api.op("discover_class_detail", json!({"name": n}));
        print_fields(&detail.result);
    }

    let structs = api.op("discover_structs", json!({}));
    let struct_names = names(&structs.result, "structs", "name");
    println!("structs ({}):", struct_names.len());
    for n in &struct_names {
        println!("  {n}");
        let detail = api.op("discover_struct_detail", json!({"name": n}));
        print_fields(&detail.result);
    }
}
