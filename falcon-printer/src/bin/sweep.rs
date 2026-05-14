use falcon::loader::{Loader, Pe};
use std::collections::HashMap;
use std::env;
use std::path::Path;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let binary = env::args().nth(1).unwrap_or_else(|| {
        "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe".to_string()
    });
    let pe = Pe::from_file(Path::new(&binary))?;
    let entries = pe.function_entries()?;
    let total = entries.len();
    println!("[sweep] {total} functions to try");

    let mut ok = 0usize;
    let mut fail_by_reason: HashMap<String, usize> = HashMap::new();
    let mut sample_failures: HashMap<String, u64> = HashMap::new();

    for (i, entry) in entries.iter().enumerate() {
        let addr = entry.address();
        match pe.function(addr) {
            Ok(_) => ok += 1,
            Err(e) => {
                let msg = e.to_string();
                let key = classify(&msg);
                *fail_by_reason.entry(key.clone()).or_insert(0) += 1;
                sample_failures.entry(key).or_insert(addr);
            }
        }
        if (i + 1) % 100 == 0 {
            eprintln!("[sweep] {} / {total}  (ok={ok})", i + 1);
        }
    }

    println!();
    println!("[sweep] DONE: {ok}/{total} lifted ({:.1}%)",
        100.0 * ok as f64 / total as f64);
    println!();
    println!("[sweep] failure breakdown:");
    let mut sorted: Vec<_> = fail_by_reason.iter().collect();
    sorted.sort_by_key(|(_, n)| std::cmp::Reverse(**n));
    for (reason, count) in sorted {
        let sample = sample_failures.get(reason).copied().unwrap_or(0);
        println!("  {count:>5}  {reason:<60}  (sample: 0x{sample:x})");
    }
    Ok(())
}

fn classify(msg: &str) -> String {
    if let Some(rest) = msg.strip_prefix("Custom(\"Unhandled instruction ") {
        if let Some(end) = rest.find(' ') {
            return format!("unhandled: {}", &rest[..end]);
        }
    }
    if msg.contains("DisassemblyFailure") {
        return "DisassemblyFailure".into();
    }
    if msg.contains("Unhandled instruction") {
        return "unhandled (other)".into();
    }
    msg.lines().next().unwrap_or(msg).chars().take(80).collect()
}
