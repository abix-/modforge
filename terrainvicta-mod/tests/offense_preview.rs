//! Offense mode preview: the siege plan offense mode would make at the
//! next phase start, without assigning. All automated councilors work
//! one nation within 5 borders of Ukraine: Purge a disabled point
//! (33%+), Crackdown (15%+), Purge (33%+), else Public Campaign
//! there. Checks every pick is in that one nation, meets its
//! step's minimum, and no control point gets two attacks.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test offense_preview -- --nocapture
//! ```

mod common;
use std::collections::HashSet;

use common::api_or_skip;
use serde_json::json;

#[test]
fn plan_besieges_one_nation() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("offense_preview", json!({"as_phase_start": true}));
    assert!(r.ok, "offense_preview failed: {:?}", r.error);
    println!("{}", serde_json::to_string_pretty(&r.result).unwrap());
    let mut nations = HashSet::new();
    let mut attacked = HashSet::new();
    for c in r.result.as_array().expect("array") {
        let p = &c["planned"];
        let Some(step) = p["step"].as_str() else { continue };
        let who = &c["councilor"];
        nations.insert(p["nation"].to_string());
        assert!(p["ring"].as_u64().expect("ring") <= 5, "{who}: beyond 5 borders");
        let chance = p["chance"].as_f64().expect("chance");
        let min = match step {
            "purge now" => 0.50,
            "crackdown" => 0.15,
            "public campaign" => 0.0,
            _ => 0.33,
        };
        assert!(chance >= min, "{who}: {step} at {chance}");
        if matches!(p["mission"].as_str(), Some("Purge" | "Crackdown")) {
            assert!(attacked.insert(p["target"].to_string()), "{who}: {} attacked twice", p["target"]);
        }
    }
    assert!(nations.len() <= 1, "more than one nation: {nations:?}");
}
