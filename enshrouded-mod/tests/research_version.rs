//! Can we read the running game? The build hash the game writes to
//! enshrouded.log at startup must also be in its memory, and the text
//! next to it there says which version this is.
//!
//! ```text
//! cargo run -p enshrouded-mod        # game running
//! k3sc cargo-lock test -p enshrouded-mod --test research_version -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when enshrouded-mod or the game is
//! not running.

use modforge::memory_research::Remote;
use serde_json::json;
use std::path::Path;

/// The 40-hex build hash in the log's "enshrouded(...) - version <hash>" line.
fn logged_hash(log: &Path) -> String {
    let text = std::fs::read_to_string(log).unwrap_or_else(|e| panic!("read {log:?}: {e}"));
    let line = text
        .lines()
        .find(|l| l.contains("[GameFramework] enshrouded(") && l.contains(" - version "))
        .unwrap_or_else(|| panic!("no version line in {log:?}"));
    let hash = line.split(" - version ").nth(1).unwrap_or("");
    hash.chars().take_while(char::is_ascii_hexdigit).collect()
}

/// The zero-ended texts in `bytes`, printable ones only.
fn texts(bytes: &[u8]) -> Vec<String> {
    bytes
        .split(|b| *b == 0)
        .filter(|s| s.len() >= 2 && s.iter().all(|b| b.is_ascii_graphic() || *b == b' '))
        .map(|s| String::from_utf8_lossy(s).into_owned())
        .collect()
}

#[test]
fn build_hash_in_memory_matches_log() {
    let r = Remote::at(17187);
    let game = match r.op("game", json!({})) {
        Ok(g) => g,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    println!("game {game}");
    let exe = Path::new(game["path"].as_str().expect("path"));
    let log = exe.with_file_name("enshrouded.log");
    let hash = logged_hash(&log);
    assert_eq!(hash.len(), 40, "log hash {hash:?}");
    println!("log says version {hash}");

    let sig: Vec<String> = hash.bytes().map(|b| format!("{b:02x}")).collect();
    let found = r
        .op("patterns.find", json!({"sig": sig.join(" "), "section": "any"}))
        .expect("patterns.find");
    let hits = found["addresses"].as_array().cloned().unwrap_or_default();
    println!("{} copies of the hash in the exe's memory: {hits:?}", found["count"]);
    assert!(!hits.is_empty(), "hash {hash} not in memory");

    let at = u64::from_str_radix(hits[0].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    let bytes = r.bytes(at, 128);
    assert_eq!(&bytes[..40], hash.as_bytes(), "bytes at {at:#x}");
    println!("texts from {at:#x}: {:?}", texts(&bytes));
}
