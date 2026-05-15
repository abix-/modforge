//! Shared test harness for horsey-mod integration tests.
//!
//! Each test launches a fresh Horsey instance via `modforge::harness`,
//! injects `horsey.dll`, and tears down on Drop. Run with
//! `--test-threads=1` so tests don't fight over the single game
//! process.
//!
//! Env vars:
//! - `MODFORGE_NO_GAME=1` skips the launch; tests return cleanly.
//! - `MODFORGE_SKIP_BUILD=1` skips `cargo build` for fast iteration.
//! - `MODFORGE_STEAM_EXE=<path>` overrides the Steam executable
//!   path (default `C:\Games\Steam\steam.exe`).

#![allow(dead_code)]

use modforge::harness::{
    BuildSpec, GameHarness, GameSpec, HttpProbe, InjectorSpec, RunningGame,
};
use std::path::{Path, PathBuf};
use std::time::Duration;

/// Horsey on Steam.
const STEAM_APP_ID: u32 = 3602570;
const PROCESS_NAME: &str = "Horsey.exe";
const HTTP_PORT: u16 = 33077;
const HTTP_ENDPOINT: &str = "/op";

fn workspace_root() -> PathBuf {
    // CARGO_MANIFEST_DIR points at horsey-mod; parent is the
    // workspace root.
    let manifest = Path::new(env!("CARGO_MANIFEST_DIR"));
    manifest
        .parent()
        .expect("horsey-mod has no parent dir")
        .to_path_buf()
}

fn injector_exe() -> PathBuf {
    // cargo build puts the injector at
    // target/x86_64-pc-windows-msvc/debug/horsey-inject.exe.
    workspace_root()
        .join("target")
        .join("x86_64-pc-windows-msvc")
        .join("debug")
        .join("horsey-inject.exe")
}

pub fn spec() -> GameSpec {
    let mut spec = GameSpec::defaults(
        STEAM_APP_ID,
        PROCESS_NAME,
        HttpProbe::new(HTTP_PORT, HTTP_ENDPOINT),
    );
    let mut inj = InjectorSpec::new(injector_exe());
    // Always start from a clean injector state for tests. Without
    // this, horsey-inject sees the previous run's `.injstate` and
    // refuses with "use --reload to swap, or --fresh to ignore".
    inj.args.push("--fresh".into());
    spec.injector = Some(inj);
    spec.build = Some(BuildSpec {
        package: "horsey-mod",
        release: false,
        workspace_dir: workspace_root(),
    });
    spec.launch_timeout = Duration::from_secs(180);
    spec
}

/// Launch a fresh game + inject the mod + wait for HTTP ready.
/// `test_name` is used to name the per-run log file under
/// `target/test-runs/`.
///
/// Returns `None` if `MODFORGE_NO_GAME` is set so callers can
/// `let Some(game) = common::launch("smoke") else { return; };` cleanly.
pub fn launch(test_name: &str) -> Option<RunningGame> {
    if modforge::harness::should_skip() {
        eprintln!("MODFORGE_NO_GAME=1, skipping live-game test");
        return None;
    }
    let s = spec();
    match GameHarness::launch(&s, test_name) {
        Ok(g) => Some(g),
        Err(e) => panic!("harness launch failed: {e}"),
    }
}
