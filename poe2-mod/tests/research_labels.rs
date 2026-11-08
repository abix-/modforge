//! Where are the ground item labels on this build?
//!
//! Read-only. In PoE2 an item on the ground is picked up by clicking
//! its name label, so pickup needs each label's element and the item
//! entity it stands for. ExileCore2 reads them from the in-game UI's
//! ItemsOnGroundLabelElement (its offsets ship scrambled) and
//! GameHelper2 has none, so these tests look for UI elements that
//! point at the awake ground item entities and print where.
//!
//! ```text
//! cargo run -p poe2-mod            # in one terminal, game running, items on the ground
//! k3sc cargo-lock test -p poe2-mod --test research_labels -- --nocapture --test-threads=1
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};
use std::collections::{BTreeMap, HashMap};

/// How far into an element the search looks for an item pointer.
const SPAN: usize = 0x600;

fn hex(v: &Value) -> u64 {
    match v {
        Value::Number(n) => n.as_u64().unwrap_or(0),
        Value::String(s) => u64::from_str_radix(s.trim_start_matches("0x"), 16).unwrap_or(0),
        _ => 0,
    }
}

/// The awake ground item entities: address to path of the item.
fn ground_items(r: &Remote) -> Option<HashMap<u64, String>> {
    let e = match r.op("entities", json!({"path": "WorldItem"})) {
        Ok(e) => e,
        Err(err) => {
            println!("SKIP: {err}");
            return None;
        }
    };
    let list = e["awake"]["entities"].as_array().cloned().unwrap_or_default();
    let items: HashMap<u64, String> = list
        .iter()
        .filter(|x| x["path"].as_str().is_some_and(|p| p.contains("WorldItem")))
        .map(|x| (hex(&x["address"]), x["path"].as_str().unwrap_or("").to_string()))
        .collect();
    println!("{} awake ground items", items.len());
    Some(items)
}

/// UI elements under the root that hold a ground item's entity
/// address within [`SPAN`] bytes: the offset it sits at, how many
/// elements have it there, and the parents of those elements.
#[test]
fn elements_that_point_at_ground_items() {
    let r = Remote::at(17185);
    let Some(items) = ground_items(&r) else { return };
    if items.is_empty() {
        println!("SKIP: no items on the ground; drop or find some first");
        return;
    }
    let ui = r
        .op("ui", json!({"depth": 6, "max": 20000}))
        .expect("ui tree");
    let tree = ui["tree"].as_array().cloned().unwrap_or_default();
    println!("{} UI elements walked", tree.len());
    // offset -> (elements, a sample element, its depth)
    let mut by_offset: BTreeMap<u64, Vec<(u64, u64)>> = BTreeMap::new();
    let mut parents: BTreeMap<u64, usize> = BTreeMap::new();
    let mut last_at_depth: Vec<u64> = Vec::new();
    for n in &tree {
        let at = hex(&n["address"]);
        let depth = n["depth"].as_u64().unwrap_or(0) as usize;
        last_at_depth.truncate(depth);
        let parent = last_at_depth.last().copied().unwrap_or(0);
        last_at_depth.push(at);
        for (i, w) in r.words(at, SPAN).into_iter().enumerate() {
            if items.contains_key(&w) {
                by_offset.entry(i as u64 * 8).or_default().push((at, w));
                *parents.entry(parent).or_default() += 1;
            }
        }
    }
    for (off, hits) in &by_offset {
        println!("element + {off:#x}: {} elements point at a ground item, e.g. {:#x} -> {:#x}", hits.len(), hits[0].0, hits[0].1);
    }
    for (p, n) in &parents {
        println!("parent {p:#x}: {n} such children");
    }
    assert!(!by_offset.is_empty(), "no element points at a ground item");
}
