//! What are the flowers on trees that shoot lasers?
//!
//! The operator saw them in play. This test rescans every loaded
//! UClass and prints the ones whose name matches a flower, plant or
//! laser word, with the class each one derives from, so the game's
//! own name for the thing is visible.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_flowers -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

const WORDS: &[&str] = &[
    "flower", "laser", "lazer", "beam", "plant", "bloom", "petal", "pollen", "turret", "tree",
    "vine", "spore", "seed",
];

#[test]
fn flower_classes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op("discover_classes", json!({"refresh": true}));
    let classes = r
        .result
        .get("classes")
        .and_then(|v| v.as_array())
        .cloned()
        .unwrap_or_default();
    println!("classes loaded: {}", classes.len());
    let mut hits = Vec::new();
    for c in &classes {
        let name = c.get("name").and_then(|v| v.as_str()).unwrap_or("");
        let lower = name.to_ascii_lowercase();
        if WORDS.iter().any(|w| lower.contains(w)) {
            let sup = c.get("super_path").and_then(|v| v.as_str()).unwrap_or("?");
            hits.push(format!("{name:<48} <- {sup}"));
        }
    }
    hits.sort();
    println!("{} matching classes:", hits.len());
    for h in &hits {
        println!("  {h}");
    }
}

/// Game content is Blueprint classes, which the native discovery
/// list above does not hold. Every Blueprint class loaded right now
/// is a live `BlueprintGeneratedClass` object; print the ones whose
/// name matches.
#[test]
fn flower_blueprints() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op(
        "walk_class",
        json!({"class": "BlueprintGeneratedClass", "max": 20000, "include_cdo": false}),
    );
    let all = r
        .result
        .get("instances")
        .and_then(|v| v.as_array())
        .cloned()
        .unwrap_or_default();
    println!("blueprint classes loaded: {}", all.len());
    let mut hits: Vec<String> = all
        .iter()
        .filter_map(|i| i.get("name").and_then(|v| v.as_str()))
        .filter(|n| {
            let lower = n.to_ascii_lowercase();
            WORDS.iter().any(|w| lower.contains(w))
        })
        .map(str::to_string)
        .collect();
    hits.sort();
    hits.dedup();
    println!("{} matching blueprints:", hits.len());
    for h in &hits {
        println!("  {h}");
    }
}

/// Live enemies, grouped by class. Found by class-chain needle so
/// the game's own base class names decide what counts.
#[test]
fn live_enemies() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for needle in ["Enemy", "Monster", "Creature", "AI", "Turret", "Sentry"] {
        let r = api.op("walk_class_chain", json!({"needle": needle, "max": 5000}));
        let mut counts: std::collections::BTreeMap<String, usize> = Default::default();
        for i in r
            .result
            .get("instances")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
        {
            let full = i.get("full_name").and_then(|v| v.as_str()).unwrap_or("?");
            let class = full.split(' ').next().unwrap_or("?").to_string();
            *counts.entry(class).or_default() += 1;
        }
        println!("== needle {needle}: {} classes", counts.len());
        for (c, n) in &counts {
            println!("   {n:>5}  {c}");
        }
    }
}

/// The Looker: the only live enemy whose name fits a thing that
/// sits and watches. Print its parents, where the live ones are,
/// and every function and component its Blueprint owns, so its
/// attack is named by the game.
#[test]
fn looker() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let bps = api.op(
        "walk_class",
        json!({"class": "BlueprintGeneratedClass", "max": 20000, "include_cdo": false}),
    );
    let all = bps
        .result
        .get("instances")
        .and_then(|v| v.as_array())
        .cloned()
        .unwrap_or_default();
    for i in &all {
        let name = i.get("name").and_then(|v| v.as_str()).unwrap_or("");
        if !name.to_ascii_lowercase().contains("looker") {
            continue;
        }
        let addr = i
            .get("addr")
            .and_then(|a| a.as_str())
            .and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok());
        println!(
            "== {name}  parents: {}",
            addr.map(|a| super_chain(&api, a).join(" <- "))
                .unwrap_or_default()
        );
    }
    for class in ["Looker_Base_BP_C", "Looker_Trap_BP_C"] {
        let r = api.op("walk_class", json!({"class": class, "max": 3}));
        println!(
            "== live {class}: {}",
            r.result.get("total").and_then(|v| v.as_u64()).unwrap_or(0)
        );
        for i in r
            .result
            .get("instances")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
        {
            println!(
                "     {}",
                i.get("full_name").and_then(|v| v.as_str()).unwrap_or("?")
            );
        }
    }
    // Functions live under the Blueprint class as their outer, so
    // their full names carry "Looker". ActorComponent was tried
    // too: every live component is over the 10 MB response limit.
    for kind in ["Function"] {
        let r = api.op(
            "walk_class",
            json!({"class": kind, "max": 200000, "include_cdo": true}),
        );
        let mut names: Vec<String> = r
            .result
            .get("instances")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
            .filter_map(|i| i.get("full_name").and_then(|v| v.as_str()))
            .filter(|f| f.contains("Looker_Base_BP") && !f.contains("PersistentLevel"))
            .map(str::to_string)
            .collect();
        names.sort();
        println!("== {kind} under Looker_Base_BP: {}", names.len());
        for n in &names {
            println!("     {n}");
        }
    }
}

/// Why are some Lookers open and shooting and others closed? Print
/// the fields of the Looker and its enemy base classes, then read
/// every 1-byte and 4-byte field on each live Looker, so the fields
/// that differ between open and closed ones stand out. 4-byte values
/// print as both f32 and i32 since the dump carries no type.
#[test]
fn looker_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut fields: Vec<(String, String, u64, u64)> = Vec::new();
    for class in ["Looker_Base_BP_C", "EnemyBase_C", "FS_EnemyCharacterBase"] {
        let r = api.op("discover_class_detail", json!({"name": class}));
        let list = r
            .result
            .get("fields")
            .and_then(|v| v.as_array())
            .cloned()
            .unwrap_or_default();
        println!("== {class}: {} fields", list.len());
        for f in &list {
            let name = f.get("name").and_then(|v| v.as_str()).unwrap_or("?");
            let off = f.get("offset").and_then(|v| v.as_u64()).unwrap_or(0);
            let size = f.get("element_size").and_then(|v| v.as_u64()).unwrap_or(0);
            println!("   +{off:#06x} {size:>3}  {name}");
            if size == 1 || size == 4 {
                fields.push((class.to_string(), name.to_string(), off, size));
            }
        }
    }
    let r = api.op("walk_class", json!({"class": "Looker_Base_BP_C", "max": 64}));
    let lookers: Vec<(u64, String)> = r
        .result
        .get("instances")
        .and_then(|v| v.as_array())
        .into_iter()
        .flatten()
        .filter_map(|i| {
            let a = i.get("addr")?.as_str()?;
            let n = i.get("name")?.as_str()?.to_string();
            Some((u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()?, n))
        })
        .collect();
    println!("== {} live Lookers", lookers.len());
    if lookers.is_empty() {
        println!("no Lookers loaded; stand where some are and rerun");
        return;
    }
    let max_off = fields.iter().map(|f| f.2 + f.3).max().unwrap_or(0);
    let mem: Vec<Vec<u8>> = lookers
        .iter()
        .map(|(a, _)| modforge::client::read_bytes(&api, *a, 0, max_off))
        .collect();
    // Only fields whose value is not the same on every Looker.
    for (class, name, off, size) in &fields {
        let (o, s) = (*off as usize, *size as usize);
        let vals: Vec<String> = mem
            .iter()
            .map(|b| {
                if b.len() < o + s {
                    return "?".to_string();
                }
                if s == 1 {
                    format!("{}", b[o])
                } else {
                    let raw: [u8; 4] = b[o..o + 4].try_into().unwrap();
                    let f = f32::from_le_bytes(raw);
                    let i = i32::from_le_bytes(raw);
                    if f.is_finite() && f.abs() > 1e-6 && f.abs() < 1e7 {
                        format!("{f}")
                    } else {
                        format!("{i}")
                    }
                }
            })
            .collect();
        let first = &vals[0];
        if vals.iter().all(|v| v == first) {
            continue;
        }
        println!("   {class}.{name}: {}", vals.join(" "));
    }
}

/// The Blueprints from `flower_blueprints` that could be a flower
/// that shoots. For each: the parent class chain (read from
/// UStruct::SuperStruct, +0x40 on UE 4.27) and how many live
/// objects of it exist right now, with their level paths.
const CANDIDATES: &[&str] = &[
    "Vineshroom_BP_C",
    "Vineshroom_Projectile_BP_C",
    "Vineshroom_Visuals_C",
    "SZ_BulbPlant_BP_C",
    "SG_LightFlower_00_BP_C",
    "SG_LightFlower_WK_BP_C",
];

fn super_chain(api: &modforge::client::Api<serde_json::Value>, class_addr: u64) -> Vec<String> {
    let mut out = Vec::new();
    let mut p = class_addr;
    for _ in 0..12 {
        let b = modforge::client::read_bytes(api, p, 0, 0x48);
        if b.len() < 0x48 {
            break;
        }
        let sup = modforge::client::from_le_u64(&b, 0x40);
        if sup == 0 {
            break;
        }
        let sb = modforge::client::read_bytes(api, sup, 0, 0x20);
        if sb.len() < 0x20 {
            break;
        }
        let fname = modforge::client::from_le_u64(&sb, 0x18);
        let r = api.op("fname_to_string", json!({"fname": fname}));
        out.push(
            r.result
                .get("string")
                .and_then(|s| s.as_str())
                .unwrap_or("?")
                .to_string(),
        );
        p = sup;
    }
    out
}

#[test]
fn candidate_details() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let bps = api.op(
        "walk_class",
        json!({"class": "BlueprintGeneratedClass", "max": 20000, "include_cdo": false}),
    );
    let all = bps
        .result
        .get("instances")
        .and_then(|v| v.as_array())
        .cloned()
        .unwrap_or_default();
    for name in CANDIDATES {
        println!("== {name}");
        let addr = all
            .iter()
            .find(|i| i.get("name").and_then(|v| v.as_str()) == Some(name))
            .and_then(|i| i.get("addr").and_then(|a| a.as_str()))
            .and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok());
        match addr {
            Some(a) => println!("   parents: {}", super_chain(&api, a).join(" <- ")),
            None => println!("   class not loaded"),
        }
        let r = api.op("walk_class", json!({"class": name, "max": 5}));
        let total = r.result.get("total").and_then(|v| v.as_u64()).unwrap_or(0);
        println!("   live objects: {total}");
        for i in r
            .result
            .get("instances")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
        {
            println!(
                "     {}",
                i.get("full_name").and_then(|v| v.as_str()).unwrap_or("?")
            );
        }
    }
}
