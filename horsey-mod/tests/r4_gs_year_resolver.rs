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

    let sleeps = result.get("sleeps").expect("sleeps entry");
    let sresolved = u64_of_hex(sleeps, "resolved").expect("resolved");
    let shardcoded = u64_of_hex(sleeps, "hardcoded").expect("hardcoded");
    game.log().event(
        "R4-SLEEPS",
        &format!("resolved=0x{sresolved:x} hardcoded=0x{shardcoded:x}"),
    );
    assert_eq!(
        sresolved, shardcoded,
        "sleeps offset resolver mismatch: resolved=0x{sresolved:x} hardcoded=0x{shardcoded:x}"
    );

    let money = result.get("money").expect("money entry");
    let mresolved = u64_of_hex(money, "resolved").expect("resolved");
    let mhardcoded = u64_of_hex(money, "hardcoded").expect("hardcoded");
    game.log().event(
        "R4-MONEY",
        &format!("resolved=0x{mresolved:x} hardcoded=0x{mhardcoded:x}"),
    );
    assert_eq!(
        mresolved, mhardcoded,
        "money offset resolver mismatch: resolved=0x{mresolved:x} hardcoded=0x{mhardcoded:x}"
    );

    let ctx = result.get("horse_ctx_offset").expect("horse_ctx_offset entry");
    let cresolved = u64_of_hex(ctx, "resolved").expect("resolved");
    let chardcoded = u64_of_hex(ctx, "hardcoded").expect("hardcoded");
    game.log().event(
        "R4-CTX",
        &format!("resolved=0x{cresolved:x} hardcoded=0x{chardcoded:x}"),
    );
    assert_eq!(
        cresolved, chardcoded,
        "horse_ctx_offset resolver mismatch: resolved=0x{cresolved:x} hardcoded=0x{chardcoded:x}"
    );

    for (name, key) in &[
        ("tired_flag_a", "tired_flag_a"),
        ("tired_flag_b", "tired_flag_b"),
        ("horses_begin", "horses_begin"),
        ("horses_end",   "horses_end"),
        ("live_horses_begin", "live_horses_begin"),
        ("live_horses_end",   "live_horses_end"),
    ] {
        let entry = result.get(*key).unwrap_or_else(|| panic!("{name} entry"));
        let r = u64_of_hex(entry, "resolved").expect("resolved");
        let h = u64_of_hex(entry, "hardcoded").expect("hardcoded");
        game.log().event(
            "R4-EXTRA",
            &format!("{name}: resolved=0x{r:x} hardcoded=0x{h:x}"),
        );
        assert_eq!(r, h, "{name} mismatch: resolved=0x{r:x} hardcoded=0x{h:x}");
    }

    game.pass(&format!(
        "R4: year=0x{resolved:x} sleeps=0x{sresolved:x} money=0x{mresolved:x} ctx=0x{cresolved:x} +tired flags (all match hardcoded)"
    ));
}
