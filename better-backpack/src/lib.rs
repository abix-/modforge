// Better Backpack -- Grounded 2 mod, loaded by UE4SS as a CPPMod.
//
// UE4SS lifecycle for our DLL:
//   1. UE4SS loads main.dll. DllMain captures our HMODULE so log + settings
//      can resolve their on-disk path.
//   2. UE4SS calls our exported start_mod() -> a C++ shim
//      (cpp/shim.cpp) returns a heap-allocated BetterBackpackMod
//      instance derived from RC::CppUserModBase.
//   3. Once the engine is initialized, UE4SS calls
//      BetterBackpackMod::on_unreal_init(), which calls
//      better_backpack_start() defined here. That spins up the worker
//      thread.
//   4. The worker patches CDOs (backpack capacity, hunger/thirst
//      rates), installs the WBP_InventoryInterface_C ProcessEvent
//      hook with exponential backoff, and exits.
//   5. On unload, UE4SS calls uninstall_mod which deletes the shim
//      instance, which calls better_backpack_stop() (currently a
//      no-op).
//
// Net runtime cost after init: zero. Worker thread terminates.
// Earlier "wait_for_gobjects" loop is gone -- UE4SS calls
// on_unreal_init after the engine is init'd, GObjects is already
// populated.

#![allow(clippy::missing_safety_doc)]

pub mod hook;
pub mod inv_hook;
pub mod log;
pub mod parms;
pub mod patch;
pub mod rpg;
pub mod sdk;
pub mod settings;
pub mod survival;

use std::ffi::{OsString, c_void};
use std::os::windows::ffi::OsStringExt;
use std::ptr;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::thread;
use std::time::Duration;

use windows_sys::Win32::Foundation::{CloseHandle, HMODULE};
use windows_sys::Win32::System::LibraryLoader::{GetModuleFileNameW, GetModuleHandleW};
use windows_sys::Win32::System::SystemServices::DLL_PROCESS_ATTACH;
use windows_sys::Win32::System::Threading::CreateThread;

use crate::sdk::offsets::{Platform, STEAM, XBOX};

#[allow(clippy::upper_case_acronyms)]
type BOOL = i32;
const TRUE: BOOL = 1;

const HOOK_RETRY_BASE_DELAY_MS: u64 = 500;
const HOOK_RETRY_MAX_DELAY_MS: u64 = 5_000;
const HOOK_RETRY_TIMEOUT_SEC: u64 = 600; // 10 min hard cap before giving up

/// Captured in DllMain so other modules (e.g. log, settings) can resolve
/// our own DLL's directory via GetModuleFileNameW.
pub static DLL_HMODULE: AtomicUsize = AtomicUsize::new(0);

#[unsafe(no_mangle)]
#[allow(non_snake_case)]
pub extern "system" fn DllMain(hmod: HMODULE, reason: u32, _reserved: *mut c_void) -> BOOL {
    if reason == DLL_PROCESS_ATTACH {
        DLL_HMODULE.store(hmod as usize, Ordering::Release);
    }
    TRUE
}

/// Entry point called from the C++ UE4SS shim's
/// BetterBackpackMod::on_unreal_init.
#[unsafe(no_mangle)]
pub extern "C" fn better_backpack_start() {
    // Spawn the worker thread off the engine init thread so any panic
    // we might hit doesn't propagate up into UE4SS.
    unsafe {
        let h = CreateThread(
            ptr::null(),
            0,
            Some(worker_entry),
            ptr::null(),
            0,
            ptr::null_mut(),
        );
        if !h.is_null() {
            CloseHandle(h);
        }
    }
}

/// Entry point called from the C++ UE4SS shim's
/// BetterBackpackMod::~BetterBackpackMod. Currently a no-op -- our
/// hooks are leaked intentionally so they survive worker thread exit.
#[unsafe(no_mangle)]
pub extern "C" fn better_backpack_stop() {}

unsafe extern "system" fn worker_entry(_lpv: *mut c_void) -> u32 {
    let _ = std::panic::catch_unwind(|| unsafe { worker() });
    0
}

unsafe fn worker() {
    log::init();
    bbp_log!("=== Better Backpack DLL (rust) ===");
    let settings = settings::load();
    settings.log_summary();
    bbp_log!(
        "vanilla main = {}, vanilla mount = {} (left untouched)",
        patch::VANILLA_MAIN,
        patch::VANILLA_MOUNT
    );

    let image_base = unsafe { sdk_image_base() };
    let exe_name = host_exe_name().unwrap_or_default();
    let platform = match exe_name.as_str() {
        "Grounded2-WinGRTS-Shipping.exe" => Platform::Steam,
        "Grounded2-WinGDK-Shipping.exe" => Platform::Xbox,
        other => {
            bbp_log!(
                "WARN: unknown host exe '{}'; defaulting to Steam offsets",
                other
            );
            Platform::Steam
        }
    };
    let offsets = match platform {
        Platform::Steam => &STEAM,
        Platform::Xbox => &XBOX,
    };
    bbp_log!(
        "platform = {:?}, image_base = 0x{:x}, GObjects = 0x{:x}",
        platform,
        image_base,
        image_base + offsets.g_objects
    );

    let _rt = unsafe { sdk::init_runtime(image_base, offsets) };

    // UE4SS only calls our on_unreal_init after the engine has fully
    // initialized, so GObjects is already populated. No retry loop
    // needed.

    // Capture vanilla survival rates before any patching so the RPG
    // apply step can multiply them later without compounding.
    rpg::apply::capture_vanilla();

    let initial = patch::run(settings.inventory.slot_count);
    bbp_log!(
        "initial patch round: scanned={}, patched={}, skipped_non_player={}",
        initial.scanned,
        initial.patched,
        initial.skipped_non_player
    );

    let surv = survival::run(
        settings.survival.thirst_multiplier,
        settings.survival.hunger_multiplier,
    );
    bbp_log!(
        "survival patch: scanned_classes={}, patched={}",
        surv.scanned_classes,
        surv.patched
    );

    // Install the inventory-interface hook with exponential backoff. The
    // class isn't loaded into GObjects until the inventory UI opens for
    // the first time. We retry until install succeeds or we hit the
    // timeout. After install, this thread exits and the mod's runtime
    // overhead drops to zero.
    match install_inv_hook_with_backoff(settings.inventory.slot_count) {
        Some(h) => {
            bbp_log!("inv hook: installed on {}", h.class_name());
            // Leak the hook so it lives for the lifetime of the process.
            // Drop-on-thread-exit would unhook the trampoline immediately.
            std::mem::forget(h);
        }
        None => {
            bbp_log!(
                "inv hook: gave up after {}s; scrolling will not work this session",
                HOOK_RETRY_TIMEOUT_SEC
            );
        }
    }

    // RPG spike A: kill detection. Hook HealthComponent and log every
    // creature death with the killer. HealthComponent is a native class
    // loaded with the engine, so install should succeed on first try.
    match rpg::kill_hook::install() {
        Ok(h) => {
            bbp_log!("rpg/kill: installed on {}", h.class_name());
            std::mem::forget(h);
        }
        Err(e) => {
            bbp_log!("rpg/kill: install failed ({}); spike A inactive", e);
        }
    }

    match rpg::fall_hook::install() {
        Ok(hooks) => {
            for h in hooks {
                bbp_log!("rpg/fall: installed on {}", h.class_name());
                std::mem::forget(h);
            }
        }
        Err(e) => {
            bbp_log!("rpg/fall: concrete player fall hook install failed ({})", e);
        }
    }

    // RPG spike B + eager load: poll for AInGameGameState on a separate
    // thread so PlayerState is bound to the active save the moment the
    // player enters the world. Future skill-driven CDO patches will run
    // on the same activation transition.
    rpg::world_loader::spawn(settings.clone());

    bbp_log!("init complete; worker thread exiting");
}

fn install_inv_hook_with_backoff(slot_count: i32) -> Option<hook::ProcessEventHook> {
    let mut delay_ms = HOOK_RETRY_BASE_DELAY_MS;
    let deadline = std::time::Instant::now() + Duration::from_secs(HOOK_RETRY_TIMEOUT_SEC);
    let mut last_err: Option<&str> = None;
    loop {
        match inv_hook::install(slot_count) {
            Ok(h) => return Some(h),
            Err(e) => {
                if last_err != Some(e) {
                    bbp_log!("inv hook: pending ({}), will retry", e);
                    last_err = Some(e);
                }
            }
        }
        if std::time::Instant::now() >= deadline {
            return None;
        }
        thread::sleep(Duration::from_millis(delay_ms));
        delay_ms = (delay_ms * 2).min(HOOK_RETRY_MAX_DELAY_MS);
    }
}

unsafe fn sdk_image_base() -> usize {
    let h = unsafe { GetModuleHandleW(ptr::null()) };
    h as usize
}

fn host_exe_name() -> Option<String> {
    let mut buf = [0u16; 1024];
    let n = unsafe { GetModuleFileNameW(ptr::null_mut(), buf.as_mut_ptr(), buf.len() as u32) };
    if n == 0 {
        return None;
    }
    let path = OsString::from_wide(&buf[..n as usize])
        .to_string_lossy()
        .into_owned();
    let last = path.rsplit(['/', '\\']).next()?.to_string();
    Some(last)
}
