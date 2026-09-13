#![allow(clippy::missing_safety_doc)]
mod ai_player;
mod host;

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "AbioticFactorMod",
    version: "0.1.0",
    log_file: "abioticfactor_mod.log",
    console_title: "Abiotic Factor Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    tabs: &[
        ueforge::TabDef {
            name: "Tables",
            render: ueforge::ui_data_table_browser::render,
        },
        ueforge::TabDef {
            name: "Classes",
            render: ueforge::ui_class_browser::render,
        },
        ueforge::TabDef {
            name: "Structs",
            render: ueforge::ui_struct_browser::render,
        },
    ],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("abioticfactor_mod/init", || unsafe { worker() });
}

const PROCESS_EVENT_IDX: usize = 0x4D;
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout = ueforge::ue::GObjectsLayout::WrappedChunked;

/// The one game-thread job queue for this mod. Worker threads (ops,
/// input) enqueue; `UEngine::Tick` drains it every frame, at the menu
/// and in play alike.
pub(crate) static DRAIN: ueforge::pe_queue::GameThread = ueforge::pe_queue::GameThread::new();
pub(crate) const DRAIN_HINT: &str = "abioticfactor: is the UEngine::Tick hook installed? see pe_stats.game_thread";

unsafe fn worker() {
    ueforge::log!("abioticfactor_mod init");

    let _rt = ueforge::ue::platform::resolve_and_init(
        PROCESS_EVENT_IDX,
        G_OBJECTS_LAYOUT,
        ueforge::ue::StructLayout::UE5_4,
    );

    ueforge::selector::register_builtins();
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
    ueforge::ops::OP_REGISTRY.register_many(modforge::input::ops::all());
    ueforge::shutdown::register_builtins();
    ai_player::register();
    host::register();
    ueforge::game_thread::register_ops(&DRAIN, DRAIN_HINT);
    ueforge::game_thread::serve(&DRAIN);
    ueforge::debug::register_pe_call(&DRAIN, DRAIN_HINT, ueforge::selector::resolve);

    ueforge::spawn(
        ueforge::Config {
            port: 31260,
            endpoint: "/debug",
            thread_name: "abf-debug-http",
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

    ueforge::log!("abioticfactor_mod ready, http on port 31260");
}

fn on_shutdown() {
    ueforge::log!("abioticfactor_mod shutdown");
}
