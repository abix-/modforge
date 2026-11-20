//! Weather (topside todo 21; authority.md "Weather": per-biome weather
//! events driven by the storyteller, distinct from the big storm). Each
//! game hour each biome's weather is rolled from its table by Randy
//! Random's rule: by chance alone, never by how anyone is doing, seeded
//! by the world, the hour and the biome, so every tick is a pure result.
//! The weather changes the air (modforge exposure), adds radiation, and
//! closes in how far one sees. Every number is Claude's, for the
//! operator to change.

use serde::{Deserialize, Serialize};

#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash, Serialize, Deserialize)]
pub enum Weather {
    Clear,
    Rain,
    Fog,
    HeatWave,
    ColdSnap,
    RadiationStorm,
}

impl Weather {
    pub fn name(self) -> &'static str {
        match self {
            Weather::Clear => "Clear",
            Weather::Rain => "Rain",
            Weather::Fog => "Fog",
            Weather::HeatWave => "Heat wave",
            Weather::ColdSnap => "Cold snap",
            Weather::RadiationStorm => "Radiation storm",
        }
    }

    /// What it adds to the air, degrees C.
    pub fn air(self) -> f32 {
        match self {
            Weather::Clear | Weather::RadiationStorm => 0.0,
            Weather::Rain => -5.0,
            Weather::Fog => -2.0,
            Weather::HeatWave => 25.0,
            Weather::ColdSnap => -25.0,
        }
    }

    /// The radiation it gives in the open, a game second.
    pub fn radiation(self) -> f32 {
        if self == Weather::RadiationStorm { 0.8 } else { 0.0 }
    }

    /// How far one sees in it, metres (None: as far as the world lets).
    pub fn sight(self) -> Option<f32> {
        match self {
            Weather::Fog => Some(25.0),
            Weather::Rain => Some(80.0),
            Weather::RadiationStorm => Some(60.0),
            _ => None,
        }
    }
}

/// The weather for one game hour in one biome, from its table (each
/// weather with its weight). An empty table is always clear.
pub fn roll(table: &[(Weather, u32)], seed: u64, hour: u64, biome: &str) -> Weather {
    let total: u32 = table.iter().map(|(_, w)| *w).sum();
    if total == 0 {
        return Weather::Clear;
    }
    let mut h = seed ^ hour.wrapping_mul(0x9e37_79b9_7f4a_7c15);
    for b in biome.bytes() {
        h = (h ^ b as u64).wrapping_mul(0x100_0000_01b3);
    }
    h ^= h >> 31;
    h = h.wrapping_mul(0xbf58_476d_1ce4_e5b9);
    h ^= h >> 29;
    let mut pick = (h % total as u64) as u32;
    for (weather, weight) in table {
        if pick < *weight {
            return *weather;
        }
        pick -= weight;
    }
    Weather::Clear
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn the_same_hour_rolls_the_same_and_the_table_is_followed() {
        let table = [(Weather::Clear, 1), (Weather::Fog, 1)];
        assert_eq!(roll(&table, 7, 3, "forest"), roll(&table, 7, 3, "forest"));
        let seen: std::collections::HashSet<Weather> = (0..50).map(|h| roll(&table, 7, h, "forest")).collect();
        assert_eq!(seen.len(), 2, "both weathers come in 50 hours");
        assert_eq!(roll(&[], 7, 3, "forest"), Weather::Clear);
    }
}
