//! Control point loss log: one of the player's points goes to the
//! Servants with cause Event (not blocked), the mod must log it as
//! LOST with that cause, and the point is given straight back.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test point_loss_log -- --nocapture
//! ```

mod common;
use common::{Api, api_or_skip};
use serde_json::{Value as Json, json};

const LOG: &str = "C:/Games/Steam/steamapps/common/Terra Invicta/BepInEx/LogOutput.log";

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
fn a_lost_point_is_logged() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("invoke_static", json!({"class": "GameControl", "method": "get_control"}));
    assert!(r.ok, "{:?}", r.error);
    let player = handle(&call(&api, handle(&r.result), "get_activePlayer", json!([])));
    let points = handle(&member(&api, player, "controlPoints"));
    let point = handle(&call(&api, points, "get_Item", json!([0])));
    let nation = handle(&member(&api, point, "nation"));
    let index = member(&api, point, "positionInNation");
    let name = member(&api, point, "displayName").as_str().unwrap_or("?").to_string();
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
    let before = std::fs::read_to_string(LOG).unwrap_or_default().len();
    call(&api, nation, "ChangeControlPointOwner", json!([index, "Event", {"$handle": servants}]));
    call(&api, nation, "ChangeControlPointOwner", json!([index, "Event", {"$handle": player}]));
    std::thread::sleep(std::time::Duration::from_secs(2));
    let log = std::fs::read_to_string(LOG).unwrap_or_default();
    let new = &log[before.min(log.len())..];
    let line = new.lines().find(|l| l.contains("LOST") && l.contains(&name));
    println!("{}", line.unwrap_or("(no LOST line)"));
    assert!(line.is_some_and(|l| l.contains("cause Event")), "no LOST line with cause Event for {name}");
}
