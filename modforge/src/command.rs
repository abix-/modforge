//! Commands and replays (topside authority.md "Commands and replays"): one
//! plain order a person carries out with the same actions their brain
//! pushes (`brain::walk_toward`, `turn_toward`), and a replay, the commands
//! given in a run with the tick each was given.
//!
//! Prior art: Minecraft's Baritone bot (`goto`, `follow`: an order carried
//! out through the normal movement) and StarCraft's replays (the player's
//! commands stored, not the mouse).

use glam::Vec3;
use serde::{Deserialize, Serialize};

use crate::actions::Action;
use crate::brain::{turn_toward, walk_toward, MELEE_REACH};

/// One order. `who` is a person (`W`: in the game a person's ActorId; in an
/// episode's data whom it names, resolved when given); a point (`P`: in the
/// game a `Point` in the world, its height included; in data what it names)
/// is where (topside: everything is 3D). The points are flattened, so a
/// command reads `{"do": "move_to", "x", "y", "z"}`.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
#[serde(tag = "do", rename_all = "snake_case")]
pub enum Command<W = u64, P = Point> {
    /// Go to the point by the way there.
    MoveTo {
        #[serde(flatten)]
        to: P,
    },
    /// Follow them, until a move of one's own or they are gone (the
    /// consumer's following does it).
    Follow { who: W },
    /// Lead them to the point, waiting when they fall behind, until both
    /// are there (`brain::led_there`; the consumer's leading does it). The
    /// one led follows by their own command or choice.
    Lead {
        who: W,
        #[serde(flatten)]
        to: P,
    },
    /// Walk to them, face them, and use, as E does, until talking with them.
    TalkTo { who: W },
    /// Walk to the closed door between one and them, on one's own side,
    /// and knock on it, once (the consumer finds the door: the closed one
    /// nearest them).
    Knock { who: W },
    /// Walk to them, face them, and attack in reach until they are dead.
    Attack { who: W },
    /// Attack the nearest living person one stands hostile to (the
    /// consumer names them, by the brain's one rule).
    AttackNearestEnemy,
    /// Hold the point: stay at it, warn off anyone one stands hostile to
    /// who comes for it, and fight them if they stay (topside todo 11z; the
    /// consumer's holding does it). It does not end on its own.
    Hold {
        #[serde(flatten)]
        at: P,
    },
}

/// A point in the world: x and z on the ground, y up.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Point {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}

impl From<Point> for Vec3 {
    fn from(p: Point) -> Self {
        Vec3::new(p.x, p.y, p.z)
    }
}

impl From<Vec3> for Point {
    fn from(v: Vec3) -> Self {
        Point { x: v.x, y: v.y, z: v.z }
    }
}

impl<W, P> Command<W, P> {
    /// The same order with whom and where it names worked out (`who`,
    /// `at`): the one map from an order in data to one given. None when
    /// either cannot be.
    pub fn resolve<W2, P2>(self, who: impl Fn(W) -> Option<W2>, at: impl Fn(P) -> Option<P2>) -> Option<Command<W2, P2>> {
        Some(match self {
            Command::MoveTo { to } => Command::MoveTo { to: at(to)? },
            Command::Follow { who: w } => Command::Follow { who: who(w)? },
            Command::Lead { who: w, to } => Command::Lead { who: who(w)?, to: at(to)? },
            Command::TalkTo { who: w } => Command::TalkTo { who: who(w)? },
            Command::Knock { who: w } => Command::Knock { who: who(w)? },
            Command::Attack { who: w } => Command::Attack { who: who(w)? },
            Command::AttackNearestEnemy => Command::AttackNearestEnemy,
            Command::Hold { at: p } => Command::Hold { at: at(p)? },
        })
    }
}

/// How near the spot beside a door a knocker stands to knock, in metres:
/// nearer than the brain's `REACH`, so they stand beside the doorway and
/// not in it.
pub const KNOCK_ARRIVE: f32 = 0.5;

/// What carrying out a command comes to this step.
#[derive(Clone, Debug, PartialEq)]
pub enum Step {
    /// Push these actions and carry on.
    Act(Vec<Action>),
    /// It is done: on to the next command.
    Done,
}

/// One step of a move to, talk to, or attack for someone at `here`.
/// `target` is the point, or where the one named stands (None: gone or
/// dead); `ended` is whether what it was for has happened (talking with
/// them); `seen` is whether the one named is looked at (nothing between).
/// Follow, lead and attack the nearest enemy are the consumer's to turn
/// into its following, its leading and an attack first; here they are done.
pub fn step(command: &Command, here: Vec3, target: Option<Vec3>, ended: bool, seen: bool, talk_reach: f32) -> Step {
    let Some(to) = target.filter(|_| !ended) else {
        return Step::Done;
    };
    let apart = (to - here).length();
    match command {
        Command::MoveTo { .. } => {
            let actions = walk_toward(here, to);
            if actions.is_empty() { Step::Done } else { Step::Act(actions) }
        }
        Command::TalkTo { .. } if apart > talk_reach => Step::Act(walk_toward(here, to)),
        // Near enough but not seen (a tree, a post between): closer, to the
        // brain's reach.
        Command::TalkTo { .. } if !seen && !walk_toward(here, to).is_empty() => Step::Act(walk_toward(here, to)),
        Command::TalkTo { .. } => {
            let mut actions = turn_toward(here, to);
            actions.push(Action::Use);
            Step::Act(actions)
        }
        // `to` is the spot beside the door; there (nearer than the brain's
        // reach, so the knocker stands clear of the doorway), the knock,
        // until it is knocked (`ended`).
        Command::Knock { .. } if apart > KNOCK_ARRIVE => Step::Act(vec![Action::Go { x: to.x, y: to.y, z: to.z }]),
        Command::Knock { .. } => Step::Act(vec![Action::Knock]),
        Command::Attack { .. } if apart > MELEE_REACH => Step::Act(walk_toward(here, to)),
        Command::Attack { .. } => {
            let mut actions = turn_toward(here, to);
            actions.push(Action::Attack);
            Step::Act(actions)
        }
        Command::Follow { .. } | Command::Lead { .. } | Command::Hold { .. } | Command::AttackNearestEnemy => Step::Done,
    }
}

/// A command as given: to whom, at which tick.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Given {
    pub tick: u64,
    pub who: u64,
    pub command: Command,
}

/// The commands given in a run, in order, and the world they were given
/// in. Played on the same world, it does the same things again.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Replay {
    pub seed: u64,
    pub given: Vec<Given>,
}

impl Replay {
    /// The commands moved so the first is given at `start`, each the same
    /// distance in ticks from the first as when it was given.
    pub fn from_tick(&self, start: u64) -> Vec<Given> {
        let first = self.given.first().map_or(0, |g| g.tick);
        self.given.iter().map(|g| Given { tick: start + (g.tick - first), ..*g }).collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    const TALK: f32 = 3.0;

    #[test]
    fn move_to_goes_there_and_is_done_there() {
        let command = Command::MoveTo { to: Point { x: 10.0, y: -6.0, z: 0.0 } };
        let to = Vec3::new(10.0, -6.0, 0.0);
        assert_eq!(step(&command, Vec3::ZERO, Some(to), false, true, TALK), Step::Act(vec![Action::Go { x: 10.0, y: -6.0, z: 0.0 }]));
        assert_eq!(step(&command, Vec3::new(9.5, -6.0, 0.0), Some(to), false, true, TALK), Step::Done);
        assert!(matches!(step(&command, Vec3::new(10.0, 0.0, 0.0), Some(to), false, true, TALK), Step::Act(_)), "right above it, two levels up: not there");
    }

    #[test]
    fn talk_to_walks_near_then_faces_and_uses_until_talking() {
        let them = Vec3::new(0.0, 0.0, 10.0);
        let command = Command::TalkTo { who: 7 };
        assert!(matches!(step(&command, Vec3::ZERO, Some(them), false, true, TALK), Step::Act(a) if a.contains(&Action::Go { x: 0.0, y: 0.0, z: 10.0 })));
        let near = Vec3::new(0.0, 0.0, 8.0);
        assert_eq!(step(&command, near, Some(them), false, true, TALK), Step::Act(vec![Action::Aim { x: 0.0, y: 10.0 }, Action::Use]));
        assert_eq!(
            step(&command, near, Some(them), false, false, TALK),
            Step::Act(vec![Action::Go { x: 0.0, y: 0.0, z: 10.0 }]),
            "near enough but not seen (something between): closer"
        );
        assert_eq!(step(&command, Vec3::new(0.0, 0.0, 9.0), Some(them), false, false, TALK), Step::Act(vec![Action::Aim { x: 0.0, y: 10.0 }, Action::Use]), "at reach: face them and use");
        assert_eq!(step(&command, near, Some(them), true, true, TALK), Step::Done, "talking with them: done");
        assert_eq!(step(&command, near, None, false, true, TALK), Step::Done, "gone: done");
    }

    #[test]
    fn knock_walks_to_the_door_and_knocks_until_knocked() {
        let before_the_door = Vec3::new(0.0, -6.0, 4.0);
        let command = Command::Knock { who: 7 };
        assert_eq!(step(&command, Vec3::ZERO, Some(before_the_door), false, true, TALK), Step::Act(vec![Action::Go { x: 0.0, y: -6.0, z: 4.0 }]));
        assert_eq!(
            step(&command, Vec3::new(0.0, -6.0, 3.0), Some(before_the_door), false, true, TALK),
            Step::Act(vec![Action::Go { x: 0.0, y: -6.0, z: 4.0 }]),
            "within the brain's reach but not at the spot: still going"
        );
        assert_eq!(step(&command, Vec3::new(0.0, -6.0, 3.8), Some(before_the_door), false, true, TALK), Step::Act(vec![Action::Knock]));
        assert_eq!(step(&command, Vec3::new(0.0, -6.0, 3.8), Some(before_the_door), true, true, TALK), Step::Done, "knocked: done");
        assert_eq!(step(&command, Vec3::ZERO, None, false, true, TALK), Step::Done, "no door: done");
    }

    #[test]
    fn attack_closes_then_hits_in_reach_until_dead() {
        let them = Vec3::new(5.0, 0.0, 0.0);
        let command = Command::Attack { who: 3 };
        assert!(matches!(step(&command, Vec3::ZERO, Some(them), false, true, TALK), Step::Act(a) if !a.contains(&Action::Attack)));
        let near = Vec3::new(4.0, 0.0, 0.0);
        assert_eq!(step(&command, near, Some(them), false, true, TALK), Step::Act(vec![Action::Aim { x: 5.0, y: 0.0 }, Action::Attack]));
        assert_eq!(step(&command, near, None, false, true, TALK), Step::Done, "dead: done");
    }

    /// A command's JSON keeps its points flat (`{"do": "move_to", "x", "y",
    /// "z"}`, what the command op and saved replays hold), and an order in
    /// data resolves to one given: whom and where worked out, or none.
    #[test]
    fn a_command_reads_flat_and_an_order_in_data_resolves() {
        let json = serde_json::json!({"do": "lead", "who": 4, "x": 1.0, "y": 0.5, "z": -2.0});
        let lead: Command = serde_json::from_value(json.clone()).expect("a lead reads");
        assert_eq!(lead, Command::Lead { who: 4, to: Point { x: 1.0, y: 0.5, z: -2.0 } });
        assert_eq!(serde_json::to_value(lead).expect("a lead writes"), json);
        let hold: Command = serde_json::from_value(serde_json::json!({"do": "hold", "x": 3.0, "y": 0.0, "z": 4.0})).expect("a hold reads");
        assert_eq!(hold, Command::Hold { at: Point { x: 3.0, y: 0.0, z: 4.0 } });
        // In data: whom by name, where by a thing's name.
        let order: Command<&str, &str> = Command::Lead { who: "the player", to: "tap" };
        let given = order.resolve(|w| (w == "the player").then_some(1u64), |p| (p == "tap").then_some(Point { x: 9.0, y: 0.0, z: 9.0 }));
        assert_eq!(given, Some(Command::Lead { who: 1, to: Point { x: 9.0, y: 0.0, z: 9.0 } }));
        let knock: Command<&str, &str> = Command::Knock { who: "nobody" };
        assert_eq!(knock.resolve(|_| None::<u64>, |_| None::<Point>), None, "whom it names is not there: no order");
    }

    #[test]
    fn a_replay_gives_each_command_the_same_ticks_apart() {
        let replay = Replay {
            seed: 9,
            given: vec![
                Given { tick: 100, who: 1, command: Command::Follow { who: 2 } },
                Given { tick: 160, who: 1, command: Command::AttackNearestEnemy },
            ],
        };
        let played = replay.from_tick(5000);
        assert_eq!(played.iter().map(|g| g.tick).collect::<Vec<_>>(), vec![5000, 5060]);
        assert_eq!(played[1].command, Command::AttackNearestEnemy);
        let saved = serde_json::to_string(&replay).expect("a replay saves");
        assert_eq!(serde_json::from_str::<Replay>(&saved).expect("and loads"), replay);
    }
}
