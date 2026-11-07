//! Every unit's numbers, read in one place from the game's own config
//! (research_units, docs/research.md "Unit stats"). The lineup, the
//! matchups and deployment all take their units from here.
//!
//! A card is what the player buys (`mechCount` units per purchase); a
//! mech is the unit's body (`life`, `damage` per hit, `isFly`); its main
//! skill holds range, seconds between attacks, splash and targets.
//! Config tables do not change during a session, so each card is read
//! once and kept.

use std::collections::HashMap;

use modforge::duel::UnitStats;
use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use unityforge::mono::{MonoObject, MonoType, json_handle, owned_object};

static CACHE: Mutex<Option<HashMap<i64, UnitStats>>> = Mutex::new(None);
/// Each card's footprint on the deploy field, width and height
/// (CardData.cardBaseSize, "{40, 20}"; a placed Hound's bound is 40 by 20).
static SIZES: Mutex<Option<HashMap<i64, (i32, i32)>>> = Mutex::new(None);

/// "{40, 20}" -> (40, 20).
fn size(text: &str) -> Option<(i32, i32)> {
    let mut it = text.trim_matches(|c| c == '{' || c == '}').split(',').map(|s| s.trim().parse::<i32>().ok());
    Some((it.next()??, it.next()??))
}

fn object(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}

fn call(o: &MonoObject, method: &str) -> Result<Json, String> {
    o.invoke(method, &json!([]))
}

/// FPoint is fixed point: RawValue / 2^32.
fn fixed(v: &Json) -> f64 {
    v.get("RawValue").and_then(Json::as_i64).map(|r| r as f64 / 4_294_967_296.0).unwrap_or(0.0)
}

fn int(o: &MonoObject, field: &str) -> Result<i64, String> {
    o.read_field(field)?.as_i64().ok_or_else(|| format!("{field} is not a number"))
}

/// The live Config, a Unity object (GRSingletonMonoStatic<Config>).
pub(crate) fn config() -> Result<MonoObject, String> {
    let ty = MonoType::find("Il2CppGameRiver.Config").ok_or("type GameRiver.Config not found")?;
    let all = ty.walk(true)?;
    let list = all.get("instances").cloned().unwrap_or(all);
    let mut found = None;
    for v in list.as_array().into_iter().flatten() {
        if let Some(h) = json_handle(v) {
            let o = owned_object(h);
            if found.is_none() {
                found = Some(o);
            }
        }
    }
    found.ok_or_else(|| "no live GameRiver.Config".into())
}

/// Every card row, keyed by card id. Main thread only.
fn read_all() -> Result<HashMap<i64, UnitStats>, String> {
    let cfg = config()?;
    let container = object(call(&cfg, "get_dataContainer")?).ok_or("no dataContainer")?;
    let skills = object(call(&cfg, "get_mechSkillDatas")?).ok_or("no mechSkillDatas")?;
    let skill_dic = object(skills.read_field("dataDic")?).ok_or("no skill dataDic")?;

    let mech_list = object(call(&container, "get_mechDatas")?).ok_or("no mechDatas")?;
    let mut mechs = HashMap::new();
    for i in 0..mech_list.list_len_or_zero()? {
        if let Some(m) = object(mech_list.invoke("get_Item", &json!([i]))?) {
            mechs.insert(int(&m, "id")?, m);
        }
    }

    let card_list = object(call(&container, "get_cardDatas")?).ok_or("no cardDatas")?;
    let mut out = HashMap::new();
    for i in 0..card_list.list_len_or_zero()? {
        let Some(card) = object(card_list.invoke("get_Item", &json!([i]))?) else { continue };
        let Some(mech) = mechs.get(&int(&card, "mechID")?) else { continue };
        let id = int(&card, "id")?;
        if let Some(s) = card.read_field("cardBaseSize")?.as_str().and_then(size) {
            SIZES.lock().get_or_insert_with(HashMap::new).insert(id, s);
        }
        let mut u = UnitStats {
            id,
            name: card.read_field("name")?.as_str().unwrap_or("").to_string(),
            count: int(&card, "mechCount")?.max(0) as u32,
            life: mech.read_field("life")?.as_f64().unwrap_or(0.0),
            damage: mech.read_field("damage")?.as_f64().unwrap_or(0.0),
            flies: mech.read_field("isFly")?.as_bool().unwrap_or(false),
            speed: mech.read_field("moveSpeed")?.as_f64().unwrap_or(0.0),
            ..Default::default()
        };
        // Some mechs have no main skill (id 0, not in the table), and
        // get_Item on a missing key throws.
        let skill_id = int(mech, "mainSkillID")?;
        let has_skill = skill_dic.invoke("ContainsKey", &json!([skill_id]))?.as_bool() == Some(true);
        if has_skill && let Some(skill) = object(skill_dic.invoke("get_Item", &json!([skill_id]))?) {
            u.range = fixed(&call(&skill, "GetAttackRange")?);
            u.attack_interval = fixed(&call(&skill, "GetAttackInterval")?);
            u.splash = fixed(&call(&skill, "GetSplashRange")?);
            u.weapons = call(&skill, "GetWeaponCount")?.as_i64().unwrap_or(1).max(0) as u32;
            u.hits_air = call(&skill, "IsAirAttack")?.as_bool().unwrap_or(false);
            u.hits_ground = call(&skill, "IsGroundAttack")?.as_bool().unwrap_or(false);
        }
        out.insert(id, u);
    }
    Ok(out)
}

/// One card's unit, `count` being units per purchase. Main thread only.
pub fn unit(card_id: i64) -> Result<UnitStats, String> {
    let mut g = CACHE.lock();
    if g.is_none() {
        *g = Some(read_all()?);
    }
    g.as_ref().and_then(|m| m.get(&card_id).cloned()).ok_or_else(|| format!("no card {card_id}"))
}

/// A card's footprint on the deploy field. Main thread only.
pub fn card_size(card_id: i64) -> Result<(i32, i32), String> {
    unit(card_id)?;
    SIZES.lock().as_ref().and_then(|m| m.get(&card_id).copied()).ok_or_else(|| format!("no size for card {card_id}"))
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "units",
        "Unit numbers per card from the game config (count is units per purchase): {ids: [card id]}",
        "{ids: [i64]}",
        |args| {
            let ids: Vec<i64> = args
                .get("ids")
                .and_then(Json::as_array)
                .ok_or("ids: list of card ids")?
                .iter()
                .filter_map(Json::as_i64)
                .collect();
            unityforge::main_thread_queue::MAIN_QUEUE.run_result("units", std::time::Duration::from_secs(10), move || {
                ids.iter().map(|&id| unit(id).map(|u| serde_json::to_value(&u).unwrap_or(Json::Null))).collect::<Result<Vec<_>, _>>().map(Json::Array)
            })
        },
    ));
}

#[cfg(test)]
mod tests {
    #[test]
    fn size_reads_the_game_text() {
        assert_eq!(super::size("{40, 20}"), Some((40, 20)));
        assert_eq!(super::size("nonsense"), None);
    }
}
