//! Raise a councilor's stat through one of its orgs.
//!
//! An org's councilor stat bonuses are its own fields (TIOrgState:
//! administration, command, persuasion, espionage, investigation,
//! science, security; read by GetStatBonus), counted for the councilor
//! while the org is active. The boost_org_stat op adds to one on the
//! councilor's first active org and clears the councilor's cached
//! stats (TICouncilorState.SetAttributesDirty) so it shows at once.

use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, json_handle, owned_object};

const STATS: [&str; 7] = [
    "Administration",
    "Command",
    "Persuasion",
    "Espionage",
    "Investigation",
    "Science",
    "Security",
];

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "boost_org_stat",
        "Add `amount` to `stat` on the named councilor's first active org; returns the councilor's stat before and after",
        "{councilor: str, stat: str, amount: int}",
        |args| {
            let councilor = args
                .get("councilor")
                .and_then(Json::as_str)
                .ok_or("missing councilor")?
                .to_string();
            let stat = args.get("stat").and_then(Json::as_str).ok_or("missing stat")?.to_string();
            let amount = args.get("amount").and_then(Json::as_i64).ok_or("missing amount")?;
            if !STATS.contains(&stat.as_str()) {
                return Err(format!("stat must be one of {STATS:?}"));
            }
            MAIN_QUEUE.run("boost_org_stat", Duration::from_secs(5), move || boost(&councilor, &stat, amount))?
        },
    ));
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn member_object(obj: &MonoObject, name: &str) -> Result<Option<MonoObject>, String> {
    Ok(json_handle(&member(obj, name)?).map(owned_object))
}

fn list(obj: &MonoObject) -> Result<Vec<MonoObject>, String> {
    let mut out = Vec::new();
    for i in 0..obj.list_len_or_zero()? {
        if let Some(item) = obj.list_handle(i)?.map(owned_object) {
            out.push(item);
        }
    }
    Ok(out)
}

fn name(obj: &MonoObject) -> String {
    member(obj, "displayName").ok().and_then(|v| v.as_str().map(str::to_string)).unwrap_or_default()
}

fn stat_of(councilor: &MonoObject, stat: &str) -> Result<i64, String> {
    councilor
        .invoke("GetAttribute", &json!([stat, true, true, true, false, false, false]))?
        .as_i64()
        .ok_or_else(|| "GetAttribute: not a number".to_string())
}

fn boost(who: &str, stat: &str, amount: i64) -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let faction = member_object(&control, "activePlayer")?.ok_or("no active player")?;
    let councilors = member_object(&faction, "councilors")?.ok_or("no councilors")?;
    let councilor = list(&councilors)?
        .into_iter()
        .find(|c| name(c) == who)
        .ok_or_else(|| format!("no councilor {who}"))?;
    let orgs = member_object(&councilor, "activeOrgs")?.ok_or("no active orgs")?;
    let org = list(&orgs)?.into_iter().next().ok_or_else(|| format!("{who} has no active org"))?;
    let field = stat.to_lowercase();
    let org_before = member(&org, &field)?.as_i64().ok_or("org stat: not a number")?;
    let before = stat_of(&councilor, stat)?;
    org.write_field(&field, &json!(org_before + amount))?;
    councilor.invoke("SetAttributesDirty", &json!([]))?;
    Ok(json!({
        "councilor": who,
        "org": name(&org),
        "stat": stat,
        "org_bonus_before": org_before,
        "org_bonus_after": member(&org, &field)?,
        "before": before,
        "after": stat_of(&councilor, stat)?,
    }))
}
