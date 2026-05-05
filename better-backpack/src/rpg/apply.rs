// Apply step: write skill-layered values to game state.
//
// Order of operations:
//   1. At worker init, BEFORE survival::run modifies the
//      SurvivalComponent CDO, `capture_vanilla()` reads and stores the
//      untouched hunger/thirst drain rates in static OnceLocks. This
//      gives us a fixed baseline to multiply against later.
//   2. Init-time patches (`patch::run`, `survival::run`) still apply
//      their settings-driven values. Existing non-RPG behavior is
//      preserved.
//   3. At `activate_slot`, after PlayerState is loaded, `apply` walks
//      CDOs and overwrites target fields with skill-layered values for
//      ranks > 0:
//        - backpack: settings.slot_count + skills::backpack_bonus(rank)
//        - hunger:   captured_vanilla * settings.hunger_mult *
//                    skills::survival_multiplier(rank)
//        - thirst:   same shape as hunger
//
// Skill rank 0 is a no-op for that skill (init-time values stand). The
// apply call is idempotent because we use captured vanilla as the
// baseline rather than reading the current (possibly already-modified)
// value.
//
// Live pawn instance walk is deferred. CDO-level patching is sufficient
// for inventory (DefaultMaxSize is read at component construction)
// and survival (rates are tick'd per-component). Adding instance
// patching when we hit a stat that doesn't propagate from CDO.

use std::sync::OnceLock;

use crate::bbp_log;
use crate::patch;
use crate::rpg::{skills, state::PlayerState};
use crate::sdk::{self, GObjectsView, UObject};
use crate::settings::Settings;
use crate::survival;

// ASurvivalCharacter.CustomDamageMultiplier (Maine_classes.hpp:5771).
const SURVIVAL_CHARACTER_CUSTOM_DAMAGE_MULTIPLIER: usize = 0x12B8;
// ASurvivalCharacter.HealthComponent ptr (Maine_classes.hpp:5782).
const SURVIVAL_CHARACTER_HEALTH_COMPONENT: usize = 0x1340;
// UHealthComponent.BaseDamageReduction (Maine_classes.hpp:42193).
const HEALTH_COMPONENT_BASE_DAMAGE_REDUCTION: usize = 0x00EC;

static VANILLA_HUNGER: OnceLock<f32> = OnceLock::new();
static VANILLA_THIRST: OnceLock<f32> = OnceLock::new();

/// Read and store the untouched hunger/thirst drain rates from the
/// SurvivalComponent CDO. Must run before any code modifies those
/// fields. Idempotent.
pub fn capture_vanilla() {
    if VANILLA_HUNGER.get().is_some() && VANILLA_THIRST.get().is_some() {
        return;
    }
    let Some(rt) = sdk::try_runtime() else {
        return;
    };
    let Some(survival_class) = sdk::find_class_fast("SurvivalComponent") else {
        return;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return;
    }
    for obj in view.iter() {
        if !obj.is_a(survival_class) || !obj.is_default_object() {
            continue;
        }
        let h = read_f32(obj, survival::HUNGER_ADJUSTMENT_OFFSET);
        let t = read_f32(obj, survival::THIRST_ADJUSTMENT_OFFSET);
        if h.is_finite() && h != 0.0 {
            let _ = VANILLA_HUNGER.set(h);
        }
        if t.is_finite() && t != 0.0 {
            let _ = VANILLA_THIRST.set(t);
        }
        bbp_log!(
            "rpg/apply: captured vanilla hunger={:.4}, thirst={:.4}",
            h,
            t
        );
        return; // first SurvivalComponent CDO is enough
    }
}

/// Apply skill-layered values for the given PlayerState. Called from
/// `tracker::activate_slot` after the state is loaded.
pub fn apply(state: &PlayerState, settings: &Settings) {
    apply_backpack(state, settings);
    apply_attack_damage(state);
    apply_armor(state);
    apply_hunger(state, settings);
    apply_thirst(state, settings);
}

/// Re-apply only the skill identified by `skill_id`. Used by spend()
/// after a single rank change so we don't run all 5 apply branches
/// (and produce 5 lines of log) when only one skill actually changed.
pub fn apply_one(state: &PlayerState, settings: &Settings, skill_id: &str) {
    match skill_id {
        skills::SKILL_BACKPACK => apply_backpack(state, settings),
        skills::SKILL_ATTACK_DAMAGE => apply_attack_damage(state),
        skills::SKILL_ARMOR => apply_armor(state),
        skills::SKILL_HUNGER => apply_hunger(state, settings),
        skills::SKILL_THIRST => apply_thirst(state, settings),
        other => bbp_log!("rpg/apply: apply_one unknown skill '{}'", other),
    }
}

fn apply_backpack(state: &PlayerState, settings: &Settings) {
    let rank = state
        .skill_ranks
        .get(skills::SKILL_BACKPACK)
        .copied()
        .unwrap_or(0);
    if rank == 0 {
        return;
    }
    let target = settings
        .inventory
        .slot_count
        .saturating_add(skills::backpack_bonus(rank));
    let stats = patch::run(target);
    bbp_log!(
        "rpg/apply: backpack rank={} target={} (base={} + bonus={}) patched={}",
        rank,
        target,
        settings.inventory.slot_count,
        skills::backpack_bonus(rank),
        stats.patched
    );
}

fn apply_attack_damage(state: &PlayerState) {
    let rank = state
        .skill_ranks
        .get(skills::SKILL_ATTACK_DAMAGE)
        .copied()
        .unwrap_or(0);
    if rank == 0 {
        return;
    }
    let mult = skills::attack_damage_multiplier(rank);
    let count = apply_to_player_character_cdos(|player_cdo| {
        write_f32(
            player_cdo,
            SURVIVAL_CHARACTER_CUSTOM_DAMAGE_MULTIPLIER,
            mult,
        );
    });
    bbp_log!(
        "rpg/apply: attack_damage rank={} mult={:.3} written to {} player CDO(s)",
        rank,
        mult,
        count
    );
}

fn apply_armor(state: &PlayerState) {
    let rank = state.skill_ranks.get(skills::SKILL_ARMOR).copied().unwrap_or(0);
    if rank == 0 {
        return;
    }
    let reduction = skills::armor_reduction(rank);
    let count = apply_to_player_character_cdos(|player_cdo| {
        let hc_ptr: *mut UObject = unsafe {
            player_cdo
                .field_ptr(SURVIVAL_CHARACTER_HEALTH_COMPONENT)
                .cast::<*mut UObject>()
                .read_unaligned()
        };
        if hc_ptr.is_null() {
            return;
        }
        let hc = unsafe { &*hc_ptr };
        write_f32(hc, HEALTH_COMPONENT_BASE_DAMAGE_REDUCTION, reduction);
    });
    bbp_log!(
        "rpg/apply: armor rank={} reduction={:.3} written to {} player HealthComponent CDO(s)",
        rank,
        reduction,
        count
    );
}

fn apply_hunger(state: &PlayerState, settings: &Settings) {
    let rank = state
        .skill_ranks
        .get(skills::SKILL_HUNGER)
        .copied()
        .unwrap_or(0);
    if let Some(target) = compute_survival_target(
        VANILLA_HUNGER.get().copied(),
        settings.survival.hunger_multiplier,
        rank,
    ) {
        apply_survival_field(survival::HUNGER_ADJUSTMENT_OFFSET, target, "HUNGER");
    }
}

fn apply_thirst(state: &PlayerState, settings: &Settings) {
    let rank = state
        .skill_ranks
        .get(skills::SKILL_THIRST)
        .copied()
        .unwrap_or(0);
    if let Some(target) = compute_survival_target(
        VANILLA_THIRST.get().copied(),
        settings.survival.thirst_multiplier,
        rank,
    ) {
        apply_survival_field(survival::THIRST_ADJUSTMENT_OFFSET, target, "THIRST");
    }
}

fn compute_survival_target(vanilla: Option<f32>, settings_mult: f32, rank: u32) -> Option<f32> {
    if rank == 0 {
        return None;
    }
    let v = vanilla?;
    Some(v * settings_mult * skills::survival_multiplier(rank))
}

fn apply_survival_field(offset: usize, target: f32, label: &str) {
    let Some(rt) = sdk::try_runtime() else {
        return;
    };
    let Some(survival_class) = sdk::find_class_fast("SurvivalComponent") else {
        return;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return;
    }
    let mut patched = 0usize;
    for obj in view.iter() {
        if !obj.is_a(survival_class) || !obj.is_default_object() {
            continue;
        }
        write_f32(obj, offset, target);
        patched += 1;
    }
    bbp_log!(
        "rpg/apply: {} target={:.4} written to {} CDO(s)",
        label,
        target,
        patched
    );
}

fn read_f32(obj: &UObject, offset: usize) -> f32 {
    unsafe { (obj.field_ptr(offset) as *const f32).read_unaligned() }
}

fn write_f32(obj: &UObject, offset: usize, value: f32) {
    unsafe { (obj.field_ptr(offset) as *mut f32).write_unaligned(value) }
}

/// Walk all SurvivalCharacter CDOs whose full name marks them as the
/// player class (`BP_SurvivalPlayerCharacter` substring), call `f` on
/// each. Returns the number of CDOs visited. Used by combat skills
/// that target player-only fields on ASurvivalCharacter.
fn apply_to_player_character_cdos(mut f: impl FnMut(&UObject)) -> usize {
    let Some(rt) = sdk::try_runtime() else {
        return 0;
    };
    let Some(survival_class) = sdk::find_class_fast("SurvivalCharacter") else {
        return 0;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return 0;
    }
    let mut count = 0usize;
    for obj in view.iter() {
        if !obj.is_a(survival_class) {
            continue;
        }
        if !obj.is_default_object() {
            continue;
        }
        let full = obj.full_name();
        if !full.contains("BP_SurvivalPlayerCharacter") {
            continue;
        }
        f(obj);
        count += 1;
    }
    count
}
