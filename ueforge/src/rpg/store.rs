//! Per-slot JSON persistence under `<DLL_dir>/<subdir>/<slot>.json`.
//! Atomic write (temp + rename). Generic over the persisted struct
//! so games can attach diagnostic counters or game-specific fields
//! without forking the storage layer.

use std::fs;
use std::marker::PhantomData;
use std::path::{Path, PathBuf};

use serde::Serialize;
use serde::de::DeserializeOwned;

pub struct SlotStore<S> {
    subdir: &'static str,
    _phantom: PhantomData<fn() -> S>,
}

impl<S> SlotStore<S>
where
    S: Serialize + DeserializeOwned + Default,
{
    pub const fn new(subdir: &'static str) -> Self {
        Self {
            subdir,
            _phantom: PhantomData,
        }
    }

    /// `<DLL_dir>/<subdir>/<slot>.json`. Resolves through
    /// [`crate::log::dll_dir`]; falls back to CWD if the HMODULE
    /// hasn't been captured yet.
    pub fn path(&self, slot: &str) -> PathBuf {
        let mut p = crate::log::dll_dir().unwrap_or_else(|| PathBuf::from("."));
        p.push(self.subdir);
        p.push(format!("{slot}.json"));
        p
    }

    /// Load the slot's saved state, or `S::default()` if the file is
    /// missing or unparseable. Logs the outcome.
    pub fn load(&self, slot: &str) -> S {
        let path = self.path(slot);
        match fs::read_to_string(&path) {
            Ok(text) => match serde_json::from_str::<S>(&text) {
                Ok(s) => s,
                Err(e) => {
                    crate::log!(
                        "rpg/store: parse failed for {} ({e}); starting fresh",
                        path.display()
                    );
                    S::default()
                }
            },
            Err(_) => {
                crate::log!(
                    "rpg/store: no prior save at {}; starting fresh",
                    path.display()
                );
                S::default()
            }
        }
    }

    /// Atomic save -- write to `<path>.tmp`, rename to `<path>`.
    pub fn save(&self, slot: &str, state: &S) {
        let path = self.path(slot);
        if let Err(e) = save_atomic(&path, state) {
            crate::log!("rpg/store: save to {} failed: {e}", path.display());
        }
    }
}

fn save_atomic<S: Serialize>(path: &Path, state: &S) -> std::io::Result<()> {
    if let Some(parent) = path.parent() {
        fs::create_dir_all(parent)?;
    }
    let json = serde_json::to_string_pretty(state)
        .map_err(|e| std::io::Error::other(format!("serialize: {e}")))?;
    let tmp = path.with_extension("json.tmp");
    fs::write(&tmp, json)?;
    fs::rename(&tmp, path)?;
    Ok(())
}
