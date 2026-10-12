//! The mod holds luck at its target (src/luck.rs): set the target and
//! watch the game's luck follow.
//!
//! `MEGABONK_LUCK_TARGET` is the target to set (default 2.0). The mod
//! checks every 2 s, so this reads luck for up to 6 s and asserts it
//! reached the target. Needs a run with a luck base above 0.
//!
//! ```text
//! MEGABONK_LUCK_TARGET=2.5 k3sc cargo-lock test -p megabonk-mod --test luck_target -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn luck_follows_target() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let target: f64 = std::env::var("MEGABONK_LUCK_TARGET").ok().and_then(|v| v.parse().ok()).unwrap_or(2.0);
    let r = api.op("luck_target", json!({"value": target}));
    assert!(r.ok, "luck_target failed: {:?}", r.error);
    println!("target set: {}", r.result["target"]);

    let read = || {
        api.op(
            "invoke_static",
            json!({"class": "Il2CppAssets.Scripts.Inventory.Stats.PlayerStats", "method": "GetStat", "args": [30]}),
        )
        .result
        .as_f64()
        .unwrap_or(f64::NAN)
    };
    let mut luck = read();
    println!("luck now: {luck}");
    for _ in 0..60 {
        if (luck - target).abs() < 0.001 {
            break;
        }
        std::thread::sleep(std::time::Duration::from_millis(100));
        luck = read();
    }
    println!("luck after: {luck}");
    assert!((luck - target).abs() < 0.001, "luck {luck}, target {target}");
}
