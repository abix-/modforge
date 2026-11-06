#![allow(clippy::missing_safety_doc)]

mod tweaks;
mod weapon_level;

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "QueensDomainMod",
    version: "0.1.0",
    log_file: "queensdomain_mod.log",
    console_title: "Queens' Domain Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    // No ImGui tabs. The control plane on port 31310 plus the
    // weapon level watcher (weapon_level.rs) are the whole surface.
    tabs: &[],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("queensdomain_mod/init", || unsafe { worker() });
}

// Queens' Domain is UE 4.27 (exe carries "Release-4.27", pak is
// WindowsNoEditor, PhysX3). The first UE4 game in this workspace.
//
// Measured 2026-11-05 by tests/research_ustruct_layout.rs, and UE4SS's
// startup tables agree: FUObjectItem::Object +0x0 (the stock chunked
// array), UStruct::PropertiesSize +0x58, FProperty::ElementSize +0x3C,
// Offset_Internal +0x4C. The ProcessEvent slot 0x44 was measured
// 2026-11-05 by tests/research_engine.rs: the player's function in that
// slot calls the GameInstance's, as AActor::ProcessEvent calls
// UObject::ProcessEvent, and the base function is 924 bytes.
const PROCESS_EVENT_IDX: usize = 0x44;
static DRAIN: ueforge::pe_queue::GameThread = ueforge::pe_queue::GameThread::new();
const DRAIN_HINT: &str = "queensdomain: is the UEngine::Tick hook installed? see pe_stats.game_thread";
const G_OBJECTS_LAYOUT: ueforge::ue::GObjectsLayout = ueforge::ue::GObjectsLayout::WrappedChunked;
const STRUCT_LAYOUT: ueforge::ue::StructLayout = ueforge::ue::StructLayout::UE4_27;

unsafe fn worker() {
    ueforge::log!("queensdomain_mod init");

    let _rt =
        ueforge::ue::platform::resolve_and_init(PROCESS_EVENT_IDX, G_OBJECTS_LAYOUT, STRUCT_LAYOUT);

    ueforge::selector::register_builtins();
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
    ueforge::shutdown::register_builtins();
    // Engine calls (object.call and friends) run on the game thread,
    // drained from UEngine::Tick.
    ueforge::reflect::register_ops(&DRAIN, DRAIN_HINT);
    ueforge::game_thread::register_ops(&DRAIN, DRAIN_HINT);
    ueforge::game_thread::serve(&DRAIN);

    ueforge::spawn(
        ueforge::Config {
            port: 31310,
            endpoint: "/debug",
            thread_name: "queensdomain-debug-http",
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

    // Also puts tweaks.rs back on every game load. The crash first
    // blamed on it was the hot reload: weapon_level_steps ran every step
    // clean in game on 2026-11-06.
    weapon_level::start();
    weapon_level::register_ops();

    ueforge::log!("queensdomain_mod ready, http on port 31310");
}

fn on_shutdown() {
    ueforge::log!("queensdomain_mod shutdown");
}
