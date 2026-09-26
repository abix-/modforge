//! A valid world (topside design.md "A valid world"): the walk grid built
//! from a square of the world as data (its chunks' water, cliffs, trees,
//! and rocks, every site's buildings and props, the bunkers), flooded
//! from the player's bunker door; every building door and room, every
//! spot for a person or a box, and every other bunker's door in the
//! square must be standable and reached. What is not is a broken world,
//! named. Endless did the same at placement: every spot rejected on
//! water, nothing placed that cuts a town off.

use glam::Vec2;

use crate::path::Cell;
use crate::structure::{StructureDef, TileKind, TileRun, tile_plan};
use crate::walk::{CHUNK, Rect, WalkMap, cell_of};
use crate::world2d::{Registries, World2d};

/// A bunker standing in the world: a name for reports, where, and its
/// building. The first one given is the player's; the flood starts at its
/// door.
pub struct Bunker<'a> {
    pub name: String,
    pub at: Vec2,
    pub def: &'a StructureDef,
}

/// Where a building's tiles stand in the world: it snaps to whole tiles.
fn placed(at: Vec2, runs: &[TileRun]) -> impl Iterator<Item = (TileKind, Rect)> + '_ {
    let at = at.round();
    runs.iter().map(move |r| {
        (
            r.kind,
            Rect {
                min: at + Vec2::new(r.from as f32, r.row as f32),
                max: at + Vec2::new(r.to as f32, r.row as f32 + 1.0),
            },
        )
    })
}

/// How far past the checked square the flood goes, metres: two chunks.
const MARGIN: f32 = 2.0 * CHUNK as f32;

/// The first tile of a run of tiles, in the world.
fn first_tile(r: &Rect) -> Cell {
    cell_of(r.min + Vec2::splat(0.5))
}

/// Everything wrong with the square from `lo` to `hi` of a world, by
/// name; empty for a valid one.
pub fn problems(world: &mut World2d, r: Registries, lo: Vec2, hi: Vec2, bunkers: &[Bunker]) -> Vec<String> {
    let mut map = WalkMap::default();
    let mut key = 0u64;
    let mut add = |map: &mut WalkMap, rects: Vec<Rect>| {
        key += 1;
        map.add(key, rects);
    };
    // The flood reaches past the square: a way to a site near its edge
    // may go round outside it.
    let margin = Vec2::splat(MARGIN);
    let (c0, c1) = (cell_of(lo - margin), cell_of(hi + margin));
    for cy in c0.1.div_euclid(CHUNK)..=c1.1.div_euclid(CHUNK) {
        for cx in c0.0.div_euclid(CHUNK)..=c1.0.div_euclid(CHUNK) {
            let chunk = world.chunk(r, (cx, cy));
            add(&mut map, chunk.solids());
        }
    }
    let sites = world.sites_in(r, lo - margin, hi + margin);
    let site_plans: Vec<Vec<(Vec2, Vec<TileRun>)>> = sites
        .iter()
        .map(|site| {
            site.rolled
                .members
                .iter()
                .map(|m| (site.position + Vec2::new(m.offset.x, m.offset.z), tile_plan(&m.structure)))
                .collect()
        })
        .collect();
    for (site, plans) in sites.iter().zip(&site_plans) {
        for (at, runs) in plans {
            add(&mut map, placed(*at, runs).filter(|(k, _)| k.solid()).map(|(_, r)| r).collect());
        }
        let props = site
            .rolled
            .props
            .iter()
            .map(|p| Rect::around(site.position + Vec2::new(p.position.x, p.position.z), Vec2::new(p.size.x, p.size.z)))
            .collect();
        add(&mut map, props);
    }
    let bunker_plans: Vec<Vec<TileRun>> = bunkers.iter().map(|b| tile_plan(b.def)).collect();
    for (b, runs) in bunkers.iter().zip(&bunker_plans) {
        add(&mut map, placed(b.at, runs).filter(|(k, _)| k.solid()).map(|(_, r)| r).collect());
    }

    let mut out = Vec::new();
    let Some(start) = bunkers.first().and_then(|b| {
        placed(b.at, &bunker_plans[0]).find(|(k, _)| *k == TileKind::Door).map(|(_, r)| first_tile(&r))
    }) else {
        return vec!["the player's bunker has no door".to_string()];
    };
    let reached = flood(&mut map, c0, c1, start);

    for (i, (site, plans)) in sites.iter().zip(&site_plans).enumerate() {
        if site.position.cmplt(lo).any() || site.position.cmpge(hi).any() {
            continue;
        }
        let name = format!("site {i} ({}, '{}') at {}", site.monument, site.rolled.name, site.position);
        for (b, (at, runs)) in plans.iter().enumerate() {
            let tiles: Vec<(TileKind, Rect)> = placed(*at, runs).collect();
            let doors: Vec<Cell> = tiles.iter().filter(|(k, _)| *k == TileKind::Door).map(|(_, r)| first_tile(r)).collect();
            if !doors.iter().any(|d| reached.contains(*d)) {
                out.push(format!("{name}, building {b}: no door reached from the bunker door"));
            }
            let unreached: Vec<&Rect> = tiles
                .iter()
                .filter(|(k, _)| *k == TileKind::Floor)
                .filter(|(_, r)| !reached.contains(first_tile(r)))
                .map(|(_, r)| r)
                .collect();
            if let Some(first) = unreached.first() {
                out.push(format!(
                    "{name}, building {b}: {} runs of floor not reached, the first at {}\n{}",
                    unreached.len(),
                    first.min,
                    picture(&mut map, &reached, &tiles)
                ));
            }
        }
        let spots = site
            .rolled
            .npc_spots
            .iter()
            .map(|s| ("person", s.position))
            .chain(site.rolled.loot_spots.iter().map(|s| ("box", s.position)));
        for (n, (what, p)) in spots.enumerate() {
            let at = site.position + Vec2::new(p.x, p.z);
            let tile = cell_of(at);
            if map.blocked(tile) {
                out.push(format!("{name}, spot {n} for a {what} at {at}: nobody can stand there"));
            } else if !reached.contains(tile) {
                out.push(format!("{name}, spot {n} for a {what} at {at}: not reached from the bunker door"));
            }
        }
    }
    for (b, runs) in bunkers.iter().zip(&bunker_plans).skip(1) {
        let door = placed(b.at, runs).find(|(k, _)| *k == TileKind::Door).map(|(_, r)| first_tile(&r));
        if !door.is_some_and(|d| reached.contains(d)) {
            out.push(format!("{}: its door is not reached from the player's bunker door", b.name));
        }
    }
    out
}

/// A building's tiles and one round it, top row first: `D` a door, `W` a
/// wall, `f` furniture, `#` anything else blocking, `.` reached from the
/// bunker door, `:` open and not reached.
fn picture(map: &mut WalkMap, reached: &Reached, tiles: &[(TileKind, Rect)]) -> String {
    let lo = tiles.iter().map(|(_, r)| first_tile(r)).fold((i32::MAX, i32::MAX), |a, t| (a.0.min(t.0), a.1.min(t.1)));
    let hi = tiles
        .iter()
        .map(|(_, r)| cell_of(r.max - Vec2::splat(0.5)))
        .fold((i32::MIN, i32::MIN), |a, t| (a.0.max(t.0), a.1.max(t.1)));
    let kind_at = |t: Cell| {
        tiles
            .iter()
            .find(|(_, r)| {
                let c = Vec2::new(t.0 as f32 + 0.5, t.1 as f32 + 0.5);
                c.cmpge(r.min).all() && c.cmplt(r.max).all()
            })
            .map(|(k, _)| *k)
    };
    let mut rows = Vec::new();
    for y in (lo.1 - 1..=hi.1 + 1).rev() {
        let row: String = (lo.0 - 1..=hi.0 + 1)
            .map(|x| {
                let t = (x, y);
                match kind_at(t) {
                    Some(TileKind::Door) => return 'D',
                    Some(TileKind::Wall) => return 'W',
                    Some(TileKind::Furniture) => return 'f',
                    _ => {}
                }
                if map.blocked(t) {
                    '#'
                } else if reached.contains(t) {
                    '.'
                } else {
                    ':'
                }
            })
            .collect();
        rows.push(row);
    }
    rows.join("\n")
}

/// Every tile of a square a person can walk to from `start`, one bit per
/// tile.
struct Reached {
    origin: Cell,
    side: (i32, i32),
    bits: Vec<u64>,
}

impl Reached {
    fn index(&self, c: Cell) -> Option<usize> {
        let (x, y) = (c.0 - self.origin.0, c.1 - self.origin.1);
        (x >= 0 && y >= 0 && x < self.side.0 && y < self.side.1).then(|| (y * self.side.0 + x) as usize)
    }

    fn contains(&self, c: Cell) -> bool {
        self.index(c).is_some_and(|i| self.bits[i / 64] & (1 << (i % 64)) != 0)
    }

    fn insert(&mut self, c: Cell) {
        if let Some(i) = self.index(c) {
            self.bits[i / 64] |= 1 << (i % 64);
        }
    }
}

/// Flood the open tiles of the square from `lo` to `hi` (tiles) from
/// `start`, straight steps only (a diagonal step needs both tiles beside
/// it open, so straight steps reach the same tiles).
fn flood(map: &mut WalkMap, lo: Cell, hi: Cell, start: Cell) -> Reached {
    let side = (hi.0 - lo.0 + 1, hi.1 - lo.1 + 1);
    let mut reached = Reached {
        origin: lo,
        side,
        bits: vec![0; ((side.0 * side.1) as usize).div_ceil(64)],
    };
    let mut todo = vec![start];
    reached.insert(start);
    while let Some(c) = todo.pop() {
        for n in [(c.0 + 1, c.1), (c.0 - 1, c.1), (c.0, c.1 + 1), (c.0, c.1 - 1)] {
            if reached.index(n).is_some() && !reached.contains(n) && !map.blocked(n) {
                reached.insert(n);
                todo.push(n);
            }
        }
    }
    reached
}
