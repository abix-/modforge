//! A persistent named character that exists across games: who she is and
//! what she keeps on disk between sessions and between games. Sophia is the
//! first; Charles and others follow, each a directory under Modforge/<name>
//! (or $PERSONA_HOME/<name>), never inside a build directory, so rebuilds and
//! game switches never erase her.
//!
//! Three files: profile.json (name, appearance), memory.jsonl (an
//! append-only journal of events), seen.json (everything she has ever
//! perceived, by actor name, with where and when and whether she went
//! there). Engine-free: plain strings and positions.
//!
//! This is the persistent record. The in-RAM working memory a brain reads
//! each tick is [`crate::memory::Memory`]; a game crate feeds one from the
//! other. Unifying the two is an open design item.
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
        Ok(serde_json::from_slice(&fs::read(directory.join("profile.json"))?)?)
    }

    /// Load the named character's profile, creating it on first use.
    pub fn load_or_create(directory: &Path, name: &str, appearance: &str) -> io::Result<Self> {
        fs::create_dir_all(directory)?;
        let path = directory.join("profile.json");
        match Self::load(directory) {
            Ok(profile) => Ok(profile),
            Err(error) if error.kind() == io::ErrorKind::NotFound => {
                let profile = Self { name: name.to_owned(), appearance: appearance.to_owned() };
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
    if let Some(root) = std::env::var_os("PERSONA_HOME") { return Ok(PathBuf::from(root).join(name)); }
    std::env::var_os("LOCALAPPDATA")
        .map(|path| PathBuf::from(path).join("Modforge").join(name))
        .ok_or_else(|| io::Error::new(io::ErrorKind::NotFound, "set PERSONA_HOME or LOCALAPPDATA"))
}

/// Journal one observed event.
pub fn remember(directory: &Path, event: &str, detail: &str) -> io::Result<()> {
    let seconds = SystemTime::now().duration_since(UNIX_EPOCH).map_err(io::Error::other)?.as_secs();
    let entry = serde_json::json!({"time":seconds,"event":event,"detail":detail});
    let mut file = OpenOptions::new().create(true).append(true).open(directory.join("memory.jsonl"))?;
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
    text.lines().map(|line| serde_json::from_str(line).map_err(io::Error::from)).collect()
}

/// One thing she has perceived, by the actor's name: what it is, where it
/// was when last seen, when, how often, and whether she has walked up to it.
#[derive(Clone, Debug, Serialize, Deserialize, PartialEq)]
pub struct SeenThing {
    pub class: String,
    pub location: [f64; 3],
    pub first_seen: u64,
    pub last_seen: u64,
    pub times_seen: u32,
    pub visited: bool,
}

/// Everything she has ever perceived, persisted as seen.json. Only
/// perception writes here; nothing is looked up from the world.
#[derive(Default, Serialize, Deserialize)]
pub struct Seen {
    pub things: std::collections::BTreeMap<String, SeenThing>,
}

impl Seen {
    pub fn load(directory: &Path) -> io::Result<Self> {
        match fs::read(directory.join("seen.json")) {
            Ok(bytes) => Ok(serde_json::from_slice(&bytes)?),
            Err(error) if error.kind() == io::ErrorKind::NotFound => Ok(Self::default()),
            Err(error) => Err(error),
        }
    }

    pub fn save(&self, directory: &Path) -> io::Result<()> {
        fs::create_dir_all(directory)?;
        let bytes = serde_json::to_vec_pretty(self)?;
        let path = directory.join("seen.json");
        let temporary = directory.join("seen.json.new");
        fs::write(&temporary, bytes)?;
        fs::rename(temporary, path)
    }

    /// Record one perception; returns true when this thing is new to her.
    pub fn note(&mut self, name: &str, class: &str, location: [f64; 3]) -> bool {
        let now = SystemTime::now().duration_since(UNIX_EPOCH).map(|d| d.as_secs()).unwrap_or(0);
        match self.things.get_mut(name) {
            Some(thing) => { thing.location = location; thing.last_seen = now; thing.times_seen += 1; false }
            None => { self.things.insert(name.to_owned(), SeenThing { class: class.to_owned(), location, first_seen: now, last_seen: now, times_seen: 1, visited: false }); true }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn scratch(tag: &str) -> PathBuf {
        std::env::temp_dir().join(format!("persona-{tag}-{:016x}", fastrand::u64(..)))
    }

    #[test]
    fn seen_things_persist_and_count_repeat_sightings() {
        let directory = scratch("seen");
        let mut seen = Seen::load(&directory).unwrap();
        assert!(seen.note("Pest_1", "NPC_Monster_Pest_C", [1.0, 2.0, 3.0]), "first sighting is new");
        assert!(!seen.note("Pest_1", "NPC_Monster_Pest_C", [4.0, 5.0, 6.0]), "second sighting is not");
        seen.save(&directory).unwrap();
        let again = Seen::load(&directory).unwrap();
        let thing = &again.things["Pest_1"];
        assert_eq!((thing.times_seen, thing.location, thing.visited), (2, [4.0, 5.0, 6.0], false));
        fs::remove_dir_all(directory).unwrap();
    }

    #[test]
    fn a_named_character_and_her_journal_survive_reopening() {
        let directory = scratch("profile");
        let first = Profile::load_or_create(&directory, "Charles", "male").unwrap();
        remember(&directory, "joined", "hosted save").unwrap();
        let second = Profile::load_or_create(&directory, "Charles", "female").unwrap();
        assert_eq!((first.name.as_str(), second.name.as_str(), second.appearance.as_str()), ("Charles", "Charles", "male"), "the first creation wins; later calls only load");
        assert_eq!(recall(&directory).unwrap()[0]["event"], "joined");
        fs::remove_dir_all(directory).unwrap();
    }
}
