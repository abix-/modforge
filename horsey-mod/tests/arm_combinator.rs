//! Arm the D3.4 breeding-combinator detour and assert it actually
//! fires. Catches the difference between "the address is right and
//! arming succeeds" and "vanilla actually calls into our handler at
//! runtime."
//!
//! Strategy:
//!   1. Launch game + inject mod (harness).
//!   2. dryrun -> verify address before arming. If dryrun fails, the
//!      arm step would crash; abort early with a clear message.
//!   3. arm -> assert {"armed": true}.
//!   4. Wait several seconds. The breeding combinator fires whenever
//!      vanilla creates a child horse: birth events, CRISPR clone,
//!      pop respawn. Idle game time in the menu may produce zero
//!      breedings; that's OK for this smoke test.
//!   5. stats -> read counters. Assert:
//!        - call_count is >= 0 (handler hasn't panicked the game).
//!        - combines_done == call_count (every fire reached our
//!          slow path; nothing got dropped).
//!   6. disarm -> assert {"armed": false}. Game must still be
//!      running after disarm (the test's Drop verifies this by
//!      not crashing during teardown).
//!
//! Note: this test does NOT prove the COMBINATOR EFFECT (child
//! actually inherits ext alleles). That's a future test that needs
//! a save loaded + a breeding action triggered. This test just
//! proves the wiring survives an arm + tear-down cycle without
//! crashing.

mod common;

use serde_json::{Value, json};
use std::thread;
use std::time::Duration;

fn as_u64(v: &Value, key: &str) -> Option<u64> {
    v.get(key).and_then(|x| x.as_u64())
}

#[test]
fn arm_combinator_does_not_crash() {
    let Some(game) = common::launch("arm_combinator") else {
        return;
    };

    // Step 1: dryrun. Refuse to arm if address looks bad.
    let dr = game
        .op_json("genes.ext.combinator.dryrun", &json!({}))
        .expect("combinator dryrun should succeed");
    let dr_result = dr
        .get("result")
        .expect("dryrun envelope should have result");
    let prologue = dr_result
        .get("prologue_bytes")
        .and_then(|v| v.as_str())
        .unwrap_or("");
    game.log()
        .event("PRECHECK", &format!("combinator prologue: [{prologue}]"));
    // Sanity: first byte must NOT be 0xcc (INT3 padding) or we'd
    // arm into garbage.
    let first = prologue.split_whitespace().next().unwrap_or("");
    assert_ne!(
        first, "cc",
        "combinator dryrun shows INT3 padding at target; refusing to arm"
    );

    // Step 2: arm.
    let arm = game
        .op_json("genes.ext.combinator.arm", &json!({}))
        .expect("combinator arm op should succeed");
    let armed = arm
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(false);
    assert!(armed, "combinator arm did not report armed=true: {arm}");
    game.log().event("ARM", "combinator armed");

    // Step 3: idle for a few seconds so any incidental breeding has
    // a chance to fire. We're at the main menu / wherever Steam
    // dropped us; typically no breeding fires, but the test still
    // proves the detour didn't crash the game.
    let idle = Duration::from_secs(3);
    game.log()
        .event("WAIT", &format!("idling {}s for incidental breedings", idle.as_secs()));
    thread::sleep(idle);

    // Step 4: stats. The mod must still be reachable (didn't crash)
    // and combines_done must equal call_count (every fire reached
    // our slow path).
    let stats = game
        .op_json("genes.ext.combinator.stats", &json!({}))
        .expect("combinator stats op should succeed");
    let s = stats
        .get("result")
        .expect("stats envelope should have result");
    let call_count = as_u64(s, "call_count").unwrap_or(u64::MAX);
    let combines_done = as_u64(s, "combines_done").unwrap_or(u64::MAX);
    game.log().event(
        "STATS",
        &format!("call_count={call_count} combines_done={combines_done}"),
    );
    assert!(
        call_count <= 1_000_000,
        "absurd call_count {call_count}; detour probably looping"
    );
    assert_eq!(
        call_count, combines_done,
        "combines_done ({combines_done}) != call_count ({call_count}); \
         some firings missed our slow path"
    );

    // Step 5: disarm.
    let disarm = game
        .op_json("genes.ext.combinator.disarm", &json!({}))
        .expect("combinator disarm should succeed");
    let armed_after = disarm
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(true);
    assert!(!armed_after, "disarm did not clear armed flag: {disarm}");
    game.log().event("DISARM", "combinator disarmed cleanly");

    // Step 6: post-disarm ping confirms the game is still alive.
    game.op_json("ping", &json!({}))
        .expect("game must still be alive after disarm");
    game.pass("combinator arm + idle + disarm survived without crash");
}
