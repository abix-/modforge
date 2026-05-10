// Better Backpack -- Grounded 2 mod, loaded by UE4SS as a CPPMod via the
// stock ueforge shim. ueforge::ue4ss_mod! generates DllMain + every
// extern "C" hook the shim invokes; we only declare ModInfo + the two
// callbacks (on_unreal_init / on_shutdown) and the RPG tab render
// function.

#![allow(clippy::missing_safety_doc)]

pub mod counters;
pub mod debug;
pub mod inv_hook;
pub mod parms;
pub mod patch;
pub mod rpg;
pub mod settings;
pub mod survival;

use std::ffi::c_void;
use std::ptr;
use std::thread;
use std::time::Duration;

use windows_sys::Win32::Foundation::CloseHandle;
use windows_sys::Win32::System::Threading::CreateThread;

use ueforge::ue::offsets::{STEAM, XBOX};

const HOOK_RETRY_BASE_DELAY_MS: u64 = 500;
const HOOK_RETRY_MAX_DELAY_MS: u64 = 5_000;
const HOOK_RETRY_TIMEOUT_SEC: u64 = 600; // 10 min hard cap before giving up

static MOD_INFO: ueforge::ModInfo = ueforge::ModInfo {
    name: "BetterBackpack",
    version: "0.1.0",
    log_file: "better_backpack.log",
    console_title: "Better Backpack",
    console: cfg!(feature = "console"),
    on_unreal_init: bbp_on_unreal_init,
    on_shutdown: bbp_on_shutdown,
    tabs: &[ueforge::Tab {
        name: "RPG",
        render: rpg::tab::render,
    }],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn bbp_on_unreal_init() {
    // Spawn the worker thread off the engine init thread so any panic
    // we hit doesn't propagate up into UE4SS.
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

fn bbp_on_shutdown() {
    // Hooks are leaked intentionally so they survive worker thread exit
    // (and process teardown). Nothing to clean up here today.
}

unsafe extern "system" fn worker_entry(_lpv: *mut c_void) -> u32 {
    let _ = std::panic::catch_unwind(|| unsafe { worker() });
    0
}

unsafe fn worker() {
    // Logger is already initialized by ue4ss_mod!'s on_unreal_init hook
    // (it runs ueforge::log::init before calling MOD_INFO.on_unreal_init).
    ueforge::log!("=== Better Backpack DLL (rust) ===");
    let settings = settings::load();
    settings.log_summary();
    ueforge::log!(
        "vanilla main = {}, vanilla mount = {} (left untouched)",
        patch::VANILLA_MAIN,
        patch::VANILLA_MOUNT
    );

    let image_base = ueforge::ue::platform::host_image_base();
    const PLATFORMS: &[(&str, &ueforge::ue::PlatformOffsets)] = &[
        ("Grounded2-WinGRTS-Shipping.exe", &STEAM),
        ("Grounded2-WinGDK-Shipping.exe", &XBOX),
    ];
    let offsets = ueforge::ue::platform::detect(PLATFORMS).unwrap_or_else(|| {
        let exe = ueforge::ue::platform::host_exe_name().unwrap_or_default();
        ueforge::log!(
            "WARN: unknown host exe '{}'; defaulting to Steam offsets",
            exe
        );
        &STEAM
    });
    ueforge::log!(
        "image_base = 0x{:x}, GObjects = 0x{:x}",
        image_base,
        image_base + offsets.g_objects
    );

    let _rt = unsafe { ueforge::ue::init_runtime(image_base, offsets) };

    // Capture vanilla survival rates before any patching so the RPG
    // apply step can multiply them later without compounding.
    rpg::apply::capture_vanilla();

    let initial = patch::run(settings.inventory.slot_count);
    ueforge::log!(
        "initial patch round: scanned={}, patched={}, skipped_non_player={}",
        initial.scanned,
        initial.patched,
        initial.skipped_non_player
    );

    let surv = survival::run(
        settings.survival.thirst_multiplier,
        settings.survival.hunger_multiplier,
    );
    ueforge::log!(
        "survival patch: scanned_classes={}, patched={}",
        surv.scanned_classes,
        surv.patched
    );

    // Install the inventory-interface hook with exponential backoff. The
    // class isn't loaded into GObjects until the inventory UI opens for
    // the first time.
    match install_inv_hook_with_backoff(settings.inventory.slot_count) {
        Some(h) => {
            ueforge::log!("inv hook: installed on {}", h.class_name());
            std::mem::forget(h);
        }
        None => {
            ueforge::log!(
                "inv hook: gave up after {}s; scrolling will not work this session",
                HOOK_RETRY_TIMEOUT_SEC
            );
        }
    }

    match rpg::kill_hook::install() {
        Ok(h) => {
            ueforge::log!("rpg/kill: installed on {}", h.class_name());
            std::mem::forget(h);
        }
        Err(e) => {
            ueforge::log!("rpg/kill: install failed ({}); spike A inactive", e);
        }
    }

    match rpg::fall_hook::install() {
        Ok(hooks) => {
            for h in hooks {
                ueforge::log!("rpg/fall: installed on {}", h.class_name());
                std::mem::forget(h);
            }
        }
        Err(e) => {
            ueforge::log!("rpg/fall: concrete player fall hook install failed ({})", e);
        }
    }

    rpg::world_loader::spawn(settings.clone());

    if let Some(port) = settings.debug.http_port {
        debug::spawn(port);
    }

    ueforge::log!("init complete; worker thread exiting");
}

fn install_inv_hook_with_backoff(slot_count: i32) -> Option<ueforge::hook::ProcessEventHook> {
    let mut delay_ms = HOOK_RETRY_BASE_DELAY_MS;
    let deadline = std::time::Instant::now() + Duration::from_secs(HOOK_RETRY_TIMEOUT_SEC);
    let mut last_err: Option<&str> = None;
    loop {
        match inv_hook::install(slot_count) {
            Ok(h) => return Some(h),
            Err(e) => {
                if last_err != Some(e) {
                    ueforge::log!("inv hook: pending ({}), will retry", e);
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
