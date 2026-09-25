//! The walk grid (topside docs/pathing.md, Endless's design): which
//! cells a person can stand in, built from the solid things in the world
//! as plain data, never asked of the physics world during a search.
//!
//! The world is cut into chunks of `CHUNK` by `CHUNK` cells of `CELL`
//! metres. A chunk is painted the first time a search needs it (Factorio
//! makes its map chunk by chunk as it is needed), from the rectangles of
//! the solid things that touch it, and repainted when one of those
//! changes; ground nobody walks costs nothing. A wall thinner than a cell
//! still blocks: every solid is grown by `INFLATE` (a person's clearance)
//! and a cell is blocked when its centre falls inside, so a 0.2 m wall
//! covers a row of centres and a 1.2 m doorway keeps two open.
//!
//! The consumer adds and removes solids by its own key (an entity) and
//! asks for ways; the search is modforge's one A* (`path::grid_path`).

use std::cell::RefCell;
use std::collections::{HashMap, HashSet};

use glam::Vec2;

use crate::path::{Cell, grid_path};

/// Metres per cell.
pub const CELL: f32 = 0.5;
/// Cells per chunk side (16 m).
pub const CHUNK: i32 = 32;
/// How much every solid is grown before painting: a person's clearance,
/// and more than half a cell so a thin wall always covers a row of
/// centres.
pub const INFLATE: f32 = 0.3;

/// A chunk, by its column and row.
pub type ChunkKey = (i32, i32);

/// A solid rectangle on the ground, world metres.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Rect {
    pub min: Vec2,
    pub max: Vec2,
}

impl Rect {
    pub fn around(centre: Vec2, size: Vec2) -> Self {
        Self {
            min: centre - size / 2.0,
            max: centre + size / 2.0,
        }
    }

    fn grown(self, by: f32) -> Self {
        Self {
            min: self.min - Vec2::splat(by),
            max: self.max + Vec2::splat(by),
        }
    }

    fn contains(self, p: Vec2) -> bool {
        p.x >= self.min.x && p.x <= self.max.x && p.y >= self.min.y && p.y <= self.max.y
    }
}

/// One painted chunk: a bit per cell, row by row, set when blocked.
type Painted = [u64; (CHUNK * CHUNK / 64) as usize];

/// The cell a point falls in.
pub fn cell_of(p: Vec2) -> Cell {
    ((p.x / CELL).floor() as i32, (p.y / CELL).floor() as i32)
}

/// A cell's centre in world metres.
pub fn centre(c: Cell) -> Vec2 {
    Vec2::new((c.0 as f32 + 0.5) * CELL, (c.1 as f32 + 0.5) * CELL)
}

fn chunk_of(c: Cell) -> ChunkKey {
    (c.0.div_euclid(CHUNK), c.1.div_euclid(CHUNK))
}

/// Every solid, where it touches, and the chunks painted so far.
#[derive(Default)]
pub struct WalkMap {
    solids: HashMap<u64, Vec<Rect>>,
    by_chunk: HashMap<ChunkKey, HashSet<u64>>,
    painted: HashMap<ChunkKey, Painted>,
}

/// The chunks a grown rectangle touches.
fn chunks_under(r: Rect) -> impl Iterator<Item = ChunkKey> {
    let (lo, hi) = (chunk_of(cell_of(r.min)), chunk_of(cell_of(r.max)));
    (lo.1..=hi.1).flat_map(move |cy| (lo.0..=hi.0).map(move |cx| (cx, cy)))
}

impl WalkMap {
    /// A solid thing under `key` stands on these rectangles (a wall, a
    /// building's parts, water, a tree). Replaces what `key` had.
    pub fn add(&mut self, key: u64, rects: Vec<Rect>) {
        self.remove(key);
        for r in &rects {
            for chunk in chunks_under(r.grown(INFLATE)) {
                self.by_chunk.entry(chunk).or_default().insert(key);
                self.painted.remove(&chunk);
            }
        }
        self.solids.insert(key, rects);
    }

    /// `key` is gone: the chunks it touched are painted again when next
    /// needed.
    pub fn remove(&mut self, key: u64) {
        let Some(rects) = self.solids.remove(&key) else {
            return;
        };
        for r in rects {
            for chunk in chunks_under(r.grown(INFLATE)) {
                if let Some(keys) = self.by_chunk.get_mut(&chunk) {
                    keys.remove(&key);
                }
                self.painted.remove(&chunk);
            }
        }
    }

    /// Everything gone (the storm rolled a new world).
    pub fn clear(&mut self) {
        *self = Self::default();
    }

    /// How many chunks are painted: what the walk grid costs so far.
    pub fn painted_chunks(&self) -> usize {
        self.painted.len()
    }

    fn paint(solids: &HashMap<u64, Vec<Rect>>, by_chunk: &HashMap<ChunkKey, HashSet<u64>>, chunk: ChunkKey) -> Painted {
        let mut bits: Painted = [0; (CHUNK * CHUNK / 64) as usize];
        let Some(keys) = by_chunk.get(&chunk) else {
            return bits;
        };
        let first = (chunk.0 * CHUNK, chunk.1 * CHUNK);
        for key in keys {
            for r in solids.get(key).into_iter().flatten() {
                let g = r.grown(INFLATE);
                let (lo, hi) = (cell_of(g.min), cell_of(g.max));
                for y in lo.1.max(first.1)..=hi.1.min(first.1 + CHUNK - 1) {
                    for x in lo.0.max(first.0)..=hi.0.min(first.0 + CHUNK - 1) {
                        if g.contains(centre((x, y))) {
                            let i = ((y - first.1) * CHUNK + (x - first.0)) as usize;
                            bits[i / 64] |= 1 << (i % 64);
                        }
                    }
                }
            }
        }
        bits
    }

    /// Whether a person cannot stand in `c`; paints its chunk if needed.
    pub fn blocked(&mut self, c: Cell) -> bool {
        let chunk = chunk_of(c);
        let bits = match self.painted.get(&chunk) {
            Some(b) => b,
            None => {
                let b = Self::paint(&self.solids, &self.by_chunk, chunk);
                self.painted.entry(chunk).or_insert(b)
            }
        };
        let i = ((c.1 - chunk.1 * CHUNK) * CHUNK + (c.0 - chunk.0 * CHUNK)) as usize;
        bits[i / 64] & (1 << (i % 64)) != 0
    }

    /// Every cell on the straight line from `a` to `b` can be stood in
    /// (Bresenham, Endless's `line_of_sight`): walk straight, no search.
    pub fn line_clear(&mut self, a: Vec2, b: Vec2) -> bool {
        let (from, to) = (cell_of(a), cell_of(b));
        let (dx, dy) = ((to.0 - from.0).abs(), (to.1 - from.1).abs());
        let (sx, sy) = ((to.0 - from.0).signum(), (to.1 - from.1).signum());
        let (mut x, mut y, mut err) = (from.0, from.1, dx - dy);
        loop {
            if (x, y) != from && (x, y) != to && self.blocked((x, y)) {
                return false;
            }
            if (x, y) == to {
                return true;
            }
            let e2 = 2 * err;
            if e2 > -dy {
                err -= dy;
                x += sx;
            }
            if e2 < dx {
                err += dx;
                y += sy;
            }
        }
    }

    /// The way from `from` to `to` as points to walk through, ending at
    /// `to`; None when there is none within `limit` cells searched. The
    /// cells the person stands in and walks to always count as open
    /// (they stand there; the goal may be a box). A diagonal step needs
    /// both cells beside it open, so no corner is cut through a wall.
    pub fn find_way(&mut self, from: Vec2, to: Vec2, limit: usize) -> Option<Vec<Vec2>> {
        let (start, goal) = (cell_of(from), cell_of(to));
        let map = RefCell::new(self);
        let open = |c: Cell| c == start || c == goal || !map.borrow_mut().blocked(c);
        let step = |a: Cell, b: Cell| {
            if !open(b) {
                return None;
            }
            if a.0 != b.0 && a.1 != b.1 {
                (open((b.0, a.1)) && open((a.0, b.1))).then_some(std::f32::consts::SQRT_2)
            } else {
                Some(1.0)
            }
        };
        let estimate = |c: Cell| centre(c).distance(centre(goal)) / CELL;
        let cells = grid_path(start, goal, step, estimate, limit)?;
        let mut points: Vec<Vec2> = cells.into_iter().skip(1).map(centre).collect();
        points.pop();
        points.push(to);
        Some(points)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A wall 0.2 m thick from x = -5 to 5 along y = 0, with a doorway
    /// 1.2 m wide in the middle when `door` is true.
    fn wall(map: &mut WalkMap, door: bool) {
        let t = 0.2;
        if door {
            map.add(1, vec![Rect::around(Vec2::new(-2.8, 0.0), Vec2::new(4.4, t))]);
            map.add(2, vec![Rect::around(Vec2::new(2.8, 0.0), Vec2::new(4.4, t))]);
        } else {
            map.add(1, vec![Rect::around(Vec2::ZERO, Vec2::new(10.0, t))]);
        }
    }

    #[test]
    fn a_thin_wall_blocks_the_straight_line_and_the_way_goes_round() {
        let mut map = WalkMap::default();
        wall(&mut map, false);
        let (a, b) = (Vec2::new(0.0, -3.0), Vec2::new(0.0, 3.0));
        assert!(!map.line_clear(a, b), "a 0.2 m wall stops the straight line");
        let way = map.find_way(a, b, 20_000).expect("a way round the end");
        assert!(way.iter().any(|p| p.x.abs() > 5.0), "round the wall's end: {way:?}");
        assert_eq!(*way.last().unwrap(), b);
    }

    #[test]
    fn a_doorway_keeps_the_way_through() {
        let mut map = WalkMap::default();
        wall(&mut map, true);
        let (a, b) = (Vec2::new(0.0, -3.0), Vec2::new(0.0, 3.0));
        let way = map.find_way(a, b, 20_000).expect("through the door");
        assert!(way.iter().all(|p| p.x.abs() < 1.0), "straight through the doorway: {way:?}");
    }

    #[test]
    fn a_removed_wall_opens_the_line() {
        let mut map = WalkMap::default();
        wall(&mut map, false);
        let (a, b) = (Vec2::new(0.0, -3.0), Vec2::new(0.0, 3.0));
        assert!(!map.line_clear(a, b));
        map.remove(1);
        assert!(map.line_clear(a, b), "the wall is gone");
    }

    #[test]
    fn only_the_ground_searched_is_painted_and_far_out_works() {
        let mut map = WalkMap::default();
        let far = Vec2::new(-400_000.0, 250_000.0);
        map.add(9, vec![Rect::around(far, Vec2::new(10.0, 0.2))]);
        let way = map.find_way(far - Vec2::Y * 3.0, far + Vec2::Y * 3.0, 20_000).expect("round it");
        assert!(way.len() > 2);
        assert!(map.painted_chunks() < 20, "{} chunks painted", map.painted_chunks());
    }

    #[test]
    fn nothing_found_within_the_limit_is_none() {
        let mut map = WalkMap::default();
        // A closed box of walls round the goal.
        let (lo, hi) = (Vec2::splat(-3.0), Vec2::splat(3.0));
        map.add(
            1,
            vec![
                Rect { min: Vec2::new(lo.x, lo.y), max: Vec2::new(hi.x, lo.y + 0.2) },
                Rect { min: Vec2::new(lo.x, hi.y - 0.2), max: Vec2::new(hi.x, hi.y) },
                Rect { min: Vec2::new(lo.x, lo.y), max: Vec2::new(lo.x + 0.2, hi.y) },
                Rect { min: Vec2::new(hi.x - 0.2, lo.y), max: Vec2::new(hi.x, hi.y) },
            ],
        );
        assert!(map.find_way(Vec2::new(10.0, 0.0), Vec2::ZERO, 5_000).is_none());
    }
}
