//! Pockets: the hobo's carry size, Character.capacity.value (the
//! game's base is 16). Enabled by default at POCKETS_DEFAULT; the
//! size is set through the op. Disabled puts back the game's value
//! seen before the first write.
//!
//! TODO(abix): apply once when a save loads. Which game method sets
//! Pockets on load is not yet measured; until then only the op
//! applies it.

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use std::sync::atomic::{AtomicBool, AtomicU32, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, MonoType, log};

const POCKETS_DEFAULT: f32 = 220.0;

static ENABLED: AtomicBool = AtomicBool::new(true);
static SIZE: AtomicU32 = AtomicU32::new(POCKETS_DEFAULT.to_bits());
/// The game's own value, seen before the mod wrote. NaN until seen.
static GAME_SIZE: AtomicU32 = AtomicU32::new(f32::NAN.to_bits());

fn load(a: &AtomicU32) -> f32 {
    f32::from_bits(a.load(Ordering::Acquire))
}

fn store(a: &AtomicU32, v: f32) {
    a.store(v.to_bits(), Ordering::Release);
}

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "pockets",
        "Read or set the hobo's Pockets (carry size). Enabled by default at 220. Pass no args to read",
        "{enabled?: bool, size?: float}",
        op,
    ));
}

/// The capacity stat of the player, or None outside a loaded save.
fn capacity() -> Result<Option<MonoObject>, String> {
    let ty = MonoType::find("Il2CppGame.Character")
        .ok_or("type Il2CppGame.Character not found")?;
    let list = ty.walk(true)?;
    let instances = list
        .get("instances")
        .and_then(Json::as_array)
        .or_else(|| list.as_array())
        .cloned()
        .unwrap_or_default();
    let mut owned: Vec<MonoObject> = instances
        .iter()
        .filter_map(|v| v.get("handle").and_then(Json::as_i64))
        .map(|h| MonoObject::from_owned_handle(MonoHandle(h as i32)))
        .collect();
    if owned.is_empty() {
        return Ok(None);
    }
    let ch = owned.swap_remove(0);
    let cap = ch.read_field("capacity")?;
    let h = cap
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or_else(|| format!("capacity read as {cap}"))?;
    Ok(Some(MonoObject::from_owned_handle(MonoHandle(h as i32))))
}

fn read_value(cap: &MonoObject) -> Result<f32, String> {
    let v = cap.read_field("value")?;
    v.as_f64()
        .map(|n| n as f32)
        .ok_or_else(|| format!("capacity.value read as {v}"))
}

/// Writes `size` when it differs. Returns the value read back, or
/// None outside a loaded save.
fn apply(size: f32) -> Result<Option<f32>, String> {
    let Some(cap) = capacity()? else {
        return Ok(None);
    };
    let cur = read_value(&cap)?;
    if cur == size {
        return Ok(Some(cur));
    }
    if load(&GAME_SIZE).is_nan() {
        store(&GAME_SIZE, cur);
    }
    cap.write_field("value", &json!(size))?;
    let after = read_value(&cap)?;
    log(LogLevel::Info, &format!("pockets: {cur} -> {after}"));
    Ok(Some(after))
}

fn op(args: &Json) -> Result<Json, String> {
    let set_on = args.get("enabled").and_then(Json::as_bool);
    let set_size = args.get("size").and_then(Json::as_f64).map(|v| v as f32);
    if let Some(s) = set_size
        && !(s >= 1.0)
    {
        return Err(format!("size must be at least 1, got {s}"));
    }
    MAIN_QUEUE.run(
        "pockets",
        std::time::Duration::from_secs(2),
        move || -> Result<Json, String> {
            if let Some(s) = set_size {
                store(&SIZE, s);
            }
            if let Some(on) = set_on {
                ENABLED.store(on, Ordering::Release);
            }
            let game = load(&GAME_SIZE);
            let pockets = if ENABLED.load(Ordering::Acquire) {
                apply(load(&SIZE))?
            } else if set_on == Some(false) && !game.is_nan() {
                apply(game)?
            } else {
                match capacity()? {
                    Some(cap) => Some(read_value(&cap)?),
                    None => None,
                }
            };
            Ok(json!({
                "enabled": ENABLED.load(Ordering::Acquire),
                "size": load(&SIZE),
                "pockets": pockets,
                "game_size": if game.is_nan() { Json::Null } else { json!(game) },
            }))
        },
    )?
}
