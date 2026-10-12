//! What goes into the rarity rolls and what comes out.
//!
//! Read-only. Reads the mod's `rarity_trace` op (src/rarity_trace.rs):
//! every recorded call of `Rarity.GetUpgradeOfferRarity`,
//! `GetEncounterOfferRarity` and `GetItemRarity`, with its argument
//! and result. Level up or open chests in the game first, then run
//! it.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_rarity_trace -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn rarity_rolls() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op("rarity_trace", json!({}));
    if !r.ok {
        println!("rarity_trace failed: {:?}", r.error);
        return;
    }
    let empty = vec![];
    let rolls = r.result["rolls"].as_array().unwrap_or(&empty);
    println!("{} recorded roll(s)", rolls.len());
    for roll in rolls {
        println!(
            "  {} arg={} boost={} game={} used={}",
            roll["method"].as_str().unwrap_or("?"),
            roll["arg"],
            roll["boost"],
            roll["game"],
            roll["used"]
        );
    }
}
