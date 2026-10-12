//! Where the game keeps what is unlocked.
//!
//! Read-only. Lists every Assembly-CSharp type named after unlocks,
//! and the declared methods of each whose name says unlocked, locked
//! or available, with parameter types.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_unlocks -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, game_type_names, parameters, ping_or_skip};
use serde_json::{Value, json};

#[test]
fn unlock_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names: Vec<String> = game_type_names(&api)
        .into_iter()
        .filter(|n| n.rsplit('.').next().unwrap_or(n).to_ascii_lowercase().contains("unlock"))
        .collect();
    names.sort_unstable();
    println!("\ntypes named after unlocks ({}):", names.len());
    for n in &names {
        println!("  {n}");
    }
    for n in &names {
        let interop = if n.contains('.') { format!("Il2Cpp{n}") } else { format!("Il2Cpp.{n}") };
        let r = api.op("list_methods", json!({"class": interop}));
        let empty = vec![];
        let hits: Vec<String> = r.result["methods"]
            .as_array()
            .unwrap_or(&empty)
            .iter()
            .filter_map(|m: &Value| m["name"].as_str().map(str::to_string))
            .filter(|m| {
                let l = m.to_ascii_lowercase();
                (l.contains("unlock") || l.contains("locked") || l.contains("available")) && !l.starts_with("set_")
            })
            .collect();
        if hits.is_empty() {
            continue;
        }
        println!("\n== {n}");
        let mut seen = std::collections::BTreeSet::new();
        for m in hits {
            if seen.insert(m.clone()) {
                parameters(&api, n, &m);
            }
        }
    }
}
