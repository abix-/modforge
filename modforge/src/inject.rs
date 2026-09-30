//! Inject + hot-reload a mod DLL in a running native-PE game.
//!
//! Lifted out of horsey-mod's injector when Jagged Alliance 3 became
//! the second native-PE game, as horsey-mod's Cargo.toml planned.
//!
//! The first inject:
//! - copies the DLL to a *staged* path with a timestamped filename,
//!   leaving the cargo-output DLL free for subsequent rebuilds
//! - LoadLibraryW's the staged path inside the game via
//!   CreateRemoteThread
//! - captures the returned HMODULE
//! - writes the staged path + HMODULE to `<dll stem>.injstate`
//!   alongside the source DLL
//!
//! A reload:
//! - POSTs `_shutdown` to the running HTTP server so it releases
//!   the listener thread + port
//! - CreateRemoteThread'd FreeLibrary on the recorded HMODULE
//! - deletes the old staged file (best effort)
//! - copies the new DLL to a fresh staged path
//! - LoadLibraryW's the new staged path
//! - updates the injstate file

use std::ffi::OsString;
use std::io::Read;
use std::os::windows::ffi::OsStrExt;
use std::path::{Path, PathBuf};
use std::time::{Duration, SystemTime};

use windows_sys::Win32::Foundation::{CloseHandle, HANDLE, HMODULE};
use windows_sys::Win32::System::Diagnostics::ToolHelp::{
    CreateToolhelp32Snapshot, PROCESSENTRY32W, Process32FirstW, Process32NextW, TH32CS_SNAPPROCESS,
};
use windows_sys::Win32::System::LibraryLoader::{GetModuleHandleW, GetProcAddress};
use windows_sys::Win32::System::Memory::{
    MEM_COMMIT, MEM_RELEASE, MEM_RESERVE, PAGE_READWRITE, VirtualAllocEx, VirtualFreeEx,
};
use windows_sys::Win32::System::Threading::{
    CreateRemoteThread, GetExitCodeThread, INFINITE, OpenProcess, PROCESS_ALL_ACCESS,
    WaitForSingleObject,
};

/// First-time inject of `source_dll` into `process`. With `fresh`,
/// any existing injstate is ignored and overwritten; without it an
/// existing injstate is refused, since that generation may still be
/// loaded.
pub fn inject(source_dll: &Path, process: &str, fresh: bool) -> anyhow::Result<()> {
    let source_dll = canonical_source(source_dll, process)?;
    let state_path = state_path(&source_dll)?;
    let pid = find_pid_by_name(process)?;
    println!("[inject] found PID {pid}");

    if !fresh && state_path.exists() {
        if let Ok(prev) = InjState::load(&state_path) {
            println!(
                "[inject] WARNING: state file exists ({}); use --reload to swap, or --fresh to ignore.",
                state_path.display()
            );
            println!(
                "[inject] previous gen: hmod=0x{:x} staged={}",
                prev.hmodule,
                prev.staged_path.display()
            );
            anyhow::bail!("aborting; pass --reload or --fresh");
        }
    }

    let h_proc = open_process(pid)?;
    let staged = stage_dll(&source_dll)?;
    let hmodule = load_library_remote(h_proc, &staged)?;
    // SAFETY: h_proc was returned by OpenProcess.
    unsafe { CloseHandle(h_proc) };

    InjState {
        hmodule,
        staged_path: staged,
    }
    .save(&state_path)?;
    println!("[inject] OK; hmod=0x{:x}", hmodule);
    Ok(())
}

/// Hot-reload: shut down + unload the generation recorded in the
/// injstate, stage the new build, load it. `port` is the mod's HTTP
/// control plane, asked to `_shutdown` before the unload.
pub fn reload(source_dll: &Path, process: &str, port: u16) -> anyhow::Result<()> {
    let source_dll = canonical_source(source_dll, process)?;
    let state_path = state_path(&source_dll)?;
    let pid = find_pid_by_name(process)?;
    println!("[inject] found PID {pid}");

    let prev = InjState::load(&state_path).map_err(|e| {
        anyhow::anyhow!(
            "--reload requires a prior inject; no state file at {} ({e})",
            state_path.display()
        )
    })?;
    println!(
        "[inject] previous gen: hmod=0x{:x} staged={}",
        prev.hmodule,
        prev.staged_path.display()
    );

    // Step 1: graceful shutdown so the listener releases the port.
    match send_shutdown_op(port) {
        Ok(()) => println!("[inject] _shutdown op acknowledged"),
        Err(e) => println!("[inject] _shutdown op failed (continuing anyway): {e}"),
    }
    std::thread::sleep(Duration::from_millis(250));

    // Step 2: remote FreeLibrary on the recorded HMODULE.
    let h_proc = open_process(pid)?;
    call_freelibrary_remote(h_proc, prev.hmodule)?;
    println!("[inject] FreeLibrary on old generation: OK");

    // Step 3: clean up old staged file. Best effort. Windows may
    // still hold it briefly after FreeLibrary.
    for _ in 0..10 {
        if std::fs::remove_file(&prev.staged_path).is_ok() {
            break;
        }
        std::thread::sleep(Duration::from_millis(100));
    }

    // Step 4: stage + load the new build.
    let staged = stage_dll(&source_dll)?;
    let hmodule = load_library_remote(h_proc, &staged)?;
    println!(
        "[inject] new gen: hmod=0x{:x} staged={}",
        hmodule,
        staged.display()
    );

    // SAFETY: h_proc was returned by OpenProcess.
    unsafe { CloseHandle(h_proc) };

    InjState {
        hmodule,
        staged_path: staged,
    }
    .save(&state_path)?;
    println!("[inject] reload OK");
    Ok(())
}

fn canonical_source(source_dll: &Path, process: &str) -> anyhow::Result<PathBuf> {
    if !source_dll.exists() {
        anyhow::bail!("source DLL not found at {}", source_dll.display());
    }
    let source_dll = std::fs::canonicalize(source_dll)?;
    println!("[inject] source DLL: {}", source_dll.display());
    println!("[inject] target: {process}");
    Ok(source_dll)
}

fn state_path(source_dll: &Path) -> anyhow::Result<PathBuf> {
    let parent = source_dll
        .parent()
        .ok_or_else(|| anyhow::anyhow!("source DLL has no parent"))?;
    let stem = source_dll
        .file_stem()
        .and_then(|s| s.to_str())
        .ok_or_else(|| anyhow::anyhow!("source DLL has no stem"))?;
    Ok(parent.join(format!("{stem}.injstate")))
}

// =============================================================================
// State persistence
// =============================================================================

#[derive(Debug)]
struct InjState {
    hmodule: u64,
    staged_path: PathBuf,
}

impl InjState {
    fn save(&self, path: &Path) -> anyhow::Result<()> {
        std::fs::write(
            path,
            format!("{:#x}\n{}\n", self.hmodule, self.staged_path.display()),
        )?;
        Ok(())
    }

    fn load(path: &Path) -> anyhow::Result<Self> {
        let s = std::fs::read_to_string(path)?;
        let mut lines = s.lines();
        let hex = lines
            .next()
            .ok_or_else(|| anyhow::anyhow!("empty injstate"))?;
        let hex = hex.trim().trim_start_matches("0x");
        let hmodule = u64::from_str_radix(hex, 16)?;
        let staged = lines
            .next()
            .ok_or_else(|| anyhow::anyhow!("missing staged path"))?;
        Ok(Self {
            hmodule,
            staged_path: PathBuf::from(staged.trim()),
        })
    }
}

// =============================================================================
// Staging
// =============================================================================

/// Copy `source` to a unique timestamped path next to it. Returns
/// the path. Cargo always rebuilds to `source`; we never load
/// `source` directly so it's never locked.
fn stage_dll(source: &Path) -> anyhow::Result<PathBuf> {
    let parent = source
        .parent()
        .ok_or_else(|| anyhow::anyhow!("source has no parent"))?;
    let stem = source
        .file_stem()
        .and_then(|s| s.to_str())
        .ok_or_else(|| anyhow::anyhow!("source has no stem"))?;
    let ts = SystemTime::now()
        .duration_since(SystemTime::UNIX_EPOCH)?
        .as_millis();
    let staged = parent.join(format!("{stem}-{ts}.dll"));
    std::fs::copy(source, &staged)?;
    let staged = std::fs::canonicalize(&staged)?;
    println!("[inject] staged DLL: {}", staged.display());
    Ok(staged)
}

// =============================================================================
// Process / remote-call primitives
// =============================================================================

fn find_pid_by_name(name: &str) -> anyhow::Result<u32> {
    // SAFETY: CreateToolhelp32Snapshot is safe; we close the handle.
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

fn open_process(pid: u32) -> anyhow::Result<HANDLE> {
    // SAFETY: OpenProcess never UB. Returns NULL on failure.
    let h: HANDLE = unsafe { OpenProcess(PROCESS_ALL_ACCESS, 0, pid) };
    if h.is_null() {
        anyhow::bail!(
            "OpenProcess(PID={pid}) failed (need admin? Game running as different user?)"
        );
    }
    Ok(h)
}

/// Resolve `kernel32.dll!<name>` in this process. Returns the address;
/// it IS the same address in the target process (kernel32 is loaded
/// at the same base across a session).
fn resolve_kernel32_proc(name: &[u8]) -> anyhow::Result<usize> {
    let mod_name: Vec<u16> = OsString::from("kernel32.dll")
        .encode_wide()
        .chain(std::iter::once(0))
        .collect();
    // SAFETY: kernel32 is always loaded.
    let kernel32 = unsafe { GetModuleHandleW(mod_name.as_ptr()) };
    if kernel32.is_null() {
        anyhow::bail!("GetModuleHandleW(kernel32.dll) failed");
    }
    // name must be NUL-terminated.
    debug_assert!(name.ends_with(b"\0"));
    // SAFETY: name is ASCII NUL-terminated; kernel32 is a valid module.
    let addr = unsafe { GetProcAddress(kernel32, name.as_ptr()) };
    let addr = addr.ok_or_else(|| anyhow::anyhow!("GetProcAddress({:?}) failed", name))?;
    Ok(addr as usize)
}

/// LoadLibraryW(`dll_path`) inside the target process. Returns the
/// HMODULE the target loader assigned.
fn load_library_remote(h_proc: HANDLE, dll_path: &Path) -> anyhow::Result<u64> {
    let load_library_w = resolve_kernel32_proc(b"LoadLibraryW\0")?;

    let mut wide: Vec<u16> = OsString::from(dll_path).encode_wide().collect();
    wide.push(0);
    let wide_bytes = wide.len() * 2;

    // SAFETY: target handle valid, writable region requested.
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
        anyhow::bail!("VirtualAllocEx failed");
    }

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
        // SAFETY: remote_mem allocated by VirtualAllocEx above.
        unsafe { VirtualFreeEx(h_proc, remote_mem, 0, MEM_RELEASE) };
        anyhow::bail!("WriteProcessMemory failed");
    }

    // CreateRemoteThread on LoadLibraryW(remote_mem). The thread
    // proc signature matches LoadLibraryW's (LPCWSTR -> HMODULE).
    // SAFETY: all addresses are valid; ABI matches.
    let h_thread = unsafe {
        CreateRemoteThread(
            h_proc,
            std::ptr::null(),
            0,
            std::mem::transmute::<usize, _>(load_library_w),
            remote_mem,
            0,
            std::ptr::null_mut(),
        )
    };
    if h_thread.is_null() {
        // SAFETY: remote_mem allocated above.
        unsafe { VirtualFreeEx(h_proc, remote_mem, 0, MEM_RELEASE) };
        anyhow::bail!("CreateRemoteThread(LoadLibraryW) failed");
    }

    // SAFETY: h_thread valid.
    let _ = unsafe { WaitForSingleObject(h_thread, INFINITE) };
    let mut exit_code: u32 = 0;
    // SAFETY: h_thread valid; exit_code is a u32 we own.
    unsafe { GetExitCodeThread(h_thread, &mut exit_code) };
    // GetExitCodeThread returns only u32; LoadLibraryW's HMODULE is
    // 64-bit. For our purposes the low 32 bits are sufficient as a
    // sentinel ("nonzero = success"), but for accurate FreeLibrary
    // calls we need the full 64-bit value. Read it from the target's
    // module list instead.
    let hmodule = if exit_code == 0 {
        0
    } else {
        find_module_hmodule(h_proc, dll_path)?
    };

    // SAFETY: h_thread + remote_mem both valid; we're done with them.
    unsafe {
        CloseHandle(h_thread);
        VirtualFreeEx(h_proc, remote_mem, 0, MEM_RELEASE);
    }

    if hmodule == 0 {
        anyhow::bail!("LoadLibraryW returned NULL in target");
    }
    Ok(hmodule)
}

/// Locate the loaded module's full 64-bit base address in the target
/// process by matching the path against EnumProcessModulesEx output.
fn find_module_hmodule(h_proc: HANDLE, dll_path: &Path) -> anyhow::Result<u64> {
    use windows_sys::Win32::System::ProcessStatus::{
        EnumProcessModulesEx, GetModuleFileNameExW, LIST_MODULES_ALL,
    };

    let want = dll_path
        .canonicalize()
        .unwrap_or_else(|_| dll_path.to_path_buf());
    let want_str = want.to_string_lossy().to_lowercase();

    let mut handles: Vec<HMODULE> = vec![std::ptr::null_mut(); 4096];
    let bytes_needed_room = (handles.len() * std::mem::size_of::<HMODULE>()) as u32;
    let mut bytes_needed: u32 = 0;
    // SAFETY: target handle valid; buffer is owned + sized.
    let ok = unsafe {
        EnumProcessModulesEx(
            h_proc,
            handles.as_mut_ptr(),
            bytes_needed_room,
            &mut bytes_needed,
            LIST_MODULES_ALL,
        )
    };
    if ok == 0 {
        anyhow::bail!("EnumProcessModulesEx failed");
    }
    let n = (bytes_needed as usize) / std::mem::size_of::<HMODULE>();

    let mut path_buf = [0u16; 32768];
    for hmod in handles.iter().take(n).copied() {
        // SAFETY: hmod returned by EnumProcessModulesEx; target valid.
        let len = unsafe {
            GetModuleFileNameExW(h_proc, hmod, path_buf.as_mut_ptr(), path_buf.len() as u32)
        };
        if len == 0 {
            continue;
        }
        let s = String::from_utf16_lossy(&path_buf[..len as usize]);
        let s_lower = s.to_lowercase();
        if s_lower.ends_with(&want_str) || want_str.ends_with(&s_lower) {
            return Ok(hmod as u64);
        }
    }
    anyhow::bail!("loaded module not found in process module list");
}

/// CreateRemoteThread on FreeLibrary with `hmodule`. Returns when
/// the call completes (FreeLibrary returns).
fn call_freelibrary_remote(h_proc: HANDLE, hmodule: u64) -> anyhow::Result<()> {
    let free_library = resolve_kernel32_proc(b"FreeLibrary\0")?;
    // SAFETY: ABI matches: FreeLibrary(HMODULE) -> BOOL.
    let h_thread = unsafe {
        CreateRemoteThread(
            h_proc,
            std::ptr::null(),
            0,
            std::mem::transmute::<usize, _>(free_library),
            hmodule as *mut std::ffi::c_void,
            0,
            std::ptr::null_mut(),
        )
    };
    if h_thread.is_null() {
        anyhow::bail!("CreateRemoteThread(FreeLibrary) failed");
    }
    // SAFETY: valid handle.
    unsafe { WaitForSingleObject(h_thread, INFINITE) };
    // SAFETY: valid handle, done with it.
    unsafe { CloseHandle(h_thread) };
    Ok(())
}

// =============================================================================
// _shutdown HTTP op
// =============================================================================

/// Register `_shutdown`, the op `reload` sends before it calls
/// FreeLibrary. Every injected mod DLL registers it at init.
pub fn register_ops() {
    crate::ops::OP_REGISTRY.register_many(vec![crate::ops::OpDef::new(
        "_shutdown",
        "Stop the HTTP server. Used by the injector before unloading the DLL for hot-reload.",
        "",
        |_| {
            // The shutdown runs on a fresh thread so the success
            // response reaches the client first; shutting the server
            // down before returning would drop the reply.
            std::thread::Builder::new()
                .name("inject-shutdown".into())
                .spawn(|| {
                    // Tiny delay so the in-flight HTTP response has time
                    // to flush to the client socket.
                    std::thread::sleep(Duration::from_millis(100));
                    crate::log!("inject: _shutdown -> dropping server");
                    crate::server::shutdown_all();
                })
                .ok();
            Ok(serde_json::json!({"shutting_down": true}))
        },
    )]);
}

fn send_shutdown_op(port: u16) -> anyhow::Result<()> {
    // POST is synchronous without pulling in a runtime/reqwest.
    use std::io::Write;
    use std::net::{Ipv4Addr, SocketAddr, TcpStream};
    let addr = SocketAddr::from((Ipv4Addr::LOCALHOST, port));
    let mut stream = TcpStream::connect_timeout(&addr, Duration::from_secs(2))?;
    stream.set_write_timeout(Some(Duration::from_secs(2)))?;
    stream.set_read_timeout(Some(Duration::from_secs(2)))?;

    let body = r#"{"op":"_shutdown"}"#;
    let req = format!(
        "POST /op HTTP/1.1\r\n\
         Host: 127.0.0.1\r\n\
         Content-Type: application/json\r\n\
         Content-Length: {}\r\n\
         Connection: close\r\n\
         \r\n\
         {}",
        body.len(),
        body
    );
    stream.write_all(req.as_bytes())?;
    let mut resp = String::new();
    let _ = stream.read_to_string(&mut resp);
    Ok(())
}
