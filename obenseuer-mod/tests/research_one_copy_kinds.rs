//! One copy for the game, or one copy per area (docs/loading-research.md):
//! for every one-copy class (FirstCopyGuard.OneCopyClasses, the same list
//! first_copy_wins guards), where each copy sits: its area and its top
//! object. Read-only. Needs areas kept loaded (at least two areas).
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_one_copy_kinds -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::{BTreeMap, BTreeSet};

use common::{api, call, call_static, handle_of, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// The elements of a C# array handle, as handles.
fn elements(api: &Api<Value>, arr: i64) -> Vec<i64> {
    let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
    (0..n).filter_map(|i| handle_of(&call(api, arr, "GetValue", json!([i])))).collect()
}

fn id(api: &Api<Value>, h: i64) -> Option<i64> {
    call(api, h, "GetInstanceID", json!([])).as_i64()
}

#[test]
fn one_copy_kinds() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // Top object id -> (area, top object name), for every area loaded.
    let areas: Vec<String> = op(&api, "load_alongside", json!({}))["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()).collect();
    assert!(areas.len() >= 2, "need areas kept loaded, have {areas:?}");
    let mut tops: BTreeMap<i64, (String, String)> = BTreeMap::new();
    for area in &areas {
        let Some(arr) = handle_of(&call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]))) else { continue };
        for top in elements(&api, arr) {
            let name = call(&api, top, "get_name", json!([])).as_str().unwrap_or("?").to_string();
            if let Some(i) = id(&api, top) {
                tops.insert(i, (area.clone(), name));
            }
        }
    }
    println!("areas: {areas:?}");

    let mut classes = Vec::new();
    for asm in ["Inventory, Assembly-CSharp", "AstarPath, AstarPathfindingProject"] {
        if let Some(arr) = handle_of(&call_static(&api, "Unityforge.Shim.FirstCopyGuard", "OneCopyClasses", json!([asm]))) {
            let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
            for i in 0..n {
                if let Some(c) = call(&api, arr, "GetValue", json!([i])).as_str() {
                    classes.push(c.to_string());
                }
            }
        }
    }
    println!("one-copy classes: {}\n", classes.len());

    // Class -> the top object names its copies sit under, and in how many areas.
    let mut by_top: BTreeMap<String, BTreeSet<String>> = BTreeMap::new();
    for class in &classes {
        let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
        let copies: Vec<i64> = r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of).collect();
        let mut seen: BTreeMap<String, BTreeSet<String>> = BTreeMap::new(); // top name -> areas
        for c in &copies {
            let root = handle_of(&call(&api, *c, "get_transform", json!([]))).and_then(|t| handle_of(&call(&api, t, "get_root", json!([])))).and_then(|t| handle_of(&call(&api, t, "get_gameObject", json!([]))));
            let place = root.and_then(|r| id(&api, r)).and_then(|i| tops.get(&i).cloned());
            let (area, top) = place.unwrap_or(("(kept through loads or none)".into(), "-".into()));
            seen.entry(top).or_default().insert(area);
        }
        if copies.is_empty() {
            continue;
        }
        let line: Vec<String> = seen.iter().map(|(top, a)| format!("{top} [{} areas]", a.len())).collect();
        println!("{class}: {} copies: {}", copies.len(), line.join(", "));
        for top in seen.keys() {
            by_top.entry(top.clone()).or_default().insert(class.clone());
        }
    }
    println!("\nby top object:");
    for (top, cs) in &by_top {
        println!("  {top}: {} classes", cs.len());
    }
}
