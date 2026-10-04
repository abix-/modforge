//! The automatic check for areas kept loaded (docs/kept-areas.md, proof,
//! and history, "The lifecycle rules kept areas break"): the game is played through the
//! kept-area paths without the player, and must end with every one-copy
//! field live and the player's identity intact. Every game error logged
//! along the way is listed, to gate on once the game's own errors are
//! known.
//!
//! 1. reload the save (a normal load), wait for areas kept loaded
//! 2. use a door of the home area into a kept area (the game's own
//!    Interact, as the use key calls it), then a door back
//! 3. save into the slot "ModTest" (not one of the player's), load it
//! 4. load the player's own save again (the save name is theirs again)
//!
//! Changes the game: loads, moves the player, writes Saves/<character>/ModTest.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_kept_scenario -- --nocapture
//! OBENSEUER_KEPT_OFF=1 k3sc cargo-lock test ...   (same run, kept areas off)
//! ```
//!
//! Kept areas off is saved in the settings; the run switches them back on
//! at its end, but not when it fails before that.
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{WATCHED, api, call, call_static, handle_of, instance_now, instance_of, op, ping_or_skip, wait_for_normal_load};
use serde_json::{Value, json};
use unityforge::client::Api;

fn wait_for(what: &str, secs: u64, mut done: impl FnMut() -> bool) {
    let start = Instant::now();
    while !done() {
        assert!(start.elapsed() < Duration::from_secs(secs), "{what}: not within {secs}s");
        std::thread::sleep(Duration::from_millis(200));
    }
    println!("{what} ({:.1}s)", start.elapsed().as_secs_f64());
}

fn kept(api: &Api<Value>) -> Value {
    op(api, "load_alongside", json!({}))
}

/// An active door (switched-on Changelevel) leading to `to`.
fn door_to(api: &Api<Value>, to: &str) -> Option<i64> {
    let r = api.op("walk_class", json!({"class": "Changelevel", "include_inactive": false}));
    r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of).find(|h| {
        api.op("read_field", json!({"handle": h, "field": "OtherLevel"})).result.as_str() == Some(to)
            && call(api, *h, "get_isActiveAndEnabled", json!([])).as_bool() == Some(true)
    })
}

/// The area the player is in (the active scene).
fn level_now(api: &Api<Value>) -> String {
    call_static(api, "UnityEngine.Application", "get_loadedLevelName", json!([])).as_str().unwrap_or("").to_string()
}

/// Every area an active door here leads to, sorted.
fn door_destinations(api: &Api<Value>) -> Vec<String> {
    let r = api.op("walk_class", json!({"class": "Changelevel", "include_inactive": false}));
    let mut to: Vec<String> = r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of)
        .filter(|h| call(api, *h, "get_isActiveAndEnabled", json!([])).as_bool() == Some(true))
        .filter_map(|h| api.op("read_field", json!({"handle": h, "field": "OtherLevel"})).result.as_str().map(String::from))
        .filter(|to| !to.is_empty()) // doors that lead nowhere
        .collect();
    to.sort();
    to.dedup();
    to
}

/// Through a door with the game's own Interact. Kept areas on: the mod's
/// trip. Off: the game's normal load.
fn use_door(api: &Api<Value>, to: &str, kept_on: bool) {
    let trips = kept(api)["trips"].as_array().map_or(0, |t| t.len());
    let controller = instance_now(api, "GameController");
    let door = door_to(api, to).unwrap_or_else(|| panic!("no door to {to} here"));
    call(api, door, "Interact", json!([]));
    if kept_on {
        wait_for(&format!("moved to {to}"), 30, || {
            let k = kept(api);
            k["trips"].as_array().map_or(0, |t| t.len()) > trips && k["current"].as_str() == Some(to)
        });
        println!("  trip: {}", kept(api)["trips"].as_array().and_then(|t| t.last().cloned()).unwrap_or_default());
        // The NPC system's idea of the player's area (NPCManager.ActiveScene,
        // read by 20 NPC code paths) is the area entered.
        let npc = instance_of(api, "NPCManager").ok().flatten().expect("NPCManager.instance");
        assert_eq!(call(api, npc, "get_ActiveScene", json!([])).as_str(), Some(to), "NPCManager.ActiveScene after the door");
        // The area's settings in the live set: the background radiation its
        // info_game_logic.Start pushes into RadiationController.
        let own = handle_of(&call_static(api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["info_game_logic", to]))).expect("the area's info_game_logic");
        let want = api.op("read_field", json!({"handle": own, "field": "backgroundRadiation"})).result.as_f64();
        let radiation = instance_of(api, "RadiationController").ok().flatten().expect("RadiationController.instance");
        wait_for("the area's background radiation", 5, || api.op("read_field", json!({"handle": radiation, "field": "backgroundRadiation"})).result.as_f64() == want);
        println!("  background radiation {want:?}");
        // The area's own sound: the global soundscape belongs to the area
        // entered, and stays so (a left area's SoundscapeGlobal, still
        // subscribed to MinutePassed, set its own every game minute).
        // An area whose SoundscapeGlobal has no day or night soundscape
        // (Under Map) has no global sound: in the game the rebuilt
        // SoundscapeController holds none (docs/sound.md).
        if let Some(own) = handle_of(&call_static(api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["SoundscapeGlobal", to]))) {
            let has = |f: &str| handle_of(&api.op("read_field", json!({"handle": own, "field": f})).result).is_some();
            let want = (has("soundscapeDay") || has("soundscapeNight")).then_some(to);
            let sc = instance_of(api, "SoundscapeController").ok().flatten().expect("SoundscapeController.instance");
            let area_of = |field: &str| {
                handle_of(&api.op("read_field", json!({"handle": sc, "field": field})).result)
                    .map(|s| call_static(api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": s}])))
                    .and_then(|v| v.as_str().map(String::from))
            };
            wait_for("the area's own sound", 10, || area_of("currentGlobalSoundscape").as_deref() == want);
            // And the sound playing now is the area's or none (a sound zone
            // of the area left could still be playing).
            let playing = area_of("currentSoundscape");
            assert!(playing.is_none() || playing.as_deref() == Some(to), "the sound playing after the door is in {playing:?}");
            std::thread::sleep(Duration::from_secs(3)); // time for a left area's handler to set its own (not checked to be a game minute)
            assert_eq!(area_of("currentGlobalSoundscape").as_deref(), want, "the global sound after a game minute");
            println!("  sound: global in {want:?}, playing in {playing:?}");
        }
    } else {
        wait_for_normal_load(api, &controller);
        wait_for(&format!("in {to}"), 30, || level_now(api) == to);
    }
    map_is_the_areas(api, to);
    build_space_is_the_loads(api, to);
}

/// The map after a door is the area's (docs/map.md): the panel shows the
/// area's info_map image, MapController's current record is the area's
/// map id, and the panel holds that record's landmarks only.
fn map_is_the_areas(api: &Api<Value>, to: &str) {
    let Some(info) = instance_of(api, "info_map").ok().flatten() else {
        println!("  map: none in {to}");
        return;
    };
    let name = |h: Option<i64>| h.map(|h| call(api, h, "get_name", json!([]))).and_then(|v| v.as_str().map(String::from));
    let image = name(handle_of(&api.op("read_field", json!({"handle": info, "field": "mapImage"})).result));
    let Some(image) = image else {
        println!("  map: {to} has no map image");
        return;
    };
    let task = handle_of(&api.op("read_field", json!({"handle": info, "field": "requiredTaskItem"})).result);
    let id = task.map(|t| call(api, t, "get_Id", json!([])).as_str().unwrap_or("").to_string()).unwrap_or_else(|| image.clone());
    let controller = instance_of(api, "MapController").ok().flatten().expect("MapController.instance");
    let panel = handle_of(&api.op("read_field", json!({"handle": controller, "field": "map"})).result).expect("MapController.map");
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let shown = || field(panel, "mapImage").and_then(|img| name(handle_of(&call(api, img, "get_sprite", json!([])))));
    let record = || field(controller, "currentSceneMapInfo");
    let record_id = || record().and_then(|r| api.op("read_field", json!({"handle": r, "field": "taskItemId"})).result.as_str().map(String::from));
    wait_for("the area's map", 5, || shown().as_deref() == Some(image.as_str()) && record_id().as_deref() == Some(id.as_str()));
    let count = |h: Option<i64>| h.map(|l| call(api, l, "get_Count", json!([])).as_i64().unwrap_or(-1)).unwrap_or(-1);
    let recorded = count(record().and_then(|r| field(r, "landmarkInfos")));
    let markers = count(field(panel, "landmarks"));
    println!("  map: {image} (id {id}), landmarks recorded {recorded}, on the panel {markers}");
    assert_eq!(markers, recorded, "landmarks on the map panel after the door to {to}");
}

/// The build space after a door is what the game's load makes it
/// (docs/building.md): the area's FurnitureManager saved as `isActive`, or
/// none.
fn build_space_is_the_loads(api: &Api<Value>, to: &str) {
    let managers = call_static(api, "Unityforge.Shim.SceneTools", "ComponentsIn", json!([to, "Inventory, Assembly-CSharp", "FurnitureManager"]));
    let arr = handle_of(&managers);
    let n = arr.map(|a| api.op("read_field", json!({"handle": a, "field": "Length"})).result.as_i64().unwrap_or(0)).unwrap_or(0);
    let want = (0..n)
        .filter_map(|i| handle_of(&call(api, arr.unwrap(), "GetValue", json!([i]))))
        .find(|m| api.op("read_field", json!({"handle": m, "field": "isActive"})).result.as_bool() == Some(true))
        .and_then(|m| call(api, m, "GetInstanceID", json!([])).as_i64());
    let t = handle_of(&call_static(api, "System.Type", "GetType", json!(["BuildingSystem, Assembly-CSharp"]))).expect("BuildingSystem");
    let f = handle_of(&call(api, t, "GetField", json!(["activeManager"]))).expect("activeManager field");
    let now = || handle_of(&call(api, f, "GetValue", json!([null]))).and_then(|m| call(api, m, "GetInstanceID", json!([])).as_i64());
    wait_for("the build space", 5, || now() == want);
    println!("  build space: {n} in {to}, active {want:?}");
}

#[test]
fn kept_areas_played_through() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // OBENSEUER_KEPT_OFF=1: the same run with kept areas off (the game's
    // own loads), to tell the game's own errors from the mod's.
    let kept_on = std::env::var("OBENSEUER_KEPT_OFF").is_err();
    op(&api, "load_alongside", json!({"auto": kept_on}));
    println!("kept areas {}", if kept_on { "on" } else { "OFF" });
    op(&api, "errors", json!({"mark": true}));

    // 1. A normal load, then areas kept loaded around the home area.
    let controller = instance_now(&api, "GameController");
    let loading = op(&api, "reload_save", json!({}))["loading"].as_str().unwrap_or("").to_string();
    let players_save = loading.rsplit('/').next().unwrap_or("").to_string();
    wait_for_normal_load(&api, &controller);
    // OBENSEUER_DOOR_AT_ONCE=1: the first door right after the load, before
    // the area behind it has loaded alongside (it loads behind the loading
    // screen; the door must still go through the mod).
    let at_once = std::env::var("OBENSEUER_DOOR_AT_ONCE").is_ok();
    if kept_on && !at_once {
        wait_for("areas kept loaded around home", 180, || {
            let k = kept(&api);
            k["loaded"].as_object().map_or(0, |m| m.len()) >= 2 && k["loading"].as_array().is_some_and(|l| l.is_empty())
        });
    }
    std::thread::sleep(Duration::from_secs(2));
    // Read right after a load, the name came back empty.
    wait_for("the area's name", 30, || !level_now(&api).is_empty());
    let home = level_now(&api);
    let loaded: Vec<String> = kept(&api)["loaded"].as_object().into_iter().flatten().map(|(a, _)| a.clone()).collect();
    // OBENSEUER_AWAY picks the area (Under Map: its own sky and radiation
    // 89, so its settings following the player shows; docs/areas.md, info_game_logic).
    let wanted = std::env::var("OBENSEUER_AWAY").ok();
    let away = door_destinations(&api)
        .into_iter()
        .find(|a| *a != home && (!kept_on || at_once || loaded.contains(a)) && wanted.as_deref().is_none_or(|w| w == a))
        .expect("an area a home door leads to");
    println!("home {home}, away {away}");

    // 2. Out and back through doors, twice: the second visit to the area
    // away from home must also move without a loading screen.
    for round in 1..=2 {
        use_door(&api, &away, kept_on);
        std::thread::sleep(Duration::from_secs(2));
        // Some areas have no door back (Under Map): the one door in is
        // checked, then the save.
        if door_to(&api, &home).is_none() {
            println!("  no door back to {home} from {away}: one way only");
            break;
        }
        use_door(&api, &home, kept_on);
        std::thread::sleep(Duration::from_secs(2));
        println!("  after round {round}: arrival point ids per area {}", kept(&api)["loaded"]);
    }

    // 3. Save into the test slot and load it.
    call_static(&api, "SaveController", "SaveGame", json!(["ModTest", "", "NONE"]));
    // NPCs of the area away keep their own area in the save (docs/kept-areas.md,
    // NPCs): the game's save records an NPC that has an object as being in the
    // current area, and kept areas' NPC objects were still bound.
    if kept_on {
        let mut misfiled = Vec::new();
        let mut seen = 0;
        if let Some(manager) = handle_of(&call_static(&api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["NPCManager", away]))) {
            if let Some(list) = handle_of(&call(&api, manager, "GetAllNPCs", json!([]))) {
                let n = call(&api, list, "get_Count", json!([])).as_i64().unwrap_or(0);
                for i in 0..n {
                    let Some(info) = handle_of(&call(&api, list, "get_Item", json!([i]))) else { continue };
                    let Some(ctrl) = handle_of(&api.op("read_field", json!({"handle": info, "field": "npcController"})).result) else { continue };
                    let Some(data) = handle_of(&api.op("read_field", json!({"handle": ctrl, "field": "Data"})).result) else { continue };
                    let Some(state) = handle_of(&api.op("read_field", json!({"handle": data, "field": "state"})).result) else { continue };
                    seen += 1;
                    let scene = api.op("read_field", json!({"handle": state, "field": "currentScene"})).result;
                    if scene.as_str() == Some(home.as_str()) {
                        misfiled.push(call(&api, info, "get_name", json!([])));
                    }
                }
            }
        }
        println!("NPCs of {away} after the save: {seen}, recorded as in {home}: {misfiled:?}");
        assert!(misfiled.is_empty(), "NPCs of {away} saved as in {home}: {misfiled:?}");
    }
    let controller = instance_now(&api, "GameController");
    op(&api, "reload_save", json!({}));
    wait_for_normal_load(&api, &controller);
    std::thread::sleep(Duration::from_secs(3));

    // Checks.
    // A class the loaded area has no object of is empty in the game too
    // (Under Map has no info_map).
    let level = level_now(&api);
    let has_one = |c: &str| {
        let found = call_static(&api, "Unityforge.Shim.SceneTools", "ComponentsIn", json!([level, "Inventory, Assembly-CSharp", c]));
        handle_of(&found).is_some_and(|a| api.op("read_field", json!({"handle": a, "field": "Length"})).result.as_i64().unwrap_or(0) > 0)
    };
    let dead: Vec<String> = WATCHED
        .iter()
        .map(|c| (c, instance_now(&api, c)))
        .filter(|(c, v)| v.parse::<i64>().is_err() && (v != "null" || has_one(c)))
        .map(|(c, v)| format!("{c}: {v}"))
        .collect();
    let t = handle_of(&call_static(&api, "System.Type", "GetType", json!(["PlayerIdentity, Assembly-CSharp"]))).expect("PlayerIdentity");
    let f = handle_of(&call(&api, t, "GetField", json!(["identity"]))).expect("identity field");
    let me = handle_of(&call(&api, f, "GetValue", json!([null]))).map(|h| api.op("read_field", json!({"handle": h, "field": "firstName"})).result);
    let errors = op(&api, "errors", json!({}));
    println!("\none-copy fields not live: {dead:?}");
    println!("player identity first name: {me:?}");
    println!("game errors during the run: {}", errors["total"]);
    for g in errors["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }

    // Back to the player's own save, so their next save goes to their slot.
    let controller = instance_now(&api, "GameController");
    op(&api, "load_alongside", json!({"auto": true}));
    let back = op(&api, "reload_save", json!({"save": players_save}));
    wait_for_normal_load(&api, &controller);
    println!("back on the player's save: {}, kept areas on", back["loading"]);
    assert!(dead.is_empty(), "one-copy fields not live: {dead:?}");
    assert_eq!(me.as_ref().and_then(|v| v.as_str()), Some("Tom"), "player identity lost");
}
