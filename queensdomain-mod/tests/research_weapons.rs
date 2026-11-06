//! How do weapons level up: from damage dealt, or from kills?
//!
//! Prints, read live:
//! - every loaded Blueprint class whose name says weapon, xp or
//!   level-up, with its parents,
//! - their fields whose names mention xp, level, kill or damage,
//! - the player character's fields about weapons, xp and levels,
//! - functions on those classes that mention xp or level,
//! - the loaded data tables.
//!
//! EnemyData_C already carries XPReward (10 on a Looker) and
//! EnemyBase_C carries SkipXPReward, see research_aggro.rs.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_weapons -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, fields, instances, ping_or_skip};
use serde_json::json;

const WORDS: &[&str] = &["xp", "exp", "level", "kill", "damage", "upgrade", "rank", "mastery"];

fn matches(name: &str, words: &[&str]) -> bool {
    let l = name.to_ascii_lowercase();
    words.iter().any(|w| l.contains(w))
}

fn functions(api: &modforge::client::Api<serde_json::Value>, class: &str) -> Vec<String> {
    let r = api.op("discover_class_detail", json!({"name": class}));
    r.result
        .get("functions")
        .and_then(|v| v.as_array())
        .into_iter()
        .flatten()
        .filter_map(|f| f.get("name").and_then(|v| v.as_str()).map(str::to_string))
        .collect()
}

/// The fast half: no per-class object scans. Fields and functions
/// about xp, levels, kills and damage on the player, the weapon
/// system component, the weapon script base, and the enemy base
/// classes (who hands XP out, and when).
#[test]
fn weapon_xp_owners() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let words = ["weapon", "xp", "exp", "level", "kill", "reward", "die", "death", "damage"];
    for class in [
        "FS_PlayerChar_C",
        "FS_PlayerCharacter",
        "WeaponSystem_C",
        "WeaponScriptBase_C",
        "EnemyBase_C",
        "FS_EnemyCharacterBase",
        "EnemyData_C",
    ] {
        println!("== {class}");
        for f in fields(&api, class) {
            if matches(&f.0, &words) {
                println!("   field {} +{:#x} ({})", f.0, f.1, f.2);
            }
        }
        for f in functions(&api, class) {
            if matches(&f, &words) {
                println!("   fn {f}");
            }
        }
    }
}

#[test]
fn weapon_xp() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let bps = instances(&api, "BlueprintGeneratedClass", 20000);
    let classes: Vec<(u64, String)> = bps
        .into_iter()
        .filter(|(_, n)| {
            let l = n.to_ascii_lowercase();
            (l.contains("weapon") || l.contains("xp") || l.contains("levelup") || l.contains("level_up"))
                && !l.contains("anim")
        })
        .collect();
    println!("== {} weapon / xp classes", classes.len());
    for (addr, name) in &classes {
        let parents = common::super_chain(&api, *addr);
        let fs: Vec<String> = fields(&api, name)
            .into_iter()
            .filter(|f| matches(&f.0, WORDS))
            .map(|f| format!("{}(+{:#x},{})", f.0, f.1, f.2))
            .collect();
        let fns: Vec<String> = functions(&api, name)
            .into_iter()
            .filter(|f| matches(f, &["xp", "exp", "level", "kill"]))
            .collect();
        let live = instances(&api, name, 1).len();
        println!(
            "-- {name} <- {}  live:{live}",
            parents.first().cloned().unwrap_or_default()
        );
        if !fs.is_empty() {
            println!("   fields: {}", fs.join(" "));
        }
        if !fns.is_empty() {
            println!("   functions: {}", fns.join(", "));
        }
    }

    println!("== player");
    for class in ["FS_PlayerChar_C", "FS_PlayerCharacter"] {
        for f in fields(&api, class) {
            if matches(&f.0, &["weapon", "xp", "exp", "level", "kill"]) {
                println!("   {class}.{} +{:#x} ({})", f.0, f.1, f.2);
            }
        }
        for f in functions(&api, class) {
            if matches(&f, &["weapon", "xp", "exp", "level", "kill"]) {
                println!("   {class} fn {f}");
            }
        }
    }
    for class in ["EnemyBase_C", "FS_EnemyCharacterBase"] {
        for f in functions(&api, class) {
            if matches(&f, &["xp", "exp", "kill", "die", "death", "reward"]) {
                println!("   {class} fn {f}");
            }
        }
    }

    let r = api.op("discover_data_tables", json!({}));
    println!("== data tables: {}", serde_json::to_string(&r.result).unwrap_or_default().chars().take(2000).collect::<String>());
}
