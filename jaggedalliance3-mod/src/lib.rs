//! Jagged Alliance 3 mod. `modforge-inject` loads this DLL into a
//! running JA3.exe; it serves the modforge control plane on
//! 127.0.0.1:33079.

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use windows_sys::Win32::Foundation::HINSTANCE;

const HTTP_PORT: u16 = 33079;

fn register_ops() {
    modforge::counters::register_ops();
    modforge::inject::register_ops();

    OP_REGISTRY.register_many(vec![
        OpDef::new("ping", "Liveness check", "{}", |_args| Ok(json!("pong"))),
        OpDef::new(
            "list_ops",
            "List every op registered on the global registry",
            "{}",
            |_args| Ok(OP_REGISTRY.list_json()),
        ),
    ]);
}

/// One-shot startup, on its own thread so nothing runs under the
/// Windows loader lock that DllMain holds.
fn worker_main() {
    modforge::log::init(modforge::log::Config {
        file_name: "jaggedalliance3.log",
        console_title: "jaggedalliance3-mod",
        console: false,
    });
    modforge::log!("jaggedalliance3-mod: worker started");

    modforge::shutdown::register_modforge_builtins();
    register_ops();
    modforge::server::spawn(
        modforge::server::Config {
            port: HTTP_PORT,
            endpoint: "/op",
            thread_name: "jaggedalliance3-http",
            auth_token: None,
        },
        |body| {
            let (op, args) = match modforge::envelope::parse_request(body) {
                Ok(request) => request,
                Err(error) => {
                    let response: modforge::envelope::OpResponse<Json> =
                        modforge::envelope::OpResponse::err(
                            "<parse-error>",
                            error,
                            json!({"process": "JA3.exe"}),
                        );
                    return serde_json::to_vec(&response).unwrap_or_default();
                }
            };
            let result = OP_REGISTRY
                .dispatch(&op, &args)
                .unwrap_or_else(|| Err(format!("unknown op: {op}")));
            let response = modforge::envelope::OpResponse::from_result(
                &op,
                result,
                json!({"process": "JA3.exe"}),
            );
            serde_json::to_vec(&response).unwrap_or_default()
        },
        |message| modforge::log!("{message}"),
    );
    modforge::log!("jaggedalliance3-mod: listening on 127.0.0.1:{HTTP_PORT}");
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
