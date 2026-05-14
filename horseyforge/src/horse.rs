//! Typed accessors for the Horse struct.
//!
//! "Horse pointer" in different parts of the engine means
//! different things:
//! - The roster entry in GameState.+0x280..+0x288 is a 36-byte
//!   record with name + parents + children (we walked this in
//!   `save_edit.py`).
//! - The full live-horse object (with the +0x1fc age, +0x200
//!   max_age, +0x205/+0x206 tiredness flags, etc.) is what
//!   appears in the track-manager's `+0x130/+0x138` list and is
//!   passed around as the typical "horse" argument.
//!
//! This module deals with the LIVE-HORSE pointer. The roster
//! walker lives in `gamestate.rs`.

use crate::targets::horse_offset;

/// Read horse.age (int32).
pub fn age(horse: usize) -> Option<i32> {
    if horse == 0 {
        return None;
    }
    // SAFETY: Caller passes a valid Horse* obtained from one of
    // the engine's horse lists (e.g. via a hook). The horse is
    // alive for the duration of the read.
    Some(unsafe { *((horse + horse_offset::AGE) as *const i32) })
}

/// Write horse.age. Use with care; if the game's per-frame aging
/// tick is running, this is racy.
pub fn set_age(horse: usize, value: i32) -> bool {
    if horse == 0 {
        return false;
    }
    // SAFETY: same alignment & lifetime guarantees as age().
    unsafe {
        *((horse + horse_offset::AGE) as *mut i32) = value;
    }
    true
}

pub fn max_age(horse: usize) -> Option<i32> {
    if horse == 0 {
        return None;
    }
    // SAFETY: same as age().
    Some(unsafe { *((horse + horse_offset::MAX_AGE) as *const i32) })
}

pub fn set_max_age(horse: usize, value: i32) -> bool {
    if horse == 0 {
        return false;
    }
    // SAFETY: same as set_age().
    unsafe {
        *((horse + horse_offset::MAX_AGE) as *mut i32) = value;
    }
    true
}

pub fn skill(horse: usize) -> Option<i32> {
    if horse == 0 {
        return None;
    }
    // SAFETY: same as age().
    Some(unsafe { *((horse + horse_offset::SKILL) as *const i32) })
}

pub fn set_skill(horse: usize, value: i32) -> bool {
    if horse == 0 {
        return false;
    }
    // SAFETY: same as set_age().
    unsafe {
        *((horse + horse_offset::SKILL) as *mut i32) = value;
    }
    true
}

pub fn tired_a(horse: usize) -> Option<u8> {
    if horse == 0 {
        return None;
    }
    // SAFETY: byte read at known offset; horse is alive.
    Some(unsafe { *((horse + horse_offset::TIRED_FLAG_A) as *const u8) })
}

pub fn tired_b(horse: usize) -> Option<u8> {
    if horse == 0 {
        return None;
    }
    // SAFETY: same as tired_a.
    Some(unsafe { *((horse + horse_offset::TIRED_FLAG_B) as *const u8) })
}

/// Force-clear tiredness on this horse. Note: if Yes Tire mode is
/// on, the engine clears these every frame anyway.
pub fn clear_tiredness(horse: usize) -> bool {
    if horse == 0 {
        return false;
    }
    // SAFETY: same as set_age(); writes two bytes on a known struct.
    unsafe {
        *((horse + horse_offset::TIRED_FLAG_A) as *mut u8) = 0;
        *((horse + horse_offset::TIRED_FLAG_B) as *mut u8) = 0;
    }
    true
}

pub fn species(horse: usize) -> Option<i32> {
    if horse == 0 {
        return None;
    }
    // SAFETY: int32 read at +0x1c.
    Some(unsafe { *((horse + horse_offset::TYPE_OR_SPECIES) as *const i32) })
}

pub fn name_id(horse: usize) -> Option<u32> {
    if horse == 0 {
        return None;
    }
    // SAFETY: uint32 read at +0x1f8.
    Some(unsafe { *((horse + horse_offset::NAME_ID) as *const u32) })
}

pub fn litter_stat(horse: usize) -> Option<i32> {
    if horse == 0 {
        return None;
    }
    // SAFETY: int32 read at +0x254.
    Some(unsafe { *((horse + horse_offset::LITTER_SIZE_STAT) as *const i32) })
}

pub fn set_litter_stat(horse: usize, value: i32) -> bool {
    if horse == 0 {
        return false;
    }
    // SAFETY: int32 write at +0x254.
    unsafe {
        *((horse + horse_offset::LITTER_SIZE_STAT) as *mut i32) = value;
    }
    true
}
