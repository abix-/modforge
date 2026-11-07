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

use std::time::{Duration, Instant};

use modforge::placement::{Piece, improve};
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
    seat: i64,
    round: i64,
}

/// One simulated fight, per side.
#[derive(Clone, Copy, Debug, Default)]
pub struct Outcome {
    pub ours_alive: i64,
    pub enemy_alive: i64,
    pub ours_score: i64,
    pub enemy_score: i64,
}

impl Outcome {
    fn to_json(self) -> Json {
        json!({
            "ours_alive": self.ours_alive, "enemy_alive": self.enemy_alive,
            "ours_score": self.ours_score, "enemy_score": self.enemy_score, "won": self.won(),
        })
    }

    pub fn won(&self) -> bool {
        self.enemy_alive == 0 && self.ours_alive > 0
    }

    /// Higher is better: any win above any loss, then our units alive,
    /// then fewer enemy units alive (so a closer loss still ranks).
    pub fn value(&self) -> f64 {
        (self.won() as i64 as f64) * 1e6 + self.ours_alive as f64 * 1e3 - self.enemy_alive as f64
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

/// Whether the game lets card `i` stand at the piece. Main thread only.
fn allowed(h: &Held, i: usize, p: &Piece) -> Result<bool, String> {
    with_object(h.territory, |tm| {
        let r = tm.invoke("CanMoveUnit", &json!([{"$handle": h.cards[i]}, {"x": p.x, "y": p.y}, false]))?;
        Ok(r.as_i64() == Some(0))
    })
}

/// One simulated fight with our units at `pieces`. Main thread only.
fn simulate(h: &Held, pieces: &[Piece]) -> Result<Outcome, String> {
    let rec = with_object(h.base, |b| b.invoke("GetDeepCopy", &json!([])))?;
    let rec = object(rec).ok_or("GetDeepCopy gave no record")?;
    for (u, p) in record_units(&rec, h.seat, h.round)?.iter().zip(pieces) {
        u.write_field("position", &json!({"x": p.x, "y": p.y}))?;
    }
    let ctor = json!([2, {"$handle": h.setting}, {"$handle": rec.handle().0}, false, h.seat, h.round, null]).to_string();
    let bs = object(invoke_static("Unityforge.Shim.Il2CppBridge", "NewObject", &json!(["Il2CppGameRiver.BattleSetting", ctor]))?)
        .ok_or("new BattleSetting gave nothing")?;
    let sim = object(invoke_static("Il2CppGameRiver.Client.MatchUtility", "StartFastBattleSimulation", &json!([{"$handle": bs.handle().0}]))?)
        .ok_or("StartFastBattleSimulation gave nothing")?;
    let fr = object(sim.invoke("GetFightResult", &json!([]))?).ok_or("no FightResult")?;
    let reports = field(&fr, "reports")?.ok_or("no reports")?;
    let mut out = Outcome::default();
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

/// The placement search: our units start where they stand; returns the
/// best placement found with its simulated outcome. Nothing on the
/// field moves.
fn plan_placement(budget: usize, steps: Vec<i32>) -> Result<Json, String> {
    let t = Instant::now();
    let (held, start) = MAIN_QUEUE.run_result("sim hold", Duration::from_secs(10), hold)?;
    let held = std::sync::Arc::new(held);
    let mut error = None;
    let mut best_outcome = Outcome::default();
    let mut best_value = f64::NEG_INFINITY;
    let mut start_outcome = None;
    let found = improve(
        start.clone(),
        &steps,
        budget,
        |i, p| {
            let (h, p) = (held.clone(), *p);
            MAIN_QUEUE.run_result("sim allowed", Duration::from_secs(5), move || allowed(&h, i, &p)).unwrap_or(false)
        },
        |ps| {
            let (h, ps) = (held.clone(), ps.to_vec());
            match MAIN_QUEUE.run_result("sim try", Duration::from_secs(60), move || simulate(&h, &ps)) {
                Ok(o) => {
                    start_outcome.get_or_insert(o);
                    if o.value() > best_value {
                        (best_value, best_outcome) = (o.value(), o);
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
    let ids = held.card_ids.clone();
    if let Ok(h) = std::sync::Arc::try_unwrap(held) {
        release(h);
    }
    if let (None, Some(e)) = (start_outcome, error.clone()) {
        return Err(e);
    }
    let units = |ps: &[Piece]| -> Vec<Json> {
        ids.iter().zip(ps).map(|(id, p)| json!({"card": id, "x": p.x, "y": p.y, "w": p.w, "h": p.h})).collect()
    };
    Ok(json!({
        "start": {"units": units(&start), "outcome": start_outcome.map(Outcome::to_json)},
        "best": {"units": units(&found.pieces), "outcome": best_outcome.to_json()},
        "tries": found.tries,
        "seconds": t.elapsed().as_secs_f64(),
        "first_error": error,
    }))
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "plan_placement",
        "Search our unit placement with the game's own fight simulation (nothing on the field moves): {budget: tries, default 80; steps: [100, 50, 20, 10]}",
        "{budget?: u64, steps?: [i32]}",
        |args| {
            let budget = args.get("budget").and_then(Json::as_u64).unwrap_or(80) as usize;
            let steps = args
                .get("steps")
                .and_then(Json::as_array)
                .map(|a| a.iter().filter_map(Json::as_i64).map(|s| s as i32).collect())
                .unwrap_or_else(|| vec![100, 50, 20, 10]);
            plan_placement(budget, steps)
        },
    ));
}

#[cfg(test)]
mod tests {
    use super::Outcome;

    #[test]
    fn any_win_beats_any_loss_then_survivors_count() {
        let win = Outcome { ours_alive: 1, enemy_alive: 0, ..Default::default() };
        let big_loss = Outcome { ours_alive: 0, enemy_alive: 16, ..Default::default() };
        let close_loss = Outcome { ours_alive: 0, enemy_alive: 2, ..Default::default() };
        let better_win = Outcome { ours_alive: 9, enemy_alive: 0, ..Default::default() };
        assert!(win.value() > close_loss.value());
        assert!(close_loss.value() > big_loss.value());
        assert!(better_win.value() > win.value());
    }
}
