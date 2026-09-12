#![allow(clippy::missing_safety_doc)]

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "CorsairCoveMod",
    version: "0.1.0",
    log_file: "corsaircove_mod.log",
    console_title: "Corsair Cove Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    // Minimal on purpose: no ImGui tabs, no watchers. The control
    // plane on port 31280 is the only surface until a research
    // test asks for more.
    tabs: &[],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("corsaircove_mod/init", || unsafe { worker() });
}

// Corsair Cove is UE 5.4 or 5.5 (build tag stripped from the exe;
// IoStore container version 8, FSR4 plugin, Steamworks v157).
// ProcessEvent slot 0x4D is the value measured on every UE 5.4
// game in this workspace (MISERY, Abiotic Factor) and on Sintopia.
// NOT yet measured on this game: run
// tests/research_engine.rs process_event_slot and fix this if it
// differs. Requires HookUObjectProcessEvent = 1 in
// UE4SS-settings.ini for the log line that test reads.
const PROCESS_EVENT_IDX: usize = 0x4D;
// WrappedChunked is what every UE5 game in this workspace uses.
// Confirmed on this game only once discovery_counts walks GObjects.
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout = ueforge::ue::GObjectsLayout::WrappedChunked;
const STRUCT_LAYOUT: ueforge::ue::StructLayout = ueforge::ue::StructLayout::UE5_4;

unsafe fn worker() {
    ueforge::log!("corsaircove_mod init");

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
            port: 31280,
            endpoint: "/debug",
            thread_name: "corsaircove-debug-http",
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

    ueforge::log!("corsaircove_mod ready, http on port 31280");
}

fn on_shutdown() {
    ueforge::log!("corsaircove_mod shutdown");
}
