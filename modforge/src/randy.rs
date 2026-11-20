//! Randy Random's encounters (the storyteller's random layer; Fallout 2's
//! random encounters): while the player walks, every so many metres a roll,
//! and a roll that hits picks one encounter from a registered table by its
//! weight. Never adaptive: the roll never looks at how the player is doing.
//! The game says what each encounter is and makes it happen.

use serde::{Deserialize, Serialize};

use crate::roll::salted_index;

/// One thing that can happen while walking, and how often it comes up
/// against the others in the table.
#[derive(Debug, Clone, PartialEq)]
pub struct Encounter {
    pub name: &'static str,
    pub weight: u64,
}

/// The registered table every roll picks from: how far is walked between
/// rolls, the chance in a hundred that a roll hits, and the encounters.
#[derive(Debug, Clone, PartialEq)]
pub struct EncounterTable {
    pub every_metres: f32,
    pub chance_in_100: u64,
    pub encounters: Vec<Encounter>,
}

/// How far the player has walked toward the next roll and how many rolls
/// there have been: saved, so a load rolls the same.
#[derive(Debug, Clone, Default, PartialEq, Serialize, Deserialize)]
pub struct Walking {
    pub metres: f32,
    pub rolls: u64,
}

impl EncounterTable {
    /// The player walked `metres` more: each time a roll is due, it is rolled
    /// from the world's seed and the roll's number; the encounter it hit, if
    /// any (at most one a call).
    pub fn walked(&self, walking: &mut Walking, metres: f32, seed: u64) -> Option<&Encounter> {
        walking.metres += metres.max(0.0);
        let mut hit = None;
        while walking.metres >= self.every_metres.max(f32::EPSILON) {
            walking.metres -= self.every_metres;
            walking.rolls += 1;
            if hit.is_none() {
                hit = self.roll(seed, walking.rolls);
            }
        }
        hit
    }

    /// Roll number `roll`: whether it hits, then which encounter by weight.
    pub fn roll(&self, seed: u64, roll: u64) -> Option<&Encounter> {
        if salted_index(seed ^ roll, 0x5241_4e44, 100) >= self.chance_in_100 {
            return None;
        }
        let total: u64 = self.encounters.iter().map(|e| e.weight).sum();
        let mut left = salted_index(seed ^ roll, 0x5049_434b, total);
        self.encounters.iter().find(|e| {
            if left < e.weight {
                return true;
            }
            left -= e.weight;
            false
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn table(chance: u64) -> EncounterTable {
        EncounterTable {
            every_metres: 50.0,
            chance_in_100: chance,
            encounters: vec![Encounter { name: "a", weight: 1 }, Encounter { name: "b", weight: 3 }],
        }
    }

    #[test]
    fn a_roll_comes_every_so_many_metres_walked() {
        let table = table(100);
        let mut walking = Walking::default();
        assert!(table.walked(&mut walking, 49.0, 7).is_none());
        assert!(table.walked(&mut walking, 1.0, 7).is_some());
        assert_eq!(walking.rolls, 1);
        table.walked(&mut walking, 120.0, 7);
        assert_eq!(walking.rolls, 3);
    }

    #[test]
    fn no_chance_never_hits_and_the_same_seed_rolls_the_same() {
        let mut walking = Walking::default();
        assert!(table(0).walked(&mut walking, 10_000.0, 7).is_none());
        let picks = |seed| (1..200).map(|r| table(50).roll(seed, r).map(|e| e.name)).collect::<Vec<_>>();
        assert_eq!(picks(7), picks(7));
        assert!(picks(7).contains(&Some("a")) && picks(7).contains(&Some("b")) && picks(7).contains(&None));
    }
}
