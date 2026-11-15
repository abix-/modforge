//! Where is the "collect nearby loot" prompt in memory? Run while the
//! prompt shows, and again while it does not: the copies of the text
//! that exist only while it shows belong to the prompt.
//!
//! Found 2026-11-15, build e4dfdc45: the prompt keeps no copy of its
//! text. The line "Collect nearby loot" sits twice in the game's text
//! table (in its GF_App block, 0x300...), lines run together with no
//! separator, and nothing in game memory points at either line's start.
//! Every pointer or extra copy found lay in the Windows heap (0x26b...)
//! and was the mod's own request or search buffer. Text is a dead end
//! for spotting the prompt.
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
const SHOWN: usize = 250;

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

/// The prompt's line in the game's text table.
const PROMPT_TEXT: &str = "Collect nearby loot";

/// Every address holding a pointer to the start of the prompt's line,
/// saved under PROMPT=on or PROMPT=off. Once both are saved, the
/// pointers only the "on" run saw are printed with the words around
/// them: the prompt's own record holds one.
#[test]
fn pointers_to_prompt_text() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    let found = r
        .op("memory.find_bytes", json!({"text": PROMPT_TEXT, "max": 50}))
        .expect("memory.find_bytes text");
    let lines: Vec<u64> = found["hits"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|h| u64::from_str_radix(h.as_str()?.trim_start_matches("0x"), 16).ok())
        .collect();
    println!("{PROMPT_TEXT:?} at {lines:x?}");
    assert!(!lines.is_empty(), "{PROMPT_TEXT:?} not in memory");

    let mut pointers: Vec<(u64, u64)> = Vec::new();
    for line in &lines {
        let hex: Vec<String> = line
            .to_le_bytes()
            .iter()
            .map(|b| format!("{b:02x}"))
            .collect();
        let found = r
            .op(
                "memory.find_bytes",
                json!({"hex": hex.join(""), "max": 2000}),
            )
            .expect("memory.find_bytes pointer");
        for h in found["hits"].as_array().into_iter().flatten() {
            let at = u64::from_str_radix(h.as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
            pointers.push((at, *line));
        }
        println!("  {} pointers to {line:#x}", found["matches"]);
    }

    let Ok(label) = std::env::var("PROMPT") else {
        for (at, line) in &pointers {
            println!("  {at:#x} -> {line:#x}");
        }
        return;
    };
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../target/research")
        .join(format!("loot_prompt_pointers_{label}.txt"));
    std::fs::create_dir_all(path.parent().unwrap()).unwrap();
    let saved: Vec<String> = pointers
        .iter()
        .map(|(a, l)| format!("{a:#x} {l:#x}"))
        .collect();
    std::fs::write(&path, saved.join("\n")).unwrap();
    println!("saved {} pointers to {}", pointers.len(), path.display());

    let read = |l: &str| {
        std::fs::read_to_string(path.with_file_name(format!("loot_prompt_pointers_{l}.txt")))
    };
    let (Ok(on), Ok(off)) = (read("on"), read("off")) else {
        return;
    };
    let off: std::collections::HashSet<&str> = off.lines().collect();
    let only_on: Vec<&str> = on.lines().filter(|l| !off.contains(l)).collect();
    println!("{} pointers only while the prompt shows:", only_on.len());
    for row in only_on.iter().take(SHOWN) {
        let at = u64::from_str_radix(
            row.split_whitespace()
                .next()
                .unwrap()
                .trim_start_matches("0x"),
            16,
        )
        .unwrap();
        println!("-- {row}");
        let start = at.saturating_sub(64);
        for (i, word) in r.words(start, 160).iter().enumerate() {
            let here = start + i as u64 * 8;
            let mark = if here == at { ">" } else { " " };
            println!("{mark} {:+4} {word:#018x}", here as i64 - at as i64);
        }
    }
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

/// Where a run's hits are kept, by PROMPT=on or PROMPT=off.
fn saved(label: &str, utf16: bool) -> std::path::PathBuf {
    let enc = if utf16 { "utf16" } else { "utf8" };
    std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../target/research")
        .join(format!("loot_prompt_{label}_{enc}.txt"))
}

/// Search for the text. With PROMPT=on or PROMPT=off the hits are
/// saved; once both are saved, the copies only the "on" run saw are
/// printed with their text, since those belong to the prompt.
#[test]
fn prompt_text_copies() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    let label = std::env::var("PROMPT").ok();
    for utf16 in [false, true] {
        let found = r
            .op(
                "memory.find_bytes",
                json!({"text": NEEDLE, "utf16": utf16, "max": 2000}),
            )
            .expect("memory.find_bytes");
        let hits: Vec<u64> = found["hits"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|h| u64::from_str_radix(h.as_str()?.trim_start_matches("0x"), 16).ok())
            .collect();
        println!(
            "{} {NEEDLE:?}: {} hits (capped {})",
            if utf16 { "UTF-16" } else { "UTF-8" },
            found["matches"],
            found["capped"]
        );
        let Some(label) = label.as_deref() else {
            for at in hits.iter().take(SHOWN) {
                println!("  {at:#x}  {}", around(&r, *at, utf16));
            }
            continue;
        };
        let path = saved(label, utf16);
        std::fs::create_dir_all(path.parent().unwrap()).unwrap();
        let lines: Vec<String> = hits.iter().map(|a| format!("{a:#x}")).collect();
        std::fs::write(&path, lines.join("\n")).unwrap();
        println!("  saved to {}", path.display());

        let (Ok(on), Ok(off)) = (
            std::fs::read_to_string(saved("on", utf16)),
            std::fs::read_to_string(saved("off", utf16)),
        ) else {
            continue;
        };
        let off: std::collections::HashSet<&str> = off.lines().collect();
        let only_on: Vec<&str> = on.lines().filter(|a| !off.contains(a)).collect();
        println!("  {} copies only while the prompt shows:", only_on.len());
        for a in only_on.iter().take(SHOWN) {
            let at = u64::from_str_radix(a.trim_start_matches("0x"), 16).unwrap();
            println!("  {at:#x}  {}", around(&r, at, utf16));
        }
    }
}
