//! Radar data after GameHelper2's Radar plugin: the zone's points of
//! interest found by the file names of its terrain tiles
//! (AreaInstance.cs GetTgtFileData; Radar.cs with its
//! important_tgt_files.txt, boss_arena_tgt_files.txt and
//! stairs_tgt_files.txt, copied to data/radar), and a walking path to
//! them over the walkable cells (Pathfinder.cs).

use crate::terrain::{TILE_CELLS, Terrain, Tile};
use modforge::grid;
use modforge::msvc_std::read_wstring;
use modforge::overlay::{Image, Rgb};
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

/// MapUiElementOffset: the large map's shift, default shift and zoom.
pub mod map_element {
    pub const SHIFT: u64 = 0x350;
    pub const DEFAULT_SHIFT: u64 = 0x358;
    pub const ZOOM: u64 = 0x390;
}
/// Helper.CameraAngle, in degrees.
pub const CAMERA_ANGLE: f64 = 38.7;
/// Helper.DeltaInWorldToMapDelta: world height per grid cell.
pub const HEIGHT_PER_CELL: f32 = 10.86957;
/// Radar.DrawUI LargeMapScaleBaseline.
pub const LARGE_MAP_SCALE: f32 = 0.187812;
/// Radar.DrawUI LargeMapXBias and LargeMapYBias.
pub const LARGE_MAP_BIAS: [f32; 2] = [0.6, 0.3];
/// Pictures larger than this many pixels are not made
/// (GenerateMapTexture's guard).
pub const MAX_PICTURE_PIXELS: usize = 200_000_000;
/// RadarSettings.ReachedPathDistance, in cells: a path stops being drawn
/// once the player is this close to its end.
pub const REACHED_DISTANCE: f32 = 50.0;
/// RadarSettings.PathRecomputeIntervalMs.
pub const PATH_RECOMPUTE_MS: u64 = 250;

/// Where the large map's middle is and how big it draws, from the
/// game's large map element.
#[derive(Clone, Copy, Debug, PartialEq, Serialize)]
pub struct LargeMap {
    /// Center + Shift + DefaultShift + the bias.
    pub centre: [f32; 2],
    pub zoom: f32,
}

/// The large map element at `at`: its screen position (GameHelper2's
/// LargeMapUiElement.Center) plus its shifts and the bias.
pub fn read_large_map(mem: &ProcessMemory, at: u64, scale: &crate::slots::Scale) -> Option<LargeMap> {
    let pos = crate::slots::position(mem, at, scale)?;
    let shift: [f32; 2] = mem.read_value(at + map_element::SHIFT).ok()?;
    let default: [f32; 2] = mem.read_value(at + map_element::DEFAULT_SHIFT).ok()?;
    let zoom: f32 = mem.read_value(at + map_element::ZOOM).ok()?;
    let centre = [
        pos[0] + shift[0] + default[0] + LARGE_MAP_BIAS[0],
        pos[1] + shift[1] + default[1] + LARGE_MAP_BIAS[1],
    ];
    (centre.iter().all(|v| v.is_finite()) && zoom.is_finite() && zoom > 0.0)
        .then_some(LargeMap { centre, zoom })
}

/// Grid cells to map pixels (GameHelper2 Helper): the map turns the
/// grid 45 degrees and tilts it by the camera angle.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct MapView {
    pub centre: [f32; 2],
    cos: f32,
    sin: f32,
}

impl MapView {
    /// Helper.UpdateCosSin for a map of `scale` and `diagonal` pixels.
    pub fn new(centre: [f32; 2], scale: f32, diagonal: f64) -> Self {
        let map_scale = f64::from(240.0 / scale);
        let angle = CAMERA_ANGLE.to_radians();
        Self {
            centre,
            cos: (diagonal * angle.cos() / map_scale) as f32,
            sin: (diagonal * angle.sin() / map_scale) as f32,
        }
    }

    /// The large map in a window `window_height` pixels high
    /// (Radar.UpdateLargeMapDetails: the base resolution's diagonal at
    /// the window's height).
    pub fn large_map(map: &LargeMap, window_height: f32) -> Self {
        let (w, h) = crate::slots::BASE_RESOLUTION;
        let diagonal = f64::from(w).hypot(f64::from(h)) * f64::from(window_height) / f64::from(h);
        Self::new(map.centre, map.zoom * LARGE_MAP_SCALE, diagonal)
    }

    /// Helper.DeltaInWorldToMapDelta plus the centre: where a point
    /// `delta` cells from the player and `dz` higher draws.
    pub fn at(&self, delta: [f32; 2], dz: f32) -> [f32; 2] {
        let dz = dz / HEIGHT_PER_CELL;
        [
            self.centre[0] + (delta[0] - delta[1]) * self.cos,
            self.centre[1] + (dz - (delta[0] + delta[1])) * self.sin,
        ]
    }
}

/// MapEdgeDetector.IsBorder: a cell that is blocked, or walkable only
/// for the smallest size (to make the line thicker), next to a walkable
/// cell.
pub fn is_border(t: &Terrain, x: usize, y: usize) -> bool {
    let here = t.walkable(x, y);
    if here != 0 && here != 1 {
        return false;
    }
    let open = |x: Option<usize>, y: Option<usize>| match (x, y) {
        (Some(x), Some(y)) => t.walkable(x, y) != 0,
        _ => false,
    };
    open(Some(x), Some(y + 1))
        || open(Some(x), y.checked_sub(1))
        || open(x.checked_sub(1), Some(y))
        || open(Some(x + 1), Some(y))
}

/// Radar.GenerateMapTexture: the zone's walkable outline as a picture,
/// one pixel per cell, each border cell moved up and left by its height
/// so the outline sits where the tilted ground does. None when the zone
/// has no walkable data or is too big.
pub fn walkable_picture(t: &Terrain, color: Rgb) -> Option<Image> {
    let width = t.bytes_per_row * 2;
    let rows = t.rows();
    if width == 0 || rows == 0 || width * rows > MAX_PICTURE_PIXELS {
        return None;
    }
    let mut pixels = vec![0; width * rows];
    let lift = crate::terrain::world_per_cell() * 2.0;
    let (cells_x, cells_y) = t.cells();
    for y in 0..cells_y {
        for x in 1..cells_x.saturating_sub(1) {
            if !is_border(t, x, y) {
                continue;
            }
            let h = (t.height(x, y).unwrap_or(0.0) / lift) as i64;
            let (px, py) = (x as i64 - h, y as i64 - h);
            if (0..width as i64).contains(&px) && (0..rows as i64).contains(&py) {
                pixels[py as usize * width + px as usize] = color;
            }
        }
    }
    Some(Image {
        width: width as u32,
        height: rows as u32,
        pixels,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;

    #[test]
    fn map_view_turns_and_tilts_like_gamehelper2() {
        // Zoom 1 on a 1080 high window.
        let view = MapView::large_map(
            &LargeMap {
                centre: [960.0, 540.0],
                zoom: 1.0,
            },
            1080.0,
        );
        let diagonal = 2560f64.hypot(1600.0) * 1080.0 / 1600.0;
        let map_scale = 240.0 / f64::from(LARGE_MAP_SCALE);
        let cos = (diagonal * 38.7f64.to_radians().cos() / map_scale) as f32;
        let sin = (diagonal * 38.7f64.to_radians().sin() / map_scale) as f32;
        assert_eq!(view.at([0.0, 0.0], 0.0), [960.0, 540.0]);
        // One cell along x goes right and up; along y left and up.
        assert_eq!(view.at([1.0, 0.0], 0.0), [960.0 + cos, 540.0 - sin]);
        assert_eq!(view.at([0.0, 1.0], 0.0), [960.0 - cos, 540.0 - sin]);
        // Higher ground (in world units) draws lower on the map.
        let up = view.at([0.0, 0.0], HEIGHT_PER_CELL);
        assert!((up[1] - (540.0 + sin)).abs() < 1e-3);
    }

    #[test]
    fn the_picture_outlines_walkable_cells() {
        // 6 cells wide (3 bytes per row), 3 rows; the middle row's cells
        // 2 and 3 are walkable (value 2), the rest blocked.
        // Cells 1 and 2 of the middle row are walkable (value 2).
        let t = Terrain::with_walkable(3, vec![0, 0, 0, 0x20, 0x02, 0, 0, 0, 0]);
        assert!(is_border(&t, 0, 1));
        assert!(is_border(&t, 3, 1));
        assert!(is_border(&t, 1, 0));
        assert!(is_border(&t, 2, 2));
        assert!(!is_border(&t, 1, 1), "walkable cells are not border");
        assert!(!is_border(&t, 0, 0), "a corner touches no walkable cell");
        assert!(walkable_picture(&Terrain::default(), 1).is_none());

        // One tile (23 by 23 cells, flat): one walkable cell at (5, 5)
        // gets its four neighbours drawn.
        let mut walk = vec![0u8; 12 * 23];
        walk[5 * 12 + 2] = 0x20;
        let mut t = Terrain::with_walkable(12, walk);
        (t.tiles_x, t.tiles_y) = (1, 1);
        let p = walkable_picture(&t, 0x969696).unwrap();
        assert_eq!((p.width, p.height), (24, 23));
        let lit: Vec<(u32, u32)> = (0..p.height)
            .flat_map(|y| (0..p.width).map(move |x| (x, y)))
            .filter(|(x, y)| p.pixels[(y * p.width + x) as usize] != 0)
            .collect();
        assert_eq!(lit, [(5, 4), (4, 5), (6, 5), (5, 6)]);
    }

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
