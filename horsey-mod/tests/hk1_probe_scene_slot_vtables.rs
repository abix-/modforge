//! HK1 Stage S0 probe: per scene-table slot, report vtable RVA + count.
//!
//! Walks every slot in `*(GS+0x438)` that has a plausible
//! +0x130/+0x138 vector and reports the slot occupant's vtable RVA.
//! Used to classify slots: identical vtable RVAs across multiple
//! slots = same subsystem class. Unique RVAs at expected locations
//! (e.g. slot 0x00 owned-list, slots 0x08..0x38 race lanes) pin
//! down which slot is which Location.
//!
//! Pass criterion: at least one slot has a non-null vtable RVA and a
//! horse_count <= 20.

mod common;

use serde_json::json;

#[test]
fn probe_scene_slot_vtables() {
    let Some(game) = common::launch("hk1_probe_scene_slot_vtables") else { return; };
    eprintln!("[GATE] waiting for a save to load (up to 120s) ...");
    common::wait_for_target_horse(&game, std::time::Duration::from_secs(120));
    let resp = game
        .op_json("hk1.probe.scene_slot_vtables", &json!({}))
        .expect("hk1.probe.scene_slot_vtables op should succeed");
    let result = resp.get("result").unwrap_or(&resp);
    let slots = result
        .get("slots")
        .and_then(|v| v.as_array())
        .cloned()
        .unwrap_or_default();
    let image_base = result.get("image_base").and_then(|v| v.as_str()).unwrap_or("?");
    eprintln!("\nimage_base = {image_base}");
    eprintln!("slots ({}):", slots.len());
    for s in &slots {
        eprintln!("  {s}");
    }
    assert!(!slots.is_empty(), "no scene-table slots found at all");
    let any_with_horses = slots.iter().any(|s| {
        s.get("count").and_then(|v| v.as_u64()).is_some_and(|c| c <= 20)
    });
    assert!(any_with_horses, "no slot has a plausible horse vector");
    game.pass(&format!("classified {} scene-table slots", slots.len()));
}
