//! Does the engine keep a list of its types? The exe holds about ten
//! thousand "keen::" type names. If something in memory points at a
//! name, the words around that pointer are the engine's record of the
//! type, and the other names they point at hint at its fields.
//!
//! ```text
//! cargo run -p enshrouded-mod        # game running
//! k3sc cargo-lock test -p enshrouded-mod --test research_types -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when enshrouded-mod or the game is
//! not running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};

/// A type name seen in the exe on disk.
const NAME: &str = "keen::BuildingMaterialPalette";

/// How many pointer hits to print the neighbourhood of.
const SHOWN: usize = 6;

fn hex_sig(bytes: &[u8]) -> String {
    let parts: Vec<String> = bytes.iter().map(|b| format!("{b:02x}")).collect();
    parts.join(" ")
}

fn addresses(found: &Value) -> Vec<u64> {
    found["addresses"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|a| u64::from_str_radix(a.as_str()?.trim_start_matches("0x"), 16).ok())
        .collect()
}

fn hex_field(v: &Value) -> u64 {
    u64::from_str_radix(v.as_str().unwrap_or("0").trim_start_matches("0x"), 16).unwrap_or(0)
}

/// The zero-ended printable text at `addr`, if there is one.
fn text_at(r: &Remote, addr: u64) -> Option<String> {
    let bytes = r.bytes(addr, 96);
    let end = bytes.iter().position(|b| *b == 0)?;
    let s = &bytes[..end];
    (s.len() >= 2 && s.iter().all(|b| b.is_ascii_graphic() || *b == b' '))
        .then(|| String::from_utf8_lossy(s).into_owned())
}

#[test]
fn something_points_at_a_type_name() {
    let r = Remote::at(17187);
    let game = match r.op("game", json!({})) {
        Ok(g) => g,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let base = hex_field(&game["base"]);
    let exe = base..base + game["size"].as_u64().unwrap_or(0);

    // The name with a zero on each side, so it is the whole text.
    let mut exact = vec![0u8];
    exact.extend(NAME.as_bytes());
    exact.push(0);
    let found = r
        .op("patterns.find", json!({"sig": hex_sig(&exact), "section": "any"}))
        .expect("patterns.find name");
    let names: Vec<u64> = addresses(&found).iter().map(|a| a + 1).collect();
    println!("{NAME:?} as a whole text at {names:x?}");
    assert!(!names.is_empty(), "{NAME} not in memory as its own text");

    let mut pointed = 0;
    for name in &names {
        let found = r
            .op(
                "patterns.find",
                json!({"sig": hex_sig(&name.to_le_bytes()), "section": "any"}),
            )
            .expect("patterns.find pointer");
        let refs = addresses(&found);
        println!("{} pointers to {name:#x}: {refs:x?}", found["count"]);
        pointed += refs.len();
        for at in refs.iter().take(SHOWN) {
            println!("-- around {at:#x} (rva {:#x})", at - exe.start);
            let start = at.saturating_sub(64);
            for (i, word) in r.words(start, 160).iter().enumerate() {
                let here = start + i as u64 * 8;
                let mark = if here == *at { ">" } else { " " };
                let note = if exe.contains(word) {
                    text_at(&r, *word).map_or(format!("exe+{:#x}", word - exe.start), |t| {
                        format!("{t:?}")
                    })
                } else {
                    String::new()
                };
                println!("{mark} {:+4} {word:#018x} {note}", here as i64 - *at as i64);
            }
        }
    }
    assert!(pointed > 0, "nothing in the exe points at {NAME}");
}
