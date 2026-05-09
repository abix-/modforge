// Leak-source investigation.
//
// 1. Snapshot T0
// 2. Sleep 30s while game runs
// 3. Snapshot T1
// 4. Print top growing classes (existing)
// 5. Print top packages by hosted-object count (NEW)
// 6. Print loaded levels (NEW)
// 7. For top 5 growing classes, dump K outer-chain samples (NEW)
//    -- this names the actual asset paths that are leaking.
//
// Output answers: "+144 SoundWave per 30s" -> WHICH 144 sounds,
// living under WHICH content directories.
//
// Run pattern:
//
//   set BBP_DEBUG_PORT=17171
//   cargo test --release --test explore_leak_source -- --nocapture

mod common;

use common::Api;
use serde_json::Value;
use std::collections::HashMap;
use std::time::Duration;

const WINDOW: Duration = Duration::from_secs(30);
const TOP_N: usize = 20;
const SAMPLES_PER_CLASS: usize = 8;
// Classes we always probe samples for (the strong-signal leak
// candidates from prior runs). Plus we probe the top-5 fastest
// growers regardless.
const ALWAYS_SAMPLE: &[&str] = &["SoundWave", "SoundNodeWavePlayer", "Package"];

fn read_class_counts(snap_field: &Value) -> HashMap<String, u64> {
    let mut m = HashMap::new();
    if let Some(arr) = snap_field.get("top_classes").and_then(Value::as_array) {
        for entry in arr {
            if let (Some(c), Some(n)) = (
                entry.get("class").and_then(Value::as_str),
                entry.get("count").and_then(Value::as_u64),
            ) {
                m.insert(c.to_string(), n);
            }
        }
    }
    m
}

fn read_package_counts(snap_field: &Value) -> HashMap<String, u64> {
    let mut m = HashMap::new();
    if let Some(arr) = snap_field.get("top_packages").and_then(Value::as_array) {
        for entry in arr {
            if let (Some(p), Some(n)) = (
                entry.get("package").and_then(Value::as_str),
                entry.get("hosted_count").and_then(Value::as_u64),
            ) {
                m.insert(p.to_string(), n);
            }
        }
    }
    m
}

#[test]
fn investigate_leak_source() {
    let api = Api::require();

    println!("=== Snapshot T0 ===");
    let t0 = api.snapshot();

    println!("Sleeping {}s while you play in-game...", WINDOW.as_secs());
    std::thread::sleep(WINDOW);

    println!("=== Snapshot T1 ===");
    let t1 = api.snapshot();

    let t0_classes = read_class_counts(&t0.game_population);
    let t1_classes = read_class_counts(&t1.game_population);
    let t0_pkgs = read_package_counts(&t0.game_population);
    let t1_pkgs = read_package_counts(&t1.game_population);

    let mut class_deltas: Vec<(String, i64, u64)> = t1_classes
        .iter()
        .map(|(c, n1)| {
            let n0 = *t0_classes.get(c).unwrap_or(&0);
            (c.clone(), *n1 as i64 - n0 as i64, *n1)
        })
        .collect();
    class_deltas.sort_by_key(|(_, d, _)| std::cmp::Reverse(*d));

    println!("\n=== Top {} growing CLASSES ===", TOP_N);
    println!("{:>40} {:>10} {:>10}", "class", "delta", "now");
    println!("{}", "-".repeat(64));
    for (c, d, n) in class_deltas.iter().take(TOP_N) {
        println!("{:>40} {:>+10} {:>10}", c, d, n);
    }

    let mut pkg_deltas: Vec<(String, i64, u64)> = t1_pkgs
        .iter()
        .map(|(p, n1)| {
            let n0 = *t0_pkgs.get(p).unwrap_or(&0);
            (p.clone(), *n1 as i64 - n0 as i64, *n1)
        })
        .collect();
    pkg_deltas.sort_by_key(|(_, d, _)| std::cmp::Reverse(*d));

    println!("\n=== Top {} growing PACKAGES ===", TOP_N);
    println!("{:>60} {:>10} {:>10}", "package", "delta", "now");
    println!("{}", "-".repeat(84));
    for (p, d, n) in pkg_deltas.iter().take(TOP_N) {
        println!("{:>60} {:>+10} {:>10}", p, d, n);
    }

    println!("\n=== Loaded LEVELS at T1 ===");
    if let Some(arr) = t1.game_population.get("loaded_levels").and_then(Value::as_array) {
        println!("count: {}", arr.len());
        for entry in arr.iter().take(50) {
            let class = entry.get("class").and_then(Value::as_str).unwrap_or("?");
            let name = entry.get("name").and_then(Value::as_str).unwrap_or("?");
            let pkg = entry.get("package").and_then(Value::as_str).unwrap_or("?");
            println!("  [{}] {} (pkg={})", class, name, pkg);
        }
    } else {
        println!("(no loaded_levels field present -- mod may need rebuild)");
    }

    // Pick the top-5 fastest growers, plus ALWAYS_SAMPLE list.
    let mut to_sample: Vec<String> = class_deltas
        .iter()
        .take(5)
        .filter(|(_, d, _)| *d > 0)
        .map(|(c, _, _)| c.clone())
        .collect();
    for s in ALWAYS_SAMPLE {
        if !to_sample.iter().any(|x| x == s) {
            to_sample.push((*s).to_string());
        }
    }

    println!("\n=== Outer-chain samples for suspect classes ===");
    for class in &to_sample {
        let r = api.op(
            "class_outer_samples",
            serde_json::json!({"class": class, "k": SAMPLES_PER_CLASS}),
        );
        if !r.ok {
            println!("\n[{}] op error: {:?}", class, r.error);
            continue;
        }
        let total = r
            .result
            .get("matched_count")
            .and_then(Value::as_u64)
            .unwrap_or(0);
        println!("\n[{}] live count = {}", class, total);
        if let Some(arr) = r.result.get("samples").and_then(Value::as_array) {
            for s in arr {
                if let Some(p) = s.get("full_path").and_then(Value::as_str) {
                    println!("  {}", p);
                }
            }
        }
    }
}
