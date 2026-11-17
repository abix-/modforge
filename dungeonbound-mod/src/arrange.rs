//! The `arrange` op: the equipment packed by the mod's own math, read,
//! judged, planned and placed inside the game in one request.
//! Operator 2026-11-16: "look at how euipmne and invetory grid
//! works", "we gotta do the math properly on how its all arrange",
//! "this needs to be build into our mod. this hsoudl be fast",
//! "DRY functionality in the mod itself".
//!
//! Every owned piece is valued once by the fight judge: the margin its
//! stats add to the hero with nothing worn, against the floor's
//! guardian. grid.rs finds the layout of the open equipment cells with
//! the most value under the game's rules. It is used only when the
//! fight score with it beats the score now (win first, then hp left).
//! Pieces leave through the game's stow and go to their spot through
//! the game's move (inventory.gd). Mine: a piece the math values at 0
//! (its effects are not modeled) is kept at a tiny value, so it fills
//! room nothing else wants.
//!
//! The answer carries a line for every piece, the plan and why it was
//! used or not (operator 2026-11-16: "it needs to be logging what its
//! doing and why too so we can review its logic").

use std::sync::Mutex;
use std::time::Instant;

use godot::builtin::Vector2i;
use godot::meta::ToGodot;
use godotforge::godot4::on_main;
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use crate::fight::{self, Fighter, Run};
use crate::grid;
use crate::items::wear;
use crate::read::{self, BAG, EQUIP, TRAY};

/// Search steps before the packer keeps the best layout found.
pub const BUDGET: u64 = 2_000_000;

/// The owned items of the last arrange, so the same set is not
/// planned again.
static TRIED: Mutex<Vec<i64>> = Mutex::new(Vec::new());

pub fn register_ops() {
    OP_REGISTRY.register_many([OpDef::new(
        "arrange",
        "Pack the equipment by the mod's own math and place it with the game's own moves; \
         returns the reasoning lines. Skipped when the owned items are the same as last time",
        "{force?: false}",
        arrange,
    )]);
}

fn grid_name(g: i64) -> &'static str {
    match g {
        EQUIP => "worn",
        BAG => "bag",
        _ => "tray",
    }
}

/// Equipment rows bought with the game's own buy (game_state.gd
/// buy_equip_row, what a click on a row for sale does in
/// item_grid_ui.gd): 800 gold, then 850 more each row. Operator
/// 2026-11-16: "i unlocked equipment row for 800g. the new row is
/// 1650g. we need to handle this too. more equipment means stronger".
/// Mine: bought as soon as the gold allows, ahead of shop wares.
fn buy_rows() -> Result<Vec<String>, String> {
    let mut global = read::node("/root/Global")?;
    let mut out = Vec::new();
    let id = global.get("selected_character_id");
    while read::call(&mut global, "can_buy_equip_row", &[id.clone()])?
        .try_to::<bool>()
        .unwrap_or(false)
    {
        let cost = read::call(&mut global, "next_equip_row_cost", &[id.clone()])?;
        let ok = read::call(&mut global, "buy_equip_row", &[id.clone()])?
            .try_to::<bool>()
            .unwrap_or(false);
        let rows = read::call(&mut global, "equip_rows_open", &[id.clone()])?;
        out.push(format!(
            "rows: bought an equipment row for {cost} gold: {}; {rows} rows open, next row {} gold",
            if ok { "done" } else { "refused" },
            read::call(&mut global, "next_equip_row_cost", &[id.clone()])?
        ));
        if !ok {
            break;
        }
    }
    Ok(out)
}

/// The hero with nothing worn: the hero's stats less every worn
/// piece's.
pub fn bare(list: &[read::Owned], me: &Fighter) -> Fighter {
    let mut bare = me.clone();
    for o in list.iter().filter(|o| o.grid == EQUIP) {
        wear(&mut bare, &o.stats, -1.0);
    }
    bare
}

/// What wearing a piece with these stats is worth: the fight margin
/// they add to the bare hero (mine: at least a tiny value).
pub fn value(bare: &Fighter, base: f64, squad: &[Fighter], stats: &[(&'static str, f64)]) -> f64 {
    let mut p = bare.clone();
    wear(&mut p, stats, 1.0);
    (fight::score(&p, squad, Run::Campaign).margin - base).max(1e-6)
}

/// Every piece valued by the one judge; returns the bare hero.
pub fn value_all(list: &mut [read::Owned], me: &Fighter, squad: &[Fighter]) -> Fighter {
    let bare = bare(list, me);
    let base = fight::score(&bare, squad, Run::Campaign).margin;
    for o in list.iter_mut() {
        o.piece.value = value(&bare, base, squad, &o.stats);
    }
    bare
}

fn arrange(args: &Json) -> Result<Json, String> {
    let force = args.get("force").and_then(Json::as_bool).unwrap_or(false);
    let bought = on_main("arrange rows", buy_rows)?;
    let read_at = Instant::now();
    let (seen, me, foe) = on_main("arrange read", || {
        Ok((read::seen()?, read::player()?, read::guardian()))
    })?;
    let ids = seen.ids();
    {
        let mut tried = TRIED.lock().unwrap_or_else(|e| e.into_inner());
        if !force && bought.is_empty() && *tried == ids {
            return Ok(json!({"changed": false, "lines": []}));
        }
        *tried = ids;
    }
    let mut lines = bought;
    let foe = match foe {
        Ok(f) => f,
        Err(e) => {
            lines.push(format!(
                "packing: no foe to judge against ({e}); nothing moved"
            ));
            return Ok(json!({"changed": false, "lines": lines}));
        }
    };
    let squad = vec![foe.clone()];
    let mut list: Vec<read::Owned> = seen.list.into_iter().filter(|o| o.wearable()).collect();
    let bare = value_all(&mut list, &me, &squad);
    lines.push(format!(
        "packing: read and valued {} pieces in {:.2}s against {} (hp {} atk {} block {} speed {:.1}); \
         each by the fight margin it adds to the hero with nothing worn:",
        list.len(),
        read_at.elapsed().as_secs_f64(),
        foe.name,
        foe.max_hp,
        foe.atk,
        foe.block_max,
        foe.speed
    ));
    for o in &list {
        let p = &o.piece;
        let cells = p.shapes[0].len();
        lines.push(format!(
            "  {:<24} {:<4} at ({}, {}) turn {}  {} cells, {} holes  value {:.5}  per cell {:.5}  family {}{}",
            o.name,
            grid_name(o.grid),
            o.at.0,
            o.at.1,
            o.at.2,
            cells,
            p.holes[0].len(),
            p.value,
            p.value / cells.max(1) as f64,
            p.family,
            if p.weapon { "  weapon" } else { "" }
        ));
    }
    let open_cells = seen.open.iter().filter(|&&o| o).count();
    let only: Vec<grid::Piece> = list.iter().map(|o| o.piece.clone()).collect();
    let packed_at = Instant::now();
    let g = grid::Grid {
        w: seen.w,
        h: seen.h,
        open: seen.open,
    };
    let (plan, value, done) = grid::pack(&g, &only, seen.hands, BUDGET);
    let mut planned = bare.clone();
    for s in &plan {
        wear(&mut planned, &list[s.piece].stats, 1.0);
    }
    let now = fight::score(&me, &squad, Run::Campaign);
    let then = fight::score(&planned, &squad, Run::Campaign);
    let stays =
        |s: &grid::Spot| list[s.piece].grid == EQUIP && list[s.piece].at == (s.x, s.y, s.rot);
    let worn_now = list.iter().filter(|o| o.grid == EQUIP).count();
    let same = plan.len() == worn_now && plan.iter().all(stays);
    lines.push(format!(
        "packing: {}x{} grid, {open_cells} open cells, weapon slots {}, one piece per family; \
         {} pieces planned, value {value:.4}, {} in {:.2}s; win {:.1}% hp left {:.0}% (now {:.1}% {:.0}%). The plan:",
        g.w,
        g.h,
        if seen.hands == usize::MAX { "any".to_string() } else { seen.hands.to_string() },
        plan.len(),
        if done { "best" } else { "best found (step limit)" },
        packed_at.elapsed().as_secs_f64(),
        then.win * 100.0,
        then.hp_left * 100.0,
        now.win * 100.0,
        now.hp_left * 100.0
    ));
    for s in &plan {
        let o = &list[s.piece];
        lines.push(format!(
            "  {:<24} to ({}, {}) turn {}{}",
            o.name,
            s.x,
            s.y,
            s.rot,
            if stays(s) {
                "  (stays)".to_string()
            } else {
                format!(
                    "  (from {} ({}, {}) turn {})",
                    grid_name(o.grid),
                    o.at.0,
                    o.at.1,
                    o.at.2
                )
            }
        ));
    }
    for (i, o) in list.iter().enumerate() {
        if o.grid == EQUIP && !plan.iter().any(|s| s.piece == i) {
            lines.push(format!("  {:<24} comes off", o.name));
        }
    }
    if same {
        lines.push("packing: kept, the plan is what is worn now".into());
        return Ok(json!({"changed": false, "lines": lines}));
    }
    if !then.cmp(&now).is_gt() {
        lines.push(
            "packing: kept what is worn, the plan does not beat it (win first, then hp left)"
                .into(),
        );
        return Ok(json!({"changed": false, "lines": lines}));
    }
    lines.push("packing: using the plan, it beats what is worn".into());
    // Worn pieces that keep their spot; the rest come off first.
    let keep: Vec<i64> = plan
        .iter()
        .filter(|s| stays(s))
        .map(|s| list[s.piece].id)
        .collect();
    let moves: Vec<(i64, String, i32, i32, i32)> = plan
        .iter()
        .filter(|s| !stays(s))
        .map(|s| {
            (
                list[s.piece].id,
                list[s.piece].name.clone(),
                s.x,
                s.y,
                s.rot,
            )
        })
        .collect();
    let applied = on_main("arrange apply", move || {
        let mut out = Vec::new();
        let mut inv = read::inventory()?;
        for p in read::placements(&mut inv, EQUIP)? {
            let Some(item) = read::placed_item(&p) else {
                continue;
            };
            if keep.contains(&item.instance_id().to_i64()) {
                continue;
            }
            let ok = read::call(&mut inv, "stow", &[p.to_variant()])?;
            out.push(format!(
                "  took off {}: {}",
                item.get("display_name"),
                if ok.try_to::<bool>().unwrap_or(false) {
                    "stowed"
                } else {
                    "refused"
                }
            ));
        }
        for (id, name, x, y, rot) in &moves {
            let mut from = None;
            for g in [BAG, TRAY] {
                for p in read::placements(&mut inv, g)? {
                    if read::placed_item(&p).is_some_and(|i| i.instance_id().to_i64() == *id) {
                        from = Some(p);
                    }
                }
            }
            let Some(p) = from else {
                out.push(format!("  {name} is gone"));
                continue;
            };
            let ok = read::call(
                &mut inv,
                "move",
                &[
                    p.to_variant(),
                    EQUIP.to_variant(),
                    Vector2i::new(*x, *y).to_variant(),
                    (*rot as i64).to_variant(),
                ],
            )?;
            out.push(format!(
                "  {name} to ({x}, {y}) turn {rot}: {}",
                if ok.try_to::<bool>().unwrap_or(false) {
                    "placed"
                } else {
                    "refused"
                }
            ));
        }
        // The game's own steps after a move (qa_driver.gd
        // _equip_like_a_player): equipment_changed refolds the
        // player's stats (crawl.gd _reapply_loadout).
        let mut bus = read::node("/root/EventBus")?;
        read::call(
            &mut bus,
            "emit_signal",
            &["equipment_changed".to_variant(), (-1i64).to_variant()],
        )?;
        read::call(&mut read::node("/root/Global")?, "save_game", &[])?;
        Ok(out)
    })?;
    lines.extend(applied);
    // The moves changed what is where; the next arrange plans again.
    TRIED.lock().unwrap_or_else(|e| e.into_inner()).clear();
    Ok(json!({"changed": true, "lines": lines}))
}
