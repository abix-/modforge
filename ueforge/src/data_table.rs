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

use serde_json::{Value as Json, json};

use crate::ue::{self, UObject};

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
