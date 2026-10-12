#![allow(clippy::missing_safety_doc)]

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "NuclearEpochMod",
    version: "0.1.0",
    log_file: "nuclearepoch_mod.log",
    console_title: "Nuclear Epoch Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    // Minimal on purpose: no ImGui tabs, no watchers. The control
    // plane on port 31300 is the only surface until a research
    // test asks for more.
    tabs: &[],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("nuclearepoch_mod/init", || unsafe { worker() });
}

// Nuclear Epoch is UE 5.7 (exe carries ++UE5+Release-5.7-CL-51494982;
// UE4SS logs "Found EngineVersion: 5.7"). The two layouts are UE4SS's
// 5.7 tables, logged on this game; reading the GObjects item as the
// UE 5.4 layout crashed the load walk in UObject::name. The
// ProcessEvent slot is still the placeholder from the UE 5.4 games.
const PROCESS_EVENT_IDX: usize = 0x4D;
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout =
    ueforge::ue::GObjectsLayout::WrappedChunkedUE5_7;
const STRUCT_LAYOUT: ueforge::ue::StructLayout = ueforge::ue::StructLayout::UE5_7;

unsafe fn worker() {
    ueforge::log!("nuclearepoch_mod init");

    let _rt =
        ueforge::ue::platform::resolve_and_init(PROCESS_EVENT_IDX, G_OBJECTS_LAYOUT, STRUCT_LAYOUT);

    ueforge::selector::register_builtins();
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
    ueforge::shutdown::register_builtins();

    ueforge::spawn(
        ueforge::Config {
            port: 31300,
            endpoint: "/debug",
            thread_name: "nuclearepoch-debug-http",
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

    ueforge::log!("nuclearepoch_mod ready, http on port 31300");
}

fn on_shutdown() {
    ueforge::log!("nuclearepoch_mod shutdown");
}
