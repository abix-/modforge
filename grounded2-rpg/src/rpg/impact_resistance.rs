// Impact Damage Resistance: post-application reversal of
// environmental damage on the player's HealthComponent.
//
// Empirical research (2026-05-09) showed environmental damage is
// applied by native C++ direct write to CurrentDamage BEFORE any PE
// event fires. Same shape as fall damage. There's no upstream PE
// seam. The multicast event we hook is post-application
// notification (the trace shows zero CurrentDamage delta during the
// multicast's original.call).
//
// Strategy: detect environmental multicasts via
// LastDamageInfo.DamageType class name, read the damage value from
// the parm, and SUBTRACT `damage * reduction` from CurrentDamage to
// undo the portion we want.

use std::ffi::c_void;

use ueforge::ue::{TypedField, UObject};

use crate::rpg::kill_hook::DAMAGE_INFO;

const HC_CURRENT_DAMAGE: TypedField<f32> = TypedField::at(0x032C);

fn multicast_damage_offset(fn_name: &str) -> Option<usize> {
    match fn_name {
        "MulticastHandleEffectsWithDamageFlags" => Some(0x18),
        "MulticastHandleEffectsWithDamageFlagsAtOwnerLocation"
        | "MulticastHandleEffectsWithDamageFlagsAndInflictStyleAtOwnerLocation" => Some(0x00),
        _ => None,
    }
}

/// If `level > 0` and the in-flight damage is environmental,
/// reverse `damage * reduction` from CurrentDamage. No-op
/// otherwise.
pub fn maybe_reverse(this: &UObject, fn_name: &str, parms: *mut c_void) {
    let level = crate::rpg::fall_hook::current_impact_resistance_level();
    if level == 0 || parms.is_null() {
        return;
    }
    let Some(dmg_off) = multicast_damage_offset(fn_name) else {
        return;
    };

    let damage_type_name = DAMAGE_INFO.damage_type_name(this);
    if !damage_type_name.contains("Environmental") {
        return;
    }

    let damage = unsafe {
        (parms as *const u8)
            .add(dmg_off)
            .cast::<f32>()
            .read_unaligned()
    };
    if damage <= 0.0 {
        return;
    }

    // max_bonus = 1.0 in catalog; sqrt(level/100) progress.
    let progress = (level as f32 / 100.0).sqrt().min(1.0);
    let reduction = progress;
    let to_reverse = damage * reduction;

    unsafe {
        let cd_now = HC_CURRENT_DAMAGE.read(this);
        let new_cd = (cd_now - to_reverse).max(0.0);
        HC_CURRENT_DAMAGE.write(this, new_cd);
        ueforge::log!(
            "rpg/impact: reversed environmental damage by {:.2} (raw={:.2}, reduction={:.3}, level={}); CurrentDamage {:.2} -> {:.2}",
            to_reverse,
            damage,
            reduction,
            level,
            cd_now,
            new_cd
        );
    }
}
