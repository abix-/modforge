//! Set bonuses by the game's rules (set_bonuses.gd; folded in
//! combatant_runtime.gd from_player from the worn pieces, wherever they
//! sit). A tag worn on 4, 6 or 8 pieces gives tier 1, 2 or 3; any worn
//! piece's set_count_bonus adds to every counted tag; the strength is
//! the tier times the summed set_bonus_mult, at most 3.

use crate::placement::{Fold, Place, add};

/// set_bonuses.gd DESCRIPTIONS keys.
pub const TAGS: &[&str] = &[
    "neutral",
    "fire",
    "frost",
    "lightning",
    "poison",
    "holy",
    "vampiric",
    "arcane",
    "earth",
    "wind",
    "dragon",
    "demon",
    "undead",
    "beast",
    "metal",
    "haunted",
];
pub const TIERS: &[i64] = &[4, 6, 8];
pub const MAX_STRENGTH: f64 = 3.0;
const SET_STATUS_CHANCE: f64 = 0.1;
const HAUNTED_TERROR_CHANCE: f64 = 0.06;
const HAUNTED_VS_TERRIFIED: f64 = 0.03;
const HOLY_SMITE_SHARE: f64 = 0.25;

/// set_bonuses.gd tier_for.
pub fn tier_for(count: i64) -> i64 {
    TIERS.iter().filter(|&&t| count >= t).count() as i64
}

/// set_bonuses.gd strength: the runtime's set_bonus_mult starts at 1
/// and each worn piece adds its own.
pub fn strength(tier: i64, mult: f64) -> f64 {
    (mult.max(0.0) * tier as f64).min(MAX_STRENGTH)
}

/// set_bonuses.gd active_tiers with strength: each set tag worn, and
/// how strong it is.
pub fn active(worn: &[&Place]) -> Vec<(&'static str, f64)> {
    let mult = 1.0 + worn.iter().map(|p| p.set_bonus_mult).sum::<f64>();
    let mut bonuses: Vec<i64> = worn
        .iter()
        .map(|p| p.set_count_bonus)
        .filter(|&b| b > 0)
        .collect();
    bonuses.sort();
    bonuses.dedup();
    let extra: i64 = bonuses.iter().sum();
    TAGS.iter()
        .filter_map(|&tag| {
            let n = worn
                .iter()
                .filter(|p| p.traits.tags.iter().any(|t| t == tag))
                .count() as i64;
            if n == 0 {
                return None;
            }
            let tier = tier_for(n + extra);
            (tier > 0).then(|| (tag, strength(tier, mult)))
        })
        .collect()
}

/// set_bonuses.gd apply onto the hero's fields at strength `m`, block
/// rolls on (campaign, as the judge fights). Int fields add the
/// game's int() of each share.
pub fn apply(fold: &mut Fold, tag: &str, m: f64) {
    let m = m.max(0.0);
    let get = |f: &Fold, k: &str| f.get(k).and_then(serde_json::Value::as_f64).unwrap_or(0.0);
    let (atk, hp, armor, speed) = (
        get(fold, "base_atk"),
        get(fold, "base_max_hp"),
        get(fold, "base_armor"),
        get(fold, "speed"),
    );
    let whole = |flat: f64, share: f64| (flat * m).round() + (share * m).trunc();
    match tag {
        "neutral" => {
            add(fold, "atk", whole(1.0, atk * 0.03));
            add(fold, "max_hp", whole(10.0, hp * 0.03));
            add(fold, "armor", whole(1.0, armor * 0.03));
        }
        "fire" => add(fold, "burn_on_hit_chance", SET_STATUS_CHANCE * m),
        "frost" => add(fold, "freeze_on_hit_chance", SET_STATUS_CHANCE * m),
        "poison" => add(fold, "poison_on_hit_chance", SET_STATUS_CHANCE * m),
        "lightning" => add(fold, "multistrike_chance", 0.08 * m),
        "holy" => {
            add(fold, "smite_on_heal", HOLY_SMITE_SHARE * m);
            add(fold, "luck", 0.04 * m);
        }
        "vampiric" => {
            add(fold, "atk", whole(2.0, atk * 0.05));
            add(fold, "lifesteal", 0.1 * m);
        }
        "arcane" => {
            add(fold, "atk", (atk * 0.08 * m).trunc());
            add(fold, "crit_chance", 0.05 * m);
            add(fold, "dodge_chance", 0.03 * m);
        }
        "earth" => {
            add(fold, "armor", whole(3.0, armor * 0.15));
            add(fold, "max_hp", (hp * 0.12 * m).trunc());
            add(fold, "regen_heal_bonus", m);
        }
        "wind" => add_speed(fold, whole(2.0, speed * 0.04)),
        "dragon" => {
            add(fold, "atk", (atk * 0.12 * m).trunc());
            add(fold, "crit_chance", 0.05 * m);
        }
        "demon" => {
            add(fold, "atk", whole(3.0, atk * 0.06));
            add(fold, "crit_chance", 0.05 * m);
        }
        "undead" => add(fold, "thorns_damage", whole(4.0, hp * 0.04)),
        "beast" => {
            add(fold, "crit_chance", 0.05 * m);
            add_speed(fold, whole(1.0, speed * 0.02));
        }
        "haunted" => {
            add(fold, "atk", whole(2.0, atk * 0.04));
            add(fold, "terror_on_hit_chance", HAUNTED_TERROR_CHANCE * m);
            add(fold, "bonus_vs_terrified", HAUNTED_VS_TERRIFIED * m);
        }
        "metal" => {
            add(fold, "block_chance", 0.08 * m);
            add(fold, "armor", whole(3.0, armor * 0.1));
        }
        _ => {}
    }
}

/// speed is a float field: added as is.
fn add_speed(fold: &mut Fold, amount: f64) {
    let was = fold
        .get("speed")
        .and_then(serde_json::Value::as_f64)
        .unwrap_or(0.0);
    fold.insert("speed".into(), serde_json::Value::from(was + amount));
}

/// What each set is worth at each strength step, for the packer:
/// (tag, worth at strength 0, STEP, 2 STEP, ... 3), read between steps.
#[derive(Debug, Clone, Default)]
pub struct Table {
    pub rows: Vec<(String, Vec<f64>)>,
}

pub const STEP: f64 = 0.25;

impl Table {
    pub fn worth(&self, tag: &str, s: f64) -> f64 {
        let Some((_, row)) = self.rows.iter().find(|(t, _)| t == tag) else {
            return 0.0;
        };
        let at = (s / STEP).clamp(0.0, (row.len() - 1) as f64);
        let lo = at.floor() as usize;
        let hi = (lo + 1).min(row.len() - 1);
        row[lo] + (row[hi] - row[lo]) * (at - lo as f64)
    }

    /// What the worn pieces' sets are worth.
    pub fn of(&self, worn: &[&Place]) -> f64 {
        if self.rows.is_empty() {
            return 0.0;
        }
        active(worn).iter().map(|(t, s)| self.worth(t, *s)).sum()
    }

    /// The most any set could add with these pieces, for the bound.
    pub fn most(&self, pieces: &[&Place]) -> f64 {
        self.rows
            .iter()
            .filter(|(t, _)| reachable(pieces, t))
            .map(|(_, row)| row.iter().cloned().fold(0.0, f64::max))
            .sum()
    }
}

/// Could `tag` reach tier 1 with all of `pieces` worn.
pub fn reachable(pieces: &[&Place], tag: &str) -> bool {
    let n = pieces
        .iter()
        .filter(|p| p.traits.tags.iter().any(|t| t == tag))
        .count() as i64;
    let mut bonuses: Vec<i64> = pieces
        .iter()
        .map(|p| p.set_count_bonus)
        .filter(|&b| b > 0)
        .collect();
    bonuses.sort();
    bonuses.dedup();
    n > 0 && n + bonuses.iter().sum::<i64>() >= TIERS[0]
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::placement::Traits;

    fn tagged(tag: &str) -> Place {
        Place {
            traits: Traits {
                tags: vec![tag.into()],
                ..Traits::default()
            },
            ..Place::default()
        }
    }

    #[test]
    fn four_make_tier_one_and_bonus_counts() {
        let f = tagged("fire");
        let three = [&f, &f, &f];
        assert!(active(&three).is_empty());
        let four = [&f, &f, &f, &f];
        assert_eq!(active(&four), vec![("fire", 1.0)]);
        let mut b = tagged("x");
        b.set_count_bonus = 1;
        let with = [&f, &f, &f, &b];
        assert_eq!(active(&with), vec![("fire", 1.0)]);
    }

    #[test]
    fn mult_raises_strength_to_three_at_most() {
        let f = tagged("metal");
        let mut m = tagged("metal");
        m.set_bonus_mult = 5.0;
        let worn = [&f, &f, &f, &m];
        assert_eq!(active(&worn), vec![("metal", 3.0)]);
    }
}
