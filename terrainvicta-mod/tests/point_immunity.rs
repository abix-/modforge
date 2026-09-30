//! Control point immunity: the Servants take one of the player's
//! control points through TINationState.ChangeControlPointOwner with
//! cause Politics (what a Purge does), then Enthrall, then Terrorize,
//! and the player must still own it. If the block did not hold, the point is given back before the
//! assert so the test never costs the player a point.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test point_immunity -- --nocapture
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

fn owner_is_player(api: &Api, point: i64) -> bool {
    member(api, point, "faction")["handle"]
        .as_i64()
        .is_some_and(|f| member(api, f, "isActivePlayer") == json!(true))
}

#[test]
fn servants_cannot_purge_a_player_point() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result), "get_activePlayer", json!([])));
    let points = handle(&member(&api, player, "controlPoints"));
    let point = handle(&call(&api, points, "get_Item", json!([0])));
    let nation = handle(&member(&api, point, "nation"));
    let index = member(&api, point, "positionInNation");
    let r = api.op(
        "invoke_static",
        json!({"class": "PavonisInteractive.TerraInvicta.GameStateManager", "method": "AllFactions"}),
    );
    assert!(r.ok, "{:?}", r.error);
    let factions = handle(&r.result);
    let n = call(&api, factions, "get_Length", json!([])).as_i64().unwrap();
    let servants = (0..n)
        .map(|i| handle(&call(&api, factions, "GetValue", json!([i]))))
        .find(|&f| member(&api, f, "templateName") == json!("SubmitCouncil"))
        .expect("the Servants");
    for cause in ["Politics", "Enthrall", "Terrorize"] {
        println!(
            "trying: {cause} of {} in {} to the Servants",
            member(&api, point, "displayName"),
            member(&api, nation, "displayName")
        );
        call(&api, nation, "ChangeControlPointOwner", json!([index, cause, {"$handle": servants}]));
        let kept = owner_is_player(&api, point);
        if !kept {
            call(&api, nation, "ChangeControlPointOwner", json!([index, "Event", {"$handle": player}]));
        }
        assert!(kept, "{cause}: the Servants took the player's point");
    }
}
