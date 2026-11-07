//! poe2-mod: Path of Exile 2 helper, run beside the game.
//!
//! Reads game memory read-only and answers on a localhost control
//! server (`POST http://127.0.0.1:17185/op`). Never loads into the
//! game, never writes to it, never presses keys.

mod game;

use modforge::ops::{OP_REGISTRY, OpDef};
use modforge::process_memory::{ProcessMemory, find_pid_by_name, pe_timestamp};
use serde_json::{Value as Json, json};

/// Find the running game, open it read-only, and report its exe and
/// build stamp read both from memory and from the file on disk.
fn game_op(_args: &Json) -> Result<Json, String> {
    let Some((exe_name, pid)) = game::EXE_NAMES
        .iter()
        .find_map(|name| find_pid_by_name(name).ok().map(|pid| (*name, pid)))
    else {
        return Ok(json!({"running": false, "looked_for": game::EXE_NAMES}));
    };
    let mem = ProcessMemory::open(pid).map_err(|e| format!("open pid {pid} read-only: {e}"))?;
    let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
    let stamp_in_memory = mem
        .image_timestamp(&exe)
        .map_err(|e| format!("read PE header at {:#x}: {e}", exe.base))?;
    let stamp_on_disk = std::fs::read(&exe.path)
        .ok()
        .and_then(|bytes| pe_timestamp(&bytes));
    Ok(json!({
        "running": true,
        "exe_name": exe_name,
        "pid": pid,
        "exe_path": exe.path,
        "base": format!("{:#x}", exe.base),
        "size": exe.size,
        "access": format!("{:#x}", modforge::process_memory::READ_ACCESS),
        "stamp_in_memory": stamp_in_memory,
        "stamp_on_disk": stamp_on_disk,
    }))
}

fn main() {
    OP_REGISTRY.register(OpDef::new(
        "game",
        "find the running game, open it read-only, report exe and build stamp from memory and disk",
        "",
        game_op,
    ));
    OP_REGISTRY.register(OpDef::new("list_ops", "every op", "", |_| {
        Ok(OP_REGISTRY.list_json())
    }));
    modforge::server::spawn(
        modforge::server::Config {
            port: game::PORT,
            endpoint: "/op",
            thread_name: "poe2-mod-http",
            auth_token: None,
        },
        |body| {
            let response = modforge::envelope::handle_request(body, &OP_REGISTRY, || {
                json!({"process": "poe2-mod"})
            });
            serde_json::to_vec(&response).unwrap_or_default()
        },
        |message| println!("{message}"),
    );
    loop {
        std::thread::park();
    }
}
