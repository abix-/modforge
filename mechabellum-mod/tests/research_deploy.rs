//! How deployment works: the deploy area, where units stand, and the
//! game's own placement steps. Run it with the deploy screen open.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p mechabellum-mod --test research_deploy -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::{Api, find_instances};

/// Words in a class name that point at deployment.
const WORDS: &[&str] = &["Deploy", "Formation", "Position", "BattleArea", "Placement", "Slot", "Grid", "Drag"];

/// Every type in GRClient and GRFight whose name holds one of WORDS.
/// GRClient's walk takes a few minutes.
#[test]
fn deploy_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for asm in ["GRFight", "GRCore", "GRClient"] {
        let names = unityforge::client::assembly_type_names(&api, asm).unwrap_or_default();
        let hits: Vec<&String> = names.iter().filter(|n| WORDS.iter().any(|w| n.contains(w))).collect();
        println!("{asm}: {} of {} types", hits.len(), names.len());
        for n in hits {
            println!("  {n}");
        }
    }
}

/// Fields of an object; nested objects shown by their text.
fn show(api: &Api<Value>, h: i64, indent: &str) {
    let map = api.op("inspect_object", json!({"handle": h})).result["fields"].as_object().cloned().unwrap_or_default();
    for (k, v) in &map {
        let shown = match v {
            Value::Object(o) => o.get("str").cloned().unwrap_or(v.clone()),
            _ => v.clone(),
        };
        if shown.as_str().is_some_and(|s| s.starts_with("<getter")) || k.starts_with("m_") {
            continue;
        }
        println!("{indent}{k} = {shown}");
    }
}

/// The live match, reached from the recommended formation panel
/// (its `match` field, a NormalMatch, 2026-11-07): its fields and
/// declared methods.
#[test]
fn live_match() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let panels = find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels
        .iter()
        .filter_map(handle_of)
        .find_map(|p| handle_of(&api.op("read_field", json!({"handle": p, "field": "match"})).result))
    else {
        println!("no panel holds a match; open the deploy screen");
        return;
    };
    let ty = api.op("inspect_object", json!({"handle": m})).result;
    println!("--- match ({}):", ty["il2cpp_type"]);
    show(&api, m, "  ");
    unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.Client.NormalMatch");
}

/// The match's player side: localPlayerController (PlayerController)
/// fields, and the map system the GridView holds (GridView.mapSystem).
/// MechPositionManager and the deploy state are plain classes, not
/// Unity objects, so the object search finds none (2026-11-07); they
/// should hang off one of these.
#[test]
fn player_side() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let panels = find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    if let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) {
        for f in ["localPlayerController", "playerManager", "battleInfo", "battleOpeningController"] {
            if let Some(h) = field(m, f) {
                println!("--- match.{f}:");
                show(&api, h, "  ");
            }
        }
    } else {
        println!("no panel holds a match");
    }
    let grids = find_instances(&api, "GameRiver.Client.GridView", false).unwrap_or_default();
    if let Some(ms) = grids.iter().filter_map(handle_of).find_map(|g| field(g, "mapSystem")) {
        println!("--- GridView.mapSystem:");
        show(&api, ms, "  ");
    }
}

/// Every player's units: match.playerManager.playerControllers, each
/// one's unitManager fields, and the fields of its first unit.
#[test]
fn units_on_field() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let item = |h: i64, i: i64| handle_of(&api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [i]})).result);
    unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.UnitManager");
    let panels = find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no panel holds a match");
        return;
    };
    let local = field(m, "localPlayerController");
    let pcs = field(m, "playerManager").and_then(|pm| field(pm, "playerControllers")).expect("playerControllers");
    for i in 0..common::count_of(&api, pcs).unwrap_or(0) {
        let Some(pc) = item(pcs, i) else { continue };
        let is_local = local.is_some_and(|l| {
            api.op("invoke_method", json!({"handle": pc, "method": "Equals", "args": [{"$handle": l}]})).result == json!(true)
        });
        println!("=== player {i} (local: {is_local})");
        if let Some(p) = field(pc, "player") {
            show(&api, p, "  player ");
        }
        let Some(um) = field(pc, "unitManager") else { continue };
        show(&api, um, "  unitManager ");
        // unitManager.units: CardElement, one per placed card.
        let Some(units) = field(um, "units") else { continue };
        for u in 0..common::count_of(&api, units).unwrap_or(0) {
            let Some(card) = item(units, u) else { continue };
            let data = field(card, "unitData");
            let read = |h: Option<i64>, f: &str| h.map(|h| api.op("read_field", json!({"handle": h, "field": f})).result);
            println!("  --- unit {u}: card {:?} {:?}", read(data, "id"), read(data, "name"));
            // Where it stands: the CardElement's mapElement, and (first
            // unit only, it is long) its mechPositionManager.
            if let Some(me) = field(card, "mapElement") {
                show(&api, me, "    mapElement ");
            }
            if u == 0
                && let Some(mpm) = field(card, "mechPositionManager")
            {
                show(&api, mpm, "    mechPositionManager ");
            }
        }
    }
}

/// The game's recommended formations: each RecommendFormItem's text
/// and the fields of each of its FormAreas.
#[test]
fn recommended_formations() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let items = find_instances(&api, "GameRiver.Client.RecommendFormItem", true).unwrap_or_default();
    for (i, item) in items.iter().filter_map(handle_of).enumerate() {
        let info = handle_of(&api.op("read_field", json!({"handle": item, "field": "infoText"})).result)
            .map(|t| api.op("invoke_method", json!({"handle": t, "method": "get_text", "args": []})).result)
            .unwrap_or(Value::Null);
        println!("=== form {i}: {info}");
        let Some(areas) = handle_of(&api.op("read_field", json!({"handle": item, "field": "areas"})).result) else {
            continue;
        };
        for a in 0..common::count_of(&api, areas).unwrap_or(0) {
            if let Some(area) = handle_of(&api.op("invoke_method", json!({"handle": areas, "method": "get_Item", "args": [a]})).result) {
                println!("  area {a}:");
                show(&api, area, "    ");
            }
        }
    }
}

/// Classes from deploy_types: which are live now, with the fields of
/// the first one. Pass more names in MECHABELLUM_DEPLOY_CLASSES
/// (comma separated, without the Il2Cpp prefix).
#[test]
fn live_deploy() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut classes: Vec<String> = [
        // Namespaces from deploy_types (2026-11-07).
        "GameRiver.Client.DeployStateController",
        "GameRiver.DeployStateController",
        "GameRiver.MechPositionManager",
        "GameRiver.Client.DeployJobModel",
        "GameRiver.Client.DragController",
        "GameRiver.Client.StartPositionView",
        "GameRiver.Client.MapRegionGridView",
        "GameRiver.Client.GridView",
        "GameRiver.Client.BattleArea",
    ]
    .iter()
    .map(|s| s.to_string())
    .collect();
    if let Ok(extra) = std::env::var("MECHABELLUM_DEPLOY_CLASSES") {
        classes.extend(extra.split(',').map(|s| s.trim().to_string()).filter(|s| !s.is_empty()));
    }
    for class in &classes {
        let Ok(instances) = find_instances(&api, class, true) else {
            continue;
        };
        let Some(h) = instances.first().and_then(handle_of) else {
            continue;
        };
        println!("--- {class} ({} live), first one:", instances.len());
        show(&api, h, "  ");
        for v in &instances {
            if let Some(h) = handle_of(v) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
}
