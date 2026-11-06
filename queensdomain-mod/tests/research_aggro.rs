//! How does a Looker build aggro on the player, and what lowers it?
//!
//! The operator wants to keep Lookers from aggroing. This test
//! prints the game's own aggro settings, read live:
//!
//! - a normal (not trap) Looker's aggro and sight fields on
//!   EnemyBase_C,
//! - the EnemyData_C it points at (+0x728 Data),
//! - its EnemyLineOfSightComponent (+0x620 EnemyLineOfSight),
//! - every EnemyAwarenessProfile,
//! - the player character's fields about stealth, noise, light or
//!   being seen.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_aggro -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, class_of, dump, instances, ping_or_skip, super_chain};

const AGGRO_WORDS: &[&str] = &[
    "aggro", "sight", "los", "seen", "chase", "range", "sensitiv", "aware", "height", "trap",
    "behaviour",
];

const PLAYER_WORDS: &[&str] = &[
    "stealth", "sneak", "crouch", "noise", "loud", "light", "visib", "seen", "aggro", "detect",
    "hidden", "hide", "aware", "dark", "torch", "lantern",
];

#[test]
fn aggro_config() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let lookers = instances(&api, "Looker_Base_BP_C", 64);
    let looker = lookers.iter().find(|(a, _)| {
        let b = modforge::client::read_bytes(&api, *a, 0x8C6, 1);
        b.first() == Some(&0)
    });
    let Some((looker, name)) = looker else {
        println!("no normal Looker loaded; stand where some are and rerun");
        return;
    };
    println!("== Looker {name}");
    dump(&api, *looker, "EnemyBase_C", Some(AGGRO_WORDS));

    let head = modforge::client::read_bytes(&api, *looker, 0x620, 0x110);
    let los = modforge::client::from_le_u64(&head, 0);
    let data = modforge::client::from_le_u64(&head, 0x728 - 0x620);
    for (label, p) in [("Data", data), ("EnemyLineOfSight", los)] {
        if p == 0 {
            println!("== {label}: null");
            continue;
        }
        let class = class_of(&api, p);
        println!("== {label} -> {class}");
        dump(&api, p, &class, None);
    }

    let profiles = instances(&api, "EnemyAwarenessProfile", 64);
    println!("== {} EnemyAwarenessProfile", profiles.len());
    for (p, n) in &profiles {
        println!("   {n}");
        dump(&api, *p, "EnemyAwarenessProfile", None);
    }

    aggro_cones(&api, &profiles);

    let players = instances(&api, "FS_Full_PlayerChar_C", 4);
    let Some((player, _)) = players.first() else {
        println!("no player character loaded");
        return;
    };
    let cls = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, *player, 0x10, 8), 0);
    let mut chain = vec![common::object_name(&api, cls)];
    chain.extend(super_chain(&api, cls));
    println!("== player chain: {}", chain.join(" <- "));
    for c in chain.iter().take_while(|c| c.as_str() != "Character") {
        dump(&api, *player, c, Some(PLAYER_WORDS));
    }
}

/// EnemyAwarenessProfile::AggroCones (+0x38) is a TArray of a
/// struct. Find the struct by name, then print every cone of the
/// Looker's profile and of the default one for comparison.
fn aggro_cones(api: &modforge::client::Api<serde_json::Value>, profiles: &[(u64, String)]) {
    use serde_json::json;
    let structs = instances(api, "ScriptStruct", 20000);
    let mut cone: Option<(u64, String)> = None;
    for (addr, name) in &structs {
        let l = name.to_ascii_lowercase();
        if !(l.contains("cone") || l.contains("aggro") || l.contains("awareness")) {
            continue;
        }
        let size = i32::from_le_bytes(
            modforge::client::read_bytes(api, *addr, 0x58, 4)[..4]
                .try_into()
                .unwrap(),
        );
        println!("== struct {name} size {size:#x}");
        let r = api.op("discover_struct_detail", json!({"name": name}));
        for f in r
            .result
            .get("fields")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
        {
            println!(
                "   +{:#06x} {:>3} {:<16} {}",
                f.get("offset").and_then(|v| v.as_u64()).unwrap_or(0),
                f.get("element_size").and_then(|v| v.as_u64()).unwrap_or(0),
                f.get("class").and_then(|v| v.as_str()).unwrap_or("?"),
                f.get("name").and_then(|v| v.as_str()).unwrap_or("?"),
            );
        }
        // FS_AwarenessCone, not the physics ConeConstraint.
        if l.contains("awarenesscone") {
            cone = Some((size as u64, name.clone()));
        }
    }
    let Some((stride, sname)) = cone else {
        println!("no cone struct found");
        return;
    };
    let r = api.op("discover_struct_detail", json!({"name": sname}));
    let sfields: Vec<(String, u64, u64)> = r
        .result
        .get("fields")
        .and_then(|v| v.as_array())
        .into_iter()
        .flatten()
        .filter_map(|f| {
            Some((
                f.get("name")?.as_str()?.to_string(),
                f.get("offset")?.as_u64()?,
                f.get("element_size")?.as_u64()?,
            ))
        })
        .collect();
    for (p, n) in profiles {
        if n != "Looker_AwarenessProfile" && n != "DefaultAwareness" {
            continue;
        }
        let arr = modforge::client::read_bytes(api, *p, 0x38, 16);
        let data = modforge::client::from_le_u64(&arr, 0);
        let num = i32::from_le_bytes(arr[8..12].try_into().unwrap()).clamp(0, 32) as u64;
        println!("== {n}: {num} cones ({sname}, stride {stride:#x})");
        for i in 0..num {
            let b = modforge::client::read_bytes(api, data + i * stride, 0, stride);
            let vals: Vec<String> = sfields
                .iter()
                .map(|(fname, off, size)| format!("{fname}={}", common::show(api, &b, *off, *size)))
                .collect();
            println!("   cone {i}: {}", vals.join("  "));
        }
    }
}
