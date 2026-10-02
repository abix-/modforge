//! Diagnosis log: why each cleaner picks up an item, and how that ends.
//!
//! Why: the search step (`SearchForCleanableMobActionState`) writes its
//! own reason line to Player.log from `FindMisplacedItem` when its
//! `_debugLogging` is on: `[SearchForCleanable:Actions] tiers ->
//! dedicated=... consolidate=... inference=...` (docs/research.md
//! "Cleaner shelving"). A prefix on its `OnEnter` turns that on for
//! every cleaner. That line does not name the cleaner, so a postfix on
//! `FindMisplacedItem` writes the next line: the cleaner and the item
//! it picked.
//!
//! How it ended: a prefix on the item step's
//! (`ProcessItemObjectCleanableMobActionState`) `OnExit`, before it
//! clears its fields, writes the cleaner, the item, the chosen shelf or
//! pallet, the retry count, and whether the item now carries the "no
//! placement" flag (`IsNoPlacementAvailable`: set only when the item
//! step gives up and drops it). Written with `UnityEngine.Debug.Log`,
//! so it lands in Player.log in order with the game's own lines.

use std::collections::BTreeMap;
use std::ffi::{CStr, c_char, c_void};
use std::sync::Mutex;
use std::sync::atomic::{AtomicI64, Ordering};

use serde_json::{Value as Json, json};
use unityforge::hook::{
    HOOK_REGISTRY, HookCtx, patch_postfix_result, patch_prefix_ctx, patch_prefix_instance_args,
};
use unityforge::mono::{
    LogLevel, MonoObject, MonoType, invoke_static, json_handle, log, owned_object, with_object,
};

use crate::ctx_object;

const SEARCH: &str = "Il2CppRuntime.Mob.Actions.SearchForCleanableMobActionState";
const ITEM_STEP: &str = "Il2CppRuntime.Mob.Actions.ProcessItemObjectCleanableMobActionState";
const NAVIGATOR: &str = "Il2CppRuntime.Mob.Navigation.RigidbodyNavigator";
const SHELF: &str = "Il2CppRuntime.Item.Shelving.ShelfObject";

/// Cleaners' navigators by Unity instance id, filled whenever a
/// cleaner searches, so `SetDestination` logs cleaners only.
static CLEANER_NAVS: Mutex<BTreeMap<i64, String>> = Mutex::new(BTreeMap::new());

/// Each cleaner's item step by navigator instance id (a shim handle
/// kept alive here), noted on the step's `OnEnter`, so a bad
/// `SetDestination` can be matched to the step that sent it.
static ITEM_STEPS: Mutex<BTreeMap<i64, i32>> = Mutex::new(BTreeMap::new());

/// Each cleaner's search step, the same way: shutdown switches the
/// game's `_debugLogging` back off on each (see `shutdown`).
static SEARCHES: Mutex<BTreeMap<i64, i32>> = Mutex::new(BTreeMap::new());

/// A destination with x and z both within this of 0 is logged with
/// the item step's fields (Opal was sent to `(0.00, y, 0.00)`).
const ORIGIN_RADIUS: f64 = 1.0;

pub fn install() {
    let results = [
        patch_prefix_ctx(SEARCH, "OnEnter", HookCtx::Instance, on_search_enter),
        patch_postfix_result(SEARCH, "FindMisplacedItem", &json!({}), after_find),
        patch_prefix_ctx(ITEM_STEP, "OnEnter", HookCtx::Instance, on_item_step_enter),
        patch_prefix_ctx(ITEM_STEP, "OnExit", HookCtx::Instance, on_item_step_exit),
        patch_prefix_instance_args(NAVIGATOR, "SetDestination", on_set_destination),
        // Plain parameters and a bool result: safe to patch (no out or
        // ref struct, see docs/research.md "Third capture: Opal").
        patch_postfix_result(SHELF, "TryPlaceShelvable", &json!({}), after_place),
    ];
    for r in results {
        match r {
            Ok(h) => HOOK_REGISTRY.register(h),
            Err(e) => log(LogLevel::Error, &format!("thewalkingtrade-mod: cleaner trace FAILED: {e}")),
        }
    }
    // Order 50: game crates that touch game objects run before the
    // framework's own teardown (modforge/src/shutdown.rs).
    modforge::shutdown::SHUTDOWN_REGISTRY.register(modforge::shutdown::ShutdownHandlerDef {
        name: "twt cleaner_trace: search logging off",
        order: 50,
        run: shutdown,
    });
}

extern "C" fn on_search_enter(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner trace search");
    let Some(search) = ctx_object(ctx) else { return 0 };
    if let Err(e) = search.write_field("_debugLogging", &json!(true)) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: cleaner trace: {e}"));
    }
    keep(&SEARCHES, search);
    0
}

extern "C" fn after_find(
    instance: *const c_void,
    _args: *const c_char,
    result: *const c_char,
    _out: *mut c_char,
    _cap: i32,
) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner trace pick");
    let Some(search) = ctx_object(instance) else { return -1 };
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let result = unsafe { CStr::from_ptr(result) }.to_str().unwrap_or("null");
    let Some(item) = object(&serde_json::from_str(result).unwrap_or(Json::Null)) else {
        return -1;
    };
    let line = pick_line(&search, &item).unwrap_or_else(|e| format!("[twt cleaner trace] pick error: {e}"));
    write(&line);
    // Keep the game's result.
    -1
}

/// The cleaner's navigator (`_mobObject.Navigator`) instance id and
/// the cleaner's name.
fn navigator_of(state: &MonoObject) -> Result<(i64, String), String> {
    let mob = object(&state.read_field("_mobObject")?).ok_or("no mob")?;
    let nav = object(&mob.invoke("get_Navigator", &json!([]))?).ok_or("no navigator")?;
    let id = nav.invoke("GetInstanceID", &json!([]))?.as_i64().ok_or("no instance id")?;
    let name = mob.invoke("get_Name", &json!([]))?;
    Ok((id, name.as_str().unwrap_or("?").to_string()))
}

extern "C" fn on_item_step_enter(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner trace item step enter");
    if let Some(step) = ctx_object(ctx) {
        keep(&ITEM_STEPS, step);
    }
    0
}

/// Keep a cleaner's step in `map` by navigator instance id (the map
/// owns the handle; the one it replaces is released), and note the
/// cleaner's navigator.
fn keep(map: &Mutex<BTreeMap<i64, i32>>, step: MonoObject) {
    let Ok((id, name)) = navigator_of(&step) else { return };
    let handle = step.handle().0;
    std::mem::forget(step);
    if let Ok(mut steps) = map.lock()
        && let Some(old) = steps.insert(id, handle)
        && old != handle
    {
        drop(owned_object(old));
    }
    if let Ok(mut navs) = CLEANER_NAVS.lock() {
        navs.insert(id, name);
    }
}

/// Hot reload or unload: switch the game's search logging back off,
/// so removing this module leaves the searches as the game had them.
/// Runs on the main thread, before the shim clears its handles.
fn shutdown() {
    let searches = SEARCHES.lock().map(|mut s| std::mem::take(&mut *s)).unwrap_or_default();
    for h in searches.into_values() {
        let _ = owned_object(h).write_field("_debugLogging", &json!(false));
    }
}

/// The item step's own fields at the moment it sends a cleaner
/// somewhere wrong.
fn step_fields(step: &MonoObject) -> Result<String, String> {
    let field = |f: &str| step.read_field(f).map(|v| v.to_string()).unwrap_or_else(|e| format!("<{e}>"));
    let name = |f: &str| {
        step.read_field(f)
            .and_then(|v| call(&object(&v), "ToString"))
            .map(|v| v.to_string())
            .unwrap_or_else(|e| format!("<{e}>"))
    };
    let front = object(&step.read_field("_lastChosenTransform")?);
    let front_pos = match &front {
        Some(f) => call(&object(&f.invoke("get_Transform", &json!([]))?), "get_position")?.to_string(),
        None => "-".to_string(),
    };
    Ok(format!(
        "item {}, item zone {}, stripped from foreign shelf {}, place on shelf {}, shelf {}, front {} at {front_pos}, \
         place on pallet {}, pallet {}, retries {}",
        name("_targetItem"),
        field("_itemOriginalZone"),
        field("_strippedFromForeignShelf"),
        field("_shouldPlaceOnShelf"),
        name("_targetShelf"),
        call(&front, "ToString")?,
        field("_shouldPlaceOnPallet"),
        name("_targetPallet"),
        field("_retryCount"),
    ))
}

/// `RigidbodyNavigator.SetDestination(destination, useSamplePosition)`
/// on a cleaner: where to, whether a path was already being worked out,
/// and who asked (managed stack).
extern "C" fn on_set_destination(instance: *const c_void, args: *const c_char) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner trace set destination");
    let Some(nav) = ctx_object(instance) else { return 0 };
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let args = unsafe { CStr::from_ptr(args) }.to_str().unwrap_or("[]");
    let args: Vec<Json> = serde_json::from_str(args).unwrap_or_default();
    // Every object argument is a handle this callback owns.
    let objs: Vec<Option<MonoObject>> = args.iter().map(object).collect();
    let Some(id) = nav.invoke("GetInstanceID", &json!([])).ok().and_then(|v| v.as_i64()) else { return 0 };
    let Some(name) = CLEANER_NAVS.lock().ok().and_then(|n| n.get(&id).cloned()) else { return 0 };
    let line = (|| -> Result<String, String> {
        let dest = call(objs.first().unwrap_or(&None), "ToString")?;
        let mut line = format!(
            "[twt cleaner trace] set destination: {name} to {dest} sample {}, calculating before {}",
            args.get(1).cloned().unwrap_or(Json::Null),
            nav.invoke("get_IsCalculatingPath", &json!([]))?,
        );
        if near_origin(dest.as_str().unwrap_or("")) {
            let step = ITEM_STEPS.lock().ok().and_then(|s| s.get(&id).copied());
            let fields = match step {
                Some(h) => with_object(h, step_fields).unwrap_or_else(|e| format!("<{e}>")),
                None => "no item step noted".to_string(),
            };
            line.push_str(&format!("; NEAR ORIGIN, item step: {fields}"));
        }
        Ok(line)
    })()
    .unwrap_or_else(|e| format!("[twt cleaner trace] set destination error: {e}"));
    write(&line);
    0
}

/// `"(x, y, z)"` with x and z both within `ORIGIN_RADIUS` of 0.
fn near_origin(v: &str) -> bool {
    let n: Vec<f64> = v
        .trim_matches(|c| c == '(' || c == ')')
        .split(',')
        .filter_map(|t| t.trim().parse().ok())
        .collect();
    n.len() == 3 && n[0].abs() < ORIGIN_RADIUS && n[2].abs() < ORIGIN_RADIUS
}

/// Item last counted by `shelf_filters`, so one item is counted once.
static LAST_FILTERED: AtomicI64 = AtomicI64::new(0);

/// The item step's own shelf loop (`MoveToMostAppropriatePosition`,
/// steps 899-1059) over every shelf, counted filter by filter in its
/// order: `AcceptsItem(item data)`, `CanFitItem(_shelvableComponent)`,
/// the shelf has its own item, not in `_failedTargets`, that item's zone
/// Inside (0) or Warehouse (3).
fn shelf_filters(step: &MonoObject) -> Result<Option<String>, String> {
    let item = object(&step.read_field("_targetItem")?).ok_or("no item")?;
    let id = item.invoke("GetInstanceID", &json!([]))?.as_i64().unwrap_or(0);
    if LAST_FILTERED.swap(id, Ordering::Relaxed) == id {
        return Ok(None);
    }
    let data = object(&item.invoke("get_Data", &json!([]))?).ok_or("no item data")?;
    let sv = object(&step.read_field("_shelvableComponent")?);
    let failed = object(&step.read_field("_failedTargets")?);
    let mgr = MonoType::find("Il2CppRuntime.Stage.StageManager")
        .and_then(|t| t.singleton_instance())
        .ok_or("no StageManager")?;
    let model = object(&mgr.read_field("_Model_k__BackingField")?).ok_or("no StageModel")?;
    let shelves = object(&model.read_field("_Shelves_k__BackingField")?).ok_or("no Shelves")?;
    let en = object(&shelves.invoke("GetEnumerator", &json!([]))?).ok_or("no enumerator")?;
    let [mut total, mut accepts, mut fits, mut own, mut not_failed, mut zone] = [0; 6];
    let mut fit_names = Vec::new();
    while en.invoke("MoveNext", &json!([]))?.as_bool() == Some(true) {
        let Some(shelf) = object(&en.invoke("get_Current", &json!([]))?) else { continue };
        total += 1;
        let Some(cfg) = object(&shelf.read_field("_stockingConfig")?) else { continue };
        if cfg.invoke("AcceptsItem", &json!([{"$handle": data.handle().0}]))?.as_bool() != Some(true) {
            continue;
        }
        accepts += 1;
        let Some(s) = &sv else { continue };
        if shelf.invoke("CanFitItem", &json!([{"$handle": s.handle().0}]))?.as_bool() != Some(true) {
            continue;
        }
        fits += 1;
        fit_names.push(shelf.invoke("ToString", &json!([]))?.as_str().unwrap_or("?").to_string());
        let Some(own_item) = object(&shelf.read_field("_itemObject")?) else { continue };
        own += 1;
        if let Some(f) = &failed
            && f.invoke("Contains", &json!([{"$handle": shelf.handle().0}]))?.as_bool() == Some(true)
        {
            continue;
        }
        not_failed += 1;
        if matches!(own_item.invoke("get_CurrentWorldZone", &json!([]))?.as_i64(), Some(0 | 3)) {
            zone += 1;
        }
    }
    Ok(Some(format!(
        "[twt cleaner trace] shelf filters for {} #{id}: shelvable {}, failed targets {}; shelves {total}, \
         accept {accepts}, +fit {fits}, +own item {own}, +not failed {not_failed}, +zone ok {zone}; fit: [{}]",
        item.invoke("ToString", &json!([]))?,
        if sv.is_some() { "set" } else { "NULL" },
        call(&failed, "get_Count")?,
        fit_names.join(", "),
    )))
}

/// `ShelfObject.TryPlaceShelvable(so, viewTransform, isInstant)`: the
/// shelf, the item, the result, and on a failure whether `CanFitItem`
/// still says the item fits (the search and the item step both trust
/// `CanFitItem`).
extern "C" fn after_place(
    instance: *const c_void,
    args: *const c_char,
    result: *const c_char,
    _out: *mut c_char,
    _cap: i32,
) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner trace place");
    let Some(shelf) = ctx_object(instance) else { return -1 };
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let (args, result) = unsafe { (CStr::from_ptr(args), CStr::from_ptr(result)) };
    let args: Vec<Json> = serde_json::from_str(args.to_str().unwrap_or("[]")).unwrap_or_default();
    // Every object argument is a handle this callback owns.
    let objs: Vec<Option<MonoObject>> = args.iter().map(object).collect();
    let placed = result.to_str().unwrap_or("?");
    let line = (|| -> Result<String, String> {
        let so = objs.first().unwrap_or(&None);
        let fits = match (placed, so) {
            ("false", Some(s)) => shelf.invoke("CanFitItem", &json!([{"$handle": s.handle().0}]))?.to_string(),
            _ => "-".to_string(),
        };
        Ok(format!(
            "[twt cleaner trace] place: {} on {} -> {placed}, CanFitItem after {fits}",
            call(so, "ToString")?,
            shelf.invoke("ToString", &json!([]))?,
        ))
    })()
    .unwrap_or_else(|e| format!("[twt cleaner trace] place error: {e}"));
    write(&line);
    -1
}

extern "C" fn on_item_step_exit(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner trace item step");
    let Some(step) = ctx_object(ctx) else { return 0 };
    let line = describe(&step).unwrap_or_else(|e| format!("[twt cleaner trace] error: {e}"));
    write(&line);
    if line.ends_with("dropped with no place true") {
        match shelf_filters(&step) {
            Ok(Some(l)) => write(&l),
            Ok(None) => {}
            Err(e) => write(&format!("[twt cleaner trace] shelf filters error: {e}")),
        }
    }
    0
}

fn write(line: &str) {
    if let Err(e) = invoke_static("UnityEngine.Debug", "Log", &json!([line])) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: cleaner trace: Debug.Log: {e}; line: {line}"));
    }
}

/// The object in a field or result value, owned (released on drop).
fn object(value: &Json) -> Option<MonoObject> {
    json_handle(value).map(owned_object)
}

/// `method` on an object, or "-" when there is none.
fn call(obj: &Option<MonoObject>, method: &str) -> Result<Json, String> {
    match obj {
        Some(o) => o.invoke(method, &json!([])),
        None => Ok(json!("-")),
    }
}

/// The cleaner doing a step: `_mobObject`'s name.
fn cleaner_of(state: &MonoObject) -> Result<Json, String> {
    call(&object(&state.read_field("_mobObject")?), "get_Name")
}

/// Item name and instance id, the id matching pick and end lines.
fn item_of(item: &MonoObject) -> Result<String, String> {
    Ok(format!("{} #{}", item.invoke("ToString", &json!([]))?, item.invoke("GetInstanceID", &json!([]))?))
}

fn pick_line(search: &MonoObject, item: &MonoObject) -> Result<String, String> {
    Ok(format!("[twt cleaner trace] pick: {} item {}", cleaner_of(search)?, item_of(item)?))
}

fn describe(step: &MonoObject) -> Result<String, String> {
    let cleaner = cleaner_of(step)?;
    let Some(item_obj) = object(&step.read_field("_targetItem")?) else {
        return Ok(format!("[twt cleaner trace] end: {cleaner} with no item"));
    };
    let dropped = item_obj.invoke("get_IsNoPlacementAvailable", &json!([]))?;
    let item = item_of(&item_obj)?;
    let shelf = call(&object(&step.read_field("_targetShelf")?), "ToString")?;
    let pallet = call(&object(&step.read_field("_targetPallet")?), "ToString")?;
    Ok(format!(
        "[twt cleaner trace] end: {cleaner} item {item} from zone {}: shelf {shelf}, pallet {pallet}, \
         retries {}, dropped with no place {dropped}",
        step.read_field("_itemOriginalZone")?,
        step.read_field("_retryCount")?,
    ))
}
