//! In-memory binary patches on code in this process.
//!
//! All patches go through [`patch_bytes`], which takes care of
//! VirtualProtect, byte write, and protection restore. Original
//! bytes are saved in [`APPLIED`] so [`revert_all`] puts them back.
//! Moved here from horsey-mod so every game mod shares one
//! implementation.

use parking_lot::Mutex;
use windows_sys::Win32::System::Memory::{
    PAGE_EXECUTE_READWRITE, PAGE_PROTECTION_FLAGS, VirtualProtect,
};

/// Record of one applied patch.
#[derive(Clone)]
struct Patch {
    /// Symbolic name for diagnostics.
    name: &'static str,
    /// Runtime address.
    addr: usize,
    /// Original bytes overwritten by the patch.
    original: Vec<u8>,
}

static APPLIED: Mutex<Vec<Patch>> = Mutex::new(Vec::new());

/// Write `new_bytes` at `addr`, recording the originals for revert.
/// `addr` must be inside a module loaded in this process.
pub fn patch_bytes(name: &'static str, addr: usize, new_bytes: &[u8]) -> anyhow::Result<()> {
    let len = new_bytes.len();
    // SAFETY: We trust the caller to pass a valid in-process address.
    // The slice points to code-segment memory; VirtualProtect below
    // makes the page writable, we copy, then we restore.
    let view = unsafe { std::slice::from_raw_parts(addr as *const u8, len) };
    let original: Vec<u8> = view.to_vec();

    let mut old_protect: PAGE_PROTECTION_FLAGS = 0;
    // SAFETY: addr+len is in our own process; VirtualProtect on our
    // own image's code pages is always safe.
    let ok = unsafe {
        VirtualProtect(
            addr as *mut _,
            len,
            PAGE_EXECUTE_READWRITE,
            &mut old_protect,
        )
    };
    if ok == 0 {
        anyhow::bail!("VirtualProtect RW failed at 0x{addr:x}");
    }

    // SAFETY: page is RW; write within bounds; we own the slice.
    unsafe {
        std::ptr::copy_nonoverlapping(new_bytes.as_ptr(), addr as *mut u8, len);
    }

    // Restore original protection.
    let mut tmp: PAGE_PROTECTION_FLAGS = 0;
    // SAFETY: same address + length as the prior VirtualProtect call.
    unsafe { VirtualProtect(addr as *mut _, len, old_protect, &mut tmp) };

    // Flush instruction cache. On x64 this is a no-op for correctness
    // (the CPU coheres icache with stores) but we call it for
    // form and forward-compat.
    // SAFETY: Win32 API call with valid handle and address.
    unsafe {
        let h_proc = windows_sys::Win32::System::Threading::GetCurrentProcess();
        windows_sys::Win32::System::Diagnostics::Debug::FlushInstructionCache(
            h_proc,
            addr as *const _,
            len,
        );
    }

    APPLIED.lock().push(Patch {
        name,
        addr,
        original,
    });
    crate::log!(
        "patch[{name}]: applied at 0x{addr:x} ({} bytes)",
        new_bytes.len()
    );
    Ok(())
}

/// Revert every applied patch, most recent first.
pub fn revert_all() {
    let mut g = APPLIED.lock();
    while let Some(p) = g.pop() {
        let len = p.original.len();
        let mut old_protect: PAGE_PROTECTION_FLAGS = 0;
        // SAFETY: addr was a valid in-process code page when applied.
        unsafe {
            VirtualProtect(
                p.addr as *mut _,
                len,
                PAGE_EXECUTE_READWRITE,
                &mut old_protect,
            );
            std::ptr::copy_nonoverlapping(p.original.as_ptr(), p.addr as *mut u8, len);
            let mut tmp: PAGE_PROTECTION_FLAGS = 0;
            VirtualProtect(p.addr as *mut _, len, old_protect, &mut tmp);
        }
        crate::log!("patch[{}]: reverted at 0x{:x}", p.name, p.addr);
    }
}

pub fn applied_names() -> Vec<&'static str> {
    APPLIED.lock().iter().map(|p| p.name).collect()
}
