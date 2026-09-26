//! The brain (topside life.md "The brain"): one pure function that
//! turns what a person perceives into what it does next. No engine,
//! no entities: a `Perception` in, a `Decision` out, the state it
//! keeps between thinks (`Activity`, `CombatState`) owned by the
//! consumer and handed back each time. Every random choice comes
//! from a `Roll` the consumer seeds by tick and ActorId, so a replay
//! decides the same.
//!
//! Prior art: Endless's decision system (the ordered hard rules,
//! activity kept through a fight), The Sims' needs (the worst need
//! drives the pick; what is known, not what exists, is considered),
//! Halo 2's lesson that the brain never reads the world directly.

use glam::Vec3;

use crate::actions::Action;
use crate::actor::{ActorId, Behaviour, Personality};
use crate::memory::{Known, Memory};
use crate::monument::Roll;
use crate::learn::{Band, Choice, Situation};
use crate::survival::{Need, SurvivalStats};

/// What a person is doing, kept between thinks.
#[derive(Clone, Debug, PartialEq)]
pub enum Activity {
    Idle,
    /// Walking to a known thing to satisfy a need.
    Going {
        key: u64,
        to: Vec3,
        need: Need,
    },
    /// At a known thing, doing it.
    Doing {
        key: u64,
        what: Doing,
    },
    /// Walking to a known but unchecked thing to see what it holds.
    Looking {
        key: u64,
        to: Vec3,
    },
    /// Strolling to a point near home.
    Wander {
        to: Vec3,
    },
    /// Walking home.
    GoHome,
    /// Walking to a known box to take what their bunker is short of.
    Fetching {
        key: u64,
        to: Vec3,
        need: Need,
    },
    /// Carrying food and water home to their bunker's store.
    Hauling {
        key: u64,
        to: Vec3,
    },
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Doing {
    Eat,
    Sleep,
    Check,
    /// Taking what they and their bunker need out of a box.
    Take(Need),
    /// Putting what they carried home into the store.
    Stock,
}

/// Whether a person is fighting, kept between thinks and kept apart
/// from the activity so an errand resumes after a fight (Endless).
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum CombatState {
    None,
    Fighting { target: ActorId, began_at: Vec3 },
    Fleeing { from: ActorId },
}

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
    /// Within reach of the current activity's target.
    pub arrived: bool,
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
            .field("arrived", &self.arrived)
            .finish_non_exhaustive()
    }
}

/// The one thing the consumer must carry out this tick with its own
/// data, because the brain cannot touch the world.
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Do {
    /// Take food from the known thing `key` and eat it.
    Eat {
        key: u64,
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

#[derive(Clone, Debug, PartialEq)]
pub struct Decision {
    pub activity: Activity,
    pub combat: CombatState,
    pub actions: Vec<Action>,
    pub do_now: Option<Do>,
}

/// How far a person chases before breaking off back home.
pub const LEASH: f32 = 60.0;
/// A need below this sends a person to something it knows.
pub const NEED_LINE: f32 = 50.0;
/// A need below this, with nothing known to answer it, sends a person
/// looking.
pub const LOOK_LINE: f32 = 30.0;
/// Within this of a target counts as there.
pub const REACH: f32 = 1.5;
/// Metres of walking that cost one point of satisfaction.
const METRES_PER_POINT: f32 = 4.0;

/// The brain. The first rule that applies wins.
pub fn decide(
    p: &Perception,
    activity: &Activity,
    combat: &CombatState,
    roll: &mut Roll,
) -> Decision {
    choose(p, activity, combat, roll).0
}

/// The one way a person decides (topside life.md "Learning to stay
/// alive"): every rule that fits the moment offers its choice, in the
/// order of instinct (the storm, finishing what they reached, fleeing,
/// breaking off, fighting, eating what they carry, carrying on, going to
/// what answers a need, supplying their bunker, looking, wandering), and
/// what they learned picks among them; with nothing learned, instinct's
/// order decides. Returns the decision, the situation it was made in, and
/// the choice, for the consumer to note in their memory.
pub fn choose(p: &Perception, activity: &Activity, combat: &CombatState, roll: &mut Roll) -> (Decision, Situation, Choice) {
    let mut offered: Vec<(Choice, Decision)> = Vec::new();
    let mut offer = |choice, d: Option<Decision>| {
        if let Some(d) = d {
            offered.push((choice, d));
        }
    };
    offer(Choice::Hide, hide(p));
    offer(Choice::CarryOn, arrived(p, activity, combat));
    offer(Choice::Flee, flee(p, activity, combat));
    offer(Choice::BreakOff, leash(p, activity, combat));
    offer(Choice::Fight, fight(p, activity, combat));
    // Out of a fight: the life.
    let calm = CombatState::None;
    offer(Choice::EatCarried, eat_carried(p, activity));
    offer(Choice::CarryOn, keep_going(p, activity, calm));
    offer(Choice::GoToNeed, life(p, calm));
    offer(Choice::Supply, supply(p, activity, calm, roll));
    offer(Choice::Look, look(p, activity, calm, roll));
    offer(Choice::Wander, Some(wander(p, activity, calm, roll)));
    let situation = situation(p);
    let choices: Vec<Choice> = offered.iter().map(|(c, _)| *c).collect();
    let (choice, decision) = offered.swap_remove(p.memory.learned.pick(&situation, &choices));
    (decision, situation, choice)
}

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

/// Rule 0: the storm is coming: hide or die, before anything else (the
/// player obeys the same storm). Home is the shelter a person knows;
/// at home they stay put. With no home there is nowhere to go.
fn hide(p: &Perception) -> Option<Decision> {
    if !p.storm_coming {
        return None;
    }
    let home = p.home?;
    Some(Decision {
        activity: Activity::GoHome,
        combat: CombatState::None,
        actions: if p.at_home { vec![] } else { walk_toward(p, home) },
        do_now: None,
    })
}

/// Hungry or thirsty with the answer in their own bags: eat or drink
/// it where they stand, the way the player does, and carry on with
/// what they were doing.
fn eat_carried(p: &Perception, activity: &Activity) -> Option<Decision> {
    let need = if p.needs.hunger < NEED_LINE && p.carries_food {
        Need::Hunger
    } else if p.needs.thirst < NEED_LINE && p.carries_drink {
        Need::Thirst
    } else {
        return None;
    };
    Some(Decision {
        activity: activity.clone(),
        combat: CombatState::None,
        actions: vec![],
        do_now: Some(Do::EatCarried { need }),
    })
}

/// Rule 1: at the target, start doing; done doing, stop.
fn arrived(p: &Perception, activity: &Activity, combat: &CombatState) -> Option<Decision> {
    match activity {
        Activity::Going { key, need, .. } if p.arrived => {
            let (what, do_now) = match need {
                Need::Hunger | Need::Thirst => (Doing::Eat, Some(Do::Eat { key: *key })),
                Need::Rest => (Doing::Sleep, Some(Do::Sleep)),
                Need::Safety => (Doing::Check, None),
            };
            Some(Decision {
                activity: Activity::Doing { key: *key, what },
                combat: *combat,
                actions: vec![],
                do_now,
            })
        }
        Activity::Fetching { key, need, .. } if p.arrived => Some(Decision {
            activity: Activity::Doing {
                key: *key,
                what: Doing::Take(*need),
            },
            combat: *combat,
            actions: vec![],
            do_now: Some(Do::Take { key: *key }),
        }),
        Activity::Hauling { key, .. } if p.arrived => Some(Decision {
            activity: Activity::Doing {
                key: *key,
                what: Doing::Stock,
            },
            combat: *combat,
            actions: vec![],
            do_now: Some(Do::Stock { key: *key }),
        }),
        Activity::Looking { key, .. } if p.arrived => Some(Decision {
            activity: Activity::Doing {
                key: *key,
                what: Doing::Check,
            },
            combat: *combat,
            actions: vec![],
            do_now: Some(Do::Check { key: *key }),
        }),
        Activity::Doing { key, what } => {
            // Keep eating while hungry and the thing still feeds; keep
            // sleeping until rested; a check is one look.
            let done = match what {
                Doing::Eat => {
                    let fed = p.needs.hunger >= 90.0 && p.needs.thirst >= 90.0;
                    let empty = !p
                        .memory
                        .known
                        .iter()
                        .any(|k| k.key == *key && k.believed_to_hold());
                    fed || empty
                }
                Doing::Sleep => p.needs.rest >= 95.0 || p.hostile.is_some(),
                Doing::Check => true,
                // Needed, so as much as they can carry: until the bags
                // are full or nothing in the box answers the need.
                Doing::Take(need) => {
                    let nothing_left = !p
                        .memory
                        .known
                        .iter()
                        .any(|k| k.key == *key && k.believed_to_hold() && (k.held.is_none() || (p.worth)(k, *need) > 0.0));
                    p.bags_full || nothing_left
                }
                Doing::Stock => !p.carries_for_bunker,
            };
            if !done {
                let do_now = match what {
                    Doing::Eat => Some(Do::Eat { key: *key }),
                    Doing::Take(_) => Some(Do::Take { key: *key }),
                    Doing::Stock => Some(Do::Stock { key: *key }),
                    _ => None,
                };
                return Some(Decision {
                    activity: activity.clone(),
                    combat: *combat,
                    actions: vec![],
                    do_now,
                });
            }
            Some(Decision {
                activity: Activity::Idle,
                combat: *combat,
                actions: vec![],
                do_now: (*what == Doing::Sleep).then_some(Do::Wake),
            })
        }
        Activity::GoHome if p.at_home || p.home.is_none() => Some(Decision {
            activity: Activity::Idle,
            combat: CombatState::None,
            actions: vec![],
            do_now: None,
        }),
        Activity::Wander { .. } if p.arrived => Some(Decision {
            activity: Activity::Idle,
            combat: *combat,
            actions: vec![],
            do_now: None,
        }),
        _ => None,
    }
}

/// How far someone with no home runs from a threat, metres.
pub const FLEE_FAR: f32 = 20.0;

/// Rule 2: hurt past the flee line, run home; with no home, run away
/// from the threat. A person with no home is never going home: that
/// never ends.
fn flee(p: &Perception, _activity: &Activity, combat: &CombatState) -> Option<Decision> {
    let from = match combat {
        CombatState::Fighting { target, .. } => *target,
        CombatState::Fleeing { from } => *from,
        CombatState::None => return None,
    };
    if p.health_fraction >= p.personality.flee_line() {
        // A fleeing person who is safe again stops fleeing.
        if matches!(combat, CombatState::Fleeing { .. }) && p.hostile.is_none() {
            return Some(Decision {
                activity: if p.home.is_some() { Activity::GoHome } else { Activity::Idle },
                combat: CombatState::None,
                actions: vec![],
                do_now: None,
            });
        }
        return None;
    }
    let (activity, to) = match p.home {
        Some(home) => (Activity::GoHome, home),
        None => {
            let away = p.hostile.map_or(p.position, |(_, at)| {
                p.position + (p.position - at).with_y(0.0).normalize_or_zero() * FLEE_FAR
            });
            (Activity::Wander { to: away }, away)
        }
    };
    Some(Decision {
        activity,
        combat: CombatState::Fleeing { from },
        actions: walk_toward(p, to),
        do_now: None,
    })
}

/// Rule 3: chased too far from where the fight began, break off: home,
/// or with no home back to where the fight began.
fn leash(p: &Perception, _activity: &Activity, combat: &CombatState) -> Option<Decision> {
    let CombatState::Fighting { began_at, .. } = combat else {
        return None;
    };
    if p.position.distance(*began_at) <= LEASH {
        return None;
    }
    let (activity, to) = match p.home {
        Some(home) => (Activity::GoHome, home),
        None => (Activity::Wander { to: *began_at }, *began_at),
    };
    Some(Decision {
        activity,
        combat: CombatState::None,
        actions: walk_toward(p, to),
        do_now: None,
    })
}

/// Rule 4: a hostile in sight: face it, close on it (hunters), hit
/// it in reach. The activity is kept underneath (Endless).
fn fight(p: &Perception, activity: &Activity, combat: &CombatState) -> Option<Decision> {
    let Some((who, at)) = p.hostile else {
        return remembered_threat(p, activity, combat);
    };
    let began_at = match combat {
        CombatState::Fighting { began_at, .. } => *began_at,
        _ => p.position,
    };
    let mut actions = turn_toward(p, at);
    let distance = p.position.distance(at);
    if distance <= reach_of(p) {
        actions.push(Action::Attack);
    } else if p.behaviour == Behaviour::Hunter {
        actions.push(step_toward(p, at));
    }
    Some(Decision {
        activity: activity.clone(),
        combat: CombatState::Fighting {
            target: who,
            began_at,
        },
        actions,
        do_now: (p.asleep).then_some(Do::Wake),
    })
}

/// How quickly a person reacts, by what they are doing (topside life.md
/// "How often a person thinks"), in seconds.
pub const COMBAT_REACTION: f32 = 0.25;
pub const AWAKE_REACTION: f32 = 1.0;
pub const ASLEEP_REACTION: f32 = 10.0;
/// The most tiredness slows a person: half as slow again with no rest.
pub const TIRED_SLOWEST: f32 = 1.5;

/// Ticks (at `ticks_per_sec`) until this person next decides: their
/// reaction time for what they are doing (asleep, fighting or fleeing,
/// or otherwise awake), slower the more tired they are, quicker or
/// slower by personality the way it sets their swing. Being hit does
/// not shorten it: a person under fire is at the combat rate.
pub fn reaction_ticks(asleep: bool, combat: &CombatState, rest: f32, personality: &Personality, ticks_per_sec: f32) -> u64 {
    let base = if asleep {
        ASLEEP_REACTION
    } else if matches!(combat, CombatState::None) {
        AWAKE_REACTION
    } else {
        COMBAT_REACTION
    };
    let tired = 1.0 + (TIRED_SLOWEST - 1.0) * (1.0 - rest / crate::survival::FULL).clamp(0.0, 1.0);
    let quickness = personality.swing_delay(1.0);
    ((base * tired * quickness * ticks_per_sec).round() as u64).max(1)
}

/// How long a threat out of sight still drives a fight, in ticks (5 s).
pub const THREAT_RECENT: u64 = 300;

/// Rule 4, second branch (topside life.md "Perception with belief"):
/// nothing hostile in sight, but a threat remembered in the last few
/// seconds (seen, or the one who just hit me): a hunter goes to where it
/// was, a guard turns to face it. Belief, not truth: the spot is where
/// it was, not where it is.
fn remembered_threat(p: &Perception, activity: &Activity, combat: &CombatState) -> Option<Decision> {
    let (who, at, when) = p.memory.last_threat?;
    if p.now.saturating_sub(when) > THREAT_RECENT {
        return None;
    }
    let began_at = match combat {
        CombatState::Fighting { began_at, .. } => *began_at,
        _ => p.position,
    };
    let actions = if p.behaviour == Behaviour::Hunter {
        walk_toward(p, at)
    } else {
        turn_toward(p, at)
    };
    Some(Decision {
        activity: activity.clone(),
        combat: CombatState::Fighting {
            target: who,
            began_at,
        },
        actions,
        do_now: (p.asleep).then_some(Do::Wake),
    })
}

/// Rule 5: an errand under way keeps going.
fn keep_going(p: &Perception, activity: &Activity, combat: CombatState) -> Option<Decision> {
    // A stroll or a trip out to look is not an errand: anything the
    // person comes to know on the way may take over (the rules below);
    // with nothing better, `wander` and `head_out` keep it going.
    let to = match activity {
        Activity::Going { to, .. }
        | Activity::Looking { to, .. }
        | Activity::Fetching { to, .. }
        | Activity::Hauling { to, .. } => *to,
        Activity::GoHome => p.home?,
        _ => return None,
    };
    Some(Decision {
        activity: activity.clone(),
        combat,
        actions: walk_toward(p, to),
        do_now: None,
    })
}

/// Rule 6b, the bunker's needs (topside design.md "Taking loot"): with
/// no need of their own pressing, a bunker person carrying food or water
/// home takes it to the store when the bunker is no longer short, the
/// bags are full, or there is nowhere left to look; while the bunker is
/// short they go to the best box they know holds what it needs, or look
/// inside one they have not opened.
fn supply(p: &Perception, activity: &Activity, combat: CombatState, roll: &mut Roll) -> Option<Decision> {
    let (store, store_at) = p.store?;
    // The best known box for any need the bunker is short of: a box seen
    // holding something, since only what is inside can be carried home (a
    // well is drunk from where it stands).
    let best = p
        .bunker_short
        .iter()
        .filter(|_| !p.bags_full)
        .flat_map(|&need| {
            p.memory
                .good_for(need, p.worth)
                .filter(move |(k, _)| k.key != store && k.held.is_some())
                .map(move |(k, gives)| (k, need, gives - k.position.distance(p.position) / METRES_PER_POINT))
        })
        .max_by(|a, b| a.2.total_cmp(&b.2))
        .map(|(k, need, _)| (k, need));
    let short = !p.bunker_short.is_empty();
    let unopened = || {
        p.memory
            .known
            .iter()
            .filter(|k| k.checked_at.is_none() && k.key != store)
            .min_by(|a, b| a.position.distance(p.position).total_cmp(&b.position.distance(p.position)))
    };
    let go = |activity: Activity, to: Vec3| {
        Some(Decision {
            activity,
            combat,
            actions: walk_toward(p, to),
            do_now: None,
        })
    };
    let nowhere_to_look = best.is_none() && unopened().is_none();
    if p.carries_for_bunker && (!short || p.bags_full || nowhere_to_look) {
        return go(Activity::Hauling { key: store, to: store_at }, store_at);
    }
    if p.bags_full {
        return None;
    }
    if let Some((known, need)) = best {
        return go(
            Activity::Fetching {
                key: known.key,
                to: known.position,
                need,
            },
            known.position,
        );
    }
    if !short {
        return None;
    }
    match unopened() {
        Some(known) => go(
            Activity::Looking {
                key: known.key,
                to: known.position,
            },
            known.position,
        ),
        None => Some(head_out(p, activity, combat, roll)),
    }
}

/// How far a person heads out to look when nothing they know answers a
/// need: something worth stopping for stands within this of almost
/// anywhere (topside design.md "The world", Bethesda's rule).
pub const LOOK_FAR: f32 = 150.0;

/// Nothing known answers the need: head out to find out, `LOOK_FAR` from
/// home (or from here, with no home) a rolled way, looking round on the
/// way. What is seen goes into memory and the rules that use memory take
/// over. Arriving with nothing found, the next think rolls another way.
fn head_out(p: &Perception, activity: &Activity, combat: CombatState, roll: &mut Roll) -> Decision {
    // Already on the way out: keep going the same way. Otherwise a spot
    // someone can stand on, or stay put this think.
    let to = match activity {
        Activity::Wander { to } if !p.arrived => Some(*to),
        _ => {
            let centre = p.home.unwrap_or(p.position);
            standable_spot(p, roll, |roll| {
                let angle = roll.measure(0.0, std::f32::consts::TAU);
                centre + Vec3::new(angle.cos() * LOOK_FAR, 0.0, angle.sin() * LOOK_FAR)
            })
        }
    };
    let Some(to) = to else {
        return Decision {
            activity: Activity::Idle,
            combat,
            actions: vec![],
            do_now: None,
        };
    };
    Decision {
        activity: Activity::Wander { to },
        combat,
        actions: walk_toward(p, to),
        do_now: None,
    }
}

/// Rule 6: the worst need, when it presses, picks the best known
/// thing: what it gives minus the walk, the walk costing a Lazy
/// person more, plus a little seeded chance (inside `Roll`, the
/// consumer seeds it) so two people in one spot differ.
fn life(p: &Perception, combat: CombatState) -> Option<Decision> {
    let (need, value) = p.needs.worst_need();
    if value >= NEED_LINE {
        return None;
    }
    let diligence = p.personality.get(crate::actor::Axis::Diligence);
    let walk_cost = 1.0 - 0.25 * diligence;
    let best = p
        .memory
        .good_for(need, p.worth)
        .map(|(known, gives)| {
            let distance = known.position.distance(p.position);
            let score = gives - distance / METRES_PER_POINT * walk_cost;
            (known, score)
        })
        .filter(|(_, score)| *score > 0.0)
        .max_by(|a, b| a.1.total_cmp(&b.1))?;
    let known = best.0;
    // Rest at home: sleep where you stand if this is home.
    if need == Need::Rest && p.at_home {
        return Some(Decision {
            activity: Activity::Doing {
                key: known.key,
                what: Doing::Sleep,
            },
            combat,
            actions: vec![],
            do_now: Some(Do::Sleep),
        });
    }
    Some(Decision {
        activity: Activity::Going {
            key: known.key,
            to: known.position,
            need,
        },
        combat,
        actions: walk_toward(p, known.position),
        do_now: None,
    })
}

/// Rule 7: nothing known answers a pressing need: go and look at
/// the nearest thing never checked, or with none, head out to find
/// out.
fn look(p: &Perception, activity: &Activity, combat: CombatState, roll: &mut Roll) -> Option<Decision> {
    let (need, value) = p.needs.worst_need();
    if value >= LOOK_LINE {
        return None;
    }
    let Some(known) = p.memory.unchecked_nearest(p.position) else {
        // Food and water are out there to be found; rest and safety are
        // not found by walking off.
        let findable = matches!(need, Need::Hunger | Need::Thirst);
        return findable.then(|| head_out(p, activity, combat, roll));
    };
    Some(Decision {
        activity: Activity::Looking {
            key: known.key,
            to: known.position,
        },
        combat,
        actions: walk_toward(p, known.position),
        do_now: None,
    })
}

/// Rule 8: nothing presses: stroll to a rolled point within the home
/// radius, or stand a while.
fn wander(p: &Perception, activity: &Activity, combat: CombatState, roll: &mut Roll) -> Decision {
    if !matches!(activity, Activity::Idle) {
        // Something else was under way and still is; keep it, still
        // walking if it was a stroll.
        let actions = match activity {
            Activity::Wander { to } => walk_toward(p, *to),
            _ => vec![],
        };
        return Decision {
            activity: activity.clone(),
            combat,
            actions,
            do_now: None,
        };
    }
    // Most thinks while idle do nothing; one in ten starts a stroll.
    if !roll.chance(100) {
        return Decision {
            activity: Activity::Idle,
            combat,
            actions: vec![],
            do_now: None,
        };
    }
    let centre = p.home.unwrap_or(p.position);
    let radius = p.behaviour.home_radius();
    // Only a spot someone can stand on; none in a few tries, stand a
    // while.
    let Some(to) = standable_spot(p, roll, |roll| {
        let angle = roll.measure(0.0, std::f32::consts::TAU);
        let distance = roll.measure(radius * 0.3, radius);
        centre + Vec3::new(angle.cos() * distance, 0.0, angle.sin() * distance)
    }) else {
        return Decision {
            activity: Activity::Idle,
            combat,
            actions: vec![],
            do_now: None,
        };
    };
    Decision {
        activity: Activity::Wander { to },
        combat,
        actions: walk_toward(p, to),
        do_now: None,
    }
}

/// How many spots are rolled looking for one a person can stand on.
const SPOT_TRIES: usize = 8;

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

    fn calm() -> Personality {
        Personality::default()
    }

    /// The registry's answer in these tests: a storage box is worth
    /// 50 for hunger, home 100 for rest, a wreck nothing.
    fn worth(known: &Known, need: Need) -> f32 {
        match (known.kind.as_str(), need) {
            ("storage box", Need::Hunger) => 50.0,
            ("home", Need::Rest) => 100.0,
            // A source: worth its water, seen inside or not.
            ("well", Need::Thirst) => 50.0,
            _ => 0.0,
        }
    }

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
            arrived: false,
            storm_coming: false,
            carries_food: false,
            carries_drink: false,
            store: None,
            bunker_short: Vec::new(),
            carries_for_bunker: false,
            bags_full: false,
            memory,
            personality,
            worth: &worth,
            standable: &|_| true,
        }
    }

    /// A stroll and a trip out only pick a spot someone can stand on;
    /// with none standable, the person stays.
    #[test]
    fn strolls_and_trips_out_only_pick_standable_spots() {
        let memory = Memory::default();
        let personality = calm();
        let mut p = perception(&memory, &personality);
        let east = |at: Vec3| at.x > 0.0;
        p.standable = &east;
        p.store = Some((1, Vec3::ZERO));
        p.bunker_short = vec![Need::Hunger];
        for seed in 0..40 {
            if let Activity::Wander { to } = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(seed)).activity {
                assert!(to.x > 0.0, "seed {seed}: headed for {to}, nobody can stand there");
            }
        }
        let nowhere = |_: Vec3| false;
        p.standable = &nowhere;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.activity, Activity::Idle, "nowhere standable: stays");
    }

    /// Nothing known to answer a need (theirs or their bunker's): they
    /// head out to find out, as far as something worth stopping for
    /// (150 m), a different way for different people.
    #[test]
    fn short_and_knowing_nothing_they_head_out_to_look() {
        let memory = Memory::default();
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.store = Some((1, Vec3::ZERO));
        p.bunker_short = vec![Need::Hunger];
        let to = |p: &Perception, roll: u64| match decide(p, &Activity::Idle, &CombatState::None, &mut Roll::new(roll)).activity {
            Activity::Wander { to } => to,
            other => panic!("expected to head out, got {other:?}"),
        };
        let a = to(&p, 1);
        assert!(a.distance(Vec3::ZERO) >= 100.0, "out past the home ground: {a}");
        assert_ne!(a, to(&p, 2), "different ways for different rolls");
        // Hungry themselves with nothing known: the same.
        p.store = None;
        p.bunker_short = vec![];
        p.needs.hunger = 20.0;
        assert!(to(&p, 3).distance(Vec3::ZERO) >= 100.0);
    }

    /// The bunker's needs (topside design.md "Taking loot"): short of
    /// food, a bunker person goes to the box it knows holds food, not
    /// the store; carrying food with the bunker covered, it hauls home;
    /// bags full, it hauls home even while the bunker is short.
    #[test]
    fn a_short_bunker_sends_its_people_for_food_and_they_haul_it_home() {
        let mut memory = Memory::default();
        memory.see(1, "storage box", Vec3::new(2.0, 0.0, 0.0), 1);
        memory.checked(1, vec![], 1);
        memory.see(7, "storage box", Vec3::new(40.0, 0.0, 0.0), 1);
        memory.checked(7, vec![("canned food".to_string(), 6)], 1);
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.store = Some((1, Vec3::new(2.0, 0.0, 0.0)));
        // Short of water too, with no water known: the food still sends it.
        p.bunker_short = vec![Need::Thirst, Need::Hunger];
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(
            matches!(d.activity, Activity::Fetching { key: 7, need: Need::Hunger, .. }),
            "to the box with food: {:?}",
            d.activity
        );
        // There: take.
        p.position = Vec3::new(40.0, 0.0, 0.0);
        p.arrived = true;
        let d = decide(&p, &d.activity, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.do_now, Some(Do::Take { key: 7 }));
        // Carrying it, the bunker covered: home to the store.
        p.arrived = false;
        p.carries_for_bunker = true;
        p.bunker_short = vec![];
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(matches!(d.activity, Activity::Hauling { key: 1, .. }), "{:?}", d.activity);
        // Still short but the bags are full: home too.
        p.bunker_short = vec![Need::Hunger];
        p.bags_full = true;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(matches!(d.activity, Activity::Hauling { key: 1, .. }), "{:?}", d.activity);
        // At the store: stock it until nothing is carried.
        p.position = Vec3::new(2.0, 0.0, 0.0);
        p.arrived = true;
        let d = decide(&p, &d.activity, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.do_now, Some(Do::Stock { key: 1 }));
        p.carries_for_bunker = false;
        let d = decide(&p, &d.activity, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.activity, Activity::Idle, "stocked");
    }

    /// Short of water and knowing only a well: nobody is sent to fetch
    /// from it, since a well cannot be carried home.
    #[test]
    fn a_short_bunker_does_not_fetch_from_a_well() {
        let mut memory = Memory::default();
        memory.see(1, "storage box", Vec3::new(2.0, 0.0, 0.0), 1);
        memory.checked(1, vec![], 1);
        memory.see(9, "well", Vec3::new(30.0, 0.0, 0.0), 1);
        memory.visited(9, 1);
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.store = Some((1, Vec3::new(2.0, 0.0, 0.0)));
        p.bunker_short = vec![Need::Thirst];
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(
            !matches!(d.activity, Activity::Fetching { key: 9, .. }),
            "not to the well: {:?}",
            d.activity
        );
    }

    /// Hungry with a can in the bag: eat it where they stand rather than
    /// walk to the box they know; not hungry, carry it.
    #[test]
    fn a_hungry_person_eats_what_it_carries_first() {
        let mut memory = Memory::default();
        memory.see(7, "storage box", Vec3::new(10.0, 0.0, 0.0), 1);
        memory.checked(7, vec![("canned food".to_string(), 1)], 1);
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.needs.hunger = 20.0;
        p.carries_food = true;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.do_now, Some(Do::EatCarried { need: Need::Hunger }));
        p.needs.hunger = 80.0;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_ne!(d.do_now, Some(Do::EatCarried { need: Need::Hunger }), "not hungry, it keeps it");
        p.needs.hunger = 20.0;
        p.carries_food = false;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(matches!(d.activity, Activity::Going { key: 7, .. }), "nothing carried: to the box");
    }

    #[test]
    fn reaction_time_follows_what_a_person_is_doing_and_how_tired() {
        let calm = calm();
        let fighting = CombatState::Fighting {
            target: ActorId(1),
            began_at: Vec3::ZERO,
        };
        let full = crate::survival::FULL;
        assert_eq!(reaction_ticks(false, &fighting, full, &calm, 60.0), 15, "combat, 250 ms");
        assert_eq!(reaction_ticks(false, &CombatState::None, full, &calm, 60.0), 60, "awake, 1 s");
        assert_eq!(reaction_ticks(true, &CombatState::None, full, &calm, 60.0), 600, "asleep, 10 s");
        assert_eq!(reaction_ticks(false, &CombatState::None, 0.0, &calm, 60.0), 90, "exhausted, half as slow again");
        let mut quick = calm;
        quick.axes[Axis::Agility as usize] = 1.0;
        assert!(reaction_ticks(false, &CombatState::None, full, &quick, 60.0) < 60, "an agile person is quicker");
    }

    #[test]
    fn a_hunter_goes_after_a_threat_it_remembers_and_forgets_it_later() {
        let mut memory = Memory::default();
        memory.threat(ActorId(7), Vec3::new(0.0, 0.0, 10.0), 90);
        let calm = calm();
        let p = perception(&memory, &calm);
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(matches!(d.combat, CombatState::Fighting { target: ActorId(7), .. }));
        assert!(d.actions.contains(&Action::Aim { x: 0.0, y: 10.0 }), "to where it was");
        let mut later = perception(&memory, &calm);
        later.now = 90 + THREAT_RECENT + 1;
        let d = decide(&later, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.combat, CombatState::None, "long gone");
    }

    #[test]
    fn a_coming_storm_sends_a_person_home_over_a_fight() {
        let memory = Memory::default();
        let calm = calm();
        let mut p = perception(&memory, &calm);
        p.home = Some(Vec3::new(0.0, 0.0, 30.0));
        p.at_home = false;
        p.hostile = Some((ActorId(4), Vec3::new(2.0, 0.0, 0.0)));
        p.storm_coming = true;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.activity, Activity::GoHome);
        assert_eq!(d.combat, CombatState::None, "no fighting in a storm");
        assert!(d.actions.contains(&Action::Aim { x: 0.0, y: 30.0 }), "heading home");
    }

    fn has_move(d: &Decision) -> bool {
        d.actions.iter().any(|a| matches!(a, Action::Move { .. }))
    }

    #[test]
    fn a_hunter_aims_at_what_it_hunts_and_steps_toward_it_on_the_ground() {
        let memory = Memory::default();
        let calm = calm();
        let mut p = perception(&memory, &calm);
        let at = Vec3::new(6.0, 0.0, 8.0);
        p.hostile = Some((ActorId(3), at));
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert!(d.actions.contains(&Action::Aim { x: 6.0, y: 8.0 }), "{:?}", d.actions);
        let step = d
            .actions
            .iter()
            .find_map(|a| match a {
                Action::Move { x, y } => Some((*x, *y)),
                _ => None,
            })
            .expect("closes in");
        assert!((step.0 - 0.6).abs() < 1e-4 && (step.1 - 0.8).abs() < 1e-4, "{step:?}");
    }

    #[test]
    fn a_wounded_coward_flees_home_and_a_brave_one_stands() {
        let memory = Memory::default();
        let mut coward = calm();
        coward.axes[Axis::Courage as usize] = -1.0;
        let mut p = perception(&memory, &coward);
        p.home = Some(Vec3::new(0.0, 0.0, 30.0));
        p.at_home = false;
        p.health_fraction = 0.4;
        p.hostile = Some((ActorId(9), Vec3::new(0.0, 0.0, -3.0)));
        let combat = CombatState::Fighting {
            target: ActorId(9),
            began_at: Vec3::ZERO,
        };
        let mut roll = Roll::new(1);
        let d = decide(&p, &Activity::Idle, &combat, &mut roll);
        assert_eq!(d.combat, CombatState::Fleeing { from: ActorId(9) });
        assert_eq!(d.activity, Activity::GoHome);
        assert!(has_move(&d), "runs");
        assert!(!d.actions.contains(&Action::Attack));

        let brave = {
            let mut b = calm();
            b.axes[Axis::Courage as usize] = 1.0;
            b
        };
        let p2 = Perception {
            personality: &brave,
            ..p.clone()
        };
        let d = decide(&p2, &Activity::Idle, &combat, &mut roll);
        assert!(
            matches!(d.combat, CombatState::Fighting { .. }),
            "the brave stand"
        );
    }

    /// Someone with no home never goes home, which never ends (a raider
    /// that fled once stood in a bunker for good, killing whoever woke
    /// there): wounded they run away from the threat, leashed they walk
    /// back to where the fight began, and a left-over GoHome ends.
    #[test]
    fn someone_with_no_home_runs_away_and_never_goes_home() {
        let memory = Memory::default();
        let mut coward = calm();
        coward.axes[Axis::Courage as usize] = -1.0;
        let mut p = perception(&memory, &coward);
        p.home = None;
        p.at_home = false;
        p.health_fraction = 0.4;
        p.hostile = Some((ActorId(9), Vec3::new(0.0, 0.0, -3.0)));
        let fight = CombatState::Fighting { target: ActorId(9), began_at: Vec3::ZERO };
        let d = decide(&p, &Activity::Idle, &fight, &mut Roll::new(1));
        assert_eq!(d.combat, CombatState::Fleeing { from: ActorId(9) });
        assert_eq!(d.activity, Activity::Wander { to: Vec3::new(0.0, 0.0, FLEE_FAR) }, "away from the threat");
        assert!(has_move(&d), "runs");

        let mut leashed = perception(&memory, &coward);
        leashed.home = None;
        leashed.position = Vec3::new(0.0, 0.0, -(LEASH + 5.0));
        leashed.hostile = Some((ActorId(9), Vec3::new(0.0, 0.0, -(LEASH + 8.0))));
        let d = decide(&leashed, &Activity::Idle, &fight, &mut Roll::new(1));
        assert_eq!(d.activity, Activity::Wander { to: Vec3::ZERO }, "back to where the fight began");

        let mut idle = perception(&memory, &coward);
        idle.home = None;
        let d = decide(&idle, &Activity::GoHome, &CombatState::None, &mut Roll::new(1));
        assert_ne!(d.activity, Activity::GoHome, "a GoHome with no home ends");
    }

    #[test]
    fn a_hunter_chased_past_its_leash_goes_home() {
        let memory = Memory::default();
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.position = Vec3::new(0.0, 0.0, -(LEASH + 5.0));
        p.at_home = false;
        p.hostile = Some((ActorId(9), Vec3::new(0.0, 0.0, -(LEASH + 8.0))));
        let combat = CombatState::Fighting {
            target: ActorId(9),
            began_at: Vec3::ZERO,
        };
        let d = decide(&p, &Activity::Idle, &combat, &mut Roll::new(1));
        assert_eq!(d.combat, CombatState::None);
        assert_eq!(d.activity, Activity::GoHome);
        assert!(has_move(&d));
    }

    #[test]
    fn a_hostile_in_sight_is_fought_and_the_errand_is_kept_underneath() {
        let memory = Memory::default();
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.hostile = Some((ActorId(9), Vec3::new(0.0, 0.0, -1.0)));
        let errand = Activity::Wander {
            to: Vec3::new(10.0, 0.0, 0.0),
        };
        let d = decide(&p, &errand, &CombatState::None, &mut Roll::new(1));
        assert!(d.actions.contains(&Action::Attack), "in reach: swing");
        assert_eq!(d.activity, errand, "the stroll waits");
        assert_eq!(
            d.combat,
            CombatState::Fighting {
                target: ActorId(9),
                began_at: Vec3::ZERO
            }
        );
        // A guard never chases, a hunter does.
        p.hostile = Some((ActorId(9), Vec3::new(0.0, 0.0, -10.0)));
        p.behaviour = Behaviour::Guard;
        let d = decide(&p, &errand, &CombatState::None, &mut Roll::new(1));
        assert!(!has_move(&d));
        p.behaviour = Behaviour::Hunter;
        let d = decide(&p, &errand, &CombatState::None, &mut Roll::new(1));
        assert!(has_move(&d));
    }

    #[test]
    fn a_hungry_person_goes_to_the_remembered_box_and_eats_until_fed() {
        let mut memory = Memory::default();
        memory.see(7, "storage box", Vec3::new(0.0, 0.0, -12.0), 1);
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.needs.hunger = 30.0;
        let mut roll = Roll::new(1);
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut roll);
        assert_eq!(
            d.activity,
            Activity::Going {
                key: 7,
                to: Vec3::new(0.0, 0.0, -12.0),
                need: Need::Hunger
            }
        );
        assert!(has_move(&d));
        // Arrived: eat.
        p.arrived = true;
        p.position = Vec3::new(0.0, 0.0, -11.0);
        let d = decide(&p, &d.activity, &CombatState::None, &mut roll);
        assert_eq!(d.do_now, Some(Do::Eat { key: 7 }));
        let eating = d.activity.clone();
        // Still hungry: eat again. Fed: done.
        let d = decide(&p, &eating, &CombatState::None, &mut roll);
        assert_eq!(d.do_now, Some(Do::Eat { key: 7 }));
        p.needs.hunger = 95.0;
        let d = decide(&p, &eating, &CombatState::None, &mut roll);
        assert_eq!(d.activity, Activity::Idle);
        assert_eq!(d.do_now, None);
    }

    #[test]
    fn an_empty_box_sends_a_hungry_person_looking_at_the_nearest_unchecked_thing() {
        let mut memory = Memory::default();
        memory.see(7, "storage box", Vec3::new(0.0, 0.0, -2.0), 1);
        memory.checked(7, vec![], 2);
        memory.see(8, "wreck", Vec3::new(40.0, 0.0, 0.0), 1);
        memory.see(9, "wreck", Vec3::new(-20.0, 0.0, 0.0), 1);
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.needs.hunger = 20.0;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_eq!(
            d.activity,
            Activity::Looking {
                key: 9,
                to: Vec3::new(-20.0, 0.0, 0.0)
            },
            "the nearer wreck"
        );
        // Arrived at it: check it.
        p.arrived = true;
        let d = decide(&p, &d.activity, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.do_now, Some(Do::Check { key: 9 }));
    }

    #[test]
    fn a_tired_person_at_home_sleeps_and_wakes_rested() {
        let mut memory = Memory::default();
        memory.see(1, "home", Vec3::ZERO, 1);
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.needs.rest = 20.0;
        let d = decide(&p, &Activity::Idle, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.do_now, Some(Do::Sleep));
        let sleeping = d.activity.clone();
        p.asleep = true;
        p.needs.rest = 60.0;
        let d = decide(&p, &sleeping, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.activity, sleeping, "still asleep");
        p.needs.rest = 96.0;
        let d = decide(&p, &sleeping, &CombatState::None, &mut Roll::new(1));
        assert_eq!(d.do_now, Some(Do::Wake));
        assert_eq!(d.activity, Activity::Idle);
    }

    #[test]
    fn idle_people_wander_within_their_home_radius_and_guards_stay_close() {
        let memory = Memory::default();
        let personality = calm();
        let mut p = perception(&memory, &personality);
        p.home = Some(Vec3::new(100.0, 0.0, 100.0));
        for behaviour in [Behaviour::Guard, Behaviour::Hunter] {
            p.behaviour = behaviour;
            let mut roll = Roll::new(3);
            let mut farthest: f32 = 0.0;
            let mut strolls = 0;
            for _ in 0..400 {
                let d = decide(&p, &Activity::Idle, &CombatState::None, &mut roll);
                if let Activity::Wander { to } = d.activity {
                    strolls += 1;
                    farthest = farthest.max(to.distance(p.home.unwrap()));
                    assert!(has_move(&d));
                }
            }
            assert!(
                strolls > 10 && strolls < 120,
                "{behaviour:?}: {strolls} strolls in 400"
            );
            assert!(
                farthest <= behaviour.home_radius() + 1e-3,
                "{behaviour:?}: {farthest}"
            );
            assert!(farthest > behaviour.home_radius() * 0.5);
        }
    }

    #[test]
    fn the_same_roll_decides_the_same() {
        let memory = Memory::default();
        let personality = calm();
        let p = perception(&memory, &personality);
        let a: Vec<Decision> = (0..50)
            .scan(Roll::new(9), |roll, _| {
                Some(decide(&p, &Activity::Idle, &CombatState::None, roll))
            })
            .collect();
        let b: Vec<Decision> = (0..50)
            .scan(Roll::new(9), |roll, _| {
                Some(decide(&p, &Activity::Idle, &CombatState::None, roll))
            })
            .collect();
        assert_eq!(a, b);
    }
}
