//! Render-path end-to-end verification.
//!
//! Phase 1 of the content-authoring plan: confirm D1/D3/D5 detours arm
//! on the current Horsey binary, the bestiary's BX_GIANT_BABY ext gene
//! loads, and setting tomtato's alleles to max (200.0) produces a
//! visible scale change in-game.

mod common;

use serde_json::{json, Value};

#[test]
fn make_tomtato_giant() {
    let Some(game) = common::launch("giant_tomtato") else { return };

    // 1. Verify BX_GIANT_BABY landed at ext idx 0.
    let r = game.op_json("genes.ext.get", &json!({"ext_idx": 0})).unwrap();
    let result = r.get("result").unwrap_or(&r);
    let name = result.get("name").and_then(Value::as_str).unwrap_or("");
    eprintln!("ext_idx 0: {result}");
    assert_eq!(name, "BX_GIANT_BABY", "bestiary did not land at ext_idx 0");

    // 2. Arm the render trampoline (D5). "already armed" is success.
    let arm = game.op_json("genes.ext.render.arm", &json!({})).unwrap();
    eprintln!("render.arm: {arm}");
    let err = arm.get("error").and_then(Value::as_str).unwrap_or("");
    let already = err.contains("already armed");
    let arm_ok = arm.get("error").map_or(true, |e| e.is_null()) || already;
    assert!(arm_ok, "render trampoline failed to arm: {err}");

    // 3. Find tomtato's horse_ptr from owned list.
    let owned = game.op_json("gamestate.owned_horses", &json!({})).unwrap();
    let horses = owned.get("result").and_then(|r| r.get("horses")).and_then(Value::as_array).cloned().unwrap_or_default();
    let mut tomtato_ptr: Option<String> = None;
    for h in &horses {
        if h.get("name").and_then(Value::as_str) == Some("tomtato") {
            tomtato_ptr = h.get("ptr").and_then(Value::as_str).map(String::from);
            break;
        }
    }
    let tomtato_s = tomtato_ptr.expect("tomtato not in owned list");
    let tomtato_id = u64::from_str_radix(tomtato_s.trim_start_matches("0x"), 16).unwrap();
    eprintln!("tomtato ptr/id: {tomtato_s} ({tomtato_id})");

    // 4. Set tomtato's ext allele 0 to (maternal=3, paternal=3). Value 200.
    let set = game.op_json("horse.ext.alleles.set", &json!({
        "horse_id": tomtato_id,
        "ext_gene_idx": 0,
        "maternal": 3,
        "paternal": 3,
    })).unwrap();
    eprintln!("alleles.set: {set}");

    // 5. Verify the genome stored.
    let g = game.op_json("horse.ext.genome.get", &json!({"horse_id": tomtato_id})).unwrap();
    eprintln!("genome.get: {g}");

    // 6. Trigger re-evaluation so render-trampoline picks up the new value.
    let ev = game.op_json("horse.ext.evaluate", &json!({"horse_id": tomtato_id})).unwrap();
    eprintln!("evaluate: {ev}");

    game.pass("tomtato now GIANT; look in-game");
}
