//! The game's own fight simulation on the deploy screen, and the
//! placement search over it (research_simulation run_game_simulation
//! and record_copy_units, docs/research.md "The game's own fight
//! simulation").
//!
//! One try: deep copy the battle record, move our units in the copy,
//! build a BattleSetting from it the way the game's fight check does
//! (FightAuth Main.SimpleAuth), run MatchUtility.StartFastBattleSimulation
//! and read each player's FightReport. The live record and the field
//! are never changed. Each try is its own main thread job, so the game
//! keeps running between tries.
//!
//! Where a unit may stand is the game's own check,
//! TerritoryManager.CanMoveUnit (0 is allowed; research_deploy
//! can_move_unit). Positions are unit centres, the same in the record
//! and in that check.

use std::sync::Arc;
use std::time::{Duration, Instant};

use modforge::buying::{Offer, baskets};
use modforge::placement::{Area, Piece, free_spot, improve};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, owned_object, with_object};

use crate::deploy::{bound, current_match, field, object};

/// Handles kept between tries (released by `release`). Main thread
/// work only touches them inside MAIN_QUEUE jobs.
struct Held {
    /// A deep copy of the live record; every try copies it again.
    base: i32,
    setting: i32,
    territory: i32,
    /// Our live CardElements, in the record's unit order.
    cards: Vec<i32>,
    card_ids: Vec<i64>,
    /// Units on the field at the start (units per purchase, summed).
    units: i64,
    seat: i64,
    round: i64,
}

/// One simulated fight, per side.
#[derive(Clone, Copy, Debug, Default)]
pub struct Outcome {
    pub ours_alive: i64,
    /// Our units at the start of the fight (each card's units per
    /// purchase, summed); the fight report has no such count.
    pub ours_total: i64,
    pub enemy_alive: i64,
    pub ours_score: i64,
    pub enemy_score: i64,
}

impl Outcome {
    fn to_json(self) -> Json {
        json!({
            "ours_alive": self.ours_alive, "ours_total": self.ours_total,
            "ours_left_percent": (self.left() * 1000.0).round() / 10.0,
            "enemy_alive": self.enemy_alive,
            "ours_score": self.ours_score, "enemy_score": self.enemy_score, "won": self.won(),
        })
    }

    pub fn won(&self) -> bool {
        self.enemy_alive == 0 && self.ours_alive > 0
    }

    /// Share of our units still alive, 0 to 1.
    pub fn left(&self) -> f64 {
        if self.ours_total > 0 { self.ours_alive as f64 / self.ours_total as f64 } else { 0.0 }
    }

    /// Higher is better: any win above any loss, then the share of our
    /// units left (operator 2026-11-07: "highest PERCENTAGE of units
    /// left ... 100% being perfect"), then fewer enemy units alive (so
    /// a closer loss still ranks).
    pub fn value(&self) -> f64 {
        (self.won() as i64 as f64) * 1e6 + self.left() * 1e4 - self.enemy_alive as f64
    }
}

fn get(list: &MonoObject, i: i64) -> Result<Option<MonoObject>, String> {
    Ok(object(list.invoke("get_Item", &json!([i]))?))
}

fn int(o: &MonoObject, f: &str) -> Result<i64, String> {
    o.read_field(f)?.as_i64().ok_or_else(|| format!("{f} is not a number"))
}

/// The record's units for `seat` in `round`: playerRecords[seat] (not
/// GetPlayerRecord, whose int binds to a PlayerController overload),
/// GetRoundRecord(round), playerData.units.
fn record_units(rec: &MonoObject, seat: i64, round: i64) -> Result<Vec<MonoObject>, String> {
    let prs = field(rec, "playerRecords")?.ok_or("no playerRecords")?;
    let pr = get(&prs, seat)?.ok_or("no player record for our seat")?;
    let rr = object(pr.invoke("GetRoundRecord", &json!([round]))?).ok_or("no round record")?;
    let pd = field(&rr, "playerData")?.ok_or("no playerData")?;
    let units = field(&pd, "units")?.ok_or("no units")?;
    (0..units.list_len_or_zero()?).filter_map(|i| get(&units, i).transpose()).collect()
}

/// Everything a try needs, and our units as pieces. Main thread only.
fn hold() -> Result<(Held, Vec<Piece>), String> {
    let m = current_match()?;
    let pc = field(&m, "localPlayerController")?.ok_or("no localPlayerController")?;
    let recorder = field(&pc, "replaySystem")?
        .and_then(|rs| field(&rs, "battleRecorder").ok().flatten())
        .ok_or("no replaySystem.battleRecorder")?;
    let live = object(recorder.invoke("GetCurrentRecord", &json!([]))?).ok_or("no current battle record")?;
    let base = object(live.invoke("GetDeepCopy", &json!([]))?).ok_or("GetDeepCopy gave no record")?;
    let seat = int(&base, "_Seat_k__BackingField")?;
    let round = (base.invoke("GetRoundCount", &json!([]))?.as_i64().unwrap_or(0) - 1).max(0);
    let map = base.invoke("GetMapID", &json!([]))?;

    let cfg = crate::units::config()?;
    let setting = object(cfg.invoke("GetMatchSetting", &json!([map]))?).ok_or("Config.GetMatchSetting gave nothing")?;
    let territory = field(&pc, "territoryManager")?.ok_or("no territoryManager")?;

    let recs = record_units(&base, seat, round)?;
    let live_cards = field(&pc, "unitManager")?.and_then(|um| field(&um, "units").ok().flatten()).ok_or("no unitManager.units")?;
    if live_cards.list_len_or_zero()? != recs.len() as i64 {
        return Err(format!("{} cards on the field, {} in the record", live_cards.list_len_or_zero()?, recs.len()));
    }
    let mut pieces = Vec::new();
    let mut cards = Vec::new();
    let mut card_ids = Vec::new();
    for (i, r) in recs.iter().enumerate() {
        let card = get(&live_cards, i as i64)?.ok_or("missing card")?;
        let id = field(&card, "unitData")?.map(|d| int(&d, "id")).transpose()?.unwrap_or(0);
        if id != int(r, "id")? {
            return Err(format!("card {i}: field has {id}, record has {}", int(r, "id")?));
        }
        let b = field(&card, "mapElement")?
            .and_then(|me| me.read_field("bound").ok())
            .and_then(|v| v.as_str().and_then(bound))
            .ok_or("no mapElement.bound")?;
        let pos = r.read_field("position")?;
        pieces.push(Piece {
            x: pos["x"].as_i64().unwrap_or(0) as i32,
            y: pos["y"].as_i64().unwrap_or(0) as i32,
            w: b[2] as i32,
            h: b[3] as i32,
        });
        card_ids.push(id);
        cards.push(card);
    }
    let keep = |o: MonoObject| {
        let h = o.handle().0;
        std::mem::forget(o);
        h
    };
    let held = Held {
        base: keep(base),
        setting: keep(setting),
        territory: keep(territory),
        cards: cards.into_iter().map(keep).collect(),
        units: card_ids.iter().map(|&id| crate::units::unit(id).map(|u| u.count as i64)).sum::<Result<i64, _>>()?,
        card_ids,
        seat,
        round,
    };
    Ok((held, pieces))
}

fn release(h: Held) {
    let _ = MAIN_QUEUE.run_result("sim release", Duration::from_secs(5), move || {
        for x in [h.base, h.setting, h.territory].into_iter().chain(h.cards) {
            drop(owned_object(x));
        }
        Ok::<_, String>(())
    });
}

/// Our deploy area for a unit's whole footprint: the game's own check
/// allowed centres up to x 275 and y -60 for a 50 by 20 unit, and
/// refused x 300 and y -40 (research_deploy can_move_unit), so x -300
/// to 300 and y -310 to -50. Used for a unit not bought yet, which has
/// no CardElement to ask the game about.
const OUR_AREA: Area = Area { x0: -300, x1: 300, y0: -310, y1: -50 };

/// Whether the game lets piece `i` stand there: the game's own check
/// for a unit on the field, OUR_AREA for one being bought. Main thread
/// only.
fn allowed(h: &Held, i: usize, p: &Piece) -> Result<bool, String> {
    let Some(card) = h.cards.get(i) else {
        return Ok(OUR_AREA.holds(p));
    };
    with_object(h.territory, |tm| {
        let r = tm.invoke("CanMoveUnit", &json!([{"$handle": card}, {"x": p.x, "y": p.y}, false]))?;
        Ok(r.as_i64() == Some(0))
    })
}

/// One item in the Star Expedition shop (the local player's
/// ReinforcementShopManager.reinforceItems, research_deploy
/// reinforcement_shop): its slot, card, level and price.
#[derive(Clone, Copy, Debug)]
struct Buy {
    slot: i64,
    card: i64,
    level: i64,
    price: i64,
    /// Units per purchase.
    count: i64,
}

/// The shop's unit items and our supply. Main thread only.
fn shop() -> Result<(Vec<Buy>, i64), String> {
    let m = current_match()?;
    let pc = field(&m, "localPlayerController")?.ok_or("no localPlayerController")?;
    let supply = field(&pc, "player")?.map(|p| int(&p, "supply")).transpose()?.ok_or("no player")?;
    let rs = field(&pc, "reinforcementShopManager")?.ok_or("no reinforcementShopManager")?;
    let items = field(&rs, "reinforceItems")?.ok_or("no reinforceItems")?;
    let mut out = Vec::new();
    for i in 0..items.list_len_or_zero()? {
        let Some(it) = get(&items, i)? else { continue };
        let Some(cfg) = field(&it, "_config_k__BackingField")? else { continue };
        // handCardType 2 is a unit (all five on 2026-11-07 were cards).
        if int(&cfg, "handCardType")? != 2 {
            continue;
        }
        let card = int(&cfg, "relatedID")?;
        let count = crate::units::unit(card)?.count as i64;
        out.push(Buy { slot: i, card, level: int(&cfg, "level")?, price: int(&it, "reinforcePrice")?, count });
    }
    Ok((out, supply))
}

/// One simulated fight with our units at `pieces` (the field's cards
/// first, then one per `buys`). Main thread only.
fn simulate(h: &Held, pieces: &[Piece], buys: &[Buy]) -> Result<Outcome, String> {
    let rec = with_object(h.base, |b| b.invoke("GetDeepCopy", &json!([])))?;
    let rec = object(rec).ok_or("GetDeepCopy gave no record")?;
    for (u, p) in record_units(&rec, h.seat, h.round)?.iter().zip(pieces) {
        u.write_field("position", &json!({"x": p.x, "y": p.y}))?;
    }
    if !buys.is_empty() {
        // A bought unit is a new NewUnitData in the copy (research_simulation
        // bought_unit_in_copy). The shop's level 1 is a record's level 0
        // (the lineup's Void Eye: shop level 1, record level 0); not yet
        // proven for level 2.
        let prs = field(&rec, "playerRecords")?.ok_or("no playerRecords")?;
        let pr = get(&prs, h.seat)?.ok_or("no player record")?;
        let rr = object(pr.invoke("GetRoundRecord", &json!([h.round]))?).ok_or("no round record")?;
        let pd = field(&rr, "playerData")?.ok_or("no playerData")?;
        let units = field(&pd, "units")?.ok_or("no units")?;
        let mut index = int(&pd, "unitIndex")?;
        for (b, p) in buys.iter().zip(&pieces[h.cards.len()..]) {
            let u = object(invoke_static("Unityforge.Shim.Il2CppBridge", "NewObject", &json!(["Il2CppGameRiver.NewUnitData", "[]"]))?)
                .ok_or("new NewUnitData gave nothing")?;
            u.write_field("id", &json!(b.card))?;
            u.write_field("index", &json!(index))?;
            u.write_field("level", &json!((b.level - 1).max(0)))?;
            u.write_field("sellSupply", &json!(b.price))?;
            u.write_field("position", &json!({"x": p.x, "y": p.y}))?;
            units.invoke("Add", &json!([{"$handle": u.handle().0}]))?;
            index += 1;
        }
        pd.write_field("unitIndex", &json!(index))?;
    }
    let ctor = json!([2, {"$handle": h.setting}, {"$handle": rec.handle().0}, false, h.seat, h.round, null]).to_string();
    let bs = object(invoke_static("Unityforge.Shim.Il2CppBridge", "NewObject", &json!(["Il2CppGameRiver.BattleSetting", ctor]))?)
        .ok_or("new BattleSetting gave nothing")?;
    let sim = object(invoke_static("Il2CppGameRiver.Client.MatchUtility", "StartFastBattleSimulation", &json!([{"$handle": bs.handle().0}]))?)
        .ok_or("StartFastBattleSimulation gave nothing")?;
    let fr = object(sim.invoke("GetFightResult", &json!([]))?).ok_or("no FightResult")?;
    let reports = field(&fr, "reports")?.ok_or("no reports")?;
    let mut out = Outcome { ours_total: h.units + buys.iter().map(|b| b.count).sum::<i64>(), ..Default::default() };
    for i in 0..reports.list_len_or_zero()? {
        let Some(r) = get(&reports, i)? else { continue };
        let alive = int(&r, "_AliveMechCount_k__BackingField")?;
        let score = int(&r, "_Score_k__BackingField")?;
        if i == h.seat {
            (out.ours_alive, out.ours_score) = (alive, score);
        } else {
            (out.enemy_alive, out.enemy_score) = (alive, score);
        }
    }
    Ok(out)
}

/// One placement search with `buys` added: the start's and the best
/// outcome, and the first error a try gave.
struct Searched {
    found: modforge::placement::Found,
    start: Option<Outcome>,
    best: Outcome,
    error: Option<String>,
}

fn search(held: &Arc<Held>, start: Vec<Piece>, buys: &[Buy], budget: usize, steps: &[i32]) -> Searched {
    let mut error = None;
    let mut best = Outcome::default();
    let mut best_value = f64::NEG_INFINITY;
    let mut start_outcome = None;
    let found = improve(
        start,
        steps,
        budget,
        |i, p| {
            let (h, p) = (held.clone(), *p);
            MAIN_QUEUE.run_result("sim allowed", Duration::from_secs(5), move || allowed(&h, i, &p)).unwrap_or(false)
        },
        |ps| {
            let (h, ps, bs) = (held.clone(), ps.to_vec(), buys.to_vec());
            match MAIN_QUEUE.run_result("sim try", Duration::from_secs(60), move || simulate(&h, &ps, &bs)) {
                Ok(o) => {
                    start_outcome.get_or_insert(o);
                    if o.value() > best_value {
                        (best_value, best) = (o.value(), o);
                    }
                    o.value()
                }
                Err(e) => {
                    error.get_or_insert(e);
                    f64::NEG_INFINITY
                }
            }
        },
    );
    Searched { found, start: start_outcome, best, error }
}

fn take(held: Arc<Held>) {
    if let Ok(h) = Arc::try_unwrap(held) {
        release(h);
    }
}

fn units_json(ids: &[i64], ps: &[Piece]) -> Vec<Json> {
    ids.iter().zip(ps).map(|(id, p)| json!({"card": id, "x": p.x, "y": p.y, "w": p.w, "h": p.h})).collect()
}

/// The placement search on the field's units only. Nothing on the
/// field moves.
fn plan_placement(budget: usize, steps: Vec<i32>) -> Result<Json, String> {
    let t = Instant::now();
    let (held, start) = MAIN_QUEUE.run_result("sim hold", Duration::from_secs(10), hold)?;
    let held = Arc::new(held);
    let s = search(&held, start.clone(), &[], budget, &steps);
    let ids = held.card_ids.clone();
    take(held);
    if let (None, Some(e)) = (s.start, s.error.clone()) {
        return Err(e);
    }
    Ok(json!({
        "start": {"units": units_json(&ids, &start), "outcome": s.start.map(Outcome::to_json)},
        "best": {"units": units_json(&ids, &s.found.pieces), "outcome": s.best.to_json()},
        "tries": s.found.tries,
        "seconds": t.elapsed().as_secs_f64(),
        "first_error": s.error,
    }))
}

/// The deploy plan: every way to spend the supply in the shop
/// (modforge::buying, each shop slot once), each bought unit put at the
/// free spot nearest our units, then a placement search per choice.
/// Ranked best first. Nothing is bought and nothing on the field moves.
fn plan_deploy(budget_each: usize, steps: Vec<i32>, most_baskets: usize) -> Result<Json, String> {
    let t = Instant::now();
    let (held, start) = MAIN_QUEUE.run_result("sim hold", Duration::from_secs(10), hold)?;
    let (items, supply) = MAIN_QUEUE.run_result("sim shop", Duration::from_secs(10), shop)?;
    let sizes = {
        let ids: Vec<i64> = items.iter().map(|b| b.card).collect();
        MAIN_QUEUE.run_result("sim sizes", Duration::from_secs(30), move || {
            ids.iter().map(|&id| crate::units::card_size(id)).collect::<Result<Vec<_>, _>>()
        })?
    };
    let offers: Vec<Offer> = items.iter().map(|b| Offer { id: b.slot, cost: b.price, unlock: None, most: Some(1) }).collect();
    let all = baskets(&offers, supply, usize::MAX, 0);
    let held = Arc::new(held);
    let near = {
        let n = start.len().max(1) as i32;
        (start.iter().map(|p| p.x).sum::<i32>() / n, start.iter().map(|p| p.y).sum::<i32>() / n)
    };
    let mut plans = Vec::new();
    for basket in all.iter().take(most_baskets) {
        let buys: Vec<Buy> = basket.buys.iter().filter_map(|s| items.iter().find(|b| b.slot == *s).copied()).collect();
        let mut pieces = start.clone();
        let mut fits = true;
        for b in &buys {
            let i = items.iter().position(|x| x.slot == b.slot).unwrap_or(0);
            let (w, h) = sizes[i];
            match free_spot(&pieces, w, h, OUR_AREA, near, 10) {
                Some(p) => pieces.push(p),
                None => fits = false,
            }
        }
        if !fits {
            continue;
        }
        let s = search(&held, pieces, &buys, budget_each, &steps);
        let mut ids = held.card_ids.clone();
        ids.extend(buys.iter().map(|b| b.card));
        plans.push((s.best.value(), json!({
            "buy": buys.iter().map(|b| json!({"slot": b.slot, "card": b.card, "level": b.level, "price": b.price})).collect::<Vec<_>>(),
            "spent": basket.spent,
            "left": supply - basket.spent,
            "outcome": s.best.to_json(),
            "first_placement_outcome": s.start.map(Outcome::to_json),
            "units": units_json(&ids, &s.found.pieces),
            "tries": s.found.tries,
            "first_error": s.error,
        })));
    }
    take(held);
    plans.sort_by(|a, b| b.0.partial_cmp(&a.0).unwrap_or(std::cmp::Ordering::Equal));
    Ok(json!({
        "supply": supply,
        "shop": items.iter().map(|b| json!({"slot": b.slot, "card": b.card, "level": b.level, "price": b.price})).collect::<Vec<_>>(),
        "choices": all.len(),
        "plans": plans.into_iter().map(|(_, j)| j).collect::<Vec<_>>(),
        "seconds": t.elapsed().as_secs_f64(),
    }))
}

fn steps_arg(args: &Json) -> Vec<i32> {
    args.get("steps")
        .and_then(Json::as_array)
        .map(|a| a.iter().filter_map(Json::as_i64).map(|s| s as i32).collect())
        .unwrap_or_else(|| vec![100, 50, 20, 10])
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "plan_placement",
        "Search our unit placement with the game's own fight simulation (nothing on the field moves): {budget: tries, default 80; steps: [100, 50, 20, 10]}",
        "{budget?: u64, steps?: [i32]}",
        |args| plan_placement(args.get("budget").and_then(Json::as_u64).unwrap_or(80) as usize, steps_arg(args)),
    ));
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "plan_deploy",
        "Every way to spend the supply in the shop, each with a placement search on the game's own fight simulation, best first (nothing is bought or moved): {budget: tries per choice, default 30; baskets: most choices tried, default 12; steps}",
        "{budget?: u64, baskets?: u64, steps?: [i32]}",
        |args| {
            plan_deploy(
                args.get("budget").and_then(Json::as_u64).unwrap_or(30) as usize,
                steps_arg(args),
                args.get("baskets").and_then(Json::as_u64).unwrap_or(12) as usize,
            )
        },
    ));
}

#[cfg(test)]
mod tests {
    use super::Outcome;

    #[test]
    fn any_win_beats_any_loss_then_survivors_count() {
        let win = Outcome { ours_alive: 1, ours_total: 10, enemy_alive: 0, ..Default::default() };
        let big_loss = Outcome { ours_alive: 0, ours_total: 10, enemy_alive: 16, ..Default::default() };
        let close_loss = Outcome { ours_alive: 0, ours_total: 10, enemy_alive: 2, ..Default::default() };
        let better_win = Outcome { ours_alive: 9, ours_total: 10, enemy_alive: 0, ..Default::default() };
        assert!(win.value() > close_loss.value());
        assert!(close_loss.value() > big_loss.value());
        assert!(better_win.value() > win.value());
        // 40 of 48 left (83%) beats 42 of 60 left (70%).
        let few_lost = Outcome { ours_alive: 40, ours_total: 48, ..Default::default() };
        let many_alive = Outcome { ours_alive: 42, ours_total: 60, ..Default::default() };
        assert!(few_lost.value() > many_alive.value());
    }
}
