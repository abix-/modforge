// C-ABI surface exposed to the C++ shim's ImGui render lambda.
//
// The lambda runs on UE4SS's render thread. It calls these functions to
// read tracker state and to spend skill points. Each function is small,
// returns POD types, and never panics (catch_unwind around the body).
//
// String returns use a caller-provided buffer to avoid heap-shared
// allocations. Integer-returning functions report "no slot active" or
// "skill not found" through a sentinel value, documented per function.

use std::ffi::{CStr, c_char};
use std::sync::Mutex;

use crate::rpg::skills::{self, Skill};
use crate::rpg::state::PlayerState;
use crate::rpg::tracker;
use crate::rpg::xp;

fn safe<F: FnOnce() -> R + std::panic::UnwindSafe, R: Default>(f: F) -> R {
    std::panic::catch_unwind(f).unwrap_or_default()
}

/// 1 if a save slot is currently active, 0 otherwise.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_has_active_slot() -> i32 {
    safe(|| if tracker::current_slot().is_some() { 1 } else { 0 })
}

/// Returns current level, 0 if no slot active.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_get_level() -> u32 {
    safe(|| tracker::with_state(|s| s.level).unwrap_or(0))
}

/// Cumulative XP earned, 0 if no slot active.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_get_xp() -> u64 {
    safe(|| tracker::with_state(|s| s.xp).unwrap_or(0))
}

/// XP required to reach the player's current level.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_get_xp_for_current_level() -> u64 {
    safe(|| tracker::with_state(|s| xp::cumulative_xp_for_level(s.level)).unwrap_or(0))
}

/// XP required to reach the next level (level + 1). Returns 0 once at
/// the level cap.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_get_xp_for_next_level() -> u64 {
    safe(|| {
        tracker::with_state(|s| {
            if s.level >= xp::MAX_LEVEL {
                0
            } else {
                xp::cumulative_xp_for_level(s.level + 1)
            }
        })
        .unwrap_or(0)
    })
}

/// Unspent skill points, 0 if no slot active.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_get_skill_points() -> u32 {
    safe(|| tracker::with_state(|s| s.skill_points).unwrap_or(0))
}

/// Number of skills in the catalog.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_get_skill_count() -> u32 {
    skills::CATALOG.len() as u32
}

/// Look up the skill at `index` in the catalog. On success writes the
/// skill's id and display name into the caller's buffers (NUL
/// terminated, truncated if too small) and writes current level and
/// max level to the out_* pointers. Returns 1 on success, 0 if index
/// is out of range or no slot active.
///
/// All pointers may be null on the C side; we only write non-null
/// outputs.
///
/// # Safety
/// Caller must ensure id_buf has space for `id_buf_len` bytes (same
/// for name_buf), and out_level / out_max are valid u32* if non-null.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn bbp_rpg_get_skill(
    index: u32,
    id_buf: *mut c_char,
    id_buf_len: usize,
    name_buf: *mut c_char,
    name_buf_len: usize,
    out_level: *mut u32,
    out_max: *mut u32,
) -> i32 {
    safe(|| {
        let Some(skill) = skills::CATALOG.get(index as usize) else {
            return 0;
        };
        unsafe {
            write_cstr(id_buf, id_buf_len, skill.id);
            write_cstr(name_buf, name_buf_len, skill.display_name);
            if !out_max.is_null() {
                out_max.write_unaligned(skill.max_level);
            }
            if !out_level.is_null() {
                let level = tracker::with_state(|s| {
                    s.skill_levels.get(skill.id).copied().unwrap_or(0)
                })
                .unwrap_or(0);
                out_level.write_unaligned(level);
            }
        }
        1
    })
}

/// Spend one skill point on the skill identified by the NUL-terminated
/// `skill_id` C-string. Returns 1 on success, 0 if the spend was
/// invalid (no slot, no points, unknown skill, or level already at
/// max).
///
/// On success: increments the level, decrements skill_points, runs the
/// apply step so the new value takes effect immediately, and saves to
/// disk.
///
/// # Safety
/// `skill_id` must be a valid NUL-terminated UTF-8 C string.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn bbp_rpg_spend(skill_id: *const c_char) -> i32 {
    safe(|| {
        if skill_id.is_null() {
            return 0;
        }
        let cstr = unsafe { CStr::from_ptr(skill_id) };
        let Ok(id) = cstr.to_str() else { return 0 };
        let Some(skill) = skills::lookup(id) else {
            return 0;
        };
        if tracker::spend_skill_point(skill) { 1 } else { 0 }
    })
}

/// Spend up to `count` skill points on the skill identified by the
/// NUL-terminated `skill_id` C-string. Returns the number of points
/// actually spent.
///
/// # Safety
/// `skill_id` must be a valid NUL-terminated UTF-8 C string.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn bbp_rpg_spend_many(skill_id: *const c_char, count: u32) -> u32 {
    safe(|| {
        if skill_id.is_null() || count == 0 {
            return 0;
        }
        let cstr = unsafe { CStr::from_ptr(skill_id) };
        let Ok(id) = cstr.to_str() else { return 0 };
        let Some(skill) = skills::lookup(id) else {
            return 0;
        };
        tracker::spend_skill_points(skill, count)
    })
}

/// Debug: grant `count` extra skill points immediately. Used by the
/// debug button in the ImGui tab so combat skills can be tested
/// without grinding XP. Returns 1 on success, 0 if no slot active.
#[unsafe(no_mangle)]
pub extern "C" fn bbp_rpg_debug_grant_skill_points(count: u32) -> i32 {
    safe(|| if tracker::debug_grant_skill_points(count) { 1 } else { 0 })
}

/// Format the skill's effect at `level` into the caller's buffer.
/// Returns 1 on success, 0 if skill_id is unknown. Used by the ImGui
/// tab to show "+25 slots" etc. next to the level number.
///
/// # Safety
/// `skill_id` must be a valid NUL-terminated UTF-8 C string. `out_buf`
/// must have space for `out_buf_len` bytes.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn bbp_rpg_format_skill_effect(
    skill_id: *const c_char,
    level: u32,
    out_buf: *mut c_char,
    out_buf_len: usize,
) -> i32 {
    safe(|| {
        if skill_id.is_null() {
            return 0;
        }
        let cstr = unsafe { CStr::from_ptr(skill_id) };
        let Ok(id) = cstr.to_str() else { return 0 };
        if skills::lookup(id).is_none() {
            return 0;
        }
        let s = skills::format_effect(id, level);
        unsafe { write_cstr(out_buf, out_buf_len, &s) };
        1
    })
}

unsafe fn write_cstr(buf: *mut c_char, buf_len: usize, src: &str) {
    if buf.is_null() || buf_len == 0 {
        return;
    }
    let bytes = src.as_bytes();
    let copy_len = bytes.len().min(buf_len.saturating_sub(1));
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), buf as *mut u8, copy_len);
        *buf.add(copy_len) = 0;
    }
}

// Suppress unused warnings until the shim references these.
#[allow(dead_code)]
fn _force_use(_: &PlayerState, _: &Skill) {}

// Re-export the Mutex<Option<Tracker>> indirection: tracker exposes
// helper APIs that wrap state access. (Mutex import is here because
// tracker's helpers will be added via `tracker.rs` extension in a
// follow-up edit.)
#[allow(dead_code)]
fn _silence_mutex(_: &Mutex<()>) {}
