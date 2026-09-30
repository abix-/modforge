//! Free every detained councilor of the player's faction the way a
//! successful Extract Councilor mission does
//! (TIMissionEffect_ExtractCouncilor: ReleaseCouncilor(onTime: false)),
//! then check none are still detained.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test extract_councilors -- --nocapture
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

fn name(api: &Api, h: i64) -> Json {
    let r = api.op("read_field", json!({"handle": h, "field": "displayName"}));
    if r.ok {
        return r.result;
    }
    call(api, h, "get_displayName", json!([]))
}

/// The player's councilors as (handle, name, detained).
fn councilors(api: &Api) -> Vec<(i64, Json, bool)> {
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "GameControl.control failed: {:?}", r.error);
    let player = handle(&call(api, handle(&r.result), "get_activePlayer", json!([])));
    let r = api.op("read_field", json!({"handle": player, "field": "councilors"}));
    assert!(r.ok, "councilors failed: {:?}", r.error);
    let list = handle(&r.result);
    let count = call(api, list, "get_Count", json!([])).as_i64().expect("count");
    (0..count)
        .map(|i| {
            let c = handle(&call(api, list, "get_Item", json!([i])));
            let detained = call(api, c, "get_detained", json!([])).as_bool() == Some(true);
            (c, name(api, c), detained)
        })
        .collect()
}

#[test]
fn extract_detained_councilors() {
    let Some(api) = api_or_skip() else { return };
    for (h, name, detained) in councilors(&api) {
        println!("{name}: detained {detained}");
        if detained {
            call(&api, h, "ReleaseCouncilor", json!([false]));
            println!("  released {name}");
        }
    }
    let still: Vec<Json> = councilors(&api)
        .into_iter()
        .filter(|(_, _, d)| *d)
        .map(|(_, n, _)| n)
        .collect();
    assert!(still.is_empty(), "still detained: {still:?}");
}
