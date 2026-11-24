//! Trash (topside-town "Everything works": "trash cans, the dump, septic
//! and sewage"; Project Zomboid's bins and dumpsters): what is put in a
//! trash can is taken to the dump once a day, at the collection hour,
//! and found there, to be scavenged. Engine-free; the game says where
//! the cans and the dump are.

use crate::item::{Inventory, ItemStack};

/// Whether the truck comes now: `today` the game day (whole days and the
/// part of one), once a day from `hour`, `last` the day it last came.
pub fn due(today: f32, hour: f32, last: u32) -> bool {
    let day = today.floor().max(0.0) as u32;
    day > last && today.fract() * 24.0 >= hour
}

/// One can emptied into the dump's pile: what does not fit stays in the
/// can.
pub fn collect(can: &mut Inventory, pile: &mut Inventory, max_stack: impl Fn(&str) -> u32) {
    let taken: Vec<ItemStack> = can.drain_all();
    for stack in taken {
        let most = max_stack(&stack.item);
        if let Some(left) = pile.add(stack, most) {
            let _ = can.add(left, most);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn stack(name: &str, count: u32) -> ItemStack {
        ItemStack {
            item: name.to_string(),
            count,
            quality: None,
            note: None,
            layers: Vec::new(),
            litres: 0.0,
            affixes: Vec::new(),
            made_day: 0.0,
        }
    }

    #[test]
    fn the_truck_comes_once_a_day_at_its_hour() {
        assert!(!due(1.1, 6.0, 0));
        assert!(due(1.3, 6.0, 0));
        assert!(!due(1.5, 6.0, 1));
    }

    #[test]
    fn a_can_is_emptied_into_the_pile() {
        let mut can = Inventory::new(2);
        let _ = can.add(stack("scrap", 3), 20);
        let mut pile = Inventory::new(4);
        collect(&mut can, &mut pile, |_| 20);
        assert_eq!(can.count_of("scrap"), 0);
        assert_eq!(pile.count_of("scrap"), 3);
    }
}
