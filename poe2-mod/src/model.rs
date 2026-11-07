//! What poe2-mod knows about the game, as plain data. The memory
//! readers fill these in; the features (preload alert, loot value, item
//! rules) work on them only, so they are tested without the game.

use serde::{Deserialize, Serialize};

/// Item and monster rarity, in the game's order (GameHelper2
/// RemoteEnums/Rarity.cs: Normal 0, Magic 1, Rare 2, Unique 3, the
/// number in ObjectMagicProperties' Rarity).
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash, Serialize, Deserialize)]
pub enum Rarity {
    Normal,
    Magic,
    Rare,
    Unique,
}

/// One item: on the ground, in the inventory, in a stash tab or a vendor.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Item {
    /// The item's metadata path, such as `Metadata/Items/Currency/CurrencyRerollRare`.
    pub path: String,
    /// The unique's own name; empty for others.
    pub name: String,
    /// The base type, such as `Exalted Orb` or `Gold Ring`.
    pub base: String,
    pub rarity: Option<Rarity>,
    /// Stack size; 1 for items that do not stack.
    pub stack: u32,
    /// Mod text as the game shows it.
    pub mods: Vec<String>,
}

/// One file the game has loaded, from the loaded files list. The game
/// marks each with the area change count it was last used in.
#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct LoadedFile {
    pub path: String,
    pub area_change_count: i32,
}
