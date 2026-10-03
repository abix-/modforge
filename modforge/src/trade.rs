//! Trading (topside authority.md "Trading", design.md "Trading"): things for
//! things between any two people, from what they really carry; scrap is the
//! currency, an item worth 1 like any other item; every item has one fixed
//! value (operator, 2026-10-02: the consumer's content registers them); how a
//! trader stands toward the other decides whether they trade at all and at
//! what prices: hostile refuse, neutral trade cautiously, friendly give better
//! deals.
//!
//! Prior art: Fallout's barter (a value on every item; the trader marks up
//! what they sell and marks down what they buy by standing; a trade goes
//! through when what the trader gets is worth at least what they give).

use std::collections::HashMap;

use crate::faction::Relation;
use crate::item::{Inventory, ItemStack};

/// The item that is money.
pub const CURRENCY: &str = "scrap";

/// Every item's value, in scrap; an item with none is worth nothing.
#[derive(Clone, Debug, Default)]
pub struct Values(pub HashMap<String, u32>);

impl Values {
    pub fn of(&self, item: &str) -> u32 {
        self.0.get(item).copied().unwrap_or(0)
    }

    /// What these stacks are worth.
    pub fn worth<'a>(&self, stacks: impl IntoIterator<Item = &'a ItemStack>) -> u32 {
        stacks.into_iter().map(|s| self.of(&s.item) * s.count).sum()
    }
}

/// A trader's prices toward someone: what they ask for their own things
/// and what they pay for the other's, as parts of the value.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Terms {
    pub sells_at: f32,
    pub buys_at: f32,
}

/// A trader's prices by how they stand toward the other; none when they
/// will not trade (hostile).
pub fn terms(relation: Relation) -> Option<Terms> {
    match relation {
        Relation::Hostile => None,
        Relation::Neutral => Some(Terms { sells_at: 1.5, buys_at: 0.5 }),
        Relation::Friendly => Some(Terms { sells_at: 1.1, buys_at: 0.9 }),
    }
}

/// Whether a trader with these terms takes `gets` (the other's things) for
/// `gives` (their own): what they get, at what they pay, is worth at least
/// what they give, at what they ask.
pub fn accepts(values: &Values, terms: Terms, gives: &[ItemStack], gets: &[ItemStack]) -> bool {
    !(gives.is_empty() && gets.is_empty()) && values.worth(gets) as f32 * terms.buys_at >= values.worth(gives) as f32 * terms.sells_at
}

/// One side's offer: which slot of their inventory, and how many from it.
pub type Offer = Vec<(usize, u32)>;

/// What someone pays for `wanted` from `purse`: scrap first, then the
/// things they can spare (`spare` says which), one at a time, until a
/// trader with `terms` takes it; None if all they can spare is not enough.
pub fn pay_for(values: &Values, terms: Terms, wanted: &[ItemStack], purse: &Inventory, spare: impl Fn(&str) -> bool) -> Option<Offer> {
    let mut slots: Vec<usize> = (0..purse.slots.len()).filter(|&i| purse.slots[i].as_ref().is_some_and(|s| s.item == CURRENCY || spare(&s.item))).collect();
    slots.sort_by_key(|&i| purse.slots[i].as_ref().is_some_and(|s| s.item != CURRENCY));
    let mut offer: Offer = Vec::new();
    for slot in slots {
        let have = purse.slots[slot].as_ref().map_or(0, |s| s.count);
        for _ in 0..have {
            match offer.iter_mut().find(|(s, _)| *s == slot) {
                Some((_, n)) => *n += 1,
                None => offer.push((slot, 1)),
            }
            if accepts(values, terms, wanted, &offered(purse, &offer)?) {
                return Some(offer);
            }
        }
    }
    None
}

/// The stacks an offer comes to, from the inventory it is made from; None
/// if a slot is empty or holds fewer than offered.
pub fn offered(inventory: &Inventory, offer: &Offer) -> Option<Vec<ItemStack>> {
    offer
        .iter()
        .map(|&(slot, count)| {
            let stack = inventory.slots.get(slot)?.as_ref()?;
            (count > 0 && count <= stack.count).then(|| ItemStack { count, ..stack.clone() })
        })
        .collect()
}

/// The trade carried out: `a` gives what `a_offers`, `b` what `b_offers`,
/// each into the other's inventory; all of it or none (both have what they
/// offer, both have room for what they get). `max_stack` is an item's stack
/// size.
pub fn exchange(a: &mut Inventory, b: &mut Inventory, a_offers: &Offer, b_offers: &Offer, max_stack: impl Fn(&str) -> u32) -> Result<(), String> {
    let (Some(_), Some(_)) = (offered(a, a_offers), offered(b, b_offers)) else {
        return Err("an offer holds what its side does not have".to_string());
    };
    let (mut a2, mut b2) = (a.clone(), b.clone());
    let take = |inv: &mut Inventory, offer: &Offer| -> Vec<ItemStack> { offer.iter().filter_map(|&(slot, count)| inv.remove(slot, count)).collect() };
    let from_a = take(&mut a2, a_offers);
    let from_b = take(&mut b2, b_offers);
    for stack in from_a {
        let size = max_stack(&stack.item);
        if b2.add(stack, size).is_some() {
            return Err("no room for it".to_string());
        }
    }
    for stack in from_b {
        let size = max_stack(&stack.item);
        if a2.add(stack, size).is_some() {
            return Err("no room for it".to_string());
        }
    }
    *a = a2;
    *b = b2;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn stack(item: &str, count: u32) -> ItemStack {
        ItemStack { item: item.to_string(), count, quality: None, note: None, layers: Vec::new(), litres: 0.0 }
    }

    fn values() -> Values {
        Values([("scrap", 1), ("water bottle", 10), ("canned food", 12)].into_iter().map(|(n, v)| (n.to_string(), v)).collect())
    }

    #[test]
    fn hostile_refuse_neutral_are_cautious_friends_give_better_deals() {
        assert_eq!(terms(Relation::Hostile), None);
        let (neutral, friend) = (terms(Relation::Neutral).unwrap(), terms(Relation::Friendly).unwrap());
        assert!(friend.sells_at < neutral.sells_at && friend.buys_at > neutral.buys_at);
    }

    #[test]
    fn a_trader_takes_an_offer_worth_what_they_give_at_their_prices() {
        let v = values();
        let friend = terms(Relation::Friendly).unwrap();
        // Their water (10, asked at 11) for 12 scrap (paid at 10.8): no;
        // for 13 scrap (11.7): yes.
        assert!(!accepts(&v, friend, &[stack("water bottle", 1)], &[stack("scrap", 12)]));
        assert!(accepts(&v, friend, &[stack("water bottle", 1)], &[stack("scrap", 13)]));
        // Water for food and a scrap: a friend takes it (13 * 0.9 = 11.7 >=
        // 11), a stranger does not (13 * 0.5 = 6.5 < 15); water for food
        // alone, not even a friend (10.8 < 11).
        let food_and_scrap = [stack("canned food", 1), stack("scrap", 1)];
        assert!(accepts(&v, friend, &[stack("water bottle", 1)], &food_and_scrap));
        assert!(!accepts(&v, terms(Relation::Neutral).unwrap(), &[stack("water bottle", 1)], &food_and_scrap));
        assert!(!accepts(&v, friend, &[stack("water bottle", 1)], &[stack("canned food", 1)]));
        assert!(!accepts(&v, friend, &[], &[]), "nothing for nothing is no trade");
    }

    #[test]
    fn one_pays_with_scrap_first_then_what_they_can_spare_and_only_enough() {
        let v = values();
        let neutral = terms(Relation::Neutral).unwrap();
        let mut purse = Inventory::new(3);
        purse.add(stack("canned food", 2), 10);
        purse.add(stack("scrap", 25), 100);
        let water = [stack("water bottle", 1)];
        // Water asked at 15, scrap paid at 0.5: 25 scrap is 12.5, then one
        // can (6) makes 18.5: enough.
        let paid = pay_for(&v, neutral, &water, &purse, |item| item == "canned food").expect("enough with the food");
        assert_eq!(paid, vec![(1, 25), (0, 1)], "all the scrap first, then one can");
        assert_eq!(pay_for(&v, neutral, &water, &purse, |_| false), None, "the scrap alone is not enough, and nothing else is spared");
        assert_eq!(pay_for(&v, terms(Relation::Friendly).unwrap(), &water, &purse, |_| false), Some(vec![(1, 13)]), "a friend: 13 scrap (11.7 for 11)");
    }

    #[test]
    fn an_exchange_moves_both_offers_or_nothing() {
        let mut a = Inventory::new(4);
        let mut b = Inventory::new(2);
        a.add(stack("scrap", 20), 100);
        b.add(stack("water bottle", 2), 10);
        exchange(&mut a, &mut b, &vec![(0, 13)], &vec![(0, 1)], |_| 100).expect("both have it and room");
        assert_eq!((a.count_of("scrap"), a.count_of("water bottle")), (7, 1));
        assert_eq!((b.count_of("scrap"), b.count_of("water bottle")), (13, 1));
        // b's two slots hold water and scrap now: no room for food; nothing moves.
        a.add(stack("canned food", 1), 10);
        let before = (a.clone(), b.clone());
        assert!(exchange(&mut a, &mut b, &vec![(2, 1)], &vec![], |_| 100).is_err());
        assert_eq!((a.count_of("canned food"), b.count_of("canned food")), (before.0.count_of("canned food"), 0));
        assert!(exchange(&mut a, &mut b, &vec![(0, 99)], &vec![], |_| 100).is_err(), "offering more than they have");
    }
}
