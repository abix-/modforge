use std::ffi::c_void;

use crate::bbp_log;
use crate::hook::{OriginalProcessEvent, ProcessEventHook};
use crate::rpg::{skills, tracker};
use crate::sdk::{UFunction, UObject, find_class_fast};

const PLAYER_FALL_HOOK_CLASSES: &[&str] = &[
    "BP_SurvivalPlayerCharacter_C",
    "BP_SurvivalPlayerCharacter_Female02_C",
    "BP_SurvivalPlayerCharacter_Gellarde_C",
];

const FN_ON_LANDED: &str = "OnLanded";

/// Cached UFunction pointer for `OnLanded` on the player BP
/// class. Resolved lazily on first sight of an OnLanded event.
/// All subsequent fires can pointer-compare instead of
/// allocating the function-name String. Eliminates ~1090
/// String allocations/sec from the trampoline fast path.
static ON_LANDED_UFUNCTION: std::sync::atomic::AtomicUsize =
    std::sync::atomic::AtomicUsize::new(0);

pub fn install() -> Result<Vec<ProcessEventHook>, &'static str> {
    let mut hooks = Vec::new();

    for &class_name in PLAYER_FALL_HOOK_CLASSES {
        if find_class_fast(class_name).is_none() {
            bbp_log!("rpg/fall: class {} not loaded yet, skipping", class_name);
            continue;
        }
        bbp_log!(
            "rpg/fall: hooking concrete player class {} for {} velocity-stomp",
            class_name,
            FN_ON_LANDED
        );
        let class_name_owned = class_name.to_string();
        let hook =
            ProcessEventHook::install(class_name, move |this, function, parms, original| {
                on_player_fall_event(&class_name_owned, this, function, parms, original)
            })?;
        hooks.push(hook);
    }

    if hooks.is_empty() {
        return Err("no concrete player classes were loaded for fall hook");
    }

    Ok(hooks)
}

fn on_player_fall_event(
    hook_class_name: &str,
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let _t = crate::counters::time_scope(&crate::counters::TIME_NS_FALL_HOOK);
    crate::counters::bump(&crate::counters::FALL_HOOK_FIRES);

    // Drain the debug PE queue here. The drain_pending fast path
    // is a single atomic load when the queue is empty (the
    // common case), so this is sub-ns when nothing is queued.
    crate::debug::drain_pending();

    let is_player = is_player_character(this);

    // FAST PATH: pointer-compare against the cached OnLanded
    // UFunction. If the cache is empty (cold start) we fall to
    // the slow path; otherwise non-OnLanded fires bail with a
    // single atomic load and one branch. ZERO allocations.
    let on_landed_ufunction = ON_LANDED_UFUNCTION.load(std::sync::atomic::Ordering::Relaxed);
    let is_on_landed = on_landed_ufunction != 0
        && (function as *const UFunction as usize) == on_landed_ufunction;
    if !is_on_landed && on_landed_ufunction != 0 {
        // Cache is populated and this is NOT the OnLanded
        // function. Forward without allocating fn_name.
        unsafe { original.call(this, function, parms) };
        return;
    }

    // Slow path runs for either:
    //   (1) the very first time we see any UFunction before the
    //       OnLanded cache is populated -- we need the name to
    //       check if THIS one is OnLanded
    //   (2) every subsequent OnLanded event (rare, ~per landing)
    // The earlier impact-trace diagnostic block (gated on
    // `impact_resistance > 0`) is intentionally OFF on the fast
    // path now -- the bandage research it was scaffolding for is
    // complete (see docs/damage.md). If we need that diagnostic
    // again, gate it behind a settings.debug.research flag, not
    // behind a skill level the user has on for normal gameplay.
    crate::counters::bump(&crate::counters::FALL_HOOK_FNNAME_ALLOCS);
    let fn_name = function.as_object().name();

    if on_landed_ufunction == 0 && fn_name == FN_ON_LANDED {
        ON_LANDED_UFUNCTION.store(
            function as *const UFunction as usize,
            std::sync::atomic::Ordering::Relaxed,
        );
    }

    // Velocity-stomp: works for fall landings (OnLanded fires before
    // native ApplyFallDamage reads live Velocity.Z). Does NOT work
    // for collisions (engine zeroes V.Z during collision response
    // before any PE event fires), so we only stomp on OnLanded now.
    //
    // OnLanded does not suppress; we forward to original so
    // animations and sounds still run.
    if is_player && fn_name == FN_ON_LANDED {
        let reduction = current_fall_resistance_reduction();
        if reduction > 0.0 {
            let scale = (1.0 - reduction).max(0.0) as f64;
            let stomped = stomp_player_velocity_z(this, scale);
            // Skip the log when V.Z was already zero -- the engine has
            // already absorbed the velocity and our stomp is a no-op.
            if stomped.before.abs() > 0.001 {
                bbp_log!(
                    "rpg/fall: stomped Velocity.Z {:.2} -> {:.2} on {} (reduction={:.3} via {})",
                    stomped.before,
                    stomped.after,
                    this.name(),
                    reduction,
                    hook_class_name
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

/// Look up a row in a `UDataTable` by FName, returning the row's
/// bytes pointer if found.
///
/// `UDataTable.RowMap` is `TMap<FName, uint8*>` at +0x30. UE's TMap
/// is `TSet<TPair<FName, uint8*>>` whose element type is
/// `TSetElement<TPair> { pair: 16, HashNextId: i32, HashIndex: i32 }`
/// = 24 bytes. The set's storage is a `TSparseArray` whose slots
/// are a union of (TSetElement) and (i32 PrevFreeIndex, i32
/// NextFreeIndex), sized to the larger = 24 bytes. So stride is
/// 24, not 16.
///
/// We walk all slots linearly and key-match. Free slots hold two
/// i32 free-list links in the first 8 bytes, which is extremely
/// unlikely to collide with a real FName u64. If we ever observe
/// a false hit, add the `AllocationFlags` TBitArray check at
/// +16 of the TMap.
pub(crate) fn lookup_data_table_row(table: &UObject, row_name: u64) -> Option<*const u8> {
    const ROW_MAP_OFFSET: usize = 0x0030;
    const ELEMENT_SIZE: usize = 24; // TSparseArray<TSetElement<TPair<FName,uint8*>>> slot
    unsafe {
        let row_map = table.field_ptr(ROW_MAP_OFFSET);
        let data_ptr = (row_map as *const *const u8).read_unaligned();
        let data_num = (row_map.add(8) as *const i32).read_unaligned();
        if data_ptr.is_null() || data_num <= 0 {
            return None;
        }
        let count = data_num as usize;
        for i in 0..count.min(8192) {
            let element = data_ptr.add(i * ELEMENT_SIZE);
            let key: u64 = (element as *const u64).read_unaligned();
            if key == row_name {
                let value: *const u8 = (element.add(8) as *const *const u8).read_unaligned();
                if !value.is_null() {
                    return Some(value);
                }
            }
        }
        None
    }
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
            crate::sdk::runtime()
                .name_resolver
                .to_string(std::mem::transmute::<u64, crate::sdk::FName>(raw_fname))
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

