// Better Backpack DLL injector. Walks the process list, finds Grounded 2
// (Steam or Xbox build), and pokes LoadLibraryA via CreateRemoteThread to
// map our DLL.
//
// Pattern lifted from x0reaxeax/Grounded2Minimal Injector/main.c (MIT) --
// the canonical pattern for this game family. Same behavior as the C
// version, ported to Rust.

use std::env;
use std::ffi::CString;
use std::fs::OpenOptions;
use std::io::Write;
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::ptr;
use std::sync::{Mutex, OnceLock};

use anyhow::{Context, Result, anyhow, bail};
use windows_sys::Win32::Foundation::{CloseHandle, ERROR_ACCESS_DENIED, GetLastError, HANDLE};
use windows_sys::Win32::System::Diagnostics::ToolHelp::{
    CreateToolhelp32Snapshot, PROCESSENTRY32, Process32First, Process32Next, TH32CS_SNAPPROCESS,
};
use windows_sys::Win32::System::LibraryLoader::{GetModuleHandleA, GetProcAddress};
use windows_sys::Win32::System::Memory::{
    MEM_COMMIT, MEM_RELEASE, MEM_RESERVE, PAGE_READWRITE, VirtualAllocEx, VirtualFreeEx,
};
use windows_sys::Win32::System::Threading::{
    CreateRemoteThread, GetExitCodeThread, LPTHREAD_START_ROUTINE, OpenProcess,
    PROCESS_CREATE_THREAD, PROCESS_VM_OPERATION, PROCESS_VM_READ, PROCESS_VM_WRITE,
    WaitForSingleObject,
};
use windows_sys::Win32::System::Diagnostics::Debug::WriteProcessMemory;

const TARGET_PROCESSES: &[&str] = &[
    "Grounded2-WinGRTS-Shipping.exe", // Steam
    "Grounded2-WinGDK-Shipping.exe",  // Xbox Game Pass
];

const WAIT_LOAD_LIBRARY_MS: u32 = 5_000;

static LOG_FILE: OnceLock<Mutex<std::fs::File>> = OnceLock::new();

fn log_path() -> PathBuf {
    if let Ok(mut p) = env::current_exe() {
        p.pop();
        p.push("inject.log");
        return p;
    }
    PathBuf::from("inject.log")
}

fn init_log() {
    if LOG_FILE.get().is_some() {
        return;
    }
    if let Ok(f) = OpenOptions::new()
        .create(true)
        .write(true)
        .truncate(true)
        .open(log_path())
    {
        let _ = LOG_FILE.set(Mutex::new(f));
    }
}

fn log_line(prefix: &str, msg: &str) {
    let now = std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_secs() % 86_400)
        .unwrap_or(0);
    let h = now / 3600;
    let m = (now / 60) % 60;
    let s = now % 60;
    let stamped = format!("[{h:02}:{m:02}:{s:02}] {prefix}{msg}");
    println!("{stamped}");
    if let Some(file) = LOG_FILE.get()
        && let Ok(mut f) = file.lock()
    {
        let _ = writeln!(f, "{stamped}");
        let _ = f.flush();
    }
}

fn main() -> ExitCode {
    init_log();
    log_line("", &format!("inject.exe starting (log: {})", log_path().display()));
    match run() {
        Ok(()) => {
            log_line("", "exit: success");
            ExitCode::SUCCESS
        }
        Err(err) => {
            log_line("[-] ", &format!("{err:#}"));
            log_line("", "exit: failure");
            ExitCode::from(1)
        }
    }
}

fn run() -> Result<()> {
    let dll_path = resolve_dll_path()?;
    log_line("[+] ", &format!("DLL: {}", dll_path.display()));

    let (pid, matched) = find_target_pid()
        .context("Grounded 2 not running. Launch the game and load a save first.")?;
    log_line("[+] ", &format!("target: {matched} (PID {pid})"));

    inject(pid, &dll_path)
}

fn resolve_dll_path() -> Result<PathBuf> {
    let arg = env::args().nth(1);
    let candidate: PathBuf = match arg {
        Some(arg) => PathBuf::from(arg),
        None => {
            let mut exe = env::current_exe().context("locating injector exe")?;
            exe.pop();
            exe.push("better_backpack.dll");
            exe
        }
    };
    let absolute = candidate
        .canonicalize()
        .with_context(|| format!("DLL not found: '{}'", candidate.display()))?;
    Ok(strip_unc(absolute))
}

// canonicalize on Windows returns a \\?\ prefixed path; LoadLibraryA accepts
// it, but the prefix bloats logs and trips some users up. Strip it for
// printing.
fn strip_unc(p: PathBuf) -> PathBuf {
    let s = p.to_string_lossy();
    if let Some(stripped) = s.strip_prefix(r"\\?\") {
        PathBuf::from(stripped.to_owned())
    } else {
        p
    }
}

fn find_target_pid() -> Result<(u32, &'static str)> {
    unsafe {
        let snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if snap.is_null() || snap == windows_sys::Win32::Foundation::INVALID_HANDLE_VALUE {
            bail!("CreateToolhelp32Snapshot failed: E{}", GetLastError());
        }
        let _snap_guard = HandleGuard(snap);

        let mut entry: PROCESSENTRY32 = std::mem::zeroed();
        entry.dwSize = std::mem::size_of::<PROCESSENTRY32>() as u32;

        if Process32First(snap, &mut entry) == 0 {
            bail!("Process32First failed: E{}", GetLastError());
        }

        loop {
            let name = entry_name(&entry);
            for target in TARGET_PROCESSES {
                if name.eq_ignore_ascii_case(target) {
                    return Ok((entry.th32ProcessID, target));
                }
            }
            if Process32Next(snap, &mut entry) == 0 {
                break;
            }
        }
    }
    Err(anyhow!(
        "no matching process found. Looking for: {}",
        TARGET_PROCESSES.join(", ")
    ))
}

fn entry_name(entry: &PROCESSENTRY32) -> String {
    let bytes: &[u8] = unsafe {
        std::slice::from_raw_parts(
            entry.szExeFile.as_ptr() as *const u8,
            entry.szExeFile.len(),
        )
    };
    let nul = bytes.iter().position(|&b| b == 0).unwrap_or(bytes.len());
    String::from_utf8_lossy(&bytes[..nul]).into_owned()
}

fn inject(pid: u32, dll_path: &Path) -> Result<()> {
    let path_c = CString::new(dll_path.to_string_lossy().as_bytes())
        .context("DLL path contains an interior NUL byte")?;
    let path_bytes = path_c.as_bytes_with_nul();

    unsafe {
        let h_proc = OpenProcess(
            PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD,
            0,
            pid,
        );
        if h_proc.is_null() {
            let err = GetLastError();
            let mut msg = format!("OpenProcess failed: E{err}");
            if err == ERROR_ACCESS_DENIED {
                msg.push_str(" (try running this exe as Administrator)");
            }
            bail!(msg);
        }
        let _proc_guard = HandleGuard(h_proc);

        let remote_buf = VirtualAllocEx(
            h_proc,
            ptr::null(),
            path_bytes.len(),
            MEM_COMMIT | MEM_RESERVE,
            PAGE_READWRITE,
        );
        if remote_buf.is_null() {
            bail!("VirtualAllocEx failed: E{}", GetLastError());
        }
        let _alloc_guard = RemoteAllocGuard {
            proc: h_proc,
            ptr: remote_buf,
        };

        let mut written: usize = 0;
        if WriteProcessMemory(
            h_proc,
            remote_buf,
            path_bytes.as_ptr().cast(),
            path_bytes.len(),
            &mut written,
        ) == 0
            || written != path_bytes.len()
        {
            bail!(
                "WriteProcessMemory failed: E{} (wrote {written}/{})",
                GetLastError(),
                path_bytes.len()
            );
        }

        let k32 = GetModuleHandleA(c"kernel32.dll".as_ptr().cast());
        if k32.is_null() {
            bail!("GetModuleHandleA(kernel32.dll) failed: E{}", GetLastError());
        }
        let p_load_library = GetProcAddress(k32, c"LoadLibraryA".as_ptr().cast())
            .ok_or_else(|| anyhow!("GetProcAddress(LoadLibraryA) failed: E{}", GetLastError()))?;

        let start_routine: LPTHREAD_START_ROUTINE = Some(std::mem::transmute::<
            unsafe extern "system" fn() -> isize,
            unsafe extern "system" fn(*mut core::ffi::c_void) -> u32,
        >(p_load_library));

        let h_thread = CreateRemoteThread(
            h_proc,
            ptr::null(),
            0,
            start_routine,
            remote_buf,
            0,
            ptr::null_mut(),
        );
        if h_thread.is_null() {
            bail!("CreateRemoteThread failed: E{}", GetLastError());
        }
        let _thread_guard = HandleGuard(h_thread);

        log_line("[+] ", "LoadLibraryA fired in target process; waiting...");
        let wait = WaitForSingleObject(h_thread, WAIT_LOAD_LIBRARY_MS);
        if wait == windows_sys::Win32::Foundation::WAIT_TIMEOUT {
            log_line(
                "[!] ",
                &format!("remote thread did not finish within {WAIT_LOAD_LIBRARY_MS} ms"),
            );
        }

        let mut thread_exit: u32 = 0;
        if GetExitCodeThread(h_thread, &mut thread_exit) == 0 {
            bail!("GetExitCodeThread failed: E{}", GetLastError());
        }

        if thread_exit == 0 {
            bail!(
                "LoadLibraryA returned 0 in target process. Bitness mismatch, \
                 missing dependency, or unhandled exception in DllMain."
            );
        }

        log_line(
            "[+] ",
            &format!("DLL mapped at HMODULE 0x{thread_exit:x} in target process."),
        );
        log_line("", "look for %TEMP%\\BetterBackpack.log for DLL output");
    }
    Ok(())
}

// RAII guards. Drop closes / frees in the target process.

struct HandleGuard(HANDLE);

impl Drop for HandleGuard {
    fn drop(&mut self) {
        unsafe {
            CloseHandle(self.0);
        }
    }
}

struct RemoteAllocGuard {
    proc: HANDLE,
    ptr: *mut core::ffi::c_void,
}

impl Drop for RemoteAllocGuard {
    fn drop(&mut self) {
        unsafe {
            VirtualFreeEx(self.proc, self.ptr, 0, MEM_RELEASE);
        }
    }
}
