//! Outworld Station Tweaks.
//!
//! Multi-mod scaffold. First feature: item stack tweaks. Layered
//! on top of uespy's UE4SS / debug / UI infrastructure.
//!
//! Game-specific code in this crate is intentionally minimal:
//! `ModInfo`, the on_unreal_init / on_shutdown hooks, the
//! game's `PlatformOffsets`, the `Snapshot` type, the op
//! dispatcher, and the tab render bodies. Everything else
//! is `use uespy::*`.

pub mod debug;

use uespy::ue::PlatformOffsets;

// ---- Platform detection ----
//
// Outworld Station is UE 5.4.4. Offsets below are placeholders;
// fill in once UE4SS's CXXHeaderDumper has run against the live
// game and we can read GObjects / AppendString / GNames /
// GWorld / ProcessEvent addresses from the dump.
//
// process_event_idx (0x4C on UE 5.x) is the vtable slot for
// UObject::ProcessEvent and is stable across UE 5.x builds.
const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x0,
    append_string: 0x0,
    g_names: 0x0,
    g_world: 0x0,
    process_event: 0x0,
    process_event_idx: 0x4C,
};

const PLATFORMS: &[(&str, &PlatformOffsets)] = &[
    ("OutworldStation-Win64-Shipping.exe", &STEAM),
];

// ---- Mod metadata + entry points ----

static MOD_INFO: uespy::ModInfo = uespy::ModInfo {
    name: "OWS Tweaks",
    version: "0.1.0",
    log_file: "tweaks.log",
    console_title: "OWS Tweaks",
    console: cfg!(feature = "console"),
    on_unreal_init,
    on_shutdown,
    tabs: &[uespy::Tab {
        name: "Tweaks",
        render: render_tweaks_tab,
    }],
};

uespy::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    uespy::log::log(format_args!("on_unreal_init"));

    let image_base = uespy::ue::platform::host_image_base();
    let exe = uespy::ue::platform::host_exe_name().unwrap_or_default();
    uespy::log::log(format_args!(
        "image_base = 0x{image_base:x}, host = {exe}"
    ));

    // Once OWS offsets are dumped: detect platform, init runtime,
    // spawn debug server, install drain trampoline.
    let offsets = uespy::ue::platform::detect(PLATFORMS);
    if offsets.is_none() || offsets.is_some_and(|o| o.g_objects == 0) {
        uespy::log::log(format_args!(
            "WARN: OWS PlatformOffsets are stub zeros. Dump via \
             UE4SS CXXHeaderDumper, fill in src/lib.rs::STEAM, \
             then rebuild. /debug snapshot still works."
        ));
    } else if let Some(off) = offsets {
        let _rt = unsafe { uespy::ue::init_runtime(image_base, off) };
        uespy::log::log(format_args!(
            "ue runtime ready, GObjects = 0x{:x}",
            image_base + off.g_objects
        ));
        // Future: install PE trampoline for drain site, spawn
        // debug server gated on settings.debug.http_port.
    }

    // Always bring the debug server up (offset-independent). Use
    // a fixed port for now; later, read from settings.json.
    debug::spawn(17172);
}

fn on_shutdown() {
    uespy::log::log(format_args!("on_shutdown"));
}

// ---- ImGui tab render ----

fn render_tweaks_tab() {
    uespy::ui::text("Outworld Station Tweaks");
    uespy::ui::separator();
    uespy::ui::text_disabled("(scaffold; offsets pending)");
    uespy::ui::spacing();
    if uespy::ui::button("Reload patches") {
        uespy::log::log(format_args!("Reload patches clicked (no-op)"));
    }
}
