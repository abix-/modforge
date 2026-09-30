//! Raise a councilor's stat through one of its orgs and check the
//! councilor's stat rose by exactly that much (below the 25 cap). It
//! changes the game every run, so it only runs when all three are set:
//!
//! ```text
//! TI_COUNCILOR="Imrane Atallah" TI_STAT=Espionage TI_AMOUNT=8 TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test org_stats -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn org_stat_raises_councilor_stat() {
    let (Ok(who), Ok(stat), Ok(amount)) = (
        std::env::var("TI_COUNCILOR"),
        std::env::var("TI_STAT"),
        std::env::var("TI_AMOUNT"),
    ) else {
        eprintln!("SKIP: set TI_COUNCILOR, TI_STAT and TI_AMOUNT (this changes the game)");
        return;
    };
    let amount: i64 = amount.parse().expect("TI_AMOUNT is a number");
    let Some(api) = api_or_skip() else { return };
    let r = api.op("boost_org_stat", json!({"councilor": who, "stat": stat, "amount": amount}));
    assert!(r.ok, "boost_org_stat failed: {:?}", r.error);
    println!("{}", r.result);
    let before = r.result["before"].as_i64().expect("before");
    let after = r.result["after"].as_i64().expect("after");
    assert_eq!(after, (before + amount).min(25), "{who} {stat}: {before} -> {after}");
}
