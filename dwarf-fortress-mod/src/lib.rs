//! Dwarf Fortress native research adapter.
//!
//! DFHack's dfhooks chainloader loads this DLL in the game process. The
//! adapter exposes modforge's process instrumentation over localhost without
//! duplicating DFHack's typed view of Dwarf Fortress state.

use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, Ordering};

use modforge::ops::OP_REGISTRY;
use serde_json::{Value as Json, json};
use windows_sys::Win32::Foundation::HINSTANCE;

const HTTP_PORT: u16 = 33078;
static INITIALIZED: AtomicBool = AtomicBool::new(false);

/// The chainloader currently initializes higher priorities first and shuts
/// down in reverse. Stay below DFHack's priority 100 so DFHack initializes
/// first and remains alive until after this adapter shuts down.
#[unsafe(no_mangle)]
pub static dfhooks_priority: i32 = 50;

fn start() {
    if INITIALIZED.swap(true, Ordering::AcqRel) {
        return;
    }

    modforge::log::init(modforge::log::Config {
        file_name: "dfhooks_modforge.log",
        console_title: "dwarf-fortress-mod",
        console: false,
    });
    modforge::log!("dwarf-fortress-mod: dfhooks init");

    modforge::process_ops::register();
    modforge::server::spawn(
        modforge::server::Config {
            port: HTTP_PORT,
            endpoint: "/op",
            thread_name: "dwarf-fortress-mod-http",
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
                            json!({"process": "Dwarf Fortress"}),
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
                json!({"process": "Dwarf Fortress"}),
            );
            serde_json::to_vec(&response).unwrap_or_default()
        },
        |message| modforge::log!("{message}"),
    );
}

fn stop() {
    if !INITIALIZED.swap(false, Ordering::AcqRel) {
        return;
    }
    modforge::log!("dwarf-fortress-mod: dfhooks shutdown");
    modforge::shutdown::SHUTDOWN_REGISTRY.run_all();
}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_init() {
    let _ = std::panic::catch_unwind(start);
}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_shutdown() {
    let _ = std::panic::catch_unwind(stop);
}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_update() {}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_prerender() {}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_sdl_event(_event: *mut c_void) -> bool {
    false
}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_ncurses_key(_key: i32) -> bool {
    false
}

#[unsafe(no_mangle)]
pub extern "C" fn dfhooks_sdl_loop() {}

type Bool = i32;
const DLL_PROCESS_ATTACH: u32 = 1;

/// Capture our module handle for file-relative logging. All real work starts
/// in `hooks_init`, outside the Windows loader lock.
#[unsafe(no_mangle)]
pub extern "system" fn DllMain(module: HINSTANCE, reason: u32, _reserved: *mut c_void) -> Bool {
    if reason == DLL_PROCESS_ATTACH {
        modforge::log::set_dll_module(module as _);
    }
    1
}
