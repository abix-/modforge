//! Death and the bed (topside page topside-town "Death and the bed",
//! operator 2026-11-23: "If they've given a bed, then they're able to
//! respawn... if they don't have a bed... perma-die"; "Set holds true for
//! the player"): everyone alike, a person with a bed comes back in it, a
//! person with no bed is dead for good. A person holds several beds up to
//! a limit, and a bed woken in waits out a cooldown before it is woken in
//! again (todo Bed 3; Rust's sleeping bags and beds).

use std::collections::BTreeMap;

use glam::Vec3;

/// How many beds one person holds at most (Rust's sleeping bag limit;
/// Claude's, for the operator to change).
pub const BED_LIMIT: usize = 15;
/// How long a bed woken in waits before it is woken in again, seconds
/// (Rust's sleeping bag cooldown, 5 minutes; Claude's).
pub const BED_COOLDOWN_SECONDS: u64 = 300;

/// Where a person with these beds wakes after dying: in a bed of theirs.
/// None when they have none: dead for good.
pub fn wake_in(beds: &[Vec3]) -> Option<Vec3> {
    beds.first().copied()
}

/// The bed a person wakes in now: the first of theirs (each its id and
/// where it stands) whose cooldown is over at tick `now`, `ready_at`
/// holding the tick each bed woken in is ready again. None when every bed
/// is still cooling, or they have none.
pub fn wake_in_ready(beds: &[(u64, Vec3)], ready_at: &BTreeMap<u64, u64>, now: u64) -> Option<(u64, Vec3)> {
    beds.iter().find(|(id, _)| ready_at.get(id).is_none_or(|t| *t <= now)).copied()
}

/// Whether a person holding `held` beds may take one more.
pub fn may_claim(held: usize) -> bool {
    held < BED_LIMIT
}

/// The tick a bed woken in at `now` is ready again, at `ticks_a_second`.
pub fn ready_after(now: u64, ticks_a_second: u64) -> u64 {
    now + BED_COOLDOWN_SECONDS * ticks_a_second
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_cooling_bed_is_skipped_for_the_next() {
        let beds = [(1, Vec3::X), (2, Vec3::Z)];
        let mut ready = BTreeMap::new();
        assert_eq!(wake_in_ready(&beds, &ready, 0), Some((1, Vec3::X)));
        ready.insert(1, ready_after(0, 60));
        assert_eq!(wake_in_ready(&beds, &ready, 10), Some((2, Vec3::Z)));
        ready.insert(2, ready_after(10, 60));
        assert_eq!(wake_in_ready(&beds, &ready, 20), None);
        assert_eq!(wake_in_ready(&beds, &ready, BED_COOLDOWN_SECONDS * 60), Some((1, Vec3::X)));
        assert!(may_claim(BED_LIMIT - 1) && !may_claim(BED_LIMIT));
    }
}
