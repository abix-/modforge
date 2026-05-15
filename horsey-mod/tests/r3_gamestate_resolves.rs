//! R3: pattern-scan-resolve the GAMESTATE_PTR data address.
//!
//! Per `docs/ADDRESS-RESOLUTION.md`, the canonical recovery path
//! when a hardcoded address drifts is to derive it at runtime from
//! a sleuth signature in `.text`. R1 shipped image identification
//! (build hash) and R2 shipped function-address resolution. R3
//! extends the same primitive to a DATA pointer by matching an
//! instruction that references it and decoding the RIP-relative
//! displacement.
//!
//! Specifically, GAMESTATE_PTR is the base of the game-state
//! struct (`DAT_1403fb0d8` in the decomp, "main game-state struct
//! base"). It is referenced by the cheat-money handler in
//! `draw_pause_status` (RVA `0x140066200`) which does:
//!
//!     *(int *)(DAT_1403fb0d8 + 0x308) += 1000;   // +$1000 cheat
//!
//! That compiles to a `add dword ptr [rip+disp32], 0x3e8`
//! instruction whose disp32 resolves to `GAMESTATE_PTR + 0x308`.
//! No other site in the binary adds the constant 0x3e8 to a
//! RIP-relative dword, so the signature is unique by construction.
//!
//! Contract (asserted by this test):
//!
//!   1. `targets.resolve.gamestate_ptr` returns a non-null
//!      runtime address.
//!   2. That address is inside the loaded image's `.data` /
//!      `.rdata` neighbourhood (i.e. close to but distinct from
//!      `image_base()`).
//!   3. Gated on `MODFORGE_EXPECT_LOADED=1` (so CI at the main
//!      menu doesn't false-fail): reading `+0x308` from the
//!      resolved address returns a u32 in `[0, 10_000_000]`. That
//!      catches the original bug: a resolved address whose +0x308
//!      reads as fill-pattern garbage (e.g. 16842752) fails this.

mod common;

use serde_json::{json, Value};

fn u64_of(v: &Value, key: &str) -> Option<u64> {
    v.get(key)
        .and_then(|x| x.as_str())
        .and_then(|s| u64::from_str_radix(s.trim_start_matches("0x"), 16).ok())
}

#[test]
fn gamestate_ptr_resolves_via_sleuth() {
    let Some(game) = common::launch("r3_gamestate_resolves") else {
        return;
    };
    let resp = game
        .op_json("targets.resolve.gamestate_ptr", &json!({}))
        .expect("targets.resolve.gamestate_ptr must succeed");
    let result = resp
        .get("result")
        .expect("op response must include result");
    game.log()
        .event("R3", &format!("resolve result = {result:#}"));

    let resolved = u64_of(result, "address")
        .expect("result.address (hex string) missing");
    assert!(
        resolved != 0,
        "resolver returned null GAMESTATE_PTR: {result:#}"
    );

    let image_base = u64_of(result, "image_base")
        .expect("result.image_base (hex string) missing");
    let delta = resolved.saturating_sub(image_base);
    assert!(
        delta < 0x10_000_000,
        "resolved address {resolved:#x} is implausibly far from image_base \
         {image_base:#x} (delta {delta:#x})"
    );

    if std::env::var("MODFORGE_EXPECT_LOADED").ok().as_deref() == Some("1") {
        let money = result
            .get("money_at_resolved_plus_0x308")
            .and_then(|v| v.as_u64())
            .expect("result.money_at_resolved_plus_0x308 must be present");
        assert!(
            money <= 10_000_000,
            "money read at resolved+0x308 is implausibly large \
             ({money}); resolved address likely wrong. result = {result:#}"
        );
    }

    game.pass("R3 gamestate_ptr resolves to a plausible address");
}
