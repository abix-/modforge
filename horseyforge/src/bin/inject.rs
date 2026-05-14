//! horseyforge-inject. Attach horseyforge.dll to a running Horsey.exe.
//!
//! Walks the process snapshot looking for `Horsey.exe`, opens it,
//! allocates a string for our DLL path, then calls
//! `CreateRemoteThread(target, NULL, 0, &LoadLibraryW, dll_path, 0, NULL)`
//! so the OS loads our DLL inside the target's address space. Our
//! DllMain (in `horseyforge.dll`) then takes over.
//!
//! Usage:
//!
//!   cargo run -p horseyforge --bin horseyforge-inject. \
//!         --dll C:/path/to/horseyforge.dll \
//!         --process Horsey.exe
//!
//! The DLL path defaults to the cdylib's release artifact next to
//! the injector if `--dll` is omitted. The process name defaults
//! to `Horsey.exe`.

use std::ffi::OsString;
use std::os::windows::ffi::OsStrExt;
use std::path::PathBuf;

use clap::Parser;
use windows_sys::Win32::Foundation::{CloseHandle, HANDLE};
use windows_sys::Win32::System::Diagnostics::ToolHelp::{
    CreateToolhelp32Snapshot, Process32FirstW, Process32NextW, PROCESSENTRY32W,
    TH32CS_SNAPPROCESS,
};
use windows_sys::Win32::System::LibraryLoader::{GetModuleHandleW, GetProcAddress};
use windows_sys::Win32::System::Memory::{
    VirtualAllocEx, VirtualFreeEx, MEM_COMMIT, MEM_RELEASE, MEM_RESERVE, PAGE_READWRITE,
};
use windows_sys::Win32::System::Threading::{
    CreateRemoteThread, OpenProcess, WaitForSingleObject, INFINITE, PROCESS_ALL_ACCESS,
};

#[derive(Parser, Debug)]
#[command(version, about = "Inject horseyforge.dll into a running Horsey.exe")]
struct Args {
    /// Path to horseyforge.dll. Defaults to ./horseyforge.dll next
    /// to the injector binary.
    #[arg(long)]
    dll: Option<PathBuf>,

    /// Target process executable name to search for.
    #[arg(long, default_value = "Horsey.exe")]
    process: String,
}

fn main() -> anyhow::Result<()> {
    let args = Args::parse();
    let dll_path = match args.dll {
        Some(p) => p,
        None => {
            // Default: alongside the injector binary.
            let exe = std::env::current_exe()?;
            exe.parent()
                .ok_or_else(|| anyhow::anyhow!("injector has no parent dir"))?
                .join("horseyforge.dll")
        }
    };

    if !dll_path.exists() {
        anyhow::bail!("DLL not found at {}", dll_path.display());
    }
    let dll_path = std::fs::canonicalize(&dll_path)?;

    println!("[inject] DLL: {}", dll_path.display());
    println!("[inject] target: {}", args.process);

    let pid = find_pid_by_name(&args.process)?;
    println!("[inject] found PID {pid}");

    inject_dll(pid, &dll_path)?;
    println!("[inject] OK");
    Ok(())
}

/// Walk the running-process snapshot for `name` (case-insensitive).
fn find_pid_by_name(name: &str) -> anyhow::Result<u32> {
    // SAFETY: CreateToolhelp32Snapshot is safe; we close the handle.
    let snap = unsafe { CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0) };
    if snap.is_null() || (snap as isize) == -1 {
        anyhow::bail!("CreateToolhelp32Snapshot failed");
    }

    let mut found_pid: u32 = 0;
    let target = name.to_ascii_lowercase();

    let mut entry: PROCESSENTRY32W = unsafe { std::mem::zeroed() };
    entry.dwSize = std::mem::size_of::<PROCESSENTRY32W>() as u32;

    // SAFETY: Process32FirstW reads from snapshot we own; entry is
    // valid for size.
    if unsafe { Process32FirstW(snap, &mut entry) } != 0 {
        loop {
            // Convert UTF-16 process name to String.
            let len = entry.szExeFile.iter().position(|&c| c == 0).unwrap_or(0);
            let proc_name =
                widestring::U16Str::from_slice(&entry.szExeFile[..len]).to_string_lossy();
            if proc_name.to_ascii_lowercase() == target {
                found_pid = entry.th32ProcessID;
                break;
            }
            // SAFETY: same conditions as the first read.
            if unsafe { Process32NextW(snap, &mut entry) } == 0 {
                break;
            }
        }
    }
    // SAFETY: snap was returned by CreateToolhelp32Snapshot.
    unsafe { CloseHandle(snap) };

    if found_pid == 0 {
        anyhow::bail!("process not found: {name}");
    }
    Ok(found_pid)
}

fn inject_dll(pid: u32, dll_path: &std::path::Path) -> anyhow::Result<()> {
    // SAFETY: OpenProcess is safe; we close the handle.
    let h_proc: HANDLE = unsafe { OpenProcess(PROCESS_ALL_ACCESS, 0, pid) };
    if h_proc.is_null() {
        anyhow::bail!(
            "OpenProcess(PID={pid}) failed (need admin? Game running as different user?)"
        );
    }

    // Build a UTF-16, NUL-terminated wide string of the DLL path.
    let mut wide: Vec<u16> = OsString::from(dll_path).encode_wide().collect();
    wide.push(0);
    let wide_bytes = wide.len() * 2;

    // Allocate writable memory in the target process.
    // SAFETY: VirtualAllocEx with valid handle + writable flags.
    let remote_mem = unsafe {
        VirtualAllocEx(
            h_proc,
            std::ptr::null(),
            wide_bytes,
            MEM_COMMIT | MEM_RESERVE,
            PAGE_READWRITE,
        )
    };
    if remote_mem.is_null() {
        // SAFETY: h_proc was returned by OpenProcess and not yet closed.
        unsafe { CloseHandle(h_proc) };
        anyhow::bail!("VirtualAllocEx failed");
    }

    // Write the DLL path into target's memory.
    let mut written: usize = 0;
    // SAFETY: WriteProcessMemory with valid params.
    let ok = unsafe {
        windows_sys::Win32::System::Diagnostics::Debug::WriteProcessMemory(
            h_proc,
            remote_mem,
            wide.as_ptr() as *const _,
            wide_bytes,
            &mut written,
        )
    };
    if ok == 0 || written != wide_bytes {
        // SAFETY: remote_mem was allocated by VirtualAllocEx above.
        unsafe { VirtualFreeEx(h_proc, remote_mem, 0, MEM_RELEASE) };
        unsafe { CloseHandle(h_proc) };
        anyhow::bail!("WriteProcessMemory failed");
    }

    // Look up LoadLibraryW in OUR process. It's at the same address
    // in the target because kernel32.dll is loaded at the same base
    // in both (Windows ASLR is shared per session for system DLLs).
    // SAFETY: GetModuleHandleW(L"kernel32.dll") never fails for a
    // process with kernel32 loaded.
    let kernel32 = unsafe {
        GetModuleHandleW(
            widestring::U16CString::from_str("kernel32.dll")
                .unwrap()
                .as_ptr(),
        )
    };
    if kernel32.is_null() {
        anyhow::bail!("GetModuleHandleW(kernel32.dll) failed");
    }
    let load_library_w_name = b"LoadLibraryW\0";
    // SAFETY: GetProcAddress is always safe with a valid module handle.
    let load_library_w =
        unsafe { GetProcAddress(kernel32, load_library_w_name.as_ptr()) };
    if load_library_w.is_none() {
        anyhow::bail!("GetProcAddress(LoadLibraryW) failed");
    }

    // CreateRemoteThread to call LoadLibraryW(remote_mem) in target.
    // SAFETY: All handles + addresses are valid; the start address
    // points to LoadLibraryW which has the correct (LPVOID) -> DWORD
    // signature for a thread proc.
    let h_thread = unsafe {
        CreateRemoteThread(
            h_proc,
            std::ptr::null(),
            0,
            std::mem::transmute(load_library_w),
            remote_mem,
            0,
            std::ptr::null_mut(),
        )
    };
    if h_thread.is_null() {
        // SAFETY: remote_mem was allocated by VirtualAllocEx above.
        unsafe { VirtualFreeEx(h_proc, remote_mem, 0, MEM_RELEASE) };
        unsafe { CloseHandle(h_proc) };
        anyhow::bail!("CreateRemoteThread failed");
    }

    // SAFETY: h_thread is valid; INFINITE wait is safe.
    let _ = unsafe { WaitForSingleObject(h_thread, INFINITE) };

    // Cleanup target-process resources.
    // SAFETY: All handles were returned by their respective creators.
    unsafe {
        VirtualFreeEx(h_proc, remote_mem, 0, MEM_RELEASE);
        CloseHandle(h_thread);
        CloseHandle(h_proc);
    }
    Ok(())
}
