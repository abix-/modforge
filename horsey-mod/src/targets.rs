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

pub mod fn_addr {
    /// `apply_gene_to_horse`. The gene expression function. The
    /// entry point for "construct a horse from its genome". Hook
    /// here to attach extension state to new horses.
    pub const APPLY_GENE_TO_HORSE: usize = 0x14009f680;

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

    /// `save_game_writer`. The save-file writer. Hook to inject
    /// sidecar save data.
    pub const SAVE_WRITER: usize = 0x14006dc80;

    /// `load_game`. The matching loader.
    pub const LOAD_GAME: usize = 0x14006e480;

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
}

/// Resolve the running process's image base. Safe to call from any
/// thread after process init.
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
