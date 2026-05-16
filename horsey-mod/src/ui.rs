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
    TabDef { name: "Debug",    render: render_debug },
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
    let owned = gamestate::owned_horse_count();
    let total = gamestate::horse_count();
    ui::text(&format!("Owned: {owned}    (roster pool: {total})"));
    ui::text_disabled(
        "idx  name              species  age/max  skill  tired",
    );
    ui::separator();

    if owned == 0 {
        ui::text_disabled("(no horses owned)");
        return;
    }

    // Cap the on-screen list so a giant herd doesn't melt the frame budget.
    const MAX_ROWS: usize = 32;
    let shown = owned.min(MAX_ROWS);
    for i in 0..shown {
        let Some(p) = gamestate::owned_horse_ptr(i) else { continue };
        let name_id = horse::name_id(p).unwrap_or(0);
        let name = horse::name(p).unwrap_or_else(|| format!("#{name_id}"));
        let species = horse::species(p).unwrap_or(-1);
        let age = horse::age(p).unwrap_or(-1);
        let max_age = horse::max_age(p).unwrap_or(-1);
        let skill = horse::skill(p).unwrap_or(-1);
        let ta = horse::tired_a(p).unwrap_or(0);
        let tb = horse::tired_b(p).unwrap_or(0);
        ui::text(&format!(
            "{i:>3}  {name:<16}  {species:>7}  {age:>3}/{max_age:<3}  {skill:>5}  {ta}/{tb}"
        ));
    }
    if owned > shown {
        ui::text_disabled(&format!("... +{} more (UI cap)", owned - shown));
    }
}

fn render_debug() {
    // --- Toggles ---
    let mut no_tire = gamestate::no_tire();
    if ui::checkbox("no_tire (vanilla)", &mut no_tire) {
        gamestate::set_no_tire(no_tire);
    }

    let mut debug = gamestate::debug_mode();
    if ui::checkbox("debug_mode", &mut debug) {
        gamestate::set_debug_mode(debug);
    }

    if !gamestate::looks_loaded() {
        ui::separator();
        ui::text_disabled("(no save loaded -- start a game to enable money/year/horses)");
        return;
    }

    // --- Money ---
    ui::separator();
    let money = gamestate::money().unwrap_or(0);
    ui::text(&format!("Money:  ${money}"));
    if ui::button("+1k")          { gamestate::set_money(money.saturating_add(1_000)); }
    ui::same_line();
    if ui::button("+10k")         { gamestate::set_money(money.saturating_add(10_000)); }
    ui::same_line();
    if ui::button("+100k")        { gamestate::set_money(money.saturating_add(100_000)); }
    ui::same_line();
    if ui::button("+1M")          { gamestate::set_money(money.saturating_add(1_000_000)); }
    ui::same_line();
    if ui::button("MAX")          { gamestate::set_money(99_999_999); }
    ui::same_line();
    if ui::button("zero##money")  { gamestate::set_money(0); }

    // --- Time ---
    ui::separator();
    let year = gamestate::year().unwrap_or(0);
    ui::text(&format!("Year:   {} (raw {year})", year + 1));
    if ui::button("Year +1")  { gamestate::set_year(year.saturating_add(1)); }
    ui::same_line();
    if ui::button("Year +10") { gamestate::set_year(year.saturating_add(10)); }
    ui::same_line();
    if ui::button("Year -1")  { gamestate::set_year(year.saturating_sub(1)); }
    ui::same_line();
    if ui::button("Year = 0") { gamestate::set_year(0); }

    let sleeps = gamestate::sleeps().unwrap_or(0);
    ui::text(&format!("Sleeps: {sleeps}"));

    // --- Bulk horse ops ---
    ui::separator();
    let live = gamestate::live_horse_count();
    ui::text(&format!("Horses (live): {live}"));
    if ui::button("Clear ALL tiredness") {
        for i in 0..live {
            if let Some(p) = gamestate::live_horse_ptr(i) {
                horse::clear_tiredness(p);
            }
        }
    }
    ui::same_line();
    if ui::button("Make ALL immortal (max_age=999)") {
        for i in 0..live {
            if let Some(p) = gamestate::live_horse_ptr(i) {
                horse::set_max_age(p, 999);
            }
        }
    }
    ui::same_line();
    if ui::button("Reset ALL age to 0") {
        for i in 0..live {
            if let Some(p) = gamestate::live_horse_ptr(i) {
                horse::set_age(p, 0);
            }
        }
    }

}
