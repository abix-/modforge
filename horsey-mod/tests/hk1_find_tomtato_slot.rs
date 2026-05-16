//! HK1 Stage S0.5 probe: find which scene-table slot holds a known
//! horse (default name "tomtato"). User loads a save, puts the horse
//! into the truck, then we attach and locate it.
//!
//! Designed to run with MODFORGE_ATTACH=1 against an already-running
//! game so we don't lose the in-game state by relaunching.
//!
//! Env: HORSEY_HORSE=<name> (default "tomtato").

mod common;

use serde_json::{json, Value};

#[test]
fn find_horse_slot() {
    let Some(game) = common::launch("hk1_find_tomtato_slot") else { return; };
    let want_name = std::env::var("HORSEY_HORSE").unwrap_or_else(|_| "tomtato".to_string());
    let horses = common::list_owned(&game);
    let target = horses.iter().find_map(|h| {
        let n = h.get("name").and_then(Value::as_str)?;
        if n.eq_ignore_ascii_case(&want_name) {
            let p = h.get("ptr").and_then(Value::as_str)?;
            Some((n.to_string(), p.to_string()))
        } else { None }
    });
    let (name, ptr_s) = target.unwrap_or_else(|| {
        let names: Vec<_> = horses.iter().filter_map(|h| h.get("name").and_then(Value::as_str).map(String::from)).collect();
        panic!("HORSEY_HORSE='{want_name}' not owned. owned={names:?}");
    });
    let target_ptr = u64::from_str_radix(ptr_s.trim_start_matches("0x"), 16).expect("bad ptr");
    eprintln!("\nlooking for {name} at {ptr_s} ({target_ptr:#x})");

    let resp = game.op_json("hk1.probe.scene_slot_vtables", &json!({})).expect("scene slot op");
    let result = resp.get("result").unwrap_or(&resp);
    let arr_ptr_s = result.get("arr_ptr").and_then(Value::as_str).unwrap_or("0x0");
    let arr_ptr = u64::from_str_radix(arr_ptr_s.trim_start_matches("0x"), 16).unwrap_or(0);
    let image_base_s = result.get("image_base").and_then(Value::as_str).unwrap_or("0x0");
    eprintln!("arr_ptr = {arr_ptr_s}, image_base = {image_base_s}");
    let slots = result.get("slots").and_then(Value::as_array).cloned().unwrap_or_default();

    let mut hits = Vec::new();
    for s in &slots {
        let slot_s = s.get("slot").and_then(Value::as_str).unwrap_or("?");
        let sub_ptr_s = s.get("sub_ptr").and_then(Value::as_str).unwrap_or("0x0");
        let count = s.get("count").and_then(Value::as_u64);
        let Some(count) = count else { continue };
        let sub_ptr = u64::from_str_radix(sub_ptr_s.trim_start_matches("0x"), 16).unwrap_or(0);
        let vec_begin_addr = sub_ptr + 0x130;
        let begin_resp = game.op_json("mem.peek", &json!({"addr": vec_begin_addr, "kind": "u64"})).expect("mem.peek begin");
        let begin_s = begin_resp.get("result").and_then(|r| r.get("value")).and_then(Value::as_str).unwrap_or("0x0");
        let vec_begin = u64::from_str_radix(begin_s.trim_start_matches("0x"), 16).unwrap_or(0);
        if vec_begin == 0 { continue; }
        for i in 0..count {
            let p_addr = vec_begin + i * 8;
            let p_resp = game.op_json("mem.peek", &json!({"addr": p_addr, "kind": "u64"})).expect("mem.peek elem");
            let p_s = p_resp.get("result").and_then(|r| r.get("value")).and_then(Value::as_str).unwrap_or("0x0");
            let p = u64::from_str_radix(p_s.trim_start_matches("0x"), 16).unwrap_or(0);
            if p == target_ptr {
                hits.push(format!("slot {slot_s} idx {i} (vec_count={count})"));
            }
        }
    }
    eprintln!("\n{name} at {ptr_s} found in slots:");
    for h in &hits { eprintln!("  {h}"); }
    assert!(!hits.is_empty(), "{name} not found in any slot; not owned or in an unscanned slot");
    game.pass(&format!("{name} found in {} slot(s)", hits.len()));
}
