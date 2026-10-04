//! The map (docs/map.md): for every area loaded, its own info_map (map
//! image, required task item); the live info_map.instance and its area;
//! MapController's current record (map id, landmarks); the panel's markers.
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_map -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{api, call, call_static, handle_of, instance_of, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

fn name_of(api: &Api<Value>, h: Option<i64>) -> String {
    h.map(|h| call(api, h, "get_name", json!([])).as_str().unwrap_or("?").to_string()).unwrap_or_else(|| "null".into())
}

fn area_of(api: &Api<Value>, h: i64) -> String {
    call_static(api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": h}])).as_str().unwrap_or("?").to_string()
}

fn count(api: &Api<Value>, list: Option<i64>) -> i64 {
    list.map(|l| call(api, l, "get_Count", json!([])).as_i64().unwrap_or(-1)).unwrap_or(-1)
}

#[test]
fn map() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let kept = op(&api, "load_alongside", json!({}));
    println!("current {}", kept["current"]);
    for (area, _) in kept["loaded"].as_object().into_iter().flatten() {
        match handle_of(&call_static(&api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["info_map", area]))) {
            Some(m) => println!(
                "{area}: info_map image={} task item={} radius={}",
                name_of(&api, handle_of(&read(&api, m, "mapImage"))),
                name_of(&api, handle_of(&read(&api, m, "requiredTaskItem"))),
                read(&api, m, "mapRadius")
            ),
            None => println!("{area}: no info_map"),
        }
    }
    match instance_of(&api, "info_map") {
        Ok(Some(m)) => println!("\ninfo_map.instance: {} in {}", name_of(&api, handle_of(&read(&api, m, "mapImage"))), area_of(&api, m)),
        other => println!("\ninfo_map.instance: {other:?}"),
    }
    let controller = instance_of(&api, "MapController").ok().flatten().expect("MapController.instance");
    let record = handle_of(&read(&api, controller, "currentSceneMapInfo"));
    println!(
        "MapController current record: id {} landmarks {}; records {}",
        record.map(|r| read(&api, r, "taskItemId")).unwrap_or(Value::Null),
        count(&api, record.and_then(|r| handle_of(&read(&api, r, "landmarkInfos")))),
        count(&api, handle_of(&read(&api, controller, "mapInfos")))
    );
    if let Some(panel) = handle_of(&read(&api, controller, "map")) {
        let image = handle_of(&read(&api, panel, "mapImage")).and_then(|i| handle_of(&call(&api, i, "get_sprite", json!([]))));
        println!("panel: image {} markers {}", name_of(&api, image), count(&api, handle_of(&read(&api, panel, "landmarks"))));
    }
}
