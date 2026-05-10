// Hunger and thirst rate patcher.
//
// USurvivalComponent (Maine.SurvivalComponent) holds:
//   FSurvivalTraitSettings HungerSettings;  // +0x0138
//   FSurvivalTraitSettings ThirstSettings;  // +0x0180
//
// Inside FSurvivalTraitSettings, the field we care about is
//   float AdjustmentPerSecond;   // struct +0x08
// which is the per-second drain rate (typically negative).
//
// We walk every UClass derived from SurvivalComponent (native +
// any BP-derived overrides) and patch the CDO's two
// AdjustmentPerSecond floats by the configured multipliers.
// Sticky-CDO pattern: every newly constructed SurvivalComponent
// inherits the slowed drain.
//
// Built on `ueforge::ue::class_tweak::ClassFieldTweak<f32>` so
// vanilla capture + idempotent re-apply is shared across the
// workspace.

use ueforge::ue::class_tweak::ClassFieldTweak;

pub const HUNGER_ADJUSTMENT_OFFSET: usize = 0x0138 + 0x08; // 0x0140
pub const THIRST_ADJUSTMENT_OFFSET: usize = 0x0180 + 0x08; // 0x0188

static HUNGER: ClassFieldTweak<f32> =
    ClassFieldTweak::new("SurvivalComponent", HUNGER_ADJUSTMENT_OFFSET);
static THIRST: ClassFieldTweak<f32> =
    ClassFieldTweak::new("SurvivalComponent", THIRST_ADJUSTMENT_OFFSET);

pub struct SurvivalStats {
    pub scanned_classes: usize,
    pub patched: usize,
}

pub fn run(thirst_multiplier: f32, hunger_multiplier: f32) -> SurvivalStats {
    if (thirst_multiplier - 1.0).abs() < f32::EPSILON
        && (hunger_multiplier - 1.0).abs() < f32::EPSILON
    {
        ueforge::log!("survival: both multipliers are 1.0, skipping patch");
        return SurvivalStats {
            scanned_classes: 0,
            patched: 0,
        };
    }

    let hunger_stats = if (hunger_multiplier - 1.0).abs() > f32::EPSILON {
        HUNGER
            .apply(
                |obj| obj.is_default_object(),
                |v| {
                    if !v.is_finite() || v == 0.0 {
                        None
                    } else {
                        Some(v * hunger_multiplier)
                    }
                },
            )
            .unwrap_or_default()
    } else {
        Default::default()
    };

    let thirst_stats = if (thirst_multiplier - 1.0).abs() > f32::EPSILON {
        THIRST
            .apply(
                |obj| obj.is_default_object(),
                |v| {
                    if !v.is_finite() || v == 0.0 {
                        None
                    } else {
                        Some(v * thirst_multiplier)
                    }
                },
            )
            .unwrap_or_default()
    } else {
        Default::default()
    };

    SurvivalStats {
        scanned_classes: hunger_stats.scanned.max(thirst_stats.scanned),
        patched: hunger_stats.patched + thirst_stats.patched,
    }
}
