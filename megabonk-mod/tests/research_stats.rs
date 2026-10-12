//! Where the player's luck stat is stored.
//!
//! No type is named after luck (research_luck.rs, 2026-10-03: 0 of
//! 1220), and the game shows luck as a stat (1% on the stats screen),
//! so it is a value inside the stat system. Read-only, and kept apart
//! from the type walk in research_luck.rs (the game died during that
//! walk once on 2026-10-03), so this makes only a few dozen calls:
//! - the values of the stat and rarity enums, through the runtime's
//!   own Enum.GetNames (walk_class lists none for an enum), index i
//!   being value i for a plain enum
//! - the player stat classes' declared methods
//! - every field of their live instances
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_stats -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, count_of, find_instances, handle_of, ping_or_skip, print_declared_methods};
use serde_json::{Value, json};

#[test]
fn stat_system() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // ETome: luck_check.rs (2026-10-03) found TomeInventory.statToTomes
    // (EStat -> tomes); a luck tome is the likely in-game luck that made
    // added luck count in run 1.
    println!("\n== Il2CppAssets.Scripts.Inventory__Items__Pickups.TomeInventory methods");
    print_declared_methods(&api, "Il2CppAssets.Scripts.Inventory__Items__Pickups.TomeInventory");
    for class in [
        // StatModifier.modifyType; StatComponents has AddFlat,
        // AddAdditive and AddMultiplier, and final luck is base x
        // additive (luck_math.rs, 2026-10-03).
        "Assets.Scripts.Inventory__Items__Pickups.Stats.EStatModifyType",
        "Assets.Scripts._Data.Tomes.ETome",
        "Assets.Scripts.Menu.Shop.EStat",
        "Assets.Scripts.Inventory__Items__Pickups.ERarity",
        "Assets.Scripts.Inventory__Items__Pickups.Items.EItemRarity",
    ] {
        println!("\n== {class} values");
        let ty = api.op(
            "invoke_static",
            json!({"class": "Il2CppSystem.Type", "method": "GetType", "args": [format!("{class}, Assembly-CSharp")]}),
        );
        let Some(ty_h) = handle_of(&ty.result) else {
            println!("  Type.GetType carried no handle: ok={} result={} error={:?}", ty.ok, ty.result, ty.error);
            continue;
        };
        let names = api.op(
            "invoke_static",
            json!({"class": "Il2CppSystem.Enum", "method": "GetNames", "args": [{"$handle": ty_h}]}),
        );
        match handle_of(&names.result) {
            Some(seq) => {
                let n = count_of(&api, seq).unwrap_or(0);
                for i in 0..n {
                    let item = api.op(
                        "invoke_method",
                        json!({"handle": seq, "method": "get_Item", "args": [i]}),
                    );
                    println!("  {i} = {}", item.result);
                }
                api.op("release_handle", json!({"handle": seq}));
            }
            None => println!("  GetNames: ok={} result={} error={:?}", names.ok, names.result, names.error),
        }
        api.op("release_handle", json!({"handle": ty_h}));
    }
    // EStat 30 is Luck (the values above, 2026-10-03). PlayerStats
    // declares static GetStat / GetStatRaw(EStat) -> float.
    const PLAYER_STATS: &str = "Il2CppAssets.Scripts.Inventory.Stats.PlayerStats";
    let has = api.op("invoke_static", json!({"class": PLAYER_STATS, "method": "HasStats", "args": []}));
    println!("\nPlayerStats.HasStats = {} (ok={} {:?})", has.result, has.ok, has.error);
    for method in ["GetStat", "GetStatRaw"] {
        let r = api.op("invoke_static", json!({"class": PLAYER_STATS, "method": method, "args": [30]}));
        println!("PlayerStats.{method}(Luck) = {} (ok={} {:?})", r.result, r.ok, r.error);
    }

    for class in [
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.PlayerStatsNew",
        "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatInventory",
        "Il2CppAssets.Scripts.Inventory.Stats.PlayerStats",
    ] {
        println!("\n== {class} methods");
        print_declared_methods(&api, class);
        println!("\n== {class} live instances");
        let list = find_instances(&api, class, true).unwrap_or_default();
        println!("  {} instance(s)", list.len());
        for v in list.iter().take(2) {
            let Some(h) = v.get("handle").and_then(Value::as_i64) else {
                continue;
            };
            let r = api.op("inspect_object", json!({"handle": h}));
            println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
        }
        for v in &list {
            if let Some(h) = v.get("handle").and_then(Value::as_i64) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
}
