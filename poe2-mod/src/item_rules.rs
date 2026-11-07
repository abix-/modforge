//! Item rules: which items in a vendor window or stash tab the operator
//! wants. Shaped after GameHelper2's PickupHelper (a whitelist of names,
//! item kinds by path, rarities) plus a value floor from loot value and
//! mod text, the parts ExileCore2's NpcInvWithLinq rules use most.
//! Every condition given must hold; a condition left out holds always.
//! Text matches ignore case.

use crate::model::{Item, Rarity};
use serde::{Deserialize, Serialize};

#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct ItemRule {
    /// What to call a match.
    pub name: String,
    /// The unique name or base contains one of these.
    pub names: Vec<String>,
    /// The metadata path contains this, such as `Currency` or `Rings`.
    pub path_contains: Option<String>,
    /// One of these rarities; empty means any.
    pub rarity: Vec<Rarity>,
    /// The whole stack is worth at least this many exalted orbs.
    pub min_exalted: Option<f64>,
    /// Every one of these appears in some mod's text.
    pub mods: Vec<String>,
}

fn contains(text: &str, part: &str) -> bool {
    text.to_lowercase().contains(&part.to_lowercase())
}

impl ItemRule {
    /// Does `item` pass? `stack_exalted` is its stack's price, if known;
    /// an unknown price fails a value floor.
    pub fn matches(&self, item: &Item, stack_exalted: Option<f64>) -> bool {
        let name_ok = self.names.is_empty()
            || self
                .names
                .iter()
                .any(|n| contains(&item.name, n) || contains(&item.base, n));
        let path_ok = self
            .path_contains
            .as_deref()
            .is_none_or(|p| contains(&item.path, p));
        let rarity_ok =
            self.rarity.is_empty() || item.rarity.is_some_and(|r| self.rarity.contains(&r));
        let value_ok = self
            .min_exalted
            .is_none_or(|min| stack_exalted.is_some_and(|v| v >= min));
        let mods_ok = self
            .mods
            .iter()
            .all(|want| item.mods.iter().any(|m| contains(m, want)));
        name_ok && path_ok && rarity_ok && value_ok && mods_ok
    }
}

/// Each item that passes a rule, with the first rule it passed.
pub fn matching<'r>(
    rules: &'r [ItemRule],
    items: &[Item],
    stack_exalted: impl Fn(&Item) -> Option<f64>,
) -> Vec<(usize, &'r str)> {
    items
        .iter()
        .enumerate()
        .filter_map(|(i, item)| {
            let price = stack_exalted(item);
            rules
                .iter()
                .find(|r| r.matches(item, price))
                .map(|r| (i, r.name.as_str()))
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn ring(rarity: Rarity, mods: &[&str]) -> Item {
        Item {
            path: "Metadata/Items/Rings/Ring1".into(),
            base: "Gold Ring".into(),
            rarity: Some(rarity),
            stack: 1,
            mods: mods.iter().map(|m| m.to_string()).collect(),
            ..Item::default()
        }
    }

    #[test]
    fn empty_rule_passes_everything() {
        assert!(ItemRule::default().matches(&ring(Rarity::Normal, &[]), None));
    }

    #[test]
    fn every_condition_must_hold() {
        let rule = ItemRule {
            name: "good rings".into(),
            path_contains: Some("rings".into()),
            rarity: vec![Rarity::Rare],
            mods: vec!["to maximum life".into(), "fire resistance".into()],
            ..ItemRule::default()
        };
        let both = ring(
            Rarity::Rare,
            &["+80 to maximum Life", "+30% to Fire Resistance"],
        );
        assert!(rule.matches(&both, None));
        assert!(!rule.matches(&ring(Rarity::Rare, &["+80 to maximum Life"]), None));
        assert!(!rule.matches(
            &ring(
                Rarity::Magic,
                &["+80 to maximum Life", "+30% to Fire Resistance"]
            ),
            None
        ));
    }

    #[test]
    fn value_floor_needs_a_known_price() {
        let rule = ItemRule {
            min_exalted: Some(10.0),
            ..ItemRule::default()
        };
        let item = ring(Rarity::Normal, &[]);
        assert!(rule.matches(&item, Some(10.0)));
        assert!(!rule.matches(&item, Some(9.9)));
        assert!(!rule.matches(&item, None));
    }

    #[test]
    fn matching_names_the_first_rule_passed() {
        let rules = [
            ItemRule {
                name: "uniques".into(),
                rarity: vec![Rarity::Unique],
                ..ItemRule::default()
            },
            ItemRule {
                name: "gold rings".into(),
                names: vec!["gold ring".into()],
                ..ItemRule::default()
            },
        ];
        let items = [
            ring(Rarity::Unique, &[]),
            ring(Rarity::Normal, &[]),
            Item {
                base: "Iron Ring".into(),
                ..ring(Rarity::Normal, &[])
            },
        ];
        assert_eq!(
            matching(&rules, &items, |_| None),
            vec![(0, "uniques"), (1, "gold rings")]
        );
    }
}
