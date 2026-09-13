use anyhow::{Context, Result, ensure};

fn main() -> Result<()> {
    let args: Vec<_> = std::env::args_os().skip(1).collect();
    ensure!(args.len() >= 2, "usage: inspect_function <exe> <hex-rva> [hex-rva ...]");
    let path = std::path::Path::new(&args[0]);
    for arg in &args[1..] {
        let arg = arg.to_str().context("RVA is not Unicode")?;
        let rva = u32::from_str_radix(arg.trim_start_matches("0x"), 16).context("parse RVA")?;
        println!("function +0x{rva:X}");
        for line in modforge::patterns::sleuth::inspect_file_function(path, rva)? {
            println!("{line}");
        }
    }
    Ok(())
}
