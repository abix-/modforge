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

impl Curve {
    pub const fn new(base: f64, exponent: f64, max_level: u32) -> Self {
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
