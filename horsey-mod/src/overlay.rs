//! Horsey-specific consumer of `modforge::ui::overlay`.
//!
//! Three tabs (Overview / Horses / Debug) ported from the Phase A
//! `crate::ui` module. All ImGui calls go through imgui-rs via
//! `modforge::ui::overlay::Ui`; no C++ shim involved.
//!
//! All the hook + imgui plumbing lives in [`modforge::ui::overlay`]
//! and is shared with every other native-PE mod that enables modforge's
//! `overlay-ui` Cargo feature.

use modforge::ui::overlay::{self, Condition, ImguiRenderLoop, Ui};

use crate::gamestate;
use crate::genes::EXT_GENE_COUNT;
use crate::horse;

/// Per-frame render callback state.
///
/// Currently only the Horses tab needs persistent UI state: which row
/// has its Details expand open. Other tabs are stateless.
struct HorseyOverlay {
    expanded_row: Option<usize>,
}

impl ImguiRenderLoop for HorseyOverlay {
    fn render(&mut self, ui: &mut Ui) {
        ui.window("horsey-mod")
            .size([720.0, 640.0], Condition::FirstUseEver)
            .build(|| {
                if let Some(_tb) = ui.tab_bar("horsey_tabs") {
                    if let Some(_t) = ui.tab_item("Overview") {
                        render_overview(ui);
                    }
                    if let Some(_t) = ui.tab_item("Horses") {
                        render_horses(ui, &mut self.expanded_row);
                    }
                    if let Some(_t) = ui.tab_item("Debug") {
                        render_debug(ui);
                    }
                }
            });
    }
}

fn render_overview(ui: &Ui) {
    ui.text("horsey-mod");
    ui.text_disabled(format!("ext gene slots: {}", EXT_GENE_COUNT));
    ui.text_disabled(format!("overlay frames: {}", overlay::frame_count()));
    ui.separator();

    if !gamestate::looks_loaded() {
        ui.text_disabled("(no save loaded -- start a game)");
        let races = gamestate::races();
        ui.text(format!("Races:  {races}"));
        return;
    }

    let money = gamestate::money().unwrap_or(0);
    ui.text(format!("Money:  ${money}"));

    let year = gamestate::year().unwrap_or(0);
    ui.text(format!("Year:   {}", year + 1));

    let sleeps = gamestate::sleeps().unwrap_or(0);
    ui.text(format!("Sleeps: {sleeps}"));

    let races = gamestate::races();
    ui.text(format!("Races:  {races}"));
}

fn render_horses(ui: &Ui, expanded: &mut Option<usize>) {
    if !gamestate::looks_loaded() {
        ui.text_disabled("(no save loaded -- start a game)");
        return;
    }
    let owned = gamestate::owned_horse_count();
    let total = gamestate::horse_count();
    ui.text(format!("Owned: {owned}    (roster pool: {total})"));
    ui.separator();

    if owned == 0 {
        ui.text_disabled("(no horses owned)");
        return;
    }

    const MAX_ROWS: usize = 32;
    let shown = owned.min(MAX_ROWS);
    for i in 0..shown {
        let Some(p) = gamestate::owned_horse_ptr(i) else { continue };
        let name_id = horse::name_id(p).unwrap_or(0);
        let name = horse::name(p).unwrap_or_else(|| format!("#{name_id}"));
        let age = horse::age(p).unwrap_or(-1);
        let max_age = horse::max_age(p).unwrap_or(-1);
        let skill = horse::skill(p).unwrap_or(-1);

        let is_expanded = *expanded == Some(i);
        let label = if is_expanded { format!("[-]##h{i}") } else { format!("[+]##h{i}") };
        if ui.button(&label) {
            *expanded = if is_expanded { None } else { Some(i) };
        }
        ui.same_line();
        ui.text(format!("{i:>2}  {name:<16}  age {age:>3}/{max_age:<3}  skill {skill:>4}"));

        if is_expanded {
            render_horse_details(ui, i, p);
            ui.separator();
        }
    }
    if owned > shown {
        ui.text_disabled(format!("... +{} more (UI cap)", owned - shown));
    }
}

/// Per-horse expanded details panel. Scalar block + 480-cell editable
/// gene grid (vanilla 0..239, ext 240..479). Click a cell to cycle
/// 0 -> 1 -> 2 -> 3 -> 0. Bulk buttons set every cell at once.
fn render_horse_details(ui: &Ui, row_idx: usize, horse_ptr: usize) {
    use crate::genes;

    let name_id = horse::name_id(horse_ptr).unwrap_or(0);
    let name = horse::name(horse_ptr).unwrap_or_else(|| format!("#{name_id}"));
    let species = horse::species(horse_ptr).unwrap_or(-1);
    let ta = horse::tired_a(horse_ptr).unwrap_or(0);
    let tb = horse::tired_b(horse_ptr).unwrap_or(0);

    ui.indent();
    ui.text(format!(
        "name='{name}' name_id={name_id} species={species} tired={ta}/{tb}"
    ));
    ui.text(format!("ptr=0x{horse_ptr:x}"));

    // Bulk operations.
    if ui.button(&format!("All 0##bulk0_{row_idx}")) {
        horse::set_vanilla_alleles(horse_ptr, &[0u8; horse::VANILLA_GENOME_LEN]);
        let horse_id = horse_ptr as u64;
        for ext_idx in 0..240 {
            let _ = genes::set_horse_ext_alleles(horse_id, ext_idx, 0, 0);
        }
    }
    ui.same_line();
    if ui.button(&format!("All 3##bulk3_{row_idx}")) {
        horse::set_vanilla_alleles(horse_ptr, &[3u8; horse::VANILLA_GENOME_LEN]);
        let horse_id = horse_ptr as u64;
        for ext_idx in 0..240 {
            let _ = genes::set_horse_ext_alleles(horse_id, ext_idx, 3, 3);
        }
    }
    ui.same_line();
    ui.text_disabled("(writes both diploid banks for vanilla)");

    // Vanilla grid (idx 0..=239).
    ui.text("VANILLA  (idx 0..239, click cell to cycle 0->1->2->3->0)");
    let vanilla = horse::vanilla_alleles(horse_ptr).unwrap_or([0u8; 240]);
    render_allele_grid(ui, row_idx, "v", &vanilla, |idx, new_val| {
        horse::set_vanilla_allele(horse_ptr, idx, new_val);
    });

    // Ext grid (idx 240..=479 displayed; internally ext_idx 0..=239).
    ui.text("EXT      (idx 240..479)");
    let horse_id = horse_ptr as u64;
    let mut ext_vals = [0u8; 240];
    for ext_idx in 0..240 {
        if let Some((m, _p)) = genes::get_horse_ext_alleles(horse_id, ext_idx) {
            ext_vals[ext_idx] = m;
        }
    }
    render_allele_grid(ui, row_idx, "e", &ext_vals, |idx, new_val| {
        let _ = genes::set_horse_ext_alleles(horse_id, idx, new_val, new_val);
    });

    ui.unindent();
}

/// Render 240 buttons in a 16x15 grid; each is a single-digit label
/// of the current allele value. `on_click(local_idx, new_value)`
/// cycles 0 -> 1 -> 2 -> 3 -> 0.
fn render_allele_grid<F: FnMut(usize, u8)>(
    ui: &Ui,
    row_idx: usize,
    layer_tag: &str,
    values: &[u8; 240],
    mut on_click: F,
) {
    for row in 0..15 {
        for col in 0..16 {
            let i = row * 16 + col;
            let v = values[i].min(3);
            let label = format!("{v}##{layer_tag}_{row_idx}_{i}");
            if ui.small_button(&label) {
                on_click(i, (v + 1) % 4);
            }
            if col < 15 {
                ui.same_line();
            }
        }
    }
}

fn render_debug(ui: &Ui) {
    let mut no_tire = gamestate::no_tire();
    if ui.checkbox("no_tire (vanilla)", &mut no_tire) {
        gamestate::set_no_tire(no_tire);
    }

    let mut debug = gamestate::debug_mode();
    if ui.checkbox("debug_mode", &mut debug) {
        gamestate::set_debug_mode(debug);
    }

    if !gamestate::looks_loaded() {
        ui.separator();
        ui.text_disabled("(no save loaded -- start a game to enable money/year/horses)");
        return;
    }

    // --- Money ---
    ui.separator();
    let money = gamestate::money().unwrap_or(0);
    ui.text(format!("Money:  ${money}"));
    if ui.button("+1k")          { gamestate::set_money(money.saturating_add(1_000)); }
    ui.same_line();
    if ui.button("+10k")         { gamestate::set_money(money.saturating_add(10_000)); }
    ui.same_line();
    if ui.button("+100k")        { gamestate::set_money(money.saturating_add(100_000)); }
    ui.same_line();
    if ui.button("+1M")          { gamestate::set_money(money.saturating_add(1_000_000)); }
    ui.same_line();
    if ui.button("MAX")          { gamestate::set_money(99_999_999); }
    ui.same_line();
    if ui.button("zero##money")  { gamestate::set_money(0); }

    // --- Time ---
    ui.separator();
    let year = gamestate::year().unwrap_or(0);
    ui.text(format!("Year:   {} (raw {year})", year + 1));
    if ui.button("Year +1")  { gamestate::set_year(year.saturating_add(1)); }
    ui.same_line();
    if ui.button("Year +10") { gamestate::set_year(year.saturating_add(10)); }
    ui.same_line();
    if ui.button("Year -1")  { gamestate::set_year(year.saturating_sub(1)); }
    ui.same_line();
    if ui.button("Year = 0") { gamestate::set_year(0); }

    let sleeps = gamestate::sleeps().unwrap_or(0);
    ui.text(format!("Sleeps: {sleeps}"));

    // --- Bulk horse ops ---
    ui.separator();
    let live = gamestate::live_horse_count();
    ui.text(format!("Horses (live): {live}"));
    if ui.button("Clear ALL tiredness") {
        for i in 0..live {
            if let Some(p) = gamestate::live_horse_ptr(i) {
                horse::clear_tiredness(p);
            }
        }
    }
    ui.same_line();
    if ui.button("Make ALL immortal (max_age=999)") {
        for i in 0..live {
            if let Some(p) = gamestate::live_horse_ptr(i) {
                horse::set_max_age(p, 999);
            }
        }
    }
    ui.same_line();
    if ui.button("Reset ALL age to 0") {
        for i in 0..live {
            if let Some(p) = gamestate::live_horse_ptr(i) {
                horse::set_age(p, 0);
            }
        }
    }
}

/// Install the overlay. Idempotent.
pub fn arm() -> Result<(), String> {
    overlay::arm(HorseyOverlay { expanded_row: None })
}

pub fn disarm() {
    overlay::disarm();
}

pub fn is_armed() -> bool {
    overlay::is_armed()
}

pub fn frame_count() -> u64 {
    overlay::frame_count()
}
