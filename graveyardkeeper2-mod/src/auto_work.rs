//! Auto-work: ` toggles it. While on and the player is not pressing a
//! movement key, the action key (F) counts as held, so the game's own work
//! runs: WorkPlayerState finds the closest spot, walks the player onto
//! it, plays the work animation and ticks at the vanilla pace and cost.
//! A movement key stops holding it and the game stops working.
//!
//! LazyInput.Update clears holdedKeys every frame and refills them from
//! the keyboard or gamepad; a postfix on it adds GameKey.Action through
//! the game's own LazyInput.AddHolded. The postfix is installed only while
//! auto-work is on.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use std::ffi::c_void;
use std::sync::atomic::{AtomicI32, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::hook::{Hook, patch_postfix};
use unityforge::input::{KeyCode, register_key_press};
use unityforge::mono::{LogLevel, MonoObject, MonoType, invoke_static, log};

use crate::take_all::{arg, call};

const LAZY_INPUT: &str = "LazyBearTechnology.LazyInput";
/// Movement input shorter than this counts as standing still.
const MOVE_DEADZONE: f64 = 0.1;

/// The LazyInput.Update postfix; Some while auto-work is on.
static HOOK: Mutex<Option<Hook>> = Mutex::new(None);
/// Handles kept alive while on: the LazyInput instance and GameKey.Action.
static LAZY_INPUT_OBJ: AtomicI32 = AtomicI32::new(0);
static ACTION_KEY: AtomicI32 = AtomicI32::new(0);

pub fn install() {
    if register_key_press(KeyCode::BackQuote, on_toggle).is_none() {
        log(LogLevel::Error, "auto_work: key binding failed");
    }
}

extern "C" fn on_toggle() {
    let mut hook = HOOK.lock();
    if hook.is_some() {
        *hook = None;
        release(&LAZY_INPUT_OBJ);
        release(&ACTION_KEY);
        log(LogLevel::Info, "auto_work: off");
        return;
    }
    match turn_on() {
        Ok(h) => {
            *hook = Some(h);
            log(LogLevel::Info, "auto_work: on");
        }
        Err(e) => {
            release(&LAZY_INPUT_OBJ);
            release(&ACTION_KEY);
            log(LogLevel::Warn, &format!("auto_work: could not turn on: {e}"));
        }
    }
}

fn turn_on() -> Result<Hook, String> {
    let walk = MonoType::find(LAZY_INPUT)
        .ok_or("LazyInput type not found")?
        .walk(false)?;
    let li = walk
        .get("instances")
        .and_then(Json::as_array)
        .and_then(|a| a.first())
        .and_then(|i| i.get("handle"))
        .and_then(Json::as_i64)
        .ok_or("no LazyInput instance")? as i32;
    let li = unsafe { MonoObject::from_handle(MonoHandle(li)) };

    // GameKey.Action is a static field: reach it through reflection.
    let ty = call(&li, "GetType", json!([]))?.ok_or("GetType returned null")?;
    let asm = call(&ty, "get_Assembly", json!([]))?.ok_or("no Assembly")?;
    let key_ty = call(&asm, "GetType", json!(["LazyBearTechnology.GameKey"]))?
        .ok_or("GameKey type not found")?;
    let field = call(&key_ty, "GetField", json!(["Action"]))?.ok_or("GameKey.Action not found")?;
    let action = call(&field, "GetValue", json!([null]))?.ok_or("GameKey.Action is null")?;

    LAZY_INPUT_OBJ.store(li.handle().0, Ordering::Release);
    ACTION_KEY.store(action.handle().0, Ordering::Release);
    std::mem::forget(li);
    std::mem::forget(action);

    patch_postfix(LAZY_INPUT, "Update", on_input_update)
}

fn release(slot: &AtomicI32) {
    let h = slot.swap(0, Ordering::AcqRel);
    if h != 0 {
        drop(unsafe { MonoObject::from_handle(MonoHandle(h)) });
    }
}

extern "C" fn on_input_update(_: *const c_void) {
    let (li, action) = (
        LAZY_INPUT_OBJ.load(Ordering::Acquire),
        ACTION_KEY.load(Ordering::Acquire),
    );
    if li == 0 || action == 0 {
        return;
    }
    let Ok(dir) = invoke_static(LAZY_INPUT, "GetDirection", &json!([])) else {
        return;
    };
    let x = dir.get("x").and_then(Json::as_f64).unwrap_or(0.0);
    let y = dir.get("y").and_then(Json::as_f64).unwrap_or(0.0);
    if x * x + y * y > MOVE_DEADZONE * MOVE_DEADZONE {
        return;
    }
    let li = std::mem::ManuallyDrop::new(unsafe { MonoObject::from_handle(MonoHandle(li)) });
    let action = std::mem::ManuallyDrop::new(unsafe { MonoObject::from_handle(MonoHandle(action)) });
    if let Err(e) = li.invoke("AddHolded", &json!([arg(&action)])) {
        log(LogLevel::Warn, &format!("auto_work: {e}"));
    }
}
