//! What a piece's spot on the equipment grid adds, by the game's rules
//! (operator 2026-11-17: "planner needs to take into account adjacney
//! onuses on some itesm too. we gota minmax our placement"). The game
//! adds these in combatant_runtime.gd from_player when it has the grid:
//!
//! - adjacency: equipment_item.gd adjacency_matches, _rule_matches,
//!   matches_rule; inventory.gd neighbour_placements, rotated_side;
//! - edge, corner or inner: equipment_item.gd edge_active, on_edge,
//!   on_corner, on inventory.gd open_size;
//! - board runes: slot_bonus.gd active_runes, active_placement, fold
//!   (2x2 squares; the piece covering most of a square holds it).
//!
//! The packer adds each spot's bonus to its search; each bonus is
//! worth what the fight judge says its stats add (Gain).

use std::sync::Arc;

/// What other pieces' rules look at (equipment_item.gd matches_rule).
#[derive(Debug, Clone, Default, PartialEq)]
pub struct Traits {
    pub tags: Vec<String>,
    pub weapon: bool,
    pub weapon_class: String,
    pub consumable: bool,
    pub cursed: bool,
    /// equipment_item.gd Slot name (WEAPON, SHIELD, ...).
    pub slot: String,
    pub rarity: i64,
}

/// An adjacency bonus (equipment_item.gd adjacent_*).
#[derive(Debug, Clone, Default, PartialEq)]
pub struct Adjacent {
    pub tag: String,
    pub side: String,
    pub min: i64,
    pub also_tag: String,
    pub also_side: String,
    pub stat: String,
    pub amount: f64,
    pub stat_2: String,
    pub amount_2: f64,
}

/// An edge bonus (equipment_item.gd edge_*).
#[derive(Debug, Clone, Default, PartialEq)]
pub struct Edge {
    pub stat: String,
    pub amount: f64,
    pub mode: String,
}

/// What the fight judge says each bonus is worth for this piece.
#[derive(Debug, Clone, Default, PartialEq)]
pub struct Gain {
    /// One matching neighbour (both adjacency stats).
    pub per_match: f64,
    pub edge: f64,
    /// Rune id and what holding it is worth.
    pub runes: Vec<(String, f64)>,
}

/// A piece's placement data.
#[derive(Debug, Clone, Default, PartialEq)]
pub struct Place {
    pub traits: Traits,
    pub adjacent: Option<Adjacent>,
    pub edge: Option<Edge>,
    /// The item's own bonus_atk when the Brawler rune applies to it
    /// (slot_bonus.gd fold: a melee weapon that is not a trigger bow).
    pub brawler_atk: i64,
    pub gain: Gain,
}

pub type Shared = Arc<Place>;

/// The board runes that only add stats (slot_bonus.gd RUNES kind
/// "stat", and "brawler"): rune id, the runtime field, the amount. The
/// other runes change triggers; the fight math port will value them.
pub const STAT_RUNES: &[(&str, &str, f64)] = &[
    ("leech", "lifesteal", 0.1),
    ("whetstone", "atk", 15.0),
    ("bulwark", "armor", 20.0),
    ("bramble", "thorns_damage", 10.0),
];
pub const BRAWLER_SHARE: f64 = 0.25;
pub const RUNE_SIZE: i32 = 2;

const BLADE_CLASSES: &[&str] = &["sword", "dagger"];
const CASTER_CLASSES: &[&str] = &["staff", "wand"];
const RARITIES: &[&str] = &["COMMON", "UNCOMMON", "RARE", "EPIC", "LEGENDARY"];
const SIDES_CLOCKWISE: &[&str] = &["above", "right", "below", "left"];

/// equipment_item.gd matches_rule.
pub fn matches_rule(other: &Traits, rule: &str) -> bool {
    if rule.is_empty() {
        return false;
    }
    if rule.contains("||") {
        return rule
            .split("||")
            .filter(|p| !p.is_empty())
            .any(|p| matches_rule(other, p));
    }
    let rarity_at = |name: &str| {
        RARITIES
            .iter()
            .position(|r| *r == name.to_uppercase())
            .map_or(-1, |i| i as i64)
    };
    match rule {
        "any" => true,
        "weapon" => other.weapon,
        "blade" => other.weapon && BLADE_CLASSES.contains(&other.weapon_class.as_str()),
        "caster" => other.weapon && CASTER_CLASSES.contains(&other.weapon_class.as_str()),
        "consumable" => other.consumable,
        "cursed" => other.cursed,
        _ => {
            if let Some(s) = rule.strip_prefix("slot:") {
                !other.weapon && other.slot == s.to_uppercase()
            } else if let Some(c) = rule.strip_prefix("class:") {
                other.weapon && c.split('|').any(|c| c == other.weapon_class)
            } else if let Some(r) = rule.strip_prefix("rarity>=") {
                rarity_at(r) <= other.rarity
            } else if let Some(r) = rule.strip_prefix("rarity<=") {
                rarity_at(r) >= other.rarity
            } else {
                let tag = rule.strip_prefix("tag:").unwrap_or(rule);
                other.tags.iter().any(|t| t == tag)
            }
        }
    }
}

/// inventory.gd rotated_side.
fn rotated_side(side: &str, rot: i32) -> &str {
    match SIDES_CLOCKWISE.iter().position(|s| *s == side) {
        Some(at) => SIDES_CLOCKWISE[(at + rot.rem_euclid(4) as usize) % 4],
        None => side,
    }
}

fn offset(side: &str) -> (i32, i32) {
    match side {
        "left" => (-1, 0),
        "right" => (1, 0),
        "above" => (0, -1),
        _ => (0, 1),
    }
}

/// One worn piece: its placement data, its cells on the grid, its turn
/// and origin.
pub struct Worn<'a> {
    pub place: &'a Place,
    pub cells: Vec<(i32, i32)>,
    pub rot: i32,
    pub at: (i32, i32),
}

/// The board the bonuses read: the open size for edges and the runes.
#[derive(Debug, Clone, Default)]
pub struct Board {
    /// inventory.gd open_size(EQUIP).
    pub size: (i32, i32),
    /// Each rune square's top-left cell and rune id.
    pub runes: Vec<((i32, i32), String)>,
}

/// inventory.gd neighbour_placements: the other pieces touching `me`
/// on `side` ("" for any side), turned with the piece.
fn neighbours(all: &[Worn], me: usize, side: &str) -> Vec<usize> {
    let side = rotated_side(side, all[me].rot);
    let mut reach = Vec::new();
    for &(x, y) in &all[me].cells {
        for key in SIDES_CLOCKWISE {
            if side.is_empty() || side == *key {
                let (dx, dy) = offset(key);
                reach.push((x + dx, y + dy));
            }
        }
    }
    (0..all.len())
        .filter(|&o| o != me && all[o].cells.iter().any(|c| reach.contains(c)))
        .collect()
}

/// equipment_item.gd _rule_matches.
fn rule_matches(all: &[Worn], me: usize, rule: &str, side: &str) -> i64 {
    let count = |s: &str| {
        neighbours(all, me, s)
            .iter()
            .filter(|&&o| matches_rule(&all[o].place.traits, rule))
            .count() as i64
    };
    match side {
        "left_or_right" => count("left") + count("right"),
        "left_right" => count("left").min(count("right")),
        "above_below" => count("above").min(count("below")),
        s => count(s),
    }
}

/// equipment_item.gd adjacency_matches.
pub fn adjacency_matches(all: &[Worn], me: usize) -> i64 {
    let Some(a) = &all[me].place.adjacent else {
        return 0;
    };
    if a.tag.is_empty() {
        return 0;
    }
    if !a.also_tag.is_empty() && rule_matches(all, me, &a.also_tag, &a.also_side) < 1 {
        return 0;
    }
    rule_matches(all, me, &a.tag, &a.side)
}

/// equipment_item.gd edge_active.
pub fn edge_active(edge: &Edge, cells: &[(i32, i32)], size: (i32, i32)) -> bool {
    if edge.stat.is_empty() {
        return false;
    }
    let on_edge = cells
        .iter()
        .any(|&(x, y)| x == 0 || y == 0 || x == size.0 - 1 || y == size.1 - 1);
    let on_corner = cells
        .iter()
        .any(|&(x, y)| (x == 0 || x == size.0 - 1) && (y == 0 || y == size.1 - 1));
    match edge.mode.as_str() {
        "inner" => !on_edge,
        "corner" => on_corner,
        _ => on_edge,
    }
}

/// slot_bonus.gd active_placement: the piece holding the rune square
/// at `origin` (most cells, then rarity, weapon, size, then the
/// highest and leftmost).
pub fn rune_holder(all: &[Worn], origin: (i32, i32)) -> Option<usize> {
    let mut best: Option<(usize, [i64; 6])> = None;
    for (i, w) in all.iter().enumerate() {
        let covered = w
            .cells
            .iter()
            .filter(|&&(x, y)| {
                let (dx, dy) = (x - origin.0, y - origin.1);
                dx >= 0 && dy >= 0 && dx < RUNE_SIZE && dy < RUNE_SIZE
            })
            .count() as i64;
        if covered == 0 {
            continue;
        }
        let t = &w.place.traits;
        let score = [
            covered,
            t.rarity,
            i64::from(t.weapon),
            w.cells.len() as i64,
            -i64::from(w.at.1),
            -i64::from(w.at.0),
        ];
        if best.as_ref().is_none_or(|(_, b)| score > *b) {
            best = Some((i, score));
        }
    }
    best.map(|(i, _)| i)
}

/// What each worn piece gets from its spot, as (adjacency matches,
/// edge on, rune ids held), in the order of `all`.
pub fn earned(board: &Board, all: &[Worn]) -> Vec<(i64, bool, Vec<String>)> {
    let mut out: Vec<(i64, bool, Vec<String>)> = all
        .iter()
        .enumerate()
        .map(|(i, w)| {
            let matches = match &w.place.adjacent {
                Some(a) if a.amount != 0.0 => {
                    let m = adjacency_matches(all, i);
                    if m >= a.min { m } else { 0 }
                }
                _ => 0,
            };
            let edge = w
                .place
                .edge
                .as_ref()
                .is_some_and(|e| e.amount != 0.0 && edge_active(e, &w.cells, board.size));
            (matches, edge, Vec::new())
        })
        .collect();
    for (origin, rune) in &board.runes {
        if let Some(i) = rune_holder(all, *origin) {
            out[i].2.push(rune.clone());
        }
    }
    out
}

/// What the spots are worth: each piece's matches times its value per
/// match, its edge value when on, and the value of each rune it holds.
pub fn worth(all: &[Worn], got: &[(i64, bool, Vec<String>)]) -> Vec<f64> {
    all.iter()
        .zip(got)
        .map(|(w, (m, e, runes))| {
            let g = &w.place.gain;
            let rune: f64 = runes
                .iter()
                .map(|r| {
                    g.runes
                        .iter()
                        .find(|(id, _)| id == r)
                        .map_or(0.0, |(_, v)| *v)
                })
                .sum();
            g.per_match * *m as f64 + if *e { g.edge } else { 0.0 } + rune
        })
        .collect()
}

pub type Fold = serde_json::Map<String, serde_json::Value>;

/// Adds to one of the hero's fields; whole-number fields round like
/// the game's int fields.
pub fn add(fold: &mut Fold, field: &str, amount: f64) {
    let whole = matches!(
        field,
        "atk" | "max_hp" | "armor" | "thorns_damage" | "poison_resist"
    );
    let was = fold
        .get(field)
        .and_then(serde_json::Value::as_f64)
        .unwrap_or(0.0);
    let amount = if whole { amount.round() } else { amount };
    fold.insert(field.to_string(), serde_json::Value::from(was + amount));
}

/// combatant_runtime.gd _grant: a placement stat onto the hero's
/// fields. The percent ones are taken of `now`, the hero as he is
/// (mine: the game takes them of the whole fold's total).
pub fn grant(fold: &mut Fold, stat: &str, amount: f64, now: &Fold) {
    let of = |k: &str| {
        now.get(k)
            .and_then(serde_json::Value::as_f64)
            .unwrap_or(0.0)
            .max(0.0)
    };
    match stat {
        "armor_pct" => add(fold, "armor", of("armor") * amount),
        "atk_pct" => add(fold, "atk", of("atk") * amount),
        "hp_pct" => add(fold, "max_hp", of("max_hp") * amount),
        "thorns_pct" => add(fold, "thorns_damage", of("thorns_damage") * amount),
        "damage" => add(fold, "damage_dealt_mult", amount),
        "atk" => add(fold, "atk", amount),
        "hp" => add(fold, "max_hp", amount),
        "armor" => add(fold, "armor", amount),
        "block_chance" => add(fold, "block_chance", amount),
        "block_regen" => add(fold, "block_regen", amount),
        "speed" => {
            // equipment_item.gd snap_speed: to SPEED_STEP 0.1, at least 1.
            add(fold, "speed", amount);
            let s = fold
                .get("speed")
                .and_then(serde_json::Value::as_f64)
                .unwrap_or(1.0);
            let snapped = (s / 0.1).round() * 0.1;
            fold.insert("speed".into(), serde_json::Value::from(snapped.max(1.0)));
        }
        "thorns" => add(fold, "thorns_damage", amount),
        "crit" => add(fold, "crit_chance", amount),
        "multistrike" => add(fold, "multistrike_chance", amount),
        "dodge" => add(fold, "dodge_chance", amount),
        "magic_resist" => add(fold, "magic_resist", amount),
        "lifesteal" => add(fold, "lifesteal", amount),
        "burn" => add(fold, "burn_dmg_bonus", amount),
        "poison" => add(fold, "poison_dmg_bonus", amount),
        "poison_resist" => add(fold, "poison_resist", amount),
        "bleed" => add(fold, "bleed_dmg_bonus", amount),
        "stun" => add(fold, "stun_dmg_bonus", amount),
        _ => {}
    }
}

/// A rune onto the hero's fields, for the piece holding it
/// (slot_bonus.gd fold); false for the runes that change triggers.
pub fn rune_onto(fold: &mut Fold, rune: &str, place: &Place) -> bool {
    if let Some(&(_, field, amount)) = STAT_RUNES.iter().find(|r| r.0 == rune) {
        add(fold, field, amount);
        return true;
    }
    if rune == "brawler" && place.brawler_atk != 0 {
        add(fold, "atk", place.brawler_atk as f64 * BRAWLER_SHARE);
        return true;
    }
    false
}

/// The most a piece's spot could add, for the packer's bound: every
/// matching piece in `others` as a neighbour (twice for either side),
/// the edge, and its best runes, as many as it has cells.
pub fn most(place: &Place, cells: usize, others: &[&Place], runes: usize) -> f64 {
    let g = &place.gain;
    let mut add = g.edge.max(0.0);
    if let Some(a) = &place.adjacent
        && g.per_match > 0.0
    {
        let n = others
            .iter()
            .filter(|o| matches_rule(&o.traits, &a.tag))
            .count() as f64;
        add += g.per_match * n * if a.side == "left_or_right" { 2.0 } else { 1.0 };
    }
    let mut best: Vec<f64> = g.runes.iter().map(|(_, v)| v.max(0.0)).collect();
    best.sort_by(|a, b| b.total_cmp(a));
    add + best.iter().take(runes.min(cells)).sum::<f64>()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn traits(tags: &[&str]) -> Traits {
        Traits {
            tags: tags.iter().map(|t| t.to_string()).collect(),
            ..Traits::default()
        }
    }

    fn worn<'a>(place: &'a Place, cells: &[(i32, i32)], rot: i32) -> Worn<'a> {
        Worn {
            place,
            cells: cells.to_vec(),
            rot,
            at: cells[0],
        }
    }

    /// A "right" rule turned once looks below (inventory.gd
    /// rotated_side, clockwise).
    #[test]
    fn side_turns_with_the_piece() {
        let me = Place {
            adjacent: Some(Adjacent {
                tag: "gem".into(),
                side: "right".into(),
                min: 1,
                amount: 1.0,
                ..Adjacent::default()
            }),
            ..Place::default()
        };
        let gem = Place {
            traits: traits(&["gem"]),
            ..Place::default()
        };
        let flat = [worn(&me, &[(0, 0)], 0), worn(&gem, &[(1, 0)], 0)];
        assert_eq!(adjacency_matches(&flat, 0), 1);
        let turned = [worn(&me, &[(0, 0)], 1), worn(&gem, &[(1, 0)], 0)];
        assert_eq!(adjacency_matches(&turned, 0), 0);
        let below = [worn(&me, &[(0, 0)], 1), worn(&gem, &[(0, 1)], 0)];
        assert_eq!(adjacency_matches(&below, 0), 1);
    }

    /// Both sides: the fewer of the two counts.
    #[test]
    fn left_right_takes_the_fewer() {
        let me = Place {
            adjacent: Some(Adjacent {
                tag: "any".into(),
                side: "left_right".into(),
                min: 1,
                amount: 1.0,
                ..Adjacent::default()
            }),
            ..Place::default()
        };
        let o = Place::default();
        let one = [worn(&me, &[(1, 0)], 0), worn(&o, &[(0, 0)], 0)];
        assert_eq!(adjacency_matches(&one, 0), 0);
        let both = [
            worn(&me, &[(1, 0)], 0),
            worn(&o, &[(0, 0)], 0),
            worn(&o, &[(2, 0)], 0),
        ];
        assert_eq!(adjacency_matches(&both, 0), 1);
    }

    /// The rune square goes to the piece covering more of it.
    #[test]
    fn rune_goes_to_most_cells() {
        let a = Place::default();
        let b = Place::default();
        let all = [
            worn(&a, &[(0, 0)], 0),
            worn(&b, &[(1, 0), (0, 1), (1, 1)], 0),
        ];
        assert_eq!(rune_holder(&all, (0, 0)), Some(1));
    }

    #[test]
    fn rules() {
        let t = Traits {
            weapon: true,
            weapon_class: "dagger".into(),
            rarity: 3,
            ..Traits::default()
        };
        assert!(matches_rule(&t, "blade"));
        assert!(matches_rule(&t, "class:axe|dagger"));
        assert!(matches_rule(&t, "rarity>=rare"));
        assert!(!matches_rule(&t, "rarity<=uncommon"));
        assert!(matches_rule(&t, "cursed||weapon"));
    }
}
