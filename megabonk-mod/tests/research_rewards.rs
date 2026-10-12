//! How shrine and encounter rewards are made, to rank shrines by value.
//!
//! Read-only. research_shrine_rewards.rs (2026-10-03) found the amounts
//! are not stored: they are rolled at use by EncounterUtility with a
//! rarity. This prints:
//! - the encounter enums (which reward window each shrine opens)
//! - the parameters and return types of every EncounterUtility and
//!   Rarity method, so later tests can call the generators to sample
//!   payouts without granting anything
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_rewards -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, enum_names, parameters, ping_or_skip};

#[test]
fn reward_machinery() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Assets.Scripts.UI.InGame.Rewards.EEncounter",
        "Assets.Scripts.UI.InGame.Rewards.Effects.EEncounterEffect",
        "Assets.Scripts.UI.InGame.Levelup.ERewardWindowType",
    ] {
        println!("\n== {class}");
        for (i, n) in enum_names(&api, class).iter().enumerate() {
            println!("  {i} = {n}");
        }
    }
    println!("\n== generators");
    for (class, methods) in [
        (
            "Assets.Scripts.Inventory__Items__Pickups.Upgrades.EncounterUtility",
            &[
                "GetRandomStats",
                "GetRandomStatsChaosAndGamble",
                "GetRandomStatsBalanceShrine",
                "GetRandomStatOffers",
                "GetBalanceShrineOffers",
                "GetRandomStatValue",
            ][..],
        ),
        (
            "Assets.Scripts.Inventory__Items__Pickups.Rarity",
            &[
                "GetUpgradeOfferRarity",
                "GetEncounterOfferRarity",
                "GetItemRarity",
                "GetShadyGuyRarity",
                "CalculateRarityWeights",
                "GetMultiplier",
            ][..],
        ),
    ] {
        for m in methods {
            parameters(&api, class, m);
        }
    }
}
