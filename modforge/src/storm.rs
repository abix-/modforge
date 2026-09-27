//! The storm (topside design.md "The storm", MISERY's emission): after
//! a while the sky warns, then the storm hits, and anyone caught in
//! the open dies; when it passes the world has shifted to another
//! reality. The clock is data and plain arithmetic; the consumer
//! decides what counts as shelter and rolls the new world.

/// When storms come and how long each part lasts, in seconds.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct StormDef {
    /// From one storm's start to the next; the first comes this long
    /// after the world begins.
    pub every_secs: f32,
    /// How long the sky warns before the storm hits.
    pub warning_secs: f32,
    /// How long the storm lasts.
    pub storm_secs: f32,
}

/// Where the world is in the storm's cycle.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum StormPhase {
    Calm,
    /// The sky has changed: get under a roof.
    Warning,
    /// Anyone in the open dies.
    Storm,
}

impl StormDef {
    /// The phase at `elapsed` seconds since the world began.
    pub fn phase(&self, elapsed: f32) -> StormPhase {
        if elapsed < self.every_secs - self.warning_secs {
            return StormPhase::Calm;
        }
        let into = (elapsed - (self.every_secs - self.warning_secs)) % self.every_secs;
        if into < self.warning_secs {
            StormPhase::Warning
        } else if into < self.warning_secs + self.storm_secs {
            StormPhase::Storm
        } else {
            StormPhase::Calm
        }
    }

    /// Seconds from `elapsed` until the next warning begins; zero while
    /// the sky warns or the storm hits. A consumer that runs the storm's
    /// clock this far ahead brings the next storm now, through the same
    /// cycle.
    pub fn until_next_warning(&self, elapsed: f32) -> f32 {
        if self.phase(elapsed) != StormPhase::Calm {
            return 0.0;
        }
        let first = self.every_secs - self.warning_secs;
        if elapsed < first {
            return first - elapsed;
        }
        self.every_secs - (elapsed - first) % self.every_secs
    }

    /// How many storms have passed (ended) by `elapsed`: the world has
    /// shifted this many times.
    pub fn passed(&self, elapsed: f32) -> u32 {
        let first_end = self.every_secs + self.storm_secs;
        if elapsed < first_end {
            return 0;
        }
        ((elapsed - first_end) / self.every_secs) as u32 + 1
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    const DEF: StormDef = StormDef {
        every_secs: 100.0,
        warning_secs: 10.0,
        storm_secs: 5.0,
    };

    #[test]
    fn calm_then_warning_then_storm_then_calm_again() {
        assert_eq!(DEF.phase(0.0), StormPhase::Calm);
        assert_eq!(DEF.phase(89.0), StormPhase::Calm);
        assert_eq!(DEF.phase(91.0), StormPhase::Warning);
        assert_eq!(DEF.phase(101.0), StormPhase::Storm);
        assert_eq!(DEF.phase(106.0), StormPhase::Calm);
        assert_eq!(DEF.phase(191.0), StormPhase::Warning, "the next one warns too");
        assert_eq!(DEF.phase(202.0), StormPhase::Storm);
    }

    #[test]
    fn running_the_clock_ahead_by_until_next_warning_brings_the_warning_now() {
        for elapsed in [0.0, 50.0, 89.0, 106.0, 150.0, 189.5, 250.0] {
            let ahead = DEF.until_next_warning(elapsed);
            assert!(ahead > 0.0, "calm at {elapsed}");
            assert_eq!(DEF.phase(elapsed + ahead), StormPhase::Warning, "warning after running {ahead} ahead from {elapsed}");
            assert_eq!(DEF.passed(elapsed + ahead), DEF.passed(elapsed), "no storm counted as passed that never came");
        }
    }

    #[test]
    fn nothing_to_bring_while_the_sky_warns_or_the_storm_hits() {
        assert_eq!(DEF.until_next_warning(91.0), 0.0);
        assert_eq!(DEF.until_next_warning(101.0), 0.0);
    }

    #[test]
    fn the_world_shifts_once_per_storm_passed() {
        assert_eq!(DEF.passed(104.0), 0, "still storming");
        assert_eq!(DEF.passed(105.0), 1, "the first has passed");
        assert_eq!(DEF.passed(204.0), 1);
        assert_eq!(DEF.passed(205.0), 2);
    }
}
