//! Defend Interests lasts three times as long for the player.
//!
//! TIMissionEffect_DefendInterests.ApplyEffect builds a nation's pool
//! of protection days from two global config values,
//! defendInterestPerCPDuration_days and
//! defendInterestDistributableDuration_days. Before the effect runs,
//! this sets them to three times the game's values when the mission's
//! councilor is the player's (and to the game's values otherwise);
//! after it runs, they go back to the game's values.
//!
//! A hab target gets a fixed 60 months from
//! TIHabState.ResolveDefendHabEffect. For the player, this first adds
//! the other 120 months through the same method (it extends from the
//! current expiry), and the game's own 60 lands on top.

use std::ffi::c_void;
use std::sync::atomic::{AtomicI64, Ordering};

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_postfix, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};

const MULTIPLIER: i64 = 3;
const HAB_GAME_MONTHS: i64 = 60;
const CONFIG_FIELDS: [&str; 2] = [
    "defendInterestPerCPDuration_days",
    "defendInterestDistributableDuration_days",
];

/// The game's own values of CONFIG_FIELDS, read once. -1 = not read.
static GAME_VALUES: [AtomicI64; 2] = [AtomicI64::new(-1), AtomicI64::new(-1)];

pub fn install() {
    let prefix = patch_prefix_ctx(
        "TIMissionEffect_DefendInterests",
        "ApplyEffect",
        HookCtx::Arg0,
        on_apply_effect,
    );
    let postfix = patch_postfix("TIMissionEffect_DefendInterests", "ApplyEffect", after_apply_effect);
    match (prefix, postfix) {
        (Ok(pre), Ok(post)) => {
            HOOK_REGISTRY.register(pre);
            HOOK_REGISTRY.register(post);
            log(
                LogLevel::Info,
                &format!("terrainvicta-mod: defend interests x{MULTIPLIER} armed"),
            );
        }
        (pre, post) => {
            // Never leave one half in place: a prefix without its
            // postfix would keep the AI's durations at x3.
            for (half, r) in [("prefix", pre), ("postfix", post)] {
                if let Err(e) = r {
                    log(
                        LogLevel::Warn,
                        &format!("terrainvicta-mod: defend interests {half} failed: {e}"),
                    );
                }
            }
        }
    }
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn member_object(obj: &MonoObject, name: &str) -> Result<Option<MonoObject>, String> {
    Ok(json_handle(&member(obj, name)?).map(owned_object))
}

fn config() -> Result<MonoObject, String> {
    json_handle(&invoke_static(
        "PavonisInteractive.TerraInvicta.TemplateManager",
        "get_global",
        &json!([]),
    )?)
    .map(owned_object)
    .ok_or_else(|| "TemplateManager.global is null".to_string())
}

/// Set both duration values to the game's values times `multiplier`.
fn set_durations(multiplier: i64) -> Result<(), String> {
    let config = config()?;
    for (field, game) in CONFIG_FIELDS.iter().zip(&GAME_VALUES) {
        if game.load(Ordering::Relaxed) < 0 {
            let value = config
                .read_field(field)?
                .as_i64()
                .ok_or_else(|| format!("{field}: not a number"))?;
            game.store(value, Ordering::Relaxed);
        }
        config.write_field(field, &json!(game.load(Ordering::Relaxed) * multiplier))?;
    }
    Ok(())
}

extern "C" fn on_apply_effect(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let mission = owned_object(h);
    if let Err(e) = before(&mission) {
        log(LogLevel::Warn, &format!("terrainvicta-mod: defend interests: {e}"));
    }
    0
}

fn before(mission: &MonoObject) -> Result<(), String> {
    let councilor = member_object(mission, "councilor")?.ok_or("mission has no councilor")?;
    let faction = member_object(&councilor, "faction")?.ok_or("councilor has no faction")?;
    let players = faction.invoke("get_isActivePlayer", &json!([]))?.as_bool() == Some(true);
    set_durations(if players { MULTIPLIER } else { 1 })?;
    if !players {
        return Ok(());
    }
    let target = member_object(mission, "target")?.ok_or("mission has no target")?;
    if target.invoke("get_isHabState", &json!([]))?.as_bool() == Some(true) {
        let hab = member_object(&target, "ref_hab")?.ok_or("target has no hab")?;
        let extra = HAB_GAME_MONTHS * (MULTIPLIER - 1);
        hab.invoke(
            "ResolveDefendHabEffect",
            &json!([{"$handle": faction.handle().0}, extra]),
        )?;
        log(
            LogLevel::Info,
            &format!("terrainvicta-mod: defend interests on a hab: +{extra} months before the game's {HAB_GAME_MONTHS}"),
        );
    } else {
        log(
            LogLevel::Info,
            &format!("terrainvicta-mod: defend interests x{MULTIPLIER} for this mission"),
        );
    }
    Ok(())
}

extern "C" fn after_apply_effect(_ctx: *const c_void) {
    if let Err(e) = set_durations(1) {
        log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: defend interests restore: {e}"),
        );
    }
}
