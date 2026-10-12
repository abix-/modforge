//! No stat loss on death. Enabled by default; the op turns it off.
//!
//! What the game does (Cpp2IL dump of Game.Character): Respawn()
//! calls RespawnCharacter, which takes Health's actualMax, subtracts
//! a constant 10 (compiled in; the DECREASEMAXPARAMETERAFTERDEATH
//! accessor is an interop stub the game never reads), floors it at
//! 40, and calls ParameterRange.LoadValues(newMax, newMax) on Health,
//! Food, Morale, Freshness and Warm.
//!
//! The mod copies that last step: a prefix on Respawn() records
//! Health's actualMax, and a postfix calls the same LoadValues with
//! the recorded max on the same five stats. Respawn() has no
//! arguments, unlike RespawnCharacter's out bool, which Harmony on
//! IL2CPP zeroes. The game's "max decreased" notice still shows.

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, AtomicI32, AtomicU32, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_postfix, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, log};

const CLASS: &str = "Il2CppGame.Character";
/// The five stats RespawnCharacter lowers, by their getters.
const STATS: [&str; 5] = ["get_Health", "get_Food", "get_Morale", "get_Freshness", "get_Warm"];

static ENABLED: AtomicBool = AtomicBool::new(true);
/// The Character handle the prefix took for the postfix. 0 = none.
static CHARACTER: AtomicI32 = AtomicI32::new(0);
/// Health's actualMax before the respawn, as f32 bits.
static MAX_BEFORE: AtomicU32 = AtomicU32::new(0);

pub fn install() {
    match patch_prefix_ctx(CLASS, "Respawn", HookCtx::Instance, before_respawn) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(LogLevel::Error, &format!("no stat loss on death: prefix: {e}")),
    }
    match patch_postfix(CLASS, "Respawn", after_respawn) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(LogLevel::Error, &format!("no stat loss on death: postfix: {e}")),
    }
    OP_REGISTRY.register(OpDef::new(
        "no_stat_loss_on_death",
        "Read or set whether death lowers the hobo's max stats. Enabled by default. Pass no args to read",
        "{enabled?: bool}",
        op,
    ));
}

fn handle_of(v: &Json) -> Result<i32, String> {
    v.get("handle")
        .and_then(Json::as_i64)
        .map(|h| h as i32)
        .ok_or_else(|| format!("no handle in {v}"))
}

fn stat(ch: &MonoObject, getter: &str) -> Result<MonoObject, String> {
    let h = handle_of(&ch.invoke(getter, &json!([]))?)?;
    Ok(MonoObject::from_owned_handle(MonoHandle(h)))
}

fn read_max(ch: &MonoObject) -> Result<f32, String> {
    let v = stat(ch, "get_Health")?.read_field("actualMax")?;
    v.as_f64()
        .map(|n| n as f32)
        .ok_or_else(|| format!("Health actualMax read as {v}"))
}

extern "C" fn before_respawn(ctx: *const c_void) -> i32 {
    if ctx.is_null() {
        return 0;
    }
    let ch = MonoObject::from_owned_handle(MonoHandle(ctx as usize as i32));
    if !ENABLED.load(Ordering::Acquire) {
        return 0;
    }
    match read_max(&ch) {
        Ok(max) => {
            MAX_BEFORE.store(max.to_bits(), Ordering::Release);
            // The postfix owns the handle from here.
            let old = CHARACTER.swap(ch.handle().0, Ordering::AcqRel);
            std::mem::forget(ch);
            if old != 0 {
                drop(MonoObject::from_owned_handle(MonoHandle(old)));
            }
        }
        Err(e) => log(LogLevel::Error, &format!("no stat loss on death: {e}")),
    }
    0
}

extern "C" fn after_respawn(_: *const c_void) {
    let h = CHARACTER.swap(0, Ordering::AcqRel);
    if h == 0 {
        return;
    }
    let ch = MonoObject::from_owned_handle(MonoHandle(h));
    let max = f32::from_bits(MAX_BEFORE.load(Ordering::Acquire));
    let restore = || -> Result<f32, String> {
        let lowered = read_max(&ch)?;
        for getter in STATS {
            stat(&ch, getter)?.invoke("LoadValues", &json!([max, max]))?;
        }
        Ok(lowered)
    };
    match restore() {
        Ok(lowered) => log(
            LogLevel::Info,
            &format!("no stat loss on death: max {lowered} -> {max}"),
        ),
        Err(e) => log(LogLevel::Error, &format!("no stat loss on death: {e}")),
    }
}

fn op(args: &Json) -> Result<Json, String> {
    if let Some(on) = args.get("enabled").and_then(Json::as_bool) {
        ENABLED.store(on, Ordering::Release);
    }
    Ok(json!({"enabled": ENABLED.load(Ordering::Acquire)}))
}
