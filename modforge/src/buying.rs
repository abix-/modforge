//! What to buy with a fixed amount of money, under a cap on purchases
//! and on unlocks.
//!
//! An offer is something on sale: its cost, and when it is locked, the
//! price to unlock it first (an unlock counts once, however many are
//! bought). A basket is one choice of purchases. Only baskets that
//! leave nothing more affordable are kept: money left over buys nothing
//! (operator, Mechabellum 2026-11-07: "simulation before spending it
//! all is dumb"). Most money spent first.
//!
//! Plain enumeration with repetition in offer order, the textbook way
//! to list multisets; the caps keep it small.

/// Something on sale.
#[derive(Clone, Debug, PartialEq, Eq, serde::Serialize)]
pub struct Offer {
    pub id: i64,
    pub cost: i64,
    /// None when it can be bought now; the unlock price when locked.
    pub unlock: Option<i64>,
    /// How many times it can be bought; None is no limit. A shop slot
    /// that empties when bought is Some(1).
    pub most: Option<usize>,
}

/// One choice of purchases.
#[derive(Clone, Debug, PartialEq, Eq, serde::Serialize)]
pub struct Basket {
    /// Offer ids bought, one entry per purchase.
    pub buys: Vec<i64>,
    /// Offer ids unlocked to make those buys.
    pub unlocks: Vec<i64>,
    /// Purchases and unlocks together.
    pub spent: i64,
}

struct Walk<'a> {
    offers: &'a [Offer],
    money: i64,
    max_buys: usize,
    max_unlocks: usize,
    out: Vec<Basket>,
}

impl Walk<'_> {
    /// Extra cost of buying offer `i` once more into `b`, if allowed.
    fn price(&self, b: &Basket, i: usize) -> Option<i64> {
        let o = &self.offers[i];
        if b.buys.len() >= self.max_buys || o.most.is_some_and(|m| b.buys.iter().filter(|&&x| x == o.id).count() >= m) {
            return None;
        }
        let unlock = match o.unlock {
            Some(p) if !b.unlocks.contains(&o.id) => {
                if b.unlocks.len() >= self.max_unlocks {
                    return None;
                }
                p
            }
            _ => 0,
        };
        let total = o.cost + unlock;
        (b.spent + total <= self.money).then_some(total)
    }

    fn add(&self, b: &Basket, i: usize, total: i64) -> Basket {
        let o = &self.offers[i];
        let mut n = b.clone();
        n.buys.push(o.id);
        if o.unlock.is_some() && !n.unlocks.contains(&o.id) {
            n.unlocks.push(o.id);
        }
        n.spent += total;
        n
    }

    fn go(&mut self, b: Basket, from: usize) {
        // Kept only when nothing at all (in any order) still fits.
        if (0..self.offers.len()).all(|i| self.price(&b, i).is_none()) {
            self.out.push(b.clone());
        }
        for i in from..self.offers.len() {
            if let Some(total) = self.price(&b, i) {
                let n = self.add(&b, i, total);
                self.go(n, i);
            }
        }
    }
}

/// Every basket that leaves nothing more affordable, most spent first,
/// then fewer unlocks.
pub fn baskets(offers: &[Offer], money: i64, max_buys: usize, max_unlocks: usize) -> Vec<Basket> {
    let mut w = Walk { offers, money, max_buys, max_unlocks, out: Vec::new() };
    w.go(Basket { buys: Vec::new(), unlocks: Vec::new(), spent: 0 }, 0);
    let mut out = w.out;
    out.sort_by(|a, b| b.spent.cmp(&a.spent).then(a.unlocks.len().cmp(&b.unlocks.len())));
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    fn open(id: i64, cost: i64) -> Offer {
        Offer { id, cost, unlock: None, most: None }
    }

    #[test]
    fn a_shop_slot_is_bought_once() {
        let once = |id, cost| Offer { id, cost, unlock: None, most: Some(1) };
        // 500 money, slots 100, 200, 100, 200, 100: never the same slot
        // twice, and 500 spent exactly where it fits.
        let b = baskets(&[once(0, 100), once(1, 200), once(2, 100), once(3, 200), once(4, 100)], 500, 9, 0);
        for x in &b {
            let mut ids = x.buys.clone();
            ids.dedup();
            assert_eq!(ids.len(), x.buys.len());
        }
        assert_eq!(b[0].spent, 500);
    }

    #[test]
    fn spends_as_much_as_the_caps_allow() {
        // 500 money, 2 buys: 200 + 200 is the most.
        let b = baskets(&[open(1, 100), open(2, 200)], 500, 2, 0);
        assert_eq!(b[0].buys, vec![2, 2]);
        assert_eq!(b[0].spent, 400);
        // Every basket is full: two buys each.
        assert!(b.iter().all(|x| x.buys.len() == 2));
    }

    #[test]
    fn leftover_only_when_nothing_fits() {
        // 250 money, no buy cap: 200 + nothing (50 left buys nothing) is
        // kept, 100 alone is not (another 100 fits).
        let b = baskets(&[open(1, 100), open(2, 200)], 250, 9, 0);
        assert!(b.iter().any(|x| x.buys == vec![2]));
        assert!(!b.iter().any(|x| x.buys == vec![1]));
        assert!(b.iter().any(|x| x.buys == vec![1, 1]));
    }

    #[test]
    fn an_unlock_is_paid_once_and_capped() {
        let locked = Offer { id: 3, cost: 100, unlock: Some(50), most: None };
        let b = baskets(&[locked.clone(), Offer { id: 4, cost: 100, unlock: Some(0), most: None }], 300, 2, 1);
        let two = b.iter().find(|x| x.buys == vec![3, 3]).expect("two of the same locked card");
        assert_eq!(two.spent, 250);
        assert_eq!(two.unlocks, vec![3]);
        // Two different locked cards need two unlocks; only one allowed.
        assert!(!b.iter().any(|x| x.buys.contains(&3) && x.buys.contains(&4)));
    }
}
