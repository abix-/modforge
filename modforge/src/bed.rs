//! Death and the bed (topside page topside-town "Death and the bed",
//! operator 2026-11-23: "If they've given a bed, then they're able to
//! respawn... if they don't have a bed... perma-die"; "Set holds true for
//! the player"): everyone alike, a person with a bed comes back in it, a
//! person with no bed is dead for good.

use glam::Vec3;

/// Where a person with these beds wakes after dying: in a bed of theirs.
/// None when they have none: dead for good.
pub fn wake_in(beds: &[Vec3]) -> Option<Vec3> {
    beds.first().copied()
}
