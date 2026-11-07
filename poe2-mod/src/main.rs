//! poe2-mod: Path of Exile 2 helper, run beside the game.
//!
//! Reads game memory read-only and answers on a localhost control
//! server (`POST http://127.0.0.1:17185/op`). Never loads into the
//! game, never writes to it, never presses keys.

mod game;

use modforge::ops::{OP_REGISTRY, OpDef};
use modforge::patterns::sleuth::{TEXT_SECTION, read_process_image, unique_rip_target};
use modforge::process_memory::{Module, ProcessMemory, find_pid_by_name, pe_timestamp};
use parking_lot::{Mutex, MutexGuard};
use serde_json::{Value as Json, json};

/// One static pattern's result.
struct Found {
    pattern: &'static game::StaticPattern,
    address: Result<u64, String>,
}

/// The game we have open, and the globals its patterns found. Kept
/// until the game's pid changes, so the exe is read and searched once
/// per game run, not on every op.
struct Attached {
    pid: u32,
    exe: Module,
    mem: ProcessMemory,
    statics: Vec<Found>,
}

impl Attached {
    /// The address the first pattern named `name` that matched found;
    /// the `statics` op shows whether the others agree.
    fn static_address(&self, name: &str) -> Result<u64, String> {
        let mut errors = Vec::new();
        for f in self.statics.iter().filter(|f| f.pattern.name == name) {
            match &f.address {
                Ok(address) => return Ok(*address),
                Err(e) => errors.push(format!("{}: {e}", f.pattern.source)),
            }
        }
        if errors.is_empty() {
            Err(format!("no pattern named {name:?}"))
        } else {
            Err(format!("{name}: {}", errors.join("; ")))
        }
    }
}

static ATTACHED: Mutex<Option<Attached>> = Mutex::new(None);

fn find_game() -> Option<(&'static str, u32)> {
    game::EXE_NAMES
        .iter()
        .find_map(|name| find_pid_by_name(name).ok().map(|pid| (*name, pid)))
}

/// Open the running game read-only and search its exe for every static
/// pattern, unless that was already done for this pid.
fn attached() -> Result<MutexGuard<'static, Option<Attached>>, String> {
    let (_, pid) = find_game().ok_or("game not running")?;
    let mut guard = ATTACHED.lock();
    if guard.as_ref().is_some_and(|a| a.pid == pid) {
        return Ok(guard);
    }
    let mem = ProcessMemory::open(pid).map_err(|e| format!("open pid {pid} read-only: {e}"))?;
    let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
    let image = read_process_image(&mem, &exe).map_err(|e| format!("read exe image: {e:#}"))?;
    let statics = game::STATIC_PATTERNS
        .iter()
        .map(|pattern| Found {
            pattern,
            address: unique_rip_target(&image, pattern.sig, Some(TEXT_SECTION))
                .map_err(|e| format!("{e:#}")),
        })
        .collect();
    *guard = Some(Attached {
        pid,
        exe,
        mem,
        statics,
    });
    Ok(guard)
}

/// Every static pattern, the address it found, and for each name
/// whether all its patterns agree.
fn statics_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let patterns: Vec<Json> = a
        .statics
        .iter()
        .map(|f| {
            json!({
                "name": f.pattern.name,
                "source": f.pattern.source,
                "address": f.address.as_ref().ok().map(|x| format!("{x:#x}")),
                "rva": f.address.as_ref().ok().map(|x| format!("{:#x}", x - a.exe.base)),
                "error": f.address.as_ref().err(),
            })
        })
        .collect();
    let mut agree = serde_json::Map::new();
    for f in &a.statics {
        let same: Vec<_> = a
            .statics
            .iter()
            .filter(|g| g.pattern.name == f.pattern.name)
            .map(|g| g.address.as_ref().ok().copied())
            .collect();
        let all_found_and_equal = same.iter().all(|x| x.is_some() && *x == same[0]);
        agree.insert(f.pattern.name.to_string(), json!(all_found_and_equal));
    }
    Ok(json!({"pid": a.pid, "base": format!("{:#x}", a.exe.base), "patterns": patterns, "agree": agree}))
}

/// The current game state, read the way GameHelper2's GameStates does:
/// the "Game States" global points at an object holding a vector whose
/// entry 0x10 before its end is the current state, and an array of the
/// thirteen states in a fixed order.
fn game_state_op(_args: &Json) -> Result<Json, String> {
    use game::game_states as gs;
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let read_ptr = |addr: u64| {
        a.mem
            .read_value::<u64>(addr)
            .map_err(|e| format!("read pointer at {addr:#x}: {e}"))
    };
    let global = a.static_address("Game States")?;
    let object = read_ptr(global)?;
    let vector_last = read_ptr(object + gs::CURRENT_STATE_VECTOR + 8)?;
    let current = read_ptr(
        vector_last
            .checked_sub(gs::CURRENT_STATE_FROM_END)
            .ok_or("current state vector is empty")?,
    )?;
    let mut states = Vec::with_capacity(gs::NAMES.len());
    for (i, name) in gs::NAMES.iter().enumerate() {
        let at = read_ptr(object + gs::STATES + i as u64 * gs::STATE_STRIDE)?;
        states.push((*name, at));
    }
    let current_name = states
        .iter()
        .find(|(_, at)| *at == current && current != 0)
        .map(|(name, _)| *name);
    Ok(json!({
        "game_states_global": format!("{global:#x}"),
        "game_states": format!("{object:#x}"),
        "current": format!("{current:#x}"),
        "current_name": current_name,
        "states": states.iter().map(|(name, at)| json!({"name": name, "address": format!("{at:#x}")})).collect::<Vec<_>>(),
    }))
}

/// Find the running game, open it read-only, and report its exe and
/// build stamp read both from memory and from the file on disk.
fn game_op(_args: &Json) -> Result<Json, String> {
    let Some((exe_name, pid)) = find_game() else {
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
    OP_REGISTRY.register(OpDef::new(
        "statics",
        "search the game's exe for every static pattern; each address found and whether patterns of one name agree",
        "",
        statics_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "game_state",
        "the current game state and the thirteen state addresses, read like GameHelper2's GameStates",
        "",
        game_state_op,
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
