//! Enshrouded mod. `modforge-inject` loads this DLL into a running
//! enshrouded.exe; it serves the modforge control plane on
//! 127.0.0.1:33080.

mod events;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use windows_sys::Win32::Foundation::HINSTANCE;

const HTTP_PORT: u16 = 33080;

/// The game's exe: full path, load address, size and PE timestamp.
fn game_op(_args: &Json) -> Result<Json, String> {
    let mem = modforge::process_memory::ProcessMemory::open(std::process::id())
        .map_err(|e| format!("open own process: {e}"))?;
    let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
    let timestamp = mem
        .image_timestamp(&exe)
        .map_err(|e| format!("read PE timestamp: {e}"))?;
    Ok(json!({
        "pid": std::process::id(),
        "path": exe.path,
        "base": format!("{:#x}", exe.base),
        "size": exe.size,
        "pe_timestamp": timestamp,
    }))
}

/// One-shot startup, on its own thread so nothing runs under the
/// Windows loader lock that DllMain holds.
fn worker_main() {
    modforge::log::init(modforge::log::Config {
        file_name: "enshrouded-mod.log",
        console_title: "enshrouded-mod",
        console: false,
    });
    modforge::log!("enshrouded-mod: worker started");

    modforge::process_ops::register();
    modforge::inject::register_ops();
    modforge::keen::register_ops();
    events::register();
    OP_REGISTRY.register(OpDef::new(
        "game",
        "the game's exe: pid, full path, load address, size and PE timestamp",
        "",
        game_op,
    ));
    modforge::server::spawn(
        modforge::server::Config {
            port: HTTP_PORT,
            endpoint: "/op",
            thread_name: "enshrouded-mod-http",
            auth_token: None,
        },
        |body| {
            let response = modforge::envelope::handle_request(
                body,
                &OP_REGISTRY,
                || json!({"process": "enshrouded.exe"}),
            );
            serde_json::to_vec(&response).unwrap_or_default()
        },
        |message| modforge::log!("{message}"),
    );
    modforge::log!("enshrouded-mod: listening on 127.0.0.1:{HTTP_PORT}");
}

type Bool = i32;
const DLL_PROCESS_DETACH: u32 = 0;
const DLL_PROCESS_ATTACH: u32 = 1;

#[unsafe(no_mangle)]
pub extern "system" fn DllMain(
    module: HINSTANCE,
    reason: u32,
    _reserved: *mut std::ffi::c_void,
) -> Bool {
    match reason {
        DLL_PROCESS_ATTACH => {
            modforge::log::set_dll_module(module as _);
            std::thread::spawn(worker_main);
        }
        // Stop the listener and every modforge job so no thread keeps
        // running in this DLL's code after a hot-reload unloads it.
        DLL_PROCESS_DETACH => modforge::shutdown::SHUTDOWN_REGISTRY.run_all(),
        _ => {}
    }
    1
}
