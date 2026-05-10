// Thread-RIP-by-module attribution.
//
// For 30 seconds, sample every thread's instruction pointer
// every 100 ms. For each sample, look up which loaded module
// the RIP falls in. Histogram per-thread + grand total.
//
// Answers "WHO is burning CPU" one frame deep:
//   GameThread mostly in Grounded2.exe = game logic
//   GameThread mostly in nvrtum64.dll  = NVIDIA driver path
//   Foreground Worker in ntdll.dll    = allocator / syscall
//   Foreground Worker in Grounded2.exe = game-side worker code
//
// Caveat: only the topmost frame. A thread INSIDE the
// allocator shows ntdll.dll. We do not yet walk the stack
// to find the caller. That's the next step (StackWalk64 +
// dbghelp). This is the cheap first cut.
//
// Run pattern (with the game in-world):
//   set BBP_DEBUG_PORT=17171
//   cargo test --release --test explore_thread_attribution -- --nocapture

mod common;

use common::{Api, open_perf_log};
use serde_json::Value;
use std::io::Write;

#[test]
fn sample_thread_modules() {
    let api = Api::require();
    let mut out = open_perf_log("thread_attribution");

    writeln!(out, "=== Sampling thread modules for 30s @ 10 Hz ===").unwrap();
    writeln!(out, "(suspending each thread briefly to read RIP, then resuming)").unwrap();

    let r = api.op(
        "sample_thread_modules",
        serde_json::json!({"duration_ms": 30_000, "interval_ms": 100}),
    );
    if !r.ok {
        panic!("op failed: {:?}", r.error);
    }
    let res = &r.result;

    let total = res.get("total_samples").and_then(Value::as_u64).unwrap_or(0);
    writeln!(out, "\ntotal samples: {}", total).unwrap();

    writeln!(out, "\n=== Grand total: which module is the process IN ===").unwrap();
    writeln!(out, "{:>40} {:>10} {:>8}", "module", "samples", "%").unwrap();
    writeln!(out, "{}", "-".repeat(62)).unwrap();
    if let Some(arr) = res.get("by_module_grand_total").and_then(Value::as_array) {
        for entry in arr {
            let m = entry.get("module").and_then(Value::as_str).unwrap_or("?");
            let s = entry.get("samples").and_then(Value::as_u64).unwrap_or(0);
            let p = entry.get("pct").and_then(Value::as_f64).unwrap_or(0.0);
            writeln!(out, "{:>40} {:>10} {:>7.2}%", m, s, p).unwrap();
        }
    }

    writeln!(out, "\n=== Per-thread breakdown ===").unwrap();
    if let Some(threads) = res.get("by_thread").and_then(Value::as_array) {
        for thread in threads.iter().take(20) {
            let name = thread.get("name").and_then(Value::as_str).unwrap_or("?");
            let tid = thread.get("tid").and_then(Value::as_u64).unwrap_or(0);
            let samples = thread.get("samples").and_then(Value::as_u64).unwrap_or(0);
            writeln!(
                out,
                "\n[{}] tid={} samples={}",
                name, tid, samples
            )
            .unwrap();
            if let Some(by) = thread.get("by_module").and_then(Value::as_array) {
                for m in by {
                    let mn = m.get("module").and_then(Value::as_str).unwrap_or("?");
                    let s = m.get("samples").and_then(Value::as_u64).unwrap_or(0);
                    let p = m.get("pct").and_then(Value::as_f64).unwrap_or(0.0);
                    writeln!(out, "  {:>40} {:>8} {:>6.2}%", mn, s, p).unwrap();
                }
            }
        }
    }
}
