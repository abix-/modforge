//! Generic op handlers. Each takes the JSON `args` blob from a
//! request and returns the JSON `result` blob (or an error string).
//! Snapshot building, the envelope, and the dispatch match arm
//! belong to the embedding crate.
//!
//! Selector-resolving ops accept a closure so the game's
//! game-specific selectors plug in. The convention:
//!
//! ```ignore
//! fn resolve(s: &str) -> Result<&'static UObject, String> {
//!     if let Some(r) = ueforge::selector::resolve_generic(s) {
//!         return r;
//!     }
//!     match s {
//!         "live_player" => ...,
//!         _ => Err(...),
//!     }
//! }
//!
//! match op {
//!     "read_bytes" => ueforge::ops::read_bytes(&args, resolve),
//!     ...
//! }
//! ```

use std::ffi::c_void;

use parking_lot::Mutex;
use serde_json::Value as Json;

use crate::args::{arg_str, arg_u64};
use crate::ue::{self, UObject, fname::FName};

// =====================================================================
// Op registry. The workspace-standard <Subject>Def + <Subject>Registry
// shape for debug ops. Per architecture.md, every dispatch lookup goes
// through ONE registry instead of three hardcoded match statements.
//
// K8s slot: Def=OpDef, Registry=OpRegistry (OP_REGISTRY singleton),
//           Instance=per-call (args, result), Controller=OpRegistry::dispatch
//
// Like hooks, OpDefs are populated imperatively at init time (each
// handler is a closure capturing the per-game tracker / pe_queue /
// selector resolver). The registry surface is the same as every
// other subject; the contents are produced at runtime.
// =====================================================================

pub type OpHandler = std::sync::Arc<dyn Fn(&Json) -> Result<Json, String> + Send + Sync>;

/// One debug-op declaration. The handler is a closure (boxed to
/// erase per-game capture types. Tracker references, selector
/// resolvers, PE queue handles).
pub struct OpDef {
    pub name: &'static str,
    pub summary: &'static str,
    /// Human-readable args spec for the auto-generated `list_ops`
    /// response. Free-form: `"{slot: str, count?: u32}"`. Empty
    /// string for ops with no args.
    pub args: &'static str,
    pub handler: OpHandler,
}

impl OpDef {
    /// Convenience constructor.
    pub fn new<F>(
        name: &'static str,
        summary: &'static str,
        args: &'static str,
        handler: F,
    ) -> Self
    where
        F: Fn(&Json) -> Result<Json, String> + Send + Sync + 'static,
    {
        Self {
            name,
            summary,
            args,
            handler: std::sync::Arc::new(handler),
        }
    }
}

/// The workspace-standard `<Subject>Registry` for debug ops.
/// Populated at init time via [`Self::register`]; dispatch is one
/// linear scan (registries hold ~20 ops, lookups are once per
/// HTTP request, so the scan cost is invisible).
pub struct OpRegistry {
    entries: Mutex<Vec<OpDef>>,
}

impl OpRegistry {
    pub const fn new() -> Self {
        Self {
            entries: Mutex::new(Vec::new()),
        }
    }

    /// Register one op. Callers (the framework's `register_builtins`
    /// + each game crate's worker init) push their declarations
    /// once at startup.
    pub fn register(&self, def: OpDef) {
        self.entries.lock().push(def);
    }

    /// Register a batch of ops in one shot.
    pub fn register_many<I: IntoIterator<Item = OpDef>>(&self, defs: I) {
        let mut g = self.entries.lock();
        for d in defs {
            g.push(d);
        }
    }

    /// Look up + invoke. Returns `None` if the op isn't registered
    /// (caller fall through to "unknown op" error).
    ///
    /// The handler runs OUTSIDE the registry mutex. The lock
    /// only protects the lookup. This matters for two reasons:
    /// (1) slow handlers (discovery refresh, GObjects walks)
    /// don't serialize the entire HTTP surface; (2) a handler
    /// that crashes the worker via SEH would otherwise poison
    /// the parking_lot mutex forever, hanging every subsequent
    /// request.
    pub fn dispatch(&self, name: &str, args: &Json) -> Option<Result<Json, String>> {
        let handler = {
            let g = self.entries.lock();
            g.iter().find(|o| o.name == name)?.handler.clone()
        };
        let started = std::time::Instant::now();
        let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| handler(args)));
        let elapsed_ns = started.elapsed().as_nanos() as u64;
        record_op_latency(name, elapsed_ns, matches!(result, Ok(Ok(_))));
        Some(match result {
            Ok(r) => r,
            Err(_) => Err(format!("handler '{name}' panicked")),
        })
    }

    /// Names of every registered op. For "supported ops: [...]"
    /// error messages.
    pub fn names(&self) -> Vec<&'static str> {
        self.entries.lock().iter().map(|o| o.name).collect()
    }

    /// Count of registered ops.
    pub fn len(&self) -> usize {
        self.entries.lock().len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.lock().is_empty()
    }

    /// Auto-generated `list_ops` payload: `{ ops: [{ name, summary,
    /// args }, ...] }`. The framework registers a `list_ops` op
    /// that returns this; clients use it for discovery.
    pub fn list_json(&self) -> Json {
        let g = self.entries.lock();
        serde_json::json!({
            "ops": g.iter().map(|o| serde_json::json!({
                "name": o.name,
                "summary": o.summary,
                "args": o.args,
            })).collect::<Vec<_>>()
        })
    }
}

impl Default for OpRegistry {
    fn default() -> Self {
        Self::new()
    }
}

/// Process-wide debug-op registry singleton. Game crates push
/// their ops here at worker init; the HTTP `handle()` calls
/// `OP_REGISTRY.dispatch(op, args)` for every request.
pub static OP_REGISTRY: OpRegistry = OpRegistry::new();

// ---- Per-op latency metrics --------------------------------------------
//
// `dispatch` records `(calls, errors, total_ns, max_ns)` per op
// name. Hot-path-safe (atomic adds in a HashMap behind a Mutex;
// reasonable for HTTP-dispatched ops which are cold relative to
// the trampoline). `tweak_metrics_*` ops would surface this if
// wanted; for now `op_metrics` returns the full snapshot.

#[derive(Default, Debug, Clone)]
struct OpMetrics {
    calls: u64,
    errors: u64,
    total_ns: u64,
    max_ns: u64,
}

static METRICS: std::sync::OnceLock<Mutex<std::collections::HashMap<String, OpMetrics>>> =
    std::sync::OnceLock::new();

fn metrics_map() -> &'static Mutex<std::collections::HashMap<String, OpMetrics>> {
    METRICS.get_or_init(|| Mutex::new(std::collections::HashMap::with_capacity(64)))
}

fn record_op_latency(name: &str, elapsed_ns: u64, ok: bool) {
    let mut g = metrics_map().lock();
    let e = g.entry(name.to_string()).or_default();
    e.calls = e.calls.saturating_add(1);
    if !ok {
        e.errors = e.errors.saturating_add(1);
    }
    e.total_ns = e.total_ns.saturating_add(elapsed_ns);
    if elapsed_ns > e.max_ns {
        e.max_ns = elapsed_ns;
    }
}

/// JSON snapshot of every recorded op's metrics. Sorted by
/// total_ns descending so the slow ones surface first.
pub fn metrics_json() -> Json {
    let g = metrics_map().lock();
    let mut items: Vec<(String, OpMetrics)> =
        g.iter().map(|(k, v)| (k.clone(), v.clone())).collect();
    items.sort_by(|a, b| b.1.total_ns.cmp(&a.1.total_ns));
    let entries: Vec<Json> = items
        .into_iter()
        .map(|(name, m)| {
            let avg_ns = if m.calls > 0 { m.total_ns / m.calls } else { 0 };
            serde_json::json!({
                "name": name,
                "calls": m.calls,
                "errors": m.errors,
                "total_ns": m.total_ns,
                "max_ns": m.max_ns,
                "avg_ns": avg_ns,
            })
        })
        .collect();
    serde_json::json!({ "ops": entries })
}

/// Register every framework-shipped op that does NOT need
/// per-game context (no tracker, no selector resolver, no PE
/// queue). Game crates call this once at worker init. Typically
/// before their own per-game `OP_REGISTRY.register(...)` calls.
///
/// Registered: `walk_class`, `fname_to_string`, `inspect_address`,
/// `class_outer_samples`, `sample_thread_modules`, scanner ops
/// (`scan_memory` / `scan_rescan` / `scan_session` / `scan_close`,
/// `freeze` / `unfreeze` / `freeze_list`), and `list_ops` itself.
///
/// Per-game ops with captured context (rpg `skill_*`, `call`,
/// `read_bytes`, `write_bytes`, sim ops) are registered by the
/// game crate, not here.
pub fn register_builtins() {
    // Phase 0b: scanner moved to modforge but its freeze op
    // resolves selectors against the engine. Install ueforge's
    // UObject + selector resolver into modforge::scanner before
    // any scanner op fires. Idempotent.
    crate::scanner::install_ue_resolver();

    OP_REGISTRY.register_many([
        OpDef::new(
            "walk_class",
            "Walk a UClass property chain and return the named fields",
            "{class: str}",
            |args| walk_class(args),
        ),
        OpDef::new(
            "fname_to_string",
            "Resolve an FName u64 to its string form",
            "{fname: u64}",
            |args| fname_to_string(args),
        ),
        OpDef::new(
            "inspect_address",
            "Describe the UObject at an address (class + properties + values)",
            "{addr: hex}",
            |args| inspect_address(args),
        ),
        OpDef::new(
            "class_outer_samples",
            "Sample up to k UObjects under class and return their outers",
            "{class: str, k?: u64}",
            |args| {
                let class_name = arg_str(args, "class")?;
                let k = arg_u64(args, "k", Some(20))? as usize;
                Ok(crate::ue::probe::class_outer_samples(class_name, k))
            },
        ),
        OpDef::new(
            "sample_thread_modules",
            "Sample which DLL each thread is executing in over a duration",
            "{duration_ms?: u64, interval_ms?: u64}",
            |args| {
                let duration_ms = arg_u64(args, "duration_ms", Some(30_000))? as u32;
                let interval_ms = arg_u64(args, "interval_ms", Some(100))? as u32;
                Ok(crate::winproc::sample_thread_modules_json(
                    duration_ms,
                    interval_ms,
                ))
            },
        ),
        // Scanner. Cheat-Engine-style memory search + freezes.
        OpDef::new(
            "scan_memory",
            "First-scan: find all addresses holding `value` of `type`",
            "{type: str, value: any}",
            |args| crate::scanner::scan_memory(args),
        ),
        OpDef::new(
            "scan_rescan",
            "Narrow a session by re-reading current values",
            "{session_id: u64, mode: str, value?: any, delta?: any}",
            |args| crate::scanner::scan_rescan(args),
        ),
        OpDef::new(
            "scan_session",
            "Paginate over a scan session's surviving addresses",
            "{session_id: u64, max?: u64, offset?: u64}",
            |args| crate::scanner::scan_session(args),
        ),
        OpDef::new(
            "scan_close",
            "Drop a scan session's state",
            "{session_id: u64}",
            |args| crate::scanner::scan_close(args),
        ),
        OpDef::new(
            "scan_cancel",
            "Abort the in-flight scan_memory / scan_rescan (chunk-boundary check)",
            "{}",
            |args| crate::scanner::scan_cancel(args),
        ),
        OpDef::new(
            "freeze",
            "Hold a value at addr/selector at hz Hz (re-resolves on staleness)",
            "{selector?: str, addr?: hex, offset?: u64, type: str, value: any, hz?: u32}",
            |args| crate::scanner::freeze(args),
        ),
        OpDef::new(
            "unfreeze",
            "Stop a freeze",
            "{addr: hex}",
            |args| crate::scanner::unfreeze(args),
        ),
        OpDef::new(
            "freeze_list",
            "Show every active freeze",
            "{}",
            |args| crate::scanner::freeze_list(args),
        ),
        OpDef::new(
            "discover_data_tables",
            "Every live UDataTable's row schema (cached; pass refresh=true; name= filters to one)",
            "{refresh?: bool, name?: str}",
            |args| {
                let refresh = args.get("refresh").and_then(|v| v.as_bool()).unwrap_or(false);
                let name = args.get("name").and_then(|v| v.as_str());
                Ok(crate::discovery::data_tables_json(refresh, name))
            },
        ),
        OpDef::new(
            "discover_classes",
            "Every UClass + native properties + functions (cached; pass refresh=true; name= filters to one)",
            "{refresh?: bool, name?: str}",
            |args| {
                let refresh = args.get("refresh").and_then(|v| v.as_bool()).unwrap_or(false);
                let name = args.get("name").and_then(|v| v.as_str());
                Ok(crate::discovery::classes_json(refresh, name))
            },
        ),
        OpDef::new(
            "discover_class_detail",
            "Walk one UClass's properties + functions on demand (safe from eager-walk crash)",
            "{name: str}",
            |args| {
                let name = arg_str(args, "name")?;
                Ok(crate::discovery::class_detail_json(name))
            },
        ),
        OpDef::new(
            "discover_struct_detail",
            "Walk one UScriptStruct's fields on demand",
            "{name: str}",
            |args| {
                let name = arg_str(args, "name")?;
                Ok(crate::discovery::struct_detail_json(name))
            },
        ),
        OpDef::new(
            "discover_structs",
            "Every UScriptStruct + field list (cached; pass refresh=true; name= filters to one)",
            "{refresh?: bool, name?: str}",
            |args| {
                let refresh = args.get("refresh").and_then(|v| v.as_bool()).unwrap_or(false);
                let name = args.get("name").and_then(|v| v.as_str());
                Ok(crate::discovery::structs_json(refresh, name))
            },
        ),
        OpDef::new(
            "dump_data_table",
            "Snapshot every row of a UDataTable, decoded per FProperty class",
            "{table_name: str, max_rows?: u64}",
            |args| {
                let table_name = arg_str(args, "table_name")?;
                let max_rows = args.get("max_rows").and_then(|v| v.as_u64()).map(|n| n as usize);
                crate::data_table::snapshot_table(table_name, max_rows)
                    .ok_or_else(|| format!("table '{table_name}' not loaded or has no RowStruct"))
            },
        ),
        OpDef::new(
            "list_data_tables",
            "Enumerate the registered DataTableRegistry \
             (statically-declared catalog; for the runtime-discovered \
             universe use discover_data_tables)",
            "{}",
            |_args| Ok(crate::data_table::list_json()),
        ),
        OpDef::new(
            "tweak_apply",
            "Apply a runtime-declared tweak: captures vanilla per row \
             on first apply, then writes `set` / `multiply` / `add` of \
             the configured value. Re-applies are idempotent (always \
             re-base on captured vanilla).",
            "{table: str, field: str, kind: \"i32\"|\"f32\"|\"u32\", op: \"set\"|\"multiply\"|\"add\", value: number}",
            |args| crate::data_table::tweak_apply_from_args(args),
        ),
        OpDef::new(
            "tweak_list",
            "Every dynamic tweak currently registered across the i32 / \
             f32 / u32 primitive registries. Each entry reports the \
             captured vanilla_count.",
            "{}",
            |_args| Ok(crate::data_table::dynamic_list_json()),
        ),
        OpDef::new(
            "tweak_revert",
            "Revert one specific (table, field) dynamic tweak, OR all \
             of them when args are empty. Removes the matching entry \
             (or all entries) from <DLL_dir>/tweaks.json so the revert \
             survives Ctrl+R. Returns total rows reverted.",
            "{table?: str, field?: str}",
            |args| {
                let table = args.get("table").and_then(|v| v.as_str());
                let field = args.get("field").and_then(|v| v.as_str());
                let (touched, persisted_removed): (usize, usize) = match (table, field) {
                    (Some(t), Some(f)) => {
                        let rows = crate::data_table::dynamic_revert_one(t, f);
                        let removed = crate::data_table::forget_persisted_pub(t, f)
                            .map_err(|e| format!("tweak_revert: persistence: {e}"))?;
                        (rows, if removed { 1 } else { 0 })
                    }
                    (None, None) => {
                        let rows = crate::data_table::dynamic_revert_all();
                        let removed = crate::data_table::forget_persisted_all_pub()
                            .map_err(|e| format!("tweak_revert: persistence: {e}"))?;
                        (rows, removed)
                    }
                    _ => {
                        return Err(
                            "tweak_revert: pass both `table` and `field`, or neither (revert all)"
                                .to_string(),
                        );
                    }
                };
                Ok(serde_json::json!({
                    "rows_reverted": touched,
                    "persisted_removed": persisted_removed,
                }))
            },
        ),
        OpDef::new(
            "tweak_persisted_list",
            "Snapshot of <DLL_dir>/tweaks.json (the on-disk record of \
             every tweak_apply that succeeded). Re-applied at every \
             mod init.",
            "{}",
            |_args| Ok(crate::data_table::persisted_list_json()),
        ),
        OpDef::new(
            "tweak_persisted_load",
            "Re-read <DLL_dir>/tweaks.json into memory. Use after \
             hand-editing the file. Does NOT re-apply; call \
             tweak_persisted_reapply for that.",
            "{}",
            |_args| Ok(crate::data_table::load_persisted_from_disk()),
        ),
        OpDef::new(
            "tweak_persisted_reapply",
            "Re-apply every persisted tweak from the in-memory mirror. \
             Calls discovery before resolving each field. Returns a \
             per-entry status report.",
            "{}",
            |_args| Ok(crate::data_table::reapply_persisted()),
        ),
        OpDef::new(
            "list_ops",
            "Auto-generated catalog of every registered debug op",
            "{}",
            |_args| Ok(OP_REGISTRY.list_json()),
        ),
        OpDef::new(
            "op_metrics",
            "Per-op latency metrics: calls / errors / total_ns / max_ns / avg_ns (sorted by total_ns)",
            "{}",
            |_args| Ok(crate::ops::metrics_json()),
        ),
        OpDef::new(
            "resolve_offsets",
            "Run patternsleuth's UE resolvers (GUObjectArray + FNamePool + \
             FNameToString) against the host image. Returns image-relative \
             offsets + side-by-side comparison against the configured \
             hardcoded PlatformOffsets so you can verify drift without \
             rebuilding.",
            "{}",
            |args| crate::ue::resolvers::resolve_offsets_op(args),
        ),
        OpDef::new(
            "list_selectors",
            "Auto-generated catalog of every registered selector kind",
            "{}",
            |_args| Ok(crate::selector::SELECTOR_REGISTRY.list_json()),
        ),
    ]);
}

/// Register the resolver-needing ueforge ops. Each game crate
/// supplies its own selector resolver (typically wraps
/// [`crate::selector::resolve_generic`] with extra game names like
/// `live_player:`); the closure captures it.
///
/// Registers: `read_bytes`, `write_bytes`. (Selector-form `freeze`
/// already accepts a resolver internally via the selector module's
/// `resolve_generic` + game's chained dispatch, so it goes through
/// `register_builtins`.)
pub fn register_with_resolver<R>(resolver: R)
where
    R: Fn(&str) -> Result<&'static UObject, String> + Copy + Send + Sync + 'static,
{
    OP_REGISTRY.register_many([
        OpDef::new(
            "read_bytes",
            "Read N bytes from a selector + offset",
            "{selector: str, offset?: u64, length: u64}",
            move |args| read_bytes(args, resolver),
        ),
        OpDef::new(
            "write_bytes",
            "Write hex bytes to a selector + offset",
            "{selector: str, offset?: u64, hex: str}",
            move |args| write_bytes(args, resolver),
        ),
    ]);
}

/// Cap on `read_bytes` length / `write_bytes` payload (1 MiB).
/// Sized to comfortably cover any UE struct walk while preventing
/// pathological reads from hanging the listener.
pub const BYTE_OP_CAP: usize = 0x10_0000;

/// When the resolved object's class is known, clamp
/// `offset + length` to `class.properties_size()`. Returns
/// `Err` if the range falls completely outside the class extent.
/// Returns `Ok(())` (no clamp) if the class has no usable size.
/// most likely on raw `addr:0x...` selectors that bypass class
/// resolution.
fn check_object_bounds(obj: &UObject, offset: usize, length: usize) -> Result<(), String> {
    let Some(class) = obj.class() else { return Ok(()) };
    let size = class.properties_size() as usize;
    if size == 0 || size > 0x100_0000 {
        return Ok(());
    }
    let end = offset.checked_add(length).ok_or_else(|| {
        format!("offset 0x{offset:X} + length 0x{length:X} overflows")
    })?;
    if end > size {
        return Err(format!(
            "offset 0x{offset:X} + length 0x{length:X} = 0x{end:X} \
             exceeds instance size 0x{size:X}"
        ));
    }
    Ok(())
}

pub fn read_bytes<F>(args: &Json, resolve: F) -> Result<Json, String>
where
    F: FnOnce(&str) -> Result<&'static UObject, String>,
{
    let selector = arg_str(args, "instance_selector")?.to_string();
    let offset = arg_u64(args, "offset", Some(0))? as usize;
    let length = arg_u64(args, "length", None)? as usize;
    if length > BYTE_OP_CAP {
        return Err(format!("length {length} > 1MB cap"));
    }
    let obj = resolve(&selector)?;
    check_object_bounds(obj, offset, length)?;
    let mut out = vec![0u8; length];
    // SAFETY: check_object_bounds verified `[offset, offset+length)`
    // lies within `obj`'s allocation; copy_nonoverlapping reads
    // `length` bytes from that region into the freshly-allocated
    // `out` vector (non-overlapping because `out` is a new alloc).
    unsafe {
        let base = obj.field_ptr(offset);
        std::ptr::copy_nonoverlapping(base, out.as_mut_ptr(), length);
    }
    Ok(serde_json::json!({
        "selector": selector,
        "offset": format!("0x{offset:X}"),
        "length": length,
        "bytes_hex": hex::encode(&out),
    }))
}

pub fn write_bytes<F>(args: &Json, resolve: F) -> Result<Json, String>
where
    F: FnOnce(&str) -> Result<&'static UObject, String>,
{
    let selector = arg_str(args, "instance_selector")?.to_string();
    let offset = arg_u64(args, "offset", Some(0))? as usize;
    let bytes = hex::decode(arg_str(args, "bytes_hex")?)
        .map_err(|e| format!("bad hex: {e}"))?;
    if bytes.len() > BYTE_OP_CAP {
        return Err(format!("bytes len {} > 1MB cap", bytes.len()));
    }
    let obj = resolve(&selector)?;
    check_object_bounds(obj, offset, bytes.len())?;
    // SAFETY: check_object_bounds verified the write range fits;
    // bytes is a Vec<u8> from the parsed hex input; the
    // destination is owned by `obj`. copy_nonoverlapping
    // semantics: source and destination don't alias (bytes
    // came from a separate heap allocation).
    unsafe {
        let dst = obj.field_ptr(offset) as *mut u8;
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), dst, bytes.len());
    }
    Ok(serde_json::json!({
        "selector": selector,
        "offset": format!("0x{offset:X}"),
        "wrote_bytes": bytes.len(),
    }))
}

/// Walk `GObjects`, return up to `max` non-CDO instances of the
/// named class (CDOs included if `include_cdo: true`). Pure
/// engine traversal. No host hooks needed.
pub fn walk_class(args: &Json) -> Result<Json, String> {
    let class_name = arg_str(args, "class")?.to_string();
    let max = arg_u64(args, "max", Some(256))? as usize;
    let include_cdo = args
        .get("include_cdo")
        .and_then(Json::as_bool)
        .unwrap_or(false);

    let rt = ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    let class = ue::find_class_fast(&class_name)
        .ok_or_else(|| format!("class '{class_name}' not found"))?;
    // SAFETY: rt was returned by try_runtime(), which is set
    // once by detect_and_init from DllMain-adjacent code; the
    // image_base + offsets pair is what runtime init validated.
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return Err("gobjects view invalid".to_string());
    }

    let mut hits = Vec::with_capacity(max);
    let mut total = 0usize;
    for obj in view.iter() {
        if !obj.is_a(class) {
            continue;
        }
        if !include_cdo && obj.is_default_object() {
            continue;
        }
        total += 1;
        if hits.len() >= max {
            continue;
        }
        let addr = obj as *const UObject as usize;
        hits.push(serde_json::json!({
            "addr": format!("0x{addr:X}"),
            "addr_selector": format!("addr:0x{addr:X}"),
            "name": obj.name(),
            "full_name": obj.full_name(),
            "is_cdo": obj.is_default_object(),
        }));
    }
    Ok(serde_json::json!({
        "class": class_name,
        "total": total,
        "returned": hits.len(),
        "instances": hits,
    }))
}

/// Resolve an FName (passed as a u64. The 8 bytes that make up
/// `{ comparison_index: i32, number: u32 }`) to its display
/// string. Useful from tests that walk TMap<FName, ...> bytes
/// and need to show readable keys instead of raw u64s.
///
/// Args: `{ "fname": <u64> }` (decimal or 0x-prefixed hex via JSON).
/// Result: `{ "string": "<name>" }`.
pub fn fname_to_string(args: &Json) -> Result<Json, String> {
    let raw = arg_u64(args, "fname", None)?;
    // SAFETY: FName is an 8-byte { comparison_index: i32,
    // number: u32 } struct; transmute_copy from a u64 with the
    // same little-endian byte layout is well-defined.
    let fname: FName = unsafe { std::mem::transmute_copy(&raw) };
    let rt = ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    // SAFETY: rt.name_resolver is initialized at runtime detect;
    // to_string accepts any FName (including ones whose
    // comparison_index is out of range. It returns a fallback
    // string rather than panicking).
    let s = unsafe { rt.name_resolver.to_string(fname) };
    Ok(serde_json::json!({ "string": s }))
}

/// Walk a class's property chain. Including the super-class
/// chain. Looking for the field that contains
/// `offset_within_instance`. Returns the field's name + the
/// offset-within-the-field (so callers can render
/// `MaxCanStack +0` for an exact hit, or `Colour +0xC` if the
/// target is mid-struct).
fn locate_property(
    class: &UObject,
    offset_in_instance: u32,
) -> Option<(String, u32, u32)> {
    // SAFETY: caller passes a UObject that IS a UClass instance
    // (resolved via find_class_fast); UClass extends UObject in
    // memory layout so the cast is well-defined.
    let mut cur: Option<&ue::UClass> = Some(unsafe {
        &*(class as *const UObject as *const ue::UClass)
    });
    let mut chain_depth = 0;
    while let Some(c) = cur {
        if chain_depth > 16 {
            break;
        }
        // Use the cached property list. Subsequent calls on the
        // same class share an Arc instead of re-walking + re-resolving
        // FName for every property.
        for p in c.cached_native_properties().iter() {
            if offset_in_instance >= p.offset
                && offset_in_instance < p.offset + p.element_size.max(1)
            {
                return Some((p.name.clone(), p.offset, p.element_size));
            }
        }
        cur = c.super_class();
        chain_depth += 1;
    }
    None
}

/// Given a raw memory address, find the UObject (if any) that
/// contains it. Walks GObjects, computes each object's
/// `[base, base + class.properties_size)` range, returns the
/// first match.
///
/// Args: `{ "addr": "0x<hex>" }`.
///
/// Result on hit:
/// ```json
/// {
///   "found": true,
///   "addr": "0x...",
///   "instance_addr": "0x...",
///   "class": "DataTable",
///   "instance_name": "DT_Materials",
///   "instance_full_name": "DataTable /Game/Data/DT_Materials...",
///   "offset_in_instance": "0x48",
///   "instance_size": 624
/// }
/// ```
///
/// On miss: `{ "found": false, "addr": "0x..." }`. Misses are
/// expected for raw allocator buffers, save blobs, and other
/// non-UObject memory the scanner finds.
pub fn inspect_address(args: &Json) -> Result<Json, String> {
    let addr_str = arg_str(args, "addr")?;
    let target = parse_addr(addr_str)?;

    let rt = ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    // SAFETY: rt was returned by try_runtime(), which is set
    // once by detect_and_init from DllMain-adjacent code; the
    // image_base + offsets pair is what runtime init validated.
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return Err("gobjects view invalid".into());
    }

    for obj in view.iter() {
        let base = obj as *const UObject as usize;
        let Some(class) = obj.class() else { continue };
        let size = class.properties_size() as usize;
        if size == 0 || size > 0x100_0000 {
            continue; // sanity: skip absurd sizes
        }
        if target >= base && target < base + size {
            let off = (target - base) as u32;
            let mut result = serde_json::json!({
                "found": true,
                "addr": format!("0x{target:X}"),
                "instance_addr": format!("0x{base:X}"),
                "instance_addr_selector": format!("addr:0x{base:X}"),
                "class": class.as_object().name(),
                "instance_name": obj.name(),
                "instance_full_name": obj.full_name(),
                "offset_in_instance": format!("0x{off:X}"),
                "instance_size": size,
            });
            // Try to name the field via property walk.
            if let Some((name, field_off, field_size)) =
                locate_property(class.as_object(), off)
            {
                let into_field = off - field_off;
                result["field"] = serde_json::json!(name);
                result["field_offset"] = serde_json::json!(format!("0x{field_off:X}"));
                result["field_size"] = serde_json::json!(field_size);
                if into_field > 0 {
                    result["field_inner_offset"] =
                        serde_json::json!(format!("+0x{into_field:X}"));
                }
            }
            return Ok(result);
        }
    }
    Ok(serde_json::json!({
        "found": false,
        "addr": format!("0x{target:X}"),
        "note": "address not within any UObject (raw allocator memory, save blob, or non-UObject struct)",
    }))
}

fn parse_addr(s: &str) -> Result<usize, String> {
    let hex = s
        .strip_prefix("0x")
        .or_else(|| s.strip_prefix("0X"))
        .unwrap_or(s);
    usize::from_str_radix(hex, 16).map_err(|e| format!("bad address '{s}': {e}"))
}

/// Engine portion of the `call` op: resolve the UFunction by
/// `(class_name, function_name)`, invoke `process_event` against
/// `instance` with the given parm bytes (mutated in place by UE
/// for OUT params), and return the post-call buffer as hex.
///
/// Must be called from the game thread. Game-side op handler
/// resolves the instance selector itself (it may be game-specific)
/// and enqueues a closure that calls this on the host's PE queue.
pub fn exec_call(
    instance: &UObject,
    class_name: &str,
    function_name: &str,
    mut parms: Vec<u8>,
) -> Result<Json, String> {
    let class = ue::find_class_fast(class_name)
        .ok_or_else(|| format!("class '{class_name}' not found"))?;
    let func = class.get_function(class_name, function_name).ok_or_else(|| {
        format!("function '{function_name}' not found on '{class_name}'")
    })?;
    // SAFETY: `instance` is a live UObject; `func` is its
    // UFunction returned by get_function (also live in
    // GObjects); `parms.as_mut_ptr()` points at a Vec<u8> buffer
    // owned by this fn for the duration of the call. The engine
    // reads from + writes into the buffer per the UFunction's
    // parm layout (caller is responsible for sizing parms
    // correctly via the framework's parm_size helpers).
    unsafe {
        instance.process_event(func, parms.as_mut_ptr() as *mut c_void);
    }
    Ok(serde_json::json!({
        "parms_hex_after": hex::encode(&parms),
    }))
}
