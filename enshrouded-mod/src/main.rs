//! enshrouded-mod: Enshrouded helper, run beside the game.
//!
//! Reads game memory read-only and answers on a localhost control
//! server (`POST http://127.0.0.1:17187/op`). Never loads into the
//! game, never writes to it.

use modforge::memory_research::{read_bytes_reply, rip_sites_reply};
use modforge::ops::{OP_REGISTRY, OpDef};
use modforge::patterns::sleuth::{read_process_image, scan_image};
use modforge::process_memory::{Module, ProcessMemory, find_pid_by_name};
use parking_lot::{Mutex, MutexGuard};
use serde_json::{Value as Json, json};

const EXE_NAME: &str = "enshrouded.exe";

/// Control server port, next free after the other mods (17171..17186).
const PORT: u16 = 17187;

/// Most addresses one patterns.find reply lists.
const FIND_MAX: usize = 256;

/// The game we have open, kept until its pid changes.
struct Attached {
    pid: u32,
    exe: Module,
    mem: ProcessMemory,
}

static ATTACHED: Mutex<Option<Attached>> = Mutex::new(None);

/// Open the running game read-only, unless it already is.
fn attached() -> Result<MutexGuard<'static, Option<Attached>>, String> {
    let mut guard = ATTACHED.lock();
    if guard.as_ref().is_some_and(|a| a.mem.is_running()) {
        return Ok(guard);
    }
    let pid = find_pid_by_name(EXE_NAME).map_err(|_| "game not running")?;
    let mem = ProcessMemory::open(pid).map_err(|e| format!("open pid {pid} read-only: {e}"))?;
    let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
    *guard = Some(Attached { pid, exe, mem });
    Ok(guard)
}

fn game_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let timestamp = a
        .mem
        .image_timestamp(&a.exe)
        .map_err(|e| format!("read PE timestamp: {e}"))?;
    Ok(json!({
        "pid": a.pid,
        "path": a.exe.path,
        "base": format!("{:#x}", a.exe.base),
        "size": a.exe.size,
        "pe_timestamp": timestamp,
    }))
}

fn read_bytes_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    read_bytes_reply(&a.mem, args)
}

/// The section a patterns.find is limited to; None searches them all.
fn section_arg(args: &Json) -> Result<Option<object::SectionKind>, String> {
    match args["section"].as_str().unwrap_or("any") {
        "any" => Ok(None),
        "text" => Ok(Some(object::SectionKind::Text)),
        "rdata" => Ok(Some(object::SectionKind::ReadOnlyData)),
        "data" => Ok(Some(object::SectionKind::Data)),
        other => Err(format!("section {other:?}: one of any, text, rdata, data")),
    }
}

/// Every match of `sig` in the exe as it is in memory now. The image is
/// read fresh each call, since .data changes while the game runs.
fn find_op(args: &Json) -> Result<Json, String> {
    let sig = args["sig"].as_str().ok_or("sig missing")?;
    let section = section_arg(args)?;
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let image = read_process_image(&a.mem, &a.exe).map_err(|e| format!("read exe image: {e:#}"))?;
    let hits = scan_image(&image, sig, section).map_err(|e| format!("{e:#}"))?;
    let listed: Vec<String> = hits
        .iter()
        .take(FIND_MAX)
        .map(|x| format!("{x:#x}"))
        .collect();
    Ok(json!({
        "sig": sig,
        "count": hits.len(),
        "addresses": listed,
    }))
}

fn rip_sites_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let image = read_process_image(&a.mem, &a.exe).map_err(|e| format!("read exe image: {e:#}"))?;
    let exe = a.exe.base..a.exe.base + a.exe.size;
    rip_sites_reply(&image, &exe, args)
}

fn main() {
    modforge::counters::register_ops();
    OP_REGISTRY.register_many(vec![
        OpDef::new("ping", "Liveness check", "", |_| Ok(json!("pong"))),
        OpDef::new("list_ops", "every op", "", |_| Ok(OP_REGISTRY.list_json())),
        OpDef::new(
            "game",
            "the running game: pid, exe path, load address, size and PE timestamp",
            "",
            game_op,
        ),
        OpDef::new(
            "patterns.read_bytes",
            "read-only: n bytes (at most 4096) at addr as hex, for offset research",
            "addr, n",
            read_bytes_op,
        ),
        OpDef::new(
            "patterns.find",
            "read-only: every address in the exe where sig matches, in one section (any, text, rdata, data)",
            "sig, section?",
            find_op,
        ),
        OpDef::new(
            "patterns.rip_sites",
            "read-only: every match of sig in the exe's code, its operand address and where it points",
            "sig",
            rip_sites_op,
        ),
    ]);
    modforge::server::spawn(
        modforge::server::Config {
            port: PORT,
            endpoint: "/op",
            thread_name: "enshrouded-mod-http",
            auth_token: None,
        },
        |body| {
            let response = modforge::envelope::handle_request(body, &OP_REGISTRY, || {
                json!({"process": "enshrouded-mod"})
            });
            serde_json::to_vec(&response).unwrap_or_default()
        },
        |message| println!("{message}"),
    );
    println!("enshrouded-mod: listening on 127.0.0.1:{PORT}");
    loop {
        std::thread::park();
    }
}
