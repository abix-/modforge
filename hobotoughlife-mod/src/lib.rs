//! Hobo: Tough Life mod. Rust cdylib loaded by Unityforge.Shim.Melon
//! (the MelonLoader entry) into the IL2CPP game.
//!
//! v1 is the control plane only: the framework's generic ops and
//! the Unity-side selectors, for live research on port 17180.

use unityforge::ModDef;

static MOD_INFO: ModDef = ModDef {
    name: "HoboToughLifeMod",
    version: "0.1.0",
    // 17180: 17172-17179 are held by the other modforge game mods.
    http_port: 17180,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: None,
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();

    let kind = unityforge::unity::runtime_kind()
        .map(|k| format!("{k:?}"))
        .unwrap_or_else(|| "<unset>".to_string());
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("hobotoughlife-mod: ready (runtime={kind})"),
    );
}
