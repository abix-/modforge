//! An item's plain stats and how a stat bonus changes a fighter. One
//! place for the auto-player and the mod's own steps.

use crate::fight::Fighter;
use serde_json::{Map, Value};

/// An item's plain stats and the player stat each adds to (the names
/// of dismantle_encounter.gd ABSORB_STATS). Not yet: triggers,
/// abilities, percent bonuses.
pub const ITEM_STATS: [(&str, &str); 9] = [
    ("bonus_hp", "max_hp"),
    ("bonus_atk", "atk"),
    ("bonus_armor", "armor"),
    ("bonus_speed", "speed"),
    ("bonus_dodge", "dodge_chance"),
    ("bonus_crit", "crit_chance"),
    ("bonus_multistrike", "multistrike_chance"),
    ("bonus_magic_resist", "magic_resist"),
    ("bonus_block_chance", "block_chance"),
];

/// An item's plain stats (ITEM_STATS fields) as player stat bonuses.
pub fn stats_from(vars: &Map<String, Value>) -> Vec<(&'static str, f64)> {
    ITEM_STATS
        .iter()
        .filter_map(|(field, stat)| {
            let v = vars.get(*field)?.as_f64()?;
            (v != 0.0).then_some((*stat, v))
        })
        .collect()
}

/// One permanent stat bonus on the player, by the game's stat names
/// (game_state.gd LEVEL_BONUS_POOL for the genie, dismantle's
/// ABSORB_STATS). Percent bonuses count on the stat as it is now.
pub fn apply_bonus(p: &mut Fighter, stat: &str, n: f64) {
    let pct = |v: i64| (v as f64 * (1.0 + n)).round() as i64;
    match stat {
        "max_hp_pct" => {
            p.max_hp = pct(p.max_hp);
            p.hp = p.max_hp;
        }
        "max_hp" => {
            p.max_hp += n.round() as i64;
            p.hp = p.max_hp;
        }
        "atk_pct" => p.atk = pct(p.atk),
        "atk" => p.atk += n.round() as i64,
        "armor_pct" => {
            p.block_max = pct(p.block_max);
            p.block = p.block_max;
        }
        "armor" => {
            p.block_max += n.round() as i64;
            p.block = p.block_max;
        }
        "block_chance" => p.block_chance += n,
        "dodge_chance" => p.dodge += n,
        "crit_chance" => p.crit += n,
        "multistrike_chance" => p.multistrike += n,
        "magic_resist" => p.magic_resist += n,
        "speed" => p.speed += n,
        // Block regen, luck, thorns and mana are not in the fight
        // math yet.
        _ => {}
    }
}

/// Stats of several items on a fighter (sign 1 on, -1 off).
pub fn wear(p: &mut Fighter, stats: &[(&'static str, f64)], sign: f64) {
    for (stat, v) in stats {
        apply_bonus(p, stat, sign * v);
    }
}
