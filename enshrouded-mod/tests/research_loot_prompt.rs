//! Where is the "collect nearby loot" prompt in memory? Run while the
//! prompt shows, and again while it does not: the copies of the text
//! that exist only while it shows belong to the prompt.
//!
//! ```text
//! k3sc cargo-lock test -p enshrouded-mod --test research_loot_prompt -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game or the DLL is not
//! running.

use modforge::memory_research::Remote;
use serde_json::json;

/// Part of the prompt that matches "Nearby" and "nearby".
const NEEDLE: &str = "earby";

/// How many hits to print the surrounding text of.
const SHOWN: usize = 40;

/// The printable text around a hit: UTF-8 bytes, or every other byte
/// when the text is UTF-16.
fn around(r: &Remote, at: u64, utf16: bool) -> String {
    let back = if utf16 { 64 } else { 32 };
    let bytes = r.bytes(at.saturating_sub(back), 160);
    let units: Vec<u8> = if utf16 {
        bytes.iter().step_by(2).copied().collect()
    } else {
        bytes
    };
    units
        .iter()
        .map(|b| {
            if b.is_ascii_graphic() || *b == b' ' {
                char::from(*b)
            } else {
                '.'
            }
        })
        .collect()
}

/// Stop a search still running in the game after the client gave up.
#[test]
#[ignore = "only after a timed-out search"]
fn cancel_search() {
    let r = Remote::at(33080);
    match r.op("memory.scan_cancel", json!({})) {
        Ok(v) => println!("cancel: {v}"),
        Err(e) => println!("SKIP: {e}"),
    }
}

#[test]
fn prompt_text_copies() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    for utf16 in [false, true] {
        let found = r
            .op(
                "memory.find_bytes",
                json!({"text": NEEDLE, "utf16": utf16, "max": 2000}),
            )
            .expect("memory.find_bytes");
        let hits = found["hits"].as_array().cloned().unwrap_or_default();
        println!(
            "{} {NEEDLE:?} as {}: {} hits (capped {})",
            if utf16 { "UTF-16" } else { "UTF-8" },
            if utf16 { "utf16" } else { "utf8" },
            found["matches"],
            found["capped"]
        );
        for hit in hits.iter().take(SHOWN) {
            let at =
                u64::from_str_radix(hit.as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
            println!("  {at:#x}  {}", around(&r, at, utf16));
        }
    }
}
