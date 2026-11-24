//! Power (topside todo 29; authority.md "PowerGrid": generators burn
//! fuel, wiring connects consumers, no fuel means no power, a real
//! simulation, not a toggle). A grid is the generators and consumers
//! wired together. A generator with fuel gives its output and burns its
//! fuel over time; the grid's supply goes to its consumers in their
//! order, each powered only if the whole of its draw is left (Rust's
//! electricity: a consumer short of its draw does not run). Engine-free.

use serde::{Deserialize, Serialize};

/// One generator: what it gives running, and how long one fuel lasts it.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct GeneratorDef {
    pub output: f32,
    /// Seconds one unit of fuel runs it.
    pub burn_secs: f32,
}

/// One generator's running state: how far into its current fuel it is.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Burning {
    pub into: f32,
}

impl Burning {
    /// Run `dt` seconds with `fuel` units in it: how many units are used
    /// up, and whether it gave power. No fuel, no power.
    pub fn run(&mut self, def: &GeneratorDef, fuel: u32, dt: f32) -> (u32, bool) {
        if fuel == 0 {
            self.into = 0.0;
            return (0, false);
        }
        self.into += dt;
        let mut used = 0;
        while self.into >= def.burn_secs && used < fuel {
            self.into -= def.burn_secs;
            used += 1;
        }
        (used, true)
    }
}

/// Whether a light is lit (topside-town "Everything works"; Project
/// Zomboid's house power): its switch on, its house's breaker on, and the
/// breaker on a grid with power (the town's lines from the substation, or
/// a generator wired to it).
pub fn lit(grid: bool, breaker_on: bool, switch_on: bool) -> bool {
    grid && breaker_on && switch_on
}

/// Which consumers are powered: the supply given out in order, each
/// powered only if its whole draw is left.
pub fn share(supply: f32, draws: &[f32]) -> Vec<bool> {
    let mut left = supply;
    draws
        .iter()
        .map(|draw| {
            if *draw <= left {
                left -= draw;
                true
            } else {
                false
            }
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn fuel_burns_and_no_fuel_is_no_power() {
        let def = GeneratorDef { output: 10.0, burn_secs: 60.0 };
        let mut burning = Burning::default();
        assert_eq!(burning.run(&def, 2, 30.0), (0, true));
        assert_eq!(burning.run(&def, 2, 30.0), (1, true));
        assert_eq!(burning.run(&def, 0, 30.0), (0, false));
        assert_eq!(share(10.0, &[4.0, 8.0, 5.0]), vec![true, false, true]);
        assert_eq!(share(0.0, &[1.0]), vec![false]);
    }
}
