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
// We walk every UClass that derives from SurvivalComponent (native + any
// BP-derived overrides) and patch each CDO's two AdjustmentPerSecond
// floats by the configured multipliers. Sticky-CDO pattern: every newly
// constructed SurvivalComponent inherits the slowed drain, no rescan
// needed.

use ueforge::ue::{self, GObjectsView, UObject};

pub const HUNGER_ADJUSTMENT_OFFSET: usize = 0x0138 + 0x08; // 0x0140
pub const THIRST_ADJUSTMENT_OFFSET: usize = 0x0180 + 0x08; // 0x0188

pub struct SurvivalStats {
    pub scanned_classes: usize,
    pub patched: usize,
}

pub fn run(thirst_multiplier: f32, hunger_multiplier: f32) -> SurvivalStats {
    let mut stats = SurvivalStats {
        scanned_classes: 0,
        patched: 0,
    };

    if (thirst_multiplier - 1.0).abs() < f32::EPSILON
        && (hunger_multiplier - 1.0).abs() < f32::EPSILON
    {
        ueforge::log!("survival: both multipliers are 1.0, skipping patch");
        return stats;
    }

    let Some(rt) = ue::try_runtime() else {
        return stats;
    };
    let Some(survival_class) = ue::find_class_fast("SurvivalComponent") else {
        ueforge::log!("ERROR: SurvivalComponent class not found");
        return stats;
    };

    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        ueforge::log!("ERROR: GObjects unavailable for survival patch");
        return stats;
    }

    // Walk for CDOs only -- patching live instances would compound on
    // every rescan and the CDO is sticky. CDO names start with "Default__".
    for obj in view.iter() {
        if !obj.is_a(survival_class) {
            continue;
        }
        if !obj.is_default_object() {
            continue;
        }
        stats.scanned_classes += 1;
        if patch_one(obj, thirst_multiplier, hunger_multiplier) {
            stats.patched += 1;
        }
    }

    stats
}

fn patch_one(obj: &UObject, thirst_mult: f32, hunger_mult: f32) -> bool {
    let mut changed = false;
    let full = obj.full_name();

    if (hunger_mult - 1.0).abs() > f32::EPSILON {
        let before = read_f32(obj, HUNGER_ADJUSTMENT_OFFSET);
        if before.is_finite() && before != 0.0 {
            let after = before * hunger_mult;
            write_f32(obj, HUNGER_ADJUSTMENT_OFFSET, after);
            let verify = read_f32(obj, HUNGER_ADJUSTMENT_OFFSET);
            ueforge::log!(
                "HUNGER PATCH {}: {:.4} -> {:.4} (verify={:.4})",
                full,
                before,
                after,
                verify
            );
            changed = true;
        }
    }

    if (thirst_mult - 1.0).abs() > f32::EPSILON {
        let before = read_f32(obj, THIRST_ADJUSTMENT_OFFSET);
        if before.is_finite() && before != 0.0 {
            let after = before * thirst_mult;
            write_f32(obj, THIRST_ADJUSTMENT_OFFSET, after);
            let verify = read_f32(obj, THIRST_ADJUSTMENT_OFFSET);
            ueforge::log!(
                "THIRST PATCH {}: {:.4} -> {:.4} (verify={:.4})",
                full,
                before,
                after,
                verify
            );
            changed = true;
        }
    }

    changed
}

fn read_f32(obj: &UObject, offset: usize) -> f32 {
    unsafe { (obj.field_ptr(offset) as *const f32).read_unaligned() }
}

fn write_f32(obj: &UObject, offset: usize, value: f32) {
    unsafe { (obj.field_ptr(offset) as *mut f32).write_unaligned(value) }
}
