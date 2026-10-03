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
    /// Where a stroll can go from here, every spot reachable without a
    /// search (topside life.md "Wander": the walk grid's chunk and its
    /// doorways). Asked only when they stroll.
    pub reachable: &'a dyn Fn() -> Vec<Vec3>,
    /// Whether a spot is off the map this person carries: never seen.
    pub unknown: &'a dyn Fn(Vec3) -> bool,
    /// A place they were asked to go to and wait at (an episode's errand:
    /// topside episodes.md), weighed like any other choice.
    pub asked: Option<Vec3>,
    /// Someone in sight, not hostile, carrying more than they need of what
    /// answers one of this person's needs (crate::trade): who, where, and
    /// the need. The consumer finds them from what people carry.
    pub trader: Option<(ActorId, Vec3, Need)>,
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
    /// At `with`: trade for one thing that answers `need`, paying with
    /// what they can spare, if `with` takes it (crate::trade).
    Trade {
        with: ActorId,
        need: Need,
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
/// A need below this is critical: it outranks what they were asked to do
/// (an episode's errand), and once it is met they go back to it
/// (RimWorld's ThinkTree: critical needs above assigned jobs). Claude's
/// number (topside orchestrator, 2026-10-03), for the operator to change.
pub const NEED_CRITICAL: f32 = 15.0;
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
/// "Learning to stay alive"). Asked to be somewhere (an episode's errand,
/// held to talk, holding a place), what was asked outranks their own
/// errands after it in the tree (supplying, looking, wandering), whatever
/// they learned; what comes before it (danger, their own needs) still
/// weighs against it (topside orchestrator, 2026-10-03: Roxanne left the
/// talk to look in a box).
///
/// A critical need they can answer (`critical_need`) outranks what was
/// asked: then the choices are only those before it (eating what they
/// carry, going to a need, trading for it); met, the next choice offers
/// what was asked again, and they go back to it.
pub fn learned(t: &mut Think, offered: &[Choice]) -> usize {
    let critical = critical_need(t, &Target::None);
    let up_to = match offered.iter().position(|c| *c == Choice::Asked) {
        Some(asked) if critical && asked > 0 => asked,
        Some(asked) => asked + 1,
        None => offered.len(),
    };
    t.p.memory.learned.pick(&situation(t.p), &offered[..up_to])
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
    let actions = if t.p.at_home { vec![] } else { walk_toward(t.p.position, home) };
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

/// A threat in sight or just remembered: something to fight, flee, or
/// break off from. The fight began where they stood, or where it began
/// before.
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

/// A threat, and hurt past the flee line.
pub fn enter_flee(t: &mut Think, about: &Target) -> Option<Target> {
    let threat = enter_combat(t, about)?;
    hurt(t, &threat).then_some(threat)
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
    t.act(walk_toward(p.position, to), None);
    Status::Running
}

/// Chased farther than the leash from where the fight began.
pub fn past_leash(t: &mut Think, target: &Target) -> bool {
    matches!(target, Target::Threat { began_at, .. } if t.p.position.distance(*began_at) > LEASH)
}

/// A threat, and chased past the leash.
pub fn enter_break_off(t: &mut Think, about: &Target) -> Option<Target> {
    let threat = enter_combat(t, about)?;
    past_leash(t, &threat).then_some(threat)
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
    t.act(walk_toward(p.position, p.home.unwrap_or(began_at)), None);
    Status::Running
}

/// Face the threat, close on it (hunters), hit it in reach; a threat
/// only remembered, a hunter goes to where it was and a guard turns to
/// face it. Nothing in sight or remembered: the fight is over.
pub fn fight(t: &mut Think, _: &Target) -> Status {
    let p = t.p;
    let wake = p.asleep.then_some(Do::Wake);
    if let Some((_, at)) = p.hostile {
        let mut actions = turn_toward(p.position, at);
        if p.position.distance(at) <= reach_of(p) {
            actions.push(Action::Attack);
        } else if p.behaviour == Behaviour::Hunter {
            actions.extend(walk_toward(p.position, at));
        }
        t.act(actions, wake);
        return Status::Running;
    }
    let Some((_, at)) = threat(p) else {
        t.act(vec![], None);
        return Status::Succeeded;
    };
    let actions = if p.behaviour == Behaviour::Hunter {
        walk_toward(p.position, at)
    } else {
        turn_toward(p.position, at)
    };
    t.act(actions, wake);
    Status::Running
}

// The day's life.

/// The storm or a threat takes a person out of whatever they are doing.
pub fn danger(t: &mut Think, _: &Target) -> bool {
    (t.p.storm_coming && t.p.home.is_some()) || threat(t.p).is_some()
}

/// Asked to be somewhere takes a person out of their own errands
/// (supplying, looking, wandering), which `learned` ranks below it.
pub fn asked_now(t: &mut Think, _: &Target) -> bool {
    t.p.asked.is_some()
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

/// The needs that press, worst first: the first that something known
/// answers picks the best known thing for it, what it gives minus the
/// walk, the walk costing a Lazy person more. A need nothing known answers
/// does not hide the next: worn out with nowhere to sleep, a person still
/// goes to the well they know.
fn need_target(p: &Perception) -> Option<Target> {
    let diligence = p.personality.get(crate::actor::Axis::Diligence);
    let walk_cost = 1.0 - 0.25 * diligence;
    p.needs
        .needs_worst_first()
        .into_iter()
        .take_while(|(_, value)| *value < NEED_LINE)
        .find_map(|(need, _)| {
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
        })
}

pub fn enter_need(t: &mut Think, _: &Target) -> Option<Target> {
    need_target(t.p)
}

/// Seeing to one need while another falls past the look line and below
/// it: that one comes first (seen in the running game, topside
/// tests/thirst.rs: people slept at their camp until they died of thirst,
/// knowing the water).
pub fn worse_need(t: &mut Think, target: &Target) -> bool {
    let Target::Thing { need: Some(serving), .. } = *target else {
        return false;
    };
    let needs = t.p.needs.needs_worst_first();
    let value = |n: Need| needs.iter().find(|(m, _)| *m == n).map_or(0.0, |(_, v)| *v);
    let (worst, lowest) = needs[0];
    worst != serving && lowest < LOOK_LINE && lowest < value(serving)
}

/// A need below `NEED_CRITICAL` that they can do something about (what
/// they carry, a thing they know, someone to trade with): it outranks what
/// they were asked to do (`learned`; the asked state's way back to the
/// root). One they can do nothing about leaves them where they were asked.
pub fn critical_need(t: &mut Think, target: &Target) -> bool {
    t.p.needs.worst_need().1 < NEED_CRITICAL
        && (enter_eat_carried(t, target).is_some() || need_target(t.p).is_some() || enter_trade(t, target).is_some())
}

// Trade.

/// Near enough to someone to trade with them, in metres: talking distance
/// (topside's is 3), short of it.
pub const TRADE_REACH: f32 = 2.5;

/// A need under the need line and someone in sight carrying more than
/// they need of what answers it: to them, to trade (topside design.md
/// "Trading": people trade with each other when one has extra of what the
/// other needs; operator, 2026-10-02).
pub fn enter_trade(t: &mut Think, _: &Target) -> Option<Target> {
    let (who, at, need) = t.p.trader?;
    let value = t.p.needs.needs_worst_first().into_iter().find(|(n, _)| *n == need).map(|(_, v)| v)?;
    (value < NEED_LINE).then_some(Target::Trader { who, at, need })
}

/// At the one they trade with: the trade (`Do::Trade`), once; done.
pub fn trade_with(t: &mut Think, target: &Target) -> Status {
    let Target::Trader { who, need, .. } = *target else {
        return Status::Failed;
    };
    t.act(vec![], Some(Do::Trade { with: who, need }));
    Status::Succeeded
}

/// Walk to what the state is about, awake; there, it succeeds. Rest is
/// had at home, anywhere in it.
pub fn going(t: &mut Think, target: &Target) -> Status {
    let (at, need) = match *target {
        Target::Thing { at, need, .. } => (at, need),
        Target::Trader { at, need, .. } => (at, Some(need)),
        Target::Point(at) => (at, None),
        _ => return Status::Failed,
    };
    let p = t.p;
    // There as walking there counts it (`walk_toward`, in 3D: right above or
    // below is not there); to someone to trade with, near enough to talk
    // (their own body keeps others about that far).
    let arrived = match *target {
        Target::Trader { .. } => (at - p.position).length() <= TRADE_REACH,
        _ => walk_toward(p.position, at).is_empty() || (need == Some(Need::Rest) && p.at_home),
    };
    if arrived {
        t.act(vec![], None);
        return Status::Succeeded;
    }
    t.act(walk_toward(p.position, at), p.asleep.then_some(Do::Wake));
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
/// spot that is random, reachable, and unknown (topside life.md "Wander"):
/// one of the spots they can reach without a search, within the home
/// radius, off their map when any such spot is.
pub fn enter_wander(t: &mut Think, _: &Target) -> Option<Target> {
    if !t.roll.chance(100) {
        return Some(Target::None);
    }
    let centre = t.p.home.unwrap_or(t.p.position);
    let radius = t.p.behaviour.home_radius();
    let spots: Vec<Vec3> = (t.p.reachable)()
        .into_iter()
        .filter(|s| s.distance(centre) <= radius && s.distance(t.p.position) > REACH)
        .collect();
    let unknown: Vec<Vec3> = spots.iter().copied().filter(|s| (t.p.unknown)(*s)).collect();
    let pool = if unknown.is_empty() { spots } else { unknown };
    if pool.is_empty() {
        return Some(Target::None);
    }
    Some(Target::Point(*t.roll.pick(&pool)))
}

// Asked.

/// Asked to go somewhere: there.
pub fn enter_asked(t: &mut Think, _: &Target) -> Option<Target> {
    t.p.asked.map(Target::Point)
}

/// Where they were asked to be: wait there, as long as they are asked.
pub fn wait(t: &mut Think, _: &Target) -> Status {
    t.act(vec![], None);
    Status::Running
}

/// No longer asked to be where they are headed: choose again.
pub fn not_asked(t: &mut Think, target: &Target) -> bool {
    match (t.p.asked, target) {
        (Some(asked), Target::Point(at)) => asked.distance(*at) > REACH,
        _ => true,
    }
}

/// Leading someone somewhere (topside life.md "Going with someone"; the
/// escort in Skyrim's AI packages): the leader waits for them once they
/// fall further behind than this, in metres (operator, 2026-10-02)...
pub const LEAD_WAIT: f32 = 8.0;
/// ...and goes on once they are this near again.
pub const LEAD_NEAR: f32 = 5.0;
/// A lead is done once both are this near the spot, in metres (operator,
/// 2026-10-02); the leader there, the one led comes to the spot itself, not
/// to the leader.
pub const LEAD_DONE: f32 = 2.0;

/// Whether a leader at `leader` has brought the one they lead at
/// `follower` to `to`.
pub fn led_there(leader: Vec3, follower: Vec3, to: Vec3) -> bool {
    leader.distance(to) <= LEAD_DONE && follower.distance(to) <= LEAD_DONE
}

/// Following someone (World of Warcraft's auto-follow): the follower
/// closes in while further off than this, in metres, and stands once this
/// near.
pub const FOLLOW_NEAR: f32 = 2.5;

/// Whether a follower at `follower` walks on after the one they follow at
/// `leader`.
pub fn follows(follower: Vec3, leader: Vec3) -> bool {
    follower.distance(leader) > FOLLOW_NEAR
}

/// Whether a leader at `leader` waits for the one they lead at
/// `follower`, `waiting` already or not.
pub fn waits_for(leader: Vec3, follower: Vec3, waiting: bool) -> bool {
    let apart = leader.distance(follower);
    if waiting { apart > LEAD_NEAR } else { apart > LEAD_WAIT }
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

/// How near a person comes to hit, before their personality's range.
pub const MELEE_REACH: f32 = 1.8;

fn reach_of(p: &Perception) -> f32 {
    MELEE_REACH * p.personality.range_mult()
}

/// Face a point from `from`: aim at it on the ground (topside combat.md: a
/// person faces what they aim at, seen from above).
pub fn turn_toward(from: Vec3, to: Vec3) -> Vec<Action> {
    if (to - from).with_y(0.0).length() < 1e-4 {
        return vec![];
    }
    vec![Action::Aim { x: to.x, y: to.z }]
}

/// Go to a point from `from` by the way there, unless already there: in
/// reach of it, its height included (topside: everything is 3D; the
/// consumer's navigation mesh finds and walks the way).
pub fn walk_toward(from: Vec3, to: Vec3) -> Vec<Action> {
    if (to - from).length() <= REACH {
        return vec![];
    }
    vec![Action::Go { x: to.x, y: to.y, z: to.z }]
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
            reachable: &Vec::new,
            unknown: &|_| true,
            asked: None,
            trader: None,
        }
    }

    #[test]
    fn short_of_a_need_with_a_trader_in_sight_they_go_and_trade() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let trader = (ActorId(7), Vec3::new(4.0, 0.0, 0.0), Need::Thirst);
        p.trader = Some(trader);
        let mut roll = Roll::new(1);
        let mut t = Think::new(&p, &mut roll);
        assert_eq!(enter_trade(&mut t, &Target::None), None, "not thirsty enough: no trade");
        p.needs.thirst = NEED_LINE - 1.0;
        let mut t = Think::new(&p, &mut roll);
        let target = enter_trade(&mut t, &Target::None).expect("thirsty, a trader in sight");
        assert_eq!(target, Target::Trader { who: ActorId(7), at: trader.1, need: Need::Thirst });
        assert_eq!(going(&mut t, &target), Status::Running, "4 m off: walking there");
        assert_eq!(trade_with(&mut t, &target), Status::Succeeded);
        assert_eq!(t.do_now, Some(Do::Trade { with: ActorId(7), need: Need::Thirst }));
    }

    /// Asked to be somewhere: they head there; asked somewhere else, or no
    /// longer asked, they choose again.
    #[test]
    fn asked_to_a_place_they_go_there_until_no_longer_asked() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let tap = Vec3::new(40.0, 0.0, 10.0);
        let mut roll = Roll::new(1);
        assert_eq!(enter_asked(&mut Think::new(&p, &mut roll), &Target::None), None, "not asked");
        p.asked = Some(tap);
        let target = enter_asked(&mut Think::new(&p, &mut roll), &Target::None).expect("asked");
        assert_eq!(target, Target::Point(tap));
        let mut t = Think::new(&p, &mut roll);
        assert_eq!(going(&mut t, &target), Status::Running);
        assert!(t.actions.contains(&Action::Go { x: 40.0, y: 0.0, z: 10.0 }), "going there: {:?}", t.actions);
        assert!(!not_asked(&mut Think::new(&p, &mut roll), &target));
        p.asked = Some(Vec3::new(-40.0, 0.0, 0.0));
        assert!(not_asked(&mut Think::new(&p, &mut roll), &target), "asked elsewhere");
        p.asked = None;
        assert!(not_asked(&mut Think::new(&p, &mut roll), &target), "no longer asked");
    }

    /// A need below NEED_CRITICAL that they can answer outranks being asked
    /// (topside: Mara waited at the tap and did not drink at thirst 0); one
    /// they can do nothing about, or one not yet critical, does not.
    #[test]
    fn a_critical_need_they_can_answer_outranks_being_asked() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let mut roll = Roll::new(1);
        p.asked = Some(Vec3::new(40.0, 0.0, 10.0));
        p.needs.thirst = NEED_CRITICAL - 10.0;
        p.carries_drink = true;
        assert!(critical_need(&mut Think::new(&p, &mut roll), &Target::None), "thirst {} carrying drink", p.needs.thirst);
        // Offered eating what they carry and what was asked: what was asked
        // is not offered while the need is critical.
        let offered = [Choice::EatCarried, Choice::Asked];
        assert_eq!(learned(&mut Think::new(&p, &mut roll), &offered), 0, "critical: the need first");
        p.carries_drink = false;
        assert!(!critical_need(&mut Think::new(&p, &mut roll), &Target::None), "nothing to answer it with: they stay asked");
        p.carries_drink = true;
        p.needs.thirst = NEED_CRITICAL + 10.0;
        assert!(!critical_need(&mut Think::new(&p, &mut roll), &Target::None), "not critical yet");
    }

    /// A stroll and a trip out only pick a spot someone can stand on;
    /// with none standable, the person stays.
    #[test]
    fn going_somewhere_right_above_is_not_being_there() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        p.position = Vec3::new(0.0, -6.0, 0.0);
        let mut roll = Roll::new(1);
        let mut t = Think::new(&p, &mut roll);
        let up = Target::Point(Vec3::new(0.5, 0.0, 0.5));
        assert_eq!(going(&mut t, &up), Status::Running, "two levels up: still going");
        assert_eq!(going(&mut t, &Target::Point(Vec3::new(0.5, -6.0, 0.5))), Status::Succeeded, "on their level, near: there");
    }

    #[test]
    fn a_lead_waits_past_8_m_and_is_done_once_both_are_at_the_spot() {
        let spot = Vec3::new(0.0, 0.0, 20.0);
        assert!(!waits_for(Vec3::ZERO, Vec3::new(0.0, 0.0, -7.9), false), "7.9 m behind: walk on");
        assert!(waits_for(Vec3::ZERO, Vec3::new(0.0, 0.0, -8.1), false), "8.1 m behind: wait");
        assert!(!led_there(Vec3::new(0.0, 0.0, 19.0), Vec3::new(0.0, 0.0, 16.5), spot), "the leader there, the one led not yet");
        assert!(led_there(Vec3::new(0.0, 0.0, 19.0), Vec3::new(1.0, 0.0, 19.0), spot), "both within 2 m: done");
        assert!(!led_there(Vec3::new(0.0, -3.0, 20.0), Vec3::new(0.0, -3.0, 20.0), spot), "a level below: not there");
    }

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

    /// A stroll goes only to a spot they can reach, within the home radius,
    /// and off their map when one is (topside todo 11ag); with every spot
    /// on their map, any reachable one; with none, they stand.
    #[test]
    fn a_stroll_goes_somewhere_reachable_and_unknown() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let radius = p.behaviour.home_radius();
        let spots = move || {
            vec![
                Vec3::new(5.0, 0.0, 0.0),
                Vec3::new(-5.0, 0.0, 0.0),
                Vec3::new(0.0, 0.0, 6.0),
                Vec3::new(radius + 10.0, 0.0, 0.0),
            ]
        };
        p.reachable = &spots;
        let west = |at: Vec3| at.x < 0.0;
        p.unknown = &west;
        let mut strolled = 0;
        for seed in 0..200 {
            let mut roll = Roll::new(seed);
            let mut t = Think::new(&p, &mut roll);
            if let Some(Target::Point(to)) = enter_wander(&mut t, &Target::None) {
                strolled += 1;
                assert_eq!(to, Vec3::new(-5.0, 0.0, 0.0), "seed {seed}: the one reachable spot off their map");
            }
        }
        assert!(strolled > 0, "some thinks stroll");
        // Everything reachable already seen: any reachable spot in reach.
        p.unknown = &|_| false;
        for seed in 0..200 {
            let mut roll = Roll::new(seed);
            let mut t = Think::new(&p, &mut roll);
            if let Some(Target::Point(to)) = enter_wander(&mut t, &Target::None) {
                assert!(to.distance(Vec3::ZERO) <= radius, "seed {seed}: {to} past the home radius");
            }
        }
    }

    /// Asleep at camp with thirst falling past the look line below their
    /// rest: the thirst comes first (seen in the running game, topside
    /// tests/thirst.rs); a need still above the line does not wake them.
    #[test]
    fn a_worse_need_takes_them_off_the_one_they_serve() {
        let memory = Memory::default();
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let sleeping = Target::Thing { key: 1, at: Vec3::ZERO, need: Some(Need::Rest) };
        p.needs.rest = 40.0;
        p.needs.thirst = 20.0;
        let mut roll = Roll::new(1);
        let mut t = Think::new(&p, &mut roll);
        assert!(worse_need(&mut t, &sleeping), "thirst 20 under rest 40: drink first");
        p.needs.thirst = 35.0;
        let mut t = Think::new(&p, &mut roll);
        assert!(!worse_need(&mut t, &sleeping), "thirst 35 is not past the look line");
        p.needs.thirst = 20.0;
        p.needs.rest = 10.0;
        let mut t = Think::new(&p, &mut roll);
        assert!(!worse_need(&mut t, &sleeping), "rest is still the worst");
        // Walking there, a sleeper wakes.
        p.asleep = true;
        let mut t = Think::new(&p, &mut roll);
        going(&mut t, &Target::Point(Vec3::new(10.0, 0.0, 0.0)));
        assert_eq!(t.do_now, Some(Do::Wake));
    }

    /// Seen in the running game (topside tests/thirst.rs): people worn out
    /// with no home, thirst at 11, walking past the wells they knew. Rest
    /// was their worst need and nothing answered it; the thirst below it
    /// must still send them to the well.
    #[test]
    fn a_need_nothing_answers_does_not_hide_the_next() {
        let mut memory = Memory::default();
        memory.see(7, "well", Vec3::new(10.0, 0.0, 0.0), 0);
        let personality = Personality::default();
        let mut p = perception(&memory, &personality);
        let well = |k: &crate::memory::Known, n: Need| if k.kind == "well" && n == Need::Thirst { 50.0 } else { 0.0 };
        p.worth = &well;
        p.home = None;
        p.at_home = false;
        p.needs.rest = 5.0;
        p.needs.thirst = 11.0;
        let mut roll = Roll::new(1);
        let mut t = Think::new(&p, &mut roll);
        assert_eq!(
            enter_need(&mut t, &Target::None),
            Some(Target::Thing { key: 7, at: Vec3::new(10.0, 0.0, 0.0), need: Some(Need::Thirst) }),
            "worn out with nowhere to sleep, they still go to the well"
        );
        // Nothing known for either: nothing to go to.
        p.worth = &|_, _| 0.0;
        let mut t = Think::new(&p, &mut roll);
        assert_eq!(enter_need(&mut t, &Target::None), None);
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

    #[test]
    fn a_leader_waits_when_left_behind_and_goes_on_when_caught_up() {
        let dell = Vec3::ZERO;
        let at = |m: f32| Vec3::new(m, 0.0, 0.0);
        assert!(!waits_for(dell, at(8.0), false), "close enough: go on");
        assert!(waits_for(dell, at(13.0), false), "left behind: wait");
        assert!(waits_for(dell, at(8.0), true), "waiting, not near enough yet");
        assert!(!waits_for(dell, at(4.0), true), "caught up: go on");
    }

    #[test]
    fn a_follower_closes_in_and_stands_when_near() {
        let dell = Vec3::ZERO;
        assert!(follows(Vec3::new(6.0, 0.0, 0.0), dell));
        assert!(!follows(Vec3::new(2.0, 0.0, 0.0), dell));
    }
}
