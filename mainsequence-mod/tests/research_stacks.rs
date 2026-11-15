//! Where Main Sequence keeps an item's stack size.
//!
//! Items are one data asset each (`Content/Data/Items/ITEM_*`, read
//! from the game's file manifest), not rows in a data table.
//! Answers, from the live game:
//! - which loaded classes are named after items or stacks
//! - which of their fields are named after stacks, with offset and size
//! - for each such field, the value on every live object of that class
//!
//! ```text
//! k3sc cargo-lock test -p mainsequence-mod --test research_stacks -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::{Value, json};

const CLASS_WORDS: [&str; 3] = ["item", "stack", "inventory"];
const FIELD_WORDS: [&str; 2] = ["stack", "maxamount"];

fn has_word(name: &str, words: &[&str]) -> bool {
    let lower = name.to_lowercase();
    words.iter().any(|w| lower.contains(w))
}

fn read_le(hex_str: &str) -> i64 {
    let bytes = hex::decode(hex_str).unwrap_or_default();
    let mut v: i64 = 0;
    for (i, b) in bytes.iter().enumerate().take(8) {
        v |= (*b as i64) << (8 * i);
    }
    // Sign-extend 4-byte ints.
    if bytes.len() == 4 {
        v = v as i32 as i64;
    }
    v
}

/// The Inventory class's functions and fields, and StackMultiplier
/// read both as an int and as a float on every live inventory, to
/// tell which type it is and what each inventory holds.
#[test]
fn inventory_stack_multiplier() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let empty = Vec::new();
    let d = api.op("discover_class_detail", json!({"name": "Inventory"}));
    assert!(d.ok, "discover_class_detail failed: {:?}", d.error);
    println!("Inventory fields:");
    for f in d.result["fields"].as_array().unwrap_or(&empty) {
        println!(
            "  0x{:X} {:>3} {}",
            f["offset"].as_u64().unwrap_or(0),
            f["element_size"].as_u64().unwrap_or(0),
            f["name"].as_str().unwrap_or("")
        );
    }
    println!("Inventory functions:");
    for f in d.result["functions"].as_array().unwrap_or(&empty) {
        println!("  {}", f["name"].as_str().unwrap_or(""));
    }

    let w = api.op("walk_class_chain", json!({"needle": "Inventory", "max": 400}));
    assert!(w.ok, "walk failed: {:?}", w.error);
    for inst in w.result["instances"].as_array().unwrap_or(&empty) {
        let full = inst["full_name"].as_str().unwrap_or("?");
        if !full.starts_with("Inventory ") {
            continue;
        }
        let sel = inst["addr_selector"].as_str().unwrap_or("");
        let b = api.op(
            "read_bytes",
            json!({"instance_selector": sel, "offset": 0xB0, "length": 4}),
        );
        let hex_str = b.result["bytes_hex"].as_str().unwrap_or("").to_string();
        let raw = hex::decode(&hex_str).unwrap_or_default();
        if raw.len() != 4 {
            continue;
        }
        let arr = [raw[0], raw[1], raw[2], raw[3]];
        println!(
            "  {full:<90} int {} float {}",
            i32::from_le_bytes(arr),
            f32::from_le_bytes(arr)
        );
    }
}

/// Run the mod's `stack_size` op (optional MULTIPLIER env var sets a
/// new one) and read MaxStackSize back off every ITEM_ asset.
#[test]
fn stack_size_applied() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let args = match std::env::var("MULTIPLIER").ok().and_then(|m| m.parse::<i64>().ok()) {
        Some(m) => json!({"multiplier": m}),
        None => json!({}),
    };
    let r = api.op("stack_size", args);
    assert!(r.ok, "stack_size failed: {:?}", r.error);
    println!("stack_size: {}", r.result);

    let empty = Vec::new();
    let w = api.op("walk_class_chain", json!({"needle": "Item", "max": 400}));
    assert!(w.ok, "walk failed: {:?}", w.error);
    let mut items = 0;
    for inst in w.result["instances"].as_array().unwrap_or(&empty) {
        let name = inst["name"].as_str().unwrap_or("?");
        if !name.starts_with("ITEM_") {
            continue;
        }
        let sel = inst["addr_selector"].as_str().unwrap_or("");
        let b = api.op(
            "read_bytes",
            json!({"instance_selector": sel, "offset": 0x5C, "length": 4}),
        );
        let v = read_le(b.result["bytes_hex"].as_str().unwrap_or(""));
        println!("  {name:<40} {v}");
        items += 1;
    }
    println!("{items} items");
    assert!(items > 0, "no ITEM_ assets found");
}

#[test]
fn stack_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op("discover_classes", json!({}));
    assert!(r.ok, "discover_classes failed: {:?}", r.error);
    let empty = Vec::new();
    let classes: Vec<String> = r.result["classes"]
        .as_array()
        .unwrap_or(&empty)
        .iter()
        .filter_map(|c| c["name"].as_str())
        .filter(|n| has_word(n, &CLASS_WORDS))
        .map(str::to_string)
        .collect();
    println!(
        "{} classes scanned, {} named after items, stacks or inventory",
        r.result["classes_found"], classes.len()
    );

    let mut found: Vec<(String, String, u64, u64)> = Vec::new();
    for cls in &classes {
        let d = api.op("discover_class_detail", json!({"name": cls}));
        if !d.ok {
            continue;
        }
        let fields: &Vec<Value> = d.result["fields"].as_array().unwrap_or(&empty);
        for f in fields {
            let name = f["name"].as_str().unwrap_or("");
            if has_word(name, &FIELD_WORDS) {
                let off = f["offset"].as_u64().unwrap_or(0);
                let size = f["element_size"].as_u64().unwrap_or(0);
                println!("  {cls}.{name}  offset 0x{off:X}  size {size}");
                found.push((cls.clone(), name.to_string(), off, size));
            }
        }
    }
    println!("{} stack fields", found.len());

    for (cls, field, off, size) in &found {
        if !(1..=8).contains(size) {
            continue;
        }
        let w = api.op("walk_class_chain", json!({"needle": cls, "max": 400}));
        if !w.ok {
            println!("{cls}: walk failed: {:?}", w.error);
            continue;
        }
        let insts = w.result["instances"].as_array().unwrap_or(&empty);
        println!(
            "\n{cls}.{field}: {} live objects ({} returned)",
            w.result["total"], insts.len()
        );
        for inst in insts {
            let sel = inst["addr_selector"].as_str().unwrap_or("");
            let name = inst["name"].as_str().unwrap_or("?");
            let b = api.op(
                "read_bytes",
                json!({"instance_selector": sel, "offset": off, "length": size}),
            );
            let v = if b.ok {
                read_le(b.result["bytes_hex"].as_str().unwrap_or("")).to_string()
            } else {
                format!("err {:?}", b.error)
            };
            println!("  {name:<40} {v}");
        }
    }
}
