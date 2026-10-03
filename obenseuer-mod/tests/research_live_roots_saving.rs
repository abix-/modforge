//! Design question 2 (docs/kept-areas.md, history, "Proper design"): do the
//! top objects holding the live player and managers also hold scripts that
//! save to their area's file, not the global one? If they do, saving them
//! along with another area would write their area entries into that
//! area's file.
//!
//! Lists every SavableScript under each top object of the live
//! ThirdPersonCameraController, PauseMenu, TimeOfDayAzure and
//! OpenSewerCharacterController, and where it saves: classes that always
//! call SerializeData(this, global: true), classes whose `global` field
//! decides, and the rest (area file). Class lists read from the decompiled
//! game code.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_live_roots_saving -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::{BTreeMap, BTreeSet};

use common::{api, call, call_static, handle_of, ping_or_skip};
use serde_json::json;

const ALWAYS_GLOBAL: &[&str] = &[
    "Achievements", "AnimalController", "BlackoutController", "BuildingSystem", "CharacterSlotController", "Crime",
    "DialogueCommonMethods", "DifficultyController", "DrunkEffect", "FurnitureBlueprintController", "GlobalState",
    "Inventory", "InvoiceController", "ItemsUIPanel", "JanitorController", "Keypad", "LegalServicesController",
    "MailController", "MapController", "Money", "MushroomEffect", "NPC.NPCDirector", "NoteController", "Notifications",
    "OrangeMushroomEffect", "PlayerHandItems", "PlayerIdentity", "PlayerStatUI", "PlayerStats",
    "PlayerSubscriptionsController", "RandommailSender", "RecipeController", "RelationshipController", "Sauna",
    "SaveSceneManager", "StartManager", "StartOpenSewer", "TaskController", "TaskItemsManager", "TenementController",
    "TenementEventController", "ThirdPersonCameraCollision", "ThirdPersonCameraController", "TimeOfDayAzure", "Tutorial",
    "WeatherManager",
];
const GLOBAL_BY_FIELD: &[&str] = &[
    "CounterRelay", "CraftingBase", "EditTask", "FurniturePlaceable", "LiquidStorage", "NPCInfo", "Phone",
    "RandomAudioPlayer", "Relay", "RelayRandom", "RelayRandomValue", "RelayTaskStatus", "Storage",
];
const LIVE: &[&str] = &["ThirdPersonCameraController", "PauseMenu", "TimeOfDayAzure", "OpenSewerCharacterController"];

#[test]
fn live_roots_save_where() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let savable = handle_of(&call_static(&api, "System.Type", "GetType", json!(["SavableScript, Assembly-CSharp"]))).expect("SavableScript type");
    let mut roots = BTreeMap::new();
    for class in LIVE {
        let t = handle_of(&call_static(&api, "System.Type", "GetType", json!([format!("{class}, Assembly-CSharp")])));
        let one = t
            .and_then(|t| handle_of(&call(&api, t, "GetField", json!(["instance"]))))
            .and_then(|f| handle_of(&call(&api, f, "GetValue", json!([null]))));
        let root = one
            .and_then(|o| handle_of(&call(&api, o, "get_transform", json!([]))))
            .and_then(|t| handle_of(&call(&api, t, "get_root", json!([]))))
            .and_then(|t| handle_of(&call(&api, t, "get_gameObject", json!([]))));
        if let Some(r) = root {
            let name = call(&api, r, "get_name", json!([])).as_str().unwrap_or("?").to_string();
            roots.entry(name).or_insert(r);
        }
    }
    for (name, root) in roots {
        let arr = handle_of(&call(&api, root, "GetComponentsInChildren", json!([{"handle": savable}, true]))).expect("components");
        let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
        let (mut global, mut area): (BTreeMap<String, u32>, BTreeMap<String, u32>) = Default::default();
        let mut by_field_area = BTreeSet::new();
        for i in 0..n {
            let Some(c) = handle_of(&call(&api, arr, "GetValue", json!([i]))) else { continue };
            let class = handle_of(&call(&api, c, "GetType", json!([])))
                .map(|t| call(&api, t, "get_FullName", json!([])).as_str().unwrap_or("?").to_string())
                .unwrap_or("?".into());
            let is_global = if ALWAYS_GLOBAL.contains(&class.as_str()) {
                true
            } else if GLOBAL_BY_FIELD.contains(&class.as_str()) {
                let g = api.op("read_field", json!({"handle": c, "field": "global"})).result.as_bool() == Some(true);
                if !g {
                    by_field_area.insert(class.clone());
                }
                g
            } else {
                false
            };
            *if is_global { &mut global } else { &mut area }.entry(class).or_default() += 1;
        }
        println!("\n{name}: {n} save-and-load scripts");
        println!("  global file: {global:?}");
        println!("  area file:   {area:?}");
        if !by_field_area.is_empty() {
            println!("  (area by their `global` field: {by_field_area:?})");
        }
    }
}
