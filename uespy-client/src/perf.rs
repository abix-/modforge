//! Test-side perf-log writer.
//!
//! Tee writes to stdout + a timestamped file at
//! `<repo>/perf-runs/<test_name>-<unix_ts>.txt`. The `perf-runs/`
//! directory is conventionally `.gitignore`d — runs are local
//! evidence captured during research; the committed summary lives
//! in your project's docs.
//!
//! Use in a perf test:
//!
//! ```ignore
//! use std::io::Write;
//! let mut out = uespy_client::perf::open(
//!     "leak_source",
//!     std::path::Path::new(env!("CARGO_MANIFEST_DIR")),
//! );
//! writeln!(out, "...").unwrap();
//! ```
//!
//! `env!("CARGO_MANIFEST_DIR")` MUST be evaluated in the calling
//! crate (so it resolves to the game's manifest, not uespy-client's).
//! `open` walks up from `start_dir` until it finds a `.git`
//! directory; that's the repo root that gets `perf-runs/` written
//! beneath.

use std::io::{self, Write};
use std::path::{Path, PathBuf};
use std::time::{SystemTime, UNIX_EPOCH};

pub struct PerfLog {
    path: PathBuf,
    file: std::fs::File,
}

impl PerfLog {
    pub fn path(&self) -> &Path {
        &self.path
    }
}

impl Write for PerfLog {
    fn write(&mut self, buf: &[u8]) -> io::Result<usize> {
        let _ = io::stdout().write_all(buf);
        self.file.write(buf)
    }
    fn flush(&mut self) -> io::Result<()> {
        let _ = io::stdout().flush();
        self.file.flush()
    }
}

/// Walk up from `start` until a `.git` directory is found. Returns
/// `start` unchanged if none is found within 8 levels.
fn repo_root(start: &Path) -> PathBuf {
    let mut cur = start.to_path_buf();
    for _ in 0..8 {
        if cur.join(".git").exists() {
            return cur;
        }
        if !cur.pop() {
            break;
        }
    }
    start.to_path_buf()
}

/// Open a fresh perf-run log. Prints the file path so the run is
/// self-locating, then returns a `PerfLog` that tees writes to
/// stdout and the file.
pub fn open(test_name: &str, start_dir: &Path) -> PerfLog {
    let dir = repo_root(start_dir).join("perf-runs");
    let _ = std::fs::create_dir_all(&dir);
    let ts = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_secs())
        .unwrap_or(0);
    let path = dir.join(format!("{test_name}-{ts}.txt"));
    let file = std::fs::OpenOptions::new()
        .create(true)
        .write(true)
        .truncate(true)
        .open(&path)
        .unwrap_or_else(|e| panic!("failed to open perf log {path:?}: {e}"));
    println!("=== writing perf log to: {} ===", path.display());
    PerfLog { path, file }
}
