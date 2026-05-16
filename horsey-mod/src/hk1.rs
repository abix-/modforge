//! HK1 transfer experiment plumbing.
//!
//! Backs the per-horse "Send to Truck / Pasture" overlay buttons and a
//! file logger so the operator can verify in-game behavior without
//! restarting the game between attempts.
//!
//! Hypothesis being tested:
//!   horse_ptr + 0x1d0 (u32) = container kind
//!     7 = truck, 9 = pasture (observed; other values unknown)
//!   horse_ptr + 0x1dc (u32) = sub-state / slot index inside container
//!
//! Both fields are written without any vtable / animation side-effects
//! today. The point is to see how the game's render path reacts.

use std::fs::OpenOptions;
use std::io::Write;
use std::path::PathBuf;
use std::sync::Mutex;
use std::time::{SystemTime, UNIX_EPOCH};

pub const OFF_CONTAINER_KIND: usize = 0x1d0;
pub const OFF_CONTAINER_SUB:  usize = 0x1dc;

/// Named container kinds observed so far. Add as we learn them.
pub const KIND_TRUCK:   u32 = 7;
pub const KIND_PASTURE: u32 = 9;

fn log_path() -> Option<PathBuf> {
    modforge::log::dll_dir().map(|d| d.join("hk1_overlay.log"))
}

static LOG_LOCK: Mutex<()> = Mutex::new(());

/// Append one line to `<dll_dir>/hk1_overlay.log`. Best-effort; silently
/// drops on IO error so the UI never panics.
pub fn log_line(s: &str) {
    let Some(path) = log_path() else { return };
    let _g = LOG_LOCK.lock().ok();
    let ts = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_secs())
        .unwrap_or(0);
    if let Ok(mut f) = OpenOptions::new().create(true).append(true).open(&path) {
        let _ = writeln!(f, "[{ts}] {s}");
    }
}

/// Read the (kind, sub) pair at `+0x1d0` / `+0x1dc` for a horse.
/// Returns `None` if the address range isn't readable.
pub fn read_container(horse_ptr: usize) -> Option<(u32, u32)> {
    let addr_kind = horse_ptr + OFF_CONTAINER_KIND;
    let addr_sub = horse_ptr + OFF_CONTAINER_SUB;
    if !modforge::winproc::is_addr_readable(addr_sub + 3) {
        return None;
    }
    // SAFETY: end-of-range checked above; both u32 reads land in the
    // same Horse allocation.
    let kind = unsafe { (addr_kind as *const u32).read_unaligned() };
    let sub = unsafe { (addr_sub as *const u32).read_unaligned() };
    Some((kind, sub))
}

/// Write `value` at `horse + 0x1d0`. Logs the before / after to the
/// overlay log file. Returns true if the write happened.
pub fn write_kind(horse_ptr: usize, value: u32, label: &str) -> bool {
    let addr = horse_ptr + OFF_CONTAINER_KIND;
    if !modforge::winproc::is_addr_readable(addr + 3) {
        log_line(&format!("write_kind FAIL horse=0x{horse_ptr:x} addr=0x{addr:x} unreadable"));
        return false;
    }
    let before = read_container(horse_ptr);
    // SAFETY: addr+3 readability checked; write lands in the Horse alloc.
    unsafe { (addr as *mut u32).write_unaligned(value); }
    let after = read_container(horse_ptr);
    log_line(&format!(
        "write_kind label='{label}' horse=0x{horse_ptr:x} wrote=+0x1d0={value} \
         before={before:?} after={after:?}"
    ));
    true
}
