// Skill catalog: the single source of truth for every skill in the
// game. Adding a new skill is one row in `CATALOG`, no other code
// changes required (apply.rs and format_effect dispatch generically
// on `SkillEffect`).
//
// Vocabulary (consistent throughout the codebase):
//   - "skill"        the upgrade slot itself (e.g. Backpack, Lifesteal)
//   - "skill point"  a currency the player earns by leveling
//   - "skill level"  how many points have been spent on a given skill
//
// Every skill scales 0..=100 levels with diminishing returns:
// `level_progress(level) = sqrt(level / 100)`. Level 1 = ~10% of max,
// level 25 = 50%, level 50 = ~71%, level 100 = 100%. Sqrt feels
// generous early and flattens at the end so 99 -> 100 is small.

// ---------------------------------------------------------------------
// Skill IDs (stable strings used as keys in PlayerState.skill_levels
// and in the FFI surface). Adding a new skill: define an id, append a
// row in CATALOG.
// ---------------------------------------------------------------------

pub const SKILL_BACKPACK: &str = "backpack";
pub const SKILL_HUNGER: &str = "hunger";
pub const SKILL_THIRST: &str = "thirst";
pub const SKILL_ATTACK_DAMAGE: &str = "attack_damage";
pub const SKILL_ARMOR: &str = "armor";
pub const SKILL_MOVE_SPEED: &str = "move_speed";
pub const SKILL_JUMP_HEIGHT: &str = "jump_height";
pub const SKILL_GLIDE_SPEED: &str = "glide_speed";
pub const SKILL_FALL_RESISTANCE: &str = "fall_resistance";
pub const SKILL_IMPACT_RESISTANCE: &str = "impact_resistance";
pub const SKILL_LIFESTEAL: &str = "lifesteal";
pub const SKILL_MAX_HEALTH: &str = "max_health";
pub const SKILL_LEAP_DISTANCE: &str = "leap_distance";
pub const SKILL_HEALTH_REGEN: &str = "health_regen";

/// Universal cap. Every skill scales 0..=100.
pub const SKILL_MAX_LEVEL: u32 = 100;

// ---------------------------------------------------------------------
// SkillEffect: how the skill applies AND how it formats. apply.rs and
// format_effect both dispatch on this enum, so adding a new shape of
// skill is local to one file.
// ---------------------------------------------------------------------

#[derive(Debug, Clone, Copy)]
pub enum SurvivalField {
    Hunger,
    Thirst,
}

// PercentFormat now lives in `ueforge::rpg::format`. Re-exported
// here for catalog rows that haven't migrated to StandardEffect
// yet (BackpackSlots / SurvivalDrain / PlayerFallDamageReduction).
pub use ueforge::rpg::format::PercentFormat;
pub use ueforge::rpg::std_effect::StandardEffect;

#[derive(Clone, Copy)]
pub enum SkillEffect {
    /// 9 of the 13 catalog skills route through ueforge's canonical
    /// variant menu. The Standard arm in `apply::apply_skill`
    /// forwards to `e.apply(level, max, &PLAYER)` with no game-
    /// specific dispatch logic.
    Standard(StandardEffect),

    /// Bonus slots added to `settings.inventory.slot_count`.
    /// `max_bonus_slots` is the integer added at level 100.
    /// Applied via `patch::run` over all InventoryComponents with
    /// the player-only filter -- StandardEffect doesn't have a
    /// "filtered CDO write of an int field on a non-player class"
    /// shape, so this stays game-side.
    BackpackSlots { max_bonus_slots: i32 },

    /// Survival drain rate. Final value =
    /// `vanilla * settings.survival.<x>_multiplier * (1 - max_reduction * progress)`.
    /// Pulls a multiplier from settings (per-mod config) so
    /// StandardEffect can't express it cleanly -- stays game-side.
    SurvivalDrain {
        field_offset: usize,
        max_reduction: f32,
        which: SurvivalField,
    },

    /// Composite multi-component fall-damage write (HC ratio + GMS
    /// CDO + SMMC live + UpdateCustomSettings UFunction call). No
    /// generic shape captures this; stays game-side.
    PlayerFallDamageReduction {
        ratio_offset: usize,
        take_fall_damage_offset: usize,
        min_velocity_offset: usize,
        max_reduction: f32,
        format: PercentFormat,
    },
}

/// One row in the catalog. Local alias of the framework-owned
/// `SkillDef<SkillEffect>` -- saves typing the parameter on every
/// row of the static catalog.
pub type SkillDef = ueforge::rpg::SkillDef<SkillEffect>;

// ---------------------------------------------------------------------
// Field offsets used by the catalog. Centralized here so the catalog
// rows stay readable.
//
// Source: C:\tools\work\sdk\SDK\ (Dumper-7 SDK), citations follow each
// constant.
// ---------------------------------------------------------------------

// SurvivalComponent.HungerSettings.AdjustmentPerSecond at +0x140.
pub const SURVIVAL_HUNGER_OFFSET: usize = 0x0140;
// SurvivalComponent.ThirstSettings.AdjustmentPerSecond at +0x188.
pub const SURVIVAL_THIRST_OFFSET: usize = 0x0188;

// ASurvivalCharacter.CustomDamageMultiplier (Maine_classes.hpp:5771).
pub const ASC_CUSTOM_DAMAGE_MULTIPLIER: usize = 0x12B8;
// ASurvivalCharacter.bTakeFallDamage (Maine_classes.hpp:5846).
pub const ASC_TAKE_FALL_DAMAGE: usize = 0x1571;
// ASurvivalCharacter.MinimumFallDamageVelocity (Maine_classes.hpp:5848).
pub const ASC_MINIMUM_FALL_DAMAGE_VELOCITY: usize = 0x1574;
// ASurvivalCharacter.FallDamageRatio (Maine_classes.hpp:5850).
pub const ASC_FALL_DAMAGE_RATIO: usize = 0x157C;

// USurvivalGameModeSettings.FallDamageMultiplier (Maine_classes.hpp:36808).
// Global per-game-mode scalar applied to fall damage on top of the
// per-character ratio. CDO-side value -- the runtime reads from the
// replicated copy on the mode-manager component below, so this write
// alone is not sufficient.
pub const GMS_FALL_DAMAGE_MULTIPLIER: usize = 0x008C;

// USurvivalModeManagerComponent.CustomSettings (Maine_classes.hpp:37142):
// embedded `FCustomGameModeSettings` struct at +0x114. The
// FallDamageMultiplier field lives at +0x1C inside the struct, so the
// absolute offset on the component is +0x130. This is the replicated
// runtime copy of the game-mode multiplier; native fall damage reads
// from here each fall.
pub const SMMC_CUSTOM_SETTINGS_OFFSET: usize = 0x0114;
pub const SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER: usize =
    SMMC_CUSTOM_SETTINGS_OFFSET + FCG_FALL_DAMAGE_MULTIPLIER_OFFSET;

// FCustomGameModeSettings struct layout (Maine_structs.hpp:6959, 0x20 bytes).
// Only the fields we touch are listed; the rest is preserved by reading the
// live struct, mutating in place, and writing back via the BP-callable
// `UpdateCustomSettings` UFunction.
pub const FCG_FALL_DAMAGE_MULTIPLIER_OFFSET: usize = 0x001C;
pub const FCG_STRUCT_SIZE: usize = 0x0020;

// UHealthComponent.RequiredDamageTypeFlags (Maine_classes.hpp:42197).
// Bitmask of damage-type flags incoming damage MUST have to pass the
// native gate. Setting to 0xFFFFFFFF rejects damage with `type_flags=0`
// (the fall and environmental paths in Grounded 2). Creature damage
// carries non-zero type flags so it still passes.
pub const HC_REQUIRED_DAMAGE_TYPE_FLAGS: usize = 0x00FC;

// UHealthComponent.BaseDamageReduction (Maine_classes.hpp:42193).
pub const HC_BASE_DAMAGE_REDUCTION: usize = 0x00EC;

// UGlobalCombatData (Maine_classes.hpp:23883). Singleton-style data
// asset that holds the player's out-of-combat health regen settings.
// Tweaking these fields makes regen kick in sooner, more often, or
// for more health per tick.
pub const GCD_COMBAT_REGEN_DELAY: usize = 0x0108;
pub const GCD_COMBAT_REGEN_TICK_PERCENTAGE: usize = 0x010C;
pub const GCD_COMBAT_REGEN_TICK_RATE: usize = 0x0110;

// UHealthComponent.MaxHealth (../docs/damage.md "HealthComponent layout").
// Vanilla baseline captured on first apply; we add raw HP on top.
pub const HC_MAX_HEALTH: usize = 0x0328;

// UCharacterMovementComponent.JumpZVelocity (Engine_classes.hpp:31485).
pub const CMC_JUMP_Z_VELOCITY: usize = 0x01B8;
// UCharacterMovementComponent.AirControl (Engine_classes.hpp:31514).
// Fraction 0..1 of input authority while airborne. Vanilla typically
// ~0.35 -- low value keeps the player from steering wildly mid-air,
// also caps how much horizontal velocity you can build during a fall.
pub const CMC_AIR_CONTROL: usize = 0x02C0;
// UCharacterMovementComponent.AirControlBoostMultiplier (Engine_classes.hpp:31515).
// Multiplier applied to AirControl when the player's lateral velocity
// is below `AirControlBoostVelocityThreshold`. Letting this scale up
// is what gives a real "leap" feel: you keep accelerating in your
// movement direction through the arc.
pub const CMC_AIR_CONTROL_BOOST_MULT: usize = 0x02C4;
// UCharacterMovementComponent.AirControlBoostVelocityThreshold (Engine_classes.hpp:31516).
// Speed below which the boost multiplier above kicks in. Pushing this
// up means the boost stays active even when already moving fast.
pub const CMC_AIR_CONTROL_BOOST_THRESHOLD: usize = 0x02C8;
// UCharacterMovementComponent.MaxWalkSpeed (Engine_classes.hpp:31500).
pub const CMC_MAX_WALK_SPEED: usize = 0x0288;
// UCharacterMovementComponent.MaxSwimSpeed (Engine_classes.hpp:31502).
pub const CMC_MAX_SWIM_SPEED: usize = 0x0290;
// UCharacterMovementComponent.MaxFlySpeed (Engine_classes.hpp:31503).
pub const CMC_MAX_FLY_SPEED: usize = 0x0294;
// UMaineCharMovementComponent.MaxSprintSpeed (Maine_classes.hpp:33015).
pub const CMC_MAX_SPRINT_SPEED: usize = 0x10EC;
// UMaineCharMovementComponent.MaxSwimSprintSpeed (Maine_classes.hpp:33038).
pub const CMC_MAX_SWIM_SPRINT_SPEED: usize = 0x1164;
// UMaineCharMovementComponent.CustomGroundSpeedMultiplier (Maine_classes.hpp:33050).
pub const CMC_CUSTOM_GROUND_SPEED_MULTIPLIER: usize = 0x1198;
// UMaineCharMovementComponent.CustomFlySpeedMultiplier (Maine_classes.hpp:33051).
pub const CMC_CUSTOM_FLY_SPEED_MULTIPLIER: usize = 0x119C;
// UMaineCharMovementComponent.CustomSwimSpeedMultiplier (Maine_classes.hpp:33052).
pub const CMC_CUSTOM_SWIM_SPEED_MULTIPLIER: usize = 0x11A0;

// Movement axis groupings (multiple offsets that should scale together).
const MOVE_SPEED_OFFSETS: &[usize] = &[
    CMC_MAX_WALK_SPEED,
    CMC_MAX_SPRINT_SPEED,
    CMC_MAX_SWIM_SPEED,
    CMC_MAX_SWIM_SPRINT_SPEED,
    CMC_CUSTOM_GROUND_SPEED_MULTIPLIER,
    CMC_CUSTOM_SWIM_SPEED_MULTIPLIER,
];
const JUMP_HEIGHT_OFFSETS: &[usize] = &[CMC_JUMP_Z_VELOCITY];
const GLIDE_SPEED_OFFSETS: &[usize] = &[CMC_MAX_FLY_SPEED, CMC_CUSTOM_FLY_SPEED_MULTIPLIER];
// Health regen scaling: tick percentage scales with the bonus
// (more healing per tick) while tick rate scales inversely (more
// frequent ticks). Delay is left untouched to preserve the
// "post-combat" feel.
const HEALTH_REGEN_OFFSETS: &[(usize, f32)] = &[
    (GCD_COMBAT_REGEN_TICK_PERCENTAGE, 1.0),
    (GCD_COMBAT_REGEN_TICK_RATE, -1.0),
];
const LEAP_DISTANCE_OFFSETS: &[usize] = &[
    CMC_AIR_CONTROL,
    CMC_AIR_CONTROL_BOOST_MULT,
    CMC_AIR_CONTROL_BOOST_THRESHOLD,
];

// ---------------------------------------------------------------------
// CATALOG: the source of truth.
// ---------------------------------------------------------------------

use ueforge::rpg::SkillRegistry;
use ueforge::ue::TypedField;

/// All catalog rows -- the bare slice. Wrapped in [`CATALOG`] for
/// the canonical `<Subject>Registry` shape used everywhere else
/// in the workspace; this slice is kept named so existing callers
/// can still iterate the rows directly.
pub const CATALOG_ENTRIES: &[SkillDef] = &[
    SkillDef {
        id: SKILL_BACKPACK,
        display_name: "Backpack",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::BackpackSlots {
            max_bonus_slots: 460,
        },
    },
    SkillDef {
        id: SKILL_HUNGER,
        display_name: "Hunger Resistance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::SurvivalDrain {
            field_offset: SURVIVAL_HUNGER_OFFSET,
            max_reduction: 0.75,
            which: SurvivalField::Hunger,
        },
    },
    SkillDef {
        id: SKILL_THIRST,
        display_name: "Thirst Resistance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::SurvivalDrain {
            field_offset: SURVIVAL_THIRST_OFFSET,
            max_reduction: 0.75,
            which: SurvivalField::Thirst,
        },
    },
    SkillDef {
        id: SKILL_ATTACK_DAMAGE,
        display_name: "Attack Damage",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerFloat {
            offset: TypedField::at(ASC_CUSTOM_DAMAGE_MULTIPLIER),
            base: 1.0,
            max_bonus: 3.00,
            format: PercentFormat::PlusPercentMult { word: "damage" },
        }),
    },
    SkillDef {
        id: SKILL_ARMOR,
        display_name: "Armor",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerSubcomponentFloat {
            component_offset: TypedField::at(crate::rpg::apply::ASC_HEALTH_COMPONENT),
            field_offset: TypedField::at(HC_BASE_DAMAGE_REDUCTION),
            base: 0.0,
            max_bonus: 0.50,
            format: PercentFormat::MinusPercent { word: "damage taken" },
        }),
    },
    SkillDef {
        id: SKILL_MOVE_SPEED,
        display_name: "Move Speed",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerSubcomponentMultiply {
            component_offset: TypedField::at(crate::rpg::apply::ASC_CHAR_MOVEMENT_COMPONENT),
            offsets: MOVE_SPEED_OFFSETS,
            max_bonus: 3.00,
            format_word: "move",
            vanilla: &crate::rpg::apply::MOVEMENT_VANILLA,
        }),
    },
    SkillDef {
        id: SKILL_JUMP_HEIGHT,
        display_name: "Jump Height",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerSubcomponentMultiply {
            component_offset: TypedField::at(crate::rpg::apply::ASC_CHAR_MOVEMENT_COMPONENT),
            offsets: JUMP_HEIGHT_OFFSETS,
            max_bonus: 3.00,
            format_word: "jump",
            vanilla: &crate::rpg::apply::MOVEMENT_VANILLA,
        }),
    },
    SkillDef {
        id: SKILL_LEAP_DISTANCE,
        display_name: "Leap Distance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerSubcomponentMultiply {
            component_offset: TypedField::at(crate::rpg::apply::ASC_CHAR_MOVEMENT_COMPONENT),
            offsets: LEAP_DISTANCE_OFFSETS,
            max_bonus: 5.00,
            format_word: "leap",
            vanilla: &crate::rpg::apply::MOVEMENT_VANILLA,
        }),
    },
    SkillDef {
        id: SKILL_GLIDE_SPEED,
        display_name: "Glide Speed",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerSubcomponentMultiply {
            component_offset: TypedField::at(crate::rpg::apply::ASC_CHAR_MOVEMENT_COMPONENT),
            offsets: GLIDE_SPEED_OFFSETS,
            max_bonus: 3.00,
            format_word: "glide",
            vanilla: &crate::rpg::apply::MOVEMENT_VANILLA,
        }),
    },
    SkillDef {
        id: SKILL_FALL_RESISTANCE,
        display_name: "Fall Damage Resistance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerFallDamageReduction {
            ratio_offset: ASC_FALL_DAMAGE_RATIO,
            take_fall_damage_offset: ASC_TAKE_FALL_DAMAGE,
            min_velocity_offset: ASC_MINIMUM_FALL_DAMAGE_VELOCITY,
            max_reduction: 1.00,
            format: PercentFormat::MinusPercent { word: "fall damage" },
        },
    },
    SkillDef {
        id: SKILL_IMPACT_RESISTANCE,
        display_name: "Impact Damage Resistance",
        max_level: SKILL_MAX_LEVEL,
        // Pure runtime: kill_hook's trampoline intercepts
        // ApplyDamageFromInfo, reads FDamageInfo.DamageType, and
        // if the DamageType class matches BP_EnvironmentalDamage_C
        // scales Damage by (1 - reduction * progress(level)).
        // See ../docs/damage.md "REVISED fix path".
        effect: SkillEffect::Standard(StandardEffect::Runtime {
            max_bonus: 1.0,
            format: PercentFormat::MinusPercent { word: "environmental damage" },
        }),
    },
    SkillDef {
        id: SKILL_MAX_HEALTH,
        display_name: "Max Health",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::PlayerSubcomponentAdditive {
            component_offset: TypedField::at(crate::rpg::apply::ASC_HEALTH_COMPONENT),
            field_offset: TypedField::at(HC_MAX_HEALTH),
            max_bonus: 200.0,
            format_word: "max HP",
            vanilla: &crate::rpg::apply::MAX_HEALTH_VANILLA,
        }),
    },
    SkillDef {
        id: SKILL_HEALTH_REGEN,
        display_name: "Health Regen",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::ClassFieldsMultiply {
            class: &crate::rpg::apply::CLASS_GLOBAL_COMBAT_DATA,
            offsets: HEALTH_REGEN_OFFSETS,
            max_bonus: 5.00,
            format_word: "regen",
            vanilla: &crate::rpg::apply::GLOBAL_DATA_VANILLA,
        }),
    },
    SkillDef {
        id: SKILL_LIFESTEAL,
        display_name: "Lifesteal",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Standard(StandardEffect::Runtime {
            max_bonus: 0.90,
            format: PercentFormat::PlusPercent { word: "lifesteal" },
        }),
    },
];

/// Canonical catalog handle -- the `<Subject>Registry` wrapper
/// matching the workspace contract. Pass this to `Tracker::new`
/// and use `.def(id)` for lookups.
pub const CATALOG: SkillRegistry<SkillEffect> = SkillRegistry::new(CATALOG_ENTRIES);

pub fn lookup(id: &str) -> Option<&'static SkillDef> {
    CATALOG.def(id)
}


// ---------------------------------------------------------------------
// Per-level math.
// ---------------------------------------------------------------------

/// Diminishing-returns progress at `level`. Range [0.0, 1.0]. Square
/// root so each early level matters and late levels flatten gracefully.
/// Thin alias over `ueforge::rpg::progress::sqrt_progress` so call
/// sites stay terse.
pub fn level_progress(level: u32) -> f32 {
    ueforge::rpg::progress::sqrt_progress(level, SKILL_MAX_LEVEL)
}

/// Generic "skill bonus" for any effect that maxes at `max_bonus` at
/// level 100. Used by apply.rs and the formatter.
pub fn skill_bonus(max_bonus: f32, level: u32) -> f32 {
    max_bonus * level_progress(level)
}

/// Backpack-specific bonus rounded to int. (Convenience for callers
/// who don't want to redo the float math.)
pub fn backpack_bonus_at(level: u32, max_bonus_slots: i32) -> i32 {
    (max_bonus_slots as f32 * level_progress(level)).round() as i32
}

/// Lifesteal (or any other Runtime effect) fraction.
pub fn runtime_fraction(level: u32, max_bonus: f32) -> f32 {
    skill_bonus(max_bonus, level)
}

// ---------------------------------------------------------------------
// Format effect text for the ImGui tab. One match arm per
// PercentFormat variant; the catalog row determines which arm runs.
// ---------------------------------------------------------------------

pub fn format_effect(id: &str, level: u32) -> String {
    let Some(skill) = lookup(id) else {
        return String::new();
    };
    match &skill.effect {
        SkillEffect::Standard(e) => e.format(level, skill.max_level),
        SkillEffect::BackpackSlots { max_bonus_slots } => {
            let bonus = backpack_bonus_at(level, *max_bonus_slots);
            format!("+{bonus} slots")
        }
        SkillEffect::SurvivalDrain { max_reduction, .. } => {
            let mult = (1.0 - skill_bonus(*max_reduction, level)).max(0.0);
            let pct = ((1.0 - mult) * 100.0).round() as i32;
            format!("-{pct}% drain ({mult:.2}x)")
        }
        SkillEffect::PlayerFallDamageReduction { max_reduction, format, .. } => {
            ueforge::rpg::format::format_pct(0.0, *max_reduction, level, SKILL_MAX_LEVEL, format)
        }
    }
}
