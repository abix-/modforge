//! The world's history before the player wakes (topside todo History 1;
//! operator, 2026-11-23: "a history of like 1 week beforehand... a
//! calculated history. We don't actually run the game. You just roll the
//! events exactly, and then the events become history"). Prior art: Dwarf
//! Fortress's world generation, which rolls its history as events over
//! its figures and sites and never runs the game; the map is then laid
//! down from what happened. Here the figures are the world's people, the
//! places where they live and go, and the events what each day did. The
//! consumer lays them down: where each ends, who died where, what was
//! taken, each in its people's memory. Every odd here is Claude's.

use crate::monument::Roll;

/// One person in the history: their id, their kind (a raider, a wolf), their
/// group (faction), and the place they start the week at (their home, an
/// index into the places).
#[derive(Clone, Debug, PartialEq)]
pub struct Figure {
    pub id: u64,
    pub kind: String,
    pub group: Option<String>,
    pub home: usize,
}

/// What one day of the history did.
#[derive(Clone, Debug, PartialEq)]
pub enum Event {
    /// `who` went to the place and stayed.
    Moved { day: u32, who: u64, to: usize },
    /// `who` and `with` fought at the place, neither died.
    Fought { day: u32, who: u64, with: u64, at: usize },
    /// `who` was killed at the place by `by`.
    Died { day: u32, who: u64, by: u64, at: usize },
    /// `who` took something from the place, not their home.
    Took { day: u32, who: u64, at: usize },
}

/// Each day, of 1000: a living person goes to another place.
const MOVES: u64 = 250;
/// A fight ends with one dead.
const KILLS: u64 = 400;
/// A person at a place not their home takes something.
const TAKES: u64 = 350;

/// Rolls `days` days of history over the figures and `places` places, the
/// same events every time for a seed. `fights` gives, of 1000, the chance
/// that two figures meeting at a place come to blows (operator,
/// 2026-11-23: raiders are hostile by definition, scavengers and wolves
/// might be, "all of those is a chance for hostility to occur... then we
/// roll it to see what happens"). Answers every event in the order it
/// happened.
pub fn roll(figures: &[Figure], places: usize, days: u32, fights: &dyn Fn(&Figure, &Figure) -> u64, seed: u64) -> Vec<Event> {
    let mut roll = Roll::new(seed);
    let mut at: Vec<usize> = figures.iter().map(|f| f.home).collect();
    let mut alive = vec![true; figures.len()];
    let mut events = Vec::new();
    if places == 0 {
        return events;
    }
    // Every place a figure can be: the rolled ones, and any home past them.
    let size = at.iter().copied().max().map_or(places, |home| places.max(home + 1));
    let mut by_place: Vec<Vec<usize>> = vec![Vec::new(); size];
    for day in 0..days {
        for (i, f) in figures.iter().enumerate() {
            if alive[i] && roll.chance(MOVES) {
                let to = roll.next(places as u64) as usize;
                if to != at[i] {
                    at[i] = to;
                    events.push(Event::Moved { day, who: f.id, to });
                }
            }
        }
        // Who is at each place, in order: a pair meets only where both
        // are, taken in the same order as every pair would be (i, then
        // each j after it), so the rolls fall the same.
        for here in by_place.iter_mut() {
            here.clear();
        }
        for (i, place) in at.iter().enumerate() {
            by_place[*place].push(i);
        }
        for i in 0..figures.len() {
            let here = &by_place[at[i]];
            let after = here.partition_point(|&k| k <= i);
            for &j in &here[after..] {
                if !(alive[i] && alive[j]) {
                    continue;
                }
                let (a, b) = (&figures[i], &figures[j]);
                if !roll.chance(fights(a, b)) {
                    continue;
                }
                if roll.chance(KILLS) {
                    let (dead, killer) = if roll.chance(500) { (j, i) } else { (i, j) };
                    alive[dead] = false;
                    events.push(Event::Died { day, who: figures[dead].id, by: figures[killer].id, at: at[i] });
                } else {
                    events.push(Event::Fought { day, who: a.id, with: b.id, at: at[i] });
                }
            }
        }
        for (i, f) in figures.iter().enumerate() {
            if alive[i] && at[i] != f.home && roll.chance(TAKES) {
                events.push(Event::Took { day, who: f.id, at: at[i] });
            }
        }
    }
    events
}

/// Where each figure is when the history ends: its last move, else home.
pub fn ends_at(figures: &[Figure], events: &[Event]) -> Vec<usize> {
    figures
        .iter()
        .map(|f| {
            events
                .iter()
                .rev()
                .find_map(|e| match e {
                    Event::Moved { who, to, .. } if *who == f.id => Some(*to),
                    _ => None,
                })
                .unwrap_or(f.home)
        })
        .collect()
}
