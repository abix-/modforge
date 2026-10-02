//! The test queue (topside docs/authority.md "Running tests"): a game holds
//! the tests queued to run against it and each one's result, so one test,
//! a list, or a group is queued, watched while it runs, and read when all
//! are done. Prior art: Unreal's automation tab and a CI runner taking jobs
//! from a queue. The tests themselves live with the game's test crate; a
//! runner there takes the next queued test, runs it, and reports it here.
//!
//! The game registers the `tests` op with [`register_ops`]; nothing here
//! touches the game's world.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};

use crate::ops::{OP_REGISTRY, OpDef};

/// Where one queued test stands.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum State {
    Queued,
    Running,
    Passed,
    Failed,
}

impl State {
    fn name(self) -> &'static str {
        match self {
            State::Queued => "queued",
            State::Running => "running",
            State::Passed => "passed",
            State::Failed => "failed",
        }
    }
}

/// One test in a run: its name, where it stands, and its output once done.
#[derive(Clone, Debug)]
pub struct Entry {
    pub name: String,
    pub state: State,
    pub output: String,
}

/// The tests queued together, run one after another.
#[derive(Clone, Debug)]
pub struct Run {
    pub id: u64,
    pub entries: Vec<Entry>,
}

/// Every run queued since the game started.
#[derive(Default)]
pub struct TestQueue {
    runs: Vec<Run>,
    last_id: u64,
}

impl TestQueue {
    pub const fn new() -> Self {
        Self { runs: Vec::new(), last_id: 0 }
    }

    /// Queue `names` as one run; its id.
    pub fn queue(&mut self, names: Vec<String>) -> u64 {
        self.last_id += 1;
        let entries = names.into_iter().map(|name| Entry { name, state: State::Queued, output: String::new() }).collect();
        self.runs.push(Run { id: self.last_id, entries });
        self.last_id
    }

    /// The next queued test of run `id`, now running; none when nothing is
    /// left queued in it.
    pub fn take(&mut self, id: u64) -> Option<String> {
        let entry = self.run_mut(id)?.entries.iter_mut().find(|e| e.state == State::Queued)?;
        entry.state = State::Running;
        Some(entry.name.clone())
    }

    /// Test `name` of run `id` finished, passed or failed, with its output.
    pub fn report(&mut self, id: u64, name: &str, passed: bool, output: String) -> Result<(), String> {
        let run = self.run_mut(id).ok_or_else(|| format!("no run {id}"))?;
        let entry = run.entries.iter_mut().find(|e| e.name == name && e.state == State::Running).ok_or_else(|| format!("{name} is not running in run {id}"))?;
        entry.state = if passed { State::Passed } else { State::Failed };
        entry.output = output;
        Ok(())
    }

    /// Run `id`, or the last run when none is named.
    pub fn run(&self, id: Option<u64>) -> Option<&Run> {
        match id {
            Some(id) => self.runs.iter().find(|r| r.id == id),
            None => self.runs.last(),
        }
    }

    fn run_mut(&mut self, id: u64) -> Option<&mut Run> {
        self.runs.iter_mut().find(|r| r.id == id)
    }
}

impl Run {
    /// How many of its tests stand at `state`.
    pub fn count(&self, state: State) -> usize {
        self.entries.iter().filter(|e| e.state == state).count()
    }

    /// The run as the `tests` op reports it: how many queued, running,
    /// passed and failed, whether it is done, and every test.
    pub fn status(&self) -> Json {
        json!({
            "run": self.id,
            "queued": self.count(State::Queued),
            "running": self.count(State::Running),
            "passed": self.count(State::Passed),
            "failed": self.count(State::Failed),
            "done": self.count(State::Queued) + self.count(State::Running) == 0,
            "tests": self.entries.iter().map(|e| json!({"name": e.name, "state": e.state.name(), "output": e.output})).collect::<Vec<_>>(),
        })
    }
}

/// The game's one test queue.
pub static TEST_QUEUE: Mutex<TestQueue> = Mutex::new(TestQueue::new());

/// The `tests` op, on the game's control plane: `queue` (a list of test
/// names) queues them as one run and answers its id; `take` (a run id)
/// answers its next queued test, now running, or null; `report` (a run id,
/// with `name`, `passed`, `output`) records a finished test; `status` (a
/// run id, the last run when left out) answers the run.
pub fn register_ops() {
    OP_REGISTRY.register(OpDef::new(
        "tests",
        "the test queue (authority.md \"Running tests\"): `queue` [names] queues one run and answers its id; `take` run answers its next test, now running, or null; `report` run with `name`, `passed`, `output` records a finished test; `status` run (the last when left out) answers how many are queued, running, passed and failed, and each test",
        "{queue?: [str], take?: u64, report?: u64, name?: str, passed?: bool, output?: str, status?: u64}",
        tests_op,
    ));
}

fn tests_op(args: &Json) -> Result<Json, String> {
    let mut queue = TEST_QUEUE.lock();
    if let Some(names) = args.get("queue") {
        let names: Vec<String> = names.as_array().ok_or("queue takes a list of test names")?.iter().filter_map(|n| n.as_str().map(String::from)).collect();
        if names.is_empty() {
            return Err("queue takes at least one test name".into());
        }
        let id = queue.queue(names);
        return Ok(queue.run(Some(id)).map(Run::status).unwrap_or(Json::Null));
    }
    if let Some(id) = args.get("take") {
        let id = id.as_u64().ok_or("take takes a run id")?;
        return Ok(queue.take(id).map(Json::String).unwrap_or(Json::Null));
    }
    if let Some(id) = args.get("report") {
        let id = id.as_u64().ok_or("report takes a run id")?;
        let name = args.get("name").and_then(Json::as_str).ok_or("report needs the test's name")?;
        let passed = args.get("passed").and_then(Json::as_bool).ok_or("report needs passed, true or false")?;
        let output = args.get("output").and_then(Json::as_str).unwrap_or_default().to_string();
        queue.report(id, name, passed, output)?;
        return Ok(queue.run(Some(id)).map(Run::status).unwrap_or(Json::Null));
    }
    let id = args.get("status").and_then(Json::as_u64);
    Ok(queue.run(id).map(Run::status).unwrap_or(Json::Null))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn names(n: &[&str]) -> Vec<String> {
        n.iter().map(|s| s.to_string()).collect()
    }

    #[test]
    fn a_run_takes_its_tests_in_order_one_at_a_time() {
        let mut q = TestQueue::new();
        let id = q.queue(names(&["a", "b"]));
        assert_eq!(q.take(id).as_deref(), Some("a"));
        assert_eq!(q.run(Some(id)).unwrap().count(State::Running), 1);
        q.report(id, "a", true, String::new()).unwrap();
        assert_eq!(q.take(id).as_deref(), Some("b"));
        q.report(id, "b", false, "boom".into()).unwrap();
        assert_eq!(q.take(id), None);
        let s = q.run(Some(id)).unwrap().status();
        assert_eq!((s["passed"].as_u64(), s["failed"].as_u64(), s["done"].as_bool()), (Some(1), Some(1), Some(true)));
        assert_eq!(s["tests"][1]["output"], "boom");
    }

    #[test]
    fn a_report_for_a_test_not_running_is_refused() {
        let mut q = TestQueue::new();
        let id = q.queue(names(&["a"]));
        assert!(q.report(id, "a", true, String::new()).is_err(), "a was never taken");
        assert!(q.report(id + 1, "a", true, String::new()).is_err(), "no such run");
    }

    #[test]
    fn status_with_no_run_named_is_the_last_run() {
        let mut q = TestQueue::new();
        q.queue(names(&["a"]));
        let last = q.queue(names(&["b", "c"]));
        assert_eq!(q.run(None).unwrap().id, last);
        assert_eq!(q.run(None).unwrap().status()["queued"].as_u64(), Some(2));
    }
}
