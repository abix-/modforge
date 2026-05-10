// Per-creature XP awards (game-specific bestiary). The cumulative
// curve and level math live in ueforge::rpg::xp::Curve.

use std::sync::OnceLock;

use ueforge::rpg::Curve;

/// bbp's tuning constants. Adjust here, the curve flows everywhere.
pub const CURVE: Curve = Curve::new(100.0, 1.8, 50);
pub const MAX_LEVEL: u32 = CURVE.max_level;

pub fn cumulative_xp_for_level(level: u32) -> u64 {
    CURVE.cumulative_xp_for_level(level)
}
pub fn level_for_xp(xp: u64) -> u32 {
    CURVE.level_for_xp(xp)
}

const DEFAULT_CREATURE_XP: u32 = 5;

/// Base XP awarded for killing a creature of `class_name`. Lookup is
/// case-sensitive on the BP class short name (e.g. "BP_Aphid_C").
pub fn xp_for_creature(class_name: &str) -> u32 {
    let table = TABLE.get_or_init(default_table);
    for (key, value) in table {
        if class_name == *key {
            return *value;
        }
    }
    DEFAULT_CREATURE_XP
}

/// (BP class name, base XP).
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
    ]
}

static TABLE: OnceLock<Vec<(&'static str, u32)>> = OnceLock::new();
