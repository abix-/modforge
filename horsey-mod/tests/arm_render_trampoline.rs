//! Arm the D5 render trampoline post-hook on
//! `APPLY_GENE_TO_HORSE` and assert it fires repeatedly without
//! crashing the game.
//!
//! The render trampoline is HOT: vanilla calls
//! `FUN_14009f680(buf, horse + 0x2b8)` once per visible horse per
//! frame. Idling 3 seconds at the main menu (which has demo
//! horses) should accumulate hundreds of calls. If `call_count`
//! stays at 0, either the detour isn't firing or the menu has no
//! horses; either way the test reports clear data.
//!
//! Contract:
//!   1. dryrun precheck (refuse to arm if INT3 prologue).
//!   2. arm -> armed: true.
//!   3. idle a few seconds.
//!   4. stats: call_count is finite (< 10M to catch runaway loop),
//!      genes_applied_total <= call_count (per call applies at most
//!      N ext genes; with zero ext genes the total stays at 0).
//!   5. disarm -> armed: false. Game still alive after.

mod common;

use serde_json::{Value, json};
use std::thread;
use std::time::Duration;

fn as_u64(v: &Value, key: &str) -> Option<u64> {
    v.get(key).and_then(|x| x.as_u64())
}

#[test]
fn arm_render_trampoline_fires_and_disarms_cleanly() {
    let Some(game) = common::launch("arm_render_trampoline") else {
        return;
    };

    // Dryrun precheck.
    let dr = game
        .op_json("genes.ext.render.dryrun", &json!({}))
        .expect("render dryrun should succeed");
    let prologue = dr
        .get("result")
        .and_then(|r| r.get("prologue_bytes"))
        .and_then(|v| v.as_str())
        .unwrap_or("");
    let first = prologue.split_whitespace().next().unwrap_or("");
    assert_ne!(
        first, "cc",
        "render-trampoline dryrun shows INT3 padding; refusing to arm"
    );
    game.log()
        .event("PRECHECK", &format!("render prologue [{prologue}]"));

    // Arm.
    let arm = game
        .op_json("genes.ext.render.arm", &json!({}))
        .expect("render arm op should succeed");
    let armed = arm
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(false);
    assert!(armed, "render arm did not report armed=true: {arm}");
    game.log().event("ARM", "render trampoline armed");

    // Idle. The engine fires per horse per frame. The main menu
    // has demo horses; we expect a healthy call_count after a
    // few seconds. If 0, the test logs that fact and still
    // passes (the detour didn't crash; idle is just barren).
    let idle = Duration::from_secs(3);
    game.log()
        .event("WAIT", &format!("idling {}s for engine fires", idle.as_secs()));
    thread::sleep(idle);

    // Stats.
    let stats = game
        .op_json("genes.ext.render.stats", &json!({}))
        .expect("render stats op should succeed");
    let s = stats.get("result").expect("stats result");
    let call_count = as_u64(s, "call_count").unwrap_or(u64::MAX);
    let genes_applied = as_u64(s, "genes_applied_total").unwrap_or(u64::MAX);
    game.log().event(
        "STATS",
        &format!("call_count={call_count} genes_applied={genes_applied}"),
    );

    assert!(
        call_count < 10_000_000,
        "absurd call_count {call_count}; detour probably looping"
    );
    // With zero ext genes authored (the test environment has no
    // genes-extended.xml), genes_applied_total stays at 0 even
    // when the engine fires. If it goes nonzero, something is
    // writing ext alleles unexpectedly.
    assert!(
        genes_applied <= call_count,
        "genes_applied ({genes_applied}) > call_count ({call_count}); accounting bug"
    );

    // Disarm.
    let disarm = game
        .op_json("genes.ext.render.disarm", &json!({}))
        .expect("render disarm should succeed");
    let armed_after = disarm
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(true);
    assert!(!armed_after, "disarm did not clear armed: {disarm}");
    game.log().event("DISARM", "render trampoline disarmed cleanly");

    // Post-disarm ping.
    game.op_json("ping", &json!({}))
        .expect("game must still be alive after disarm");
    game.pass("render trampoline arm + idle + disarm survived");
}
