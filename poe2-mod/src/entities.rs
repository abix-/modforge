//! Entities in the zone and their parts (components), read the way
//! GameHelper2 does (GameOffsets/Objects/States/InGameState
//! EntityOffsets.cs and AreaInstanceOffsets.cs, GameOffsets/Objects
//! Components, RemoteObjects/States/InGameStateObjects Entity.cs and
//! AreaInstance.cs).
//!
//! An entity has a details object (its path and a lookup from part
//! name to index) and a vector of part addresses. The area instance
//! keeps two std::maps of entities: awake (near the player) and
//! sleeping (further away).

use anyhow::{Context, Result, ensure};
use modforge::msvc_std::{map_entries, read_bucket, read_vector, read_wstring};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::BTreeMap;

use crate::model::Rarity;

/// AreaInstanceOffsets.Entities: AwakeEntities then SleepingEntities,
/// each a std::map (0x10 bytes).
pub const AREA_AWAKE_ENTITIES: u64 = 0x6F0;
pub const AREA_SLEEPING_ENTITIES: u64 = 0x700;
/// AreaInstanceOffsets.PlayerInfo.LocalPlayerPtr (0x5B0 + 0x20).
pub const AREA_LOCAL_PLAYER: u64 = 0x5D0;
/// GameHelper2 AreaInstance reads at most this many awake entities, and
/// this many sleeping ones.
pub const MAX_AWAKE: usize = 100_000;
pub const MAX_SLEEPING: usize = 500_000;
/// Entity.MaxComponentsInAnEntity.
pub const MAX_PARTS: i32 = 50;

/// EntityOffsets and ItemStruct.
pub mod entity {
    pub const DETAILS: u64 = 0x08;
    pub const PARTS: u64 = 0x10;
    pub const ID: u64 = 0x88;
    /// 0x0C is valid, 0x03 invalid: valid when bit 0 is clear.
    pub const VALID: u64 = 0x8C;
}
/// EntityDetails and ComponentLookUpStruct.
pub mod details {
    pub const PATH: u64 = 0x08;
    pub const LOOKUP: u64 = 0x28;
    /// The lookup's bucket of (name pointer, index) pairs.
    pub const LOOKUP_NAMES: u64 = 0x28;
    /// StdBucket.Capacity inside that bucket.
    pub const LOOKUP_CAPACITY: u64 = LOOKUP_NAMES + 0x20;
}
/// Part layouts (GameOffsets/Objects/Components).
pub mod part {
    pub const LIFE_HEALTH: u64 = 0x1B0;
    pub const LIFE_MANA: u64 = 0x208;
    pub const LIFE_ENERGY_SHIELD: u64 = 0x248;
    /// VitalStruct fields.
    pub const VITAL_RESERVED_FLAT: u64 = 0x10;
    pub const VITAL_RESERVED_PERCENT: u64 = 0x14;
    pub const VITAL_REGEN: u64 = 0x28;
    pub const VITAL_TOTAL: u64 = 0x2C;
    pub const VITAL_CURRENT: u64 = 0x30;
    pub const POSITIONED_REACTION: u64 = 0x1E0;
    pub const RENDER_WORLD_POSITION: u64 = 0x138;
    pub const CHEST_IS_OPENED: u64 = 0x168;
    pub const SHRINE_IS_USED: u64 = 0x24;
    pub const TARGETABLE_IS_TARGETABLE: u64 = 0x51;
    pub const PLAYER_NAME: u64 = 0x1B0;
    pub const PLAYER_XP: u64 = 0x1D8;
    pub const PLAYER_LEVEL: u64 = 0x204;
    /// ObjectMagicPropertiesOffsets.Details1 (0xB0), then
    /// ModsAndObjectMagicProperties.Rarity (0x94). On items the Mods
    /// part has the same details at 0, see [`crate::items`].
    pub const MAGIC_PROPERTIES_DETAILS: u64 = 0xB0;
    pub const MAGIC_PROPERTIES_RARITY: u64 = MAGIC_PROPERTIES_DETAILS + 0x94;
}

/// GameHelper2 ReadString reads 128 bytes.
const PART_NAME_BYTES: usize = 128;

/// GameHelper2 EntityHelper.IsValidEntity.
pub fn is_valid(flags: u8) -> bool {
    flags & 1 == 0
}

/// GameHelper2 EntityHelper.IsFriendly, on Positioned's Reaction.
pub fn is_friendly(reaction: u8) -> bool {
    reaction & 0x7F == 0x01
}

/// GameHelper2 RemoteEnums/Rarity.cs: Normal 0, Magic 1, Rare 2, Unique 3.
pub fn rarity(value: i32) -> Option<Rarity> {
    match value {
        0 => Some(Rarity::Normal),
        1 => Some(Rarity::Magic),
        2 => Some(Rarity::Rare),
        3 => Some(Rarity::Unique),
        _ => None,
    }
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize)]
pub struct Vital {
    pub current: i32,
    pub total: i32,
    pub reserved_flat: i32,
    pub reserved_percent: i32,
    pub regen: f32,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize)]
pub struct Life {
    pub health: Vital,
    pub mana: Vital,
    pub energy_shield: Vital,
}

#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct PlayerPart {
    pub name: String,
    pub level: u8,
    pub xp: i32,
}

/// One entity and the parts the features use. A part the entity does
/// not have is `None`.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Entity {
    pub address: u64,
    pub id: u32,
    pub valid: bool,
    pub path: String,
    /// Every part's name and address.
    #[serde(skip)]
    pub parts: BTreeMap<String, u64>,
    pub life: Option<Life>,
    pub position: Option<[f32; 3]>,
    pub friendly: Option<bool>,
    pub rarity: Option<Rarity>,
    pub chest_opened: Option<bool>,
    pub shrine_used: Option<bool>,
    pub targetable: Option<bool>,
    pub player: Option<PlayerPart>,
}

#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct PartName {
    name: u64,
    index: i32,
    _pad: i32,
}

/// The entity's path and its parts by name (GameHelper2
/// Entity.UpdateComponentData). An empty path or more than
/// [`MAX_PARTS`] parts means it is not an entity.
pub fn read_parts(mem: &ProcessMemory, at: u64) -> Result<(String, BTreeMap<String, u64>)> {
    let details: u64 = mem
        .read_value(at + entity::DETAILS)
        .with_context(|| format!("read entity details pointer at {at:#x}"))?;
    let path = read_wstring(mem, details + details::PATH).context("read entity path")?;
    ensure!(!path.is_empty(), "entity at {at:#x} has no path");
    let lookup: u64 = mem
        .read_value(details + details::LOOKUP)
        .context("read part lookup pointer")?;
    let capacity: i32 = mem
        .read_value(lookup + details::LOOKUP_CAPACITY)
        .context("read part count")?;
    ensure!(
        capacity <= MAX_PARTS,
        "entity at {at:#x} claims {capacity} parts"
    );
    let names: Vec<PartName> =
        read_bucket(mem, lookup + details::LOOKUP_NAMES).context("read part names")?;
    let addresses: Vec<u64> = read_vector(mem, at + entity::PARTS).context("read part list")?;
    let mut parts = BTreeMap::new();
    for n in names {
        let Some(address) = usize::try_from(n.index).ok().and_then(|i| addresses.get(i)) else {
            continue;
        };
        if let Ok(name) = mem.read_cstr(n.name, PART_NAME_BYTES)
            && !name.is_empty()
        {
            parts.insert(name, *address);
        }
    }
    Ok((path, parts))
}

fn read_vital(mem: &ProcessMemory, at: u64) -> Result<Vital> {
    Ok(Vital {
        current: mem.read_value(at + part::VITAL_CURRENT)?,
        total: mem.read_value(at + part::VITAL_TOTAL)?,
        reserved_flat: mem.read_value(at + part::VITAL_RESERVED_FLAT)?,
        reserved_percent: mem.read_value(at + part::VITAL_RESERVED_PERCENT)?,
        regen: mem.read_value(at + part::VITAL_REGEN)?,
    })
}

fn flag(mem: &ProcessMemory, at: u64) -> Option<bool> {
    mem.read_value::<u8>(at).ok().map(|b| b != 0)
}

/// The entity at `at`, with every part the features use that it has.
/// A part that cannot be read stays `None`.
pub fn read(mem: &ProcessMemory, at: u64) -> Result<Entity> {
    let (path, parts) = read_parts(mem, at)?;
    let id: u32 = mem.read_value(at + entity::ID).context("read entity id")?;
    let flags: u8 = mem
        .read_value(at + entity::VALID)
        .context("read entity valid flag")?;
    let get = |name: &str| parts.get(name).copied();
    let life = get("Life").and_then(|p| {
        Some(Life {
            health: read_vital(mem, p + part::LIFE_HEALTH).ok()?,
            mana: read_vital(mem, p + part::LIFE_MANA).ok()?,
            energy_shield: read_vital(mem, p + part::LIFE_ENERGY_SHIELD).ok()?,
        })
    });
    let position = get("Render").and_then(|p| mem.read_value(p + part::RENDER_WORLD_POSITION).ok());
    let friendly = get("Positioned")
        .and_then(|p| mem.read_value::<u8>(p + part::POSITIONED_REACTION).ok())
        .map(is_friendly);
    let rarity = get("ObjectMagicProperties")
        .and_then(|p| {
            mem.read_value::<i32>(p + part::MAGIC_PROPERTIES_RARITY)
                .ok()
        })
        .and_then(rarity);
    let player = get("Player").and_then(|p| {
        Some(PlayerPart {
            name: read_wstring(mem, p + part::PLAYER_NAME).ok()?,
            level: mem.read_value(p + part::PLAYER_LEVEL).ok()?,
            xp: mem.read_value(p + part::PLAYER_XP).ok()?,
        })
    });
    Ok(Entity {
        address: at,
        id,
        valid: is_valid(flags),
        chest_opened: get("Chest").and_then(|p| flag(mem, p + part::CHEST_IS_OPENED)),
        shrine_used: get("Shrine").and_then(|p| flag(mem, p + part::SHRINE_IS_USED)),
        targetable: get("Targetable").and_then(|p| flag(mem, p + part::TARGETABLE_IS_TARGETABLE)),
        path,
        parts,
        life,
        position,
        friendly,
        rarity,
        player,
    })
}

/// EntityNodeKey: the id and padding, before the entity pointer.
const ENTITY_KEY_SIZE: u64 = 8;

/// The entity addresses in one of the area's entity maps.
pub fn map_addresses(mem: &ProcessMemory, map: u64, max: usize) -> Result<Vec<u64>> {
    let entries = map_entries(mem, map, max)?;
    Ok(entries
        .into_iter()
        .filter_map(|data| mem.read_value::<u64>(data + ENTITY_KEY_SIZE).ok())
        .filter(|p| *p != 0)
        .collect())
}

/// The local player's entity address.
pub fn local_player(mem: &ProcessMemory, area_instance: u64) -> Result<u64> {
    let p: u64 = mem
        .read_value(area_instance + AREA_LOCAL_PLAYER)
        .context("read local player pointer")?;
    ensure!(p != 0, "no local player");
    Ok(p)
}

#[cfg(test)]
pub(crate) mod tests {
    use super::*;
    use modforge::msvc_std::Vector;

    #[test]
    fn flags_like_gamehelper2() {
        assert!(is_valid(0x0C));
        assert!(!is_valid(0x03));
        assert!(is_friendly(0x01));
        assert!(is_friendly(0x81));
        assert!(!is_friendly(0x02));
        assert_eq!(rarity(2), Some(Rarity::Rare));
        assert_eq!(rarity(9), None);
    }

    /// Memory laid out like one entity: the entity, its details, the
    /// part lookup with names, and the part address list. The parts
    /// themselves belong to the caller.
    pub(crate) struct FakeEntity {
        entity: Box<[u8; 0x90]>,
        _details: Box<[u8; 0x30]>,
        lookup: Box<[u8; 0x50]>,
        _names: Vec<PartName>,
        _name_text: Vec<Vec<u8>>,
        _parts: Vec<u64>,
        _path: Vec<u16>,
    }

    impl FakeEntity {
        pub(crate) fn address(&self) -> u64 {
            self.entity.as_ptr() as u64
        }
    }

    pub(crate) fn fake_entity(path: &str, parts: &[(&str, u64)]) -> FakeEntity {
        let path: Vec<u16> = path.encode_utf16().collect();
        let name_text: Vec<Vec<u8>> = parts
            .iter()
            .map(|(n, _)| {
                let mut t = n.as_bytes().to_vec();
                t.resize(PART_NAME_BYTES, 0);
                t
            })
            .collect();
        let addresses: Vec<u64> = parts.iter().map(|(_, a)| *a).collect();
        let names: Vec<PartName> = name_text
            .iter()
            .enumerate()
            .map(|(i, t)| PartName {
                name: t.as_ptr() as u64,
                index: i as i32,
                _pad: 0,
            })
            .collect();
        let vector = |first: u64, bytes: usize| Vector {
            first,
            last: first + bytes as u64,
            end: first + bytes as u64,
        };
        let mut lookup = Box::new([0u8; 0x50]);
        put(
            &mut lookup[..],
            0x28,
            vector(names.as_ptr() as u64, names.len() * size_of::<PartName>()),
        );
        put(&mut lookup[..], 0x48, names.len() as i32);
        let mut details = Box::new([0u8; 0x30]);
        put(&mut details[..], 0x08, path.as_ptr() as u64);
        put(&mut details[..], 0x18, path.len() as i64);
        put(&mut details[..], 0x20, 31i64);
        put(&mut details[..], 0x28, lookup.as_ptr() as u64);
        let mut entity = Box::new([0u8; 0x90]);
        put(&mut entity[..], 0x08, details.as_ptr() as u64);
        put(
            &mut entity[..],
            0x10,
            vector(addresses.as_ptr() as u64, addresses.len() * 8),
        );
        put(&mut entity[..], 0x88, 77u32);
        entity[0x8C] = 0x0C;
        FakeEntity {
            entity,
            _details: details,
            lookup,
            _names: names,
            _name_text: name_text,
            _parts: addresses,
            _path: path,
        }
    }

    /// A monster: the fake entity and its parts' memory.
    struct Monster {
        entity: FakeEntity,
        life: Box<[u8; 0x280]>,
        _render: Box<[u8; 0x150]>,
        _positioned: Box<[u8; 0x1E8]>,
        _magic: Box<[u8; 0x148]>,
    }

    pub(crate) fn put<T: Copy>(buf: &mut [u8], at: usize, value: T) {
        // SAFETY: test only; T is plain data and fits at `at`.
        let bytes = unsafe {
            std::slice::from_raw_parts((&value as *const T).cast::<u8>(), size_of::<T>())
        };
        buf[at..at + bytes.len()].copy_from_slice(bytes);
    }

    fn fake_monster() -> Monster {
        let mut life = Box::new([0u8; 0x280]);
        put(&mut life[..], 0x1B0 + 0x2C, 120i32);
        put(&mut life[..], 0x1B0 + 0x30, 80i32);
        put(&mut life[..], 0x248 + 0x2C, 40i32);
        let mut render = Box::new([0u8; 0x150]);
        put(&mut render[..], 0x138, [10.0f32, 20.0, 1.5]);
        let mut positioned = Box::new([0u8; 0x1E8]);
        positioned[0x1E0] = 0x02;
        let mut magic = Box::new([0u8; 0x148]);
        put(&mut magic[..], 0x144, 3i32);
        let entity = fake_entity(
            "Metadata/Monsters/Wolf/Wolf",
            &[
                ("Life", life.as_ptr() as u64),
                ("Render", render.as_ptr() as u64),
                ("Positioned", positioned.as_ptr() as u64),
                ("ObjectMagicProperties", magic.as_ptr() as u64),
            ],
        );
        Monster {
            entity,
            life,
            _render: render,
            _positioned: positioned,
            _magic: magic,
        }
    }

    #[test]
    fn reads_an_entity_and_its_parts() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let fake = fake_monster();
        let e = read(&mem, fake.entity.address()).unwrap();
        assert_eq!(e.path, "Metadata/Monsters/Wolf/Wolf");
        assert_eq!(e.id, 77);
        assert!(e.valid);
        assert_eq!(
            e.parts.keys().collect::<Vec<_>>(),
            ["Life", "ObjectMagicProperties", "Positioned", "Render"]
        );
        assert_eq!(e.parts["Life"], fake.life.as_ptr() as u64);
        let life = e.life.unwrap();
        assert_eq!((life.health.current, life.health.total), (80, 120));
        assert_eq!(life.energy_shield.total, 40);
        assert_eq!(e.position, Some([10.0, 20.0, 1.5]));
        assert_eq!(e.friendly, Some(false));
        assert_eq!(e.rarity, Some(Rarity::Unique));
        assert_eq!((e.chest_opened, e.player), (None, None));
    }

    #[test]
    fn too_many_parts_is_not_an_entity() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut fake = fake_monster();
        put(&mut fake.entity.lookup[..], 0x48, 51i32);
        assert!(read(&mem, fake.entity.address()).is_err());
    }
}
