// Grounded 2 - RPG System -- Grounded 2 mod, loaded by UE4SS as a CPPMod via the
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

use ueforge::ue::offsets::{STEAM, XBOX};

static MOD_INFO: ueforge::ModInfo = ueforge::ModInfo {
    name: "Grounded2RPG",
    version: "0.1.0",
    log_file: "grounded2_rpg.log",
    console_title: "Grounded 2 - RPG System",
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
    // Run heavy init off the engine init thread so any panic doesn't
    // propagate up into UE4SS. ueforge::worker::spawn names the
    // thread + catches panics with a logged message.
    ueforge::worker::spawn("grounded2_rpg/init", || unsafe { worker() });
}

fn bbp_on_shutdown() {
    // Hooks are leaked intentionally so they survive worker thread
    // exit (and process teardown). The slot poller, however, owns
    // a worker thread that needs an explicit stop signal so it
    // doesn't outlive an unloaded DLL during hot-reload.
    rpg::world_loader::shutdown();
    ueforge::log!("grounded2-rpg: shutdown");
}

unsafe fn worker() {
    // Logger is already initialized by ue4ss_mod!'s on_unreal_init hook
    // (it runs ueforge::log::init before calling MOD_INFO.on_unreal_init).
    ueforge::log!("=== Grounded 2 - RPG System DLL (rust) ===");
    let settings =
        ueforge::settings::Settings::<settings::Settings>::load("settings.json").get();
    settings.log_summary();
    ueforge::log!(
        "vanilla main = {}, vanilla mount = {} (left untouched)",
        patch::VANILLA_MAIN,
        patch::VANILLA_MOUNT
    );

    const PLATFORMS: &[(&str, &ueforge::ue::PlatformOffsets)] = &[
        ("Grounded2-WinGRTS-Shipping.exe", &STEAM),
        ("Grounded2-WinGDK-Shipping.exe", &XBOX),
    ];
    let _rt = ueforge::ue::platform::detect_and_init(PLATFORMS);

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

    // Install the inventory-interface hook with exponential backoff.
    // The class isn't loaded into GObjects until the inventory UI
    // opens for the first time. ueforge::hook::install_with_backoff
    // owns the retry loop + log lines + timeout.
    if let Some(h) = ueforge::hook::install_with_backoff(
        "inv hook",
        ueforge::hook::RetryPolicy::default_install(),
        || inv_hook::install(settings.inventory.slot_count),
    ) {
        ueforge::log!("inv hook: installed on {}", h.class_name());
        std::mem::forget(h);
    }

    ueforge::hook::install_immediate_or_log(
        "rpg/kill",
        rpg::kill_hook::install,
        |h| h.class_name(),
    );

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

