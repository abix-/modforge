//! Vehicles (topside todo 57; authority.md "Actor": "a vehicle is an
//! actor whose queue the driver fills instead of their own body's"). A
//! vehicle's def is its kind of actor plus what makes it a vehicle: how
//! much faster than walking it goes, its tank, the fuel it burns while it
//! moves (fuel in place of hunger: it burns only driven), its seats, and
//! its breakdown risk for each game minute driven, rolled by chance
//! alone from the world seed, the vehicle and the minute (Randy
//! Random's rule). Engine-free.

use serde::{Deserialize, Serialize};

#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct VehicleDef {
    /// Times walking speed.
    pub speed: f32,
    /// Seconds of driving a full tank holds.
    pub tank: f32,
    /// Seconds of driving one can of fuel gives.
    pub per_can: f32,
    pub seats: u32,
    /// The chance in each game minute driven that it breaks down.
    pub breakdown: f32,
}

/// The fuel left after `dt` seconds, burnt only while moving.
pub fn burn(fuel: f32, dt: f32, moving: bool) -> f32 {
    if moving { (fuel - dt).max(0.0) } else { fuel }
}

/// The fuel after one can is put in, never past the tank.
pub fn fill(def: &VehicleDef, fuel: f32) -> f32 {
    (fuel + def.per_can).min(def.tank)
}

/// Whether the vehicle breaks down in this game minute driven.
pub fn breaks(def: &VehicleDef, seed: u64, vehicle: u64, minute: u64) -> bool {
    let mut h = seed ^ vehicle.wrapping_mul(0x9e37_79b9_7f4a_7c15) ^ minute.wrapping_mul(0xbf58_476d_1ce4_e5b9);
    h ^= h >> 31;
    h = h.wrapping_mul(0x94d0_49bb_1331_11eb);
    h ^= h >> 29;
    ((h % 1_000_000) as f32) < def.breakdown * 1_000_000.0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn fuel_burns_only_driven_and_breakdowns_follow_the_risk() {
        let def = VehicleDef { speed: 3.0, tank: 600.0, per_can: 200.0, seats: 2, breakdown: 0.1 };
        assert_eq!(burn(10.0, 1.0, false), 10.0);
        assert_eq!(burn(10.0, 1.0, true), 9.0);
        assert_eq!(burn(0.5, 1.0, true), 0.0);
        assert_eq!(fill(&def, 500.0), 600.0);
        let broke = (0..10_000).filter(|m| breaks(&def, 7, 1, *m)).count();
        assert!((800..1200).contains(&broke), "about one in ten: {broke}");
        assert_eq!(breaks(&def, 7, 1, 3), breaks(&def, 7, 1, 3));
    }
}
