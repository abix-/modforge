// Time-series perf sampler.
//
// Snapshots once per second for SAMPLE_COUNT seconds. Reports
// per-second deltas for working_set, page_faults, and GObjects
// total. Distinguishes "steady drip" from "bursty load event"
// from "ramp" -- a single T0/T1 window can't.
//
// Output is teed to stdout AND `perf-runs/timeseries-<ts>.txt`
// (gitignored).
//
// Run pattern:
//
//   set BBP_DEBUG_PORT=17171
//   cargo test --release --test explore_perf_timeseries -- --nocapture

mod common;

use common::{Api, open_perf_log};
use std::io::Write;
use std::time::{Duration, Instant};

const SAMPLE_COUNT: usize = 60;
const SAMPLE_INTERVAL: Duration = Duration::from_secs(1);

fn u64_field(v: &serde_json::Value, k: &str) -> u64 {
    v.get(k).and_then(serde_json::Value::as_u64).unwrap_or(0)
}

#[test]
fn timeseries_60_seconds() {
    let api = Api::require();
    let mut out = open_perf_log("timeseries");

    writeln!(
        out,
        "\n=== Time-series perf sampler ({}s, 1Hz) ===",
        SAMPLE_COUNT
    )
    .unwrap();
    writeln!(
        out,
        "{:>4}  {:>10}  {:>14}  {:>12}  {:>11}  {:>11}",
        "t", "ws_delta", "ws_total_mb", "pf_delta", "gobj_delta", "gobj_total"
    )
    .unwrap();
    writeln!(out, "{}", "-".repeat(72)).unwrap();

    let start = Instant::now();
    let mut prev_ws: u64 = 0;
    let mut prev_pf: u64 = 0;
    let mut prev_gobj: u64 = 0;
    let mut first = true;

    for i in 0..SAMPLE_COUNT {
        let snap = api.snapshot();
        let t = start.elapsed().as_secs_f32();
        let ws = u64_field(&snap.process_memory, "working_set_size");
        let pf = u64_field(&snap.process_memory, "page_fault_count");
        let gobj = u64_field(&snap.game_population, "gobjects_total");

        let ws_delta = if first { 0i64 } else { ws as i64 - prev_ws as i64 };
        let pf_delta = if first { 0i64 } else { pf as i64 - prev_pf as i64 };
        let gobj_delta = if first {
            0i64
        } else {
            gobj as i64 - prev_gobj as i64
        };

        writeln!(
            out,
            "{:>4.1}  {:>+10}  {:>14.1}  {:>+12}  {:>+11}  {:>11}",
            t,
            ws_delta,
            ws as f64 / (1024.0 * 1024.0),
            pf_delta,
            gobj_delta,
            gobj
        )
        .unwrap();

        prev_ws = ws;
        prev_pf = pf;
        prev_gobj = gobj;
        first = false;

        if i + 1 < SAMPLE_COUNT {
            std::thread::sleep(SAMPLE_INTERVAL);
        }
    }

    let elapsed = start.elapsed().as_secs_f32();
    let final_snap = api.snapshot();
    let final_ws = u64_field(&final_snap.process_memory, "working_set_size");
    let final_pf = u64_field(&final_snap.process_memory, "page_fault_count");
    let final_gobj = u64_field(&final_snap.game_population, "gobjects_total");

    writeln!(out, "\n=== Summary over {:.1}s ===", elapsed).unwrap();
    writeln!(
        out,
        "  working_set:   {:.1} MB final",
        final_ws as f64 / (1024.0 * 1024.0)
    )
    .unwrap();
    writeln!(out, "  page_faults:   {} cumulative", final_pf).unwrap();
    writeln!(out, "  GObjects:      {} final", final_gobj).unwrap();
}
