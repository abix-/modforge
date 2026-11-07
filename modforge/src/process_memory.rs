//! Read another process's memory from outside it, read-only.
//!
//! For tools that run as their own program next to a game instead of
//! inside it. The handle is opened with `PROCESS_QUERY_INFORMATION |
//! PROCESS_VM_READ` (0x410) and nothing else, the same access
//! ExileCore2's snapshot reader and the abiotic-factor stack tests use.
//! There is no write method: a [`ProcessMemory`] cannot change the
//! process it reads.
//!
//! ## SAFETY contract (all `unsafe` blocks in this module)
//!
//! Every block calls a `windows-sys` FFI. Handles come from
//! `OpenProcess` / `CreateToolhelp32Snapshot`, are checked for null or
//! INVALID_HANDLE_VALUE, and are closed exactly once. `ReadProcessMemory`
//! copies into a buffer we own whose length is passed alongside; the
//! kernel validates the source range in the other process and fails
//! instead of faulting. Windows structs are plain data where all-zero
//! is a valid value.

use std::ffi::c_void;
use std::io;

use windows_sys::Win32::Foundation::{CloseHandle, HANDLE, HMODULE};
use windows_sys::Win32::System::Diagnostics::Debug::ReadProcessMemory;
use windows_sys::Win32::System::Diagnostics::ToolHelp::{
    CreateToolhelp32Snapshot, PROCESSENTRY32W, Process32FirstW, Process32NextW, TH32CS_SNAPPROCESS,
};
use windows_sys::Win32::System::ProcessStatus::{
    EnumProcessModulesEx, GetModuleFileNameExW, GetModuleInformation, LIST_MODULES_ALL, MODULEINFO,
};
use windows_sys::Win32::System::Threading::{
    OpenProcess, PROCESS_QUERY_INFORMATION, PROCESS_VM_READ,
};

/// The only access this module ever asks for.
pub const READ_ACCESS: u32 = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;

/// PID of the first running process whose exe name matches `name`
/// (case-insensitive, with the `.exe`).
pub fn find_pid_by_name(name: &str) -> anyhow::Result<u32> {
    // SAFETY: see module contract; the snapshot is closed below.
    let snap = unsafe { CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0) };
    if snap.is_null() || (snap as isize) == -1 {
        anyhow::bail!("CreateToolhelp32Snapshot failed");
    }
    let mut found_pid: u32 = 0;
    let target = name.to_ascii_lowercase();
    // SAFETY: PROCESSENTRY32W is plain data; all-zero is a valid value.
    let mut entry: PROCESSENTRY32W = unsafe { std::mem::zeroed() };
    entry.dwSize = std::mem::size_of::<PROCESSENTRY32W>() as u32;
    // SAFETY: snap is valid; entry has its dwSize set.
    if unsafe { Process32FirstW(snap, &mut entry) } != 0 {
        loop {
            let len = entry.szExeFile.iter().position(|&c| c == 0).unwrap_or(0);
            let proc_name = String::from_utf16_lossy(&entry.szExeFile[..len]);
            if proc_name.to_ascii_lowercase() == target {
                found_pid = entry.th32ProcessID;
                break;
            }
            // SAFETY: same as the first read.
            if unsafe { Process32NextW(snap, &mut entry) } == 0 {
                break;
            }
        }
    }
    // SAFETY: snap was created above.
    unsafe { CloseHandle(snap) };
    if found_pid == 0 {
        anyhow::bail!("process not found: {name}");
    }
    Ok(found_pid)
}

/// One loaded module (exe or dll) in the read process.
#[derive(Clone, Debug, serde::Serialize)]
pub struct Module {
    pub base: u64,
    pub size: u64,
    pub path: String,
}

/// A read-only handle on another process.
pub struct ProcessMemory {
    handle: HANDLE,
    pid: u32,
}

// SAFETY: a process HANDLE is a kernel object reference, usable from any
// thread; ReadProcessMemory on one handle from several threads is allowed.
unsafe impl Send for ProcessMemory {}
// SAFETY: as above; no method mutates shared state behind &self.
unsafe impl Sync for ProcessMemory {}

impl ProcessMemory {
    /// Open `pid` with [`READ_ACCESS`].
    pub fn open(pid: u32) -> io::Result<Self> {
        // SAFETY: see module contract; null is checked.
        let handle = unsafe { OpenProcess(READ_ACCESS, 0, pid) };
        if handle.is_null() {
            return Err(io::Error::last_os_error());
        }
        Ok(Self { handle, pid })
    }

    pub fn pid(&self) -> u32 {
        self.pid
    }

    /// Fill `buf` from `addr` in the other process. Fails unless every
    /// byte was read.
    pub fn read(&self, addr: u64, buf: &mut [u8]) -> io::Result<()> {
        let mut got: usize = 0;
        // SAFETY: buf is ours and its length is passed; the kernel checks
        // the source range and fails instead of faulting.
        let ok = unsafe {
            ReadProcessMemory(
                self.handle,
                addr as *const c_void,
                buf.as_mut_ptr().cast(),
                buf.len(),
                &mut got,
            )
        };
        if ok == 0 {
            return Err(io::Error::last_os_error());
        }
        if got != buf.len() {
            return Err(io::Error::new(
                io::ErrorKind::UnexpectedEof,
                format!("read {got} of {} bytes at {addr:#x}", buf.len()),
            ));
        }
        Ok(())
    }

    /// Read `len` bytes from `addr`.
    pub fn read_vec(&self, addr: u64, len: usize) -> io::Result<Vec<u8>> {
        let mut buf = vec![0u8; len];
        self.read(addr, &mut buf)?;
        Ok(buf)
    }

    /// Read a plain-data value. `T` must be valid for any bit pattern
    /// (integers, floats, `#[repr(C)]` structs of those).
    pub fn read_value<T: Copy + Default>(&self, addr: u64) -> io::Result<T> {
        let mut value = T::default();
        // SAFETY: value is a live T on our stack; we view its bytes for the
        // length of the read. T is plain data by this function's contract.
        let bytes = unsafe {
            std::slice::from_raw_parts_mut((&mut value as *mut T).cast::<u8>(), size_of::<T>())
        };
        self.read(addr, bytes)?;
        Ok(value)
    }

    /// Every module loaded in the process, exe first.
    pub fn modules(&self) -> io::Result<Vec<Module>> {
        let mut handles: Vec<HMODULE> = vec![std::ptr::null_mut(); 1024];
        let mut needed: u32 = 0;
        // SAFETY: handles is ours and its byte size is passed.
        let ok = unsafe {
            EnumProcessModulesEx(
                self.handle,
                handles.as_mut_ptr(),
                (handles.len() * size_of::<HMODULE>()) as u32,
                &mut needed,
                LIST_MODULES_ALL,
            )
        };
        if ok == 0 {
            return Err(io::Error::last_os_error());
        }
        handles.truncate(needed as usize / size_of::<HMODULE>());
        let mut out = Vec::with_capacity(handles.len());
        for h in handles {
            // SAFETY: MODULEINFO is plain data; all-zero is valid.
            let mut info: MODULEINFO = unsafe { std::mem::zeroed() };
            // SAFETY: h came from EnumProcessModulesEx on this handle.
            let ok = unsafe {
                GetModuleInformation(self.handle, h, &mut info, size_of::<MODULEINFO>() as u32)
            };
            if ok == 0 {
                continue;
            }
            let mut name = [0u16; 1024];
            // SAFETY: name is ours and its length in u16s is passed.
            let n = unsafe {
                GetModuleFileNameExW(self.handle, h, name.as_mut_ptr(), name.len() as u32)
            };
            out.push(Module {
                base: info.lpBaseOfDll as u64,
                size: info.SizeOfImage as u64,
                path: String::from_utf16_lossy(&name[..n as usize]),
            });
        }
        Ok(out)
    }

    /// The exe's own module.
    pub fn main_module(&self) -> io::Result<Module> {
        self.modules()?
            .into_iter()
            .next()
            .ok_or_else(|| io::Error::new(io::ErrorKind::NotFound, "process has no modules"))
    }

    /// The link timestamp in `module`'s PE header, read from memory.
    /// Equal to [`pe_timestamp`] of the file on disk when both are the
    /// same build.
    pub fn image_timestamp(&self, module: &Module) -> io::Result<u32> {
        let header = self.read_vec(module.base, PE_HEADER_BYTES)?;
        pe_timestamp(&header)
            .ok_or_else(|| io::Error::new(io::ErrorKind::InvalidData, "no PE header at module base"))
    }
}

/// Bytes enough to hold the DOS header and the PE file header.
pub const PE_HEADER_BYTES: usize = 0x400;

/// The PE file header's TimeDateStamp: "MZ", then `e_lfanew` at 0x3C
/// pointing at "PE\0\0", then the stamp 8 bytes past it.
pub fn pe_timestamp(bytes: &[u8]) -> Option<u32> {
    if bytes.get(..2)? != b"MZ" {
        return None;
    }
    let e_lfanew = u32::from_le_bytes(bytes.get(0x3C..0x40)?.try_into().ok()?) as usize;
    if bytes.get(e_lfanew..e_lfanew + 4)? != b"PE\0\0" {
        return None;
    }
    let at = e_lfanew + 8;
    Some(u32::from_le_bytes(bytes.get(at..at + 4)?.try_into().ok()?))
}

impl Drop for ProcessMemory {
    fn drop(&mut self) {
        // SAFETY: handle came from OpenProcess and is closed once, here.
        unsafe { CloseHandle(self.handle) };
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    static MARKER: [u8; 8] = *b"modforge";

    #[test]
    fn reads_own_process_like_another() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let got = mem
            .read_vec(MARKER.as_ptr() as u64, MARKER.len())
            .expect("read marker");
        assert_eq!(got, MARKER);
        let value: u64 = mem.read_value(MARKER.as_ptr() as u64).expect("read value");
        assert_eq!(value.to_le_bytes(), MARKER);
    }

    #[test]
    fn main_module_starts_with_mz() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let exe = mem.main_module().expect("main module");
        assert!(exe.size > 0);
        assert_eq!(mem.read_vec(exe.base, 2).expect("read header"), b"MZ");
    }

    #[test]
    fn memory_timestamp_matches_disk() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let exe = mem.main_module().expect("main module");
        let in_memory = mem.image_timestamp(&exe).expect("stamp from memory");
        let on_disk = pe_timestamp(&std::fs::read(&exe.path).expect("read exe")).expect("stamp from disk");
        assert_eq!(in_memory, on_disk);
    }

    #[test]
    fn pe_timestamp_rejects_non_pe() {
        assert_eq!(pe_timestamp(b"not a pe file"), None);
        assert_eq!(pe_timestamp(&[]), None);
    }

    #[test]
    fn unreadable_address_is_an_error() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        assert!(mem.read_vec(0x10, 8).is_err());
    }

    #[test]
    fn finds_own_exe_by_name() {
        let exe = std::env::current_exe().expect("current exe");
        let name = exe.file_name().unwrap().to_string_lossy().to_string();
        let pid = find_pid_by_name(&name).expect("find own exe");
        assert!(pid > 0);
    }
}
