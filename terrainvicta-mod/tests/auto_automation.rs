//! Automation back on: runs what every phase start does
//! (enable_automation) and checks every active councilor of the
//! player's then has automation on.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test auto_automation -- --nocapture
//! ```

mod common;
use common::{Api, api_or_skip};
use serde_json::{Value as Json, json};

fn handle(v: &Json) -> i64 {
    v["handle"].as_i64().unwrap_or_else(|| panic!("expected a handle, got {v}"))
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

#[test]
fn every_active_councilor_is_automated() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("enable_automation", json!({}));
    assert!(r.ok, "enable_automation failed: {:?}", r.error);
    println!("{}", r.result);
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result), "get_activePlayer", json!([])));
    let list = handle(&member(&api, player, "councilors"));
    let n = call(&api, list, "get_Count", json!([])).as_i64().unwrap();
    for i in 0..n {
        let c = handle(&call(&api, list, "get_Item", json!([i])));
        if member(&api, c, "active") != json!(true) {
            continue;
        }
        let who = member(&api, c, "displayName");
        println!("{who}: automation {}", member(&api, c, "permanentDefenseMode"));
        assert_eq!(member(&api, c, "permanentDefenseMode"), json!(true), "{who} not automated");
    }
}
