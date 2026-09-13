//! Sophia's persistent profile: her name and appearance in profile.json,
//! an append-only journal in memory.jsonl, and everything she has ever
//! perceived in seen.json. Stored outside the build directory so rebuilds
//! never erase her.
use serde::{Deserialize, Serialize};
use std::fs::{self, OpenOptions};
use std::io::{self, Write};
use std::path::{Path, PathBuf};
use std::time::{SystemTime, UNIX_EPOCH};

#[derive(Serialize, Deserialize)]
pub struct Profile {
    pub name: String,
    pub appearance: String,
}

impl Profile {
    /// Load an existing profile without creating or changing it.
    pub fn load(directory: &Path) -> io::Result<Self> {
        Ok(serde_json::from_slice(&fs::read(directory.join("profile.json"))?)?)
    }

    pub fn load_or_create(directory: &Path) -> io::Result<Self> {
        fs::create_dir_all(directory)?;
        let path = directory.join("profile.json");
        match Self::load(directory) {
            Ok(profile) => Ok(profile),
            Err(error) if error.kind() == io::ErrorKind::NotFound => {
                let profile = Self { name: "Sophia".into(), appearance: "female".into() };
                let mut file = OpenOptions::new().write(true).create_new(true).open(path)?;
                file.write_all(&serde_json::to_vec_pretty(&profile)?)?;
                file.sync_all()?;
                Ok(profile)
            }
            Err(error) => Err(error),
        }
    }
}

/// Stored outside the build directory so rebuilds do not erase Sophia.
pub fn directory() -> io::Result<PathBuf> {
    if let Some(path) = std::env::var_os("SOPHIA_HOME") { return Ok(path.into()); }
    std::env::var_os("LOCALAPPDATA")
        .map(|path| PathBuf::from(path).join("Modforge/Sophia"))
        .ok_or_else(|| io::Error::new(io::ErrorKind::NotFound, "set SOPHIA_HOME or LOCALAPPDATA"))
}

/// Journal one observed event.
pub fn remember(directory: &Path, event: &str, detail: &str) -> io::Result<()> {
    let seconds = SystemTime::now().duration_since(UNIX_EPOCH).map_err(io::Error::other)?.as_secs();
    let entry = serde_json::json!({"time":seconds,"event":event,"detail":detail});
    let mut file = OpenOptions::new().create(true).append(true).open(directory.join("memory.jsonl"))?;
    writeln!(file, "{entry}")?;
    file.sync_data()
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

/// Everything she has ever perceived, persisted in her profile as seen.json.
/// Only perception writes here; nothing is looked up from the world.
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

/// The journal, oldest first.
#[cfg(test)]
pub fn recall(directory: &Path) -> io::Result<Vec<serde_json::Value>> {
    let text = match fs::read_to_string(directory.join("memory.jsonl")) {
        Ok(text) => text,
        Err(error) if error.kind() == io::ErrorKind::NotFound => return Ok(Vec::new()),
        Err(error) => return Err(error),
    };
    text.lines().map(|line| serde_json::from_str(line).map_err(io::Error::from)).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn seen_things_persist_and_count_repeat_sightings() {
        let directory = std::env::temp_dir().join(format!("sophia-seen-{:016x}", fastrand::u64(..)));
        let mut seen = Seen::load(&directory).unwrap();
        assert!(seen.note("Pest_1", "NPC_Monster_Pest_C", [1.0, 2.0, 3.0]), "first sighting is new");
        assert!(!seen.note("Pest_1", "NPC_Monster_Pest_C", [4.0, 5.0, 6.0]), "second sighting is not");
        seen.save(&directory).unwrap();
        let again = Seen::load(&directory).unwrap();
        let thing = &again.things["Pest_1"];
        assert_eq!((thing.times_seen, thing.location, thing.visited), (2, [4.0, 5.0, 6.0], false));
        fs::remove_file(directory.join("seen.json")).unwrap();
        fs::remove_dir(directory).unwrap();
    }

    #[test]
    fn identity_and_memory_survive_reopening() {
        let directory = std::env::temp_dir().join(format!("sophia-profile-{:016x}", fastrand::u64(..)));
        let first = Profile::load_or_create(&directory).unwrap();
        remember(&directory, "joined", "hosted save").unwrap();
        let second = Profile::load_or_create(&directory).unwrap();
        assert_eq!(first.name, second.name);
        assert_eq!(second.name, "Sophia");
        assert_eq!(second.appearance, "female");
        assert_eq!(recall(&directory).unwrap()[0]["event"], "joined");
        fs::remove_file(directory.join("profile.json")).unwrap();
        fs::remove_file(directory.join("memory.jsonl")).unwrap();
        fs::remove_dir(directory).unwrap();
    }
}
