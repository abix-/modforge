#![allow(clippy::missing_safety_doc)]

mod stacks;

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "MainSequenceMod",
    version: "0.1.0",
    log_file: "mainsequence_mod.log",
    console_title: "Main Sequence Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    // No ImGui tabs. The control plane on port 31320 is the only
    // surface; stacks.rs is the one watcher and ends itself.
    tabs: &[],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("mainsequence_mod/init", || unsafe { worker() });
}

// Main Sequence is UE 5.7 (exe carries ++UE5+Release-5.7). The two
// layouts are UE4SS's 5.7 tables, the same ones Nuclear Epoch uses.
// The ProcessEvent slot is still the placeholder from the UE 5.4
// games.
const PROCESS_EVENT_IDX: usize = 0x4D;
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout =
    ueforge::ue::GObjectsLayout::WrappedChunkedUE5_7;
const STRUCT_LAYOUT: ueforge::ue::StructLayout = ueforge::ue::StructLayout::UE5_7;

unsafe fn worker() {
    ueforge::log!("mainsequence_mod init");

    let _rt =
        ueforge::ue::platform::resolve_and_init(PROCESS_EVENT_IDX, G_OBJECTS_LAYOUT, STRUCT_LAYOUT);

    ueforge::selector::register_builtins();
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
    ueforge::shutdown::register_builtins();

    stacks::register_ops();
    stacks::start();

    ueforge::spawn(
        ueforge::Config {
            port: 31320,
            endpoint: "/debug",
            thread_name: "mainsequence-debug-http",
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

    ueforge::log!("mainsequence_mod ready, http on port 31320");
}

fn on_shutdown() {
    ueforge::log!("mainsequence_mod shutdown");
}
