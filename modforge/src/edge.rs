//! The edge (topside todo 11i, operator 2026-10-02): the one faucet of what
//! enters the world from beyond it, lifted from survivalist-mod's incursion
//! (`spawn_band_at_edge`: a band comes in at a point past the camps, at an
//! angle rolled from the clock). Here, game-free: where a group comes in
//! (on the rim of the world's places, at a rolled angle), how many (2 to
//! 4), when word of a place reaches the edge, and when the next group may
//! come (at most one a game hour). The consumer spawns the people and sends
//! them to the place.

use serde::{Deserialize, Serialize};

use crate::storyteller::point_at_angle;

/// How many come in one group.
pub const GROUP_MIN: u32 = 2;
pub const GROUP_MAX: u32 = 4;

/// At most one group in this many game seconds: a game hour (operator,
/// 2026-10-02).
pub const GROUP_EVERY_SECS: f32 = 3600.0;

/// Word of a place on its way to the edge: the place's key and where it
/// is, the point where it reaches the edge and the group will come in, and
/// the tick it gets there.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct Word {
    pub key: u64,
    /// What the place is ("tap"), as the one who told it knew it.
    pub kind: String,
    pub place: (f32, f32, f32),
    pub edge: (f32, f32),
    pub reaches_at: u64,
}

/// The edge's state: word on its way, and the tick the next group may come
/// at.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Edge {
    pub word: Vec<Word>,
    pub next_group_at: u64,
}

impl Edge {
    /// Word of a place set out for the edge; word of a place already on
    /// its way is not sent twice.
    pub fn told(&mut self, word: Word) {
        if !self.word.iter().any(|w| w.key == word.key) {
            self.word.push(word);
        }
    }

    /// The word a group comes for now, if any: the first that has reached
    /// the edge, once the next group may come; then the one after may not
    /// come for `every` ticks.
    pub fn due(&mut self, now: u64, every: u64) -> Option<Word> {
        if now < self.next_group_at {
            return None;
        }
        let i = self.word.iter().position(|w| w.reaches_at <= now)?;
        self.next_group_at = now + every;
        Some(self.word.remove(i))
    }
}

/// Where the edge is at a rolled angle: as far from `centre` as the
/// farthest of `places`, so past every place and still in the world.
pub fn edge_point(centre: (f32, f32), places: &[(f32, f32)], roll: u64) -> Option<(f32, f32)> {
    let rim = places.iter().map(|p| ((p.0 - centre.0).powi(2) + (p.1 - centre.1).powi(2)).sqrt()).fold(None, |m: Option<f32>, d| Some(m.map_or(d, |m| m.max(d))))?;
    let angle = (roll % 6283) as f64 / 1000.0;
    let (x, y) = point_at_angle((centre.0 as i64, centre.1 as i64), angle, rim as f64);
    Some((x as f32, y as f32))
}

/// How many come in a group, rolled.
pub fn group_size(roll: u64) -> u32 {
    GROUP_MIN + (roll % u64::from(GROUP_MAX - GROUP_MIN + 1)) as u32
}

#[cfg(test)]
mod tests {
    use super::*;

    fn word(key: u64, reaches_at: u64) -> Word {
        Word { key, kind: "tap".to_string(), place: (0.0, 0.0, 0.0), edge: (100.0, 0.0), reaches_at }
    }

    #[test]
    fn a_group_comes_once_word_reaches_the_edge_and_not_again_for_an_hour() {
        let mut edge = Edge::default();
        edge.told(word(7, 100));
        assert_eq!(edge.due(50, 1000), None, "the word has not reached the edge yet");
        assert_eq!(edge.due(100, 1000).map(|w| w.key), Some(7));
        edge.told(word(7, 150));
        assert_eq!(edge.due(500, 1000), None, "the next group not before the hour is out");
        assert_eq!(edge.due(1100, 1000).map(|w| w.key), Some(7));
    }

    #[test]
    fn word_of_one_place_is_not_sent_twice() {
        let mut edge = Edge::default();
        edge.told(word(7, 100));
        edge.told(word(7, 200));
        assert_eq!(edge.word.len(), 1);
    }

    #[test]
    fn the_edge_is_as_far_out_as_the_farthest_place() {
        let at = edge_point((0.0, 0.0), &[(100.0, 0.0), (0.0, 300.0)], 1571).expect("a point");
        let d = (at.0.powi(2) + at.1.powi(2)).sqrt();
        assert!((d - 300.0).abs() < 2.0, "the edge at {at:?}, {d} out");
        assert_eq!(edge_point((0.0, 0.0), &[], 3), None);
    }

    #[test]
    fn a_group_is_two_to_four() {
        for roll in 0..20 {
            assert!((GROUP_MIN..=GROUP_MAX).contains(&group_size(roll)));
        }
    }
}
