#![allow(clippy::missing_safety_doc)]

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "AlchemyFactoryMod",
    version: "0.1.0",
    log_file: "alchemyfactory_mod.log",
    console_title: "Alchemy Factory Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    // Minimal on purpose: no ImGui tabs, no watchers. The control
    // plane on port 31290 is the only surface until a research
    // test asks for more.
    tabs: &[],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("alchemyfactory_mod/init", || unsafe { worker() });
}

// Alchemy Factory is UE 5.7 (exe carries ++UE5+Release-5.7). The
// first UE 5.7 game in this workspace, so every number below is a
// placeholder carried over from the UE 5.4 games until
// tests/research_engine.rs (process_event_slot) and
// tests/research_ustruct_layout.rs measure the real ones live.
const PROCESS_EVENT_IDX: usize = 0x4D;
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout = ueforge::ue::GObjectsLayout::WrappedChunked;
const STRUCT_LAYOUT: ueforge::ue::StructLayout = ueforge::ue::StructLayout::UE5_4;

unsafe fn worker() {
    ueforge::log!("alchemyfactory_mod init");

    let _rt = ueforge::ue::platform::resolve_and_init(
        PROCESS_EVENT_IDX,
        G_OBJECTS_LAYOUT,
        STRUCT_LAYOUT,
    );

    ueforge::selector::register_builtins();
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
    ueforge::shutdown::register_builtins();

    ueforge::spawn(
        ueforge::Config {
            port: 31290,
            endpoint: "/debug",
            thread_name: "alchemyfactory-debug-http",
            auth_token: None,
        },
        |body| {
            let resp = ueforge::envelope::handle_request(
                body,
                &ueforge::ops::OP_REGISTRY,
                || serde_json::json!({"status": "ok"}),
            );
            serde_json::to_vec(&resp).unwrap_or_else(|_| b"{}".to_vec())
        },
        |msg| ueforge::log!("{}", msg),
    );

    ueforge::log!("alchemyfactory_mod ready, http on port 31290");
}

fn on_shutdown() {
    ueforge::log!("alchemyfactory_mod shutdown");
}
