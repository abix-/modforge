//! Repeating behaviour as data: `loop.start` runs any op with fixed
//! arguments every `period_ms` on its own thread until `loop.stop`. A
//! follow loop, a perception hand-off, an explore cycle are then a name,
//! an op and a period, started from the endpoint or a tab button, with no
//! thread written per behaviour. Errors from the op are logged and the loop
//! keeps going; a loop ends itself when its op reports `{"stop": true}`.
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::collections::BTreeMap;
use std::sync::Arc;
use std::sync::atomic::{AtomicBool, AtomicU64, Ordering};
use std::time::Duration;

struct Loop {
    op: String,
    args: Value,
    period: Duration,
    on: Arc<AtomicBool>,
    runs: Arc<AtomicU64>,
    last: Arc<Mutex<String>>,
}

static LOOPS: Mutex<BTreeMap<String, Loop>> = Mutex::new(BTreeMap::new());

/// Start (or replace) the named loop.
pub fn start(name: &str, op: &str, args: Value, period: Duration) -> Result<Value, String> {
    stop(name);
    let on = Arc::new(AtomicBool::new(true));
    let runs = Arc::new(AtomicU64::new(0));
    let last = Arc::new(Mutex::new(String::new()));
    let (thread_on, thread_runs, thread_last) = (on.clone(), runs.clone(), last.clone());
    let (thread_name, thread_op, thread_args) = (name.to_owned(), op.to_owned(), args.clone());
    std::thread::Builder::new().name(format!("ueforge-loop-{name}")).spawn(move || {
        while thread_on.load(Ordering::Relaxed) {
            let reply = crate::ops::OP_REGISTRY.dispatch(&thread_op, &thread_args);
            thread_runs.fetch_add(1, Ordering::Relaxed);
            match reply {
                Some(Ok(value)) => {
                    *thread_last.lock() = value.to_string();
                    if value["stop"] == true { crate::log!("loop {thread_name}: {thread_op} asked to stop"); break; }
                }
                Some(Err(error)) => { *thread_last.lock() = format!("error: {error}"); crate::log!("loop {thread_name}: {thread_op}: {error}"); }
                None => { *thread_last.lock() = format!("unknown op {thread_op}"); crate::log!("loop {thread_name}: unknown op {thread_op}"); break; }
            }
            std::thread::sleep(period);
        }
        thread_on.store(false, Ordering::Relaxed);
        crate::log!("loop {thread_name} ended");
    }).map_err(|e| e.to_string())?;
    LOOPS.lock().insert(name.to_owned(), Loop { op: op.to_owned(), args, period, on, runs, last });
    Ok(json!({"loop": name, "op": op, "period_ms": period.as_millis() as u64, "state": "started"}))
}

/// Stop the named loop; true when one was running.
pub fn stop(name: &str) -> bool {
    match LOOPS.lock().remove(name) {
        Some(entry) => { entry.on.store(false, Ordering::Relaxed); true }
        None => false,
    }
}

/// Every loop: op, arguments, period, whether it still runs, run count, last reply.
pub fn list() -> Value {
    let loops = LOOPS.lock();
    json!(loops.iter().map(|(name, l)| json!({"loop": name, "op": l.op, "args": l.args, "period_ms": l.period.as_millis() as u64,
        "running": l.on.load(Ordering::Relaxed), "runs": l.runs.load(Ordering::Relaxed), "last": l.last.lock().chars().take(400).collect::<String>()})).collect::<Vec<_>>())
}

/// Stop every loop, for shutdown and hot reload.
pub fn stop_all() {
    for (_, entry) in std::mem::take(&mut *LOOPS.lock()) { entry.on.store(false, Ordering::Relaxed); }
}

pub fn register_ops() {
    use crate::ops::{OP_REGISTRY, OpDef};
    OP_REGISTRY.register_many([
        OpDef::new("loop.start", "Run an op with fixed arguments every period_ms until loop.stop; a loop with the same name is replaced; the op ending with {stop: true} ends the loop", "{name: str, op: str, args?: {}, period_ms?: u64}", |args| {
            let name = args["name"].as_str().filter(|s| !s.is_empty()).ok_or("name is required")?;
            let op = args["op"].as_str().filter(|s| !s.is_empty()).ok_or("op is required")?;
            let period = Duration::from_millis(args["period_ms"].as_u64().unwrap_or(2000).max(50));
            start(name, op, args["args"].clone(), period)
        }),
        OpDef::new("loop.stop", "Stop a named loop (or every loop with name \"*\")", "{name: str}", |args| {
            let name = args["name"].as_str().filter(|s| !s.is_empty()).ok_or("name is required")?;
            if name == "*" { stop_all(); return Ok(json!({"stopped": "all"})); }
            Ok(json!({"loop": name, "stopped": stop(name)}))
        }),
        OpDef::new("loop.list", "Every loop with its op, period, run count and last reply", "{}", |_| Ok(json!({"loops": list()}))),
    ]);
}
