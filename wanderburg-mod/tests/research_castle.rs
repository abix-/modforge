//! What the game manager, the player's castle and the castle's
//! modules hold.
//!
//! Read-only on purpose: walk_class, inspect_object, list_methods
//! and read_field only. No write_field, no invoke on game code,
//! no Harmony probe. Nothing here can change game state.
//!
//! Class names come from tests/research_types.rs (the survey of
//! Assembly-CSharp) and are given in full so the shim's exact
//! match hits and the short-name scan never runs.
//!
//! ```text
//! k3sc cargo-lock test -p wanderburg-mod --test research_castle -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running so
//! the workspace suite stays green. Instances of the castle and
//! its modules only exist inside a run; from the menu those tests
//! print zero and pass.

mod common;
use common::{api, find_instances, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// Walk a class, inspect up to `max` live instances, release the
/// handles, and print the declared methods once.
fn survey(api: &Api<Value>, class: &str, max: usize) {
    let list = match find_instances(api, class, true) {
        Ok(l) => l,
        Err(e) => {
            println!("{class}: walk_class failed: {e}");
            return;
        }
    };
    println!("\n== {class}: {} instance(s)", list.len());
    for v in list.iter().take(max) {
        let Some(h) = v.get("handle").and_then(Value::as_i64) else {
            println!("  {v}");
            continue;
        };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("?");
        let r = api.op("inspect_object", json!({"handle": h}));
        println!(
            "-- {name} (handle {h}):\n{}",
            serde_json::to_string_pretty(&r.result).unwrap_or_default()
        );
        api.op("release_handle", json!({"handle": h}));
    }
    for v in list.iter().skip(max) {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            api.op("release_handle", json!({"handle": h}));
        }
    }
    // The interop proxies live under an `Il2Cpp.` namespace, so
    // declared_on is "Il2Cpp.GM" for class "GM"; match on the
    // suffix rather than the bare name.
    let r = api.op("list_methods", json!({"class": class}));
    if !r.ok {
        println!("list_methods({class}) failed: {:?}", r.error);
        return;
    }
    let empty = vec![];
    let methods = r.result["methods"].as_array().unwrap_or(&empty);
    let mine: Vec<&Value> = methods
        .iter()
        .filter(|m| {
            m["declared_on"]
                .as_str()
                .is_some_and(|d| d == class || d.ends_with(&format!(".{class}")))
        })
        .collect();
    println!("{class} declares {} method(s):", mine.len());
    for m in mine {
        println!(
            "  {}({}) -> {}{}",
            m["name"].as_str().unwrap_or("?"),
            m["params"].as_i64().unwrap_or(0),
            m["return"].as_str().unwrap_or("?"),
            if m["static"].as_bool().unwrap_or(false) { " [static]" } else { "" }
        );
    }
}

#[test]
fn game_manager() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    survey(&api, "GM", 1);
    survey(&api, "MC", 1);
    survey(&api, "AM", 1);
}

#[test]
fn player_castle() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // GM.vm is the player-driven castle (VM carries the nested
    // InputType); VS and VP sit next to it. AgentVehicle
    // instances are the enemy castles, one shown for comparison.
    survey(&api, "VM", 1);
    survey(&api, "VS", 1);
    survey(&api, "VP", 1);
    survey(&api, "AgentVehicle", 1);
}

/// The player's castle as it is right now: core stats and every
/// mounted module with its name, levels, damage and cooldowns.
#[test]
fn loadout() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // Unity stops ticking while the game window is unfocused, and
    // the window is unfocused whenever the operator is typing in
    // the terminal that launches this test. Wait up to 60 s for
    // the main-thread queue to drain so they can click back in.
    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(60);
    let mut vm = None;
    while vm.is_none() && std::time::Instant::now() < deadline {
        let r = api.op("walk_class", json!({"class": "VM", "include_inactive": false}));
        if r.ok {
            vm = r
                .result
                .get("instances")
                .and_then(Value::as_array)
                .or_else(|| r.result.as_array())
                .and_then(|a| a.first())
                .and_then(|v| v.get("handle"))
                .and_then(Value::as_i64);
            if vm.is_none() {
                println!("no live VM (not in a run?)");
                return;
            }
        } else {
            println!("main thread not ticking yet ({:?}); click into the game window", r.error);
            std::thread::sleep(std::time::Duration::from_secs(3));
        }
    }
    let Some(vm) = vm else {
        println!("gave up after 60 s: the game never ticked. Focus the game window and rerun.");
        return;
    };
    let read = |h: i64, field: &str| -> Value {
        api.op("read_field", json!({"handle": h, "field": field})).result
    };
    println!("castle:");
    for f in [
        "currentHP", "maxHP", "currentArmor", "currentShield", "currentNitro", "maxNitro",
        "nitroRegenRate", "maxVelocity", "currentSpeed", "vehicleSizeRank",
        "canAbsorbVehiclesOfSizeRank", "currentVehicleBaseChosenIndex",
        "frontSlotsTaken", "backSlotsTaken", "topSlotsTaken", "sideSlotsTaken",
        "captainSlotsTaken", "crewSlotsTaken",
    ] {
        println!("  {f} = {}", read(vm, f));
    }
    for f in [
        "module1", "module2", "module3", "module4",
        "activeModule1", "activeModule2", "activeModule3", "activeModule4",
    ] {
        let v = read(vm, f);
        let Some(mh) = common::handle_of(&v) else {
            println!("{f}: {v}");
            continue;
        };
        println!("{f}: {}", v.get("str").and_then(Value::as_str).unwrap_or("?"));
        for mf in [
            "moduleName", "mountedSlotIndex", "rarity", "generalModuleLevel", "passiveLevel",
            "cooldownLevel", "ultLevel", "vehicleSizeLevel", "currentActiveBaseDamage",
            "currentPassiveBaseDamage", "flatDamageAdded", "currentActiveAbilityCooldown",
            "currentAutoAttackCooldown", "activeAbilityRange", "activeAbilityCurrentSize",
            "autoAttackCurrentSize",
        ] {
            println!("    {mf} = {}", read(mh, mf));
        }
        api.op("release_handle", json!({"handle": mh}));
    }
    api.op("release_handle", json!({"handle": vm}));
}

#[test]
fn modules() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    survey(&api, "ModuleSlot", 2);
    survey(&api, "Module2", 2);
}
