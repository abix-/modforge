//! How the game's type records are laid out: every word around the
//! record of a known struct and a known plain type, with the text each
//! word points at, so the fields (name, size, field list, count) can
//! be read off.
//!
//! ```text
//! k3sc cargo-lock test -p enshrouded-mod --test research_type_tables -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game or the DLL is not
//! running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};

fn hits(v: &Value) -> Vec<u64> {
    v["hits"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|h| u64::from_str_radix(h.as_str()?.trim_start_matches("0x"), 16).ok())
        .collect()
}

fn hex(bytes: &[u8]) -> String {
    bytes
        .iter()
        .map(|b| format!("{b:02x}"))
        .collect::<Vec<_>>()
        .join(" ")
}

fn scan(r: &Remote, bytes: &[u8]) -> Vec<u64> {
    r.op(
        "image.scan",
        json!({"signature": hex(bytes), "section": "all", "max": 2000}),
    )
    .map(|v| hits(&v))
    .unwrap_or_default()
}

/// The text at `ptr` if it is a short printable C string.
fn c_text(r: &Remote, ptr: u64) -> Option<String> {
    let b = r.bytes(ptr, 80);
    let end = b.iter().position(|c| *c == 0)?;
    (end >= 2 && b[..end].iter().all(|c| c.is_ascii_graphic() || *c == b' '))
        .then(|| String::from_utf8_lossy(&b[..end]).into_owned())
}

/// Every word from `at - back` to `at + fwd`, with the text it points
/// at when it points at one.
fn dump(r: &Remote, at: u64, back: u64, fwd: usize) {
    let start = at - back;
    for (i, w) in r.words(start, back as usize + fwd).iter().enumerate() {
        let here = start + i as u64 * 8;
        let mark = if here == at { ">" } else { " " };
        let text = c_text(r, *w).map(|t| format!(" {t:?}")).unwrap_or_default();
        println!("{mark} {:+5} {w:#018x}{text}", here as i64 - at as i64);
    }
}

/// The record for each full name: where a pointer to the name sits,
/// and the words around it.
#[test]
fn type_record_layout() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    for name in ["keen::ecs::LootInteractionEvent", "keen::bool"] {
        let mut needle = name.as_bytes().to_vec();
        needle.push(0);
        for text in scan(&r, &needle) {
            for p in scan(&r, &text.to_le_bytes()) {
                println!("== {name:?} named from {p:#x}");
                dump(&r, p, 96, 160);
            }
        }
    }
}
