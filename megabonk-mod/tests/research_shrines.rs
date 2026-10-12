//! What are the shrines and other things you interact with in a run?
//!
//! Read-only. Lists every Assembly-CSharp type named after shrines,
//! interactables, statues, altars, pots or portals, then for each one
//! the number of live instances in the current map and, from the
//! first live one, its plain fields (numbers, text, bools) so its
//! purpose shows: names, descriptions, costs, rewards.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_shrines -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, game_type_names, ping_or_skip};
use serde_json::{Value, json};

const WORDS: [&str; 6] = ["shrine", "interactable", "statue", "altar", "pot", "portal"];
/// Unity plumbing every MonoBehaviour carries; not the thing's own data.
const PLUMBING: [&str; 14] = [
    "hideFlags", "isWrapped", "m_CachedPtr", "pooledPtr", "name", "tag", "transform", "gameObject",
    "enabled", "isActiveAndEnabled", "useGUILayout", "didAwake", "didStart", "destroyCancellationToken",
];

#[test]
fn shrines_and_interactables() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names: Vec<String> = game_type_names(&api)
        .into_iter()
        .filter(|n| {
            let short = n.rsplit('.').next().unwrap_or(n).to_ascii_lowercase();
            WORDS.iter().any(|w| short.contains(w)) && !short.contains("potion") && !short.contains("spot")
        })
        .collect();
    names.sort_unstable();
    println!("\nmatching types ({}):", names.len());
    for n in &names {
        println!("  {n}");
    }

    println!("\n== live in this map");
    for n in &names {
        let list = find_instances(&api, n, false).unwrap_or_default();
        if list.is_empty() {
            continue;
        }
        let mut own = Vec::new();
        if let Some(h) = list[0].get("handle").and_then(Value::as_i64) {
            let f = api.op("inspect_object", json!({"handle": h})).result;
            if let Some(fields) = f["fields"].as_object() {
                for (k, v) in fields {
                    if PLUMBING.contains(&k.as_str()) || v.is_object() || v.as_str().is_some_and(|s| s.starts_with("<getter")) {
                        continue;
                    }
                    own.push(format!("{k}={v}"));
                }
            }
        }
        println!("{n}: {} live | {}", list.len(), own.join(", "));
        for v in &list {
            if let Some(h) = v.get("handle").and_then(Value::as_i64) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
}
