//! rustforge_spike legacy entry point. Prints arch / function count /
//! first-block IL for a single function. The real Rust-print path is in
//! `src/bin/rust_print.rs`; this main.rs survives only as the crate's
//! `[[bin]]` default and as a smoke test that Falcon loads the binary.

use falcon::loader::{Loader, Pe};
use std::env;
use std::path::Path;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = env::args().collect();
    let binary = args.get(1).map(String::as_str).unwrap_or(
        "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe",
    );
    let addr_filter = args.get(2).and_then(|s| {
        u64::from_str_radix(s.trim_start_matches("0x"), 16).ok()
    });

    println!("[spike] loading {binary}");
    let pe = Pe::from_file(Path::new(binary))?;
    println!("[spike] arch: {:?}", pe.architecture());

    let entries = pe.function_entries()?;
    println!("[spike] function entries: {}", entries.len());

    let target_addr = addr_filter.unwrap_or_else(|| {
        entries.iter().map(|e| e.address()).min().unwrap_or(0)
    });
    println!("[spike] lifting function at 0x{target_addr:x}");

    let func = pe.function(target_addr)?;
    let cfg = func.control_flow_graph();
    println!(
        "[spike] lifted: {} blocks, {} edges",
        cfg.blocks().len(),
        cfg.edges().len()
    );

    if let Some(block) = cfg.blocks().first() {
        println!("[spike] first block:");
        for instr in block.instructions() {
            println!("  {}", instr);
        }
    }

    Ok(())
}
