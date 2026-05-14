//! batch_print: run the rust printer on a list of addresses, writing one .rs per fn.
use std::env;
use std::path::PathBuf;
use std::process::Command;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let bin = env::args().nth(1).unwrap_or_else(|| {
        "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe".to_string()
    });
    let out_dir = env::args().nth(2).unwrap_or_else(|| {
        "C:/code/grounded2mods/horseygame/decompiled/rust".to_string()
    });
    let printer = env::args().nth(3).unwrap_or_else(|| {
        "C:/code/grounded2mods/target/x86_64-pc-windows-msvc/release/rust_print.exe"
            .to_string()
    });

    // Read addrs from stdin (one per line, hex with or without 0x).
    use std::io::BufRead;
    let stdin = std::io::stdin();
    let addrs: Vec<String> = stdin
        .lock()
        .lines()
        .filter_map(|l| l.ok())
        .map(|l| l.trim().to_string())
        .filter(|s| !s.is_empty() && !s.starts_with('#'))
        .collect();

    let mut ok = 0usize;
    let mut err = 0usize;
    for a in &addrs {
        let target = PathBuf::from(&out_dir).join(format!(
            "fn_{}.rs",
            a.trim_start_matches("0x").to_lowercase()
        ));
        let out = Command::new(&printer)
            .arg(&bin)
            .arg(a)
            .output()?;
        if out.status.success() && !out.stdout.is_empty() {
            std::fs::write(&target, &out.stdout)?;
            ok += 1;
        } else {
            err += 1;
        }
    }
    eprintln!("[batch] {ok} ok, {err} err, {} total", addrs.len());
    Ok(())
}
