//! The StateTree (docs/statetree.md): the one way a person decides. States
//! form a tree; what a person is doing is one path from the root down to
//! one leaf, kept in their `Record`, the one record of what they are
//! doing. Each think the leaf's task runs, then the transitions are
//! checked from the leaf up to the root; a state is chosen again only
//! when one fires, or when the task ends. Unreal's StateTree is the
//! model: "a general-purpose hierarchical state machine that combines
//! the Selectors from behavior trees with States and Transitions from
//! state machines".
//!
//! The system lives here; a game's tree (its states, their order, their
//! rules) lives with the game.

use glam::Vec3;

use crate::actor::ActorId;
use crate::learn::Choice;
use crate::survival::Need;

/// A state, by its place in the tree's list.
pub type StateId = usize;
/// The first state in a tree's list is its root.
pub const ROOT: StateId = 0;

/// What the active state is about.
#[derive(Clone, Copy, Debug, Default, PartialEq)]
pub enum Target {
    #[default]
    None,
    /// A remembered thing: its memory key, where it is, and the need
    /// that sent them, if one did.
    Thing { key: u64, at: Vec3, need: Option<Need> },
    /// A point on the ground.
    Point(Vec3),
    /// Who they fight or run from, and where the fight began.
    Threat { who: ActorId, began_at: Vec3 },
    /// A need met from what they carry.
    Need(Need),
}

/// What a person is doing: the active leaf and what it is about. The
/// consumer keeps it on the person and hands it back each think.
#[derive(Clone, Copy, Debug, Default, PartialEq)]
pub struct Record {
    pub state: Option<StateId>,
    pub target: Target,
}

/// A task's answer each think.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Status {
    Running,
    Succeeded,
    Failed,
}

/// How a parent tries its children.
pub enum Select<C> {
    /// The first child that can be entered.
    InOrder,
    /// What the person learned picks among the children that can be
    /// entered: handed their choices in the tree's order, it answers the
    /// index of the one to take.
    Learned(fn(&mut C, &[Choice]) -> usize),
}

/// When a transition fires.
pub enum When<C> {
    /// The active task succeeded.
    Succeeded,
    /// The active task failed.
    Failed,
    /// This holds, checked every think.
    Holds(fn(&mut C, &Target) -> bool),
}

/// Leave the active state and choose again, starting at `to`.
pub struct Transition<C> {
    pub when: When<C>,
    pub to: StateId,
}

pub struct StateDef<C> {
    pub name: &'static str,
    pub parent: Option<StateId>,
    /// What choosing this state means to the learning, for a child of a
    /// `Select::Learned` parent.
    pub choice: Option<Choice>,
    /// Whether the state can be entered now, handed what its parent (or
    /// the state left) was about; the answer is what it will be about.
    pub enter: fn(&mut C, &Target) -> Option<Target>,
    pub select: Select<C>,
    /// What a leaf does each think.
    pub task: Option<fn(&mut C, &Target) -> Status>,
    pub transitions: Vec<Transition<C>>,
}

/// Enter whenever asked, about what the parent is about.
pub fn always<C>(_: &mut C, target: &Target) -> Option<Target> {
    Some(*target)
}

pub struct StateTree<C> {
    pub states: Vec<StateDef<C>>,
}

impl<C> StateTree<C> {
    pub fn name(&self, state: StateId) -> &'static str {
        self.states[state].name
    }

    /// Whether `state` is `ancestor` or under it.
    pub fn is_under(&self, state: StateId, ancestor: StateId) -> bool {
        self.up_from(state).any(|s| s == ancestor)
    }

    /// `state`, then each parent up to the root.
    fn up_from(&self, state: StateId) -> impl Iterator<Item = StateId> + '_ {
        std::iter::successors(Some(state), |s| self.states[*s].parent)
    }

    fn children(&self, of: StateId) -> impl Iterator<Item = StateId> + '_ {
        (0..self.states.len()).filter(move |s| self.states[*s].parent == Some(of))
    }

    /// Walk down from `from` to a leaf that can be entered, and what it
    /// is about; `chose` gets each learned choice taken on the way.
    fn select(&self, from: StateId, ctx: &mut C, about: &Target, chose: &mut Vec<Choice>) -> Option<(StateId, Target)> {
        let state = &self.states[from];
        let target = (state.enter)(ctx, about)?;
        let children: Vec<StateId> = self.children(from).collect();
        if children.is_empty() {
            return Some((from, target));
        }
        match state.select {
            Select::InOrder => children.into_iter().find_map(|c| self.select(c, ctx, &target, chose)),
            Select::Learned(pick) => {
                // Every child that can be entered is a choice; a child with
                // no choice named is never offered.
                let mut open = Vec::new();
                for c in children {
                    let Some(choice) = self.states[c].choice else {
                        continue;
                    };
                    let mut below = Vec::new();
                    if let Some((leaf, t)) = self.select(c, ctx, &target, &mut below) {
                        open.push((choice, leaf, t, below));
                    }
                }
                if open.is_empty() {
                    return None;
                }
                let choices: Vec<Choice> = open.iter().map(|o| o.0).collect();
                let (choice, leaf, t, below) = open.swap_remove(pick(ctx, &choices));
                chose.push(choice);
                chose.extend(below);
                Some((leaf, t))
            }
        }
    }

    /// One think: run the active task, fire the first transition from
    /// the leaf up, and choose again only then (or when the task ended,
    /// from the root). A newly chosen state's task runs in the same think
    /// so the person acts on it at once; a state already run this think
    /// is not run twice. Answers the learned choices made, in order.
    pub fn think(&self, ctx: &mut C, record: &mut Record) -> Vec<Choice> {
        let mut chose = Vec::new();
        let mut ran: Vec<StateId> = Vec::new();
        let mut from = match record.state {
            Some(_) => None,
            None => Some(ROOT),
        };
        loop {
            if let Some(start) = from.take() {
                *record = match self.select(start, ctx, &record.target, &mut chose) {
                    Some((state, target)) => Record { state: Some(state), target },
                    None => Record::default(),
                };
            }
            let Some(leaf) = record.state else {
                return chose;
            };
            if ran.contains(&leaf) {
                return chose;
            }
            ran.push(leaf);
            let status = self.states[leaf].task.map_or(Status::Succeeded, |task| task(ctx, &record.target));
            let target = record.target;
            let fired = self.up_from(leaf).find_map(|s| {
                self.states[s]
                    .transitions
                    .iter()
                    .find(|t| match t.when {
                        When::Succeeded => status == Status::Succeeded,
                        When::Failed => status == Status::Failed,
                        When::Holds(holds) => holds(ctx, &target),
                    })
                    .map(|t| t.to)
            });
            from = match (fired, status) {
                (Some(to), _) => Some(to),
                (None, Status::Running) => return chose,
                // Ended with nowhere named to go: choose again from the
                // root (a failure goes up the tree to it).
                (None, _) => Some(ROOT),
            };
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A test person: what their tasks answer, what holds, and a log of
    /// what ran.
    #[derive(Default)]
    struct Person {
        danger: bool,
        hungry: bool,
        walk: Option<Status>,
        entered: Vec<&'static str>,
        ran: Vec<&'static str>,
        offered: Vec<Choice>,
        take: usize,
    }

    fn state(name: &'static str, parent: Option<StateId>) -> StateDef<Person> {
        StateDef {
            name,
            parent,
            choice: None,
            enter: always,
            select: Select::InOrder,
            task: None,
            transitions: Vec::new(),
        }
    }

    const HIDE: StateId = 1;
    const LIFE: StateId = 2;
    const WALK: StateId = 4;

    /// root (in order): hide (when in danger), life (learned): eat (when
    /// hungry), walk. Life leaves for the root when danger comes.
    fn tree() -> StateTree<Person> {
        let mut root = state("root", None);
        root.select = Select::InOrder;
        let mut hide = state("hide", Some(ROOT));
        hide.enter = |p, t| {
            p.entered.push("hide");
            p.danger.then_some(*t)
        };
        hide.task = Some(|p, _| {
            p.ran.push("hide");
            Status::Running
        });
        hide.transitions.push(Transition {
            when: When::Holds(|p, _| !p.danger),
            to: ROOT,
        });
        let mut life = state("life", Some(ROOT));
        life.select = Select::Learned(|p, offered| {
            p.offered = offered.to_vec();
            p.take.min(offered.len() - 1)
        });
        life.transitions.push(Transition {
            when: When::Holds(|p, _| p.danger),
            to: ROOT,
        });
        let mut eat = state("eat", Some(LIFE));
        eat.choice = Some(Choice::GoToNeed);
        eat.enter = |p, _| {
            p.entered.push("eat");
            p.hungry.then_some(Target::Need(Need::Hunger))
        };
        eat.task = Some(|p, _| {
            p.ran.push("eat");
            p.hungry = false;
            Status::Succeeded
        });
        let mut walk = state("walk", Some(LIFE));
        walk.choice = Some(Choice::Wander);
        walk.enter = |p, _| {
            p.entered.push("walk");
            Some(Target::Point(Vec3::X))
        };
        walk.task = Some(|p, _| {
            p.ran.push("walk");
            p.walk.unwrap_or(Status::Running)
        });
        StateTree {
            states: vec![root, hide, life, eat, walk],
        }
    }

    #[test]
    fn the_first_child_in_order_that_can_be_entered_is_chosen() {
        let tree = tree();
        let mut p = Person {
            danger: true,
            ..Default::default()
        };
        let mut record = Record::default();
        tree.think(&mut p, &mut record);
        assert_eq!(record.state, Some(HIDE));
        p.danger = false;
        let mut record = Record::default();
        tree.think(&mut p, &mut record);
        assert!(tree.is_under(record.state.unwrap(), LIFE), "no danger: the day's life");
    }

    #[test]
    fn a_running_task_keeps_its_state_and_nothing_is_chosen_again() {
        let tree = tree();
        let mut p = Person::default();
        let mut record = Record::default();
        tree.think(&mut p, &mut record);
        assert_eq!(record.state, Some(WALK));
        p.entered.clear();
        for _ in 0..5 {
            tree.think(&mut p, &mut record);
        }
        assert_eq!(record.state, Some(WALK));
        assert!(p.entered.is_empty(), "no state's enter was asked while walking: {:?}", p.entered);
        assert_eq!(p.ran.iter().filter(|r| **r == "walk").count(), 6);
    }

    #[test]
    fn a_transition_on_a_parent_takes_the_person_out_of_any_child() {
        let tree = tree();
        let mut p = Person::default();
        let mut record = Record::default();
        tree.think(&mut p, &mut record);
        assert_eq!(record.state, Some(WALK));
        p.danger = true;
        tree.think(&mut p, &mut record);
        assert_eq!(record.state, Some(HIDE), "danger on the life takes them out of the walk");
        assert_eq!(p.ran.last(), Some(&"hide"), "and they hide in the same think");
        p.danger = false;
        tree.think(&mut p, &mut record);
        assert!(tree.is_under(record.state.unwrap(), LIFE), "safe again: they choose again");
    }

    #[test]
    fn a_task_that_ends_chooses_again_from_the_root() {
        let tree = tree();
        let mut p = Person {
            hungry: true,
            ..Default::default()
        };
        let mut record = Record::default();
        let chose = tree.think(&mut p, &mut record);
        assert_eq!(p.ran.first(), Some(&"eat"));
        assert_eq!(record.state, Some(WALK), "ate, then chose again: the walk, in the same think");
        assert_eq!(chose, vec![Choice::GoToNeed, Choice::Wander], "both choices go to the learning");
        p.walk = Some(Status::Failed);
        p.entered.clear();
        tree.think(&mut p, &mut record);
        assert!(p.entered.contains(&"walk"), "the failed walk went up to the root and chose again");
    }

    #[test]
    fn what_was_learned_picks_among_the_children() {
        let tree = tree();
        let mut p = Person {
            hungry: true,
            take: 1,
            ..Default::default()
        };
        let mut record = Record::default();
        let chose = tree.think(&mut p, &mut record);
        assert_eq!(p.offered, vec![Choice::GoToNeed, Choice::Wander], "offered in the tree's order");
        assert_eq!(chose, vec![Choice::Wander]);
        assert_eq!(record, Record { state: Some(WALK), target: Target::Point(Vec3::X) });
        assert!(p.hungry, "the eat was offered but not taken");
    }
}
