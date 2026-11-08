//! Mouse moves and clicks with irregular timing, for helpers that act
//! for the operator. After ExileCore2's PickIt (PickAsync,
//! SetCursorPositionAsync with SmoothCursorMovement, ClickRandom) and
//! GameHelper2's PickupHelper (random reaction delay, click cooldown):
//! the cursor goes to a random point inside the target in 10 to 50
//! steps, along a slight bow, and every wait is drawn from a range.
//!
//! The plan ([`stroke`], [`point_in`], [`Wait::draw`]) is pure and
//! seeded so it is tested without moving the real cursor; [`click`]
//! carries it out over [`super::l1`].

use super::{Button, Key, l1};
use serde::{Deserialize, Serialize};
use std::time::Duration;

/// A wait drawn evenly from `min..=max` milliseconds.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Wait {
    pub min: u32,
    pub max: u32,
}

impl Wait {
    pub const fn new(min: u32, max: u32) -> Self {
        Self { min, max }
    }

    pub fn draw(self, rng: &mut fastrand::Rng) -> u32 {
        let max = self.max.max(self.min);
        rng.u32(self.min..=max)
    }

    fn sleep(self, rng: &mut fastrand::Rng) {
        let ms = self.draw(rng);
        if ms > 0 {
            std::thread::sleep(Duration::from_millis(u64::from(ms)));
        }
    }
}

/// How a click is timed.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct Timing {
    /// Before the move starts (PickupHelper MinPickupDelayMs to
    /// MaxPickupDelayMs: 5 to 150).
    pub react: Wait,
    /// Between two steps of the move (PickIt waits 1 ms a step).
    pub step: Wait,
    /// On the target before the button goes down.
    pub settle: Wait,
    /// The button held down.
    pub hold: Wait,
}

impl Default for Timing {
    fn default() -> Self {
        Self {
            react: Wait::new(5, 150),
            step: Wait::new(1, 4),
            settle: Wait::new(20, 70),
            hold: Wait::new(30, 90),
        }
    }
}

/// PickIt ClickRandom(5, 3): a random point inside the rectangle
/// (`x, y, w, h`), kept `margin` in from its edges where it is big
/// enough.
pub fn point_in(rect: [f32; 4], margin: [f32; 2], rng: &mut fastrand::Rng) -> [f32; 2] {
    let mut axis = |start: f32, len: f32, m: f32| {
        let m = m.min(len / 2.0).max(0.0);
        start + m + rng.f32() * (len - 2.0 * m).max(0.0)
    };
    let x = axis(rect[0], rect[2], margin[0]);
    let y = axis(rect[1], rect[3], margin[1]);
    [x, y]
}

/// The cursor's path from `from` to `to`, `to` last: PickIt's step
/// count (a step per 10 pixels, 10 to 50), eased in and out, bowed
/// sideways by up to a tenth of the length (at most 40 pixels) to a
/// random side, so no two moves trace the same line.
pub fn stroke(from: [f32; 2], to: [f32; 2], rng: &mut fastrand::Rng) -> Vec<[i32; 2]> {
    let d = [to[0] - from[0], to[1] - from[1]];
    let len = d[0].hypot(d[1]);
    let steps = ((len / 10.0) as usize).clamp(10, 50);
    let normal = if len > 0.0 {
        [-d[1] / len, d[0] / len]
    } else {
        [0.0, 0.0]
    };
    let bow = (len * 0.1).min(40.0) * (rng.f32() * 2.0 - 1.0);
    (1..=steps)
        .map(|i| {
            let t = i as f32 / steps as f32;
            let eased = t * t * (3.0 - 2.0 * t);
            let side = bow * (std::f32::consts::PI * t).sin();
            [
                (from[0] + d[0] * eased + normal[0] * side).round() as i32,
                (from[1] + d[1] * eased + normal[1] * side).round() as i32,
            ]
        })
        .collect()
}

/// Move from where the cursor is to `to` (screen pixels) along a
/// [`stroke`], wait, and click `button` there, every wait from
/// `timing`.
pub fn click(
    button: Button,
    to: [f32; 2],
    timing: &Timing,
    rng: &mut fastrand::Rng,
) -> Result<(), String> {
    timing.react.sleep(rng);
    let (x, y) = l1::cursor_pos()?;
    let path = stroke([x as f32, y as f32], to, rng);
    for p in &path {
        l1::move_abs(p[0], p[1])?;
        timing.step.sleep(rng);
    }
    timing.settle.sleep(rng);
    let end = path.last().copied().unwrap_or([x, y]);
    l1::click_held(button, end[0], end[1], timing.hold.draw(rng))
}

/// Hold `hold`, press `press`, let `hold` go, every wait from
/// `timing`: a move key held while a dodge or skill key goes down.
/// Keys in `lift` that are down now (the operator's own, as a held W
/// against a roll to the S side) go up first and down again after,
/// so the operator's hold is back when this ends; keys in `hold` that
/// are down already are left alone.
pub fn press_holding(
    hold: &[Key],
    lift: &[Key],
    press: Key,
    timing: &Timing,
    rng: &mut fastrand::Rng,
) -> Result<(), String> {
    timing.react.sleep(rng);
    let lifted: Vec<Key> = lift.iter().copied().filter(|k| l1::key_held(*k)).collect();
    let pressed: Vec<Key> = hold.iter().copied().filter(|k| !l1::key_held(*k)).collect();
    let mut out = Ok(());
    for k in &lifted {
        out = out.and(l1::key_up(*k));
    }
    for k in &pressed {
        out = out.and(l1::key_down(*k));
    }
    timing.settle.sleep(rng);
    out = out.and(l1::key_press(press, timing.hold.draw(rng)));
    timing.step.sleep(rng);
    // Always let go and give back, even after an error.
    for k in &pressed {
        let _ = l1::key_up(*k);
    }
    for k in &lifted {
        let _ = l1::key_down(*k);
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn waits_stay_in_their_range_and_vary() {
        let mut rng = fastrand::Rng::with_seed(7);
        let w = Wait::new(5, 150);
        let draws: Vec<u32> = (0..200).map(|_| w.draw(&mut rng)).collect();
        assert!(draws.iter().all(|d| (5..=150).contains(d)));
        let distinct: std::collections::HashSet<_> = draws.iter().collect();
        assert!(
            distinct.len() > 50,
            "only {} distinct waits",
            distinct.len()
        );
        assert_eq!(Wait::new(9, 3).draw(&mut rng), 9);
    }

    #[test]
    fn the_point_is_inside_the_rectangle_and_its_margin() {
        let mut rng = fastrand::Rng::with_seed(1);
        for _ in 0..500 {
            let [x, y] = point_in([100.0, 50.0, 80.0, 20.0], [5.0, 3.0], &mut rng);
            assert!((105.0..=175.0).contains(&x), "{x}");
            assert!((53.0..=67.0).contains(&y), "{y}");
        }
        // Smaller than its margins: the middle.
        assert_eq!(
            point_in([0.0, 0.0, 4.0, 2.0], [5.0, 3.0], &mut rng),
            [2.0, 1.0]
        );
    }

    #[test]
    fn strokes_end_on_the_target_and_differ() {
        let mut rng = fastrand::Rng::with_seed(3);
        let a = stroke([0.0, 0.0], [300.0, 0.0], &mut rng);
        let b = stroke([0.0, 0.0], [300.0, 0.0], &mut rng);
        assert_eq!(a.len(), 30);
        assert_eq!(*a.last().unwrap(), [300, 0]);
        assert_eq!(*b.last().unwrap(), [300, 0]);
        assert_ne!(a, b);
        // The bow stays within a tenth of the length.
        assert!(a.iter().all(|p| p[1].abs() <= 30));
        // Short moves still take 10 steps; long ones at most 50.
        assert_eq!(stroke([0.0, 0.0], [5.0, 5.0], &mut rng).len(), 10);
        assert_eq!(stroke([0.0, 0.0], [2000.0, 0.0], &mut rng).len(), 50);
        assert_eq!(stroke([7.0, 7.0], [7.0, 7.0], &mut rng), vec![[7, 7]; 10]);
    }
}
