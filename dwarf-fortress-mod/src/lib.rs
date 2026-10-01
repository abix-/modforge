//! Dwarf Fortress native research adapter.
//!
//! DFHack's dfhooks chainloader loads this DLL in the game process. The
//! adapter exposes modforge's process instrumentation over localhost without
//! duplicating DFHack's typed view of Dwarf Fortress state.

use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, AtomicU64, Ordering};

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use windows_sys::Win32::Foundation::HINSTANCE;

const HTTP_PORT: u16 = 33078;
static INITIALIZED: AtomicBool = AtomicBool::new(false);
static RESEARCH_SCRATCH: AtomicU64 = AtomicU64::new(0x5a17_c0de_1357_9bdf);

/// The chainloader currently initializes higher priorities first and shuts
/// down in reverse. Stay below DFHack's priority 100 so DFHack initializes
/// first and remains alive until after this adapter shuts down.
#[unsafe(no_mangle)]
pub static dfhooks_priority: i32 = 50;

fn arg_u64(args: &Json, key: &str, default: Option<u64>) -> Result<u64, String> {
    let Some(value) = args.get(key) else {
        return default.ok_or_else(|| format!("missing '{key}'"));
    };
    if let Some(value) = value.as_u64() {
        return Ok(value);
    }
    let Some(value) = value.as_str() else {
        return Err(format!("'{key}' must be an integer or hexadecimal string"));
    };
    let value = value.trim();
    if let Some(hex) = value
        .strip_prefix("0x")
        .or_else(|| value.strip_prefix("0X"))
    {
        u64::from_str_radix(hex, 16).map_err(|e| format!("invalid '{key}': {e}"))
    } else {
        value
            .parse::<u64>()
            .map_err(|e| format!("invalid '{key}': {e}"))
    }
}

fn raw_base_addr(args: &Json) -> Result<u64, String> {
    if args.get("addr").is_some() {
        return arg_u64(args, "addr", None);
    }
    let selector = args
        .get("instance_selector")
        .and_then(Json::as_str)
        .ok_or_else(|| "missing 'addr' or 'instance_selector'".to_string())?;
    let address = selector
        .strip_prefix("addr:")
        .ok_or_else(|| "only 'addr:0x...' instance selectors are available".to_string())?;
    arg_u64(&json!({"addr": address}), "addr", None)
}

fn read_memory(addr: usize, len: usize) -> Result<Json, String> {
    use windows_sys::Win32::System::Diagnostics::Debug::ReadProcessMemory;
    use windows_sys::Win32::System::Threading::GetCurrentProcess;

    if !(1..=4096).contains(&len) {
        return Err("'len' must be between 1 and 4096".to_string());
    }
    let mut bytes = vec![0u8; len];
    let mut read = 0usize;
    // SAFETY: ReadProcessMemory validates the source range in the kernel and
    // writes into the owned `bytes` allocation, which is exactly `len` bytes.
    let ok = unsafe {
        ReadProcessMemory(
            GetCurrentProcess(),
            addr as *const _,
            bytes.as_mut_ptr().cast(),
            len,
            &mut read,
        )
    };
    bytes.truncate(read);
    if ok == 0 || read == 0 {
        return Err(format!("address 0x{addr:x} is not readable"));
    }
    let ascii: String = bytes
        .iter()
        .map(|byte| {
            if byte.is_ascii_graphic() || *byte == b' ' {
                char::from(*byte)
            } else {
                '.'
            }
        })
        .collect();
    Ok(json!({
        "addr": format!("0x{addr:x}"),
        "requested": len,
        "read": read,
        "hex": bytes.iter().map(|byte| format!("{byte:02x}")).collect::<Vec<_>>().join(" "),
        "bytes_hex": bytes.iter().map(|byte| format!("{byte:02x}")).collect::<String>(),
        "ascii": ascii,
    }))
}

fn parse_hex_bytes(text: &str) -> Result<Vec<u8>, String> {
    let compact: String = text
        .chars()
        .filter(|character| !character.is_ascii_whitespace())
        .collect();
    if compact.is_empty() || !compact.len().is_multiple_of(2) {
        return Err(
            "'hex' must contain a non-empty, even number of hexadecimal digits".to_string(),
        );
    }
    (0..compact.len())
        .step_by(2)
        .map(|index| {
            u8::from_str_radix(&compact[index..index + 2], 16)
                .map_err(|error| format!("invalid hex byte at offset {index}: {error}"))
        })
        .collect()
}

fn write_memory(addr: usize, bytes: &[u8]) -> Result<Json, String> {
    use windows_sys::Win32::System::Diagnostics::Debug::WriteProcessMemory;
    use windows_sys::Win32::System::Threading::GetCurrentProcess;

    if bytes.is_empty() || bytes.len() > 4096 {
        return Err("write length must be between 1 and 4096 bytes".to_string());
    }
    let end = addr
        .checked_add(bytes.len() - 1)
        .ok_or_else(|| "write range overflows the address space".to_string())?;
    if !modforge::winproc::is_addr_writable(addr) || !modforge::winproc::is_addr_writable(end) {
        return Err(format!("range 0x{addr:x}..=0x{end:x} is not writable"));
    }
    let mut written = 0usize;
    // SAFETY: both endpoints are in writable committed pages and
    // WriteProcessMemory validates the complete range in the kernel.
    let ok = unsafe {
        WriteProcessMemory(
            GetCurrentProcess(),
            addr as *mut _,
            bytes.as_ptr().cast(),
            bytes.len(),
            &mut written,
        )
    };
    if ok == 0 || written != bytes.len() {
        return Err(format!(
            "WriteProcessMemory wrote {written} of {} bytes",
            bytes.len()
        ));
    }
    let readback = read_memory(addr, bytes.len())?;
    Ok(json!({
        "addr": format!("0x{addr:x}"),
        "written": written,
        "readback": readback,
    }))
}

fn register_ops() {
    modforge::counters::register_ops();

    OP_REGISTRY.register_many(vec![
        OpDef::new(
            "ping",
            "Verify the in-process adapter is responsive",
            "{}",
            |_args| Ok(json!("pong")),
        ),
        OpDef::new(
            "list_ops",
            "List registered research operations",
            "{}",
            |_args| Ok(OP_REGISTRY.list_json()),
        ),
        OpDef::new(
            "process.modules",
            "List modules loaded in the Dwarf Fortress process",
            "{}",
            |_args| {
                Ok(json!({
                    "modules": modforge::winproc::loaded_modules()
                        .into_iter()
                        .map(|(base, size, name)| json!({
                            "base": format!("0x{base:x}"),
                            "size": size,
                            "name": name,
                        }))
                        .collect::<Vec<_>>(),
                }))
            },
        ),
        OpDef::new(
            "process.threads",
            "List process threads with names and accumulated CPU time",
            "{}",
            |_args| Ok(modforge::winproc::process_threads_json()),
        ),
        OpDef::new(
            "process.cpu",
            "Read total process user and kernel CPU time",
            "{}",
            |_args| Ok(modforge::winproc::process_cpu_json()),
        ),
        OpDef::new(
            "process.memory",
            "Read process working-set, private-memory, and page-fault counters",
            "{}",
            |_args| Ok(modforge::winproc::process_memory_json()),
        ),
        OpDef::new(
            "process.regions",
            "Map committed, reserved, image, mapped, and private memory regions",
            "{}",
            |_args| Ok(modforge::winproc::process_regions_json()),
        ),
        OpDef::new(
            "process.sample_threads",
            "Sample thread instruction pointers and attribute execution to modules",
            "{duration_ms?: 1000, interval_ms?: 20}",
            |args| {
                let duration_ms = arg_u64(args, "duration_ms", Some(1_000))?.min(30_000) as u32;
                let interval_ms = arg_u64(args, "interval_ms", Some(20))?.clamp(10, 1_000) as u32;
                Ok(modforge::winproc::sample_thread_modules_json(
                    duration_ms,
                    interval_ms,
                ))
            },
        ),
        OpDef::new(
            "sample_thread_modules",
            "Canonical process thread instruction-pointer sampler",
            "{duration_ms?: 1000, interval_ms?: 20}",
            |args| {
                let duration_ms = arg_u64(args, "duration_ms", Some(1_000))?.min(30_000) as u32;
                let interval_ms = arg_u64(args, "interval_ms", Some(20))?.clamp(10, 1_000) as u32;
                Ok(modforge::winproc::sample_thread_modules_json(
                    duration_ms,
                    interval_ms,
                ))
            },
        ),
        OpDef::new(
            "memory.read",
            "Read up to 4096 bytes from an in-process address",
            "{addr: u64|hex-string, len?: 64}",
            |args| {
                let addr = arg_u64(args, "addr", None)? as usize;
                let len = arg_u64(args, "len", Some(64))? as usize;
                read_memory(addr, len)
            },
        ),
        OpDef::new(
            "memory.write",
            "Write up to 4096 bytes to writable in-process memory and read them back",
            "{addr: u64|hex-string, offset?: u64, hex: string}",
            |args| {
                let base = arg_u64(args, "addr", None)?;
                let offset = arg_u64(args, "offset", Some(0))?;
                let addr = base
                    .checked_add(offset)
                    .ok_or_else(|| "addr + offset overflowed".to_string())?
                    as usize;
                let bytes = parse_hex_bytes(
                    args.get("hex")
                        .and_then(Json::as_str)
                        .ok_or_else(|| "missing 'hex'".to_string())?,
                )?;
                write_memory(addr, &bytes)
            },
        ),
        OpDef::new(
            "memory.scratch",
            "Return an adapter-owned writable address for nondestructive tool tests",
            "{}",
            |_args| {
                Ok(json!({
                    "addr": format!("0x{:x}", std::ptr::addr_of!(RESEARCH_SCRATCH) as usize),
                    "value": format!("0x{:x}", RESEARCH_SCRATCH.load(Ordering::Relaxed)),
                    "size": std::mem::size_of::<AtomicU64>(),
                }))
            },
        ),
        OpDef::new(
            "memory.scan",
            "Start a Cheat-Engine-style scan of readable process memory",
            "{type: u8|i8|u16|i16|u32|i32|u64|i64|f32|f64, value: number, regions?: string}",
            modforge::scanner::scan_memory,
        ),
        OpDef::new(
            "memory.rescan",
            "Narrow a memory scan after game state changes",
            "{session_id: u64, mode: exact|changed|unchanged|decreased|increased, value?: number}",
            modforge::scanner::scan_rescan,
        ),
        OpDef::new(
            "memory.session",
            "Read a page of surviving addresses from a memory scan",
            "{session_id: u64, max?: u32, offset?: u32}",
            modforge::scanner::scan_session,
        ),
        OpDef::new(
            "memory.scan_close",
            "Release a completed memory scan session",
            "{session_id: u64}",
            modforge::scanner::scan_close,
        ),
        OpDef::new(
            "memory.scan_cancel",
            "Cancel the currently running memory scan",
            "{}",
            modforge::scanner::scan_cancel,
        ),
        OpDef::new(
            "scan_memory",
            "First-scan: find all addresses holding a typed value",
            "{type: string, value: number, regions?: string}",
            modforge::scanner::scan_memory,
        ),
        OpDef::new(
            "scan_rescan",
            "Narrow a scan session by rereading current values",
            "{session_id: u64, mode: string, value?: number, delta?: number}",
            modforge::scanner::scan_rescan,
        ),
        OpDef::new(
            "scan_session",
            "Paginate over a scan session's surviving addresses",
            "{session_id: u64, max?: u64, offset?: u64}",
            modforge::scanner::scan_session,
        ),
        OpDef::new(
            "scan_close",
            "Drop a scan session",
            "{session_id: u64}",
            modforge::scanner::scan_close,
        ),
        OpDef::new(
            "scan_cancel",
            "Cancel an in-flight memory scan or rescan",
            "{}",
            modforge::scanner::scan_cancel,
        ),
        OpDef::new(
            "freeze",
            "Continuously hold a typed value at a writable address",
            "{addr: u64|hex-string, offset?: u64, type: string, value: number, hz?: u32}",
            modforge::scanner::freeze,
        ),
        OpDef::new(
            "unfreeze",
            "Stop holding a value at an address",
            "{addr: u64|hex-string}",
            modforge::scanner::unfreeze,
        ),
        OpDef::new(
            "freeze_list",
            "List all active memory freezes",
            "{}",
            modforge::scanner::freeze_list,
        ),
        OpDef::new(
            "read_bytes",
            "Canonical raw-memory read operation",
            "{addr?: u64|hex-string, instance_selector?: 'addr:0x...', offset?: u64, length?: 64}",
            |args| {
                let base = raw_base_addr(args)?;
                let offset = arg_u64(args, "offset", Some(0))?;
                let addr = base
                    .checked_add(offset)
                    .ok_or_else(|| "addr + offset overflowed".to_string())?
                    as usize;
                let len = if args.get("length").is_some() {
                    arg_u64(args, "length", None)?
                } else {
                    arg_u64(args, "len", Some(64))?
                } as usize;
                read_memory(addr, len)
            },
        ),
        OpDef::new(
            "write_bytes",
            "Canonical raw-memory write operation",
            "{addr?: u64|hex-string, instance_selector?: 'addr:0x...', offset?: u64, bytes_hex: string}",
            |args| {
                let base = raw_base_addr(args)?;
                let offset = arg_u64(args, "offset", Some(0))?;
                let addr = base
                    .checked_add(offset)
                    .ok_or_else(|| "addr + offset overflowed".to_string())?
                    as usize;
                let bytes = parse_hex_bytes(
                    args.get("bytes_hex")
                        .or_else(|| args.get("hex"))
                        .and_then(Json::as_str)
                        .ok_or_else(|| "missing 'bytes_hex'".to_string())?,
                )?;
                write_memory(addr, &bytes)
            },
        ),
        OpDef::new(
            "image.scan",
            "Scan Dwarf Fortress image bytes using a patternsleuth signature",
            "{signature: string, section?: text|data|rdata|all, max?: 200}",
            |args| {
                let signature = args
                    .get("signature")
                    .and_then(Json::as_str)
                    .ok_or_else(|| "missing 'signature'".to_string())?;
                let section = args.get("section").and_then(Json::as_str).unwrap_or("text");
                let hits = match section {
                    "text" => modforge::patterns::sleuth::scan_all_matches(signature),
                    "data" => modforge::patterns::sleuth::scan_data_matches(signature),
                    "rdata" => modforge::patterns::sleuth::scan_rdata_matches(signature),
                    "all" => modforge::patterns::sleuth::scan_section(signature, None),
                    _ => return Err("'section' must be text, data, rdata, or all".to_string()),
                }
                .map_err(|error| error.to_string())?;
                let total = hits.len();
                let max = arg_u64(args, "max", Some(200))?.min(2_000) as usize;
                Ok(json!({
                    "signature": signature,
                    "section": section,
                    "total": total,
                    "hits": hits.into_iter().take(max)
                        .map(|addr| format!("0x{addr:x}"))
                        .collect::<Vec<_>>(),
                }))
            },
        ),
        OpDef::new(
            "watch_writes",
            "Watch an in-process address and capture its native writer and call chain",
            "{addr: u64|hex-string, len?: 1|2|4|8, duration_ms?: u32, mode?: write|readwrite|exec}",
            |args| {
                let addr = arg_u64(args, "addr", None)? as usize;
                let len = arg_u64(args, "len", Some(4))? as u8;
                let duration_ms = arg_u64(args, "duration_ms", Some(60_000))?;
                let duration_ms = u32::try_from(duration_ms)
                    .map_err(|_| "'duration_ms' exceeds u32".to_string())?;
                let mode = args.get("mode").and_then(Json::as_str).unwrap_or("write");
                Ok(modforge::winproc::capture_write_watchpoint(
                    addr,
                    len,
                    duration_ms,
                    mode,
                ))
            },
        ),
        OpDef::new(
            "hooks.list",
            "List native detours installed through Modforge",
            "{}",
            |_args| {
                Ok(json!({
                    "hooks": modforge::hook::registry()
                        .into_iter()
                        .map(|hook| json!({
                            "name": hook.name,
                            "target_addr": format!("0x{:x}", hook.target_addr),
                            "enabled": hook.enabled,
                        }))
                        .collect::<Vec<_>>(),
                }))
            },
        ),
        OpDef::new(
            "op_metrics",
            "Report dispatch latency and errors for every operation",
            "{}",
            |_args| Ok(modforge::ops::metrics_json()),
        ),
    ]);

    OP_REGISTRY.register_many(modforge::input::ops::all());
}

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

    register_ops();
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
