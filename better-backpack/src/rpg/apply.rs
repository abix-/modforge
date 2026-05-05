// Apply step: write skill-leveled values to game state.
//
// Adding a new skill is one row in `skills::CATALOG`. apply.rs
// dispatches generically on the row's `SkillEffect` so we never edit
// this file when adding skills of an existing shape (and rarely when
// adding a new shape, since all the work is in
// `apply_effect`).
//
// Order of operations at session start:
//   1. `capture_vanilla()` runs at worker init BEFORE survival::run
//      modifies the SurvivalComponent CDO. Untouched hunger/thirst
//      drain rates land in OnceLocks. The same OnceLocks (plus the
//      movement-component ones) are populated lazily on first apply
//      call for the player CDO when needed.
//   2. Init-time `patch::run` and `survival::run` still apply settings
//      values (preserves non-RPG behavior for users without a save
//      slot).
//   3. At `activate_slot`, `apply()` walks CATALOG and dispatches each
//      skill. Skills at level 0 short-circuit so non-RPG behavior is
//      preserved. `apply_one()` does the same for a single skill on
//      spend.
//
// Movement now also mirrors writes onto live player pawns because CDO
// updates alone were not enough to produce an obvious gameplay effect.

use std::ffi::c_void;
use std::sync::OnceLock;

use crate::bbp_log;
use crate::inv_hook;
use crate::patch;
use crate::rpg::skills::{self, Skill, SkillEffect, SurvivalField};
use crate::rpg::state::PlayerState;
use crate::sdk::{self, GObjectsView, UObject};
use crate::settings::Settings;
use crate::survival;

// ASurvivalCharacter.HealthComponent ptr (Maine_classes.hpp:5782).
const ASC_HEALTH_COMPONENT: usize = 0x1340;
// ASurvivalCharacter.CharMovementComponent ptr (Maine_classes.hpp:5790).
const ASC_CHAR_MOVEMENT_COMPONENT: usize = 0x1380;

static VANILLA_HUNGER: OnceLock<f32> = OnceLock::new();
static VANILLA_THIRST: OnceLock<f32> = OnceLock::new();
static VANILLA_FALL_DAMAGE_RATIO: OnceLock<f32> = OnceLock::new();
static VANILLA_MIN_FALL_DAMAGE_VELOCITY: OnceLock<f32> = OnceLock::new();
static VANILLA_GAME_MODE_FALL_DAMAGE_MULTIPLIER: OnceLock<f32> = OnceLock::new();
static VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER: OnceLock<f32> = OnceLock::new();

// Per-offset vanilla baselines for movement, captured lazily on first
// apply for that offset. Stored in a small fixed-size table because
// we know the set of offsets we ever touch is small (<10).
struct VanillaTable {
    entries: std::sync::Mutex<Vec<(usize, f32)>>,
}
static MOVEMENT_VANILLA: VanillaTable = VanillaTable {
    entries: std::sync::Mutex::new(Vec::new()),
};

impl VanillaTable {
    fn get(&self, offset: usize) -> Option<f32> {
        self.entries
            .lock()
            .ok()
            .and_then(|g| g.iter().find(|(k, _)| *k == offset).map(|(_, v)| *v))
    }

    fn set_if_unset(&self, offset: usize, value: f32) {
        if !value.is_finite() || value == 0.0 {
            return;
        }
        let Ok(mut g) = self.entries.lock() else {
            return;
        };
        if !g.iter().any(|(k, _)| *k == offset) {
            g.push((offset, value));
        }
    }
}

/// Read and store the untouched hunger/thirst drain rates. Run at
/// init before any patching.
pub fn capture_vanilla() {
    if VANILLA_HUNGER.get().is_some() && VANILLA_THIRST.get().is_some() {
        return;
    }
    let Some(rt) = sdk::try_runtime() else { return };
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
        return;
    }
}

/// Apply every CATALOG skill at its current level. Called from
/// `tracker::activate_slot`.
pub fn apply(state: &PlayerState, settings: &Settings) {
    for skill in skills::CATALOG {
        apply_skill(state, settings, skill);
    }
}

/// Apply one skill, looked up by id. Called from `spend_skill_point`.
pub fn apply_one(state: &PlayerState, settings: &Settings, skill_id: &str) {
    let Some(skill) = skills::lookup(skill_id) else {
        bbp_log!("rpg/apply: apply_one unknown skill '{}'", skill_id);
        return;
    };
    apply_skill(state, settings, skill);
}

fn apply_skill(state: &PlayerState, settings: &Settings, skill: &Skill) {
    let level = state.skill_levels.get(skill.id).copied().unwrap_or(0);
    if level == 0 {
        return;
    }
    match &skill.effect {
        SkillEffect::BackpackSlots { max_bonus_slots } => {
            let bonus = skills::backpack_bonus_at(level, *max_bonus_slots);
            let target = settings.inventory.slot_count.saturating_add(bonus);
            let stats = patch::run(target);
            inv_hook::update_slot_count(target);
            bbp_log!(
                "rpg/apply: {} level={} target={} (base={} + bonus={}) patched={}",
                skill.id,
                level,
                target,
                settings.inventory.slot_count,
                bonus,
                stats.patched
            );
        }
        SkillEffect::SurvivalDrain {
            field_offset,
            max_reduction,
            which,
        } => {
            let vanilla = match which {
                SurvivalField::Hunger => VANILLA_HUNGER.get().copied(),
                SurvivalField::Thirst => VANILLA_THIRST.get().copied(),
            };
            let settings_mult = match which {
                SurvivalField::Hunger => settings.survival.hunger_multiplier,
                SurvivalField::Thirst => settings.survival.thirst_multiplier,
            };
            let Some(v) = vanilla else { return };
            let skill_mult = (1.0 - skills::skill_bonus(*max_reduction, level)).max(0.0);
            let target = v * settings_mult * skill_mult;
            let count = apply_to_survival_component_cdos(*field_offset, target);
            bbp_log!(
                "rpg/apply: {} level={} target={:.4} (vanilla={:.4} * settings={:.3} * skill={:.3}) written to {} CDO(s)",
                skill.id,
                level,
                target,
                v,
                settings_mult,
                skill_mult,
                count
            );
        }
        SkillEffect::PlayerCharFloat {
            offset,
            base,
            max_bonus,
            ..
        } => {
            let value = base + skills::skill_bonus(*max_bonus, level);
            let count = apply_to_player_character_cdos(|player_cdo| {
                write_f32(player_cdo, *offset, value);
            });
            bbp_log!(
                "rpg/apply: {} level={} value={:.3} written to {} player CDO(s)",
                skill.id,
                level,
                value,
                count
            );
        }
        SkillEffect::PlayerHealthCompFloat {
            offset,
            base,
            max_bonus,
            ..
        } => {
            let value = base + skills::skill_bonus(*max_bonus, level);
            let count = apply_to_player_character_cdos(|player_cdo| {
                if let Some(hc) = read_component_ptr(player_cdo, ASC_HEALTH_COMPONENT) {
                    write_f32(hc, *offset, value);
                }
            });
            bbp_log!(
                "rpg/apply: {} level={} value={:.3} written to {} player HC CDO(s)",
                skill.id,
                level,
                value,
                count
            );
        }
        SkillEffect::PlayerHealthCompU32Mask { offset, mask, .. } => {
            // Binary gate: any level > 0 sets the mask. Walk player CDOs
            // and live pawns -- the mask stays set for the life of the
            // session, like Armor's BaseDamageReduction.
            let cdo_count = apply_to_player_character_cdos(|player_cdo| {
                if let Some(hc) = read_component_ptr(player_cdo, ASC_HEALTH_COMPONENT) {
                    write_u32(hc, *offset, *mask);
                }
            });
            let live_count = apply_to_live_player_characters(|player| {
                if let Some(hc) = read_component_ptr(player, ASC_HEALTH_COMPONENT) {
                    write_u32(hc, *offset, *mask);
                }
            });
            bbp_log!(
                "rpg/apply: {} level={} mask=0x{:08x} written to {} player HC CDO(s), {} live player HC(s)",
                skill.id,
                level,
                mask,
                cdo_count,
                live_count
            );
        }
        SkillEffect::PlayerMovementMult {
            offsets, max_bonus, ..
        } => {
            let mult = 1.0 + skills::skill_bonus(*max_bonus, level);
            let cdo_count = apply_to_player_character_cdos(|player_cdo| {
                let Some(mc) = read_component_ptr(player_cdo, ASC_CHAR_MOVEMENT_COMPONENT) else {
                    return;
                };
                for &off in *offsets {
                    // Capture vanilla on first sight, then write.
                    let cur = read_f32(mc, off);
                    MOVEMENT_VANILLA.set_if_unset(off, cur);
                    if let Some(v) = MOVEMENT_VANILLA.get(off) {
                        write_f32(mc, off, v * mult);
                    }
                }
            });
            let live_count = apply_to_live_player_characters(|player| {
                let Some(mc) = read_component_ptr(player, ASC_CHAR_MOVEMENT_COMPONENT) else {
                    return;
                };
                for &off in *offsets {
                    if let Some(v) = MOVEMENT_VANILLA.get(off) {
                        write_f32(mc, off, v * mult);
                    }
                }
            });
            bbp_log!(
                "rpg/apply: {} level={} mult={:.3} written to {} player CDO(s), {} live pawn(s)",
                skill.id,
                level,
                mult,
                cdo_count,
                live_count
            );
        }
        SkillEffect::PlayerFallDamageReduction {
            ratio_offset,
            take_fall_damage_offset,
            min_velocity_offset,
            max_reduction,
            ..
        } => {
            let reduction = skills::skill_bonus(*max_reduction, level).min(1.0);
            let cdo_count = apply_to_player_character_cdos(|player_cdo| {
                let cur = read_f32(player_cdo, *ratio_offset);
                if cur.is_finite() && cur > 0.0 {
                    let _ = VANILLA_FALL_DAMAGE_RATIO.set(cur);
                }
                let cur_min_velocity = read_f32(player_cdo, *min_velocity_offset);
                if cur_min_velocity.is_finite() && cur_min_velocity > 0.0 {
                    let _ = VANILLA_MIN_FALL_DAMAGE_VELOCITY.set(cur_min_velocity);
                }
                if let Some(v) = VANILLA_FALL_DAMAGE_RATIO.get().copied() {
                    write_f32(player_cdo, *ratio_offset, v * (1.0 - reduction));
                }
                if let Some(v) = VANILLA_MIN_FALL_DAMAGE_VELOCITY.get().copied() {
                    // As resistance rises, require substantially higher landing
                    // velocity before fall damage can trigger at all.
                    let boosted = v * (1.0 + reduction * 99.0);
                    write_f32(player_cdo, *min_velocity_offset, boosted);
                }
                write_bool(player_cdo, *take_fall_damage_offset, reduction < 0.999);
            });
            let live_count = apply_to_live_player_characters(|player| {
                if let Some(v) = VANILLA_FALL_DAMAGE_RATIO.get().copied() {
                    write_f32(player, *ratio_offset, v * (1.0 - reduction));
                }
                if let Some(v) = VANILLA_MIN_FALL_DAMAGE_VELOCITY.get().copied() {
                    let boosted = v * (1.0 + reduction * 99.0);
                    write_f32(player, *min_velocity_offset, boosted);
                }
                write_bool(player, *take_fall_damage_offset, reduction < 0.999);
            });
            let gms_count = apply_to_survival_game_mode_settings(|settings| {
                let cur = read_f32(settings, skills::GMS_FALL_DAMAGE_MULTIPLIER);
                if cur.is_finite() && cur > 0.0 {
                    let _ = VANILLA_GAME_MODE_FALL_DAMAGE_MULTIPLIER.set(cur);
                }
                if let Some(v) = VANILLA_GAME_MODE_FALL_DAMAGE_MULTIPLIER.get().copied() {
                    write_f32(
                        settings,
                        skills::GMS_FALL_DAMAGE_MULTIPLIER,
                        v * (1.0 - reduction),
                    );
                }
            });
            let smmc_count = apply_to_survival_mode_manager_components(|component| {
                let cur = read_f32(component, skills::SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER);
                if cur.is_finite() && cur > 0.0 {
                    let _ = VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER.set(cur);
                }
                if let Some(v) = VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER.get().copied() {
                    write_f32(
                        component,
                        skills::SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER,
                        v * (1.0 - reduction),
                    );
                }
            });
            let update_count = invoke_update_custom_settings_for_fall_damage(reduction);
            bbp_log!(
                "rpg/apply: {} level={} reduction={:.3} written to {} player CDO(s), {} live pawn(s), {} game-mode setting(s), {} mode-manager component(s); UpdateCustomSettings invoked on {} component(s)",
                skill.id,
                level,
                reduction,
                cdo_count,
                live_count,
                gms_count,
                smmc_count,
                update_count
            );
        }
        SkillEffect::Runtime { .. } => {
            // Pure runtime effect (kill_hook reads the level on every
            // damage tick). Nothing to write.
            bbp_log!(
                "rpg/apply: {} level={} (runtime; no cdo write)",
                skill.id,
                level
            );
        }
    }
}

// ---------------------------------------------------------------------
// Low-level helpers shared by the SkillEffect arms.
// ---------------------------------------------------------------------

fn read_f32(obj: &UObject, offset: usize) -> f32 {
    unsafe { (obj.field_ptr(offset) as *const f32).read_unaligned() }
}

fn write_f32(obj: &UObject, offset: usize, value: f32) {
    unsafe { (obj.field_ptr(offset) as *mut f32).write_unaligned(value) }
}

fn write_u32(obj: &UObject, offset: usize, value: u32) {
    unsafe { (obj.field_ptr(offset) as *mut u32).write_unaligned(value) }
}

fn write_bool(obj: &UObject, offset: usize, value: bool) {
    unsafe { (obj.field_ptr(offset) as *mut u8).write(if value { 1 } else { 0 }) }
}

fn read_component_ptr(parent: &UObject, offset: usize) -> Option<&UObject> {
    unsafe {
        let p: *mut UObject = parent
            .field_ptr(offset)
            .cast::<*mut UObject>()
            .read_unaligned();
        p.as_ref()
    }
}

/// Walk all SurvivalCharacter CDOs whose full name marks them as the
/// player class (`BP_SurvivalPlayerCharacter` substring), call `f` on
/// each. Returns the number of CDOs visited.
fn apply_to_player_character_cdos(mut f: impl FnMut(&UObject)) -> usize {
    apply_to_player_characters(true, &mut f)
}

/// Walk all live player SurvivalCharacter instances (non-CDOs) whose
/// full name marks them as the player class, call `f` on each.
fn apply_to_live_player_characters(mut f: impl FnMut(&UObject)) -> usize {
    apply_to_player_characters(false, &mut f)
}

fn apply_to_player_characters(is_cdo: bool, f: &mut impl FnMut(&UObject)) -> usize {
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
        if obj.is_default_object() != is_cdo {
            continue;
        }
        if !obj.full_name().contains("BP_SurvivalPlayerCharacter") {
            continue;
        }
        f(obj);
        count += 1;
    }
    count
}

/// Walk every SurvivalComponent CDO and write `value` at `offset`.
/// Used by SurvivalDrain skills.
fn apply_to_survival_component_cdos(offset: usize, value: f32) -> usize {
    let Some(rt) = sdk::try_runtime() else {
        return 0;
    };
    let Some(class) = sdk::find_class_fast("SurvivalComponent") else {
        return 0;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return 0;
    }
    let mut count = 0usize;
    for obj in view.iter() {
        if !obj.is_a(class) || !obj.is_default_object() {
            continue;
        }
        write_f32(obj, offset, value);
        count += 1;
    }
    count
}

/// Mirror what the in-game difficulty UI does at runtime: read the live
/// `FCustomGameModeSettings` struct off `USurvivalModeManagerComponent`,
/// mutate `FallDamageMultiplier`, and call back into the native
/// `UpdateCustomSettings(FCustomGameModeSettings)` UFunction via
/// ProcessEvent. That triggers the engine's own write + OnRep + cache
/// invalidation path, which our raw memory write to +0x130 does not.
///
/// Returns the number of components on which the call was invoked.
fn invoke_update_custom_settings_for_fall_damage(reduction: f32) -> usize {
    let Some(rt) = sdk::try_runtime() else {
        return 0;
    };
    let Some(class) = sdk::find_class_fast("SurvivalModeManagerComponent") else {
        return 0;
    };
    let Some(update_fn) = class.get_function("SurvivalModeManagerComponent", "UpdateCustomSettings")
    else {
        bbp_log!(
            "rpg/apply: UpdateCustomSettings UFunction not found on SurvivalModeManagerComponent"
        );
        return 0;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return 0;
    }

    let mut count = 0usize;
    for obj in view.iter() {
        if !obj.is_a(class) {
            continue;
        }
        if obj.is_default_object() {
            continue;
        }

        // Snapshot the live FCustomGameModeSettings struct so the call
        // preserves every field except FallDamageMultiplier.
        let mut parms = [0u8; skills::FCG_STRUCT_SIZE];
        unsafe {
            std::ptr::copy_nonoverlapping(
                obj.field_ptr(skills::SMMC_CUSTOM_SETTINGS_OFFSET) as *const u8,
                parms.as_mut_ptr(),
                skills::FCG_STRUCT_SIZE,
            );
        }

        // Capture vanilla on first sight.
        let cur = unsafe {
            (parms
                .as_ptr()
                .add(skills::FCG_FALL_DAMAGE_MULTIPLIER_OFFSET) as *const f32)
                .read_unaligned()
        };
        if cur.is_finite() && cur > 0.0 {
            let _ = VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER.set(cur);
        }

        if let Some(v) = VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER.get().copied() {
            let target = v * (1.0 - reduction);
            unsafe {
                (parms
                    .as_mut_ptr()
                    .add(skills::FCG_FALL_DAMAGE_MULTIPLIER_OFFSET)
                    as *mut f32)
                    .write_unaligned(target);
            }
        }

        unsafe {
            obj.process_event(update_fn, parms.as_mut_ptr() as *mut c_void);
        }
        count += 1;
    }
    count
}

fn apply_to_survival_mode_manager_components(mut f: impl FnMut(&UObject)) -> usize {
    let Some(rt) = sdk::try_runtime() else {
        return 0;
    };
    let Some(class) = sdk::find_class_fast("SurvivalModeManagerComponent") else {
        return 0;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return 0;
    }

    let mut count = 0;
    for obj in view.iter() {
        if !obj.is_a(class) {
            continue;
        }
        if obj.is_default_object() {
            continue;
        }
        f(obj);
        count += 1;
    }
    count
}

fn apply_to_survival_game_mode_settings(mut f: impl FnMut(&UObject)) -> usize {
    let Some(rt) = sdk::try_runtime() else {
        return 0;
    };
    let Some(class) = sdk::find_class_fast("SurvivalGameModeSettings") else {
        return 0;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return 0;
    }

    let mut count = 0;
    for obj in view.iter() {
        if !obj.is_a(class) {
            continue;
        }
        f(obj);
        count += 1;
    }
    count
}
