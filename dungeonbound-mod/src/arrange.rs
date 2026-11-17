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
use crate::placement;
use crate::read::{self, BAG, EQUIP, TRAY};
use crate::sets;

/// Search steps before the packer keeps the best layout found.
pub const BUDGET: u64 = 2_000_000;

/// The owned items of the last arrange, so the same set is not
/// planned again.
static TRIED: Mutex<Vec<i64>> = Mutex::new(Vec::new());

pub fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "arrange",
            "Pack the equipment by the mod's own math and place it with the game's own moves; \
             returns the reasoning lines. Skipped when the owned items are the same as last time",
            "{force?: false}",
            arrange,
        ),
        OpDef::new(
            "spots",
            "What the spots of the worn pieces add (adjacency, edge, runes), by the game's fold \
             and by the mod's placement rules, field by field",
            "{}",
            spots,
        ),
    ]);
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

/// The game's stat weights (equipment_item.gd stat_score), by the hero
/// field each item stat lands on: bonus_hp 0.6, bonus_atk 5, bonus_armor
/// 5, bonus_speed 8, dodge, crit and multistrike 120, bonus_crit_mult 120,
/// block chance 150 and magic resist 40 (block_rolls is true in a
/// campaign), block regen 80, lifesteal 100, thorns 4, status damage 8,
/// poison_resist_pct 80.
const WEIGHTS: [(&str, f64); 18] = [
    ("stun_dmg_bonus", 8.0),
    ("max_hp", 0.6),
    ("atk", 5.0),
    ("armor", 5.0),
    ("speed", 8.0),
    ("dodge_chance", 120.0),
    ("crit_chance", 120.0),
    ("multistrike_chance", 120.0),
    ("crit_multiplier", 120.0),
    ("block_chance", 150.0),
    ("block_regen", 80.0),
    ("magic_resist", 40.0),
    ("lifesteal", 100.0),
    ("thorns_damage", 4.0),
    ("burn_dmg_bonus", 8.0),
    ("poison_dmg_bonus", 8.0),
    ("bleed_dmg_bonus", 8.0),
    ("poison_resist", 80.0),
];

/// A hero fold by the game's stat weights: differences of it value spot
/// and set bonuses on the same scale as a piece's stat_score.
pub fn weigh(fold: &read::Fold) -> f64 {
    WEIGHTS
        .iter()
        .map(|(k, w)| fold.get(*k).and_then(Json::as_f64).unwrap_or(0.0) * w)
        .sum()
}

/// The one judge of pieces and sets of pieces: the hero as the game
/// folds them (read::fold) plus what the run adds (read::Hero), in the
/// mod's fight math against `squad`.
pub struct Judge {
    pub squad: Vec<Fighter>,
    now: read::Fold,
    /// The game's fold with nothing worn.
    empty: read::Fold,
    /// The hero now less the fold of what is worn now with its
    /// placements.
    run: read::Fold,
    /// Fight margin with nothing worn.
    pub base: f64,
}

impl Judge {
    pub fn new(hero: &read::Hero, squad: Vec<Fighter>) -> Judge {
        let run = hero
            .now
            .iter()
            .filter_map(|(k, v)| {
                let d = v.as_f64()? - hero.placed.get(k)?.as_f64()?;
                Some((k.clone(), Json::from(d)))
            })
            .collect();
        let mut j = Judge {
            squad,
            now: hero.now.clone(),
            empty: hero.empty.clone(),
            run,
            base: 0.0,
        };
        j.base = j.score(&hero.empty).margin;
        j
    }

    /// The hero with a fold's pieces worn, at full hp.
    pub fn hero(&self, fold: &read::Fold) -> Fighter {
        let mut vars = self.now.clone();
        for (k, v) in fold {
            if let Some(n) = v.as_f64() {
                let d = self.run.get(k).and_then(Json::as_f64).unwrap_or(0.0);
                vars.insert(k.clone(), Json::from(n + d));
            }
        }
        let mut p = fight::from_vars("Player", &vars);
        p.hp = p.max_hp;
        p.block = p.block_max;
        p
    }

    pub fn score(&self, fold: &read::Fold) -> fight::Score {
        fight::score(&self.hero(fold), &self.squad, Run::Campaign)
    }

    /// What a piece's spot bonuses are worth for it: the stats each adds
    /// to the piece worn alone, by the game's stat weights (weigh).
    /// Mine: an adjacency bonus is worth the same for each match.
    pub fn gains(
        &self,
        piece: &grid::Piece,
        alone: &read::Fold,
        board: &placement::Board,
    ) -> placement::Gain {
        let p = &piece.place;
        let at = weigh(alone);
        let worth = |f: read::Fold| weigh(&f) - at;
        let mut g = placement::Gain::default();
        if let Some(a) = &p.adjacent
            && a.amount != 0.0
        {
            let mut f = alone.clone();
            placement::grant(&mut f, &a.stat, a.amount, &self.now);
            if !a.stat_2.is_empty() {
                placement::grant(&mut f, &a.stat_2, a.amount_2, &self.now);
            }
            g.per_match = worth(f);
        }
        if let Some(e) = &p.edge
            && e.amount != 0.0
        {
            let mut f = alone.clone();
            placement::grant(&mut f, &e.stat, e.amount, &self.now);
            g.edge = worth(f);
        }
        // Mine: one empty cell is worth the same at every count.
        if p.atk_per_empty != 0 {
            let mut f = alone.clone();
            placement::add(&mut f, "atk", p.atk_per_empty as f64);
            g.per_empty = worth(f);
        }
        let mut ids: Vec<&String> = board.runes.iter().map(|(_, r)| r).collect();
        ids.sort();
        ids.dedup();
        for id in ids {
            let mut f = alone.clone();
            if placement::rune_onto(&mut f, id, p) {
                g.runes.push((id.clone(), worth(f)));
            }
        }
        g
    }

    /// A fold of worn pieces with what their spots add
    /// (combatant_runtime.gd from_player with the grid: adjacency
    /// amount times matches, edge, runes).
    pub fn spotted(
        &self,
        fold: &read::Fold,
        grid: &grid::Grid,
        pieces: &[grid::Piece],
        layout: &[grid::Spot],
    ) -> read::Fold {
        spotted(fold, &self.now, grid, pieces, layout)
    }

    /// What each set these pieces could make is worth, at each strength
    /// step: the stats the set adds to the hero with nothing worn, by
    /// the game's stat weights (weigh).
    pub fn set_table<'a>(&self, pieces: impl IntoIterator<Item = &'a grid::Piece>) -> sets::Table {
        let places: Vec<&placement::Place> = pieces.into_iter().map(|p| &*p.place).collect();
        let tags: Vec<&str> = sets::TAGS
            .iter()
            .copied()
            .filter(|t| sets::reachable(&places, t))
            .collect();
        let steps = (sets::MAX_STRENGTH / sets::STEP).round() as usize;
        let rows = std::thread::scope(|s| {
            let jobs: Vec<_> = tags
                .iter()
                .map(|&tag| {
                    s.spawn(move || {
                        let row: Vec<f64> = (0..=steps)
                            .map(|k| {
                                if k == 0 {
                                    return 0.0;
                                }
                                let mut f = self.empty.clone();
                                sets::apply(&mut f, tag, k as f64 * sets::STEP);
                                weigh(&f) - weigh(&self.empty)
                            })
                            .collect();
                        (tag.to_string(), row)
                    })
                })
                .collect();
            jobs.into_iter().filter_map(|j| j.join().ok()).collect()
        });
        sets::Table { rows }
    }

    /// A piece's value and what its spot bonuses are worth: its value
    /// is the game's own stat_score of it (equipment_item.gd, what the
    /// game's bots pick gear by in qa_driver.gd and jerry_sim.gd).
    /// Mine: at least a tiny value, so a piece fills an empty slot.
    pub fn price(
        &self,
        piece: &mut grid::Piece,
        alone: &read::Fold,
        score: f64,
        board: &placement::Board,
    ) {
        piece.value = score.max(1e-6);
        let g = self.gains(piece, alone, board);
        if g != std::sync::Arc::as_ref(&piece.place).gain {
            std::sync::Arc::make_mut(&mut piece.place).gain = g;
        }
    }

    /// Every piece valued, with its spot bonuses, at once on every core
    /// (values already worked out come from what is remembered).
    pub fn value_all(&self, list: &mut [read::Owned], board: &placement::Board) {
        let got: Vec<(usize, grid::Piece)> = std::thread::scope(|s| {
            let list = &*list;
            let jobs: Vec<_> = (0..list.len())
                .map(|i| {
                    s.spawn(move || {
                        let mut piece = list[i].piece.clone();
                        self.price(&mut piece, &list[i].alone, list[i].score, board);
                        (i, piece)
                    })
                })
                .collect();
            jobs.into_iter().filter_map(|j| j.join().ok()).collect()
        });
        for (i, p) in got {
            list[i].piece = p;
        }
    }
}

/// The game's fold of the pieces with these object ids, on the main
/// thread.
pub fn fold_of(ids: Vec<i64>) -> Result<read::Fold, String> {
    on_main("fold", move || {
        let items: Vec<godot::obj::Gd<godot::classes::Object>> = ids
            .iter()
            .filter_map(|&id| godotforge::godot4::target::object_by_id(id).ok())
            .collect();
        read::fold(&items)
    })
}

/// The game's fold of a layout with its placements, as it builds the
/// hero (game_state.gd: from_player with placements_in(EQUIP)): each
/// piece's own placement row (its grown stats and the rest) moved to
/// its planned spot. Spot bonuses, sets and percent scaling are all the
/// game's own.
pub fn fold_placed(plan: Vec<(i64, i32, i32, i32)>) -> Result<read::Fold, String> {
    on_main("fold placed", move || {
        let mut inv = read::inventory()?;
        let mut items = Vec::new();
        let mut rows = godot::builtin::VarArray::new();
        for (id, x, y, rot) in &plan {
            let Some(row) = read::row_of(&mut inv, *id)? else {
                continue;
            };
            let Some(item) = read::placed_item(&row) else {
                continue;
            };
            let mut moved = godot::builtin::VarDictionary::new();
            for (k, v) in row.iter_shared() {
                moved.set(&k, &v);
            }
            moved.set("x", *x);
            moved.set("y", *y);
            moved.set("rot", *rot);
            moved.set("grid", EQUIP);
            rows.push(&moved.to_variant());
            items.push(item);
        }
        read::fold_in(&items, rows.to_variant())
    })
}

/// Search steps per swap in the first pass over every swap; the best
/// `FINALISTS` are packed again with the full BUDGET. Mine.
pub const QUICK: u64 = 20_000;
pub const FINALISTS: usize = 8;

/// How many forge sets or pairs go to the game's preview. Mine.
pub const PREVIEW_MOST: usize = 40;

/// Keeps the `PREVIEW_MOST` asks with the best `score`, best first: the
/// mod ranks every forge set or pair by the game's own recipe and only
/// the best are previewed by the game (operator 2026-11-17: "this
/// shouldnt take so long", "we need it all DRY done proeprly").
pub fn best_first<T>(asks: &mut Vec<T>, score: impl Fn(&T) -> f64) {
    let mut scored: Vec<(f64, T)> = asks.drain(..).map(|a| (score(&a), a)).collect();
    scored.sort_by(|a, b| b.0.total_cmp(&a.0));
    scored.truncate(PREVIEW_MOST);
    asks.extend(scored.into_iter().map(|(_, a)| a));
}

/// Owned pieces `remove` turned into `add` (a forge, a socketed gem).
pub struct Swap {
    pub remove: Vec<usize>,
    pub add: grid::Piece,
}

/// Full packs already done, by what was packed: the same pieces on the
/// same grid pack to the same value, so a step that looks again (the
/// shop after a buy is refused, the next ware) does not pack again.
static PACKED: Mutex<Vec<(u64, f64)>> = Mutex::new(Vec::new());

/// A fold of worn pieces with what their spots add, the percent ones
/// taken of `now` (Judge::spotted).
pub fn spotted(
    fold: &read::Fold,
    now: &read::Fold,
    grid: &grid::Grid,
    pieces: &[grid::Piece],
    layout: &[grid::Spot],
) -> read::Fold {
    let all = grid::worn_of(pieces, layout);
    let mut f = fold.clone();
    let per_empty: i64 = all.iter().map(|w| w.place.atk_per_empty).sum();
    if per_empty != 0 {
        let change = placement::empty_change(&grid.board, &all);
        placement::add(&mut f, "atk", (per_empty * change) as f64);
        placement::add(&mut f, "built_atk", (per_empty * change) as f64);
    }
    for (w, (m, e, runes)) in all.iter().zip(placement::earned(&grid.board, &all)) {
        let p = w.place;
        if let Some(a) = &p.adjacent
            && m > 0
        {
            placement::grant(&mut f, &a.stat, a.amount * m as f64, now);
            if !a.stat_2.is_empty() {
                placement::grant(&mut f, &a.stat_2, a.amount_2 * m as f64, now);
            }
        }
        if let Some(ed) = &p.edge
            && e
        {
            placement::grant(&mut f, &ed.stat, ed.amount, now);
        }
        for r in &runes {
            placement::rune_onto(&mut f, r, p);
        }
    }
    f
}

/// The worn pieces as a layout of `list`.
pub fn worn_layout(list: &[read::Owned]) -> Vec<grid::Spot> {
    list.iter()
        .enumerate()
        .filter(|(_, o)| o.grid == EQUIP)
        .map(|(i, o)| grid::Spot {
            piece: i,
            x: o.at.0,
            y: o.at.1,
            rot: o.at.2,
        })
        .collect()
}

/// What the spots of what is worn add, by the game (its fold with the
/// placements less without) and by the mod, field by field; for
/// research_placement.
fn spots(_: &Json) -> Result<Json, String> {
    on_main("spots", || {
        let seen = read::seen()?;
        let list: Vec<read::Owned> = seen.list.iter().filter(|o| o.wearable()).cloned().collect();
        let pieces: Vec<grid::Piece> = list.iter().map(|o| o.piece.clone()).collect();
        let layout = worn_layout(&list);
        let g = seen.grid();
        let h = &seen.hero;
        let ours = spotted(&h.worn, &h.now, &g, &pieces, &layout);
        let diff = |a: &read::Fold| -> serde_json::Map<String, Json> {
            a.iter()
                .filter_map(|(k, v)| {
                    let d = v.as_f64()? - h.worn.get(k)?.as_f64()?;
                    (d.abs() > 1e-9).then(|| (k.clone(), Json::from(d)))
                })
                .collect()
        };
        let all = grid::worn_of(&pieces, &layout);
        let earned = placement::earned(&g.board, &all);
        let worn: Vec<Json> = layout
            .iter()
            .zip(&earned)
            .map(|(s, (m, e, r))| {
                let o = &list[s.piece];
                json!({"name": o.name, "at": [s.x, s.y, s.rot], "matches": m, "edge": e,
                       "runes": r, "adjacent": format!("{:?}", o.piece.place.adjacent),
                       "edge_rule": format!("{:?}", o.piece.place.edge)})
            })
            .collect();
        Ok(json!({
            "game": diff(&h.placed),
            "mod": diff(&ours),
            "board": format!("{:?}", g.board),
            "empty": {
                "mod": placement::empty_cells(&g.board, &all),
                "mod_base": g.board.base.len(),
                "game": read::empty_equip_cells(read::call(
                    &mut read::inventory()?,
                    "placements_in",
                    &[EQUIP.to_variant()],
                )?)?,
                "game_none": read::empty_equip_cells(godot::builtin::VarArray::new().to_variant())?,
                "worn_all": seen.list.iter().filter(|o| o.grid == EQUIP).count(),
                "worn_judged": layout.len(),
            },
            "worn": worn,
        }))
    })
}

fn pack_key(g: &grid::Grid, pieces: &[grid::Piece], hands: usize, budget: u64) -> u64 {
    use std::hash::{Hash, Hasher};
    let mut h = std::collections::hash_map::DefaultHasher::new();
    (g.w, g.h, &g.open, hands, budget).hash(&mut h);
    (g.board.size, &g.board.runes, format!("{:?}", g.sets.rows)).hash(&mut h);
    for p in pieces {
        (p.value.to_bits(), &p.shapes, &p.holes, &p.family, p.weapon).hash(&mut h);
        format!("{:?}", p.place).hash(&mut h);
    }
    h.finish()
}

/// The packer's best equipment value, from the cache when packed
/// before.
pub fn packed_value(g: &grid::Grid, pieces: &[grid::Piece], hands: usize, budget: u64) -> f64 {
    let key = pack_key(g, pieces, hands, budget);
    if let Some(&(_, v)) = PACKED
        .lock()
        .unwrap_or_else(|e| e.into_inner())
        .iter()
        .find(|(k, _)| *k == key)
    {
        return v;
    }
    let v = grid::pack(g, pieces, hands, budget).1;
    let mut c = PACKED.lock().unwrap_or_else(|e| e.into_inner());
    if c.len() >= 256 {
        c.remove(0);
    }
    c.push((key, v));
    v
}

/// The packer's best equipment value with no swap, and the best swaps
/// by the same value (best first, at most `finalists`), each as (value,
/// index into `swaps`). Mine: a swap is worth its packed value.
pub fn rank(
    g: &grid::Grid,
    hands: usize,
    owned: &[grid::Piece],
    swaps: &[Swap],
    finalists: usize,
) -> (f64, Vec<(f64, usize)>) {
    let packed = |s: Option<&Swap>, budget: u64| {
        let mut pieces: Vec<grid::Piece> = (0..owned.len())
            .filter(|i| s.is_none_or(|s| !s.remove.contains(i)))
            .map(|i| owned[i].clone())
            .collect();
        pieces.extend(s.map(|s| s.add.clone()));
        packed_value(g, &pieces, hands, budget)
    };
    let mut top: Vec<(f64, usize)> = swaps
        .iter()
        .enumerate()
        .map(|(k, s)| (packed(Some(s), QUICK), k))
        .collect();
    top.sort_by(|a, b| b.0.total_cmp(&a.0));
    top.truncate(finalists);
    for t in top.iter_mut() {
        t.0 = packed(Some(&swaps[t.1]), BUDGET);
    }
    top.sort_by(|a, b| b.0.total_cmp(&a.0));
    (packed(None, BUDGET), top)
}

pub fn arrange(args: &Json) -> Result<Json, String> {
    let force = args.get("force").and_then(Json::as_bool).unwrap_or(false);
    let bought = on_main("arrange rows", buy_rows)?;
    let read_at = Instant::now();
    let (seen, foe) = on_main("arrange read", || Ok((read::seen()?, read::guardian())))?;
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
    let read_s = read_at.elapsed().as_secs_f64();
    let value_at = Instant::now();
    let judge = Judge::new(&seen.hero, vec![foe.clone()]);
    let mut list: Vec<read::Owned> = seen.list.iter().filter(|o| o.wearable()).cloned().collect();
    judge.value_all(&mut list, &seen.board);
    lines.push(format!(
        "packing: read {} pieces in {read_s:.2}s, valued in {:.2}s, against {} (hp {} atk {} block {} speed {:.1}); \
         each by the fight margin it adds to the hero with nothing worn:",
        list.len(),
        value_at.elapsed().as_secs_f64(),
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
    let mut g = seen.grid();
    g.sets = judge.set_table(&only);
    let (plan, value, done) = grid::pack(&g, &only, seen.hands, BUDGET);
    // Kept or used by the game's stat score: the plan's value against
    // what is worn now, counted the same way. The fight odds, each
    // folded by the game with its placements, are only logged.
    let worn_value = grid::layout_value(&g, &only, &worn_layout(&list));
    let now = judge.score(&seen.hero.placed);
    let then = judge.score(&fold_placed(
        plan.iter()
            .map(|s| (list[s.piece].id, s.x, s.y, s.rot))
            .collect(),
    )?);
    let spot_worth = grid::spot_values(&g, &only, &plan);
    let (spot_got, empty) = {
        let all = grid::worn_of(&only, &plan);
        (
            placement::earned(&g.board, &all),
            placement::empty_cells(&g.board, &all),
        )
    };
    let stays =
        |s: &grid::Spot| list[s.piece].grid == EQUIP && list[s.piece].at == (s.x, s.y, s.rot);
    let worn_now = list.iter().filter(|o| o.grid == EQUIP).count();
    let same = plan.len() == worn_now && plan.iter().all(stays);
    lines.push(format!(
        "packing: {}x{} grid, {open_cells} open cells, weapon slots {}, one piece per family; \
         {} pieces planned, value {value:.1} (worn now {worn_value:.1}), {} in {:.2}s; win {:.1}% hp left {:.0}% (now {:.1}% {:.0}%). The plan:",
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
    for (k, s) in plan.iter().enumerate() {
        let o = &list[s.piece];
        let (m, e, runes) = &spot_got[k];
        let mut spot = Vec::new();
        if *m > 0 {
            spot.push(format!("{m} matching beside it"));
        }
        if *e {
            spot.push("its edge bonus".to_string());
        }
        for r in runes {
            spot.push(format!("rune {r}"));
        }
        if o.piece.place.atk_per_empty != 0 {
            spot.push(format!(
                "{empty} empty cells at {} atk each",
                o.piece.place.atk_per_empty
            ));
        }
        lines.push(format!(
            "  {:<24} to ({}, {}) turn {}{}{}",
            o.name,
            s.x,
            s.y,
            s.rot,
            if spot.is_empty() {
                String::new()
            } else {
                format!("  spot: {} (worth {:.4})", spot.join(", "), spot_worth[k])
            },
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
    let planned: Vec<&placement::Place> = plan.iter().map(|s| &*only[s.piece].place).collect();
    for (tag, s) in sets::active(&planned) {
        lines.push(format!(
            "  set {tag} at strength {s:.2} (worth {:.4})",
            g.sets.worth(tag, s)
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
    // Operator 2026-11-17: "win rate isnt how we choose pitam gear", "we
    // want to use all our slots".
    if value <= worn_value {
        lines.push("packing: kept what is worn, the plan's value does not beat it".into());
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
    // Plans again only when the game refused a move: a plan it took is
    // what the next search would find again (it cost a second search of
    // seconds at every stop). Operator 2026-11-17: "need all these
    // thigns to be fast".
    if applied
        .iter()
        .any(|l| l.ends_with("refused") || l.ends_with("is gone"))
    {
        TRIED.lock().unwrap_or_else(|e| e.into_inner()).clear();
    }
    lines.extend(applied);
    Ok(json!({"changed": true, "lines": lines}))
}
