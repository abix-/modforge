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

    /// The named person in their folder, made on first use: every game
    /// that opens the same name in the same folder hosts the same person
    /// (what one game saved, the next loads).
    pub fn open(directory: &Path, name: &str, appearance: &str) -> io::Result<Self> {
        Profile::load_or_create(directory, name, appearance)?;
        Self::load(directory)
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

/// What a game writes to host a Persona (authority.md "Binder": eyes and
/// hands into one world, never deciding): what the person senses there,
/// what a thing of that game is worth for a need, and the brain's actions
/// carried out with the game's own hands. The brain decides; the binder
/// only senses and acts.
pub trait PersonaBinder {
    /// What the person senses now in this game, filled from its world;
    /// `worth` is this binder's own `worth`, handed back for the brain.
    fn perceive<'a>(
        &'a self,
        persona: &'a Persona,
        worth: &'a dyn Fn(&crate::memory::Known, crate::survival::Need) -> f32,
    ) -> crate::brain::Perception<'a>;

    /// What a remembered thing of this game is worth for a need (the
    /// game's registry answers; memory only remembers the kind).
    fn worth(&self, known: &crate::memory::Known, need: crate::survival::Need) -> f32;

    /// Carry out what the brain decided this think.
    fn act(&mut self, actions: Vec<crate::actions::Action>, do_now: Option<crate::brain::Do>);

    /// The game's rates for the person's needs and the seconds since the
    /// last think, when the Persona's needs drain in this game; None
    /// when the game keeps the needs itself (topside's survival tick).
    fn needs_drain(&self) -> Option<(crate::survival::SurvivalRates, f32)> {
        None
    }
}

/// One think of a person hosted by a game: the binder senses, the game's
/// tree decides (seeded by `roll`), what they chose goes to what they
/// learn from, the needs drain for the time since the last think when the
/// game asks (`needs_drain`), and the binder carries out the actions.
pub fn think<B: PersonaBinder>(
    binder: &mut B,
    persona: &mut Persona,
    tree: &crate::statetree::StateTree<crate::brain::Brain>,
    roll: &mut crate::monument::Roll,
) {
    let mut doing = persona.doing;
    let (actions, do_now, situation, chose, condition) = {
        let worth = |k: &crate::memory::Known, n| binder.worth(k, n);
        let perception = binder.perceive(persona, &worth);
        let situation = crate::brain::situation(&perception);
        let condition = crate::survival::Condition {
            asleep: perception.asleep,
            at_home: perception.at_home,
            threat_in_sight: perception.hostile.is_some(),
            night: perception.night,
        };
        let mut thought = crate::brain::Think::new(&perception, roll);
        let chose = tree.think(&mut thought, &mut doing);
        (thought.actions, thought.do_now, situation, chose, condition)
    };
    persona.doing = doing;
    if let Some((rates, seconds)) = binder.needs_drain() {
        persona.needs.tick(rates, condition, seconds);
    }
    for choice in chose {
        persona.memory.learned.chose(situation, choice);
    }
    binder.act(actions, do_now);
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::brain::{self, Brain, Do, Perception};
    use crate::statetree::{Enter, ROOT, Select, StateDef, StateTree, Task};
    use crate::survival::Need;

    /// A game with nothing in it but what the person carries.
    #[derive(Default)]
    struct Empty {
        did: Vec<Option<Do>>,
        drain: Option<(crate::survival::SurvivalRates, f32)>,
    }

    impl PersonaBinder for Empty {
        fn perceive<'a>(
            &'a self,
            persona: &'a Persona,
            worth: &'a dyn Fn(&crate::memory::Known, Need) -> f32,
        ) -> Perception<'a> {
            Perception {
                now: 1,
                position: glam::Vec3::ZERO,
                yaw: 0.0,
                health_fraction: 1.0,
                needs: persona.needs,
                home: None,
                behaviour: crate::actor::Behaviour::Hunter,
                at_home: false,
                asleep: false,
                hostile: None,
                game: &(),
                night: false,
                carries_food: true,
                carries_drink: false,
                bags_full: false,
                memory: &persona.memory,
                personality: &persona.personality,
                worth,
                standable: &|_| true,
                reachable: &Vec::new,
                unknown: &|_| true,
                asked: None,
                trader: None,
            }
        }

        fn worth(&self, _: &crate::memory::Known, _: Need) -> f32 {
            0.0
        }

        fn act(&mut self, _: Vec<crate::actions::Action>, do_now: Option<Do>) {
            self.did.push(do_now);
        }

        fn needs_drain(&self) -> Option<(crate::survival::SurvivalRates, f32)> {
            self.drain
        }
    }

    #[test]
    fn needs_drain_through_a_think_only_when_the_game_asks() {
        let tree = StateTree { states: vec![state("root", None)] };
        let rates = crate::survival::SurvivalRates::lasting(100.0, 50.0, 1000.0);
        let mut kept = Persona::default();
        think(&mut Empty::default(), &mut kept, &tree, &mut crate::monument::Roll::new(1));
        assert_eq!(kept.needs, crate::survival::SurvivalStats::default(), "the game keeps the needs: untouched");
        let mut drained = Persona::default();
        let mut game = Empty { drain: Some((rates, 10.0)), ..Empty::default() };
        think(&mut game, &mut drained, &tree, &mut crate::monument::Roll::new(1));
        let mut expected = crate::survival::SurvivalStats::default();
        expected.tick(rates, crate::survival::Condition::default(), 10.0);
        assert_eq!(drained.needs, expected, "10 s of the game's rates");
        assert_eq!((drained.needs.hunger, drained.needs.thirst), (90.0, 80.0));
    }

    #[test]
    fn two_games_opening_the_same_name_host_the_same_person() {
        let directory = scratch("open");
        let mut in_topside = Persona::open(&directory, "Sophia", "female").unwrap();
        assert_eq!(in_topside.profile, Profile { name: "Sophia".into(), appearance: "female".into() });
        in_topside.memory.see(9, "well", glam::Vec3::ONE, 3);
        in_topside.needs.thirst = 30.0;
        in_topside.save(&directory).unwrap();
        let in_abiotic = Persona::open(&directory, "Sophia", "other").unwrap();
        assert_eq!(in_abiotic, in_topside, "what one game saved, the other opens");
        fs::remove_dir_all(directory).unwrap();
    }

    fn state(name: &'static str, parent: Option<usize>) -> StateDef<Brain> {
        StateDef { name, parent, choice: None, enter: None, select: Select::InOrder, task: None, transitions: Vec::new() }
    }

    #[test]
    fn a_binder_drives_a_persona_through_one_think() {
        let mut eat = state("eat what they carry", Some(ROOT));
        eat.enter = Some(brain::enter_eat_carried as Enter<Brain>);
        eat.task = Some(brain::eat_carried as Task<Brain>);
        let tree = StateTree { states: vec![state("root", None), eat] };
        let mut persona = Persona::default();
        persona.needs.hunger = 20.0;
        let mut game = Empty::default();
        think(&mut game, &mut persona, &tree, &mut crate::monument::Roll::new(1));
        assert_eq!(game.did, vec![Some(Do::EatCarried { need: Need::Hunger })], "hungry, carrying food: they eat it");    }

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
