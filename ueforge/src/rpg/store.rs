//! Per-slot JSON persistence under `<DLL_dir>/<subdir>/<slot>.json`.
//!
//! Atomic write: serialize -> write `<path>.tmp` -> `fsync` the
//! temp -> `rename` to `<path>`. The `fsync` step is what turns
//! "rename is atomic" into "rename is also durable across power
//! loss" -- without it a crash between the rename and the
//! kernel's own flush leaves a torn or zero-byte file.
//!
//! Generic over the persisted struct so games can attach
//! diagnostic counters or game-specific fields without forking the
//! storage layer.
//!
//! Errors: every `save` returns `io::Result<()>`. Callers MUST
//! propagate or surface; silent failure is the bug that loses
//! save data. The store also caches the last-seen save error in
//! [`Self::last_error`] so the debug snapshot can expose it
//! without having to thread the Result up through callers that
//! don't know what to do with it.

use std::fs;
use std::io::{self, Write};
use std::marker::PhantomData;
use std::path::{Path, PathBuf};

use parking_lot::Mutex;
use serde::Serialize;
use serde::de::DeserializeOwned;

pub struct SlotStore<S> {
    subdir: &'static str,
    last_error: Mutex<Option<String>>,
    _phantom: PhantomData<fn() -> S>,
}

impl<S> SlotStore<S>
where
    S: Serialize + DeserializeOwned + Default,
{
    pub const fn new(subdir: &'static str) -> Self {
        Self {
            subdir,
            last_error: Mutex::new(None),
            _phantom: PhantomData,
        }
    }

    /// `<DLL_dir>/<subdir>/<slot>.json`. Resolves through
    /// [`crate::log::dll_dir`]; falls back to CWD if the HMODULE
    /// hasn't been captured yet.
    ///
    /// The slot key is validated to reject path separators and
    /// leading dots so a user-controlled string can't escape the
    /// configured subdir. Invalid keys produce a sentinel filename
    /// (`__invalid__.json`) that visibly signals the problem to
    /// the next reader rather than silently writing somewhere
    /// unexpected.
    pub fn path(&self, slot: &str) -> PathBuf {
        let mut p = crate::log::dll_dir().unwrap_or_else(|| PathBuf::from("."));
        p.push(self.subdir);
        let safe = if is_valid_slot(slot) {
            slot
        } else {
            "__invalid__"
        };
        p.push(format!("{safe}.json"));
        p
    }

    /// Load the slot's saved state, or `S::default()` if the file
    /// is missing or unparseable. Logs the outcome. Always
    /// succeeds (silent fall-through to default is the right
    /// behavior for missing-or-corrupt save data).
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

    /// Atomic save -- write to `<path>.tmp`, fsync, rename to
    /// `<path>`. Returns the underlying `io::Result`. On error,
    /// caches the message in [`Self::last_error`] for snapshot
    /// surfaces and logs it.
    ///
    /// The fsync is what makes the rename durable. Without it,
    /// a crash between rename and the kernel's own write-back
    /// can leave a torn / zero-byte file -- the very failure
    /// mode atomic-rename was supposed to prevent.
    pub fn save(&self, slot: &str, state: &S) -> io::Result<()> {
        let path = self.path(slot);
        match save_atomic(&path, state) {
            Ok(()) => {
                self.last_error.lock().take();
                Ok(())
            }
            Err(e) => {
                let msg = format!("save to {} failed: {e}", path.display());
                crate::log!("rpg/store: {msg}");
                *self.last_error.lock() = Some(msg);
                Err(e)
            }
        }
    }

    /// Most recent save error, if any. Cleared on a successful
    /// save. For debug-snapshot surfaces.
    pub fn last_error(&self) -> Option<String> {
        self.last_error.lock().clone()
    }

    /// Clear the cached last-error. For tests that want to assert
    /// on a fresh state.
    pub fn clear_last_error(&self) {
        self.last_error.lock().take();
    }
}

fn is_valid_slot(slot: &str) -> bool {
    if slot.is_empty() {
        return false;
    }
    if slot.starts_with('.') {
        return false;
    }
    !slot.chars().any(|c| matches!(c, '/' | '\\' | ':' | '\0'))
}

fn save_atomic<S: Serialize>(path: &Path, state: &S) -> io::Result<()> {
    if let Some(parent) = path.parent() {
        fs::create_dir_all(parent)?;
    }
    let json = serde_json::to_string_pretty(state)
        .map_err(|e| io::Error::other(format!("serialize: {e}")))?;
    let tmp = path.with_extension("json.tmp");

    // Open + write + flush + fsync the temp before renaming so
    // the rename guarantees durability, not just atomicity.
    {
        let mut f = fs::File::create(&tmp)?;
        f.write_all(json.as_bytes())?;
        f.sync_all()?;
    }
    fs::rename(&tmp, path)?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use serde::{Deserialize, Serialize};

    #[derive(Default, Serialize, Deserialize, Debug, PartialEq, Eq, Clone)]
    struct State {
        a: u32,
        b: String,
    }

    #[test]
    fn slot_validation() {
        assert!(is_valid_slot("abc123"));
        assert!(is_valid_slot("save_2026"));
        assert!(is_valid_slot("0123abcd0123abcd0123abcd0123abcd"));
        // bad
        assert!(!is_valid_slot(""));
        assert!(!is_valid_slot("."));
        assert!(!is_valid_slot(".."));
        assert!(!is_valid_slot(".hidden"));
        assert!(!is_valid_slot("a/b"));
        assert!(!is_valid_slot("a\\b"));
        assert!(!is_valid_slot("c:thing"));
        assert!(!is_valid_slot("a\0b"));
    }

    #[test]
    fn save_load_round_trip() {
        let tmp = std::env::temp_dir().join(format!(
            "ueforge_slotstore_test_{}",
            std::process::id()
        ));
        let _ = fs::remove_dir_all(&tmp);
        // Force the store to write under our temp dir by setting
        // the dll_dir override -- but dll_dir is a static; we
        // can't override per-test. Instead, exercise save_atomic
        // directly.
        let path = tmp.join("save.json");
        let state = State {
            a: 42,
            b: "hello".into(),
        };
        save_atomic(&path, &state).expect("save");
        let read: State =
            serde_json::from_str(&fs::read_to_string(&path).expect("read")).expect("parse");
        assert_eq!(read, state);
        // Idempotent re-save.
        save_atomic(&path, &state).expect("save 2");
        let _ = fs::remove_dir_all(&tmp);
    }

    #[test]
    fn save_atomic_creates_parent() {
        let tmp = std::env::temp_dir().join(format!(
            "ueforge_slotstore_parent_{}",
            std::process::id()
        ));
        let _ = fs::remove_dir_all(&tmp);
        let path = tmp.join("nested").join("dir").join("save.json");
        let state = State::default();
        save_atomic(&path, &state).expect("save with nested parents");
        assert!(path.exists());
        let _ = fs::remove_dir_all(&tmp);
    }

    #[test]
    fn invalid_slot_routes_to_sentinel() {
        // We can't easily test path() without dll_dir set, so
        // verify the slot validator alone.
        assert_eq!(is_valid_slot("../escape"), false);
        assert_eq!(is_valid_slot("normal_save"), true);
    }
}
