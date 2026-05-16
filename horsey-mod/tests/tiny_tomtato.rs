//! Counterpart to giant_tomtato: set tomtato's BX_GIANT_BABY allele
//! to MINIMUM (tier 0) so we can A/B compare the visible scale.

mod common;

use serde_json::{json, Value};

#[test]
fn make_tomtato_tiny() {
    let Some(game) = common::launch("tiny_tomtato") else { return };

    let arm = game.op_json("genes.ext.render.arm", &json!({})).unwrap();
    eprintln!("render.arm: {arm}");

    let owned = game.op_json("gamestate.owned_horses", &json!({})).unwrap();
    let horses = owned.get("result").and_then(|r| r.get("horses")).and_then(Value::as_array).cloned().unwrap_or_default();
    let tomtato = horses.iter().find(|h| {
        h.get("name").and_then(Value::as_str).map(|n| n.to_ascii_lowercase().contains("tomtato")).unwrap_or(false)
    });
    let Some(t) = tomtato else {
        panic!("no horse named 'tomtato' in owned list ({} horses)", horses.len());
    };
    let ptr = t.get("ptr").and_then(Value::as_str).unwrap_or("0x0");
    let id = u64::from_str_radix(ptr.trim_start_matches("0x"), 16).unwrap();
    eprintln!("tomtato ptr/id: {ptr} ({id})");

    let r = game.op_json("horse.ext.alleles.set", &json!({
        "horse_id":     id,
        "ext_gene_idx": 0,
        "maternal":     0,
        "paternal":     0,
    })).unwrap();
    eprintln!("alleles.set: {r}");
    assert_eq!(r.get("ok").and_then(Value::as_bool), Some(true), "alleles.set failed");

    eprintln!("[PASS] tomtato now TINY (allele tier 0); look in-game");
}
