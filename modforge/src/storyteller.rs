//! Storyteller / director: tick-driven event pacer for game mods.
//!
//! The director picks a weighted-random rule on an irregular
//! cadence, fires it, and schedules the next event. Config knobs
//! are tweakable live via the standard `storyteller_config` op.
//!
//! Engine-agnostic. Games supply their own rules and seed source.
//!
//! ```ignore
//! use modforge::storyteller::{Director, Rule, Outcome};
//!
//! static RULES: &[Rule] = &[
//!     Rule { name: "horde", weight: 1, run: horde_run },
//!     Rule { name: "vendor", weight: 1, run: vendor_run },
//! ];
//!
//! static DIRECTOR: Director = Director::new(RULES);
//!
//! // in your frame tick:
//! DIRECTOR.tick(now, || session_seed());
//! ```

use std::collections::HashSet;
use std::hash::Hash;
use std::sync::atomic::{AtomicU32, AtomicU64, Ordering};

use parking_lot::Mutex;
use serde_json::{Value as Json, json};

use crate::ops::{OP_REGISTRY, OpDef};
use crate::roll::Budget;

/// One episode (topside docs/episodes.md): a story that starts with a
/// storm and ends at the next, running inside a reality it fits.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct EpisodeDef {
    pub name: String,
    /// The realities it fits, by name; empty fits any.
    pub fits: Vec<String>,
    /// The people it needs, each cast from people who already exist.
    pub parts: Vec<PartDef>,
    /// What its parts and the player say (topside episodes.md "The
    /// lines"): rules like any line, each needing its part, so they win
    /// over plain talk while the episode runs.
    pub lines: Vec<LineDef>,
    /// What its parts do, on their own, when the player has done
    /// something (topside the-tap.md "How it opens": the note read, Dell
    /// comes down and knocks): rules like the lines, each fired once.
    pub cues: Vec<CueDef>,
    /// Whether the door's enemy stands outside the player's bunker door
    /// when the game starts in it (topside design.md "What 2D changes":
    /// not in The Tap's opening, the first fight comes later).
    pub door_enemy: bool,
    /// How it can end, in order: the first whose pivot points are all
    /// reached and whose parts are alive is the ending (topside the-tap.md
    /// "Which ending"); the last needs nothing.
    pub endings: Vec<EndingDef>,
    /// What it brings into the world once cast (Skyrim's quest aliases
    /// filled with things placed where the quest says): topside the-tap.md
    /// "How it opens", the tap.
    pub things: Vec<ThingDef>,
    /// Where it asks its parts to be, and when (Skyrim's quest stages with
    /// conditions, RimWorld's quest parts): for each part the first whose
    /// pivot points hold applies.
    pub errands: Vec<ErrandDef>,
    /// Its pivot points reached by what someone does, not by a line (topside
    /// todo 11ai), each read from memory and the world.
    pub deeds: Vec<DeedDef>,
}

/// A pivot point reached by what is done (topside todo 11ai): its name, and
/// the condition, in the one condition language (`Cond`), whose holding
/// reaches it.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct DeedDef {
    pub pivot: String,
    pub when: Cond,
}

/// One condition, the one way an episode says what must be true (Skyrim's
/// condition functions joined with AND and OR on quest stages and AI
/// packages): a few pieces read from memory and the world, joined with
/// All, Any, Not and First. Used by deeds and errands alike; `holds`
/// decides it.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Cond {
    All(Vec<Cond>),
    Any(Vec<Cond>),
    Not(Box<Cond>),
    /// A pivot point reached.
    Reached(String),
    /// Someone remembers doing this toward them since then; `every`: toward
    /// every member of a group (told everyone of their bunker).
    Remembered { by: Who, did: DidKind, toward: Target, since: Since, every: bool },
    /// Of the deeds `of` someone did toward them since then, the first is
    /// `is` (shot before they spoke: of Hit and Talked, the first a Hit).
    First { by: Who, of: Vec<DidKind>, toward: Target, is: DidKind, since: Since },
    /// One of them within `within` metres of the target.
    Near { who: Who, to: Target, within: f32 },
    /// One of them leading or following one of `of`.
    With { who: Who, of: Who },
    /// One of them alive, near a target if given.
    Alive { who: Who, near: Option<(Target, f32)> },
    /// One of them holding a place at the episode's thing.
    Holds { who: Who, thing: String },
    /// One of them home, in their bunker below the ground.
    AtHome { who: Who },
    /// The episode's thing is no longer in the world.
    Gone(String),
    /// The storm's phase now.
    Phase(crate::storm::StormPhase),
    /// One of them has a store open, of this kind, holding this, if given.
    Opened { who: Who, store: Store, holds: Option<Measure> },
    /// An errand's window has ended.
    Ended(String),
}

/// Someone an episode names: the player, a part, a group, or anyone.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Who {
    ThePlayer,
    Part(String),
    Group(Group),
    Anyone,
}

/// A group an episode names: a part's bunker, the people the edge sent for
/// word of the episode's thing, or the player's bunker.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Group {
    BunkerOf(String),
    CameFor(String),
    ThePlayersBunker,
}

/// What a deed is toward: someone, the episode's thing, or nothing.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Target {
    Who(Who),
    Thing(String),
    Nobody,
}

/// A kind of deed as memory keeps it (`memory::Did`): the episode's thing
/// by name (ate from it, told of it), a line by name (heard it).
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum DidKind {
    Hit,
    Killed,
    Talked,
    Heard(Option<String>),
    Ate(String),
    Told(String),
    Knocked,
}

/// From when a deed counts: the episode's start, a pivot point reached, or
/// within an errand's window.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Since {
    EpisodeStart,
    Pivot(String),
    During(String),
}

/// Which store: their bunker's own, or one something draws from.
#[derive(Clone, Copy, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Store {
    TheirOwn,
    DrawnFrom,
}

/// What a store holds: reads dry, or more than so many days of what
/// answers a need for its living people.
#[derive(Clone, Copy, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Measure {
    Dry,
    DaysOver(crate::survival::Need, f32),
}

/// A store someone has open, as the world has it.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct OpenStore {
    pub theirs: bool,
    pub drawn_from: bool,
    pub dry: bool,
    /// Days of what answers hunger and thirst, for its living people.
    pub days: (f32, f32),
}

/// What a game knows for deciding a condition: the one place the world is
/// read (topside fills it once a game second). Every person by ActorId.
pub trait Facts {
    fn now(&self) -> u64;
    fn player(&self) -> crate::actor::ActorId;
    fn episode_started(&self) -> u64;
    /// When a pivot point was reached, if it was.
    fn reached_at(&self, pivot: &str) -> Option<u64>;
    /// An errand's window: when it started, and when it ended if it has.
    fn window(&self, errand: &str) -> Option<(u64, Option<u64>)>;
    /// Everyone the `Who` names, living or dead.
    fn members(&self, who: &Who) -> Vec<crate::actor::ActorId>;
    fn alive(&self, id: crate::actor::ActorId) -> bool;
    fn memory(&self, id: crate::actor::ActorId) -> Option<&crate::memory::Memory>;
    fn feet(&self, id: crate::actor::ActorId) -> Option<glam::Vec3>;
    /// Where the episode's thing stands, if it is in the world.
    fn thing_at(&self, thing: &str) -> Option<glam::Vec3>;
    /// The item the episode's thing is (what eating from it is remembered
    /// as).
    fn item_of(&self, thing: &str) -> String;
    /// The words someone says telling of the thing ("told of the tap").
    fn told_words(&self, by: crate::actor::ActorId, thing: &str) -> String;
    /// Whether `a` leads or follows `b`.
    fn with(&self, a: crate::actor::ActorId, b: crate::actor::ActorId) -> bool;
    /// Whether they hold a place at the thing.
    fn holds_at(&self, id: crate::actor::ActorId, thing: &str) -> bool;
    fn at_home(&self, id: crate::actor::ActorId) -> bool;
    fn storm(&self) -> crate::storm::StormPhase;
    fn opened(&self, id: crate::actor::ActorId) -> Option<OpenStore>;
}

/// Whether a condition holds, and if it does, who it is about and when:
/// a deed remembered by its doer at its tick (the first, for anyone), every
/// other condition by the player, now. The one decider of the condition
/// language.
pub fn holds(cond: &Cond, facts: &impl Facts) -> Option<(crate::actor::ActorId, u64)> {
    use crate::memory::Did;
    let now = (facts.player(), facts.now());
    let any_of = |who: &Who, test: &dyn Fn(crate::actor::ActorId) -> bool| facts.members(who).into_iter().any(test);
    let at = |target: &Target| -> Vec<glam::Vec3> {
        match target {
            Target::Who(w) => facts.members(w).into_iter().filter(|id| facts.alive(*id)).filter_map(|id| facts.feet(id)).collect(),
            Target::Thing(t) => facts.thing_at(t).into_iter().collect(),
            Target::Nobody => Vec::new(),
        }
    };
    // The ticks a deed counts in.
    let window = |since: &Since| -> Option<(u64, u64)> {
        match since {
            Since::EpisodeStart => Some((facts.episode_started(), u64::MAX)),
            Since::Pivot(p) => facts.reached_at(p).map(|t| (t, u64::MAX)),
            Since::During(e) => facts.window(e).map(|(from, to)| (from, to.unwrap_or(u64::MAX))),
        }
    };
    // Whether a remembered deed is of this kind and toward this target.
    let toward = |target: &Target, id: crate::actor::ActorId| match target {
        Target::Who(w) => facts.members(w).contains(&id),
        Target::Thing(_) | Target::Nobody => true,
    };
    let matches = |by: crate::actor::ActorId, kind: &DidKind, target: &Target, did: &Did| match (kind, did) {
        (DidKind::Hit, Did::Hit(id, _)) | (DidKind::Killed, Did::Killed(id)) | (DidKind::Talked, Did::Talked(id, _)) => toward(target, *id),
        (DidKind::Heard(line), Did::Heard(id, said)) => line.as_ref().is_none_or(|l| *l == said.name) && toward(target, *id),
        (DidKind::Ate(thing), Did::Ate(item)) => *item == facts.item_of(thing),
        (DidKind::Told(thing), Did::Talked(id, said)) => said.words == facts.told_words(by, thing) && toward(target, *id),
        (DidKind::Knocked, Did::Knocked) => true,
        _ => false,
    };
    match cond {
        Cond::All(all) => {
            let mut first = None;
            for c in all {
                let held = holds(c, facts)?;
                first.get_or_insert(held);
            }
            first.or(Some(now))
        }
        Cond::Any(any) => any.iter().find_map(|c| holds(c, facts)),
        Cond::Not(c) => holds(c, facts).is_none().then_some(now),
        Cond::Reached(p) => facts.reached_at(p).map(|t| (now.0, t)),
        Cond::Remembered { by, did, toward: target, since, every } => {
            let (from, to) = window(since)?;
            let done = |doer: crate::actor::ActorId, test: &dyn Fn(&Did) -> bool| {
                facts.memory(doer)?.done.iter().find(|(t, d)| *t >= from && *t <= to && test(d)).map(|(t, _)| *t)
            };
            if *every {
                let Target::Who(group) = target else {
                    return None;
                };
                let all = facts.members(group);
                // By one of them, toward each member of the group (each one
                // the deed was toward), at the last of those deeds.
                return facts.members(by).into_iter().find_map(|doer| {
                    let ticks: Option<Vec<u64>> = all
                        .iter()
                        .filter(|m| **m != doer)
                        .map(|m| done(doer, &|d| matches(doer, did, target, d) && done_toward(d) == Some(*m)))
                        .collect();
                    ticks.filter(|t| !t.is_empty()).map(|t| (doer, t.into_iter().max().unwrap_or(from)))
                });
            }
            facts.members(by).into_iter().filter_map(|doer| done(doer, &|d| matches(doer, did, target, d)).map(|t| (doer, t))).min_by_key(|(_, t)| *t)
        }
        Cond::First { by, of, toward: target, is, since } => {
            let (from, to) = window(since)?;
            facts.members(by).into_iter().find_map(|doer| {
                let memory = facts.memory(doer)?;
                let (t, first) = memory.done.iter().find(|(t, d)| *t >= from && *t <= to && of.iter().any(|k| matches(doer, k, target, d)))?;
                matches(doer, is, target, first).then_some((doer, *t))
            })
        }
        Cond::Near { who, to, within } => {
            let spots = at(to);
            any_of(who, &|id| facts.alive(id) && facts.feet(id).is_some_and(|f| spots.iter().any(|s| s.distance(f) <= *within))).then_some(now)
        }
        Cond::With { who, of } => {
            let others = facts.members(of);
            any_of(who, &|id| facts.alive(id) && others.iter().any(|o| facts.with(id, *o))).then_some(now)
        }
        Cond::Alive { who, near } => {
            let spots = near.as_ref().map(|(t, _)| at(t));
            any_of(who, &|id| {
                facts.alive(id)
                    && match (&spots, near) {
                        (Some(spots), Some((_, within))) => facts.feet(id).is_some_and(|f| spots.iter().any(|s| s.distance(f) <= *within)),
                        _ => true,
                    }
            })
            .then_some(now)
        }
        Cond::Holds { who, thing } => any_of(who, &|id| facts.alive(id) && facts.holds_at(id, thing)).then_some(now),
        Cond::AtHome { who } => any_of(who, &|id| facts.alive(id) && facts.at_home(id)).then_some(now),
        Cond::Gone(thing) => facts.thing_at(thing).is_none().then_some(now),
        Cond::Phase(phase) => (facts.storm() == *phase).then_some(now),
        Cond::Opened { who, store, holds: measure } => any_of(who, &|id| {
            facts.opened(id).is_some_and(|open| {
                let kind = match store {
                    Store::TheirOwn => open.theirs,
                    Store::DrawnFrom => open.drawn_from,
                };
                kind && match measure {
                    None => true,
                    Some(Measure::Dry) => open.dry,
                    Some(Measure::DaysOver(need, days)) => match need {
                        crate::survival::Need::Thirst => open.days.1 > *days,
                        _ => open.days.0 > *days,
                    },
                }
            })
        })
        .then_some(now),
        Cond::Ended(errand) => facts.window(errand).and_then(|(_, end)| end).map(|t| (now.0, t)),
    }
}

/// Whom a remembered deed was toward, if anyone.
fn done_toward(did: &crate::memory::Did) -> Option<crate::actor::ActorId> {
    use crate::memory::Did;
    match did {
        Did::Hit(id, _) | Did::Killed(id) | Did::Talked(id, _) | Did::Heard(id, _) | Did::HeardKnocking(id) | Did::Traded(id, ..) | Did::TradeRefused(id) => Some(*id),
        _ => None,
    }
}

/// One errand (Skyrim's quest stages giving AI packages to aliases,
/// RimWorld's quest parts giving lord jobs to groups): whom it asks (a
/// part, a group: each member), what, when (a condition in the one
/// language), from when (now, or the first game morning after its
/// condition first holds), and, for a named errand, when its window ends:
/// its name is reached as a pivot point when it starts, and its window
/// (start to end) is what `Since::During` reads.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct ErrandDef {
    pub name: Option<String>,
    pub who: Who,
    pub does: ErrandAct,
    pub when: Cond,
    pub at: ErrandStart,
    pub ends: Option<Cond>,
    /// The pivot point reached when they arrive where it sends them.
    pub reached_on_arrival: Option<String>,
}

/// When an errand starts once its condition holds.
#[derive(Clone, Copy, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum ErrandStart {
    Now,
    FirstMorningAfter,
}

/// What an errand asks.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum ErrandAct {
    /// Stand beside the episode's thing of this name, at this side of it
    /// (radians round it).
    GoTo { thing: String, side: f32 },
    /// Lead someone to stand beside it.
    Lead { who: Who, thing: String, side: f32 },
    /// Go back home, after an errand.
    GoHome,
    /// Be home, never taken out of a talk for it.
    StayHome,
    /// An order, through the one command path: whom it names (a group:
    /// each one given the nearest living member of it) and where (a thing)
    /// worked out when given.
    Order(crate::command::Command<Who, ThingRef>),
}

/// Where an order in data goes: beside the episode's thing of this name
/// (a struct, as a command's point is flattened: `thing: tap`).
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct ThingRef {
    pub thing: String,
}

/// The tick an errand starting at `start` starts, its condition first
/// holding at `held`: then, or the start of the first game day after it
/// (a game day starts at morning, `survival::day_fraction`), a day being
/// `day` ticks.
pub fn starts_at(start: ErrandStart, held: u64, day: u64) -> u64 {
    match start {
        ErrandStart::Now => held,
        ErrandStart::FirstMorningAfter => (held / day.max(1) + 1) * day.max(1),
    }
}

/// The errand that applies to someone now: the first in the def that names
/// them (`names`) whose condition holds and whose start has come
/// (`started`: an errand's start tick worked out by the game, None when it
/// has not started).
pub fn errand_for<'a>(def: &'a EpisodeDef, names: impl Fn(&Who) -> bool, facts: &impl Facts, started: impl Fn(&ErrandDef) -> bool) -> Option<&'a ErrandDef> {
    def.errands.iter().find(|e| names(&e.who) && started(e) && holds(&e.when, facts).is_some())
}

/// One thing an episode brings into the world: its name in the episode
/// (what its lines and pivot points call it), the item it is, where it
/// stands, and who it belongs to and who knows it.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct ThingDef {
    pub name: String,
    pub item: String,
    /// In a building of the site nearest the middle between these two
    /// places.
    pub between: (Place, Place),
    /// The part whose bunker's store it draws from, if any (a tap on
    /// Mara's water).
    pub draws_from: Option<String>,
    /// The part who found it: they know it as a place they have been, and
    /// every site near the way to it from the first place.
    pub found_by: Option<String>,
    /// Whether whoever found it keeps it to themselves.
    pub kept_quiet: bool,
}

/// A place an episode names: the player's bunker door, or a part's home.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum Place {
    PlayerBunkerDoor,
    HomeOf(String),
}

/// One ending: its name, what it says happened, the pivot points it needs,
/// and the parts who must be alive for it.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct EndingDef {
    pub name: String,
    pub words: String,
    pub needs: Vec<String>,
    pub alive: Vec<String>,
}

/// The ending an episode comes to: the first of its endings whose pivot
/// points are all `reached` and whose parts `alive` holds.
pub fn ending<'a>(def: &'a EpisodeDef, reached: &[&str], alive: impl Fn(&str) -> bool) -> Option<&'a EndingDef> {
    def.endings.iter().find(|e| e.needs.iter().all(|n| reached.contains(&n.as_str())) && e.alive.iter().all(|p| alive(p)))
}

/// One cue, as a rule: when the player has done `did` (a `Did`'s words,
/// "read note"), the person cast as `part` is given the order `does`, the
/// one command a person carries out, whom it names (the player or a part)
/// and where (an episode thing, by name) worked out when given
/// (`Command::resolve`); once an episode, remembered as the pivot point
/// `name` reached.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct CueDef {
    pub name: String,
    pub did: String,
    pub part: String,
    pub does: crate::command::Command<Who, ThingRef>,
}

/// The cues due now: each whose deed the player has done since the episode
/// started (`done`, the player's memory: tick and deed), and not reached
/// yet (`reached`, the pivot points reached by name). In the episode's
/// order.
pub fn cues_due<'a>(def: &'a EpisodeDef, done: &[(u64, crate::memory::Did)], started: u64, reached: &[&str]) -> Vec<&'a CueDef> {
    def.cues
        .iter()
        .filter(|cue| !reached.contains(&cue.name.as_str()))
        .filter(|cue| done.iter().any(|(at, did)| *at >= started && did.words() == cue.did))
        .collect()
}

/// One line, as a rule (topside episodes.md "One way for every
/// conversation"; Valve's response rules): who may say it, what must be
/// true when they do, several ways of saying it with {slots} filled from
/// the world and the speaker's memory, what it tells, and how hearing it
/// feels. An episode's line, a plain line, and the player's choice are
/// all this; `crate::talk::pick` says the best matching one.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct LineDef {
    /// What saying it is ("believes Dell", "the way"): memory keeps it
    /// beside the words, and replies, pivot points, and feelings go by it.
    /// Rules may share a name (the same line said at two moments).
    pub name: String,
    /// Who may say it: a part of the episode ("Dell"), "player" for the
    /// player's choices, or "" for anyone but the player.
    pub part: String,
    /// What must all be true of the speaker.
    pub when: Vec<When>,
    pub ways: Vec<String>,
    /// What it tells the listener of: a thing the episode brought into the
    /// world by name ("tap"), else the kind of a thing the speaker knows
    /// ("well"), else "" for nothing. The {slots} of a way are filled for
    /// this thing.
    pub tells: String,
    /// How the one spoken to feels about hearing it, -1 to 1 (a threat
    /// below `relationship::HOSTILE`, a kind word above 0; topside life.md
    /// "How a person feels about others").
    pub felt: f32,
    /// Silence (topside episodes.md: doing nothing is always a choice;
    /// Firewatch, Oxenfree, Cyberpunk 2077): a player's line with no ways
    /// is never shown as a choice; when it matches, it is said by itself
    /// if the player chooses nothing within this many real seconds. 0 for
    /// every other line.
    pub wait: f32,
}

impl LineDef {
    /// The line's own id, what a choice and a saved talk name it by: its
    /// name and its ways, hashed (FNV-1a, the same in every build). Lines
    /// added or moved never change another's id, so a saved choice keeps
    /// saying the line it said; editing this line's words changes its id
    /// (and a save's content hash, topside save.rs).
    pub fn id(&self) -> u64 {
        let mut hash: u64 = 0xcbf2_9ce4_8422_2325;
        for byte in self.name.bytes().chain([0]).chain(self.ways.iter().flat_map(|w| w.bytes().chain([0]))) {
            hash ^= u64::from(byte);
            hash = hash.wrapping_mul(0x0000_0100_0000_01b3);
        }
        hash
    }
}

/// One thing that must be true of the speaker for a line to be said, read
/// from their memory and the moment (`crate::talk::Speaking`).
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum When {
    /// The one spoken to is cast as this part, or "player".
    To(String),
    /// The one spoken to started this conversation (the player's E).
    Opened,
    /// The speaker is knocking on a shut door now: the line is called
    /// through it, heard like the knock, no conversation opened.
    Knocking,
    /// The speaker holds a place and warns off one who comes for it: the
    /// line is called to them, heard where they are, no conversation opened
    /// (topside todo 11z).
    Warning,
    /// The speaker feels at least this toward the one spoken to (from -1
    /// to 1, relationship::feeling; topside todo 11af: a stranger says yes
    /// to staying when they feel well enough toward the one asking).
    Feels(f32),
    /// Nothing has been said in this conversation yet: the speaker's
    /// first word. A plain question asked once, not offered after every
    /// reply (a conversation ends after the last reply).
    First,
    /// What the speaker last heard from the one they talk to, in this
    /// conversation and not yet answered, was this line.
    Heard(String),
    /// The speaker has heard this line from the one they talk to, at any
    /// time: a moment left open when a conversation ended without an
    /// answer is still open the next time.
    HasHeard(String),
    /// What the speaker last said to the one they talk to, in this
    /// conversation, was this line, and nothing was heard since: they go
    /// on.
    JustSaid(String),
    /// The speaker has said this line, to anyone, ever.
    Said(String),
    /// This pivot point of the episode has been reached.
    Reached(String),
    /// The speaker knows a thing of this kind and may tell of it (not one
    /// they keep quiet).
    Knows(String),
    /// The speaker stands within this many metres of the thing the episode
    /// brought in by this name.
    Near(String, f32),
    /// The speaker's need (hunger, thirst) is this low or lower.
    Needs(String, f32),
    Not(Box<When>),
    /// Any one of these.
    Any(Vec<When>),
}

/// One way of saying something, picked from the seed and `salt` among
/// the ways whose every {slot} is in `slots`, its slots filled; None when
/// no way can be filled.
pub fn say(ways: &[String], slots: &[(&str, &str)], seed: u64, salt: u64) -> Option<String> {
    let fillable: Vec<&String> = ways
        .iter()
        .filter(|way| slots_of(way).all(|slot| slots.iter().any(|(name, _)| *name == slot)))
        .collect();
    if fillable.is_empty() {
        return None;
    }
    let way = fillable[crate::roll::salted_index(seed, salt, fillable.len() as u64) as usize];
    let mut words = way.clone();
    for (name, value) in slots {
        words = words.replace(&format!("{{{name}}}"), value);
    }
    Some(words)
}

/// The {slot} names in a way of saying something.
fn slots_of(way: &str) -> impl Iterator<Item = &str> {
    way.split('{').skip(1).filter_map(|rest| rest.split_once('}').map(|(name, _)| name))
}

/// One person an episode needs (episodes.md "The people"): its name in
/// the episode and where it is cast from.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct PartDef {
    pub name: String,
    pub from: CastFrom,
}

/// Where a part is cast from: always a bunker person, since only bunker
/// people live on across episodes (realities.md).
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub enum CastFrom {
    /// A random person of the player's bunker.
    PlayerBunker,
    /// A random person of the bunker nearest the player's.
    NearestOtherBunker,
    /// A random person of the same bunker as the named part.
    SameBunkerAs(String),
    /// Of the player's bunker, the one who feels most toward the player,
    /// from their own memory (topside the-fever.md: "whoever in the
    /// player's bunker trusted the player most").
    MostTrustingOfPlayerBunker,
    /// Whoever played this part in the episode before, if living, wherever
    /// they are now (the-fever.md: Mara).
    PlayedBefore(String),
    /// Whoever played this part in the episode before, only if still of
    /// the player's bunker (the-fever.md: "Dell: in it only if Dell stayed
    /// home").
    PlayedBeforeAtHome(String),
}

/// One bunker's people, as the consumer sees them, for casting.
pub struct CastBunker<P> {
    pub player: bool,
    /// How far it stands from the player's bunker.
    pub distance: f32,
    pub people: Vec<P>,
}

/// Fill an episode's parts from the bunkers' people, from the seed: each
/// a random person from where it says, never one already cast. A part
/// with nobody left to cast is left out.
/// `before`: who played which part in the episode before; `feels`: how a
/// person feels toward the player, from their memory (None: nothing of
/// them).
pub fn cast<P: Copy + PartialEq>(parts: &[PartDef], bunkers: &[CastBunker<P>], before: &[(String, P)], feels: impl Fn(P) -> Option<f32>, seed: u64) -> Vec<(String, P)> {
    let nearest = bunkers
        .iter()
        .enumerate()
        .filter(|(_, b)| !b.player && !b.people.is_empty())
        .min_by(|a, b| a.1.distance.total_cmp(&b.1.distance))
        .map(|(i, _)| i);
    let bunker_of = |p: P| bunkers.iter().position(|b| b.people.contains(&p));
    let player_bunker = bunkers.iter().position(|b| b.player);
    let mut cast: Vec<(String, P, usize)> = Vec::new();
    for (salt, part) in parts.iter().enumerate() {
        let taken = |p: &P| cast.iter().any(|(_, c, _)| c == p);
        // Parts drawn from memory name one person, or no one.
        let named = match &part.from {
            CastFrom::MostTrustingOfPlayerBunker => player_bunker.and_then(|b| {
                bunkers[b]
                    .people
                    .iter()
                    .copied()
                    .filter(|p| !taken(p))
                    .filter_map(|p| feels(p).map(|f| (p, f)))
                    .max_by(|a, b| a.1.total_cmp(&b.1))
                    .map(|(p, _)| p)
            }),
            CastFrom::PlayedBefore(other) => before.iter().find(|(n, p)| n == other && !taken(p) && bunker_of(*p).is_some()).map(|(_, p)| *p),
            CastFrom::PlayedBeforeAtHome(other) => before.iter().find(|(n, p)| n == other && !taken(p) && bunker_of(*p) == player_bunker).map(|(_, p)| *p),
            _ => None,
        };
        if matches!(part.from, CastFrom::MostTrustingOfPlayerBunker | CastFrom::PlayedBefore(_) | CastFrom::PlayedBeforeAtHome(_)) {
            if let Some(p) = named
                && let Some(b) = bunker_of(p)
            {
                cast.push((part.name.clone(), p, b));
            }
            continue;
        }
        let bunker = match &part.from {
            CastFrom::PlayerBunker => player_bunker,
            CastFrom::NearestOtherBunker => nearest,
            CastFrom::SameBunkerAs(other) => cast.iter().find(|(n, ..)| n == other).map(|(.., b)| *b),
            _ => None,
        };
        let Some(bunker) = bunker else {
            continue;
        };
        let free: Vec<P> = bunkers[bunker]
            .people
            .iter()
            .copied()
            .filter(|p| !cast.iter().any(|(_, c, _)| c == p))
            .collect();
        if free.is_empty() {
            continue;
        }
        let at = crate::roll::salted_index(seed, salt as u64, free.len() as u64) as usize;
        cast.push((part.name.clone(), free[at], bunker));
    }
    cast.into_iter().map(|(name, person, _)| (name, person)).collect()
}

impl EpisodeDef {
    pub fn fits(&self, reality: &str) -> bool {
        self.fits.is_empty() || self.fits.iter().any(|r| r == reality)
    }
}

/// Every episode the storyteller can start, in the order registered.
#[derive(Default)]
pub struct EpisodeRegistry {
    defs: Vec<EpisodeDef>,
}

impl EpisodeRegistry {
    /// Every episode, in the order registered.
    pub fn all(&self) -> &[EpisodeDef] {
        &self.defs
    }

    pub fn register(&mut self, def: EpisodeDef) -> Result<(), String> {
        if self.defs.iter().any(|d| d.name == def.name) {
            return Err(format!("episode '{}' registered twice", def.name));
        }
        self.defs.push(def);
        Ok(())
    }

    pub fn def(&self, name: &str) -> Option<&EpisodeDef> {
        self.defs.iter().find(|d| d.name == name)
    }

    /// The episode for the reality a storm has handed over, picked from
    /// the seed and the storm's number among those that fit it; before
    /// any storm, the first registered that fits (the first episode);
    /// none if no episode fits.
    pub fn pick(&self, reality: &str, seed: u64, storms: u32) -> Option<&EpisodeDef> {
        let fitting: Vec<&EpisodeDef> = self.defs.iter().filter(|d| d.fits(reality)).collect();
        if fitting.is_empty() {
            return None;
        }
        if storms == 0 {
            return Some(fitting[0]);
        }
        let at = crate::roll::salted_index(seed, u64::from(storms), fitting.len() as u64) as usize;
        Some(fitting[at])
    }

    /// How hearing this line feels (`LineDef::felt`), by its name, of any
    /// episode; 0 for a line no episode has.
    pub fn felt(&self, line: &str) -> f32 {
        self.defs.iter().flat_map(|d| &d.lines).find(|l| l.name == line).map_or(0.0, |l| l.felt)
    }
}

/// One thing the director can make happen.
pub struct Rule {
    pub name: &'static str,
    pub weight: u32,
    pub run: fn(now: f32) -> Result<Outcome, String>,
}

/// What a rule did this pass.
pub enum Outcome {
    Fired,
    Passed,
}

/// A chance that rises with progression until it reaches a cap.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct EncounterChance {
    pub base: f64,
    pub per_level: f64,
    pub max: f64,
}

impl EncounterChance {
    pub fn at(&self, level: f64) -> f64 {
        (self.base + self.per_level * level).min(self.max)
    }
}

/// Engine-independent policy for adaptive encounters.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct EncounterConfig {
    pub budget: Budget,
    pub escalation: EncounterChance,
    pub pack: EncounterChance,
    pub pack_min: usize,
    pub pack_max: usize,
    pub session_cap: usize,
    pub scatter_min: f64,
    pub scatter_max: f64,
    pub height_offset: f64,
}

/// The encounter composition selected for one place.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct EncounterPlan<P> {
    pub place: P,
    pub copies: usize,
    pub escalations: usize,
    pub pack: usize,
}

/// One caller-observed anchor available to an encounter.
pub struct EncounterAnchor<A, C> {
    pub value: A,
    pub class: Option<C>,
    pub position: Option<(f64, f64, f64)>,
}

/// Why a particular spawn was selected.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum EncounterSpawnKind {
    Copy,
    Escalation,
    Pack,
}

/// One engine-independent spawn request returned to the caller.
pub struct EncounterSpawn<A, C> {
    pub kind: EncounterSpawnKind,
    pub anchor: A,
    pub class: C,
    pub position: (f64, f64, f64),
}

/// Adaptive encounter state, selection, placement, and session caps.
pub struct EncounterPlanner<P> {
    config: EncounterConfig,
    processed: HashSet<P>,
    processed_total: usize,
    spawned_total: usize,
}

impl<P> EncounterPlanner<P>
where
    P: Clone + Eq + Hash,
{
    pub fn new(config: EncounterConfig) -> Self {
        Self {
            config,
            processed: HashSet::new(),
            processed_total: 0,
            spawned_total: 0,
        }
    }

    /// Forget places that are no longer loaded so they can roll again later.
    pub fn retain_places(&mut self, mut is_loaded: impl FnMut(&P) -> bool) {
        self.processed.retain(|place| is_loaded(place));
    }

    /// Claim a newly loaded place and select its encounter composition.
    pub fn plan_place(
        &mut self,
        place: P,
        existing_count: usize,
        level: f64,
    ) -> Option<EncounterPlan<P>> {
        if !self.processed.insert(place.clone()) {
            return None;
        }
        self.processed_total += 1;

        let mut plan = EncounterPlan {
            place,
            copies: 0,
            escalations: 0,
            pack: 0,
        };
        if self.config.budget.is_quiet() {
            return Some(plan);
        }

        let extras = self.config.budget.roll_scaled(level, existing_count as f64);
        let escalation_chance = self.config.escalation.at(level);
        for _ in 0..extras {
            if fastrand::f64() < escalation_chance {
                plan.escalations += 1;
            } else {
                plan.copies += 1;
            }
        }

        if fastrand::f64() < self.config.pack.at(level) {
            let pack_max = self.config.pack_max.max(self.config.pack_min);
            plan.pack = self.config.pack_min + fastrand::usize(0..=pack_max - self.config.pack_min);
        }
        Some(plan)
    }

    /// Select anchors, classes, and scatter positions, then ask the caller to
    /// execute each request. Only successful requests consume the session cap.
    pub fn execute<A, C>(
        &mut self,
        plan: &EncounterPlan<P>,
        anchors: &[EncounterAnchor<A, C>],
        escalation_pool: &[C],
        mut on_pack: impl FnMut(&C, usize),
        mut spawn: impl FnMut(EncounterSpawn<A, C>) -> bool,
    ) -> usize
    where
        A: Clone,
        C: Clone,
    {
        if anchors.is_empty() || escalation_pool.is_empty() {
            return 0;
        }

        let mut spawned = 0;
        let mut attempt = |kind: EncounterSpawnKind, anchor: &EncounterAnchor<A, C>, class: &C| {
            if self.is_full() {
                return;
            }
            let Some((x, y, z)) = anchor.position else {
                return;
            };
            let angle = fastrand::f64() * std::f64::consts::TAU;
            let distance = self.config.scatter_min
                + fastrand::f64() * (self.config.scatter_max - self.config.scatter_min);
            let request = EncounterSpawn {
                kind,
                anchor: anchor.value.clone(),
                class: class.clone(),
                position: (
                    x + angle.cos() * distance,
                    y + angle.sin() * distance,
                    z + self.config.height_offset,
                ),
            };
            if spawn(request) {
                self.spawned_total += 1;
                spawned += 1;
            }
        };

        for _ in 0..plan.copies {
            let anchor = &anchors[fastrand::usize(0..anchors.len())];
            if let Some(class) = &anchor.class {
                attempt(EncounterSpawnKind::Copy, anchor, class);
            }
        }
        for _ in 0..plan.escalations {
            let anchor = &anchors[fastrand::usize(0..anchors.len())];
            let class = &escalation_pool[fastrand::usize(0..escalation_pool.len())];
            attempt(EncounterSpawnKind::Escalation, anchor, class);
        }
        if plan.pack > 0 {
            let anchor = &anchors[fastrand::usize(0..anchors.len())];
            let class = &escalation_pool[fastrand::usize(0..escalation_pool.len())];
            on_pack(class, plan.pack);
            for _ in 0..plan.pack {
                attempt(EncounterSpawnKind::Pack, anchor, class);
            }
        }

        spawned
    }

    pub fn is_full(&self) -> bool {
        self.spawned_total >= self.config.session_cap
    }

    pub fn spawned_total(&self) -> usize {
        self.spawned_total
    }

    pub fn processed_total(&self) -> usize {
        self.processed_total
    }
}

/// How a phenomenon relates to player risk and reward.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum PhenomenonNature {
    Reward,
    Danger,
    Neutral,
}

/// Caller-supplied planning facts for one phenomenon type.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct PhenomenonDef {
    pub count_min: usize,
    pub count_max: usize,
    pub spread: f64,
    pub weight_base: f64,
    pub weight_per_level: f64,
    pub nature: PhenomenonNature,
}

/// One entry in a game's phenomenon catalog: what it is called,
/// what it spawns, and how it plans.
///
/// [`PhenomenonDef`] is the planning half. This adds the two
/// things a game supplies alongside it: a name for the logs and
/// the controls, and the actor classes to draw from, one picked
/// per prop. The catalog is then a plain `&[Phenomenon]` of the
/// game's own content.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Phenomenon {
    pub name: &'static str,
    /// Classes to draw from; each prop picks one at random.
    pub classes: &'static [&'static str],
    pub planning: PhenomenonDef,
}

/// Engine-independent policy for phenomena placed into streamed regions.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct PhenomenonConfig {
    pub budget: Budget,
    pub session_cap: usize,
}

/// Phenomenon types selected for one region.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PhenomenonPlan<P> {
    pub place: P,
    pub phenomena: Vec<usize>,
}

/// One resolved phenomenon spawn for the caller to execute.
pub struct PhenomenonSpawn<C> {
    pub phenomenon: usize,
    pub class: C,
    pub position: (f64, f64, f64),
    pub yaw: f64,
}

/// Phenomenon region lifecycle, selection, placement, and session caps.
pub struct PhenomenonPlanner<P> {
    config: PhenomenonConfig,
    processed: HashSet<P>,
    spawned_total: usize,
    phenomena_total: usize,
}

impl<P> PhenomenonPlanner<P>
where
    P: Clone + Eq + Hash,
{
    pub fn new(config: PhenomenonConfig) -> Self {
        Self {
            config,
            processed: HashSet::new(),
            spawned_total: 0,
            phenomena_total: 0,
        }
    }

    /// Forget regions that are no longer loaded so they can roll on re-entry.
    pub fn retain_places(&mut self, mut is_loaded: impl FnMut(&P) -> bool) {
        self.processed.retain(|place| is_loaded(place));
    }

    /// Claim a newly loaded region and select its distinct phenomenon types.
    pub fn plan_place(
        &mut self,
        place: P,
        level: f64,
        defs: &[PhenomenonDef],
    ) -> Option<PhenomenonPlan<P>> {
        if !self.processed.insert(place.clone()) {
            return None;
        }

        let mut plan = PhenomenonPlan {
            place,
            phenomena: Vec::new(),
        };
        if self.config.budget.is_quiet() {
            return Some(plan);
        }

        let count = self.config.budget.roll_count(level);
        let weights: Vec<crate::roll::Weight> = defs
            .iter()
            .map(|def| crate::roll::Weight::new(def.weight_base, def.weight_per_level))
            .collect();
        plan.phenomena = crate::roll::pick_distinct(&weights, level, count);

        let has_reward = plan
            .phenomena
            .iter()
            .any(|&index| defs[index].nature == PhenomenonNature::Reward);
        let has_danger = plan
            .phenomena
            .iter()
            .any(|&index| defs[index].nature == PhenomenonNature::Danger);
        if has_reward && !has_danger {
            let dangers: Vec<usize> = defs
                .iter()
                .enumerate()
                .filter_map(|(index, def)| {
                    (def.nature == PhenomenonNature::Danger).then_some(index)
                })
                .collect();
            if !dangers.is_empty() {
                plan.phenomena
                    .push(dangers[fastrand::usize(0..dangers.len())]);
            }
        }
        Some(plan)
    }

    /// Generate clustered placement requests and let the caller resolve ground,
    /// engine classes, and spawning. Only successful spawns consume the cap.
    pub fn execute<C>(
        &mut self,
        phenomena: &[usize],
        defs: &[PhenomenonDef],
        centre: (f64, f64),
        half_extent: f64,
        mut ground: impl FnMut(f64, f64) -> Option<f64>,
        mut variant_count: impl FnMut(usize) -> usize,
        mut resolve: impl FnMut(usize, usize) -> Option<C>,
        mut spawn: impl FnMut(PhenomenonSpawn<C>) -> bool,
    ) -> usize {
        let mut ordered = phenomena.to_vec();
        ordered.sort_by_key(|&index| match defs[index].nature {
            PhenomenonNature::Reward => 0,
            PhenomenonNature::Danger => 1,
            PhenomenonNature::Neutral => 2,
        });

        let mut reward_spot = None;
        let mut placed = 0;
        for index in ordered {
            let def = &defs[index];
            let (px, py) = match (def.nature, reward_spot) {
                (PhenomenonNature::Danger, Some(spot)) => spot,
                _ => (
                    centre.0 + (fastrand::f64() * 2.0 - 1.0) * half_extent,
                    centre.1 + (fastrand::f64() * 2.0 - 1.0) * half_extent,
                ),
            };
            if def.nature == PhenomenonNature::Reward && reward_spot.is_none() {
                reward_spot = Some((px, py));
            }

            let count = def.count_min + fastrand::usize(0..=def.count_max - def.count_min);
            for _ in 0..count {
                if self.is_full() {
                    break;
                }
                let angle = fastrand::f64() * std::f64::consts::TAU;
                let distance = fastrand::f64() * def.spread;
                let x = px + angle.cos() * distance;
                let y = py + angle.sin() * distance;
                let Some(z) = ground(x, y) else {
                    continue;
                };
                let variant = fastrand::usize(0..variant_count(index));
                let Some(class) = resolve(index, variant) else {
                    continue;
                };
                let request = PhenomenonSpawn {
                    phenomenon: index,
                    class,
                    position: (x, y, z),
                    yaw: fastrand::f64() * std::f64::consts::TAU,
                };
                if spawn(request) {
                    self.spawned_total += 1;
                    placed += 1;
                }
            }
            self.phenomena_total += 1;
        }
        placed
    }

    pub fn is_full(&self) -> bool {
        self.spawned_total >= self.config.session_cap
    }

    pub fn spawned_total(&self) -> usize {
        self.spawned_total
    }

    pub fn phenomena_total(&self) -> usize {
        self.phenomena_total
    }
}

/// One caller-observed target for adaptive pressure. The caller
/// supplies engine facts; Modforge owns eligibility, threshold,
/// and strongest-target selection.
pub struct PressureTarget<T> {
    pub eligible: bool,
    pub pressure: i64,
    pub value: T,
}

/// Select the first strongest eligible target at or above the
/// minimum pressure. Equal-pressure ties preserve caller order.
pub fn strongest_pressure_target<T>(
    targets: impl IntoIterator<Item = PressureTarget<T>>,
    minimum_pressure: i64,
) -> Option<PressureTarget<T>> {
    let mut strongest: Option<PressureTarget<T>> = None;
    for target in targets {
        if !target.eligible || target.pressure < minimum_pressure {
            continue;
        }
        if strongest
            .as_ref()
            .map(|current| target.pressure > current.pressure)
            .unwrap_or(true)
        {
            strongest = Some(target);
        }
    }
    strongest
}

/// One caller-defined adaptive-pressure tier.
pub struct PressureTier<T> {
    pub at_least: i64,
    pub value: T,
}

/// Resolve the first tier whose threshold the pressure reaches.
/// Callers order tiers from strongest to weakest.
pub fn pressure_tier<T>(pressure: i64, tiers: &[PressureTier<T>]) -> Option<&PressureTier<T>> {
    tiers.iter().find(|tier| pressure >= tier.at_least)
}

/// Calculate the integer centroid and maximum distance from it for
/// an existing set of map points.
pub fn centroid_and_spread(points: &[(i64, i64)]) -> Option<((i64, i64), i64)> {
    if points.is_empty() {
        return None;
    }
    let sum = points.iter().fold((0i64, 0i64), |sum, point| {
        (sum.0 + point.0, sum.1 + point.1)
    });
    let count = points.len() as i64;
    let centroid = (sum.0 / count, sum.1 / count);
    let spread = points
        .iter()
        .map(|point| {
            let dx = point.0 - centroid.0;
            let dy = point.1 - centroid.1;
            (((dx * dx + dy * dy) as f64).sqrt()) as i64
        })
        .max()
        .unwrap_or(0);
    Some((centroid, spread))
}

/// Calculate a map point from an existing centre, angle, and radius.
pub fn point_at_angle(centre: (i64, i64), angle: f64, radius: f64) -> (i64, i64) {
    (
        centre.0 + (angle.cos() * radius) as i64,
        centre.1 + (angle.sin() * radius) as i64,
    )
}

/// Return the first nearest point, preserving input order on ties.
pub fn nearest_point(origin: (i64, i64), points: &[(i64, i64)]) -> Option<usize> {
    let mut nearest = None;
    let mut nearest_distance = i64::MAX;
    for (index, point) in points.iter().enumerate() {
        let distance = (point.0 - origin.0).pow(2) + (point.1 - origin.1).pow(2);
        if distance < nearest_distance {
            nearest_distance = distance;
            nearest = Some(index);
        }
    }
    nearest
}

/// Pick a deterministic point on a ring around a pressure target.
pub fn pressure_ring_position(now: f32, salt: u64, centre: (i64, i64), radius: f64) -> (i64, i64) {
    let mut hash = (now.to_bits() as u64).wrapping_mul(0x9E3779B97F4A7C15) ^ (salt << 17);
    hash ^= hash >> 29;
    let angle = (hash % 6283) as f64 / 1000.0;
    (
        centre.0 + (angle.cos() * radius) as i64,
        centre.1 + (angle.sin() * radius) as i64,
    )
}

struct ActivePressure<I, H> {
    target_id: I,
    handle: H,
}

/// Active adaptive-pressure lifecycle: global cap, per-target
/// exclusion, tracking, and caller-driven liveness pruning.
pub struct PressureTracker<I, H> {
    max_active: usize,
    active: Mutex<Vec<ActivePressure<I, H>>>,
}

impl<I, H> PressureTracker<I, H>
where
    I: Copy + Eq,
    H: Copy,
{
    pub const fn new(max_active: usize) -> Self {
        Self {
            max_active,
            active: Mutex::new(Vec::new()),
        }
    }

    /// Remove finished pressure events. The caller observes engine
    /// liveness and releases engine resources for each removed handle.
    pub fn prune(&self, mut is_alive: impl FnMut(H) -> bool, mut cleanup: impl FnMut(H)) {
        self.active.lock().retain(|event| {
            let alive = is_alive(event.handle);
            if !alive {
                cleanup(event.handle);
            }
            alive
        });
    }

    pub fn is_full(&self) -> bool {
        self.active.lock().len() >= self.max_active
    }

    pub fn is_targeted(&self, target_id: I) -> bool {
        self.active
            .lock()
            .iter()
            .any(|event| event.target_id == target_id)
    }

    pub fn track(&self, target_id: I, handle: H) {
        self.active
            .lock()
            .push(ActivePressure { target_id, handle });
    }

    pub fn len(&self) -> usize {
        self.active.lock().len()
    }
}

/// Pacing knobs. Defaults can be overridden at construction or
/// live via the `storyteller_config` op.
#[derive(Clone, Copy)]
pub struct Config {
    pub min_gap_secs: f32,
    pub max_gap_secs: f32,
    pub retry_gap_secs: f32,
}

impl Config {
    pub const fn default_config() -> Self {
        Self {
            min_gap_secs: 180.0,
            max_gap_secs: 600.0,
            retry_gap_secs: 60.0,
        }
    }

    pub fn to_json(&self) -> Json {
        json!({
            "min_gap_secs": self.min_gap_secs,
            "max_gap_secs": self.max_gap_secs,
            "retry_gap_secs": self.retry_gap_secs,
        })
    }

    pub fn apply_args(&mut self, args: &Json) {
        if let Some(v) = args.get("min_gap_secs").and_then(Json::as_f64) {
            self.min_gap_secs = v as f32;
        }
        if let Some(v) = args.get("max_gap_secs").and_then(Json::as_f64) {
            self.max_gap_secs = v as f32;
        }
        if let Some(v) = args.get("retry_gap_secs").and_then(Json::as_f64) {
            self.retry_gap_secs = v as f32;
        }
        if self.max_gap_secs < self.min_gap_secs {
            self.max_gap_secs = self.min_gap_secs;
        }
    }
}

#[derive(Clone, Copy)]
struct LastEvent {
    rule: &'static str,
    at: f32,
}

pub struct Director {
    rules: &'static [Rule],
    config: Mutex<Config>,
    next_event_bits: AtomicU32,
    last_now_bits: AtomicU32,
    rng_state: AtomicU64,
    last_event: Mutex<Option<LastEvent>>,
}

impl Director {
    pub const fn new(rules: &'static [Rule]) -> Self {
        Self {
            rules,
            config: Mutex::new(Config::default_config()),
            next_event_bits: AtomicU32::new(0),
            last_now_bits: AtomicU32::new(0),
            rng_state: AtomicU64::new(0),
            last_event: Mutex::new(None),
        }
    }

    pub const fn with_config(rules: &'static [Rule], config: Config) -> Self {
        Self {
            rules,
            config: Mutex::new(config),
            next_event_bits: AtomicU32::new(0),
            last_now_bits: AtomicU32::new(0),
            rng_state: AtomicU64::new(0),
            last_event: Mutex::new(None),
        }
    }

    /// Drive the director forward. Call once per frame tick.
    ///
    /// `seed_fn` returns the world seed for RNG seeding; called
    /// only until the first successful seed. Return `Err` when
    /// no game is loaded yet.
    pub fn tick(
        &self,
        now: f32,
        seed_fn: impl FnOnce() -> Result<i64, String>,
        on_error: impl FnOnce(&str, &str),
    ) {
        if !self.ensure_seeded(seed_fn) {
            return;
        }
        self.last_now_bits.store(now.to_bits(), Ordering::Relaxed);

        let next = self.next_event_bits.load(Ordering::Relaxed);
        if next == 0 {
            self.schedule_next(now, false);
            return;
        }
        if now < f32::from_bits(next) {
            return;
        }

        let rule = self.pick_rule();
        match (rule.run)(now) {
            Ok(Outcome::Fired) => {
                *self.last_event.lock() = Some(LastEvent {
                    rule: rule.name,
                    at: now,
                });
                self.schedule_next(now, false);
            }
            Ok(Outcome::Passed) => self.schedule_next(now, true),
            Err(e) => {
                if !e.contains("not found") {
                    on_error(rule.name, &e);
                }
                self.schedule_next(now, true);
            }
        }
    }

    /// Snapshot of the director's core state for status ops.
    pub fn status(&self) -> Json {
        let cfg = *self.config.lock();
        let next = self.next_event_bits.load(Ordering::Relaxed);
        let now = f32::from_bits(self.last_now_bits.load(Ordering::Relaxed));
        let secs_until_next = if next == 0 {
            Json::Null
        } else {
            json!((f32::from_bits(next) - now).max(0.0))
        };
        let last = (*self.last_event.lock())
            .map(|l| json!({"rule": l.rule, "secs_ago": (now - l.at).max(0.0)}));
        json!({
            "config": cfg.to_json(),
            "secs_until_next_event": secs_until_next,
            "last_event": last,
        })
    }

    /// Read or tweak config. Returns the config after any change.
    pub fn apply_config(&self, args: &Json) -> Json {
        let mut cfg = self.config.lock();
        cfg.apply_args(args);
        cfg.to_json()
    }

    /// Register the standard `storyteller_config` op. Games
    /// register their own `storyteller_status` since it includes
    /// game-specific fields.
    pub fn register_config_op(&'static self) {
        OP_REGISTRY.register(OpDef::new(
            "storyteller_config",
            "Read (no args) or tweak the director's knobs live: min_gap_secs, max_gap_secs, retry_gap_secs.",
            "{min_gap_secs?: number, max_gap_secs?: number, retry_gap_secs?: number}",
            move |args| Ok(self.apply_config(args)),
        ));
    }

    fn ensure_seeded(&self, seed_fn: impl FnOnce() -> Result<i64, String>) -> bool {
        if self.rng_state.load(Ordering::Relaxed) != 0 {
            return true;
        }
        if let Ok(seed) = seed_fn() {
            self.rng_state.store(
                ((seed as u64) ^ 0xD1B5_4A32_D192_ED03) | 1,
                Ordering::Relaxed,
            );
            return true;
        }
        false
    }

    fn schedule_next(&self, now: f32, retry: bool) {
        let cfg = *self.config.lock();
        let gap = if retry {
            cfg.retry_gap_secs
        } else {
            let mut s = self.rng_state.load(Ordering::Relaxed);
            let g = draw_gap(&mut s, cfg.min_gap_secs, cfg.max_gap_secs);
            self.rng_state.store(s, Ordering::Relaxed);
            g
        };
        self.next_event_bits
            .store((now + gap).to_bits(), Ordering::Relaxed);
    }

    fn pick_rule(&self) -> &'static Rule {
        let weights: Vec<u32> = self.rules.iter().map(|r| r.weight).collect();
        let mut s = self.rng_state.load(Ordering::Relaxed);
        let i = pick_index(&mut s, &weights);
        self.rng_state.store(s, Ordering::Relaxed);
        &self.rules[i]
    }
}

// ---- pure RNG helpers ------------------------------------------------

fn split_next(state: &mut u64) -> u64 {
    *state = state.wrapping_add(0x9E37_79B9_7F4A_7C15);
    let mut z = *state;
    z = (z ^ (z >> 30)).wrapping_mul(0xBF58_476D_1CE4_E5B9);
    z = (z ^ (z >> 27)).wrapping_mul(0x94D0_49BB_1331_11EB);
    z ^ (z >> 31)
}

fn split_frac(state: &mut u64) -> f32 {
    (split_next(state) >> 40) as f32 / (1u64 << 24) as f32
}

fn draw_gap(state: &mut u64, min: f32, max: f32) -> f32 {
    min + split_frac(state) * (max - min)
}

fn pick_index(state: &mut u64, weights: &[u32]) -> usize {
    let total: u64 = weights.iter().map(|&w| u64::from(w)).sum();
    if total == 0 {
        return 0;
    }
    let roll = split_next(state) % total;
    let mut acc = 0u64;
    for (i, &w) in weights.iter().enumerate() {
        acc += u64::from(w);
        if roll < acc {
            return i;
        }
    }
    0
}

#[cfg(test)]
mod tests {
    use super::*;

    /// For a part, the first errand whose pivot points hold applies: stay
    /// home until the note is read, then nothing; sent, go to the thing
    /// until arrived; arrived, go home.
    #[test]
    fn the_first_errand_whose_condition_holds_applies() {
        let reached = |p: &[&str]| Cond::All(p.iter().map(|s| Cond::Reached(s.to_string())).collect());
        let not = |p: &str| Cond::Not(Box::new(Cond::Reached(p.to_string())));
        let errand = |does: ErrandAct, when: Cond| ErrandDef { name: None, who: Who::Part("Dell".to_string()), does, when, at: ErrandStart::Now, ends: None, reached_on_arrival: None };
        let go = ErrandAct::GoTo { thing: "tap".to_string(), side: 0.0 };
        let mut def = episode("test");
        def.errands = vec![
            errand(go.clone(), Cond::All(vec![reached(&["sent"]), not("looked")])),
            errand(ErrandAct::GoHome, Cond::All(vec![reached(&["sent", "looked"]), not("told again")])),
            errand(ErrandAct::StayHome, not("the note read")),
        ];
        let does = |reached: &[&str]| {
            let mut facts = World::default();
            for (i, p) in reached.iter().enumerate() {
                facts.pivots.push((p.to_string(), i as u64));
            }
            errand_for(&def, |w| *w == Who::Part("Dell".to_string()), &facts, |_| true).map(|e| e.does.clone())
        };
        assert_eq!(does(&[]), Some(ErrandAct::StayHome), "home until the note");
        assert_eq!(does(&["the note read"]), None, "then nothing asked");
        assert_eq!(does(&["the note read", "sent"]), Some(go), "sent: to the tap");
        assert_eq!(does(&["the note read", "sent", "looked"]), Some(ErrandAct::GoHome), "looked: home");
        assert_eq!(does(&["the note read", "sent", "looked", "told again"]), None);
        assert_eq!(errand_for(&def, |w| *w == Who::Part("Mara".to_string()), &World::default(), |_| true), None, "nothing asked of a part with no errand");
    }

    /// An episode with nothing in it but its name.
    fn episode(name: &str) -> EpisodeDef {
        EpisodeDef {
            name: name.to_string(),
            fits: Vec::new(),
            parts: Vec::new(),
            lines: Vec::new(),
            cues: Vec::new(),
            door_enemy: false,
            endings: Vec::new(),
            things: Vec::new(),
            errands: Vec::new(),
            deeds: Vec::new(),
        }
    }

    use crate::actor::ActorId;
    use crate::memory::{Did, Line, Memory};

    /// Facts given by hand: the player is 1; each person's memory, place and
    /// whether alive; the parts and groups by name; the episode's things,
    /// pivot points and errand windows; who is with whom, who holds what,
    /// who is home, the storm, an open store.
    #[derive(Default)]
    struct World {
        now: u64,
        people: Vec<(ActorId, bool, glam::Vec3, Memory)>,
        parts: Vec<(String, ActorId)>,
        groups: Vec<(Group, Vec<ActorId>)>,
        things: Vec<(String, glam::Vec3)>,
        pivots: Vec<(String, u64)>,
        windows: Vec<(String, u64, Option<u64>)>,
        with: Vec<(ActorId, ActorId)>,
        holding: Vec<(ActorId, String)>,
        home: Vec<ActorId>,
        storm: Option<crate::storm::StormPhase>,
        open: Vec<(ActorId, OpenStore)>,
    }

    impl Facts for World {
        fn now(&self) -> u64 {
            self.now
        }
        fn player(&self) -> ActorId {
            ActorId(1)
        }
        fn episode_started(&self) -> u64 {
            0
        }
        fn reached_at(&self, pivot: &str) -> Option<u64> {
            self.pivots.iter().find(|(p, _)| p == pivot).map(|(_, t)| *t)
        }
        fn window(&self, errand: &str) -> Option<(u64, Option<u64>)> {
            self.windows.iter().find(|(e, ..)| e == errand).map(|(_, from, to)| (*from, *to))
        }
        fn members(&self, who: &Who) -> Vec<ActorId> {
            match who {
                Who::ThePlayer => vec![ActorId(1)],
                Who::Part(p) => self.parts.iter().filter(|(n, _)| n == p).map(|(_, id)| *id).collect(),
                Who::Group(g) => self.groups.iter().filter(|(n, _)| n == g).flat_map(|(_, ids)| ids.clone()).collect(),
                Who::Anyone => self.people.iter().map(|p| p.0).collect(),
            }
        }
        fn alive(&self, id: ActorId) -> bool {
            self.people.iter().any(|p| p.0 == id && p.1)
        }
        fn memory(&self, id: ActorId) -> Option<&Memory> {
            self.people.iter().find(|p| p.0 == id).map(|p| &p.3)
        }
        fn feet(&self, id: ActorId) -> Option<glam::Vec3> {
            self.people.iter().find(|p| p.0 == id).map(|p| p.2)
        }
        fn thing_at(&self, thing: &str) -> Option<glam::Vec3> {
            self.things.iter().find(|(n, _)| n == thing).map(|(_, at)| *at)
        }
        fn item_of(&self, thing: &str) -> String {
            thing.to_string()
        }
        fn told_words(&self, _: ActorId, thing: &str) -> String {
            format!("told of the {thing}")
        }
        fn with(&self, a: ActorId, b: ActorId) -> bool {
            self.with.contains(&(a, b))
        }
        fn holds_at(&self, id: ActorId, thing: &str) -> bool {
            self.holding.iter().any(|(h, t)| *h == id && t == thing)
        }
        fn at_home(&self, id: ActorId) -> bool {
            self.home.contains(&id)
        }
        fn storm(&self) -> crate::storm::StormPhase {
            self.storm.unwrap_or(crate::storm::StormPhase::Calm)
        }
        fn opened(&self, id: ActorId) -> Option<OpenStore> {
            self.open.iter().find(|(o, _)| *o == id).map(|(_, s)| *s)
        }
    }

    fn person(world: &mut World, id: u64, at: glam::Vec3, did: &[(u64, Did)]) {
        let mut memory = Memory::default();
        for (t, d) in did {
            memory.did(d.clone(), *t);
        }
        world.people.push((ActorId(id), true, at, memory));
    }

    fn line(name: &str, words: &str) -> Line {
        Line { name: name.to_string(), words: words.to_string() }
    }

    /// Remembered: anyone's first drink is reached by whoever drank first,
    /// at their tick; told every member of a group holds only when each was
    /// told; a deed out of its window does not count.
    #[test]
    fn remembered_reads_memory_by_whom_toward_whom_and_when() {
        let mut w = World { now: 100, ..Default::default() };
        person(&mut w, 1, glam::Vec3::ZERO, &[(40, Did::Ate("tap".into())), (50, Did::Talked(ActorId(2), line("tell", "told of the tap")))]);
        person(&mut w, 2, glam::Vec3::ZERO, &[(30, Did::Ate("tap".into()))]);
        person(&mut w, 3, glam::Vec3::ZERO, &[]);
        w.groups.push((Group::ThePlayersBunker, vec![ActorId(1), ActorId(2), ActorId(3)]));
        let drank = Cond::Remembered { by: Who::Anyone, did: DidKind::Ate("tap".into()), toward: Target::Nobody, since: Since::EpisodeStart, every: false };
        assert_eq!(holds(&drank, &w), Some((ActorId(2), 30)), "the first who drank, at their tick");
        let told_all = Cond::Remembered { by: Who::ThePlayer, did: DidKind::Told("tap".into()), toward: Target::Who(Who::Group(Group::ThePlayersBunker)), since: Since::EpisodeStart, every: true };
        assert_eq!(holds(&told_all, &w), None, "3 was never told");
        w.people[0].3.did(Did::Talked(ActorId(3), line("tell", "told of the tap")), 60);
        assert_eq!(holds(&told_all, &w), Some((ActorId(1), 60)), "all told, at the last telling");
        w.windows.push(("the fight".into(), 70, Some(90)));
        let ate_during = Cond::Remembered { by: Who::ThePlayer, did: DidKind::Ate("tap".into()), toward: Target::Nobody, since: Since::During("the fight".into()), every: false };
        assert_eq!(holds(&ate_during, &w), None, "the drink at 40 is outside the window 70 to 90");
    }

    /// First: shoots first is the first of hit or talked toward a group being
    /// a hit; a word first and a hit after does not hold.
    #[test]
    fn first_is_the_first_of_those_deeds() {
        let maras = Group::BunkerOf("Mara".into());
        let shoots_first = Cond::First { by: Who::ThePlayer, of: vec![DidKind::Hit, DidKind::Talked], toward: Target::Who(Who::Group(maras.clone())), is: DidKind::Hit, since: Since::EpisodeStart };
        let mut w = World::default();
        person(&mut w, 1, glam::Vec3::ZERO, &[(10, Did::Hit(ActorId(5), 20.0)), (20, Did::Talked(ActorId(5), line("hi", "hi")))]);
        w.groups.push((maras.clone(), vec![ActorId(5)]));
        assert_eq!(holds(&shoots_first, &w), Some((ActorId(1), 10)));
        let mut w = World::default();
        person(&mut w, 1, glam::Vec3::ZERO, &[(10, Did::Talked(ActorId(5), line("hi", "hi"))), (20, Did::Hit(ActorId(5), 20.0))]);
        w.groups.push((maras, vec![ActorId(5)]));
        assert_eq!(holds(&shoots_first, &w), None, "spoke first");
    }

    /// The world pieces: near a thing, with someone, alive near a thing (the
    /// dead do not count), holding at a thing, home, the thing gone, the
    /// storm's phase, a store open.
    #[test]
    fn the_world_pieces_read_the_world() {
        let tap = glam::Vec3::new(10.0, 0.0, 0.0);
        let mut w = World { now: 5, ..Default::default() };
        person(&mut w, 1, glam::Vec3::new(8.0, 0.0, 0.0), &[]);
        person(&mut w, 2, glam::Vec3::new(9.0, 0.0, 0.0), &[]);
        person(&mut w, 3, glam::Vec3::new(10.0, 0.0, 1.0), &[]);
        w.people[2].1 = false;
        w.things.push(("tap".into(), tap));
        w.parts.push(("Dell".into(), ActorId(2)));
        w.groups.push((Group::CameFor("tap".into()), vec![ActorId(3)]));
        let near = |within: f32| Cond::Near { who: Who::ThePlayer, to: Target::Thing("tap".into()), within };
        assert!(holds(&near(4.0), &w).is_some() && holds(&near(1.0), &w).is_none());
        let with_dell = Cond::With { who: Who::Part("Dell".into()), of: Who::ThePlayer };
        assert!(holds(&with_dell, &w).is_none());
        w.with.push((ActorId(2), ActorId(1)));
        assert!(holds(&with_dell, &w).is_some(), "Dell follows the player");
        let strangers_near = Cond::Alive { who: Who::Group(Group::CameFor("tap".into())), near: Some((Target::Thing("tap".into()), 4.0)) };
        assert!(holds(&strangers_near, &w).is_none(), "the one stranger there is dead");
        w.holding.push((ActorId(2), "tap".into()));
        assert!(holds(&Cond::Holds { who: Who::Part("Dell".into()), thing: "tap".into() }, &w).is_some());
        assert!(holds(&Cond::AtHome { who: Who::ThePlayer }, &w).is_none());
        w.home.push(ActorId(1));
        assert!(holds(&Cond::AtHome { who: Who::ThePlayer }, &w).is_some());
        assert!(holds(&Cond::Gone("tap".into()), &w).is_none());
        w.things.clear();
        assert!(holds(&Cond::Gone("tap".into()), &w).is_some());
        assert!(holds(&Cond::Phase(crate::storm::StormPhase::Storm), &w).is_none());
        w.storm = Some(crate::storm::StormPhase::Storm);
        assert!(holds(&Cond::Phase(crate::storm::StormPhase::Storm), &w).is_some());
        let over = Cond::Opened { who: Who::ThePlayer, store: Store::TheirOwn, holds: Some(Measure::DaysOver(crate::survival::Need::Thirst, 10.0)) };
        w.open.push((ActorId(1), OpenStore { theirs: true, drawn_from: false, dry: false, days: (3.0, 12.0) }));
        assert!(holds(&over, &w).is_some(), "12 days of water, over 10");
        assert!(holds(&Cond::Opened { who: Who::ThePlayer, store: Store::DrawnFrom, holds: Some(Measure::Dry) }, &w).is_none());
    }

    /// All, Any, Not, an errand's window ended, and the first morning after;
    /// a condition writes and reads back (the episode files' data).
    #[test]
    fn conditions_join_and_errand_windows_and_mornings() {
        let mut w = World { now: 7, ..Default::default() };
        w.pivots.push(("a".into(), 3));
        let a = Cond::Reached("a".into());
        let b = Cond::Reached("b".into());
        assert!(holds(&Cond::All(vec![a.clone(), b.clone()]), &w).is_none());
        assert!(holds(&Cond::Any(vec![a.clone(), b.clone()]), &w).is_some());
        assert!(holds(&Cond::Not(Box::new(b.clone())), &w).is_some());
        w.windows.push(("the fight".into(), 2, None));
        assert!(holds(&Cond::Ended("the fight".into()), &w).is_none(), "still on");
        w.windows[0].2 = Some(6);
        assert_eq!(holds(&Cond::Ended("the fight".into()), &w), Some((ActorId(1), 6)));
        assert_eq!(starts_at(ErrandStart::Now, 250, 100), 250);
        assert_eq!(starts_at(ErrandStart::FirstMorningAfter, 250, 100), 300, "the next day's start");
        let stays_out = Cond::All(vec![Cond::Ended("the fight".into()), Cond::Not(Box::new(Cond::Remembered { by: Who::ThePlayer, did: DidKind::Hit, toward: Target::Who(Who::Anyone), since: Since::During("the fight".into()), every: false }))]);
        let text = serde_json::to_string(&stays_out).expect("a condition writes");
        let back: Cond = serde_json::from_str(&text).expect("and reads back");
        assert_eq!(back, stays_out, "{text}");
    }

    /// A cue is due once the player has done its deed since the episode
    /// started, and never again once reached.
    #[test]
    fn a_cue_is_due_once_its_deed_is_done_and_not_after() {
        use crate::memory::Did;
        let def = EpisodeDef {
            name: "the tap".to_string(),
            fits: Vec::new(),
            parts: Vec::new(),
            lines: Vec::new(),
            cues: vec![CueDef { name: "the note read".to_string(), did: "read note".to_string(), part: "Dell".to_string(), does: crate::command::Command::Knock { who: Who::ThePlayer } }],
            door_enemy: false,
            endings: Vec::new(),
            things: Vec::new(),
            errands: Vec::new(),
            deeds: Vec::new(),
        };
        assert!(cues_due(&def, &[], 10, &[]).is_empty(), "nothing done, nothing due");
        assert!(cues_due(&def, &[(5, Did::Read("note".to_string()))], 10, &[]).is_empty(), "read before the episode started");
        assert!(cues_due(&def, &[(12, Did::Read("map".to_string()))], 10, &[]).is_empty(), "another deed");
        let done = [(12, Did::Read("note".to_string()))];
        assert_eq!(cues_due(&def, &done, 10, &[]).len(), 1, "the note read: due");
        assert!(cues_due(&def, &done, 10, &["the note read"]).is_empty(), "once reached, never again");
    }

    fn episodes() -> EpisodeRegistry {
        let mut registry = EpisodeRegistry::default();
        let episode = |name: &str, fits: &[&str]| EpisodeDef {
            name: name.to_string(),
            fits: fits.iter().map(|r| r.to_string()).collect(),
            parts: Vec::new(),
            lines: Vec::new(),
            cues: Vec::new(),
            door_enemy: true,
            endings: Vec::new(),
            things: Vec::new(),
            errands: Vec::new(),
            deeds: Vec::new(),
        };
        registry.register(episode("anywhere", &[])).unwrap();
        registry.register(episode("only loop", &["Loop"])).unwrap();
        registry.register(episode("day or loop", &["Endless Day", "Loop"])).unwrap();
        registry
    }

    #[test]
    fn an_episode_is_only_picked_in_a_reality_it_fits() {
        let registry = episodes();
        for storms in 0..100 {
            for reality in ["Mixed world", "Endless Day", "Loop"] {
                let picked = registry.pick(reality, 7, storms).unwrap();
                assert!(picked.fits(reality), "{} picked in {reality}", picked.name);
            }
        }
    }

    #[test]
    fn every_fitting_episode_can_be_picked() {
        let registry = episodes();
        let picked: HashSet<String> = (0..200).map(|storms| registry.pick("Loop", 7, storms).unwrap().name.clone()).collect();
        assert_eq!(picked.len(), 3);
    }

    #[test]
    fn before_any_storm_it_is_the_first_registered_that_fits() {
        let registry = episodes();
        for seed in 0..20 {
            assert_eq!(registry.pick("Mixed world", seed, 0).unwrap().name, "anywhere");
            assert_eq!(registry.pick("Loop", seed, 0).unwrap().name, "anywhere");
        }
    }

    #[test]
    fn a_line_heard_feels_as_its_rule_says() {
        let mut registry = EpisodeRegistry::default();
        let line = |name: &str, felt| LineDef {
            name: name.to_string(),
            part: "player".to_string(),
            when: Vec::new(),
            ways: vec!["words".to_string()],
            tells: String::new(),
            felt,
            wait: 0.0,
        };
        registry
            .register(EpisodeDef {
                name: "the tap".to_string(),
                fits: Vec::new(),
                parts: Vec::new(),
                lines: vec![line("threatens Mara", -0.6), line("talks with Mara", 0.2)],
                cues: Vec::new(),
                door_enemy: false,
            endings: Vec::new(),
            things: Vec::new(),
            errands: Vec::new(),
            deeds: Vec::new(),
            })
            .unwrap();
        assert_eq!(registry.felt("threatens Mara"), -0.6);
        assert_eq!(registry.felt("talks with Mara"), 0.2);
        assert_eq!(registry.felt("nothing to say"), 0.0);
    }

    #[test]
    fn no_episode_when_none_fits() {
        let mut registry = EpisodeRegistry::default();
        registry
            .register(EpisodeDef {
                name: "only loop".to_string(),
                fits: vec!["Loop".to_string()],
                parts: Vec::new(),
                lines: Vec::new(),
                cues: Vec::new(),
                door_enemy: true,
            endings: Vec::new(),
            things: Vec::new(),
            errands: Vec::new(),
            deeds: Vec::new(),
            })
            .unwrap();
        assert_eq!(registry.pick("Mixed world", 7, 1), None);
    }

    fn ways() -> Vec<String> {
        [
            "Out the door, then {way}. Keep the {landmark} on your {side}.",
            "Go {way} out the door. The {place} has a tap.",
            "It's out there somewhere.",
        ]
        .map(str::to_string)
        .to_vec()
    }

    #[test]
    fn the_same_seed_says_it_the_same_way_every_slot_filled() {
        let slots = [("way", "left"), ("landmark", "radio tower"), ("side", "right"), ("place", "gas station")];
        for seed in 0..30 {
            let said = say(&ways(), &slots, seed, 1).unwrap();
            assert_eq!(Some(said.clone()), say(&ways(), &slots, seed, 1));
            assert!(!said.contains('{'), "{said}");
        }
        let all: HashSet<String> = (0..60).map(|seed| say(&ways(), &slots, seed, 1).unwrap()).collect();
        assert_eq!(all.len(), 3, "every way gets said");
    }

    #[test]
    fn a_way_with_a_slot_missing_is_never_said() {
        let slots = [("way", "left"), ("place", "gas station")];
        for seed in 0..30 {
            let said = say(&ways(), &slots, seed, 1).unwrap();
            assert!(!said.contains("landmark") && !said.contains('{'), "{said}");
        }
        assert_eq!(say(&ways()[..1], &slots, 7, 1), None, "no way can be filled");
    }

    /// The player's bunker (people 1 to 4), a near bunker (10 to 13), a
    /// far one (20 to 23).
    fn bunkers() -> Vec<CastBunker<u32>> {
        vec![
            CastBunker { player: false, distance: 900.0, people: vec![20, 21, 22, 23] },
            CastBunker { player: true, distance: 0.0, people: vec![1, 2, 3, 4] },
            CastBunker { player: false, distance: 300.0, people: vec![10, 11, 12, 13] },
        ]
    }

    fn the_tap() -> Vec<PartDef> {
        let part = |name: &str, from| PartDef { name: name.to_string(), from };
        vec![
            part("Dell", CastFrom::PlayerBunker),
            part("Mara", CastFrom::NearestOtherBunker),
            part("Mara's child", CastFrom::SameBunkerAs("Mara".to_string())),
        ]
    }

    #[test]
    fn each_part_is_cast_from_where_it_says() {
        for seed in 0..50 {
            let cast = cast(&the_tap(), &bunkers(), &[], |_| None, seed);
            let of = |part: &str| cast.iter().find(|(n, _)| n == part).map(|(_, p)| *p).unwrap();
            assert!((1..=4).contains(&of("Dell")), "Dell from the player's bunker");
            assert!((10..=13).contains(&of("Mara")), "Mara from the nearest other bunker");
            assert!((10..=13).contains(&of("Mara's child")), "the child from Mara's bunker");
            assert_ne!(of("Mara"), of("Mara's child"), "two parts never get the same person");
        }
    }

    #[test]
    fn the_same_seed_casts_the_same_people() {
        assert_eq!(cast(&the_tap(), &bunkers(), &[], |_| None, 7), cast(&the_tap(), &bunkers(), &[], |_| None, 7));
    }

    #[test]
    fn a_part_with_nobody_to_cast_is_left_out() {
        let lonely = vec![CastBunker { player: true, distance: 0.0, people: vec![1] }];
        let cast = cast(&the_tap(), &lonely, &[], |_| None, 7);
        assert_eq!(cast, vec![("Dell".to_string(), 1)]);
    }

    #[test]
    fn parts_drawn_from_memory_name_who_remembers_and_who_played_before() {
        let part = |name: &str, from| PartDef { name: name.to_string(), from };
        let parts = vec![
            part("the first sick person", CastFrom::MostTrustingOfPlayerBunker),
            part("Dell", CastFrom::PlayedBeforeAtHome("Dell".to_string())),
            part("Mara", CastFrom::PlayedBefore("Mara".to_string())),
        ];
        let before = vec![("Dell".to_string(), 2), ("Mara".to_string(), 11)];
        // 3 feels most toward the player; 2 played Dell and is home.
        let feels = |p: u32| match p {
            1 => Some(0.1),
            2 => Some(0.3),
            3 => Some(0.6),
            _ => None,
        };
        let cast = cast(&parts, &bunkers(), &before, feels, 7);
        assert_eq!(cast, vec![("the first sick person".to_string(), 3), ("Dell".to_string(), 2), ("Mara".to_string(), 11)]);
        // Dell gone from the player's bunker: Dell is left out.
        let moved = vec![("Dell".to_string(), 12), ("Mara".to_string(), 11)];
        let cast = super::cast(&parts, &bunkers(), &moved, feels, 7);
        assert!(!cast.iter().any(|(n, _)| n == "Dell"), "Dell, no longer home, is cast: {cast:?}");
    }
}
