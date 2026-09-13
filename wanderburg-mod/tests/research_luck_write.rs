//! Can luck be raised from outside? Calls the game's own
//! ArtifactSystem.ModifyLuck(amount) once and reads
//! ArtifactSystem.addedLuck and CurrentLuck before and after.
//!
//! The luck fields live on ArtifactSystem, not on GM. Both sit on
//! the same game object (named GAMEMANAGER), which is how the
//! first scan misattributed them.
//!
//! This test CHANGES game state: it adds 0.25 luck to the current
//! run. Run it inside a run with the game window focused.
//!
//! ```text
//! k3sc cargo-lock test -p wanderburg-mod --test research_luck_write -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, first_handle, ping_or_skip};
use serde_json::{Value, json};

/// Added when no target is given.
const AMOUNT: f64 = 0.25;

/// Set `WANDERBURG_LUCK_TARGET=<number>` to move luck TO that
/// value instead: the test reads the current value and passes the
/// difference (positive or negative) to ModifyLuck.
fn target() -> Option<f64> {
    std::env::var("WANDERBURG_LUCK_TARGET").ok()?.parse().ok()
}

#[test]
fn modify_luck_once() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some(art) = first_handle(&api, "ArtifactSystem") else {
        println!("no live ArtifactSystem");
        return;
    };
    let read = |what: &str| -> Value {
        let f = api.op("read_field", json!({"handle": art, "field": what}));
        if f.ok && !f.result.is_null() {
            return f.result;
        }
        let g = api.op(
            "invoke_method",
            json!({"handle": art, "method": format!("get_{what}"), "args": []}),
        );
        if g.ok {
            return g.result;
        }
        json!({"read_field": f.error, "getter": g.error})
    };
    let before = read("addedLuck");
    println!("before: addedLuck={before} CurrentLuck={}", read("CurrentLuck"));
    let amount = match (target(), before.as_f64()) {
        (Some(t), Some(cur)) => t - cur,
        (Some(t), None) => {
            println!("target {t} given but current luck unreadable; not touching it");
            api.op("release_handle", json!({"handle": art}));
            return;
        }
        (None, _) => AMOUNT,
    };
    let r = api.op(
        "invoke_method",
        json!({"handle": art, "method": "ModifyLuck", "args": [amount]}),
    );
    println!("ArtifactSystem.ModifyLuck({amount}): ok={} result={} error={:?}", r.ok, r.result, r.error);
    println!("after:  addedLuck={} CurrentLuck={}", read("addedLuck"), read("CurrentLuck"));
    api.op("release_handle", json!({"handle": art}));
}
