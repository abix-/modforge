// RPG ImGui tab. Migrated from the old cpp/shim.cpp render lambda;
// every read goes straight to tracker / skills / xp now (no FFI layer).

use ueforge::ui;

use crate::rpg::{apply, skills, tracker, xp};

pub fn render() {
    let _t = crate::counters::time_scope(&crate::counters::TIME_NS_IMGUI_GET_XP);
    crate::counters::bump(&crate::counters::IMGUI_TAB_RENDERS);

    if tracker::current_slot().is_none() {
        ui::text("No save loaded.");
        ui::text_disabled("Pick a save from the main menu to begin.");
        return;
    }

    let (level, current_xp, skill_points) = tracker::with_state(|s| {
        (s.level, s.xp, s.skill_points)
    })
    .unwrap_or((0, 0, 0));

    let xp_cur = xp::cumulative_xp_for_level(level);
    let xp_next = if level >= xp::MAX_LEVEL {
        0
    } else {
        xp::cumulative_xp_for_level(level + 1)
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

    for skill in skills::CATALOG {
        let id = skill.id;
        let max = skill.max_level;
        let cur_level = tracker::with_state(|s| {
            s.skill_levels.get(id).copied().unwrap_or(0)
        })
        .unwrap_or(0);

        let cur_effect = skills::format_effect(id, cur_level);
        let next_effect = if cur_level < max {
            skills::format_effect(id, cur_level + 1)
        } else {
            String::new()
        };

        let can_spend = skill_points > 0 && cur_level < max;
        let can_refund = cur_level > 0;

        // Use ImGui's `##id` suffix to make each button instance unique
        // without a PushID/PopID pair.
        {
            let _d = ui::Disabled::new(!can_spend);
            if ui::button(&format!("+1##{id}")) {
                let _ = tracker::spend_skill_point(skill);
            }
            ui::same_line();
            if ui::button(&format!("+10##{id}")) {
                tracker::spend_skill_points(skill, 10);
            }
        }
        ui::same_line();
        {
            let _d = ui::Disabled::new(!can_refund);
            if ui::button(&format!("-1##{id}")) {
                let _ = tracker::refund_skill_point(skill);
            }
            ui::same_line();
            if ui::button(&format!("-10##{id}")) {
                tracker::refund_skill_points(skill, 10);
            }
        }
        ui::same_line();

        // Per-skill enable toggle. Disabling treats the skill as level 0
        // (vanilla) without refunding the points.
        let mut enabled = apply::is_skill_enabled(id);
        if ui::checkbox(&format!("on##{id}"), &mut enabled) {
            apply::set_skill_enabled(id, enabled);
            tracker::reapply_one(id);
        }
        ui::same_line();

        let line = if cur_level == 0 {
            format!("{:<20} level 0 / {max}  (next: {next_effect})", skill.display_name)
        } else if cur_level >= max {
            format!("{:<20} level {cur_level} / {max}  MAX  {cur_effect}", skill.display_name)
        } else {
            format!(
                "{:<20} level {cur_level} / {max}  {cur_effect}  (next: {next_effect})",
                skill.display_name
            )
        };
        ui::text(&line);
    }

    // Debug controls -- testing only.
    ui::separator();
    ui::text_disabled("Debug (testing only)");
    if ui::button("+5 skill points") {
        let _ = tracker::debug_grant_skill_points(5);
    }
    ui::same_line();
    if ui::button("+50 skill points") {
        let _ = tracker::debug_grant_skill_points(50);
    }
}
