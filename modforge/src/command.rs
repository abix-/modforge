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

/// One order. `who` is a person's ActorId; a point is on the ground.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
#[serde(tag = "do", rename_all = "snake_case")]
pub enum Command {
    /// Walk to the point.
    MoveTo { x: f32, y: f32 },
    /// Follow them, until a move of one's own or they are gone (the
    /// consumer's following does it).
    Follow { who: u64 },
    /// Walk to them, face them, and use, as E does, until talking with them.
    TalkTo { who: u64 },
    /// Walk to them, face them, and attack in reach until they are dead.
    Attack { who: u64 },
    /// Attack the nearest living person one stands hostile to (the
    /// consumer names them, by the brain's one rule).
    AttackNearestEnemy,
}

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
/// them). Follow and attack the nearest enemy are the consumer's to turn
/// into its following and an attack first; here they are done.
pub fn step(command: &Command, here: Vec3, target: Option<Vec3>, ended: bool, talk_reach: f32) -> Step {
    let Some(to) = target.filter(|_| !ended) else {
        return Step::Done;
    };
    let apart = (to - here).with_y(0.0).length();
    match command {
        Command::MoveTo { .. } => {
            let actions = walk_toward(here, to);
            if actions.is_empty() { Step::Done } else { Step::Act(actions) }
        }
        Command::TalkTo { .. } if apart > talk_reach => Step::Act(walk_toward(here, to)),
        Command::TalkTo { .. } => {
            let mut actions = turn_toward(here, to);
            actions.push(Action::Use);
            Step::Act(actions)
        }
        Command::Attack { .. } if apart > MELEE_REACH => Step::Act(walk_toward(here, to)),
        Command::Attack { .. } => {
            let mut actions = turn_toward(here, to);
            actions.push(Action::Attack);
            Step::Act(actions)
        }
        Command::Follow { .. } | Command::AttackNearestEnemy => Step::Done,
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
    fn move_to_walks_there_and_is_done_there() {
        let to = Vec3::new(10.0, 0.0, 0.0);
        let far = step(&Command::MoveTo { x: 10.0, y: 0.0 }, Vec3::ZERO, Some(to), false, TALK);
        assert_eq!(far, Step::Act(vec![Action::Aim { x: 10.0, y: 0.0 }, Action::Move { x: 1.0, y: 0.0 }]));
        assert_eq!(step(&Command::MoveTo { x: 10.0, y: 0.0 }, Vec3::new(9.5, 0.0, 0.0), Some(to), false, TALK), Step::Done);
    }

    #[test]
    fn talk_to_walks_near_then_faces_and_uses_until_talking() {
        let them = Vec3::new(0.0, 0.0, 10.0);
        let command = Command::TalkTo { who: 7 };
        assert!(matches!(step(&command, Vec3::ZERO, Some(them), false, TALK), Step::Act(a) if a.contains(&Action::Move { x: 0.0, y: 1.0 })));
        let near = Vec3::new(0.0, 0.0, 8.0);
        assert_eq!(step(&command, near, Some(them), false, TALK), Step::Act(vec![Action::Aim { x: 0.0, y: 10.0 }, Action::Use]));
        assert_eq!(step(&command, near, Some(them), true, TALK), Step::Done, "talking with them: done");
        assert_eq!(step(&command, near, None, false, TALK), Step::Done, "gone: done");
    }

    #[test]
    fn attack_closes_then_hits_in_reach_until_dead() {
        let them = Vec3::new(5.0, 0.0, 0.0);
        let command = Command::Attack { who: 3 };
        assert!(matches!(step(&command, Vec3::ZERO, Some(them), false, TALK), Step::Act(a) if !a.contains(&Action::Attack)));
        let near = Vec3::new(4.0, 0.0, 0.0);
        assert_eq!(step(&command, near, Some(them), false, TALK), Step::Act(vec![Action::Aim { x: 5.0, y: 0.0 }, Action::Attack]));
        assert_eq!(step(&command, near, None, false, TALK), Step::Done, "dead: done");
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
