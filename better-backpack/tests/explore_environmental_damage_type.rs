// Discovery: read BP_EnvironmentalDamage_C's CDO to find:
//   - its DamageTypeFlags (uint32 @ +0x60 on USurvivalDamageType)
//     -> tells us which ESurvivalDamageTypeFlags bits the engine
//        uses to identify environmental damage. A status effect
//        with matching DamageTypeFlags would filter to apply only
//        to environmental damage.
//   - bCanApplyDamageReductionFromStatusEffect (bool @ +0x67)
//     -> whether environmental damage even respects status-effect
//        reduction. If false, status effects can't help us.
//   - bCanApplyDamageReductionFromEquipment (bool @ +0x66)
//     -> whether equipment (armor) reduces environmental damage.
//        Confirms what the engine's gear pipeline does.
//
// Pure test code -- uses walk_class + read_bytes primitives.
//
// Run:
//   set BBP_DEBUG_PORT=17171
//   cargo test --release --target x86_64-pc-windows-msvc \
//     --test explore_environmental_damage_type -- --nocapture --test-threads=1

mod common;

use serde_json::json;

#[test]
fn read_environmental_damage_cdo() {
    let api = common::Api::require();

    // Walk the BP_EnvironmentalDamage_C class with CDOs included.
    // A class typically has exactly one default object.
    let r = api.op(
        "walk_class",
        json!({
            "class": "BP_EnvironmentalDamage_C",
            "max": 16,
            "include_cdo": true,
        }),
    );
    let instances = r.result.get("instances").and_then(|v| v.as_array()).unwrap();
    eprintln!("walk_class returned {} instance(s)", instances.len());
    for inst in instances {
        eprintln!("  {}", inst);
    }

    // The CDO's `is_cdo` field is true; pick that one.
    let cdo = instances
        .iter()
        .find(|i| i.get("is_cdo").and_then(|v| v.as_bool()).unwrap_or(false))
        .expect("no CDO found for BP_EnvironmentalDamage_C");
    let cdo_addr = cdo.get("addr_selector").and_then(|v| v.as_str()).unwrap();
    eprintln!("\nCDO selector: {cdo_addr}");

    // Read the relevant fields. USurvivalDamageType layout:
    //   +0x60 uint32 DamageTypeFlags
    //   +0x64 bool   bCanBlock
    //   +0x65 bool   bCanBlockWithWeapon
    //   +0x66 bool   bCanApplyDamageReductionFromEquipment
    //   +0x67 bool   bCanApplyDamageReductionFromStatusEffect
    //   +0x68 bool   bCanPlayHitReaction
    //   +0x69 bool   bDamageDurability
    //   +0x6A bool   bCanKill
    //   +0x6B bool   bCanRepair
    //   +0x6C bool   bAppliesEffectsOnDamageOverTime
    //   +0x6D bool   bCanIncapacitate
    let r = api.op(
        "read_bytes",
        json!({
            "instance_selector": cdo_addr,
            "offset": 0x60,
            "length": 0x10,
        }),
    );
    assert!(r.ok, "read_bytes failed: {:?}", r.error);
    let bytes = common::hex_decode(
        r.result.get("bytes_hex").and_then(|v| v.as_str()).unwrap(),
    )
    .unwrap();

    let damage_type_flags = u32::from_le_bytes(bytes[0..4].try_into().unwrap());
    let b_can_block = bytes[4];
    let b_can_block_with_weapon = bytes[5];
    let b_can_apply_dr_equipment = bytes[6];
    let b_can_apply_dr_status_effect = bytes[7];
    let b_can_play_hit_react = bytes[8];
    let b_damage_durability = bytes[9];
    let b_can_kill = bytes[10];
    let b_can_repair = bytes[11];
    let b_applies_effects_dot = bytes[12];
    let b_can_incapacitate = bytes[13];

    eprintln!("\n=== BP_EnvironmentalDamage_C CDO fields ===");
    eprintln!("  DamageTypeFlags                          = 0x{:08x}", damage_type_flags);
    eprintln!("    (bits set: {:?})", flags_set(damage_type_flags));
    eprintln!("  bCanBlock                                = {}", b_can_block != 0);
    eprintln!("  bCanBlockWithWeapon                      = {}", b_can_block_with_weapon != 0);
    eprintln!("  bCanApplyDamageReductionFromEquipment    = {}", b_can_apply_dr_equipment != 0);
    eprintln!("  bCanApplyDamageReductionFromStatusEffect = {}", b_can_apply_dr_status_effect != 0);
    eprintln!("  bCanPlayHitReaction                      = {}", b_can_play_hit_react != 0);
    eprintln!("  bDamageDurability                        = {}", b_damage_durability != 0);
    eprintln!("  bCanKill                                 = {}", b_can_kill != 0);
    eprintln!("  bCanRepair                               = {}", b_can_repair != 0);
    eprintln!("  bAppliesEffectsOnDamageOverTime          = {}", b_applies_effects_dot != 0);
    eprintln!("  bCanIncapacitate                         = {}", b_can_incapacitate != 0);

    eprintln!("\n=== Implications ===");
    if b_can_apply_dr_status_effect != 0 {
        eprintln!(
            "  bCanApplyDamageReductionFromStatusEffect = TRUE: a status effect with matching"
        );
        eprintln!(
            "  DamageTypeFlags would reduce environmental damage. The proper fix is to add"
        );
        eprintln!(
            "  a Type=DamageReduction (29) or Type=DamageReductionMultiplier (30) status effect"
        );
        eprintln!(
            "  with DamageTypeFlags = 0x{:08x} (matching environmental).",
            damage_type_flags
        );
    } else {
        eprintln!(
            "  bCanApplyDamageReductionFromStatusEffect = FALSE: status-effect reduction"
        );
        eprintln!(
            "  is bypassed for this damage type. We cannot use a status effect to mitigate."
        );
        eprintln!(
            "  Fall back to: post-application reversal in the multicast trampoline OR a"
        );
        eprintln!(
            "  native detour on whatever C++ function actually writes CurrentDamage."
        );
    }
}

fn flags_set(flags: u32) -> Vec<u32> {
    (0..32).filter(|i| (flags >> i) & 1 == 1).collect()
}
