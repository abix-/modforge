// Per-skill test: impact_resistance.
//
// USER EXPECTATION (post-fix 2026-05-09):
//   - Enabling impact_resistance does NOT block bandages or
//     other healing.
//   - The mask field RequiredDamageTypeFlags is NOT written
//     by this skill (proof the binary-mask hack is gone).
//   - Environmental damage gets reduced when the skill is
//     above level 0; at L100, reduction is full.
//
// The damage-reduction half is harder to test without a real
// environmental event firing. We assert what we can directly:
// that the mask is NOT 0xFFFFFFFF when impact_resistance is
// active. The end-to-end environmental reduction is covered
// by `tests/bandage_regression.rs` (proves bandages still
// work) plus the in-game manual rock-collision test logged
// via `damage_ring`.

mod common;

#[test]
fn impact_resistance_does_not_write_required_damage_type_flags_mask() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    if s.live_player.is_none() {
        panic!("no live player; load a save and spawn into the world");
    }

    // Make sure impact_resistance is enabled with at least L1 so
    // any apply path that *would* set the mask gets a chance.
    if s.skill_level("impact_resistance") == 0 {
        if s.player_state.as_ref().unwrap().skill_points < 1 {
            eprintln!("skipping: need 1 skill point to take impact_resistance");
            return;
        }
        api.skill_spend("impact_resistance", 1);
    }
    api.skill_toggle("impact_resistance", true);

    let post = api.snapshot();
    let mask = &post.live_hc().required_damage_type_flags;
    assert_ne!(
        mask, "0xFFFFFFFF",
        "REGRESSION: the binary RequiredDamageTypeFlags mask is back. \
         impact_resistance should NEVER write 0xFFFFFFFF -- that mask \
         broke bandages. Skill must be a Runtime intercept on \
         ApplyDamageFromInfo, not a CDO field write."
    );
    eprintln!(
        "  mask after impact_resistance enabled at L{} = {} (expected NOT 0xFFFFFFFF)",
        post.skill_level("impact_resistance"),
        mask
    );
}

#[test]
fn impact_resistance_runtime_variant_is_in_catalog() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let entry = s
        .catalog
        .iter()
        .find(|c| c.id == "impact_resistance")
        .expect("impact_resistance not in catalog");
    assert_eq!(
        entry.effect_kind, "Runtime",
        "impact_resistance must be a Runtime effect. The previous \
         PlayerHealthCompU32Mask shape blocked bandages."
    );
}
