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
