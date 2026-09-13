//! Host the existing local world save as a LAN game from the main menu.
//!
//! Decoded from the shipped Continue menu (W_MainMenu_ContinueGame_C):
//! SelectNewWorldEntry copies the chosen entry's FolderName into the game
//! instance's ActiveWorldSaveName, and the host button ends in
//! HostMultiplayerGame(MaxPlayers, HostLAN, MapToHost) on the W_HostMenu_Parent_C
//! base, which creates the session and opens MapToHost with
//! "?listen?bIsLanMatch=1?MaxPlayers=N". This op performs those two steps with
//! the real widget and game instance; nothing else about hosting is reimplemented.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::{ClassRef, UObject};

static HOST_MENU_PARENT: ClassRef = ClassRef::new("W_HostMenu_Parent_C");

#[repr(C)]
struct HostMultiplayerGameParms {
    player_count: i32,
    use_lan: u8,
    _pad: [u8; 3],
    map_to_host: [u8; 8],
}

/// Replace the FString at `offset` on `object` with `text`, growing its
/// buffer through the engine allocator when the current capacity is too small.
pub(crate) unsafe fn write_fstring(object: &UObject, offset: usize, text: &str) -> Result<(), String> {
    let header = unsafe { object.field_ptr(offset) };
    let needed = i32::try_from(text.encode_utf16().count() + 1).map_err(|_| "save name too long")?;
    let max = unsafe { ((header as usize + 12) as *const i32).read_unaligned() };
    if max < needed {
        unsafe { ueforge::ue::tarray::grow_raw(header, 2, needed)? };
    }
    let data = unsafe { (header as *const *mut u16).read_unaligned() };
    for (index, unit) in text.encode_utf16().chain(std::iter::once(0)).enumerate() {
        unsafe { data.add(index).write_unaligned(unit) };
    }
    unsafe { ((header as usize + 8) as *mut i32).write_unaligned(needed) };
    Ok(())
}

/// Call a static Blueprint library function on its class default object,
/// filling named parameters from `set`, and return the parameter block with the
/// offset of ReturnValue (0 when the function returns nothing).
pub(crate) unsafe fn call_static(class: &str, function: &str, set: &[(&str, &[u8])]) -> Result<(Vec<u8>, usize), String> {
    let cdo = ueforge::selector::resolve(&format!("singleton:{class}"))?;
    let uclass = ueforge::ue::find_class_fast(class).ok_or_else(|| format!("class '{class}' not found"))?;
    let func = uclass.get_function(class, function).ok_or_else(|| format!("function '{class}::{function}' not found"))?;
    let params = func.iter_parameters();
    let mut parms = vec![0u8; func.parms_size() as usize];
    for (name, bytes) in set {
        let param = params.iter().find(|p| p.name == *name).ok_or_else(|| format!("{class}::{function} has no parameter {name}"))?;
        if param.element_size as usize != bytes.len() {
            return Err(format!("{class}::{function} parameter {name} is {} bytes, not {}", param.element_size, bytes.len()));
        }
        parms[param.offset as usize..][..bytes.len()].copy_from_slice(bytes);
    }
    let ret = params.iter().find(|p| p.name == "ReturnValue").map_or(0, |p| p.offset as usize);
    // SAFETY: game thread; the block is sized from the live UFunction.
    unsafe { cdo.process_event(func, parms.as_mut_ptr().cast()) };
    Ok((parms, ret))
}

/// The same check HostMultiplayerGame makes before creating a session:
/// IsLoggedIn(GetPlayerController(0)). Without it the menu silently hosts single player.
unsafe fn logged_in(world_context: &UObject) -> Result<bool, String> {
    let context = (world_context as *const UObject as u64).to_le_bytes();
    let (parms, ret) = unsafe { call_static("GameplayStatics", "GetPlayerController", &[("WorldContextObject", &context), ("PlayerIndex", &0i32.to_le_bytes())])? };
    let controller = parms[ret..ret + 8].to_vec();
    if controller.iter().all(|b| *b == 0) { return Err("no player controller yet".into()); }
    let (parms, ret) = unsafe { call_static("KismetSystemLibrary", "IsLoggedIn", &[("SpecificPlayer", &controller)])? };
    Ok(parms[ret] != 0)
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
        let name_offset = ueforge::input::class_property_offset(instance, "ActiveWorldSaveName", 16)?;
        let map_offset = ueforge::input::class_property_offset(widget, "MapToHost", 8)?;
        let mut parms = HostMultiplayerGameParms { player_count: max_players, use_lan: 1, _pad: [0; 3], map_to_host: [0; 8] };
        // SAFETY: game thread; offsets come from the live reflected classes.
        unsafe {
            write_fstring(instance, name_offset, &save)?;
            std::ptr::copy_nonoverlapping(widget.field_ptr(map_offset), parms.map_to_host.as_mut_ptr(), 8);
            ueforge::ue::pe_call::call_ufunction(widget, &HOST_MENU_PARENT, "HostMultiplayerGame", &mut parms)?;
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
            ueforge::ue::pe_call::call_ufunction_zeroed(master, "W_MainMenu_Master_C", "SplashKeyDown")?;
            ueforge::ue::pe_call::call_ufunction_zeroed(master, "W_MainMenu_Master_C", "Continue_EarlyAccess")?;
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
