//! Regression: the GAMESTATE_PTR resolver finds the live slot, its
//! deref looks like a real save, and owned_horses populates. Trips
//! fast on the next slot drift across Horsey builds; the 2026-05-17
//! +0x1110 drift silently broke every gamestate-dependent op for a
//! whole session before this test existed.
//!
//! Default: fresh launch via the harness (canonical contract). Per
//! the skill, the game auto-loads the save on every launch, so
//! gamestate is live by the time HTTP comes up. To probe an
//! already-running session interactively, set `MODFORGE_ATTACH=1`.

mod common;

use serde_json::{json, Value};

#[test]
fn gamestate_resolver_is_alive() {
    let Some(game) = common::launch("gamestate_resolver_lives") else { return };

    let v = game.op_json("targets.resolve.gamestate_ptr", &json!({}))
        .expect("resolve op");
    let r = v.get("result").unwrap_or(&v);
    eprintln!("[RESOLVE] {}", serde_json::to_string_pretty(r).unwrap());

    let deref = r.get("deref").and_then(Value::as_str).unwrap_or("");
    let money = r.get("money_at_deref_plus_0x308");
    assert!(
        money.map(|m| !m.is_null()).unwrap_or(false),
        "money_at_deref_plus_0x308 is null -- resolver still broken. deref={deref}"
    );

    let owned = common::list_owned(&game);
    eprintln!("[OWNED] {} horse(s)", owned.len());
    for h in &owned {
        let n = h.get("name").and_then(Value::as_str).unwrap_or("?");
        eprintln!("  - {n}");
    }
    assert!(!owned.is_empty(), "owned_horses empty -- GS deref worked but horse list reader broke");
}
