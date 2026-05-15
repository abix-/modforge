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

    // Step 2: for each candidate, verify by reading adjacent fields.
    // GameState layout per decomp:
    //   +0x308 money  (we just scanned for this value)
    //   +0x314 year   (sane: 0..100 typically, year-since-game-start)
    //   +0x318 sleeps (sane: small monotonic counter, < ~10000)
    // A candidate is plausible iff year < 100 AND sleeps < 10_000_000.
    // GameState is heap-allocated; the EXE-relative xref-count test
    // doesn't apply (RIP-rel disp32 can't reach heap addresses past
    // ±2GB from .text).
    fn peek_u32(game: &modforge::harness::RunningGame, addr: u64) -> Option<u32> {
        let resp = game
            .op_json("mem.peek", &json!({"addr": addr, "kind": "u32"}))
            .ok()?;
        resp.get("result")
            .and_then(|r| r.get("value"))
            .and_then(|v| v.as_u64())
            .map(|v| v as u32)
    }
    let mut ranked: Vec<(u64, u32, u32, u32, bool)> = Vec::new();
    for h in hits.iter() {
        let money_addr = u64_of(h, "addr").expect("addr");
        let m = peek_u32(&game, money_addr).unwrap_or(0);
        // year at money + 0xC (offset 0x314 - 0x308 = 0xC)
        let year = peek_u32(&game, money_addr + 0xC).unwrap_or(u32::MAX);
        // sleeps at money + 0x10
        let sleeps = peek_u32(&game, money_addr + 0x10).unwrap_or(u32::MAX);
        let plausible = m == expect_money && year < 100 && sleeps < 10_000_000;
        ranked.push((money_addr, m, year, sleeps, plausible));
    }

    // Log every candidate (sorted plausible-first).
    ranked.sort_by(|a, b| b.4.cmp(&a.4));
    for (money_addr, m, year, sleeps, plausible) in &ranked {
        let candidate_base = money_addr.saturating_sub(0x308);
        game.log().event(
            "FIND-GS",
            &format!(
                "{} money@0x{money_addr:x} (gamestate@0x{candidate_base:x}): \
                 money={m} year={year} sleeps={sleeps}",
                if *plausible { "OK" } else { "??" },
            ),
        );
    }

    let plausible: Vec<_> = ranked.iter().filter(|r| r.4).collect();
    assert!(
        !plausible.is_empty(),
        "no candidate has plausible year+sleeps near the money slot. \
         Ranking: {ranked:?}"
    );
    assert_eq!(
        plausible.len(),
        1,
        "more than one candidate looks plausible; need a tighter \
         discriminator (e.g. also check supplies / horse_count). \
         Plausible: {plausible:?}",
    );
    let top = plausible[0];
    game.pass(&format!(
        "real gamestate_ptr = 0x{:x} (money@0x{:x}={}, year={}, sleeps={})",
        top.0.saturating_sub(0x308),
        top.0,
        top.1,
        top.2,
        top.3,
    ));
}
