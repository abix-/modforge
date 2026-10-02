mod crime;
mod deposit;
mod settings;
mod tweaks;

use unityforge::ModDef;

static MOD_INFO: ModDef = ModDef {
    name: "ObenseuerMod",
    version: "0.1.0",
    http_port: 17175,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: Some(on_shutdown),
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();

    tweaks::install();
    deposit::install();
    crime::install();
    settings::get().register_hud_op();

    unityforge::mono::log(unityforge::mono::LogLevel::Info, "obenseuer-mod: ready");
}

fn on_shutdown() {
    unityforge::mono::log(unityforge::mono::LogLevel::Info, "obenseuer-mod: shutdown");
}
