//! The brain's rules (topside life.md "The brain"): what a person may do,
//! as the enter conditions and tasks of a StateTree (docs/statetree.md).
//! No engine, no entities: a `Perception` in, actions and one `Do` out.
//! What a person is doing between thinks is the tree's `Record`; which
//! states there are, in what order, is the game's tree. Every random
//! choice comes from a `Roll` the consumer seeds by tick and ActorId, so
//! a replay decides the same.
//!
//! Prior art: Endless's decision system, The Sims' needs (the worst need
//! drives the pick; what is known, not what exists, is considered),
//! Halo 2's lesson that the brain never reads the world directly.

use glam::Vec3;

use crate::actions::Action;
use crate::actor::{ActorId, Behaviour, Personality};
use crate::learn::{Band, Choice, Situation};
use crate::memory::{Known, Memory};
use crate::monument::Roll;
use crate::statetree::{Context, Status, Target};
use crate::survival::{Need, SurvivalStats};

/// What the consumer saw this think. Positions are world metres; y
/// is up and the ground is x and z. The brain steers with `Aim` at a
/// ground point and `Move` along the ground's x and z.
#[derive(Clone)]
pub struct Perception<'a> {
    pub now: u64,
    pub position: Vec3,
    pub yaw: f32,
    pub health_fraction: f32,
    pub needs: SurvivalStats,
    pub home: Option<Vec3>,
    pub behaviour: Behaviour,
    pub at_home: bool,
    pub asleep: bool,
    /// The nearest hostile in sight, if any.
    pub hostile: Option<(ActorId, Vec3)>,
    /// The storm is coming or here (topside design.md "The storm"):
    /// hide or die.
    pub storm_coming: bool,
    /// Something in their own bags answers hunger, and thirst: they
    /// eat and drink what they carry before going for more.
    pub carries_food: bool,
    pub carries_drink: bool,
    /// Their bunker's store, if they have one: its key and where.
    pub store: Option<(u64, Vec3)>,
    /// What their bunker is short of, by what they remember of its store
    /// and what they carry (topside design.md "Taking loot"): the needs
    /// that send them topside for more, the shortest first.
    pub bunker_short: Vec<Need>,
    /// They carry food or water that belongs in the store.
    pub carries_for_bunker: bool,
    /// Their bags hold no more.
    pub bags_full: bool,
    pub memory: &'a Memory,
    pub personality: &'a Personality,
    /// The registry's answer for a remembered thing: how much its
    /// kind is worth for a need (RimWorld: the def says, memory only
    /// remembers the kind). The consumer builds it from its
    /// registries; the brain never reads the world.
    pub worth: &'a dyn Fn(&Known, Need) -> f32,
    /// Whether a person can stand at a point (topside pathing.md: never
    /// head for a place nobody can stand on). The consumer answers from
    /// its tiles; a stroll or a trip out only ever picks a spot where
    /// this holds.
    pub standable: &'a dyn Fn(Vec3) -> bool,
}

impl std::fmt::Debug for Perception<'_> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("Perception")
            .field("now", &self.now)
            .field("position", &self.position)
            .field("needs", &self.needs)
            .field("hostile", &self.hostile)
            .finish_non_exhaustive()
    }
}

/// The one thing the consumer must carry out this tick with its own
/// data, because the brain cannot touch the world.
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Do {
    /// Eat or drink from the known thing `key`, for `need`.
    Eat {
        key: u64,
        need: Need,
    },
    Sleep,
    Wake,
    /// Look inside the known thing `key` and note what it held.
    Check {
        key: u64,
    },
    /// Eat or drink something they carry that answers `need`.
    EatCarried {
        need: Need,
    },
    /// At the known box `key`: take everything in it that they or their
    /// bunker need, as much as they can carry.
    Take {
        key: u64,
    },
    /// At their bunker's store `key`: put in the food and water they
    /// carry.
    Stock {
        key: u64,
    },
}

/// One think of one person: what they perceive, their roll, and what
/// they will do this tick, written by the tasks.
pub struct Think<'a> {
    pub p: &'a Perception<'a>,
    pub roll: &'a mut Roll,
    pub actions: Vec<Action>,
    pub do_now: Option<Do>,
}

impl<'a> Think<'a> {
    pub fn new(p: &'a Perception<'a>, roll: &'a mut Roll) -> Self {
        Self {
            p,
            roll,
            actions: Vec::new(),
            do_now: None,
        }
    }

    /// What they do this tick.
    fn act(&mut self, actions: Vec<Action>, do_now: Option<Do>) {
        self.actions = actions;
        self.do_now = do_now;
    }
}

/// The brain's tree is a tree of `Think`s.
pub struct Brain;

impl Context for Brain {
    type Of<'a> = Think<'a>;
}

/// How far a person chases before breaking off back home.
pub const LEASH: f32 = 60.0;
/// A need below this sends a person to something it knows.
pub const NEED_LINE: f32 = 50.0;
/// A need at or above this is met: eating or drinking for it stops.
pub const FED: f32 = 90.0;
/// Rest at or above this is rested: sleep ends.
pub const RESTED: f32 = 95.0;
/// A need below this, with nothing known to answer it, sends a person
/// looking.
pub const LOOK_LINE: f32 = 30.0;
/// Within this of a target counts as there.
pub const REACH: f32 = 1.5;
/// Metres of walking that cost one point of satisfaction.
const METRES_PER_POINT: f32 = 4.0;
/// How far someone with no home runs from a threat, metres.
pub const FLEE_FAR: f32 = 20.0;
/// How long a threat out of sight still drives a fight, in ticks (5 s).
pub const THREAT_RECENT: u64 = 300;
/// How far a person heads out to look when nothing they know answers a
/// need: something worth stopping for stands within this of almost
/// anywhere (topside design.md "The world", Bethesda's rule).
pub const LOOK_FAR: f32 = 150.0;
/// How many spots are rolled looking for one a person can stand on.
const SPOT_TRIES: usize = 8;

/// The moment as the learning sees it, kept small so like moments match.
pub fn situation(p: &Perception) -> Situation {
    let need = |v: f32| Band::of(v, LOOK_LINE, NEED_LINE);
    let knows = |n: Need| p.memory.good_for(n, p.worth).next().is_some();
    Situation {
        hunger: need(p.needs.hunger),
        thirst: need(p.needs.thirst),
        rest: need(p.needs.rest),
        health: Band::of(p.health_fraction, 0.3, 0.7),
        has_home: p.home.is_some(),
        at_home: p.at_home,
        hostile_in_sight: p.hostile.is_some(),
        carries_food: p.carries_food || p.carries_drink,
        knows_food: knows(Need::Hunger) || knows(Need::Thirst),
        storm_coming: p.storm_coming,
        bunker_short: !p.bunker_short.is_empty(),
    }
}

/// What they learned picks among the day's life (topside life.md
/// "Learning to stay alive").
pub fn learned(t: &mut Think, offered: &[Choice]) -> usize {
    t.p.memory.learned.pick(&situation(t.p), offered)
}

// The storm.

/// The storm is coming: hide or die, before anything else (the player
/// obeys the same storm). Home is the shelter a person knows; with no
/// home there is nowhere to go.
pub fn enter_hide(t: &mut Think, _: &Target) -> Option<Target> {
    if !t.p.storm_coming {
        return None;
    }
    t.p.home.map(Target::Point)
}

/// Home, then stay put.
pub fn hide(t: &mut Think, target: &Target) -> Status {
    let Target::Point(home) = *target else {
        return Status::Failed;
    };
    let actions = if t.p.at_home { vec![] } else { walk_toward(t.p, home) };
    t.act(actions, None);
    Status::Running
}

pub fn storm_over(t: &mut Think, _: &Target) -> bool {
    !t.p.storm_coming
}

// Fighting.

/// The threat they face: the nearest hostile in sight, or one
/// remembered in the last few seconds (topside life.md "Perception with
/// belief": belief, not truth, so the spot is where it was), and where
/// it is.
fn threat(p: &Perception) -> Option<(ActorId, Vec3)> {
    if let Some(seen) = p.hostile {
        return Some(seen);
    }
    let (who, at, when) = p.memory.last_threat?;
    (p.now.saturating_sub(when) <= THREAT_RECENT).then_some((who, at))
}

/// A threat in sight or just remembered: fight, flee, or break off. The
/// fight began where they stood, or where it began before.
pub fn enter_combat(t: &mut Think, about: &Target) -> Option<Target> {
    let (who, _) = threat(t.p)?;
    let began_at = match about {
        Target::Threat { began_at, .. } => *began_at,
        _ => t.p.position,
    };
    Some(Target::Threat { who, began_at })
}

/// Hurt past their flee line (courage moves it).
pub fn hurt(t: &mut Think, _: &Target) -> bool {
    t.p.health_fraction < t.p.personality.flee_line()
}

pub fn enter_flee(t: &mut Think, about: &Target) -> Option<Target> {
    hurt(t, about).then_some(*about)
}

/// Run home; with no home, away from the threat (a person with no home
/// is never going home: that never ends). Safe again, it is over.
pub fn flee(t: &mut Think, _: &Target) -> Status {
    let p = t.p;
    let Some((_, from)) = threat(p) else {
        t.act(vec![], None);
        return Status::Succeeded;
    };
    let to = p
        .home
        .unwrap_or_else(|| p.position + (p.position - from).with_y(0.0).normalize_or_zero() * FLEE_FAR);
    t.act(walk_toward(p, to), None);
    Status::Running
}

/// Chased farther than the leash from where the fight began.
pub fn past_leash(t: &mut Think, target: &Target) -> bool {
    matches!(target, Target::Threat { began_at, .. } if t.p.position.distance(*began_at) > LEASH)
}

pub fn enter_break_off(t: &mut Think, about: &Target) -> Option<Target> {
    past_leash(t, about).then_some(*about)
}

/// Home, or with no home back to where the fight began.
pub fn break_off(t: &mut Think, target: &Target) -> Status {
    let p = t.p;
    let Target::Threat { began_at, .. } = *target else {
        return Status::Failed;
    };
    let there = match p.home {
        Some(_) => p.at_home,
        None => p.position.distance(began_at) <= REACH,
    };
    if there {
        t.act(vec![], None);
        return Status::Succeeded;
    }
    t.act(walk_toward(p, p.home.unwrap_or(began_at)), None);
    Status::Running
}

/// Face the threat, close on it (hunters), hit it in reach; a threat
/// only remembered, a hunter goes to where it was and a guard turns to
/// face it. Nothing in sight or remembered: the fight is over.
pub fn fight(t: &mut Think, _: &Target) -> Status {
    let p = t.p;
    let wake = p.asleep.then_some(Do::Wake);
    if let Some((_, at)) = p.hostile {
        let mut actions = turn_toward(p, at);
        if p.position.distance(at) <= reach_of(p) {
            actions.push(Action::Attack);
        } else if p.behaviour == Behaviour::Hunter {
            actions.push(step_toward(p, at));
        }
        t.act(actions, wake);
        return Status::Running;
    }
    let Some((_, at)) = threat(p) else {
        t.act(vec![], None);
        return Status::Succeeded;
    };
    let actions = if p.behaviour == Behaviour::Hunter {
        walk_toward(p, at)
    } else {
        turn_toward(p, at)
    };
    t.act(actions, wake);
    Status::Running
}

// The day's life.

/// The storm or a threat takes a person out of whatever they are doing.
pub fn danger(t: &mut Think, _: &Target) -> bool {
    (t.p.storm_coming && t.p.home.is_some()) || threat(t.p).is_some()
}

/// Hungry or thirsty with the answer in their own bags: eat or drink it
/// where they stand, the way the player does.
pub fn enter_eat_carried(t: &mut Think, _: &Target) -> Option<Target> {
    let p = t.p;
    let need = if p.needs.hunger < NEED_LINE && p.carries_food {
        Need::Hunger
    } else if p.needs.thirst < NEED_LINE && p.carries_drink {
        Need::Thirst
    } else {
        return None;
    };
    Some(Target::Need(need))
}

pub fn eat_carried(t: &mut Think, target: &Target) -> Status {
    let Target::Need(need) = *target else {
        return Status::Failed;
    };
    t.act(vec![], Some(Do::EatCarried { need }));
    Status::Succeeded
}

/// The worst need, when it presses, picks the best known thing: what it
/// gives minus the walk, the walk costing a Lazy person more.
fn need_target(p: &Perception) -> Option<Target> {
    let (need, value) = p.needs.worst_need();
    if value >= NEED_LINE {
        return None;
    }
    let diligence = p.personality.get(crate::actor::Axis::Diligence);
    let walk_cost = 1.0 - 0.25 * diligence;
    let (known, _) = p
        .memory
        .good_for(need, p.worth)
        .map(|(known, gives)| (known, gives - known.position.distance(p.position) / METRES_PER_POINT * walk_cost))
        .filter(|(_, score)| *score > 0.0)
        .max_by(|a, b| a.1.total_cmp(&b.1))?;
    Some(Target::Thing {
        key: known.key,
        at: known.position,
        need: Some(need),
    })
}

pub fn enter_need(t: &mut Think, _: &Target) -> Option<Target> {
    need_target(t.p)
}

/// Walk to what the state is about; there, it succeeds. Rest is had at
/// home, anywhere in it.
pub fn going(t: &mut Think, target: &Target) -> Status {
    let (at, need) = match *target {
        Target::Thing { at, need, .. } => (at, need),
        Target::Point(at) => (at, None),
        _ => return Status::Failed,
    };
    let p = t.p;
    let arrived = (at - p.position).with_y(0.0).length() <= REACH || (need == Some(Need::Rest) && p.at_home);
    if arrived {
        t.act(vec![], None);
        return Status::Succeeded;
    }
    t.act(walk_toward(p, at), None);
    Status::Running
}

/// Whether the known thing `key` is still believed to hold something for
/// `need` (or has not been looked inside yet).
fn holds_for(p: &Perception, key: u64, need: Need) -> bool {
    p.memory
        .known
        .iter()
        .any(|k| k.key == key && k.believed_to_hold() && (k.held.is_none() || (p.worth)(k, need) > 0.0))
}

/// At the thing, for the need that sent them, until that need is met
/// (everything is for a need): eat or drink until fed or it holds nothing
/// for it, sleep until rested, a place for safety is one look.
pub fn use_it(t: &mut Think, target: &Target) -> Status {
    let Target::Thing { key, need: Some(need), .. } = *target else {
        return Status::Failed;
    };
    let p = t.p;
    match need {
        Need::Hunger | Need::Thirst => {
            let now = if need == Need::Hunger { p.needs.hunger } else { p.needs.thirst };
            if now >= FED || !holds_for(p, key, need) {
                t.act(vec![], None);
                return Status::Succeeded;
            }
            t.act(vec![], Some(Do::Eat { key, need }));
            Status::Running
        }
        Need::Rest => {
            if p.needs.rest >= RESTED {
                t.act(vec![], Some(Do::Wake));
                return Status::Succeeded;
            }
            t.act(vec![], (!p.asleep).then_some(Do::Sleep));
            Status::Running
        }
        Need::Safety => {
            t.act(vec![], None);
            Status::Succeeded
        }
    }
}

/// Look inside the thing once.
pub fn check(t: &mut Think, target: &Target) -> Status {
    let Target::Thing { key, .. } = *target else {
        return Status::Failed;
    };
    t.act(vec![], Some(Do::Check { key }));
    Status::Succeeded
}

/// Take what they and their bunker need, as much as they can carry:
/// until the bags are full or nothing in the box answers the need.
pub fn take(t: &mut Think, target: &Target) -> Status {
    let Target::Thing { key, need: Some(need), .. } = *target else {
        return Status::Failed;
    };
    let p = t.p;
    if p.bags_full || !holds_for(p, key, need) {
        t.act(vec![], None);
        return Status::Succeeded;
    }
    t.act(vec![], Some(Do::Take { key }));
    Status::Running
}

/// Put what they carried home into the store, until nothing is carried.
pub fn stock(t: &mut Think, target: &Target) -> Status {
    let Target::Thing { key, .. } = *target else {
        return Status::Failed;
    };
    if !t.p.carries_for_bunker {
        t.act(vec![], None);
        return Status::Succeeded;
    }
    t.act(vec![], Some(Do::Stock { key }));
    Status::Running
}

// The bunker's needs (topside design.md "Taking loot").

/// Their bunker's store, if they have one.
pub fn enter_supply(t: &mut Think, _: &Target) -> Option<Target> {
    t.p.store.map(|_| Target::None)
}

/// The best known box for any need the bunker is short of: a box seen
/// holding something, since only what is inside can be carried home (a
/// well is drunk from where it stands).
fn supply_best(p: &Perception) -> Option<Target> {
    let (store, _) = p.store?;
    if p.bags_full {
        return None;
    }
    p.bunker_short
        .iter()
        .flat_map(|&need| {
            p.memory
                .good_for(need, p.worth)
                .filter(move |(k, _)| k.key != store && k.held.is_some())
                .map(move |(k, gives)| (k, need, gives - k.position.distance(p.position) / METRES_PER_POINT))
        })
        .max_by(|a, b| a.2.total_cmp(&b.2))
        .map(|(k, need, _)| Target::Thing {
            key: k.key,
            at: k.position,
            need: Some(need),
        })
}

/// The nearest known box not yet looked inside, other than their store.
fn unopened<'a>(p: &Perception<'a>) -> Option<&'a Known> {
    let store = p.store.map(|(key, _)| key);
    p.memory
        .known
        .iter()
        .filter(|k| k.checked_at.is_none() && Some(k.key) != store)
        .min_by(|a, b| a.position.distance(p.position).total_cmp(&b.position.distance(p.position)))
}

/// Carrying food or water home: when the bunker is no longer short, the
/// bags are full, or there is nowhere left to look.
pub fn enter_haul(t: &mut Think, _: &Target) -> Option<Target> {
    let p = t.p;
    let (store, at) = p.store?;
    let short = !p.bunker_short.is_empty();
    let nowhere_to_look = supply_best(p).is_none() && unopened(p).is_none();
    (p.carries_for_bunker && (!short || p.bags_full || nowhere_to_look)).then_some(Target::Thing {
        key: store,
        at,
        need: None,
    })
}

/// While the bunker is short: to the best box they know holds what it
/// needs.
pub fn enter_fetch(t: &mut Think, _: &Target) -> Option<Target> {
    supply_best(t.p)
}

/// Short with no box known to hold it: look inside one not yet opened.
pub fn enter_look_in(t: &mut Think, _: &Target) -> Option<Target> {
    let p = t.p;
    if p.bags_full || p.bunker_short.is_empty() {
        return None;
    }
    unopened(p).map(|k| Target::Thing {
        key: k.key,
        at: k.position,
        need: None,
    })
}

/// Short with nothing known and nothing to open: head out to find out.
pub fn enter_head_out_short(t: &mut Think, _: &Target) -> Option<Target> {
    if t.p.bags_full || t.p.bunker_short.is_empty() {
        return None;
    }
    head_out_spot(t)
}

// Looking.

/// A need pressing hard with nothing known to answer it.
pub fn enter_look(t: &mut Think, _: &Target) -> Option<Target> {
    (t.p.needs.worst_need().1 < LOOK_LINE).then_some(Target::None)
}

/// The nearest known thing never checked.
pub fn enter_unchecked(t: &mut Think, _: &Target) -> Option<Target> {
    let p = t.p;
    p.memory.unchecked_nearest(p.position).map(|k| Target::Thing {
        key: k.key,
        at: k.position,
        need: None,
    })
}

/// Food and water are out there to be found; rest and safety are not
/// found by walking off.
pub fn enter_head_out_need(t: &mut Think, _: &Target) -> Option<Target> {
    let (need, _) = t.p.needs.worst_need();
    if !matches!(need, Need::Hunger | Need::Thirst) {
        return None;
    }
    head_out_spot(t)
}

/// `LOOK_FAR` from home (or from here, with no home) a rolled way, a spot
/// someone can stand on. What is seen on the way goes into memory, and
/// the rules that use memory take over.
fn head_out_spot(t: &mut Think) -> Option<Target> {
    let centre = t.p.home.unwrap_or(t.p.position);
    standable_spot(t.p, t.roll, |roll| {
        let angle = roll.measure(0.0, std::f32::consts::TAU);
        centre + Vec3::new(angle.cos() * LOOK_FAR, 0.0, angle.sin() * LOOK_FAR)
    })
    .map(Target::Point)
}

/// Out looking, something known now answers: choose again.
pub fn knows_better(t: &mut Think, _: &Target) -> bool {
    let p = t.p;
    need_target(p).is_some() || supply_best(p).is_some() || (!p.bunker_short.is_empty() && unopened(p).is_some())
}

// Wandering.

/// Nothing presses: most thinks they stand; one in ten they stroll to a
/// rolled point within the home radius, a spot someone can stand on.
pub fn enter_wander(t: &mut Think, _: &Target) -> Option<Target> {
    if !t.roll.chance(100) {
        return Some(Target::None);
    }
    let centre = t.p.home.unwrap_or(t.p.position);
    let radius = t.p.behaviour.home_radius();
    let spot = standable_spot(t.p, t.roll, |roll| {
        let angle = roll.measure(0.0, std::f32::consts::TAU);
        let distance = roll.measure(radius * 0.3, radius);
        centre + Vec3::new(angle.cos() * distance, 0.0, angle.sin() * distance)
    });
    Some(spot.map_or(Target::None, Target::Point))
}

/// Stand this think, or stroll to the spot.
pub fn wander(t: &mut Think, target: &Target) -> Status {
    match target {
        Target::Point(_) => going(t, target),
        _ => {
            t.act(vec![], None);
            Status::Succeeded
        }
    }
}

/// A need or their bunker presses: a stroll gives way to it.
pub fn pressing(t: &mut Think, _: &Target) -> bool {
    let p = t.p;
    p.needs.worst_need().1 < NEED_LINE || (p.store.is_some() && (!p.bunker_short.is_empty() || p.carries_for_bunker))
}

// Reaction.

/// How quickly a person reacts, by what they are doing (topside life.md
/// "How often a person thinks"), in seconds.
pub const COMBAT_REACTION: f32 = 0.25;
pub const AWAKE_REACTION: f32 = 1.0;
pub const ASLEEP_REACTION: f32 = 10.0;
/// The most tiredness slows a person: half as slow again with no rest.
pub const TIRED_SLOWEST: f32 = 1.5;

/// Ticks (at `ticks_per_sec`) until this person next decides: their
/// reaction time for what they are doing (asleep, fighting, or otherwise
/// awake), slower the more tired they are, quicker or slower by
/// personality the way it sets their swing. Being hit does not shorten
/// it: a person under fire is at the combat rate.
pub fn reaction_ticks(asleep: bool, fighting: bool, rest: f32, personality: &Personality, ticks_per_sec: f32) -> u64 {
    let base = if asleep {
        ASLEEP_REACTION
    } else if fighting {
        COMBAT_REACTION
    } else {
        AWAKE_REACTION
    };
    let tired = 1.0 + (TIRED_SLOWEST - 1.0) * (1.0 - rest / crate::survival::FULL).clamp(0.0, 1.0);
    let quickness = personality.swing_delay(1.0);
    ((base * tired * quickness * ticks_per_sec).round() as u64).max(1)
}

// Steering.

/// The first rolled spot a person can stand on, within `SPOT_TRIES`.
fn standable_spot(p: &Perception, roll: &mut Roll, mut spot: impl FnMut(&mut Roll) -> Vec3) -> Option<Vec3> {
    (0..SPOT_TRIES).map(|_| spot(roll)).find(|to| (p.standable)(*to))
}

fn reach_of(p: &Perception) -> f32 {
    1.8 * p.personality.range_mult()
}

/// Face a point: aim at it on the ground (topside combat.md: a person
/// faces what they aim at, seen from above).
fn turn_toward(p: &Perception, to: Vec3) -> Vec<Action> {
    if (to - p.position).with_y(0.0).length() < 1e-4 {
        return vec![];
    }
    vec![Action::Aim { x: to.x, y: to.z }]
}

/// A step toward a point along the ground: the move's x is the
/// world's x and its y is the world's z, the view's right and up seen
/// from above.
fn step_toward(p: &Perception, to: Vec3) -> Action {
    let d = (to - p.position).with_y(0.0).normalize_or_zero();
    Action::Move { x: d.x, y: d.z }
}

/// Face a point and walk to it, unless already there.
fn walk_toward(p: &Perception, to: Vec3) -> Vec<Action> {
    let flat = (to - p.position).with_y(0.0);
    if flat.length() <= REACH {
        return vec![];
    }
    let mut actions = turn_toward(p, to);
    actions.push(step_toward(p, to));
    actions
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::actor::Axis;

    fn perception<'a>(memory: &'a Memory, personality: &'a Personality) -> Perception<'a> {
        Perception {
            now: 100,
            position: Vec3::ZERO,
            yaw: 0.0,
            health_fraction: 1.0,
            needs: SurvivalStats::default(),
            home: Some(Vec3::ZERO),
            behaviour: Behaviour::Hunter,
            at_home: true,
            asleep: false,
            hostile: None,
            storm_coming: false,
            carries_food: false,
            carries_drink: false,
            store: None,
            bunker_short: Vec::new(),
            carries_for_bunker: false,
            bags_full: false,
            memory,
            personality,
            worth: &|_, _| 0.0,
            standable: &|_| true,
        }
    }

    /// A stroll and a trip out only pick a spot someone can stand on;
    /// with none standable, the person stays.
    #[test]
    fn strolls_and_trips_out_only_pick_standable_spots() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let east = |at: Vec3| at.x > 0.0;
        p.standable = &east;
        p.bunker_short = vec![Need::Hunger];
        let mut picked = 0;
        for seed in 0..40 {
            let mut roll = Roll::new(seed);
            let mut t = Think::new(&p, &mut roll);
            for target in [enter_head_out_short(&mut t, &Target::None), enter_wander(&mut t, &Target::None)] {
                if let Some(Target::Point(to)) = target {
                    picked += 1;
                    assert!(to.x > 0.0, "seed {seed}: headed for {to}, nobody can stand there");
                }
            }
        }
        assert!(picked > 0, "some spots were picked");
        let nowhere = |_: Vec3| false;
        p.standable = &nowhere;
        for seed in 0..40 {
            let mut roll = Roll::new(seed);
            let mut t = Think::new(&p, &mut roll);
            assert_eq!(enter_head_out_short(&mut t, &Target::None), None, "nowhere standable: no trip out");
            assert!(!matches!(enter_wander(&mut t, &Target::None), Some(Target::Point(_))), "nor a stroll");
        }
    }

    #[test]
    fn reaction_time_follows_what_a_person_is_doing_and_how_tired() {
        let calm = Personality::default();
        let full = crate::survival::FULL;
        assert_eq!(reaction_ticks(false, true, full, &calm, 60.0), 15, "combat, 250 ms");
        assert_eq!(reaction_ticks(false, false, full, &calm, 60.0), 60, "awake, 1 s");
        assert_eq!(reaction_ticks(true, false, full, &calm, 60.0), 600, "asleep, 10 s");
        assert_eq!(reaction_ticks(false, false, 0.0, &calm, 60.0), 90, "exhausted, half as slow again");
        let mut quick = calm;
        quick.axes[Axis::Agility as usize] = 1.0;
        assert!(reaction_ticks(false, false, full, &quick, 60.0) < 60, "an agile person is quicker");
    }
}
