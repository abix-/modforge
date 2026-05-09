// Performance instrumentation: snapshot at T0, sleep for a
// window while gameplay continues, snapshot at T1. Reports:
//   1. Per-counter event-rate deltas (kill_hook fires/sec, etc.)
//   2. Per-hot-path CPU time deltas (ms spent inside our code)
//   3. Total process CPU time delta (for "our share" ratio)
//   4. Process memory delta (working set + private bytes)
//
// This tells us THREE distinct things:
//   - WHICH function fires often (rate counters)
//   - WHICH function is expensive (time counters)
//   - WHETHER memory is leaking (process memory delta)
//   - WHAT FRACTION of total process CPU is in our mod
//     (sum of TIME_NS_* / process_cpu_total_ns delta)
//
// Run (with the game in-world):
//   set BBP_DEBUG_PORT=17171
//   cargo test --target x86_64-pc-windows-msvc \
//     --test explore_perf_counters -- --nocapture --test-threads=1

mod common;

use std::time::{Duration, Instant};

const WINDOW_SECS: u64 = 30;

fn u64_field(map: &serde_json::Map<String, serde_json::Value>, k: &str) -> u64 {
    map.get(k).and_then(|v| v.as_u64()).unwrap_or(0)
}

#[test]
fn measure_counter_deltas() {
    let api = common::Api::require();

    eprintln!("\n=== Snapshot T0 ===");
    let t0 = Instant::now();
    let s0 = api.snapshot();
    let counters0 = s0.counters.as_object().expect("counters not an object").clone();
    let mem0 = s0.process_memory.as_object().cloned().unwrap_or_default();
    let cpu0 = s0.process_cpu.as_object().cloned().unwrap_or_default();

    eprintln!("Sleeping {WINDOW_SECS}s while you play in-game...");
    std::thread::sleep(Duration::from_secs(WINDOW_SECS));

    eprintln!("\n=== Snapshot T1 ===");
    let elapsed = t0.elapsed().as_secs_f64();
    let s1 = api.snapshot();
    let counters1 = s1.counters.as_object().expect("counters not an object").clone();
    let mem1 = s1.process_memory.as_object().cloned().unwrap_or_default();
    let cpu1 = s1.process_cpu.as_object().cloned().unwrap_or_default();

    // ---------------- Event-rate counters ----------------
    let mut rate_rows: Vec<(String, u64, f64)> = counters0
        .keys()
        .filter(|k| !k.starts_with("time_ns_") && !k.ends_with("_peak"))
        .map(|k| {
            let v0 = u64_field(&counters0, k);
            let v1 = u64_field(&counters1, k);
            let delta = v1.saturating_sub(v0);
            let per_sec = delta as f64 / elapsed;
            (k.clone(), delta, per_sec)
        })
        .collect();
    rate_rows.sort_by(|a, b| b.2.partial_cmp(&a.2).unwrap_or(std::cmp::Ordering::Equal));

    eprintln!("\n=== Event rate counters over {:.1}s ===", elapsed);
    eprintln!("{:<40} {:>12} {:>12}", "counter", "delta", "per second");
    eprintln!("{}", "-".repeat(70));
    for (k, delta, per_sec) in &rate_rows {
        eprintln!("{:<40} {:>12} {:>12.1}", k, delta, per_sec);
    }

    // ---------------- CPU time counters (per hot path) ----------------
    let mut time_rows: Vec<(String, u64, f64)> = counters0
        .keys()
        .filter(|k| k.starts_with("time_ns_"))
        .map(|k| {
            let v0 = u64_field(&counters0, k);
            let v1 = u64_field(&counters1, k);
            let delta_ns = v1.saturating_sub(v0);
            let pct = (delta_ns as f64) / (elapsed * 1_000_000_000.0) * 100.0;
            (k.clone(), delta_ns, pct)
        })
        .collect();
    time_rows.sort_by(|a, b| b.1.cmp(&a.1));

    eprintln!("\n=== CPU time spent in OUR mod over {:.1}s ===", elapsed);
    eprintln!(
        "{:<40} {:>14} {:>10}",
        "hot path", "ns total", "% wall"
    );
    eprintln!("{}", "-".repeat(70));
    let mut our_total_ns: u64 = 0;
    for (k, ns, pct) in &time_rows {
        eprintln!("{:<40} {:>14} {:>9.3}%", k, ns, pct);
        our_total_ns = our_total_ns.saturating_add(*ns);
    }
    eprintln!(
        "{:<40} {:>14} {:>9.3}%",
        "  (sum)",
        our_total_ns,
        (our_total_ns as f64) / (elapsed * 1_000_000_000.0) * 100.0
    );

    // ---------------- Process CPU + ratio ----------------
    let proc_cpu_total_0 = u64_field(&cpu0, "process_cpu_total_ns");
    let proc_cpu_total_1 = u64_field(&cpu1, "process_cpu_total_ns");
    let proc_cpu_delta = proc_cpu_total_1.saturating_sub(proc_cpu_total_0);
    let proc_cpu_user_delta =
        u64_field(&cpu1, "process_cpu_user_ns").saturating_sub(u64_field(&cpu0, "process_cpu_user_ns"));
    let proc_cpu_kernel_delta = u64_field(&cpu1, "process_cpu_kernel_ns")
        .saturating_sub(u64_field(&cpu0, "process_cpu_kernel_ns"));

    eprintln!("\n=== Process CPU over {:.1}s ===", elapsed);
    eprintln!(
        "  process_cpu_user_ns:    {} ns ({:.3}% of wall)",
        proc_cpu_user_delta,
        (proc_cpu_user_delta as f64) / (elapsed * 1_000_000_000.0) * 100.0
    );
    eprintln!(
        "  process_cpu_kernel_ns:  {} ns ({:.3}% of wall)",
        proc_cpu_kernel_delta,
        (proc_cpu_kernel_delta as f64) / (elapsed * 1_000_000_000.0) * 100.0
    );
    eprintln!(
        "  process_cpu_total_ns:   {} ns ({:.3}% of wall)",
        proc_cpu_delta,
        (proc_cpu_delta as f64) / (elapsed * 1_000_000_000.0) * 100.0
    );
    eprintln!(
        "  our hot-path total:     {} ns ({:.3}% of wall)",
        our_total_ns,
        (our_total_ns as f64) / (elapsed * 1_000_000_000.0) * 100.0
    );
    if proc_cpu_delta > 0 {
        let our_share = (our_total_ns as f64) / (proc_cpu_delta as f64) * 100.0;
        eprintln!(
            "  OUR FRACTION OF PROCESS CPU: {:.3}%",
            our_share
        );
    }

    // ---------------- Process memory delta ----------------
    let ws_0 = u64_field(&mem0, "working_set_size");
    let ws_1 = u64_field(&mem1, "working_set_size");
    let pu_0 = u64_field(&mem0, "private_usage");
    let pu_1 = u64_field(&mem1, "private_usage");
    let pf_0 = u64_field(&mem0, "page_fault_count");
    let pf_1 = u64_field(&mem1, "page_fault_count");

    eprintln!("\n=== Process memory delta over {:.1}s ===", elapsed);
    eprintln!(
        "  working_set_size:   {:>13} -> {:>13}  delta {:+} ({:+.2} MB)",
        ws_0,
        ws_1,
        (ws_1 as i128) - (ws_0 as i128),
        ((ws_1 as i128) - (ws_0 as i128)) as f64 / (1024.0 * 1024.0)
    );
    eprintln!(
        "  private_usage:      {:>13} -> {:>13}  delta {:+} ({:+.2} MB)",
        pu_0,
        pu_1,
        (pu_1 as i128) - (pu_0 as i128),
        ((pu_1 as i128) - (pu_0 as i128)) as f64 / (1024.0 * 1024.0)
    );
    eprintln!(
        "  page_fault_count:   {:>13} -> {:>13}  delta {:+} ({:+.1}/sec)",
        pf_0,
        pf_1,
        (pf_1 as i128) - (pf_0 as i128),
        ((pf_1 as i128) - (pf_0 as i128)) as f64 / elapsed
    );

    // ---------------- Per-thread CPU breakdown ----------------
    let threads0 = s0.process_threads.get("threads").and_then(|v| v.as_array()).cloned().unwrap_or_default();
    let threads1 = s1.process_threads.get("threads").and_then(|v| v.as_array()).cloned().unwrap_or_default();
    let mut by_tid_0: std::collections::HashMap<u64, (String, u64)> = std::collections::HashMap::new();
    for t in &threads0 {
        if let (Some(tid), Some(name), Some(cpu)) = (
            t.get("tid").and_then(|v| v.as_u64()),
            t.get("name").and_then(|v| v.as_str()),
            t.get("cpu_total_ns").and_then(|v| v.as_u64()),
        ) {
            by_tid_0.insert(tid, (name.to_string(), cpu));
        }
    }
    let mut deltas: Vec<(String, u64)> = Vec::new();
    for t in &threads1 {
        let tid = t.get("tid").and_then(|v| v.as_u64()).unwrap_or(0);
        let name = t.get("name").and_then(|v| v.as_str()).unwrap_or("?").to_string();
        let cpu1 = t.get("cpu_total_ns").and_then(|v| v.as_u64()).unwrap_or(0);
        let cpu0 = by_tid_0.get(&tid).map(|x| x.1).unwrap_or(0);
        let delta = cpu1.saturating_sub(cpu0);
        if delta > 0 {
            deltas.push((name, delta));
        }
    }
    deltas.sort_by(|a, b| b.1.cmp(&a.1));
    eprintln!("\n=== Top threads by CPU time delta ===");
    eprintln!("{:<48} {:>14} {:>9}", "thread", "ns", "% wall");
    eprintln!("{}", "-".repeat(74));
    for (name, ns) in deltas.iter().take(15) {
        let pct = (*ns as f64) / (elapsed * 1_000_000_000.0) * 100.0;
        eprintln!("{:<48} {:>14} {:>8.2}%", name, ns, pct);
    }

    // ---------------- Game object population delta ----------------
    let pop0 = s0.game_population.clone();
    let pop1 = s1.game_population.clone();
    let total0 = pop0.get("gobjects_total").and_then(|v| v.as_u64()).unwrap_or(0);
    let total1 = pop1.get("gobjects_total").and_then(|v| v.as_u64()).unwrap_or(0);
    eprintln!("\n=== UE5 GObjects population ===");
    eprintln!(
        "  total: {} -> {}  delta {:+}",
        total0,
        total1,
        (total1 as i64) - (total0 as i64)
    );

    let classes0 = pop0.get("top_classes").and_then(|v| v.as_array()).cloned().unwrap_or_default();
    let classes1 = pop1.get("top_classes").and_then(|v| v.as_array()).cloned().unwrap_or_default();
    let mut count_0: std::collections::HashMap<String, u64> = std::collections::HashMap::new();
    for c in &classes0 {
        if let (Some(name), Some(count)) = (
            c.get("class").and_then(|v| v.as_str()),
            c.get("count").and_then(|v| v.as_u64()),
        ) {
            count_0.insert(name.to_string(), count);
        }
    }
    let mut class_deltas: Vec<(String, i64, u64)> = Vec::new();
    for c in &classes1 {
        let name = c.get("class").and_then(|v| v.as_str()).unwrap_or("?").to_string();
        let count1 = c.get("count").and_then(|v| v.as_u64()).unwrap_or(0);
        let count0 = count_0.get(&name).copied().unwrap_or(0);
        let delta = (count1 as i64) - (count0 as i64);
        class_deltas.push((name, delta, count1));
    }
    class_deltas.sort_by(|a, b| b.1.cmp(&a.1));
    eprintln!("\n=== Top growing UE classes (count delta over window) ===");
    eprintln!("{:<48} {:>10} {:>10}", "class", "delta", "now");
    eprintln!("{}", "-".repeat(70));
    for (name, delta, now) in class_deltas.iter().take(20) {
        eprintln!("{:<48} {:>+10} {:>10}", name, delta, now);
    }

    eprintln!("\n=== Top 5 by event rate ===");
    for (k, _delta, per_sec) in rate_rows.iter().take(5) {
        eprintln!("  {:<40} {:.1}/sec", k, per_sec);
    }
    eprintln!("\n=== Top 3 by hot-path CPU time ===");
    for (k, ns, pct) in time_rows.iter().take(3) {
        eprintln!("  {:<40} {} ns ({:.3}% wall)", k, ns, pct);
    }
}
