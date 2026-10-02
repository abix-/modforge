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
#[derive(Clone, Debug, PartialEq)]
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
}

/// One line, as a rule (topside episodes.md "One way for every
/// conversation"; Valve's response rules): who may say it, what must be
/// true when they do, several ways of saying it with {slots} filled from
/// the world and the speaker's memory, what it tells, and how hearing it
/// feels. An episode's line, a plain line, and the player's choice are
/// all this; `crate::talk::pick` says the best matching one.
#[derive(Clone, Debug, PartialEq)]
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

/// One thing that must be true of the speaker for a line to be said, read
/// from their memory and the moment (`crate::talk::Speaking`).
#[derive(Clone, Debug, PartialEq)]
pub enum When {
    /// The one spoken to is cast as this part, or "player".
    To(String),
    /// The one spoken to started this conversation (the player's E).
    Opened,
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
#[derive(Clone, Debug, PartialEq)]
pub struct PartDef {
    pub name: String,
    pub from: CastFrom,
}

/// Where a part is cast from: always a bunker person, since only bunker
/// people live on across episodes (realities.md).
#[derive(Clone, Debug, PartialEq)]
pub enum CastFrom {
    /// A random person of the player's bunker.
    PlayerBunker,
    /// A random person of the bunker nearest the player's.
    NearestOtherBunker,
    /// A random person of the same bunker as the named part.
    SameBunkerAs(String),
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
pub fn cast<P: Copy + PartialEq>(parts: &[PartDef], bunkers: &[CastBunker<P>], seed: u64) -> Vec<(String, P)> {
    let nearest = bunkers
        .iter()
        .enumerate()
        .filter(|(_, b)| !b.player && !b.people.is_empty())
        .min_by(|a, b| a.1.distance.total_cmp(&b.1.distance))
        .map(|(i, _)| i);
    let mut cast: Vec<(String, P, usize)> = Vec::new();
    for (salt, part) in parts.iter().enumerate() {
        let bunker = match &part.from {
            CastFrom::PlayerBunker => bunkers.iter().position(|b| b.player),
            CastFrom::NearestOtherBunker => nearest,
            CastFrom::SameBunkerAs(other) => cast.iter().find(|(n, ..)| n == other).map(|(.., b)| *b),
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

    fn episodes() -> EpisodeRegistry {
        let mut registry = EpisodeRegistry::default();
        let episode = |name: &str, fits: &[&str]| EpisodeDef {
            name: name.to_string(),
            fits: fits.iter().map(|r| r.to_string()).collect(),
            parts: Vec::new(),
            lines: Vec::new(),
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
            let cast = cast(&the_tap(), &bunkers(), seed);
            let of = |part: &str| cast.iter().find(|(n, _)| n == part).map(|(_, p)| *p).unwrap();
            assert!((1..=4).contains(&of("Dell")), "Dell from the player's bunker");
            assert!((10..=13).contains(&of("Mara")), "Mara from the nearest other bunker");
            assert!((10..=13).contains(&of("Mara's child")), "the child from Mara's bunker");
            assert_ne!(of("Mara"), of("Mara's child"), "two parts never get the same person");
        }
    }

    #[test]
    fn the_same_seed_casts_the_same_people() {
        assert_eq!(cast(&the_tap(), &bunkers(), 7), cast(&the_tap(), &bunkers(), 7));
    }

    #[test]
    fn a_part_with_nobody_to_cast_is_left_out() {
        let lonely = vec![CastBunker { player: true, distance: 0.0, people: vec![1] }];
        let cast = cast(&the_tap(), &lonely, 7);
        assert_eq!(cast, vec![("Dell".to_string(), 1)]);
    }
}
