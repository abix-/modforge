// Per-creature XP awards (game-specific bestiary). The cumulative
// curve and per-class lookup live in ueforge::rpg::xp.

use ueforge::rpg::{CreatureDef, CreatureRegistry, Curve};

/// g2rpg's tuning constants. Adjust here, the curve flows everywhere.
pub const CURVE: Curve = Curve::new(100.0, 1.8, 50);
pub const MAX_LEVEL: u32 = CURVE.max_level;

pub fn cumulative_xp_for_level(level: u32) -> u64 {
    CURVE.cumulative_xp_for_level(level)
}
pub fn level_for_xp(xp: u64) -> u32 {
    CURVE.level_for_xp(xp)
}

/// Base XP awarded for killing a creature of `class_name`. Lookup is
/// case-sensitive on the BP class short name (e.g. "BP_Aphid_C").
pub fn xp_for_creature(class_name: &str) -> u32 {
    CREATURES.lookup(class_name)
}

pub static CREATURES: CreatureRegistry = CreatureRegistry::new(
    &[
        // Tier 1 -- common starter bugs
        CreatureDef { class_name: "BP_Aphid_C",       base_xp: 5 },
        CreatureDef { class_name: "BP_Larva_C",       base_xp: 5 },
        CreatureDef { class_name: "BP_Larva_Burrow_C", base_xp: 5 },
        CreatureDef { class_name: "BP_Grub_C",        base_xp: 5 },
        CreatureDef { class_name: "BP_Mite_C",        base_xp: 3 },
        CreatureDef { class_name: "BP_Gnat_C",        base_xp: 3 },
        // Tier 2 -- combatants
        CreatureDef { class_name: "BP_Weevil_C",          base_xp: 15 },
        CreatureDef { class_name: "BP_Roly_Poly_C",       base_xp: 25 },
        CreatureDef { class_name: "BP_Ladybug_Augusta_C", base_xp: 30 },
        CreatureDef { class_name: "BP_Ant_C",             base_xp: 20 },
        CreatureDef { class_name: "BP_Bee_C",             base_xp: 35 },
        // Tier 3 -- mid-game
        CreatureDef { class_name: "BP_Spider_C",      base_xp: 75 },
        CreatureDef { class_name: "BP_Wolf_Spider_C", base_xp: 100 },
        CreatureDef { class_name: "BP_Stinkbug_C",    base_xp: 60 },
        CreatureDef { class_name: "BP_Mosquito_C",    base_xp: 50 },
        // Tier 4 -- elites
        CreatureDef { class_name: "BP_Black_Widow_C", base_xp: 250 },
        CreatureDef { class_name: "BP_Mantis_C",      base_xp: 300 },
        CreatureDef { class_name: "BP_Wasp_Queen_C",  base_xp: 400 },
        // Bosses
        CreatureDef { class_name: "BP_Spider_Tarantula_Boss_C", base_xp: 750 },
    ],
    5,
);
