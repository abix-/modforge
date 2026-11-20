//! Engine-agnostic quality tier system: roll a tier from
//! cumulative per-mille odds, pick a statistical sibling.
//!
//! Quality tiers are ranked item variants (Legendary, Epic, Rare,
//! Uncommon above the base Normal). Each tier has several
//! statistical siblings with jittered stats sharing one display
//! name, so two Rare rifles are usually not exactly the same.
//!
//! Games define their tier names, odds tables (per sender), and
//! swap mechanics. This module provides the probability rolls.

use crate::unknown::rng;

/// Roll a tier index from cumulative per-mille odds (best tier
/// first). Returns None for the base/common tier. Each entry in
/// `odds` is the per-mille chance of that tier (1 = 0.1%, 10 = 1%),
/// evaluated cumulatively from the top.
pub fn roll_tier(odds: &[u64], now: f32, salt: u64) -> Option<usize> {
    let r = rng(now, salt, 1000);
    let mut cum = 0u64;
    for (i, &o) in odds.iter().enumerate() {
        cum += o;
        if r < cum {
            return Some(i);
        }
    }
    None
}

/// Pick a sibling number in [1, siblings]. Each tier has several
/// statistical siblings with jittered stats; this picks which one.
pub fn roll_sibling(siblings: u64, now: f32, salt: u64) -> u64 {
    rng(now, salt.wrapping_mul(97), siblings) + 1
}

/// One quality tier of a game's table (best first): its name, its
/// per-mille odds, and how much harder a weapon of it hits (1 is the base
/// tier's).
#[derive(Clone, Debug, PartialEq)]
pub struct Tier {
    pub name: String,
    pub per_mille: u64,
    pub power: f32,
    /// The least danger a spot must have for this tier to be found there
    /// (topside authority.md "LootTable": the danger sets the ceiling of
    /// the tiers; no top tier from a safe place).
    pub min_danger: u32,
}

/// The odds of a table at a spot of `danger`, best tier first, as
/// `roll_tier` takes them: a tier the danger does not reach has none.
pub fn odds(tiers: &[Tier], danger: u32) -> Vec<u64> {
    tiers.iter().map(|t| if t.min_danger <= danger { t.per_mille } else { 0 }).collect()
}

/// How much a stack of `tier` (None the base tier) multiplies its hits:
/// the one place quality changes an item's numbers.
pub fn power(tier: Option<usize>, tiers: &[Tier]) -> f32 {
    tier.and_then(|t| tiers.get(t)).map_or(1.0, |t| t.power)
}

/// The name of `tier`, None for the base tier.
pub fn name(tier: Option<usize>, tiers: &[Tier]) -> Option<&str> {
    tier.and_then(|t| tiers.get(t)).map(|t| t.name.as_str())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn table() -> Vec<Tier> {
        vec![
            Tier { name: "best".into(), per_mille: 100, power: 1.5, min_danger: 3 },
            Tier { name: "good".into(), per_mille: 300, power: 1.2, min_danger: 0 },
        ]
    }

    #[test]
    fn a_safe_spot_never_rolls_the_top_tier() {
        let o = odds(&table(), 1);
        assert_eq!(o, vec![0, 300]);
        assert!((0..2000).all(|s| roll_tier(&o, 0.0, s) != Some(0)));
    }

    #[test]
    fn a_better_tier_hits_harder_and_the_base_tier_as_it_is() {
        let t = table();
        assert_eq!(power(None, &t), 1.0);
        assert_eq!(power(Some(0), &t), 1.5);
        assert_eq!(power(Some(1), &t), 1.2);
        assert_eq!(name(Some(1), &t), Some("good"));
        assert_eq!(name(None, &t), None);
    }

    #[test]
    fn tiers_roll_at_about_their_odds() {
        let o = odds(&table(), 3);
        let rolls: Vec<_> = (0..2000).map(|s| roll_tier(&o, 0.0, s)).collect();
        let best = rolls.iter().filter(|r| **r == Some(0)).count();
        let good = rolls.iter().filter(|r| **r == Some(1)).count();
        let base = rolls.iter().filter(|r| r.is_none()).count();
        assert!((120..280).contains(&best), "best {best}");
        assert!((450..750).contains(&good), "good {good}");
        assert!((1050..1350).contains(&base), "base {base}");
    }
}
