//! Generic catalog row + lookup helpers for any RPG mod.
//!
//! The `Skill<E>` struct is the universal shape: an id (stable
//! string used as a save-file key), a display name, a max level,
//! and an effect. The `effect` is parameterized -- each game
//! supplies its own enum (`bbp::SkillEffect`, `outworld::SkillEffect`)
//! that names every kind of skill that game implements. ueforge
//! ships the catalog scaffolding; each game ships the variants.
//!
//! ```ignore
//! use ueforge::rpg::Skill;
//!
//! pub enum SkillEffect {
//!     BackpackSlots { max_bonus: i32 },
//!     // ...
//! }
//!
//! pub static CATALOG: &[Skill<SkillEffect>] = &[
//!     Skill {
//!         id: "backpack",
//!         display_name: "Backpack",
//!         max_level: 100,
//!         effect: SkillEffect::BackpackSlots { max_bonus: 460 },
//!     },
//!     // ...
//! ];
//!
//! let s = ueforge::rpg::find_skill(CATALOG, "backpack");
//! ```

#[derive(Debug, Clone, Copy)]
pub struct Skill<E: 'static> {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect: E,
}

/// Look up a skill in `catalog` by stable string id. O(N) linear
/// scan; catalogs are tiny (~25 rows) and lookups are cold-path
/// (button click, snapshot, ImGui row label) -- no need for a hash
/// map.
pub fn find_skill<'a, E>(catalog: &'a [Skill<E>], id: &str) -> Option<&'a Skill<E>> {
    catalog.iter().find(|s| s.id == id)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[derive(Debug, Clone, Copy)]
    enum TestEffect {
        Foo,
        Bar { v: u32 },
    }

    static CATALOG: &[Skill<TestEffect>] = &[
        Skill {
            id: "foo",
            display_name: "Foo",
            max_level: 50,
            effect: TestEffect::Foo,
        },
        Skill {
            id: "bar",
            display_name: "Bar",
            max_level: 100,
            effect: TestEffect::Bar { v: 7 },
        },
    ];

    #[test]
    fn find_hit() {
        let s = find_skill(CATALOG, "bar").unwrap();
        assert_eq!(s.id, "bar");
        assert_eq!(s.max_level, 100);
        match s.effect {
            TestEffect::Bar { v } => assert_eq!(v, 7),
            _ => panic!(),
        }
    }

    #[test]
    fn find_miss() {
        assert!(find_skill(CATALOG, "nope").is_none());
    }
}
