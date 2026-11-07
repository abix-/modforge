//! Unit against unit numbers that name no game: a unit's damage per
//! second, and a group's totals.
//!
//! A game crate reads its units into [`UnitStats`] (Mechabellum:
//! mechabellum-mod `src/units.rs`) and every comparison it shows the
//! player (the starting lineup, matchups, deployment) goes through
//! here, so they all count the same way.
//!
//! First pass, operator 2026-11-07: "simulated fights between two
//! units ... as we play we can use the data to refine our math".
//! Damage per second is damage per hit over seconds between attacks;
//! weapon count, splash, armor and crowd control are carried but not
//! yet counted (not yet proven how the game uses them).

use serde::Serialize;

/// One kind of unit, as many of it as the player has.
#[derive(Clone, Debug, Default, Serialize)]
pub struct UnitStats {
    pub id: i64,
    pub name: String,
    /// How many of this unit.
    pub count: u32,
    pub life: f64,
    /// Damage per hit.
    pub damage: f64,
    /// Seconds between attacks.
    pub attack_interval: f64,
    pub range: f64,
    pub splash: f64,
    pub weapons: u32,
    pub hits_air: bool,
    pub hits_ground: bool,
    pub flies: bool,
}

impl UnitStats {
    /// Damage per second of one unit.
    pub fn dps(&self) -> f64 {
        if self.attack_interval > 0.0 { self.damage / self.attack_interval } else { 0.0 }
    }
}

/// A group's totals: all its units together.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Totals {
    pub units: u32,
    pub life: f64,
    pub dps: f64,
    pub hits_air: bool,
}

pub fn totals(group: &[UnitStats]) -> Totals {
    let mut t = Totals::default();
    for u in group {
        let n = f64::from(u.count);
        t.units += u.count;
        t.life += u.life * n;
        t.dps += u.dps() * n;
        t.hits_air |= u.hits_air;
    }
    t
}

#[cfg(test)]
mod tests {
    use super::*;

    fn unit(count: u32, life: f64, damage: f64, interval: f64, air: bool) -> UnitStats {
        UnitStats { count, life, damage, attack_interval: interval, hits_air: air, ..Default::default() }
    }

    #[test]
    fn dps_is_damage_over_interval() {
        assert_eq!(unit(1, 1.0, 7858.0, 3.4, false).dps(), 7858.0 / 3.4);
        assert_eq!(unit(1, 1.0, 10.0, 0.0, false).dps(), 0.0);
    }

    #[test]
    fn totals_count_every_unit() {
        // Sabertooth x1 and two purchases of 12 Fangs (Mechabellum
        // Star Expedition rows, 2026-11-07).
        let t = totals(&[unit(1, 15541.0, 7858.0, 3.4, false), unit(24, 158.0, 104.0, 1.5, true)]);
        assert_eq!(t.units, 25);
        assert_eq!(t.life, 15541.0 + 24.0 * 158.0);
        assert!((t.dps - (7858.0 / 3.4 + 24.0 * 104.0 / 1.5)).abs() < 1e-9);
        assert!(t.hits_air);
    }
}
