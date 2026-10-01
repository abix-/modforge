//! In-memory binary patches on code in this process.
//!
//! All patches go through [`patch_bytes`], which takes care of
//! VirtualProtect, byte write, and protection restore. Each patch
//! records its undo (the original bytes, written back) on
//! [`crate::shutdown::SHUTDOWN_REGISTRY`] as it is applied, so the
//! generation's shutdown and [`revert_all`] put them back.
//! Moved here from horsey-mod so every game mod shares one
//! implementation.

use windows_sys::Win32::System::Memory::{
    PAGE_EXECUTE_READWRITE, PAGE_PROTECTION_FLAGS, VirtualProtect,
};

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

    crate::log!(
        "patch[{name}]: applied at 0x{addr:x} ({} bytes)",
        new_bytes.len()
    );
    // The undo: put the original bytes back.
    crate::shutdown::SHUTDOWN_REGISTRY
        .record("code patch", name.to_string(), 150, move || {
            let len = original.len();
            let mut old_protect: PAGE_PROTECTION_FLAGS = 0;
            // SAFETY: addr was a valid in-process code page when applied.
            unsafe {
                VirtualProtect(addr as *mut _, len, PAGE_EXECUTE_READWRITE, &mut old_protect);
                std::ptr::copy_nonoverlapping(original.as_ptr(), addr as *mut u8, len);
                let mut tmp: PAGE_PROTECTION_FLAGS = 0;
                VirtualProtect(addr as *mut _, len, old_protect, &mut tmp);
            }
            crate::log!("patch[{name}]: reverted at 0x{addr:x}");
        })
        .keep();
    Ok(())
}

/// Revert every applied patch now, most recent first, by running
/// their recorded undos.
pub fn revert_all() {
    crate::shutdown::SHUTDOWN_REGISTRY.undo_all("code patch");
}

/// Names of the patches still applied, oldest first.
pub fn applied_names() -> Vec<String> {
    crate::shutdown::SHUTDOWN_REGISTRY.list("code patch")
}
