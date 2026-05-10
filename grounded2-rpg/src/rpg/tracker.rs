// Bbp tracker shim. Owns the static `ueforge::rpg::Tracker` and
// exposes the g2rpg-side surface that the rest of the mod calls
// (kill_hook, world_loader, debug, tab). Every skill-state
// operation routes through ueforge::rpg::Tracker, which owns
// state, persistence, and the apply dispatch via GameApplier.

use ueforge::rpg::{SkillsState, Tracker};

use crate::rpg::applier::GameApplier;
use crate::rpg::skills::{self, CATALOG};
use crate::rpg::xp::CURVE;
use crate::settings::Settings;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum KillSource {
    Player,
    Buggy,
}

pub static TRACKER: Tracker<GameApplier> = Tracker::new(CATALOG, CURVE, "saves");

pub fn activate_slot(slot: String, settings: Settings) {
    cache_buggy_kill_multiplier(settings.rpg.buggy_kill_xp_multiplier.max(0.0));
    TRACKER.activate_slot(slot, GameApplier { settings });
}

pub fn deactivate_slot() {
    TRACKER.deactivate_slot();
}

pub fn current_slot() -> Option<String> {
    TRACKER.current_slot()
}

pub fn with_state<R>(f: impl FnOnce(&SkillsState) -> R) -> Option<R> {
    TRACKER.with_state(f)
}

pub fn spend_skill_point(skill: &skills::Skill) -> bool {
    TRACKER.spend_skill_points(skill.id, 1) > 0
}

pub fn spend_skill_points(skill: &skills::Skill, count: u32) -> u32 {
    TRACKER.spend_skill_points(skill.id, count)
}

pub fn refund_skill_point(skill: &skills::Skill) -> bool {
    TRACKER.refund_skill_points(skill.id, 1) > 0
}

pub fn refund_skill_points(skill: &skills::Skill, count: u32) -> u32 {
    TRACKER.refund_skill_points(skill.id, count)
}

pub fn reapply_one(skill_id: &str) {
    TRACKER.reapply_one(skill_id);
}

pub fn reapply_all() -> bool {
    TRACKER.reapply_all()
}

pub fn debug_grant_skill_points(count: u32) -> bool {
    TRACKER.debug_grant_skill_points(count)
}

/// Called from the kill hook on every confirmed creature kill.
/// Awards XP via the per-creature lookup, scaled by `source`.
pub fn record_kill(creature_class_name: &str, source: KillSource) {
    let base = crate::rpg::xp::xp_for_creature(creature_class_name);
    let scaled = match source {
        KillSource::Player => base,
        KillSource::Buggy => {
            let mult = TRACKER
                .with_state(|_| {
                    // Settings live inside GameApplier; expose via a
                    // dedicated accessor if the multiplier ever
                    // varies per-kill. For now the multiplier is
                    // captured at slot activate and survives until
                    // deactivate.
                })
                .map(|_| 1.0_f32)
                .unwrap_or(1.0);
            // We don't currently expose Settings through Tracker;
            // the multiplier is read from a process-global cache.
            (base as f32 * mult * settings_buggy_kill_xp_multiplier()) as u32
        }
    };
    let xp = TRACKER.record_xp(scaled as u64);
    ueforge::log!(
        "rpg/kill: ({creature_class_name}) source={source:?} +{scaled} XP -> total {} (level {})",
        xp.map(|r| r.total_xp).unwrap_or(0),
        xp.map(|r| r.new_level).unwrap_or(0),
    );
}

// ---------------------------------------------------------------
// Settings escape hatch for record_kill's buggy-kill multiplier.
// Tracker doesn't expose Settings; we cache the per-slot
// multiplier in a static at activate_slot. Game-specific.
// ---------------------------------------------------------------

use std::sync::atomic::{AtomicU32, Ordering};

static BUGGY_MULT_BITS: AtomicU32 = AtomicU32::new(0x3F800000); // 1.0_f32

pub fn cache_buggy_kill_multiplier(v: f32) {
    BUGGY_MULT_BITS.store(v.to_bits(), Ordering::Relaxed);
}

fn settings_buggy_kill_xp_multiplier() -> f32 {
    f32::from_bits(BUGGY_MULT_BITS.load(Ordering::Relaxed))
}
