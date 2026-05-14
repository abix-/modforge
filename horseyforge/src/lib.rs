//! horseyforge: native-PE binding of modforge for Horsey Game.
//!
//! Sibling to ueforge (UE5) and unityforge (Unity). Whereas those
//! frameworks ride on a managed plugin loader, horseyforge injects
//! via the proxy-DLL pattern: the cdylib produced here ships as
//! `steam_api64.dll`, the user renames the real one to
//! `steam_api64_real.dll`, and Windows loads us first because the
//! game asks for `steam_api64.dll` by name.
//!
//! The build script enumerates `steam_api64.dll`'s exports and
//! emits forwarders in a .DEF file so every existing Steam API
//! call goes through to the real DLL transparently.
//!
//! Our `DllMain` runs the moment the DLL is loaded. It spawns a
//! worker thread (NEVER do work in DllMain itself; the loader
//! holds a lock that almost everything in the Win32 API
//! eventually tries to take) which:
//!   1. Initializes modforge's logger.
//!   2. Generates a random auth token, writes it next to the DLL.
//!   3. Registers Horsey-specific ops on modforge's registry.
//!   4. Spawns modforge's HTTP server with auth on 127.0.0.1:33077.
//!
//! Function-hook installation (MinHook trampolines on the 18
//! game functions we identified during decompilation) is staged
//! for a follow-up phase.

pub mod fatigue;
pub mod gamestate;
pub mod horse;
pub mod ops;
pub mod patches;
pub mod snapshot;
pub mod targets;

use std::sync::OnceLock;

// modforge::server::spawn() pushes its SpawnHandle into a global
// SERVER_REGISTRY and doesn't return it. To stop the server (e.g.
// during a hot-reload), call modforge::server::shutdown_all().

/// Per-launch random auth token. Tests / clients read it from
/// `horseyforge.auth` written next to the DLL.
static AUTH_TOKEN: OnceLock<&'static str> = OnceLock::new();

/// One-shot startup. Spawned from a worker thread by DllMain to
/// avoid the DllMain-loader-lock trap.
fn worker_main() {
    // 1. Initialize the modforge logger. It writes to a file in the
    //    same directory as the DLL (resolved via `set_dll_module`
    //    which DllMain called before spawning us).
    modforge::log::init(modforge::log::Config {
        file_name: "horseyforge.log",
        console_title: "horseyforge",
        console: false,
    });
    modforge::log!("horseyforge worker thread started");

    // 2. Resolve the DLL directory for our auth-file write.
    let dll_dir = modforge::log::dll_dir_wait(std::time::Duration::from_secs(5))
        .unwrap_or_else(|| std::path::PathBuf::from("."));

    // 3. Generate a random auth token; write it for clients to pick up.
    let token: String = (0..16).map(|_| format!("{:02x}", random_byte())).collect();
    let token: &'static str = Box::leak(token.into_boxed_str());
    let _ = AUTH_TOKEN.set(token);
    let auth_path = dll_dir.join("horseyforge.auth");
    if let Err(e) = std::fs::write(&auth_path, token) {
        modforge::log!(
            "horseyforge: failed to write auth file {}: {e}",
            auth_path.display()
        );
    } else {
        modforge::log!("horseyforge: auth token written to {}", auth_path.display());
    }

    // 4. Register Horsey-specific ops on the modforge global registry.
    ops::register_all();

    // 5. Install the sleep_safe_no_tire patch.
    //
    //   The game's `no_tire` cheat (DAT_1403d95c5) drives a per-frame
    //   loop in FUN_1400ceb60 that zeroes BOTH +0x205 and +0x206 on
    //   every horse. +0x206 is the sleep-gate's "is any horse tired"
    //   counter. When it's always 0, the player can't sleep.
    //
    //   This patch NOPs the +0x206 zero, leaving the +0x205 zero in
    //   place. Net effect: enabling no_tire bypasses race-eligibility
    //   fatigue without breaking the day cycle.
    match patches::sleep_safe_no_tire::apply() {
        Ok(()) => {
            // Now we can safely enable the game's own no_tire.
            gamestate::set_no_tire(true);
            modforge::log!(
                "horseyforge: sleep_safe_no_tire patched + game no_tire enabled"
            );
        }
        Err(e) => {
            modforge::log!(
                "horseyforge: sleep_safe_no_tire FAILED ({e}); leaving no_tire off so sleep still works"
            );
        }
    }

    // 5. Start the HTTP server. Single endpoint /op, auth via header.
    let server_cfg = modforge::server::Config {
        port: 33077,
        endpoint: "/op",
        thread_name: "horseyforge-http",
        auth_token: Some(token),
    };
    modforge::server::spawn(
        server_cfg,
        |body: &str| -> Vec<u8> {
            // Parse + dispatch via the modforge op envelope. This
            // mirrors what ueforge / unityforge do.
            let (op, args) = match modforge::envelope::parse_request(body) {
                Ok(v) => v,
                Err(e) => {
                    let resp = modforge::envelope::OpResponse::err(
                        "<parse-error>",
                        e,
                        snapshot::HorseyState::placeholder(),
                    );
                    return serde_json::to_vec(&resp).unwrap_or_else(|_| b"{}".to_vec());
                }
            };
            let state = snapshot::HorseyState::capture();
            let result = modforge::ops::OP_REGISTRY
                .dispatch(&op, &args)
                .unwrap_or_else(|| Err(format!("unknown op: {op}")));
            let resp = modforge::envelope::OpResponse::from_result(&op, result, state);
            serde_json::to_vec(&resp).unwrap_or_else(|_| b"{}".to_vec())
        },
        |msg| modforge::log!("{msg}"),
    );

    modforge::log!("horseyforge: listening on 127.0.0.1:33077 (auth in horseyforge.auth)");
}

fn random_byte() -> u8 {
    // ProcessRandomBytes via the OS tickcount + stack-address mixing.
    // Localhost-only auth token; this is plenty.
    use windows_sys::Win32::System::SystemInformation::GetTickCount;
    // SAFETY: GetTickCount is always callable from any thread.
    let mix = unsafe { GetTickCount() };
    let mut x: u32 = mix ^ ((&mix as *const _ as usize as u32).wrapping_mul(2654435761));
    x ^= x.wrapping_shl(13);
    x ^= x.wrapping_shr(7);
    x ^= x.wrapping_shl(17);
    (x & 0xff) as u8
}

// =============================================================================
// DllMain
// =============================================================================

use windows_sys::Win32::Foundation::HINSTANCE;

/// Windows BOOL: `i32` underneath. windows-sys 0.61 doesn't
/// re-export the alias.
type BOOL = i32;

const DLL_PROCESS_ATTACH: u32 = 1;
const DLL_THREAD_ATTACH: u32 = 2;
const DLL_THREAD_DETACH: u32 = 3;
const DLL_PROCESS_DETACH: u32 = 0;

/// PE entry. The MSVC linker recognizes the literal name `DllMain`
/// and generates the CRT bridge automatically.
#[unsafe(no_mangle)]
pub extern "system" fn DllMain(
    hinst: HINSTANCE,
    reason: u32,
    _reserved: *mut std::ffi::c_void,
) -> BOOL {
    match reason {
        DLL_PROCESS_ATTACH => {
            // Hand the HMODULE to modforge's logger so dll_dir()
            // can resolve our path. This call only touches loaded-DLL
            // metadata; safe inside DllMain.
            modforge::log::set_dll_module(hinst as _);
            // Spawn the worker. NEVER block here.
            std::thread::spawn(worker_main);
        }
        DLL_PROCESS_DETACH => {
            // Stop every server modforge has running so the listener
            // thread doesn't keep our DLL pinned past unload.
            modforge::server::shutdown_all();
            // Restore the bytes we overwrote in Horsey.exe so the
            // game runs vanilla again after we detach. CRITICAL.
            // without this, a hot-reload would leave NOPs in the
            // exe and the next-gen DLL would re-patch on top of
            // already-NOP'd code.
            patches::revert_all();
            // Best-effort: also turn off no_tire so the game's own
            // per-frame loop (with our NOPs reverted) doesn't keep
            // zeroing the tired flags.
            gamestate::set_no_tire(false);
        }
        DLL_THREAD_ATTACH | DLL_THREAD_DETACH => {}
        _ => {}
    }
    1 // TRUE
}
