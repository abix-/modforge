//! Grant a mission through orgs to the councilors with the highest
//! stat that cannot run it yet, and check each can run it afterwards.
//! It changes the game, so it only runs when all three are set:
//!
//! ```text
//! TI_MISSION=Propaganda TI_COUNT=3 TI_STAT=Persuasion TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test org_missions -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn granted_councilors_can_run_the_mission() {
    let (Ok(mission), Ok(count), Ok(stat)) = (
        std::env::var("TI_MISSION"),
        std::env::var("TI_COUNT"),
        std::env::var("TI_STAT"),
    ) else {
        eprintln!("SKIP: set TI_MISSION, TI_COUNT and TI_STAT (this changes the game)");
        return;
    };
    let count: u64 = count.parse().expect("TI_COUNT is a number");
    let Some(api) = api_or_skip() else { return };
    let r = api.op("grant_org_mission", json!({"mission": mission, "count": count, "stat": stat}));
    assert!(r.ok, "grant_org_mission failed: {:?}", r.error);
    println!("{}", serde_json::to_string_pretty(&r.result).unwrap());
    for g in r.result["granted"].as_array().expect("granted") {
        if g["skipped"].is_string() {
            continue;
        }
        assert_eq!(g["can_run_now"], json!(true), "{} still cannot run {mission}", g["councilor"]);
    }
}
