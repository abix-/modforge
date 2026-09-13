//! Wanderburg mod. Rust cdylib loaded by Unityforge.Shim.Melon
//! (the MelonLoader entry) into the IL2CPP game.
//!
//! Bootstrap path:
//! 1. MelonLoader loads `Unityforge.Shim.Melon.dll` from Mods/.
//! 2. The shim locates `wanderburg_mod.unityforge.dll` next to
//!    itself, `LoadLibrary`s it, and calls
//!    `unityforge_init(bridge)`.
//! 3. `on_init` registers the framework's generic ops and the
//!    Unity-side selectors: the HTTP control plane for live
//!    research (walk_class / inspect_object / read_field /
//!    write_field / invoke_method / list_singletons / ...).
//! 4. The shim's OnUpdate drives `unityforge_tick` every frame.
//!
//! Control plane only. Anything on top waits for a research test
//! and the operator asking for it.

use unityforge::ModDef;

mod regen;

static MOD_INFO: ModDef = ModDef {
    name: "WanderburgMod",
    version: "0.1.0",
    // 17177: 17173 is held by eufy-capture on the operator's
    // machine, 17175 is Schedule 1, 17176 is taken by another
    // crate in this workspace.
    http_port: 17177,
    on_init: Some(on_init),
    on_tick: Some(on_tick),
    on_shutdown: Some(on_shutdown),
    tabs: &[],
};

/// Runs every frame on the Unity main thread after the queue drain.
fn on_tick(_now: f32) {
    regen::tick();
}

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();

    let kind = unityforge::unity::runtime_kind()
        .map(|k| format!("{k:?}"))
        .unwrap_or_else(|| "<unset>".to_string());
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("wanderburg-mod: ready (runtime={kind}), http on port 17177"),
    );
}

fn on_shutdown() {
    unityforge::mono::log(unityforge::mono::LogLevel::Info, "wanderburg-mod: shutdown");
}
