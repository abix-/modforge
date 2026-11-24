//! A place's tier (topside-town "Tiers"): how hard its people are and
//! how good its loot is. Each type of place has its usual tier, and the
//! roll can move it: "an airfield is always tier 3, but it doesn't have
//! to be only tier 3". The number of tiers is the map's. Prior art: 7
//! Days to Die's buildings are tier 1 to 5, enemies and loot scaling
//! together.

use crate::monument::Roll;

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

/// A modifier on a place, Diablo's prefixes on buildings (topside-town
/// "Tiers": "a rare or an extra loot or a whatever type building or
/// extra hard monsters"), rolled per building and per area.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Modifier {
    /// Its loot rolls two dangers higher.
    Rare,
    /// Twice the boxes.
    ExtraLoot,
    /// One more person, and its people two dangers harder.
    ExtraHard,
}

impl Modifier {
    /// The word put before the place's name, as Diablo names a rare.
    pub fn word(self) -> &'static str {
        match self {
            Modifier::Rare => "rare",
            Modifier::ExtraLoot => "well stocked",
            Modifier::ExtraHard => "guarded",
        }
    }
}

/// The modifier one roll gives, if any: one in `one_in` rolls has one,
/// each kind as likely. The odds are the caller's.
pub fn modifier(seed: u64, one_in: u64) -> Option<Modifier> {
    let mut roll = Roll::new(seed);
    if roll.next(one_in.max(1)) != 0 {
        return None;
    }
    Some([Modifier::Rare, Modifier::ExtraLoot, Modifier::ExtraHard][roll.next(3) as usize])
}

/// What a place's modifiers make of its tier: (boxes, loot danger,
/// people, people's danger).
pub fn with_modifiers(tier: u32, modifiers: &[Modifier]) -> (u32, u32, u32, u32) {
    let danger = danger_of(tier);
    let (mut boxes, mut loot, mut people, mut hard) = (tier, danger, tier.saturating_sub(2), danger);
    for m in modifiers {
        match m {
            Modifier::Rare => loot += 2,
            Modifier::ExtraLoot => boxes *= 2,
            Modifier::ExtraHard => {
                people += 1;
                hard += 2;
            }
        }
    }
    (boxes, loot, people, hard)
}

/// Moves a rolled monument's loot, people and gates to the tier it rolls
/// from its type's usual tier (`usual_danger` + 1), keeping each spot's
/// own step above the type (a gated back room stays one above).
pub fn set_tier(monument: &mut crate::structure::MonumentDef, usual_danger: u32, tiers: u32, seed: u64) -> u32 {
    let tier = roll(usual_danger + 1, tiers, seed);
    let shift = i64::from(danger_of(tier)) - i64::from(usual_danger);
    let moved = |d: u32| (i64::from(d) + shift).max(0) as u32;
    for s in &mut monument.loot_spots {
        s.danger = moved(s.danger);
    }
    for s in &mut monument.npc_spots {
        s.danger = moved(s.danger);
    }
    for g in &mut monument.gates {
        g.level = moved(g.level);
    }
    tier
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn modifiers_change_what_is_inside() {
        assert_eq!(with_modifiers(1, &[]), (1, 0, 0, 0));
        assert_eq!(with_modifiers(3, &[Modifier::Rare, Modifier::ExtraHard]), (3, 4, 2, 4));
        assert_eq!(with_modifiers(2, &[Modifier::ExtraLoot]).0, 4);
        let some = (0..300).filter(|&s| modifier(s, 6).is_some()).count();
        assert!(some > 20 && some < 100);
    }

    #[test]
    fn a_tier_stays_near_its_usual_and_inside_the_map() {
        let tiers: Vec<u32> = (0..200).map(|s| roll(3, 6, s)).collect();
        assert!(tiers.iter().all(|&t| (2..=5).contains(&t)));
        assert!(tiers.contains(&3) && tiers.contains(&2) && tiers.contains(&4));
        assert!((0..200).all(|s| roll(6, 6, s) <= 6 && roll(1, 6, s) >= 1));
    }
}
