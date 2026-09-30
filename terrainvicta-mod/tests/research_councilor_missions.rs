//! Research: every mission each of the player's councilors can run
//! right now (TICouncilorState.GetPossibleMissionList, filtered for
//! the councilor's conditions, as the mission screen shows it), and
//! who can run TI_MISSION (default Propaganda, Public Campaign).
//!
//! ```text
//! TI_MISSION=Propaganda TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_councilor_missions -- --nocapture
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

#[test]
fn missions_per_councilor() {
    let Some(api) = api_or_skip() else { return };
    let wanted = std::env::var("TI_MISSION").unwrap_or_else(|_| "Propaganda".into());
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result).unwrap(), "get_activePlayer", json!([]))).unwrap();
    let mut can = Vec::new();
    for c in list(&api, handle(&member(&api, player, "councilors")).unwrap()) {
        let who = member(&api, c, "displayName").as_str().unwrap_or("?").to_string();
        let possible = handle(&call(&api, c, "GetPossibleMissionList", json!([true, false, true, null, false]))).unwrap();
        let names: Vec<String> = list(&api, possible)
            .into_iter()
            .map(|m| member(&api, m, "displayName").as_str().unwrap_or("?").to_string()
                + " (" + member(&api, m, "dataName").as_str().unwrap_or("?") + ")")
            .collect();
        if names.iter().any(|n| n.ends_with(&format!("({wanted})"))) {
            can.push(who.clone());
        }
        println!("{who}: {}", names.join(", "));
    }
    println!("\ncan run {wanted}: {} of them: {}", can.len(), can.join(", "));
}
