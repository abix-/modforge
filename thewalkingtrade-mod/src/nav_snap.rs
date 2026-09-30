//! Cleaners no longer hang when told to walk to a point in the air
//! (docs/research.md "Cleaner stuck carrying an item").
//!
//! Vanilla (Cpp2IL dump 1.2.5): the cleaner item step walks to a
//! shelf's front point, which on a wall-mounted shelf sits at the
//! shelf's own height (2.15 m for a top wall shelf, read live), and
//! calls `SetDestination(point, useSamplePosition: false)`, so the
//! point is not snapped to the floor. No path can be made, the
//! navigator is not "stuck" (it is not moving), and the step waits
//! forever. Shown live: a hire sent to the 2.15 m front point never
//! paths; to the 0.57 m one he walks.
//!
//! Two changes, both the game's own mechanism:
//! - byte patch: that one call passes `useSamplePosition: true`, so the
//!   navigator snaps the point to the nearest walkable floor
//!   (`NavMesh.SamplePosition` in `TryCalculateAndApplyPathAsync`);
//! - the snap searches within the navigator's `_offMeshRecoveryRadius`
//!   (1.0 m, read live), too short from 2.15 m up, so hires' navigators
//!   get SNAP_RADIUS, set in a prefix on `RigidbodyNavigator.Awake`.

use std::ffi::c_void;

use serde_json::json;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, log};

use crate::ctx_object;

const MODULE: &str = "GameAssembly.dll";

/// The item step's call, read from the 1.2.5 DLL
/// (`MoveToMostAppropriatePosition`): `movss [rsp+0C8h],xmm11; mov
/// r10,[rax+2A8h]; mov rax,[rax+2B0h]; mov [rsp+20h],rax; xor r9d,r9d;
/// lea r8,[rsp+0C0h]; lea rcx,[rsp+80h]; call r10`. Matches once in
/// every code section (`spiked_wall_bytes`).
const CALL_SIG: &str = "F3 44 0F 11 9C 24 C8 00 00 00 4C 8B 90 A8 02 00 00 48 8B 80 B0 02 00 00 48 89 44 24 20 45 33 C9 4C 8D 84 24 C0 00 00 00 48 8D 8C 24 80 00 00 00 41 FF D2";
/// Where `xor r9d,r9d` (45 33 C9) sits in a match.
const XOR_AT: usize = 29;
/// `mov r9b, 1`: same length; a bool argument only uses the low byte.
const PASS_TRUE: [u8; 3] = [0x41, 0xB1, 0x01];

/// Snap reach for hires, metres: more than a top wall shelf's height.
const SNAP_RADIUS: f64 = 3.0;

pub fn install() {
    match patch() {
        Ok(addr) => log(
            LogLevel::Info,
            &format!("thewalkingtrade-mod: cleaner destination snaps to floor, patched at 0x{addr:x}"),
        ),
        Err(e) => log(LogLevel::Error, &format!("thewalkingtrade-mod: nav snap FAILED: {e}")),
    }
    match patch_prefix_ctx("Il2CppRuntime.Mob.Navigation.RigidbodyNavigator", "Awake", HookCtx::Instance, on_awake) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(LogLevel::Error, &format!("thewalkingtrade-mod: patch RigidbodyNavigator.Awake FAILED: {e}")),
    }
}

fn patch() -> Result<usize, String> {
    let hits = modforge::patterns::sleuth::scan_module_matches(MODULE, CALL_SIG).map_err(|e| format!("scan: {e}"))?;
    let [start] = hits[..] else {
        return Err(format!("expected 1 match, found {}: {hits:x?}", hits.len()));
    };
    let at = start + XOR_AT;
    modforge::code_patch::patch_bytes("cleaner_destination_snap", at, &PASS_TRUE).map_err(|e| e.to_string())?;
    Ok(at)
}

/// Hires only: their game object is a `StaffMobPrefab` / `ChildStaffMobPrefab`.
extern "C" fn on_awake(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: navigator awake");
    let Some(nav) = ctx_object(ctx) else { return 0 };
    let set = || -> Result<(), String> {
        let name = nav.invoke("ToString", &json!([]))?;
        if !name.as_str().is_some_and(|s| s.contains("StaffMob")) {
            return Ok(());
        }
        nav.write_field("_offMeshRecoveryRadius", &json!(SNAP_RADIUS))
    };
    if let Err(e) = set() {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: nav snap radius: {e}"));
    }
    0
}
