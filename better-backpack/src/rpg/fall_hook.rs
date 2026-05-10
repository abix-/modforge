use std::ffi::c_void;

use ueforge::hook::{LazyFunctionPtr, OriginalProcessEvent, ProcessEventHook};
use crate::rpg::{skills, tracker};
use ueforge::ue::{UFunction, UObject};

const PLAYER_FALL_HOOK_CLASSES: &[&str] = &[
    "BP_SurvivalPlayerCharacter_C",
    "BP_SurvivalPlayerCharacter_Female02_C",
    "BP_SurvivalPlayerCharacter_Gellarde_C",
];

const FN_ON_LANDED: &str = "OnLanded";

/// Lazily-cached UFunction pointer for `OnLanded`. The trampoline
/// pointer-compares against this via `LazyFunctionPtr::matches` so
/// non-OnLanded fires bail with a single atomic load + branch -- no
/// FName resolve, no heap alloc.
static ON_LANDED: LazyFunctionPtr = LazyFunctionPtr::new();

pub fn install() -> Result<Vec<ProcessEventHook>, &'static str> {
    ProcessEventHook::install_many(PLAYER_FALL_HOOK_CLASSES, |this, function, parms, original| {
        on_player_fall_event(this, function, parms, original)
    })
}

fn on_player_fall_event(
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let _t = ueforge::counters::time_scope(&crate::counters::TIME_NS_FALL_HOOK);
    ueforge::counters::bump(&crate::counters::FALL_HOOK_FIRES);

    // Drain the debug PE queue here. The drain_pending fast path
    // is a single atomic load when the queue is empty (the
    // common case), so this is sub-ns when nothing is queued.
    crate::debug::drain_pending();

    // FAST PATH: identity-cached OnLanded check. Warm path is one
    // atomic load + one branch; cold path resolves the FName once
    // and caches.
    let is_on_landed = ON_LANDED.matches(function, FN_ON_LANDED);
    if !is_on_landed {
        unsafe { original.call(this, function, parms) };
        return;
    }

    // Velocity-stomp: works for fall landings (OnLanded fires before
    // native ApplyFallDamage reads live Velocity.Z). Does NOT work
    // for collisions (engine zeroes V.Z during collision response
    // before any PE event fires), so we only stomp on OnLanded.
    // OnLanded does not suppress; we forward to original so
    // animations and sounds still run.
    let is_player = is_player_character(this);
    if is_player {
        let reduction = current_fall_resistance_reduction();
        if reduction > 0.0 {
            let scale = (1.0 - reduction).max(0.0) as f64;
            let stomped = stomp_player_velocity_z(this, scale);
            // Skip the log when V.Z was already zero -- the engine
            // has already absorbed the velocity and our stomp is a
            // no-op.
            if stomped.before.abs() > 0.001 {
                ueforge::log!(
                    "rpg/fall: stomped Velocity.Z {:.2} -> {:.2} on {} (reduction={:.3})",
                    stomped.before,
                    stomped.after,
                    this.name(),
                    reduction,
                );
            }
        }
    }

    unsafe { original.call(this, function, parms) };
}

struct VelocityStomp {
    before: f64,
    after: f64,
}

fn stomp_player_velocity_z(player: &UObject, scale: f64) -> VelocityStomp {
    // ASurvivalCharacter.CharMovementComponent ptr at +0x1380.
    // UMovementComponent.Velocity (FVector, doubles) at +0xD8.
    // FVector.Z at +0x10 inside FVector -> absolute +0xE8 on CMC.
    const ASC_CHAR_MOVEMENT_COMPONENT: usize = 0x1380;
    const CMC_VELOCITY_Z: usize = 0x00E8;
    unsafe {
        let cmc: *mut UObject = player
            .field_ptr(ASC_CHAR_MOVEMENT_COMPONENT)
            .cast::<*mut UObject>()
            .read_unaligned();
        let Some(cmc) = cmc.as_ref() else {
            return VelocityStomp {
                before: 0.0,
                after: 0.0,
            };
        };
        let z_ptr = cmc.field_ptr(CMC_VELOCITY_Z) as *mut f64;
        let before = z_ptr.read_unaligned();
        let after = before * scale;
        z_ptr.write_unaligned(after);
        VelocityStomp { before, after }
    }
}

fn current_fall_resistance_reduction() -> f32 {
    tracker::with_state(|state| {
        let level = state
            .skill_levels
            .get(skills::SKILL_FALL_RESISTANCE)
            .copied()
            .unwrap_or(0);
        if level == 0 {
            return 0.0;
        }
        skills::skill_bonus(1.0, level).min(1.0)
    })
    .unwrap_or(0.0)
}

fn is_player_character(obj: &UObject) -> bool {
    obj.full_name().contains("BP_SurvivalPlayerCharacter")
}

/// Look up a row in a `UDataTable` by FName-as-u64. Thin wrapper
/// over `ueforge::ue::tmap::find_value_by_fname_key` at the
/// `UDataTable.RowMap` offset. The TMap walking mechanics +
/// stride / pair-value layout constants live in ueforge so every
/// UE-mod project shares the same vetted code.
pub(crate) fn lookup_data_table_row(table: &UObject, row_name: u64) -> Option<*const u8> {
    use ueforge::ue::offsets::datatable;
    unsafe { ueforge::ue::tmap::find_value_by_fname_key(table, datatable::ROW_MAP, row_name) }
}

/// Read `FStatusEffectData.Type` (u8 at +0x30) and `Value`
/// (f32 at +0x34) from the row bytes.
fn read_status_effect_row(row: *const u8) -> (u8, f32) {
    const TYPE_OFFSET: usize = 0x30;
    const VALUE_OFFSET: usize = 0x34;
    unsafe {
        let stat_type = (row.add(TYPE_OFFSET) as *const u8).read_unaligned();
        let value = (row.add(VALUE_OFFSET) as *const f32).read_unaligned();
        (stat_type, value)
    }
}

/// One entry in the player's StatusEffects array, formatted for
/// the debug snapshot. Mirrors the data the `sfx-list` log line
/// already emits.
#[derive(Debug, Clone)]
pub struct StatusEffectEntry {
    pub row: String,
    pub table: String,
    pub stat_type: Option<u8>,
    pub value: Option<f32>,
}

/// Snapshot variant of `probe_player_status_effects`. Walks the
/// first live player and returns the StatusEffects array as a
/// Vec. None when no live player is available. Used by the debug
/// HTTP endpoint to expose status effects without requiring a log
/// scrape.
pub fn snapshot_player_status_effects() -> Option<Vec<StatusEffectEntry>> {
    use crate::rpg::apply;

    let mut out: Option<Vec<StatusEffectEntry>> = None;
    apply::apply_to_live_player_characters(|player| {
        if out.is_none() {
            out = Some(collect_status_effects(player));
        }
    });
    out
}

fn collect_status_effects(player: &UObject) -> Vec<StatusEffectEntry> {
    const ASC_STATUS_EFFECT_COMPONENT: usize = 0x1378;
    const SEC_STATUS_EFFECTS_TARRAY: usize = 0x01C8;
    const STATUS_EFFECT_ROW_HANDLE: usize = 0x0058;

    let mut entries = Vec::new();
    let sec = unsafe {
        let p: *mut UObject = player
            .field_ptr(ASC_STATUS_EFFECT_COMPONENT)
            .cast::<*mut UObject>()
            .read_unaligned();
        match p.as_ref() {
            Some(c) => c,
            None => return entries,
        }
    };
    let (data_ptr, num) = unsafe {
        let base = sec.field_ptr(SEC_STATUS_EFFECTS_TARRAY);
        let data = (base as *const *const *mut UObject).read_unaligned();
        let num = (base.add(8) as *const i32).read_unaligned();
        (data, num.max(0) as usize)
    };
    if data_ptr.is_null() || num == 0 {
        return entries;
    }
    for i in 0..num.min(64) {
        let effect = unsafe {
            let p = data_ptr.add(i).read_unaligned();
            match p.as_ref() {
                Some(e) => e,
                None => continue,
            }
        };
        let table_ptr = unsafe {
            effect
                .field_ptr(STATUS_EFFECT_ROW_HANDLE)
                .cast::<*mut UObject>()
                .read_unaligned()
        };
        let raw_fname: u64 = unsafe {
            let fname_ptr = effect.field_ptr(STATUS_EFFECT_ROW_HANDLE + 8);
            (fname_ptr as *const u64).read_unaligned()
        };
        let row_name = unsafe {
            ueforge::ue::runtime()
                .name_resolver
                .to_string(std::mem::transmute::<u64, ueforge::ue::FName>(raw_fname))
        };
        let table_name = unsafe {
            table_ptr
                .as_ref()
                .map(|t| t.full_name())
                .unwrap_or_else(|| "<null-table>".to_string())
        };
        let row_meta = unsafe {
            table_ptr
                .as_ref()
                .and_then(|t| lookup_data_table_row(t, raw_fname).map(read_status_effect_row))
        };
        let (stat_type, value) = match row_meta {
            Some((ty, val)) => (Some(ty), Some(val)),
            None => (None, None),
        };
        entries.push(StatusEffectEntry {
            row: row_name,
            table: table_name,
            stat_type,
            value,
        });
    }
    entries
}


pub(crate) fn current_impact_resistance_level() -> u32 {
    tracker::with_state(|state| {
        state
            .skill_levels
            .get(skills::SKILL_IMPACT_RESISTANCE)
            .copied()
            .unwrap_or(0)
    })
    .unwrap_or(0)
}

