//! Base defense: an AI councilor's Crackdown and Coup against the
//! player, through the real modifiers on the Crackdown and Coup
//! mission templates (the calls the mission roll makes).
//!
//! - Crackdown's defended-asset bonus on an undefended control point
//!   of the player's is the full defended value (10).
//! - Coup's defended-point count on that point's nation is the
//!   defended points there plus 1 per undefended point of the
//!   player's there.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test base_defense -- --nocapture
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

/// A field, or failing that a property getter.
fn member(api: &Api, h: i64, name: &str) -> Json {
    let r = api.op("read_field", json!({"handle": h, "field": name}));
    if r.ok {
        return r.result;
    }
    call(api, h, &format!("get_{name}"), json!([]))
}

fn static_call(api: &Api, class: &str, method: &str) -> Json {
    let r = api.op("invoke_static", json!({"class": class, "method": method}));
    assert!(r.ok, "{class}.{method} failed: {:?}", r.error);
    r.result
}

fn list(api: &Api, h: i64) -> Vec<i64> {
    let n = call(api, h, "get_Count", json!([])).as_i64().expect("count");
    (0..n).map(|i| handle(&call(api, h, "get_Item", json!([i])))).collect()
}

/// The defending modifier of `class` on a mission template.
fn defending_modifier(api: &Api, mission_getter: &str, class: &str) -> i64 {
    let mission = handle(&static_call(api, "PavonisInteractive.TerraInvicta.TIFactionState", mission_getter));
    let resolution = handle(&member(api, mission, "resolutionMethod"));
    let modifiers = handle(&member(api, resolution, "defendingModifiers"));
    list(api, modifiers)
        .into_iter()
        .find(|&m| {
            let ty = handle(&call(api, m, "GetType", json!([])));
            call(api, ty, "get_Name", json!([])) == json!(class)
        })
        .unwrap_or_else(|| panic!("{class} not on {mission_getter}"))
}

fn is(api: &Api, h: i64, name: &str) -> bool {
    member(api, h, name) == json!(true)
}

fn players(api: &Api, cp: i64) -> bool {
    match member(api, cp, "faction")["handle"].as_i64() {
        Some(f) => is(api, f, "isActivePlayer"),
        None => false,
    }
}

#[test]
fn players_points_are_defended() {
    let Some(api) = api_or_skip() else { return };
    let control = handle(&static_call(&api, "GameControl", "get_control"));
    let player = handle(&call(&api, control, "get_activePlayer", json!([])));

    let cp = list(&api, handle(&member(&api, player, "controlPoints")))
        .into_iter()
        .find(|&cp| !is(&api, cp, "defended"))
        .expect("an undefended control point of the player's");

    let factions = handle(&static_call(&api, "PavonisInteractive.TerraInvicta.GameStateManager", "AllFactions"));
    let count = call(&api, factions, "get_Length", json!([])).as_i64().expect("length");
    let attacker = (0..count)
        .map(|i| handle(&call(&api, factions, "GetValue", json!([i]))))
        .filter(|&f| !is(&api, f, "isActivePlayer"))
        .find_map(|f| list(&api, handle(&member(&api, f, "councilors"))).first().copied())
        .expect("an AI councilor");

    let args = |target: i64| json!([{"$handle": attacker}, {"$handle": target}, 0.0, "None"]);

    let crackdown = defending_modifier(&api, "get_crackdownMission", "TIMissionModifier_DefendedAsset");
    let bonus = call(&api, crackdown, "GetModifier", args(cp)).as_f64().expect("bonus");
    println!("crackdown defended-asset bonus on an undefended point of ours: {bonus}");
    assert!((bonus - 10.0).abs() < 0.001, "expected 10, got {bonus}");

    let nation = handle(&member(&api, cp, "nation"));
    let points = list(&api, handle(&member(&api, nation, "controlPoints")));
    let defended = points.iter().filter(|&&p| is(&api, p, "defended")).count() as f64;
    let ours_open = points
        .iter()
        .filter(|&&p| !is(&api, p, "defended") && players(&api, p))
        .count() as f64;
    let coup = defending_modifier(&api, "get_coupMission", "TIMissionModifier_numDefendedControlPoints");
    let value = call(&api, coup, "GetModifier", args(nation)).as_f64().expect("coup");
    let expected = defended + ours_open;
    println!("coup defended-point count: {value} (defended {defended}, ours undefended {ours_open})");
    assert!((value - expected).abs() < 0.001, "expected {expected}, got {value}");
}
