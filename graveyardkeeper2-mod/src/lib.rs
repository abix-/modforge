mod auto_work;
mod autopsy;
mod energy;
mod harvest;
mod inventory;
mod replant;
mod stacks;
mod take_all;
mod tweaks;
mod work;

use unityforge::ModDef;

static MOD_INFO: ModDef = ModDef {
    name: "GraveyardKeeper2Mod",
    version: "0.1.0",
    http_port: 17178,
    on_init: Some(on_init),
    on_tick: Some(on_tick),
    on_shutdown: Some(on_shutdown),
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();
    energy::install();
    inventory::install();
    tweaks::install();
    take_all::install();
    auto_work::install();
    replant::install();
    autopsy::install();

    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "graveyardkeeper2-mod: ready",
    );
}

fn on_tick(now: f32) {
    tweaks::on_tick(now);
    take_all::on_tick();
    replant::on_tick();
    autopsy::on_tick();
    work::on_tick();
}

fn on_shutdown() {
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "graveyardkeeper2-mod: shutdown",
    );
}
