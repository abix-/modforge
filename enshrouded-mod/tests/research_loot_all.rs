//! Which code uses the "IsLootAllSequence" name? The game names the
//! hold-E "collect nearby loot" action by it, so the code that reads
//! that name is the code that decides when the prompt shows.
//!
//! Finds the name in the exe with image.scan, then every place that
//! points at it: RIP-relative lea and mov in the code, and 8-byte
//! pointers in the data (a type or field record holding the name).
//! Prints the bytes around each code site.
//!
//! Found 2026-11-15, build e4dfdc45: no code points at any of the
//! names; they sit only in the game's type tables. "IsLootAllSequence"
//! is flag 2 of a sequence flag list (DoesRequireStandingUp 0,
//! IsLootingSequence 1, IsLootAllSequence 2,
//! IsTransformedToLootWithHealth 3), so it describes an animation, not
//! the prompt. "lootAll" is a bool field (48-byte field records: name,
//! length, type, offset) at offset 0x14 of keen::ecs::LootInteractionEvent
//! and keen::ds::ecs::LootInteractionEvent, beside guestId, hostId,
//! offerId, knowledgeUnlockOperations and bypassInteraction: the event
//! sent when the hold finishes, not the state that shows the prompt.
//! No lea in the code points at those type records either.
//!
//! ```text
//! k3sc cargo-lock test -p enshrouded-mod --test research_loot_all -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game or the DLL is not
//! running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};

const NAMES: &[&str] = &["IsLootAllSequence", "lootAll", "LootInteractionActionEvent"];

/// RIP-relative encodings that load or take the address of a global,
/// as (name, opcode bytes before the 4-byte operand).
const PREFIXES: &[(&str, &str)] = &[
    ("lea rax", "48 8d 05"),
    ("lea rcx", "48 8d 0d"),
    ("lea rdx", "48 8d 15"),
    ("lea rbx", "48 8d 1d"),
    ("lea rbp", "48 8d 2d"),
    ("lea rsi", "48 8d 35"),
    ("lea rdi", "48 8d 3d"),
    ("lea r8", "4c 8d 05"),
    ("lea r9", "4c 8d 0d"),
    ("lea r10", "4c 8d 15"),
    ("lea r11", "4c 8d 1d"),
    ("lea r12", "4c 8d 25"),
    ("lea r13", "4c 8d 2d"),
    ("lea r14", "4c 8d 35"),
    ("lea r15", "4c 8d 3d"),
    ("mov rax", "48 8b 05"),
    ("mov rcx", "48 8b 0d"),
    ("mov rdx", "48 8b 15"),
];

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

fn scan(r: &Remote, signature: &str, section: &str) -> Vec<u64> {
    match r.op(
        "image.scan",
        json!({"signature": signature, "section": section, "max": 2000}),
    ) {
        Ok(v) => hits(&v),
        Err(e) => {
            println!("  scan {signature:?} in {section}: {e}");
            Vec::new()
        }
    }
}

/// The text at `ptr` if it is `len` printable bytes.
fn text_at(r: &Remote, ptr: u64, len: u64) -> Option<String> {
    if !(1..=200).contains(&len) {
        return None;
    }
    let b = r.bytes(ptr, len as usize);
    (b.len() == len as usize && b.iter().all(|c| c.is_ascii_graphic() || *c == b' '))
        .then(|| String::from_utf8_lossy(&b).into_owned())
}

/// The 40-byte records around `at` whose first two words are a text
/// pointer and its length, with the rest of each record's words.
fn records_around(r: &Remote, at: u64) {
    const STRIDE: u64 = 40;
    let mut first = at;
    while let [p, n, ..] = r.words(first - STRIDE, 16)[..] {
        if text_at(r, p, n).is_none() {
            break;
        }
        first -= STRIDE;
    }
    let mut here = first;
    loop {
        let w = r.words(here, STRIDE as usize);
        let Some(name) = text_at(r, w[0], w[1]) else {
            break;
        };
        let mark = if here == at { ">" } else { " " };
        println!("{mark} {here:#x} {name:?} {:x?}", &w[2..]);
        here += STRIDE;
    }
}

/// The value list holding "IsLootAllSequence", and the structs with a
/// "lootAll" field: every neighbouring record, by name.
#[test]
fn records_naming_loot_all() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    for name in ["IsLootAllSequence", "lootAll"] {
        for text in scan(&r, &hex(name.as_bytes()), "all") {
            for p in scan(&r, &hex(&text.to_le_bytes()), "all") {
                println!("== {name:?} record at {p:#x}");
                records_around(&r, p);
            }
        }
    }
}

/// Every text pair (pointer, length) in the `len` bytes at `at`.
fn texts_in(r: &Remote, at: u64, len: usize) {
    let w = r.words(at, len);
    for i in 0..w.len().saturating_sub(1) {
        if let Some(t) = text_at(r, w[i], w[i + 1]) {
            println!("   {:+5} {t:?}", i as i64 * 8);
        }
    }
}

/// The "lootAll" field's type, and the field records around each
/// "lootAll" record, read as text pairs, to name the structs.
#[test]
fn loot_all_field_owners() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    let text = scan(&r, &hex(b"lootAll"), "all");
    for t in &text {
        for p in scan(&r, &hex(&t.to_le_bytes()), "all") {
            let ty = r.words(p + 16, 8)[0];
            println!("== record {p:#x}, type {ty:#x}:");
            texts_in(&r, ty, 128);
            println!("   around the record:");
            texts_in(&r, p - 512, 1024);
        }
    }
}

/// Field records are 48 bytes apart. The struct holding guestId,
/// hostId, offerId, lootAll: which type record points at its first
/// field, and what code points at that type record.
#[test]
fn loot_request_struct() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    let text = scan(&r, &hex(b"guestId"), "all");
    for t in &text {
        for field in scan(&r, &hex(&t.to_le_bytes()), "all") {
            println!("== guestId field record {field:#x}");
            for owner in scan(&r, &hex(&field.to_le_bytes()), "all") {
                println!("-- pointed at from {owner:#x}");
                texts_in(&r, owner - 256, 512);
                let start = owner - 64;
                for (what, prefix) in PREFIXES {
                    for a in [
                        start,
                        start + 8,
                        start + 16,
                        start + 24,
                        start + 32,
                        start + 40,
                        start + 48,
                        start + 56,
                    ] {
                        for site in scan(&r, &format!("{prefix} X0x{a:x}"), "text") {
                            println!("   code {what} at {site:#x} -> {a:#x}");
                        }
                    }
                }
            }
        }
    }
}

#[test]
fn code_using_loot_all_name() {
    let r = Remote::at(33080);
    if let Err(e) = r.op("ping", json!({})) {
        println!("SKIP: {e}");
        return;
    }
    for name in NAMES {
        let at = scan(&r, &hex(name.as_bytes()), "all");
        println!("== {name:?} at {at:x?}");
        for text in &at {
            let back = r.bytes(text.saturating_sub(16), 16 + name.len() + 16);
            println!("   around {text:#x}: {}", hex(&back));

            for (what, prefix) in PREFIXES {
                for site in scan(&r, &format!("{prefix} X0x{text:x}"), "text") {
                    println!("-- {what} at {site:#x}");
                    let start = site.saturating_sub(96);
                    for (i, row) in r.bytes(start, 192).chunks(16).enumerate() {
                        let here = start + i as u64 * 16;
                        let mark = if (here..here + 16).contains(&site) {
                            ">"
                        } else {
                            " "
                        };
                        println!("{mark} {here:#x}  {}", hex(row));
                    }
                }
            }

            let pointers = scan(&r, &hex(&text.to_le_bytes()), "all");
            for p in &pointers {
                println!("-- pointer at {p:#x}");
                let start = p.saturating_sub(32);
                for (i, word) in r.words(start, 96).iter().enumerate() {
                    let here = start + i as u64 * 8;
                    let mark = if here == *p { ">" } else { " " };
                    println!("{mark} {:+4} {word:#018x}", here as i64 - *p as i64);
                }
            }
        }
    }
}
