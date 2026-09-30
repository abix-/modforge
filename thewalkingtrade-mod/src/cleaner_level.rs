//! Body disposal from cleaner level 2 instead of 3.
//!
//! The game keeps `FloorWorkerJobSettings.DisposeCorpsesUnlockLevel = 3`
//! as a const, so the 3 is compiled into every check. Three places
//! gate it (read from the Cpp2IL dump, see docs/research.md):
//!
//! - `FloorWorkerMobGoalState.GetCurrentPolicy`: `cmp r8d,3` decides
//!   whether the cleaner's work policy may dispose of bodies.
//! - `FloorWorkerJobSettings.HasAnyValidWork`: `cmp edx,3` decides
//!   whether disposing alone counts as work (organise off).
//! - The settings window: the perk box with `LevelRequirement` 3
//!   greys the option out.
//!
//! The first two get their immediate byte patched 3 -> 2 in
//! GameAssembly.dll at startup; the third is written on the window
//! each time it opens (prefix on its `OnEnable`).

use std::ffi::c_void;

use serde_json::json;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

use crate::ctx_object;

const MODULE: &str = "GameAssembly.dll";
const NEW_LEVEL: u8 = 2;

/// `mov r10d,ecx; cmp r8d,3; jge +6; xor edx,edx; xor ecx,ecx; jmp;
/// test rax,rax; je; movzx edx,byte ptr [rax+11h]`. Immediate at +6.
const POLICY_SIG: &str = "44 8B D1 41 83 F8 03 7D 06 33 D2 33 C9 EB ?? 48 85 C0 74 ?? 0F B6 50 11";
const POLICY_IMM: usize = 6;

/// Whole start of HasAnyValidWork: `cmp edx,1; jl; cmp [rcx+10h],0;
/// jne; cmp edx,3; jl; cmp [rcx+11h],0; je; mov al,1; ret; cmp edx,4`.
/// Immediate at +13.
const VALID_WORK_SIG: &str =
    "83 FA 01 7C ?? 80 79 10 00 75 ?? 83 FA 03 7C ?? 80 79 11 00 74 ?? B0 01 C3 83 FA 04";
const VALID_WORK_IMM: usize = 13;

pub fn install() {
    match patch_prefix_ctx(
        "Il2CppRuntime.Staff.View.FloorWorkerJobSettingsView",
        "OnEnable",
        HookCtx::Instance,
        on_window_enable,
    ) {
        Ok(h) => HOOK_REGISTRY.register(h),
        Err(e) => log(
            LogLevel::Error,
            &format!("thewalkingtrade-mod: patch FloorWorkerJobSettingsView.OnEnable FAILED: {e}"),
        ),
    }
    for (name, sig, imm) in [
        ("cleaner_dispose_policy_level", POLICY_SIG, POLICY_IMM),
        ("cleaner_dispose_valid_work_level", VALID_WORK_SIG, VALID_WORK_IMM),
    ] {
        match patch_level(name, sig, imm) {
            Ok(addr) => log(
                LogLevel::Info,
                &format!("thewalkingtrade-mod: {name}: 3 -> {NEW_LEVEL} at 0x{addr:x}"),
            ),
            Err(e) => log(
                LogLevel::Error,
                &format!("thewalkingtrade-mod: {name} FAILED: {e}"),
            ),
        }
    }
}

fn patch_level(name: &'static str, sig: &str, imm: usize) -> Result<usize, String> {
    let hits = modforge::patterns::sleuth::scan_module_matches(MODULE, sig)
        .map_err(|e| format!("scan: {e}"))?;
    let [start] = hits[..] else {
        return Err(format!("expected 1 match, found {}: {hits:x?}", hits.len()));
    };
    let addr = start + imm;
    modforge::code_patch::patch_bytes(name, addr, &[NEW_LEVEL]).map_err(|e| e.to_string())?;
    Ok(addr)
}

/// Prefix on the cleaner settings window's `OnEnable`: lower its
/// level 3 perk box to 2 each time it opens, before it draws.
extern "C" fn on_window_enable(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: cleaner window open");
    let Some(view) = ctx_object(ctx) else { return 0 };
    if let Err(e) = lower_window(&view) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: cleaner window: {e}"));
    }
    0
}

fn lower_window(view: &MonoObject) -> Result<(), String> {
    let arr = view.read_field("_perksSettingsContainers")?;
    let Some(ah) = json_handle(&arr) else { return Ok(()) };
    let boxes = owned_object(ah);
    // Same getters, same order, as the client's count_of.
    let n = boxes
        .invoke("get_Length", &json!([]))
        .or_else(|_| boxes.invoke("get_Count", &json!([])))?
        .as_i64()
        .unwrap_or(0);
    for i in 0..n {
        let item = boxes.invoke("get_Item", &json!([i]))?;
        let Some(ch) = json_handle(&item) else { continue };
        let c = owned_object(ch);
        if c.read_field("LevelRequirement")?.as_i64() == Some(3) {
            c.write_field("LevelRequirement", &json!(NEW_LEVEL))?;
        }
    }
    Ok(())
}
