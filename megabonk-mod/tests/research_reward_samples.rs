//! Sample what shrine rewards pay, by calling the game's own generators.
//!
//! Read 2026-10-03 (research_rewards.rs):
//! - `Rarity.GetMultiplier(ERarity) -> float`
//! - `Rarity.GetEncounterOfferRarity(float luck) -> ERarity`
//! - `EncounterUtility.GetRandomStatOffers(int amount, bool forceLegendary,
//!   bool useShrineStats) -> List<EncounterOffer>`
//! - `EncounterUtility.GetBalanceShrineOffers(int amount) -> List<EncounterOffer>`
//!
//! These build offers and grant nothing: no ChangeStat, no window. This
//! prints the multiplier per rarity, the rarity spread over 200 rolls at
//! luck 0 and 5, and 10 samples of each offer list with every effect's
//! stat, amount and type.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_reward_samples -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, count_of, enum_names, handle_of, ping_or_skip};
use serde_json::{Value, json};
use std::collections::BTreeMap;
use unityforge::client::Api;

const RARITY: &str = "Il2CppAssets.Scripts.Inventory__Items__Pickups.Rarity";
const ENCOUNTERS: &str = "Il2CppAssets.Scripts.Inventory__Items__Pickups.Upgrades.EncounterUtility";

fn stat(api: &Api<Value>, class: &str, method: &str, args: Value) -> Value {
    let r = api.op("invoke_static", json!({"class": class, "method": method, "args": args}));
    if !r.ok {
        println!("  {method} failed: {:?}", r.error);
    }
    r.result
}

fn field(api: &Api<Value>, h: i64, name: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": name})).result
}

fn item(api: &Api<Value>, seq: i64, i: i64) -> Option<i64> {
    handle_of(&api.op("invoke_method", json!({"handle": seq, "method": "get_Item", "args": [i]})).result)
}

/// One offer list: each offer's rarity and its effects (stat, amount, type).
fn show_offers(api: &Api<Value>, list: &Value, stats: &[String], rarities: &[String]) -> String {
    let Some(l) = handle_of(list) else { return format!("no list: {list}") };
    let mut out = Vec::new();
    for i in 0..count_of(api, l).unwrap_or(0) {
        let Some(o) = item(api, l, i) else { continue };
        let r = field(api, o, "rarity").as_i64().unwrap_or(-1);
        let mut effects = Vec::new();
        if let Some(es) = handle_of(&field(api, o, "effects")) {
            for j in 0..count_of(api, es).unwrap_or(0) {
                let Some(e) = item(api, es, j) else { continue };
                let kind = field(api, e, "effectType");
                let value = field(api, e, "value");
                let m = handle_of(&field(api, e, "statModifier"));
                let detail = m.map(|m| {
                    let s = field(api, m, "stat").as_i64().unwrap_or(-1);
                    format!(
                        "{} {} type {}",
                        stats.get(s as usize).map(String::as_str).unwrap_or("?"),
                        field(api, m, "modification"),
                        field(api, m, "modifyType")
                    )
                });
                effects.push(format!("[effect {kind} value {value} {}]", detail.unwrap_or_default()));
                api.op("release_handle", json!({"handle": e}));
            }
        }
        out.push(format!("{}: {}", rarities.get(r as usize).map(String::as_str).unwrap_or("?"), effects.join(" ")));
        api.op("release_handle", json!({"handle": o}));
    }
    api.op("release_handle", json!({"handle": l}));
    out.join(" | ")
}

#[test]
fn reward_samples() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let rarities = enum_names(&api, "Assets.Scripts.Inventory__Items__Pickups.ERarity");
    let stats = enum_names(&api, "Assets.Scripts.Menu.Shop.EStat");

    println!("== GetMultiplier per rarity");
    for (i, r) in rarities.iter().enumerate() {
        println!("  {r}: {}", stat(&api, RARITY, "GetMultiplier", json!([i])));
    }

    for luck in [0.0, 5.0] {
        let mut spread: BTreeMap<String, u32> = BTreeMap::new();
        for _ in 0..200 {
            let r = stat(&api, RARITY, "GetEncounterOfferRarity", json!([luck])).as_i64().unwrap_or(-1);
            *spread.entry(rarities.get(r as usize).cloned().unwrap_or_else(|| r.to_string())).or_default() += 1;
        }
        println!("== GetEncounterOfferRarity, 200 rolls at luck {luck}: {spread:?}");
    }

    println!("== GetRandomStatOffers(3, false, true), 10 samples");
    for _ in 0..10 {
        let l = stat(&api, ENCOUNTERS, "GetRandomStatOffers", json!([3, false, true]));
        println!("  {}", show_offers(&api, &l, &stats, &rarities));
    }
    // EncounterData assets hold fixed offers (2026-10-03: types 2
    // GreedAltar, 1 RandomStats, 8 BalanceShrine); their effects.
    let encounters = enum_names(&api, "Assets.Scripts.UI.InGame.Rewards.EEncounter");
    println!("== EncounterData offers (fixed in the game's data)");
    for v in common::find_instances(&api, "Il2CppAssets.Scripts.UI.InGame.Rewards.EncounterData", true).unwrap_or_default() {
        let Some(d) = v.get("handle").and_then(Value::as_i64) else { continue };
        let t = field(&api, d, "encounterType").as_i64().unwrap_or(-1);
        let offers = field(&api, d, "offers");
        println!(
            "  {}: {}",
            encounters.get(t as usize).map(String::as_str).unwrap_or("?"),
            show_offers(&api, &offers, &stats, &rarities)
        );
    }

    println!("== GetBalanceShrineOffers(3), 10 samples");
    for _ in 0..10 {
        let l = stat(&api, ENCOUNTERS, "GetBalanceShrineOffers", json!([3]));
        println!("  {}", show_offers(&api, &l, &stats, &rarities));
    }
}
