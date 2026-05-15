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
/// Toggled from the debug cheat menu (line 60442 in old decomp).
/// Original decomp RVA was 0x1403d95c5; re-derived from the live
/// image 2026-05-15 via the cmp/sete-direct-to-same-byte sig.
/// Drift -0x20 from old hardcoded.
pub const NO_TIRE_TOGGLE: usize = 0x1403d95a5;

/// Debug-mode-active flag. Set when the player types "debug" in
/// the pause menu. Gates the cheat-menu buttons + extended status
/// line. Original decomp RVA was 0x1403d959b; re-derived from the
/// live image via the unlock-block sig (set 1 followed by set 0
/// at target1 - 0x79). Drift -0x20 from old hardcoded.
pub const DEBUG_MODE_ACTIVE: usize = 0x1403d957b;

/// Debug-mode log gate. When set, retirement messages,
/// `%s = (%d rand + ...)` price formulas, and other debug lines
/// print to the log. Independent of `DEBUG_MODE_ACTIVE`.
/// Original decomp RVA was 0x1403d9526; re-derived from the live
/// image via the global-init triplet sig (0x100, 0xffffffff, 0).
/// Drift -0x20 from old hardcoded.
pub const DEBUG_LOG_GATE: usize = 0x1403d9506;

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

    /// `check_horse_eligibility`. Re-derived 2026-05-15 via probe;
    /// original Ghidra RVA `0x1400dde40` pointed mid-function.
    /// True entry at +1008 from stale (low confidence; may be a
    /// different function with the same prologue shape).
    pub const CHECK_HORSE_ELIGIBILITY: usize = 0x1400de230;

    /// `retire_horse_handler`. Re-derived via the format-string
    /// xref method (`tests/find_retire_horse_handler.rs`): scan
    /// `.rdata` for the unique "%s retired %s (useless)..." format
    /// literal, xref to the `lea rcx` inside the function, walk
    /// backward through .text past int3-padding to the prologue.
    /// True entry +1013 bytes from old Ghidra RVA 0x1400df280.
    pub const RETIRE_HORSE_HANDLER: usize = 0x1400df675;

    /// `compute_horse_price`. Re-derived via probe; original
    /// Ghidra RVA `0x1400dcab0` pointed mid-function. True entry
    /// at -811 from stale.
    pub const COMPUTE_HORSE_PRICE: usize = 0x1400dc785;

    /// `crispr_lab_state_machine`. Re-derived via probe; original
    /// Ghidra RVA `0x140089510` pointed mid-function. True entry
    /// at -84 (high confidence; small drift).
    pub const CRISPR_LAB: usize = 0x1400894bc;

    /// `breeding_state_machine`. Re-derived via probe; original
    /// Ghidra RVA `0x1400e0aa0` pointed mid-function. True entry
    /// at -649 from stale.
    pub const BREEDING: usize = 0x1400e0817;

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
    /// Re-derived 2026-05-15; original Ghidra RVA `0x140066200`
    /// pointed mid-function. True entry at -308 from stale.
    pub const DRAW_PAUSE_STATUS: usize = 0x1400660cc;

    /// `tmx_map_parser`. The .tmx loader.
    pub const TMX_MAP_PARSER: usize = 0x1400fe2e0;

    /// `pop_genome_builder`. Pop.xml runtime spawner. Re-derived
    /// 2026-05-15; original Ghidra RVA pointed mid-function. True
    /// entry at -57 (high confidence; minor drift).
    pub const POP_GENOME_BUILDER: usize = 0x1400927e7;

    /// `daily_horse_event_emitter`. Per-day per-horse event log.
    pub const DAILY_HORSE_EVENT: usize = 0x14002fe00;

    /// `track_state_machine`. Race lifecycle.
    pub const TRACK_STATE_MACHINE: usize = 0x14002d7c0;

    /// `circus_event_handler`.
    pub const CIRCUS_HANDLER: usize = 0x140039190;

    /// `sumo_match_handler`. Re-derived 2026-05-15; original Ghidra
    /// RVA pointed mid-function. True entry at -84 (high confidence).
    pub const SUMO_HANDLER: usize = 0x14007b28c;

    /// `power_plant_handler`. Re-derived 2026-05-15; True entry at
    /// -320 from stale.
    pub const POWER_PLANT: usize = 0x140069270;

    /// `world_action_dispatcher`. Re-derived 2026-05-15; True entry
    /// at -190 from stale.
    pub const WORLD_ACTION: usize = 0x1401075a2;

    /// `hot_air_balloon_controller`. Re-derived 2026-05-15; True
    /// entry at +1024 from stale (low confidence; window-edge).
    pub const BALLOON_CONTROLLER: usize = 0x14010a9e0;

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

    /// One candidate way to recover an address from a `.text`
    /// instruction.
    struct Candidate {
        name: &'static str,
        /// IDA-style sleuth signature. `??` per wildcard byte.
        sig: &'static str,
        /// Byte offset of the anchor `disp32` inside the matched
        /// bytes (the one we decode to recover the target).
        disp32_offset: usize,
        /// Total length of the instruction whose `next_ip` is the
        /// reference point for the anchor `disp32`.
        instr_len: usize,
        /// Inline offset added to the target by the instruction.
        /// Subtracted from the resolved target to recover the base.
        inline_offset: usize,
        /// Optional second `disp32` to cross-validate (must refer
        /// to the SAME final target). Catches false matches where
        /// the opcode shape is right but the operand is a different
        /// global. `(disp32_offset, next_ip_offset)` relative to
        /// the match start.
        validate_disp32: Option<(usize, usize)>,
    }

    /// CANDIDATES kept empty: the GAMESTATE_PTR resolver no longer
    /// uses the generic `Candidate` framework. The slot is recovered
    /// by `resolve_gamestate_ptr_via_constructor` (below) which
    /// anchors on a unique instruction inside the GameState
    /// constructor `FUN_1400fd580` and scans the local function body
    /// for the slot-store instruction. The historical Candidate
    /// shape (single-instruction `add [rip+disp32], imm` against the
    /// slot) was based on a wrong mental model where the slot was
    /// treated as the struct itself.
    #[allow(dead_code)]
    const CANDIDATES: &[Candidate] = &[];

    /// Resolved runtime address of `NO_TIRE_TOGGLE` (the 1-byte
    /// cheat-toggle flag at `DAT_1403d95c5`). Cached.
    pub fn no_tire_toggle() -> Option<usize> {
        static CACHE: OnceLock<Option<usize>> = OnceLock::new();
        *CACHE.get_or_init(|| resolve_data_global(
            CANDIDATES_NO_TIRE_TOGGLE,
            super::NO_TIRE_TOGGLE,
        ))
    }

    /// Resolved runtime address of `DEBUG_MODE_ACTIVE` (the 1-byte
    /// debug-cheat-active flag at `DAT_1403d959b`). Cached.
    pub fn debug_mode_active() -> Option<usize> {
        static CACHE: OnceLock<Option<usize>> = OnceLock::new();
        *CACHE.get_or_init(|| {
            let resolved = resolve_debug_mode_active_via_unlock_block()?;
            let hardcoded = super::rebase(super::DEBUG_MODE_ACTIVE);
            let delta = resolved.abs_diff(hardcoded);
            if delta > 0x1000 {
                modforge::log!(
                    "R3 DEBUG_MODE_ACTIVE sanity gate rejected resolved=0x{resolved:x}; \
                     hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x1000"
                );
                return None;
            }
            Some(resolved)
        })
    }

    /// Locate DEBUG_MODE_ACTIVE via the d-e-b-u-g typed-string
    /// unlock block. Decomp (FUN_140066200 line 537-539):
    ///
    /// ```c
    /// DAT_1403d959b = '\x01';    // DEBUG_MODE_ACTIVE
    /// DAT_1403d9522 = 0;          // adjacent flag, 0x79 below
    /// ```
    ///
    /// MSVC emits these as two adjacent RIP-relative byte stores:
    /// `c6 05 dd1 dd1 dd1 dd1 01  c6 05 dd2 dd2 dd2 dd2 00`. The
    /// pair is rare in `.text` (most adjacent set-1/set-0 byte
    /// stores target unrelated globals), but the SPECIFIC pair
    /// where `target2 - target1 == -0x79` is unique by construction:
    /// the 0x79-byte distance is a fingerprint of the decomp's
    /// `.data` layout for the cheat-globals subsystem.
    ///
    /// Algorithm:
    ///   1. Scan `.text` for the 14-byte adjacent-write pattern.
    ///   2. For each match, decode both disp32s to CPU-effective
    ///      target addresses.
    ///   3. Filter to matches where `target2 == target1 - 0x79`.
    ///   4. If exactly one match passes, return its target1.
    fn resolve_debug_mode_active_via_unlock_block() -> Option<usize> {
        use modforge::patterns::sleuth;
        const SIG: &str = "c6 05 ?? ?? ?? ?? 01 c6 05 ?? ?? ?? ?? 00";
        const PAIR_OFFSET: isize = -0x79;

        let hits = sleuth::scan_all_matches(SIG).ok()?;
        let mut accepted: Vec<usize> = Vec::new();
        for instr_addr in hits {
            // SAFETY: instr_addr is inside `.text`, mapped.
            let disp1 = unsafe {
                ((instr_addr + 2) as *const i32).read_unaligned()
            } as isize;
            let disp2 = unsafe {
                ((instr_addr + 9) as *const i32).read_unaligned()
            } as isize;
            // CPU effective addrs. First instr is 7 bytes long;
            // second instr starts at +7 and is 7 bytes long.
            let target1 = instr_addr.wrapping_add(7).wrapping_add(disp1 as usize);
            let target2 = instr_addr.wrapping_add(14).wrapping_add(disp2 as usize);
            let delta = target2.wrapping_sub(target1) as isize;
            if delta == PAIR_OFFSET {
                accepted.push(target1);
            }
        }
        accepted.sort_unstable();
        accepted.dedup();
        match accepted.len() {
            0 => {
                modforge::log!(
                    "R3 DEBUG_MODE_ACTIVE: no unlock-block match with target delta -0x79"
                );
                None
            }
            1 => Some(accepted[0]),
            n => {
                modforge::log!(
                    "R3 DEBUG_MODE_ACTIVE: {n} distinct candidate slots after \
                     filtering for delta -0x79; sig is genuinely ambiguous"
                );
                None
            }
        }
    }

    /// Resolved runtime address of `APPLY_GENE_TO_HORSE`. Cached.
    pub fn apply_gene_to_horse() -> Option<usize> {
        resolve_function(
            "APPLY_GENE_TO_HORSE",
            APPLY_GENE_TO_HORSE_SIGS,
            super::fn_addr::APPLY_GENE_TO_HORSE,
        )
    }
    /// Resolved runtime address of `HORSE_CONSTRUCTOR`. Cached.
    pub fn horse_constructor() -> Option<usize> {
        resolve_function(
            "HORSE_CONSTRUCTOR",
            HORSE_CONSTRUCTOR_SIGS,
            super::fn_addr::HORSE_CONSTRUCTOR,
        )
    }
    /// Resolved runtime address of `HORSE_DESTRUCTOR`. Cached.
    pub fn horse_destructor() -> Option<usize> {
        resolve_function(
            "HORSE_DESTRUCTOR",
            HORSE_DESTRUCTOR_SIGS,
            super::fn_addr::HORSE_DESTRUCTOR,
        )
    }
    /// Resolved runtime address of `GENE_COMBINATOR`. Cached.
    pub fn gene_combinator() -> Option<usize> {
        resolve_function(
            "GENE_COMBINATOR",
            GENE_COMBINATOR_SIGS,
            super::fn_addr::GENE_COMBINATOR,
        )
    }
    /// Resolved runtime address of `SAVE_WRITER`. Cached.
    pub fn save_writer() -> Option<usize> {
        resolve_function(
            "SAVE_WRITER",
            SAVE_WRITER_SIGS,
            super::fn_addr::SAVE_WRITER,
        )
    }
    /// Resolved runtime address of `LOAD_GAME`. Cached.
    pub fn load_game() -> Option<usize> {
        resolve_function("LOAD_GAME", LOAD_GAME_SIGS, super::fn_addr::LOAD_GAME)
    }
    /// Resolved runtime address of `HORSE_SAVE_WRITER`. Cached.
    pub fn horse_save_writer() -> Option<usize> {
        resolve_function(
            "HORSE_SAVE_WRITER",
            HORSE_SAVE_WRITER_SIGS,
            super::fn_addr::HORSE_SAVE_WRITER,
        )
    }
    /// Resolved runtime address of `HORSE_SAVE_LOADER`. Cached.
    pub fn horse_save_loader() -> Option<usize> {
        resolve_function(
            "HORSE_SAVE_LOADER",
            HORSE_SAVE_LOADER_SIGS,
            super::fn_addr::HORSE_SAVE_LOADER,
        )
    }

    /// 32-byte body sigs captured from the live image
    /// (2026-05-15, build sha256 prefix 742a6222ba73). Each is the
    /// first 32 bytes of the function's prologue + initial body.
    /// 32 random bytes virtually never collide in a 4 MiB `.text`
    /// section, so these resolve uniquely without further
    /// wildcarding. When MSVC reorders or restructures, the
    /// resolver fails and the production call site falls back to
    /// the hardcoded RVA; that's the migration's safety net.
    const APPLY_GENE_TO_HORSE_SIGS: &[&str] = &[
        "48 8b c4 55 53 56 57 41 54 41 55 41 56 41 57 48 8d a8 d8 fb ff ff 48 81 ec e8 04 00 00 0f 29 70",
    ];
    const HORSE_CONSTRUCTOR_SIGS: &[&str] = &[
        "48 89 5c 24 10 48 89 4c 24 08 57 48 83 ec 20 48 8b d9 48 8d 05 ?? ?? ?? ?? 48 89 01 33 ff 48 89",
    ];
    const HORSE_DESTRUCTOR_SIGS: &[&str] = &[
        "48 89 5c 24 08 48 89 74 24 10 57 48 83 ec 20 48 8d 05 ?? ?? ?? ?? 8b f2 48 89 01 48 8b d9 ff 0d",
    ];
    const GENE_COMBINATOR_SIGS: &[&str] = &[
        "48 89 5c 24 08 48 89 6c 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 ec 20 4c 8b f9 45",
    ];
    const SAVE_WRITER_SIGS: &[&str] = &[
        "57 41 56 48 81 ec 40 01 00 00 48 8b e9 48 8d 51 18 48 8d 4c 24 30 e8 ?? ?? ?? ?? 48 8b 54 24 48",
    ];
    const LOAD_GAME_SIGS: &[&str] = &[
        "48 89 5c 24 08 55 56 57 41 54 41 55 41 56 41 57 48 8b ec 48 83 ec 70 48 8b f1 44 8b c2 48 8d 15",
    ];
    const HORSE_SAVE_WRITER_SIGS: &[&str] = &[
        "57 41 56 48 83 ec 40 48 8b e9 e8 ?? ?? ?? ?? 48 8d 8d b8 02 00 00 44 8b f0 e8 ?? ?? ?? ?? 48 8b",
    ];
    const HORSE_SAVE_LOADER_SIGS: &[&str] = &[
        "53 57 48 83 ec 58 48 8b f9 48 81 c1 b8 02 00 00 e8 ?? ?? ?? ?? 48 8d 8f a8 02 00 00 e8 ?? ?? ??",
    ];

    // ====================================================================
    // H batch: unused-in-v1 functions whose hardcoded RVA points at a
    // valid function prologue in this build. 32-byte body sigs captured
    // live (2026-05-15). Per-target accessors below.
    // ====================================================================

    pub fn eval_diploid_blend_a() -> Option<usize> {
        resolve_function("EVAL_DIPLOID_BLEND_A", EVAL_DIPLOID_BLEND_A_SIGS, super::fn_addr::EVAL_DIPLOID_BLEND_A)
    }
    pub fn eval_diploid_blend_b() -> Option<usize> {
        resolve_function("EVAL_DIPLOID_BLEND_B", EVAL_DIPLOID_BLEND_B_SIGS, super::fn_addr::EVAL_DIPLOID_BLEND_B)
    }
    pub fn gene_death_drift() -> Option<usize> {
        resolve_function("GENE_DEATH_DRIFT", GENE_DEATH_DRIFT_SIGS, super::fn_addr::GENE_DEATH_DRIFT)
    }
    pub fn gene_allele_swap() -> Option<usize> {
        resolve_function("GENE_ALLELE_SWAP", GENE_ALLELE_SWAP_SIGS, super::fn_addr::GENE_ALLELE_SWAP)
    }
    pub fn gene_table_xml_writer() -> Option<usize> {
        resolve_function("GENE_TABLE_XML_WRITER", GENE_TABLE_XML_WRITER_SIGS, super::fn_addr::GENE_TABLE_XML_WRITER)
    }
    pub fn gene_table_loader() -> Option<usize> {
        resolve_function("GENE_TABLE_LOADER", GENE_TABLE_LOADER_SIGS, super::fn_addr::GENE_TABLE_LOADER)
    }
    pub fn pop_xml_loader() -> Option<usize> {
        resolve_function("POP_XML_LOADER", POP_XML_LOADER_SIGS, super::fn_addr::POP_XML_LOADER)
    }
    pub fn gene_engine_consumer() -> Option<usize> {
        resolve_function("GENE_ENGINE_CONSUMER", GENE_ENGINE_CONSUMER_SIGS, super::fn_addr::GENE_ENGINE_CONSUMER)
    }
    pub fn tmx_map_parser() -> Option<usize> {
        resolve_function("TMX_MAP_PARSER", TMX_MAP_PARSER_SIGS, super::fn_addr::TMX_MAP_PARSER)
    }
    pub fn daily_horse_event() -> Option<usize> {
        resolve_function("DAILY_HORSE_EVENT", DAILY_HORSE_EVENT_SIGS, super::fn_addr::DAILY_HORSE_EVENT)
    }
    pub fn track_state_machine() -> Option<usize> {
        resolve_function("TRACK_STATE_MACHINE", TRACK_STATE_MACHINE_SIGS, super::fn_addr::TRACK_STATE_MACHINE)
    }
    pub fn circus_handler() -> Option<usize> {
        resolve_function("CIRCUS_HANDLER", CIRCUS_HANDLER_SIGS, super::fn_addr::CIRCUS_HANDLER)
    }

    // 32-byte body sigs from live image. RIP-relative disp32 + call
    // disp32 fields wildcarded so future minor MSVC reorders survive.
    // EVAL_DIPLOID_BLEND_A and _B are sibling functions back-to-back
    // in `.text` (B is 0xe0 bytes after A) with identical 32-byte
    // prologue prefixes; they diverge only in the `lea rbp,
    // [rip+disp32]` displacement (each points at its own jump table
    // in `.rdata`). Use the literal disp32 to disambiguate. This is
    // build-specific; if `.rdata` shifts, these sigs miss and the
    // production call site falls back to hardcoded.
    const EVAL_DIPLOID_BLEND_A_SIGS: &[&str] = &[
        "48 89 5c 24 08 48 89 6c 24 10 48 89 74 24 18 57 48 83 ec 20 48 63 da 48 8d 2d 72 87 34 00 48 8b",
    ];
    const EVAL_DIPLOID_BLEND_B_SIGS: &[&str] = &[
        "48 89 5c 24 08 48 89 6c 24 10 48 89 74 24 18 57 48 83 ec 20 48 63 da 48 8d 2d 92 86 34 00 48 8b",
    ];
    const GENE_DEATH_DRIFT_SIGS: &[&str] = &[
        "48 8b c4 55 53 56 57 41 54 41 55 41 56 41 57 48 8d a8 b8 fa ff ff 48 81 ec 08 06 00 00 0f 29 70",
    ];
    const GENE_ALLELE_SWAP_SIGS: &[&str] = &[
        "48 89 5c 24 08 48 89 74 24 10 48 89 7c 24 18 48 63 fa 48 be c1 d4 1c 42 29 8f a0 3f 4d 63 d9 45",
    ];
    const GENE_TABLE_XML_WRITER_SIGS: &[&str] = &[
        "41 54 41 55 41 56 41 57 48 8d 6c 24 90 48 81 ec 70 01 00 00 0f 29 70 c8 0f 29 78 b8 44 0f 29 40",
    ];
    // 32-byte sig collided with another function that has the same
    // push-r15 + lea rbp prologue. Extended to 48 bytes to include
    // a unique body fragment (mov [rbx], sil; lea rax, [rip+disp32]
    // with disp wildcarded; nop padding).
    const GENE_TABLE_LOADER_SIGS: &[&str] = &[
        "41 57 48 8d a8 28 ff ff ff 48 81 ec a0 01 00 00 0f 29 70 b8 0f 29 78 a8 44 0f 29 40 98 44 0f 29 48 88 33 f6 8b ce 48 8d 05 ?? ?? ?? ?? 0f 1f 00",
    ];
    const POP_XML_LOADER_SIGS: &[&str] = &[
        "48 8d ac 24 c0 cf ff ff b8 40 31 00 00 e8 ?? ?? ?? ?? 48 2b e0 48 8d 4c 24 50 e8 ?? ?? ?? ?? 90",
    ];
    const GENE_ENGINE_CONSUMER_SIGS: &[&str] = &[
        "48 8b c4 55 53 56 57 41 54 41 55 41 56 41 57 48 8d a8 88 fd ff ff 48 81 ec 38 03 00 00 0f 29 70",
    ];
    const TMX_MAP_PARSER_SIGS: &[&str] = &[
        "48 89 5c 24 08 48 89 7c 24 10 55 48 8b ec 48 83 ec 20 8b fa 33 db 83 fa 0c 7f 25 b9 78 04 00 00",
    ];
    const DAILY_HORSE_EVENT_SIGS: &[&str] = &[
        "48 89 5c 24 10 48 89 74 24 18 48 89 7c 24 20 55 41 54 41 55 41 56 41 57 48 8d 6c 24 c9 48 81 ec",
    ];
    const TRACK_STATE_MACHINE_SIGS: &[&str] = &[
        "48 8b c4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec e0",
    ];
    const CIRCUS_HANDLER_SIGS: &[&str] = &[
        "48 8b c4 48 89 48 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8d 6c 24 b8 48 81 ec 48 01 00 00 0f",
    ];

    // ====================================================================
    // Re-derived batch: original Ghidra RVAs pointed mid-function.
    // The forensic `r2_save_find_entries`-style probe (see
    // `tests/forensic_stale_fn_entries.rs`) found a valid function
    // prologue within +/-1024 bytes of each stale RVA. Updated
    // `fn_addr::*` constants below correspond to those true entries.
    //
    // Confidence varies with the distance from the stale RVA:
    //   - close (<100 bytes): high confidence (same function, minor
    //     drift between builds).
    //   - medium (100-512): likely same function.
    //   - far (>500): may be a DIFFERENT function than the original
    //     name implies. Semantic verification deferred until any of
    //     these becomes a production target.
    //
    // None are currently consumed by horsey-mod's active patch stack.

    pub fn check_horse_eligibility() -> Option<usize> {
        resolve_function("CHECK_HORSE_ELIGIBILITY", CHECK_HORSE_ELIGIBILITY_SIGS, super::fn_addr::CHECK_HORSE_ELIGIBILITY)
    }
    /// Resolved runtime address of `RETIRE_HORSE_HANDLER`. Cached.
    /// True entry re-derived 2026-05-15 via the format-string xref
    /// method (see `tests/find_retire_horse_handler.rs`).
    pub fn retire_horse_handler() -> Option<usize> {
        resolve_function(
            "RETIRE_HORSE_HANDLER",
            RETIRE_HORSE_HANDLER_SIGS,
            super::fn_addr::RETIRE_HORSE_HANDLER,
        )
    }
    pub fn compute_horse_price() -> Option<usize> {
        resolve_function("COMPUTE_HORSE_PRICE", COMPUTE_HORSE_PRICE_SIGS, super::fn_addr::COMPUTE_HORSE_PRICE)
    }
    pub fn crispr_lab() -> Option<usize> {
        resolve_function("CRISPR_LAB", CRISPR_LAB_SIGS, super::fn_addr::CRISPR_LAB)
    }
    pub fn breeding() -> Option<usize> {
        resolve_function("BREEDING", BREEDING_SIGS, super::fn_addr::BREEDING)
    }
    pub fn draw_pause_status() -> Option<usize> {
        resolve_function("DRAW_PAUSE_STATUS", DRAW_PAUSE_STATUS_SIGS, super::fn_addr::DRAW_PAUSE_STATUS)
    }
    pub fn pop_genome_builder() -> Option<usize> {
        resolve_function("POP_GENOME_BUILDER", POP_GENOME_BUILDER_SIGS, super::fn_addr::POP_GENOME_BUILDER)
    }
    pub fn sumo_handler() -> Option<usize> {
        resolve_function("SUMO_HANDLER", SUMO_HANDLER_SIGS, super::fn_addr::SUMO_HANDLER)
    }
    pub fn power_plant() -> Option<usize> {
        resolve_function("POWER_PLANT", POWER_PLANT_SIGS, super::fn_addr::POWER_PLANT)
    }
    pub fn world_action() -> Option<usize> {
        resolve_function("WORLD_ACTION", WORLD_ACTION_SIGS, super::fn_addr::WORLD_ACTION)
    }
    pub fn balloon_controller() -> Option<usize> {
        resolve_function("BALLOON_CONTROLLER", BALLOON_CONTROLLER_SIGS, super::fn_addr::BALLOON_CONTROLLER)
    }

    const CHECK_HORSE_ELIGIBILITY_SIGS: &[&str] = &[
        "48 89 5c 24 10 48 89 74 24 18 55 57 41 54 41 56 41 57 48 8b ec 48 81 ec 80 00 00 00 0f 29 74 24",
    ];
    const RETIRE_HORSE_HANDLER_SIGS: &[&str] = &[
        // 32-byte prologue captured live 2026-05-15:
        //   push rbx; push rsi; push rdi; push r12; push r13; push r14;
        //   push r15; lea rbp, [rsp - 0x1f]; sub rsp, 0xf8; mov r13, rcx;
        //   xor r12d, r12d; mov dword [rbp + ??], r12d
        // The trailing `?? ` wildcards the rbp-relative disp8 of the
        // first mov; everything before is stable across builds.
        "53 56 57 41 54 41 55 41 56 41 57 48 8d 6c 24 e1 48 81 ec f8 00 00 00 4c 8b e9 45 33 e4 44 89 65",
    ];
    const COMPUTE_HORSE_PRICE_SIGS: &[&str] = &[
        "48 89 7c 24 10 55 48 8b ec 48 83 ec 60 0f 29 74 24 50 48 8b f9 4c 63 c2 48 8b 91 30 01 00 00 48",
    ];
    const CRISPR_LAB_SIGS: &[&str] = &[
        "57 41 54 41 56 41 57 48 8d a8 58 fe ff ff 48 81 ec 80 02 00 00 0f 29 70 c8 0f 29 78 b8 44 0f 29",
    ];
    const BREEDING_SIGS: &[&str] = &[
        "57 41 54 41 55 41 56 41 57 48 8b ec 48 83 ec 68 44 8b f2 4c 8b f9 4c 8b 81 30 01 00 00 48 8b 81",
    ];
    const DRAW_PAUSE_STATUS_SIGS: &[&str] = &[
        "57 41 54 41 56 41 57 48 8d 68 a1 48 81 ec c0 00 00 00 0f 29 70 c8 0f 29 78 b8 44 0f 29 40 a8 44",
    ];
    const POP_GENOME_BUILDER_SIGS: &[&str] = &[
        "57 41 54 41 55 41 56 41 57 48 8d 6c 24 d9 48 81 ec e0 00 00 00 0f 29 b4 24 d0 00 00 00 48 8b f9",
    ];
    const SUMO_HANDLER_SIGS: &[&str] = &[
        "57 41 56 48 8d 68 a1 48 81 ec c0 00 00 00 0f 29 70 d8 0f 29 78 c8 44 0f 29 40 b8 44 0f 29 48 a8",
    ];
    const POWER_PLANT_SIGS: &[&str] = &[
        "48 89 5c 24 08 55 48 8b ec 48 83 ec 60 0f 29 74 24 50 48 8b d9 ff 81 50 02 00 00 e8 ?? ?? ?? ??",
    ];
    const WORLD_ACTION_SIGS: &[&str] = &[
        "57 41 54 41 55 41 56 41 57 48 83 ec 70 0f 29 70 c8 0f 29 78 b8 44 8b ca 4c 8b f9 0f 57 c0 f3 0f",
    ];
    const BALLOON_CONTROLLER_SIGS: &[&str] = &[
        "48 8b c4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec a0",
    ];

    /// Generic function resolver: try each sig in order; first
    /// match wins; sanity-gate against the rebased hardcoded RVA
    /// at 0x10000 bytes (1 MiB is too loose; 0x10000 covers
    /// observed save-target drifts in this codebase).
    fn resolve_function(
        name: &'static str,
        sigs: &'static [&'static str],
        hardcoded_rva: usize,
    ) -> Option<usize> {
        use modforge::patterns::sleuth::{self, Target};
        let target = Target { name, sigs };
        let resolution = sleuth::resolve_all(std::slice::from_ref(&target)).ok()?;
        let resolved = resolution.get(name)?;
        let hardcoded = super::rebase(hardcoded_rva);
        let delta = resolved.abs_diff(hardcoded);
        if delta > 0x10000 {
            modforge::log!(
                "R2 {name} sanity gate rejected resolved=0x{resolved:x}; \
                 hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x10000"
            );
            return None;
        }
        Some(resolved)
    }

    /// Resolved runtime address of `RACES_COUNTER`
    /// (`DAT_1403eded8`). Cached.
    pub fn races_counter() -> Option<usize> {
        static CACHE: OnceLock<Option<usize>> = OnceLock::new();
        *CACHE.get_or_init(|| {
            let resolved = resolve_races_counter_via_minus_10p5f_anchor()?;
            let hardcoded = super::rebase(super::RACES_COUNTER);
            let delta = resolved.abs_diff(hardcoded);
            if delta > 0x1000 {
                modforge::log!(
                    "R3 RACES_COUNTER sanity gate rejected resolved=0x{resolved:x}; \
                     hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x1000"
                );
                return None;
            }
            Some(resolved)
        })
    }

    /// Resolved runtime address of `SAVE_VERSION_GLOBAL`
    /// (`DAT_1403fb0e0`). Cached.
    ///
    /// SAVE_VERSION_GLOBAL is structurally at GAMESTATE_PTR + 8
    /// (the slot for the save format version sits immediately
    /// after the GameState pointer slot in `.data`). Same layout
    /// as the original decomp (`0x1403fb0e0` - `0x1403fb0d8` = 8).
    /// Derive from the resolved GAMESTATE_PTR rather than scanning
    /// the binary independently.
    pub fn save_version_global() -> Option<usize> {
        static CACHE: OnceLock<Option<usize>> = OnceLock::new();
        *CACHE.get_or_init(|| {
            let gs = gamestate_ptr()?;
            let resolved = gs.wrapping_add(8);
            let hardcoded = super::rebase(super::SAVE_VERSION_GLOBAL);
            let delta = resolved.abs_diff(hardcoded);
            if delta > 0x1000 {
                modforge::log!(
                    "R3 SAVE_VERSION_GLOBAL sanity gate rejected resolved=0x{resolved:x}; \
                     hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x1000"
                );
                return None;
            }
            Some(resolved)
        })
    }

    /// Locate RACES_COUNTER via the adjacent -10.5f float-init
    /// then RACES_COUNTER zero-init pattern. Decomp
    /// (all_functions.c:84919-84920):
    ///
    /// ```c
    /// *(undefined4 *)((longlong)param_1 + 0x10c) = 0xc1280000;  // -10.5f
    /// DAT_1403eded8 = 0;                                         // RACES_COUNTER
    /// ```
    ///
    /// MSVC emits:
    ///   c7 ?? 0c 01 00 00 00 00 28 c1   ; mov dword [reg+0x10c], 0xc1280000  (10b)
    ///   c7 05 dd dd dd dd 00 00 00 00   ; mov dword [rip+disp_RACES], 0      (10b)
    /// 20 bytes total. The float constant `0xc1280000` (= -10.5)
    /// stored at offset 0x10c on a register is rare enough that
    /// combined with the immediately-following RIP-rel zero-store
    /// it uniquely fingerprints this init site.
    fn resolve_races_counter_via_minus_10p5f_anchor() -> Option<usize> {
        use modforge::patterns::sleuth;
        // Anchor: the -10.5f float-init at [reg+0x10c] (10 bytes),
        // followed by `mov [rip+disp32], edi` (6 bytes, the
        // RACES_COUNTER = 0 store; MSVC uses edi which was zeroed
        // earlier rather than the longer `c7 05 ... 00 00 00 00`
        // imm32 encoding), followed by the 0xffffffff-init at
        // [reg+0x250] (10 bytes) which bookends the sequence.
        // 26 bytes total.
        const SIG: &str =
            "c7 ?? 0c 01 00 00 00 00 28 c1 89 3d ?? ?? ?? ?? c7 ?? 50 02 00 00 ff ff ff ff";
        let hits = sleuth::scan_all_matches(SIG).ok()?;
        let mut accepted: Vec<usize> = Vec::new();
        for instr_addr in hits {
            // RACES_COUNTER store (`89 3d`) starts at offset 10.
            // disp32 at offset 12, instr_len 6 (so next_ip is
            // match_start + 16). SAFETY: instr_addr is inside
            // `.text`, mapped.
            let disp = unsafe {
                ((instr_addr + 12) as *const i32).read_unaligned()
            } as isize;
            let target = instr_addr.wrapping_add(16).wrapping_add(disp as usize);
            accepted.push(target);
        }
        accepted.sort_unstable();
        accepted.dedup();
        match accepted.len() {
            0 => {
                modforge::log!("R3 RACES_COUNTER: no anchor match");
                None
            }
            1 => Some(accepted[0]),
            n => {
                modforge::log!("R3 RACES_COUNTER: {n} distinct candidates; sig is ambiguous");
                None
            }
        }
    }

    /// Resolved runtime address of `DEBUG_LOG_GATE` (the
    /// retirement-message printf gate at `DAT_1403d9526`). Cached.
    pub fn debug_log_gate() -> Option<usize> {
        static CACHE: OnceLock<Option<usize>> = OnceLock::new();
        *CACHE.get_or_init(|| {
            let resolved = resolve_debug_log_gate_via_init_triplet()?;
            let hardcoded = super::rebase(super::DEBUG_LOG_GATE);
            let delta = resolved.abs_diff(hardcoded);
            if delta > 0x1000 {
                modforge::log!(
                    "R3 DEBUG_LOG_GATE sanity gate rejected resolved=0x{resolved:x}; \
                     hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x1000"
                );
                return None;
            }
            Some(resolved)
        })
    }

    /// Locate DEBUG_LOG_GATE via the global-init block sequence
    /// `(_DAT_1403d9598 = 0x100; _DAT_1403d95c0 = 0xffffffff;)`.
    ///
    /// Decomp (all_functions.c:70335-70341) writes 8 dword
    /// initializers in order. MSVC emits the 3rd and 4th writes
    /// (`0x100`, then `0xffffffff`) adjacent in `.text`; this pair
    /// is uniquely identifiable by the `(0x100, 0xffffffff)` imm32
    /// sequence. The 5th write (DEBUG_LOG_GATE = 0) is NOT
    /// adjacent in the live image. MSVC reordered it elsewhere.
    /// We recover DEBUG_LOG_GATE by anchoring on the 3rd-write
    /// target and applying the decomp's known relative offset
    /// (`_DAT_1403d9526 - _DAT_1403d9598 = -0x72`), which holds
    /// across the cheat-globals subsystem because all cheat
    /// globals drift uniformly when `.data` is re-laid-out.
    ///
    /// If a future build breaks the relative-offset assumption,
    /// the 0x1000-byte sanity gate against the hardcoded RVA will
    /// reject the result and production falls back to hardcoded.
    fn resolve_debug_log_gate_via_init_triplet() -> Option<usize> {
        use modforge::patterns::sleuth;
        // 3rd-write (0x100) + 4th-write (0xffffffff). disp32 of the
        // 3rd write is at offset 2; the matched 20 bytes are exactly
        // the two adjacent 10-byte instructions, so next_ip of the
        // 3rd write = match_start + 10.
        const SIG: &str =
            "c7 05 ?? ?? ?? ?? 00 01 00 00 c7 05 ?? ?? ?? ?? ff ff ff ff";
        // Decomp-derived relative offset from DAT_1403d9598 (3rd
        // write target) to DAT_1403d9526 (DEBUG_LOG_GATE):
        //   0x1403d9526 - 0x1403d9598 = -0x72
        const REL_OFFSET_FROM_DAT9598: isize = -0x72;

        let hits = sleuth::scan_all_matches(SIG).ok()?;
        let mut accepted: Vec<usize> = Vec::new();
        for instr_addr in hits {
            // SAFETY: instr_addr is inside `.text`, mapped.
            let disp1 = unsafe {
                ((instr_addr + 2) as *const i32).read_unaligned()
            } as isize;
            // CPU effective of the 3rd write = (instr_addr + 10) + disp1.
            let third_write_target = instr_addr.wrapping_add(10).wrapping_add(disp1 as usize);
            let debug_log_gate = third_write_target.wrapping_add(REL_OFFSET_FROM_DAT9598 as usize);
            accepted.push(debug_log_gate);
        }
        accepted.sort_unstable();
        accepted.dedup();
        match accepted.len() {
            0 => {
                modforge::log!(
                    "R3 DEBUG_LOG_GATE: init-triplet sig found no matches"
                );
                None
            }
            1 => Some(accepted[0]),
            n => {
                modforge::log!(
                    "R3 DEBUG_LOG_GATE: {n} distinct candidates; sig is ambiguous"
                );
                None
            }
        }
    }

    /// Wrapper around `resolve_via` that gates the result against
    /// the hardcoded RVA. If the resolved address drifts more than
    /// 0x1000 bytes from the rebased hardcoded location, the
    /// signature almost certainly matched a different `.data`
    /// global; reject and let the caller fall back to the
    /// hardcoded value. The 0x1000 bound is the size of a typical
    /// `.data` neighbourhood for a single subsystem's flags in
    /// Horsey.exe; addresses inside that band are plausibly the
    /// real target, addresses outside it are not.
    ///
    /// As R3 batch 1 sigs get refined (or replaced via xref-derived
    /// patterns) and the resolver consistently agrees with the
    /// hardcoded RVA in tests, this gate can be relaxed. Until
    /// then it protects the cheat-menu toggles from writing to the
    /// wrong byte.
    fn resolve_data_global(
        candidates: &[Candidate],
        hardcoded_rva: usize,
    ) -> Option<usize> {
        let resolved = resolve_via(candidates)?;
        let hardcoded = super::rebase(hardcoded_rva);
        let delta = resolved.abs_diff(hardcoded);
        if delta > 0x1000 {
            modforge::log!(
                "R3 sanity gate rejected resolved=0x{resolved:x}; \
                 hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x1000"
            );
            return None;
        }
        Some(resolved)
    }

    /// `DAT_1403d95c5 = DAT_1403d95c5 == '\0';` (toggle pattern in
    /// the cheat-menu button handler). MSVC compiles this to:
    ///   cmp  byte ptr [rip+disp1], 0   ; 80 3D dd1 dd1 dd1 dd1 00
    ///   sete byte ptr [rip+disp2]      ; 0F 94 05 dd2 dd2 dd2 dd2
    /// Both disp1 and disp2 resolve to NO_TIRE_TOGGLE (same byte
    /// being tested + written). Total 14 bytes. The combination of
    /// `cmp imm=0` then `sete` directly to memory at a RIP-rel
    /// address is rare; constraining the two disp32s to the same
    /// target locks it to NO_TIRE_TOGGLE empirically.
    /// Bytes verified from the live image (forensic scan 2026-05-15):
    /// instr at 0x7ff7517b6add reads `80 3d c1 2a 37 00 00 0f 94 05
    /// ba 2a 37 00` decoding to slot 0x7ff751b295a5.
    const CANDIDATES_NO_TIRE_TOGGLE: &[Candidate] = &[
        Candidate {
            name: "no_tire_toggle_cmp_sete_to_same_byte",
            sig: "80 3d ?? ?? ?? ?? 00 0f 94 05 ?? ?? ?? ??",
            disp32_offset: 2,
            instr_len: 7,
            inline_offset: 0,
            // disp32_2 at offset 10, its next_ip at offset 14 (end
            // of the sete-mem instruction). Same target as disp32_1.
            validate_disp32: Some((10, 14)),
        },
    ];

    /// DEBUG_MODE_ACTIVE is resolved by
    /// `resolve_debug_mode_active_via_unlock_block` (below) rather
    /// than the generic Candidate framework: the discriminator is
    /// a non-zero delta between two disp32s in the same matched
    /// pattern (target1 - target2 == 0x79), which the Candidate
    /// validate_disp32 only supports for delta == 0.
    #[allow(dead_code)]
    const CANDIDATES_DEBUG_MODE_ACTIVE: &[Candidate] = &[];

    /// DEBUG_LOG_GATE init block (all_functions.c:70335-70341):
    ///
    /// ```c
    /// DAT_1403d9590 = 0xffffffff;   //  1st: c7 05 dd dd dd dd ff ff ff ff
    /// DAT_1403d9594 = 0;            //  2nd: c7 05 dd dd dd dd 00 00 00 00
    /// _DAT_1403d9598 = 0x100;       //  3rd: c7 05 dd dd dd dd 00 01 00 00
    /// _DAT_1403d95c0 = 0xffffffff;  //  4th: c7 05 dd dd dd dd ff ff ff ff
    /// _DAT_1403d9526 = 0;           //  5th: c7 05 dd dd dd dd 00 00 00 00 <- DEBUG_LOG_GATE
    /// ```
    ///
    /// Anchor on the 3rd->4th->5th triplet:
    ///   imm32 = 0x100         (3rd)
    ///   imm32 = 0xffffffff    (4th)
    ///   imm32 = 0             (5th, DEBUG_LOG_GATE init)
    ///
    /// Total 30 bytes. The 5th instruction's disp32 starts at
    /// offset 22 in the match; its instruction body is 10 bytes
    /// (offset 20..30), so next_ip = match_start + 30.
    ///
    /// Why this triplet uniquely matches: the `(0x100, 0xffffffff,
    /// 0)` imm32 sequence is rare in `.text`. The pair
    /// `(0xffffffff, 0)` alone appears elsewhere (e.g. positions
    /// 1-2 of this same init block), but preceded by `0x100` it
    /// pins to positions 3-4-5.
    /// Kept as documentation only; the actual resolver is
    /// `resolve_debug_log_gate_via_init_triplet` below (the 5th
    /// write isn't adjacent to the 4th in the live image, so this
    /// 30-byte triplet would need to span MSVC's reordered output;
    /// the bespoke resolver anchors on the 3rd-write target and
    /// applies the decomp-derived relative offset).
    #[allow(dead_code)]
    const CANDIDATES_DEBUG_LOG_GATE: &[Candidate] = &[];

    /// Generic resolver: try each candidate signature in order.
    /// Cross-validates when multiple candidates resolve and warns on
    /// disagreement.
    fn resolve_via(candidates: &[Candidate]) -> Option<usize> {
        let targets: Vec<Target<'_>> = candidates
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
        let mut last: Option<usize> = None;
        for c in candidates {
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
            // Optional second-disp32 self-validation: when the
            // candidate pattern references the same target twice
            // (e.g. cmp [x],0; mov [x],al), both disp32 must decode
            // to the same address. Catches false positives where the
            // opcode shape matches but the operand is some other
            // global.
            if let Some((off2, next_ip2_off)) = c.validate_disp32 {
                // SAFETY: same rationale as above; offsets are
                // inside the matched instruction window.
                let disp2 = unsafe {
                    ((instr_addr + off2) as *const i32).read_unaligned()
                } as isize;
                let next_ip2 = instr_addr.wrapping_add(next_ip2_off);
                let ref2 = next_ip2.wrapping_add(disp2 as usize);
                if ref2 != referenced {
                    modforge::log!(
                        "R3 {} validate_disp32 mismatch: ref1=0x{referenced:x} ref2=0x{ref2:x}",
                        c.name
                    );
                    continue;
                }
            }
            let base = referenced - c.inline_offset;
            modforge::log!(
                "R3 candidate {name}: instr=0x{instr_addr:x} disp32={disp32:#x} \
                 referenced=0x{referenced:x} base=0x{base:x}",
                name = c.name,
            );
            if let Some(prev) = last {
                if prev != base {
                    modforge::log!(
                        "R3 WARN candidate {} disagrees: prev=0x{prev:x} new=0x{base:x}",
                        c.name
                    );
                }
            }
            last = Some(base);
        }
        last
    }

    fn resolve_gamestate_ptr_uncached() -> Option<usize> {
        let resolved = resolve_gamestate_ptr_via_constructor()?;
        // Sanity gate: hardcoded RVA is the cross-check. The resolver
        // can drift with the binary; if the new resolved address is
        // wildly far from where we expect the slot to live, something
        // matched the wrong instruction and we should fall back.
        let hardcoded = super::rebase(super::GAMESTATE_PTR);
        let delta = resolved.abs_diff(hardcoded);
        if delta > 0x1000 {
            modforge::log!(
                "R3 GAMESTATE_PTR sanity gate rejected resolved=0x{resolved:x}; \
                 hardcoded=0x{hardcoded:x}; delta=0x{delta:x} > 0x1000"
            );
            return None;
        }
        Some(resolved)
    }

    /// Recover GAMESTATE_PTR by anchoring on a distinctive
    /// instruction inside the GameState constructor `FUN_1400fd580`
    /// and decoding the disp32 of the RIP-relative slot store within
    /// the same function body.
    ///
    /// Decomp evidence (`horsey-mod/research/decompiled/funcs/1400f/1400fd580_FUN_1400fd580.c`):
    ///
    /// ```c
    /// // line 86: store the freshly-constructed object into the slot
    /// DAT_1403fb0d8 = param_1;
    /// // ... a handful of field zero-inits ...
    /// // line 96: write the magic 1.0f constant at offset 0x114
    /// *(undefined4 *)((longlong)param_1 + 0x114) = 0x3f800000;
    /// ```
    ///
    /// The 1.0f-at-+0x114 write is a uniquely identifying byte
    /// sequence (literal `00 00 80 3F` immediate + the disp32 `0x114`
    /// inside a `mov dword [reg+disp32], imm32` encoding). It marks
    /// the GameState constructor's body.
    ///
    /// The DAT_1403fb0d8 store is the only RIP-relative `mov [rip+
    /// disp32], reg` (qword-store) inside this function. We find it
    /// by enumerating the 14 ModR/M variants of that opcode and
    /// keeping the unique match within ~600 bytes preceding the
    /// 1.0f anchor.
    ///
    /// Same shape as HorseyLiveTweaks' `kPatWorldRootStore`
    /// (`scene_resolver.cpp:11`): store-site anchor + RIP-relative
    /// disp32 decode. The difference is that we use a separate
    /// scan rather than a single pattern, because the constructor's
    /// distance between the slot store and the next distinctive
    /// instruction is too variable to encode as fixed wildcards.
    fn resolve_gamestate_ptr_via_constructor() -> Option<usize> {
        use modforge::patterns::sleuth;

        // Anchor: literal `mov dword [reg+0x114], 0x3f800000`.
        // Encoding: `[REX.B?] C7 <ModR/M> 14 01 00 00 00 00 80 3F`.
        // Two variants for low (rax..rdi, no REX.B) vs high
        // (r8..r15, REX.B = 0x41).
        let anchor_low = sleuth::scan_all_matches(
            "C7 ?? 14 01 00 00 00 00 80 3F",
        ).ok().unwrap_or_default();
        let anchor_high = sleuth::scan_all_matches(
            "41 C7 ?? 14 01 00 00 00 00 80 3F",
        ).ok().unwrap_or_default();
        let mut anchors: Vec<usize> = Vec::new();
        anchors.extend(anchor_low);
        anchors.extend(anchor_high);
        anchors.sort_unstable();
        anchors.dedup();
        if anchors.is_empty() {
            modforge::log!(
                "R3 GAMESTATE_PTR: no anchor match for 1.0f@+0x114 in any reg variant"
            );
            return None;
        }
        if anchors.len() > 1 {
            modforge::log!(
                "R3 GAMESTATE_PTR: {} anchor matches for 1.0f@+0x114; \
                 will try each until exactly one produces a unique slot store",
                anchors.len()
            );
        }

        // Slot-store candidates: `mov [rip+disp32], reg` for the 7
        // low regs (no REX.B, prefix 0x48) plus 7 high regs (REX.B,
        // prefix 0x4C). rsp/r12 are skipped (their ModR/M encoding
        // requires a SIB byte, and MSVC never keeps `this`-like
        // values in rsp anyway).
        const STORE_SIGS_LOW: &[&str] = &[
            // mov [rip+disp32], rax
            "48 89 05 ?? ?? ?? ??",
            // mov [rip+disp32], rcx
            "48 89 0D ?? ?? ?? ??",
            // mov [rip+disp32], rdx
            "48 89 15 ?? ?? ?? ??",
            // mov [rip+disp32], rbx
            "48 89 1D ?? ?? ?? ??",
            // mov [rip+disp32], rbp
            "48 89 2D ?? ?? ?? ??",
            // mov [rip+disp32], rsi
            "48 89 35 ?? ?? ?? ??",
            // mov [rip+disp32], rdi
            "48 89 3D ?? ?? ?? ??",
        ];
        const STORE_SIGS_HIGH: &[&str] = &[
            // mov [rip+disp32], r8
            "4C 89 05 ?? ?? ?? ??",
            // mov [rip+disp32], r9
            "4C 89 0D ?? ?? ?? ??",
            // mov [rip+disp32], r10
            "4C 89 15 ?? ?? ?? ??",
            // mov [rip+disp32], r11
            "4C 89 1D ?? ?? ?? ??",
            // mov [rip+disp32], r13
            "4C 89 2D ?? ?? ?? ??",
            // mov [rip+disp32], r14
            "4C 89 35 ?? ?? ?? ??",
            // mov [rip+disp32], r15
            "4C 89 3D ?? ?? ?? ??",
        ];

        let mut all_stores: Vec<usize> = Vec::new();
        for sig in STORE_SIGS_LOW.iter().chain(STORE_SIGS_HIGH.iter()) {
            if let Ok(hits) = sleuth::scan_all_matches(sig) {
                all_stores.extend(hits);
            }
        }
        all_stores.sort_unstable();
        all_stores.dedup();
        if all_stores.is_empty() {
            modforge::log!("R3 GAMESTATE_PTR: zero RIP-rel qword stores in .text (impossible)");
            return None;
        }

        // For each anchor, count slot-stores in the 600-byte window
        // preceding it. The right anchor has exactly one. Decomp
        // shows the DAT store ~5 field-zeros before the 1.0f store,
        // so 600 is generous even after MSVC's SSE batching.
        //
        // The "exactly one" requirement is the discriminator: a
        // false anchor in some other function might have zero or
        // many candidate stores in its preceding window.
        const WINDOW: usize = 600;
        for &anchor in &anchors {
            let lo = anchor.saturating_sub(WINDOW);
            let preceding: Vec<usize> = all_stores
                .iter()
                .copied()
                .filter(|&s| s >= lo && s < anchor)
                .collect();
            if preceding.len() == 1 {
                let store_addr = preceding[0];
                // Decode disp32: bytes at offset 3 of the instruction
                // for low regs (48 89 XX d d d d), offset 3 for high
                // regs too (4C 89 XX d d d d). Both 7-byte
                // instructions; next_ip = store_addr + 7.
                //
                // SAFETY: store_addr is inside `.text`, readable.
                let disp32 = unsafe {
                    ((store_addr + 3) as *const i32).read_unaligned()
                } as isize;
                let next_ip = store_addr.wrapping_add(7);
                let slot = next_ip.wrapping_add(disp32 as usize);
                modforge::log!(
                    "R3 GAMESTATE_PTR: anchor=0x{anchor:x} store=0x{store_addr:x} \
                     disp32={disp32:#x} slot=0x{slot:x}"
                );
                return Some(slot);
            }
        }
        modforge::log!(
            "R3 GAMESTATE_PTR: no anchor had exactly one preceding qword-store within {WINDOW} bytes"
        );
        None
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
pub fn find_text_section() -> Option<(usize, usize)> {
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
