//! Research: control points per faction (and whether the game counts
//! it as alien-aligned, IsAlienProxy), and the size of the Alien
//! Administration nation.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_faction_control -- --nocapture
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

fn count(api: &Api, v: &Json) -> i64 {
    handle(v).map(|h| call(api, h, "get_Count", json!([])).as_i64().unwrap_or(-1)).unwrap_or(-1)
}

#[test]
fn faction_control_points() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op(
        "invoke_static",
        json!({"class": "PavonisInteractive.TerraInvicta.GameStateManager", "method": "AllFactions"}),
    );
    assert!(r.ok, "{:?}", r.error);
    let factions = handle(&r.result).unwrap();
    let n = call(&api, factions, "get_Length", json!([])).as_i64().unwrap();
    for i in 0..n {
        let f = handle(&call(&api, factions, "GetValue", json!([i]))).unwrap();
        println!(
            "{:<22} control points {:>3}  alien-aligned {}  proAlien {}  antiAlien {}",
            member(&api, f, "displayName").as_str().unwrap_or("?"),
            count(&api, &member(&api, f, "controlPoints")),
            member(&api, f, "IsAlienProxy"),
            member(&api, f, "proAlien"),
            member(&api, f, "antiAlien"),
        );
    }
    let r = api.op(
        "invoke_static",
        json!({"class": "PavonisInteractive.TerraInvicta.GameStateManager", "method": "AlienNation"}),
    );
    assert!(r.ok, "{:?}", r.error);
    match handle(&r.result) {
        Some(nation) => println!(
            "Alien Administration: extant {}  regions {}  control points {}",
            member(&api, nation, "extant"),
            count(&api, &member(&api, nation, "regions")),
            member(&api, nation, "numControlPoints"),
        ),
        None => println!("Alien Administration: does not exist"),
    }
}
