//! Sickness (topside todo Events 5, "sickness spreading"; RimWorld's
//! plague and Project Zomboid's knox infection, without the death
//! sentence): a sick person is hurt a little each second until it passes,
//! and gives it to whoever stays near them. Engine-free; the game holds
//! who is sick and hurts them through its own hit path.

use serde::{Deserialize, Serialize};

/// How sickness goes, for one game.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct SicknessDef {
    /// Seconds it lasts before it passes.
    pub lasts: f32,
    /// How near, metres, someone must be to catch it.
    pub reach: f32,
    /// The chance a second, 0 to 1, that someone in reach catches it.
    pub catch_chance: f32,
}

/// One person's sickness: how long they have had it.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Sickness {
    pub had: f32,
}

impl Sickness {
    /// `dt` seconds more of it; true when it has passed.
    pub fn tick(&mut self, def: &SicknessDef, dt: f32) -> bool {
        self.had += dt;
        self.had >= def.lasts
    }
}

/// Whether someone `distance` from a sick person catches it over `dt`
/// seconds, `roll` a share from 0 to 1 the game rolls.
pub fn catches(def: &SicknessDef, distance: f32, dt: f32, roll: f32) -> bool {
    distance <= def.reach && roll < def.catch_chance * dt
}

#[cfg(test)]
mod tests {
    use super::*;

    const DEF: SicknessDef = SicknessDef { lasts: 10.0, reach: 2.0, catch_chance: 0.5 };

    #[test]
    fn it_passes_after_it_lasts() {
        let mut sick = Sickness::default();
        assert!(!sick.tick(&DEF, 9.0));
        assert!(sick.tick(&DEF, 1.0));
    }

    #[test]
    fn only_the_near_catch_it() {
        assert!(catches(&DEF, 1.0, 1.0, 0.1));
        assert!(!catches(&DEF, 3.0, 1.0, 0.1));
        assert!(!catches(&DEF, 1.0, 1.0, 0.9));
    }
}
