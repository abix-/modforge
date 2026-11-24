//! Affixes (topside design.md "Loot randomization", Diablo 2's affix
//! model): random properties rolled onto an item as it enters existence,
//! on top of its base type, its layers and its quality tier. A
//! "lightweight pipe" and a "sharpened pipe" are the same pipe with
//! different affixes; affixes stack, and two on one item is rare.
//!
//! An affix carries its own numbers on the stack, so the one place an
//! item's numbers are worked out (`item::numbers_of`) needs no registry
//! to read them.

use crate::unknown::rng;

/// One affix: its name, as a player reads it before the item's, and what
/// it changes: added to the item's reach (metres), spread (degrees) and
/// delay (seconds), how much harder its hits land (1 changes nothing), and
/// the armor it adds when worn (crate::gear).
#[derive(Clone, PartialEq, Debug, serde::Serialize, serde::Deserialize)]
pub struct Affix {
    pub name: String,
    pub reach: f32,
    pub spread_degrees: f32,
    pub delay: f32,
    pub power: f32,
    #[serde(default)]
    pub armor: f32,
    /// Added to the wearer's most health while worn (crate::gear).
    #[serde(default)]
    pub health: f32,
}

/// Roll the affixes of one item from `table`: the first comes one time in
/// `one_in`, a second (a different one) one time in `one_in` again after
/// it, so two are rare. Seeded by `now` and `salt`, as quality is.
pub fn roll(table: &[Affix], one_in: u64, now: f32, salt: u64) -> Vec<Affix> {
    let mut out: Vec<Affix> = Vec::new();
    if table.is_empty() || one_in == 0 {
        return out;
    }
    for round in 0..2u64 {
        let salt = mix(salt ^ mix(round + 1));
        if rng(now, salt, one_in) != 0 {
            break;
        }
        let pick = &table[rng(now, mix(salt), table.len() as u64) as usize];
        if out.iter().any(|a| a.name == pick.name) {
            break;
        }
        out.push(pick.clone());
    }
    out
}

/// Splitmix64's finaliser: each roll its own salt, unrelated to the last.
fn mix(mut x: u64) -> u64 {
    x = x.wrapping_add(0x9E37_79B9_7F4A_7C15);
    x = (x ^ (x >> 30)).wrapping_mul(0xBF58_476D_1CE4_E5B9);
    x = (x ^ (x >> 27)).wrapping_mul(0x94D0_49BB_1331_11EB);
    x ^ (x >> 31)
}

/// How much harder an item's affixes make its hits land, all together.
pub fn power(affixes: &[Affix]) -> f32 {
    affixes.iter().map(|a| a.power).product()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn table() -> Vec<Affix> {
        let a = |name: &str, delay, power| Affix {
            name: name.to_string(),
            reach: 0.0,
            spread_degrees: 0.0,
            delay,
            power,
            armor: 0.0,
            health: 0.0,
        };
        vec![a("light", -0.1, 1.0), a("sharp", 0.0, 1.2)]
    }

    #[test]
    fn some_items_roll_affixes_and_two_are_rare() {
        let rolls: Vec<_> = (0..4000).map(|s| roll(&table(), 4, 0.0, s)).collect();
        let one = rolls.iter().filter(|r| r.len() == 1).count();
        let two = rolls.iter().filter(|r| r.len() == 2).count();
        assert!((700..1300).contains(&one), "one {one}");
        assert!(two > 0 && two < one / 2, "two {two}");
        assert!(rolls.iter().all(|r| r.len() < 2 || r[0].name != r[1].name));
        assert_eq!(roll(&table(), 4, 0.0, 77), roll(&table(), 4, 0.0, 77));
    }

    #[test]
    fn affixes_multiply_hits_together() {
        let t = table();
        assert_eq!(power(&[]), 1.0);
        assert!((power(&[t[1].clone(), t[1].clone()]) - 1.44).abs() < 1e-5);
    }
}
