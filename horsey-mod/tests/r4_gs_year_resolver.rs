//! R4: verify `gs_offset::year()` resolves at runtime via
//! patternsleuth (anchored on the pause-menu format string) and
//! matches the hardcoded `gs_offset::YEAR` const for this build.

mod common;

use serde_json::{json, Value};

fn u64_of_hex(v: &Value, key: &str) -> Option<u64> {
    v.get(key).and_then(|x| x.as_str()).and_then(|s| u64::from_str_radix(s.trim_start_matches("0x"), 16).ok())
}

#[test]
fn gs_year_resolver_agrees_with_hardcoded() {
    let Some(game) = common::launch("r4_gs_year_resolver") else { return; };

    let resp = game
        .op_json("targets.resolve.field_offsets", &json!({}))
        .expect("targets.resolve.field_offsets must succeed");
    let result = resp.get("result").expect("result");
    let year = result.get("year").expect("year entry");
    let resolved = u64_of_hex(year, "resolved").expect("resolved");
    let hardcoded = u64_of_hex(year, "hardcoded").expect("hardcoded");
    game.log().event(
        "R4-YEAR",
        &format!("resolved=0x{resolved:x} hardcoded=0x{hardcoded:x}"),
    );

    assert_eq!(
        resolved, hardcoded,
        "year offset resolver mismatch: resolved=0x{resolved:x} hardcoded=0x{hardcoded:x}"
    );
    game.pass(&format!("gs_offset::year() resolves to 0x{resolved:x} (matches hardcoded)"));
}
