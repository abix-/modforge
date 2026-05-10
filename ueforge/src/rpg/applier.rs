//! `RpgApplier` -- the trait every game implements to plug its own
//! `SkillEffect` enum into the generic [`super::Tracker`].
//!
//! Per kovarex's promotion rule, ueforge owns the bones (catalog,
//! state, persistence, tracker, tab) and the game owns the meat
//! (the actual writes -- which UE field at which offset). The
//! Applier is the seam.
//!
//! ```ignore
//! pub struct GameApplier { settings: Settings }
//!
//! impl ueforge::rpg::RpgApplier for GameApplier {
//!     type Effect = SkillEffect;
//!
//!     fn apply_skill(&self, state: &SkillsState, skill: &Skill<SkillEffect>) {
//!         let level = state.level_of(skill.id);
//!         match skill.effect {
//!             SkillEffect::BackpackSlots { max_bonus } => {
//!                 // ... write to UInventoryComponent CDOs ...
//!             }
//!             // ... other variants ...
//!         }
//!     }
//!
//!     fn format_effect(&self, skill: &Skill<SkillEffect>, level: u32) -> String {
//!         // pretty per-skill text for the ImGui row
//!     }
//! }
//! ```

use super::{Skill, SkillsState};

pub trait RpgApplier: Send + Sync + 'static {
    /// The game's effect enum. Owned by the game crate.
    type Effect: Copy + 'static;

    /// Apply ONE skill against `state`. Called whenever the level
    /// of that skill changes (spend / refund / toggle / slot
    /// activate). The level is `state.level_of(skill.id)`; if it's
    /// zero, the impl typically restores vanilla / does nothing.
    fn apply_skill(&self, state: &SkillsState, skill: &Skill<Self::Effect>);

    /// Apply every skill in `catalog`. Default impl walks them in
    /// catalog order and calls `apply_skill` for each. Override if
    /// dependency ordering matters.
    fn apply_all(&self, state: &SkillsState, catalog: &[Skill<Self::Effect>]) {
        for s in catalog {
            self.apply_skill(state, s);
        }
    }

    /// Format the in-game effect text shown next to a skill row.
    /// Examples: "+25% damage", "-50% drain", "+460 slots".
    fn format_effect(&self, skill: &Skill<Self::Effect>, level: u32) -> String;
}
