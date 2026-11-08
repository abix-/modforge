//! The zone the player is in, read the way GameHelper2 does
//! (GameOffsets/Objects/States/InGameStateOffset.cs,
//! InGameState/AreaInstanceOffsets.cs, InGameState/WorldDataOffset.cs,
//! FilesStructures/WorldAreaDatOffsets.cs and RemoteObjects
//! FilesStructures/WorldAreaDat.cs).

use anyhow::{Context, Result};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;

/// InGameStateOffset.AreaInstanceData.
pub const IN_GAME_AREA_INSTANCE: u64 = 0x290;
/// InGameStateOffset.WorldData.
pub const IN_GAME_WORLD_DATA: u64 = 0x368;
/// AreaInstanceOffsets.CurrentAreaLevel (a byte). GameHelper2 has
/// 0xBC; on the build of 2026-11-06 it is 0xC4 (research_offsets).
pub const AREA_LEVEL: u64 = 0xC4;
/// AreaInstanceOffsets.CurrentAreaHash: GameHelper2 0x114, now 0x11C.
pub const AREA_HASH: u64 = 0x11C;
/// WorldDataOffset.WorldAreaDetailsPtr at 0x98 (on this build it points
/// to the area instance), then WorldAreaDetailsStruct
/// .WorldAreaDetailsRowPtr: GameHelper2 0x98, now 0xA0 (research_offsets).
pub const WORLD_AREA_DETAILS: u64 = 0x98;
pub const WORLD_AREA_ROW: u64 = 0xA0;
/// The WorldArea.dat row.
pub mod row {
    pub const ID: u64 = 0x00;
    pub const NAME: u64 = 0x08;
    pub const ACT: u64 = 0x10;
    pub const IS_TOWN: u64 = 0x14;
    pub const HAS_WAYPOINT: u64 = 0x15;
}
/// GameHelper2 ReadUnicodeString reads 256 bytes.
const TEXT_UNITS: usize = 128;

/// Ids GameHelper2 counts as towns although the row says otherwise.
const EXTRA_TOWNS: &[&str] = &["HeistHub", "KalguuranSettlersLeague"];

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Zone {
    pub id: String,
    pub name: String,
    pub act: i32,
    pub level: u8,
    /// Changes with every new instance of a zone.
    pub hash: u32,
    pub is_town: bool,
    pub is_hideout: bool,
    pub has_waypoint: bool,
}

/// GameHelper2 WorldAreaDat: a town if the row says so or the id is one
/// of [`EXTRA_TOWNS`]; a hideout if the id has "hideout" but not "map".
pub fn is_town(id: &str, row_says_town: bool) -> bool {
    row_says_town || EXTRA_TOWNS.contains(&id)
}

pub fn is_hideout(id: &str) -> bool {
    let id = id.to_lowercase();
    id.contains("hideout") && !id.contains("map")
}

/// The zone, from the in-game state's address.
pub fn read(mem: &ProcessMemory, in_game_state: u64) -> Result<Zone> {
    let ptr = |addr: u64, what: &str| -> Result<u64> {
        let p: u64 = mem
            .read_value(addr)
            .with_context(|| format!("read {what} pointer at {addr:#x}"))?;
        anyhow::ensure!(p != 0, "{what} pointer at {addr:#x} is null");
        Ok(p)
    };
    let area = ptr(in_game_state + IN_GAME_AREA_INSTANCE, "area instance")?;
    let world = ptr(in_game_state + IN_GAME_WORLD_DATA, "world data")?;
    let details = ptr(world + WORLD_AREA_DETAILS, "world area details")?;
    let row_at = ptr(details + WORLD_AREA_ROW, "world area row")?;
    let level: u8 = mem
        .read_value(area + AREA_LEVEL)
        .context("read area level")?;
    let hash: u32 = mem.read_value(area + AREA_HASH).context("read area hash")?;
    let text = |field: u64, what: &str| -> Result<String> {
        let at = ptr(row_at + field, what)?;
        mem.read_wide_cstr(at, TEXT_UNITS)
            .with_context(|| format!("read {what} at {at:#x}"))
    };
    let id = text(row::ID, "area id")?;
    let name = text(row::NAME, "area name")?;
    let act: i32 = mem.read_value(row_at + row::ACT).context("read act")?;
    let town: u8 = mem
        .read_value(row_at + row::IS_TOWN)
        .context("read town flag")?;
    let waypoint: u8 = mem
        .read_value(row_at + row::HAS_WAYPOINT)
        .context("read waypoint flag")?;
    Ok(Zone {
        is_town: is_town(&id, town != 0),
        is_hideout: is_hideout(&id),
        has_waypoint: waypoint != 0,
        id,
        name,
        act,
        level,
        hash,
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn towns_and_hideouts_like_gamehelper2() {
        assert!(is_town("HeistHub", false));
        assert!(is_town("G1_town", true));
        assert!(!is_town("G1_1", false));
        assert!(is_hideout("HideoutFelled"));
        assert!(!is_hideout("MapHideoutFelled"));
        assert!(!is_hideout("G1_1"));
    }

    fn wide(text: &str) -> Vec<u16> {
        let mut v: Vec<u16> = text.encode_utf16().collect();
        v.resize(TEXT_UNITS, 0);
        v
    }

    #[test]
    fn reads_zone_through_the_pointer_chain() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let id = wide("G1_1");
        let name = wide("Clearfell");
        let mut row = [0u8; 0x18];
        row[..8].copy_from_slice(&(id.as_ptr() as u64).to_le_bytes());
        row[8..16].copy_from_slice(&(name.as_ptr() as u64).to_le_bytes());
        row[0x10..0x14].copy_from_slice(&1i32.to_le_bytes());
        row[0x15] = 1;
        let mut details = [0u64; 0xA8 / 8];
        details[WORLD_AREA_ROW as usize / 8] = row.as_ptr() as u64;
        let mut world = [0u64; 0xA0 / 8];
        world[WORLD_AREA_DETAILS as usize / 8] = details.as_ptr() as u64;
        let mut area = [0u8; 0x120];
        area[AREA_LEVEL as usize] = 3;
        let h = AREA_HASH as usize;
        area[h..h + 4].copy_from_slice(&0xDEADu32.to_le_bytes());
        let mut state = [0u64; 0x370 / 8];
        state[0x290 / 8] = area.as_ptr() as u64;
        state[0x368 / 8] = world.as_ptr() as u64;

        let zone = read(&mem, state.as_ptr() as u64).unwrap();
        assert_eq!(
            zone,
            Zone {
                id: "G1_1".into(),
                name: "Clearfell".into(),
                act: 1,
                level: 3,
                hash: 0xDEAD,
                is_town: false,
                is_hideout: false,
                has_waypoint: true,
            }
        );

        state[0x368 / 8] = 0;
        assert!(read(&mem, state.as_ptr() as u64).is_err());
    }
}
