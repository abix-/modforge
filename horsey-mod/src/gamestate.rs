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
    // R3: prefer the pattern-scan-resolved address (correct for any
    // build whose decomp still has the cheat-money / race-fee /
    // field_440 sites in `draw_pause_status` / `track_state_machine`).
    // Fall back to the hardcoded RVA so older builds that match the
    // 2026-05-08 decomp keep working. The resolver caches; this is
    // one branch on the hot path.
    if let Some(resolved) = targets::resolve::gamestate_ptr() {
        return resolved;
    }
    targets::rebase(targets::GAMESTATE_PTR)
}

/// Heuristic: is a save actually loaded?
///
/// `ptr()` is always non-zero (the GameState struct is statically
/// embedded in `.data`), so a presence check is meaningless. Instead
/// we read the roster vector at `+0x280/+0x288`:
///
///   - Both pointers must be non-null and within a plausible heap
///     range (`begin >= 0x10000`).
///   - `end >= begin` (sane vector ordering).
///   - `end - begin` must be a multiple of 0x24 (the roster entry
///     stride) and yield a count under a sanity bound.
///
/// When no save is loaded, these slots usually hold null or leftover
/// values from a prior session and one of the checks fails. When a
/// save IS loaded, vanilla writes a real `std::vector<HorseEntry>`
/// span into them and every check passes. Empirically reliable; if
/// the game ever ships a build where the roster sits empty mid-load,
/// the UI just shows "no save loaded" for that frame instead of
/// garbage values.
///
/// Used by `snapshot::HorseyState::world_loaded` and by the in-game
/// UI's loaded-vs-menu gate.
pub fn looks_loaded() -> bool {
    let p = ptr();
    if p == 0 {
        return false;
    }
    // SAFETY: GameState struct is statically embedded and always
    // mapped; reading two pointer-sized fields at known offsets is
    // safe regardless of whether a save is loaded. We never deref
    // begin/end here, just inspect their numeric values.
    let begin = unsafe { *((p + gs_offset::HORSES_BEGIN) as *const usize) };
    let end = unsafe { *((p + gs_offset::HORSES_END) as *const usize) };
    roster_span_looks_loaded(begin, end)
}

/// Forensic dump of every value the loaded-save heuristic touches.
/// Returned as JSON so tests can capture + diff across game states
/// (main menu vs. in-save) without re-implementing pointer reads.
pub fn diag() -> serde_json::Value {
    let p = ptr();
    if p == 0 {
        return serde_json::json!({"ptr": "0x0"});
    }
    // SAFETY: GameState is statically embedded; offsets are within
    // its allocated range. We never deref the read pointers.
    let roster_begin = unsafe { *((p + gs_offset::HORSES_BEGIN) as *const usize) };
    let roster_end = unsafe { *((p + gs_offset::HORSES_END) as *const usize) };
    let live_begin = unsafe { *((p + 0x130) as *const usize) };
    let live_end = unsafe { *((p + 0x138) as *const usize) };

    let roster_count = if roster_end >= roster_begin && roster_begin != 0 {
        roster_end.checked_sub(roster_begin).map(|s| s / 0x24)
    } else {
        None
    };
    let live_count = if live_end >= live_begin && live_begin != 0 {
        live_end.checked_sub(live_begin).map(|s| s / 8)
    } else {
        None
    };

    // Dump every documented GameState field at once. When the right
    // "save loaded" signal is unknown, a single in-save run of
    // `gamestate.diag` lets us see which field is non-zero only
    // when the player is actually in a save. The candidate set
    // mirrors `targets::gs_offset` so future drift is obvious.
    let r_u32 = |off: usize| -> u32 {
        // SAFETY: same rationale as the roster reads above. Uses
        // read_unaligned because a few documented offsets (e.g.
        // 0x415) sit on byte boundaries that the underlying field
        // type doesn't require to be u32-aligned.
        unsafe { ((p + off) as *const u32).read_unaligned() }
    };
    let r_u64 = |off: usize| -> u64 {
        // SAFETY: as above; read_unaligned guards against off-stride
        // pointer offsets in the candidate set.
        unsafe { ((p + off) as *const u64).read_unaligned() }
    };

    serde_json::json!({
        "ptr": format!("0x{p:x}"),
        "roster_0x280_0x288": {
            "begin": format!("0x{roster_begin:x}"),
            "end":   format!("0x{roster_end:x}"),
            "span_bytes": roster_end.wrapping_sub(roster_begin),
            "count_if_sane": roster_count,
            "looks_loaded": roster_span_looks_loaded(roster_begin, roster_end),
        },
        "live_0x130_0x138": {
            "begin": format!("0x{live_begin:x}"),
            "end":   format!("0x{live_end:x}"),
            "span_bytes": live_end.wrapping_sub(live_begin),
            "count_if_sane": live_count,
        },
        "fields_u32": {
            "frame_tick_0x254": r_u32(0x254),
            "field_268_0x268":  r_u32(0x268),
            "trailing_278_0x278": r_u32(0x278),
            "trailing_27c_0x27c": r_u32(0x27c),
            "money_0x308":  r_u32(gs_offset::MONEY),
            "year_0x314":   r_u32(gs_offset::YEAR),
            "sleeps_0x318": r_u32(gs_offset::SLEEPS),
            "supplies_start_0x31c": r_u32(gs_offset::SUPPLIES_START),
            "field_37c_0x37c": r_u32(gs_offset::FIELD_37C),
            "field_39c_0x39c": r_u32(gs_offset::FIELD_39C),
            "field_410_0x410": r_u32(gs_offset::FIELD_410),
            "field_414_0x414": r_u32(gs_offset::FIELD_414),
            "field_415_0x415": r_u32(gs_offset::FIELD_415),
            "field_418_0x418": r_u32(gs_offset::FIELD_418),
            "field_41c_0x41c": r_u32(gs_offset::FIELD_41C),
            "field_440_0x440": r_u32(gs_offset::FIELD_440),
        },
        "fields_u64": {
            // Pointers / 8-byte counters that might signal loaded state.
            "ptr_at_0x130": format!("0x{:x}", r_u64(0x130)),
            "ptr_at_0x138": format!("0x{:x}", r_u64(0x138)),
            "ptr_at_0x140": format!("0x{:x}", r_u64(0x140)),
            "ptr_at_0x148": format!("0x{:x}", r_u64(0x148)),
            "ptr_at_0x280": format!("0x{:x}", r_u64(0x280)),
            "ptr_at_0x288": format!("0x{:x}", r_u64(0x288)),
            "ptr_at_0x290": format!("0x{:x}", r_u64(0x290)),
        },
        "globals_u32": {
            "races": races(),
        },
        "verdict_looks_loaded": looks_loaded(),
        // Hex dump of the first 0x4000 bytes of GameState. When the
        // money offset has drifted between builds, grepping this for
        // the on-screen money value finds the new offset in one
        // round-trip.
        "hex_dump_0x000_0x4000": hex_dump(p, 0x4000),
    })
}

fn hex_dump(base: usize, n: usize) -> String {
    let mut out = String::with_capacity(n * 3);
    for i in 0..n {
        // SAFETY: range is within the statically-mapped GameState
        // struct; reads are byte-aligned.
        let b = unsafe { *((base + i) as *const u8) };
        if i > 0 && i % 16 == 0 {
            out.push('\n');
        }
        use std::fmt::Write;
        let _ = write!(out, "{b:02x} ");
    }
    out
}

/// Pure decision: does a `(begin, end)` pair for the roster vector at
/// `+0x280/+0x288` look like a real loaded-save span?
///
/// Extracted from `looks_loaded` so the heuristic itself is unit-
/// testable without needing a live GameState.
#[inline]
pub fn roster_span_looks_loaded(begin: usize, end: usize) -> bool {
    // Both pointers must look like heap addresses; nulls and tiny
    // values are leftover / uninitialized.
    if begin < 0x10000 || end < begin {
        return false;
    }
    let span = end - begin;
    if span % 0x24 != 0 {
        return false;
    }
    let count = span / 0x24;
    // Vanilla save format caps the roster around 256; allow 10x slack
    // for modded saves. Anything bigger is fill-pattern noise.
    count < 2560
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
    let abs = targets::resolve::no_tire_toggle()
        .unwrap_or_else(|| targets::rebase(targets::NO_TIRE_TOGGLE));
    // SAFETY: NO_TIRE_TOGGLE lives in the .data section of the
    // exe; valid for the process lifetime.
    unsafe { *(abs as *const u8) != 0 }
}

/// Set the "No Tire" toggle byte.
pub fn set_no_tire(enabled: bool) {
    let abs = targets::resolve::no_tire_toggle()
        .unwrap_or_else(|| targets::rebase(targets::NO_TIRE_TOGGLE));
    // SAFETY: Same as above; writing a byte to a .data global.
    unsafe {
        *(abs as *mut u8) = if enabled { 1 } else { 0 };
    }
}

/// Read the debug-mode active flag.
pub fn debug_mode() -> bool {
    let abs = targets::resolve::debug_mode_active()
        .unwrap_or_else(|| targets::rebase(targets::DEBUG_MODE_ACTIVE));
    // SAFETY: same .data-section global rationale.
    unsafe { *(abs as *const u8) != 0 }
}

/// Forcibly enable / disable debug mode (without making the user
/// type "debug" in the pause menu).
pub fn set_debug_mode(enabled: bool) {
    let abs = targets::resolve::debug_mode_active()
        .unwrap_or_else(|| targets::rebase(targets::DEBUG_MODE_ACTIVE));
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

#[cfg(test)]
mod tests {
    use super::roster_span_looks_loaded as ok;

    #[test]
    fn null_pointers_are_not_loaded() {
        assert!(!ok(0, 0));
        assert!(!ok(0, 0x1000));
        assert!(!ok(0x1000, 0x2000), "addrs below 0x10000 don't look like heap");
    }

    #[test]
    fn end_before_begin_is_not_loaded() {
        assert!(!ok(0x80000000, 0x70000000));
    }

    #[test]
    fn misaligned_span_is_not_loaded() {
        // span of 0x25 is not divisible by 0x24
        assert!(!ok(0x80000000, 0x80000000 + 0x25));
    }

    #[test]
    fn empty_but_aligned_span_is_loaded() {
        // begin == end, span = 0; 0 % 0x24 == 0; count = 0 < 2560
        assert!(ok(0x80000000, 0x80000000));
    }

    #[test]
    fn typical_save_span_is_loaded() {
        // 32 horses = 32 * 0x24 = 0x480
        assert!(ok(0x80000000, 0x80000000 + 0x480));
    }

    #[test]
    fn implausibly_huge_span_is_not_loaded() {
        // 100k horses worth of stride: pure fill-pattern noise.
        let huge = 100_000 * 0x24;
        assert!(!ok(0x80000000, 0x80000000 + huge));
    }

    #[test]
    fn fill_pattern_pointers_fail() {
        // Reproduce the 2026-05-15 main-menu state: bytes at the
        // roster slots hold a 0x01010101 fill pattern. Both pointers
        // are < 0x10000 -> fails the first gate. Even if they were
        // larger, the span is wildly off-stride.
        let begin = 0x01010101usize;
        let end = 0x02020202usize;
        assert!(!ok(begin, end));
    }
}
