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

/// Piece values already worked out, by judge and piece: a piece's value
/// stays the same until the hero or the foe changes, so a step only
/// values pieces it has not seen. Operator 2026-11-17: "we want this
/// fast bro".
static VALUES: Mutex<Vec<(u64, f64)>> = Mutex::new(Vec::new());

fn hash_of(parts: &impl std::hash::Hash) -> u64 {
    use std::hash::Hasher;
    let mut h = std::collections::hash_map::DefaultHasher::new();
    parts.hash(&mut h);
    h.finish()
}

/// The one judge of pieces and sets of pieces: the hero as the game
/// folds them (read::fold) plus what the run adds (read::Hero), in the
/// mod's fight math against `squad`.
pub struct Judge {
    pub squad: Vec<Fighter>,
    now: read::Fold,
    /// The hero now less the fold of what is worn now.
    run: read::Fold,
    /// Fight margin with nothing worn.
    pub base: f64,
    /// What the judge's values depend on besides the piece.
    key: u64,
}

impl Judge {
    pub fn new(hero: &read::Hero, squad: Vec<Fighter>) -> Judge {
        let run = hero
            .now
            .iter()
            .filter_map(|(k, v)| {
                let d = v.as_f64()? - hero.worn.get(k)?.as_f64()?;
                Some((k.clone(), Json::from(d)))
            })
            .collect();
        let key = hash_of(&(
            Json::Object(hero.now.clone()).to_string(),
            Json::Object(hero.worn.clone()).to_string(),
            Json::Object(hero.empty.clone()).to_string(),
            format!("{squad:?}"),
        ));
        let mut j = Judge {
            squad,
            now: hero.now.clone(),
            run,
            base: 0.0,
            key,
        };
        j.base = j.score(&hero.empty).margin;
        j
    }

    fn value_key(&self, alone: &read::Fold) -> u64 {
        hash_of(&(self.key, Json::Object(alone.clone()).to_string()))
    }

    fn cached(&self, alone: &read::Fold) -> Option<f64> {
        let k = self.value_key(alone);
        VALUES
            .lock()
            .unwrap_or_else(|e| e.into_inner())
            .iter()
            .find(|(c, _)| *c == k)
            .map(|&(_, v)| v)
    }

    fn remember(&self, alone: &read::Fold, v: f64) {
        let k = self.value_key(alone);
        let mut c = VALUES.lock().unwrap_or_else(|e| e.into_inner());
        if c.len() >= 4096 {
            c.drain(..1024);
        }
        c.push((k, v));
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

    /// What wearing a piece is worth: the fight margin it adds to the
    /// hero with nothing worn (mine: at least a tiny value).
    pub fn value(&self, alone: &read::Fold) -> f64 {
        if let Some(v) = self.cached(alone) {
            return v;
        }
        let v = (self.score(alone).margin - self.base).max(1e-6);
        self.remember(alone, v);
        v
    }

    /// Every piece valued: from what is remembered, the rest at once on
    /// every core.
    pub fn value_all(&self, list: &mut [read::Owned]) {
        let new: Vec<usize> = (0..list.len())
            .filter(|&i| match self.cached(&list[i].alone) {
                Some(v) => {
                    list[i].piece.value = v;
                    false
                }
                None => true,
            })
            .collect();
        let got: Vec<(usize, f64)> = std::thread::scope(|s| {
            let list = &*list;
            let jobs: Vec<_> = new
                .iter()
                .map(|&i| {
                    s.spawn(move || (i, (self.score(&list[i].alone).margin - self.base).max(1e-6)))
                })
                .collect();
            jobs.into_iter().filter_map(|j| j.join().ok()).collect()
        });
        for (i, v) in got {
            self.remember(&list[i].alone, v);
            list[i].piece.value = v;
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

fn pack_key(g: &grid::Grid, pieces: &[grid::Piece], hands: usize, budget: u64) -> u64 {
    use std::hash::{Hash, Hasher};
    let mut h = std::collections::hash_map::DefaultHasher::new();
    (g.w, g.h, &g.open, hands, budget).hash(&mut h);
    for p in pieces {
        (p.value.to_bits(), &p.shapes, &p.holes, &p.family, p.weapon).hash(&mut h);
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
    let mut list: Vec<read::Owned> = seen.list.into_iter().filter(|o| o.wearable()).collect();
    judge.value_all(&mut list);
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
    let g = grid::Grid {
        w: seen.w,
        h: seen.h,
        open: seen.open,
    };
    let (plan, value, done) = grid::pack(&g, &only, seen.hands, BUDGET);
    // Both by the same judge: the plan and what is worn, each folded by
    // the game.
    let now = judge.score(&seen.hero.worn);
    let then = judge.score(&fold_of(plan.iter().map(|s| list[s.piece].id).collect())?);
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
    // Operator 2026-11-17: "empty equipment slots are wasted". A plan that
    // wears more pieces and does not lose is used too.
    let order = then.cmp(&now);
    if order.is_lt() || (order.is_eq() && plan.len() <= worn_now) {
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
