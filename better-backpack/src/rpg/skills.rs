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
pub const SKILL_LIFESTEAL: &str = "lifesteal";

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

#[derive(Debug, Clone, Copy)]
pub enum SkillEffect {
    /// Bonus slots added to `settings.inventory.slot_count`.
    /// `max_bonus_slots` is the integer added at level 100.
    /// Applied via `patch::run` over all InventoryComponents.
    BackpackSlots { max_bonus_slots: i32 },

    /// Survival drain rate. Final value =
    /// `vanilla * settings.survival.<x>_multiplier * (1 - max_reduction * progress)`.
    /// `field_offset` is the offset of `AdjustmentPerSecond` inside
    /// SurvivalComponent (hunger or thirst).
    SurvivalDrain {
        field_offset: usize,
        max_reduction: f32,
        which: SurvivalField,
    },

    /// Direct float write on `ASurvivalCharacter` player CDO.
    /// Final value = `base + max_bonus * progress`.
    PlayerCharFloat {
        offset: usize,
        base: f32,
        max_bonus: f32,
        /// "+50% damage" / "-50% damage taken" / "+30% lifesteal" etc.
        format: PercentFormat,
    },

    /// Direct float write on the player's `UHealthComponent` (followed
    /// from the player CDO via the HealthComponent ptr at +0x1340).
    /// Final value = `base + max_bonus * progress`.
    PlayerHealthCompFloat {
        offset: usize,
        base: f32,
        max_bonus: f32,
        format: PercentFormat,
    },

    /// Multiply captured vanilla baselines on the player's
    /// `UMaineCharMovementComponent` (followed from the player CDO at
    /// +0x1380). All `offsets` get scaled by the same multiplier
    /// `1 + max_bonus * progress` against the captured vanilla value
    /// at that offset. Use one entry per movement axis (walk vs jump
    /// vs fly are separate skills).
    PlayerMovementMult {
        offsets: &'static [usize],
        max_bonus: f32,
        /// Word inserted in the formatted "+50% <word>" line.
        format_word: &'static str,
    },

    /// Scale the player's fall-damage ratio against the captured
    /// vanilla baseline on `ASurvivalCharacter`.
    PlayerFallDamageReduction {
        ratio_offset: usize,
        take_fall_damage_offset: usize,
        min_velocity_offset: usize,
        max_reduction: f32,
        format: PercentFormat,
    },

    /// Pure runtime effect. The kill_hook (or any other live
    /// trampoline) reads the current level on every tick and acts on
    /// it, no CDO write.
    Runtime {
        max_bonus: f32,
        format: PercentFormat,
    },
}

#[derive(Debug, Clone, Copy)]
pub enum PercentFormat {
    /// "+25% damage (1.25x)" (multiplier-style buff)
    PlusPercentMult { word: &'static str },
    /// "-25% damage taken" (reduction-style buff)
    MinusPercent { word: &'static str },
    /// "+30% lifesteal" (raw fraction)
    PlusPercent { word: &'static str },
    /// "-25% drain (0.75x)" (multiplicative drain reduction)
    DrainReduction,
}

#[derive(Debug, Clone, Copy)]
pub struct Skill {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect: SkillEffect,
}

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

// UHealthComponent.BaseDamageReduction (Maine_classes.hpp:42193).
pub const HC_BASE_DAMAGE_REDUCTION: usize = 0x00EC;

// UCharacterMovementComponent.JumpZVelocity (Engine_classes.hpp:31485).
pub const CMC_JUMP_Z_VELOCITY: usize = 0x01B8;
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

// ---------------------------------------------------------------------
// CATALOG: the source of truth.
// ---------------------------------------------------------------------

pub const CATALOG: &[Skill] = &[
    Skill {
        id: SKILL_BACKPACK,
        display_name: "Backpack",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::BackpackSlots {
            max_bonus_slots: 460,
        },
    },
    Skill {
        id: SKILL_HUNGER,
        display_name: "Hunger Resistance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::SurvivalDrain {
            field_offset: SURVIVAL_HUNGER_OFFSET,
            max_reduction: 0.75,
            which: SurvivalField::Hunger,
        },
    },
    Skill {
        id: SKILL_THIRST,
        display_name: "Thirst Resistance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::SurvivalDrain {
            field_offset: SURVIVAL_THIRST_OFFSET,
            max_reduction: 0.75,
            which: SurvivalField::Thirst,
        },
    },
    Skill {
        id: SKILL_ATTACK_DAMAGE,
        display_name: "Attack Damage",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerCharFloat {
            offset: ASC_CUSTOM_DAMAGE_MULTIPLIER,
            base: 1.0,
            max_bonus: 3.00,
            format: PercentFormat::PlusPercentMult { word: "damage" },
        },
    },
    Skill {
        id: SKILL_ARMOR,
        display_name: "Armor",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerHealthCompFloat {
            offset: HC_BASE_DAMAGE_REDUCTION,
            base: 0.0,
            max_bonus: 0.50,
            format: PercentFormat::MinusPercent {
                word: "damage taken",
            },
        },
    },
    Skill {
        id: SKILL_MOVE_SPEED,
        display_name: "Move Speed",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerMovementMult {
            offsets: MOVE_SPEED_OFFSETS,
            max_bonus: 3.00,
            format_word: "move",
        },
    },
    Skill {
        id: SKILL_JUMP_HEIGHT,
        display_name: "Jump Height",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerMovementMult {
            offsets: JUMP_HEIGHT_OFFSETS,
            max_bonus: 3.00,
            format_word: "jump",
        },
    },
    Skill {
        id: SKILL_GLIDE_SPEED,
        display_name: "Glide Speed",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerMovementMult {
            offsets: GLIDE_SPEED_OFFSETS,
            max_bonus: 3.00,
            format_word: "glide",
        },
    },
    Skill {
        id: SKILL_FALL_RESISTANCE,
        display_name: "Fall Damage Resistance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerFallDamageReduction {
            ratio_offset: ASC_FALL_DAMAGE_RATIO,
            take_fall_damage_offset: ASC_TAKE_FALL_DAMAGE,
            min_velocity_offset: ASC_MINIMUM_FALL_DAMAGE_VELOCITY,
            max_reduction: 1.00,
            format: PercentFormat::MinusPercent {
                word: "fall damage",
            },
        },
    },
    Skill {
        id: SKILL_LIFESTEAL,
        display_name: "Lifesteal",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::Runtime {
            max_bonus: 0.90,
            format: PercentFormat::PlusPercent { word: "lifesteal" },
        },
    },
];

pub fn lookup(id: &str) -> Option<&'static Skill> {
    CATALOG.iter().find(|s| s.id == id)
}

// ---------------------------------------------------------------------
// Per-level math.
// ---------------------------------------------------------------------

/// Diminishing-returns progress at `level`. Range [0.0, 1.0]. Square
/// root so each early level matters and late levels flatten gracefully.
pub fn level_progress(level: u32) -> f32 {
    let l = level.min(SKILL_MAX_LEVEL) as f32;
    (l / SKILL_MAX_LEVEL as f32).sqrt()
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
        SkillEffect::BackpackSlots { max_bonus_slots } => {
            let bonus = backpack_bonus_at(level, *max_bonus_slots);
            format!("+{bonus} slots")
        }
        SkillEffect::SurvivalDrain { max_reduction, .. } => {
            let mult = (1.0 - skill_bonus(*max_reduction, level)).max(0.0);
            let pct = ((1.0 - mult) * 100.0).round() as i32;
            format!("-{pct}% drain ({:.2}x)", mult)
        }
        SkillEffect::PlayerCharFloat {
            base,
            max_bonus,
            format,
            ..
        }
        | SkillEffect::PlayerHealthCompFloat {
            base,
            max_bonus,
            format,
            ..
        } => format_pct(*base, *max_bonus, level, format),
        SkillEffect::PlayerFallDamageReduction {
            max_reduction,
            format,
            ..
        } => format_pct(0.0, *max_reduction, level, format),
        SkillEffect::PlayerMovementMult {
            max_bonus,
            format_word,
            ..
        } => {
            let mult = 1.0 + skill_bonus(*max_bonus, level);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% {format_word} ({:.2}x)", mult)
        }
        SkillEffect::Runtime { max_bonus, format } => format_pct(0.0, *max_bonus, level, format),
    }
}

fn format_pct(base: f32, max_bonus: f32, level: u32, fmt: &PercentFormat) -> String {
    let bonus = skill_bonus(max_bonus, level);
    let value = base + bonus;
    match fmt {
        PercentFormat::PlusPercentMult { word } => {
            let pct = (bonus * 100.0).round() as i32;
            format!("+{pct}% {word} ({:.2}x)", value)
        }
        PercentFormat::MinusPercent { word } => {
            let pct = (bonus * 100.0).round() as i32;
            format!("-{pct}% {word}")
        }
        PercentFormat::PlusPercent { word } => {
            let pct = (bonus * 100.0).round() as i32;
            format!("+{pct}% {word}")
        }
        PercentFormat::DrainReduction => {
            let mult = (1.0 - bonus).max(0.0);
            let pct = (bonus * 100.0).round() as i32;
            format!("-{pct}% drain ({:.2}x)", mult)
        }
    }
}
