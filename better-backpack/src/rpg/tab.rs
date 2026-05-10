// RPG ImGui tab. Body lives in `ueforge::rpg::tab::render`; this
// crate supplies the static Tracker and the on/off toggle hooks
// (which route into bbp's `apply` module's process-global
// disabled-skills set).

use ueforge::rpg::tab::{render as render_rpg_tab, ToggleFns};

use crate::rpg::{apply, tracker};

fn set_enabled_void(skill_id: &'static str, enabled: bool) {
    apply::set_skill_enabled(skill_id, enabled);
}

const TOGGLES: ToggleFns = ToggleFns {
    is_enabled: apply::is_skill_enabled,
    set_enabled: set_enabled_void,
};

pub fn render() {
    let _t = ueforge::counters::time_scope(&crate::counters::TIME_NS_IMGUI_GET_XP);
    ueforge::counters::bump(&crate::counters::IMGUI_TAB_RENDERS);
    render_rpg_tab(&tracker::TRACKER, Some(&TOGGLES));
}
