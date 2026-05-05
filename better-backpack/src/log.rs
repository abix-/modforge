// File-only logger. Drops to %TEMP%\BetterBackpack.log. The C++ baseline
// also wired up a console via AllocConsole, but the file is the durable
// channel; we'll add console output back if we miss it.

use std::fs::File;
use std::io::Write;
use std::path::PathBuf;
use std::sync::{Mutex, OnceLock};
use std::time::SystemTime;

use windows_sys::Win32::Storage::FileSystem::GetTempPathA;

struct Sink {
    file: Mutex<Option<File>>,
}

static SINK: OnceLock<Sink> = OnceLock::new();

pub fn init() {
    if SINK.get().is_some() {
        return;
    }
    let path = log_path();
    let file = File::create(&path).ok();
    let _ = SINK.set(Sink {
        file: Mutex::new(file),
    });
    log(format_args!("log file: {}", path.display()));
}

fn log_path() -> PathBuf {
    let mut buf = vec![0u8; 1024];
    let n = unsafe { GetTempPathA(buf.len() as u32, buf.as_mut_ptr()) };
    let dir = if n > 0 && (n as usize) < buf.len() {
        let s = String::from_utf8_lossy(&buf[..n as usize]).to_string();
        PathBuf::from(s)
    } else {
        PathBuf::from(".\\")
    };
    dir.join("BetterBackpack.log")
}

pub fn log(args: std::fmt::Arguments<'_>) {
    let Some(sink) = SINK.get() else { return };
    let line = format_line(args);
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

#[macro_export]
macro_rules! bbp_log {
    ($($arg:tt)*) => {
        $crate::log::log(format_args!($($arg)*))
    };
}
