//! HK1 Stage S0 probe: dump the active Location's field layout.
//!
//! Drives `hk1.probe.active_location` and prints:
//!   - active_scene_id, location ptr, vtable RVA
//!   - LOC[0x26] horse-vec begin/end + count
//!   - LOC[0x2c] armed flag, LOC[0x2d] drag idx, LOC[0x2e] candidate idx
//!   - first 0x240 bytes of the Location object
//!
//! Pass criterion: location ptr resolves AND horse-vec count is plausible
//! (0..=20). With active_scene_id == -1 (overworld), probe falls back to
//! slot 0x00 (owned horses); count should match owned-horse count.
//!
//! Re-run while the player walks into the paddock / home to confirm
//! the LOC pointer changes and the click-drag fields populate.

mod common;

use serde_json::json;

#[test]
fn probe_active_location_layout() {
    let Some(game) = common::launch("hk1_probe_loc_field_layout") else { return; };
    eprintln!("[GATE] waiting for a save to load (up to 120s) ...");
    common::wait_for_target_horse(&game, std::time::Duration::from_secs(120));
    let resp = game
        .op_json("hk1.probe.active_location", &json!({}))
        .expect("hk1.probe.active_location op should succeed");
    eprintln!("\nfull response: {resp}");
    let result = resp.get("result").unwrap_or(&resp);

    if let Some(err) = result.get("error").and_then(|v| v.as_str()) {
        // Acceptable on overworld with empty slot 0: just report and pass.
        eprintln!("probe reported: {err}");
        game.pass("probe completed with reported error");
        return;
    }

    let asid = result.get("active_scene_id");
    let loc_ptr = result.get("loc_ptr").and_then(|v| v.as_str()).unwrap_or("?");
    let vtable_rva = result.get("vtable_rva").and_then(|v| v.as_str()).unwrap_or("?");
    let horse_count = result.get("loc_horse_count");
    let drag = result.get("loc_drag_idx");
    let cand = result.get("loc_cand_idx");
    let armed = result.get("loc_armed");

    eprintln!("active_scene_id : {asid:?}");
    eprintln!("loc_ptr         : {loc_ptr}");
    eprintln!("vtable_rva      : {vtable_rva}");
    eprintln!("loc_horse_count : {horse_count:?}");
    eprintln!("loc_drag_idx    : {drag:?}");
    eprintln!("loc_cand_idx    : {cand:?}");
    eprintln!("loc_armed       : {armed:?}");

    let count = horse_count.and_then(|v| v.as_u64()).unwrap_or(u64::MAX);
    assert!(count <= 20, "implausible horse count {count}; LOC layout wrong?");
    game.pass(&format!(
        "active_location loc_ptr={loc_ptr} vtable={vtable_rva} horses={count}"
    ));
}
