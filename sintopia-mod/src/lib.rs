#![allow(clippy::missing_safety_doc)]

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "SintopiaMod",
    version: "0.1.0",
    log_file: "sintopia_mod.log",
    console_title: "Sintopia Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    // Minimal on purpose: no ImGui tabs, no watchers. The control
    // plane on port 31270 is the only surface until a research
    // test asks for more.
    tabs: &[],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("sintopia_mod/init", || unsafe { worker() });
}

// Sintopia is UE 5.2.1 (exe FileVersion 5.2.1.0, source build).
// ProcessEvent slot 0x4D measured live 2026-09-11 by
// tests/research_engine.rs process_event_slot: the
// BP_DiabolicalGameInstance_C vtable holds the address UE4SS logs
// (0x7ff6b1d5fdb0) at slot 0x4d. Requires HookUObjectProcessEvent
// = 1 in UE4SS-settings.ini for that log line to exist.
const PROCESS_EVENT_IDX: usize = 0x4D;
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout = ueforge::ue::GObjectsLayout::WrappedChunked;

unsafe fn worker() {
    ueforge::log!("sintopia_mod init");

    let _rt = ueforge::ue::platform::resolve_and_init(PROCESS_EVENT_IDX, G_OBJECTS_LAYOUT);

    ueforge::selector::register_builtins();
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
    ueforge::shutdown::register_builtins();

    ueforge::spawn(
        ueforge::Config {
            port: 31270,
            endpoint: "/debug",
            thread_name: "sintopia-debug-http",
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

    ueforge::log!("sintopia_mod ready, http on port 31270");
}

fn on_shutdown() {
    ueforge::log!("sintopia_mod shutdown");
}
