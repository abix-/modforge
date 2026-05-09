// Logger: spawns a console window via AllocConsole and writes every line
// to both the console and %TEMP%\BetterBackpack.log. The C++ baseline did
// the same. Console output is the primary live-debug surface; the file is
// the durable record.

use std::ffi::OsString;
use std::fs::File;
use std::io::Write;
use std::os::windows::ffi::OsStringExt;
use std::path::PathBuf;
#[cfg(feature = "console")]
use std::ptr;
use std::sync::atomic::Ordering;
use std::sync::{Mutex, OnceLock};
use std::time::SystemTime;

#[cfg(feature = "console")]
use windows_sys::Win32::Foundation::HANDLE;
use windows_sys::Win32::Foundation::HMODULE;
#[cfg(feature = "console")]
use windows_sys::Win32::System::Console::{
    AllocConsole, GetStdHandle, STD_OUTPUT_HANDLE, SetConsoleTitleW, WriteConsoleA,
};
use windows_sys::Win32::System::LibraryLoader::GetModuleFileNameW;

use crate::DLL_HMODULE;

struct Sink {
    file: Mutex<Option<File>>,
    #[cfg(feature = "console")]
    console: HANDLE,
}

unsafe impl Send for Sink {}
unsafe impl Sync for Sink {}

static SINK: OnceLock<Sink> = OnceLock::new();

pub fn init() {
    if SINK.get().is_some() {
        return;
    }
    #[cfg(feature = "console")]
    let console = unsafe {
        AllocConsole();
        let title: Vec<u16> = "Better Backpack\0".encode_utf16().collect();
        SetConsoleTitleW(title.as_ptr());
        GetStdHandle(STD_OUTPUT_HANDLE)
    };
    let path = log_path();
    let file = File::create(&path).ok();
    let _ = SINK.set(Sink {
        file: Mutex::new(file),
        #[cfg(feature = "console")]
        console,
    });
    log(format_args!("log file: {}", path.display()));
}

fn log_path() -> PathBuf {
    dll_dir()
        .unwrap_or_else(|| PathBuf::from(".\\"))
        .join("better_backpack.log")
}

/// Directory containing our own DLL. Resolved via GetModuleFileNameW
/// against the HMODULE captured in DllMain.
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
    p.pop(); // strip filename, keep directory
    Some(p)
}

pub fn log(args: std::fmt::Arguments<'_>) {
    let Some(sink) = SINK.get() else { return };
    let line = format_line(args);
    #[cfg(feature = "console")]
    if !sink.console.is_null() {
        let mut written: u32 = 0;
        unsafe {
            WriteConsoleA(
                sink.console,
                line.as_ptr().cast(),
                line.len() as u32,
                &mut written,
                ptr::null(),
            );
        }
    }
    let _t = crate::counters::time_scope(&crate::counters::TIME_NS_BBP_LOG);
    crate::counters::bump(&crate::counters::BBP_LOG_LINES);
    if let Ok(mut guard) = sink.file.lock()
        && let Some(f) = guard.as_mut()
    {
        let _ = f.write_all(&line);
        crate::counters::bump(&crate::counters::BBP_LOG_FSYNCS);
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

#[macro_export]
macro_rules! bbp_log {
    ($($arg:tt)*) => {
        $crate::log::log(format_args!($($arg)*))
    };
}
