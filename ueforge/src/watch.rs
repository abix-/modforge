//! Watch functions as they are called: `hook.watch {class, function}`
//! installs one ProcessEvent hook on the class (kept for the life of the
//! DLL) and records every call of the named functions on it: the object,
//! the function, its parameters decoded by their types, and when. The
//! reading tool for "does the game call X on her, and with what": no
//! bytecode decoding, no guessing. `hook.log` returns the recent calls.
use crate::hook::process_event::ProcessEventHook;
use crate::reflect;
use crate::ue::{UFunction, UObject};
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::collections::{BTreeMap, BTreeSet, VecDeque};
use std::time::Instant;

struct Watched {
    _hook: ProcessEventHook,
    /// Function names to record; empty records every function on the class.
    functions: BTreeSet<String>,
}

static WATCHED: Mutex<BTreeMap<String, Watched>> = Mutex::new(BTreeMap::new());
static FILTERS: Mutex<BTreeMap<String, BTreeSet<String>>> = Mutex::new(BTreeMap::new());
static LOG: Mutex<VecDeque<Value>> = Mutex::new(VecDeque::new());
static STARTED: Mutex<Option<Instant>> = Mutex::new(None);
const LOG_CAPACITY: usize = 512;

fn record(this: &UObject, function: &UFunction, parms: *mut std::ffi::c_void, class_name: &str) {
    let name = function.as_object().name();
    let wanted = FILTERS.lock().get(class_name).map(|f| f.is_empty() || f.contains(&name)).unwrap_or(false);
    if !wanted { return; }
    let started = *STARTED.lock().get_or_insert_with(Instant::now);
    let mut params = serde_json::Map::new();
    if !parms.is_null() {
        for property in function.iter_parameters() {
            let kind = reflect::property_type(&property).unwrap_or_default();
            // SAFETY: the engine's parameter block for this call, laid out by the function.
            params.insert(property.name.clone(), unsafe { reflect::read_value(parms as *const u8, &property, &kind) });
        }
    }
    let entry = json!({"t_ms": started.elapsed().as_millis() as u64, "object": this.name(), "class": this.class().map(|c| c.as_object().name()).unwrap_or_default(), "function": name, "params": params});
    let mut log = LOG.lock();
    if log.len() >= LOG_CAPACITY { log.pop_front(); }
    log.push_back(entry);
}

/// Watch `function` (or every function when empty) on `class`. The hook
/// on a class is installed once and kept; later calls only change the
/// function filter.
pub fn watch(class: &str, function: Option<&str>) -> Result<Value, String> {
    let mut filters = FILTERS.lock();
    let filter = filters.entry(class.to_owned()).or_default();
    if let Some(function) = function { filter.insert(function.to_owned()); } else { filter.clear(); }
    let functions = filter.clone();
    drop(filters);
    let mut watched = WATCHED.lock();
    if let Some(existing) = watched.get_mut(class) { existing.functions = functions.clone(); return Ok(json!({"class": class, "functions": functions, "state": "filter_updated"})); }
    let leaked: &'static str = Box::leak(class.to_owned().into_boxed_str());
    let hook = ProcessEventHook::install(leaked, move |this, function, parms, original| {
        // SAFETY: the engine's own call, forwarded unchanged after recording.
        unsafe { original.call(this, function, parms) };
        record(this, function, parms, leaked);
    }).map_err(|e| format!("hook on {class}: {e}"))?;
    watched.insert(class.to_owned(), Watched { _hook: hook, functions: functions.clone() });
    Ok(json!({"class": class, "functions": functions, "state": "installed"}))
}

/// Stop recording a class (the hook stays installed, recording nothing).
pub fn unwatch(class: &str) -> bool {
    FILTERS.lock().remove(class).is_some()
}

pub fn register_ops() {
    use crate::ops::{OP_REGISTRY, OpDef};
    OP_REGISTRY.register_many([
        OpDef::new("hook.watch", "Record every call of a function on a class (or every function when none given): object, parameters decoded by type, time", "{class: str, function?: str}", |args| {
            let class = args["class"].as_str().filter(|s| !s.is_empty()).ok_or("class is required")?;
            watch(class, args["function"].as_str().filter(|s| !s.is_empty()))
        }),
        OpDef::new("hook.unwatch", "Stop recording a class's functions", "{class: str}", |args| {
            let class = args["class"].as_str().filter(|s| !s.is_empty()).ok_or("class is required")?;
            Ok(json!({"class": class, "stopped": unwatch(class)}))
        }),
        OpDef::new("hook.log", "The recent recorded calls, oldest first; clear=true empties the log after reading", "{clear?: bool, limit?: u64}", |args| {
            let limit = args["limit"].as_u64().unwrap_or(200) as usize;
            let mut log = LOG.lock();
            let calls: Vec<Value> = log.iter().rev().take(limit).cloned().collect::<Vec<_>>().into_iter().rev().collect();
            if args["clear"].as_bool().unwrap_or(false) { log.clear(); }
            Ok(json!({"count": calls.len(), "calls": calls, "watching": FILTERS.lock().clone()}))
        }),
    ]);
}
