//! Weapon numbers that get better as the weapon levels up.
//!
//! K8s slot: Def=LevelScaledStatDef, Registry=STATS (bare slice, no
//! registry config), Instance=APPLIED (vanilla + level per row),
//! Controller=tick.
//!
//! The game keeps each weapon's level in the save slot's WeaponLevels
//! map (FS_SaveSlot_C, key the weapon's item data object, value i32) and
//! each weapon's numbers on its FS_WeaponStats asset. Vanilla scales only
//! attack with level (AttackPowerIncreasePerLevel, 0.03 per level). A row
//! here scales one more number by the same rule. Measured by
//! tests/research_weapons.rs weapon_levels_in_save.
//!
//! Nothing is hooked. Every few seconds the level is read from the cached
//! save object (one indexed liveness check and a map of a handful of
//! entries) and the number is written only when the level changed.
//! Objects are searched for only when one is missing, at most every
//! FIND_RETRY. The vanilla number goes back at shutdown, so a hot reload
//! starts from it.

use std::time::{Duration, Instant};

use parking_lot::Mutex;
use ueforge::ue::{ClassRef, UObject, is_live};

/// One weapon number that shrinks as the weapon levels up (a cost or a
/// wait): vanilla / (1 + per_level * (level - 1)).
pub struct LevelScaledStatDef {
    /// The weapon's item data object, the key in the save's WeaponLevels.
    pub item: &'static str,
    /// The weapon's FS_WeaponStats asset.
    pub stats: &'static str,
    /// The f32 field on that asset.
    pub field: &'static str,
    pub per_level: f32,
}

impl LevelScaledStatDef {
    pub fn value_at(&self, vanilla: f32, level: i32) -> f32 {
        vanilla / (1.0 + self.per_level * (level.max(1) - 1) as f32)
    }
}

/// The torch's secondary recharges faster with level, at the game's own
/// 3% per level: 30 s per charge at level 1, 17.4 s at 25, 7.6 s at 100.
pub static STATS: &[LevelScaledStatDef] = &[LevelScaledStatDef {
    item: "Torch_Weapon_Item",
    stats: "Torch_WeaponStats",
    field: "AbilityPointsPerCharge",
    per_level: 0.03,
}];

static SAVE_CLASS: ClassRef = ClassRef::new("FS_SaveSlot_C");
static STATS_CLASS: ClassRef = ClassRef::new("FS_WeaponStats");
const LEVELS_FIELD: &str = "WeaponLevels";
const INTERVAL: Duration = Duration::from_secs(3);
const FIND_RETRY: Duration = Duration::from_secs(30);

#[derive(Clone, Copy)]
struct Save {
    addr: usize,
    levels: usize,
}

#[derive(Clone, Copy)]
struct Applied {
    addr: usize,
    offset: usize,
    vanilla: f32,
    level: i32,
}

struct State {
    save: Option<Save>,
    rows: Vec<Option<Applied>>,
    next_find: Instant,
}

static STATE: Mutex<Option<State>> = Mutex::new(None);
static POLLER: Mutex<Option<modforge::rpg::poller::PollerHandle>> = Mutex::new(None);

pub fn start() {
    *STATE.lock() = Some(State {
        save: None,
        rows: STATS.iter().map(|_| None).collect(),
        next_find: Instant::now(),
    });
    let handle = modforge::rpg::poller::spawn_interval("queensdomain/weapon_level", INTERVAL, || {
        if let Err(e) = modforge::seh::guard(tick) {
            ueforge::log!("weapon_level: tick faulted: {e}");
            if let Some(st) = STATE.lock().as_mut() {
                st.save = None;
            }
        }
    });
    *POLLER.lock() = Some(handle);
    // Order 260: after the poller (250) has stopped.
    modforge::shutdown::SHUTDOWN_REGISTRY
        .record("weapon_level", "restore vanilla".into(), 260, restore)
        .keep();
}

fn tick() {
    let mut guard = STATE.lock();
    let Some(st) = guard.as_mut() else { return };
    let save_live = st.save.is_some_and(|s| is_live(s.addr));
    let rows_live = st.rows.iter().all(|r| r.is_some_and(|a| is_live(a.addr)));
    if !save_live || !rows_live {
        if Instant::now() < st.next_find {
            if !save_live {
                return;
            }
        } else {
            st.next_find = Instant::now() + FIND_RETRY;
            if !save_live {
                st.save = find_save();
                // A new save means a game was loaded: put the fixed
                // changes back once (tweaks.rs walks every object).
                if st.save.is_some() {
                    crate::tweaks::apply_all();
                }
            }
            for (row, slot) in STATS.iter().zip(st.rows.iter_mut()) {
                if !slot.is_some_and(|a| is_live(a.addr)) {
                    *slot = find_stats(row);
                }
            }
        }
    }
    let Some(save) = st.save else { return };
    // SAFETY: checked live above; the poller is the only writer of these fields.
    let save_obj = unsafe { &*(save.addr as *const UObject) };
    for (row, slot) in STATS.iter().zip(st.rows.iter_mut()) {
        let Some(applied) = slot.as_mut() else { continue };
        let Some(level) = read_level(save_obj, save.levels, row.item) else { continue };
        if level == applied.level {
            continue;
        }
        let value = row.value_at(applied.vanilla, level);
        // SAFETY: the stats asset is live and offset is its reflected f32 field.
        unsafe { (*(applied.addr as *const UObject)).write_field(applied.offset, value) };
        ueforge::log!(
            "weapon_level: {} level {level}, {} {} -> {value}",
            row.item,
            row.field,
            applied.vanilla
        );
        applied.level = level;
    }
}

fn find_save() -> Option<Save> {
    let obj = SAVE_CLASS.find_instance(|_| true)?;
    let levels = field_offset(obj, LEVELS_FIELD)?;
    ueforge::log!("weapon_level: save {} at {:#x}", obj.name(), obj.as_ptr() as usize);
    Some(Save {
        addr: obj.as_ptr() as usize,
        levels,
    })
}

fn find_stats(row: &LevelScaledStatDef) -> Option<Applied> {
    let obj = STATS_CLASS.find_instance(|o| o.name() == row.stats)?;
    let offset = field_offset(obj, row.field)?;
    // SAFETY: a reflected f32 field of a live object.
    let vanilla: f32 = unsafe { obj.read_field(offset) };
    ueforge::log!("weapon_level: {} {} vanilla {vanilla}", row.stats, row.field);
    Some(Applied {
        addr: obj.as_ptr() as usize,
        offset,
        vanilla,
        level: 0,
    })
}

fn field_offset(obj: &UObject, name: &str) -> Option<usize> {
    ueforge::reflect::fields_of(obj)
        .into_iter()
        .find(|(p, _)| p.name == name)
        .map(|(p, _)| p.offset as usize)
}

/// The level the save holds for `item`. Free map slots hold free-list
/// links, not object pointers, so a key is named only when readable.
fn read_level(save: &UObject, levels: usize, item: &str) -> Option<i32> {
    // SAFETY: `levels` is the reflected WeaponLevels TMap<object, i32> of a live save.
    unsafe { ueforge::ue::tmap::scalar_entries::<u64, i32>(save, levels) }.find_map(|e| {
        let key = e.key() as usize;
        if key == 0 || !modforge::winproc::is_addr_readable(key + 0x20) {
            return None;
        }
        // SAFETY: readable object header.
        let name = unsafe { &*(key as *const UObject) }.name();
        (name == item).then(|| e.value())
    })
}

/// The watcher's steps one at a time, read only, for
/// tests/research_weapons.rs weapon_level_steps. Each step is logged
/// before it runs, so if one takes the game down the log's last line
/// names it.
pub fn register_ops() {
    ueforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "weapon_level_step",
        "run one step of the weapon level watcher, read only",
        "{step: class|save|stats|level}",
        |args| {
            let step = args.get("step").and_then(|v| v.as_str()).unwrap_or("").to_string();
            ueforge::log!("weapon_level_step {step}: start");
            let out = modforge::seh::guard(|| run_step(&step)).map_err(|e| format!("{step} faulted: {e}"))?;
            ueforge::log!("weapon_level_step {step}: done {out:?}");
            out
        },
    ));
}

fn run_step(step: &str) -> Result<serde_json::Value, String> {
    let row = &STATS[0];
    match step {
        "class" => Ok(serde_json::json!({
            "save_class": SAVE_CLASS.get().is_some(),
            "stats_class": STATS_CLASS.get().is_some(),
        })),
        "save" => {
            let s = find_save().ok_or("no save")?;
            Ok(serde_json::json!({"addr": s.addr, "levels": s.levels, "live": is_live(s.addr)}))
        }
        "stats" => {
            let a = find_stats(row).ok_or("no stats asset")?;
            Ok(serde_json::json!({"addr": a.addr, "offset": a.offset, "vanilla": a.vanilla, "live": is_live(a.addr)}))
        }
        "level" => {
            let s = find_save().ok_or("no save")?;
            // SAFETY: found live this call.
            let obj = unsafe { &*(s.addr as *const UObject) };
            Ok(serde_json::json!({"level": read_level(obj, s.levels, row.item)}))
        }
        _ => Err(format!("unknown step {step}")),
    }
}

fn restore() {
    let Some(st) = STATE.lock().take() else { return };
    for (row, applied) in STATS.iter().zip(st.rows) {
        let Some(a) = applied else { continue };
        if a.level == 0 || !is_live(a.addr) {
            continue;
        }
        // SAFETY: live stats asset, reflected f32 field.
        unsafe { (*(a.addr as *const UObject)).write_field(a.offset, a.vanilla) };
        ueforge::log!("weapon_level: {} {} restored to {}", row.stats, row.field, a.vanilla);
    }
}
