use unityforge::ModDef;

mod auto_automation;
mod base_defense;
mod control_points;
mod council;
mod defend_interests;
mod immunity;
mod no_death;
mod offense;
mod org_budget;
mod org_missions;
mod org_research;
mod org_stats;
mod point_immunity;

static MOD_INFO: ModDef = ModDef {
    name: "TerraInvictaMod",
    version: "0.1.0",
    http_port: 17179,
    on_init: Some(on_init),
    on_tick: None,
    on_shutdown: None,
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();
    council::install();
    control_points::install();
    immunity::install();
    no_death::install();
    defend_interests::install();
    base_defense::install();
    org_budget::install();
    org_missions::install();
    org_research::install();
    org_stats::install();
    point_immunity::install();
    offense::install();
    auto_automation::install();
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "terrainvicta-mod: ready (ops + selectors installed)",
    );
}
