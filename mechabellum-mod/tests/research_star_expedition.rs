//! Which classes run the Star Expedition mode?
//!
//! Read-only. No class is named Star Expedition; these are the
//! candidates from research_types (the async battle map with its
//! star view, the interstellar expedition classes, and the battle
//! flow controllers). Prints which have live Unity objects right
//! now and the fields of the first one. Run it with the mode open.
//!
//! ```text
//! k3sc cargo-lock test -p mechabellum-mod --test research_star_expedition -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::json;
use unityforge::client::find_instances;

const CANDIDATES: &[&str] = &[
    "GameRiver.Client.InterstellarExpeditionResourceController",
    "GameRiver.Client.InterstellarExpeditionShow",
    "GameRiver.Client.AsyncBattleWindow",
    "GameRiver.Client.AsyncBattleSoloWindow",
    "GameRiver.Client.AsyncBattleCoopWindow",
    "GameRiver.Client.AsyncBattleMapWindow",
    "GameRiver.Client.AsyncBattleMapStarView",
    "GameRiver.Client.AsyncBattlePluginsPanel",
    "GameRiver.Client.AsyncBattleResultPanel",
    "GameRiver.Client.SinglePlayerWindow",
    "GameRiver.Client.BattleScene",
    "GameRiver.Client.BattleView",
];

/// The windows above hold UI only. The game is PureMVC (GRUtility),
/// so the mode's state should sit in a Proxy, reached through the
/// Facade or Model, not as a Unity object. Their declared methods.
#[test]
fn proxy_methods() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Il2CppPureMVC.Patterns.Facade.Facade",
        "Il2CppPureMVC.Core.Model",
        "Il2CppGameRiver.Client.AsyncBattleProxy",
        "Il2CppGameRiver.Client.AsyncBattleUtility",
    ] {
        unityforge::client::print_declared_methods(&api, class);
    }
}

/// Every registered proxy's name (PureMVC Model.proxyMap keys), then
/// the live AsyncBattleProxy's fields and its SaveInfo's fields.
#[test]
fn live_proxy() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let call = |h: i64, method: &str| {
        api.op("invoke_method", json!({"handle": h, "method": method, "args": []}))
    };
    // Facade.instance comes back typed as the IFacade interface, and
    // get_model on it carried no handle (2026-11-07); Model has its
    // own static instance.
    let model = api.op(
        "invoke_static",
        json!({"class": "Il2CppPureMVC.Core.Model", "method": "get_instance", "args": []}),
    );
    let model_h = handle_of(&model.result)
        .unwrap_or_else(|| panic!("Model.instance carried no handle: {:?} {}", model.error, model.result));
    println!("Model.instance is {}", model.result["il2cpp_type"]);
    let map_h = handle_of(&call(model_h, "get_proxyMap").result).expect("Model.proxyMap");
    let keys = call(map_h, "get_Keys");
    let keys_h = handle_of(&keys.result).unwrap_or_else(|| panic!("proxyMap.Keys: {:?} {}", keys.error, keys.result));
    let n = common::count_of(&api, keys_h).unwrap_or(0);
    let mut names: Vec<String> = (0..n)
        .map(|i| {
            api.op("invoke_method", json!({"handle": keys_h, "method": "get_Item", "args": [i]}))
                .result
                .as_str()
                .unwrap_or("?")
                .to_string()
        })
        .collect();
    names.sort();
    println!("{n} proxies: {}", names.join(", "));

    let name = names.iter().find(|n| n.contains("AsyncBattle")).cloned().expect("an AsyncBattle proxy");
    let proxy = api.op("invoke_method", json!({"handle": model_h, "method": "RetrieveProxy", "args": [name]}));
    let proxy_h = handle_of(&proxy.result).unwrap_or_else(|| panic!("RetrieveProxy: {:?}", proxy.error));
    println!("--- {name}:");
    println!("{}", serde_json::to_string_pretty(&api.op("inspect_object", json!({"handle": proxy_h})).result["fields"]).unwrap_or_default());
    if let Some(save_h) = handle_of(&call(proxy_h, "GetSaveInfo").result) {
        println!("--- SaveInfo:");
        println!("{}", serde_json::to_string_pretty(&api.op("inspect_object", json!({"handle": save_h})).result["fields"]).unwrap_or_default());
        api.op("release_handle", json!({"handle": save_h}));
    } else {
        println!("GetSaveInfo carried no handle (no save?)");
    }
    for h in [proxy_h, keys_h, map_h, model_h] {
        api.op("release_handle", json!({"handle": h}));
    }
}

/// Every registered mediator's name (PureMVC View.mediatorMap keys):
/// the menus' and windows' button handlers live on them.
#[test]
fn live_mediators() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let view = api.op("invoke_static", json!({"class": "Il2CppPureMVC.Core.View", "method": "get_instance", "args": []}));
    let Some(view_h) = handle_of(&view.result) else {
        println!("View.instance carried no handle: {:?} {}", view.error, view.result);
        return;
    };
    let call = |h: i64, method: &str| api.op("invoke_method", json!({"handle": h, "method": method, "args": []}));
    let Some(map_h) = handle_of(&call(view_h, "get_mediatorMap").result) else {
        println!("no View.mediatorMap");
        return;
    };
    let Some(keys_h) = handle_of(&call(map_h, "get_Keys").result) else {
        println!("no mediatorMap.Keys");
        return;
    };
    let n = common::count_of(&api, keys_h).unwrap_or(0);
    let mut names: Vec<String> = (0..n)
        .map(|i| {
            let r = api.op("invoke_method", json!({"handle": keys_h, "method": "get_Item", "args": [i]}));
            r.result.as_str().map(str::to_string).unwrap_or_else(|| format!("{:?} {}", r.error, r.result))
        })
        .collect();
    names.sort();
    println!("{n} mediators: {}", names.join(", "));
    // KeyCollection has no get_Item; ask for names directly
    // (MECHABELLUM_MEDIATORS, comma separated, adds more).
    let mut try_names: Vec<String> = ["MainMenuBarMediator", "AsyncBattleWindowMediator", "AsyncBattleMapWindowMediator", "MainMenuMediator", "HomeWindowMediator"]
        .iter()
        .map(|s| s.to_string())
        .collect();
    if let Ok(extra) = std::env::var("MECHABELLUM_MEDIATORS") {
        try_names.extend(extra.split(',').map(|s| s.trim().to_string()));
    }
    for name in try_names {
        let has = api.op("invoke_method", json!({"handle": view_h, "method": "HasMediator", "args": [name]}));
        println!("HasMediator({name}) = {} {:?}", has.result, has.error);
    }
}

/// Press a window's button the way the game's pointer handler does
/// (InteractiveUIComponent.DispatchClickEvent). MECHABELLUM_PRESS is
/// "Window.getter" (default MainMenuBar.get_AsyncBattleButton); a
/// getter that gives a holder rather than the button is inspected and
/// its InteractiveUIComponent fields pressed if MECHABELLUM_PRESS_FIELD
/// names one. CHANGES WHAT THE GAME SHOWS, so it runs only with
/// MECHABELLUM_PRESS set.
#[test]
fn press_button() {
    let Ok(spec) = std::env::var("MECHABELLUM_PRESS") else {
        println!("SKIP: set MECHABELLUM_PRESS=Window.getter");
        return;
    };
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (window, getter) = spec.split_once('.').expect("Window.getter");
    let class = format!("GameRiver.Client.{window}");
    let Some(w) = shown(&api, &class).into_iter().next() else {
        println!("no {class} showing");
        return;
    };
    // "Window.?" lists the active window's button fields instead.
    if getter == "?" {
        let fields = api.op("inspect_object", json!({"handle": w})).result["fields"].as_object().cloned().unwrap_or_default();
        for (k, v) in fields {
            if v["il2cpp_type"].as_str().is_some_and(|t| t.contains("Interactive") || t.contains("Button")) {
                println!("  {k}: {}", v["il2cpp_type"]);
            }
        }
        return;
    }
    // "Window.field:name" presses a button held in a field.
    let b = match getter.strip_prefix("field:") {
        Some(f) => api.op("read_field", json!({"handle": w, "field": f})),
        None => api.op("invoke_method", json!({"handle": w, "method": getter, "args": []})),
    };
    let Some(mut bh) = handle_of(&b.result) else {
        println!("{getter}: {:?} {}", b.error, b.result);
        return;
    };
    println!("{getter} -> {}", b.result["il2cpp_type"]);
    if let Ok(f) = std::env::var("MECHABELLUM_PRESS_FIELD") {
        let r = api.op("read_field", json!({"handle": bh, "field": f}));
        bh = handle_of(&r.result).unwrap_or_else(|| panic!("{f}: {:?} {}", r.error, r.result));
        println!("{f} -> {}", r.result["il2cpp_type"]);
    }
    let c = api.op("invoke_method", json!({"handle": bh, "method": "DispatchClickEvent", "args": []}));
    println!("DispatchClickEvent ok {} {:?} {}", c.ok, c.error, c.result);
    if !c.ok {
        let fields = api.op("inspect_object", json!({"handle": bh})).result["fields"].clone();
        println!("{}", serde_json::to_string_pretty(&fields).unwrap_or_default());
    }
}

/// Start a Star Expedition run the way the start button does once its
/// checks pass (AsyncBattleWindowMediator StartGameButton_OnClicked,
/// its confirm action: AsyncBattleProxy.RequestEnterScene). CHANGES
/// THE GAME, so it runs only with MECHABELLUM_START=1.
#[test]
fn start_expedition() {
    if std::env::var("MECHABELLUM_START").ok().as_deref() != Some("1") {
        println!("SKIP: set MECHABELLUM_START=1 to start a Star Expedition run");
        return;
    }
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let model = api.op("invoke_static", json!({"class": "Il2CppPureMVC.Core.Model", "method": "get_instance", "args": []}));
    let model_h = handle_of(&model.result).expect("Model.instance");
    for name in ["AsyncBattleProxy", "GameRiver.Client.AsyncBattleProxy"] {
        let p = api.op("invoke_method", json!({"handle": model_h, "method": "RetrieveProxy", "args": [name]}));
        println!("RetrieveProxy({name}) -> {} {:?}", p.result["il2cpp_type"], p.error);
        if let Some(h) = handle_of(&p.result) {
            let r = api.op("invoke_method", json!({"handle": h, "method": "RequestEnterScene", "args": []}));
            println!("RequestEnterScene ok {} {:?} {}", r.ok, r.error, r.result);
            return;
        }
    }
}

/// Which windows are showing now: each instance's
/// gameObject.activeInHierarchy (windows stay loaded when hidden).
#[test]
fn showing() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for w in [
        "MainMenuBar",
        "AsyncBattleWindow",
        "AsyncBattleSoloWindow",
        "AsyncBattleMapWindow",
        "ChooseAdvanceTeamWindow",
        "ChooseRecommendFormPanel",
        "ReinforcementShopPanel",
        "AsyncBattleResultPanel",
    ] {
        let class = format!("GameRiver.Client.{w}");
        let all = find_instances(&api, &class, true).unwrap_or_default().len();
        println!("{w}: {} of {all} showing", shown(&api, &class).len());
    }
}

/// The question a popup asks: every text field of each PopupWindow
/// on screen (the game's yes/no box, Cpp2IL dump GRClient PopupWindow:
/// SetMessage, SetCallback, OnClickConfirm, OnClickDiscard). Read-only.
#[test]
fn popup() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for w in shown(&api, "GameRiver.Client.PopupWindow") {
        println!("--- PopupWindow {w}");
        let fields = api.op("inspect_object", json!({"handle": w})).result["fields"].as_object().cloned().unwrap_or_default();
        for (k, v) in fields {
            let t = v["il2cpp_type"].as_str().unwrap_or("");
            if !t.contains("Text") {
                continue;
            }
            let Some(h) = handle_of(&v) else { continue };
            let text = api.op("invoke_method", json!({"handle": h, "method": "get_text", "args": []})).result;
            println!("  {k}: {text}");
        }
    }
}

/// The instances of `class` whose gameObject is active in the
/// hierarchy (on screen).
fn shown(api: &unityforge::client::Api<serde_json::Value>, class: &str) -> Vec<i64> {
    let mut out = Vec::new();
    for v in find_instances(api, class, true).unwrap_or_default() {
        let Some(h) = handle_of(&v) else { continue };
        let go = api.op("invoke_method", json!({"handle": h, "method": "get_gameObject", "args": []}));
        if let Some(g) = handle_of(&go.result)
            && api.op("invoke_method", json!({"handle": g, "method": "get_activeInHierarchy", "args": []})).result == json!(true)
        {
            out.push(h);
        }
    }
    out
}

#[test]
fn live_candidates() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in CANDIDATES {
        let instances = match find_instances(&api, class, true) {
            Ok(v) => v,
            Err(e) => {
                println!("{class}: {e}");
                continue;
            }
        };
        let Some(h) = instances.first().and_then(handle_of) else {
            continue;
        };
        let fields = api.op("inspect_object", json!({"handle": h})).result;
        println!("--- {class} ({} live), first one's fields:", instances.len());
        println!("{}", serde_json::to_string_pretty(&fields["fields"]).unwrap_or_default());
        for v in &instances {
            if let Some(h) = handle_of(v) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
}
