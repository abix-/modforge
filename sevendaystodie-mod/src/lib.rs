//! 7 Days To Die mod. Rust cdylib loaded by
//! Unityforge.Shim.SevenDaysToDie (the game's IModApi entry) into
//! the Mono game.
//!
//! v1 is the control plane only: the framework's generic ops and
//! the Unity-side selectors, for live research on port 17182.

use unityforge::ModDef;

static MOD_INFO: ModDef = ModDef {
    name: "SevenDaysToDieMod",
    version: "0.1.0",
    // 17182: 17172-17181 are held by the other modforge game mods.
    http_port: 17182,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: None,
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "sevendaystodie-mod: ready (ops + selectors installed)",
    );
}
