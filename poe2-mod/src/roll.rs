//! Rolling away from enemies that come too close (operator,
//! 2026-11-07: WASD movement is on, so the roll goes the way the move
//! keys point). No prior art in GameHelper2 or ExileCore2.
//!
//! The way away is the sum of the unit vectors from each close enemy to
//! the player on the screen, so two enemies on the left and one on the
//! top send the roll down and right. It is snapped to one of eight
//! ways, each one or two of the move keys (W is up on the screen).

use modforge::input::human::{Timing, Wait};
use serde::{Deserialize, Serialize};
use std::time::{Duration, Instant};

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct Settings {
    /// An enemy this many grid cells from the player or nearer sets a
    /// roll off.
    pub danger: f32,
    /// Between two rolls.
    pub pause: Wait,
    /// The game's dodge roll key.
    pub key: String,
    /// The move keys: up, left, down, right on the screen.
    pub up: String,
    pub left: String,
    pub down: String,
    pub right: String,
    pub timing: Timing,
}

impl Default for Settings {
    fn default() -> Self {
        Self {
            danger: 15.0,
            pause: Wait::new(900, 1400),
            key: "space".into(),
            up: "w".into(),
            left: "a".into(),
            down: "s".into(),
            right: "d".into(),
            timing: Timing {
                react: Wait::new(5, 40),
                step: Wait::new(30, 60),
                settle: Wait::new(15, 35),
                hold: Wait::new(30, 70),
            },
        }
    }
}

/// Which move keys point which way on the screen.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Way {
    Up,
    Left,
    Down,
    Right,
}

/// The ways (one or two) nearest to the screen direction `d` (x right,
/// y down), in eight steps of 45 degrees.
pub fn ways(d: [f32; 2]) -> Vec<Way> {
    if d[0] == 0.0 && d[1] == 0.0 {
        return Vec::new();
    }
    // Angle with 0 right, 90 down.
    let a = d[1].atan2(d[0]).to_degrees().rem_euclid(360.0);
    let step = ((a + 22.5) / 45.0).floor() as i32 % 8;
    match step {
        0 => vec![Way::Right],
        1 => vec![Way::Down, Way::Right],
        2 => vec![Way::Down],
        3 => vec![Way::Down, Way::Left],
        4 => vec![Way::Left],
        5 => vec![Way::Up, Way::Left],
        6 => vec![Way::Up],
        _ => vec![Way::Up, Way::Right],
    }
}

/// The way away from the enemies at `threats` (screen points) for a
/// player at `me`: the sum of the unit vectors from each to the player.
pub fn away(me: [f32; 2], threats: &[[f32; 2]]) -> [f32; 2] {
    threats.iter().fold([0.0, 0.0], |acc, t| {
        let d = [me[0] - t[0], me[1] - t[1]];
        let n = d[0].hypot(d[1]);
        if n < 1e-3 {
            acc
        } else {
            [acc[0] + d[0] / n, acc[1] + d[1] / n]
        }
    })
}

/// What rolling remembers.
#[derive(Debug, Default)]
pub struct State {
    last: Option<Instant>,
    pause: Duration,
}

impl State {
    /// May a roll go now?
    pub fn ready(&self, now: Instant) -> bool {
        self.last
            .is_none_or(|t| now.duration_since(t) >= self.pause)
    }

    pub fn rolled(&mut self, s: &Settings, now: Instant, rng: &mut fastrand::Rng) {
        self.last = Some(now);
        self.pause = Duration::from_millis(u64::from(s.pause.draw(rng)));
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn eight_ways_on_the_screen() {
        assert_eq!(ways([1.0, 0.0]), vec![Way::Right]);
        assert_eq!(ways([0.0, -1.0]), vec![Way::Up]);
        assert_eq!(ways([-1.0, 1.0]), vec![Way::Down, Way::Left]);
        assert_eq!(ways([1.0, -1.0]), vec![Way::Up, Way::Right]);
        assert_eq!(ways([-1.0, 0.1]), vec![Way::Left]);
        assert!(ways([0.0, 0.0]).is_empty());
    }

    #[test]
    fn away_from_the_enemies() {
        let me = [500.0, 500.0];
        // One on the left: roll right.
        assert_eq!(ways(away(me, &[[400.0, 500.0]])), vec![Way::Right]);
        // Two on the left, one above: down and right.
        let d = away(me, &[[400.0, 500.0], [400.0, 510.0], [500.0, 400.0]]);
        assert_eq!(ways(d), vec![Way::Down, Way::Right]);
    }

    #[test]
    fn pauses_between_rolls() {
        let s = Settings::default();
        let mut st = State::default();
        let mut rng = fastrand::Rng::with_seed(3);
        let t0 = Instant::now();
        assert!(st.ready(t0));
        st.rolled(&s, t0, &mut rng);
        assert!(!st.ready(t0 + Duration::from_millis(500)));
        assert!(st.ready(t0 + Duration::from_millis(1500)));
    }
}
