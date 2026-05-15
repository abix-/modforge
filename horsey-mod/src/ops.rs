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
                    "world_loaded": gamestate::ptr() != 0,
                    "no_tire": gamestate::no_tire(),
                    "debug_mode": gamestate::debug_mode(),
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
