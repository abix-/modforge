//! A persistent named character that exists across games: who she is and
//! what she keeps on disk between sessions and between games. Sophia is the
//! first; Charles and others follow, each a directory under Modforge/<name>
//! (or $PERSONA_HOME/<name>), never inside a build directory, so rebuilds and
//! game switches never erase her.
//!
//! Files: profile.json (name, appearance), memory.json (her
//! [`crate::memory::Memory`], the same one a brain reads each think:
//! everything she has seen is its known things, a thing she walked up to
//! is checked, what she did is its things done). Engine-free.
use crate::memory::Memory;
use serde::{Deserialize, Serialize};
use std::fs::{self, OpenOptions};
use std::io::{self, Write};
use std::path::{Path, PathBuf};

#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Profile {
    pub name: String,
    pub appearance: String,
}

/// One person, whole, the same in every game that hosts them: who they are,
/// what they remember, their needs, their personality, their skills, and
/// what they are doing now. A game keeps one for each person it hosts and
/// hands it to the brain each think.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Persona {
    pub profile: Profile,
    pub memory: Memory,
    pub needs: crate::survival::SurvivalStats,
    pub personality: crate::actor::Personality,
    pub skills: crate::practice::Skills,
    /// What they are doing now: the brain's state and what it is about.
    pub doing: crate::statetree::Record,
}

/// What a persona keeps besides its profile and memory (persona.json).
#[derive(Default, Serialize, Deserialize)]
struct Rest {
    needs: crate::survival::SurvivalStats,
    personality: crate::actor::Personality,
    skills: crate::practice::Skills,
    doing: crate::statetree::Record,
}

impl Persona {
    /// The person kept in this folder: their profile (which must be there),
    /// their memory, and the rest; what was never saved starts fresh.
    pub fn load(directory: &Path) -> io::Result<Self> {
        let profile = Profile::load(directory)?;
        let memory = load_memory(directory)?;
        let rest: Rest = match fs::read(directory.join("persona.json")) {
            Ok(bytes) => serde_json::from_slice(&bytes)?,
            Err(error) if error.kind() == io::ErrorKind::NotFound => Rest::default(),
            Err(error) => return Err(error),
        };
        Ok(Self { profile, memory, needs: rest.needs, personality: rest.personality, skills: rest.skills, doing: rest.doing })
    }

    /// Save the whole person in their folder, each file written beside and
    /// then moved in.
    pub fn save(&self, directory: &Path) -> io::Result<()> {
        fs::create_dir_all(directory)?;
        write_whole(directory, "profile.json", &serde_json::to_vec_pretty(&self.profile)?)?;
        save_memory(directory, &self.memory)?;
        let rest = Rest { needs: self.needs, personality: self.personality, skills: self.skills.clone(), doing: self.doing };
        write_whole(directory, "persona.json", &serde_json::to_vec(&rest)?)
    }
}

/// Write a file beside its place, then move it in.
fn write_whole(directory: &Path, name: &str, bytes: &[u8]) -> io::Result<()> {
    let temporary = directory.join(format!("{name}.new"));
    fs::write(&temporary, bytes)?;
    fs::rename(temporary, directory.join(name))
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
    write_whole(directory, "memory.json", &serde_json::to_vec(memory)?)
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
    fn a_whole_persona_saved_loads_the_same() {
        let directory = scratch("persona");
        let mut persona = Persona {
            profile: Profile { name: "Sophia".into(), appearance: "female".into() },
            personality: crate::actor::Personality::seed(crate::actor::ActorId(3), 9),
            ..Persona::default()
        };
        persona.memory.see(1, "pest", glam::Vec3::ONE, 4);
        persona.needs.hunger = 40.0;
        persona.skills.practise("combat", 5);
        persona.save(&directory).unwrap();
        assert_eq!(Persona::load(&directory).unwrap(), persona);
        fs::remove_dir_all(directory).unwrap();
    }

    #[test]
    fn a_named_character_and_what_she_did_survive_reopening() {
        let directory = scratch("profile");
        let first = Profile::load_or_create(&directory, "Charles", "male").unwrap();
        let mut memory = load_memory(&directory).unwrap();
        memory.did(crate::memory::Did::Done("joined at hosted save".into()), 5);
        save_memory(&directory, &memory).unwrap();
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
        assert_eq!(
            load_memory(&directory).unwrap().done,
            vec![(5, crate::memory::Did::Done("joined at hosted save".into()))]
        );
        fs::remove_dir_all(directory).unwrap();
    }
}
