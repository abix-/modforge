//! Data-table catalog framework. One of ueforge's opinionated UE5
//! mod modules (rpg / stacks / difficulty / inventory / damage /
//! data_table).
//!
//! ```text
//! K8s slot: Def=DataTableDef, Registry=DataTableRegistry,
//!           Instance=live UDataTable + its RowMap rows,
//!           Controller=DataTableSnapshot::capture +
//!                      probe::discover_data_tables
//! ```
//!
//! Stacks + difficulty + status effects are all special cases of
//! "typed-field operations on iterated objects". The tables
//! themselves (`UDataTable` + row schema) are their own first-class
//! concept: a stable id + the UE short name of the data-table + the
//! row-struct schema (field name -> offset -> element size).
//!
//! Phase 1 (this module) is a READ-only browser surface: declare
//! known tables statically, snapshot rows on demand, render in
//! ImGui. Writes are deferred to a later phase that unifies stack +
//! difficulty + future field tweaks behind a single TweakDef.
//!
//! ```ignore
//! use ueforge::data_table::{DataTableDef, DataTableRegistry, RowField, RowSchema};
//!
//! static DT_MATERIALS: DataTableDef = DataTableDef {
//!     id: "materials",
//!     table_name: "DT_Materials",
//!     row_struct: RowSchema {
//!         name: "FMaterialRow",
//!         fields: &[
//!             RowField { name: "MaxCanStack", offset: 0x48, element_size: 4 },
//!         ],
//!     },
//! };
//!
//! pub static DATA_TABLES: DataTableRegistry =
//!     DataTableRegistry::new(&[&DT_MATERIALS]);
//! ```

/// One field on a data-table row struct: the property's name, its
/// byte offset within a row, and the size of one element. Mirrors
/// [`crate::ue::NativeProperty`] (the runtime form for UClasses);
/// kept as its own type because data-table schemas are typically
/// hand-declared static catalog data, while `NativeProperty` is
/// produced by walking the live FField chain.
#[derive(Debug, Clone, Copy)]
pub struct RowField {
    pub name: &'static str,
    pub offset: usize,
    pub element_size: u32,
}

/// Schema of a data-table row struct: the UE `UScriptStruct` short
/// name + the field list. Static-catalog form; the discovery path
/// (`probe::discover_data_tables`) emits the same shape as JSON.
#[derive(Debug, Clone, Copy)]
pub struct RowSchema {
    pub name: &'static str,
    pub fields: &'static [RowField],
}

/// One data-table the mod knows about: a stable id, the UE short
/// name to resolve via `datatable::find_by_short_name`, and the row
/// schema. Pure data; no runtime state.
pub struct DataTableDef {
    /// Stable id for [`DataTableRegistry::def`] lookup. Lowercase
    /// snake_case by convention (`"materials"`, `"status_effects"`).
    pub id: &'static str,
    /// UE short name of the `UDataTable` instance, resolved at
    /// snapshot time via
    /// [`crate::ue::datatable::find_by_short_name`].
    pub table_name: &'static str,
    /// Row-struct schema. Field offsets are decoded from the SDK
    /// headers; cross-checked at runtime against discovery in
    /// Phase 1e.
    pub row_struct: RowSchema,
}

/// Workspace-standard `<Subject>Registry` for data tables. Stores
/// `&[&'static DataTableDef]` (slice of refs) so consumers can
/// declare each Def as its own named static + inline the registry
/// literal. Mirrors `StackRegistry` / `StatusRegistry`.
pub struct DataTableRegistry {
    entries: &'static [&'static DataTableDef],
}

impl DataTableRegistry {
    pub const fn new(entries: &'static [&'static DataTableDef]) -> Self {
        Self { entries }
    }

    /// Canonical lookup. O(N) linear scan; registries are tiny.
    pub fn def(&self, id: &str) -> Option<&'static DataTableDef> {
        for d in self.entries {
            if d.id == id {
                return Some(*d);
            }
        }
        None
    }

    pub fn entries(&self) -> &'static [&'static DataTableDef] {
        self.entries
    }

    pub fn iter(&self) -> std::slice::Iter<'_, &'static DataTableDef> {
        self.entries.iter()
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }
}

impl<'a> IntoIterator for &'a DataTableRegistry {
    type Item = &'static DataTableDef;
    type IntoIter = std::iter::Copied<std::slice::Iter<'a, &'static DataTableDef>>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter().copied()
    }
}

// ---- Snapshot (Phase 1b) -------------------------------------------------

use std::sync::OnceLock;

use serde_json::{Value as Json, json};

use crate::ue::{self, UObject};

// ---- Name-based tweaks ---------------------------------------------------

/// Look up `field_name` on the row struct of `table_name` in the
/// in-memory discovery cache. Returns `(offset, element_size, FProperty class)`.
///
/// Cheap (HashMap-like linear scan over the cached table list).
/// `None` if the table isn't in the cache or the field isn't on
/// its row struct -- callers should re-call after
/// `discovery::refresh()` if content streamed in late.
pub fn resolve_field(table_name: &str, field_name: &str) -> Option<(usize, u32, String)> {
    let snap = crate::discovery::cached()?;
    let tables = snap.data_tables.get("data_tables")?.as_array()?;
    for t in tables {
        if t.get("table_name").and_then(|v| v.as_str()) != Some(table_name) {
            continue;
        }
        let fields = t
            .get("row_struct")
            .and_then(|v| v.get("fields"))
            .and_then(|v| v.as_array())?;
        for f in fields {
            if f.get("name").and_then(|v| v.as_str()) != Some(field_name) {
                continue;
            }
            let offset = f.get("offset").and_then(|v| v.as_i64())? as usize;
            let size = f.get("element_size").and_then(|v| v.as_i64())? as u32;
            let class = f
                .get("class")
                .and_then(|v| v.as_str())
                .unwrap_or("")
                .to_string();
            return Some((offset, size, class));
        }
    }
    None
}

/// Name-based wrapper over `FieldTweak<T>` -- the offset is
/// resolved from the discovery cache on first apply rather than
/// baked at declaration. This is the canonical write entry for
/// new-game bootstrap: a mod declares one static per knob, no
/// SDK header dive, no hand-typed offsets, and a game patch that
/// shifts the offset is picked up by the next discovery refresh.
///
/// ```ignore
/// use ueforge::data_table::NamedFieldTweak;
///
/// static MAX_STACK: NamedFieldTweak<i32> =
///     NamedFieldTweak::new("DT_Materials", "MaxCanStack");
///
/// // From `on_unreal_init` (after discovery::run_at_load):
/// MAX_STACK.apply(|v| v.saturating_mul(4), |v| v <= 1).ok();
/// ```
///
/// `T` semantics match `FieldTweak<T>`: vanilla snapshot captured
/// per row on first read; subsequent applies re-base on the captured
/// baseline, never compounding. Reverting via [`revert`](Self::revert)
/// writes vanilla back to every captured row.
pub struct NamedFieldTweak<T: Copy + PartialEq + Send + 'static> {
    table_name: &'static str,
    field_name: &'static str,
    inner: OnceLock<ue::datatable::FieldTweak<T>>,
}

impl<T: Copy + PartialEq + Send + 'static> NamedFieldTweak<T> {
    pub const fn new(table_name: &'static str, field_name: &'static str) -> Self {
        Self {
            table_name,
            field_name,
            inner: OnceLock::new(),
        }
    }

    pub fn table_name(&self) -> &'static str {
        self.table_name
    }

    pub fn field_name(&self) -> &'static str {
        self.field_name
    }

    /// Resolve the offset (lazily, once) and apply. Errors if the
    /// field isn't in the discovery cache -- caller can
    /// `discovery::refresh()` and try again.
    pub fn apply<F, S>(&self, transform: F, skip_if: S) -> Result<usize, String>
    where
        F: Fn(T) -> T,
        S: Fn(T) -> bool,
    {
        let tweak = self.resolve_or_init()?;
        tweak.apply(transform, skip_if)
    }

    /// Revert every captured row to its vanilla value.
    pub fn revert(&self) -> Result<usize, String> {
        let tweak = self.resolve_or_init()?;
        tweak.revert()
    }

    fn resolve_or_init(&self) -> Result<&ue::datatable::FieldTweak<T>, String> {
        if let Some(t) = self.inner.get() {
            return Ok(t);
        }
        let (offset, _size, _class) = resolve_field(self.table_name, self.field_name)
            .ok_or_else(|| {
                format!(
                    "NamedFieldTweak: field '{}.{}' not in discovery cache",
                    self.table_name, self.field_name
                )
            })?;
        let tweak = ue::datatable::FieldTweak::new(self.table_name, offset);
        // First setter wins; second loses (we still got our copy back).
        let _ = self.inner.set(tweak);
        Ok(self.inner.get().expect("just initialized"))
    }

    /// Spawn a background worker that waits for the table to
    /// load (via `ue::datatable::on_first_sight`), refreshes the
    /// discovery cache so the field is resolvable, then applies
    /// once. Same shape as `FieldTweak::apply_when_ready` --
    /// the typical init-time entry point.
    pub fn apply_when_ready<F, S>(
        &'static self,
        timeout: std::time::Duration,
        transform: F,
        skip_if: S,
    ) where
        F: Fn(T) -> T + Send + 'static,
        S: Fn(T) -> bool + Send + 'static,
    {
        ue::datatable::on_first_sight(self.table_name, timeout, move |_dt| {
            // Re-walk discovery if our field isn't cached yet --
            // the table only just appeared.
            if resolve_field(self.table_name, self.field_name).is_none() {
                let _ = crate::discovery::refresh();
            }
            match self.apply(&transform, &skip_if) {
                Ok(n) => crate::log::log(format_args!(
                    "NamedFieldTweak<{}>: applied to {n} rows of {}.{}",
                    std::any::type_name::<T>(),
                    self.table_name,
                    self.field_name
                )),
                Err(e) => crate::log::log(format_args!(
                    "NamedFieldTweak<{}>: apply failed on {}.{}: {e}",
                    std::any::type_name::<T>(),
                    self.table_name,
                    self.field_name
                )),
            }
        });
    }
}

// ---- Class field, name-based --------------------------------------------

/// Look up `field_name` on `class_name` in the discovery cache's
/// classes JSON. Returns `(offset, element_size)`. `None` if the
/// class isn't in the cache or the field isn't on it.
pub fn resolve_class_field(class_name: &str, field_name: &str) -> Option<(usize, u32)> {
    let snap = crate::discovery::cached()?;
    let classes = snap.classes.get("classes")?.as_array()?;
    for c in classes {
        if c.get("name").and_then(|v| v.as_str()) != Some(class_name) {
            continue;
        }
        let fields = c.get("fields")?.as_array()?;
        for f in fields {
            if f.get("name").and_then(|v| v.as_str()) != Some(field_name) {
                continue;
            }
            let offset = f.get("offset").and_then(|v| v.as_i64())? as usize;
            let size = f.get("element_size").and_then(|v| v.as_i64())? as u32;
            return Some((offset, size));
        }
    }
    None
}

/// Name-based wrapper over [`ue::class_tweak::ClassFieldTweak<T>`].
/// Same shape as [`NamedFieldTweak<T>`] but for live UObjects: a
/// mod declares one static per knob with `(class_name, field_name)`,
/// the offset is resolved from the discovery cache on first apply,
/// and the underlying `ClassFieldTweak<T>` provides per-instance
/// vanilla snapshot + idempotent re-apply.
///
/// ```ignore
/// static SURVIVAL_HUNGER: ClassNamedFieldTweak<f32> =
///     ClassNamedFieldTweak::new("SurvivalComponent", "HungerDecayRate");
///
/// // From the mod's on_unreal_init worker (post discovery):
/// SURVIVAL_HUNGER.apply(|_obj| true, |v| Some(v * 0.5)).ok();
/// ```
pub struct ClassNamedFieldTweak<T: Copy + PartialEq + Send + 'static> {
    class_name: &'static str,
    field_name: &'static str,
    inner: OnceLock<ue::class_tweak::ClassFieldTweak<T>>,
}

impl<T: Copy + PartialEq + Send + 'static> ClassNamedFieldTweak<T> {
    pub const fn new(class_name: &'static str, field_name: &'static str) -> Self {
        Self {
            class_name,
            field_name,
            inner: OnceLock::new(),
        }
    }

    pub fn class_name(&self) -> &'static str {
        self.class_name
    }

    pub fn field_name(&self) -> &'static str {
        self.field_name
    }

    pub fn apply<Filter, Transform>(
        &self,
        filter: Filter,
        transform: Transform,
    ) -> Result<ue::class_tweak::ClassTweakStats, String>
    where
        Filter: Fn(&UObject) -> bool,
        Transform: Fn(T) -> Option<T>,
    {
        let tweak = self.resolve_or_init()?;
        tweak.apply(filter, transform)
    }

    pub fn revert(&self) -> Result<usize, String> {
        let tweak = self.resolve_or_init()?;
        tweak.revert()
    }

    fn resolve_or_init(&self) -> Result<&ue::class_tweak::ClassFieldTweak<T>, String> {
        if let Some(t) = self.inner.get() {
            return Ok(t);
        }
        let (offset, _size) = resolve_class_field(self.class_name, self.field_name)
            .ok_or_else(|| {
                format!(
                    "ClassNamedFieldTweak: field '{}.{}' not in discovery cache",
                    self.class_name, self.field_name
                )
            })?;
        let tweak = ue::class_tweak::ClassFieldTweak::new(self.class_name, offset);
        let _ = self.inner.set(tweak);
        Ok(self.inner.get().expect("just initialized"))
    }
}

/// Capture every row of `table_name`, decoding fields per the live
/// `FProperty` chain on the table's `RowStruct`. Up to `max_rows`
/// entries are returned (`None` = all). Cold path; allocates freely.
///
/// Decode coverage (FProperty class -> JSON):
/// - `IntProperty` (i32), `UInt32Property` (u32), `Int64Property` (i64),
///   `UInt64Property` (u64), `ByteProperty` (u8 number)
/// - `FloatProperty` (f32), `DoubleProperty` (f64)
/// - `BoolProperty` (single-byte interpretation; bitfield bools land
///   as numeric -- they need their bitmask which isn't in the FField
///   chain we walk today)
/// - `NameProperty` (resolved FName -> string)
/// - `StrProperty` (FString -> string)
/// - `ObjectProperty` / `SoftObjectProperty` / `ClassProperty` /
///   `WeakObjectProperty` -- pointer hex
/// - Everything else -- `{ "raw_bytes_hex": "..." }` of the first
///   `element_size` bytes so a future decoder can be added without
///   re-walking.
///
/// Returns `None` if the table can't be resolved or has no RowStruct.
pub fn snapshot_table(table_name: &str, max_rows: Option<usize>) -> Option<Json> {
    let table = ue::datatable::find_by_short_name(table_name)?;
    let row_struct_ptr: *const UObject = unsafe {
        (table.as_ptr().add(crate::ue::offsets::datatable::ROW_STRUCT)
            as *const *const UObject)
            .read_unaligned()
    };
    let row_struct = unsafe { row_struct_ptr.as_ref()? };
    let schema = ue::probe::walk_struct_fields(row_struct);

    let rt = ue::try_runtime()?;
    let mut rows: Vec<Json> = Vec::new();
    let mut total_rows = 0usize;
    unsafe {
        for (fname_key, row_ptr) in ue::datatable::iter_rows(table) {
            total_rows += 1;
            if let Some(limit) = max_rows {
                if rows.len() >= limit {
                    continue;
                }
            }
            let fname = std::mem::transmute::<u64, crate::ue::fname::FName>(fname_key);
            let row_name = rt.name_resolver.to_string(fname);
            let fields_json = decode_row_fields(row_ptr, &schema);
            rows.push(json!({
                "row_name": row_name,
                "row_fname": fname_key,
                "fields": fields_json,
            }));
        }
    }

    Some(json!({
        "table_name": table_name,
        "full_path": table.full_name(),
        "row_struct": {
            "name": row_struct.name(),
            "fields": schema,
        },
        "rows_total": total_rows,
        "rows_returned": rows.len(),
        "rows": rows,
    }))
}

// ---- Drift validation (Phase 1e) -----------------------------------------

/// Cross-check every `DataTableDef` in `reg` against the live
/// reflection data ueforge::discovery captured. Each declared
/// field is compared on `(offset, element_size)` against the
/// FProperty entry of the same name on the table's RowStruct.
///
/// Returns a JSON report:
///
/// ```text
/// { "tables": [
///     { "id": "materials", "status": "ok" },
///     { "id": "recipes",
///       "status": "drift",
///       "issues": [
///         {"field": "Yield", "kind": "offset",
///          "declared": 0x10, "live": 0x14}
///       ]
///     },
///     { "id": "obsolete",
///       "status": "table_missing" }
///   ],
///   "ok_count": ...,
///   "drift_count": ...,
///   "missing_count": ... }
/// ```
///
/// Cold path; run once at mod init after `discovery::run_at_load`.
/// Logs every drift line via `ueforge::log!` so missed UE patches
/// surface in the deployed log even if the JSON is never read.
pub fn validate_registry(reg: &DataTableRegistry) -> Json {
    let mut tables_out: Vec<Json> = Vec::new();
    let mut ok = 0usize;
    let mut drift = 0usize;
    let mut missing = 0usize;

    let discovery = crate::discovery::cached();
    let empty_arr = Vec::new();
    let live_tables = discovery
        .as_ref()
        .and_then(|d| d.data_tables.get("data_tables").and_then(|v| v.as_array()))
        .unwrap_or(&empty_arr);

    for def in reg.entries() {
        let live = live_tables.iter().find(|t| {
            t.get("table_name")
                .and_then(|v| v.as_str())
                .is_some_and(|n| n == def.table_name)
        });
        let Some(live) = live else {
            missing += 1;
            crate::log::log(format_args!(
                "DataTable drift: '{}' (id={}) not present in discovery cache",
                def.table_name, def.id
            ));
            tables_out.push(json!({
                "id": def.id,
                "table_name": def.table_name,
                "status": "table_missing",
            }));
            continue;
        };

        let live_fields = live
            .get("row_struct")
            .and_then(|v| v.get("fields"))
            .and_then(|v| v.as_array())
            .cloned()
            .unwrap_or_default();

        let mut issues: Vec<Json> = Vec::new();
        for declared in def.row_struct.fields {
            let live_f = live_fields.iter().find(|f| {
                f.get("name")
                    .and_then(|v| v.as_str())
                    .is_some_and(|n| n == declared.name)
            });
            let Some(lf) = live_f else {
                issues.push(json!({
                    "field": declared.name,
                    "kind": "missing",
                    "declared_offset": declared.offset,
                }));
                continue;
            };
            let live_offset = lf.get("offset").and_then(|v| v.as_i64()).unwrap_or(0) as usize;
            let live_size = lf.get("element_size").and_then(|v| v.as_i64()).unwrap_or(0) as u32;
            if live_offset != declared.offset {
                issues.push(json!({
                    "field": declared.name,
                    "kind": "offset",
                    "declared": declared.offset,
                    "live": live_offset,
                }));
            }
            if live_size != declared.element_size {
                issues.push(json!({
                    "field": declared.name,
                    "kind": "element_size",
                    "declared": declared.element_size,
                    "live": live_size,
                }));
            }
        }

        if issues.is_empty() {
            ok += 1;
            tables_out.push(json!({
                "id": def.id,
                "table_name": def.table_name,
                "status": "ok",
            }));
        } else {
            drift += 1;
            for iss in &issues {
                crate::log::log(format_args!(
                    "DataTable drift: '{}' field '{}' {}: declared={:?} live={:?}",
                    def.table_name,
                    iss.get("field").and_then(|v| v.as_str()).unwrap_or("?"),
                    iss.get("kind").and_then(|v| v.as_str()).unwrap_or("?"),
                    iss.get("declared"),
                    iss.get("live"),
                ));
            }
            tables_out.push(json!({
                "id": def.id,
                "table_name": def.table_name,
                "status": "drift",
                "issues": issues,
            }));
        }
    }

    json!({
        "tables": tables_out,
        "ok_count": ok,
        "drift_count": drift,
        "missing_count": missing,
    })
}

fn decode_row_fields(row_ptr: *const u8, schema: &[Json]) -> Json {
    let mut map = serde_json::Map::with_capacity(schema.len());
    for f in schema {
        let name = f["name"].as_str().unwrap_or("<no-name>").to_string();
        let class = f["class"].as_str().unwrap_or("");
        let offset = f["offset"].as_i64().unwrap_or(0) as usize;
        let element_size = f["element_size"].as_i64().unwrap_or(0) as usize;
        let value = unsafe { decode_field(row_ptr, offset, element_size, class) };
        map.insert(name, value);
    }
    Json::Object(map)
}

unsafe fn decode_field(row_ptr: *const u8, offset: usize, element_size: usize, class: &str) -> Json {
    unsafe {
        let p = row_ptr.add(offset);
        match class {
            "IntProperty" | "Int32Property" => {
                json!((p as *const i32).read_unaligned())
            }
            "UInt32Property" => json!((p as *const u32).read_unaligned()),
            "Int64Property" => json!((p as *const i64).read_unaligned()),
            "UInt64Property" => json!((p as *const u64).read_unaligned()),
            "Int16Property" => json!((p as *const i16).read_unaligned()),
            "UInt16Property" => json!((p as *const u16).read_unaligned()),
            "Int8Property" | "SByteProperty" => json!((p as *const i8).read_unaligned()),
            "ByteProperty" => json!((p as *const u8).read()),
            "BoolProperty" => json!((p as *const u8).read() != 0),
            "FloatProperty" => json!((p as *const f32).read_unaligned()),
            "DoubleProperty" => json!((p as *const f64).read_unaligned()),
            "NameProperty" => {
                let fname: crate::ue::fname::FName = (p as *const crate::ue::fname::FName)
                    .read_unaligned();
                if fname.is_none() {
                    return Json::Null;
                }
                let rt = match ue::try_runtime() {
                    Some(r) => r,
                    None => return Json::Null,
                };
                json!(rt.name_resolver.to_string(fname))
            }
            "StrProperty" => {
                // FString = TArray<u16> { Data, Num, Max }
                let data: *const u16 = (p as *const *const u16).read_unaligned();
                let num = (p.add(8) as *const i32).read_unaligned();
                if data.is_null() || num <= 0 {
                    return json!("");
                }
                // Strip trailing NUL if present (FString stores it).
                let len = if num > 0 { (num - 1) as usize } else { 0 };
                let slice = std::slice::from_raw_parts(data, len);
                json!(String::from_utf16_lossy(slice))
            }
            "ObjectProperty"
            | "ClassProperty"
            | "SoftObjectProperty"
            | "SoftClassProperty"
            | "WeakObjectProperty"
            | "LazyObjectProperty" => {
                let ptr: *const UObject = (p as *const *const UObject).read_unaligned();
                if ptr.is_null() {
                    return Json::Null;
                }
                let obj = &*ptr;
                json!({
                    "addr": format!("0x{:x}", ptr as usize),
                    "name": obj.name(),
                })
            }
            _ => {
                let len = element_size.min(64);
                let slice = std::slice::from_raw_parts(p, len);
                let hex: String = slice.iter().map(|b| format!("{:02x}", b)).collect();
                json!({ "raw_bytes_hex": hex, "element_size": element_size })
            }
        }
    }
}
