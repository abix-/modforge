//! Full diagnostic snapshot: stats + dryrun for every ext-gene
//! detour, plus current armed state. Run this to get the whole
//! status table at once.
mod common;
use serde_json::{json, Value};

fn run(game: &modforge::harness::RunningGame, op: &str) {
    let r = game.op_json(op, &json!({})).unwrap_or(Value::Null);
    let res = r.get("result").unwrap_or(&r);
    let err = r.get("error").and_then(Value::as_str).unwrap_or("");
    eprintln!("\n--- {op} ---\nresult: {res}\nerror:  {err}");
}

#[test]
fn snapshot() {
    let Some(game) = common::launch("render_stats") else { return };
    eprintln!("\n=== STATS ===");
    for op in [
        "genes.ext.stats",
        "genes.ext.render.stats",
        "genes.ext.combinator.stats",
        "genes.ext.lifecycle.stats",
        "genes.ext.save.stats",
    ] {
        run(&game, op);
    }
    eprintln!("\n=== DRYRUN (what each detour expects to patch) ===");
    for op in [
        "genes.ext.dryrun",
        "genes.ext.render.dryrun",
        "genes.ext.combinator.dryrun",
        "genes.ext.lifecycle.dryrun",
        "genes.ext.save.dryrun",
    ] {
        run(&game, op);
    }
}
