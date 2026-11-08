//! The zone's terrain: ground height and walkable cells per grid cell,
//! read the way GameHelper2 does (GameOffsets/Objects/States/InGameState
//! AreaInstanceOffsets.cs TerrainStruct and TileStructure; RemoteObjects
//! States/InGameStateObjects AreaInstance.cs GetTerrainHeight,
//! GetSubTerrainHeight, TryGetTerrainDimensions; Plugins/Radar
//! MapEdgeDetector.cs for the walkable nibbles).
//!
//! The zone is a grid of tiles, each 23 by 23 grid cells. A cell's
//! height is its tile's height times the zone's multiplier plus the
//! cell's own small height, with the tile's rotation applied, times
//! -7.8125. The two small rotation tables come from the game's code
//! (the Terrain Rotation Selector and Terrain Rotator Helper statics).

use anyhow::{Context, Result, ensure};
use modforge::msvc_std::{Vector, read_vector};
use modforge::process_memory::ProcessMemory;
use std::collections::HashMap;

/// AreaInstanceOffsets.TerrainMetadata.
pub const AREA_TERRAIN: u64 = 0x8D0;
/// TerrainStruct.
pub mod meta {
    pub const TOTAL_TILES: u64 = 0x18;
    pub const TILES: u64 = 0x28;
    pub const WALKABLE: u64 = 0xD0;
    pub const BYTES_PER_ROW: u64 = 0x130;
    pub const HEIGHT_MULTIPLIER: u64 = 0x134;
}
/// TileStructure.TileToGridConversion and TileToWorldConversion.
pub const TILE_CELLS: usize = 0x17;
pub const TILE_WORLD: f32 = 250.0;
/// TerrainStruct.TileHeightFinalMultiplier.
pub const HEIGHT_FINAL: f32 = 7.8125;
/// AreaInstance.MaxTerrainGridCells.
const MAX_CELLS: u64 = 100_000_000;
/// Core.RotationSelector and Core.RotatorHelper sizes.
pub const ROTATION_SELECTOR_LEN: usize = 9;
pub const ROTATOR_HELPER_LEN: usize = 25;

/// World units per grid cell (AreaInstance.WorldToGridConvertor).
pub fn world_per_cell() -> f32 {
    TILE_WORLD / TILE_CELLS as f32
}

/// TileStructure, 0x38 bytes.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
pub struct Tile {
    pub sub_tiles: u64,
    pub tgt_file: u64,
    _pad: [u8; 0x20],
    pub height: i16,
    _pad2: [u8; 2],
    pub id_x: u8,
    pub id_y: u8,
    pub rotation: u8,
    _pad3: u8,
}

/// One zone's terrain, read once per zone.
#[derive(Debug, Default)]
pub struct Terrain {
    pub tiles_x: usize,
    pub tiles_y: usize,
    pub height_multiplier: i16,
    pub bytes_per_row: usize,
    tiles: Vec<Tile>,
    sub_heights: HashMap<u64, Vec<i8>>,
    walkable: Vec<u8>,
    rotation_selector: Vec<u8>,
    rotator_helper: Vec<u8>,
}

impl Terrain {
    pub fn cells(&self) -> (usize, usize) {
        (self.tiles_x * TILE_CELLS, self.tiles_y * TILE_CELLS)
    }

    /// GameHelper2 GetTerrainHeight for one cell, in world units. None
    /// outside the zone or when the tile's small heights were not read.
    pub fn height(&self, x: usize, y: usize) -> Option<f32> {
        let (cx, cy) = self.cells();
        if x >= cx || y >= cy {
            return None;
        }
        let tile = self
            .tiles
            .get((y / TILE_CELLS) * self.tiles_x + x / TILE_CELLS)?;
        let sub = self.sub_heights.get(&tile.sub_tiles)?;
        let (rx, ry) = (x % TILE_CELLS, y % TILE_CELLS);
        let selected = match self.rotation_selector.get(usize::from(tile.rotation)) {
            Some(r) => (usize::from(*r) * 3).min(24),
            None => 24,
        };
        let helper = |i: usize| usize::from(self.rotator_helper.get(i).copied().unwrap_or(0));
        let rotator = [TILE_CELLS - rx - 1, rx, TILE_CELLS - ry - 1, ry];
        let (x0, x1, y0) = (helper(selected), helper(selected + 1), helper(selected + 2));
        let y1 = if x0 == 0 { 2 } else { 0 };
        let fx = rotator.get(x0 * 2 + x1).copied().unwrap_or(0);
        let fy = rotator.get(y0 + y1).copied().unwrap_or(0);
        let small = sub_height(sub, fy, fx);
        let h = f32::from(tile.height) * f32::from(self.height_multiplier) + small as f32;
        Some(-(h * HEIGHT_FINAL))
    }

    /// GameHelper2 MapEdgeDetector: two cells per byte, the even one in
    /// the low four bits. 0 is not walkable; 1 to 5 are walkable for
    /// entities up to that size.
    pub fn walkable(&self, x: usize, y: usize) -> u8 {
        if x / 2 >= self.bytes_per_row {
            return 0;
        }
        let shift = if x % 2 == 0 { 0 } else { 4 };
        self.walkable
            .get(y * self.bytes_per_row + x / 2)
            .map_or(0, |b| (b >> shift) & 0xF)
    }

    /// The grid cell of a world position.
    pub fn cell_of(x: f32, y: f32) -> (usize, usize) {
        let w = world_per_cell();
        ((x / w).max(0.0) as usize, (y / w).max(0.0) as usize)
    }
}

/// GameHelper2 GetSubTerrainHeight: the small heights are packed by
/// how many distinct values the tile has.
pub fn sub_height(sub: &[i8], y: usize, x: usize) -> i32 {
    if x >= TILE_CELLS || y >= TILE_CELLS || sub.is_empty() {
        return 0;
    }
    let index = y * TILE_CELLS + x;
    let at = |i: usize| sub.get(i).copied().map_or(0, i32::from);
    let packed = |i: usize| sub.get(i).copied().map_or(0, |b| b as u8);
    match sub.len() {
        0x01 => at(0),
        0x45 => at(usize::from(
            (packed((index >> 3) + 2) >> (index & 7)) & 0x01,
        )),
        0x89 => at(usize::from(
            (packed((index >> 2) + 4) >> ((index & 3) << 1)) & 0x03,
        )),
        0x119 => at(usize::from(
            (packed((index >> 1) + 16) >> ((index & 1) << 2)) & 0x0F,
        )),
        _ => at(index),
    }
}

/// GameHelper2 TryGetTerrainDimensions: the tile counts, when they fit
/// the cell limit and the tile vector holds exactly that many tiles.
pub fn dimensions(total: [i64; 2], tiles: &Vector) -> Option<(usize, usize)> {
    let [tx, ty] = total;
    if tx <= 0 || ty <= 0 {
        return None;
    }
    let (tx, ty) = (tx as u64, ty as u64);
    let cells = tx
        .checked_mul(TILE_CELLS as u64)?
        .checked_mul(ty.checked_mul(TILE_CELLS as u64)?)?;
    if cells > MAX_CELLS || tiles.first == 0 || tiles.last < tiles.first || tiles.end < tiles.last {
        return None;
    }
    if tiles.last - tiles.first != tx * ty * size_of::<Tile>() as u64 {
        return None;
    }
    Some((tx as usize, ty as usize))
}

/// The terrain of the area instance at `area`, with the two rotation
/// tables read from the game's statics.
pub fn read(
    mem: &ProcessMemory,
    area: u64,
    rotation_selector: Vec<u8>,
    rotator_helper: Vec<u8>,
) -> Result<Terrain> {
    let at = area + AREA_TERRAIN;
    let total: [i64; 2] = mem
        .read_value(at + meta::TOTAL_TILES)
        .context("read tile counts")?;
    let header: Vector = mem
        .read_value(at + meta::TILES)
        .context("read tile vector")?;
    let (tiles_x, tiles_y) =
        dimensions(total, &header).with_context(|| format!("terrain does not fit: {total:?}"))?;
    let tiles: Vec<Tile> = read_vector(mem, at + meta::TILES).context("read tiles")?;
    ensure!(
        tiles.len() == tiles_x * tiles_y,
        "tile count changed while reading"
    );
    let mut sub_heights = HashMap::new();
    for t in &tiles {
        if t.sub_tiles == 0 || sub_heights.contains_key(&t.sub_tiles) {
            continue;
        }
        if let Ok(h) = read_vector::<i8>(mem, t.sub_tiles) {
            sub_heights.insert(t.sub_tiles, h);
        }
    }
    let bytes_per_row: i32 = mem.read_value(at + meta::BYTES_PER_ROW)?;
    Ok(Terrain {
        tiles_x,
        tiles_y,
        height_multiplier: mem.read_value(at + meta::HEIGHT_MULTIPLIER)?,
        bytes_per_row: usize::try_from(bytes_per_row).unwrap_or(0),
        tiles,
        sub_heights,
        walkable: read_vector(mem, at + meta::WALKABLE).unwrap_or_default(),
        rotation_selector,
        rotator_helper,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;

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
    fn tile_is_gamehelper2_size() {
        assert_eq!(size_of::<Tile>(), 0x38);
    }

    #[test]
    fn small_heights_unpack_like_gamehelper2() {
        assert_eq!(sub_height(&[-3], 5, 5), -3);
        // 0x45 bytes: two values, then one bit per cell from byte 2.
        let mut two = vec![10i8, 20];
        two.resize(0x45, 0);
        two[2] = 0b10;
        assert_eq!(sub_height(&two, 0, 0), 10);
        assert_eq!(sub_height(&two, 0, 1), 20);
        // Full array: one value per cell.
        let full: Vec<i8> = (0..(TILE_CELLS * TILE_CELLS))
            .map(|i| (i % 100) as i8)
            .collect();
        assert_eq!(sub_height(&full, 1, 2), (TILE_CELLS + 2) as i32);
        assert_eq!(sub_height(&full, TILE_CELLS, 0), 0);
    }

    #[test]
    fn dimensions_need_a_matching_tile_vector() {
        let tiles = [Tile::default(); 6];
        let v = vector_of(&tiles);
        assert_eq!(dimensions([3, 2], &v), Some((3, 2)));
        assert_eq!(dimensions([2, 2], &v), None);
        assert_eq!(dimensions([0, 2], &v), None);
        assert_eq!(dimensions([100_000, 100_000], &v), None);
    }

    #[test]
    fn walkable_nibbles() {
        let t = Terrain {
            bytes_per_row: 2,
            walkable: vec![0x21, 0x00, 0x50, 0x03],
            ..Terrain::default()
        };
        assert_eq!(t.walkable(0, 0), 1);
        assert_eq!(t.walkable(1, 0), 2);
        assert_eq!(t.walkable(1, 1), 5);
        assert_eq!(t.walkable(2, 1), 3);
        assert_eq!(t.walkable(4, 0), 0);
    }

    #[test]
    fn reads_terrain_and_heights() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let small = [4i8];
        let sub = vector_of(&small);
        let mut tiles = [Tile::default(); 2];
        tiles[0].sub_tiles = &sub as *const _ as u64;
        tiles[0].height = 2;
        tiles[1].sub_tiles = &sub as *const _ as u64;
        tiles[1].height = -1;
        let walk = [0x11u8; 24];
        let mut area = vec![0u8; 0x8D0 + 0x140];
        put(&mut area[..], 0x8D0 + 0x18, [2i64, 1]);
        put(&mut area[..], 0x8D0 + 0x28, vector_of(&tiles));
        put(&mut area[..], 0x8D0 + 0xD0, vector_of(&walk));
        put(&mut area[..], 0x8D0 + 0x130, 12i32);
        put(&mut area[..], 0x8D0 + 0x134, 3i16);

        let t = read(&mem, area.as_ptr() as u64, vec![0; 9], vec![0; 25]).unwrap();
        assert_eq!((t.tiles_x, t.tiles_y), (2, 1));
        assert_eq!(t.cells(), (46, 23));
        // (2 * 3 + 4) * -7.8125 and (-1 * 3 + 4) * -7.8125.
        assert_eq!(t.height(0, 0), Some(-78.125));
        assert_eq!(t.height(30, 10), Some(-7.8125));
        assert_eq!(t.height(46, 0), None);
        assert_eq!(t.walkable(3, 1), 1);
    }
}
