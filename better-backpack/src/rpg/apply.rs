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
pub(crate) const ASC_HEALTH_COMPONENT: usize = 0x1340;
// ASurvivalCharacter.CharMovementComponent ptr (Maine_classes.hpp:5790).
pub(crate) const ASC_CHAR_MOVEMENT_COMPONENT: usize = 0x1380;

static VANILLA_HUNGER: OnceLock<f32> = OnceLock::new();
static VANILLA_THIRST: OnceLock<f32> = OnceLock::new();
static VANILLA_FALL_DAMAGE_RATIO: OnceLock<f32> = OnceLock::new();
static VANILLA_MAX_HEALTH: OnceLock<f32> = OnceLock::new();

pub(crate) fn vanilla_hunger() -> Option<f32> {
    VANILLA_HUNGER.get().copied()
}
pub(crate) fn vanilla_thirst() -> Option<f32> {
    VANILLA_THIRST.get().copied()
}
pub(crate) fn vanilla_fall_damage_ratio() -> Option<f32> {
    VANILLA_FALL_DAMAGE_RATIO.get().copied()
}
pub(crate) fn vanilla_max_health() -> Option<f32> {
    VANILLA_MAX_HEALTH.get().copied()
}

/// Snapshot every captured `(offset, value)` pair we have for the
/// HC u32 mask family. Used by the debug snapshot endpoint.
pub(crate) fn vanilla_hc_masks_snapshot() -> Vec<(usize, u32)> {
    VANILLA_HC_U32_MASK
        .lock()
        .ok()
        .map(|g| g.clone())
        .unwrap_or_default()
}

/// All currently-disabled skill ids. The toggle UI state.
pub(crate) fn disabled_skills_snapshot() -> Vec<&'static str> {
    DISABLED_SKILLS
        .lock()
        .ok()
        .map(|g| g.clone())
        .unwrap_or_default()
}
// Per-(offset) vanilla `UHealthComponent` u32 mask values, captured
// the first time we see a non-default value. Used by
// PlayerHealthCompU32Mask to restore the original mask when the
// skill is at level 0 or disabled (otherwise the mask we wrote
// would stay set, blocking everything that comes through
// ApplyDamage with type_flags=0 -- including healing items like
// bandages, which use negative damage).
static VANILLA_HC_U32_MASK: std::sync::Mutex<Vec<(usize, u32)>> = std::sync::Mutex::new(Vec::new());

fn capture_vanilla_hc_mask(offset: usize, value: u32) {
    if let Ok(mut g) = VANILLA_HC_U32_MASK.lock()
        && !g.iter().any(|(o, _)| *o == offset)
    {
        g.push((offset, value));
    }
}

pub(crate) fn vanilla_hc_mask(offset: usize) -> Option<u32> {
    VANILLA_HC_U32_MASK
        .lock()
        .ok()
        .and_then(|g| g.iter().find(|(o, _)| *o == offset).map(|(_, v)| *v))
}

// Process-global per-skill enable flags. Default ON. Toggling fires
// `apply_one` so the change is immediate. Not persisted across
// launches: cheap to reapply, and avoids a save-schema bump for a
// runtime convenience.
static DISABLED_SKILLS: std::sync::Mutex<Vec<&'static str>> = std::sync::Mutex::new(Vec::new());


pub fn is_skill_enabled(skill_id: &str) -> bool {
    let Ok(g) = DISABLED_SKILLS.lock() else {
        return true;
    };
    !g.iter().any(|s| *s == skill_id)
}

/// Set the enabled flag for `skill_id`. Returns the new state.
pub fn set_skill_enabled(skill_id: &'static str, enabled: bool) -> bool {
    if let Ok(mut g) = DISABLED_SKILLS.lock() {
        let pos = g.iter().position(|s| *s == skill_id);
        match (enabled, pos) {
            (true, Some(i)) => {
                g.swap_remove(i);
            }
            (false, None) => {
                g.push(skill_id);
            }
            _ => {}
        }
    }
    enabled
}
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
static GLOBAL_DATA_VANILLA: VanillaTable = VanillaTable {
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
    // Most variants short-circuit at level 0 (no work to do, vanilla
    // values are already in place). PlayerHealthCompU32Mask is the
    // exception: once the mask has been written we MUST be able to
    // restore the captured vanilla on disable/level-0, otherwise the
    // mask stays set and blocks bandages / healing.
    if level == 0 && !matches!(skill.effect, SkillEffect::PlayerHealthCompU32Mask { .. }) {
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
        SkillEffect::GlobalDataMult {
            class_name,
            offsets,
            max_bonus,
            ..
        } => {
            let enabled = is_skill_enabled(skill.id);
            let mult = if enabled {
                1.0 + skills::skill_bonus(*max_bonus, level)
            } else {
                1.0
            };
            let count = apply_to_class(class_name, |obj| {
                for &(off, exp) in *offsets {
                    let cur = read_f32(obj, off);
                    GLOBAL_DATA_VANILLA.set_if_unset(off, cur);
                    if let Some(v) = GLOBAL_DATA_VANILLA.get(off) {
                        let scaled = v * mult.powf(exp);
                        write_f32(obj, off, scaled);
                    }
                }
            });
            bbp_log!(
                "rpg/apply: {} level={} mult={:.3} written to {} {} instance(s)",
                skill.id,
                level,
                mult,
                count,
                class_name
            );
        }
        SkillEffect::PlayerHealthCompAdditive {
            offset, max_bonus, ..
        } => {
            let bonus = skills::skill_bonus(*max_bonus, level);
            let cdo_count = apply_to_player_character_cdos(|player_cdo| {
                if let Some(hc) = read_component_ptr(player_cdo, ASC_HEALTH_COMPONENT) {
                    let cur = read_f32(hc, *offset);
                    if cur.is_finite() && cur > 0.0 {
                        let _ = VANILLA_MAX_HEALTH.set(cur);
                    }
                    if let Some(v) = VANILLA_MAX_HEALTH.get().copied() {
                        write_f32(hc, *offset, v + bonus);
                    }
                }
            });
            let live_count = apply_to_live_player_characters(|player| {
                if let Some(hc) = read_component_ptr(player, ASC_HEALTH_COMPONENT) {
                    if let Some(v) = VANILLA_MAX_HEALTH.get().copied() {
                        write_f32(hc, *offset, v + bonus);
                    }
                }
            });
            bbp_log!(
                "rpg/apply: {} level={} bonus=+{:.1} HP (vanilla={:?}) written to {} CDO(s), {} live pawn(s)",
                skill.id,
                level,
                bonus,
                VANILLA_MAX_HEALTH.get().copied(),
                cdo_count,
                live_count
            );
        }
        SkillEffect::PlayerHealthCompU32Mask { offset, mask, .. } => {
            // Binary gate. When the skill is active (level>0 AND
            // enabled), write `mask` to the HC u32 field on every
            // player CDO and the live pawn. When the skill is off
            // (level==0 OR disabled), restore the captured vanilla
            // value. This is the path that blocks bandages /
            // healing for impact_resistance: the engine routes
            // negative-damage healing through the same ApplyDamage
            // gate that consults RequiredDamageTypeFlags, so leaving
            // the mask = 0xFFFFFFFF rejects healing too.
            let active = level > 0 && is_skill_enabled(skill.id);
            let target_mask = if active {
                *mask
            } else {
                vanilla_hc_mask(*offset).unwrap_or(0)
            };
            let cdo_count = apply_to_player_character_cdos(|player_cdo| {
                if let Some(hc) = read_component_ptr(player_cdo, ASC_HEALTH_COMPONENT) {
                    let cur = read_u32(hc, *offset);
                    if cur != *mask {
                        capture_vanilla_hc_mask(*offset, cur);
                    }
                    write_u32(hc, *offset, target_mask);
                }
            });
            let live_count = apply_to_live_player_characters(|player| {
                if let Some(hc) = read_component_ptr(player, ASC_HEALTH_COMPONENT) {
                    let cur = read_u32(hc, *offset);
                    if cur != *mask {
                        capture_vanilla_hc_mask(*offset, cur);
                    }
                    write_u32(hc, *offset, target_mask);
                }
            });
            bbp_log!(
                "rpg/apply: {} level={} active={} mask=0x{:08x} (vanilla=0x{:08x}) written to {} player HC CDO(s), {} live player HC(s)",
                skill.id,
                level,
                active,
                target_mask,
                vanilla_hc_mask(*offset).unwrap_or(0),
                cdo_count,
                live_count
            );
        }
        SkillEffect::PlayerMovementMult {
            offsets, max_bonus, ..
        } => {
            // Per-skill runtime toggle: treat as level 0 (vanilla
            // values) when disabled. Lets the player drop their
            // superjump on demand without losing the spent points.
            let enabled = is_skill_enabled(skill.id);
            let mult = if enabled {
                1.0 + skills::skill_bonus(*max_bonus, level)
            } else {
                1.0
            };
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
            // Fall mitigation that actually works lives elsewhere:
            // the velocity-stomp on `Velocity.Z` in `fall_hook.rs`
            // (validated, drops fall damage to zero at level 100) and
            // `RequiredDamageTypeFlags = 0xFFFFFFFF` from
            // impact_resistance for environmental damage. The
            // FallDamageRatio / GMS / SMMC multiplier writes above
            // are belt-and-suspenders -- the native ApplyFallDamage
            // path doesn't actually consult them. We do NOT call
            // `UpdateCustomSettings` because that UFunction triggers
            // the replication path on a Net-flagged field, which
            // hangs the game when invoked mid-session from any
            // non-game thread (toggle / spend / refund / poller
            // tick). See changelog 2026-05-09 for the deadlock log.
            bbp_log!(
                "rpg/apply: {} level={} reduction={:.3} written to {} player CDO(s), {} live pawn(s), {} game-mode setting(s), {} mode-manager component(s)",
                skill.id,
                level,
                reduction,
                cdo_count,
                live_count,
                gms_count,
                smmc_count
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

pub(crate) fn read_f32(obj: &UObject, offset: usize) -> f32 {
    unsafe { (obj.field_ptr(offset) as *const f32).read_unaligned() }
}

fn write_f32(obj: &UObject, offset: usize, value: f32) {
    unsafe { (obj.field_ptr(offset) as *mut f32).write_unaligned(value) }
}

pub(crate) fn read_u32(obj: &UObject, offset: usize) -> u32 {
    unsafe { (obj.field_ptr(offset) as *const u32).read_unaligned() }
}

fn write_u32(obj: &UObject, offset: usize, value: u32) {
    unsafe { (obj.field_ptr(offset) as *mut u32).write_unaligned(value) }
}

fn write_bool(obj: &UObject, offset: usize, value: bool) {
    unsafe { (obj.field_ptr(offset) as *mut u8).write(if value { 1 } else { 0 }) }
}

pub(crate) fn read_component_ptr(parent: &UObject, offset: usize) -> Option<&UObject> {
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
/// Read each instance of `class_name` and pass the first one
/// found to `f`. Returns true if any was found. Used by the debug
/// snapshot to read singleton-style or per-game-mode objects
/// (UGlobalCombatData, USurvivalGameModeSettings, etc.).
pub(crate) fn first_instance_of(class_name: &str, f: impl FnOnce(&UObject)) -> bool {
    let Some(rt) = sdk::try_runtime() else {
        return false;
    };
    let Some(class) = sdk::find_class_fast(class_name) else {
        return false;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return false;
    }
    for obj in view.iter() {
        if !obj.is_a(class) || obj.is_default_object() {
            continue;
        }
        f(obj);
        return true;
    }
    false
}

/// Read the class default object of `class_name` and pass to `f`.
/// Returns true if found. Used to inspect SurvivalComponent CDO
/// (hunger/thirst drain rates), ASurvivalCharacter CDO (combat
/// multipliers), etc.
pub(crate) fn class_default_object(class_name: &str, f: impl FnOnce(&UObject)) -> bool {
    let Some(rt) = sdk::try_runtime() else {
        return false;
    };
    let Some(class) = sdk::find_class_fast(class_name) else {
        return false;
    };
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return false;
    }
    for obj in view.iter() {
        if !obj.is_a(class) || !obj.is_default_object() {
            continue;
        }
        f(obj);
        return true;
    }
    false
}

pub(crate) fn apply_to_live_player_characters(mut f: impl FnMut(&UObject)) -> usize {
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

fn apply_to_class(class_name: &str, mut f: impl FnMut(&UObject)) -> usize {
    let Some(rt) = sdk::try_runtime() else {
        return 0;
    };
    let Some(class) = sdk::find_class_fast(class_name) else {
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
