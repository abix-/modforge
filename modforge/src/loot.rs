//! Loot tables as data (topside design.md "Loot tables scale with
//! danger", icarus difficulty): the danger of a spot decides both how
//! much it holds and what can be in it. A roadside shack rolls common
//! junk; the gated room of a launch site can roll the rare things.
//! Rolled with the consumer's seeded `Roll`, so a world rolls the same
//! loot every time.

use crate::monument::Roll;

/// One thing a table can give: the item, how many, how likely against
/// the others, and the least danger a spot must have to roll it.
#[derive(Clone, Debug, PartialEq)]
pub struct LootEntry {
    pub item: String,
    pub count: (u32, u32),
    pub weight: u32,
    pub min_danger: u32,
}

/// A loot table: its entries, and how many picks a spot of danger 0
/// makes; every point of danger adds `picks_per_danger` more.
#[derive(Clone, Debug, PartialEq)]
pub struct LootTable {
    pub entries: Vec<LootEntry>,
    pub picks: (u32, u32),
    pub picks_per_danger: u32,
}

/// Roll a spot of `danger` from `table`: (item, count) stacks, only
/// from the entries that danger allows, weighted.
pub fn roll_loot(table: &LootTable, danger: u32, roll: &mut Roll) -> Vec<(String, u32)> {
    let open: Vec<&LootEntry> = table
        .entries
        .iter()
        .filter(|e| e.min_danger <= danger && e.weight > 0)
        .collect();
    let total: u32 = open.iter().map(|e| e.weight).sum();
    if total == 0 {
        return Vec::new();
    }
    let picks = roll.between(table.picks.0, table.picks.1) + table.picks_per_danger * danger;
    let mut out: Vec<(String, u32)> = Vec::new();
    for _ in 0..picks {
        let mut at = roll.next(u64::from(total)) as u32;
        let entry = open
            .iter()
            .find(|e| {
                if at < e.weight {
                    return true;
                }
                at -= e.weight;
                false
            })
            .expect("the weights add up to the total");
        let count = roll.between(entry.count.0, entry.count.1);
        match out.iter_mut().find(|(item, _)| *item == entry.item) {
            Some((_, n)) => *n += count,
            None => out.push((entry.item.clone(), count)),
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    fn table() -> LootTable {
        let e = |item: &str, weight, min_danger| LootEntry {
            item: item.to_string(),
            count: (1, 1),
            weight,
            min_danger,
        };
        LootTable {
            entries: vec![e("scrap", 10, 0), e("rifle", 1, 4)],
            picks: (1, 2),
            picks_per_danger: 1,
        }
    }

    #[test]
    fn a_safe_spot_never_rolls_what_danger_guards() {
        for seed in 0..200 {
            let loot = roll_loot(&table(), 1, &mut Roll::new(seed));
            assert!(loot.iter().all(|(item, _)| item != "rifle"));
        }
    }

    #[test]
    fn danger_gives_more_and_opens_the_rare_things() {
        let count = |danger| -> (u32, bool) {
            let mut n = 0;
            let mut rare = false;
            for seed in 0..200 {
                for (item, c) in roll_loot(&table(), danger, &mut Roll::new(seed)) {
                    n += c;
                    rare |= item == "rifle";
                }
            }
            (n, rare)
        };
        let (safe, _) = count(0);
        let (deep, rare) = count(5);
        assert!(deep > safe, "more at danger 5: {deep} vs {safe}");
        assert!(rare, "the rifle turns up somewhere at danger 5");
        assert_eq!(roll_loot(&table(), 3, &mut Roll::new(9)), roll_loot(&table(), 3, &mut Roll::new(9)), "same seed, same loot");
    }
}
