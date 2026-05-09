//! File + console logger for Windows DLL mods.
//!
//! The DLL captures its own `HMODULE` in `DllMain`, calls
//! `set_dll_module(hmod)`, then later (from a worker thread)
//! calls `init(Config { .. })`. After init, every line goes to
//! `<DLL_dir>/<filename>` and (if `console: true`) a popped-up
//! console window titled `console_title`.
//!
//! Game-specific perf counters live in the embedding crate. Wrap
//! `log()` with a `time_scope` if you want timing. The generic
//! logger doesn't take that dep.

use std::ffi::OsString;
use std::fs::File;
use std::io::Write;
use std::os::windows::ffi::OsStringExt;
use std::path::PathBuf;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::{Mutex, OnceLock};
use std::time::SystemTime;

use windows_sys::Win32::Foundation::{HANDLE, HMODULE};
use windows_sys::Win32::System::Console::{
    AllocConsole, GetStdHandle, STD_OUTPUT_HANDLE, SetConsoleTitleW, WriteConsoleA,
};
use windows_sys::Win32::System::LibraryLoader::GetModuleFileNameW;

/// Logger configuration. Only the file is mandatory; the console
/// is feature-gated at the embedding crate's level (e.g. ship
/// builds skip it).
#[derive(Clone, Copy)]
pub struct Config {
    /// File name (no path) under the DLL's directory.
    pub file_name: &'static str,
    /// Window title for the popped-up console. Used only when
    /// `console = true`. UTF-8 input is converted to UTF-16 for
    /// `SetConsoleTitleW`.
    pub console_title: &'static str,
    /// If `true`, call `AllocConsole` during `init` and mirror
    /// every line to stdout. Off in shipping.
    pub console: bool,
}

struct Sink {
    file: Mutex<Option<File>>,
    console: HANDLE,
}

unsafe impl Send for Sink {}
unsafe impl Sync for Sink {}

static SINK: OnceLock<Sink> = OnceLock::new();

/// HMODULE of the embedding DLL, captured in `DllMain` and stored
/// here so `dll_dir()` can resolve `GetModuleFileNameW` after init.
/// Stored as `usize` so the `static` is `Sync` and zero-initialized.
static DLL_HMODULE: AtomicUsize = AtomicUsize::new(0);

/// Call from `DllMain` (or anywhere the DLL's HMODULE is known).
/// Required before `init`; without it, `dll_dir()` falls back to
/// `.\` and the log file lands wherever the host launched from.
pub fn set_dll_module(hmod: HMODULE) {
    DLL_HMODULE.store(hmod as usize, Ordering::Release);
}

/// Initialize the logger. Idempotent — second call is a no-op so
/// it's safe to wire multiple init paths.
pub fn init(cfg: Config) {
    if SINK.get().is_some() {
        return;
    }
    let console = if cfg.console {
        unsafe {
            AllocConsole();
            let title: Vec<u16> = cfg
                .console_title
                .encode_utf16()
                .chain(std::iter::once(0))
                .collect();
            SetConsoleTitleW(title.as_ptr());
            GetStdHandle(STD_OUTPUT_HANDLE)
        }
    } else {
        std::ptr::null_mut()
    };
    let path = log_path(cfg.file_name);
    let file = File::create(&path).ok();
    let _ = SINK.set(Sink {
        file: Mutex::new(file),
        console,
    });
    log(format_args!("uespy log file: {}", path.display()));
}

/// Resolve the directory containing the DLL captured via
/// `set_dll_module`. Returns `None` if the HMODULE is null or
/// `GetModuleFileNameW` fails.
pub fn dll_dir() -> Option<PathBuf> {
    let hmod = DLL_HMODULE.load(Ordering::Acquire) as HMODULE;
    if hmod.is_null() {
        return None;
    }
    let mut buf = [0u16; 1024];
    let n = unsafe { GetModuleFileNameW(hmod, buf.as_mut_ptr(), buf.len() as u32) };
    if n == 0 || (n as usize) >= buf.len() {
        return None;
    }
    let path = OsString::from_wide(&buf[..n as usize]);
    let mut p = PathBuf::from(path);
    p.pop();
    Some(p)
}

fn log_path(file_name: &str) -> PathBuf {
    dll_dir()
        .unwrap_or_else(|| PathBuf::from(".\\"))
        .join(file_name)
}

/// Write one line. Prepends a `[HH:MM:SS]` wall-clock prefix and
/// appends `\r\n`. If `init` hasn't run yet, the call is a silent
/// no-op (don't crash on early diagnostic prints).
pub fn log(args: std::fmt::Arguments<'_>) {
    let Some(sink) = SINK.get() else { return };
    let line = format_line(args);
    if !sink.console.is_null() {
        let mut written: u32 = 0;
        unsafe {
            WriteConsoleA(
                sink.console,
                line.as_ptr().cast(),
                line.len() as u32,
                &mut written,
                std::ptr::null(),
            );
        }
    }
    if let Ok(mut guard) = sink.file.lock()
        && let Some(f) = guard.as_mut()
    {
        let _ = f.write_all(&line);
        let _ = f.flush();
    }
}

fn format_line(args: std::fmt::Arguments<'_>) -> Vec<u8> {
    let secs = SystemTime::now()
        .duration_since(SystemTime::UNIX_EPOCH)
        .map(|d| d.as_secs() % 86_400)
        .unwrap_or(0);
    let h = secs / 3600;
    let m = (secs / 60) % 60;
    let s = secs % 60;
    let mut out = Vec::with_capacity(96);
    let _ = write!(&mut out, "[{:02}:{:02}:{:02}] ", h, m, s);
    let _ = out.write_fmt(args);
    out.extend_from_slice(b"\r\n");
    out
}

/// Convenience macro for embedding crates:
///
/// ```ignore
/// #[macro_export]
/// macro_rules! my_log {
///     ($($arg:tt)*) => {
///         $crate::uespy::log::log(format_args!($($arg)*))
///     };
/// }
/// ```
///
/// (Provided as a doc example, not exported, since macro_export
/// scoping wants to live in the dependent crate.)
#[doc(hidden)]
pub fn _macro_doc_anchor() {}
