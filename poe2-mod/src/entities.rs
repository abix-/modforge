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
    pub const LIFE_WARD: u64 = 0x2E8;
    /// VitalStruct fields.
    pub const VITAL_RESERVED_FLAT: u64 = 0x10;
    pub const VITAL_RESERVED_PERCENT: u64 = 0x14;
    pub const VITAL_REGEN: u64 = 0x28;
    pub const VITAL_TOTAL: u64 = 0x2C;
    pub const VITAL_CURRENT: u64 = 0x30;
    pub const POSITIONED_REACTION: u64 = 0x1E0;
    pub const RENDER_WORLD_POSITION: u64 = 0x138;
    pub const RENDER_MODEL_BOUNDS: u64 = 0x144;
    pub const RENDER_TERRAIN_HEIGHT: u64 = 0x1B0;
    pub const CHEST_DATA: u64 = 0x160;
    pub const CHEST_IS_OPENED: u64 = 0x168;
    /// ChestsStructInternal.StrongboxDatPtr: not 0 on a strongbox.
    pub const CHEST_DATA_STRONGBOX: u64 = 0x50;
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
    pub ward: Vital,
}

impl Vital {
    /// VitalStruct.ReservedTotal.
    pub fn reserved(&self) -> i32 {
        (self.reserved_percent as f32 / 10000.0 * self.total as f32).ceil() as i32
            + self.reserved_flat
    }

    /// VitalStruct.Unreserved.
    pub fn unreserved(&self) -> i32 {
        self.total - self.reserved()
    }

    /// VitalStruct.CurrentInPercent: of the unreserved part, 0 when
    /// there is none.
    pub fn percent(&self) -> i32 {
        let unreserved = self.unreserved();
        if self.total == 0 || unreserved <= 0 {
            return 0;
        }
        (100.0 * f64::from(self.current) / f64::from(unreserved)).round() as i32
    }
}

impl Life {
    /// Life.IsAlive.
    pub fn alive(&self) -> bool {
        self.health.current > 0
    }
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
    /// The ground height under the entity (Render.TerrainHeight).
    pub terrain_height: Option<f32>,
    /// The model's size (Render.ModelBounds); z is its height.
    pub model_bounds: Option<[f32; 3]>,
    /// Chest.IsStrongbox, read through the chest's data.
    pub strongbox: Option<bool>,
    pub friendly: Option<bool>,
    pub rarity: Option<Rarity>,
    pub chest_opened: Option<bool>,
    pub shrine_used: Option<bool>,
    pub targetable: Option<bool>,
    pub player: Option<PlayerPart>,
    pub stats: Option<Stats>,
}

/// GameStats ids the features read (RemoteEnums/GameStats.cs).
pub mod stat {
    pub const CURRENT_ENDURANCE_CHARGES: i32 = 5;
    pub const CURRENT_FRENZY_CHARGES: i32 = 6;
    pub const CURRENT_POWER_CHARGES: i32 = 7;
    pub const IS_DEAD: i32 = 2423;
    pub const CURRENT_RAGE: i32 = 6995;
}

/// StatsOffsets and StatsStructInternal.
pub mod stats_part {
    pub const BY_ITEMS: u64 = 0x160;
    pub const WEAPON_INDEX: u64 = 0x168;
    pub const SHAPESHIFT_ROW: u64 = 0x170;
    pub const BY_BUFFS_AND_ACTIONS: u64 = 0x1C8;
    /// The (stat, value) vector inside either.
    pub const LIST: u64 = 0xF8;
}

/// The Stats part: stat id to value, from items and from buffs and
/// actions.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Stats {
    pub by_items: BTreeMap<i32, i32>,
    pub by_buffs_and_actions: BTreeMap<i32, i32>,
    pub weapon_index: i32,
    pub shapeshifted: bool,
}

impl Stats {
    /// GameHelper2's stat lookup: buffs and actions first, then items.
    pub fn get(&self, id: i32) -> Option<i32> {
        self.by_buffs_and_actions
            .get(&id)
            .or_else(|| self.by_items.get(&id))
            .copied()
    }
}

/// The Stats part at `at` (Stats.UpdateData). A missing list is empty.
pub fn read_stats(mem: &ProcessMemory, at: u64) -> Result<Stats> {
    let list = |ptr_at: u64| -> BTreeMap<i32, i32> {
        mem.read_value::<u64>(ptr_at)
            .ok()
            .filter(|p| *p != 0)
            .and_then(|p| read_vector::<[i32; 2]>(mem, p + stats_part::LIST).ok())
            .map(|v| v.into_iter().map(|[k, v]| (k, v)).collect())
            .unwrap_or_default()
    };
    Ok(Stats {
        by_items: list(at + stats_part::BY_ITEMS),
        by_buffs_and_actions: list(at + stats_part::BY_BUFFS_AND_ACTIONS),
        weapon_index: mem
            .read_value(at + stats_part::WEAPON_INDEX)
            .context("read weapon index")?,
        shapeshifted: mem.read_value::<u64>(at + stats_part::SHAPESHIFT_ROW)? != 0,
    })
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
            ward: read_vital(mem, p + part::LIFE_WARD).ok()?,
        })
    });
    let position = get("Render").and_then(|p| mem.read_value(p + part::RENDER_WORLD_POSITION).ok());
    let terrain_height =
        get("Render").and_then(|p| mem.read_value(p + part::RENDER_TERRAIN_HEIGHT).ok());
    let model_bounds =
        get("Render").and_then(|p| mem.read_value(p + part::RENDER_MODEL_BOUNDS).ok());
    let strongbox = get("Chest")
        .and_then(|p| mem.read_value::<u64>(p + part::CHEST_DATA).ok())
        .filter(|d| *d != 0)
        .and_then(|d| mem.read_value::<u64>(d + part::CHEST_DATA_STRONGBOX).ok())
        .map(|s| s != 0);
    let friendly = get("Positioned")
        .and_then(|p| mem.read_value::<u8>(p + part::POSITIONED_REACTION).ok())
        .map(is_friendly);
    let rarity = get("ObjectMagicProperties")
        .and_then(|p| {
            mem.read_value::<i32>(p + part::MAGIC_PROPERTIES_RARITY)
                .ok()
        })
        .and_then(rarity);
    let stats = get("Stats").and_then(|p| read_stats(mem, p).ok());
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
        terrain_height,
        model_bounds,
        strongbox,
        stats,
        friendly,
        rarity,
        player,
    })
}

/// BuffsOffsets.StatusEffectPtr: a vector of status effect pointers.
pub const BUFFS_EFFECTS: u64 = 0x160;
/// StatusEffectStruct.
pub mod effect {
    pub const DEFINITION: u64 = 0x08;
    pub const TOTAL_TIME: u64 = 0x18;
    pub const TIME_LEFT: u64 = 0x1C;
    pub const CHARGES: u64 = 0x40;
    pub const FLASK_SLOT: u64 = 0x42;
}
/// GameHelper2 ReadUnicodeString reads 256 bytes.
const TEXT_UNITS: usize = 128;

/// One status effect on an entity (GameHelper2 Buffs).
#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Buff {
    /// BuffDefinitions.dat id, such as `power_charge`.
    pub name: String,
    /// Seconds; infinite for buffs that do not run out (shown as null).
    pub total_time: f32,
    pub time_left: f32,
    pub charges: i16,
    /// The flask that gave it, for flask buffs.
    pub flask_slot: i16,
}

/// Every status effect on the Buffs part at `buffs`. An effect that
/// cannot be read is skipped.
pub fn read_buffs(mem: &ProcessMemory, buffs: u64) -> Result<Vec<Buff>> {
    let effects: Vec<u64> =
        read_vector(mem, buffs + BUFFS_EFFECTS).context("read status effects")?;
    Ok(effects
        .into_iter()
        .filter_map(|at| {
            let def: u64 = mem.read_value(at + effect::DEFINITION).ok()?;
            let name_ptr: u64 = mem.read_value(def).ok()?;
            Some(Buff {
                name: mem.read_wide_cstr(name_ptr, TEXT_UNITS).ok()?,
                total_time: mem.read_value(at + effect::TOTAL_TIME).ok()?,
                time_left: mem.read_value(at + effect::TIME_LEFT).ok()?,
                charges: mem.read_value(at + effect::CHARGES).ok()?,
                flask_slot: mem.read_value(at + effect::FLASK_SLOT).ok()?,
            })
        })
        .collect())
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

        pub(crate) fn set_vtable(&mut self, vtable: u64) {
            put(&mut self.entity[..], 0, vtable);
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
        life: Box<[u8; 0x320]>,
        _render: Box<[u8; 0x1C0]>,
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
        let mut life = Box::new([0u8; 0x320]);
        put(&mut life[..], 0x2E8 + 0x2C, 30i32);
        put(&mut life[..], 0x1B0 + 0x2C, 120i32);
        put(&mut life[..], 0x1B0 + 0x30, 80i32);
        put(&mut life[..], 0x248 + 0x2C, 40i32);
        let mut render = Box::new([0u8; 0x1C0]);
        put(&mut render[..], 0x138, [10.0f32, 20.0, 1.5]);
        put(&mut render[..], 0x1B0, -3.25f32);
        put(&mut render[..], 0x144, [1.0f32, 2.0, 90.0]);
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
    fn reads_stats_buffs_first() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let items: [[i32; 2]; 2] = [[stat::CURRENT_POWER_CHARGES, 1], [stat::IS_DEAD, 0]];
        let buffs: [[i32; 2]; 1] = [[stat::CURRENT_POWER_CHARGES, 3]];
        let vector = |s: &[[i32; 2]]| {
            let first = s.as_ptr() as u64;
            let last = first + size_of_val(s) as u64;
            Vector {
                first,
                last,
                end: last,
            }
        };
        let mut by_items = [0u8; 0x110];
        put(&mut by_items, 0xF8, vector(&items));
        let mut by_buffs = [0u8; 0x110];
        put(&mut by_buffs, 0xF8, vector(&buffs));
        let mut part = [0u8; 0x1D0];
        put(&mut part, 0x160, by_items.as_ptr() as u64);
        put(&mut part, 0x168, 1i32);
        put(&mut part, 0x1C8, by_buffs.as_ptr() as u64);
        let s = read_stats(&mem, part.as_ptr() as u64).unwrap();
        assert_eq!(s.get(stat::CURRENT_POWER_CHARGES), Some(3));
        assert_eq!(s.get(stat::IS_DEAD), Some(0));
        assert_eq!(s.get(stat::CURRENT_RAGE), None);
        assert_eq!((s.weapon_index, s.shapeshifted), (1, false));
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
        assert_eq!(e.terrain_height, Some(-3.25));
        assert_eq!(e.model_bounds, Some([1.0, 2.0, 90.0]));
        assert_eq!(life.ward.total, 30);
        assert!(life.alive());
        assert_eq!(e.friendly, Some(false));
        assert_eq!(e.rarity, Some(Rarity::Unique));
        assert_eq!((e.chest_opened, e.player), (None, None));
    }

    #[test]
    fn reads_buffs() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut name: Vec<u16> = "power_charge".encode_utf16().collect();
        name.resize(TEXT_UNITS, 0);
        let def = [name.as_ptr() as u64];
        let mut fx = [0u8; 0x48];
        put(&mut fx[..], 0x08, def.as_ptr() as u64);
        put(&mut fx[..], 0x18, f32::INFINITY);
        put(&mut fx[..], 0x1C, f32::INFINITY);
        put(&mut fx[..], 0x40, 3i16);
        let effects = [fx.as_ptr() as u64, 0x10];
        let first = effects.as_ptr() as u64;
        let mut buffs = [0u8; 0x178];
        put(
            &mut buffs[..],
            0x160,
            Vector {
                first,
                last: first + 16,
                end: first + 16,
            },
        );
        let got = read_buffs(&mem, buffs.as_ptr() as u64).unwrap();
        assert_eq!(got.len(), 1, "the unreadable effect is skipped");
        assert_eq!((got[0].name.as_str(), got[0].charges), ("power_charge", 3));
        assert!(got[0].time_left.is_infinite());
    }

    #[test]
    fn too_many_parts_is_not_an_entity() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut fake = fake_monster();
        put(&mut fake.entity.lookup[..], 0x48, 51i32);
        assert!(read(&mem, fake.entity.address()).is_err());
    }
}
