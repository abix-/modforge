//! Set the luck boost and read it back from the running game.
//!
//! `MEGABONK_LUCK_BOOST` is the value to set (0 turns it off). Without
//! it the test only reads the current boost.
//!
//! ```text
//! MEGABONK_LUCK_BOOST=1 k3sc cargo-lock test -p megabonk-mod --test luck_boost -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn set_and_read_back() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let wanted: Option<f64> = std::env::var("MEGABONK_LUCK_BOOST").ok().and_then(|v| v.parse().ok());
    let args = match wanted {
        Some(v) => json!({"value": v}),
        None => json!({}),
    };
    let r = api.op("luck_boost", args);
    assert!(r.ok, "luck_boost failed: {:?}", r.error);
    let now = r.result["boost"].as_f64().expect("boost is a number");
    println!("luck boost now {now}");
    if let Some(v) = wanted {
        assert!((now - v).abs() < 1e-6, "set {v}, game reports {now}");
    }
}
