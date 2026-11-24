//! Temperature and radiation (topside todo 20; authority.md "Survival":
//! "hunger, thirst, temperature, radiation. Always active ... Atlas is
//! the reference for how pressures stack"). Beside hunger and thirst:
//! a body's warmth drifts toward the air around it, faster the farther
//! off it is, and out of the safe band it hurts; radiation taken in adds
//! to a dose that clears slowly, and over a line it hurts. The consumer
//! says the air's temperature and the radiation where the person stands;
//! shelter is the consumer's (indoors is warmer and shielded). Every
//! number is Claude's, for the operator to change.

use serde::{Deserialize, Serialize};

/// A body's own warmth, degrees C.
pub const BODY: f32 = 37.0;
/// Under this a body is cold and hurts; over `HOT` it is hot and hurts.
pub const COLD: f32 = 35.0;
pub const HOT: f32 = 39.0;
/// How fast warmth drifts toward the air: this share of the gap a game
/// second, as clothes and a body's heat slow it.
pub const DRIFT: f32 = 0.0005;
/// What a body warms itself toward when the air is mild: its own warmth
/// holds between these airs.
pub const MILD: (f32, f32) = (10.0, 30.0);
/// The warmth heat sources add to the air where a person stands
/// (topside-town "Everything works": "furnaces, fireplaces, wood stoves,
/// AC"; Valheim's and Atlas's fires warm whoever is near them): each
/// source as (how far off, its heat, its reach), its heat falling to
/// nothing at its reach, summed. A negative heat cools (AC).
pub fn warmth_near(sources: &[(f32, f32, f32)]) -> f32 {
    sources.iter().map(|&(far, heat, reach)| if far < reach { heat * (1.0 - far / reach) } else { 0.0 }).sum()
}

/// Over this dose radiation hurts; a dose clears this much a game second.
pub const SICK: f32 = 50.0;
pub const CLEARS: f32 = 0.01;
/// The most dose a body holds.
pub const DOSE_MOST: f32 = 200.0;

/// One person's exposure.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Exposure {
    /// Body warmth, degrees C.
    pub warmth: f32,
    /// Radiation dose taken in.
    pub dose: f32,
}

impl Default for Exposure {
    fn default() -> Self {
        Exposure { warmth: BODY, dose: 0.0 }
    }
}

/// What hurts a person this second.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Harm {
    Cold,
    Heat,
    Radiation,
}

impl Exposure {
    /// `dt` game seconds in air at `air` degrees and `radiation` a second.
    pub fn tick(&mut self, air: f32, radiation: f32, dt: f32) {
        // In mild air a body holds its own warmth.
        let toward = if air >= MILD.0 && air <= MILD.1 { BODY } else if air < MILD.0 { BODY - (MILD.0 - air) * 0.5 } else { BODY + (air - MILD.1) * 0.5 };
        self.warmth += (toward - self.warmth) * (DRIFT * dt).min(1.0);
        self.dose = (self.dose + radiation * dt - CLEARS * dt).clamp(0.0, DOSE_MOST);
    }

    /// Whatever hurts now, cold or heat first.
    pub fn harms(&self) -> Vec<Harm> {
        let mut harms = Vec::new();
        if self.warmth < COLD {
            harms.push(Harm::Cold);
        } else if self.warmth > HOT {
            harms.push(Harm::Heat);
        }
        if self.dose > SICK {
            harms.push(Harm::Radiation);
        }
        harms
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn freezing_air_chills_and_radiation_builds_then_clears() {
        let mut e = Exposure::default();
        for _ in 0..2000 {
            e.tick(-20.0, 0.0, 1.0);
        }
        assert_eq!(e.harms(), vec![Harm::Cold]);
        let mut e = Exposure::default();
        for _ in 0..100 {
            e.tick(20.0, 1.0, 1.0);
        }
        assert_eq!(e.harms(), vec![Harm::Radiation]);
        for _ in 0..10000 {
            e.tick(20.0, 0.0, 1.0);
        }
        assert!(e.harms().is_empty(), "the dose clears and mild air keeps the body warm");
    }
}
