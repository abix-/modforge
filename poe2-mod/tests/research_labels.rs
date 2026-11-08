//! Where are the ground item labels on this build?
//!
//! Read-only. In PoE2 an item on the ground is picked up by clicking
//! its name label, so pickup needs each label's element and the item
//! entity it stands for. ExileCore2 reads them from the in-game UI's
//! ItemsOnGroundLabelElement (its offsets ship scrambled): a list of
//! VisibleItemLabel records, 32 bytes each, holding the label element,
//! the entity id and a position offset. GameHelper2 has none.
//!
//! Found so far (2026-11-07, 5 items on the ground, 14595 elements
//! walked from the UI manager, 0x600 bytes each): no element holds a
//! ground item entity's address, so the labels point at the item by id.
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

/// How far into an element the search looks.
const SPAN: usize = 0x600;
/// Longest list read, in bytes.
const MAX_LIST: u64 = 0x2000;

fn hex(v: &Value) -> u64 {
    match v {
        Value::Number(n) => n.as_u64().unwrap_or(0),
        Value::String(s) => u64::from_str_radix(s.trim_start_matches("0x"), 16).unwrap_or(0),
        _ => 0,
    }
}

/// The awake ground item entities: id to address.
fn ground_items(r: &Remote) -> Option<HashMap<u32, u64>> {
    let e = match r.op("entities", json!({"path": "WorldItem"})) {
        Ok(e) => e,
        Err(err) => {
            println!("SKIP: {err}");
            return None;
        }
    };
    let list = e["awake"]["entities"].as_array().cloned().unwrap_or_default();
    let items: HashMap<u32, u64> = list
        .iter()
        .map(|x| (x["id"].as_u64().unwrap_or(0) as u32, hex(&x["address"])))
        .collect();
    println!("{} awake ground items: {items:x?}", items.len());
    Some(items)
}

/// The UI tree from the UI manager: (address, depth).
fn tree(r: &Remote) -> Vec<(u64, usize)> {
    let manager = r.op("ui", json!({})).expect("ui")["manager"].as_u64().unwrap_or(0);
    let ui = r
        .op("ui", json!({"at": manager, "depth": 6, "max": 20000}))
        .expect("ui tree");
    let tree: Vec<(u64, usize)> = ui["tree"]
        .as_array()
        .cloned()
        .unwrap_or_default()
        .iter()
        .map(|n| (hex(&n["address"]), n["depth"].as_u64().unwrap_or(0) as usize))
        .collect();
    println!("{} UI elements walked from the manager {manager:#x}", tree.len());
    tree
}

/// Lists (std::vector begin, end, capacity) inside UI elements whose
/// records pair a pointer to a walked UI element with a ground item
/// entity id near it, ExileCore2's VisibleItemLabel shape. Ids alone
/// are small numbers found everywhere (first run: 396 noise hits), so
/// the element pointer is what makes a hit.
#[test]
fn lists_of_label_records() {
    let r = Remote::at(17185);
    let Some(items) = ground_items(&r) else { return };
    if items.is_empty() {
        println!("SKIP: no items on the ground; drop or find some first");
        return;
    }
    let walked = tree(&r);
    let elements: std::collections::HashSet<u64> = walked.iter().map(|w| w.0).collect();
    let mut found: BTreeMap<(u64, u64), Vec<String>> = BTreeMap::new();
    for &(at, depth) in &walked {
        let w = r.words(at, SPAN);
        for i in 0..w.len().saturating_sub(2) {
            let (begin, end, cap) = (w[i], w[i + 1], w[i + 2]);
            let len = end.wrapping_sub(begin);
            let plausible = begin > 0x10000
                && begin <= end
                && end <= cap
                && len >= 8
                && len <= MAX_LIST
                && begin.is_multiple_of(8);
            if !plausible {
                continue;
            }
            let bytes = r.bytes(begin, len as usize);
            let u32_at = |o: usize| u32::from_le_bytes(bytes[o..o + 4].try_into().unwrap());
            let u64_at = |o: usize| u64::from_le_bytes(bytes[o..o + 8].try_into().unwrap());
            // (pointer offset, id offset relative to it, id)
            let mut hits = Vec::new();
            for o in (0..bytes.len().saturating_sub(7)).step_by(8) {
                if !elements.contains(&u64_at(o)) {
                    continue;
                }
                let near = (o.saturating_sub(16)..(o + 28).min(bytes.len().saturating_sub(3))).step_by(4);
                for k in near {
                    let v = u32_at(k);
                    if items.contains_key(&v) {
                        hits.push((o, k as i64 - o as i64, v));
                    }
                }
            }
            let ids: std::collections::BTreeSet<u32> = hits.iter().map(|h| h.2).collect();
            if ids.len() >= 2 {
                found.entry((at, i as u64 * 8)).or_default().push(format!(
                    "depth {depth}, list {begin:#x} of {len:#x} bytes, (pointer at, id +, id) {hits:x?}"
                ));
            }
        }
    }
    for ((at, off), lines) in &found {
        for l in lines {
            println!("element {at:#x} + {off:#x}: {l}");
        }
    }
    assert!(!found.is_empty(), "no list pairs a UI element with two ground item ids");
}

/// Found by label_groups_two_lists_deep (2026-11-07): a depth-2
/// element under the UI manager holds at +0x2F0 a list of 72-byte
/// label groups; group +0 is a list of 32-byte records with the label
/// element at +0 and the entity id at +8, all 5 ground items there.
/// This finds the child path to it and dumps a group and its records.
#[test]
fn the_label_element_path_and_records() {
    let r = Remote::at(17185);
    let Some(items) = ground_items(&r) else { return };
    if items.is_empty() {
        println!("SKIP: no items on the ground; drop or find some first");
        return;
    }
    let manager = r.op("ui", json!({})).expect("ui")["manager"].as_u64().unwrap_or(0);
    let kids = |at: u64| -> Vec<u64> {
        let w = r.words(at + 0x10, 0x10);
        let (b, e) = (w[0], w[1]);
        if b == 0 || e <= b || e - b > 0x2000 {
            return Vec::new();
        }
        r.words(b, (e - b) as usize)
    };
    let mut found = Vec::new();
    for (i, c) in kids(manager).into_iter().enumerate() {
        for (j, g) in kids(c).into_iter().enumerate() {
            let w = r.words(g + 0x2F0, 0x18);
            let (b, e) = (w[0], w[1]);
            if b == 0 || e <= b || (e - b) % 72 != 0 || e - b > 72 * 64 {
                continue;
            }
            let groups = r.bytes(b, (e - b) as usize);
            let mut ids = Vec::new();
            for group in groups.chunks_exact(72) {
                let gw = words_of(group);
                let (lb, le) = (gw[0], gw[1]);
                if lb == 0 || le <= lb || (le - lb) % 32 != 0 || le - lb > 32 * 256 {
                    continue;
                }
                for rec in r.bytes(lb, (le - lb) as usize).chunks_exact(32) {
                    let id = u32::from_le_bytes(rec[8..12].try_into().unwrap());
                    if items.contains_key(&id) {
                        ids.push(id);
                    }
                }
            }
            if !ids.is_empty() {
                println!("path [{i}, {j}] element {g:#x}: {} groups, item ids {ids:x?}", groups.len() / 72);
                found.push((g, groups));
            }
        }
    }
    let Some((g, groups)) = found.first() else {
        panic!("no child at depth 2 holds label groups at +0x2F0");
    };
    for (n, group) in groups.chunks_exact(72).enumerate() {
        let gw = words_of(group);
        let floats: Vec<f32> = group
            .chunks_exact(4)
            .map(|c| f32::from_le_bytes(c.try_into().unwrap()))
            .collect();
        println!("group {n} words {gw:x?}");
        println!("group {n} floats {floats:?}");
        let (lb, le) = (gw[0], gw[1]);
        if lb == 0 || le <= lb || le - lb > 32 * 256 {
            continue;
        }
        for rec in r.bytes(lb, (le - lb) as usize).chunks_exact(32) {
            let rw = words_of(rec);
            let rf: Vec<f32> = rec
                .chunks_exact(4)
                .map(|c| f32::from_le_bytes(c.try_into().unwrap()))
                .collect();
            let id = u32::from_le_bytes(rec[8..12].try_into().unwrap());
            println!("  record id {id:#x} words {rw:x?} floats {rf:?}");
        }
    }
    let ew = r.words(*g, 0x340);
    println!("element {g:#x} words 0x2c0..0x340: {:x?}", &ew[0x2c0 / 8..0x340 / 8]);
}

/// The ground_labels op over the found layout: every awake ground item
/// has a label, each label names a ground item, and shown labels have
/// a rectangle on the screen.
#[test]
fn every_ground_item_has_a_label() {
    let r = Remote::at(17185);
    let Some(items) = ground_items(&r) else { return };
    let out = r.op("ground_labels", json!({})).expect("ground_labels");
    let labels = out["labels"].as_array().cloned().unwrap_or_default();
    for l in &labels {
        println!(
            "id {:#x} visible {} screen {} item {} {} exalted {} candidate {}",
            l["id"].as_u64().unwrap_or(0),
            l["visible"],
            l["screen"],
            l["item"]["base"],
            l["item"]["path"],
            l["exalted"],
            l["candidate"]
        );
    }
    let ids: std::collections::HashSet<u32> =
        labels.iter().map(|l| l["id"].as_u64().unwrap_or(0) as u32).collect();
    for id in items.keys() {
        assert!(ids.contains(id), "ground item {id:#x} has no label");
    }
    for l in &labels {
        assert!(!l["item"].is_null(), "label {} names no ground item", l["id"]);
        if l["visible"] == true {
            assert!(!l["screen"].is_null(), "shown label {} has no rectangle", l["id"]);
        }
    }
}

/// std::vector headers among `w`: (word index, begin, length in bytes).
fn vectors(w: &[u64]) -> Vec<(usize, u64, u64)> {
    (0..w.len().saturating_sub(2))
        .filter_map(|i| {
            let (begin, end, cap) = (w[i], w[i + 1], w[i + 2]);
            let len = end.wrapping_sub(begin);
            (begin > 0x10000
                && begin <= end
                && end <= cap
                && len >= 8
                && len <= MAX_LIST
                && begin.is_multiple_of(8))
            .then_some((i, begin, len))
        })
        .collect()
}

fn words_of(bytes: &[u8]) -> Vec<u64> {
    bytes
        .chunks_exact(8)
        .map(|c| u64::from_le_bytes(c.try_into().unwrap()))
        .collect()
}

/// ExileCore2's shape two lists deep: element, list of label groups,
/// each group's list of 32-byte records {element pointer, entity id,
/// position}. A record counts when its pointer is a real UI element
/// (points at itself at +8) and an item id sits within the record.
/// Also any item entity address one plain pointer away from an element
/// (PoE1 kept labels in a linked list of {label, item entity} nodes).
#[test]
fn label_groups_two_lists_deep() {
    let r = Remote::at(17185);
    let Some(items) = ground_items(&r) else { return };
    if items.is_empty() {
        println!("SKIP: no items on the ground; drop or find some first");
        return;
    }
    let addresses: std::collections::HashSet<u64> = items.values().copied().collect();
    let walked: Vec<(u64, usize)> = tree(&r).into_iter().filter(|w| w.1 <= 3).collect();
    println!("{} elements at depth 3 or less", walked.len());
    let mut self_check: HashMap<u64, bool> = HashMap::new();
    let mut is_element = |p: u64| -> bool {
        *self_check
            .entry(p)
            .or_insert_with(|| r.words(p, 0x10).get(1) == Some(&p))
    };
    let mut lines = Vec::new();
    for &(at, depth) in &walked {
        let w = r.words(at, SPAN);
        // Plain pointers: item addresses in the 0x200 bytes they point at.
        for (i, &p) in w.iter().enumerate() {
            if p < 0x10000 || !p.is_multiple_of(8) {
                continue;
            }
            for (k, v) in r.words(p, 0x200).iter().enumerate() {
                if addresses.contains(v) {
                    lines.push(format!(
                        "element {at:#x} (depth {depth}) + {:#x} -> {p:#x} + {:#x} = item {v:#x}",
                        i * 8,
                        k * 8
                    ));
                }
            }
        }
        for (i, begin, len) in vectors(&w) {
            let outer = r.bytes(begin, len as usize);
            let mut inner = vec![(None, begin, outer.clone())];
            for (j, b, l) in vectors(&words_of(&outer)) {
                inner.push((Some(j * 8), b, r.bytes(b, l as usize)));
            }
            for (at_in_outer, b, bytes) in inner {
                let u32_at = |o: usize| u32::from_le_bytes(bytes[o..o + 4].try_into().unwrap());
                let mut hits = Vec::new();
                for o in (0..bytes.len().saturating_sub(31)).step_by(8) {
                    let p = u64::from_le_bytes(bytes[o..o + 8].try_into().unwrap());
                    if p < 0x10000 {
                        continue;
                    }
                    let id_offsets: Vec<usize> =
                        (o + 8..o + 32).step_by(4).filter(|k| items.contains_key(&u32_at(*k))).collect();
                    if !id_offsets.is_empty() && is_element(p) {
                        hits.push((o, id_offsets[0] - o, u32_at(id_offsets[0])));
                    }
                }
                let ids: std::collections::BTreeSet<u32> = hits.iter().map(|h| h.2).collect();
                if !ids.is_empty() {
                    lines.push(format!(
                        "element {at:#x} (depth {depth}) + {:#x} list {begin:#x}, inner at {at_in_outer:x?} list {b:#x}: (record at, id +, id) {hits:x?}",
                        i * 8
                    ));
                }
            }
        }
    }
    for l in &lines {
        println!("{l}");
    }
    assert!(!lines.is_empty(), "no label records or item addresses found");
}
