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

    /// Additive write on the player's `UHealthComponent`. Captures
    /// vanilla on first sight, then writes `vanilla + max_bonus *
    /// progress`. Used for Max Health: the player keeps stacking
    /// HP rather than scaling a baseline value (so gear / status
    /// effects that also touch the field are preserved).
    PlayerHealthCompAdditive {
        offset: usize,
        max_bonus: f32,
        format_word: &'static str,
    },

    /// Bitmask write on the player's `UHealthComponent` -- when level
    /// > 0, set the named uint32 field to `mask`. Used by Impact Damage
    /// Resistance to set `RequiredDamageTypeFlags` so damage with no
    /// flag bits (fall, environmental) fails the native gate while
    /// creature attacks (which carry non-zero type flags) pass through.
    PlayerHealthCompU32Mask {
        offset: usize,
        mask: u32,
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

    /// Per-offset multiplier write on every instance of a named
    /// class. Vanilla captured on first sight per (class, offset)
    /// pair. Each entry is `(offset, exponent)`: written value is
    /// `vanilla * (1 + max_bonus * progress) ^ exponent`. Use
    /// exponent = +1.0 for "boost" fields (more is better) and
    /// exponent = -1.0 for "shrink" fields (lower is better, e.g.
    /// regen tick rate). Used for global-data assets that drive a
    /// gameplay system from one shared singleton-style object.
    GlobalDataMult {
        class_name: &'static str,
        offsets: &'static [(usize, f32)],
        max_bonus: f32,
        format_word: &'static str,
    },

    /// Pure runtime effect. The kill_hook (or any other live
    /// trampoline) reads the current level on every tick and acts on
    /// it, no CDO write.
    Runtime {
        max_bonus: f32,
        format: PercentFormat,
    },

    /// Apply a row from `Table_StatusEffects` to the player's
    /// `UStatusEffectComponent`. **The canonical pattern Grounded 2
    /// itself uses** for gear/perk/HoT effects (proved by the
    /// bandage research: bandages are a `Type=Health` row applied
    /// this way). Migrating skills to this surface integrates with
    /// vanilla heal/damage multipliers, replicates correctly, and
    /// avoids the `RequiredDamageTypeFlags` mask bug that blocked
    /// bandages.
    ///
    /// `row_fname` is the FName u64 of the chosen row in
    /// `Table_StatusEffects` (capture via the discovery test
    /// `tests/explore_status_effect_rows.rs`). `value_at_max` is
    /// the row's `Value` we'll write at level 100; vanilla
    /// (level 0) restores whatever was captured.
    PlayerStatusEffect {
        row_fname: u64,
        /// Value the row's `Value` field is set to at level 100.
        /// At level 0, the captured vanilla is restored.
        /// Examples:
        ///   - FallDamage type (mul, vanilla 1.0): set to 0.0 for
        ///     full immunity at L100.
        ///   - DamageReductionMultiplier (add, vanilla 0.0): set
        ///     to 1.0 for full reduction at L100.
        ///   - MaxHealth (add, vanilla 0.0): set to e.g. 200.0 for
        ///     +200 HP at L100.
        value_at_max: f32,
        format_word: &'static str,
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

// UHealthComponent.MaxHealth (docs/damage.md "HealthComponent layout").
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
        id: SKILL_LEAP_DISTANCE,
        display_name: "Leap Distance",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerMovementMult {
            offsets: LEAP_DISTANCE_OFFSETS,
            max_bonus: 5.00,
            format_word: "leap",
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
        id: SKILL_IMPACT_RESISTANCE,
        display_name: "Impact Damage Resistance",
        max_level: SKILL_MAX_LEVEL,
        // MIGRATED 2026-05-09 to a Runtime effect: no CDO write,
        // no mask. kill_hook's trampoline intercepts
        // ApplyDamageFromInfo on the player HC, reads
        // FDamageInfo.DamageType, and if the DamageType class
        // matches BP_EnvironmentalDamage_C scales the Damage
        // parm by (1 - reduction * progress(level)) before
        // forwarding. Same shape as fall_resistance's
        // velocity-stomp on OnLanded -- just a different surface
        // (ApplyDamageFromInfo) and a different discriminator
        // (DamageType class instead of "the only fall path").
        //
        // Why this and not the binary mask: the mask
        // (RequiredDamageTypeFlags = 0xFFFFFFFF) blocked all
        // type_flags=0 events, including bandage heal-ticks --
        // hard regression on the user. The intercept-and-scale
        // approach only touches damage events whose DamageType
        // is environmental; heals and combat damage pass through
        // untouched. See docs/damage.md "REVISED fix path".
        effect: SkillEffect::Runtime {
            max_bonus: 1.0,
            format: PercentFormat::MinusPercent {
                word: "environmental damage",
            },
        },
    },
    Skill {
        id: SKILL_MAX_HEALTH,
        display_name: "Max Health",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::PlayerHealthCompAdditive {
            offset: HC_MAX_HEALTH,
            max_bonus: 200.0,
            format_word: "max HP",
        },
    },
    Skill {
        id: SKILL_HEALTH_REGEN,
        display_name: "Health Regen",
        max_level: SKILL_MAX_LEVEL,
        effect: SkillEffect::GlobalDataMult {
            class_name: "GlobalCombatData",
            offsets: HEALTH_REGEN_OFFSETS,
            max_bonus: 5.00,
            format_word: "regen",
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
        SkillEffect::PlayerHealthCompU32Mask { format, .. } => {
            // Boolean-style: active when the player has at least one
            // skill point, full strength applied unconditionally (the
            // gate is binary, not scaled).
            let bonus = if level > 0 { 1.0 } else { 0.0 };
            format_pct(0.0, bonus, level, format)
        }
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
        SkillEffect::GlobalDataMult {
            max_bonus,
            format_word,
            ..
        } => {
            let mult = 1.0 + skill_bonus(*max_bonus, level);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% {format_word} ({:.2}x)", mult)
        }
        SkillEffect::PlayerHealthCompAdditive {
            max_bonus,
            format_word,
            ..
        } => {
            let bonus = skill_bonus(*max_bonus, level).round() as i32;
            format!("+{bonus} {format_word}")
        }
        SkillEffect::PlayerStatusEffect {
            value_at_max,
            format_word,
            ..
        } => {
            // Pure presence indicator -- the engine computes the
            // effective stat after combining with vanilla rows of
            // the same Type, so a precise per-skill value isn't
            // available here without knowing the row's Type.
            let progress = level_progress(level);
            let pct = (progress * 100.0).round() as i32;
            format!("{pct}% {format_word} (to value={:.2})", value_at_max * progress)
        }
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
