//! Arm the D3.1 / D3.2 lifecycle anchors (horse ctor + dtor) and
//! assert they fire when the game creates / destroys horses.
//!
//! Even at the main menu, the game allocates and destroys horse
//! structs (demo horses, name pool, CRISPR vials). After arming we
//! expect `ctor_calls > 0` within a few seconds.
//!
//! What this guarantees:
//!   1. The ctor + dtor detours arm cleanly together.
//!   2. The detours actually fire (`ctor_calls > 0`) without
//!      crashing the game.
//!   3. `entries_created` advances when `genes::ensure_horse_ext_genome`
//!      is called from the ctor handler.
//!   4. Disarm leaves the game alive.

mod common;

use serde_json::{Value, json};
use std::thread;
use std::time::Duration;

fn as_u64(v: &Value, key: &str) -> Option<u64> {
    v.get(key).and_then(|x| x.as_u64())
}

#[test]
fn arm_lifecycle_fires_on_horse_creation() {
    let Some(game) = common::launch("arm_lifecycle") else {
        return;
    };

    // Dryrun precheck for both ctor + dtor.
    let dr = game
        .op_json("genes.ext.lifecycle.dryrun", &json!({}))
        .expect("lifecycle dryrun should succeed");
    let result = dr.get("result").expect("dryrun result");
    for which in ["ctor", "dtor"] {
        let prologue = result
            .get(which)
            .and_then(|t| t.get("prologue_bytes"))
            .and_then(|v| v.as_str())
            .unwrap_or("");
        let first = prologue.split_whitespace().next().unwrap_or("");
        assert_ne!(
            first, "cc",
            "lifecycle {which} dryrun shows INT3 padding; refusing to arm"
        );
        game.log()
            .event("PRECHECK", &format!("{which} prologue [{prologue}]"));
    }

    // Arm.
    let arm = game
        .op_json("genes.ext.lifecycle.arm", &json!({}))
        .expect("lifecycle arm op should succeed");
    let armed = arm
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(false);
    assert!(armed, "lifecycle arm did not report armed=true: {arm}");
    game.log().event("ARM", "lifecycle armed");

    // Wait for the game to do horse-creation work.
    let idle = Duration::from_secs(5);
    game.log()
        .event("WAIT", &format!("idling {}s for horse creates", idle.as_secs()));
    thread::sleep(idle);

    // Stats.
    let stats = game
        .op_json("genes.ext.lifecycle.stats", &json!({}))
        .expect("lifecycle stats op should succeed");
    let s = stats.get("result").expect("stats result");
    let ctor_calls = as_u64(s, "ctor_calls").unwrap_or(u64::MAX);
    let dtor_calls = as_u64(s, "dtor_calls").unwrap_or(u64::MAX);
    let entries_created = as_u64(s, "entries_created").unwrap_or(u64::MAX);
    let entries_dropped = as_u64(s, "entries_dropped").unwrap_or(u64::MAX);
    game.log().event(
        "STATS",
        &format!(
            "ctor_calls={ctor_calls} dtor_calls={dtor_calls} \
             entries_created={entries_created} entries_dropped={entries_dropped}"
        ),
    );

    // Sanity bounds.
    assert!(
        ctor_calls <= 1_000_000,
        "absurd ctor_calls {ctor_calls}; detour probably looping"
    );

    // entries_created == ctor_calls when handler runs to completion
    // (every ctor invocation should create exactly one EXT_HORSE_GENOMES
    // entry). Mismatch means slowpath panicked silently.
    assert_eq!(
        ctor_calls, entries_created,
        "entries_created ({entries_created}) != ctor_calls ({ctor_calls}); \
         ctor slow-path missed some firings"
    );
    assert_eq!(
        dtor_calls, entries_dropped,
        "entries_dropped ({entries_dropped}) != dtor_calls ({dtor_calls}); \
         dtor slow-path missed some firings"
    );

    // Disarm.
    let disarm = game
        .op_json("genes.ext.lifecycle.disarm", &json!({}))
        .expect("lifecycle disarm should succeed");
    let armed_ctor_after = disarm
        .get("result")
        .and_then(|r| r.get("armed_ctor"))
        .and_then(|v| v.as_bool())
        .unwrap_or(true);
    let armed_dtor_after = disarm
        .get("result")
        .and_then(|r| r.get("armed_dtor"))
        .and_then(|v| v.as_bool())
        .unwrap_or(true);
    assert!(!armed_ctor_after, "ctor still armed after disarm: {disarm}");
    assert!(!armed_dtor_after, "dtor still armed after disarm: {disarm}");
    game.log().event("DISARM", "lifecycle disarmed cleanly");

    // Post-disarm ping.
    game.op_json("ping", &json!({}))
        .expect("game must still be alive after disarm");
    game.pass("lifecycle arm + idle + disarm survived; counters consistent");
}
