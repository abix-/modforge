//! Typed accessors for the global GameState struct at
//! `DAT_1403fb0d8`. All offsets sourced from
//! `decompiled/annotated/0x14006dc80_save_game_writer.c` and our
//! decompilation of the cheat-menu / save-file paths.
//!
//! Safety:
//! - The game's main thread mutates GameState constantly. Reads
//!   from our HTTP worker are NOT synchronized with the game's
//!   per-frame update. For atomic-sized fields (uint32 etc.) the
//!   read sees a single coherent value; for multi-field
//!   structures (e.g. the 6-supply array) a snapshot may capture
//!   mid-update state. That's acceptable for the control-plane
//!   use case.
//! - Writes from the HTTP worker (e.g. `set_money`) MAY race with
//!   the game's own writes. For cheat-style mutations (money
//!   bump, year jump) the win-by-last-writer outcome is what the
//!   user wants. For state-machine mutations, we'll queue them
//!   onto the main thread later via a worker-queue (see ueforge's
//!   pe_queue.rs for the pattern).

use crate::targets::{self, gs_offset};

/// Resolve the runtime address of the GameState struct.
///
/// CRITICAL CORRECTION (2026-05-14): The slot at `GAMESTATE_PTR`
/// (0x1403fb0d8) is NOT a pointer-to-struct. It IS the struct,
/// embedded in the game's `.data` segment. The decomp evidence
/// (e.g. cheat-money handler `*(int *)(DAT_1403fb0d8 + 0x308) += 1000`)
/// does direct offset arithmetic with no double-deref. We were
/// double-dereferencing and reading whatever the first 8 bytes of
/// the struct happened to be. Usually zero (so `ptr() == 0`
/// guards held and other code paths short-circuited), but on a
/// freshly-launched game with the game in main-menu state, the
/// first 8 bytes held the canonical-but-unmapped value
/// 0x2400000000B which crashed every subsequent deref.
///
/// The struct lives in the binary; `rebase(GAMESTATE_PTR)` is its
/// runtime address. Reads from offsets inside the struct are safe
/// as long as the offset is within the struct's allocated size,
/// regardless of whether a save is loaded.
pub fn ptr() -> usize {
    targets::rebase(targets::GAMESTATE_PTR)
}

/// Read a uint32 field from GameState at the given offset.
pub fn read_u32(off: usize) -> Option<u32> {
    let p = ptr();
    if p == 0 {
        return None;
    }
    // SAFETY: GameState is alive for the world's lifetime; reading
    // a uint32 at a known offset is safe as long as `p != 0`.
    Some(unsafe { *((p + off) as *const u32) })
}

/// Write a uint32 field on GameState at the given offset.
pub fn write_u32(off: usize, value: u32) -> bool {
    let p = ptr();
    if p == 0 {
        return false;
    }
    // SAFETY: Same alignment guarantees as read_u32. Concurrent
    // reads/writes by the game thread are tolerated; the worst
    // case is a single torn-write, which the engine recovers from
    // on the next frame.
    unsafe {
        *((p + off) as *mut u32) = value;
    }
    true
}

pub fn read_u8(off: usize) -> Option<u8> {
    let p = ptr();
    if p == 0 {
        return None;
    }
    // SAFETY: same rationale as read_u32; uint8 reads are always atomic.
    Some(unsafe { *((p + off) as *const u8) })
}

pub fn write_u8(off: usize, value: u8) -> bool {
    let p = ptr();
    if p == 0 {
        return false;
    }
    // SAFETY: same rationale as write_u32.
    unsafe {
        *((p + off) as *mut u8) = value;
    }
    true
}

// =============================================================================
// Convenience accessors for documented fields
// =============================================================================

pub fn money() -> Option<u32> {
    read_u32(gs_offset::MONEY)
}
pub fn set_money(value: u32) -> bool {
    write_u32(gs_offset::MONEY, value)
}

pub fn year() -> Option<u32> {
    read_u32(gs_offset::YEAR)
}
pub fn set_year(value: u32) -> bool {
    write_u32(gs_offset::YEAR, value)
}

pub fn sleeps() -> Option<u32> {
    read_u32(gs_offset::SLEEPS)
}

pub fn frame_tick() -> Option<u32> {
    read_u32(gs_offset::FRAME_TICK)
}

// =============================================================================
// Cheat-toggle accessors (operate on dedicated globals, not GameState fields)
// =============================================================================

/// Read the "No Tire" toggle byte (true = tiredness disabled).
pub fn no_tire() -> bool {
    let abs = targets::rebase(targets::NO_TIRE_TOGGLE);
    // SAFETY: NO_TIRE_TOGGLE lives in the .data section of the
    // exe; valid for the process lifetime.
    unsafe { *(abs as *const u8) != 0 }
}

/// Set the "No Tire" toggle byte.
pub fn set_no_tire(enabled: bool) {
    let abs = targets::rebase(targets::NO_TIRE_TOGGLE);
    // SAFETY: Same as above; writing a byte to a .data global.
    unsafe {
        *(abs as *mut u8) = if enabled { 1 } else { 0 };
    }
}

/// Read the debug-mode active flag.
pub fn debug_mode() -> bool {
    let abs = targets::rebase(targets::DEBUG_MODE_ACTIVE);
    // SAFETY: same .data-section global rationale.
    unsafe { *(abs as *const u8) != 0 }
}

/// Forcibly enable / disable debug mode (without making the user
/// type "debug" in the pause menu).
pub fn set_debug_mode(enabled: bool) {
    let abs = targets::rebase(targets::DEBUG_MODE_ACTIVE);
    // SAFETY: same .data-section global rationale.
    unsafe {
        *(abs as *mut u8) = if enabled { 1 } else { 0 };
    }
}

/// Read the races counter (separate global, not in GameState).
pub fn races() -> u32 {
    let abs = targets::rebase(targets::RACES_COUNTER);
    // SAFETY: races counter is a uint32 in .data; always valid.
    unsafe { *(abs as *const u32) }
}

// =============================================================================
// Horse-list walker
// =============================================================================

/// Iterate the horse-roster pointers from GameState.
/// `(end - begin) / 0x24` is the count; each in-memory horse is
/// 0x24 = 36 bytes. The roster is the same one written by
/// `save_game_writer`.
pub fn horse_count() -> usize {
    let p = ptr();
    if p == 0 {
        return 0;
    }
    // SAFETY: begin/end pointers are stable while the world is
    // alive; reading two pointer-sized fields from GameState.
    let begin = unsafe { *((p + gs_offset::HORSES_BEGIN) as *const usize) };
    let end = unsafe { *((p + gs_offset::HORSES_END) as *const usize) };
    if end < begin {
        0
    } else {
        (end - begin) / 0x24
    }
}

/// Get the in-memory horse pointer for index `i`. Returns None if
/// out of range. Note: these are 36-byte ROSTER ENTRIES, not the
/// full live-horse objects (the live objects are pointed to from
/// other lists like `+0x130/+0x138`).
pub fn horse_roster_entry(i: usize) -> Option<usize> {
    let p = ptr();
    if p == 0 {
        return None;
    }
    // SAFETY: begin pointer is stable while world is alive.
    let begin = unsafe { *((p + gs_offset::HORSES_BEGIN) as *const usize) };
    if begin == 0 {
        return None;
    }
    if i >= horse_count() {
        return None;
    }
    Some(begin + i * 0x24)
}

// =============================================================================
// Live-horse pointer list (gamestate + 0x130 / +0x138)
// =============================================================================
//
// The retirement handler iterates `*(longlong *)(param_1 + 0x130)`. Through
// our decompilation pass, `param_1` at that callsite traces back to
// `DAT_1403fb0d8`, the GameState. The list holds 8-byte pointers to the
// full live-Horse objects whose +0x1fc/+0x200/+0x205/+0x206/+0x21c/+0x254
// fields we already model.

/// Live-horse list begin offset on GameState.
const LIVE_HORSES_BEGIN: usize = 0x130;
/// Live-horse list end offset on GameState.
const LIVE_HORSES_END: usize = 0x138;

/// Count of live horse pointers in the gamestate `+0x130..+0x138` list.
pub fn live_horse_count() -> usize {
    let p = ptr();
    if p == 0 {
        return 0;
    }
    // SAFETY: begin/end pointers are stable while the world is alive.
    let begin = unsafe { *((p + LIVE_HORSES_BEGIN) as *const usize) };
    let end = unsafe { *((p + LIVE_HORSES_END) as *const usize) };
    if end < begin {
        0
    } else {
        (end - begin) / 8
    }
}

/// Get the i-th live Horse pointer. Returns None if out of range or
/// the list is empty.
pub fn live_horse_ptr(i: usize) -> Option<usize> {
    let p = ptr();
    if p == 0 {
        return None;
    }
    // SAFETY: begin is a stable pointer; loading 8 bytes at `begin + i*8`
    // is in-bounds when i < count.
    let begin = unsafe { *((p + LIVE_HORSES_BEGIN) as *const usize) };
    if begin == 0 || i >= live_horse_count() {
        return None;
    }
    // SAFETY: read one pointer-sized slot inside the vector.
    Some(unsafe { *((begin + i * 8) as *const usize) })
}
