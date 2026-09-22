mod energy;
mod inventory;

use unityforge::ModDef;

static MOD_INFO: ModDef = ModDef {
    name: "GraveyardKeeper2Mod",
    version: "0.1.0",
    http_port: 17178,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: Some(on_shutdown),
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();
    energy::install();
    inventory::install();

    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "graveyardkeeper2-mod: ready",
    );
}

fn on_shutdown() {
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "graveyardkeeper2-mod: shutdown",
    );
}
