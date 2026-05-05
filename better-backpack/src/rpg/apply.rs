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
//        - backpack: settings.slot_count + skills::backpack_bonus(level)
//        - hunger:   captured_vanilla * settings.hunger_mult *
//                    skills::survival_multiplier(level)
//        - thirst:   same shape as hunger
//
// Skill level 0 is a no-op for that skill (init-time values stand). The
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
// ASurvivalCharacter.CharMovementComponent ptr (Maine_classes.hpp:5790).
const SURVIVAL_CHARACTER_CHAR_MOVEMENT_COMPONENT: usize = 0x1380;
// UHealthComponent.BaseDamageReduction (Maine_classes.hpp:42193).
const HEALTH_COMPONENT_BASE_DAMAGE_REDUCTION: usize = 0x00EC;
// UCharacterMovementComponent.JumpZVelocity (Engine_classes.hpp:31485).
const CMC_JUMP_Z_VELOCITY: usize = 0x01B8;
// UCharacterMovementComponent.MaxWalkSpeed (Engine_classes.hpp:31500).
const CMC_MAX_WALK_SPEED: usize = 0x0288;
// UCharacterMovementComponent.MaxSwimSpeed (Engine_classes.hpp:31502).
const CMC_MAX_SWIM_SPEED: usize = 0x0290;
// UCharacterMovementComponent.MaxFlySpeed (Engine_classes.hpp:31503).
const CMC_MAX_FLY_SPEED: usize = 0x0294;
// UMaineCharMovementComponent.MaxSprintSpeed (Maine_classes.hpp:33015).
const CMC_MAX_SPRINT_SPEED: usize = 0x10EC;

static VANILLA_HUNGER: OnceLock<f32> = OnceLock::new();
static VANILLA_THIRST: OnceLock<f32> = OnceLock::new();

// Movement vanilla baselines (read from the player CDO's
// CharMovementComponent on first apply call). Stored separately so
// re-apply always multiplies vanilla, not the previously-modified
// value.
static VANILLA_MAX_WALK_SPEED: OnceLock<f32> = OnceLock::new();
static VANILLA_MAX_SPRINT_SPEED: OnceLock<f32> = OnceLock::new();
static VANILLA_MAX_SWIM_SPEED: OnceLock<f32> = OnceLock::new();
static VANILLA_MAX_FLY_SPEED: OnceLock<f32> = OnceLock::new();
static VANILLA_JUMP_Z_VELOCITY: OnceLock<f32> = OnceLock::new();

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
    apply_move_speed(state);
    apply_jump_height(state);
    apply_glide_speed(state);
    apply_hunger(state, settings);
    apply_thirst(state, settings);
    // Lifesteal is a runtime hook (kill_hook reads PlayerState on
    // every damage event), no apply step. Including it here would be
    // a no-op.
}

/// Re-apply only the skill identified by `skill_id`. Used by spend()
/// after a single level change so we don't run all 5 apply branches
/// (and produce 5 lines of log) when only one skill actually changed.
pub fn apply_one(state: &PlayerState, settings: &Settings, skill_id: &str) {
    match skill_id {
        skills::SKILL_BACKPACK => apply_backpack(state, settings),
        skills::SKILL_ATTACK_DAMAGE => apply_attack_damage(state),
        skills::SKILL_ARMOR => apply_armor(state),
        skills::SKILL_MOVE_SPEED => apply_move_speed(state),
        skills::SKILL_JUMP_HEIGHT => apply_jump_height(state),
        skills::SKILL_GLIDE_SPEED => apply_glide_speed(state),
        skills::SKILL_HUNGER => apply_hunger(state, settings),
        skills::SKILL_THIRST => apply_thirst(state, settings),
        skills::SKILL_LIFESTEAL => {
            // No CDO write needed; the kill_hook reads the level
            // every time a damage event fires.
            let level = state
                .skill_levels
                .get(skills::SKILL_LIFESTEAL)
                .copied()
                .unwrap_or(0);
            bbp_log!(
                "rpg/apply: lifesteal level={} (runtime; no cdo write)",
                level
            );
        }
        other => bbp_log!("rpg/apply: apply_one unknown skill '{}'", other),
    }
}

fn apply_backpack(state: &PlayerState, settings: &Settings) {
    let level = state
        .skill_levels
        .get(skills::SKILL_BACKPACK)
        .copied()
        .unwrap_or(0);
    if level == 0 {
        return;
    }
    let target = settings
        .inventory
        .slot_count
        .saturating_add(skills::backpack_bonus(level));
    let stats = patch::run(target);
    bbp_log!(
        "rpg/apply: backpack level={} target={} (base={} + bonus={}) patched={}",
        level,
        target,
        settings.inventory.slot_count,
        skills::backpack_bonus(level),
        stats.patched
    );
}

fn apply_attack_damage(state: &PlayerState) {
    let level = state
        .skill_levels
        .get(skills::SKILL_ATTACK_DAMAGE)
        .copied()
        .unwrap_or(0);
    if level == 0 {
        return;
    }
    let mult = skills::attack_damage_multiplier(level);
    let count = apply_to_player_character_cdos(|player_cdo| {
        write_f32(
            player_cdo,
            SURVIVAL_CHARACTER_CUSTOM_DAMAGE_MULTIPLIER,
            mult,
        );
    });
    bbp_log!(
        "rpg/apply: attack_damage level={} mult={:.3} written to {} player CDO(s)",
        level,
        mult,
        count
    );
}

fn apply_armor(state: &PlayerState) {
    let level = state.skill_levels.get(skills::SKILL_ARMOR).copied().unwrap_or(0);
    if level == 0 {
        return;
    }
    let reduction = skills::armor_reduction(level);
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
        "rpg/apply: armor level={} reduction={:.3} written to {} player HealthComponent CDO(s)",
        level,
        reduction,
        count
    );
}

fn capture_movement_vanilla(player_cdo: &UObject) {
    let mc_ptr: *mut UObject = unsafe {
        player_cdo
            .field_ptr(SURVIVAL_CHARACTER_CHAR_MOVEMENT_COMPONENT)
            .cast::<*mut UObject>()
            .read_unaligned()
    };
    if mc_ptr.is_null() {
        return;
    }
    let mc = unsafe { &*mc_ptr };
    let walk = read_f32(mc, CMC_MAX_WALK_SPEED);
    let sprint = read_f32(mc, CMC_MAX_SPRINT_SPEED);
    let swim = read_f32(mc, CMC_MAX_SWIM_SPEED);
    let fly = read_f32(mc, CMC_MAX_FLY_SPEED);
    let jump = read_f32(mc, CMC_JUMP_Z_VELOCITY);
    if walk.is_finite() && walk > 0.0 {
        let _ = VANILLA_MAX_WALK_SPEED.set(walk);
    }
    if sprint.is_finite() && sprint > 0.0 {
        let _ = VANILLA_MAX_SPRINT_SPEED.set(sprint);
    }
    if swim.is_finite() && swim > 0.0 {
        let _ = VANILLA_MAX_SWIM_SPEED.set(swim);
    }
    if fly.is_finite() && fly > 0.0 {
        let _ = VANILLA_MAX_FLY_SPEED.set(fly);
    }
    if jump.is_finite() && jump > 0.0 {
        let _ = VANILLA_JUMP_Z_VELOCITY.set(jump);
    }
}

fn with_player_movement_component(mut f: impl FnMut(&UObject)) -> usize {
    apply_to_player_character_cdos(|player_cdo| {
        // Idempotent: only sets the OnceLocks the first time we see
        // a valid CDO.
        capture_movement_vanilla(player_cdo);
        let mc_ptr: *mut UObject = unsafe {
            player_cdo
                .field_ptr(SURVIVAL_CHARACTER_CHAR_MOVEMENT_COMPONENT)
                .cast::<*mut UObject>()
                .read_unaligned()
        };
        if mc_ptr.is_null() {
            return;
        }
        let mc = unsafe { &*mc_ptr };
        f(mc);
    })
}

fn apply_move_speed(state: &PlayerState) {
    let level = state
        .skill_levels
        .get(skills::SKILL_MOVE_SPEED)
        .copied()
        .unwrap_or(0);
    if level == 0 {
        return;
    }
    let mult = skills::move_speed_multiplier(level);
    let count = with_player_movement_component(|mc| {
        if let Some(&w) = VANILLA_MAX_WALK_SPEED.get() {
            write_f32(mc, CMC_MAX_WALK_SPEED, w * mult);
        }
        if let Some(&s) = VANILLA_MAX_SPRINT_SPEED.get() {
            write_f32(mc, CMC_MAX_SPRINT_SPEED, s * mult);
        }
        if let Some(&sw) = VANILLA_MAX_SWIM_SPEED.get() {
            write_f32(mc, CMC_MAX_SWIM_SPEED, sw * mult);
        }
    });
    bbp_log!(
        "rpg/apply: move_speed level={} mult={:.3} written to {} player CDO(s)",
        level,
        mult,
        count
    );
}

fn apply_jump_height(state: &PlayerState) {
    let level = state
        .skill_levels
        .get(skills::SKILL_JUMP_HEIGHT)
        .copied()
        .unwrap_or(0);
    if level == 0 {
        return;
    }
    let mult = skills::jump_height_multiplier(level);
    let count = with_player_movement_component(|mc| {
        if let Some(&v) = VANILLA_JUMP_Z_VELOCITY.get() {
            write_f32(mc, CMC_JUMP_Z_VELOCITY, v * mult);
        }
    });
    bbp_log!(
        "rpg/apply: jump_height level={} mult={:.3} written to {} player CDO(s)",
        level,
        mult,
        count
    );
}

fn apply_glide_speed(state: &PlayerState) {
    let level = state
        .skill_levels
        .get(skills::SKILL_GLIDE_SPEED)
        .copied()
        .unwrap_or(0);
    if level == 0 {
        return;
    }
    let mult = skills::glide_speed_multiplier(level);
    let count = with_player_movement_component(|mc| {
        if let Some(&f) = VANILLA_MAX_FLY_SPEED.get() {
            write_f32(mc, CMC_MAX_FLY_SPEED, f * mult);
        }
    });
    bbp_log!(
        "rpg/apply: glide_speed level={} mult={:.3} written to {} player CDO(s)",
        level,
        mult,
        count
    );
}

fn apply_hunger(state: &PlayerState, settings: &Settings) {
    let level = state
        .skill_levels
        .get(skills::SKILL_HUNGER)
        .copied()
        .unwrap_or(0);
    if let Some(target) = compute_survival_target(
        VANILLA_HUNGER.get().copied(),
        settings.survival.hunger_multiplier,
        skills::hunger_multiplier(level),
        level,
    ) {
        apply_survival_field(survival::HUNGER_ADJUSTMENT_OFFSET, target, "HUNGER");
    }
}

fn apply_thirst(state: &PlayerState, settings: &Settings) {
    let level = state
        .skill_levels
        .get(skills::SKILL_THIRST)
        .copied()
        .unwrap_or(0);
    if let Some(target) = compute_survival_target(
        VANILLA_THIRST.get().copied(),
        settings.survival.thirst_multiplier,
        skills::thirst_multiplier(level),
        level,
    ) {
        apply_survival_field(survival::THIRST_ADJUSTMENT_OFFSET, target, "THIRST");
    }
}

fn compute_survival_target(
    vanilla: Option<f32>,
    settings_mult: f32,
    skill_mult: f32,
    level: u32,
) -> Option<f32> {
    if level == 0 {
        return None;
    }
    let v = vanilla?;
    Some(v * settings_mult * skill_mult)
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
