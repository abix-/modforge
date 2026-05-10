//! Status-effect Def + registry. The row-level identity for one
//! UE5 status effect (data-table row + value-field offset +
//! vanilla cache).
//!
//! ```text
//! K8s slot: Def=StatusDef, Registry=StatusRegistry,
//!           Instance=mutated row in a UDataTable,
//!           Controller=StatusEffectApply Effect (and future
//!                      StatusEffectClear / StatusEffectMutate)
//! ```
//!
//! Per the workspace
//! [composition model](../../docs/architecture.md), the things
//! we research are Effects (operations on game state). For
//! status effects, the canonical operation is "mutate the row's
//! Value field + invoke `CreateAndAddEffect` on the player's
//! component" -- shipped by [`super::StatusEffectApply`].
//!
//! The status itself (which row, in which table, at which value
//! offset) is data, not behavior. That data lives here as
//! [`StatusDef`], decoupled from the operations that mutate it.
//! Multiple Effects can target the same status (apply, clear,
//! peek), and the data-table row + vanilla cache is shared.
//!
//! ```ignore
//! use ueforge::rpg::status::{StatusDef, StatusRegistry};
//!
//! static MAX_HEALTH_VANILLA: VanillaCache<u64, f32> = VanillaCache::new();
//!
//! pub static MAX_HEALTH_STATUS: StatusDef = StatusDef {
//!     id: "max_health",
//!     table_finder: || find_status_table(),
//!     row_fname: ROW_FNAME_MAX_HEALTH,
//!     value_offset: ueforge::ue::status_effect::DEFAULT_VALUE_OFFSET,
//!     vanilla: &MAX_HEALTH_VANILLA,
//! };
//!
//! pub static STATUSES: StatusRegistry = StatusRegistry::new(&[
//!     &MAX_HEALTH_STATUS,
//!     // ... other StatusDefs
//! ]);
//!
//! // The skill's Effect references the StatusDef:
//! static EFFECT_MAX_HEALTH: ueforge::rpg::StatusEffectApply =
//!     ueforge::rpg::StatusEffectApply {
//!         player: &PLAYER,
//!         status: &MAX_HEALTH_STATUS,
//!         component_class: &SE_COMPONENT,
//!         component_offset: TypedField::at(0x...),
//!         function_name: "CreateAndAddEffect",
//!         value_at_max: 200.0,
//!         format_word: "max HP",
//!     };
//! ```

use crate::rpg::vanilla::VanillaCache;
use crate::ue::UObject;

/// Identity + data-table-row coordinates for one UE5 status
/// effect. The Def is purely data; Effects (StatusEffectApply,
/// future StatusEffectClear, etc.) consume `&'static StatusDef`
/// to act on the row.
pub struct StatusDef {
    /// Stable id for [`StatusRegistry::def`] lookup.
    pub id: &'static str,
    /// Resolves the `UDataTable` carrying the row. Called per
    /// apply; cache the result internally if your finder is
    /// expensive.
    pub table_finder: fn() -> Option<&'static UObject>,
    /// FName of the row to mutate, packed as a u64.
    pub row_fname: u64,
    /// Byte offset of the row's `Value` field within the row
    /// struct. Defaults to the Maine layout
    /// (`ueforge::ue::status_effect::DEFAULT_VALUE_OFFSET`,
    /// `0x34`); override per game.
    pub value_offset: usize,
    /// Per-row vanilla cache keyed by row_fname. The first
    /// Effect to touch the row captures the vanilla value;
    /// subsequent reads return the captured baseline so we
    /// always scale from vanilla, not from whatever a previous
    /// apply wrote.
    pub vanilla: &'static VanillaCache<u64, f32>,
}

/// Workspace-standard `<Subject>Registry` for status effects.
pub struct StatusRegistry {
    entries: &'static [&'static StatusDef],
}

impl StatusRegistry {
    pub const fn new(entries: &'static [&'static StatusDef]) -> Self {
        Self { entries }
    }

    /// Canonical lookup. O(N) linear scan; status registries
    /// are tiny. None for unknown ids.
    pub fn def(&self, id: &str) -> Option<&'static StatusDef> {
        for d in self.entries {
            if d.id == id {
                return Some(*d);
            }
        }
        None
    }

    pub fn entries(&self) -> &'static [&'static StatusDef] {
        self.entries
    }

    pub fn iter(&self) -> std::slice::Iter<'_, &'static StatusDef> {
        self.entries.iter()
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }
}
