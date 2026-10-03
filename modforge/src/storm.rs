//! The storm (topside design.md "The storm", MISERY's emission): after
//! a while the sky warns, then the storm hits, and anyone caught in
//! the open dies; when it passes the world has shifted to another
//! reality. When it comes is the episode's (topside design.md "The
//! session rhythm": each episode's data gives a range in game days, rolled
//! when it starts); the clock is plain arithmetic toward that moment; the
//! consumer decides what counts as shelter and rolls the new world.

/// How long each part of a storm lasts, in seconds.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct StormDef {
    /// How long the sky warns before the storm hits.
    pub warning_secs: f32,
    /// How long the storm lasts.
    pub storm_secs: f32,
}

/// Where the world is in the storm's coming.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum StormPhase {
    Calm,
    /// The sky has changed: get under a roof.
    Warning,
    /// Anyone in the open dies.
    Storm,
}

impl StormDef {
    /// The phase at `secs` on the clock, the storm hitting at `at`: the
    /// sky warns `warning_secs` before it, the storm lasts `storm_secs`.
    pub fn phase(&self, secs: f32, at: f32) -> StormPhase {
        if secs < at - self.warning_secs {
            StormPhase::Calm
        } else if secs < at {
            StormPhase::Warning
        } else if secs < at + self.storm_secs {
            StormPhase::Storm
        } else {
            StormPhase::Calm
        }
    }

    /// Whether the storm hitting at `at` has passed by `secs`: the world
    /// shifts.
    pub fn passed(&self, secs: f32, at: f32) -> bool {
        secs >= at + self.storm_secs
    }

    /// The storm brought now (the consumer's `storm` order): it hits at
    /// this second, so the sky warns from `secs` on.
    pub fn now(&self, secs: f32) -> f32 {
        secs + self.warning_secs
    }
}

/// When the storm hits, in seconds on the clock: `days` game days (a range,
/// as an episode's data gives it) after `from`, rolled from `seed`
/// (`roll::salted_index`, the same every time for the same seed), a game
/// day being `day_secs`.
pub fn storm_at(from: f32, days: (f32, f32), day_secs: f32, seed: u64) -> f32 {
    let (low, high) = (days.0.min(days.1), days.0.max(days.1));
    let share = crate::roll::salted_index(seed, 0x5707_4D00, 10_001) as f32 / 10_000.0;
    from + (low + (high - low) * share) * day_secs
}

#[cfg(test)]
mod tests {
    use super::*;

    const DEF: StormDef = StormDef {
        warning_secs: 10.0,
        storm_secs: 5.0,
    };

    #[test]
    fn calm_then_warning_then_storm_then_calm_again() {
        assert_eq!(DEF.phase(0.0, 100.0), StormPhase::Calm);
        assert_eq!(DEF.phase(89.0, 100.0), StormPhase::Calm);
        assert_eq!(DEF.phase(91.0, 100.0), StormPhase::Warning);
        assert_eq!(DEF.phase(101.0, 100.0), StormPhase::Storm);
        assert_eq!(DEF.phase(106.0, 100.0), StormPhase::Calm);
        assert!(!DEF.passed(104.0, 100.0), "still storming");
        assert!(DEF.passed(105.0, 100.0), "passed");
    }

    #[test]
    fn a_storm_brought_now_warns_now() {
        for secs in [0.0, 50.0, 89.0] {
            assert_eq!(DEF.phase(secs, DEF.now(secs)), StormPhase::Warning, "at {secs}");
            assert!(!DEF.passed(secs, DEF.now(secs)));
        }
    }

    /// Two game days after the start, a day 1200 s: at 2400 s; a range
    /// rolls inside it, the same for the same seed.
    #[test]
    fn the_storm_comes_when_the_episode_says() {
        assert_eq!(storm_at(0.0, (2.0, 2.0), 1200.0, 7), 2400.0);
        assert_eq!(storm_at(100.0, (2.0, 2.0), 1200.0, 7), 2500.0, "from when the episode started");
        let rolled: Vec<f32> = (0..50).map(|seed| storm_at(0.0, (1.0, 3.0), 1200.0, seed)).collect();
        assert!(rolled.iter().all(|at| (1200.0..=3600.0).contains(at)), "{rolled:?}");
        assert!(rolled.iter().any(|at| *at != rolled[0]), "the range is rolled, not one point");
        assert_eq!(storm_at(0.0, (1.0, 3.0), 1200.0, 9), storm_at(0.0, (1.0, 3.0), 1200.0, 9));
    }
}
