//! Install the mod into Dungeonbound's folder. The game must be
//! closed: Windows will not replace a loaded DLL.
//!
//! The installed GodotSteam file is renamed to the `.original.dll`
//! name when it is GodotSteam (not ours), so a game update that
//! brings a new GodotSteam is picked up on the next deploy.
//!
//! Usage: `deploy [game folder]`.

use std::path::PathBuf;

use anyhow::{Context, bail};

const DEFAULT_GAME_DIR: &str = r"C:\Games\Steam\steamapps\common\Dungeonbound";
const GODOTSTEAM: &str = "libgodotsteam.windows.template_release.x86_64.dll";
const GODOTSTEAM_ORIGINAL: &str = "libgodotsteam.windows.template_release.x86_64.original.dll";
/// Only our DLL exports this.
const OUR_EXPORT: &[u8] = b"dungeonbound_gdext_init";

fn main() -> anyhow::Result<()> {
    let game = std::env::args()
        .nth(1)
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from(DEFAULT_GAME_DIR));
    let exe = std::env::current_exe()?;
    // Built beside this exe, in the same profile folder.
    let built = exe
        .parent()
        .context("deploy exe has no parent folder")?
        .join("dungeonbound_mod.dll");
    if !built.exists() {
        bail!("{} not built", built.display());
    }

    let installed = game.join(GODOTSTEAM);
    let original = game.join(GODOTSTEAM_ORIGINAL);
    if installed.exists() {
        let bytes = std::fs::read(&installed)?;
        let ours = bytes.windows(OUR_EXPORT.len()).any(|w| w == OUR_EXPORT);
        if !ours {
            std::fs::rename(&installed, &original).with_context(|| {
                format!("rename {} (is the game running?)", installed.display())
            })?;
            println!("GodotSteam moved to {}", original.display());
        }
    }
    if !original.exists() {
        bail!(
            "{} missing; verify the game files in Steam",
            original.display()
        );
    }
    std::fs::copy(&built, &installed)
        .with_context(|| format!("copy to {} (is the game running?)", installed.display()))?;
    println!("installed {}", installed.display());
    Ok(())
}
