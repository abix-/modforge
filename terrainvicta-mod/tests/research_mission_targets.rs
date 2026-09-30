//! Research: every valid target one councilor has for one mission,
//! with the game's success chance at no bonus spend, best first, plus
//! the councilor's location and current mission.
//!
//! ```text
//! TI_COUNCILOR="Jose Maria Brito" TI_MISSION=GainInfluence TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_mission_targets -- --nocapture
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
    call(api, h, &format!("get_{name}"), json!([]))
}

fn list(api: &Api, h: i64) -> Vec<i64> {
    let n = call(api, h, "get_Count", json!([])).as_i64().unwrap_or(0);
    (0..n)
        .filter_map(|i| handle(&call(api, h, "get_Item", json!([i]))))
        .collect()
}

fn name(api: &Api, h: i64) -> String {
    member(api, h, "displayName").as_str().unwrap_or("?").to_string()
}

#[test]
fn mission_targets_for_one_councilor() {
    let Some(api) = api_or_skip() else { return };
    let who = std::env::var("TI_COUNCILOR").unwrap_or_else(|_| "Jose Maria Brito".into());
    let mission = std::env::var("TI_MISSION").unwrap_or_else(|_| "GainInfluence".into());
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result).unwrap(), "get_activePlayer", json!([]))).unwrap();
    let c = list(&api, handle(&member(&api, player, "councilors")).unwrap())
        .into_iter()
        .find(|&c| name(&api, c) == who)
        .unwrap_or_else(|| panic!("no councilor {who}"));
    let location = handle(&member(&api, c, "location")).map(|l| name(&api, l)).unwrap_or_default();
    let current = handle(&member(&api, c, "activeMission")).map(|m| name(&api, m)).unwrap_or("none".into());
    println!("{who}: location {location}, current mission {current}");
    let possible = handle(&call(&api, c, "GetPossibleMissionList", json!([true, false, true, null, false]))).unwrap();
    let Some(template) = list(&api, possible)
        .into_iter()
        .find(|&m| member(&api, m, "dataName") == json!(mission))
    else {
        println!("  cannot run {mission}");
        return;
    };
    let resolution = handle(&member(&api, template, "resolutionMethod")).unwrap();
    let targets = handle(&call(&api, template, "GetValidTargets", json!([{"$handle": c}]))).unwrap();
    let mut rows: Vec<(f64, String)> = list(&api, targets)
        .into_iter()
        .map(|t| {
            let chance = call(
                &api,
                resolution,
                "GetSuccessChance",
                json!([{"$handle": template}, {"$handle": c}, {"$handle": t}, 0.0, false]),
            )
            .as_f64()
            .unwrap_or(-1.0);
            (chance, name(&api, t))
        })
        .collect();
    rows.sort_by(|a, b| b.0.total_cmp(&a.0));
    println!("  {} valid {mission} targets:", rows.len());
    for (chance, t) in rows {
        println!("    {:5.1}%  {t}", chance * 100.0);
    }
}
