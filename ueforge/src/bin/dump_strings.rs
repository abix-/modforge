//! Thin CLI over `ueforge::uasset::extract_printable_strings` +
//! the classifiers. See module docs.
//!
//! ```sh
//! cargo run -p ueforge --bin dump-strings -- <file> [file ...]
//! ```

use std::env;
use std::fs;
use std::path::Path;
use std::process::ExitCode;

use ueforge::uasset::{
    DEFAULT_MIN_PRINTABLE_LEN, classify_prose, classify_ue_name, classify_ue_path,
    extract_printable_strings,
};

fn run(paths: &[String]) -> Result<(), String> {
    for arg in paths {
        let path = Path::new(arg);
        if !path.exists() {
            eprintln!("missing: {}", path.display());
            continue;
        }
        let data = fs::read(path).map_err(|e| format!("read {}: {e}", path.display()))?;
        let all = extract_printable_strings(&data, DEFAULT_MIN_PRINTABLE_LEN);

        println!(
            "\n===== {} ({} bytes) =====",
            path.file_name()
                .map(|s| s.to_string_lossy().into_owned())
                .unwrap_or_default(),
            data.len()
        );
        println!("total unique strings: {}", all.len());

        let names: Vec<&String> = all.iter().filter(|s| classify_ue_name(s)).collect();
        let paths_v: Vec<&String> = all.iter().filter(|s| classify_ue_path(s)).collect();
        let prose: Vec<&String> = all
            .iter()
            .filter(|s| classify_prose(s) && !classify_ue_path(s))
            .collect();
        let other: Vec<&String> = all
            .iter()
            .filter(|s| !classify_ue_name(s) && !classify_ue_path(s) && !classify_prose(s))
            .collect();

        println!("  ue names (identifier-shaped): {}", names.len());
        println!("  ue paths (/Game/... style):   {}", paths_v.len());
        println!("  prose-shaped (sentences):     {}", prose.len());
        println!("  other:                        {}", other.len());

        println!("\n--- UE paths ---");
        for s in &paths_v {
            println!("{s}");
        }

        println!("\n--- prose ---");
        for s in prose.iter().take(200) {
            println!("{s}");
        }

        println!("\n--- ue names sample (first 200) ---");
        for s in names.iter().take(200) {
            println!("{s}");
        }
    }
    Ok(())
}

fn main() -> ExitCode {
    let args: Vec<String> = env::args().skip(1).collect();
    if args.is_empty() {
        eprintln!("usage: dump-strings <file> [file ...]");
        return ExitCode::from(2);
    }
    match run(&args) {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("error: {e}");
            ExitCode::FAILURE
        }
    }
}
