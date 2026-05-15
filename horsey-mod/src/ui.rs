//! In-game ImGui tab content rendered inside the standalone window
//! spawned by `modforge::ui::native`.
//!
//! Tab `render` functions run on the modforge render thread. They
//! read game state via the same accessors the HTTP ops use. Writes
//! are intentionally fenced to the explicit toggle controls in the
//! Cheats tab; everything else stays read-only.

use modforge::ui::api as ui;
use modforge::ui::TabDef;

use crate::gamestate;
use crate::genes::EXT_GENE_COUNT;
use crate::horse;

/// All tabs the standalone window shows. Registered once at attach.
pub static TABS: &[TabDef] = &[
    TabDef { name: "Overview", render: render_overview },
    TabDef { name: "Horses",   render: render_horses },
    TabDef { name: "Cheats",   render: render_cheats },
];

fn render_overview() {
    ui::text("horsey-mod");
    ui::text_disabled(&format!("ext gene slots: {}", EXT_GENE_COUNT));
    ui::separator();

    if !gamestate::looks_loaded() {
        ui::text_disabled("(no save loaded -- start a game)");
        let races = gamestate::races();
        ui::text(&format!("Races:  {races}"));
        return;
    }

    let money = gamestate::money().unwrap_or(0);
    ui::text(&format!("Money:  ${money}"));

    let year = gamestate::year().unwrap_or(0);
    ui::text(&format!("Year:   {}", year + 1));

    let sleeps = gamestate::sleeps().unwrap_or(0);
    ui::text(&format!("Sleeps: {sleeps}"));

    let races = gamestate::races();
    ui::text(&format!("Races:  {races}"));
}

fn render_horses() {
    if !gamestate::looks_loaded() {
        ui::text_disabled("(no save loaded -- start a game)");
        return;
    }
    let live = gamestate::live_horse_count();
    let total = gamestate::horse_count();
    ui::text(&format!("Live horses: {live} / {total} roster slots"));
    ui::text_disabled(
        "idx  species  age/max  skill  tired  name_id  ptr",
    );
    ui::separator();

    if live == 0 {
        ui::text_disabled("(no horses in roster)");
        return;
    }

    // Cap the on-screen list so a 500-horse roster doesn't melt the
    // frame budget. Anything beyond gets a tail summary.
    const MAX_ROWS: usize = 32;
    let shown = live.min(MAX_ROWS);
    for i in 0..shown {
        let Some(p) = gamestate::live_horse_ptr(i) else { continue };
        let species = horse::species(p).unwrap_or(-1);
        let age = horse::age(p).unwrap_or(-1);
        let max_age = horse::max_age(p).unwrap_or(-1);
        let skill = horse::skill(p).unwrap_or(-1);
        let ta = horse::tired_a(p).unwrap_or(0);
        let tb = horse::tired_b(p).unwrap_or(0);
        let name_id = horse::name_id(p).unwrap_or(0);
        ui::text(&format!(
            "{i:>3}  {species:>7}  {age:>3}/{max_age:<3}  {skill:>5}  {ta}/{tb:>3}  {name_id:>7}  0x{p:x}"
        ));
    }
    if live > shown {
        ui::text_disabled(&format!("... +{} more (UI cap)", live - shown));
    }
}

fn render_cheats() {
    let mut no_tire = gamestate::no_tire();
    if ui::checkbox("no_tire (vanilla)", &mut no_tire) {
        gamestate::set_no_tire(no_tire);
    }

    let mut debug = gamestate::debug_mode();
    if ui::checkbox("debug_mode", &mut debug) {
        gamestate::set_debug_mode(debug);
    }

    ui::separator();
    ui::text_disabled("HTTP equivalents:");
    ui::text_disabled("  cheats.no_tire.set / cheats.debug_mode.set");
}
