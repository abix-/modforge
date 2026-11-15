//! The research ops every mod DLL loaded into a native game serves:
//! modules, threads, CPU and memory counters, raw reads and writes, the
//! value scanner and freezes, image scans, write watchpoints, hooks,
//! op metrics and input.
//!
//! Moved here from dwarf-fortress-mod when Enshrouded became the second
//! mod to need the same set. `patterns.read_bytes` and
//! `patterns.rip_sites` answer in the shape
//! [`crate::memory_research::Remote`] reads, so research tests written
//! against an outside reader work unchanged against an injected DLL.

use std::sync::atomic::{AtomicU64, Ordering};

use crate::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

static RESEARCH_SCRATCH: AtomicU64 = AtomicU64::new(0x5a17_c0de_1357_9bdf);

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
    if !crate::winproc::is_addr_writable(addr) || !crate::winproc::is_addr_writable(end) {
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

/// This process opened read-only through the same reader the outside
/// mods use, so the Remote-shaped replies are built by one function.
fn own_process() -> Result<crate::process_memory::ProcessMemory, String> {
    crate::process_memory::ProcessMemory::open(std::process::id())
        .map_err(|e| format!("open own process: {e}"))
}

/// Register every op in this module, plus `counters` and `input` ops.
pub fn register() {
    crate::counters::register_ops();

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
            "List modules loaded in the game process",
            "{}",
            |_args| {
                Ok(json!({
                    "modules": crate::winproc::loaded_modules()
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
            |_args| Ok(crate::winproc::process_threads_json()),
        ),
        OpDef::new(
            "process.cpu",
            "Read total process user and kernel CPU time",
            "{}",
            |_args| Ok(crate::winproc::process_cpu_json()),
        ),
        OpDef::new(
            "process.memory",
            "Read process working-set, private-memory, and page-fault counters",
            "{}",
            |_args| Ok(crate::winproc::process_memory_json()),
        ),
        OpDef::new(
            "process.regions",
            "Map committed, reserved, image, mapped, and private memory regions",
            "{}",
            |_args| Ok(crate::winproc::process_regions_json()),
        ),
        OpDef::new(
            "process.sample_threads",
            "Sample thread instruction pointers and attribute execution to modules",
            "{duration_ms?: 1000, interval_ms?: 20}",
            |args| {
                let duration_ms = arg_u64(args, "duration_ms", Some(1_000))?.min(30_000) as u32;
                let interval_ms = arg_u64(args, "interval_ms", Some(20))?.clamp(10, 1_000) as u32;
                Ok(crate::winproc::sample_thread_modules_json(
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
                Ok(crate::winproc::sample_thread_modules_json(
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
            crate::scanner::scan_memory,
        ),
        OpDef::new(
            "memory.find_bytes",
            "Find a byte sequence or text (UTF-8, or UTF-16 with utf16) in readable private memory",
            "{text?: string, utf16?: bool, hex?: string, max?: 1000}",
            crate::scanner::find_bytes,
        ),
        OpDef::new(
            "memory.rescan",
            "Narrow a memory scan after game state changes",
            "{session_id: u64, mode: exact|changed|unchanged|decreased|increased, value?: number}",
            crate::scanner::scan_rescan,
        ),
        OpDef::new(
            "memory.session",
            "Read a page of surviving addresses from a memory scan",
            "{session_id: u64, max?: u32, offset?: u32}",
            crate::scanner::scan_session,
        ),
        OpDef::new(
            "memory.scan_close",
            "Release a completed memory scan session",
            "{session_id: u64}",
            crate::scanner::scan_close,
        ),
        OpDef::new(
            "memory.scan_cancel",
            "Cancel the currently running memory scan",
            "{}",
            crate::scanner::scan_cancel,
        ),
        OpDef::new(
            "scan_memory",
            "First-scan: find all addresses holding a typed value",
            "{type: string, value: number, regions?: string}",
            crate::scanner::scan_memory,
        ),
        OpDef::new(
            "scan_rescan",
            "Narrow a scan session by rereading current values",
            "{session_id: u64, mode: string, value?: number, delta?: number}",
            crate::scanner::scan_rescan,
        ),
        OpDef::new(
            "scan_session",
            "Paginate over a scan session's surviving addresses",
            "{session_id: u64, max?: u64, offset?: u64}",
            crate::scanner::scan_session,
        ),
        OpDef::new(
            "scan_close",
            "Drop a scan session",
            "{session_id: u64}",
            crate::scanner::scan_close,
        ),
        OpDef::new(
            "scan_cancel",
            "Cancel an in-flight memory scan or rescan",
            "{}",
            crate::scanner::scan_cancel,
        ),
        OpDef::new(
            "freeze",
            "Continuously hold a typed value at a writable address",
            "{addr: u64|hex-string, offset?: u64, type: string, value: number, hz?: u32}",
            crate::scanner::freeze,
        ),
        OpDef::new(
            "unfreeze",
            "Stop holding a value at an address",
            "{addr: u64|hex-string}",
            crate::scanner::unfreeze,
        ),
        OpDef::new(
            "freeze_list",
            "List all active memory freezes",
            "{}",
            crate::scanner::freeze_list,
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
            "patterns.read_bytes",
            "read-only: n bytes (at most 4096) at addr as hex, in the shape memory_research::Remote reads",
            "addr, n",
            |args| crate::memory_research::read_bytes_reply(&own_process()?, args),
        ),
        OpDef::new(
            "patterns.rip_sites",
            "read-only: every match of sig in the exe's code, its operand address and where it points",
            "sig",
            |args| {
                let mem = own_process()?;
                let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
                let image = crate::patterns::sleuth::read_process_image(&mem, &exe)
                    .map_err(|e| format!("read exe image: {e:#}"))?;
                crate::memory_research::rip_sites_reply(&image, &(exe.base..exe.base + exe.size), args)
            },
        ),
        OpDef::new(
            "image.scan",
            "Scan the game exe's bytes using a patternsleuth signature",
            "{signature: string, section?: text|data|rdata|all, max?: 200}",
            |args| {
                let signature = args
                    .get("signature")
                    .and_then(Json::as_str)
                    .ok_or_else(|| "missing 'signature'".to_string())?;
                let section = args.get("section").and_then(Json::as_str).unwrap_or("text");
                let hits = match section {
                    "text" => crate::patterns::sleuth::scan_all_matches(signature),
                    "data" => crate::patterns::sleuth::scan_data_matches(signature),
                    "rdata" => crate::patterns::sleuth::scan_rdata_matches(signature),
                    "all" => crate::patterns::sleuth::scan_section(signature, None),
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
                Ok(crate::winproc::capture_write_watchpoint(
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
                    "hooks": crate::hook::registry()
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
            |_args| Ok(crate::ops::metrics_json()),
        ),
    ]);

    OP_REGISTRY.register_many(crate::input::ops::all());
}
