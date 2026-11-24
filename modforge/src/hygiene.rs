//! How clean a person is (topside-town "Everything works": "showers,
//! baths, sinks, toilets and soap keep a person clean"; The Sims'
//! hygiene and Project Zomboid's dirtiness). Dirt builds over time and
//! faster working or fighting; washing takes it off, a shower or a bath
//! all of it, a sink some, soap doubling what a wash takes. Every number
//! is Claude's, for the operator to change; what dirt does to a person
//! is the operator's to decide.

use serde::{Deserialize, Serialize};

/// Fully filthy.
pub const FILTHY: f32 = 100.0;
/// Dirt gained a game day, living.
pub const DIRT_A_DAY: f32 = 50.0;

/// One person's dirt, 0 clean to `FILTHY`.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Hygiene {
    pub dirt: f32,
}

/// What a wash is had at.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Wash {
    /// A shower or a bath: all of it.
    Whole,
    /// A sink: hands and face.
    Hands,
}

impl Hygiene {
    /// Dirt builds over `days` of living.
    pub fn live(&mut self, days: f32) {
        self.dirt = (self.dirt + DIRT_A_DAY * days).min(FILTHY);
    }

    /// A wash, with soap or without.
    pub fn wash(&mut self, wash: Wash, soap: bool) {
        let takes = match wash {
            Wash::Whole => FILTHY,
            Wash::Hands => 20.0,
        } * if soap { 2.0 } else { 1.0 };
        self.dirt = (self.dirt - takes).max(0.0);
    }

    pub fn filthy(&self) -> bool {
        self.dirt >= FILTHY
    }
}

/// Clothes worn by someone filthy get dirty, and are washed then dried
/// clean (topside-town "Everything works": "the washer and dryer clean
/// them"; Project Zomboid's washer and dryer): their names, a dirty one
/// `dirty <name>`, a washed one `wet <name>`.
pub fn soiled(name: &str) -> Option<String> {
    (!name.starts_with("dirty ") && !name.starts_with("wet ")).then(|| format!("dirty {name}"))
}

/// What a washer (`dry` false) or a dryer (`dry` true) makes of clothes
/// put in it, if anything.
pub fn launder(name: &str, dry: bool) -> Option<String> {
    if dry {
        name.strip_prefix("wet ").map(str::to_string)
    } else {
        name.strip_prefix("dirty ").map(|n| format!("wet {n}"))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn dirt_builds_and_a_shower_takes_it_all() {
        let mut h = Hygiene::default();
        h.live(2.0);
        assert!(h.filthy());
        h.wash(Wash::Hands, true);
        assert_eq!(h.dirt, 60.0);
        h.wash(Wash::Whole, false);
        assert_eq!(h.dirt, 0.0);
    }

    #[test]
    fn dirty_clothes_are_washed_then_dried() {
        let dirty = soiled("shirt").unwrap();
        assert_eq!(soiled(&dirty), None);
        assert_eq!(launder(&dirty, true), None);
        let wet = launder(&dirty, false).unwrap();
        assert_eq!(launder(&wet, true).as_deref(), Some("shirt"));
    }
}
