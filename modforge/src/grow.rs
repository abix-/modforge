//! Growing food (topside-town "Everything works": "gardens, farm fields,
//! barns, animals and seed make food"; Project Zomboid's farming, a seed
//! sown in a plot that ripens over days and is harvested): a crop is
//! sown from its seed on a day, ripens after its days, and gives its
//! food, and seed back, when harvested ripe. Engine-free; the game holds
//! the crops and where they grow.

use serde::{Deserialize, Serialize};

/// One crop: its seed, what it gives, and how long it takes.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct CropDef {
    pub seed: &'static str,
    pub food: &'static str,
    /// Game days from sowing to ripe.
    pub days: f32,
    /// How much food a ripe crop gives, and how many seeds back.
    pub gives: u32,
    pub seeds_back: u32,
}

/// One crop in the ground: which, and the day it was sown.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Sown {
    pub crop: usize,
    pub day: f32,
}

/// The crop sown from `seed`, of `crops`, if it is a seed.
pub fn crop_of(crops: &[CropDef], seed: &str) -> Option<usize> {
    crops.iter().position(|c| c.seed == seed)
}

/// Whether a crop sown on `sown` is ripe on `today`.
pub fn ripe(def: &CropDef, sown: f32, today: f32) -> bool {
    today - sown >= def.days
}

#[cfg(test)]
mod tests {
    use super::*;

    const CROPS: [CropDef; 1] = [CropDef { seed: "carrot seed", food: "carrot", days: 3.0, gives: 4, seeds_back: 2 }];

    #[test]
    fn a_seed_sown_ripens_after_its_days() {
        let crop = crop_of(&CROPS, "carrot seed").unwrap();
        assert_eq!(crop_of(&CROPS, "scrap"), None);
        assert!(!ripe(&CROPS[crop], 1.0, 3.5));
        assert!(ripe(&CROPS[crop], 1.0, 4.0));
    }
}
