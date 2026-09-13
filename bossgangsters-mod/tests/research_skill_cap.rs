//! Can Harmony patch the three methods that hardcode the skill
//! level cap of 10?
//!
//! From docs/skills.md the cap lives in:
//! - FighterHandler.AddSkillXp (refuses XP at abilityValue >= 10)
//! - EmployeeBase.CurrentAbilityValue (clamps effective level 1..10)
//! - FighterHandler.SetTemporaryVisionSkillLevel (clamps 1..10)
//!
//! harmony_probe applies a no-op prefix and unpatches, reporting
//! per-target patchability without a restart.
//!
//! ```text
//! cargo test -p bossgangsters-mod --test research_skill_cap -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

/// FighterSkill.Lockpicking: no side effects on level, safe to
/// drive for the proof.
const SKILL_LOCKPICKING: i64 = 7;

#[test]
fn skill_cap_methods_are_patchable() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let targets = [
        ("FighterHandler", "AddSkillXp"),
        ("EmployeeBase", "CurrentAbilityValue"),
        ("FighterHandler", "SetTemporaryVisionSkillLevel"),
    ];
    for (class, method) in targets {
        let res = api.op(
            "harmony_probe",
            json!({"class": class, "method": method, "ctx_kind": 0}),
        );
        if res.ok {
            println!("{class}.{method}: patchable ({})", res.result);
        } else {
            println!("{class}.{method}: NOT PATCHABLE ({:?})", res.error);
        }
    }
}

/// Proof the cap is 100 now: at level 10 vanilla AddSkillXp
/// refuses XP, so a level-up past 10 can only come from the mod's
/// patch. Sets Lockpicking to level 10, drives AddSkillXp past
/// the 550 XP threshold, expects level 11, then restores the
/// original level and progress.
#[test]
fn add_skill_xp_levels_past_10() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let handle_in = |res: &serde_json::Value| res.get("handle").and_then(|h| h.as_i64());

    let Some(club_player) = unityforge::client::first_handle_inactive(&api, "ClubPlayer") else {
        println!("ClubPlayer: no live instance; load a save first");
        return;
    };
    let fh = api.op(
        "read_field",
        json!({"handle": club_player, "field": "playerFighterHandler"}),
    );
    assert!(fh.ok, "playerFighterHandler read failed: {:?}", fh.error);
    let fighter = handle_in(&fh.result).expect("playerFighterHandler has no handle");

    let fd = api.op("read_field", json!({"handle": fighter, "field": "fighterData"}));
    assert!(fd.ok, "fighterData read failed: {:?}", fd.error);
    let fighter_data = handle_in(&fd.result).expect("fighterData has no handle");
    let ab = api.op(
        "read_field",
        json!({"handle": fighter_data, "field": "employeeAbilities"}),
    );
    assert!(ab.ok, "employeeAbilities read failed: {:?}", ab.error);
    let abilities = handle_in(&ab.result).expect("employeeAbilities has no handle");
    let el = api.op(
        "invoke_method",
        json!({"handle": abilities, "method": "GetValue", "args": [SKILL_LOCKPICKING]}),
    );
    assert!(el.ok, "GetValue failed: {:?}", el.error);
    let ability = handle_in(&el.result).expect("ability element has no handle");

    let read_i64 = |field: &str| -> i64 {
        let r = api.op("read_field", json!({"handle": ability, "field": field}));
        assert!(r.ok, "{field} read failed: {:?}", r.error);
        r.result.as_i64().or_else(|| r.result.as_f64().map(|f| f as i64)).unwrap()
    };
    let read_f64 = |field: &str| -> f64 {
        let r = api.op("read_field", json!({"handle": ability, "field": field}));
        assert!(r.ok, "{field} read failed: {:?}", r.error);
        r.result.as_f64().unwrap()
    };
    let write = |field: &str, value: serde_json::Value| {
        let r = api.op(
            "write_field",
            json!({"handle": ability, "field": field, "value": value}),
        );
        assert!(r.ok, "{field} write failed: {:?}", r.error);
    };

    let orig_level = read_i64("abilityValue");
    let orig_progress = read_f64("progressValue");
    println!("Lockpicking before: level {orig_level}, progress {orig_progress}");

    write("abilityValue", json!(10));
    write("progressValue", json!(0.0));

    // Level 10 -> 11 needs 550 XP; 600 clears it at any multiplier.
    let inv = api.op(
        "invoke_method",
        json!({"handle": fighter, "method": "AddSkillXp", "args": [SKILL_LOCKPICKING, 600.0]}),
    );
    assert!(inv.ok, "AddSkillXp failed: {:?}", inv.error);

    let after_level = read_i64("abilityValue");
    let after_progress = read_f64("progressValue");
    println!("Lockpicking after 600 XP at level 10: level {after_level}, progress {after_progress}");

    // Restore before asserting so a failure does not leave the
    // save altered.
    write("abilityValue", json!(orig_level));
    write("progressValue", json!(orig_progress));
    println!("Lockpicking restored: level {orig_level}, progress {orig_progress}");

    assert_eq!(
        after_level, 11,
        "level did not pass 10; the cap patch is not active"
    );
}
