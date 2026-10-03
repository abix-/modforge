//! Each area's own settings (docs/kept-areas.md, rule 1, which copy:
//! info_game_logic): for every area loaded, its info_game_logic's fields,
//! so a check can use areas whose settings differ. And the live set's
//! values they are pushed into (RadiationController, the sky). Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_area_settings -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{api, call, call_static, handle_of, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const FIELDS: &[&str] = &[
    "overrideSky",
    "disableOverrideSkyOnPlay",
    "_3dSkybox",
    "hideMainMap",
    "prisonLevelName",
    "prisonEntrypoint",
    "baseSafetyFactor",
    "itemExpirationTimeMinutes",
    "backgroundRadiation",
    "backgroundRadiationWasteland",
];

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

fn instance(api: &Api<Value>, class: &str) -> Option<i64> {
    let t = handle_of(&call_static(api, "System.Type", "GetType", json!([format!("{class}, Assembly-CSharp")])))?;
    let f = handle_of(&call(api, t, "GetField", json!(["instance"])))?;
    handle_of(&call(api, f, "GetValue", json!([null])))
}

#[test]
fn area_settings() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let kept = op(&api, "load_alongside", json!({}));
    println!("current {}", kept["current"]);
    for (area, _) in kept["loaded"].as_object().into_iter().flatten() {
        let Some(own) = handle_of(&call_static(&api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["info_game_logic", area]))) else {
            println!("{area}: no info_game_logic");
            continue;
        };
        let profile = handle_of(&read(&api, own, "overrideProfile")).map(|p| call(&api, p, "get_name", json!([]))).unwrap_or(Value::Null);
        let values: Vec<String> = FIELDS.iter().map(|f| format!("{f}={}", read(&api, own, f))).collect();
        println!("{area}: overrideProfile={profile} {}", values.join(" "));
    }
    if let Some(r) = instance(&api, "RadiationController") {
        println!("\nlive RadiationController: backgroundRadiation={} backgroundRadiationWasteland={}", read(&api, r, "backgroundRadiation"), read(&api, r, "backgroundRadiationWasteland"));
    }
    if let Some(g) = instance(&api, "info_game_logic") {
        println!("live info_game_logic: in {}", call_static(&api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": g}])));
    }
}
