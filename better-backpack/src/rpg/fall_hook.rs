use std::ffi::c_void;

use crate::bbp_log;
use crate::hook::{OriginalProcessEvent, ProcessEventHook};
use crate::rpg::{skills, tracker};
use crate::sdk::{UFunction, UObject, find_class_fast};

const PLAYER_FALL_HOOK_CLASSES: &[&str] = &[
    "BP_SurvivalPlayerCharacter_C",
    "BP_SurvivalPlayerCharacter_Female02_C",
    "BP_SurvivalPlayerCharacter_Gellarde_C",
];

const FN_ON_LANDED: &str = "OnLanded";

pub fn install() -> Result<Vec<ProcessEventHook>, &'static str> {
    let mut hooks = Vec::new();

    for &class_name in PLAYER_FALL_HOOK_CLASSES {
        if find_class_fast(class_name).is_none() {
            bbp_log!("rpg/fall: class {} not loaded yet, skipping", class_name);
            continue;
        }
        bbp_log!(
            "rpg/fall: hooking concrete player class {} for {} velocity-stomp",
            class_name,
            FN_ON_LANDED
        );
        let class_name_owned = class_name.to_string();
        let hook =
            ProcessEventHook::install(class_name, move |this, function, parms, original| {
                on_player_fall_event(&class_name_owned, this, function, parms, original)
            })?;
        hooks.push(hook);
    }

    if hooks.is_empty() {
        return Err("no concrete player classes were loaded for fall hook");
    }

    Ok(hooks)
}

fn on_player_fall_event(
    hook_class_name: &str,
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let fn_name = function.as_object().name();
    let is_player = is_player_character(this);

    // Velocity-stomp: when OnLanded fires on the player and
    // fall_resistance is active, scale `CharMovementComponent.Velocity.Z`
    // by `(1 - reduction)` BEFORE forwarding to the original BP event.
    // The native ASurvivalCharacter::ApplyFallDamage runs immediately
    // after Super::Landed returns (which is what fires OnLanded), so if
    // the native fall formula reads live velocity at invocation time,
    // damage is scaled or zeroed accordingly. At level 100 (reduction
    // = 1.0) Velocity.Z becomes 0 and fall damage should be zero.
    //
    // OnLanded suppression is REMOVED. We forward to the original BP
    // event so other landing logic (animations, sounds) still runs.
    if fn_name == FN_ON_LANDED && is_player {
        let reduction = current_fall_resistance_reduction();
        if reduction > 0.0 {
            let scale = (1.0 - reduction).max(0.0) as f64;
            let stomped = stomp_player_velocity_z(this, scale);
            bbp_log!(
                "rpg/fall: stomped Velocity.Z {:.2} -> {:.2} on {} (reduction={:.3} via {})",
                stomped.before,
                stomped.after,
                this.name(),
                reduction,
                hook_class_name
            );
        }
    }

    // Walk-backwards trace for plant / terrain collision damage.
    // GATED on impact_resistance level > 0 so it stays silent for
    // normal users and kicks in only when the player has put a point
    // into the diagnostic skill. Logs every fall/land/damage/hit PE
    // event hitting the player BP class, with `CurrentDamage` snapshot
    // before and after `original.call`. The PE event whose POST reading
    // is higher than its pre reading is the event during which native
    // code wrote `CurrentDamage` -- our intercept seam.
    let impact_diag = is_player
        && current_impact_resistance_level() > 0
        && is_collision_relevant(&fn_name);
    let cd_before = if impact_diag {
        let cd = read_player_current_damage(this);
        bbp_log!(
            "rpg/impact-trace: bp-class fn={} on {} CurrentDamage={:.2}",
            fn_name,
            this.name(),
            cd
        );
        Some(cd)
    } else {
        None
    };

    unsafe { original.call(this, function, parms) };

    if let Some(before) = cd_before {
        let after = read_player_current_damage(this);
        if (after - before).abs() > 0.001 {
            bbp_log!(
                "rpg/impact-trace: bp-class fn={} POST CurrentDamage={:.2} (delta={:.2})",
                fn_name,
                after,
                after - before
            );
        }
    }
}

struct VelocityStomp {
    before: f64,
    after: f64,
}

fn stomp_player_velocity_z(player: &UObject, scale: f64) -> VelocityStomp {
    // ASurvivalCharacter.CharMovementComponent ptr at +0x1380.
    // UMovementComponent.Velocity (FVector, doubles) at +0xD8.
    // FVector.Z at +0x10 inside FVector -> absolute +0xE8 on CMC.
    const ASC_CHAR_MOVEMENT_COMPONENT: usize = 0x1380;
    const CMC_VELOCITY_Z: usize = 0x00E8;
    unsafe {
        let cmc: *mut UObject = player
            .field_ptr(ASC_CHAR_MOVEMENT_COMPONENT)
            .cast::<*mut UObject>()
            .read_unaligned();
        let Some(cmc) = cmc.as_ref() else {
            return VelocityStomp {
                before: 0.0,
                after: 0.0,
            };
        };
        let z_ptr = cmc.field_ptr(CMC_VELOCITY_Z) as *mut f64;
        let before = z_ptr.read_unaligned();
        let after = before * scale;
        z_ptr.write_unaligned(after);
        VelocityStomp { before, after }
    }
}

fn current_fall_resistance_reduction() -> f32 {
    tracker::with_state(|state| {
        let level = state
            .skill_levels
            .get(skills::SKILL_FALL_RESISTANCE)
            .copied()
            .unwrap_or(0);
        if level == 0 {
            return 0.0;
        }
        skills::skill_bonus(1.0, level).min(1.0)
    })
    .unwrap_or(0.0)
}

fn is_player_character(obj: &UObject) -> bool {
    obj.full_name().contains("BP_SurvivalPlayerCharacter")
}

fn is_collision_relevant(fn_name: &str) -> bool {
    fn_name.contains("Damage")
        || fn_name.contains("Damaged")
        || fn_name.contains("Hit")
        || fn_name.contains("Land")
        || fn_name.contains("Fall")
        || fn_name.contains("Impact")
        || fn_name.contains("Health")
        || fn_name.contains("Receive")
}

fn current_impact_resistance_level() -> u32 {
    tracker::with_state(|state| {
        state
            .skill_levels
            .get(skills::SKILL_IMPACT_RESISTANCE)
            .copied()
            .unwrap_or(0)
    })
    .unwrap_or(0)
}

/// Read the player's `HealthComponent.CurrentDamage` (+0x32C). The
/// player BP instance has its HealthComponent ptr at +0x1340 inside
/// `ASurvivalCharacter`.
fn read_player_current_damage(player: &UObject) -> f32 {
    const ASC_HEALTH_COMPONENT: usize = 0x1340;
    const HC_CURRENT_DAMAGE: usize = 0x032C;
    unsafe {
        let hc: *mut UObject = player
            .field_ptr(ASC_HEALTH_COMPONENT)
            .cast::<*mut UObject>()
            .read_unaligned();
        if let Some(hc) = hc.as_ref() {
            hc.field_ptr(HC_CURRENT_DAMAGE)
                .cast::<f32>()
                .read_unaligned()
        } else {
            f32::NAN
        }
    }
}
