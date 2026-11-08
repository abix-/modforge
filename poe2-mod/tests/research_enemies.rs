//! Is what attack aims at a real monster? Attack fired 16 times at a
//! "HedgehogSlow" the operator could not see (2026-11-07). GameHelper2
//! HealthBars skips entities that are not valid (HealthBars.cs:196,
//! Entity.IsValid from EntityHelper.IsValidEntity), which attack's
//! enemy list did not check. This lists every monster path entity with
//! the valid flag, its parts, targetable, life, rarity and buffs, and
//! marks the ones the enemies op takes. Read-only, never clicks.
//!
//! ```text
//! cargo run -p poe2-mod
//! k3sc cargo-lock test -p poe2-mod --test research_enemies -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::json;

#[test]
fn every_monster_and_why_it_counts() {
    let r = Remote::at(17185);
    let list = match r.op("entities", json!({"path": "Metadata/Monsters"})) {
        Ok(l) => l,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let taken = r.op("enemies", json!({})).expect("enemies");
    let taken_keys: Vec<u64> = taken["enemies"]
        .as_array()
        .cloned()
        .unwrap_or_default()
        .iter()
        .map(|e| e["key"].as_u64().unwrap_or(0))
        .collect();
    for e in list["awake"]["entities"].as_array().cloned().unwrap_or_default() {
        let address = e["address"].as_u64().unwrap_or(0);
        let parts = r
            .op("inspect", json!({"addr": format!("{address:#x}")}))
            .map(|v| v["parts"].as_object().map(|o| o.keys().cloned().collect::<Vec<_>>().join(",")).unwrap_or_default())
            .unwrap_or_default();
        println!(
            "{} {} valid {} targetable {} friendly {} life {}/{} rarity {} buffs {} parts [{parts}]",
            if taken_keys.contains(&address) { "TAKEN" } else { "     " },
            e["path"],
            e["valid"],
            e["targetable"],
            e["friendly"],
            e["life"]["health"]["current"],
            e["life"]["health"]["total"],
            e["rarity"],
            e["buffs"],
        );
    }
}
