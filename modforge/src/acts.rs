//! The act repertoire and the franchise vote that picks one (lifted from
//! survivalist-mod's rob, steal, scavenge and trade, docs/faction-war.md
//! "Multidimensional factions"; topside todo 11j). A faction's genome is
//! four traits, aggression, expansionism, defensiveness and guile, each
//! 0 to 1; each member votes with the faction's genome leaned by their
//! own personality; each act scores a blend of the traits, a voter is for
//! it at `FLOOR` or over (survivalist's ROB_FLOOR), and the act carried
//! by a strict majority with the highest mean is the one done
//! (`genome::Ballot`). Engine-free: the consumer names the voters and
//! carries the act out. The blends and the lean are Claude's, for the
//! operator to change.

use serde::{Deserialize, Serialize};

use crate::actor::{Axis, Personality};
use crate::genome::Ballot;

/// A voter is for an act scoring this or more.
pub const FLOOR: f64 = 0.55;
/// How far a member's own personality leans the faction's genome.
pub const LEAN: f32 = 0.2;

/// One thing a faction does to another or to the player.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash, Serialize, Deserialize)]
pub enum Act {
    Raid,
    Scavenge,
    Trade,
    Steal,
}

impl Act {
    pub const ALL: [Act; 4] = [Act::Raid, Act::Scavenge, Act::Trade, Act::Steal];
}

/// A faction's traits, each 0 to 1.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Genome {
    pub aggression: f32,
    pub expansionism: f32,
    pub defensiveness: f32,
    pub guile: f32,
}

impl Genome {
    /// A faction's genome rolled from its name, the same every time.
    pub fn of(faction: &str) -> Genome {
        let mut h: u64 = 0xcbf2_9ce4_8422_2325;
        for b in faction.bytes() {
            h = (h ^ b as u64).wrapping_mul(0x100_0000_01b3);
        }
        let mut next = || {
            h ^= h >> 33;
            h = h.wrapping_mul(0xff51_afd7_ed55_8ccd);
            h ^= h >> 33;
            (h % 1000) as f32 / 999.0
        };
        Genome { aggression: next(), expansionism: next(), defensiveness: next(), guile: next() }
    }

    /// The faction's genome as one member votes it: brave and fierce
    /// lean aggression, the fearful defensiveness.
    pub fn leaned(self, p: &Personality) -> Genome {
        let axis = |a: Axis| p.axes[a as usize];
        let c = |v: f32| v.clamp(0.0, 1.0);
        Genome {
            aggression: c(self.aggression + LEAN * (axis(Axis::Courage) + axis(Axis::Ferocity)) / 2.0),
            expansionism: c(self.expansionism + LEAN * axis(Axis::Diligence)),
            defensiveness: c(self.defensiveness + LEAN * axis(Axis::Fear)),
            guile: c(self.guile + LEAN * axis(Axis::Precision)),
        }
    }

    /// How much a voter of this genome wants an act, 0 to 1.
    pub fn score(self, act: Act) -> f64 {
        let s = match act {
            Act::Raid => (self.aggression + self.expansionism) / 2.0,
            Act::Steal => (self.guile + self.aggression) / 2.0,
            Act::Scavenge => (self.defensiveness + self.expansionism) / 2.0,
            Act::Trade => (1.0 - self.aggression + self.guile) / 2.0,
        };
        s as f64
    }
}

/// Every voter votes on every act; the act carried by a majority with
/// the highest mean, and its ballot (for reinforcement and for who goes:
/// the voters for it).
pub fn vote(faction: &str, voters: &[(i64, Personality)]) -> Option<(Act, Ballot)> {
    let genome = Genome::of(faction);
    Act::ALL
        .into_iter()
        .map(|act| {
            let mut ballot = Ballot::new(FLOOR);
            for (id, p) in voters {
                ballot.cast(*id, genome.leaned(p).score(act));
            }
            (act, ballot)
        })
        .filter(|(_, b)| b.has_majority())
        .max_by(|a, b| a.1.mean_score().total_cmp(&b.1.mean_score()))
}

/// Who of the voters is for an act: those it scores `FLOOR` or more for.
pub fn for_it(faction: &str, act: Act, voters: &[(i64, Personality)]) -> Vec<i64> {
    let genome = Genome::of(faction);
    voters.iter().filter(|(_, p)| genome.leaned(p).score(act) >= FLOOR).map(|(id, _)| *id).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn fierce_voters_carry_a_raid() {
        let mut fierce = Personality::default();
        fierce.axes[Axis::Courage as usize] = 1.0;
        fierce.axes[Axis::Ferocity as usize] = 1.0;
        fierce.axes[Axis::Diligence as usize] = 1.0;
        // A faction whose genome leans fierce enough: try names until one
        // votes raid, as the rolls are fixed by the name.
        let voters: Vec<(i64, Personality)> = (0..5).map(|i| (i, fierce)).collect();
        let raiding = (0..200).map(|i| format!("band {i}")).find(|f| vote(f, &voters).is_some_and(|(a, _)| a == Act::Raid));
        let faction = raiding.expect("some faction of fierce members votes to raid");
        assert_eq!(for_it(&faction, Act::Raid, &voters).len(), 5);
        assert_eq!(Genome::of(&faction), Genome::of(&faction), "the same name, the same genome");
    }
}
