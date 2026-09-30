//! Research: for each current mission of the player's councilors, the
//! success chance every other councilor would have had on the same
//! target (the game's own chance, no bonus spend), to see whether the
//! best councilor got each job.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_mission_fit -- --nocapture
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

fn try_call(api: &Api, h: i64, method: &str, args: Json) -> Option<Json> {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    r.ok.then_some(r.result)
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

fn hash(api: &Api, h: i64) -> i64 {
    call(api, h, "GetHashCode", json!([])).as_i64().unwrap()
}

#[test]
fn best_councilor_per_job() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result).unwrap(), "get_activePlayer", json!([]))).unwrap();
    let councilors = list(&api, handle(&member(&api, player, "councilors")).unwrap());
    for &c in &councilors {
        let Some(m) = handle(&member(&api, c, "activeMission")) else {
            println!("{}: no mission", name(&api, c));
            continue;
        };
        let template = handle(&call(&api, m, "get_missionTemplate", json!([]))).unwrap();
        let data_name = member(&api, template, "dataName");
        let target = handle(&member(&api, m, "target")).unwrap();
        let target_hash = hash(&api, target);
        let own = call(&api, m, "GetSuccessChance", json!([])).as_f64().unwrap_or(-1.0);
        println!(
            "{} on {} {} at {:.0}%",
            name(&api, c),
            member(&api, m, "displayName").as_str().unwrap_or("?"),
            name(&api, target),
            own * 100.0
        );
        let resolution = handle(&member(&api, template, "resolutionMethod")).unwrap();
        for &o in &councilors {
            if o == c {
                continue;
            }
            let possible = handle(&call(&api, o, "GetPossibleMissionList", json!([true, false, true, null, false]))).unwrap();
            let Some(their) = list(&api, possible)
                .into_iter()
                .find(|&t| member(&api, t, "dataName") == data_name)
            else {
                continue;
            };
            let targets = handle(&call(&api, their, "GetValidTargets", json!([{"$handle": o}]))).unwrap();
            if !list(&api, targets).into_iter().any(|t| hash(&api, t) == target_hash) {
                println!("    {}: target out of reach", name(&api, o));
                continue;
            }
            let theirs = try_call(
                &api,
                resolution,
                "GetSuccessChance",
                json!([{"$handle": their}, {"$handle": o}, {"$handle": target}, 0.0, false]),
            )
            .and_then(|v| v.as_f64())
            .unwrap_or(-1.0);
            let busy = handle(&member(&api, o, "activeMission")).map(|om| name(&api, om)).unwrap_or("idle".into());
            println!("    {}: {:.0}% (now on {busy})", name(&api, o), theirs * 100.0);
        }
    }
}
