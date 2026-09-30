//! Hires do not die: a killing hit leaves them at 1 HP instead.
//!
//! Vanilla (Cpp2IL dump): `Damageable.ApplyDamage` lowers `_health`
//! (floored at 0), invokes its `Damaged` handlers, and only then
//! checks `_health <= 0` to invoke `Died` (hire's `OnDied`: ragdoll
//! with loot, despawn, `StaffManager.OnDespawned` removes them for
//! good). Read live on a hire (`staff_damage_handlers`): the last
//! `Damaged` handler is the hire's own `StaffMobObject.OnDamagedCheckLowHp`,
//! subscribed only on hires.
//!
//! A prefix on that handler sets the hire's health back to 1 when the
//! hit took it to 0, before the death check sees it; the handler then
//! runs its normal low-HP behaviour, and `flee_return` brings a fled
//! hire back healed. The earlier handlers see 0 for that hit; read in
//! the dump, none acts on it (`CombatManager` forwards the args,
//! `BaseMobCombatant` updates threat, `MobHealFromInventory` only heals
//! while health > 0). Hooking the hire's own handler instead of
//! `CombatManager.OnDamageableDamaged` means only hits on hires reach
//! Rust (measured: about 90 calls a second on every damageable).

use std::ffi::c_void;

use serde_json::json;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

use crate::ctx_object;

const SAVED_HEALTH: f64 = 1.0;

pub fn install() {
    match patch_prefix_ctx(
        "Il2CppRuntime.Mob.Staff.StaffMobObject",
        "OnDamagedCheckLowHp",
        HookCtx::Instance,
        on_hire_damaged,
    ) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(
            LogLevel::Error,
            &format!("thewalkingtrade-mod: patch StaffMobObject.OnDamagedCheckLowHp FAILED: {e}"),
        ),
    }
}

extern "C" fn on_hire_damaged(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: hire damaged (no death)");
    let Some(staff) = ctx_object(ctx) else { return 0 };
    if let Err(e) = rescue(&staff) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: no death: {e}"));
    }
    // Never skip: the low-HP check still runs.
    0
}

fn rescue(staff: &MonoObject) -> Result<(), String> {
    let d = staff.read_field("_damageable")?;
    let Some(dh) = json_handle(&d) else { return Ok(()) };
    let dmg = owned_object(dh);
    let health = dmg.invoke("get_Health", &json!([]))?.as_f64().unwrap_or(1.0);
    if health > 0.0 {
        return Ok(());
    }
    dmg.invoke("SetHealth", &json!([SAVED_HEALTH]))?;
    let name = staff.invoke("get_Name", &json!([]))?;
    log(
        LogLevel::Info,
        &format!(
            "thewalkingtrade-mod: saved {} from death at {SAVED_HEALTH} HP",
            name.as_str().unwrap_or("?")
        ),
    );
    Ok(())
}
