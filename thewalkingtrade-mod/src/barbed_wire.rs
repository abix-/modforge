//! Barbed wire lasts DURABILITY_FACTOR times longer.
//!
//! Vanilla (Cpp2IL dump 1.2.5, read live): every 0.25 s a secured
//! `BarbedWireDamageTrigger` deals `_damagePerTick` (10) to what is
//! caught in it and `_ownDamagePerTick` (2.0) to its own Damageable,
//! which is what wears it out. A prefix on the trigger's `Awake` sets
//! the self-damage to the original divided by DURABILITY_FACTOR as
//! each wire comes into being (serialized fields are already set
//! then), so nothing is searched or polled.

use std::ffi::c_void;

use serde_json::json;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, log};

use crate::ctx_object;

const DURABILITY_FACTOR: f64 = 10.0;
/// `_ownDamagePerTick` of every wire, read live on 2026-09-30.
const ORIGINAL_OWN_DAMAGE: f64 = 2.0;

pub fn install() {
    match patch_prefix_ctx(
        "Il2CppRuntime.Combat.BarbedWireDamageTrigger",
        "Awake",
        HookCtx::Instance,
        on_awake,
    ) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(
            LogLevel::Error,
            &format!("thewalkingtrade-mod: patch BarbedWireDamageTrigger.Awake FAILED: {e}"),
        ),
    }
}

extern "C" fn on_awake(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: barbed wire awake");
    let Some(wire) = ctx_object(ctx) else { return 0 };
    let want = ORIGINAL_OWN_DAMAGE / DURABILITY_FACTOR;
    if let Err(e) = wire.write_field("_ownDamagePerTick", &json!(want)) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: barbed wire: {e}"));
    }
    0
}
