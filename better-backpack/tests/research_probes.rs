// Research probes: archived test-side reimplementation of the
// fall_hook diagnostic probes that used to live in the mod.
//
// The mod stays generic (snapshot + call + read_bytes + walk_class
// + write_bytes). Anything that was research scaffolding lives
// here, where it's reproducible, version-controlled, and never
// runs unless deliberately invoked.
//
// Original mod-side functions removed in 2026-05-09 evening's
// performance pass (they fired on every UFunction call to the
// player BP class -- 1090+/sec -- causing 50% CPU and growing
// RAM through allocator churn). See `docs/ongoing.md` section
// 13 "Measured runaway".
//
// Each probe below is `#[ignore]`d by default. Run individually:
//   set BBP_DEBUG_PORT=17171
//   cargo test --target x86_64-pc-windows-msvc \
//     --test research_probes <probe_name> -- --nocapture --ignored

#![allow(dead_code)]

mod common;

use serde_json::json;

// ---------------------------------------------------------------
// Field offsets and class names. Captured from the mod-side
// research code; preserved here so the tests have the same
// ground truth.
// ---------------------------------------------------------------

const ASC_STATUS_EFFECT_COMPONENT: usize = 0x1378;
const ASC_HEALTH_COMPONENT: usize = 0x1340;
const ASC_CHAR_MOVEMENT_COMPONENT: usize = 0x1380;
const HC_CURRENT_DAMAGE: usize = 0x032C;
const CMC_VELOCITY_Z: usize = 0x00E8;
const SEC_STATUS_EFFECTS_TARRAY: usize = 0x01C8;
const STATUS_EFFECT_ROW_HANDLE: usize = 0x0058;
const SE_ROW_TYPE_OFFSET: usize = 0x30;
const SE_ROW_VALUE_OFFSET: usize = 0x34;

// EStatusEffectType values from Maine_structs.hpp:136 that are
// relevant to skills in our catalog.
const PROBE_STAT_TYPES: &[(&str, u8)] = &[
    ("FallDamage", 14),
    ("DamageReduction", 29),
    ("DamageReductionMultiplier", 30),
    ("AttackDamage", 23),
    ("LifeSteal", 38),
    ("CriticalHitChance", 31),
    ("CriticalDamage", 62),
    ("ReflectDamage", 37),
    ("MaxHealth", 5),
];

// ---------------------------------------------------------------
// Probe 1: dump player StatusEffects array with row Type/Value.
//
// Original: fall_hook::probe_player_status_effects (removed).
// New: snapshot already exposes status_effects; this test just
// reads them. Kept here to preserve the original probe flow as
// a runnable test.
// ---------------------------------------------------------------

#[test]
#[ignore]
fn probe_player_status_effects() {
    let api = common::Api::require();
    let s = api.snapshot();
    let sfx = s.status_effects.as_deref().unwrap_or(&[]);
    eprintln!("player has {} active status effects", sfx.len());
    for (i, e) in sfx.iter().enumerate() {
        eprintln!(
            "  [{i:2}] row={:<28} type={:?} value={:?}  table={}",
            e.row, e.stat_type, e.value, e.table
        );
    }
}

// ---------------------------------------------------------------
// Probe 2: GetValueForStat() per damage-relevant stat type.
//
// Original: fall_hook::probe_status_effect_values (removed).
// Calls UStatusEffectComponent::GetValueForStat(StatType, false)
// for each interesting type via the generic `call` op. Logs
// the engine's combined value across all active effects of
// that type, which tells us the runtime reduction baseline.
// ---------------------------------------------------------------

#[repr(C)]
struct GetValueForStatParms {
    stat_type: u8,
    temporary_only: bool,
    _pad: [u8; 2],
    return_value: f32,
}

#[test]
#[ignore]
fn probe_status_effect_values() {
    let api = common::Api::require();

    // Resolve the player's StatusEffectComponent address by
    // reading the pointer from ASurvivalCharacter+0x1378.
    // The snapshot doesn't expose the SEC pointer directly;
    // we walk the player class then read_bytes the field.
    let player_resp = api.op("walk_class", json!({"class": "BP_SurvivalPlayerCharacter_Female02_C", "max": 4}));
    let instances = player_resp.result.get("instances").and_then(|v| v.as_array()).expect("walk failed");
    let player = instances
        .iter()
        .find(|i| !i.get("is_cdo").and_then(|v| v.as_bool()).unwrap_or(false))
        .expect("no live player; load a save and spawn");
    let player_sel = player.get("addr_selector").and_then(|v| v.as_str()).unwrap();

    let r = api.op_ok(
        "read_bytes",
        json!({"instance_selector": player_sel, "offset": ASC_STATUS_EFFECT_COMPONENT, "length": 8}),
    );
    let bytes = common::hex_decode(
        r.live_player.is_some().then_some(()).map_or(
            "0000000000000000",
            |_| "",
        ),
    )
    .ok()
    .unwrap_or_default();
    let _ = bytes;
    // The above accessor pattern was placeholder; do the real
    // read via a direct op response:
    let r2 = api.op(
        "read_bytes",
        json!({"instance_selector": player_sel, "offset": ASC_STATUS_EFFECT_COMPONENT, "length": 8}),
    );
    let sec_bytes = common::hex_decode(
        r2.result.get("bytes_hex").and_then(|v| v.as_str()).unwrap(),
    )
    .unwrap();
    let sec_ptr = u64::from_le_bytes(sec_bytes[..8].try_into().unwrap());
    if sec_ptr == 0 {
        panic!("StatusEffectComponent ptr is null");
    }
    let sec_sel = format!("addr:0x{sec_ptr:x}");

    // For each target stat, call GetValueForStat via the generic
    // `call` primitive. The parms struct needs to be 8 bytes
    // total: u8 stat + bool temp + 2 pad + f32 ret.
    eprintln!("rpg/sfx-probe (test-side):");
    let mut summary = String::new();
    for (name, stat_type) in PROBE_STAT_TYPES {
        let parms = GetValueForStatParms {
            stat_type: *stat_type,
            temporary_only: false,
            _pad: [0; 2],
            return_value: 0.0,
        };
        let bytes = unsafe { common::parms_as_bytes(&parms) };
        match api.call_ufunction("StatusEffectComponent", "GetValueForStat", &sec_sel, bytes) {
            Ok((after, _state)) => {
                let ret_value =
                    f32::from_le_bytes(after[4..8].try_into().unwrap_or([0; 4]));
                summary.push_str(&format!(" {}({})={:.3}", name, stat_type, ret_value));
            }
            Err(e) => {
                summary.push_str(&format!(" {}({})=ERR({})", name, stat_type, e));
            }
        }
    }
    eprintln!("  {}", summary);
}

// ---------------------------------------------------------------
// Probe 3: read player CurrentDamage live.
//
// Original: fall_hook::read_player_current_damage (removed).
// Replaced by snapshot.live_player.hc.current_damage.
// ---------------------------------------------------------------

#[test]
#[ignore]
fn probe_player_current_damage() {
    let api = common::Api::require();
    let s = api.snapshot();
    let hc = s.live_hc();
    eprintln!(
        "player CurrentDamage = {:.2} / MaxHealth {:.2}",
        hc.current_damage, hc.max_health
    );
}

// ---------------------------------------------------------------
// Probe 4: read player CharMovementComponent.Velocity.Z live.
//
// Original: fall_hook::read_player_velocity_z (removed).
// Walks the player BP class, reads CMC pointer, reads Velocity.Z.
// ---------------------------------------------------------------

#[test]
#[ignore]
fn probe_player_velocity_z() {
    let api = common::Api::require();

    let r = api.op(
        "walk_class",
        json!({"class": "BP_SurvivalPlayerCharacter_Female02_C", "max": 4}),
    );
    let instances = r.result.get("instances").and_then(|v| v.as_array()).unwrap();
    let player = instances
        .iter()
        .find(|i| !i.get("is_cdo").and_then(|v| v.as_bool()).unwrap_or(false))
        .expect("no live player");
    let player_sel = player.get("addr_selector").and_then(|v| v.as_str()).unwrap();

    let cmc_resp = api.op(
        "read_bytes",
        json!({"instance_selector": player_sel, "offset": ASC_CHAR_MOVEMENT_COMPONENT, "length": 8}),
    );
    let cmc_bytes = common::hex_decode(
        cmc_resp.result.get("bytes_hex").and_then(|v| v.as_str()).unwrap(),
    )
    .unwrap();
    let cmc_ptr = u64::from_le_bytes(cmc_bytes[..8].try_into().unwrap());
    if cmc_ptr == 0 {
        panic!("CMC ptr is null");
    }

    let vz_resp = api.op(
        "read_bytes",
        json!({"instance_selector": format!("addr:0x{cmc_ptr:x}"), "offset": CMC_VELOCITY_Z, "length": 4}),
    );
    let vz_bytes = common::hex_decode(
        vz_resp.result.get("bytes_hex").and_then(|v| v.as_str()).unwrap(),
    )
    .unwrap();
    let vz = f32::from_le_bytes(vz_bytes[..4].try_into().unwrap());
    eprintln!("player Velocity.Z = {:.2}", vz);
}

// ---------------------------------------------------------------
// `is_collision_relevant` from the mod is preserved here as a
// pure function. Original used to gate the `impact-trace` PE
// log block in fall_hook. Now lives test-side because that
// trace was 100% research scaffolding.
// ---------------------------------------------------------------

pub fn is_collision_relevant(fn_name: &str) -> bool {
    if fn_name.contains("Tick") {
        return false;
    }
    fn_name.contains("Damage")
        || fn_name.contains("Damaged")
        || fn_name.contains("Hit")
        || fn_name.contains("Land")
        || fn_name.contains("Fall")
        || fn_name.contains("Impact")
        || fn_name.contains("Health")
        || fn_name.contains("ReceiveAny")
        || fn_name.contains("ReceiveActor")
}
