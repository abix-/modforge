//! What are the LIVE tuning values on each punching bag station?
//!
//! The decompile only shows code defaults for the serialized
//! fields (perfectWindows 0.16/0.12/0.09 etc.); the prefab can
//! override them per station. The auto-punch window must come
//! from the live objects.
//!
//! ```text
//! cargo test -p bossgangsters-mod --test research_punching_bag_tuning -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn punching_bag_live_tuning() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let res = api.op(
        "walk_class",
        json!({"class": "PunchingBagStation", "include_inactive": true}),
    );
    assert!(res.ok, "walk_class failed: {:?}", res.error);
    let instances = res.result["instances"].as_array().cloned().unwrap_or_default();
    println!("PunchingBagStation instances: {}", instances.len());

    for inst in &instances {
        let Some(handle) = inst.get("handle").and_then(|h| h.as_i64()) else {
            continue;
        };
        println!(
            "\n=== station handle {handle} ({}) ===",
            inst.get("name").and_then(|n| n.as_str()).unwrap_or("?")
        );
        for field in [
            "difficultyTier",
            "maximumAwayAngle",
            "perfectWindows",
            "perfectWindowForgiveness",
            "reactionWindows",
            "pendulumSpringStrength",
            "apexHoldDuration",
        ] {
            let r = api.op("read_field", json!({"handle": handle, "field": field}));
            if r.ok {
                println!("  {field} = {}", r.result);
            } else {
                println!("  {field}: read failed ({:?})", r.error);
            }
        }
    }
}
