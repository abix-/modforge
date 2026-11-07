//! Doing a deploy plan on the field the way the player does.
//!
//! The shop's buy button (ReinforcementShopPanelMediator
//! ViewComponentOnBuyAction) builds a PAD_SelectReinforcementShopItem
//! with the item's Index (ReinforcementShopManager.GetReinforceItemIndex)
//! and ID (IReinforceItem.GetID), asks PlayerController.CheckAction and
//! then calls TryPerformActionSync. Dropping a dragged unit
//! (MoveActorController OnClickGround and FinishMoving) builds a
//! PAD_MoveUnit, AddMoveData(controller, card, position, rotate), the
//! same check, the same call. The AI does both the same way (AIBrain
//! BuyUnit and MoveUnit).
//!
//! A CardElement carries no unit index (its unitData is the card's
//! config row), so a card is the object itself: handles are kept from
//! one main thread job to the next, and a bought card is one that
//! Equals none of the cards there before. Each action is its own main
//! thread job, so the game updates between them.

use std::time::Duration;

use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, owned_object, with_object};

use crate::deploy::{bound, current_match, field, object};

fn controller() -> Result<MonoObject, String> {
    field(&current_match()?, "localPlayerController")?.ok_or_else(|| "no localPlayerController".into())
}

fn int(o: &MonoObject, f: &str) -> Result<i64, String> {
    o.read_field(f)?.as_i64().ok_or_else(|| format!("{f} is not a number"))
}

/// Our cards on the field, in the field's order: (card id, card).
fn our_cards(pc: &MonoObject) -> Result<Vec<(i64, MonoObject)>, String> {
    let list = field(pc, "unitManager")?.and_then(|um| field(&um, "units").ok().flatten()).ok_or("no unitManager.units")?;
    let mut out = Vec::new();
    for i in 0..list.list_len_or_zero()? {
        let Some(card) = object(list.invoke("get_Item", &json!([i]))?) else { continue };
        let d = field(&card, "unitData")?.ok_or("card has no unitData")?;
        out.push((int(&d, "id")?, card));
    }
    Ok(out)
}

/// A handle kept past its job; given back by `release`.
fn keep(o: MonoObject) -> i32 {
    let h = o.handle().0;
    std::mem::forget(o);
    h
}

fn release(hs: Vec<i32>) {
    let _ = job("act release", move || {
        for h in hs {
            drop(owned_object(h));
        }
        Ok(())
    });
}

/// A new action object of the game's class.
fn action(class: &str) -> Result<MonoObject, String> {
    object(invoke_static("Unityforge.Shim.Il2CppBridge", "NewObject", &json!([class, "[]"]))?).ok_or_else(|| format!("new {class} gave nothing"))
}

/// The game's check, then the game's call, as its own buttons do.
fn perform(pc: &MonoObject, a: &MonoObject) -> Result<(), String> {
    let arg = json!([{"$handle": a.handle().0}]);
    if pc.invoke("CheckAction", &arg)?.as_bool() != Some(true) {
        return Err("the game's check refused it".into());
    }
    if pc.invoke("TryPerformActionSync", &arg)?.as_bool() != Some(true) {
        return Err("the game did not perform it".into());
    }
    Ok(())
}

/// Buy the shop item in `slot`. Main thread only.
fn buy(slot: i64) -> Result<(), String> {
    let pc = controller()?;
    let rs = field(&pc, "reinforcementShopManager")?.ok_or("no reinforcementShopManager")?;
    let items = field(&rs, "reinforceItems")?.ok_or("no reinforceItems")?;
    let item = object(items.invoke("get_Item", &json!([slot]))?).ok_or_else(|| format!("no shop item {slot}"))?;
    let index = rs.invoke("GetReinforceItemIndex", &json!([{"$handle": item.handle().0}]))?;
    let id = item.invoke("GetID", &json!([]))?;
    let a = action("Il2CppGameRiver.PAD_SelectReinforcementShopItem")?;
    a.invoke("set_Index", &json!([index]))?;
    a.invoke("set_ID", &json!([id]))?;
    perform(&pc, &a)
}

/// Move the card so its centre is at (x, y). Main thread only.
fn move_card(card: i32, x: i64, y: i64) -> Result<(), String> {
    let pc = controller()?;
    let a = action("Il2CppGameRiver.PAD_MoveUnit")?;
    a.invoke("AddMoveData", &json!([{"$handle": pc.handle().0}, {"$handle": card}, {"x": x, "y": y}, false]))?;
    perform(&pc, &a)
}

fn job<T: Send + 'static>(name: &'static str, f: impl FnOnce() -> Result<T, String> + Send + 'static) -> Result<T, String> {
    MAIN_QUEUE.run_result(name, Duration::from_secs(10), f)
}

/// (card id, kept handle) of our cards, in the field's order.
fn cards() -> Result<Vec<(i64, i32)>, String> {
    job("act cards", || Ok(our_cards(&controller()?)?.into_iter().map(|(id, c)| (id, keep(c))).collect()))
}

/// The cards in `after` that Equal none in `before`, in field order.
fn new_cards(before: &[(i64, i32)], after: &[(i64, i32)]) -> Result<Vec<(i64, i32)>, String> {
    let (before, after) = (before.to_vec(), after.to_vec());
    job("act new cards", move || {
        let mut out = Vec::new();
        for &(id, h) in &after {
            let mut seen = false;
            for &(_, b) in &before {
                if with_object(h, |o| o.invoke("Equals", &json!([{"$handle": b}])))?.as_bool() == Some(true) {
                    seen = true;
                    break;
                }
            }
            if !seen {
                out.push((id, h));
            }
        }
        Ok(out)
    })
}

/// Buy `slots`, then put every unit where `units` says: the field's
/// cards first in their order, then one per bought slot (the plan
/// from plan_deploy, its `buy` and `units`).
fn apply(slots: Vec<i64>, units: Vec<(i64, i64, i64)>) -> Result<Json, String> {
    let before = cards()?;
    let r = apply_with(&before, slots, units);
    release(before.iter().map(|c| c.1).collect());
    r
}

fn apply_with(before: &[(i64, i32)], slots: Vec<i64>, units: Vec<(i64, i64, i64)>) -> Result<Json, String> {
    if units.len() != before.len() + slots.len() {
        return Err(format!("{} units given for {} cards and {} buys", units.len(), before.len(), slots.len()));
    }
    for (n, ((id, _), (card, _, _))) in before.iter().zip(&units).enumerate() {
        if id != card {
            return Err(format!("unit {n}: field has card {id}, plan has {card}"));
        }
    }
    let mut steps = Vec::new();
    for &slot in &slots {
        let r = job("act buy", move || buy(slot));
        steps.push(json!({"buy": slot, "ok": r.is_ok(), "error": r.err()}));
    }
    let after = cards()?;
    let bought = new_cards(before, &after);
    // Handles in `after` that are not bought are let go now.
    let bought = match bought {
        Ok(b) => {
            release(after.iter().filter(|a| !b.iter().any(|x| x.1 == a.1)).map(|a| a.1).collect());
            b
        }
        Err(e) => {
            release(after.iter().map(|a| a.1).collect());
            return Err(e);
        }
    };
    let r = place(before, &bought, &units, steps, slots.len());
    release(bought.iter().map(|b| b.1).collect());
    r
}

fn place(before: &[(i64, i32)], bought: &[(i64, i32)], units: &[(i64, i64, i64)], mut steps: Vec<Json>, asked: usize) -> Result<Json, String> {
    let mut order: Vec<(i64, i32)> = before.to_vec();
    order.extend(bought.iter().copied());
    // A bought card goes to the plan's spot for a bought unit of the
    // same card, first unused first.
    let mut targets: Vec<Option<(i64, i64)>> = before.iter().zip(units).map(|(_, u)| Some((u.1, u.2))).collect();
    let mut free: Vec<(i64, i64, i64)> = units[before.len()..].to_vec();
    for (id, _) in bought {
        let at = free.iter().position(|u| u.0 == *id);
        targets.push(at.map(|k| {
            let u = free.remove(k);
            (u.1, u.2)
        }));
    }
    // A move can be refused while another unit still stands in the way;
    // try the refused ones again after the others moved.
    let mut todo: Vec<usize> = (0..order.len()).filter(|&k| targets[k].is_some()).collect();
    for _ in 0..3 {
        let mut left = Vec::new();
        for k in todo {
            let (handle, (x, y)) = (order[k].1, targets[k].unwrap_or_default());
            match job("act move", move || move_card(handle, x, y)) {
                Ok(()) => steps.push(json!({"move": k, "card": order[k].0, "x": x, "y": y, "ok": true})),
                Err(e) => {
                    steps.push(json!({"move": k, "card": order[k].0, "x": x, "y": y, "ok": false, "error": e}));
                    left.push(k);
                }
            }
        }
        todo = left;
        if todo.is_empty() {
            break;
        }
    }
    let now = job("act read", || {
        let pc = controller()?;
        let supply = field(&pc, "player")?.map(|p| int(&p, "supply")).transpose()?;
        let mut cards = Vec::new();
        for (id, card) in our_cards(&pc)? {
            let b = field(&card, "mapElement")?.and_then(|me| me.read_field("bound").ok()).and_then(|v| v.as_str().and_then(bound));
            cards.push(json!({"card": id, "bound": b}));
        }
        Ok(json!({"supply": supply, "cards": cards}))
    })?;
    Ok(json!({
        "bought": bought.len(),
        "asked_to_buy": asked,
        "not_moved": todo.iter().map(|&k| json!({"unit": k, "card": order[k].0})).collect::<Vec<_>>(),
        "steps": steps,
        "now": now,
    }))
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "apply_deploy",
        "Buy and place as a plan_deploy plan says, through the game's own buy and move actions: {buy: [{slot}], units: [{card, x, y}]} (the field's cards first, then the bought ones)",
        "{buy: [{slot: i64}], units: [{card: i64, x: i64, y: i64}]}",
        |args| {
            let slots: Vec<i64> = args
                .get("buy")
                .and_then(Json::as_array)
                .ok_or("buy: list of {slot}")?
                .iter()
                .filter_map(|b| b.get("slot").and_then(Json::as_i64).or_else(|| b.as_i64()))
                .collect();
            let units: Vec<(i64, i64, i64)> = args
                .get("units")
                .and_then(Json::as_array)
                .ok_or("units: list of {card, x, y}")?
                .iter()
                .map(|u| {
                    let n = |k: &str| u.get(k).and_then(Json::as_i64).ok_or_else(|| format!("unit {k} missing"));
                    Ok((n("card")?, n("x")?, n("y")?))
                })
                .collect::<Result<_, String>>()?;
            apply(slots, units)
        },
    ));
}
