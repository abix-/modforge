// Hunger and thirst rate patcher. Two `ueforge::difficulty::DifficultyDef`
// entries on `USurvivalComponent` CDOs, declared in one
// `DifficultyRegistry`. The framework owns vanilla capture +
// idempotent re-apply + the multiplier atomic; this file owns
// the field offsets and the call from `worker()`.
//
// USurvivalComponent (Maine.SurvivalComponent) holds:
//   FSurvivalTraitSettings HungerSettings;  // +0x0138
//   FSurvivalTraitSettings ThirstSettings;  // +0x0180
// Inside FSurvivalTraitSettings: float AdjustmentPerSecond at +0x08.

use ueforge::difficulty::{DifficultyDef, DifficultyRegistry};

pub const HUNGER_ADJUSTMENT_OFFSET: usize = 0x0138 + 0x08; // 0x0140
pub const THIRST_ADJUSTMENT_OFFSET: usize = 0x0180 + 0x08; // 0x0188

static SURVIVAL_DEFS: [DifficultyDef; 2] = [
    DifficultyDef::new("hunger", "SurvivalComponent", HUNGER_ADJUSTMENT_OFFSET),
    DifficultyDef::new("thirst", "SurvivalComponent", THIRST_ADJUSTMENT_OFFSET),
];

pub static SURVIVAL: DifficultyRegistry = DifficultyRegistry::new(&SURVIVAL_DEFS);

pub struct SurvivalStats {
    pub scanned_classes: usize,
    pub patched: usize,
}

pub fn run(thirst_multiplier: f32, hunger_multiplier: f32) -> SurvivalStats {
    SURVIVAL.def("hunger").unwrap().set_multiplier(hunger_multiplier);
    SURVIVAL.def("thirst").unwrap().set_multiplier(thirst_multiplier);

    let mut scanned_classes = 0usize;
    let mut patched = 0usize;
    for (id, r) in SURVIVAL.apply_all_to_cdos() {
        let stats = r.unwrap_or_default();
        if stats.scanned == 0 {
            ueforge::log!("survival: '{id}' multiplier is 1.0 (or skipped), no patch");
        }
        scanned_classes = scanned_classes.max(stats.scanned);
        patched += stats.patched;
    }

    SurvivalStats {
        scanned_classes,
        patched,
    }
}
