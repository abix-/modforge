//! A persistent named character that exists across games: who she is and
//! what she keeps on disk between sessions and between games. Sophia is the
//! first; Charles and others follow, each a directory under Modforge/<name>
//! (or $PERSONA_HOME/<name>), never inside a build directory, so rebuilds and
//! game switches never erase her.
//!
//! Files: profile.json (name, appearance), memory.json (her
//! [`crate::memory::Memory`], the same one a brain reads each think:
//! everything she has seen is its known things, a thing she walked up to
//! is checked), memory.jsonl (an append-only journal of events).
//! Engine-free.
use crate::memory::Memory;
use serde::{Deserialize, Serialize};
use std::fs::{self, OpenOptions};
use std::io::{self, Write};
use std::path::{Path, PathBuf};
use std::time::{SystemTime, UNIX_EPOCH};

#[derive(Clone, Serialize, Deserialize)]
pub struct Profile {
    pub name: String,
    pub appearance: String,
}

impl Profile {
    /// Load an existing profile without creating or changing it.
    pub fn load(directory: &Path) -> io::Result<Self> {
        Ok(serde_json::from_slice(&fs::read(
            directory.join("profile.json"),
        )?)?)
    }

    /// Load the named character's profile, creating it on first use.
    pub fn load_or_create(directory: &Path, name: &str, appearance: &str) -> io::Result<Self> {
        fs::create_dir_all(directory)?;
        let path = directory.join("profile.json");
        match Self::load(directory) {
            Ok(profile) => Ok(profile),
            Err(error) if error.kind() == io::ErrorKind::NotFound => {
                let profile = Self {
                    name: name.to_owned(),
                    appearance: appearance.to_owned(),
                };
                let mut file = OpenOptions::new().write(true).create_new(true).open(path)?;
                file.write_all(&serde_json::to_vec_pretty(&profile)?)?;
                file.sync_all()?;
                Ok(profile)
            }
            Err(error) => Err(error),
        }
    }
}

/// Where a named character lives: $PERSONA_HOME/<name>, else
/// %LOCALAPPDATA%/Modforge/<name>. Outside every build directory.
pub fn directory(name: &str) -> io::Result<PathBuf> {
    if let Some(root) = std::env::var_os("PERSONA_HOME") {
        return Ok(PathBuf::from(root).join(name));
    }
    std::env::var_os("LOCALAPPDATA")
        .map(|path| PathBuf::from(path).join("Modforge").join(name))
        .ok_or_else(|| io::Error::new(io::ErrorKind::NotFound, "set PERSONA_HOME or LOCALAPPDATA"))
}

/// A person's memory as it was last saved in their folder (memory.json):
/// the same `Memory` a brain reads each think, so what they knew in one
/// session or one game they know in the next. Empty the first time.
pub fn load_memory(directory: &Path) -> io::Result<Memory> {
    match fs::read(directory.join("memory.json")) {
        Ok(bytes) => Ok(serde_json::from_slice(&bytes)?),
        Err(error) if error.kind() == io::ErrorKind::NotFound => Ok(Memory::default()),
        Err(error) => Err(error),
    }
}

/// Save a person's memory in their folder, whole, written beside and then
/// moved in, so a crash never leaves half of it.
pub fn save_memory(directory: &Path, memory: &Memory) -> io::Result<()> {
    fs::create_dir_all(directory)?;
    let temporary = directory.join("memory.json.new");
    fs::write(&temporary, serde_json::to_vec(memory)?)?;
    fs::rename(temporary, directory.join("memory.json"))
}

/// Journal one observed event.
pub fn remember(directory: &Path, event: &str, detail: &str) -> io::Result<()> {
    let seconds = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map_err(io::Error::other)?
        .as_secs();
    let entry = serde_json::json!({"time":seconds,"event":event,"detail":detail});
    let mut file = OpenOptions::new()
        .create(true)
        .append(true)
        .open(directory.join("memory.jsonl"))?;
    writeln!(file, "{entry}")?;
    file.sync_data()
}

/// The journal, oldest first.
pub fn recall(directory: &Path) -> io::Result<Vec<serde_json::Value>> {
    let text = match fs::read_to_string(directory.join("memory.jsonl")) {
        Ok(text) => text,
        Err(error) if error.kind() == io::ErrorKind::NotFound => return Ok(Vec::new()),
        Err(error) => return Err(error),
    };
    text.lines()
        .map(|line| serde_json::from_str(line).map_err(io::Error::from))
        .collect()
}

/// The key a thing a game knows only by name is remembered under in
/// `Memory` (an Unreal actor's name): the same name, the same key, in every
/// session (FNV-1a).
pub fn key_of(name: &str) -> u64 {
    name.bytes().fold(0xcbf2_9ce4_8422_2325, |h, b| (h ^ u64::from(b)).wrapping_mul(0x0100_0000_01b3))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn scratch(tag: &str) -> PathBuf {
        std::env::temp_dir().join(format!("persona-{tag}-{:016x}", fastrand::u64(..)))
    }

    #[test]
    fn a_thing_seen_by_name_is_one_known_thing_where_last_seen() {
        let directory = scratch("seen");
        let mut memory = load_memory(&directory).unwrap();
        let key = key_of("Pest_1");
        assert_eq!(key, key_of("Pest_1"), "the same name, the same key");
        assert_ne!(key, key_of("Pest_2"));
        memory.see(key, "NPC_Monster_Pest_C", glam::Vec3::new(1.0, 2.0, 3.0), 10);
        memory.see(key, "NPC_Monster_Pest_C", glam::Vec3::new(4.0, 5.0, 6.0), 20);
        save_memory(&directory, &memory).unwrap();
        let again = load_memory(&directory).unwrap();
        assert_eq!(again.known.len(), 1, "seen twice, known once");
        let thing = &again.known[0];
        assert_eq!((thing.position, thing.seen_at, thing.checked_at), (glam::Vec3::new(4.0, 5.0, 6.0), 20, None));
        fs::remove_dir_all(directory).unwrap();
    }

    #[test]
    fn memory_saved_in_the_persona_folder_loads_the_same() {
        let directory = scratch("memory");
        assert_eq!(load_memory(&directory).unwrap(), Memory::default(), "empty the first time");
        let mut memory = Memory::default();
        memory.see(7, "pest", glam::Vec3::new(1.0, 2.0, 3.0), 10);
        memory.visited(7, 12);
        save_memory(&directory, &memory).unwrap();
        assert_eq!(load_memory(&directory).unwrap(), memory);
        fs::remove_dir_all(directory).unwrap();
    }

    #[test]
    fn a_named_character_and_her_journal_survive_reopening() {
        let directory = scratch("profile");
        let first = Profile::load_or_create(&directory, "Charles", "male").unwrap();
        remember(&directory, "joined", "hosted save").unwrap();
        let second = Profile::load_or_create(&directory, "Charles", "female").unwrap();
        assert_eq!(
            (
                first.name.as_str(),
                second.name.as_str(),
                second.appearance.as_str()
            ),
            ("Charles", "Charles", "male"),
            "the first creation wins; later calls only load"
        );
        assert_eq!(recall(&directory).unwrap()[0]["event"], "joined");
        fs::remove_dir_all(directory).unwrap();
    }
}
