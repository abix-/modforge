//! Skill catalog row + lookup. Per the workspace
//! [composition model](../../docs/architecture.md), a Skill is
//! one or more Effects applied with parameters; this struct is
//! the leveling / persistence / UI scaffolding around an
//! [`EffectDef`](super::EffectDef).
//!
//! ```text
//! K8s slot: Def=SkillDef, Registry=SkillRegistry,
//!           Instance=SkillsState.skill_levels[id],
//!           Controller=Tracker
//! ```
//!
//! ```ignore
//! use ueforge::rpg::{EffectDef, SkillDef, SkillRegistry};
//!
//! pub static CATALOG: SkillRegistry = SkillRegistry::new(&[
//!     SkillDef {
//!         id: "attack_damage",
//!         display_name: "Attack Damage",
//!         max_level: 100,
//!         effect: EffectDef::new("PlayerFloat", &ATTACK_DAMAGE_EFFECT),
//!     },
//!     // ...
//! ]);
//!
//! let s = CATALOG.def("attack_damage");
//! ```

use super::EffectDef;

/// Skill catalog row -- the Def in the workspace's
/// Def/Registry/Instance/Controller pattern. Carries the
/// player-facing identity (id / display_name / max_level) plus
/// the [`EffectDef`] that does the work.
pub struct SkillDef {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect: EffectDef,
}

/// Skill registry -- the workspace-standard `<Subject>Registry`
/// wrapper around a static catalog slice. Game crates declare:
///
/// ```ignore
/// pub static CATALOG: SkillRegistry = SkillRegistry::new(&[
///     SkillDef { id: "...", display_name: "...", max_level: 100,
///                effect: EffectDef::new("Kind", &INSTANCE) },
///     // ...
/// ]);
/// ```
///
/// and look up by id via the canonical `def` method:
///
/// ```ignore
/// let s = CATALOG.def("attack_damage");
/// ```
pub struct SkillRegistry {
    entries: &'static [SkillDef],
}

impl SkillRegistry {
    /// Construct a registry from a `'static` catalog slice.
    /// `const fn` so consumers can declare `static CATALOG:
    /// SkillRegistry = SkillRegistry::new(&[...])`.
    pub const fn new(entries: &'static [SkillDef]) -> Self {
        Self { entries }
    }

    /// Canonical lookup. O(N) linear scan; catalogs are tiny
    /// (~25 rows) and lookups are cold-path -- no hash map needed.
    pub fn def(&self, id: &str) -> Option<&'static SkillDef> {
        self.entries.iter().find(|s| s.id == id)
    }

    /// Borrow the underlying static slice for iteration (e.g.
    /// the ImGui tab renders one row per entry).
    pub fn entries(&self) -> &'static [SkillDef] {
        self.entries
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    /// Convenience for `for skill in registry` patterns.
    pub fn iter(&self) -> std::slice::Iter<'_, SkillDef> {
        self.entries.iter()
    }
}

// `for x in &CATALOG` works through this impl. `for x in CATALOG`
// (consuming the registry) doesn't make sense -- the registry IS
// the catalog handle, not a sequence to consume.
impl<'a> IntoIterator for &'a SkillRegistry {
    type Item = &'a SkillDef;
    type IntoIter = std::slice::Iter<'a, SkillDef>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter()
    }
}
