//! The starting lineup screen (`ChooseAdvanceTeamWindow`, research_lineup):
//! each choice's units with their totals, so "what lineup do I pick"
//! is answered the same way every game.
//!
//! A choice is two slots (`asyncUnitTop`, `asyncUnitBottom`), each a
//! card and a count shown as "x2". The count is read as purchases of
//! the card (`mechCount` units each); not yet proven
//! (onelog todo "x2 means two purchases or two units").

use modforge::duel::{UnitStats, totals};
use serde_json::{Value as Json, json};
use unityforge::mono::{MonoObject, MonoType, json_handle, owned_object};

use crate::units;

fn object(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}

/// Text on screen: TMP_Text and GRText both answer get_text.
fn text(o: &MonoObject, field: &str) -> String {
    o.read_field(field)
        .ok()
        .and_then(object)
        .and_then(|t| t.invoke("get_text", &json!([])).ok())
        .and_then(|v| v.as_str().map(str::to_string))
        .unwrap_or_default()
}

/// The open lineup window (isInit true). Main thread only.
fn window() -> Result<Option<MonoObject>, String> {
    let ty = MonoType::find("Il2CppGameRiver.Client.ChooseAdvanceTeamWindow")
        .ok_or("type ChooseAdvanceTeamWindow not found")?;
    let all = ty.walk(false)?;
    let list = all.get("instances").cloned().unwrap_or(all);
    for v in list.as_array().into_iter().flatten() {
        if let Some(w) = json_handle(v).map(owned_object)
            && w.read_field("isInit")?.as_bool() == Some(true)
        {
            return Ok(Some(w));
        }
    }
    Ok(None)
}

/// One slot as the units it gives.
fn slot(icon: &MonoObject, field: &str) -> Result<UnitStats, String> {
    let s = object(icon.read_field(field)?).ok_or_else(|| format!("no {field}"))?;
    let card = object(s.read_field("cardData")?).ok_or_else(|| format!("{field}: no cardData"))?;
    let id = card.read_field("id")?.as_i64().ok_or("card id")?;
    let purchases: u32 = text(&s, "countText").chars().filter(char::is_ascii_digit).collect::<String>().parse().unwrap_or(1);
    let mut u = units::unit(id)?;
    u.count *= purchases;
    let shown = text(&s, "nameText");
    if !shown.is_empty() {
        u.name = shown;
    }
    Ok(u)
}

/// Every choice on screen with its units and totals, most damage per
/// second first. Main thread only.
fn choices() -> Result<Json, String> {
    let Some(win) = window()? else {
        return Err("the lineup screen is not open".into());
    };
    let icons = object(win.read_field("advanceTeamIcons")?).ok_or("no advanceTeamIcons")?;
    let mut out = Vec::new();
    for i in 0..icons.list_len_or_zero()? {
        let Some(icon) = object(icons.invoke("get_Item", &json!([i]))?) else { continue };
        let group = vec![slot(&icon, "asyncUnitTop")?, slot(&icon, "asyncUnitBottom")?];
        let t = totals(&group);
        out.push(json!({
            "choice": i,
            "units": group.iter().map(|u| json!({
                "name": u.name, "card": u.id, "count": u.count, "life": u.life, "dps": u.dps(),
                "range": u.range, "splash": u.splash, "hits_air": u.hits_air,
            })).collect::<Vec<_>>(),
            "totals": t,
        }));
    }
    out.sort_by(|a, b| b["totals"]["dps"].as_f64().partial_cmp(&a["totals"]["dps"].as_f64()).unwrap_or(std::cmp::Ordering::Equal));
    Ok(Json::Array(out))
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "lineup",
        "The starting lineup choices on screen, each with its units and totals (life, damage per second, hits air), most damage first",
        "",
        |_| unityforge::main_thread_queue::MAIN_QUEUE.run_result("lineup", std::time::Duration::from_secs(10), choices),
    ));
}
