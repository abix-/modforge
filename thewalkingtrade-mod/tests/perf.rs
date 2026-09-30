//! What the mod costs in the live game.
//!
//! Switches modforge's named timing on (cleared), waits while the
//! game is played, then prints `timing_report`: every "twt: ..."
//! piece of work with calls, total, average and worst single run,
//! slowest first, plus frame counts. Timing goes off again at the
//! end. Play normally (a fight loads the damage hook) during the
//! window.
//!
//! ```text
//! TWT_PERF_SECS=60 k3sc cargo-lock test -p thewalkingtrade-mod --test perf -- --nocapture
//! ```
//!
//! The Rust timers do not include the C# shim's own work per hook
//! call (boxing arguments, building JSON); read `calls` for that.

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn perf_window() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let secs: u64 = std::env::var("TWT_PERF_SECS")
        .ok()
        .and_then(|s| s.parse().ok())
        .unwrap_or(60);
    let on = api.op("timing", json!({"on": true, "reset": true}));
    assert!(on.ok, "timing on failed: {:?}", on.error);
    println!("measuring for {secs} s; play now");
    std::thread::sleep(std::time::Duration::from_secs(secs));
    let r = api.op("timing_report", json!({}));
    let off = api.op("timing", json!({"on": false, "reset": false}));
    assert!(r.ok, "timing_report failed: {:?}", r.error);
    println!("{:<48} {:>8} {:>10} {:>10} {:>10}", "name", "calls", "total ms", "avg us", "worst ms");
    let empty = vec![];
    for e in r.result["entries"].as_array().unwrap_or(&empty) {
        println!(
            "{:<48} {:>8} {:>10.2} {:>10.1} {:>10.2}",
            e["name"].as_str().unwrap_or("?"),
            e["calls"].as_u64().unwrap_or(0),
            e["total_ms"].as_f64().unwrap_or(0.0),
            e["avg_us"].as_f64().unwrap_or(0.0),
            e["worst_ms"].as_f64().unwrap_or(0.0),
        );
    }
    assert!(off.ok, "timing off failed: {:?}", off.error);
}
