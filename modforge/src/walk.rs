//! The walk grid (topside docs/pathing.md, Endless's design): which
//! tiles a person can stand on, built from the solid things in the world
//! as plain data, never asked of the physics world during a search.
//!
//! One grid, the Factorio way (pathing.md "One grid"): a tile is `TILE`
//! metres, a chunk is `CHUNK` by `CHUNK` tiles, the same tiles the
//! buildings sit on. A chunk is painted the first time a search needs it
//! (Factorio makes its map chunk by chunk as it is needed), from the
//! rectangles of the solid things that touch it, and repainted when one
//! of those changes; ground nobody walks costs nothing. A tile is
//! blocked when anything solid covers any of it; a wall on the tiles
//! covers exactly its own.
//!
//! The consumer adds and removes solids by its own key (an entity) and
//! asks for ways; the search is modforge's one A* (`path::grid_path`).

use std::cell::RefCell;
use std::collections::{HashMap, HashSet};

use glam::Vec2;

use crate::path::{Cell, search};

/// Metres per tile.
pub const TILE: f32 = 1.0;
/// Tiles per chunk side.
pub const CHUNK: i32 = 32;

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

    /// It covers some of tile `t` (touching an edge is not covering).
    fn covers(self, t: Cell) -> bool {
        let (lo, hi) = (Vec2::new(t.0 as f32, t.1 as f32) * TILE, Vec2::new(t.0 as f32 + 1.0, t.1 as f32 + 1.0) * TILE);
        self.min.x < hi.x && self.max.x > lo.x && self.min.y < hi.y && self.max.y > lo.y
    }
}

/// One painted chunk: a bit per cell, row by row, set when blocked.
type Painted = [u64; (CHUNK * CHUNK / 64) as usize];

/// The tile a point stands on.
pub fn cell_of(p: Vec2) -> Cell {
    ((p.x / TILE).floor() as i32, (p.y / TILE).floor() as i32)
}

/// A tile's centre in world metres.
pub fn centre(c: Cell) -> Vec2 {
    Vec2::new((c.0 as f32 + 0.5) * TILE, (c.1 as f32 + 0.5) * TILE)
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
    /// Each chunk's doorways and the ways between them.
    ways: HashMap<ChunkKey, ChunkWays>,
    /// How many tiles the last `find_way` flooded: what it cost.
    pub last_searched: usize,
}

/// The chunks a rectangle touches.
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
            for chunk in chunks_under(*r) {
                self.by_chunk.entry(chunk).or_default().insert(key);
                self.forget(chunk);
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
            for chunk in chunks_under(r) {
                if let Some(keys) = self.by_chunk.get_mut(&chunk) {
                    keys.remove(&key);
                }
                self.forget(chunk);
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
                let (lo, hi) = (cell_of(r.min), cell_of(r.max));
                for y in lo.1.max(first.1)..=hi.1.min(first.1 + CHUNK - 1) {
                    for x in lo.0.max(first.0)..=hi.0.min(first.0 + CHUNK - 1) {
                        if r.covers((x, y)) {
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

    /// A person can stand at `p`.
    pub fn standable(&mut self, p: Vec2) -> bool {
        !self.blocked(cell_of(p))
    }

    /// The chunk around `p` as the walk grid sees it, for looking at,
    /// drawn from the tile `p` stands on (marked `mark`): one line per row
    /// of tiles, top row first. `#` blocked; `.` open and reachable from
    /// the marked tile inside the chunk; `:` open but not reachable from
    /// it; `D` a doorway to the next chunk it can reach, `x` one it
    /// cannot. And how many doorways it reaches.
    pub fn picture(&mut self, p: Vec2, mark: char) -> ChunkPicture {
        let at = cell_of(p);
        let key = chunk_of(at);
        let (x0, y0) = (key.0 * CHUNK, key.1 * CHUNK);
        let doors = self.doors_of(key);
        let flood = self.flood(at, None);
        let reach = |t: Cell| t == at || flood.way_to(t).is_some();
        let reached = doors.iter().filter(|d| reach(**d)).count();
        let rows = (0..CHUNK)
            .rev()
            .map(|dy| {
                (0..CHUNK)
                    .map(|dx| {
                        let t = (x0 + dx, y0 + dy);
                        if t == at {
                            mark
                        } else if doors.contains(&t) {
                            if reach(t) { 'D' } else { 'x' }
                        } else if self.blocked(t) {
                            '#'
                        } else if reach(t) {
                            '.'
                        } else {
                            ':'
                        }
                    })
                    .collect()
            })
            .collect();
        ChunkPicture {
            chunk: key,
            tile: at,
            rows,
            doorways: doors.len(),
            reached,
        }
    }

    /// The centre of the nearest tile a person can stand on, within
    /// `within` tiles of `p`, if any: where to go instead of a blocked
    /// spot.
    pub fn nearest_standable(&mut self, p: Vec2, within: i32) -> Option<Vec2> {
        let c = cell_of(p);
        (0..=within).find_map(|r| {
            let ring: Vec<Cell> = (-r..=r)
                .flat_map(|dy| (-r..=r).map(move |dx| (c.0 + dx, c.1 + dy)))
                .filter(|t| (t.0 - c.0).abs() == r || (t.1 - c.1).abs() == r)
                .collect();
            ring.into_iter().find(|t| !self.blocked(*t)).map(centre)
        })
    }

    /// A chunk and its four neighbours changed: their doorways and the
    /// ways between them are worked out again when next needed.
    fn forget(&mut self, chunk: ChunkKey) {
        self.painted.remove(&chunk);
        for k in [chunk, (chunk.0 - 1, chunk.1), (chunk.0 + 1, chunk.1), (chunk.0, chunk.1 - 1), (chunk.0, chunk.1 + 1)] {
            self.ways.remove(&k);
        }
    }

    /// Every tile of `origin`'s chunk reachable from it inside the chunk,
    /// cheapest first (Dijkstra over at most `CHUNK` by `CHUNK` tiles, in
    /// plain arrays). `also` counts as open even if blocked (a goal that
    /// is a thing, a box). A diagonal step needs both tiles beside it
    /// open, so no corner is cut through a wall.
    fn flood(&mut self, origin: Cell, also: Option<Cell>) -> Flood {
        let key = chunk_of(origin);
        let (x0, y0) = (key.0 * CHUNK, key.1 * CHUNK);
        let n = (CHUNK * CHUNK) as usize;
        let at = |i: usize| (x0 + i as i32 % CHUNK, y0 + i as i32 / CHUNK);
        let open: Vec<bool> = (0..n)
            .map(|i| {
                let c = at(i);
                c == origin || Some(c) == also || !self.blocked(c)
            })
            .collect();
        self.last_searched += n;
        let index = |c: Cell| {
            (c.0 >= x0 && c.0 < x0 + CHUNK && c.1 >= y0 && c.1 < y0 + CHUNK)
                .then(|| ((c.1 - y0) * CHUNK + (c.0 - x0)) as usize)
        };
        let mut cost = vec![f32::INFINITY; n];
        let mut came = vec![usize::MAX; n];
        let mut heap = std::collections::BinaryHeap::new();
        let start = index(origin).expect("the origin is in its chunk");
        cost[start] = 0.0;
        heap.push(Reverse(start, 0.0));
        while let Some(Reverse(i, c)) = heap.pop() {
            if c > cost[i] {
                continue;
            }
            let here = at(i);
            for (dx, dy) in NEIGHBOURS {
                let Some(j) = index((here.0 + dx, here.1 + dy)) else {
                    continue;
                };
                if !open[j] {
                    continue;
                }
                let step = if dx != 0 && dy != 0 {
                    let (a, b) = (index((here.0 + dx, here.1)), index((here.0, here.1 + dy)));
                    if !(a.is_some_and(|a| open[a]) && b.is_some_and(|b| open[b])) {
                        continue;
                    }
                    std::f32::consts::SQRT_2
                } else {
                    1.0
                };
                if c + step < cost[j] {
                    cost[j] = c + step;
                    came[j] = i;
                    heap.push(Reverse(j, c + step));
                }
            }
        }
        Flood { key, cost, came }
    }

    /// The doorways of a chunk: along each edge, the middle tile of each
    /// run of open tiles that meets open tiles in the neighbour (Endless's
    /// entrances). Both chunks of an edge find the same runs, so a
    /// doorway's partner across the edge is a doorway of the neighbour.
    fn doorways(&mut self, key: ChunkKey) -> Vec<Cell> {
        let (x0, y0) = (key.0 * CHUNK, key.1 * CHUNK);
        let edges = [
            ((x0, y0), (1, 0), (0, -1)),
            ((x0, y0 + CHUNK - 1), (1, 0), (0, 1)),
            ((x0, y0), (0, 1), (-1, 0)),
            ((x0 + CHUNK - 1, y0), (0, 1), (1, 0)),
        ];
        let mut out = Vec::new();
        for (first, along, beyond) in edges {
            let mut run: Option<i32> = None;
            for k in 0..=CHUNK {
                let open = k < CHUNK && {
                    let t = (first.0 + along.0 * k, first.1 + along.1 * k);
                    !self.blocked(t) && !self.blocked((t.0 + beyond.0, t.1 + beyond.1))
                };
                match (open, run) {
                    (true, None) => run = Some(k),
                    (false, Some(s)) => {
                        let m = (s + k - 1) / 2;
                        out.push((first.0 + along.0 * m, first.1 + along.1 * m));
                        run = None;
                    }
                    _ => {}
                }
            }
        }
        out.sort_unstable();
        out.dedup();
        out
    }

    /// A chunk's doorways, worked out once until it changes.
    fn doors_of(&mut self, key: ChunkKey) -> Vec<Cell> {
        if let Some(w) = self.ways.get(&key) {
            return w.doors.clone();
        }
        let doors = self.doorways(key);
        self.ways.insert(
            key,
            ChunkWays {
                doors: doors.clone(),
                from_door: HashMap::new(),
            },
        );
        doors
    }

    /// The ways inside its chunk from doorway `door` to every other
    /// doorway of the chunk it can reach: cost and tiles (without the
    /// doorway itself), from one flood, kept until the chunk changes.
    fn ways_from(&mut self, door: Cell) -> Vec<(Cell, f32, Vec<Cell>)> {
        let key = chunk_of(door);
        let doors = self.doors_of(key);
        if let Some(found) = self.ways.get(&key).and_then(|w| w.from_door.get(&door)) {
            return found.clone();
        }
        let flood = self.flood(door, None);
        let found: Vec<(Cell, f32, Vec<Cell>)> = doors
            .iter()
            .filter(|d| **d != door)
            .filter_map(|d| flood.way_to(*d).map(|(cost, tiles)| (*d, cost, tiles)))
            .collect();
        if let Some(w) = self.ways.get_mut(&key) {
            w.from_door.insert(door, found.clone());
        }
        found
    }

    /// The doorway across the edge from doorway `door`, in the
    /// neighbouring chunk, if that chunk has one there.
    fn across(&mut self, door: Cell) -> Vec<Cell> {
        let key = chunk_of(door);
        let (x0, y0) = (key.0 * CHUNK, key.1 * CHUNK);
        let mut out = Vec::new();
        for (on_edge, step) in [
            (door.1 == y0, (0, -1)),
            (door.1 == y0 + CHUNK - 1, (0, 1)),
            (door.0 == x0, (-1, 0)),
            (door.0 == x0 + CHUNK - 1, (1, 0)),
        ] {
            let partner = (door.0 + step.0, door.1 + step.1);
            if on_edge && self.doors_of(chunk_of(partner)).contains(&partner) {
                out.push(partner);
            }
        }
        out
    }

    /// The way from `from` to `to` as points to walk through, ending at
    /// `to`; None when there is none (pathing.md "Search by chunk, then
    /// across chunks"). In one chunk: that chunk's tiles only. Otherwise
    /// the search runs over the chunks' doorways, at most `limit` of
    /// them, and the ways inside each chunk are joined into the whole
    /// way. The tile walked from, and the one walked to (it may be a
    /// thing, a box), always count as open.
    pub fn find_way(&mut self, from: Vec2, to: Vec2, limit: usize) -> Option<Vec<Vec2>> {
        self.last_searched = 0;
        let (start, goal) = (cell_of(from), cell_of(to));
        let points = |tiles: Vec<Cell>| {
            let mut points: Vec<Vec2> = tiles.into_iter().map(centre).collect();
            points.pop();
            points.push(to);
            points
        };
        let from_start = self.flood(start, Some(goal));
        if chunk_of(start) == chunk_of(goal)
            && let Some((_, tiles)) = from_start.way_to(goal)
        {
            return Some(points(tiles));
        }
        // Out of the start's chunk by its doorways, into the goal's by its.
        let start_doors: HashMap<Cell, (f32, Vec<Cell>)> = self
            .doors_of(chunk_of(start))
            .into_iter()
            .filter_map(|d| from_start.way_to(d).map(|w| (d, w)))
            .collect();
        let from_goal = self.flood(goal, Some(goal));
        let goal_doors: HashMap<Cell, (f32, Vec<Cell>)> = self
            .doors_of(chunk_of(goal))
            .into_iter()
            .filter_map(|d| {
                from_goal.way_to(d).map(|(cost, tiles)| {
                    // Walked the other way: from the doorway to the goal.
                    let mut back: Vec<Cell> = std::iter::once(goal).chain(tiles).collect();
                    back.reverse();
                    (d, (cost, back.into_iter().skip(1).collect()))
                })
            })
            .collect();
        // Shut in, at either end: no doorway reached, so no way, known
        // without looking anywhere else.
        if start_doors.is_empty() || goal_doors.is_empty() {
            return None;
        }
        let map = RefCell::new(&mut *self);
        let next = |at: Cell| -> Vec<(Cell, f32)> {
            if at == start {
                return start_doors.iter().map(|(d, (c, _))| (*d, *c)).collect();
            }
            let mut out: Vec<(Cell, f32)> = Vec::new();
            if let Some((c, _)) = goal_doors.get(&at) {
                out.push((goal, *c));
            }
            let mut map = map.borrow_mut();
            out.extend(map.ways_from(at).into_iter().map(|(d, c, _)| (d, c)));
            out.extend(map.across(at).into_iter().map(|d| (d, 1.0)));
            out
        };
        let estimate = |c: Cell| centre(c).distance(centre(goal)) / TILE;
        let (doorways, _) = search(start, next, estimate, |c| c == goal, limit)?;
        // Join the ways: out of the start, inside each chunk, across each
        // edge, into the goal.
        let mut tiles = Vec::new();
        for pair in doorways.windows(2) {
            let (a, b) = (pair[0], pair[1]);
            if a == start {
                tiles.extend(start_doors[&b].1.iter().copied());
            } else if b == goal {
                tiles.extend(goal_doors[&a].1.iter().copied());
            } else if let Some((_, _, way)) = self.ways_from(a).into_iter().find(|(d, _, _)| *d == b) {
                tiles.extend(way);
            } else {
                tiles.push(b);
            }
        }
        Some(points(tiles))
    }
}

/// The eight neighbours, straight first.
const NEIGHBOURS: [(i32, i32); 8] = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, -1), (-1, 1), (1, 1)];

/// A heap entry, cheapest first.
struct Reverse(usize, f32);
impl PartialEq for Reverse {
    fn eq(&self, other: &Self) -> bool {
        self.1 == other.1
    }
}
impl Eq for Reverse {}
impl PartialOrd for Reverse {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for Reverse {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.1.total_cmp(&self.1)
    }
}

/// What a flood over one chunk found: the cost to each tile it reached
/// and the tile each was reached from.
struct Flood {
    key: ChunkKey,
    cost: Vec<f32>,
    came: Vec<usize>,
}

impl Flood {
    /// The cost to `to` and the tiles walked to it (without the origin),
    /// if the flood reached it.
    fn way_to(&self, to: Cell) -> Option<(f32, Vec<Cell>)> {
        let (x0, y0) = (self.key.0 * CHUNK, self.key.1 * CHUNK);
        if chunk_of(to) != self.key {
            return None;
        }
        let mut i = ((to.1 - y0) * CHUNK + (to.0 - x0)) as usize;
        let cost = self.cost[i];
        if !cost.is_finite() {
            return None;
        }
        let mut tiles = Vec::new();
        while self.came[i] != usize::MAX {
            tiles.push((x0 + i as i32 % CHUNK, y0 + i as i32 / CHUNK));
            i = self.came[i];
        }
        tiles.reverse();
        Some((cost, tiles))
    }
}

/// A chunk drawn from the walk grid (`WalkMap::picture`).
#[derive(Clone, Debug, PartialEq)]
pub struct ChunkPicture {
    pub chunk: ChunkKey,
    pub tile: Cell,
    /// Top row first: `#` blocked, `.` open and reachable from the marked
    /// tile, `:` open and not reachable, `D` a reachable doorway, `x` an
    /// unreachable one, and the marked tile.
    pub rows: Vec<String>,
    /// The chunk's doorways to its neighbours.
    pub doorways: usize,
    /// How many of them can be walked to from the tile.
    pub reached: usize,
}

/// One chunk's doorways and the ways between them, worked out as needed.
struct ChunkWays {
    doors: Vec<Cell>,
    from_door: HashMap<Cell, Vec<(Cell, f32, Vec<Cell>)>>,
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A wall on the tiles of row 0 from x = -5 to 5, with a doorway one
    /// tile wide (tile 0) when `door` is true.
    fn wall(map: &mut WalkMap, door: bool) {
        if door {
            map.add(1, vec![Rect { min: Vec2::new(-5.0, 0.0), max: Vec2::new(0.0, 1.0) }]);
            map.add(2, vec![Rect { min: Vec2::new(1.0, 0.0), max: Vec2::new(5.0, 1.0) }]);
        } else {
            map.add(1, vec![Rect { min: Vec2::new(-5.0, 0.0), max: Vec2::new(5.0, 1.0) }]);
        }
    }

    #[test]
    fn a_wall_blocks_the_straight_line_and_the_way_goes_round() {
        let mut map = WalkMap::default();
        wall(&mut map, false);
        let (a, b) = (Vec2::new(0.0, -3.0), Vec2::new(0.0, 3.0));
        assert!(!map.line_clear(a, b), "the wall stops the straight line");
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

    /// A way across chunks: 150 tiles east past a wall 60 tiles long,
    /// found over the chunks' doorways, the joined way walks only open
    /// tiles, and it never floods more than a handful of chunks.
    #[test]
    fn a_way_across_chunks_goes_round_a_long_wall() {
        let mut map = WalkMap::default();
        map.add(1, vec![Rect { min: Vec2::new(70.0, -30.0), max: Vec2::new(71.0, 30.0) }]);
        let (a, b) = (Vec2::new(0.5, 0.5), Vec2::new(150.5, 0.5));
        let way = map.find_way(a, b, 2_000).expect("round the wall");
        assert_eq!(*way.last().unwrap(), b);
        for p in &way[..way.len() - 1] {
            assert!(!map.blocked(cell_of(*p)), "the way stands on open tiles: {p}");
        }
        assert!(way.iter().any(|p| p.y.abs() >= 30.0), "round the wall's end");
        // Consecutive points are neighbouring tiles: nothing is skipped.
        for pair in way.windows(2) {
            assert!(pair[0].distance(pair[1]) <= 1.5, "a gap in the way: {} to {}", pair[0], pair[1]);
        }
    }

    /// A goal shut inside four walls is known unreachable by flooding
    /// its own chunk and the start's, not every tile around.
    #[test]
    fn an_unreachable_goal_costs_two_chunks_not_the_world() {
        let mut map = WalkMap::default();
        let (lo, hi) = (Vec2::new(100.0, 0.0), Vec2::new(106.0, 6.0));
        map.add(
            1,
            vec![
                Rect { min: lo, max: Vec2::new(hi.x, lo.y + 1.0) },
                Rect { min: Vec2::new(lo.x, hi.y - 1.0), max: hi },
                Rect { min: lo, max: Vec2::new(lo.x + 1.0, hi.y) },
                Rect { min: Vec2::new(hi.x - 1.0, lo.y), max: hi },
            ],
        );
        assert!(map.find_way(Vec2::new(0.5, 0.5), Vec2::new(103.5, 3.5), 2_000).is_none());
        let chunk = (CHUNK * CHUNK) as usize;
        assert!(map.last_searched <= 2 * chunk, "flooded {} tiles", map.last_searched);
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
