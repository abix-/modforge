//! Skill progression curves. The default "sqrt diminishing returns"
//! is what every RPG mod we reference uses: level 1 = ~10% of max,
//! level 25 = 50%, level 100 = 100%. Generous early, flat at the end.

/// `sqrt(level / max)`. Generous early, flat near the cap.
/// Returns `0.0` at level 0, `1.0` at `level >= max`.
pub fn sqrt_progress(level: u32, max: u32) -> f32 {
    if max == 0 || level >= max {
        return if level == 0 { 0.0 } else { 1.0 };
    }
    ((level as f64) / (max as f64)).sqrt() as f32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn endpoints() {
        assert_eq!(sqrt_progress(0, 100), 0.0);
        assert_eq!(sqrt_progress(100, 100), 1.0);
        assert_eq!(sqrt_progress(200, 100), 1.0);
    }

    #[test]
    fn quarter_is_half() {
        let p = sqrt_progress(25, 100);
        assert!((p - 0.5).abs() < 1e-6, "got {p}");
    }
}
