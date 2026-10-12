//! Every weapon in the game and what the player holds.
//!
//! Read-only. Every live WeaponData asset's plain fields (name,
//! description, numbers), and the player's WeaponInventory fields.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_weapons -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, handle_of, ping_or_skip};
use serde_json::{Value, json};

const PLUMBING: [&str; 14] = [
    "hideFlags", "isWrapped", "m_CachedPtr", "pooledPtr", "name", "tag", "transform", "gameObject",
    "enabled", "isActiveAndEnabled", "useGUILayout", "didAwake", "didStart", "destroyCancellationToken",
];

fn plain(api: &unityforge::client::Api<Value>, h: i64) -> String {
    let f = api.op("inspect_object", json!({"handle": h})).result;
    let mut out = Vec::new();
    if let Some(fields) = f["fields"].as_object() {
        for (k, v) in fields {
            if PLUMBING.contains(&k.as_str()) || v.is_object() || v.is_null() || v.as_str().is_some_and(|s| s.starts_with("<getter")) {
                continue;
            }
            out.push(format!("{k}={v}"));
        }
    }
    out.join(", ")
}

#[test]
fn weapons() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    println!("== WeaponData assets");
    for v in find_instances(&api, "WeaponData", true).unwrap_or_default() {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            println!("  {}", plain(&api, h));
            api.op("release_handle", json!({"handle": h}));
        }
    }
    // UnlockUtility.GetAvailableWeapons() -> List<WeaponData>: the
    // weapons this save has available (research_unlocks.rs, 2026-10-03).
    println!("\n== available (unlocked) weapons");
    let avail = api.op(
        "invoke_static",
        json!({"class": "Il2CppAssets.Scripts.Inventory__Items__Pickups.Progression.UnlockUtility", "method": "GetAvailableWeapons", "args": []}),
    );
    match handle_of(&avail.result) {
        Some(list) => {
            let n = common::count_of(&api, list).unwrap_or(0);
            let mut names = Vec::new();
            for i in 0..n {
                if let Some(w) = handle_of(&api.op("invoke_method", json!({"handle": list, "method": "get_Item", "args": [i]})).result) {
                    names.push(
                        api.op("read_field", json!({"handle": w, "field": "_damageSourceName_k__BackingField"}))
                            .result
                            .as_str()
                            .unwrap_or("?")
                            .to_string(),
                    );
                }
            }
            names.sort_unstable();
            println!("  {n}: {}", names.join(", "));
        }
        None => println!("  GetAvailableWeapons: {} {:?}", avail.result, avail.error),
    }

    // Characters: each CharacterData asset's plain fields and the
    // weapon it starts with, to match the pick to the character.
    println!("\n== characters");
    for v in find_instances(&api, "CharacterData", true).unwrap_or_default() {
        let Some(h) = v.get("handle").and_then(Value::as_i64) else { continue };
        let f = api.op("inspect_object", json!({"handle": h})).result;
        let weapon = f["fields"]
            .as_object()
            .and_then(|o| o.iter().find(|(k, _)| k.to_ascii_lowercase().contains("weapon")))
            .map(|(k, val)| {
                let name = handle_of(val)
                    .map(|w| api.op("read_field", json!({"handle": w, "field": "_damageSourceName_k__BackingField"})).result)
                    .unwrap_or(Value::Null);
                format!("{k}={}", if name.is_null() { val.to_string() } else { name.to_string() })
            })
            .unwrap_or_default();
        println!("  {} | {weapon}", plain(&api, h));
        api.op("release_handle", json!({"handle": h}));
    }

    println!("\n== player's WeaponInventory");
    let call = |h: i64, m: &str| api.op("invoke_method", json!({"handle": h, "method": m, "args": []})).result;
    let gm = handle_of(&api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []})).result)
        .expect("GameManager.Instance");
    let player = handle_of(&call(gm, "get_player")).expect("player (start a run first)");
    let inv = handle_of(&call(player, "get_inventory")).expect("inventory");
    let weapons = handle_of(&call(inv, "get_weaponInventory")).expect("weaponInventory");
    println!("  {}", api.op("inspect_object", json!({"handle": weapons})).result["fields"]);
}
