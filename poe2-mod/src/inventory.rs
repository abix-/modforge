//! The player's inventories (main, gear, flasks, cursor, ...), read
//! the way GameHelper2 does (GameOffsets/Objects/States/InGameState
//! ServerDataOffset.cs and InventoryOffset.cs; RemoteObjects/States
//! InGameStateObjects ServerData.cs and Inventory.cs; RemoteEnums
//! InventoryName.cs).

use anyhow::{Context, Result, ensure};
use modforge::msvc_std::read_vector;
use modforge::process_memory::ProcessMemory;
use serde::Serialize;

/// AreaInstanceOffsets.PlayerInfo.ServerDataPtr (PlayerInfo + 0),
/// PlayerInfo at 0x5B8 on the build of 2026-11-06 (GameHelper2 0x5B0).
pub const AREA_SERVER_DATA: u64 = 0x5B8;
/// ServerDataOffsets.PlayerServerDataPtr: a vector whose first entry is
/// the player's server data.
pub const SERVER_PLAYER_DATA: u64 = 0x48;
/// ServerDataStructure.PlayerInventories: a vector of [`InventoryEntry`].
pub const PLAYER_INVENTORIES: u64 = 0x320;
/// InventoryStruct.TotalBoxes (two ints) and ItemList (a vector of
/// pointers, one per box; empty boxes are 0, a big item fills several).
pub const INVENTORY_BOXES: u64 = 0x150;
pub const INVENTORY_ITEMS: u64 = 0x170;

/// GameHelper2 RemoteEnums/InventoryName.cs, by id.
pub const NAMES: &[&str] = &[
    "NoInvSelected",
    "MainInventory1",
    "BodyArmour1",
    "Weapon1",
    "Offhand1",
    "Helm1",
    "Amulet1",
    "Ring1",
    "Ring2",
    "Gloves1",
    "Boots1",
    "Belt1",
    "Flask1",
    "Cursor1",
    "Map1",
    "Weapon2",
    "Offhand2",
    "Expedition2Crafting",
    "StrDexMasterCrafting",
    "DexMasterCrafting",
    "DexIntMasterCrafting",
    "IntMasterCrafting",
    "VerisiumCraftingInput",
    "VerisiumCraftingOutput",
    "PassiveJewels1",
    "AnimatedArmour1",
    "GuildTag1",
    "StashInventoryId",
];

pub fn name(id: i32) -> String {
    usize::try_from(id)
        .ok()
        .and_then(|i| NAMES.get(i))
        .map_or_else(|| format!("Inventory{id}"), |n| n.to_string())
}

/// InventoryArrayStruct.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct InventoryEntry {
    id: i32,
    _pad: i32,
    inventory: u64,
    _inventory_less_0x10: u64,
}

/// InventoryItemStruct.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct InventoryItem {
    item: u64,
    slot_start: [i32; 2],
    slot_end: [i32; 2],
}

/// One item in an inventory: its entity and the boxes it covers.
#[derive(Clone, Copy, Debug, PartialEq, Serialize)]
pub struct Placed {
    pub item: u64,
    pub start: [i32; 2],
    pub end: [i32; 2],
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Inventory {
    pub id: i32,
    pub name: String,
    pub address: u64,
    pub boxes: [i32; 2],
    pub items: Vec<Placed>,
}

/// Every inventory the player has, without their items.
pub fn list(mem: &ProcessMemory, area_instance: u64) -> Result<Vec<(i32, u64)>> {
    let server: u64 = mem
        .read_value(area_instance + AREA_SERVER_DATA)
        .context("read server data pointer")?;
    ensure!(server != 0, "no server data");
    let players: Vec<u64> =
        read_vector(mem, server + SERVER_PLAYER_DATA).context("read player data list")?;
    let player = *players.first().context("player data list is empty")?;
    let entries: Vec<InventoryEntry> =
        read_vector(mem, player + PLAYER_INVENTORIES).context("read inventory list")?;
    Ok(entries.into_iter().map(|e| (e.id, e.inventory)).collect())
}

/// The inventory at `at` and its items, each once even when it covers
/// several boxes.
pub fn read(mem: &ProcessMemory, id: i32, at: u64) -> Result<Inventory> {
    let boxes: [i32; 2] = mem
        .read_value(at + INVENTORY_BOXES)
        .with_context(|| format!("read inventory size at {at:#x}"))?;
    let slots: Vec<u64> = read_vector(mem, at + INVENTORY_ITEMS).context("read inventory slots")?;
    let mut seen = std::collections::HashSet::new();
    let mut items = Vec::new();
    for slot in slots {
        if slot == 0 || !seen.insert(slot) {
            continue;
        }
        let Ok(entry) = mem.read_value::<InventoryItem>(slot) else {
            continue;
        };
        if entry.item != 0 {
            items.push(Placed {
                item: entry.item,
                start: entry.slot_start,
                end: entry.slot_end,
            });
        }
    }
    Ok(Inventory {
        id,
        name: name(id),
        address: at,
        boxes,
        items,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;
    use modforge::msvc_std::Vector;

    fn vector_of<T>(items: &[T]) -> Vector {
        let first = items.as_ptr() as u64;
        let last = first + size_of_val(items) as u64;
        Vector {
            first,
            last,
            end: last,
        }
    }

    #[test]
    fn names_by_id() {
        assert_eq!(name(1), "MainInventory1");
        assert_eq!(name(12), "Flask1");
        assert_eq!(name(99), "Inventory99");
    }

    #[test]
    fn reads_inventories_and_items_once() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        // Two items: one covering two boxes.
        let big = InventoryItem {
            item: 0xA000,
            slot_start: [0, 0],
            slot_end: [1, 2],
        };
        let small = InventoryItem {
            item: 0xB000,
            slot_start: [2, 0],
            slot_end: [3, 1],
        };
        let slots = [
            &big as *const _ as u64,
            &big as *const _ as u64,
            &small as *const _ as u64,
            0,
        ];
        let mut inventory = [0u8; 0x188];
        put(&mut inventory[..], 0x150, [12i32, 5]);
        put(&mut inventory[..], 0x170, vector_of(&slots));
        let entries = [InventoryEntry {
            id: 1,
            _pad: 0,
            inventory: inventory.as_ptr() as u64,
            _inventory_less_0x10: 0,
        }];
        let mut player = [0u8; 0x338];
        put(&mut player[..], 0x320, vector_of(&entries));
        let players = [player.as_ptr() as u64];
        let mut server = [0u8; 0x60];
        put(&mut server[..], 0x48, vector_of(&players));
        let mut area = [0u8; AREA_SERVER_DATA as usize + 8];
        put(&mut area[..], AREA_SERVER_DATA as usize, server.as_ptr() as u64);

        let found = list(&mem, area.as_ptr() as u64).unwrap();
        assert_eq!(found, [(1, inventory.as_ptr() as u64)]);
        let inv = read(&mem, 1, found[0].1).unwrap();
        assert_eq!(inv.name, "MainInventory1");
        assert_eq!(inv.boxes, [12, 5]);
        assert_eq!(
            inv.items,
            [
                Placed {
                    item: 0xA000,
                    start: [0, 0],
                    end: [1, 2]
                },
                Placed {
                    item: 0xB000,
                    start: [2, 0],
                    end: [3, 1]
                },
            ]
        );
    }
}
