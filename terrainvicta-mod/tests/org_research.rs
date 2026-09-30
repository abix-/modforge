//! Test: 10x research points per month on the player's ORG_BOOST_COUNT
//! (default 1) orgs with the most research not boosted yet, read back
//! from each org. Each run boosts different orgs; none stacks.
//!
//! ```text
//! ORG_BOOST_COUNT=3 TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test org_research -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn org_research_is_ten_times() {
    let Some(api) = api_or_skip() else { return };
    let count: u64 = std::env::var("ORG_BOOST_COUNT")
        .ok()
        .and_then(|c| c.parse().ok())
        .unwrap_or(1);
    let r = api.op("boost_org_research", json!({"count": count}));
    assert!(r.ok, "boost_org_research failed: {:?}", r.error);
    println!("{}", serde_json::to_string_pretty(&r.result).unwrap());
    for org in r.result["boosted"].as_array().expect("boosted") {
        let before = org["before"].as_f64().expect("before");
        let after = org["after"].as_f64().expect("after");
        assert!((after - before * 10.0).abs() < 0.001, "{}: {after} is not 10x {before}", org["org"]);
    }
}
