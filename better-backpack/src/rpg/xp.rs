// XP curve, level math, and per-creature XP awards.
//
// Placeholder values per TODO R6. All numbers are intended to be tuned
// via in-game play; the shape is deliberately simple to keep the math
// predictable.
//
// Curve: cumulative XP required to *reach* level N is `100 * N^1.8`
// (rounded). Level 1 starts at 0 XP. Level 2 at ~100, level 10 at
// ~6310, level 50 at ~91100. Maxes out at level 50.
//
// Per-creature XP comes from a small static lookup keyed on the
// dying actor's class name. Unknown classes get a `default_xp` so the
// system is forgiving about new bug species we haven't tabulated.

use std::sync::OnceLock;

pub const MAX_LEVEL: u32 = 50;

/// Cumulative XP required to reach a given level. Level 1 = 0.
pub fn cumulative_xp_for_level(level: u32) -> u64 {
    if level <= 1 {
        return 0;
    }
    let n = level.min(MAX_LEVEL) as f64;
    (100.0 * n.powf(1.8)).round() as u64
}

/// Returns the level a player at `xp` total XP has earned.
pub fn level_for_xp(xp: u64) -> u32 {
    // Linear scan is fine; MAX_LEVEL is 50.
    for level in (1..=MAX_LEVEL).rev() {
        if xp >= cumulative_xp_for_level(level) {
            return level;
        }
    }
    1
}

/// Base XP awarded for killing a creature of `class_name`. Lookup is
/// case-sensitive on the BP class short name (e.g. "BP_Aphid_C"). Falls
/// back to the default if unknown.
pub fn xp_for_creature(class_name: &str) -> u32 {
    let table = TABLE.get_or_init(default_table);
    for (key, value) in table {
        if class_name == *key {
            return *value;
        }
    }
    DEFAULT_CREATURE_XP
}

const DEFAULT_CREATURE_XP: u32 = 5;

/// (BP class name, base XP). Lookup is linear; the table is small.
fn default_table() -> Vec<(&'static str, u32)> {
    vec![
        // Tier 1 -- common starter bugs
        ("BP_Aphid_C", 5),
        ("BP_Larva_C", 5),
        ("BP_Larva_Burrow_C", 5),
        ("BP_Grub_C", 5),
        ("BP_Mite_C", 3),
        ("BP_Gnat_C", 3),
        // Tier 2 -- combatants
        ("BP_Weevil_C", 15),
        ("BP_Roly_Poly_C", 25),
        ("BP_Ladybug_Augusta_C", 30),
        ("BP_Ant_C", 20),
        ("BP_Bee_C", 35),
        // Tier 3 -- mid-game
        ("BP_Spider_C", 75),
        ("BP_Wolf_Spider_C", 100),
        ("BP_Stinkbug_C", 60),
        ("BP_Mosquito_C", 50),
        // Tier 4 -- elites
        ("BP_Black_Widow_C", 250),
        ("BP_Mantis_C", 300),
        ("BP_Wasp_Queen_C", 400),
        // Bosses
        ("BP_Spider_Tarantula_Boss_C", 750),
        // (Buggies don't appear here; they're never dying-actor side --
        // the player can't kill their own Buggy and earn XP for it.)
    ]
}

static TABLE: OnceLock<Vec<(&'static str, u32)>> = OnceLock::new();
