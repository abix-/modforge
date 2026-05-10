// Hunger and thirst rate patcher. Two `ueforge::difficulty::DifficultyKnob`
// instances on `USurvivalComponent` CDOs. The framework owns vanilla
// capture + idempotent re-apply + the multiplier atomic; this file
// owns the field offsets and the call from `worker()`.
//
// USurvivalComponent (Maine.SurvivalComponent) holds:
//   FSurvivalTraitSettings HungerSettings;  // +0x0138
//   FSurvivalTraitSettings ThirstSettings;  // +0x0180
// Inside FSurvivalTraitSettings: float AdjustmentPerSecond at +0x08.

use ueforge::difficulty::DifficultyKnob;

pub const HUNGER_ADJUSTMENT_OFFSET: usize = 0x0138 + 0x08; // 0x0140
pub const THIRST_ADJUSTMENT_OFFSET: usize = 0x0180 + 0x08; // 0x0188

static HUNGER: DifficultyKnob =
    DifficultyKnob::new("SurvivalComponent", HUNGER_ADJUSTMENT_OFFSET);
static THIRST: DifficultyKnob =
    DifficultyKnob::new("SurvivalComponent", THIRST_ADJUSTMENT_OFFSET);

pub struct SurvivalStats {
    pub scanned_classes: usize,
    pub patched: usize,
}

pub fn run(thirst_multiplier: f32, hunger_multiplier: f32) -> SurvivalStats {
    HUNGER.set_multiplier(hunger_multiplier);
    THIRST.set_multiplier(thirst_multiplier);

    let h = HUNGER.apply_to_cdos().unwrap_or_default();
    let t = THIRST.apply_to_cdos().unwrap_or_default();

    if h.scanned == 0 && t.scanned == 0 {
        ueforge::log!("survival: both multipliers are 1.0, skipping patch");
    }

    SurvivalStats {
        scanned_classes: h.scanned.max(t.scanned),
        patched: h.patched + t.patched,
    }
}
