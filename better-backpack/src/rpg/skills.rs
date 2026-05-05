// Skill catalog and per-level math.
//
// Vocabulary (consistent throughout the codebase):
//   - "skill"        the upgrade slot itself (e.g. Backpack, Lifesteal)
//   - "skill point"  a currency the player earns by leveling
//   - "skill level"  how many points have been spent on a given skill
//
// Each skill scales 0..=100 levels. Final bonus at level 100 is the
// per-skill "max_bonus" constant. Levels in between scale via
// `level_progress(level) = sqrt(level / 100)` so:
//   level 1   -> 10% of max
//   level 10  -> 32% of max
//   level 25  -> 50% of max
//   level 50  -> 71% of max
//   level 100 -> 100% of max
// Sqrt feels generous early (every level is felt) and naturally
// flattens at the end (you can sink 99 -> 100 but the gain is small).

pub const SKILL_BACKPACK: &str = "backpack";
pub const SKILL_HUNGER: &str = "hunger";
pub const SKILL_THIRST: &str = "thirst";
pub const SKILL_ATTACK_DAMAGE: &str = "attack_damage";
pub const SKILL_ARMOR: &str = "armor";
pub const SKILL_MOVE_SPEED: &str = "move_speed";
pub const SKILL_JUMP_HEIGHT: &str = "jump_height";
pub const SKILL_GLIDE_SPEED: &str = "glide_speed";
pub const SKILL_LIFESTEAL: &str = "lifesteal";

/// Universal cap. Every skill scales 0..=100 with diminishing returns.
pub const SKILL_MAX_LEVEL: u32 = 100;

// Per-skill "final" bonuses at level 100. Tunable.
const BACKPACK_MAX_BONUS_SLOTS: i32 = 60; // 40 vanilla -> 100 at level 100
const HUNGER_MAX_REDUCTION: f32 = 0.75;   // 1.0x -> 0.25x drain
const THIRST_MAX_REDUCTION: f32 = 0.75;
const ATTACK_DAMAGE_MAX_BONUS: f32 = 0.50; // 1.0x -> 1.5x
const ARMOR_MAX_REDUCTION: f32 = 0.50;     // 0% -> 50% damage taken cut
const MOVE_SPEED_MAX_BONUS: f32 = 0.50;    // 1.0x -> 1.5x
const JUMP_HEIGHT_MAX_BONUS: f32 = 0.80;   // 1.0x -> 1.8x
const GLIDE_SPEED_MAX_BONUS: f32 = 0.50;   // 1.0x -> 1.5x
const LIFESTEAL_MAX_FRACTION: f32 = 0.30;  // 0% -> 30% of damage healed back

#[derive(Debug, Clone, Copy)]
pub struct Skill {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
}

pub const CATALOG: &[Skill] = &[
    Skill { id: SKILL_BACKPACK, display_name: "Backpack", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_HUNGER, display_name: "Hunger Resistance", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_THIRST, display_name: "Thirst Resistance", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_ATTACK_DAMAGE, display_name: "Attack Damage", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_ARMOR, display_name: "Armor", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_MOVE_SPEED, display_name: "Move Speed", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_JUMP_HEIGHT, display_name: "Jump Height", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_GLIDE_SPEED, display_name: "Glide Speed", max_level: SKILL_MAX_LEVEL },
    Skill { id: SKILL_LIFESTEAL, display_name: "Lifesteal", max_level: SKILL_MAX_LEVEL },
];

pub fn lookup(id: &str) -> Option<&'static Skill> {
    CATALOG.iter().find(|s| s.id == id)
}

/// Diminishing-returns progress at `level`. Range [0.0, 1.0].
/// Square-root curve so each early level matters and late levels
/// flatten gracefully.
pub fn level_progress(level: u32) -> f32 {
    let l = level.min(SKILL_MAX_LEVEL) as f32;
    (l / SKILL_MAX_LEVEL as f32).sqrt()
}

/// Slot-count bonus added on top of the settings base.
pub fn backpack_bonus(level: u32) -> i32 {
    (BACKPACK_MAX_BONUS_SLOTS as f32 * level_progress(level)).round() as i32
}

/// Hunger drain multiplier: 1.0 at level 0, 0.25 at level 100.
pub fn hunger_multiplier(level: u32) -> f32 {
    (1.0 - HUNGER_MAX_REDUCTION * level_progress(level)).max(0.0)
}

/// Thirst drain multiplier.
pub fn thirst_multiplier(level: u32) -> f32 {
    (1.0 - THIRST_MAX_REDUCTION * level_progress(level)).max(0.0)
}

/// Player damage multiplier from the Attack Damage skill.
pub fn attack_damage_multiplier(level: u32) -> f32 {
    1.0 + ATTACK_DAMAGE_MAX_BONUS * level_progress(level)
}

/// Damage reduction fraction from the Armor skill.
pub fn armor_reduction(level: u32) -> f32 {
    (ARMOR_MAX_REDUCTION * level_progress(level)).clamp(0.0, 1.0)
}

/// Movement speed multiplier (applied to MaxWalkSpeed and
/// MaxSprintSpeed and MaxSwimSpeed).
pub fn move_speed_multiplier(level: u32) -> f32 {
    1.0 + MOVE_SPEED_MAX_BONUS * level_progress(level)
}

/// Jump-Z velocity multiplier.
pub fn jump_height_multiplier(level: u32) -> f32 {
    1.0 + JUMP_HEIGHT_MAX_BONUS * level_progress(level)
}

/// Glide speed (MaxFlySpeed) multiplier.
pub fn glide_speed_multiplier(level: u32) -> f32 {
    1.0 + GLIDE_SPEED_MAX_BONUS * level_progress(level)
}

/// Fraction of damage dealt that heals the player back.
pub fn lifesteal_fraction(level: u32) -> f32 {
    LIFESTEAL_MAX_FRACTION * level_progress(level)
}

/// Human-readable effect description for `id` at `level`. The string
/// is what the ImGui tab displays so the player knows what the skill
/// does. Format: short, fits on one line next to "level N / MAX".
pub fn format_effect(id: &str, level: u32) -> String {
    match id {
        SKILL_BACKPACK => {
            let bonus = backpack_bonus(level);
            format!("+{bonus} slots")
        }
        SKILL_HUNGER => {
            let mult = hunger_multiplier(level);
            let pct = ((1.0 - mult) * 100.0).round() as i32;
            format!("-{pct}% drain ({:.2}x)", mult)
        }
        SKILL_THIRST => {
            let mult = thirst_multiplier(level);
            let pct = ((1.0 - mult) * 100.0).round() as i32;
            format!("-{pct}% drain ({:.2}x)", mult)
        }
        SKILL_ATTACK_DAMAGE => {
            let mult = attack_damage_multiplier(level);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% damage ({:.2}x)", mult)
        }
        SKILL_ARMOR => {
            let red = armor_reduction(level);
            let pct = (red * 100.0).round() as i32;
            format!("-{pct}% damage taken")
        }
        SKILL_MOVE_SPEED => {
            let mult = move_speed_multiplier(level);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% move ({:.2}x)", mult)
        }
        SKILL_JUMP_HEIGHT => {
            let mult = jump_height_multiplier(level);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% jump ({:.2}x)", mult)
        }
        SKILL_GLIDE_SPEED => {
            let mult = glide_speed_multiplier(level);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% glide ({:.2}x)", mult)
        }
        SKILL_LIFESTEAL => {
            let frac = lifesteal_fraction(level);
            let pct = (frac * 100.0).round() as i32;
            format!("+{pct}% lifesteal")
        }
        _ => String::new(),
    }
}
