//! Chances the way games roll them, and how often a fight is won.
//!
//! [`Gate`] is the pseudo-random distribution Warcraft III and Dota 2
//! use for crits and dodges: the chance starts low and grows by a
//! constant `c` after each miss, so streaks are rare but the long-run
//! rate is the stated chance. Dungeonbound's `gated_roll`
//! (combatant_runtime.gd) is the same rule, with the constant found
//! by bisection on a 0.001 grid and a warm start (the miss count a
//! fight starts with is drawn, not zero).
//!
//! [`win_rate`] plays a fight many times and counts the wins.

/// Grid the game snaps a chance to before finding its constant.
const STEP: f64 = 0.001;
/// Bisection steps the game takes.
const BISECT_STEPS: usize = 40;

/// The long-run rate a growth constant `c` gives: 1 / expected tries.
pub fn prd_rate(c: f64) -> f64 {
    if c <= 0.0 {
        return 0.0;
    }
    let mut expected = 0.0;
    let mut reach = 1.0;
    let last = (1.0 / c).ceil() as u32;
    for n in 1..=last {
        let p = (c * f64::from(n)).min(1.0);
        expected += f64::from(n) * reach * p;
        reach *= 1.0 - p;
        if reach < 1e-12 {
            break;
        }
    }
    1.0 / expected
}

/// The growth constant whose long-run rate is `chance`.
pub fn prd_constant(chance: f64) -> f64 {
    let target = (chance.clamp(0.0, 1.0) / STEP).round() * STEP;
    if target >= 1.0 {
        return 1.0;
    }
    if target <= 0.0 {
        return 0.0;
    }
    let (mut lo, mut hi) = (0.0, target);
    for _ in 0..BISECT_STEPS {
        let mid = (lo + hi) * 0.5;
        if prd_rate(mid) > target {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    (lo + hi) * 0.5
}

/// One chance rolled again and again, remembering misses.
#[derive(Clone, Debug)]
pub struct Gate {
    chance: f64,
    c: f64,
    /// None until the first roll, which draws the warm start.
    fails: Option<u32>,
}

impl Gate {
    pub fn new(chance: f64) -> Self {
        Self {
            chance,
            c: prd_constant(chance),
            fails: None,
        }
    }

    pub fn roll(&mut self, rng: &mut fastrand::Rng) -> bool {
        roll_with(&mut self.fails, self.chance, self.c, rng)
    }
}

/// One roll of a gate whose chance changes between rolls (a curse or a
/// status moves it), keeping only the miss count: Dungeonbound's
/// `gated_roll` finds the constant for the chance of this roll.
pub fn gated_roll(fails: &mut Option<u32>, chance: f64, rng: &mut fastrand::Rng) -> bool {
    // Every constant on the game's 0.001 grid, found once (the game
    // keeps the same cache, _gate_constants).
    static GRID: std::sync::OnceLock<Vec<f64>> = std::sync::OnceLock::new();
    let c = if chance > 0.0 && chance < 1.0 {
        let grid = GRID.get_or_init(|| {
            (0..=(1.0 / STEP).round() as usize)
                .map(|k| prd_constant(k as f64 * STEP))
                .collect()
        });
        grid[((chance / STEP).round() as usize).min(grid.len() - 1)]
    } else {
        0.0
    };
    roll_with(fails, chance, c, rng)
}

fn roll_with(fails: &mut Option<u32>, chance: f64, c: f64, rng: &mut fastrand::Rng) -> bool {
    let roll = rng.f64();
    if chance <= 0.0 {
        return false;
    }
    if chance >= 1.0 {
        *fails = Some(0);
        return true;
    }
    if c <= 0.0 {
        return roll < chance;
    }
    let had = match *fails {
        Some(f) => f,
        None => warm_fails(c, rng),
    };
    let n = had + 1;
    if roll < (c * f64::from(n)).min(1.0) {
        *fails = Some(0);
        true
    } else {
        *fails = Some(n);
        false
    }
}

/// A miss count drawn as if the gate had been rolling for a while.
fn warm_fails(c: f64, rng: &mut fastrand::Rng) -> u32 {
    let target = rng.f64() / prd_rate(c);
    let mut reach = 1.0;
    let mut total = 0.0;
    let last = (1.0 / c).ceil() as u32;
    for fails in 0..last {
        total += reach;
        if total >= target {
            return fails;
        }
        reach *= 1.0 - (c * f64::from(fails + 1)).min(1.0);
    }
    last - 1
}

/// Wins out of `trials` fights, each played by `fight` with its own
/// random stream. Same `seed`, same answer.
pub fn win_rate(trials: u32, seed: u64, mut fight: impl FnMut(&mut fastrand::Rng) -> bool) -> f64 {
    if trials == 0 {
        return 0.0;
    }
    let mut rng = fastrand::Rng::with_seed(seed);
    let wins = (0..trials).filter(|_| fight(&mut rng)).count();
    wins as f64 / f64::from(trials)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn constant_gives_the_chance_back() {
        for chance in [0.05, 0.1, 0.25, 0.35, 0.5, 0.8] {
            let rate = prd_rate(prd_constant(chance));
            assert!((rate - chance).abs() < 1e-6, "{chance}: {rate}");
        }
    }

    #[test]
    fn gate_hits_at_its_chance() {
        let mut rng = fastrand::Rng::with_seed(7);
        let mut gate = Gate::new(0.1);
        let hits = (0..200_000).filter(|_| gate.roll(&mut rng)).count();
        let rate = hits as f64 / 200_000.0;
        assert!((rate - 0.1).abs() < 0.003, "{rate}");
    }

    #[test]
    fn gate_never_and_always() {
        let mut rng = fastrand::Rng::with_seed(1);
        assert!(!Gate::new(0.0).roll(&mut rng));
        assert!(Gate::new(1.0).roll(&mut rng));
    }
}
