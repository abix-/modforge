//! modforge-inject. Inject + hot-reload a mod DLL in a running
//! native-PE game. See `modforge::inject`.

use std::path::PathBuf;

use clap::Parser;

#[derive(Parser, Debug)]
#[command(version, about = "Inject + hot-reload a mod DLL in a running game")]
struct Args {
    /// Path to the freshly-built mod DLL.
    #[arg(long)]
    dll: PathBuf,

    /// Target process executable name, e.g. `JA3.exe`.
    #[arg(long)]
    process: String,

    /// The mod's HTTP control-plane port, asked to `_shutdown`
    /// before a reload unloads the old generation.
    #[arg(long)]
    port: u16,

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
    if args.reload {
        modforge::inject::reload(&args.dll, &args.process, args.port)
    } else {
        modforge::inject::inject(&args.dll, &args.process, args.fresh)
    }
}
