//! Detention immunity: an AI faction detains one of the player's
//! councilors through TICouncilorState.DetainCouncilor (the path every
//! enemy mission takes), and the councilor must stay free. If the
//! patch did not hold, the councilor is released again before the
//! assert so the test never leaves anyone captured.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test detention_immunity -- --nocapture
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

fn static_call(api: &Api, class: &str, method: &str) -> Json {
    let r = api.op("invoke_static", json!({"class": class, "method": method}));
    assert!(r.ok, "{class}.{method} failed: {:?}", r.error);
    r.result
}

#[test]
fn players_councilor_cannot_be_detained() {
    let Some(api) = api_or_skip() else { return };
    let control = handle(&static_call(&api, "GameControl", "get_control"));
    let player = handle(&call(&api, control, "get_activePlayer", json!([])));

    let r = api.op("read_field", json!({"handle": player, "field": "councilors"}));
    assert!(r.ok, "councilors failed: {:?}", r.error);
    let councilor = handle(&call(&api, handle(&r.result), "get_Item", json!([0])));
    assert_eq!(call(&api, councilor, "get_detained", json!([])), json!(false), "councilor already detained");

    let factions = handle(&static_call(
        &api,
        "PavonisInteractive.TerraInvicta.GameStateManager",
        "AllFactions",
    ));
    let count = call(&api, factions, "get_Length", json!([])).as_i64().expect("length");
    let enemy = (0..count)
        .map(|i| handle(&call(&api, factions, "GetValue", json!([i]))))
        .find(|&f| call(&api, f, "get_isActivePlayer", json!([])) == json!(false))
        .expect("an AI faction");

    call(
        &api,
        councilor,
        "DetainCouncilor",
        json!([{"$handle": enemy}, 1.0, 1.0, false]),
    );
    let detained = call(&api, councilor, "get_detained", json!([])) == json!(true);
    if detained {
        call(&api, councilor, "ReleaseCouncilor", json!([false]));
    }
    assert!(!detained, "the player's councilor was detained");
}
