//! Reflection-discovery snapshot: one GObjects pass produces a
//! cached view of every live `UDataTable`, `UClass`, and
//! `UScriptStruct` in the game. The mod runs this at load and
//! every consumer (debug ops, ImGui browser, future TweakDef
//! resolution) reads from the cache.
//!
//! ```text
//! K8s slot: Def=DiscoverySnapshot (singleton; no kinds — carve-out
//!                                  like Settings),
//!           Registry=n/a,
//!           Instance=cached Arc<DiscoverySnapshot>,
//!           Controller=run_at_load / refresh
//! ```
//!
//! Why in-memory, not files on disk:
//!
//! - **DRY.** The HTTP `discover_*` ops + the ImGui browser tab
//!   read from the same cache. The walk runs ONCE per refresh.
//! - **Always current.** A game patch that shifts an offset is
//!   reflected the next time anything reads from the cache; no
//!   stale-JSON-on-disk class of bug.
//! - **Cheap on hot reload.** Mod reload doesn't have to clean up
//!   files; the cache disappears with the DLL.
//!
//! If you want a file, redirect a curl: `curl ... > dump.json`.
//!
//! ## Usage
//!
//! ```ignore
//! // From the game crate's on_unreal_init worker, after
//! // ue::platform::detect_and_init:
//! let _ = ueforge::discovery::run_at_load();
//! // logs e.g. "discovery: 412 data_tables, 28341 classes, 1893 structs"
//! ```
//!
//! ## Re-walking
//!
//! GObjects grows as content streams in (level loads, save loads,
//! level transitions). Call [`refresh`] (or hit any `discover_*`
//! op with `{refresh: true}`) to re-walk; the new snapshot
//! replaces the old in the cache atomically.

use std::sync::{Arc, OnceLock};

use parking_lot::RwLock;
use serde_json::{Value as Json, json};

use crate::ue::{self, UClass, UObject};

/// One snapshot of the game's reflection state. Created by [`walk`],
/// stored in the global cache by [`run_at_load`] / [`refresh`].
pub struct DiscoverySnapshot {
    pub data_tables: Json,
    pub classes: Json,
    pub structs: Json,
}

static CACHE: OnceLock<RwLock<Option<Arc<DiscoverySnapshot>>>> = OnceLock::new();

fn cell() -> &'static RwLock<Option<Arc<DiscoverySnapshot>>> {
    CACHE.get_or_init(|| RwLock::new(None))
}

/// Currently cached snapshot, if [`run_at_load`] / [`refresh`] has
/// run at least once.
pub fn cached() -> Option<Arc<DiscoverySnapshot>> {
    cell().read().clone()
}

/// Walk GObjects once, populate the cache, log a one-line summary.
/// Returns the new snapshot for the caller (typically discarded).
pub fn run_at_load() -> Arc<DiscoverySnapshot> {
    let snap = Arc::new(walk());
    *cell().write() = Some(snap.clone());
    crate::log::log(format_args!(
        "discovery: {} data_tables, {} classes, {} structs",
        snap.data_tables["tables_found"].as_u64().unwrap_or(0),
        snap.classes["classes_found"].as_u64().unwrap_or(0),
        snap.structs["structs_found"].as_u64().unwrap_or(0),
    ));
    snap
}

/// Re-walk and replace the cache. Same as [`run_at_load`] today;
/// kept distinct so future versions can diff against the prior
/// snapshot for "what new content loaded" reporting.
pub fn refresh() -> Arc<DiscoverySnapshot> {
    run_at_load()
}

/// JSON view: every live `UDataTable` + row schema. Refresh-on-demand
/// for op handlers. If the cache is cold, walks now. `name_filter`
/// restricts the result to a single entry by exact short name (the
/// table's UE short name); pass `None` for the full dump.
pub fn data_tables_json(refresh_first: bool, name_filter: Option<&str>) -> Json {
    let snap = snapshot(refresh_first);
    match name_filter {
        None => snap.data_tables.clone(),
        Some(name) => filter_named(&snap.data_tables, "data_tables", "table_name", name),
    }
}

/// JSON view: every `UClass` + native property list + function list.
pub fn classes_json(refresh_first: bool, name_filter: Option<&str>) -> Json {
    let snap = snapshot(refresh_first);
    match name_filter {
        None => snap.classes.clone(),
        Some(name) => filter_named(&snap.classes, "classes", "name", name),
    }
}

/// JSON view: every `UScriptStruct` + field list.
pub fn structs_json(refresh_first: bool, name_filter: Option<&str>) -> Json {
    let snap = snapshot(refresh_first);
    match name_filter {
        None => snap.structs.clone(),
        Some(name) => filter_named(&snap.structs, "structs", "name", name),
    }
}

/// Wrap one entry from a discovery section back in the section's
/// envelope (same shape minus the count fields, plus a `match`
/// pointer to the located entry).
fn filter_named(section: &Json, array_key: &str, name_key: &str, target: &str) -> Json {
    let empty = Vec::new();
    let arr = section
        .get(array_key)
        .and_then(|v| v.as_array())
        .unwrap_or(&empty);
    let found = arr
        .iter()
        .find(|e| e.get(name_key).and_then(|v| v.as_str()) == Some(target));
    match found {
        Some(e) => json!({
            "match": e.clone(),
            "filter": target,
        }),
        None => json!({
            "match": null,
            "filter": target,
            "error": format!("{} '{}' not in discovery cache", name_key, target),
        }),
    }
}

fn snapshot(refresh_first: bool) -> Arc<DiscoverySnapshot> {
    if refresh_first {
        return refresh();
    }
    if let Some(s) = cached() {
        return s;
    }
    run_at_load()
}

fn walk() -> DiscoverySnapshot {
    let Some(rt) = ue::try_runtime() else {
        return error_snap("ueforge: ue runtime not initialized");
    };
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return error_snap("gobjects view invalid");
    }
    let dt_class = ue::find_class_fast("DataTable");

    let mut data_tables: Vec<Json> = Vec::new();
    let mut classes: Vec<Json> = Vec::new();
    let mut structs: Vec<Json> = Vec::new();
    let mut scanned = 0usize;
    let mut panicked = 0usize;

    for obj in view.iter() {
        scanned += 1;
        // Catch Rust panics emitted during per-object describe
        // (FName resolution, name walks, etc.). Does NOT catch
        // SEH access violations -- those are blocked at the
        // pointer-read site via `winproc::is_addr_readable`.
        let res = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
            let Some(cls) = obj.class() else { return };
            let cls_name = cls.as_object().name();

            if let Some(dt) = dt_class {
                if obj.is_a(dt) && !obj.is_default_object() {
                    data_tables.push(crate::ue::probe::describe_data_table(obj));
                }
            }

            if cls_name == "Class" {
                let uclass: &UClass = unsafe { &*(obj as *const UObject as *const UClass) };
                classes.push(describe_class(uclass));
            } else if cls_name == "ScriptStruct" {
                structs.push(describe_script_struct(obj));
            }
        }));
        if res.is_err() {
            panicked += 1;
        }
    }
    if panicked > 0 {
        crate::log::log(format_args!(
            "discovery: {panicked} per-object panics caught (objects skipped)"
        ));
    }

    let data_tables_found = data_tables.len();
    let classes_found = classes.len();
    let structs_found = structs.len();

    DiscoverySnapshot {
        data_tables: json!({
            "data_tables": data_tables,
            "scanned_objects": scanned,
            "tables_found": data_tables_found,
        }),
        classes: json!({
            "classes": classes,
            "scanned_objects": scanned,
            "classes_found": classes_found,
        }),
        structs: json!({
            "structs": structs,
            "scanned_objects": scanned,
            "structs_found": structs_found,
        }),
    }
}

fn describe_class(cls: &UClass) -> Json {
    let obj = cls.as_object();
    let props = cls.cached_native_properties();
    let fields: Vec<Json> = props
        .iter()
        .map(|p| {
            json!({
                "name": p.name,
                "offset": p.offset,
                "element_size": p.element_size,
            })
        })
        .collect();
    let functions: Vec<Json> = cls
        .iter_functions()
        .into_iter()
        .map(|(name, flags)| {
            json!({
                "name": name,
                "function_flags": format!("0x{:08x}", flags),
            })
        })
        .collect();
    let super_name = cls.super_class().map(|s| s.as_object().name());
    json!({
        "name": obj.name(),
        "full_path": obj.full_name(),
        "super": super_name,
        "properties_size": cls.properties_size(),
        "fields": fields,
        "functions": functions,
    })
}

fn describe_script_struct(obj: &UObject) -> Json {
    let fields = crate::ue::probe::walk_struct_fields(obj);
    json!({
        "name": obj.name(),
        "full_path": obj.full_name(),
        "fields": fields,
    })
}

fn error_snap(msg: &str) -> DiscoverySnapshot {
    DiscoverySnapshot {
        data_tables: json!({"error": msg}),
        classes: json!({"error": msg}),
        structs: json!({"error": msg}),
    }
}
