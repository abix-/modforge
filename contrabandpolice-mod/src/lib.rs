//! Contraband Police mod.
//!
//! Contraband Police is Unity 2022.3.62f2, IL2CPP (GameAssembly.dll
//! plus il2cpp_data). Loaded through `Unityforge.Shim.Melon`, the
//! MelonLoader entry mechabellum-mod runs on. Minimal on purpose:
//! the builtin ops and selectors on the control plane are the only
//! surface until a research test asks for more.

use unityforge::ModDef;

static MOD_INFO: ModDef = ModDef {
    name: "ContrabandPoliceMod",
    version: "0.1.0",
    // 17186: 17172 to 17184 are held by the other Unity crates and
    // 17185 by poe2-mod.
    http_port: 17186,
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
        &format!("contrabandpolice-mod: ready (runtime={kind}), http on port 17186"),
    );
}

fn on_shutdown() {
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "contrabandpolice-mod: shutdown",
    );
}
