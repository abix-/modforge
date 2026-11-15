//! Where are the game's event functions in this build? Kiln's
//! signatures (github.com/frostdev-ops/kiln, sigdb/symbols/server.d/
//! gameplay.json and server.json) for SimStep, DeliverEvents and
//! EmitEvent, scanned in the running game's exe, with the offsets their
//! holes hold. Kiln's addresses for client build 26404966: SimStep
//! 0xa2c580.
//!
//! ```text
//! k3sc cargo-lock test -p enshrouded-mod --test research_events -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game or the DLL is not
//! running.

use modforge::keen::{hole_value, kiln_sig};
use modforge::memory_research::Remote;
use serde_json::json;

/// (what, Kiln signature).
///
/// Found 2026-11-15, build e4dfdc45: each matches once. SimStep rva
/// 0xa2c660 calls DeliverEvents rva 0xa25a50; EmitEvent rva 0x961470.
/// Pending event buffers at storage+0x7b9ef0, count at +0x7b9ef8,
/// buffer used at +0x10, record size byte at +6; event map cap
/// +0xe16dc8, count +0xe16e0c, bits +0xe16dc0. Same offsets as Kiln's
/// notes for the server (docs/re/gameplay.md section 1).
const SIGS: &[(&str, &str)] = &[
    (
        "SimStep",
        "40 55 53 56 41 55 48 8D AC 24 F8 FF FD FF B8 08 01 02 00 E8 ?? ?? ?? ??",
    ),
    (
        "SimStep.deliver",
        "48 8B CE 4C 89 BC 24 ?? ?? ?? ?? E8 {gameplay/DeliverEvents:rel32} 4C 8B 0E 45 33 ED",
    ),
    (
        "DeliverEvents",
        "40 56 41 55 41 56 48 83 EC 40 48 8B 31 45 33 ED 4C 8B F1 4C 39 A9 {gameplay/storage.pending_count:d32} 0F 86",
    ),
    (
        "DeliverEvents.pending",
        "4D 8B BE {gameplay/storage.pending:d32} 33 ED 4C 03 F9 41 39 6F {gameplay/buffer.used:d8} 0F 86",
    ),
    (
        "DeliverEvents.record",
        "4C 8B 9E {gameplay/events.map.cap:d32} 8B FD 49 03 3F 83 BE {gameplay/events.map.count:d32} 00 44 0F B6 67 {gameplay/record.size:d8} 44 8B 0F 74 ?? 48 8B 9E {gameplay/events.map.bits:d32}",
    ),
    (
        "EmitEvent",
        "48 83 EC 28 4C 8B D9 41 81 F8 00 01 00 00 73 ?? 45 8B D0 41 8B C0 41 83 E2 07",
    ),
];

fn hits(v: &serde_json::Value) -> Vec<u64> {
    v["hits"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|h| u64::from_str_radix(h.as_str()?.trim_start_matches("0x"), 16).ok())
        .collect()
}

#[test]
fn event_functions() {
    let r = Remote::at(33080);
    let game = match r.op("game", json!({})) {
        Ok(g) => g,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let base = u64::from_str_radix(
        game["base"]
            .as_str()
            .unwrap_or("0")
            .trim_start_matches("0x"),
        16,
    )
    .unwrap_or_else(|_| game["base"].as_u64().unwrap_or(0));
    println!("exe base {base:#x}");
    for (what, sig) in SIGS {
        let (pattern, holes) = kiln_sig(sig).expect("signature");
        let found = r
            .op(
                "image.scan",
                json!({"signature": pattern, "section": "text", "max": 20}),
            )
            .expect("image.scan");
        let at = hits(&found);
        println!("== {what}: {} match(es)", found["total"]);
        for a in at {
            let bytes = r.bytes(a, pattern.split_whitespace().count());
            print!("   rva {:#x}", a - base);
            for h in &holes {
                match hole_value(h, &bytes, a) {
                    Some(v) if h.kind == modforge::keen::HoleKind::Rel32 => {
                        print!("  {} -> rva {:#x}", h.name, v - base)
                    }
                    Some(v) => print!("  {} = {v:#x}", h.name),
                    None => print!("  {} unread", h.name),
                }
            }
            println!();
        }
    }
}
