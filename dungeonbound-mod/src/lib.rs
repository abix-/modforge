//! Dungeonbound mod.
//!
//! Dungeonbound is Godot 4.7.1 and loads one GDExtension, GodotSteam,
//! from `libgodotsteam.windows.template_release.x86_64.dll` through
//! its entry point `godotsteam_init`. This DLL is deployed under that
//! name and starts the real GodotSteam, renamed beside it. Every op is
//! godotforge's; the control plane is on 127.0.0.1:31330/op.

pub mod fight;

static MOD_INFO: godotforge::ModDef = godotforge::ModDef {
    name: "dungeonbound-mod",
    version: "0.1.0",
    http_port: 31330,
    log_file: "dungeonbound-mod.log",
    on_init: None,
    on_tick: None,
    on_shutdown: None,
};

godotforge::godot4_mod!(MOD_INFO,
    stand_in: godotsteam_init,
    original: "libgodotsteam.windows.template_release.x86_64.original.dll");
