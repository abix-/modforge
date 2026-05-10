//! Generic RPG ImGui tab template.
//!
//! Renders header (level + XP bar + unspent skill points), one row
//! per catalog skill (+1/+10/-1/-10/on-toggle/effect-text), and a
//! debug footer (+5 / +50 skill points).
//!
//! Game crates wire it as their `Tab` render fn:
//!
//! ```ignore
//! ueforge::Tab {
//!     name: "RPG",
//!     render: || ueforge::rpg::tab::render(&TRACKER, &TOGGLE_FNS),
//! }
//! ```
//!
//! The toggle on/off button is opt-in via the `ToggleFns` callbacks
//! the consumer passes -- since the "disabled skills" feature is
//! orthogonal to the catalog/tracker shape and not every game wants
//! it.

use crate::ui;

use super::{RpgApplier, Tracker};

/// Callbacks for the per-skill on/off toggle. Pass `None` to omit
/// the toggle column.
pub struct ToggleFns {
    pub is_enabled: fn(skill_id: &str) -> bool,
    pub set_enabled: fn(skill_id: &'static str, enabled: bool),
}

/// Render the full RPG tab body. Call from a `Tab { render: ... }`
/// callback.
pub fn render<A: RpgApplier>(tracker: &'static Tracker<A>, toggle: Option<&ToggleFns>) {
    if tracker.current_slot().is_none() {
        ui::text("No save loaded.");
        ui::text_disabled("Pick a save from the main menu to begin.");
        return;
    }

    let curve = tracker.curve();
    let (level, current_xp, skill_points) = tracker
        .with_state(|s| (s.level, s.xp, s.skill_points))
        .unwrap_or((0, 0, 0));

    let xp_cur = curve.cumulative_xp_for_level(level);
    let xp_next = if level >= curve.max_level {
        0
    } else {
        curve.cumulative_xp_for_level(level + 1)
    };

    ui::text(&format!("Level {level}"));
    if xp_next > xp_cur {
        let span = xp_next - xp_cur;
        let into_band = current_xp.saturating_sub(xp_cur);
        let progress = if span > 0 {
            into_band as f32 / span as f32
        } else {
            1.0
        };
        let overlay = format!("{current_xp} / {xp_next} XP");
        ui::progress_bar(progress, Some(&overlay));
    } else {
        ui::text(&format!("Max level ({current_xp} XP)"));
    }

    ui::text(&format!("Unspent skill points: {skill_points}"));
    ui::separator();

    for skill in tracker.catalog().iter() {
        render_row(tracker, toggle, skill, skill_points);
    }

    // Debug controls -- testing only.
    ui::separator();
    ui::text_disabled("Debug (testing only)");
    if ui::button("+5 skill points") {
        let _ = tracker.debug_grant_skill_points(5);
    }
    ui::same_line();
    if ui::button("+50 skill points") {
        let _ = tracker.debug_grant_skill_points(50);
    }
}

fn render_row<A: RpgApplier>(
    tracker: &'static Tracker<A>,
    toggle: Option<&ToggleFns>,
    skill: &super::SkillDef<A::Effect>,
    skill_points: u32,
) {
    let id = skill.id;
    let max = skill.max_level;
    let cur_level = tracker
        .with_state(|s| s.skill_levels.get(id).copied().unwrap_or(0))
        .unwrap_or(0);

    // Format effects via the Applier (game-specific text).
    let cur_effect = format_effect(tracker, skill, cur_level);
    let next_effect = if cur_level < max {
        format_effect(tracker, skill, cur_level + 1)
    } else {
        String::new()
    };

    let can_spend = skill_points > 0 && cur_level < max;
    let can_refund = cur_level > 0;

    {
        let _d = ui::Disabled::new(!can_spend);
        if ui::button(&format!("+1##{id}")) {
            tracker.spend_skill_points(id, 1);
        }
        ui::same_line();
        if ui::button(&format!("+10##{id}")) {
            tracker.spend_skill_points(id, 10);
        }
    }
    ui::same_line();
    {
        let _d = ui::Disabled::new(!can_refund);
        if ui::button(&format!("-1##{id}")) {
            tracker.refund_skill_points(id, 1);
        }
        ui::same_line();
        if ui::button(&format!("-10##{id}")) {
            tracker.refund_skill_points(id, 10);
        }
    }
    ui::same_line();

    if let Some(t) = toggle {
        let mut enabled = (t.is_enabled)(id);
        if ui::checkbox(&format!("on##{id}"), &mut enabled) {
            (t.set_enabled)(id, enabled);
            tracker.reapply_one(id);
        }
        ui::same_line();
    }

    let line = if cur_level == 0 {
        format!(
            "{:<20} level 0 / {max}  (next: {next_effect})",
            skill.display_name
        )
    } else if cur_level >= max {
        format!(
            "{:<20} level {cur_level} / {max}  MAX  {cur_effect}",
            skill.display_name
        )
    } else {
        format!(
            "{:<20} level {cur_level} / {max}  {cur_effect}  (next: {next_effect})",
            skill.display_name
        )
    };
    ui::text(&line);
}

/// Helper that calls the Applier's format_effect under the tracker
/// lock and returns the string. Threading the applier through
/// requires a method on Tracker since the Applier lives inside the
/// inner `Mutex`.
fn format_effect<A: RpgApplier>(
    tracker: &Tracker<A>,
    skill: &super::SkillDef<A::Effect>,
    level: u32,
) -> String {
    tracker
        .format_effect(skill, level)
        .unwrap_or_else(String::new)
}
