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
// Live pawn instance walk is a follow-up; CDO patches propagate to
// new spawns at construction.

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
        let Ok(mut g) = self.entries.lock() else { return };
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
    let Some(survival_class) = sdk::find_class_fast("SurvivalComponent") else { return };
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
    let level = state
        .skill_levels
        .get(skill.id)
        .copied()
        .unwrap_or(0);
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
        SkillEffect::PlayerMovementMult {
            offsets,
            max_bonus,
            ..
        } => {
            let mult = 1.0 + skills::skill_bonus(*max_bonus, level);
            let count = apply_to_player_character_cdos(|player_cdo| {
                let Some(mc) = read_component_ptr(player_cdo, ASC_CHAR_MOVEMENT_COMPONENT)
                else {
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
            bbp_log!(
                "rpg/apply: {} level={} mult={:.3} written to {} player CDO(s)",
                skill.id,
                level,
                mult,
                count
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
    let Some(rt) = sdk::try_runtime() else { return 0 };
    let Some(survival_class) = sdk::find_class_fast("SurvivalCharacter") else { return 0 };
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
    let Some(rt) = sdk::try_runtime() else { return 0 };
    let Some(class) = sdk::find_class_fast("SurvivalComponent") else { return 0 };
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
