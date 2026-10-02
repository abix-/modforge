//! The map each person carries (topside life.md "The map each person
//! carries"): one bit per tile seen, kept per chunk, and the tick each
//! chunk was last seen. The player's is the same data (their minimap
//! draws it). What a person's eyes reach is recursive shadowcasting
//! (Bjorn Bergstrom's, RogueBasin "FOV using recursive shadowcasting")
//! over the tiles that block sight, so the inside of a building stays
//! unseen until they look in.

use std::collections::HashMap;

use crate::path::Cell;
use crate::walk::{CHUNK, ChunkKey};

/// One chunk of a map: which of its tiles were seen, and when last.
#[derive(Clone, Debug, Default, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct ChunkSeen {
    bits: [u64; 16],
    pub seen_at: u64,
}

/// What one person has seen of the world.
#[derive(Clone, Debug, Default, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct Map {
    chunks: HashMap<ChunkKey, ChunkSeen>,
}

/// The chunk a tile is in, and its bit in that chunk.
fn split(c: Cell) -> (ChunkKey, usize) {
    let key = (c.0.div_euclid(CHUNK), c.1.div_euclid(CHUNK));
    let bit = (c.1.rem_euclid(CHUNK) * CHUNK + c.0.rem_euclid(CHUNK)) as usize;
    (key, bit)
}

/// The eight octants of shadowcasting, as (xx, xy, yx, yy) turns.
const OCTANTS: [(i32, i32, i32, i32); 8] = [
    (1, 0, 0, 1),
    (0, 1, 1, 0),
    (0, -1, 1, 0),
    (-1, 0, 0, 1),
    (-1, 0, 0, -1),
    (0, -1, -1, 0),
    (0, 1, -1, 0),
    (1, 0, 0, -1),
];

impl Map {
    /// Mark tile `c` seen at tick `now`.
    pub fn see(&mut self, c: Cell, now: u64) {
        let (key, bit) = split(c);
        let chunk = self.chunks.entry(key).or_default();
        chunk.bits[bit / 64] |= 1 << (bit % 64);
        chunk.seen_at = now;
    }

    /// Whether tile `c` has been seen.
    pub fn seen(&self, c: Cell) -> bool {
        let (key, bit) = split(c);
        self.chunks.get(&key).is_some_and(|chunk| chunk.bits[bit / 64] & (1 << (bit % 64)) != 0)
    }

    /// How many tiles have been seen.
    pub fn tiles_seen(&self) -> usize {
        self.chunks.values().map(|c| c.bits.iter().map(|b| b.count_ones() as usize).sum::<usize>()).sum()
    }

    /// Join `other` into this map (topside life.md: what their bunker tells
    /// them): every tile either has seen is seen, and each chunk was last
    /// seen at the later of the two.
    pub fn join(&mut self, other: &Map) {
        for (key, theirs) in &other.chunks {
            let mine = self.chunks.entry(*key).or_default();
            for (a, b) in mine.bits.iter_mut().zip(theirs.bits) {
                *a |= b;
            }
            mine.seen_at = mine.seen_at.max(theirs.seen_at);
        }
    }

    /// When chunk `key` was last seen, if ever.
    pub fn chunk_seen_at(&self, key: ChunkKey) -> Option<u64> {
        self.chunks.get(&key).map(|c| c.seen_at)
    }

    /// Look around from tile `from`: every tile within `radius` the eyes
    /// reach is seen at `now`; a tile `opaque` says blocks sight is seen
    /// (a wall's face) but hides what is past it.
    pub fn look(&mut self, from: Cell, radius: i32, opaque: &mut dyn FnMut(Cell) -> bool, now: u64) {
        self.see(from, now);
        for (xx, xy, yx, yy) in OCTANTS {
            self.cast(from, 1, 1.0, 0.0, radius, (xx, xy, yx, yy), opaque, now);
        }
    }

    /// One octant's rows from `row` out, the light between the slopes
    /// `start` and `end` (RogueBasin's recursive shadowcasting).
    #[allow(clippy::too_many_arguments)]
    fn cast(
        &mut self,
        from: Cell,
        row: i32,
        mut start: f32,
        end: f32,
        radius: i32,
        (xx, xy, yx, yy): (i32, i32, i32, i32),
        opaque: &mut dyn FnMut(Cell) -> bool,
        now: u64,
    ) {
        if start < end {
            return;
        }
        let r2 = radius * radius;
        for j in row..=radius {
            let dy = -j;
            let mut dx = -j - 1;
            let mut blocked = false;
            let mut next_start = start;
            while dx <= 0 {
                dx += 1;
                let tile = (from.0 + dx * xx + dy * xy, from.1 + dx * yx + dy * yy);
                let left = (dx as f32 - 0.5) / (dy as f32 + 0.5);
                let right = (dx as f32 + 0.5) / (dy as f32 - 0.5);
                if start < right {
                    continue;
                }
                if end > left {
                    break;
                }
                if dx * dx + dy * dy < r2 {
                    self.see(tile, now);
                }
                let dark = opaque(tile);
                if blocked {
                    if dark {
                        next_start = right;
                    } else {
                        blocked = false;
                        start = next_start;
                    }
                } else if dark && j < radius {
                    blocked = true;
                    self.cast(from, j + 1, start, left, radius, (xx, xy, yx, yy), opaque, now);
                    next_start = right;
                }
            }
            if blocked {
                break;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Two maps joined: every tile either saw, each chunk at the later
    /// tick (topside todo 11af).
    #[test]
    fn two_maps_join() {
        let (mut a, mut b) = (Map::default(), Map::default());
        a.see((1, 1), 10);
        b.see((2, 2), 20);
        b.see((100, 0), 5);
        a.join(&b);
        assert!(a.seen((1, 1)) && a.seen((2, 2)) && a.seen((100, 0)));
        assert!(!a.seen((3, 3)));
        assert_eq!(a.chunk_seen_at((0, 0)), Some(20), "the later of the two");
        assert_eq!(a.chunk_seen_at((3, 0)), Some(5));
        assert_eq!(a.tiles_seen(), 3);
        assert_eq!(b.tiles_seen(), 2, "the other map is unchanged");
    }

    /// A closed room: walls round x 10..=16, y -3..=3.
    fn room_wall(c: Cell) -> bool {
        let on_x = c.0 == 10 || c.0 == 16;
        let on_y = c.1 == -3 || c.1 == 3;
        (on_x && (-3..=3).contains(&c.1)) || (on_y && (10..=16).contains(&c.0))
    }

    #[test]
    fn a_person_walking_past_a_building_does_not_see_inside_it() {
        let mut map = Map::default();
        map.look((0, 0), 25, &mut room_wall, 1);
        assert!(map.seen((10, 0)), "the wall's face is seen");
        assert!(map.seen((5, 5)) && map.seen((-20, 0)), "open ground around is seen");
        assert!(!map.seen((13, 0)), "the inside stays unseen");
        assert!(!map.seen((30, 0)), "past the radius stays unseen");
        let before = map.tiles_seen();
        // Stepping inside, the room is seen.
        map.look((13, 0), 25, &mut room_wall, 2);
        assert!(map.seen((13, 0)) && map.seen((15, 2)));
        assert!(map.tiles_seen() > before);
        assert_eq!(map.chunk_seen_at((0, 0)), Some(2), "the chunk was last seen at the second look");
    }

    #[test]
    fn tiles_on_both_sides_of_a_chunk_edge_are_kept_apart() {
        let mut map = Map::default();
        map.see((-1, -1), 1);
        assert!(map.seen((-1, -1)));
        assert!(!map.seen((31, 31)) && !map.seen((0, 0)));
        assert_eq!(map.tiles_seen(), 1);
    }
}
