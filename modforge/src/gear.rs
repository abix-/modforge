//! Gear, Diablo 2's way (topside todo "Tiered loot", operator 2026-11-23:
//! "in all things in Diablo 2 style... maximum randomization, but then
//! logic"; "each armor had stats... it could have an X to a Y value for
//! each thing, and then each particular item might have a modifier or
//! more on it"; "the rune word system, where you had some things that had
//! sockets, and then you could put in a series of rune words in order to
//! make a particular cool effect").
//!
//! A base is an item as gear: its tier (1 up) and its grade within the
//! tier (0 the plain one, then the x tiers above it, as Diablo 2's normal,
//! exceptional and elite bases), its own numbers each rolled X to Y when
//! found, and the sockets a plain one can be found with. A found piece of
//! gear is plain, magic (one or two affixes) or rare (three or four), by
//! the odds the content gives; only a plain one has sockets, as Diablo 2's
//! rune word bases are plain. An affix's numbers are each rolled X to Y.
//! A rune is an item that goes in a socket and adds its own numbers; runes
//! put in the sockets in a rune word's order make the rune word, its
//! numbers added on top. Every number lives on the stack as an `Affix`,
//! so `item::numbers_of` reads it with no registry.

use serde::{Deserialize, Serialize};

use crate::affix::Affix;
use crate::item::{ItemDef, ItemStack};
use crate::monument::Roll;

/// What kind of gear an item is: what an affix or a rune word can go on.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Deserialize)]
#[serde(rename_all = "lowercase")]
pub enum GearKind {
    Melee,
    Gun,
    Armor,
}

/// The kind of gear `def` is, if any: a gun has ammo, a melee weapon a
/// fight and none, armor is worn.
pub fn kind_of(def: &ItemDef) -> Option<GearKind> {
    match (&def.combat, &def.armor) {
        (Some(fight), _) if fight.ammo.is_some() => Some(GearKind::Gun),
        (Some(_), _) => Some(GearKind::Melee),
        (None, Some(_)) => Some(GearKind::Armor),
        (None, None) => None,
    }
}

/// Numbers rolled X to Y, each a least and a most; one left out changes
/// nothing.
#[derive(Clone, Debug, PartialEq, Deserialize, Default)]
#[serde(deny_unknown_fields, default)]
pub struct Ranges {
    /// Added to reach, metres.
    pub reach: (f32, f32),
    /// Added to spread, degrees.
    pub spread: (f32, f32),
    /// Added to the time between blows or shots, seconds.
    pub delay: (f32, f32),
    /// How much harder hits land, in hundredths over 1 (10 is 1.1).
    pub power: (f32, f32),
    /// Added to the armor worn.
    pub armor: (f32, f32),
}

impl Ranges {
    /// These numbers rolled, as an affix of `name`.
    fn roll(&self, name: &str, roll: &mut Roll) -> Affix {
        let mut at = |(lo, hi): (f32, f32)| if hi > lo { roll.measure(lo, hi) } else { lo };
        Affix {
            name: name.to_string(),
            reach: at(self.reach),
            spread_degrees: at(self.spread),
            delay: at(self.delay),
            power: 1.0 + at(self.power) / 100.0,
            armor: at(self.armor),
        }
    }
}

/// An item as gear.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct BaseDef {
    pub item: String,
    #[serde(default = "first")]
    pub tier: u32,
    #[serde(default)]
    pub grade: u32,
    /// Its own numbers, rolled X to Y when it is found.
    #[serde(default)]
    pub rolls: Ranges,
    /// The sockets a plain one is found with, fewest and most.
    #[serde(default)]
    pub sockets: (u32, u32),
}

fn first() -> u32 {
    1
}

/// One affix: its name, the gear it goes on, the least tier it is found
/// at, how likely against the others, and its numbers.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct AffixDef {
    pub name: String,
    pub on: Vec<GearKind>,
    #[serde(default = "first")]
    pub tier: u32,
    #[serde(default = "common")]
    pub weight: u64,
    pub rolls: Ranges,
}

fn common() -> u64 {
    100
}

/// A rune: the item, and the numbers it adds in a socket.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct RuneDef {
    pub item: String,
    pub rolls: Ranges,
}

/// A rune word: its name, its runes in order, the gear it is made in (the
/// sockets exactly as many as its runes), and its numbers.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct RuneWord {
    pub name: String,
    pub runes: Vec<String>,
    pub on: Vec<GearKind>,
    pub rolls: Ranges,
}

/// How a found piece of gear comes, per mille: magic, then rare; the rest
/// plain.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Odds {
    pub magic: u64,
    pub rare: u64,
}

/// Every piece of gear content: read from a game's content (topside's
/// content/gear.yaml).
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct GearDefs {
    pub odds: Odds,
    pub bases: Vec<BaseDef>,
    pub affixes: Vec<AffixDef>,
    #[serde(default)]
    pub runes: Vec<RuneDef>,
    #[serde(default, rename = "rune words")]
    pub words: Vec<RuneWord>,
}

/// A stack's sockets: how many it has, the runes in them in order, and
/// the rune word they made, if they made one.
#[derive(Clone, Debug, PartialEq, Default, Serialize, Deserialize)]
pub struct Sockets {
    pub count: u32,
    pub runes: Vec<String>,
    pub word: Option<String>,
}

/// `stack` of `def` found at a spot of `tier`: its base's numbers rolled,
/// then plain with its sockets, magic, or rare, its affixes rolled from
/// those its kind and the tier allow. An item that is not gear, or has no
/// base, is left as it is. The same for a seed.
pub fn found(defs: &GearDefs, def: &ItemDef, stack: &mut ItemStack, tier: u32, seed: u64) {
    let Some(kind) = kind_of(def) else {
        return;
    };
    let mut roll = Roll::new(seed);
    if let Some(base) = defs.bases.iter().find(|b| b.item == def.name) {
        stack.affixes.push(base.rolls.roll("", &mut roll));
        let n = roll.next(1000);
        let count = if n < defs.odds.rare {
            roll.between(3, 4)
        } else if n < defs.odds.rare + defs.odds.magic {
            roll.between(1, 2)
        } else {
            stack.sockets.count = roll.between(base.sockets.0, base.sockets.1);
            0
        };
        let mut open: Vec<&AffixDef> = defs.affixes.iter().filter(|a| a.on.contains(&kind) && a.tier <= tier).collect();
        for _ in 0..count {
            let total: u64 = open.iter().map(|a| a.weight).sum();
            if total == 0 {
                break;
            }
            let mut at = roll.next(total);
            let Some(k) = open.iter().position(|a| {
                if at < a.weight {
                    return true;
                }
                at -= a.weight;
                false
            }) else {
                break;
            };
            // Each affix once on a piece.
            let a = open.remove(k);
            stack.affixes.push(a.rolls.roll(&a.name, &mut roll));
        }
    }
}

/// Puts the rune `rune` in the next free socket of `stack` of `def`:
/// its numbers added, and, the sockets full in a rune word's order for
/// this kind of gear, the rune word made, its numbers added on top.
/// Refused (false) when `rune` is not a rune or no socket is free.
pub fn socket(defs: &GearDefs, def: &ItemDef, stack: &mut ItemStack, rune: &str, seed: u64) -> bool {
    let Some(r) = defs.runes.iter().find(|r| r.item == rune) else {
        return false;
    };
    if stack.sockets.runes.len() as u32 >= stack.sockets.count {
        return false;
    }
    let mut roll = Roll::new(seed);
    stack.sockets.runes.push(rune.to_string());
    stack.affixes.push(r.rolls.roll(rune, &mut roll));
    let full = stack.sockets.runes.len() as u32 == stack.sockets.count;
    if let (true, Some(kind)) = (full, kind_of(def))
        && let Some(word) = defs.words.iter().find(|w| w.on.contains(&kind) && w.runes == stack.sockets.runes)
    {
        stack.sockets.word = Some(word.name.clone());
        stack.affixes.push(word.rolls.roll(&word.name, &mut roll));
    }
    true
}

/// Whether `item` is a rune.
pub fn is_rune(defs: &GearDefs, item: &str) -> bool {
    defs.runes.iter().any(|r| r.item == item)
}
