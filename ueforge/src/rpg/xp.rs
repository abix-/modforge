//! XP curve math. Cumulative XP for a level + inverse "what level
//! does this XP unlock". Pure math, no IO, no UE.

/// `cumulative_xp_for_level(level) = round(base * level^exponent)`,
/// capped at `max_level`. Defaults match the g2rpg convention:
/// `base = 100`, `exponent = 1.8`, `max_level = 50` -- generous
/// early, flat at the end.
#[derive(Debug, Clone, Copy)]
pub struct Curve {
    pub base: f64,
    pub exponent: f64,
    pub max_level: u32,
}

/// Hard upper bound on `Curve::max_level`. `level_for_xp` is a
/// linear scan; downstream consumers tempted to pick an unbounded
/// max (e.g. "any UE game; pick 10_000") would walk that many
/// iterations on every snapshot. 1024 is plenty for any realistic
/// RPG curve and keeps the scan deterministic.
pub const MAX_LEVEL_LIMIT: u32 = 1024;

impl Curve {
    /// `base = 100`, `exponent = 1.8`, `max_level = 50` is the bbp
    /// default. `max_level` MUST be `<= MAX_LEVEL_LIMIT` (1024); the
    /// `assert!` here makes a 10K-level mistake a build-time failure
    /// when the const is in a `static`, or a panic at runtime
    /// otherwise.
    pub const fn new(base: f64, exponent: f64, max_level: u32) -> Self {
        assert!(
            max_level <= MAX_LEVEL_LIMIT,
            "Curve::new: max_level exceeds MAX_LEVEL_LIMIT"
        );
        Self {
            base,
            exponent,
            max_level,
        }
    }

    /// Cumulative XP required to *reach* `level`. Level 1 = 0.
    pub fn cumulative_xp_for_level(&self, level: u32) -> u64 {
        if level <= 1 {
            return 0;
        }
        let n = level.min(self.max_level) as f64;
        (self.base * n.powf(self.exponent)).round() as u64
    }

    /// What level does `xp` total XP grant? Linear scan -- max_level
    /// is bounded (typical 50-100) so the cost is trivial.
    pub fn level_for_xp(&self, xp: u64) -> u32 {
        for level in (1..=self.max_level).rev() {
            if xp >= self.cumulative_xp_for_level(level) {
                return level;
            }
        }
        1
    }
}

/// Per-creature XP lookup. UE5 RPG mods typically award XP based on
/// what the player killed: a bestiary table keyed by BP class short
/// name (`"BP_Aphid_C"`) mapping to base XP.
///
/// The table is `&'static [(&'static str, u32)]`, so the catalog
/// lives in `static`s and resolves with no allocation. Linear scan:
/// realistic bestiaries are <100 rows, called once per kill -- the
/// scan cost is invisible.
///
/// ```ignore
/// pub static BESTIARY: Bestiary = Bestiary::new(
///     &[
///         ("BP_Aphid_C", 5),
///         ("BP_Roly_Poly_C", 25),
///         ("BP_Spider_C", 75),
///     ],
///     5, // default for unknown classes
/// );
/// // Per-kill:
/// let xp = BESTIARY.lookup("BP_Aphid_C"); // 5
/// ```
#[derive(Debug, Clone, Copy)]
pub struct Bestiary {
    pub table: &'static [(&'static str, u32)],
    pub default_xp: u32,
}

impl Bestiary {
    pub const fn new(table: &'static [(&'static str, u32)], default_xp: u32) -> Self {
        Self { table, default_xp }
    }

    /// XP for `class_name`. Case-sensitive exact match; falls back
    /// to `default_xp` for unknown classes.
    pub fn lookup(&self, class_name: &str) -> u32 {
        for (key, value) in self.table {
            if class_name == *key {
                return *value;
            }
        }
        self.default_xp
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn level_one_is_zero() {
        let c = Curve::new(100.0, 1.8, 50);
        assert_eq!(c.cumulative_xp_for_level(1), 0);
        assert_eq!(c.cumulative_xp_for_level(0), 0);
    }

    #[test]
    fn round_trip() {
        let c = Curve::new(100.0, 1.8, 50);
        for level in 1..=50 {
            let xp = c.cumulative_xp_for_level(level);
            assert_eq!(c.level_for_xp(xp), level, "round-trip at level {level}");
        }
    }

    #[test]
    fn caps_at_max_level() {
        let c = Curve::new(100.0, 1.8, 50);
        let xp_max = c.cumulative_xp_for_level(50);
        assert_eq!(c.level_for_xp(xp_max + 999_999), 50);
    }
}
