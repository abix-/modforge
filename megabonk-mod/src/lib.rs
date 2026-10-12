//! Megabonk mod.
//!
//! Megabonk is Unity 2023.2.22f1, IL2CPP (GameAssembly.dll plus
//! global-metadata.dat). Loaded through `Unityforge.Shim.Melon`, the
//! MelonLoader entry schedule1-mod runs on. Minimal on purpose: the
//! builtin ops and selectors on the control plane are the only
//! surface until a research test asks for more.

use unityforge::ModDef;

mod rarity;
mod run_defaults;
mod timer;

static MOD_INFO: ModDef = ModDef {
    name: "MegabonkMod",
    version: "0.1.0",
    // 17183: 17172 to 17182 are held by the other Unity crates.
    http_port: 17183,
    on_init: Some(on_init),
    on_tick: Some(tick),
    on_shutdown: Some(on_shutdown),
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();
    rarity::install();
    run_defaults::install();
    timer::install();

    let kind = unityforge::unity::runtime_kind()
        .map(|k| format!("{k:?}"))
        .unwrap_or_else(|| "<unset>".to_string());
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("megabonk-mod: ready (runtime={kind}), http on port 17183"),
    );
}

/// Every frame, from the shim's Update (main thread).
fn tick(now: f32) {
    run_defaults::tick(now);
    timer::tick();
}

fn on_shutdown() {
    unityforge::mono::log(unityforge::mono::LogLevel::Info, "megabonk-mod: shutdown");
}
