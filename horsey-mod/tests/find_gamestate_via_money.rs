//! Locate the real `GAMESTATE_PTR` for this build by scanning
//! `.data` for the player's on-screen money value, then using
//! `mem.find_xrefs` to verify each candidate.
//!
//! Workflow:
//!
//!   1. `MODFORGE_EXPECT_MONEY=N` says "the user has $N in their
//!      currently-loaded save right now."
//!   2. Patternsleuth `mem.scan_data` finds every `.data` u32
//!      equal to N. Each candidate address is a possible
//!      `GAMESTATE_PTR + 0x308`.
//!   3. For each candidate, run `mem.find_xrefs` against it. The
//!      real money slot has many gameplay-code xrefs (cmp / mov /
//!      add); spurious matches usually have zero.
//!   4. Log the full ranking. The user picks the right candidate
//!      and feeds its address back as a fixed point for authoring
//!      `GAMESTATE_PTR` signatures.
//!
//! No env -> test skips (cannot guess money). `MODFORGE_ATTACH=1`
//! is the canonical way to run this (attach to a manually-loaded
//! save without disturbing it).

mod common;

use serde_json::{json, Value};

fn u64_of(v: &Value, key: &str) -> Option<u64> {
    v.get(key)
        .and_then(|x| x.as_str())
        .and_then(|s| u64::from_str_radix(s.trim_start_matches("0x"), 16).ok())
}

#[test]
fn find_gamestate_ptr_by_money_xref_count() {
    let expect_money = match std::env::var("MODFORGE_EXPECT_MONEY") {
        Ok(s) => s.parse::<u32>().ok(),
        Err(_) => None,
    };
    let Some(expect_money) = expect_money else {
        eprintln!("MODFORGE_EXPECT_MONEY unset; cannot locate gamestate \
                   without a known-live value. Skipping.");
        return;
    };
    let Some(game) = common::launch("find_gamestate_via_money") else {
        return;
    };
    game.log().event(
        "FIND-GS",
        &format!("expected on-screen money = {expect_money}"),
    );

    // Step 1: scan .data for the money value.
    let scan = game
        .op_json(
            "mem.scan_data",
            &json!({"value": expect_money, "kind": "u32"}),
        )
        .expect("mem.scan_data must succeed");
    let scan_result = scan.get("result").expect("result");
    let hits = scan_result
        .get("hits")
        .and_then(|v| v.as_array())
        .expect("result.hits array");
    game.log().event(
        "FIND-GS",
        &format!(
            "scan_data: {} candidate(s) for u32 == {expect_money}",
            hits.len()
        ),
    );
    assert!(
        !hits.is_empty(),
        "no .data u32 holds the value {expect_money}; either the user is \
         not in-save or money is stored at a non-u32-aligned offset"
    );

    // Step 2: per candidate, run find_xrefs and count gameplay hits.
    let mut ranked: Vec<(u64, usize, Vec<String>)> = Vec::new();
    for h in hits.iter() {
        let money_addr = u64_of(h, "addr").expect("addr");
        let xref = game
            .op_json(
                "mem.find_xrefs",
                &json!({"target_addr": money_addr, "max_hits": 64}),
            )
            .expect("mem.find_xrefs must succeed");
        let xref_hits = xref
            .get("result")
            .and_then(|r| r.get("hits"))
            .and_then(|v| v.as_array())
            .cloned()
            .unwrap_or_default();
        let opcode_classes: Vec<String> = xref_hits
            .iter()
            .filter_map(|h| {
                h.get("opcode_class")
                    .and_then(|v| v.as_str())
                    .map(|s| s.to_string())
            })
            .collect();
        ranked.push((money_addr, xref_hits.len(), opcode_classes));
        if ranked.len() >= 16 {
            break;
        }
    }

    // Step 3: rank by xref count descending and log.
    ranked.sort_by(|a, b| b.1.cmp(&a.1));
    for (money_addr, count, classes) in &ranked {
        let classes_str = classes.join(",");
        let candidate_base = money_addr.saturating_sub(0x308);
        game.log().event(
            "FIND-GS",
            &format!(
                "money@0x{money_addr:x} (gamestate@0x{candidate_base:x}): \
                 {count} xref(s) [{classes_str}]"
            ),
        );
    }

    let top = ranked.first().expect("at least one candidate");
    assert!(
        top.1 > 1,
        "best candidate for money has only {} xref(s); real gamestate \
         money slot should have many (cmp / mov / add from cheat / race / \
         save code). Ranking: {ranked:?}",
        top.1,
    );
    game.pass(&format!(
        "best gamestate_ptr candidate: 0x{:x} (money 0x{:x}, {} xrefs)",
        top.0.saturating_sub(0x308),
        top.0,
        top.1,
    ));
}
