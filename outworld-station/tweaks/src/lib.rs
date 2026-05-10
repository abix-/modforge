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

use uespy::ue::{GObjectsLayout, PlatformOffsets};

// ---- Platform detection ----
//
// OutworldStation-Win64-Shipping.exe (Steam, UE 5.4.4).
// Image base + addresses captured by UE4SS's pattern scanner on
// 2026-05-09 (`UE4SS.log` has the absolute addresses; image
// base 0x7ff6da6f0000 from our own log). Image-relative offsets
// computed by subtracting the base.
//
// g_names / g_world: UE4SS didn't log explicit addresses for
// these on this exe. Neither is required by the ops we're using
// today (walk_class, read_bytes, write_bytes, call). Fill in
// later if a feature needs them.
//
// process_event_idx 0x4C: vtable slot for UObject::ProcessEvent,
// stable across UE 5.x.
const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x07A9_38D0,    // GUObjectArray
    append_string: 0x010D_F9D0, // FName::ToString
    g_names: 0x0,               // not logged by UE4SS scanner; fill in if needed
    g_world: 0x0,               // not logged by UE4SS scanner; fill in if needed
    process_event: 0x012A_F540, // UObject::ProcessEvent
    process_event_idx: 0x4C,
    // UE 5.4 stock — FUObjectArray wraps FChunkedFixedUObjectArray
    // at +0x10. Verified live: NumElements=142650, NumChunks=3.
    g_objects_layout: GObjectsLayout::WrappedChunked,
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
