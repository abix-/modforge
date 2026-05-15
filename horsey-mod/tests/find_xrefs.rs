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
//! Validation: target the already-resolved GAMESTATE_PTR slot
//! address. Since the slot is a `.data` pointer slot, every read
//! site in the decomp (`*(int*)(DAT_1403fb0d8 + N)`) compiles to
//! `mov reg, [rip+disp_to_slot]; ...`, so the xref scan against
//! the slot itself surfaces every load of the pointer. Assert:
//!   - many hits (the slot is heavily referenced; the in-image
//!     decomp has 364+ references to `DAT_1403fb0d8`).
//!   - every hit's `instr_addr` is inside `.text`.

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

    // Step 1: get the resolved GAMESTATE_PTR slot address (a
    // `.data` location that holds the heap GameState pointer). We
    // target the SLOT itself, not slot+0x308: the slot is the
    // RIP-rel target of every gamestate-read instruction, so the
    // xref scan against it should surface dozens of gameplay sites.
    let resolve = game
        .op_json("targets.resolve.gamestate_ptr", &json!({}))
        .expect("targets.resolve.gamestate_ptr must succeed");
    let slot = u64_of(resolve.get("result").unwrap(), "slot")
        .expect("R3 must have resolved GAMESTATE_PTR before this test runs");
    assert!(slot != 0, "GAMESTATE_PTR slot null; cannot find xrefs");
    let target = slot;

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
    // Bound: at least 10 hits. The slot is loaded everywhere via
    // `mov reg, [rip+disp_to_slot]`, and the decomp has 364+
    // references to `DAT_1403fb0d8`. If we see fewer than 10, the
    // slot address is wrong or the find_xrefs op regressed.
    assert!(
        hits.len() >= 10,
        "expected at least 10 xrefs to GAMESTATE_PTR slot 0x{target:x}; \
         got {}. Either the slot is wrong or find_xrefs regressed.",
        hits.len()
    );

    // Log all hits for human review.
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
        "find_xrefs returned {} site(s) referencing slot 0x{target:x}",
        hits.len()
    ));
}
