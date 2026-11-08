//! The Actor part: active skills, their cooldowns and the entities the
//! actor deployed (minions, totems, mines), read the way GameHelper2
//! does (GameOffsets/Objects/Components/Actor.cs, RemoteObjects
//! Components/Actor.cs, Utils/MiscHelper.cs ActiveSkillGemDataParser).

use anyhow::{Context, Result};
use modforge::msvc_std::{read_vector, read_vector_header};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::{BTreeMap, HashMap};

/// ActorOffset.
pub const ACTOR_ANIMATION: u64 = 0x8B0;
pub const ACTOR_SKILLS: u64 = 0xB08;
pub const ACTOR_COOLDOWNS: u64 = 0xB20;
pub const ACTOR_DEPLOYED: u64 = 0xC28;
/// ActiveSkillDetails.
pub mod skill {
    pub const USE_STAGE: u64 = 0x08;
    pub const CAST_TYPE: u64 = 0x0C;
    pub const KEY: u64 = 0x40;
    pub const PER_LEVEL_ROW: u64 = 0x48;
    pub const TOTAL_USES: u64 = 0xE4;
    pub const COOLDOWN_MS: u64 = 0xE8;
}
/// ActiveSkillCooldown: one entry of 0x48 bytes.
pub mod cooldown {
    pub const SIZE: u64 = 0x48;
    pub const LIST: u64 = 0x10;
    pub const LIST_ENTRY: u64 = 0x10;
    pub const MAX_USES: u64 = 0x30;
    pub const KEY: u64 = 0x3C;
}
/// GameHelper2 skips skills whose key's high half is below this.
const PLAYER_SKILL_KEY: u32 = 0x8000;
/// GameHelper2 ReadUnicodeString reads 256 bytes.
const TEXT_UNITS: usize = 128;

/// GameHelper2 ActiveSkillGemDataParser: what the skill key says
/// about the gem that gives the skill.
#[derive(Clone, Copy, Debug, PartialEq, Serialize)]
pub struct Gem {
    pub on_player_item: bool,
    pub socket: u8,
    pub link: u8,
    /// Inventory id, as in the inventory names.
    pub inventory: u8,
    pub name_hash: u32,
}

pub fn gem(key: u32) -> Gem {
    let name_hash = key >> 0x10;
    let mut rest = key & 0xFFFF;
    let inventory = ((rest & 0x7F) + 1) as u8;
    rest >>= 7;
    let link = (rest & 0x07) as u8;
    rest >>= 3;
    let socket = (rest & 0x07) as u8;
    rest >>= 3;
    rest >>= 2;
    Gem {
        on_player_item: rest > 0,
        socket,
        link,
        inventory,
        name_hash,
    }
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Skill {
    /// The GrantedEffectsPerLevel row's name, GameHelper2's skill name.
    pub name: String,
    pub key: u32,
    pub use_stage: i32,
    pub cast_type: i32,
    pub total_uses: i32,
    pub cooldown_ms: i32,
    /// Running cooldowns, and the uses before it cannot be used.
    pub active_cooldowns: usize,
    pub max_uses: Option<i32>,
    pub usable: bool,
    pub gem: Gem,
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Actor {
    pub animation: i32,
    pub skills: Vec<Skill>,
    /// Deployed entities by GameHelper2's DeployedObjectType.
    pub deployed: BTreeMap<i32, u32>,
}

/// DeployedEntityStructure: 24 bytes in PoE2.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct Deployed {
    entity_id: i32,
    skill_id: i32,
    kind: i32,
    _pad: i32,
    counter: i32,
    _pad2: i32,
}

/// The Actor part at `at`. Skills without a per-level row or with a
/// key below the player range are left out, as GameHelper2 does.
pub fn read(mem: &ProcessMemory, at: u64) -> Result<Actor> {
    let animation: i32 = mem
        .read_value(at + ACTOR_ANIMATION)
        .context("read animation")?;
    let mut cooldowns: HashMap<u32, (usize, i32)> = HashMap::new();
    let cd = read_vector_header(mem, at + ACTOR_COOLDOWNS).context("read cooldowns")?;
    for i in 0..cd.len(cooldown::SIZE) {
        let base = cd.at(i, cooldown::SIZE);
        let key: u32 = mem.read_value(base + cooldown::KEY)?;
        let max_uses: i32 = mem.read_value(base + cooldown::MAX_USES)?;
        let running = read_vector_header(mem, base + cooldown::LIST)
            .map(|v| v.len(cooldown::LIST_ENTRY))
            .unwrap_or(0);
        cooldowns.insert(key, (running, max_uses));
    }
    let pairs: Vec<[u64; 2]> = read_vector(mem, at + ACTOR_SKILLS).context("read skills")?;
    let mut skills = Vec::new();
    for [details, _] in pairs {
        if details == 0 {
            continue;
        }
        let Ok(row) = mem.read_value::<u64>(details + skill::PER_LEVEL_ROW) else {
            continue;
        };
        let Ok(key) = mem.read_value::<u32>(details + skill::KEY) else {
            continue;
        };
        if row == 0 || (key >> 0x10) < PLAYER_SKILL_KEY {
            continue;
        }
        // GameHelper2 reads the text at the pointer the row starts with.
        let name = mem
            .read_value::<u64>(row)
            .ok()
            .and_then(|p| mem.read_wide_cstr(p, TEXT_UNITS).ok())
            .unwrap_or_default();
        let (active_cooldowns, max_uses) = match cooldowns.get(&key) {
            Some((running, max)) => (*running, Some(*max)),
            None => (0, None),
        };
        skills.push(Skill {
            name,
            key,
            use_stage: mem.read_value(details + skill::USE_STAGE).unwrap_or(0),
            cast_type: mem.read_value(details + skill::CAST_TYPE).unwrap_or(0),
            total_uses: mem.read_value(details + skill::TOTAL_USES).unwrap_or(0),
            cooldown_ms: mem.read_value(details + skill::COOLDOWN_MS).unwrap_or(0),
            active_cooldowns,
            max_uses,
            usable: max_uses.is_none_or(|m| (active_cooldowns as i64) < i64::from(m)),
            gem: gem(key),
        });
    }
    let mut deployed = BTreeMap::new();
    for d in read_vector::<Deployed>(mem, at + ACTOR_DEPLOYED).unwrap_or_default() {
        *deployed.entry(d.kind).or_insert(0) += 1;
    }
    Ok(Actor {
        animation,
        skills,
        deployed,
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
    fn gem_bits_like_gamehelper2() {
        // name hash 0x8123, then from the low bit: inventory-1 = 2 (7
        // bits), link 3, socket 5, two unknown bits, equipped bit.
        let low: u32 = 2 | (3 << 7) | (5 << 10) | (1 << 15);
        let g = gem((0x8123 << 16) | low);
        assert_eq!(
            g,
            Gem {
                on_player_item: true,
                socket: 5,
                link: 3,
                inventory: 3,
                name_hash: 0x8123
            }
        );
    }

    #[test]
    fn reads_skills_cooldowns_and_deployed() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let name: Vec<u16> = "Fireball\0".encode_utf16().collect();
        let name_ptr = name.as_ptr() as u64;
        let row = [name_ptr];
        let key: u32 = 0x8001_0001;
        let mut fireball = [0u8; 0x100];
        put(&mut fireball[..], 0x08, 2i32);
        put(&mut fireball[..], 0x40, key);
        put(&mut fireball[..], 0x48, row.as_ptr() as u64);
        put(&mut fireball[..], 0xE4, 7i32);
        put(&mut fireball[..], 0xE8, 3000i32);
        // An internal skill GameHelper2 leaves out.
        let mut internal = [0u8; 0x100];
        put(&mut internal[..], 0x40, 0x2000_0001u32);
        put(&mut internal[..], 0x48, row.as_ptr() as u64);
        let skills = [
            [fireball.as_ptr() as u64, 0],
            [internal.as_ptr() as u64, 0],
            [0, 0],
        ];
        // One running cooldown of one use: not usable.
        let running = [[0u8; 0x10]];
        let mut cd = [[0u8; cooldown::SIZE as usize]];
        put(&mut cd[0][..], 0x10, vector_of(&running));
        put(&mut cd[0][..], 0x30, 1i32);
        put(&mut cd[0][..], 0x3C, key);
        let deployed = [
            Deployed {
                kind: 9,
                ..Deployed::default()
            },
            Deployed {
                kind: 9,
                ..Deployed::default()
            },
        ];
        let mut actor = vec![0u8; 0xC40];
        put(&mut actor[..], 0x8B0, 0x41i32);
        put(&mut actor[..], 0xB08, vector_of(&skills));
        put(&mut actor[..], 0xB20, vector_of(&cd));
        put(&mut actor[..], 0xC28, vector_of(&deployed));

        let a = read(&mem, actor.as_ptr() as u64).unwrap();
        assert_eq!(a.animation, 0x41);
        assert_eq!(a.skills.len(), 1);
        let s = &a.skills[0];
        assert_eq!(s.name, "Fireball");
        assert_eq!((s.use_stage, s.total_uses, s.cooldown_ms), (2, 7, 3000));
        assert_eq!(
            (s.active_cooldowns, s.max_uses, s.usable),
            (1, Some(1), false)
        );
        assert_eq!(a.deployed, BTreeMap::from([(9, 2)]));
    }
}
