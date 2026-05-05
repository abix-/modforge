// Skill catalog and per-rank math.
//
// Three skills initially. Each one's per-rank effect is settings-
// independent: callers combine `settings_base + skill_bonus` (additive)
// or `settings_mult * skill_mult` (multiplicative) at apply time.
// This keeps skills.rs free of any settings shape.
//
//   - backpack: +5 slots per rank, max rank 12 (rank 12 -> +60 slots)
//   - hunger:   -7.5% drain per rank, max rank 10 (rank 10 -> 0.25x)
//   - thirst:   -7.5% drain per rank, max rank 10 (rank 10 -> 0.25x)
//
// Settings own the BASE; skills layer on top. See the design note at
// TODO.md section 0 step 3.

pub const SKILL_BACKPACK: &str = "backpack";
pub const SKILL_HUNGER: &str = "hunger";
pub const SKILL_THIRST: &str = "thirst";
pub const SKILL_ATTACK_DAMAGE: &str = "attack_damage";
pub const SKILL_ARMOR: &str = "armor";

pub const BACKPACK_PER_RANK: i32 = 5;
pub const BACKPACK_MAX_RANK: u32 = 12;

pub const SURVIVAL_PER_RANK_FRACTION: f32 = 0.075;
pub const SURVIVAL_MAX_RANK: u32 = 10;

// Attack damage: +5% per rank, max rank 10 -> 1.5x player damage.
pub const ATTACK_DAMAGE_PER_RANK_FRACTION: f32 = 0.05;
pub const ATTACK_DAMAGE_MAX_RANK: u32 = 10;

// Armor: +5% damage reduction per rank, max rank 10 -> 0.5 reduction
// (50% less damage taken). UE applies BaseDamageReduction as a flat
// fraction subtracted from incoming damage; we cap at the engine's
// MaximumDamageReductionMultiplier (1.0) which is already the upper
// bound of the field.
pub const ARMOR_PER_RANK_REDUCTION: f32 = 0.05;
pub const ARMOR_MAX_RANK: u32 = 10;

#[derive(Debug, Clone, Copy)]
pub struct Skill {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_rank: u32,
}

pub const CATALOG: &[Skill] = &[
    Skill { id: SKILL_BACKPACK, display_name: "Backpack", max_rank: BACKPACK_MAX_RANK },
    Skill { id: SKILL_HUNGER, display_name: "Hunger Resistance", max_rank: SURVIVAL_MAX_RANK },
    Skill { id: SKILL_THIRST, display_name: "Thirst Resistance", max_rank: SURVIVAL_MAX_RANK },
    Skill { id: SKILL_ATTACK_DAMAGE, display_name: "Attack Damage", max_rank: ATTACK_DAMAGE_MAX_RANK },
    Skill { id: SKILL_ARMOR, display_name: "Armor", max_rank: ARMOR_MAX_RANK },
];

pub fn lookup(id: &str) -> Option<&'static Skill> {
    CATALOG.iter().find(|s| s.id == id)
}

/// Slot-count bonus added on top of the settings base. Rank 0 = 0.
pub fn backpack_bonus(rank: u32) -> i32 {
    let r = rank.min(BACKPACK_MAX_RANK) as i32;
    BACKPACK_PER_RANK * r
}

/// Multiplier applied on top of the settings hunger/thirst multiplier.
/// Rank 0 = 1.0 (no skill effect). Rank 10 = 0.25.
pub fn survival_multiplier(rank: u32) -> f32 {
    let r = rank.min(SURVIVAL_MAX_RANK) as f32;
    (1.0 - SURVIVAL_PER_RANK_FRACTION * r).max(0.0)
}

/// Player damage multiplier from the Attack Damage skill. Rank 0 = 1.0,
/// rank 10 = 1.5.
pub fn attack_damage_multiplier(rank: u32) -> f32 {
    let r = rank.min(ATTACK_DAMAGE_MAX_RANK) as f32;
    1.0 + ATTACK_DAMAGE_PER_RANK_FRACTION * r
}

/// Damage reduction fraction from the Armor skill. Rank 0 = 0.0,
/// rank 10 = 0.5.
pub fn armor_reduction(rank: u32) -> f32 {
    let r = rank.min(ARMOR_MAX_RANK) as f32;
    (ARMOR_PER_RANK_REDUCTION * r).clamp(0.0, 1.0)
}

/// Human-readable effect description for `id` at `rank`. The string is
/// what the ImGui tab displays so the player knows what the skill
/// does. Format: short, fits on one line next to "rank N/MAX".
pub fn format_effect(id: &str, rank: u32) -> String {
    match id {
        SKILL_BACKPACK => {
            let bonus = backpack_bonus(rank);
            format!("+{bonus} slots")
        }
        SKILL_HUNGER => {
            let mult = survival_multiplier(rank);
            let pct = ((1.0 - mult) * 100.0).round() as i32;
            format!("-{pct}% drain ({:.2}x)", mult)
        }
        SKILL_THIRST => {
            let mult = survival_multiplier(rank);
            let pct = ((1.0 - mult) * 100.0).round() as i32;
            format!("-{pct}% drain ({:.2}x)", mult)
        }
        SKILL_ATTACK_DAMAGE => {
            let mult = attack_damage_multiplier(rank);
            let pct = ((mult - 1.0) * 100.0).round() as i32;
            format!("+{pct}% damage ({:.2}x)", mult)
        }
        SKILL_ARMOR => {
            let red = armor_reduction(rank);
            let pct = (red * 100.0).round() as i32;
            format!("-{pct}% damage taken")
        }
        _ => String::new(),
    }
}
