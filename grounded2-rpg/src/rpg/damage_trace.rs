// Damage diagnostic instrumentation. Records every PE event arriving
// on the player's HealthComponent into the debug damage_ring + log
// trail. Surfaces everything (heal candidates, multicast notifications,
// ApplyDamage variants) so research has a single source of ground
// truth for what fires when the player takes / receives damage.
//
// Read-only. Lives in its own module so the kill hook stays focused
// on kill credit.

use std::ffi::c_void;

use ueforge::ue::{TypedField, UFunction, UObject};

use crate::counters;
use crate::debug;

const HC_CURRENT_DAMAGE_OFFSET: usize = 0x032C;
const HC_CURRENT_DAMAGE: TypedField<f32> = TypedField::at(HC_CURRENT_DAMAGE_OFFSET);

/// Decoded `(damage, damage_flags, type_flags)` for the per-fn parm
/// shapes we know about. Returns `None` for non-damage fns; the
/// caller treats those as record-only entries.
fn decode_parms(fn_name: &str, parms: *const u8) -> Option<(f32, i32, u32)> {
    if parms.is_null() {
        return None;
    }
    let triple = match fn_name {
        "MulticastHandleEffectsWithDamageFlags" => unsafe {
            (
                parms.add(0x18).cast::<f32>().read_unaligned(),
                parms.add(0x1C).cast::<i32>().read_unaligned(),
                parms.add(0x20).cast::<u32>().read_unaligned(),
            )
        },
        "MulticastHandleEffectsWithDamageFlagsAtOwnerLocation"
        | "MulticastHandleEffectsWithDamageFlagsAndInflictStyleAtOwnerLocation" => unsafe {
            (
                parms.add(0x00).cast::<f32>().read_unaligned(),
                parms.add(0x04).cast::<i32>().read_unaligned(),
                parms.add(0x08).cast::<u32>().read_unaligned(),
            )
        },
        "ApplyDamageFromInfo" => unsafe {
            (parms.add(0x00).cast::<f32>().read_unaligned(), 0, 0)
        },
        _ => return None,
    };
    Some(triple)
}

fn now_secs() -> u64 {
    std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_secs())
        .unwrap_or(0)
}

/// Record one PE fire on the player's HC. Always pushes a damage_ring
/// entry; logs the loud line only for known damage fns. Returns `true`
/// if the fn looked like a damage event (caller may want to dump the
/// FDamageInfo afterwards).
pub fn observe(this: &UObject, function: &UFunction, parms: *mut c_void) -> bool {
    let fn_name = function.as_object().name();
    let cd_now = unsafe { HC_CURRENT_DAMAGE.read(this) };
    let at_secs = now_secs();

    match decode_parms(&fn_name, parms as *const u8) {
        Some((damage, damage_flags, type_flags)) => {
            ueforge::counters::bump(&counters::KILL_HOOK_LOG_LINES);
            ueforge::log!(
                "rpg/dmg-trace: fn={} damage={:.2} flags=0x{:08x} type_flags=0x{:08x}",
                fn_name,
                damage,
                damage_flags,
                type_flags
            );
            debug::record_damage_event(debug::DamageEvent {
                at_secs,
                function: fn_name,
                damage,
                damage_flags,
                type_flags,
                current_damage_before: Some(cd_now),
                current_damage_after: None,
            });
            true
        }
        None => {
            // Quiet capture so the ring shows everything (heal
            // candidates included) without spamming the log.
            debug::record_damage_event(debug::DamageEvent {
                at_secs,
                function: fn_name,
                damage: 0.0,
                damage_flags: 0,
                type_flags: 0,
                current_damage_before: Some(cd_now),
                current_damage_after: None,
            });
            false
        }
    }
}

/// Snapshot CurrentDamage before + after `original.call`, log if the
/// delta is non-trivial. The non-zero-delta case identifies the fn
/// as the damage-application path (vs notification-only).
pub fn trace_current_damage_delta(this: &UObject, before: f32) {
    let after = unsafe { HC_CURRENT_DAMAGE.read(this) };
    if (after - before).abs() > 0.001 {
        ueforge::log!(
            "rpg/dmg-trace:   CurrentDamage before={:.2} after={:.2} delta={:.2}",
            before,
            after,
            after - before
        );
    }
}

pub fn read_current_damage(this: &UObject) -> f32 {
    unsafe { HC_CURRENT_DAMAGE.read(this) }
}

/// Dump the FDamageInfo (0xE8 bytes at HealthComponent +0x3B0) that
/// the engine populated for the damage event currently being
/// processed.
pub fn log_last_damage_info(hc: &UObject) {
    use crate::rpg::kill_hook::DAMAGE_INFO;
    use ueforge::ue::actor::describe;

    // FVector hit location: 3 doubles at +0x008 inside the struct.
    const HIT_LOCATION_REL: usize = 0x008;
    const DAMAGE_SOURCE_TYPE_REL: usize = 0x06A;

    let base = DAMAGE_INFO.last_damage_info_offset;
    let damage_type_name = DAMAGE_INFO.damage_type_name(hc);
    let dflags = DAMAGE_INFO.damage_flags(hc);
    let instigator = DAMAGE_INFO.instigator(hc);
    let source = DAMAGE_INFO.damage_source(hc);

    let read_f64 = |off: usize| -> f64 {
        unsafe { hc.field_ptr(off).cast::<f64>().read_unaligned() }
    };
    let hit_x = read_f64(base + HIT_LOCATION_REL);
    let hit_y = read_f64(base + HIT_LOCATION_REL + 8);
    let hit_z = read_f64(base + HIT_LOCATION_REL + 16);

    let source_type: u8 = unsafe {
        hc.field_ptr(base + DAMAGE_SOURCE_TYPE_REL)
            .cast::<u8>()
            .read_unaligned()
    };

    ueforge::log!(
        "rpg/dmg-trace:   LastDamageInfo: DamageType={} src_type={} flags=0x{:08x} hit=({:.0},{:.0},{:.0})",
        damage_type_name,
        source_type,
        dflags,
        hit_x,
        hit_y,
        hit_z
    );
    ueforge::log!(
        "rpg/dmg-trace:   instigator={} source={}",
        describe(instigator),
        describe(source)
    );
}
