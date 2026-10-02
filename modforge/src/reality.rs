//! Realities as data (topside docs/realities.md): the storm shifts
//! everyone into a different reality, and a reality is its own thing,
//! with its own danger and the rules that work differently in it. The
//! consumer registers its realities and asks which one each storm hands
//! over. Engine-free, plain data.

use crate::roll::salted_index;

/// How dangerous a reality is (realities.md "Danger").
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Danger {
    /// A reality to breathe in.
    Calm,
    /// Fights won with care.
    Hard,
    /// Giant bosses guard the best loot; sometimes the only answer is
    /// to run.
    Deadly,
}

impl Danger {
    pub fn name(self) -> &'static str {
        match self {
            Self::Calm => "calm",
            Self::Hard => "hard",
            Self::Deadly => "deadly",
        }
    }
}

/// One reality: its name, its danger, and the rules it changes.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct RealityDef {
    pub name: String,
    pub danger: Danger,
    /// Whether the day has a night.
    pub night: bool,
    /// Whether a death is final for someone with no home to wake in.
    pub death_sticks: bool,
}

/// Every reality the storm can hand over, in the order registered.
#[derive(Default)]
pub struct RealityRegistry {
    defs: Vec<RealityDef>,
}

impl RealityRegistry {
    pub fn register(&mut self, def: RealityDef) -> Result<(), String> {
        if self.defs.iter().any(|d| d.name == def.name) {
            return Err(format!("reality '{}' registered twice", def.name));
        }
        self.defs.push(def);
        Ok(())
    }

    pub fn def(&self, name: &str) -> Option<&RealityDef> {
        self.defs.iter().find(|d| d.name == name)
    }

    pub fn len(&self) -> usize {
        self.defs.len()
    }

    pub fn is_empty(&self) -> bool {
        self.defs.is_empty()
    }

    /// The reality after `storms` storms, from the world's first seed:
    /// the first registered before any storm; after one, a pick from
    /// the seed and the storm's number among every reality but the one
    /// being left.
    pub fn pick(&self, seed: u64, storms: u32, leaving: &str) -> Option<&RealityDef> {
        if storms == 0 {
            return self.defs.first();
        }
        let others: Vec<&RealityDef> = self.defs.iter().filter(|d| d.name != leaving).collect();
        if others.is_empty() {
            return self.def(leaving);
        }
        let at = salted_index(seed, u64::from(storms), others.len() as u64) as usize;
        Some(others[at])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn reality(name: &str) -> RealityDef {
        RealityDef {
            name: name.to_string(),
            danger: Danger::Hard,
            night: true,
            death_sticks: true,
        }
    }

    fn three() -> RealityRegistry {
        let mut registry = RealityRegistry::default();
        for name in ["first", "second", "third"] {
            registry.register(reality(name)).unwrap();
        }
        registry
    }

    #[test]
    fn before_any_storm_it_is_the_first_registered() {
        assert_eq!(three().pick(7, 0, "").unwrap().name, "first");
    }

    #[test]
    fn the_same_seed_and_storm_pick_the_same_reality() {
        let registry = three();
        for storms in 1..20 {
            assert_eq!(registry.pick(7, storms, "first"), registry.pick(7, storms, "first"));
        }
    }

    #[test]
    fn a_pick_never_repeats_the_reality_being_left() {
        let registry = three();
        for seed in 0..50 {
            for storms in 1..20 {
                for leaving in ["first", "second", "third"] {
                    assert_ne!(registry.pick(seed, storms, leaving).unwrap().name, leaving);
                }
            }
        }
    }

    #[test]
    fn every_other_reality_can_be_picked() {
        let registry = three();
        let picked: std::collections::HashSet<String> =
            (1..200).map(|storms| registry.pick(7, storms, "first").unwrap().name.clone()).collect();
        assert_eq!(picked, ["second", "third"].map(str::to_string).into_iter().collect());
    }

    #[test]
    fn a_reality_registered_twice_is_refused() {
        let mut registry = three();
        assert!(registry.register(reality("second")).is_err());
    }
}
