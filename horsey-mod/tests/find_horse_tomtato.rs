//! Ground-truth validation: find the horse named "tomtato".
//!
//! Strategy: pull every Horse* via the validated GS+0x438 -> +0x90 ->
//! +0x130/+0x138 chain. For each, read the 0x498-byte Horse object
//! and search the bytes for the ASCII string "tomtato". If found at
//! offset N, report it. That pins down the in-Horse name buffer offset
//! AND proves the owned-horse chain reaches the player's real horses.
//!
//! Run with the user's tomtato save loaded:
//!   $env:MODFORGE_ATTACH = "1"
//!   k3sc cargo-lock test -p horsey-mod --test find_horse_tomtato. --nocapture

mod common;

use serde_json::{json, Value};

const TARGET_NAME: &[u8] = b"tomtato";
const HORSE_ALLOC_SIZE: usize = 0x498;

fn parse_hex(s: &str) -> usize {
    usize::from_str_radix(s.trim_start_matches("0x"), 16).unwrap_or(0)
}

fn read_bytes(
    game: &modforge::harness::RunningGame,
    addr: usize,
    n: usize,
) -> Option<Vec<u8>> {
    let resp = game
        .op_json(
            "patterns.read_bytes",
            &json!({ "addr": format!("0x{addr:x}"), "n": n }),
        )
        .ok()?;
    let hex = resp
        .get("result")
        .and_then(|r| r.get("bytes"))
        .and_then(Value::as_str)?;
    Some(
        hex.split_whitespace()
            .map(|b| u8::from_str_radix(b, 16).unwrap())
            .collect(),
    )
}

fn find_subseq(haystack: &[u8], needle: &[u8]) -> Vec<usize> {
    let mut out = Vec::new();
    if needle.is_empty() || needle.len() > haystack.len() {
        return out;
    }
    for i in 0..=haystack.len() - needle.len() {
        if &haystack[i..i + needle.len()] == needle {
            out.push(i);
        }
    }
    out
}

#[test]
fn find_horse_named_tomtato() {
    let Some(game) = common::launch("find_horse_tomtato") else {
        return;
    };

    // Poll for save to load. Vanilla Horsey may take 10+ seconds to
    // restore the last save after launch. Wait up to 60s for the
    // owned-horse chain to populate.
    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(60);
    let mut resp = serde_json::Value::Null;
    let mut last_count: u64 = 0;
    while std::time::Instant::now() < deadline {
        resp = game
            .op_json("gamestate.owned_horses", &json!({}))
            .expect("gamestate.owned_horses should succeed");
        last_count = resp
            .get("result")
            .and_then(|r| r.get("count"))
            .and_then(Value::as_u64)
            .unwrap_or(0);
        if last_count > 0 {
            break;
        }
        std::thread::sleep(std::time::Duration::from_secs(2));
    }
    eprintln!("\n=== Final owned_horse_count after poll: {last_count} ===");
    let result = resp.get("result").unwrap_or(&resp);
    let count = result
        .get("count")
        .and_then(Value::as_u64)
        .unwrap_or(0) as usize;
    let horses = result
        .get("horses")
        .and_then(Value::as_array)
        .cloned()
        .unwrap_or_default();

    eprintln!("\n=== Owned horses (count={count}) ===");
    let mut found_in_horse: Vec<(usize, Vec<usize>, u32)> = Vec::new();
    for (idx, h) in horses.iter().enumerate() {
        let ptr_s = h.get("ptr").and_then(Value::as_str).unwrap_or("0x0");
        let ptr = parse_hex(ptr_s);
        let name_id = h.get("name_id").and_then(Value::as_u64).unwrap_or(0) as u32;
        let age = h.get("age").and_then(Value::as_i64).unwrap_or(-1);
        eprintln!("  horse[{idx}] ptr={ptr_s} age={age} name_id={name_id}");
        if ptr == 0 {
            continue;
        }
        let Some(bytes) = read_bytes(&game, ptr, HORSE_ALLOC_SIZE) else {
            eprintln!("    read failed");
            continue;
        };
        let hits = find_subseq(&bytes, TARGET_NAME);
        if !hits.is_empty() {
            for off in &hits {
                eprintln!(
                    "    FOUND 'tomtato' at horse_ptr+0x{off:x} (name_id field at +0x1f8 = {name_id})"
                );
            }
            found_in_horse.push((idx, hits, name_id));
        } else {
            // Show the first 32 bytes for context.
            let preview: Vec<String> =
                bytes.iter().take(32).map(|b| format!("{b:02x}")).collect();
            eprintln!("    no match. first 32 bytes: {}", preview.join(" "));
        }
    }

    if found_in_horse.is_empty() {
        eprintln!(
            "\n'tomtato' NOT found in any owned Horse object. Either:\n  \
             - the wrong save is loaded (no horse named tomtato),\n  \
             - the owned-horse chain reaches a list that excludes tomtato,\n  \
             - the name is stored on a struct outside the Horse object (pointer to a name buffer)."
        );
    } else {
        eprintln!("\nSummary:");
        for (idx, offsets, nid) in &found_in_horse {
            eprintln!(
                "  horse[{idx}] (name_id={nid}): name string at horse_ptr+{offsets:?}"
            );
        }
    }

    // Soft assert: at least one horse exists, even if we don't find the name.
    assert!(count > 0, "no owned horses returned; save may not be loaded");
    game.pass(&format!(
        "owned={count}, tomtato-hits={}",
        found_in_horse.len()
    ));
}
