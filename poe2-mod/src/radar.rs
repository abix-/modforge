//! Radar data after GameHelper2's Radar plugin: the zone's points of
//! interest found by the file names of its terrain tiles
//! (AreaInstance.cs GetTgtFileData; Radar.cs with its
//! important_tgt_files.txt, boss_arena_tgt_files.txt and
//! stairs_tgt_files.txt, copied to data/radar), and a walking path to
//! them over the walkable cells (Pathfinder.cs).

use crate::terrain::{TILE_CELLS, Terrain, Tile};
use modforge::grid;
use modforge::msvc_std::read_wstring;
use modforge::path::Cell;
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::{BTreeMap, HashMap};

/// TgtFileStruct: the path text after the vtable.
pub const TGT_FILE_PATH: u64 = 0x08;
/// Pathfinder.DefaultMaxIterations.
pub const MAX_EXPANSIONS: usize = 1_000_000;
/// Pathfinder.DefaultMaxDistance, in cells.
pub const MAX_DISTANCE: f32 = 2500.0;
/// Pathfinder.TryFindNearestWalkable's ring limit.
pub const NEAREST_RADIUS: i32 = 75;
/// Radar.TempleTgtPrefix.
pub const TEMPLE_PREFIX: &str =
    "Metadata/Terrain/Leagues/Incursion/Tiles/Features/Waygates/WaygateDevice";
/// Radar.RunestoneTgtPrefix.
pub const RUNESTONE_PREFIX: &str = "Metadata/Terrain/Leagues/Expedition/Tiles/CampaignRunes/";
/// The part of a temple or runestone tile that gets the icon.
const ICON_PART: &str = ":1-y:1";
/// The important list's key for every zone.
const COMMON: &str = "common";

/// A tile's key: its file path with the tile's part, the part's x and y
/// swapped on odd rotations (GetTgtFileData). The path ends in ".tdt",
/// so keys read "....tdtx:2-y:1".
pub fn tile_key(path: &str, tile: &Tile) -> String {
    let (a, b) = if tile.rotation.is_multiple_of(2) {
        (tile.id_x, tile.id_y)
    } else {
        (tile.id_y, tile.id_x)
    };
    format!("{path}x:{a}-y:{b}")
}

/// Where each tile key lies: the grid cell of each tile's corner.
/// `path_of(tgt file pointer)` gives a tile's file path; tiles with no
/// path are left out.
pub fn tile_files(
    tiles: &[Tile],
    tiles_x: usize,
    mut path_of: impl FnMut(u64) -> Option<String>,
) -> BTreeMap<String, Vec<Cell>> {
    let mut out: BTreeMap<String, Vec<Cell>> = BTreeMap::new();
    if tiles_x == 0 {
        return out;
    }
    let mut paths: HashMap<u64, Option<String>> = HashMap::new();
    for (i, tile) in tiles.iter().enumerate() {
        let path = paths
            .entry(tile.tgt_file)
            .or_insert_with(|| path_of(tile.tgt_file).filter(|p| !p.is_empty()));
        let Some(path) = path else { continue };
        let cell = (
            ((i % tiles_x) * TILE_CELLS) as i32,
            ((i / tiles_x) * TILE_CELLS) as i32,
        );
        out.entry(tile_key(path, tile)).or_default().push(cell);
    }
    out
}

/// The tile keys of a zone's terrain, each tile's path read through its
/// tgt file pointer.
pub fn read_tile_files(mem: &ProcessMemory, terrain: &Terrain) -> BTreeMap<String, Vec<Cell>> {
    tile_files(terrain.tiles(), terrain.tiles_x, |p| tile_path(mem, p))
}

/// The file path in the TgtFileStruct at `tgt_file`.
pub fn tile_path(mem: &ProcessMemory, tgt_file: u64) -> Option<String> {
    (tgt_file != 0)
        .then(|| read_wstring(mem, tgt_file + TGT_FILE_PATH).ok())
        .flatten()
}

/// What a point of interest is.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub enum Kind {
    /// A named place from the important list.
    Important,
    Temple,
    Runestone,
    Boss,
    Stairs,
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Point {
    pub kind: Kind,
    pub name: String,
    pub cell: Cell,
}

/// GameHelper2's tile lists.
#[derive(Debug, Default)]
pub struct Lists {
    /// Zone id (or "common") to tile key to the name shown.
    pub important: HashMap<String, HashMap<String, String>>,
    pub boss: HashMap<String, String>,
    pub stairs: HashMap<String, String>,
}

impl Lists {
    /// The lists as GameHelper2 ships them.
    pub fn gamehelper2() -> serde_json::Result<Self> {
        Ok(Self {
            important: serde_json::from_str(include_str!("../data/radar/important_tgt_files.txt"))?,
            boss: serde_json::from_str(include_str!("../data/radar/boss_arena_tgt_files.txt"))?,
            stairs: serde_json::from_str(include_str!("../data/radar/stairs_tgt_files.txt"))?,
        })
    }
}

/// The points of interest in zone `zone_id`: the important names for
/// this zone and for every zone, then one icon per tile as Radar picks
/// it (temple, runestone, boss arena, stairs, the first that fits).
pub fn points(files: &BTreeMap<String, Vec<Cell>>, lists: &Lists, zone_id: &str) -> Vec<Point> {
    let mut out = Vec::new();
    for zone in [zone_id, COMMON] {
        let Some(names) = lists.important.get(zone) else {
            continue;
        };
        let mut names: Vec<_> = names.iter().collect();
        names.sort();
        for (key, name) in names {
            for &cell in files.get(key).into_iter().flatten() {
                out.push(Point {
                    kind: Kind::Important,
                    name: name.clone(),
                    cell,
                });
            }
        }
    }
    for (key, cells) in files {
        let icon = if key.starts_with(TEMPLE_PREFIX) && key.ends_with(ICON_PART) {
            Some((Kind::Temple, "Vaal Ruins"))
        } else if key.starts_with(RUNESTONE_PREFIX) && key.ends_with(ICON_PART) {
            Some((Kind::Runestone, "Runestones"))
        } else if let Some(name) = lists.boss.get(key) {
            Some((Kind::Boss, name.as_str()))
        } else {
            lists.stairs.get(key).map(|n| (Kind::Stairs, n.as_str()))
        };
        let Some((kind, name)) = icon else { continue };
        for &cell in cells {
            out.push(Point {
                kind,
                name: name.to_string(),
                cell,
            });
        }
    }
    out
}

/// The walking path from `from` to `to` over open cells, smoothed, as
/// Pathfinder.FindPath does: a blocked start or end moves to the nearest
/// open cell, and points too far away get no path.
pub fn path(from: Cell, to: Cell, open: impl Fn(Cell) -> bool) -> Option<Vec<Cell>> {
    let start = grid::nearest_open(from, NEAREST_RADIUS, &open)?;
    if grid::distance(start, to) > MAX_DISTANCE {
        return None;
    }
    let goal = grid::nearest_open(to, NEAREST_RADIUS, &open)?;
    if start == goal {
        return Some(vec![start]);
    }
    let cells = grid::walk_path(start, goal, &open, MAX_EXPANSIONS)?;
    Some(grid::smooth(&cells, &open))
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;

    fn tile(tgt_file: u64, id_x: u8, id_y: u8, rotation: u8) -> Tile {
        let mut t = Tile::default();
        (t.tgt_file, t.id_x, t.id_y, t.rotation) = (tgt_file, id_x, id_y, rotation);
        t
    }

    #[test]
    fn lists_parse() {
        let lists = Lists::gamehelper2().unwrap();
        assert!(lists.important.contains_key("G1_2"));
        assert!(!lists.boss.is_empty());
        assert!(!lists.stairs.is_empty());
    }

    #[test]
    fn the_tile_path_is_the_text_after_the_vtable() {
        let mem = ProcessMemory::open(std::process::id()).unwrap();
        let text: Vec<u16> = "Metadata/Terrain/Mesa/Peak.tdt".encode_utf16().collect();
        // Vtable, then the std::wstring: buffer pointer, length, capacity.
        let mut tgt = [0u8; 0x28];
        put(&mut tgt, 0x08, text.as_ptr() as u64);
        put(&mut tgt, 0x18, text.len() as i32);
        put(&mut tgt, 0x20, text.len() as i32);
        assert_eq!(
            tile_path(&mem, tgt.as_ptr() as u64).as_deref(),
            Some("Metadata/Terrain/Mesa/Peak.tdt")
        );
        assert_eq!(tile_path(&mem, 0), None);
    }

    #[test]
    fn keys_swap_the_part_on_odd_rotations() {
        assert_eq!(tile_key("A.tdt", &tile(0, 2, 1, 0)), "A.tdtx:2-y:1");
        assert_eq!(tile_key("A.tdt", &tile(0, 2, 1, 3)), "A.tdtx:1-y:2");
    }

    #[test]
    fn tiles_are_found_by_file_and_named() {
        let boss = "Metadata/Terrain/Maps/Mesa/Tiles/Peak.tdt";
        let burrow = "Metadata/Terrain/Woods/AreaTransitions/FallenTreeSlash_in.tdt";
        let temple = format!("{TEMPLE_PREFIX}_01.tdt");
        // Three tiles across, two down.
        let tiles = [
            tile(1, 0, 0, 0),
            tile(0, 0, 0, 0),
            tile(2, 1, 2, 1),
            tile(3, 1, 1, 0),
            tile(4, 0, 0, 0),
            tile(3, 0, 0, 0),
        ];
        let mut asked = Vec::new();
        let files = tile_files(&tiles, 3, |p| {
            asked.push(p);
            match p {
                1 => Some(boss.to_string()),
                2 => Some(burrow.to_string()),
                3 => Some(temple.clone()),
                _ => None,
            }
        });
        // Each file pointer is read once.
        asked.sort();
        assert_eq!(asked, [0, 1, 2, 3, 4]);
        let c = TILE_CELLS as i32;
        assert_eq!(files[&format!("{boss}x:0-y:0")], [(0, 0)]);
        assert_eq!(files[&format!("{burrow}x:2-y:1")], [(2 * c, 0)]);
        assert_eq!(files[&format!("{temple}x:1-y:1")], [(0, c)]);

        let lists = Lists::gamehelper2().unwrap();
        let found = points(&files, &lists, "G1_2");
        let get = |k: Kind| -> Vec<(&str, Cell)> {
            found
                .iter()
                .filter(|p| p.kind == k)
                .map(|p| (p.name.as_str(), p.cell))
                .collect()
        };
        assert_eq!(get(Kind::Important), [("Mud Burrow", (2 * c, 0))]);
        assert_eq!(get(Kind::Boss), [("Boss", (0, 0))]);
        assert_eq!(get(Kind::Temple), [("Vaal Ruins", (0, c))]);
        // The burrow is only named in its own zone.
        assert!(
            points(&files, &lists, "G1_1")
                .iter()
                .all(|p| p.kind != Kind::Important)
        );
    }

    /// A 40 by 40 zone with a wall at x = 20 from y = 0 to 30.
    fn zone(c: Cell) -> bool {
        (0..40).contains(&c.0) && (0..40).contains(&c.1) && !(c.0 == 20 && c.1 <= 30)
    }

    #[test]
    fn the_path_goes_round_and_starts_off_the_wall() {
        let p = path((20, 5), (35, 5), zone).unwrap();
        assert!(zone(p[0]));
        assert_eq!(p.last(), Some(&(35, 5)));
        assert!(p.iter().any(|c| c.1 > 30));
        assert!(p.windows(2).all(|w| grid::line_clear(w[0], w[1], zone)));
        assert_eq!(path((3, 3), (3, 3), zone), Some(vec![(3, 3)]));
        assert_eq!(path((3, 3), (3, 3000), zone), None);
    }
}
