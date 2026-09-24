//! Autopsy table helpers.
//!
//! No "Extract?" confirmation when taking an item out of a body's pocket.
//! UIAutopsyWindowData.TryExtractItemFromPocket opens a yes/no
//! UIDialogWindow (header key ui_extract_item_header) whose yes action
//! starts the pocket extract craft. A prefix on UIDialogWindow.Open skips
//! that one dialog and runs its yes action (ButtonsData[0].onPressed) on
//! the next tick, as a click on Yes would. Every other dialog opens as
//! usual.
//!
//! Auto autopsy when the player opens the table with a body on it. A
//! prefix on UIAutopsyWindow.Redraw notes the window; on the next tick,
//! with the body part cells drawn, every cell holding a part the game lets
//! the player remove (not isOrganMistake) goes through the game's own
//! UIAutopsyWindowData.TryExtractMainOrgan, as a click on it would. That
//! opens a UICraftSelectionWindow; while this runs, a prefix on its Open
//! skips the window and its start button (OnCraftStarted) is pressed, so
//! the game queues the extract craft itself. Every filled pocket slot goes
//! through TryExtractItemFromPocket the same way; its "Extract?" yes
//! action is collected (not deferred to the next tick) and run, which
//! queues the pocket extract craft. work.rs then works the table's queue,
//! free of energy. A zombie body is left alone: clicking its parts changes
//! organs instead of removing them.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use std::ffi::{CStr, c_char, c_void};
use std::sync::atomic::{AtomicBool, AtomicI32, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::hook::{HOOK_REGISTRY, patch_prefix_instance_args};
use unityforge::mono::{LogLevel, MonoObject, invoke_static, log};

use crate::take_all::{arg, call};
use crate::tweaks::read_handle;
use crate::work;

const EXTRACT_HEADER_KEY: &str = "ui_extract_item_header";

/// The confirmed dialog's yes action (an Action handle), run next tick.
static PENDING_YES: AtomicI32 = AtomicI32::new(0);
/// The autopsy window whose Redraw just ran, owned here.
static PENDING_WINDOW: AtomicI32 = AtomicI32::new(0);
/// Set while this module presses body part cells, so the craft selection
/// window they open is skipped and kept in SELECTIONS.
static PRESSING: AtomicBool = AtomicBool::new(false);
/// UICraftSelectionWindowData handles caught while PRESSING, owned here.
static SELECTIONS: Mutex<Vec<i32>> = Mutex::new(Vec::new());
/// Pocket "Extract?" yes actions caught while PRESSING, owned here.
static POCKET_YES: Mutex<Vec<i32>> = Mutex::new(Vec::new());
/// UniqueId of the last body auto autopsied, so a redraw does not queue
/// its parts twice.
static LAST_BODY: Mutex<Option<Json>> = Mutex::new(None);

pub fn install() {
    type Prefix = extern "C" fn(*const c_void, *const c_char) -> i32;
    let hooks: [(&str, &str, Prefix); 3] = [
        ("UIDialogWindow", "Open(UIDialogWindowData)", on_dialog_open),
        ("UIAutopsyWindow", "Redraw", on_autopsy_redraw),
        ("UICraftSelectionWindow", "Open(UICraftSelectionWindowData)", on_selection_open),
    ];
    for (class, method, prefix) in hooks {
        match patch_prefix_instance_args(class, method, prefix) {
            Ok(hook) => HOOK_REGISTRY.register(hook),
            Err(e) => log(LogLevel::Error, &format!("autopsy: hook {class}.{method} failed: {e}")),
        }
    }
}

/// The first argument's handle from a prefix's JSON args, owned.
fn arg0(args: *const c_char) -> Option<MonoObject> {
    if args.is_null() {
        return None;
    }
    unsafe { CStr::from_ptr(args) }
        .to_str()
        .ok()
        .and_then(|s| serde_json::from_str::<Json>(s).ok())
        .and_then(|j| j.get(0).and_then(|a| a.get("handle")).and_then(Json::as_i64))
        .map(|h| own(h as i32))
}

extern "C" fn on_autopsy_redraw(instance: *const c_void, _args: *const c_char) -> i32 {
    let h = instance as usize as i32;
    if h != 0 {
        let old = PENDING_WINDOW.swap(h, Ordering::AcqRel);
        if old != 0 && old != h {
            drop(own(old));
        }
    }
    0
}

extern "C" fn on_selection_open(instance: *const c_void, args: *const c_char) -> i32 {
    let window = instance as usize as i32;
    if window != 0 {
        drop(own(window));
    }
    let Some(data) = arg0(args) else {
        return 0;
    };
    if !PRESSING.load(Ordering::Acquire) {
        return 0;
    }
    SELECTIONS.lock().push(data.handle().0);
    std::mem::forget(data);
    1
}

fn own(h: i32) -> MonoObject {
    unsafe { MonoObject::from_handle(MonoHandle(h)) }
}

extern "C" fn on_dialog_open(instance: *const c_void, args: *const c_char) -> i32 {
    let window = instance as usize as i32;
    if window != 0 {
        drop(own(window));
    }
    let Some(data) = arg0(args) else {
        return 0;
    };
    match extract_yes_action(&data) {
        Ok(Some(yes)) if PRESSING.load(Ordering::Acquire) => {
            POCKET_YES.lock().push(yes.handle().0);
            std::mem::forget(yes);
            1
        }
        Ok(Some(yes)) => {
            let old = PENDING_YES.swap(yes.handle().0, Ordering::AcqRel);
            std::mem::forget(yes);
            if old != 0 {
                drop(own(old));
            }
            1
        }
        Ok(None) => 0,
        Err(e) => {
            log(LogLevel::Warn, &format!("autopsy: {e}"));
            0
        }
    }
}

/// The yes action when this is the pocket "Extract?" dialog.
fn extract_yes_action(data: &MonoObject) -> Result<Option<MonoObject>, String> {
    let header = data.invoke("get_Header", &json!([]))?;
    let extract = invoke_static("LLBase", "L", &json!([EXTRACT_HEADER_KEY]))?;
    if header != extract {
        return Ok(None);
    }
    let buttons = call(data, "get_ButtonsData", json!([]))?.ok_or("dialog has no buttons")?;
    let yes = call(&buttons, "get_Item", json!([0]))?.ok_or("dialog has no yes button")?;
    Ok(Some(read_handle(&yes, "onPressed")?))
}

// Runs on the Unity main thread, like the hooks.
pub fn on_tick() {
    let h = PENDING_YES.swap(0, Ordering::AcqRel);
    if h != 0 {
        let yes = own(h);
        match yes.invoke("Invoke", &json!([])) {
            Ok(_) => log(LogLevel::Info, "autopsy: extracted without confirmation"),
            Err(e) => log(LogLevel::Warn, &format!("autopsy: yes action: {e}")),
        }
    }
    let w = PENDING_WINDOW.swap(0, Ordering::AcqRel);
    if w != 0 {
        if let Err(e) = auto_autopsy(&own(w)) {
            PRESSING.store(false, Ordering::Release);
            let left = std::mem::take(&mut *SELECTIONS.lock());
            for h in left.into_iter().chain(std::mem::take(&mut *POCKET_YES.lock())) {
                drop(own(h));
            }
            log(LogLevel::Warn, &format!("autopsy: {e}"));
        }
    }
}

/// Queues every removable body part of the body on the table, then has
/// work.rs work the table.
fn auto_autopsy(window: &MonoObject) -> Result<(), String> {
    let data = read_handle(window, "data")?;
    if data.invoke("get_IsEmpty", &json!([]))? == json!(true) || data.read_field("isZombie")? == json!(true) {
        return Ok(());
    }
    let body = read_handle(&data, "bodyItem")?;
    let body_id = body.invoke("get_UniqueId", &json!([]))?;
    if LAST_BODY.lock().as_ref() == Some(&body_id) {
        return Ok(());
    }

    let widget = read_handle(window, "bodyOrgansInventoryWidget")?;
    let cells = read_handle(&widget, "mainOrgansFixedTypeItemCells")?;
    let n = cells.read_field("_size")?.as_i64().unwrap_or(0);
    PRESSING.store(true, Ordering::Release);
    for i in 0..n {
        let Some(fixed) = call(&cells, "get_Item", json!([i]))? else {
            continue;
        };
        let Some(cell) = call(&fixed, "get_UIItemCell", json!([]))? else {
            continue;
        };
        let Some(item) = call(&cell, "get_DisplayingItem", json!([]))? else {
            continue;
        };
        if item.invoke("get_IsEmpty", &json!([]))? == json!(true) {
            continue;
        }
        let def = call(&item, "get_Definition", json!([]))?.ok_or("part has no Definition")?;
        if def.read_field("isOrganMistake")? == json!(true) {
            continue;
        }
        data.invoke("TryExtractMainOrgan", &json!([arg(&cell)]))?;
    }
    // Pocket slots: one cell per item (a stack draws one cell per count).
    let pocket = read_handle(window, "bodyPocketInventoryWidget")?;
    let cells = read_handle(&pocket, "cells")?;
    let n = cells.read_field("_size")?.as_i64().unwrap_or(0);
    for i in 0..n {
        let Some(cell) = call(&cells, "get_Item", json!([i]))? else {
            continue;
        };
        let Some(item) = call(&cell, "get_DisplayingItem", json!([]))? else {
            continue;
        };
        if item.invoke("get_IsEmpty", &json!([]))? == json!(true) {
            continue;
        }
        data.invoke("TryExtractItemFromPocket", &json!([arg(&cell)]))?;
    }
    PRESSING.store(false, Ordering::Release);

    let mut queued = 0;
    for h in std::mem::take(&mut *POCKET_YES.lock()) {
        own(h).invoke("Invoke", &json!([]))?;
        queued += 1;
    }
    let selections = std::mem::take(&mut *SELECTIONS.lock());
    for h in selections {
        let sel = own(h);
        let craft = call(&sel, "get_CraftDefinition", json!([]))?
            .and_then(|d| d.read_field("id").ok())
            .unwrap_or(Json::Null);
        if sel.invoke("get_CanStartCraft", &json!([]))? != json!(true) {
            log(LogLevel::Info, &format!("autopsy: cannot start {craft}"));
            continue;
        }
        let start = call(&sel, "get_OnCraftStarted", json!([]))?.ok_or("no start action")?;
        start.invoke("Invoke", &json!([]))?;
        queued += 1;
    }
    *LAST_BODY.lock() = Some(body_id);
    log(LogLevel::Info, &format!("autopsy: queued {queued} part(s)"));
    if queued > 0 {
        work::queue(read_handle(&data, "autopsyTable")?, "autopsy", table_done);
    }
    Ok(())
}

/// The table's work is done once nothing is started or queued.
fn table_done(table: &MonoObject) -> Result<bool, String> {
    let cc = read_handle(table, "craftComponent")?;
    Ok(cc.invoke("get_IsStarted", &json!([]))? != json!(true)
        && cc.invoke("get_HasCraftsInQueue", &json!([]))? != json!(true))
}
