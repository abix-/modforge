//! What each shrine pays out, to rank them by value.
//!
//! Read-only. research_shrines.rs (2026-10-03) said what each
//! interactable is but not what it gives. This prints, for each shrine
//! class, its declared methods and every field of its first live
//! instance (objects shown as their type), and every type named after
//! encounters, rewards or offers, with the fields of their first live
//! instance.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_shrine_rewards -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, game_type_names, ping_or_skip, print_declared_methods};
use serde_json::{Value, json};
use unityforge::client::Api;

const PLUMBING: [&str; 14] = [
    "hideFlags", "isWrapped", "m_CachedPtr", "pooledPtr", "name", "tag", "transform", "gameObject",
    "enabled", "isActiveAndEnabled", "useGUILayout", "didAwake", "didStart", "destroyCancellationToken",
];

fn first_fields(api: &Api<Value>, class: &str) {
    let list = find_instances(api, class, true).unwrap_or_default();
    println!("  live: {}", list.len());
    if let Some(h) = list.first().and_then(|v| v.get("handle")).and_then(Value::as_i64) {
        let f = api.op("inspect_object", json!({"handle": h})).result;
        if let Some(fields) = f["fields"].as_object() {
            for (k, v) in fields {
                if PLUMBING.contains(&k.as_str()) || v.as_str().is_some_and(|s| s.starts_with("<getter")) {
                    continue;
                }
                let shown = v.get("il2cpp_type").and_then(Value::as_str).map(|t| format!("<{t}>")).unwrap_or_else(|| v.to_string());
                println!("    {k} = {shown}");
            }
        }
    }
    for v in &list {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            api.op("release_handle", json!({"handle": h}));
        }
    }
}

fn call(api: &Api<Value>, h: i64, method: &str) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": []})).result
}

fn fields_of(api: &Api<Value>, h: i64) -> String {
    let f = api.op("inspect_object", json!({"handle": h})).result;
    let mut out = Vec::new();
    if let Some(fields) = f["fields"].as_object() {
        for (k, v) in fields {
            if PLUMBING.contains(&k.as_str()) || v.as_str().is_some_and(|s| s.starts_with("<getter")) {
                continue;
            }
            out.push(format!("{k}={}", v.get("str").cloned().unwrap_or_else(|| v.clone())));
        }
    }
    out.join(", ")
}

/// The game's own words and numbers for each shrine: the text it shows
/// when you walk up (GetInteractString, a getter), the greed shrine's
/// stat effect, and the EncounterData assets' offers (reward choices).
#[test]
fn shrine_texts() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Il2Cpp.ChargeShrine",
        "Il2Cpp.InteractableShrineGreed",
        "Il2Cpp.InteractableShrineChallenge",
        "Il2Cpp.InteractableShrineMagnet",
        "Il2Cpp.InteractableShrineMoai",
        "Il2Cpp.InteractableShrineCursed",
        "Il2Cpp.InteractableShrineBalance",
        "Il2Cpp.InteractableMicrowave",
        "Il2Cpp.InteractableShadyGuy",
        "Il2Cpp.InteractablePot",
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Chests.InteractableChest",
    ] {
        let list = find_instances(&api, class, true).unwrap_or_default();
        if let Some(h) = list.first().and_then(|v| v.get("handle")).and_then(Value::as_i64) {
            println!("{class}: says {} | debug name {}", call(&api, h, "GetInteractString"), call(&api, h, "GetDebugName"));
            if class.ends_with("Greed")
                && let Some(e) = api.op("read_field", json!({"handle": h, "field": "statEffect"})).result.get("handle").and_then(Value::as_i64)
            {
                println!("  statEffect: {}", fields_of(&api, e));
            }
        }
        for v in &list {
            if let Some(h) = v.get("handle").and_then(Value::as_i64) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }

    // The amounts are rolled at use, so read what the game recorded:
    // ShrineLogs and its entries (5 live on 2026-10-03), each entry's
    // fields and the text of every text field it holds.
    println!("\n== shrine log");
    for class in ["Il2Cpp.ShrineLogs", "Il2Cpp.ShrineLogEntry"] {
        println!("-- {class}");
        common::print_declared_methods(&api, class);
        for v in find_instances(&api, class, true).unwrap_or_default() {
            let Some(h) = v.get("handle").and_then(Value::as_i64) else { continue };
            println!("  {}", fields_of(&api, h));
            let f = api.op("inspect_object", json!({"handle": h})).result;
            if let Some(fields) = f["fields"].as_object() {
                for (k, val) in fields {
                    if val.get("il2cpp_type").and_then(Value::as_str).is_some_and(|t| t.contains("TextMeshPro"))
                        && let Some(t) = val.get("handle").and_then(Value::as_i64)
                    {
                        println!("    {k}: {}", call(&api, t, "get_text"));
                    }
                }
            }
        }
    }

    println!("\n== EncounterData offers");
    for v in find_instances(&api, "Il2CppAssets.Scripts.UI.InGame.Rewards.EncounterData", true).unwrap_or_default() {
        let Some(d) = v.get("handle").and_then(Value::as_i64) else { continue };
        println!("EncounterData: {}", fields_of(&api, d));
        if let Some(offers) = api.op("read_field", json!({"handle": d, "field": "offers"})).result.get("handle").and_then(Value::as_i64) {
            let n = common::count_of(&api, offers).unwrap_or(0);
            for i in 0..n {
                let item = api.op("invoke_method", json!({"handle": offers, "method": "get_Item", "args": [i]})).result;
                if let Some(o) = item.get("handle").and_then(Value::as_i64) {
                    println!("  offer {i}: {}", fields_of(&api, o));
                }
            }
        }
    }
}

#[test]
fn shrine_rewards() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Il2Cpp.ChargeShrine",
        "Il2Cpp.InteractableShrineGreed",
        "Il2Cpp.InteractableShrineChallenge",
        "Il2Cpp.InteractableShrineMagnet",
        "Il2Cpp.InteractableShrineMoai",
        "Il2Cpp.InteractableShrineCursed",
        "Il2Cpp.InteractableShrineBalance",
        "Il2Cpp.InteractableMicrowave",
        "Il2Cpp.InteractableShadyGuy",
    ] {
        println!("\n== {class}");
        print_declared_methods(&api, class);
        first_fields(&api, class);
    }

    let mut names: Vec<String> = game_type_names(&api)
        .into_iter()
        .filter(|n| {
            let short = n.rsplit('.').next().unwrap_or(n).to_ascii_lowercase();
            ["encounter", "reward", "offer"].iter().any(|w| short.contains(w))
        })
        .collect();
    names.sort_unstable();
    println!("\n== types named after encounters, rewards, offers ({})", names.len());
    for n in &names {
        println!("\n-- {n}");
        first_fields(&api, n);
    }
}
