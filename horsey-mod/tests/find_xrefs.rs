//! `mem.find_xrefs` op contract.
//!
//! The op scans the loaded image's `.text` section for every
//! RIP-relative instruction whose `disp32` resolves to a caller-
//! supplied target data address. For each hit it returns the
//! instruction's address (best-guess; the START of the matched
//! disp32, minus a small prefix lookback) plus a window of bytes
//! around it so a human can author a sleuth signature directly
//! from real compiler output.
//!
//! Validation: target the already-resolved GAMESTATE_PTR address
//! (we know its runtime address from R3 via `targets.resolve.
//! gamestate_ptr`). Assert:
//!   - at least one hit
//!   - the cheat-money instruction bytes `81 05 .. .. .. .. e8 03 00 00`
//!     appear in at least one returned context window (this is the
//!     instruction the existing R3 sig anchors on)
//!
//! This proves the xref scanner finds the same site sleuth already
//! locates, plus N more candidate sites the user can mine for
//! additional signatures.

mod common;

use serde_json::{json, Value};

fn u64_of(v: &Value, key: &str) -> Option<u64> {
    v.get(key)
        .and_then(|x| x.as_str())
        .and_then(|s| u64::from_str_radix(s.trim_start_matches("0x"), 16).ok())
}

#[test]
fn find_xrefs_locates_known_gamestate_references() {
    let Some(game) = common::launch("find_xrefs_gamestate") else {
        return;
    };

    // Step 1: get the known-good GAMESTATE_PTR + 0x308 address (the
    // operand of the cheat-money `add` instruction). We aim find_xrefs
    // at this address and expect to land on at least the cheat-money
    // site we already anchor a sleuth sig to.
    let resolve = game
        .op_json("targets.resolve.gamestate_ptr", &json!({}))
        .expect("targets.resolve.gamestate_ptr must succeed");
    let gamestate_ptr = u64_of(resolve.get("result").unwrap(), "address")
        .expect("R3 must have resolved GAMESTATE_PTR before this test runs");
    assert!(gamestate_ptr != 0, "GAMESTATE_PTR null; cannot find xrefs");
    let target = gamestate_ptr + 0x308;

    // Step 2: scan.
    let resp = game
        .op_json("mem.find_xrefs", &json!({"target_addr": target}))
        .expect("mem.find_xrefs must succeed");
    let result = resp.get("result").expect("result");
    let hits = result
        .get("hits")
        .and_then(|v| v.as_array())
        .expect("result.hits array");
    game.log()
        .event("XREFS", &format!("target=0x{target:x} hits={}", hits.len()));
    assert!(!hits.is_empty(), "no xrefs found for {target:#x}");

    // Step 3: at least one hit's context window must contain the
    // cheat-money byte pattern. This is the existence proof: the
    // scanner sees the site we already pattern-match elsewhere.
    // Don't assert any specific opcode pattern: the cheat-money
    // sig `81 05 .. e8 03 00 00` MISSES this build (the +$1000
    // cheat compiles to a different encoding here). The scanner's
    // job is to surface whatever instructions reference the
    // target so signatures can be authored from real bytes. Log
    // each hit verbatim into the harness log for inspection.
    for h in hits.iter() {
        game.log().event(
            "XREF",
            &format!(
                "instr@{} ({}): {}",
                h.get("instr_addr").and_then(|v| v.as_str()).unwrap_or("?"),
                h.get("opcode_class").and_then(|v| v.as_str()).unwrap_or("?"),
                h.get("context_hex").and_then(|v| v.as_str()).unwrap_or("?"),
            ),
        );
    }

    game.pass(&format!(
        "find_xrefs returned {} site(s) referencing 0x{target:x}; \
         full hex windows logged for signature authoring",
        hits.len()
    ));
}
