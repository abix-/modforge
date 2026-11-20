//! Pure Skill mod. Rust cdylib loaded by Unityforge.Shim.Il2Cpp
//! (the BepInEx 6 entry) into the IL2CPP game. MelonLoader 0.7.3
//! crashes this Unity build while generating interop assemblies.
//!
//! Bootstrap path:
//! 1. BepInEx loads `Unityforge.Shim.Il2Cpp.dll` from
//!    BepInEx/plugins/unityforge/.
//! 2. The shim locates `pureskill_mod.unityforge.dll` next to
//!    itself, `LoadLibrary`s it, and calls `unityforge_init(bridge)`.
//! 3. `on_init` registers the framework's generic ops and the
//!    Unity-side selectors: the HTTP control plane for live research.
//! 4. The shim's injected tick driver calls `unityforge_tick` every
//!    frame.
//!
//! Control plane only. Anything on top waits for a research test
//! and the operator asking for it.

use unityforge::ModDef;

/// 17187: 17172 to 17186 are held by other crates in this workspace.
const PORT: u16 = 17187;

static MOD_INFO: ModDef = ModDef {
    name: "PureSkillMod",
    version: "0.1.0",
    http_port: PORT,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: Some(on_shutdown),
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
        &format!("pureskill-mod: ready (runtime={kind}), http on port {PORT}"),
    );
}

fn on_shutdown() {
    unityforge::mono::log(unityforge::mono::LogLevel::Info, "pureskill-mod: shutdown");
}
