//! Left clicking the nearest enemy, for the operator (2026-11-07: "on
//! left click on enemy does one cast"). No prior art in GameHelper2 or
//! ExileCore2; enemies are chosen as GameHelper2's HealthBars takes
//! monsters (kinds::classify), aimed at through the camera as the
//! bars are, and clicked with modforge::input::human's moves and waits.
//!
//! It stays on one enemy until that one dies or leaves range, so the
//! cursor does not jump between monsters, and the pause between casts
//! is drawn from a range so they do not come at a steady beat.

use modforge::input::human::{Timing, Wait};
use serde::{Deserialize, Serialize};
use std::time::{Duration, Instant};

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct Settings {
    /// Grid cells from the player an enemy may be.
    pub range: f32,
    /// Between two casts.
    pub pause: Wait,
    /// How far from the body's middle a click may land, in pixels:
    /// half width, half height.
    pub spread: [f32; 2],
    pub timing: Timing,
}

impl Default for Settings {
    fn default() -> Self {
        Self {
            range: 40.0,
            pause: Wait::new(300, 700),
            spread: [10.0, 15.0],
            timing: Timing {
                // Shorter than pickup's: the enemy moves while we wait.
                react: Wait::new(5, 80),
                ..Timing::default()
            },
        }
    }
}

/// An enemy on the screen.
#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Enemy {
    /// The entity's address: one enemy's lasting key.
    pub key: u64,
    pub name: String,
    /// Grid cells from the player.
    pub distance: f32,
    /// The middle of its body, in screen pixels.
    pub screen: [f32; 2],
}

impl Enemy {
    /// The box a click may land in around the body's middle.
    pub fn aim_box(&self, spread: [f32; 2]) -> [f32; 4] {
        [
            self.screen[0] - spread[0],
            self.screen[1] - spread[1],
            2.0 * spread[0],
            2.0 * spread[1],
        ]
    }
}

/// What attack remembers between casts.
#[derive(Debug, Default)]
pub struct State {
    target: Option<u64>,
    last_cast: Option<Instant>,
    pause: Duration,
}

impl State {
    /// The enemy to cast at now: the one already aimed at while it is
    /// still in range, else the nearest in range; none while the pause
    /// after the last cast runs.
    pub fn choose<'a>(&self, s: &Settings, enemies: &'a [Enemy], now: Instant) -> Option<&'a Enemy> {
        if self.last_cast.is_some_and(|t| now.duration_since(t) < self.pause) {
            return None;
        }
        let in_range = || enemies.iter().filter(|e| e.distance <= s.range);
        if let Some(t) = self.target
            && let Some(e) = in_range().find(|e| e.key == t)
        {
            return Some(e);
        }
        in_range().min_by(|a, b| a.distance.total_cmp(&b.distance))
    }

    /// A cast at `key` happened at `now`; the next pause is drawn.
    pub fn cast(&mut self, s: &Settings, key: u64, now: Instant, rng: &mut fastrand::Rng) {
        self.target = Some(key);
        self.last_cast = Some(now);
        self.pause = Duration::from_millis(u64::from(s.pause.draw(rng)));
    }

    /// A new zone: forget the target.
    pub fn clear(&mut self) {
        self.target = None;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn enemy(key: u64, distance: f32) -> Enemy {
        Enemy {
            key,
            name: format!("enemy {key}"),
            distance,
            screen: [500.0, 400.0],
        }
    }

    #[test]
    fn keeps_its_target_then_takes_the_nearest() {
        let s = Settings::default();
        let mut st = State::default();
        let mut rng = fastrand::Rng::with_seed(4);
        let t0 = Instant::now();
        let all = [enemy(1, 30.0), enemy(2, 12.0), enemy(3, 50.0)];
        assert_eq!(st.choose(&s, &all, t0).map(|e| e.key), Some(2));
        st.cast(&s, 2, t0, &mut rng);
        // The pause after a cast.
        assert_eq!(st.choose(&s, &all, t0 + Duration::from_millis(200)), None);
        // A nearer one comes, but the target is kept.
        let t1 = t0 + Duration::from_millis(800);
        let nearer = [enemy(1, 5.0), enemy(2, 20.0)];
        assert_eq!(st.choose(&s, &nearer, t1).map(|e| e.key), Some(2));
        // The target is gone: the nearest.
        assert_eq!(st.choose(&s, &[enemy(1, 5.0), enemy(4, 9.0)], t1).map(|e| e.key), Some(1));
        // None in range.
        assert_eq!(st.choose(&s, &[enemy(3, 50.0)], t1), None);
    }

    #[test]
    fn pauses_vary_and_the_aim_box_surrounds_the_body() {
        let s = Settings::default();
        let mut st = State::default();
        let mut rng = fastrand::Rng::with_seed(8);
        let mut seen = std::collections::HashSet::new();
        for _ in 0..50 {
            st.cast(&s, 1, Instant::now(), &mut rng);
            assert!((300..=700).contains(&st.pause.as_millis()));
            seen.insert(st.pause);
        }
        assert!(seen.len() > 10);
        assert_eq!(enemy(1, 1.0).aim_box([10.0, 15.0]), [490.0, 385.0, 20.0, 30.0]);
    }
}
