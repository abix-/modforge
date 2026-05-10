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
