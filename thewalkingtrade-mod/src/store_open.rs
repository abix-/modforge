//! The shop opens by itself when a new day starts.
//!
//! Vanilla (Cpp2IL dump 1.2.5): `GameController.OnPlayerSleepCompleted`
//! despawns zombies and customers, calls `StoreManager.CloseStore`,
//! clears items, moves the player to respawn, runs `TimeManager.Sleep`
//! and starts the save. A postfix on it calls
//! `StoreManager.TryToggleStoreOpen`, the call the open switch
//! (`OpenShopSwitch.Interact`) makes, so the game's own checks
//! (opening blocked, prerequisite quests) and the sign still apply.

use std::ffi::c_void;

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, patch_postfix};
use unityforge::mono::{LogLevel, MonoType, json_handle, log, owned_object};

pub fn install() {
    match patch_postfix("Il2CppRuntime.Game.GameController", "OnPlayerSleepCompleted", after_sleep) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(
            LogLevel::Error,
            &format!("thewalkingtrade-mod: patch GameController.OnPlayerSleepCompleted FAILED: {e}"),
        ),
    }
}

extern "C" fn after_sleep(_: *const c_void) {
    let _m = modforge::counters::measure("twt: hook: new day open shop");
    match open() {
        Ok(msg) => log(LogLevel::Info, &format!("thewalkingtrade-mod: new day: {msg}")),
        Err(e) => log(LogLevel::Warn, &format!("thewalkingtrade-mod: new day open: {e}")),
    }
}

fn open() -> Result<String, String> {
    let ty = MonoType::find("Il2CppRuntime.Game.StoreManager").ok_or("type StoreManager not found")?;
    let walked = ty.walk(false)?;
    let list = walked
        .get("instances")
        .and_then(Json::as_array)
        .or_else(|| walked.as_array())
        .cloned()
        .unwrap_or_default();
    let h = list.first().and_then(json_handle).ok_or("no StoreManager")?;
    let store = owned_object(h);
    for v in list.iter().skip(1) {
        if let Some(h) = json_handle(v) {
            drop(owned_object(h));
        }
    }
    if store.invoke("get_IsOpen", &json!([]))?.as_bool() == Some(true) {
        return Ok("shop already open".into());
    }
    let ok = store.invoke("TryToggleStoreOpen", &json!([]))?;
    Ok(format!("shop opened = {ok}"))
}
