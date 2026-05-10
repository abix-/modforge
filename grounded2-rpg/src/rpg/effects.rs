// Game-specific Effect implementations -- the operations that
// don't fit the framework's standard Effect library.
//
// Per the workspace composition model
// (../../../ueforge/docs/architecture.md), each thing we research
// and figure out how to do in the game is one Effect type. This
// module owns the three Maine-specific operations:
//
//   - BackpackSlotsEffect      -- write inventory slot count to
//                                 every InventoryComponent CDO
//   - SurvivalDrainEffect      -- scale hunger/thirst drain on
//                                 the SurvivalComponent CDO
//   - PlayerFallDamageReductionEffect -- composite multi-component
//                                 fall-damage write
//
// The framework's standard effects (PlayerFloat, SubcomponentMultiply,
// etc.) are used directly in `skills.rs` static declarations -- no
// custom impl needed there.

use std::sync::OnceLock;

use ueforge::rpg::Effect;

use crate::inv_hook;
use crate::patch;
use crate::rpg::apply::{
    self, apply_to_live_player_characters, apply_to_player_character_cdos,
    apply_to_survival_component_cdos, apply_to_survival_game_mode_settings,
    apply_to_survival_mode_manager_components, write_bool,
};
use crate::rpg::skills::{
    self, ASC_FALL_DAMAGE_RATIO, ASC_MINIMUM_FALL_DAMAGE_VELOCITY, ASC_TAKE_FALL_DAMAGE,
    GMS_FALL_DAMAGE_MULTIPLIER, SKILL_MAX_LEVEL, SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER,
    SURVIVAL_HUNGER_OFFSET, SURVIVAL_THIRST_OFFSET, skill_bonus,
};
use crate::rpg::world_loader;
use ueforge::ue::field::{read_f32, write_f32};

// ---------------------------------------------------------------
// BackpackSlotsEffect -- adds skill-derived bonus slots to the
// settings-configured base inventory size, then patches every
// player InventoryComponent CDO + tells inv_hook the new count.
// ---------------------------------------------------------------

pub struct BackpackSlotsEffect {
    pub max_bonus_slots: i32,
}

impl Effect for BackpackSlotsEffect {
    fn apply(&self, level: u32, _max_level: u32, _ctx: &ueforge::rpg::TriggerCtx) {
        let Some(settings) = world_loader::loaded_settings() else {
            return;
        };
        let bonus = skills::backpack_bonus_at(level, self.max_bonus_slots);
        let target = settings.inventory.slot_count.saturating_add(bonus);
        let stats = patch::run(target);
        inv_hook::update_slot_count(target);
        ueforge::log!(
            "rpg/effects: backpack level={} target={} (base={} + bonus={}) patched={}",
            level,
            target,
            settings.inventory.slot_count,
            bonus,
            stats.patched
        );
    }

    fn format(&self, level: u32, _max_level: u32) -> String {
        let bonus = skills::backpack_bonus_at(level, self.max_bonus_slots);
        format!("+{bonus} slots")
    }
}

pub static BACKPACK: BackpackSlotsEffect = BackpackSlotsEffect {
    max_bonus_slots: 460,
};

// ---------------------------------------------------------------
// SurvivalDrainEffect -- scales hunger or thirst drain on every
// SurvivalComponent CDO. Final value =
//   vanilla * settings_mult * (1 - max_reduction * progress)
// ---------------------------------------------------------------

#[derive(Clone, Copy)]
pub enum SurvivalKind {
    Hunger,
    Thirst,
}

pub struct SurvivalDrainEffect {
    pub field_offset: usize,
    pub max_reduction: f32,
    pub kind: SurvivalKind,
}

impl Effect for SurvivalDrainEffect {
    fn apply(&self, level: u32, _max_level: u32, _ctx: &ueforge::rpg::TriggerCtx) {
        let Some(settings) = world_loader::loaded_settings() else {
            return;
        };
        let vanilla = match self.kind {
            SurvivalKind::Hunger => apply::vanilla_hunger(),
            SurvivalKind::Thirst => apply::vanilla_thirst(),
        };
        let settings_mult = match self.kind {
            SurvivalKind::Hunger => settings.survival.hunger_multiplier,
            SurvivalKind::Thirst => settings.survival.thirst_multiplier,
        };
        let Some(v) = vanilla else {
            return;
        };
        let skill_mult = (1.0 - skill_bonus(self.max_reduction, level)).max(0.0);
        let target = v * settings_mult * skill_mult;
        let count = apply_to_survival_component_cdos(self.field_offset, target);
        ueforge::log!(
            "rpg/effects: survival_drain level={} target={:.4} (vanilla={:.4} * settings={:.3} * skill={:.3}) written to {} CDO(s)",
            level, target, v, settings_mult, skill_mult, count
        );
    }

    fn format(&self, level: u32, _max_level: u32) -> String {
        let mult = (1.0 - skill_bonus(self.max_reduction, level)).max(0.0);
        let pct = ((1.0 - mult) * 100.0).round() as i32;
        format!("-{pct}% drain ({mult:.2}x)")
    }
}

pub static HUNGER_DRAIN: SurvivalDrainEffect = SurvivalDrainEffect {
    field_offset: SURVIVAL_HUNGER_OFFSET,
    max_reduction: 0.75,
    kind: SurvivalKind::Hunger,
};

pub static THIRST_DRAIN: SurvivalDrainEffect = SurvivalDrainEffect {
    field_offset: SURVIVAL_THIRST_OFFSET,
    max_reduction: 0.75,
    kind: SurvivalKind::Thirst,
};

// ---------------------------------------------------------------
// PlayerFallDamageReductionEffect -- composite multi-component
// fall-damage write (HC ratio + GMS CDO + SMMC live).
// ---------------------------------------------------------------

static VANILLA_FALL_DAMAGE_RATIO: OnceLock<f32> = OnceLock::new();
static VANILLA_MIN_FALL_DAMAGE_VELOCITY: OnceLock<f32> = OnceLock::new();
static VANILLA_GAME_MODE_FALL_DAMAGE_MULTIPLIER: OnceLock<f32> = OnceLock::new();
static VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER: OnceLock<f32> = OnceLock::new();

pub struct PlayerFallDamageReductionEffect {
    pub ratio_offset: usize,
    pub take_fall_damage_offset: usize,
    pub min_velocity_offset: usize,
    pub max_reduction: f32,
}

impl Effect for PlayerFallDamageReductionEffect {
    fn apply(&self, level: u32, _max_level: u32, _ctx: &ueforge::rpg::TriggerCtx) {
        let reduction = skill_bonus(self.max_reduction, level).min(1.0);
        let cdo_count = apply_to_player_character_cdos(|player_cdo| {
            let cur = read_f32(player_cdo, self.ratio_offset);
            if cur.is_finite() && cur > 0.0 {
                let _ = VANILLA_FALL_DAMAGE_RATIO.set(cur);
            }
            let cur_min_velocity = read_f32(player_cdo, self.min_velocity_offset);
            if cur_min_velocity.is_finite() && cur_min_velocity > 0.0 {
                let _ = VANILLA_MIN_FALL_DAMAGE_VELOCITY.set(cur_min_velocity);
            }
            if let Some(v) = VANILLA_FALL_DAMAGE_RATIO.get().copied() {
                write_f32(player_cdo, self.ratio_offset, v * (1.0 - reduction));
            }
            if let Some(v) = VANILLA_MIN_FALL_DAMAGE_VELOCITY.get().copied() {
                let boosted = v * (1.0 + reduction * 99.0);
                write_f32(player_cdo, self.min_velocity_offset, boosted);
            }
            write_bool(
                player_cdo,
                self.take_fall_damage_offset,
                reduction < 0.999,
            );
        });
        let live_count = apply_to_live_player_characters(|player| {
            if let Some(v) = VANILLA_FALL_DAMAGE_RATIO.get().copied() {
                write_f32(player, self.ratio_offset, v * (1.0 - reduction));
            }
            if let Some(v) = VANILLA_MIN_FALL_DAMAGE_VELOCITY.get().copied() {
                let boosted = v * (1.0 + reduction * 99.0);
                write_f32(player, self.min_velocity_offset, boosted);
            }
            write_bool(player, self.take_fall_damage_offset, reduction < 0.999);
        });
        let gms_count = apply_to_survival_game_mode_settings(|settings| {
            let cur = read_f32(settings, GMS_FALL_DAMAGE_MULTIPLIER);
            if cur.is_finite() && cur > 0.0 {
                let _ = VANILLA_GAME_MODE_FALL_DAMAGE_MULTIPLIER.set(cur);
            }
            if let Some(v) = VANILLA_GAME_MODE_FALL_DAMAGE_MULTIPLIER.get().copied() {
                write_f32(
                    settings,
                    GMS_FALL_DAMAGE_MULTIPLIER,
                    v * (1.0 - reduction),
                );
            }
        });
        let smmc_count = apply_to_survival_mode_manager_components(|component| {
            let cur = read_f32(component, SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER);
            if cur.is_finite() && cur > 0.0 {
                let _ = VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER.set(cur);
            }
            if let Some(v) = VANILLA_SMMC_FALL_DAMAGE_MULTIPLIER.get().copied() {
                write_f32(
                    component,
                    SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER,
                    v * (1.0 - reduction),
                );
            }
        });
        ueforge::log!(
            "rpg/effects: fall_damage level={} reduction={:.3} written to {} player CDO(s), {} live pawn(s), {} game-mode setting(s), {} mode-manager component(s)",
            level, reduction, cdo_count, live_count, gms_count, smmc_count
        );
    }

    fn format(&self, level: u32, _max_level: u32) -> String {
        ueforge::rpg::format::format_pct(
            0.0,
            self.max_reduction,
            level,
            SKILL_MAX_LEVEL,
            &ueforge::rpg::PercentFormat::MinusPercent { word: "fall damage" },
        )
    }
}

pub static FALL_DAMAGE: PlayerFallDamageReductionEffect = PlayerFallDamageReductionEffect {
    ratio_offset: ASC_FALL_DAMAGE_RATIO,
    take_fall_damage_offset: ASC_TAKE_FALL_DAMAGE,
    min_velocity_offset: ASC_MINIMUM_FALL_DAMAGE_VELOCITY,
    max_reduction: 1.00,
};

pub(crate) fn vanilla_fall_damage_ratio() -> Option<f32> {
    VANILLA_FALL_DAMAGE_RATIO.get().copied()
}
