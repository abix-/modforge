//! Hardcoded function addresses + global addresses from Horsey.exe.
//!
//! Source: our 100% decompilation pass (build mtime 2026-05-08).
//! When the game updates, these will shift; the recovery path is
//! pattern-scan via `modforge::scanner` and re-derive the offset
//! table. For now we treat the May 2026 build as the reference.
//!
//! All addresses are PE relative-virtual offsets. To compute the
//! actual runtime address: `image_base + RVA`. The `image_base` is
//! resolved at process start via `GetModuleHandleW(NULL)`.

/// PE preferred image base. The game ships without ASLR randomization
/// in most launches, so this is also typically the runtime base.
/// `image_base()` below resolves the actual one.
pub const PREFERRED_IMAGE_BASE: usize = 0x140000000;

// =============================================================================
// Global game state pointers
// =============================================================================

/// Pointer to the global game-state struct.
///
/// Verified from `compute_save_path` callers and the cheat-money
/// handler at line 60473 of `decompiled/all_functions.c`:
///   `*(int *)(DAT_1403fb0d8 + 0x308) += 1000;`
pub const GAMESTATE_PTR: usize = 0x1403fb0d8;

/// Pointer to the loaded save format VERSION. Set by `load_game`
/// after reading the first uint32 of the save file.
/// Conditional reads in the save loader gate on `version > 11`.
pub const SAVE_VERSION_GLOBAL: usize = 0x1403fb0e0;

/// The Races counter. NOT inside GameState; a separate global.
/// Confirmed at line 84920 (`DAT_1403eded8 = 0;`).
pub const RACES_COUNTER: usize = 0x1403eded8;

/// The "No Tire" / "Yes Tire" toggle byte. When non-zero, the
/// per-frame update loop zeroes horse.+0x205 / +0x206 on every
/// horse, effectively disabling tiredness.
/// Toggled from the debug cheat menu (line 60442).
pub const NO_TIRE_TOGGLE: usize = 0x1403d95c5;

/// Debug-mode-active flag. Set when the player types "debug" in
/// the pause menu. Gates the cheat-menu buttons + extended status
/// line.
pub const DEBUG_MODE_ACTIVE: usize = 0x1403d959b;

/// Debug-mode log gate. When set, retirement messages,
/// `%s = (%d rand + ...)` price formulas, and other debug lines
/// print to the log. Independent of `DEBUG_MODE_ACTIVE`.
pub const DEBUG_LOG_GATE: usize = 0x1403d9526;

// =============================================================================
// GameState struct field offsets (from DAT_1403fb0d8)
// =============================================================================

pub mod gs_offset {
    pub const FRAME_TICK: usize = 0x254;
    pub const FIELD_268: usize = 0x268;
    pub const MONEY: usize = 0x308;
    pub const YEAR: usize = 0x314;
    pub const SLEEPS: usize = 0x318;
    /// Start of the 6-supply array. Each supply is 8 bytes:
    /// `[uint32 count][uint8 flag_a][uint8 flag_b][2 bytes pad]`.
    /// The 7th supply field (used by the Loaded cheat) at +0x344 is
    /// in the same stride; the writer/loader walks 6 then handles
    /// the 7th separately.
    pub const SUPPLIES_START: usize = 0x31c;
    pub const FIELD_37C: usize = 0x37c;
    pub const FIELD_39C: usize = 0x39c;
    pub const FIELD_410: usize = 0x410;
    pub const FIELD_414: usize = 0x414;
    pub const FIELD_415: usize = 0x415;
    pub const FIELD_418: usize = 0x418;
    pub const FIELD_41C: usize = 0x41c;
    pub const FIELD_440: usize = 0x440;
    /// Begin pointer for the horse vector (stride 0x24 = 36 bytes
    /// per in-memory horse).
    pub const HORSES_BEGIN: usize = 0x280;
    /// End pointer for the horse vector. `(end - begin) / 0x24` =
    /// horse count.
    pub const HORSES_END: usize = 0x288;
    pub const TRAILING_278: usize = 0x278;
    pub const TRAILING_27C: usize = 0x27c;
}

// =============================================================================
// Horse struct field offsets
// =============================================================================
//
// Note: "horse pointer" in different parts of the engine references
// different concrete types. The track manager iterates one list
// (`+0x130/+0x138`); the BarnMating handler accesses parents via
// `param_1[0x88]` and `param_1[0x89]`. We use the same field
// offsets in both. The struct is the same; the wrapping containers
// differ.

pub mod horse_offset {
    /// Horse type/species code. Compared to 2/3/4/6 in various
    /// dispatchers.
    pub const TYPE_OR_SPECIES: usize = 0x1c;
    /// Horse name ID (passed to `name_resolve` / FUN_1400c78c0).
    pub const NAME_ID: usize = 0x1f8;
    /// Horse age (years; int32).
    pub const AGE: usize = 0x1fc;
    /// Max age / lifespan threshold (int32). Compared as
    /// `age < max_age - 1` in the release-to-wild branch.
    pub const MAX_AGE: usize = 0x200;
    /// "On track / unavailable" flag (uint8). When 0, price doubles.
    pub const ON_TRACK_FLAG: usize = 0x204;
    /// Tiredness flag A (uint8). Zeroed every frame by Yes Tire.
    pub const TIRED_FLAG_A: usize = 0x205;
    /// Tiredness flag B (uint8). Zeroed every frame by Yes Tire.
    pub const TIRED_FLAG_B: usize = 0x206;
    /// Breeding flag (uint8). Set on both parents during BarnMating.
    pub const BREEDING_FLAG: usize = 0x207;
    /// Skill / fitness counter (int32). Used by retirement.
    pub const SKILL: usize = 0x21c;
    /// Litter-size stat (int32). Used in breeding: children =
    /// min(parent_a.litter, parent_b.litter) + rng_bonus.
    pub const LITTER_SIZE_STAT: usize = 0x254;
}

// =============================================================================
// Game function addresses (for MinHook trampoline targets)
// =============================================================================

// CRITICAL CORRECTION (2026-05-14):
//
// Ghidra's pyghidra decomp pass indexes function entries OFF-BY-16
// for the MSVC-compiled Horsey.exe. Every address in the pyghidra
// `INDEX.md` points 16 bytes INTO the function body, past the
// register-save prologue. The true entry is at `ghidra_addr - 16`.
//
// Why this matters: if we hook at Ghidra's address, retour's
// trampoline copies bytes that depend on register values set up by
// the SKIPPED prologue (specifically `mov rax, rsp; push rbp; ...`
// for big functions). When our handler runs between caller-CALL and
// trampoline-execution, it clobbers RAX (volatile in Win64 ABI),
// and the trampoline's relocated `lea rbp, [rax-X]` reads garbage.
//
// Most functions Ghidra indexed in this build have one of these
// shapes 16 bytes BEFORE their indexed entry:
//   - `48 8b c4 55 53 56 57 41 54 41 55 41 56 41 57`
//     = `mov rax, rsp; push rbp; push rbx; ... push r15`
//   - `48 89 5c 24 08 48 89 6c 24 10 48 89 74 24 18 57`
//     = shadow-space saves of rbx/rbp/rsi + push rdi
//
// All addresses below have been adjusted to the TRUE entry. The
// original Ghidra address is in a comment for cross-reference
// with `horsey-mod/research/decompiled/INDEX.md`.

pub mod fn_addr {
    /// `apply_gene_to_horse`. The gene expression function. The
    /// entry point for "construct a horse from its genome". Hook
    /// here to attach extension state to new horses.
    /// Ghidra indexed as `FUN_14009f680`; true entry -16 bytes.
    pub const APPLY_GENE_TO_HORSE: usize = 0x14009f670;

    /// `eval_diploid_blend_a`. One of two allele-blend evaluators.
    /// Takes `(horse_genome*, gene_idx: i32)` and returns a blended
    /// `f32`. Called by `APPLY_GENE_TO_HORSE` 233 times per horse
    /// with literal indices 0..239. D1 trampoline target:
    /// dispatch to `EXT_GENE_TABLE` when `gene_idx >= 240`.
    /// Ghidra indexed as `FUN_1400a5d20`; true entry -16 bytes.
    pub const EVAL_DIPLOID_BLEND_A: usize = 0x1400a5d10;

    /// `eval_diploid_blend_b`. Sibling evaluator using the same
    /// record layout but a different blend formula. Same trampoline
    /// strategy as the A variant.
    /// Ghidra indexed as `FUN_1400a5e00`; true entry -16 bytes.
    pub const EVAL_DIPLOID_BLEND_B: usize = 0x1400a5df0;

    /// `gene_table_consumer_or_horse_dies`. The "horse death"
    /// handler that ALSO mutates gene-table mutation rates by +/-5.
    /// D1 trampoline target: when its mutation targets
    /// `gene_idx >= 240`, redirect to `EXT_GENE_TABLE`.
    /// Ghidra indexed as `FUN_1400c0660`; true entry -16 bytes.
    pub const GENE_DEATH_DRIFT: usize = 0x1400c0650;

    /// `gene_allele_renumber_sync`. When alleles X and Y of a gene
    /// are swapped, this function syncs the swap across every pop
    /// record. D1 trampoline target: when called with
    /// `gene_idx >= 240`, swap inside `EXT_POP_WEIGHTS` and
    /// `EXT_GENE_TABLE` instead.
    /// Ghidra indexed as `FUN_1400c03a0`; true entry -16 bytes.
    pub const GENE_ALLELE_SWAP: usize = 0x1400c0390;

    /// `gene_table_xml_writer` (`FUN_1400a4880`). Serializes the
    /// 240-slot gene table back to XML. Vanilla iterates 0..239.
    /// D1 trampoline target (optional): also dump
    /// `EXT_GENE_TABLE` to a sidecar XML.
    pub const GENE_TABLE_XML_WRITER: usize = 0x1400a4880;

    /// `gene_table_loader` (`FUN_1400a3eb0`). Loads `genes.xml`
    /// into the 240-slot table at startup. Not patched in v1; we
    /// run our own loader for `genes-extended.xml` from
    /// `worker_main`.
    pub const GENE_TABLE_LOADER: usize = 0x1400a3eb0;

    /// `pop_xml_loader` (`FUN_1400a4fe0`). Loads `pop.xml`
    /// populations. Not patched in v1; pop authoring stays vanilla
    /// and our extended pop weights are stored in `EXT_POP_WEIGHTS`.
    pub const POP_XML_LOADER: usize = 0x1400a4fe0;

    /// `gene_engine_consumer`. Called immediately after
    /// `APPLY_GENE_TO_HORSE` to transcribe the temp render param
    /// array into the persistent horse render struct. The D5
    /// trampoline lives at the boundary between APPLY_GENE_TO_HORSE
    /// and this function.
    /// Ghidra indexed as `FUN_1400ab3d0`; true entry -16 bytes.
    pub const GENE_ENGINE_CONSUMER: usize = 0x1400ab3c0;

    /// `check_horse_eligibility`. The "Horse is too tired/old/young/hungry"
    /// dispatcher. Hook to override eligibility decisions.
    pub const CHECK_HORSE_ELIGIBILITY: usize = 0x1400dde40;

    /// `retire_horse_handler`. Fitness-based retirement scanner,
    /// runs at most once per game year.
    pub const RETIRE_HORSE_HANDLER: usize = 0x1400df280;

    /// `compute_horse_price`. The `(rand+nice+record)*years+deco`
    /// formula. Hook to customize horse pricing.
    pub const COMPUTE_HORSE_PRICE: usize = 0x1400dcab0;

    /// `crispr_lab_state_machine`. The 13-state CRISPR handler.
    pub const CRISPR_LAB: usize = 0x140089510;

    /// `breeding_state_machine`. The BarnMating state machine.
    pub const BREEDING: usize = 0x1400e0aa0;

    /// `save_game_writer`. Top-level save driver.
    /// True entry RVA derived 2026-05-15 via pattern-scan probe
    /// (`tests/r2_save_find_entries.rs`); the original Ghidra RVA
    /// `0x14006dc80` was -1548 bytes inside the function body.
    /// Prologue: `57 41 56 48 81 ec 40 01 00 00 48 8b e9 48 8d 51`
    /// (push rdi; push r14; sub rsp,0x140; mov rbp,rcx; lea rdx,...).
    /// Verified by `tests/r2_save_signatures.rs`.
    pub const SAVE_WRITER: usize = 0x14006d674;

    /// `load_game`. Top-level save loader.
    /// Same correction as `SAVE_WRITER`: original Ghidra RVA
    /// `0x14006e480` was -304 bytes inside the body. True entry
    /// prologue: `48 89 5c 24 08 55 56 57 41 54 41 55 41 56 41 57
    /// 48 8b ec 48 83 ec 70` (shadow-save rbx + push 7 regs +
    /// mov rbp,rsp + sub rsp,0x70). Verified by
    /// `tests/r2_save_signatures.rs`.
    pub const LOAD_GAME: usize = 0x14006e350;

    /// `draw_pause_status`. Pause-menu renderer + debug-mode unlock.
    pub const DRAW_PAUSE_STATUS: usize = 0x140066200;

    /// `tmx_map_parser`. The .tmx loader.
    pub const TMX_MAP_PARSER: usize = 0x1400fe2e0;

    /// `pop_genome_builder`. Pop.xml runtime spawner.
    pub const POP_GENOME_BUILDER: usize = 0x140092820;

    /// `daily_horse_event_emitter`. Per-day per-horse event log.
    pub const DAILY_HORSE_EVENT: usize = 0x14002fe00;

    /// `track_state_machine`. Race lifecycle.
    pub const TRACK_STATE_MACHINE: usize = 0x14002d7c0;

    /// `circus_event_handler`.
    pub const CIRCUS_HANDLER: usize = 0x140039190;

    /// `sumo_match_handler`.
    pub const SUMO_HANDLER: usize = 0x14007b2e0;

    /// `power_plant_handler`.
    pub const POWER_PLANT: usize = 0x1400693b0;

    /// `world_action_dispatcher`.
    pub const WORLD_ACTION: usize = 0x140107660;

    /// `hot_air_balloon_controller`.
    pub const BALLOON_CONTROLLER: usize = 0x14010a5e0;

    // -------------------------------------------------------------
    // D3/D4 lifecycle + breeding + per-horse save targets
    // (research closed 2026-05-15; see todo.md D3.0/D3.4/D4.1b/D4.2b)
    // -------------------------------------------------------------

    /// Horse struct constructor. Caller passes a freshly allocated
    /// 0x498-byte buffer (`FUN_1402c704c(0x498)`); the constructor
    /// installs the vtable `&PTR_FUN_14030d660`, zeros 50+ fields,
    /// sets default `max_age = 0x1e` at +0x44, increments the global
    /// live-count `_DAT_1403f311c`, and returns the same pointer.
    /// Single entry point for ALL horse-creation paths (40+ call
    /// sites). D3.1 lifecycle anchor for `EXT_HORSE_GENOMES`.
    /// Ghidra indexed as `FUN_1400aac60`; true entry -16 bytes.
    pub const HORSE_CONSTRUCTOR: usize = 0x1400aac50;

    /// Horse struct destructor. Resets vtable, decrements
    /// `_DAT_1403f311c`, releases sub-objects (`+0x3e` sub-struct,
    /// std::string SSO buffers at +0x51/+0x31/+0x2d), then frees
    /// the 0x498 buffer if `param_2 & 1` (C++ delete flag).
    /// Mirror partner of `HORSE_CONSTRUCTOR`. D3.2 lifecycle anchor.
    /// Ghidra indexed as `FUN_1400bf1f0`; true entry -16 bytes.
    pub const HORSE_DESTRUCTOR: usize = 0x1400bf1e0;

    /// Breeding combinator. Mendelian recombination of two parents'
    /// 0x1e0-byte inline genomes (at `horse + 0x2b8`) into a child's
    /// inline genome. Signature:
    /// `(parent_a + 0x2b8, parent_b + 0x2b8, child + 0x2b8)`.
    /// Body: outer loop 2 strands x inner loop 240 genes, per
    /// (strand, gene) calls `FUN_1400c6580()` for an RNG coinflip
    /// selecting one parent's strand to copy from. Plus linked-
    /// inheritance bitmask forcing same-parent across 3 ranges:
    /// 72..86 (Neck), 97..174 (Head/etc.), 183..197 (palette base).
    /// D3.4 detour target. Post-hook recovers horse base ptrs as
    /// `param_N - 0x2b8` and runs own Mendelian on `EXT_HORSE_GENOMES`.
    /// Ghidra indexed as `FUN_1400a2d80`; true entry -16 bytes.
    pub const GENE_COMBINATOR: usize = 0x1400a2d70;

    /// Per-horse save serializer. Called per pointer from the roster
    /// iterator (`FUN_14006d610`). Writes the inline genome at
    /// `horse + 0x2b8` via `FUN_14006d470`, then ~12 other small
    /// fields (name_id, age, flags, etc.). D4.1b sidecar-write
    /// anchor: post-hook appends our ext alleles for the same horse
    /// in the same iteration order.
    /// True entry RVA derived 2026-05-15 via probe; the original
    /// Ghidra RVA `0x14006ee10` was -277 bytes inside the body.
    /// Prologue: `57 41 56 48 83 ec 40 48 8b e9 e8 .. .. .. .. 48`
    /// (push rdi; push r14; sub rsp,0x40; mov rbp,rcx; call rel32).
    /// Verified by `tests/r2_save_signatures.rs`.
    pub const HORSE_SAVE_WRITER: usize = 0x14006ecfb;

    /// Per-horse save loader. Mirror of `HORSE_SAVE_WRITER`. Reads
    /// the inline genome via `FUN_14006d580(horse + 0x2b8)`, then
    /// the small fields, then calls `FUN_1400b3070(horse)` at line
    /// :65182 to regenerate render fields by re-running the engine
    /// + consumer. Our D1/D5 detours fire during that regen, so any
    /// ext alleles in `EXT_HORSE_GENOMES` populated BEFORE this
    /// returns get applied automatically. D4.2b sidecar-read anchor.
    /// True entry RVA derived 2026-05-15 via probe; the original
    /// Ghidra RVA `0x14006f150` was -287 bytes inside the body.
    /// Prologue: `53 57 48 83 ec 58 48 8b f9 48 81 c1 b8 02 00 00`
    /// (push rbx; push rdi; sub rsp,0x58; mov rdi,rcx; add rcx,0x2b8).
    /// The `add rcx, 0x2b8` is the genome-offset reference and the
    /// most distinctive signature byte sequence. Verified by
    /// `tests/r2_save_signatures.rs`.
    pub const HORSE_SAVE_LOADER: usize = 0x14006f031;
}

/// Resolve the running process's image base. Safe to call from any
/// thread after process init.
/// R3: pattern-scan resolution of data globals whose hardcoded RVAs
/// can drift between Horsey.exe builds.
///
/// Same primitive R1/R2 use for function entries: hand a few
/// candidate signatures to `modforge::patterns::sleuth`, take the
/// first that matches, then decode the RIP-relative displacement
/// inside the matched instruction to recover the data address.
pub mod resolve {
    use modforge::patterns::sleuth::{self, Target};
    use std::sync::OnceLock;

    /// Resolved runtime address of GAMESTATE_PTR (the main game-state
    /// struct base, `DAT_1403fb0d8` in the decomp). Cached on first
    /// successful resolve. Returns `None` if every candidate
    /// signature missed (game build has shifted further than the
    /// catalogued sigs cover).
    pub fn gamestate_ptr() -> Option<usize> {
        static CACHE: OnceLock<Option<usize>> = OnceLock::new();
        *CACHE.get_or_init(resolve_gamestate_ptr_uncached)
    }

    /// One candidate way to recover GAMESTATE_PTR from a `.text`
    /// instruction.
    struct Candidate {
        name: &'static str,
        /// IDA-style sleuth signature for the instruction. Single
        /// `?` per wildcard byte.
        sig: &'static str,
        /// Byte offset of disp32 inside the matched bytes.
        disp32_offset: usize,
        /// Total length of the matched instruction.
        instr_len: usize,
        /// Inline offset added to GAMESTATE_PTR by the instruction
        /// (subtracted from the resolved target to recover the base).
        inline_offset: usize,
    }

    /// Candidate set. Each references a decomp site that does
    /// something with `DAT_1403fb0d8 + N`; the constant N is the
    /// `inline_offset`. The instruction encoding is the most likely
    /// MSVC emission for that C expression.
    const CANDIDATES: &[Candidate] = &[
        // `*(int *)(DAT_1403fb0d8 + 0x308) += 1000;` (cheat-money
        // handler in draw_pause_status). The constant 0x3e8 (=1000)
        // makes this site unique across the binary.
        // Encoding: add dword ptr [rip+disp32], imm32
        //   81 05 dd dd dd dd e8 03 00 00
        Candidate {
            name: "cheat_money_add_1000",
            sig: "81 05 ?? ?? ?? ?? e8 03 00 00",
            disp32_offset: 2,
            instr_len: 10,
            inline_offset: 0x308,
        },
        // `*(int *)(DAT_1403fb0d8 + 0x308) < 0x32` race-fee check.
        // Encoding: cmp dword ptr [rip+disp32], imm8
        //   83 3d dd dd dd dd 32
        Candidate {
            name: "race_fee_cmp_50",
            sig: "83 3d ?? ?? ?? ?? 32",
            disp32_offset: 2,
            instr_len: 7,
            inline_offset: 0x308,
        },
        // `*(undefined4 *)(DAT_1403fb0d8 + 0x440) = 0x14;` from
        // some race-state-set path. Less unique than the above
        // because the constant 0x14 is common, but the +0x440 is
        // a distinct site.
        // Encoding: mov dword ptr [rip+disp32], imm32
        //   c7 05 dd dd dd dd 14 00 00 00
        Candidate {
            name: "field_440_set_20",
            sig: "c7 05 ?? ?? ?? ?? 14 00 00 00",
            disp32_offset: 2,
            instr_len: 10,
            inline_offset: 0x440,
        },
    ];

    fn resolve_gamestate_ptr_uncached() -> Option<usize> {
        let targets: Vec<Target<'_>> = CANDIDATES
            .iter()
            .map(|c| Target {
                name: c.name,
                sigs: std::slice::from_ref(&c.sig),
            })
            .collect();
        let res = match sleuth::resolve_all(&targets) {
            Ok(r) => r,
            Err(e) => {
                modforge::log!("R3 resolver scan failed: {e}");
                return None;
            }
        };

        let mut last_base: Option<usize> = None;
        for c in CANDIDATES {
            let Some(instr_addr) = res.get(c.name) else {
                modforge::log!("R3 candidate {} missed", c.name);
                continue;
            };
            // SAFETY: instr_addr is inside `.text`, mapped readable.
            let disp_ptr = (instr_addr + c.disp32_offset) as *const i32;
            let disp32 = unsafe { disp_ptr.read_unaligned() } as isize;
            let next_ip = instr_addr.wrapping_add(c.instr_len);
            let referenced = next_ip.wrapping_add(disp32 as usize);
            if referenced < c.inline_offset {
                modforge::log!(
                    "R3 {} produced too-small target 0x{referenced:x}",
                    c.name
                );
                continue;
            }
            let base = referenced - c.inline_offset;
            modforge::log!(
                "R3 candidate {name}: instr=0x{instr_addr:x} disp32={disp32:#x} \
                 referenced=0x{referenced:x} base=0x{base:x}",
                name = c.name,
            );
            // Cross-validate: if multiple candidates resolve, they
            // should agree on the base. Keep the first; warn on
            // disagreement.
            if let Some(prev) = last_base {
                if prev != base {
                    modforge::log!(
                        "R3 WARN candidate {} disagrees: prev=0x{prev:x} new=0x{base:x}",
                        c.name
                    );
                }
            }
            last_base = Some(base);
        }
        if last_base.is_none() {
            modforge::log!("R3 GAMESTATE_PTR: no candidate signature matched");
        }
        last_base
    }
}

pub fn image_base() -> usize {
    use windows_sys::Win32::System::LibraryLoader::GetModuleHandleW;
    // SAFETY: GetModuleHandleW(NULL) returns the .exe HMODULE,
    // which on x64 IS the image base. Always safe.
    let h = unsafe { GetModuleHandleW(std::ptr::null()) };
    h as usize
}

/// Translate a hardcoded address (RVA-style, written as absolute
/// pointer in our decompilation) into a runtime address adjusted
/// for actual image base.
pub fn rebase(absolute_from_dump: usize) -> usize {
    let delta = image_base().wrapping_sub(PREFERRED_IMAGE_BASE);
    absolute_from_dump.wrapping_add(delta)
}

// =============================================================================
// Build identification (Phase R1 from docs/ADDRESS-RESOLUTION.md)
// =============================================================================

/// SHA256 of the loaded Horsey.exe image's .text section. Used to
/// pin "which build am I on" so we can correlate crashes to a
/// specific binary. Skip .reloc + .rsrc because those carry
/// per-load fixups / locale strings that drift between identical
/// builds.
///
/// Caches the result in a `OnceLock` so repeated calls are free.
pub fn image_text_sha256() -> String {
    use sha2::{Digest, Sha256};
    use std::sync::OnceLock;
    static CACHE: OnceLock<String> = OnceLock::new();
    CACHE
        .get_or_init(|| {
            let Some((text_addr, text_size)) = find_text_section() else {
                return "unavailable".to_string();
            };
            // SAFETY: text_addr / text_size point at the loaded image's
            // .text bytes; readable for the lifetime of the process.
            let bytes =
                unsafe { std::slice::from_raw_parts(text_addr as *const u8, text_size) };
            let mut hasher = Sha256::new();
            hasher.update(bytes);
            let digest = hasher.finalize();
            digest.iter().map(|b| format!("{b:02x}")).collect::<String>()
        })
        .clone()
}

/// Walk the PE header at `image_base()` to find the .text section's
/// runtime address and size. Returns None on any parse failure.
/// caller should treat that as "build identification not available
/// this session" and continue.
fn find_text_section() -> Option<(usize, usize)> {
    let base = image_base();
    if base == 0 {
        return None;
    }
    // SAFETY: PE images are mapped read-only from offset 0; the
    // DOS header is always present at the image base, and the PE
    // header follows after a small jump.
    unsafe {
        // DOS header `e_lfanew` is at offset 0x3c.
        let e_lfanew = *((base + 0x3c) as *const u32) as usize;
        let pe = base + e_lfanew;
        // PE signature must be "PE\0\0".
        let sig = *(pe as *const [u8; 4]);
        if sig != *b"PE\0\0" {
            return None;
        }
        // COFF File Header sits right after the signature (4 bytes).
        let num_sections = *((pe + 4 + 2) as *const u16) as usize;
        let opt_header_size = *((pe + 4 + 16) as *const u16) as usize;
        let opt_header = pe + 4 + 20;
        let section_table = opt_header + opt_header_size;
        // Walk section headers; each is 40 bytes.
        for i in 0..num_sections {
            let hdr = section_table + i * 40;
            let name_bytes = *(hdr as *const [u8; 8]);
            // Section name is null-padded ASCII, ".text\0\0\0".
            if &name_bytes[..5] == b".text" {
                let virtual_size = *((hdr + 8) as *const u32) as usize;
                let virtual_addr = *((hdr + 12) as *const u32) as usize;
                return Some((base + virtual_addr, virtual_size));
            }
        }
    }
    None
}

/// Public accessor for the .text section's runtime size in bytes.
/// Returns `None` on PE-parse failure.
pub fn find_text_section_size() -> Option<usize> {
    find_text_section().map(|(_addr, size)| size)
}

/// Mtime + size of the on-disk Horsey.exe, if findable.
pub fn image_file_info() -> Option<(std::path::PathBuf, std::time::SystemTime, u64)> {
    // GetModuleFileNameW for HMODULE = image_base() returns the
    // path. We resolve through std::env::current_exe() since the
    // injected DLL shares the same process and main exe.
    let path = std::env::current_exe().ok()?;
    let meta = std::fs::metadata(&path).ok()?;
    let mtime = meta.modified().ok()?;
    let size = meta.len();
    Some((path, mtime, size))
}
