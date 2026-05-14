use falcon::loader::{Loader, Pe};
use falcon::translator::Options;
use std::collections::HashMap;
use std::env;
use std::fs;
use std::path::Path;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let binary = env::args().nth(1).unwrap_or_else(|| {
        "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe".to_string()
    });
    let addr_file = env::args().nth(2).unwrap_or_else(|| {
        "C:/code/grounded2mods/rustforge-spike/ghidra_addrs.txt".to_string()
    });

    let pe = Pe::from_file(Path::new(&binary))?;
    let addrs: Vec<u64> = fs::read_to_string(&addr_file)?
        .lines()
        .filter_map(|s| {
            let s = s.trim().trim_start_matches("0x");
            u64::from_str_radix(s, 16).ok()
        })
        .collect();
    let total = addrs.len();
    println!("[sweep-ghidra] {total} ghidra-discovered addresses");

    let mut ok = 0usize;
    let mut fail_by_reason: HashMap<String, usize> = HashMap::new();
    let mut sample_failures: HashMap<String, u64> = HashMap::new();

    let mut opts = Options::new();
    opts.set_unsupported_are_intrinsics(true);
    for (i, &addr) in addrs.iter().enumerate() {
        match pe.function_extended(addr, &opts) {
            Ok(_) => ok += 1,
            Err(e) => {
                let msg = e.to_string();
                let key = classify(&msg);
                *fail_by_reason.entry(key.clone()).or_insert(0) += 1;
                sample_failures.entry(key).or_insert(addr);
            }
        }
        if (i + 1) % 1000 == 0 {
            eprintln!("[sweep-ghidra] {} / {total}  (ok={ok})", i + 1);
        }
    }

    println!();
    println!(
        "[sweep-ghidra] DONE: {ok}/{total} lifted ({:.1}%)",
        100.0 * ok as f64 / total as f64
    );
    println!();
    println!("[sweep-ghidra] top failure reasons:");
    let mut sorted: Vec<_> = fail_by_reason.iter().collect();
    sorted.sort_by_key(|(_, n)| std::cmp::Reverse(**n));
    for (reason, count) in sorted.iter().take(25) {
        let sample = sample_failures.get(*reason).copied().unwrap_or(0);
        println!("  {count:>5}  {reason:<60}  (sample: 0x{sample:x})");
    }
    if sorted.len() > 25 {
        let rest: usize = sorted.iter().skip(25).map(|(_, n)| **n).sum();
        println!("  {rest:>5}  ...(other {} reasons)", sorted.len() - 25);
    }
    Ok(())
}

fn classify(msg: &str) -> String {
    if let Some(pos) = msg.find("Unhandled instruction ") {
        let rest = &msg[pos + "Unhandled instruction ".len()..];
        if let Some(end) = rest.find(|c: char| c == ' ' || c == ',' || c == '"') {
            return format!("unhandled: {}", &rest[..end]);
        }
        return format!("unhandled: {}", &rest[..rest.len().min(20)]);
    }
    if msg.contains("DisassemblyFailure") {
        return "DisassemblyFailure".into();
    }
    if msg.contains("Unrecoverable error during disassembly") {
        return "DisasmFailureUnrecoverable".into();
    }
    msg.lines().next().unwrap_or(msg).chars().take(80).collect()
}
