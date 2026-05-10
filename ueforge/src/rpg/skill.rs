//! Skill catalog row + lookup. Per the workspace architecture
//! contract, this is the **Skill subsystem's CRD**:
//!
//! ```text
//! K8s slot: Def=SkillDef<E>, Registry=per-mod &[SkillDef<E>] catalog,
//!           Instance=SkillsState.skill_levels[id], Controller=Tracker<A>::apply_skill
//! ```
//!
//! The `Skill<E>` / `SkillDef<E>` struct is the universal Def
//! shape: an id (stable string used as a save-file key), a
//! display name, a max level, and an effect. The `effect` is
//! parameterized -- each game supplies its own enum
//! (`g2rpg::SkillEffect`, `outworld::SkillEffect`) that names
//! every kind of skill that game implements. ueforge ships the
//! Def + lookup; each game ships the registry (its own static
//! catalog slice) and the variants.
//!
//! ```ignore
//! use ueforge::rpg::SkillDef;
//!
//! pub enum SkillEffect {
//!     BackpackSlots { max_bonus: i32 },
//!     // ...
//! }
//!
//! pub static CATALOG: &[SkillDef<SkillEffect>] = &[
//!     SkillDef {
//!         id: "backpack",
//!         display_name: "Backpack",
//!         max_level: 100,
//!         effect: SkillEffect::BackpackSlots { max_bonus: 460 },
//!     },
//!     // ...
//! ];
//!
//! let s = ueforge::rpg::skill_def(CATALOG, "backpack");
//! ```
//!
//! See [architecture.md](../../docs/architecture.md) for the
//! cross-subsystem naming contract.

/// Skill catalog row -- the Def in the workspace's
/// Def/Registry/Instance/Controller pattern.
#[derive(Debug, Clone, Copy)]
pub struct SkillDef<E: 'static> {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect: E,
}

/// Skill registry -- the workspace-standard `<Subject>Registry`
/// wrapper around a static catalog slice. Holds the entries plus
/// any future registry-level config (none today; future fields
/// might include a default category, version, etc.).
///
/// Game crates declare:
///
/// ```ignore
/// pub static CATALOG: SkillRegistry<MySkillEffect> = SkillRegistry::new(&[
///     SkillDef { id: "backpack", display_name: "Backpack",
///                max_level: 100, effect: ... },
///     // ...
/// ]);
/// ```
///
/// and look up by id via the canonical `def` method:
///
/// ```ignore
/// let s = CATALOG.def("backpack");
/// ```
pub struct SkillRegistry<E: 'static> {
    entries: &'static [SkillDef<E>],
}

// Manual Copy/Clone so we don't pick up an unwanted `E: Copy`
// bound from the derive macros. Registries are just static slice
// refs internally; copying is free.
impl<E: 'static> Clone for SkillRegistry<E> {
    fn clone(&self) -> Self {
        *self
    }
}
impl<E: 'static> Copy for SkillRegistry<E> {}

impl<E: 'static> SkillRegistry<E> {
    /// Construct a registry from a `'static` catalog slice.
    /// `const fn` so consumers can declare `static CATALOG:
    /// SkillRegistry<...> = SkillRegistry::new(&[...])`.
    pub const fn new(entries: &'static [SkillDef<E>]) -> Self {
        Self { entries }
    }

    /// Canonical lookup. O(N) linear scan; catalogs are tiny
    /// (~25 rows) and lookups are cold-path (button click,
    /// snapshot, ImGui row label) -- no hash map needed.
    pub fn def(&self, id: &str) -> Option<&'static SkillDef<E>> {
        self.entries.iter().find(|s| s.id == id)
    }

    /// Borrow the underlying static slice for iteration (e.g. the
    /// ImGui tab renders one row per entry).
    pub fn entries(&self) -> &'static [SkillDef<E>] {
        self.entries
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    /// Convenience for `for skill in registry` patterns.
    pub fn iter(&self) -> std::slice::Iter<'_, SkillDef<E>> {
        self.entries.iter()
    }
}

// `for x in CATALOG` and `for x in &CATALOG` both work. The
// former relies on `SkillRegistry` being Copy.
impl<E: 'static> IntoIterator for SkillRegistry<E> {
    type Item = &'static SkillDef<E>;
    type IntoIter = std::slice::Iter<'static, SkillDef<E>>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter()
    }
}
impl<'a, E: 'static> IntoIterator for &'a SkillRegistry<E> {
    type Item = &'a SkillDef<E>;
    type IntoIter = std::slice::Iter<'a, SkillDef<E>>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter()
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[derive(Debug, Clone, Copy)]
    enum TestEffect {
        Foo,
        Bar { v: u32 },
    }

    static CATALOG: SkillRegistry<TestEffect> = SkillRegistry::new(&[
        SkillDef {
            id: "foo",
            display_name: "Foo",
            max_level: 50,
            effect: TestEffect::Foo,
        },
        SkillDef {
            id: "bar",
            display_name: "Bar",
            max_level: 100,
            effect: TestEffect::Bar { v: 7 },
        },
    ]);

    #[test]
    fn registry_def_hit() {
        let s = CATALOG.def("bar").unwrap();
        assert_eq!(s.id, "bar");
        assert_eq!(s.max_level, 100);
        match s.effect {
            TestEffect::Bar { v } => assert_eq!(v, 7),
            _ => panic!(),
        }
    }

    #[test]
    fn registry_def_miss() {
        assert!(CATALOG.def("nope").is_none());
    }

    #[test]
    fn registry_iter() {
        let ids: Vec<&str> = CATALOG.iter().map(|s| s.id).collect();
        assert_eq!(ids, vec!["foo", "bar"]);
    }
}
