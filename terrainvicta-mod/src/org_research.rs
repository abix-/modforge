//! Test: ten times the research points per month of one org.
//!
//! An org's research income is its own field, incomeResearch_month,
//! rolled once from its template as incomeResearch plus 0 to
//! randIncomeResearch (TIOrgState.cs:439). The boost_org_research op
//! multiplies it on the `count` orgs of the player's with the most
//! research that are not boosted yet. An org above the most its
//! template can roll counts as boosted, so nothing stacks.

use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, json_handle, owned_object};

const MULTIPLIER: f64 = 10.0;

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "boost_org_research",
        "10x research points per month on the player's `count` (default 1) orgs with the most research not boosted yet",
        "{count?: int}",
        |args| {
            let count = args.get("count").and_then(Json::as_u64).unwrap_or(1) as usize;
            MAIN_QUEUE.run("boost_org_research", Duration::from_secs(5), move || boost(count))?
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

fn number(obj: &MonoObject, name: &str) -> Result<f64, String> {
    member(obj, name)?
        .as_f64()
        .ok_or_else(|| format!("{name}: not a number"))
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

fn boost(count: usize) -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let faction = member_object(&control, "activePlayer")?.ok_or("no active player")?;
    let councilors = member_object(&faction, "councilors")?.ok_or("no councilors")?;
    // Orgs with research not boosted yet: (org, research, holder).
    let mut candidates = Vec::new();
    for c in list(&councilors)? {
        let Some(orgs) = member_object(&c, "orgs")? else {
            continue;
        };
        let holder = member(&c, "displayName")?.as_str().unwrap_or("?").to_string();
        for org in list(&orgs)? {
            let research = number(&org, "incomeResearch_month")?;
            let template = member_object(&org, "template")?.ok_or("org has no template")?;
            let natural_max =
                number(&template, "incomeResearch")? + number(&template, "randIncomeResearch")?;
            if research > 0.0 && research <= natural_max {
                candidates.push((org, research, holder.clone()));
            }
        }
    }
    candidates.sort_by(|a, b| b.1.total_cmp(&a.1));
    let mut boosted = Vec::new();
    for (org, before, holder) in candidates.into_iter().take(count) {
        org.write_field("incomeResearch_month", &json!(before * MULTIPLIER))?;
        boosted.push(json!({
            "org": member(&org, "displayName")?,
            "holder": holder,
            "before": before,
            "after": number(&org, "incomeResearch_month")?,
            "adjusted_after": number(&org, "adjustedIncomeResearch_month")?,
        }));
    }
    if !boosted.is_empty() {
        faction.invoke("SetResourceIncomeDataDirty", &json!([]))?;
    }
    Ok(json!({"asked": count, "boosted": boosted}))
}
