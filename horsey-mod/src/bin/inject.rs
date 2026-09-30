//! horsey-inject. Inject + hot-reload horsey.dll in a running
//! Horsey.exe through `modforge::inject`, plus the one Horsey-only
//! step: dropping the bestiary next to the staged DLL.

use std::path::{Path, PathBuf};

use clap::Parser;

/// horsey.dll's HTTP control plane (see lib.rs worker_main).
const HTTP_PORT: u16 = 33077;

#[derive(Parser, Debug)]
#[command(version, about = "Inject + hot-reload horsey.dll in Horsey.exe")]
struct Args {
    /// Path to the freshly-built horsey.dll (cargo's release output).
    /// Defaults to `./horsey.dll` next to the injector binary.
    #[arg(long)]
    dll: Option<PathBuf>,

    /// Target process executable name to search for.
    #[arg(long, default_value = "Horsey.exe")]
    process: String,

    /// Hot-reload: shutdown + unload the current generation, stage the
    /// new DLL, load it.
    #[arg(long)]
    reload: bool,

    /// Discard any existing injstate and inject as if for the first time.
    #[arg(long)]
    fresh: bool,
}

fn main() -> anyhow::Result<()> {
    let args = Args::parse();

    let source_dll = match args.dll.clone() {
        Some(p) => p,
        None => std::env::current_exe()?
            .parent()
            .ok_or_else(|| anyhow::anyhow!("injector has no parent dir"))?
            .join("horsey.dll"),
    };
    if let Some(dll_dir) = source_dll.parent() {
        stage_bestiary(dll_dir);
    }

    if args.reload {
        modforge::inject::reload(&source_dll, &args.process, HTTP_PORT)
    } else {
        modforge::inject::inject(&source_dll, &args.process, args.fresh)
    }
}

/// Drop the bestiary `genes-extended.xml` next to the staged DLL so
/// horsey.dll's worker_main auto-loads it at attach. Skipped silently
/// if the source file is missing (e.g. crate moved); skipped if a
/// genes-extended.xml is already present so the player's edits don't
/// get clobbered on re-inject.
fn stage_bestiary(dll_dir: &Path) {
    let src = Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("bestiary")
        .join("genes-extended.xml");
    if !src.exists() {
        return;
    }
    let dst = dll_dir.join("genes-extended.xml");
    if dst.exists() {
        println!(
            "[inject] genes-extended.xml already at {} (leaving user copy)",
            dst.display()
        );
        return;
    }
    match std::fs::copy(&src, &dst) {
        Ok(_) => println!("[inject] staged bestiary: {}", dst.display()),
        Err(e) => println!("[inject] WARN: stage bestiary failed: {e}"),
    }
}
