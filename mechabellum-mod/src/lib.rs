//! Mechabellum mod.
//!
//! Mechabellum is Unity 2022.3.62f3, IL2CPP (GameAssembly.dll plus
//! global-metadata.dat v31). Loaded through `Unityforge.Shim.Melon`,
//! the MelonLoader entry megabonk-mod runs on. Minimal on purpose:
//! the builtin ops and selectors on the control plane are the only
//! surface until a research test asks for more.

use unityforge::ModDef;

mod act;
mod deploy;
mod lineup;
mod sim;
mod units;

static MOD_INFO: ModDef = ModDef {
    name: "MechabellumMod",
    version: "0.1.0",
    // 17184: 17172 to 17183 are held by the other Unity crates.
    http_port: 17184,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: Some(on_shutdown),
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();
    units::install();
    lineup::install();
    deploy::install();
    sim::install();
    act::install();

    let kind = unityforge::unity::runtime_kind()
        .map(|k| format!("{k:?}"))
        .unwrap_or_else(|| "<unset>".to_string());
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("mechabellum-mod: ready (runtime={kind}), http on port 17184"),
    );
}

fn on_shutdown() {
    unityforge::mono::log(unityforge::mono::LogLevel::Info, "mechabellum-mod: shutdown");
}
