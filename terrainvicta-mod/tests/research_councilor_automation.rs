//! Research: the automation settings of each of the player's
//! councilors. The game only calls SelectPermanentDefenseModeMission
//! (offense mode) at a phase start for a councilor with
//! permanentDefenseMode on and repeatOrder off
//! (TIMissionPhaseState.StartofTurnBookkeeping).
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_councilor_automation -- --nocapture
//! ```

mod common;
use common::{Api, api_or_skip};
use serde_json::{Value as Json, json};

fn handle(v: &Json) -> Option<i64> {
    v["handle"].as_i64()
}

fn call(api: &Api, h: i64, method: &str, args: Json) -> Json {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    assert!(r.ok, "{method} failed: {:?}", r.error);
    r.result
}

fn member(api: &Api, h: i64, name: &str) -> Json {
    let r = api.op("read_field", json!({"handle": h, "field": name}));
    if r.ok {
        return r.result;
    }
    let r = api.op("invoke_method", json!({"handle": h, "method": format!("get_{name}"), "args": []}));
    if r.ok { r.result } else { json!(format!("unreadable: {:?}", r.error)) }
}

#[test]
fn councilor_automation_settings() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result).unwrap(), "get_activePlayer", json!([]))).unwrap();
    let list = handle(&member(&api, player, "councilors")).unwrap();
    let n = call(&api, list, "get_Count", json!([])).as_i64().unwrap();
    for i in 0..n {
        let c = handle(&call(&api, list, "get_Item", json!([i]))).unwrap();
        let location = handle(&member(&api, c, "location"))
            .map(|l| member(&api, l, "displayName"))
            .unwrap_or(Json::Null);
        let mission = match handle(&member(&api, c, "activeMission")) {
            Some(m) => {
                let target = handle(&member(&api, m, "target"));
                let owner = target
                    .and_then(|t| handle(&member(&api, t, "ref_faction")))
                    .map(|f| member(&api, f, "displayName"))
                    .unwrap_or(Json::Null);
                format!(
                    "{} on {} (owner {}) at {:.0}%",
                    member(&api, m, "displayName"),
                    target.map(|t| member(&api, t, "displayName")).unwrap_or(Json::Null),
                    owner,
                    call(&api, m, "GetSuccessChance", json!([])).as_f64().unwrap_or(-1.0) * 100.0
                )
            }
            None => "none".into(),
        };
        println!("{}: current mission {mission}", member(&api, c, "displayName"));
        println!(
            "{}: permanentDefenseMode {} repeatOrder {} permanentAssignment {} active {} detained {} status {} location {}",
            member(&api, c, "displayName"),
            member(&api, c, "permanentDefenseMode"),
            member(&api, c, "repeatOrder"),
            member(&api, c, "permanentAssignment"),
            member(&api, c, "active"),
            member(&api, c, "detained"),
            member(&api, c, "status"),
            location,
        );
    }
}
