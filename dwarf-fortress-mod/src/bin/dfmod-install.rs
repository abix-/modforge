use std::path::{Path, PathBuf};

const DEFAULT_GAME_DIR: &str = r"C:\Games\Steam\steamapps\common\Dwarf Fortress";

fn require_file(path: &Path, purpose: &str) -> Result<(), String> {
    if path.is_file() {
        Ok(())
    } else {
        Err(format!("{purpose} not found: {}", path.display()))
    }
}

fn run() -> Result<(), String> {
    let game_dir = std::env::args_os()
        .nth(1)
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from(DEFAULT_GAME_DIR));
    let manifest_dir = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let workspace_dir = manifest_dir
        .parent()
        .ok_or_else(|| "crate has no workspace parent".to_string())?;

    require_file(&game_dir.join("Dwarf Fortress.exe"), "Dwarf Fortress")?;
    require_file(&game_dir.join("dfhooks.dll"), "DFHack dfhooks chainloader")?;

    let source_dll = [
        workspace_dir
            .join("target")
            .join("x86_64-pc-windows-msvc")
            .join("release")
            .join("dfhooks_modforge.dll"),
        workspace_dir
            .join("target")
            .join("release")
            .join("dfhooks_modforge.dll"),
    ]
    .into_iter()
    .find(|path| path.is_file())
    .unwrap_or_else(|| {
        workspace_dir
            .join("target")
            .join("release")
            .join("dfhooks_modforge.dll")
    });
    require_file(&source_dll, "release adapter")?;

    let target_dll = game_dir.join("dfhooks_modforge.dll");
    std::fs::copy(&source_dll, &target_dll).map_err(|e| {
        format!(
            "failed to stage {} to {}: {e}",
            source_dll.display(),
            target_dll.display()
        )
    })?;

    let scripts_dir = game_dir.join("dfhack-config").join("scripts");
    std::fs::create_dir_all(&scripts_dir)
        .map_err(|e| format!("failed to create {}: {e}", scripts_dir.display()))?;
    let source_script = manifest_dir
        .join("dfhack")
        .join("scripts_modinstalled")
        .join("modforge-ghost-target.lua");
    let target_script = scripts_dir.join("modforge-ghost-target.lua");
    std::fs::copy(&source_script, &target_script).map_err(|e| {
        format!(
            "failed to stage {} to {}: {e}",
            source_script.display(),
            target_script.display()
        )
    })?;

    println!("staged {}", target_dll.display());
    println!("staged {}", target_script.display());
    println!("restart Dwarf Fortress to load the native adapter");
    Ok(())
}

fn main() {
    if let Err(error) = run() {
        eprintln!("dfmod-install: {error}");
        std::process::exit(1);
    }
}
