//! dump_il: print raw Falcon IL (pre-printer) for one function. Use
//! when investigating why `rust_print` output looks wrong; lets you
//! see what the lifter actually produced before our middle-end passes
//! touch it. One section per basic block, plus the CFG edges.

use falcon::loader::{Loader, Pe};
use std::env;
use std::path::Path;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let binary = env::args().nth(1).unwrap_or_else(|| {
        "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe".to_string()
    });
    let addr_hex = env::args().nth(2).unwrap_or_else(|| "0x140089510".into());
    let addr = u64::from_str_radix(addr_hex.trim_start_matches("0x"), 16)?;

    let pe = Pe::from_file(Path::new(&binary))?;
    let func = pe.function(addr)?;
    let cfg = func.control_flow_graph();

    println!("# Function 0x{addr:x}");
    println!("# blocks: {}, edges: {}", cfg.blocks().len(), cfg.edges().len());
    println!();

    let block_list = cfg.blocks();
    let mut blocks: Vec<_> = block_list.iter().collect();
    blocks.sort_by_key(|b| b.address().unwrap_or(0));

    for block in &blocks {
        println!("## Block @ 0x{:x}  (index {})",
            block.address().unwrap_or(0), block.index());
        for instr in block.instructions() {
            println!("  {}", instr);
        }
        let succs: Vec<_> = cfg.edges()
            .iter()
            .filter(|e| e.head() == block.index())
            .map(|e| {
                let cond = e.condition().map(|c| format!(" if {c}")).unwrap_or_default();
                format!("block#{}{}", e.tail(), cond)
            })
            .collect();
        if !succs.is_empty() {
            println!("  -> {}", succs.join(", "));
        }
        println!();
    }
    Ok(())
}
