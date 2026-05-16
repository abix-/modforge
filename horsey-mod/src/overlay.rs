//! Horsey-specific consumer of `modforge::ui::overlay`.
//!
//! Three tabs (Overview / Horses / Debug) ported from the Phase A
//! `crate::ui` module. All ImGui calls go through imgui-rs via
//! `modforge::ui::overlay::Ui`; no C++ shim involved.
//!
//! All the hook + imgui plumbing lives in [`modforge::ui::overlay`]
//! and is shared with every other native-PE mod that enables modforge's
//! `overlay-ui` Cargo feature.

use std::collections::HashSet;

use modforge::ui::overlay::{self, Condition, ImguiRenderLoop, Ui};

use crate::gamestate;
use crate::genes::EXT_GENE_COUNT;
use crate::horse;

/// Per-frame render callback state.
///
/// `expanded_row` is the owned-horse index whose Details panel is open
/// (only one at a time). `collapsed_chromos` and `ext_collapsed`
/// remember which chromosome strips the user has closed within the
/// Details panel. State is global across horses so that flipping
/// between horses keeps the strip layout stable.
struct HorseyOverlay {
    expanded_row:      Option<usize>,
    collapsed_chromos: HashSet<u8>,
    ext_collapsed:     bool,
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
                        render_horses(
                            ui,
                            &mut self.expanded_row,
                            &mut self.collapsed_chromos,
                            &mut self.ext_collapsed,
                        );
                    }
                    if let Some(_t) = ui.tab_item("Matrix") {
                        render_matrix(ui);
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

fn render_horses(
    ui: &Ui,
    expanded: &mut Option<usize>,
    collapsed_chromos: &mut HashSet<u8>,
    ext_collapsed: &mut bool,
) {
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
            render_horse_details(ui, i, p, collapsed_chromos, ext_collapsed);
            ui.separator();
        }
    }
    if owned > shown {
        ui.text_disabled(format!("... +{} more (UI cap)", owned - shown));
    }
}

/// Per-horse expanded details panel.
///
/// Layout: scalar block, bulk-op buttons, then a vertical list of
/// chromosome strips (vanilla, sourced from the in-game CRISPR table
/// via [`crate::chromosomes`]) followed by one strip for the extended
/// gene layer. Each strip has a collapse toggle.
///
/// Each cell in a strip is a small button showing the current allele
/// tier (0..3). Click cycles 0 -> 1 -> 2 -> 3 -> 0. Vanilla writes go
/// through `horse::set_vanilla_allele` (writes BOTH diploid banks,
/// matching CRISPR's apply path). Ext writes go through
/// `genes::set_horse_ext_alleles` (mat = pat = value).
fn render_horse_details(
    ui: &Ui,
    row_idx: usize,
    horse_ptr: usize,
    collapsed_chromos: &mut HashSet<u8>,
    ext_collapsed: &mut bool,
) {
    use crate::{chromosomes, genes};

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

    // HK1 container experiment. Live readout of horse+0x1d0 / +0x1dc
    // (the bytes that varied between tomtato's truck-state and
    // pasture-state byte-dumps) plus poke buttons. Every click writes
    // a line to <dll_dir>/hk1_overlay.log so the operator can hand
    // results back to the agent without restarting the game.
    {
        use crate::hk1;
        let (kind_s, sub_s) = match hk1::read_container(horse_ptr) {
            Some((k, s)) => (format!("{k}"), format!("{s}")),
            None => ("?".into(), "?".into()),
        };
        ui.text(format!("HK1: container kind (+0x1d0) = {kind_s}    sub (+0x1dc) = {sub_s}"));
        if ui.small_button(&format!("Truck (7)##hk1_truck_{row_idx}")) {
            hk1::write_kind(horse_ptr, hk1::KIND_TRUCK, &format!("ui:truck name='{name}'"));
        }
        ui.same_line();
        if ui.small_button(&format!("Pasture (9)##hk1_past_{row_idx}")) {
            hk1::write_kind(horse_ptr, hk1::KIND_PASTURE, &format!("ui:pasture name='{name}'"));
        }
        ui.same_line();
        // Probe ramp: lets the operator try unknown values 0..=15 to
        // sweep for race-line / other states without retyping curl.
        for v in [0u32, 1, 2, 3, 4, 5, 6, 8, 10, 11, 12] {
            if ui.small_button(&format!("{v}##hk1_v{v}_{row_idx}")) {
                hk1::write_kind(horse_ptr, v, &format!("ui:try{v} name='{name}'"));
            }
            ui.same_line();
        }
        ui.text_disabled("(log: hk1_overlay.log)");
    }

    // Bulk operations across the whole genome.
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

    // Vanilla: one strip per chromosome from CRISPR's table.
    let vanilla = horse::vanilla_alleles(horse_ptr).unwrap_or([0u8; 240]);
    let chromos = chromosomes::chromosome_map();
    if chromos.is_empty() {
        ui.text_disabled("(chromosome table not yet resolved -- falling back to flat layout)");
    }
    ui.text(format!("VANILLA  ({} chromosomes, click to cycle 0->1->2->3->0)", chromos.len()));

    for chromo in chromos {
        let cid = chromo.id;
        let is_collapsed = collapsed_chromos.contains(&cid);
        let toggle_label = if is_collapsed {
            format!("[>] c{cid:<2} ({} genes)##chr_{row_idx}_{cid}", chromo.slots.len())
        } else {
            format!("[v] c{cid:<2} ({} genes)##chr_{row_idx}_{cid}", chromo.slots.len())
        };
        if ui.small_button(&toggle_label) {
            if is_collapsed { collapsed_chromos.remove(&cid); }
            else { collapsed_chromos.insert(cid); }
        }
        // Show a comma-separated preview of the genes on this
        // chromosome next to its header (works whether expanded or
        // not). Useful as a one-glance chromosome identifier.
        ui.same_line();
        let preview = chromo.slots.iter()
            .map(|&flat| crate::gene_names::vanilla_gene_name(flat)
                .unwrap_or("?").to_string())
            .collect::<Vec<_>>()
            .join(", ");
        ui.text_disabled(format!(" {preview}"));
        if !is_collapsed {
            render_chromo_strip(ui, row_idx, cid, &chromo.slots, &vanilla, |flat, new_val| {
                horse::set_vanilla_allele(horse_ptr, flat as usize, new_val);
            });
        }
    }

    // Ext: one collapsible block (no chromosome metadata for our ext genes).
    let horse_id = horse_ptr as u64;
    let mut ext_vals = [0u8; 240];
    for ext_idx in 0..240 {
        if let Some((m, _p)) = genes::get_horse_ext_alleles(horse_id, ext_idx) {
            ext_vals[ext_idx] = m;
        }
    }
    let ext_label = if *ext_collapsed {
        format!("[>] ext ({} genes)##ext_{row_idx}", EXT_GENE_COUNT)
    } else {
        format!("[v] ext ({} genes)##ext_{row_idx}", EXT_GENE_COUNT)
    };
    if ui.small_button(&ext_label) {
        *ext_collapsed = !*ext_collapsed;
    }
    if !*ext_collapsed {
        // Render as a flat grid (no chromosome metadata for ext yet).
        for row in 0..15 {
            for col in 0..16 {
                let i = row * 16 + col;
                let v = ext_vals[i].min(3);
                let label = format!("{v}##e_{row_idx}_{i}");
                if ui.small_button(&label) {
                    let new_val = (v + 1) % 4;
                    let _ = genes::set_horse_ext_alleles(horse_id, i, new_val, new_val);
                }
                if col < 15 {
                    ui.same_line();
                }
            }
        }
    }

    ui.unindent();
}

/// Render one chromosome's slots as a horizontal row of buttons.
/// Each button shows the current allele tier for the gene at that
/// slot (looked up via `flat_idx` into `values`). Click cycles the
/// tier and invokes `on_click(flat_idx, new_value)`.
fn render_chromo_strip<F: FnMut(u8, u8)>(
    ui: &Ui,
    row_idx: usize,
    chromo_id: u8,
    slots: &[u8],
    values: &[u8; 240],
    mut on_click: F,
) {
    for (pos, &flat) in slots.iter().enumerate() {
        let v = values[flat as usize].min(3);
        let label = format!("{v}##c{row_idx}_{chromo_id}_{pos}");
        if ui.small_button(&label) {
            on_click(flat, (v + 1) % 4);
        }
        if ui.is_item_hovered() {
            let name = crate::gene_names::vanilla_gene_name(flat).unwrap_or("?");
            ui.tooltip(|| {
                ui.text(format!("{name}  (flat {flat}, allele tier {v})"));
            });
        }
        if pos + 1 < slots.len() {
            ui.same_line();
        }
    }
}

/// Map an allele tier (0..=3) to an RGBA color in the 0..1 range.
/// Dark grey for 0, blue, green, bright yellow for 3.
fn tier_color(tier: u8) -> [f32; 4] {
    match tier {
        0 => [0.18, 0.18, 0.20, 1.0],
        1 => [0.22, 0.45, 0.78, 1.0],
        2 => [0.30, 0.70, 0.32, 1.0],
        _ => [0.95, 0.85, 0.20, 1.0],
    }
}

/// Dwarf-Therapist-style matrix view. Rows = owned horses, columns =
/// 480 gene cells (240 vanilla grouped by chromosome + 240 ext).
/// Each cell is a tiny colored rect; hover -> tooltip; click -> cycle
/// tier (writes both diploid banks for vanilla).
fn render_matrix(ui: &Ui) {
    use crate::{chromosomes, gene_names, genes};
    if !gamestate::looks_loaded() {
        ui.text_disabled("(no save loaded -- start a game)");
        return;
    }
    let owned = gamestate::owned_horse_count();
    let chromos = chromosomes::chromosome_map();
    if chromos.is_empty() {
        ui.text_disabled("(chromosome table not resolved; matrix unavailable)");
        return;
    }
    ui.text(format!(
        "{owned} horses x 480 alleles  (vanilla = {} chromosomes, ext = {} flat)",
        chromos.len(), EXT_GENE_COUNT
    ));
    ui.text_disabled("hover for name, click to cycle 0->1->2->3->0");
    ui.separator();

    const CELL_W: f32 = 6.0;
    const CELL_H: f32 = 14.0;
    const CHROMO_GAP: f32 = 3.0;
    const EXT_GAP: f32 = 8.0;
    const NAME_COL_W: f32 = 110.0;

    ui.child_window("matrix_scroll")
        .size([0.0, 0.0])
        .horizontal_scrollbar(true)
        .build(|| {
            let dl = ui.get_window_draw_list();
            for i in 0..owned {
                let Some(p) = gamestate::owned_horse_ptr(i) else { continue };
                let name_id = horse::name_id(p).unwrap_or(0);
                let name = horse::name(p).unwrap_or_else(|| format!("#{name_id}"));

                // Horse name column (left-aligned, fixed width).
                let row_origin = ui.cursor_screen_pos();
                ui.text(&name);
                // Reset cursor to the right of the name column, same Y.
                ui.set_cursor_screen_pos([row_origin[0] + NAME_COL_W, row_origin[1]]);

                // Vanilla cells grouped by chromosome.
                let vanilla = horse::vanilla_alleles(p).unwrap_or([0u8; 240]);
                for (ci, chromo) in chromos.iter().enumerate() {
                    for &flat in &chromo.slots {
                        let tier = vanilla[flat as usize].min(3);
                        let pos = ui.cursor_screen_pos();
                        let color = tier_color(tier);
                        dl.add_rect(
                            pos,
                            [pos[0] + CELL_W, pos[1] + CELL_H],
                            color,
                        ).filled(true).build();
                        let _ = ui.invisible_button(
                            format!("vc_{i}_{flat}"),
                            [CELL_W, CELL_H],
                        );
                        if ui.is_item_hovered() {
                            let gname = gene_names::vanilla_gene_name(flat)
                                .unwrap_or("?");
                            ui.tooltip(|| {
                                ui.text(format!("{name} . {gname}  (c{}, tier {tier})", chromo.id));
                            });
                        }
                        if ui.is_item_clicked() {
                            horse::set_vanilla_allele(p, flat as usize, (tier + 1) % 4);
                        }
                        ui.same_line_with_spacing(0.0, 0.0);
                    }
                    // gap between chromosomes (skip after last)
                    if ci + 1 < chromos.len() {
                        ui.dummy([CHROMO_GAP, CELL_H]);
                        ui.same_line_with_spacing(0.0, 0.0);
                    }
                }

                // Gap then ext block.
                ui.dummy([EXT_GAP, CELL_H]);
                ui.same_line_with_spacing(0.0, 0.0);
                let horse_id = p as u64;
                for ext_idx in 0..EXT_GENE_COUNT {
                    let tier = genes::get_horse_ext_alleles(horse_id, ext_idx)
                        .map(|(m, _)| m.min(3)).unwrap_or(0);
                    let pos = ui.cursor_screen_pos();
                    dl.add_rect(
                        pos,
                        [pos[0] + CELL_W, pos[1] + CELL_H],
                        tier_color(tier),
                    ).filled(true).build();
                    let _ = ui.invisible_button(
                        format!("ec_{i}_{ext_idx}"),
                        [CELL_W, CELL_H],
                    );
                    if ui.is_item_hovered() {
                        ui.tooltip(|| {
                            ui.text(format!("{name} . ext[{ext_idx}]  (tier {tier})"));
                        });
                    }
                    if ui.is_item_clicked() {
                        let n = ((tier + 1) % 4) as u8;
                        let _ = genes::set_horse_ext_alleles(horse_id, ext_idx, n, n);
                    }
                    ui.same_line_with_spacing(0.0, 0.0);
                }
                // End of row.
                ui.new_line();
            }
        });
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
    overlay::arm(HorseyOverlay {
        expanded_row:      None,
        collapsed_chromos: HashSet::new(),
        ext_collapsed:     false,
    })
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
