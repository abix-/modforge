//! Set the run timer pause and leave it that way (src/timer.rs).
//!
//! `MEGABONK_TIMER_PAUSED` is true (default) or false. Reads the pause
//! back and asserts it took.
//!
//! ```text
//! MEGABONK_TIMER_PAUSED=true k3sc cargo-lock test -p megabonk-mod --test timer_set -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn set_pause() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let paused = std::env::var("MEGABONK_TIMER_PAUSED").map(|v| v != "false").unwrap_or(true);
    let r = api.op("timer_pause", json!({"paused": paused}));
    assert!(r.ok, "timer_pause failed: {:?}", r.error);
    println!("timer: {}", r.result);
    assert_eq!(r.result["paused"].as_bool(), Some(paused));
}
