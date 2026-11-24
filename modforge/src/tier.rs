//! A place's tier (topside-town "Tiers"): how hard its people are and
//! how good its loot is. Each type of place has its usual tier, and the
//! roll can move it: "an airfield is always tier 3, but it doesn't have
//! to be only tier 3". The number of tiers is the map's. Prior art: 7
//! Days to Die's buildings are tier 1 to 5, enemies and loot scaling
//! together.

use crate::roll::Roll;

/// The tier a place of `usual` tier rolls, from 1 to `tiers`: most often
/// its usual tier, one either side half as often, two above now and then.
/// The odds are Claude's.
pub fn roll(usual: u32, tiers: u32, seed: u64) -> u32 {
    let mut roll = Roll::new(seed);
    let usual = usual.clamp(1, tiers.max(1)) as i64;
    let moved = match roll.between(0, 9) {
        0 | 1 => usual - 1,
        2 | 3 => usual + 1,
        4 => usual + 2,
        _ => usual,
    };
    moved.clamp(1, i64::from(tiers.max(1))) as u32
}

/// The danger a tier rolls its loot and people at: tier 1 is danger 0.
pub fn danger_of(tier: u32) -> u32 {
    tier.saturating_sub(1)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_tier_stays_near_its_usual_and_inside_the_map() {
        let tiers: Vec<u32> = (0..200).map(|s| roll(3, 6, s)).collect();
        assert!(tiers.iter().all(|&t| (2..=5).contains(&t)));
        assert!(tiers.contains(&3) && tiers.contains(&2) && tiers.contains(&4));
        assert!((0..200).all(|s| roll(6, 6, s) <= 6 && roll(1, 6, s) >= 1));
    }
}
