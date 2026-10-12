//! Run defaults: every run starts with these tomes and stats.
//!
//! | Tome         | Stat          | Value          |
//! |--------------|---------------|----------------|
//! | Luck (13)    | Luck (30)     | 5.0 (500%)     |
//! | Blood (18)   | Lifesteal (17)| 1.0 (100%)     |
//!
//! Found 2026-10-03 (tests/research_luck_write.rs, tome_add.rs,
//! luck_add.rs, luck_math.rs):
//! - `TomeInventory.AddTome(TomeData, List<StatModifier> upgradeOffer,
//!   ERarity)` gives the tome but applies nothing from the upgrade list
//!   (luck base stayed 0.0 after it)
//! - a stat's parts are `PlayerStatsNew.statValuesMap[stat]`; final luck
//!   is base x additive, a fresh run's luck parts are base 0, additive
//!   1.0, and one Flat (EStatModifyType 2) modifier through
//!   `StatInventory.ChangeStat` sets the base: Flat 5.0 read luck 5.0
//!
//! During a run, on the main thread (the shim's Update), every
//! `CHECK_SECONDS`, for each default: give the tome when missing, and
//! when the stat's base is 0 store one Flat modifier of the value. Once
//! the base is set nothing more is added, so it cannot pile up. The
//! `run_defaults` op reads the table, or sets one value with
//! `{stat, value}` (0 turns that one off).

use std::sync::atomic::{AtomicI64, AtomicU32, Ordering};

use serde_json::{Value as Json, json};
use unityforge::mono::{LogLevel, MonoObject, MonoType, invoke_static, json_handle, log, owned_object};

/// One default: the tome to hold, the stat to set, its value (f32 bits),
/// and the run it was last applied in (the player's Unity instance id).
struct RunDefault {
    name: &'static str,
    tome: i64,
    stat: i64,
    value: AtomicU32,
    applied_in: AtomicI64,
}

static DEFAULTS: [RunDefault; 2] = [
    // 0x40A0_0000 is 5.0: 500% luck.
    RunDefault { name: "luck", tome: 13, stat: 30, value: AtomicU32::new(0x40A0_0000), applied_in: AtomicI64::new(0) },
    // 0x3F80_0000 is 1.0: 100% lifesteal.
    RunDefault { name: "lifesteal", tome: 18, stat: 17, value: AtomicU32::new(0x3F80_0000), applied_in: AtomicI64::new(0) },
];

/// ERarity 1 is Common.
const COMMON: i64 = 1;
/// EStatModifyType 2 is Flat.
const FLAT: i64 = 2;
const CHECK_SECONDS: f32 = 2.0;
const STAT_MODIFIER: &str = "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatModifier, Assembly-CSharp";
const STAT_MODIFIER_LIST: &str = "Il2CppSystem.Collections.Generic.List`1[[Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatModifier, Assembly-CSharp]], Il2Cppmscorlib";

/// When the last check ran (shim time), f32 bits.
static LAST_CHECK: AtomicU32 = AtomicU32::new(0);

fn table() -> Json {
    Json::Array(
        DEFAULTS
            .iter()
            .map(|d| json!({"stat": d.name, "tome": d.tome, "value": f32::from_bits(d.value.load(Ordering::Relaxed))}))
            .collect(),
    )
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register_many([modforge::ops::OpDef::new(
        "run_defaults",
        "Read the run defaults (tome + stat value), or set one with {stat: \"luck\"|\"lifesteal\", value} (0 is off)",
        "{stat?: str, value?: f32}",
        |args| {
            if let (Some(name), Some(v)) = (args.get("stat").and_then(Json::as_str), args.get("value").and_then(Json::as_f64)) {
                let d = DEFAULTS.iter().find(|d| d.name == name).ok_or_else(|| format!("no run default '{name}'"))?;
                d.value.store((v as f32).to_bits(), Ordering::Relaxed);
            }
            Ok(json!({"defaults": table()}))
        },
    )]);
}

/// Called every frame from the shim's Update (main thread).
pub fn tick(now: f32) {
    if now - f32::from_bits(LAST_CHECK.load(Ordering::Relaxed)) < CHECK_SECONDS {
        return;
    }
    LAST_CHECK.store(now.to_bits(), Ordering::Relaxed);
    if let Err(e) = apply() {
        log(LogLevel::Warn, &format!("megabonk-mod: run defaults: {e}"));
    }
}

fn object(value: Json) -> Option<MonoObject> {
    json_handle(&value).map(owned_object)
}

fn apply() -> Result<(), String> {
    // Outside a run there is no player: nothing to do.
    let Some(gm) = object(invoke_static("Il2Cpp.GameManager", "get_Instance", &json!([]))?) else {
        return Ok(());
    };
    let Some(player) = object(gm.invoke("get_player", &json!([]))?) else {
        return Ok(());
    };
    let inv = object(player.invoke("get_inventory", &json!([]))?).ok_or("no inventory")?;
    let tomes = object(inv.invoke("get_tomeInventory", &json!([]))?).ok_or("no tomeInventory")?;
    let stats = object(inv.invoke("get_playerStats", &json!([]))?).ok_or("no playerStats")?;
    let map = object(stats.invoke("get_statValuesMap", &json!([]))?).ok_or("no statValuesMap")?;
    let stat_inv = object(inv.invoke("get_statInventory", &json!([]))?).ok_or("no statInventory")?;
    // A new run makes a new player, so its instance id marks the run.
    let run = player.invoke("GetInstanceID", &json!([]))?.as_i64().ok_or("no player instance id")?;

    for d in &DEFAULTS {
        let value = f64::from(f32::from_bits(d.value.load(Ordering::Relaxed)));
        if value <= 0.0 {
            continue;
        }
        if tomes.invoke("HasTome", &json!([d.tome]))?.as_bool() != Some(true) {
            give_tome(&tomes, d.tome)?;
            log(LogLevel::Info, &format!("megabonk-mod: gave the {} tome", d.name));
        }
        // Once per run: top the base up to the value. The game may
        // already have given some (lifesteal base read 0.189 from the
        // Blood tome, 2026-10-03), so add only the difference; once
        // per run, a late-applying change cannot be added twice.
        if d.applied_in.load(Ordering::Relaxed) == run {
            continue;
        }
        let parts = object(map.invoke("get_Item", &json!([d.stat]))?).ok_or("no stat parts")?;
        let base = parts.read_field("_baseValue_k__BackingField")?.as_f64().unwrap_or(0.0);
        if base < value {
            let modifier = stat_modifier(d.stat, value - base)?;
            stat_inv.invoke("ChangeStat", &json!([{"$handle": modifier.handle().0}, true, 0.0, false]))?;
            log(LogLevel::Info, &format!("megabonk-mod: set {} {value} (base was {base})", d.name));
        }
        d.applied_in.store(run, Ordering::Relaxed);
    }
    Ok(())
}

/// A Flat StatModifier of `value` on `stat`.
fn stat_modifier(stat: i64, value: f64) -> Result<MonoObject, String> {
    let modifier = object(invoke_static("System.Activator", "CreateInstance", &json!([STAT_MODIFIER]))?)
        .ok_or("could not make a StatModifier")?;
    modifier.write_field("stat", &json!(stat))?;
    modifier.write_field("modification", &json!(value))?;
    modifier.write_field("modifyType", &json!(FLAT))?;
    Ok(modifier)
}

/// `AddTome` with the game's TomeData for `tome`, an empty upgrade list
/// and Common, as tests/tome_add.rs did. The TomeData assets come from
/// the shim's instance walk (a type name passed to
/// Resources.FindObjectsOfTypeAll does not convert to an
/// Il2CppSystem.Type, 2026-10-03).
fn give_tome(tomes: &MonoObject, tome: i64) -> Result<(), String> {
    let ty = MonoType::find("TomeData").ok_or("TomeData type not found")?;
    let walked = ty.walk(true)?;
    let list = walked.get("instances").and_then(Json::as_array).or_else(|| walked.as_array()).cloned().unwrap_or_default();
    let mut found = None;
    for v in &list {
        let Some(t) = object(v.clone()) else { continue };
        if found.is_none() && t.read_field("eTome")?.as_i64() == Some(tome) {
            found = Some(t);
        }
    }
    let data = found.ok_or_else(|| format!("no TomeData for tome {tome}"))?;
    let offer = object(invoke_static("System.Activator", "CreateInstance", &json!([STAT_MODIFIER_LIST]))?)
        .ok_or("could not make an upgrade list")?;
    tomes.invoke("AddTome", &json!([{"$handle": data.handle().0}, {"$handle": offer.handle().0}, COMMON]))?;
    Ok(())
}
