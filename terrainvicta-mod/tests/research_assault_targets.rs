//! Research: the Assault Alien Asset targets each of the player's
//! councilors can reach (object hash to tell same-named assets apart,
//! region, success chance), and the mission each councilor is on now.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_assault_targets -- --nocapture
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
fn assault_targets_per_councilor() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result).unwrap(), "get_activePlayer", json!([]))).unwrap();
    for c in list(&api, handle(&member(&api, player, "councilors")).unwrap()) {
        let current = match handle(&member(&api, c, "activeMission")) {
            Some(m) => match handle(&member(&api, m, "target")) {
                Some(t) => format!(
                    "{} on {} #{} in {}",
                    name(&api, m),
                    name(&api, t),
                    call(&api, t, "GetHashCode", json!([])),
                    handle(&member(&api, t, "ref_region")).map(|r| name(&api, r)).unwrap_or_default()
                ),
                None => format!("{} with no target", name(&api, m)),
            },
            None => "none".into(),
        };
        println!("{}: current mission {current}", name(&api, c));
        let possible = handle(&call(&api, c, "GetPossibleMissionList", json!([true, false, true, null, false]))).unwrap();
        let Some(assault) = list(&api, possible)
            .into_iter()
            .find(|&m| member(&api, m, "dataName") == json!("AssaultAlienAsset"))
        else {
            println!("  cannot run Assault Alien Asset");
            continue;
        };
        let resolution = handle(&member(&api, assault, "resolutionMethod")).unwrap();
        let targets = handle(&call(&api, assault, "GetValidTargets", json!([{"$handle": c}]))).unwrap();
        for t in list(&api, targets) {
            let hash = call(&api, t, "GetHashCode", json!([]));
            let region = handle(&member(&api, t, "ref_region")).map(|r| name(&api, r)).unwrap_or_default();
            let chance = call(
                &api,
                resolution,
                "GetSuccessChance",
                json!([{"$handle": assault}, {"$handle": c}, {"$handle": t}, 0.0, false]),
            );
            println!("  target {} #{hash} in {region}: chance {chance}", name(&api, t));
        }
    }
}
