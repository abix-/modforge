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
    let backpack_rank = state
        .skill_ranks
        .get(skills::SKILL_BACKPACK)
        .copied()
        .unwrap_or(0);
    let hunger_rank = state
        .skill_ranks
        .get(skills::SKILL_HUNGER)
        .copied()
        .unwrap_or(0);
    let thirst_rank = state
        .skill_ranks
        .get(skills::SKILL_THIRST)
        .copied()
        .unwrap_or(0);

    if backpack_rank > 0 {
        let target = settings
            .inventory
            .slot_count
            .saturating_add(skills::backpack_bonus(backpack_rank));
        bbp_log!(
            "rpg/apply: backpack rank={} target={} (base={} + bonus={})",
            backpack_rank,
            target,
            settings.inventory.slot_count,
            skills::backpack_bonus(backpack_rank)
        );
        let stats = patch::run(target);
        bbp_log!(
            "rpg/apply: backpack patched={} skipped_non_player={}",
            stats.patched,
            stats.skipped_non_player
        );
    }

    if hunger_rank > 0 || thirst_rank > 0 {
        if let Some(target_hunger) = compute_survival_target(
            VANILLA_HUNGER.get().copied(),
            settings.survival.hunger_multiplier,
            hunger_rank,
        ) {
            apply_survival_field(survival::HUNGER_ADJUSTMENT_OFFSET, target_hunger, "HUNGER");
        }
        if let Some(target_thirst) = compute_survival_target(
            VANILLA_THIRST.get().copied(),
            settings.survival.thirst_multiplier,
            thirst_rank,
        ) {
            apply_survival_field(survival::THIRST_ADJUSTMENT_OFFSET, target_thirst, "THIRST");
        }
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
