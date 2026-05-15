//! Horsey-specific ops registered on modforge's global op
//! registry. Every op here is a closure that reads or writes the
//! game state via `gamestate.rs` / `horse.rs`.
//!
//! Wire format: requests are JSON `{"op":"name","args":{...}}`,
//! posted to `127.0.0.1:33077/op` with the auth header
//! `X-Ueforge-Auth: <token>` (token is in `horsey.auth`).
//!
//! Each op returns a `Json` result; the envelope around it
//! (`{"ok":..., "op":..., "result":..., "state":...}`) is added
//! by lib.rs's handler.

use modforge::ops::{OpDef, OP_REGISTRY};
use serde_json::{json, Value as Json};

use crate::fatigue;
use crate::gamestate;
use crate::genes::{
    self, ExtGene, ExtHorseGenome, RenderMapping, RenderMode, EXT_GENE_COUNT,
};
use crate::genes_xml;
use crate::horse;
use crate::patches;

/// Register every Horsey op on the modforge global registry.
/// Called once from the worker thread at DLL init.
pub fn register_all() {
    OP_REGISTRY.register_many(vec![
        OpDef::new("ping", "Liveness check", "", |_| Ok(json!("pong"))),

        // ===== Hot-reload protocol =====
        //
        // The injector (`horsey-inject.exe --reload`) issues this op
        // before remotely calling FreeLibrary on our HMODULE. After the
        // op returns we drop every SpawnHandle in modforge's registry
        // so the HTTP listener thread joins and releases port 33077.
        //
        // We schedule the actual shutdown on a fresh thread so we can
        // RETURN the success response to the client first. If we
        // shut the server down before returning, the client never
        // sees the OK and may panic.
        OpDef::new(
            "_shutdown",
            "Stop the HTTP server. Used by the injector before unloading the DLL for hot-reload.",
            "",
            |_| {
                std::thread::Builder::new()
                    .name("horsey-shutdown".into())
                    .spawn(|| {
                        // Tiny delay so the in-flight HTTP response
                        // has time to flush to the client socket.
                        std::thread::sleep(std::time::Duration::from_millis(100));
                        modforge::log!("horsey-mod: _shutdown -> dropping server");
                        modforge::server::shutdown_all();
                    })
                    .ok();
                Ok(json!({"shutting_down": true}))
            },
        ),

        OpDef::new(
            "list_ops",
            "List every op registered on the global registry.",
            "",
            |_| Ok(OP_REGISTRY.list_json()),
        ),

        // ===== GameState reads =====
        OpDef::new(
            "game.read",
            "Read the high-level game state snapshot.",
            "",
            |_| {
                Ok(json!({
                    "money": gamestate::money(),
                    "year": gamestate::year(),
                    "sleeps": gamestate::sleeps(),
                    "races": gamestate::races(),
                    "horse_count": gamestate::horse_count(),
                    "world_loaded": gamestate::looks_loaded(),
                    "no_tire": gamestate::no_tire(),
                    "debug_mode": gamestate::debug_mode(),
                }))
            },
        ),

        // Forensic dump of every byte / value the loaded-save heuristic
        // depends on. Driven by `tests/gamestate_diag.rs`. The op
        // itself never asserts; consumers print + diff.
        OpDef::new(
            "gamestate.diag",
            "Raw values used by gamestate::looks_loaded(). For tests / debugging.",
            "",
            |_| Ok(gamestate::diag()),
        ),

        // R3: pattern-scan-resolve the GAMESTATE_PTR data address
        // via modforge::patterns::sleuth. Recovery path for the
        // 'hardcoded address drifted' bug class.
        // Scan `.text` for RIP-relative instructions whose decoded
        // disp32 resolves to `target_addr`. Backed by
        // `modforge::patterns::sleuth::scan_all_matches` with a
        // patternsleuth `X<target>` xref pattern; no hand-rolled
        // byte scanning (rule locked in horsey-mod/docs/todo.md
        // "P0 RULE: USE PATTERNSLEUTH" and in global CLAUDE.md).
        // For each hit returns a 16-byte context window so
        // signatures can be authored directly from real compiler
        // output.
        OpDef::new(
            "mem.find_xrefs",
            "Scan .text for RIP-relative xrefs to a target data address \
            via patternsleuth X<target> pattern. Returns hits with byte context.",
            "{target_addr: u64, max_hits?: usize}",
            |args| {
                let target = args
                    .get("target_addr")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: target_addr".to_string())?
                    as usize;
                let max_hits = args
                    .get("max_hits")
                    .and_then(Json::as_u64)
                    .unwrap_or(64) as usize;
                // Patternsleuth's SIMD grouper needs anchor bytes
                // in the signature, so a bare `X<target>` won't
                // scan. Instead enumerate the common RIP-relative
                // opcode prefixes for x86_64 MSVC output and scan
                // each separately. Patternsleuth handles each
                // anchored scan; we union, dedupe, and return.
                //
                // The prefix list covers the encodings actually
                // emitted by MSVC for GameState-style global access:
                // u32/u8 loads, stores, compares with imm8/imm32,
                // adds with imm32, byte XORs, SSE moves.
                const PREFIXES: &[(&str, &str, usize)] = &[
                    // (name, prefix_bytes, disp32_offset_from_match_start)
                    ("mov_r64",     "48 8b 05",     3),
                    ("mov_r32",     "8b 05",        2),
                    ("mov_store64", "48 89 05",     3),
                    ("mov_store32", "89 05",        2),
                    ("lea_r64",     "48 8d 05",     3),
                    ("add_imm32",   "81 05",        2),
                    ("add_imm8",    "83 05",        2),
                    ("cmp_dw_imm8", "83 3d",        2),
                    ("cmp_dw_imm32","81 3d",        2),
                    ("mov_dw_imm",  "c7 05",        2),
                    ("mov_b_imm",   "c6 05",        2),
                    ("cmp_b_imm",   "80 3d",        2),
                    ("xor_b_imm",   "80 35",        2),
                    ("movzx",       "0f b6 05",     3),
                    ("movdqa_xmm6", "66 0f 7f 35",  4),
                ];
                let target_hex = format!("X0x{target:x}");
                let mut all_hits: Vec<(usize, &'static str, usize)> = Vec::new();
                for (name, prefix, disp_off) in PREFIXES {
                    let sig = format!("{prefix} {target_hex}");
                    match modforge::patterns::sleuth::scan_all_matches(&sig) {
                        Ok(addrs) => {
                            for addr in addrs {
                                all_hits.push((addr, name, *disp_off));
                            }
                        }
                        Err(e) => {
                            modforge::log!("find_xrefs sig {sig:?} skipped: {e}");
                        }
                    }
                }
                all_hits.sort_unstable_by_key(|(a, _, _)| *a);
                all_hits.dedup_by_key(|(a, _, _)| *a);
                all_hits.truncate(max_hits);
                let entries: Vec<Json> = all_hits.iter().map(|&(instr_addr, name, disp_off)| {
                    let disp_addr = instr_addr + disp_off;
                    let start = instr_addr;
                    let end = disp_addr + 4 + 6;
                    let len = end - start;
                    // SAFETY: address is inside the .text section
                    // patternsleuth scanned; readable for the
                    // process lifetime.
                    let bytes: Vec<u8> = unsafe {
                        std::slice::from_raw_parts(start as *const u8, len).to_vec()
                    };
                    let context_hex = bytes
                        .iter()
                        .map(|b| format!("{b:02x}"))
                        .collect::<Vec<_>>()
                        .join(" ");
                    json!({
                        "instr_addr": format!("0x{instr_addr:x}"),
                        "disp32_addr": format!("0x{disp_addr:x}"),
                        "opcode_class": name,
                        "context_hex": context_hex,
                    })
                }).collect();
                Ok(json!({
                    "target_addr": format!("0x{target:x}"),
                    "max_hits": max_hits,
                    "hits": entries,
                }))
            },
        ),

        // Find every `.data` position containing a given u32 / u64
        // / arbitrary-byte value. Backed by patternsleuth
        // (`sleuth::scan_data_matches`); no hand-rolled scanning.
        // Use to anchor address resolution on observed live values
        // (e.g. the player's on-screen money) instead of guessing
        // MSVC encodings from decomp output.
        OpDef::new(
            "mem.scan_data",
            "Patternsleuth scan of .data for a u32 (default) or u64 value, \
            or arbitrary bytes. Returns every matching address.",
            "{value: u64, kind?: 'u32'|'u64'|'bytes', bytes?: 'aa bb ..', max_hits?: usize}",
            |args| {
                let kind = args
                    .get("kind")
                    .and_then(Json::as_str)
                    .unwrap_or("u32");
                let sig = match kind {
                    "u32" => {
                        let v = args
                            .get("value")
                            .and_then(Json::as_u64)
                            .ok_or_else(|| "missing or non-u64 arg: value (kind=u32)".to_string())?
                            as u32;
                        v.to_le_bytes()
                            .iter()
                            .map(|b| format!("{b:02x}"))
                            .collect::<Vec<_>>()
                            .join(" ")
                    }
                    "u64" => {
                        let v = args
                            .get("value")
                            .and_then(Json::as_u64)
                            .ok_or_else(|| "missing or non-u64 arg: value (kind=u64)".to_string())?;
                        v.to_le_bytes()
                            .iter()
                            .map(|b| format!("{b:02x}"))
                            .collect::<Vec<_>>()
                            .join(" ")
                    }
                    "bytes" => args
                        .get("bytes")
                        .and_then(Json::as_str)
                        .ok_or_else(|| "missing string arg: bytes (kind=bytes)".to_string())?
                        .to_string(),
                    other => return Err(format!("unknown kind: {other}")),
                };
                let max_hits = args
                    .get("max_hits")
                    .and_then(Json::as_u64)
                    .unwrap_or(64) as usize;
                let mut addrs = modforge::patterns::sleuth::scan_data_matches(&sig)
                    .map_err(|e| format!("sleuth scan_data_matches failed: {e}"))?;
                let total = addrs.len();
                addrs.truncate(max_hits);
                let entries: Vec<Json> = addrs
                    .iter()
                    .map(|a| json!({"addr": format!("0x{a:x}")}))
                    .collect();
                Ok(json!({
                    "sig": sig,
                    "kind": kind,
                    "total_hits": total,
                    "hits": entries,
                }))
            },
        ),

        // Two-address aliasing probe: write a sentinel byte at A,
        // read at B; if they're the same byte the read returns the
        // sentinel. Used by tests to prove a resolved address points
        // at the same byte as the hardcoded one. Restores A's
        // original value before returning, even on early-out.
        OpDef::new(
            "mem.alias_check",
            "Test whether two byte addresses alias the same memory. \
            Writes 0xAB then 0xCD to A, reads B after each, restores.",
            "{addr_a: u64, addr_b: u64}",
            |args| {
                let a = args.get("addr_a").and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: addr_a".to_string())? as usize;
                let b = args.get("addr_b").and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: addr_b".to_string())? as usize;
                if a == 0 || b == 0 {
                    return Err("zero address rejected".to_string());
                }
                // SAFETY: caller-controlled raw addresses. The op is
                // intended only for `.data` byte globals; misuse
                // crashes the host (acceptable for a test-only op).
                let pa = a as *mut u8;
                let pb = b as *const u8;
                let original = unsafe { *pa };
                let probe1 = 0xAB_u8;
                let probe2 = 0xCD_u8;
                unsafe { *pa = probe1; }
                let read1 = unsafe { *pb };
                unsafe { *pa = probe2; }
                let read2 = unsafe { *pb };
                unsafe { *pa = original; }
                let same = read1 == probe1 && read2 == probe2;
                Ok(json!({
                    "addr_a": format!("0x{a:x}"),
                    "addr_b": format!("0x{b:x}"),
                    "same_byte": same,
                    "read1_after_writing_0xab_to_a": read1,
                    "read2_after_writing_0xcd_to_a": read2,
                    "original_value_restored": original,
                }))
            },
        ),

        OpDef::new(
            "targets.resolve.cheat_globals",
            "Resolve NO_TIRE_TOGGLE, DEBUG_MODE_ACTIVE, DEBUG_LOG_GATE at runtime via patternsleuth.",
            "",
            |_| {
                let image_base = crate::targets::image_base();
                fn entry(addr: Option<usize>, fallback_rva: usize) -> Json {
                    let resolved = addr;
                    let addr_hex = match resolved {
                        Some(a) => format!("0x{a:x}"),
                        None => "0x0".to_string(),
                    };
                    let current_byte_value = resolved.map(|a| {
                        // SAFETY: byte read from a mapped .data global.
                        unsafe { *(a as *const u8) }
                    });
                    json!({
                        "address": addr_hex,
                        "hardcoded": format!("0x{:x}", crate::targets::rebase(fallback_rva)),
                        "current_byte_value": current_byte_value,
                    })
                }
                Ok(json!({
                    "image_base": format!("0x{image_base:x}"),
                    "no_tire_toggle": entry(
                        crate::targets::resolve::no_tire_toggle(),
                        crate::targets::NO_TIRE_TOGGLE,
                    ),
                    "debug_mode_active": entry(
                        crate::targets::resolve::debug_mode_active(),
                        crate::targets::DEBUG_MODE_ACTIVE,
                    ),
                    "debug_log_gate": entry(
                        crate::targets::resolve::debug_log_gate(),
                        crate::targets::DEBUG_LOG_GATE,
                    ),
                }))
            },
        ),

        OpDef::new(
            "targets.resolve.gamestate_ptr",
            "Resolve GAMESTATE_PTR at runtime via patternsleuth signatures.",
            "",
            |_| {
                let image_base = crate::targets::image_base();
                let resolved = crate::targets::resolve::gamestate_ptr();
                let address_hex = match resolved {
                    Some(a) => format!("0x{a:x}"),
                    None => "0x0".to_string(),
                };
                // If resolved, also surface the u32 at +0x308 so the
                // test can sanity-check it against on-screen money.
                let money_at_resolved_plus_0x308 = resolved.and_then(|a| {
                    // SAFETY: caller has just resolved this address;
                    // if it's plausible (delta from image_base small),
                    // reading a u32 from `+0x308` is in-bounds for
                    // the embedded GameState struct. read_unaligned
                    // guards against misalignment surprises.
                    let p = (a + 0x308) as *const u32;
                    Some(unsafe { p.read_unaligned() })
                });
                Ok(json!({
                    "address": address_hex,
                    "image_base": format!("0x{image_base:x}"),
                    "hardcoded": format!("0x{:x}", crate::targets::rebase(crate::targets::GAMESTATE_PTR)),
                    "money_at_resolved_plus_0x308": money_at_resolved_plus_0x308,
                }))
            },
        ),

        // ===== Money cheats =====
        OpDef::new(
            "game.money.get",
            "Read current money.",
            "",
            |_| Ok(json!({"money": gamestate::money()})),
        ),
        OpDef::new(
            "game.money.set",
            "Set money to a specific value.",
            "{value: u32}",
            |args| {
                let v = args_u32(args, "value")?;
                let ok = gamestate::set_money(v);
                Ok(json!({"set": ok, "money": gamestate::money()}))
            },
        ),
        OpDef::new(
            "game.money.add",
            "Add to money (negative subtracts; saturates at 0).",
            "{value: i32}",
            |args| {
                let delta = args_i32(args, "value")?;
                let current = gamestate::money().unwrap_or(0) as i64;
                let new_val = (current + delta as i64).max(0).min(u32::MAX as i64) as u32;
                let ok = gamestate::set_money(new_val);
                Ok(json!({"set": ok, "money": gamestate::money()}))
            },
        ),

        // ===== Year =====
        OpDef::new(
            "game.year.get",
            "Read current year (0-indexed; displayed +1 in-game).",
            "",
            |_| Ok(json!({"year": gamestate::year()})),
        ),
        OpDef::new(
            "game.year.set",
            "Set the year.",
            "{value: u32}",
            |args| {
                let v = args_u32(args, "value")?;
                let ok = gamestate::set_year(v);
                Ok(json!({"set": ok, "year": gamestate::year()}))
            },
        ),

        // ===== Cheats =====
        OpDef::new(
            "cheats.no_tire.get",
            "Read the No Tire toggle (true = fatigue disabled).",
            "",
            |_| Ok(json!({"no_tire": gamestate::no_tire()})),
        ),
        OpDef::new(
            "cheats.no_tire.set",
            "Enable / disable the GAME's built-in No Tire cheat. Note: \
this zeroes BOTH tired flags so the sleep gate breaks. Prefer \
fatigue.suppressor.set which only zeroes the race-eligibility flag.",
            "{enabled: bool}",
            |args| {
                let v = args_bool(args, "enabled")?;
                gamestate::set_no_tire(v);
                Ok(json!({"no_tire": gamestate::no_tire()}))
            },
        ),
        OpDef::new(
            "fatigue.suppressor.get",
            "Status of the (deprecated) per-frame Rust-side suppressor.",
            "",
            |_| Ok(json!({"enabled": fatigue::is_enabled()})),
        ),
        OpDef::new(
            "fatigue.suppressor.set",
            "Toggle the (deprecated) per-frame Rust-side suppressor. \
The proper fix is sleep_safe_no_tire (already auto-applied at attach).",
            "{enabled: bool}",
            |args| {
                let v = args_bool(args, "enabled")?;
                fatigue::set_enabled(v);
                Ok(json!({"enabled": fatigue::is_enabled()}))
            },
        ),
        OpDef::new(
            "patches.list",
            "List the binary patches currently applied to Horsey.exe.",
            "",
            |_| Ok(json!({"applied": patches::applied_names()})),
        ),
        OpDef::new(
            "cheats.debug_mode.get",
            "Read the debug-mode-active flag.",
            "",
            |_| Ok(json!({"debug_mode": gamestate::debug_mode()})),
        ),
        OpDef::new(
            "cheats.debug_mode.set",
            "Force debug mode on / off (skips the 'type \"debug\" in pause menu' unlock).",
            "{enabled: bool}",
            |args| {
                let v = args_bool(args, "enabled")?;
                gamestate::set_debug_mode(v);
                Ok(json!({"debug_mode": gamestate::debug_mode()}))
            },
        ),

        // ===== Horse roster =====
        OpDef::new(
            "horses.count",
            "Number of horses in the roster (36-byte records).",
            "",
            |_| Ok(json!({"count": gamestate::horse_count()})),
        ),
        OpDef::new(
            "horses.roster_addr",
            "Memory address of the roster entry at index `i`.",
            "{index: usize}",
            |args| {
                let i = args_usize(args, "index")?;
                let p = gamestate::horse_roster_entry(i);
                Ok(json!({"address": p.map(|a| format!("0x{:x}", a))}))
            },
        ),
        OpDef::new(
            "horses.live",
            "Walk gamestate+0x130/+0x138 and return every live horse with its full state. Powers the roster UI.",
            "",
            |_| {
                let n = gamestate::live_horse_count();
                let mut out = Vec::with_capacity(n);
                for i in 0..n {
                    let Some(h) = gamestate::live_horse_ptr(i) else { continue };
                    if h == 0 { continue; }
                    out.push(json!({
                        "index": i,
                        "address": format!("0x{:x}", h),
                        "age": horse::age(h),
                        "max_age": horse::max_age(h),
                        "skill": horse::skill(h),
                        "tired_a": horse::tired_a(h),
                        "tired_b": horse::tired_b(h),
                        "species": horse::species(h),
                        "name_id": horse::name_id(h),
                        "litter_stat": horse::litter_stat(h),
                    }));
                }
                Ok(json!({
                    "count": n,
                    "horses": out,
                }))
            },
        ),

        // ===== Direct horse-object accessors =====
        // Each takes a horse pointer (hex string) obtained from a hook.
        // For now the only path to get one of these is via a function
        // hook (which we'll add in the next phase). When that lands,
        // these become useful.
        OpDef::new(
            "horse.read",
            "Read all known fields of a horse at given address.",
            "{addr: hex-string}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                Ok(json!({
                    "address": format!("0x{:x}", h),
                    "age": horse::age(h),
                    "max_age": horse::max_age(h),
                    "skill": horse::skill(h),
                    "tired_a": horse::tired_a(h),
                    "tired_b": horse::tired_b(h),
                    "species": horse::species(h),
                    "name_id": horse::name_id(h),
                    "litter_stat": horse::litter_stat(h),
                }))
            },
        ),
        OpDef::new(
            "horse.set_age",
            "Set a horse's age field.",
            "{addr: hex-string, value: i32}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                let v = args_i32(args, "value")?;
                let ok = horse::set_age(h, v);
                Ok(json!({"set": ok, "age": horse::age(h)}))
            },
        ),
        OpDef::new(
            "horse.set_max_age",
            "Set a horse's max-age (lifespan) field.",
            "{addr: hex-string, value: i32}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                let v = args_i32(args, "value")?;
                let ok = horse::set_max_age(h, v);
                Ok(json!({"set": ok, "max_age": horse::max_age(h)}))
            },
        ),
        OpDef::new(
            "horse.clear_tiredness",
            "Zero out the tired flags on a horse.",
            "{addr: hex-string}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                let ok = horse::clear_tiredness(h);
                Ok(json!({"set": ok}))
            },
        ),

        // ===== Extended-gene ops (D0 / D7 infra for the bestiary expansion mod) =====
        // These let us author and inspect extended-gene state via HTTP without
        // touching any vanilla data. Backed by `crate::genes`. See the gene-doubling
        // implementation plan in `horsey-mod/docs/todo.md`.
        OpDef::new(
            "genes.ext.count",
            "Return the configured extended-gene count and total (vanilla + ext).",
            "",
            |_| {
                Ok(json!({
                    "ext_gene_count": EXT_GENE_COUNT,
                    "vanilla_count": 240,
                    "total": 240 + EXT_GENE_COUNT,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.list",
            "List every extended-gene definition (snapshot copy).",
            "",
            |_| Ok(serde_json::to_value(genes::list_ext_genes()).unwrap_or(json!([]))),
        ),
        OpDef::new(
            "genes.ext.get",
            "Read one extended-gene definition by extended-range index (0..EXT_GENE_COUNT).",
            "{ext_idx: usize}",
            |args| {
                let i = args_usize(args, "ext_idx")?;
                match genes::get_ext_gene(i) {
                    Some(g) => Ok(serde_json::to_value(g).unwrap_or(json!(null))),
                    None => Err(format!("ext_idx {i} out of range")),
                }
            },
        ),
        OpDef::new(
            "genes.ext.set",
            "Set one extended-gene definition by extended-range index. \
Args: ext_idx (usize), name (string), mutation_rate (u32), scale (u64), \
alleles ([u32; 4]), optional render { slot, mode: 'add'|'mul'|'set' }.",
            "{ext_idx, name, mutation_rate, scale, alleles, render?}",
            |args| {
                let ext_idx = args_usize(args, "ext_idx")?;
                let name = args_string(args, "name")?;
                let mutation_rate = args_u32(args, "mutation_rate")?;
                let scale = args
                    .get("scale")
                    .and_then(Json::as_u64)
                    .unwrap_or(1);
                let alleles_v = args
                    .get("alleles")
                    .and_then(Json::as_array)
                    .ok_or_else(|| "missing or non-array arg: alleles".to_string())?;
                if alleles_v.len() != 4 {
                    return Err(format!("alleles must be length 4, got {}", alleles_v.len()));
                }
                let mut alleles = [0u32; 4];
                for (i, v) in alleles_v.iter().enumerate() {
                    alleles[i] = v
                        .as_u64()
                        .ok_or_else(|| format!("alleles[{i}] not a u32"))?
                        as u32;
                }
                let render = match args.get("render") {
                    Some(r) if !r.is_null() => {
                        let slot = r
                            .get("slot")
                            .and_then(Json::as_u64)
                            .ok_or_else(|| "render.slot missing".to_string())?
                            as u32;
                        let mode_s = r
                            .get("mode")
                            .and_then(Json::as_str)
                            .ok_or_else(|| "render.mode missing".to_string())?;
                        let mode = match mode_s {
                            "add" => RenderMode::Add,
                            "mul" => RenderMode::Mul,
                            "set" => RenderMode::Set,
                            other => return Err(format!("unknown render mode: {other}")),
                        };
                        Some(RenderMapping { slot, mode })
                    }
                    _ => None,
                };
                let g = ExtGene {
                    name,
                    mutation_rate,
                    scale,
                    alleles,
                    render,
                };
                match genes::set_ext_gene(ext_idx, g) {
                    Some(_) => Ok(json!({"set": true, "ext_idx": ext_idx})),
                    None => Err(format!("ext_idx {ext_idx} out of range")),
                }
            },
        ),
        OpDef::new(
            "genes.ext.find",
            "Look up an extended gene by name. Returns ext_idx + record, or null.",
            "{name: string}",
            |args| {
                let name = args_string(args, "name")?;
                match genes::find_ext_gene_by_name(&name) {
                    Some((i, g)) => Ok(json!({
                        "ext_idx": i,
                        "total_idx": 240 + i,
                        "gene": serde_json::to_value(g).unwrap_or(json!(null)),
                    })),
                    None => Ok(json!(null)),
                }
            },
        ),
        OpDef::new(
            "genes.ext.dump",
            "Full dump of every extended-gene buffer (genes + pop weights + horse-id list). \
Heavy. Use for debugging.",
            "",
            |_| Ok(serde_json::to_value(genes::snapshot()).unwrap_or(json!(null))),
        ),

        // Per-pop extended weights.
        OpDef::new(
            "pop.ext.weights.get",
            "Read a pop's extended-gene weight matrix. Auto-initializes to defaults if unseen.",
            "{pop_id: u32}",
            |args| {
                let pop_id = args_u32(args, "pop_id")?;
                let w = genes::get_or_init_pop_weights(pop_id);
                Ok(serde_json::to_value(w).unwrap_or(json!(null)))
            },
        ),
        OpDef::new(
            "pop.ext.weight.set",
            "Set one allele weight for a pop's extended gene. Inverse weights: lower = more likely.",
            "{pop_id: u32, ext_gene_idx: usize, allele_idx: usize, weight: u32}",
            |args| {
                let pop_id = args_u32(args, "pop_id")?;
                let ext_gene_idx = args_usize(args, "ext_gene_idx")?;
                let allele_idx = args_usize(args, "allele_idx")?;
                let weight = args_u32(args, "weight")?;
                genes::set_pop_ext_weight(pop_id, ext_gene_idx, allele_idx, weight)?;
                Ok(json!({"set": true}))
            },
        ),

        // Per-horse extended genomes.
        OpDef::new(
            "horse.ext.genome.get",
            "Read a horse's extended diploid genome. Returns null if not yet stored.",
            "{horse_id: u64}",
            |args| {
                let horse_id = args
                    .get("horse_id")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: horse_id".to_string())?;
                match genes::get_horse_ext_genome(horse_id) {
                    Some(g) => Ok(serde_json::to_value(g).unwrap_or(json!(null))),
                    None => Ok(json!(null)),
                }
            },
        ),
        OpDef::new(
            "horse.ext.default_alleles.set",
            "Set one diploid allele pair on the DEFAULT extended genome -- the \
fallback every horse without its own entry inherits. Use this to give every \
horse the same extended-gene effect during early bring-up before D3 per-horse \
spawn hooks are wired.",
            "{ext_gene_idx: usize, maternal: u8, paternal: u8}",
            |args| {
                let ext_gene_idx = args_usize(args, "ext_gene_idx")?;
                let maternal = args_u32(args, "maternal")? as u8;
                let paternal = args_u32(args, "paternal")? as u8;
                genes::set_default_ext_alleles(ext_gene_idx, maternal, paternal)?;
                Ok(json!({"set": true}))
            },
        ),
        OpDef::new(
            "horse.ext.default_alleles.get",
            "Read the default extended genome (the fallback every horse inherits). \
Returns null if no default is set.",
            "",
            |_| match genes::get_default_ext_genome() {
                Some(g) => Ok(json!({"alleles": g.alleles})),
                None => Ok(json!(null)),
            },
        ),
        OpDef::new(
            "horse.ext.default_alleles.clear",
            "Clear the default extended genome. Horses with no specific entry \
contribute nothing to render after this.",
            "",
            |_| {
                genes::clear_default_ext_genome();
                Ok(json!({"cleared": true}))
            },
        ),
        OpDef::new(
            "horse.ext.alleles.set",
            "Set one diploid allele pair for one extended gene of one horse. \
Auto-creates the horse's extended genome if not present.",
            "{horse_id: u64, ext_gene_idx: usize, maternal: u8, paternal: u8}",
            |args| {
                let horse_id = args
                    .get("horse_id")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: horse_id".to_string())?;
                let ext_gene_idx = args_usize(args, "ext_gene_idx")?;
                let maternal = args_u32(args, "maternal")? as u8;
                let paternal = args_u32(args, "paternal")? as u8;
                genes::set_horse_ext_alleles(horse_id, ext_gene_idx, maternal, paternal)?;
                Ok(json!({"set": true}))
            },
        ),
        OpDef::new(
            "horse.ext.alleles.get",
            "Read one diploid allele pair for one extended gene of one horse. \
Returns {maternal, paternal} (both in [0..3]). Errors if the horse has no ext \
genome entry.",
            "{horse_id: u64, ext_gene_idx: usize}",
            |args| {
                let horse_id = args
                    .get("horse_id")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: horse_id".to_string())?;
                let ext_gene_idx = args_usize(args, "ext_gene_idx")?;
                match genes::get_horse_ext_alleles(horse_id, ext_gene_idx) {
                    Some((m, p)) => Ok(json!({"maternal": m, "paternal": p})),
                    None => Err(format!(
                        "no ext genome for horse_id 0x{horse_id:x} (or gene {ext_gene_idx} out of range)"
                    )),
                }
            },
        ),
        OpDef::new(
            "horse.ext.genome.set",
            "Set a horse's full extended genome. `alleles` must be length 2*EXT_GENE_COUNT.",
            "{horse_id: u64, alleles: [u8]}",
            |args| {
                let horse_id = args
                    .get("horse_id")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: horse_id".to_string())?;
                let alleles_v = args
                    .get("alleles")
                    .and_then(Json::as_array)
                    .ok_or_else(|| "missing or non-array arg: alleles".to_string())?;
                let want = 2 * EXT_GENE_COUNT;
                if alleles_v.len() != want {
                    return Err(format!("alleles must be length {want}, got {}", alleles_v.len()));
                }
                let mut alleles = Vec::with_capacity(want);
                for (i, v) in alleles_v.iter().enumerate() {
                    alleles.push(
                        v.as_u64()
                            .ok_or_else(|| format!("alleles[{i}] not a u8"))?
                            as u8 & 0x3,
                    );
                }
                genes::set_horse_ext_genome(horse_id, ExtHorseGenome { alleles });
                Ok(json!({"set": true}))
            },
        ),
        OpDef::new(
            "horse.ext.genome.drop",
            "Drop a horse's extended genome (call from D3.2 detour after vanilla free).",
            "{horse_id: u64}",
            |args| {
                let horse_id = args
                    .get("horse_id")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: horse_id".to_string())?;
                let was_present = genes::drop_horse_ext_genome(horse_id);
                Ok(json!({"dropped": was_present}))
            },
        ),
        OpDef::new(
            "horse.ext.evaluate",
            "Evaluate one extended gene's diploid blend for one horse. \
Mirrors FUN_1400a5d20's math against our sidecar buffers.",
            "{horse_id: u64, ext_gene_idx: usize}",
            |args| {
                let horse_id = args
                    .get("horse_id")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing or non-u64 arg: horse_id".to_string())?;
                let ext_gene_idx = args_usize(args, "ext_gene_idx")?;
                let value = genes::evaluate_ext_gene(horse_id, ext_gene_idx);
                Ok(json!({"value": value}))
            },
        ),
        OpDef::new(
            "genes.ext.dryrun",
            "Walk each D1 detour target and return its runtime address + first 16 bytes. \
Read-only; never mutates game memory. Use to verify target addresses look correct \
before calling `genes.ext.arm`.",
            "",
            |_| {
                let reports = patches::ext_genes::dryrun();
                let json_reports: Vec<_> = reports
                    .iter()
                    .map(|r| {
                        json!({
                            "name": r.name,
                            "rva": format!("0x{:x}", r.rva),
                            "runtime_addr": format!("0x{:x}", r.runtime_addr),
                            "prologue_bytes": r.prologue_bytes
                                .iter()
                                .map(|b| format!("{b:02x}"))
                                .collect::<Vec<_>>()
                                .join(" "),
                        })
                    })
                    .collect();
                Ok(json!({
                    "armed": patches::ext_genes::is_armed(),
                    "targets": json_reports,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.arm",
            "Install the DI-A v1 detour set (currently: EVAL_DIPLOID_BLEND_A). \
After this returns OK, every call to FUN_1400a5d20 routes through our handler: \
idx<240 falls through to vanilla via the saved trampoline; idx>=240 returns \
`genes::evaluate_ext_gene` against our sidecar tables. \
Use `genes.ext.dryrun` first to validate addresses, `genes.ext.stats` after to \
confirm the detour is firing.",
            "",
            |_| match patches::ext_genes::arm() {
                Ok(()) => Ok(json!({"armed": true})),
                Err(e) => Err(e.to_string()),
            },
        ),
        OpDef::new(
            "genes.ext.stats",
            "DI-A detour invocation counters across all wired handlers \
(EVAL_DIPLOID_BLEND_A, EVAL_DIPLOID_BLEND_B, GENE_ALLELE_SWAP). \
Use for end-to-end verification: after arming, walk the game; \
`call_count` should climb (detours fire); `ext_call_count` stays at 0 \
until a caller passes idx>=240 (i.e. once the render trampoline drives \
extended evaluations).",
            "",
            |_| {
                let s = patches::ext_genes::stats();
                Ok(json!({
                    "armed": patches::ext_genes::is_armed(),
                    "call_count": s.call_count,
                    "ext_call_count": s.ext_call_count,
                    "max_idx_seen": s.max_idx_seen,
                    "per_target": {
                        "eval_a": {
                            "calls": s.call_count_a,
                            "ext_path": s.ext_count_a,
                            "last_idx": s.last_idx_a,
                        },
                        "eval_b": {
                            "calls": s.call_count_b,
                            "ext_path": s.ext_count_b,
                            "last_idx": s.last_idx_b,
                        },
                        "allele_swap": {
                            "calls": s.call_count_swap,
                            "ext_path": s.ext_count_swap,
                            "last_idx": s.last_idx_swap,
                        },
                    },
                }))
            },
        ),
        OpDef::new(
            "genes.ext.disarm",
            "Revert the DI-A detours. Returns to vanilla behavior for the 3 \
wired functions. No-op if not armed. Also runs automatically on DLL detach.",
            "",
            |_| {
                patches::ext_genes::revert();
                Ok(json!({"armed": patches::ext_genes::is_armed()}))
            },
        ),
        OpDef::new(
            "genes.ext.render.dryrun",
            "Read-only address + prologue dump for the D5 post-hook target \
(APPLY_GENE_TO_HORSE / FUN_14009f680). Use to verify the address is plausible \
before calling `genes.ext.render.arm`.",
            "",
            |_| {
                let r = patches::render_trampoline::dryrun();
                Ok(json!({
                    "armed": patches::render_trampoline::is_armed(),
                    "name": r.name,
                    "rva": format!("0x{:x}", r.rva),
                    "runtime_addr": format!("0x{:x}", r.runtime_addr),
                    "prologue_bytes": r.prologue_bytes
                        .iter()
                        .map(|b| format!("{b:02x}"))
                        .collect::<Vec<_>>()
                        .join(" "),
                }))
            },
        ),
        OpDef::new(
            "genes.ext.render.arm",
            "Install the D5 post-hook on FUN_14009f680. After this returns OK, every \
call to the gene-effect engine runs vanilla first, then our handler walks \
EXT_GENE_TABLE applying render mappings to the buf. Visual extended-gene effects \
become live for every horse with an extended genome.",
            "",
            |_| match patches::render_trampoline::arm() {
                Ok(()) => Ok(json!({"armed": true})),
                Err(e) => Err(e.to_string()),
            },
        ),
        OpDef::new(
            "genes.ext.render.disarm",
            "Revert the D5 post-hook. Visuals return to pure vanilla. No-op if not \
armed. Runs automatically on DLL detach.",
            "",
            |_| {
                patches::render_trampoline::revert();
                Ok(json!({"armed": patches::render_trampoline::is_armed()}))
            },
        ),
        OpDef::new(
            "genes.ext.render.stats",
            "D5 post-hook invocation counters. `call_count` = total invocations of \
FUN_14009f680 since arming; `genes_applied_total` = sum of extended-gene render \
applications across all calls (0 until a horse with an extended genome is \
evaluated).",
            "",
            |_| {
                let s = patches::render_trampoline::stats();
                Ok(json!({
                    "armed": patches::render_trampoline::is_armed(),
                    "call_count": s.call_count,
                    "genes_applied_total": s.genes_applied_total,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.combinator.dryrun",
            "Read-only address + prologue dump for the D3.4 post-hook target \
(GENE_COMBINATOR / FUN_1400a2d80). Use to verify the address is plausible before \
calling `genes.ext.combinator.arm`.",
            "",
            |_| {
                let r = patches::combinator::dryrun();
                Ok(json!({
                    "armed": patches::combinator::is_armed(),
                    "name": r.name,
                    "rva": format!("0x{:x}", r.rva),
                    "runtime_addr": format!("0x{:x}", r.runtime_addr),
                    "prologue_bytes": r.prologue_bytes
                        .iter()
                        .map(|b| format!("{b:02x}"))
                        .collect::<Vec<_>>()
                        .join(" "),
                }))
            },
        ),
        OpDef::new(
            "genes.ext.combinator.arm",
            "Install the D3.4 post-hook on FUN_1400a2d80. After this returns OK, every \
breeding event (child born from two parents) runs vanilla's Mendelian on the inline \
genome at horse+0x2b8, then our handler runs an independent Mendelian on \
EXT_HORSE_GENOMES so the child inherits extended alleles too. Without this, bred \
horses get default-zero ext alleles.",
            "",
            |_| match patches::combinator::arm() {
                Ok(()) => Ok(json!({"armed": true})),
                Err(e) => Err(e.to_string()),
            },
        ),
        OpDef::new(
            "genes.ext.combinator.disarm",
            "Revert the D3.4 post-hook. Bred horses stop inheriting ext alleles. No-op \
if not armed. Runs automatically on DLL detach.",
            "",
            |_| {
                patches::combinator::revert();
                Ok(json!({"armed": patches::combinator::is_armed()}))
            },
        ),
        OpDef::new(
            "genes.ext.combinator.stats",
            "D3.4 combinator post-hook counters. `call_count` = total invocations of \
FUN_1400a2d80 since arming; `combines_done` = ext combinations actually executed \
(equal to call_count once vanilla returns cleanly).",
            "",
            |_| {
                let s = patches::combinator::stats();
                Ok(json!({
                    "armed": patches::combinator::is_armed(),
                    "call_count": s.call_count,
                    "combines_done": s.combines_done,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.lifecycle.dryrun",
            "Read-only address + prologue dump for the D3.1/D3.2 lifecycle anchors \
(HORSE_CONSTRUCTOR / FUN_1400aac60 and HORSE_DESTRUCTOR / FUN_1400bf1f0).",
            "",
            |_| {
                let c = patches::lifecycle::dryrun_ctor();
                let d = patches::lifecycle::dryrun_dtor();
                let fmt = |r: patches::lifecycle::TargetReport| {
                    json!({
                        "name": r.name,
                        "rva": format!("0x{:x}", r.rva),
                        "runtime_addr": format!("0x{:x}", r.runtime_addr),
                        "prologue_bytes": r.prologue_bytes
                            .iter()
                            .map(|b| format!("{b:02x}"))
                            .collect::<Vec<_>>()
                            .join(" "),
                    })
                };
                Ok(json!({
                    "armed_ctor": patches::lifecycle::is_armed_ctor(),
                    "armed_dtor": patches::lifecycle::is_armed_dtor(),
                    "ctor": fmt(c),
                    "dtor": fmt(d),
                }))
            },
        ),
        OpDef::new(
            "genes.ext.lifecycle.arm",
            "Install the D3.1/D3.2 horse-struct lifecycle anchors. After this returns OK, \
every horse creation triggers a default-zero EXT_HORSE_GENOMES entry, and every horse \
destruction drops the entry. Without this, ext entries leak across game sessions and \
new horses won't have ext alleles unless explicitly set.",
            "",
            |_| match patches::lifecycle::arm() {
                Ok(()) => Ok(json!({"armed": true})),
                Err(e) => Err(e.to_string()),
            },
        ),
        OpDef::new(
            "genes.ext.lifecycle.disarm",
            "Revert the D3.1/D3.2 lifecycle anchors. EXT_HORSE_GENOMES no longer mirrors \
horse births/deaths automatically. No-op if not armed. Runs automatically on DLL detach.",
            "",
            |_| {
                patches::lifecycle::revert();
                Ok(json!({
                    "armed_ctor": patches::lifecycle::is_armed_ctor(),
                    "armed_dtor": patches::lifecycle::is_armed_dtor(),
                }))
            },
        ),
        OpDef::new(
            "genes.ext.save.dryrun",
            "Read-only address + prologue dump for the D4 save-sidecar hooks \
(SAVE_WRITER, LOAD_GAME, HORSE_SAVE_WRITER, HORSE_SAVE_LOADER).",
            "",
            |_| {
                let r = patches::save_sidecar::dryrun_all();
                let fmt = |x: &patches::save_sidecar::TargetReport| {
                    json!({
                        "name": x.name,
                        "rva": format!("0x{:x}", x.rva),
                        "runtime_addr": format!("0x{:x}", x.runtime_addr),
                        "prologue_bytes": x.prologue_bytes
                            .iter()
                            .map(|b| format!("{b:02x}"))
                            .collect::<Vec<_>>()
                            .join(" "),
                    })
                };
                Ok(json!({
                    "armed": patches::save_sidecar::is_armed(),
                    "targets": [fmt(&r[0]), fmt(&r[1]), fmt(&r[2]), fmt(&r[3])],
                }))
            },
        ),
        OpDef::new(
            "genes.ext.save.arm",
            "Install the D4 save-sidecar hooks. After this returns OK, saves write \
a `save<N>.dat.ext` sidecar containing dense ext alleles for every horse in roster \
order. Loads consume it before vanilla regenerates render fields, so ext effects \
survive save/load.",
            "",
            |_| match patches::save_sidecar::arm() {
                Ok(()) => Ok(json!({"armed": true})),
                Err(e) => Err(e.to_string()),
            },
        ),
        OpDef::new(
            "genes.ext.save.disarm",
            "Revert the D4 save-sidecar hooks. Future saves/loads ignore ext alleles. \
Existing sidecar files are left in place. No-op if not armed. Runs automatically on \
DLL detach.",
            "",
            |_| {
                patches::save_sidecar::revert();
                Ok(json!({"armed": patches::save_sidecar::is_armed()}))
            },
        ),
        OpDef::new(
            "patterns.scan",
            "Scan the loaded Horsey.exe .text section for an IDA-style byte pattern. \
Returns the runtime address of the first match (or null if no match). Used by \
test harness + future R1/R2 address-resolution code. Body: {sig: string}, where \
sig is e.g. \"48 89 5c 24 ?? 57 48 83 ec\". Read-only.",
            "{sig: string}",
            |args| {
                let sig = args.get("sig").and_then(Json::as_str).unwrap_or("");
                if sig.is_empty() {
                    return Err("missing or empty sig".into());
                }
                let found = modforge::patterns::scan_loaded_image(sig);
                Ok(json!({
                    "sig": sig,
                    "found": found.map(|a| format!("0x{a:x}")),
                }))
            },
        ),
        OpDef::new(
            "game.build_info",
            "Return identification for the loaded Horsey.exe build: SHA-256 of the \
.text section, image base, text size, and (when available) the on-disk \
mtime + size of the .exe file. Stable per-build; changes only when Steam ships a new \
binary. Used by tests + bug reports to pin which build was tested.",
            "",
            |_| {
                use crate::targets;
                let sha = targets::image_text_sha256();
                let base = targets::image_base();
                let text_size = targets::find_text_section_size().unwrap_or(0);
                let file_info = targets::image_file_info();
                let mut out = json!({
                    "image_sha256": sha,
                    "image_base": format!("0x{base:x}"),
                    "text_size": text_size,
                });
                if let Some((path, mtime, size)) = file_info {
                    let mtime_secs = mtime
                        .duration_since(std::time::SystemTime::UNIX_EPOCH)
                        .map(|d| d.as_secs())
                        .unwrap_or(0);
                    out.as_object_mut().unwrap().insert(
                        "exe_path".into(),
                        json!(path.display().to_string()),
                    );
                    out.as_object_mut()
                        .unwrap()
                        .insert("exe_mtime_unix".into(), json!(mtime_secs));
                    out.as_object_mut()
                        .unwrap()
                        .insert("exe_size".into(), json!(size));
                }
                Ok(out)
            },
        ),
        OpDef::new(
            "patterns.sleuth.resolve",
            "Multi-target patternsleuth resolver. Body: \
{patterns: [{name, sigs:[...]}, ...]}. Each target supplies one or more IDA-style \
signatures; first match wins per target. Returns {results: {name: \"0x...\" | null}}. \
Used by horsey-mod tests + future R2 attach-time address resolution.",
            "{patterns: [{name: string, sigs: [string]}]}",
            |args| {
                use modforge::patterns::sleuth;
                let arr = args
                    .get("patterns")
                    .and_then(Json::as_array)
                    .ok_or_else(|| "missing patterns array".to_string())?;

                // Collect owned strings first so the borrows live long
                // enough; build Target<'a> views over them.
                let mut owned: Vec<(String, Vec<String>)> =
                    Vec::with_capacity(arr.len());
                for entry in arr {
                    let name = entry
                        .get("name")
                        .and_then(Json::as_str)
                        .ok_or_else(|| "pattern entry missing `name`".to_string())?
                        .to_string();
                    let sigs = entry
                        .get("sigs")
                        .and_then(Json::as_array)
                        .ok_or_else(|| {
                            format!("pattern {name:?} missing `sigs` array")
                        })?;
                    let sig_strs: Vec<String> = sigs
                        .iter()
                        .filter_map(|v| v.as_str().map(str::to_string))
                        .collect();
                    if sig_strs.is_empty() {
                        return Err(format!("pattern {name:?} has no sigs"));
                    }
                    owned.push((name, sig_strs));
                }

                // Borrow into Target<'a>.
                let sigs_refs: Vec<Vec<&str>> = owned
                    .iter()
                    .map(|(_, sigs)| sigs.iter().map(String::as_str).collect())
                    .collect();
                let targets: Vec<sleuth::Target> = owned
                    .iter()
                    .zip(sigs_refs.iter())
                    .map(|((n, _), s)| sleuth::Target { name: n, sigs: s })
                    .collect();

                let resolution = sleuth::resolve_all(&targets)
                    .map_err(|e| e.to_string())?;

                // Emit as {name: "0x..."} or null.
                let mut results = serde_json::Map::new();
                for (name, _) in &owned {
                    let v = match resolution.get(name) {
                        Some(addr) => Json::String(format!("0x{addr:x}")),
                        None => Json::Null,
                    };
                    results.insert(name.clone(), v);
                }
                Ok(json!({ "results": Json::Object(results) }))
            },
        ),
        OpDef::new(
            "patterns.read_bytes",
            "Read `n` bytes at a runtime address inside the loaded Horsey.exe image, \
return as a hex-byte string suitable for direct use as a `patterns.scan` sig. Used \
to derive test signatures from known-good function entries. Body: \
{addr: \"0x...\", n: u32}.",
            "{addr: string, n: u32}",
            |args| {
                let addr_str =
                    args.get("addr").and_then(Json::as_str).unwrap_or("");
                let n = args.get("n").and_then(Json::as_u64).unwrap_or(16) as usize;
                let addr_str = addr_str.trim_start_matches("0x");
                let addr = usize::from_str_radix(addr_str, 16)
                    .map_err(|e| format!("bad addr: {e}"))?;
                if n == 0 || n > 4096 {
                    return Err(format!("n out of range: {n}"));
                }
                // SAFETY: caller asserts the address is inside the
                // loaded image. We don't validate further; pattern
                // search downstream will catch garbage.
                let view = unsafe {
                    std::slice::from_raw_parts(addr as *const u8, n)
                };
                let hex: String = view
                    .iter()
                    .map(|b| format!("{:02x}", b))
                    .collect::<Vec<_>>()
                    .join(" ");
                Ok(json!({ "addr": format!("0x{addr:x}"), "n": n, "bytes": hex }))
            },
        ),
        OpDef::new(
            "genes.ext.save.stats",
            "D4 save-sidecar counters. `save_calls`/`load_calls` = top-level save/load \
invocations; `horse_writes`/`horse_reads` = per-horse records appended/consumed; \
`files_written`/`files_read` = sidecar files successfully written/read.",
            "",
            |_| {
                let s = patches::save_sidecar::stats();
                Ok(json!({
                    "armed": patches::save_sidecar::is_armed(),
                    "save_calls": s.save_calls,
                    "load_calls": s.load_calls,
                    "horse_writes": s.horse_writes,
                    "horse_reads": s.horse_reads,
                    "files_written": s.files_written,
                    "files_read": s.files_read,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.save.write_now",
            "Directly write the BXSAVEXT sidecar for the given channel, bypassing the \
detour. Walks current EXT_HORSE_GENOMES + writes the file at sidecar_path(channel). \
Used by the end-to-end save/restart/reload test to skip the vanilla save trigger \
while still proving cross-launch persistence of the codec. Body: {channel: u32}.",
            "{channel: u32}",
            |args| {
                use std::io::Write as _;
                let channel = args
                    .get("channel")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing channel".to_string())? as u32;
                let path = patches::save_sidecar::sidecar_path(channel);
                if let Some(parent) = path.parent() {
                    let _ = std::fs::create_dir_all(parent);
                }
                let genomes: Vec<(u64, genes::ExtHorseGenome)> = {
                    let ids = genes::list_horse_genome_ids();
                    ids.into_iter()
                        .filter_map(|id| {
                            genes::get_horse_ext_genome(id).map(|g| (id, g))
                        })
                        .collect()
                };
                let mut f = std::fs::File::create(&path)
                    .map_err(|e| format!("create {}: {e}", path.display()))?;
                patches::save_sidecar::write_header(
                    &mut f,
                    genes::EXT_GENE_COUNT as u32,
                    genomes.len() as u32,
                )
                .map_err(|e| format!("write_header: {e}"))?;
                for (_id, g) in &genomes {
                    patches::save_sidecar::write_horse_record(&mut f, g)
                        .map_err(|e| format!("write_horse_record: {e}"))?;
                }
                f.flush().map_err(|e| format!("flush: {e}"))?;
                Ok(json!({
                    "path": path.display().to_string(),
                    "horses": genomes.len(),
                }))
            },
        ),
        OpDef::new(
            "genes.ext.save.read_now",
            "Directly read the BXSAVEXT sidecar for the given channel into \
EXT_HORSE_GENOMES (clears existing entries first). Mirror of write_now. Body: \
{channel: u32}. Returns {path, horses} on success.",
            "{channel: u32}",
            |args| {
                let channel = args
                    .get("channel")
                    .and_then(Json::as_u64)
                    .ok_or_else(|| "missing channel".to_string())? as u32;
                let path = patches::save_sidecar::sidecar_path(channel);
                if !path.exists() {
                    return Err(format!("sidecar missing: {}", path.display()));
                }
                let mut f = std::fs::File::open(&path)
                    .map_err(|e| format!("open {}: {e}", path.display()))?;
                let hdr = patches::save_sidecar::read_header(&mut f)
                    .map_err(|e| format!("read_header: {e}"))?;
                for i in 0..hdr.horse_count {
                    // Drop any existing entry at this index so the
                    // sidecar's values are authoritative.
                    let _ = genes::drop_horse_ext_genome(i as u64);
                }
                for i in 0..hdr.horse_count {
                    let g = patches::save_sidecar::read_horse_record(&mut f)
                        .map_err(|e| format!("read_horse_record {i}: {e}"))?;
                    // Key by sequential index; the real path keys by horse pointer
                    // through the detour. For the e2e test we use index keys so
                    // assertions stay self-consistent across launches.
                    genes::set_horse_ext_genome(i as u64, g);
                }
                Ok(json!({
                    "path": path.display().to_string(),
                    "horses": hdr.horse_count,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.lifecycle.stats",
            "D3.1/D3.2 lifecycle anchor counters. `ctor_calls`/`dtor_calls` = total \
invocations of FUN_1400aac60/FUN_1400bf1f0; `entries_created`/`entries_dropped` = \
new vs removed EXT_HORSE_GENOMES entries.",
            "",
            |_| {
                let s = patches::lifecycle::stats();
                Ok(json!({
                    "armed_ctor": patches::lifecycle::is_armed_ctor(),
                    "armed_dtor": patches::lifecycle::is_armed_dtor(),
                    "ctor_calls": s.ctor_calls,
                    "dtor_calls": s.dtor_calls,
                    "entries_created": s.entries_created,
                    "entries_dropped": s.entries_dropped,
                }))
            },
        ),
        OpDef::new(
            "genes.ext.reload",
            "Re-parse `genes-extended.xml` from disk and replace EXT_GENE_TABLE entries. \
Default path: <DLL_DIR>/genes-extended.xml. Pass `path` to override.",
            "{path?: string}",
            |args| {
                let path: std::path::PathBuf = match args.get("path").and_then(Json::as_str) {
                    Some(p) => std::path::PathBuf::from(p),
                    None => modforge::log::dll_dir_wait(std::time::Duration::from_secs(1))
                        .unwrap_or_else(|| std::path::PathBuf::from("."))
                        .join("genes-extended.xml"),
                };
                if !path.exists() {
                    return Err(format!("file not found: {}", path.display()));
                }
                match genes_xml::load_from_file(&path) {
                    Ok(stats) => Ok(json!({
                        "path": path.display().to_string(),
                        "parsed": stats.parsed,
                        "placed": stats.placed,
                        "skipped_oor": stats.skipped_oor,
                        "skipped_conflict": stats.skipped_conflict,
                        "render_mappings": stats.render_mappings,
                        "errors": stats.errors,
                    })),
                    Err(e) => Err(e),
                }
            },
        ),

        // ===== Native ImGui window (Phase A) =====
        //
        // Opens a standalone top-level Win32 + D3D11 + ImGui window
        // inside the injected DLL. Independent of any host engine;
        // sits beside Horsey.exe's window and is alt-tabbable.
        OpDef::new(
            "ui.native.spawn",
            "Spawn the standalone ImGui window. Idempotent.",
            "{window_title?: str}",
            |args| {
                let title = args.get("window_title")
                    .and_then(|v| v.as_str())
                    .unwrap_or("horsey-mod");
                let armed = modforge::ui::native::spawn(title);
                Ok(json!({"armed": armed}))
            },
        ),
        OpDef::new(
            "ui.native.shutdown",
            "Close the standalone ImGui window + join the render thread.",
            "",
            |_| {
                modforge::ui::native::shutdown();
                Ok(json!({"armed": modforge::ui::native::is_visible()}))
            },
        ),
        OpDef::new(
            "ui.native.is_visible",
            "True if the standalone ImGui window currently exists.",
            "",
            |_| Ok(json!({"visible": modforge::ui::native::is_visible()})),
        ),
        OpDef::new(
            "ui.native.stats",
            "Render-loop stats (frame count, visibility).",
            "",
            |_| Ok(json!({
                "visible": modforge::ui::native::is_visible(),
                "frames": modforge::ui::native::frame_count(),
            })),
        ),
    ]);
    modforge::log!("horsey-mod: registered ops");
}

// =============================================================================
// Argument helpers (mirroring modforge::args style)
// =============================================================================

fn args_u32(args: &Json, key: &str) -> Result<u32, String> {
    args.get(key)
        .and_then(Json::as_u64)
        .map(|v| v as u32)
        .ok_or_else(|| format!("missing or non-u32 arg: {key}"))
}

fn args_i32(args: &Json, key: &str) -> Result<i32, String> {
    args.get(key)
        .and_then(Json::as_i64)
        .map(|v| v as i32)
        .ok_or_else(|| format!("missing or non-i32 arg: {key}"))
}

fn args_usize(args: &Json, key: &str) -> Result<usize, String> {
    args.get(key)
        .and_then(Json::as_u64)
        .map(|v| v as usize)
        .ok_or_else(|| format!("missing or non-usize arg: {key}"))
}

fn args_bool(args: &Json, key: &str) -> Result<bool, String> {
    args.get(key)
        .and_then(Json::as_bool)
        .ok_or_else(|| format!("missing or non-bool arg: {key}"))
}

fn args_string(args: &Json, key: &str) -> Result<String, String> {
    args.get(key)
        .and_then(Json::as_str)
        .map(|s| s.to_string())
        .ok_or_else(|| format!("missing or non-string arg: {key}"))
}

fn args_hex_addr(args: &Json, key: &str) -> Result<usize, String> {
    let s = args
        .get(key)
        .and_then(Json::as_str)
        .ok_or_else(|| format!("missing or non-string arg: {key}"))?;
    let s = s.strip_prefix("0x").unwrap_or(s);
    usize::from_str_radix(s, 16).map_err(|e| format!("bad hex addr in {key}: {e}"))
}

// `scan_xrefs` removed in favour of patternsleuth-backed
// `modforge::patterns::sleuth::scan_all_matches` with an `X<target>`
// pattern. See horsey-mod/docs/todo.md "P0 RULE: USE PATTERNSLEUTH"
// and global CLAUDE.md.
