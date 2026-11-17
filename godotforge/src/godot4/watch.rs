//! Watch the game: record the signals objects emit, with their
//! arguments, as the game plays. Read-only: the mod only listens;
//! the game's own code emits.
//!
//! `watch_signals` connects to an object's signals (all, or the ones
//! named), `watch_events` reads what was recorded since a sequence
//! number, `watch_stop` disconnects everything.

use std::cell::RefCell;
use std::collections::VecDeque;
use std::sync::Mutex;

use godot::builtin::{Callable, StringName, Variant};
use godot::classes::{Engine, Object, Time};
use godot::meta::ToGodot;
use godot::obj::{Gd, InstanceId, Singleton};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use super::{on_main, target, value};

/// Events kept; the oldest go first.
const MAX_EVENTS: usize = 20_000;
/// Nesting kept in an event's arguments.
const ARG_DEPTH: u32 = 2;

struct Log {
    next_seq: u64,
    events: VecDeque<Json>,
}

static LOG: Mutex<Log> = Mutex::new(Log {
    next_seq: 1,
    events: VecDeque::new(),
});

thread_local! {
    /// Connections made, to undo on `watch_stop`. Main thread only.
    static CONNECTIONS: RefCell<Vec<(InstanceId, StringName, Callable)>> =
        const { RefCell::new(Vec::new()) };
}

pub fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "watch_signals",
            "Record the signals an object emits, with arguments, time and frame",
            "{id|node, signals?: [name] default all}",
            watch_signals,
        ),
        OpDef::new(
            "watch_events",
            "Recorded signal events after a sequence number, oldest first",
            "{since?: seq, max?: 1000}",
            watch_events,
        ),
        OpDef::new(
            "watch_stop",
            "Disconnect every watch; recorded events stay",
            "{}",
            watch_stop,
        ),
    ]);
}

fn record(source: &str, signal: &str, args: &[&Variant]) {
    let ms = Time::singleton().get_ticks_msec();
    let frame = Engine::singleton().get_process_frames();
    let args: Vec<Json> = args.iter().map(|a| value::to_json(a, ARG_DEPTH)).collect();
    let Ok(mut log) = LOG.lock() else {
        return;
    };
    let seq = log.next_seq;
    log.next_seq += 1;
    log.events.push_back(json!({
        "seq": seq,
        "ms": ms,
        "frame": frame,
        "source": source,
        "signal": signal,
        "args": args,
    }));
    while log.events.len() > MAX_EVENTS {
        log.events.pop_front();
    }
}

fn source_name(o: &Gd<Object>) -> String {
    match value::object(o).get("path").and_then(Json::as_str) {
        Some(p) => p.to_string(),
        None => format!("{}#{}", o.get_class(), o.instance_id().to_i64()),
    }
}

fn watch_signals(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("watch_signals", move || {
        let mut o = target::object(&args)?;
        let names: Vec<String> = match args.get("signals").and_then(Json::as_array) {
            Some(a) => a
                .iter()
                .filter_map(Json::as_str)
                .map(str::to_string)
                .collect(),
            None => o
                .get_signal_list()
                .iter_shared()
                .map(|s| s.get(&"name".to_variant()).unwrap_or_default().to_string())
                .collect(),
        };
        let source = source_name(&o);
        let mut connected = Vec::new();
        let mut failed = Vec::new();
        for name in names {
            let signal = StringName::from(name.as_str());
            if !o.has_signal(&signal) {
                failed.push(json!({"signal": name, "error": "no such signal"}));
                continue;
            }
            let (src, sig) = (source.clone(), name.clone());
            let callable = Callable::from_fn(format!("watch {name}"), move |a: &[&Variant]| {
                record(&src, &sig, a);
                Variant::nil()
            });
            let err = o.connect(&signal, &callable);
            if err == godot::global::Error::OK {
                CONNECTIONS.with(|c| c.borrow_mut().push((o.instance_id(), signal, callable)));
                connected.push(json!(name));
            } else {
                failed.push(json!({"signal": name, "error": format!("{err:?}")}));
            }
        }
        Ok(json!({"source": source, "connected": connected, "failed": failed}))
    })
}

fn watch_events(args: &Json) -> Result<Json, String> {
    let since = args.get("since").and_then(Json::as_u64).unwrap_or(0);
    let max = args
        .get("max")
        .and_then(Json::as_u64)
        .map_or(1000, |m| m.min(MAX_EVENTS as u64)) as usize;
    let log = LOG.lock().map_err(|_| "watch log poisoned")?;
    let events: Vec<&Json> = log
        .events
        .iter()
        .filter(|e| e["seq"].as_u64().is_some_and(|s| s > since))
        .take(max)
        .collect();
    Ok(json!({"next_seq": log.next_seq, "count": events.len(), "events": events}))
}

fn watch_stop(_args: &Json) -> Result<Json, String> {
    on_main("watch_stop", || {
        let conns = CONNECTIONS.with(|c| std::mem::take(&mut *c.borrow_mut()));
        let mut stopped = 0;
        for (id, signal, callable) in conns {
            if let Ok(mut o) = Gd::<Object>::try_from_instance_id(id)
                && o.is_connected(&signal, &callable)
            {
                o.disconnect(&signal, &callable);
                stopped += 1;
            }
        }
        Ok(json!({"stopped": stopped}))
    })
}
