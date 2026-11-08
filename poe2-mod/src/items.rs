//! Items, read the way GameHelper2 does (GameOffsets/Objects/Components
//! Base.cs, ModsAndObjectMagicProperties.cs, Stack.cs, RenderItem in
//! Render.cs, WorldItem.cs; RemoteObjects/Components Base.cs, Mods.cs,
//! ObjectMagicProperties.cs, RenderItem.cs).
//!
//! An item is an entity like a monster, with item parts. On the ground
//! it sits inside a world item entity's WorldItem part.

use crate::entities::read_parts;
use crate::loot_value::file_basename;
use crate::model::Item;
use anyhow::{Context, Result};
use modforge::msvc_std::{Vector, read_vector_header};
use modforge::process_memory::ProcessMemory;

/// BaseOffsets.DisplayNameRowPtr; the name row holds a pointer to the
/// display name at [`BASE_DISPLAY_NAME`] (BaseOffsets.DisplayNameOffset).
pub const BASE_DISPLAY_NAME_ROW: u64 = 0x10;
pub const BASE_DISPLAY_NAME: u64 = 0x30;
/// ModsOffsets.Details0 at 0: Rarity, then the five mod vectors
/// (implicit, explicit, enchant, hellscape, crucible).
pub const MODS_RARITY: u64 = 0x94;
pub const MODS_VECTORS: u64 = 0xA0;
pub const MODS_VECTOR_COUNT: u64 = 5;
/// ModArrayStruct: 0x40 bytes, the Mods.dat row pointer at 0x28; the
/// row starts with a pointer to the mod's id.
pub const MOD_ENTRY_SIZE: u64 = 0x40;
pub const MOD_ENTRY_ROW: u64 = 0x28;
/// StackOffsets.Count.
pub const STACK_COUNT: u64 = 0x18;
/// RenderItemOffsets.ResourcePathPtr.
pub const RENDER_ITEM_PATH: u64 = 0x28;
/// WorldItemOffsets.ItemEntityPtr.
pub const WORLD_ITEM_ENTITY: u64 = 0x28;
/// GameHelper2 ReadUnicodeString reads 256 bytes.
const TEXT_UNITS: usize = 128;

fn wide_at_pointer(mem: &ProcessMemory, at: u64) -> Result<String> {
    let p: u64 = mem
        .read_value(at)
        .with_context(|| format!("read text pointer at {at:#x}"))?;
    anyhow::ensure!(p != 0, "text pointer at {at:#x} is null");
    Ok(mem.read_wide_cstr(p, TEXT_UNITS)?)
}

/// Every mod id in the five mod vectors of the mods data at `mods`
/// (the Mods part, or ObjectMagicProperties' second copy at 0xB0).
pub fn read_mod_ids(mem: &ProcessMemory, mods: u64) -> Vec<String> {
    let mut ids = Vec::new();
    for v in 0..MODS_VECTOR_COUNT {
        let Ok(vector): Result<Vector> = read_vector_header(mem, mods + MODS_VECTORS + v * 0x18)
        else {
            continue;
        };
        for i in 0..vector.len(MOD_ENTRY_SIZE) {
            let entry = vector.at(i, MOD_ENTRY_SIZE);
            let Ok(row) = mem.read_value::<u64>(entry + MOD_ENTRY_ROW) else {
                continue;
            };
            if row == 0 {
                continue;
            }
            if let Ok(id) = wide_at_pointer(mem, row) {
                ids.push(id);
            }
        }
    }
    ids
}

/// The item entity at `at`. A part it lacks leaves that field empty;
/// a unique's own name is not in memory, so `name` stays empty and
/// loot value finds it from `art`.
pub fn read(mem: &ProcessMemory, at: u64) -> Result<Item> {
    let (path, parts) = read_parts(mem, at)?;
    let get = |name: &str| parts.get(name).copied();
    let base = get("Base")
        .and_then(|p| mem.read_value::<u64>(p + BASE_DISPLAY_NAME_ROW).ok())
        .filter(|row| *row != 0)
        .and_then(|row| wide_at_pointer(mem, row + BASE_DISPLAY_NAME).ok())
        .unwrap_or_default();
    let rarity = get("Mods")
        .and_then(|p| mem.read_value::<i32>(p + MODS_RARITY).ok())
        .and_then(crate::entities::rarity);
    let mods = get("Mods")
        .map(|p| read_mod_ids(mem, p))
        .unwrap_or_default();
    let stack = get("Stack")
        .and_then(|p| mem.read_value::<i32>(p + STACK_COUNT).ok())
        .and_then(|n| u32::try_from(n).ok())
        .filter(|n| *n > 0)
        .unwrap_or(1);
    let art = get("RenderItem")
        .and_then(|p| wide_at_pointer(mem, p + RENDER_ITEM_PATH).ok())
        .map(|path| file_basename(&path).to_string())
        .unwrap_or_default();
    Ok(Item {
        path,
        name: String::new(),
        base,
        rarity,
        stack,
        mods,
        art,
    })
}

/// The item inside a ground item entity, if `parts` has a WorldItem.
pub fn on_ground(mem: &ProcessMemory, world_item_part: u64) -> Result<Item> {
    let item: u64 = mem
        .read_value(world_item_part + WORLD_ITEM_ENTITY)
        .context("read ground item's item pointer")?;
    anyhow::ensure!(item != 0, "ground item has no item");
    read(mem, item)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::{FakeEntity, fake_entity, put};
    use crate::model::Rarity;

    fn wide(text: &str) -> Vec<u16> {
        let mut v: Vec<u16> = text.encode_utf16().collect();
        v.resize(TEXT_UNITS, 0);
        v
    }

    struct FakeItem {
        entity: FakeEntity,
        _keep: Vec<Box<[u8]>>,
        _text: Vec<Vec<u16>>,
    }

    fn fake_item() -> FakeItem {
        let text = vec![
            wide("Gold Ring"),
            wide("IncreasedLife3"),
            wide("FireResist2"),
            wide("Art/2DItems/Rings/GoldRing.dds"),
        ];
        let ptr = |i: usize| text[i].as_ptr() as u64;
        // The display name row: a pointer to the name at 0x30.
        let mut name_row = vec![0u8; 0x38].into_boxed_slice();
        put(&mut name_row, 0x30, ptr(0));
        let mut base = vec![0u8; 0x20].into_boxed_slice();
        put(&mut base, 0x10, name_row.as_ptr() as u64);
        // Two Mods.dat rows, each starting with a pointer to its id.
        let mut row_a = vec![0u8; 8].into_boxed_slice();
        put(&mut row_a, 0, ptr(1));
        let mut row_b = vec![0u8; 8].into_boxed_slice();
        put(&mut row_b, 0, ptr(2));
        let mut entries = vec![0u8; 0x80].into_boxed_slice();
        put(&mut entries, 0x28, row_a.as_ptr() as u64);
        put(&mut entries, 0x40 + 0x28, row_b.as_ptr() as u64);
        let first = entries.as_ptr() as u64;
        let mut mods = vec![0u8; 0xA0 + 5 * 0x18].into_boxed_slice();
        put(&mut mods, 0x94, 2i32);
        // Explicit mods: the second vector.
        put(
            &mut mods,
            0xA0 + 0x18,
            Vector {
                first,
                last: first + 0x80,
                end: first + 0x80,
            },
        );
        let mut stack = vec![0u8; 0x20].into_boxed_slice();
        put(&mut stack, 0x18, 1i32);
        let mut render_item = vec![0u8; 0x30].into_boxed_slice();
        put(&mut render_item, 0x28, ptr(3));
        let entity = fake_entity(
            "Metadata/Items/Rings/Ring1",
            &[
                ("Base", base.as_ptr() as u64),
                ("Mods", mods.as_ptr() as u64),
                ("Stack", stack.as_ptr() as u64),
                ("RenderItem", render_item.as_ptr() as u64),
            ],
        );
        FakeItem {
            entity,
            _keep: vec![
                name_row,
                base,
                row_a,
                row_b,
                entries,
                mods,
                stack,
                render_item,
            ],
            _text: text,
        }
    }

    #[test]
    fn reads_an_item_and_its_parts() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let fake = fake_item();
        let item = read(&mem, fake.entity.address()).unwrap();
        assert_eq!(
            item,
            Item {
                path: "Metadata/Items/Rings/Ring1".into(),
                name: String::new(),
                base: "Gold Ring".into(),
                rarity: Some(Rarity::Rare),
                stack: 1,
                mods: vec!["IncreasedLife3".into(), "FireResist2".into()],
                art: "GoldRing".into(),
            }
        );
    }

    #[test]
    fn ground_item_points_at_its_item() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let fake = fake_item();
        let mut world_item = [0u8; 0x30];
        put(&mut world_item, 0x28, fake.entity.address());
        let item = on_ground(&mem, world_item.as_ptr() as u64).unwrap();
        assert_eq!(item.base, "Gold Ring");
        world_item = [0; 0x30];
        assert!(on_ground(&mem, world_item.as_ptr() as u64).is_err());
    }
}
