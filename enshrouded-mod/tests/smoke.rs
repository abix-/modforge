//! Smoke test: the injected DLL answers, serves the standard
//! modforge tools, and can write memory (its own scratch value, never
//! the game's).
//!
//! ```text
//! modforge-inject --process enshrouded.exe --dll target/x86_64-pc-windows-msvc/release/enshrouded.dll
//! k3sc cargo-lock test -p enshrouded-mod --test smoke -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game or the DLL is not
//! running.

use modforge::memory_research::Remote;
use serde_json::json;

fn remote_or_skip() -> Option<Remote> {
    let r = Remote::at(33080);
    match r.op("ping", json!({})) {
        Ok(_) => Some(r),
        Err(e) => {
            println!("SKIP: {e}");
            None
        }
    }
}

#[test]
fn standard_tools_are_served() {
    let Some(r) = remote_or_skip() else { return };
    let ops = r.op("list_ops", json!({})).expect("list_ops");
    let names: Vec<String> = ops["ops"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|op| op["name"].as_str().map(str::to_string))
        .collect();
    println!("{} ops: {names:?}", names.len());
    for want in [
        "_shutdown",
        "memory.read",
        "memory.write",
        "memory.scan",
        "freeze",
        "image.scan",
        "watch_writes",
        "process.sample_threads",
        "timing_report",
        "game",
    ] {
        assert!(names.iter().any(|n| n == want), "no {want} op");
    }
}

#[test]
fn write_reads_back_on_own_scratch() {
    let Some(r) = remote_or_skip() else { return };
    let scratch = r.op("memory.scratch", json!({})).expect("memory.scratch");
    let addr = scratch["addr"].as_str().expect("addr").to_string();
    let before = r
        .op("memory.read", json!({"addr": addr, "len": 8}))
        .expect("read");
    let original = before["bytes_hex"].as_str().expect("bytes_hex").to_string();

    let written = r
        .op(
            "memory.write",
            json!({"addr": addr, "hex": "0102030405060708"}),
        )
        .expect("write");
    assert_eq!(written["readback"]["bytes_hex"], "0102030405060708");

    r.op("memory.write", json!({"addr": addr, "hex": original}))
        .expect("restore");
    println!("scratch {addr}: wrote, read back, restored {original}");
}
