//! Host the existing local world save as a LAN game from the main menu.
//!
//! Decoded from the shipped Continue menu (W_MainMenu_ContinueGame_C):
//! SelectNewWorldEntry copies the chosen entry's FolderName into the game
//! instance's ActiveWorldSaveName, and the host button ends in
//! HostMultiplayerGame(MaxPlayers, HostLAN, MapToHost) on the W_HostMenu_Parent_C
//! base, which creates the session and opens MapToHost with
//! "?listen?bIsLanMatch=1?MaxPlayers=N". This op performs those two steps with
//! the real widget and game instance through ueforge's generic field and call
//! tools; nothing else about hosting is reimplemented.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// The same check HostMultiplayerGame makes before creating a session:
/// IsLoggedIn(GetPlayerController(0)). Without it the menu silently hosts single player.
unsafe fn logged_in(world_context: &UObject) -> Result<bool, String> {
    let statics = ueforge::selector::resolve("singleton:GameplayStatics")?;
    let controller = unsafe { ueforge::reflect::call(statics, "GameplayStatics", "GetPlayerController", json!({"WorldContextObject": format!("0x{:X}", world_context.as_ptr() as u64), "PlayerIndex": 0}).as_object().unwrap())? };
    let controller = crate::ai_player::addr(&controller["ReturnValue"]);
    if controller == 0 { return Err("no player controller yet".into()); }
    let system = ueforge::selector::resolve("singleton:KismetSystemLibrary")?;
    let reply = unsafe { ueforge::reflect::call(system, "KismetSystemLibrary", "IsLoggedIn", json!({"SpecificPlayer": format!("0x{controller:X}")}).as_object().unwrap())? };
    Ok(reply["ReturnValue"] == true)
}

fn saved_world(args: &Value) -> Result<Value, String> {
    let save = args["save"].as_str().filter(|s| !s.is_empty())
        .ok_or("save must name an existing world save folder")?.to_owned();
    let max_players = i32::try_from(args["max_players"].as_i64().unwrap_or(6)).map_err(|e| e.to_string())?;
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(5), crate::DRAIN_HINT, move || {
        let widget = ueforge::selector::resolve("first_class:W_MainMenu_ContinueGame_C")?;
        let instance = ueforge::selector::resolve("first_class:Abiotic_GameInstance_C")?;
        // SAFETY: game thread; the widget is a live world context object.
        if !unsafe { logged_in(widget)? } {
            return Err("online login not complete; HostMultiplayerGame would fall back to single player".into());
        }
        unsafe {
            ueforge::reflect::set_fields(instance, json!({"ActiveWorldSaveName": save}).as_object().unwrap())?;
            // MapToHost is the widget's own soft map reference, passed through unchanged.
            let map = ueforge::reflect::get_fields(widget, &["MapToHost".into()])?["MapToHost"].clone();
            ueforge::reflect::call(widget, "W_HostMenu_Parent_C", "HostMultiplayerGame", json!({"MaxPlayers": max_players, "HostLAN": true, "MapToHost": map}).as_object().unwrap())?;
        }
        Ok(json!({"save":save,"max_players":max_players,"lan":true,"state":"host_requested"}))
    })
}

/// Press anything to begin: the master menu widget's own splash key handler
/// (no parameters), then the early-access notice's continue. Live 2026-09-13,
/// research_main_menu.
fn splash(_: &Value) -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(5), crate::DRAIN_HINT, || {
        let master = ueforge::selector::resolve("first_class:W_MainMenu_Master_C")?;
        unsafe {
            ueforge::reflect::call(master, "W_MainMenu_Master_C", "SplashKeyDown", &serde_json::Map::new())?;
            ueforge::reflect::call(master, "W_MainMenu_Master_C", "Continue_EarlyAccess", &serde_json::Map::new())?;
        }
        Ok(json!({"state": "splash_dismissed"}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new(
            "host.saved_world",
            "Host an existing world save as a LAN game through the main menu's own host path",
            "{save: str, max_players?: int}",
            saved_world,
        ),
        ueforge::ops::OpDef::new(
            "host.splash",
            "Dismiss the press-anything splash and the early-access notice through the master menu widget's own handlers",
            "{}",
            splash,
        ),
    ]);
}
