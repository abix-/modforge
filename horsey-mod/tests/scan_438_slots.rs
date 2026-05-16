//! Diagnostic: dump every (*(GS+0x438) + slot) +0x130/+0x138 horse-vector count.
//! User picks the slot whose count matches their in-game owned-horse count.

mod common;

use serde_json::{json, Value};

#[test]
fn dump_slot_horse_counts() {
    let Some(game) = common::launch("scan_438_slots") else {
        return;
    };
    let resp = game
        .op_json("gamestate.scan_438_slots", &json!({}))
        .expect("scan_438_slots op should succeed");
    eprintln!("\nfull response: {resp}");
    let result = resp.get("result").unwrap_or(&resp);
    eprintln!("\narr_ptr: {:?}", result.get("arr_ptr"));
    let slots = result
        .get("slots_with_horse_vec")
        .and_then(Value::as_array)
        .cloned()
        .unwrap_or_default();
    eprintln!("slots_with_horse_vec ({} entries):", slots.len());
    for s in &slots {
        eprintln!("  {s}");
    }
    game.pass(&format!("scanned {} slots", slots.len()));
}
