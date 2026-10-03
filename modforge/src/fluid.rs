//! Water is a fluid (topside design.md "Water is a fluid"; Project
//! Zomboid's fluid containers, Obenseuer's water): an amount in litres,
//! held in containers up to their size (`ItemDef::holds_litres`, the
//! litres in a stack `ItemStack::litres`). Anyone fills a container at a
//! source, pours from one container into another, and drinks from a
//! container; every one of these moves litres the one way, `transfer`.

use crate::item::{Inventory, ItemRegistry, ItemStack};

/// What a litre drunk is worth to thirst (operator, 2026-10-03).
pub const THIRST_PER_LITRE: f32 = 100.0;

/// How much one drink takes, in litres (Claude's number, for the operator
/// to change).
pub const MOUTHFUL: f32 = 0.25;

/// Moves water from `from` into `to`: as much as `from` holds, as `to` has
/// room for (`room`), and at most `most`. Answers the litres moved. The
/// one way water moves; a source that never runs dry passes
/// `f32::INFINITY` as what it holds.
pub fn transfer(from: &mut f32, to: &mut f32, room: f32, most: f32) -> f32 {
    let moved = from.min(room.max(0.0)).min(most).max(0.0);
    if moved.is_finite() {
        *from -= moved;
        *to += moved;
        moved
    } else {
        0.0
    }
}

/// The room left in a container stack: its size less what it holds; none
/// for a stack that is not a container.
pub fn room(stack: &ItemStack, items: &ItemRegistry) -> f32 {
    items.def(&stack.item).and_then(|d| d.holds_litres).map_or(0.0, |size| (size - stack.litres).max(0.0))
}

/// Fills a container at a source: up to its size, from what the source
/// holds (`from`: a store's water for a source drawn from it, or
/// `f32::INFINITY` for one that never runs dry). Answers the litres taken.
pub fn fill(to: &mut ItemStack, from: &mut f32, items: &ItemRegistry) -> f32 {
    let room = room(to, items);
    transfer(from, &mut to.litres, room, f32::INFINITY)
}

/// Pours one container into another, as much as the one poured into has
/// room for. Answers the litres poured.
pub fn pour(from: &mut ItemStack, to: &mut ItemStack, items: &ItemRegistry) -> f32 {
    let room = room(to, items);
    transfer(&mut from.litres, &mut to.litres, room, f32::INFINITY)
}

/// One drink from what holds water (a container's litres, a store's): a
/// mouthful, or what is left. Answers the litres drunk (the drinker's
/// thirst takes them through `SurvivalStats::drink`).
pub fn drink(from: &mut f32) -> f32 {
    let mut drunk = 0.0;
    transfer(from, &mut drunk, f32::INFINITY, MOUTHFUL)
}

/// Every litre an inventory's containers hold.
pub fn litres_in(held: &Inventory) -> f32 {
    held.slots.iter().flatten().map(|s| s.litres * s.count as f32).sum()
}

/// The room in an inventory's containers, in litres.
pub fn room_in(held: &Inventory, items: &ItemRegistry) -> f32 {
    held.slots.iter().flatten().map(|s| room(s, items) * s.count as f32).sum()
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::item::{ItemDef, ItemKind};

    fn items() -> ItemRegistry {
        let mut items = ItemRegistry::default();
        let container = |name: &str, size: f32| ItemDef {
            name: name.to_string(),
            description: String::new(),
            unique: false,
            kind: ItemKind::Container,
            max_stack: 1,
            quality_siblings: 1,
            combat: None,
            food: None,
            storage: None,
            armor: None,
            good_for: Default::default(),
            picture: None,
            layer_slots: Vec::new(),
            breaks_when_struck: false,
            holds_litres: Some(size),
        };
        items.register(container("5 L water bottle", 5.0)).unwrap();
        items.register(container("water barrel", 200.0)).unwrap();
        items
    }

    fn stack(item: &str, litres: f32) -> ItemStack {
        ItemStack { item: item.to_string(), count: 1, quality: None, note: None, layers: Vec::new(), litres }
    }

    /// Filled at a river, a bottle takes its size; at a source drawn from
    /// a store, no more than the store holds, and the store loses it.
    #[test]
    fn filling_takes_up_to_the_size_and_from_the_store() {
        let items = items();
        let mut bottle = stack("5 L water bottle", 1.0);
        let mut river = f32::INFINITY;
        assert_eq!(fill(&mut bottle, &mut river, &items), 4.0);
        assert_eq!(bottle.litres, 5.0);
        assert!(river.is_infinite(), "a river never runs dry");
        let mut empty = stack("5 L water bottle", 0.0);
        let mut store = 3.0;
        assert_eq!(fill(&mut empty, &mut store, &items), 3.0, "the store's 3 L, not 5");
        assert_eq!((empty.litres, store), (3.0, 0.0));
        assert_eq!(fill(&mut empty, &mut store, &items), 0.0, "a dry store gives nothing");
    }

    /// Poured into the barrel, a bottle empties into it, never past its
    /// size.
    #[test]
    fn pouring_moves_what_fits() {
        let items = items();
        let mut bottle = stack("5 L water bottle", 5.0);
        let mut barrel = stack("water barrel", 10.0);
        assert_eq!(pour(&mut bottle, &mut barrel, &items), 5.0);
        assert_eq!((bottle.litres, barrel.litres), (0.0, 15.0));
        let mut full = stack("water barrel", 198.0);
        let mut another = stack("5 L water bottle", 5.0);
        assert_eq!(pour(&mut another, &mut full, &items), 2.0, "room for 2 L");
        assert_eq!((another.litres, full.litres), (3.0, 200.0));
    }

    /// A drink is a mouthful, or what is left; litres are counted across
    /// an inventory's containers.
    #[test]
    fn drinking_takes_a_mouthful_and_litres_are_counted() {
        let items = items();
        let mut held = 0.3;
        assert_eq!(drink(&mut held), MOUTHFUL);
        assert!((drink(&mut held) - 0.05).abs() < 1e-6, "what is left");
        assert_eq!(drink(&mut held), 0.0);
        let mut inventory = Inventory::new(4);
        inventory.slots[0] = Some(stack("5 L water bottle", 2.0));
        inventory.slots[2] = Some(stack("water barrel", 10.0));
        assert_eq!(litres_in(&inventory), 12.0);
        assert_eq!(room_in(&inventory, &items), 3.0 + 190.0);
        // A mouthful drunk fills thirst at THIRST_PER_LITRE a litre.
        let mut stats = crate::survival::SurvivalStats { thirst: 10.0, ..Default::default() };
        stats.drink(MOUTHFUL);
        assert_eq!(stats.thirst, 10.0 + MOUTHFUL * THIRST_PER_LITRE);
    }
}
