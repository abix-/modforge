//! In-game ImGui tab content rendered inside the standalone window
//! spawned by `modforge::ui::native`.
//!
//! Tab `render` functions run on the modforge render thread. They
//! read game state via the same accessors the HTTP ops use; never
//! write anything in here.

use modforge::ui::api as ui;
use modforge::ui::TabDef;

use crate::gamestate;
use crate::genes::EXT_GENE_COUNT;

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
    let live = gamestate::live_horse_count();
    let total = gamestate::horse_count();
    ui::text(&format!("Live horses: {live} / {total} roster slots"));
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
        if let Some(p) = gamestate::live_horse_ptr(i) {
            ui::text(&format!("#{i:>3} ptr=0x{p:x}"));
        }
    }
    if live > shown {
        ui::text_disabled(&format!("... +{} more (UI cap)", live - shown));
    }
}

fn render_cheats() {
    let no_tire = gamestate::no_tire();
    ui::text(&format!(
        "no_tire (vanilla cheat): {}",
        if no_tire { "ON" } else { "off" }
    ));

    let debug = gamestate::debug_mode();
    ui::text(&format!(
        "debug_mode: {}",
        if debug { "ON" } else { "off" }
    ));
    ui::separator();
    ui::text_disabled("Read-only view. Mutate via the HTTP ops");
    ui::text_disabled("(curl 127.0.0.1:33077/op).");
}
