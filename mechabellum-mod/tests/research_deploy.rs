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
            // The first unit's card data and card fields: what names a
            // card for the game's buy and move actions.
            if u == 0 {
                if let Some(d) = data {
                    show(&api, d, "    unitData ");
                }
                show(&api, card, "    card ");
            }
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

/// Where the game lets our first unit go: TerritoryManager.CanMoveUnit
/// (unit, position, isForce false), the game's own check (Cpp2IL dump,
/// GRCore TerritoryManager), asked over a grid of positions. Prints the
/// answer at the unit's own place first, then the grid as a map
/// (`#` allowed, `.` refused).
#[test]
fn can_move_unit() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let panels = find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no panel holds a match");
        return;
    };
    let Some(pc) = field(m, "localPlayerController") else { return };
    let pcf = api.op("inspect_object", json!({"handle": pc})).result["fields"].as_object().cloned().unwrap_or_default();
    for (k, v) in &pcf {
        if k.to_lowercase().contains("territor") {
            println!("localPlayerController.{k} = {}", v.get("str").cloned().unwrap_or(v.clone()));
        }
    }
    let tm = ["territoryManager", "TerritoryManager", "territory"].iter().find_map(|f| field(pc, f));
    let Some(tm) = tm else {
        println!("no territory manager on the local player controller");
        return;
    };
    let Some(unit) = field(pc, "unitManager")
        .and_then(|um| field(um, "units"))
        .and_then(|l| handle_of(&api.op("invoke_method", json!({"handle": l, "method": "get_Item", "args": [0]})).result))
    else {
        println!("no unit 0");
        return;
    };
    let bound = field(unit, "mapElement").map(|me| api.op("read_field", json!({"handle": me, "field": "bound"})).result);
    println!("unit 0 bound {bound:?}");
    let ask = |x: i64, y: i64| api.op("invoke_method", json!({"handle": tm, "method": "CanMoveUnit", "args": [{"$handle": unit}, {"x": x, "y": y}, false]}));
    for (x, y) in [(-20, -170), (5, -160), (0, 0), (0, 100)] {
        let r = ask(x, y);
        println!("CanMoveUnit({x}, {y}) -> {} {:?}", r.result, r.error);
    }
    let first = ask(5, -160).result;
    println!("grid: x -300..300 step 25, y 300..-300 step 20; '#' answers like the unit's own place");
    for y in (-15..=15).rev().map(|i| i * 20) {
        let row: String = (-12..=12).map(|i| if ask(i * 25, y).result == first { '#' } else { '.' }).collect();
        println!("  y {y:>4} {row}");
    }
}

/// What can be bought now: the local player's ShopManager (Cpp2IL dump,
/// GRCore ShopManager): buy count and its cap, unlock count and its
/// cap, and each unlocked shop card with its cost, units per purchase
/// and CanBuyUnit answer (0 is allowed). Also the player's supply.
#[test]
fn shop() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let call = |h: i64, m: &str, args: Value| api.op("invoke_method", json!({"handle": h, "method": m, "args": args}));
    let panels = find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no panel holds a match");
        return;
    };
    let Some(pc) = field(m, "localPlayerController") else { return };
    let pcf = api.op("inspect_object", json!({"handle": pc})).result["fields"].as_object().cloned().unwrap_or_default();
    for (k, v) in &pcf {
        let l = k.to_lowercase();
        if l.contains("shop") || l.contains("supply") {
            println!("localPlayerController.{k} = {}", v.get("str").cloned().unwrap_or(v.clone()));
        }
    }
    if let Some(p) = field(pc, "player") {
        show(&api, p, "  player ");
    }
    let Some(sm) = ["shopManager", "ShopManager"].iter().find_map(|f| field(pc, f)) else {
        println!("no shopManager on the local player controller");
        return;
    };
    for g in ["GetBuyCount", "GetMaxBuyCount", "GetUnlockCount", "GetMaxUnlockCount", "IsBuyCountPerUnitLimit", "CanUnlockUnit"] {
        println!("ShopManager.{g} = {}", call(sm, g, json!([])).result);
    }
    show(&api, sm, "  shopManager ");
    if let Some(shop) = handle_of(&call(sm, "GetShop", json!([])).result) {
        show(&api, shop, "  shop ");
    }
    if let Some(ss) = field(pc, "shopSystem") {
        show(&api, ss, "  shopSystem ");
    }
    // GetUnlockedUnits hands back an IReadOnlyList the count helper
    // cannot read; Shop.unlockedUnits and lockedUnits are plain Lists.
    let Some(shop) = field(sm, "shop") else {
        println!("no shopManager.shop");
        return;
    };
    for which in ["unlockedUnits", "lockedUnits"] {
        let Some(list) = field(shop, which) else {
            println!("no shop.{which}");
            continue;
        };
        println!("shop.{which}: {}", common::count_of(&api, list).unwrap_or(0));
        for i in 0..common::count_of(&api, list).unwrap_or(0) {
            let Some(card) = handle_of(&call(list, "get_Item", json!([i])).result) else { continue };
            let data = field(card, "unitData");
            let read = |f: &str| data.map(|d| api.op("read_field", json!({"handle": d, "field": f})).result).unwrap_or_default();
            let id = read("id");
            println!(
                "  {which} {i}: card {id} {} cost {} x{} unlock price {} can buy {}",
                read("name"), read("baseMoney"), read("mechCount"), read("unlockPrice"), call(sm, "CanBuyUnit", json!([id])).result
            );
        }
    }
}

/// Star Expedition's shop, the one on screen (5 items, refresh, buy
/// population): the local player's ReinforcementShopManager (Cpp2IL
/// dump, GRCore). Its counters and costs, then every field, and the
/// items of each list field.
#[test]
fn reinforcement_shop() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let call = |h: i64, m: &str, args: Value| api.op("invoke_method", json!({"handle": h, "method": m, "args": args}));
    let panels = find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no panel holds a match");
        return;
    };
    let Some(rs) = field(m, "localPlayerController").and_then(|pc| field(pc, "reinforcementShopManager")) else {
        println!("no reinforcementShopManager");
        return;
    };
    for g in [
        "get_supply", "get_maxUnitCount", "IsMechFull", "GetAddUnitCount", "GetAddUnitCountCost", "get_canBuyMaxMechCount",
        "get_extraBuyPopulationCost", "get_extraBuyPuplationCount", "get_extraRefreshCost", "get_freeRefreshCount",
        "get_maxFreeRefreshCount", "get_maxManualRefreshCount", "get_canManualRefresh", "get_maxBuyItemCount",
        "get_currentBuyItemCount", "get_discountItemCount",
    ] {
        let r = call(rs, g, json!([]));
        println!("{g} = {} {}", r.result, r.error.unwrap_or_default());
    }
    let fields = api.op("inspect_object", json!({"handle": rs})).result["fields"].as_object().cloned().unwrap_or_default();
    for (k, v) in &fields {
        let s = v.get("str").cloned().unwrap_or(v.clone());
        if s.as_str().is_some_and(|t| t.starts_with("<getter")) {
            continue;
        }
        println!("  {k} = {s}");
        if s.as_str().is_some_and(|t| t.contains("List`1"))
            && let Some(list) = handle_of(v)
        {
            for i in 0..common::count_of(&api, list).unwrap_or(0).min(12) {
                let Some(it) = handle_of(&call(list, "get_Item", json!([i])).result) else { continue };
                println!("    [{i}] {}", api.op("inspect_object", json!({"handle": it})).result["il2cpp_type"]);
                show(&api, it, "      ");
                if let Some(cfg) = field(it, "_config_k__BackingField") {
                    show(&api, cfg, "      config ");
                }
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
