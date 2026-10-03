//! How Obenseuer's loading screens spend their time at a door, and which
//! game managers are rebuilt at every door instead of living once for the
//! whole game (operator 2026-10-02: keep one copy and stop the save and
//! load at each door).
//!
//! The test watches while the player walks through doors in the game.
//! Read-only: walk_class, read_field, invoke_method and invoke_static on
//! getters only. Each trip is timed in four parts:
//!
//! - fade: from SaveController.Loading going true to the fade to black
//!   finishing (LoadingScreen.Fading back to false)
//! - save and read back: from there to LoadingScreen.LevelLoadDone going
//!   false; the game writes the autosave and reads it back in this part
//! - bar: until LevelLoadDone is true again (the new area's scene loaded)
//! - restore: until SaveController.Loading is false again (the area's
//!   saved boxes, NPCs and clock put back)
//!
//! After each trip every manager's instance ids are compared with the
//! ones before it: the same id kept the object, a new id is a rebuilt one.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_loading -- --test-threads=1 --nocapture
//! ```
//!
//! OBENSEUER_WATCH_SECS (default 600) and OBENSEUER_WATCH_TRIPS (default
//! 3) bound the watch. SKIPs (prints why and passes) when the game is not
//! running. Results go to output/loading-trips.txt.

mod common;
use std::time::{Duration, Instant};

use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// The game's managers and per-player objects: each sets itself as the
/// one copy in Awake. LoadingScreen and SaveController are the ones the
/// game already keeps through scene changes; they are here to show what
/// kept looks like.
const MANAGERS: &[&str] = &[
    "SaveController",
    "LoadingScreen",
    "Inventory",
    "BackpackStorage",
    "PlayerStats",
    "TimeOfDayAzure",
    "Crime",
    "Money",
    "DifficultyController",
    "WaitingController",
    "TenementController",
    "GameUIController",
    "Notifications",
    "InteractObjects",
];

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

fn handles(api: &Api<Value>, class: &str) -> Vec<i64> {
    let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
    let list = r
        .result
        .get("instances")
        .and_then(Value::as_array)
        .or_else(|| r.result.as_array())
        .cloned()
        .unwrap_or_default();
    list.iter().filter_map(handle_of).collect()
}

/// Every manager's live instance ids, plus the main camera's (the player).
fn snapshot(api: &Api<Value>) -> Vec<(String, Vec<i64>)> {
    let mut out = Vec::new();
    for class in MANAGERS {
        let mut ids = Vec::new();
        for h in handles(api, class) {
            if let Some(id) = call(api, h, "GetInstanceID", json!([])).as_i64() {
                ids.push(id);
            }
            release(api, h);
        }
        ids.sort();
        out.push((class.to_string(), ids));
    }
    let camera = api.op("invoke_static", json!({"class": "UnityEngine.Camera", "method": "get_main", "args": []}));
    let mut ids = Vec::new();
    if let Some(h) = handle_of(&camera.result) {
        if let Some(id) = call(api, h, "GetInstanceID", json!([])).as_i64() {
            ids.push(id);
        }
        release(api, h);
    }
    out.push(("main camera".to_string(), ids));
    out
}

fn active_scene(api: &Api<Value>) -> String {
    let r = api.op(
        "invoke_static",
        json!({"class": "UnityEngine.Application", "method": "get_loadedLevelName", "args": []}),
    );
    r.result.as_str().map(String::from).unwrap_or_else(|| format!("? ({} {:?})", r.result, r.error))
}

fn compare(before: &[(String, Vec<i64>)], after: &[(String, Vec<i64>)]) -> Vec<String> {
    before
        .iter()
        .zip(after)
        .map(|((class, a), (_, b))| {
            let verdict = if a.is_empty() && b.is_empty() {
                "none live"
            } else if a == b {
                "KEPT"
            } else if a.iter().any(|id| b.contains(id)) {
                "partly kept"
            } else {
                "REBUILT"
            };
            format!("  {class:<22} {verdict:<12} count {} -> {}  ids {a:?} -> {b:?}", a.len(), b.len())
        })
        .collect()
}

struct Probe {
    loading_screen: i64,
}

impl Probe {
    fn new(api: &Api<Value>) -> Result<Self, String> {
        let r = api.op("walk_class", json!({"class": "LoadingScreen", "include_inactive": true}));
        let loading_screen = r
            .result
            .get("instances")
            .and_then(Value::as_array)
            .and_then(|a| a.first())
            .and_then(handle_of)
            .ok_or_else(|| format!("no live LoadingScreen; walk_class gave {} error {:?}", r.result, r.error))?;
        let r = api.op("invoke_static", json!({"class": "SaveController", "method": "get_Loading", "args": []}));
        r.result.as_bool().ok_or(format!("SaveController.Loading gave {} error {:?}", r.result, r.error))?;
        Ok(Self { loading_screen })
    }

    /// (SaveController.Loading, LoadingScreen.Fading, LoadingScreen.LevelLoadDone)
    fn state(&self, api: &Api<Value>) -> (bool, bool, bool) {
        let loading = api
            .op("invoke_static", json!({"class": "SaveController", "method": "get_Loading", "args": []}))
            .result
            .as_bool()
            .unwrap_or(false);
        let fading = call(api, self.loading_screen, "get_Fading", json!([])).as_bool().unwrap_or(false);
        let done = read(api, self.loading_screen, "LevelLoadDone").as_bool().unwrap_or(true);
        (loading, fading, done)
    }
}

#[derive(Default)]
struct Trip {
    start: Option<Instant>,
    fade_done: Option<Instant>,
    bar_start: Option<Instant>,
    bar_done: Option<Instant>,
    end: Option<Instant>,
    longest_freeze: Duration,
}

fn secs(a: Option<Instant>, b: Option<Instant>) -> String {
    match (a, b) {
        (Some(a), Some(b)) => format!("{:6.2}s", (b - a).as_secs_f64()),
        _ => "   n/a ".to_string(),
    }
}

fn env_num(name: &str, default: u64) -> u64 {
    std::env::var(name).ok().and_then(|v| v.parse().ok()).unwrap_or(default)
}

/// Walk through doors in the game while this runs.
#[test]
fn door_trips_timed_and_managers_tracked() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let watch = Duration::from_secs(env_num("OBENSEUER_WATCH_SECS", 600));
    let want_trips = env_num("OBENSEUER_WATCH_TRIPS", 1) as usize;
    // The game answers only while its frames run (not while it is paused
    // in the background), so keep asking until it does.
    let setup_until = Instant::now() + watch;
    let probe = loop {
        match Probe::new(&api) {
            Ok(p) => break p,
            Err(e) if Instant::now() < setup_until => {
                println!("waiting for the game to answer: {e}");
                std::thread::sleep(Duration::from_secs(1));
            }
            Err(e) => panic!("cannot watch loading: {e}"),
        }
    };

    let mut lines = Vec::new();
    let mut before = snapshot(&api);
    let mut scene = active_scene(&api);
    println!("watching up to {}s for {want_trips} door trips; start scene {scene}", watch.as_secs());
    println!("walk through doors in the game now");

    let begin = Instant::now();
    let mut trips = 0;
    let mut trip = Trip::default();
    let mut last_poll = Instant::now();
    let mut seen_fading = false;
    while begin.elapsed() < watch && trips < want_trips {
        let (loading, fading, done) = probe.state(&api);
        let now = Instant::now();
        if trip.start.is_some() {
            trip.longest_freeze = trip.longest_freeze.max(now - last_poll);
        }
        last_poll = now;

        if trip.start.is_none() {
            if loading {
                trip.start = Some(now);
                seen_fading = fading;
            }
        } else {
            seen_fading |= fading;
            if trip.fade_done.is_none() && seen_fading && !fading {
                trip.fade_done = Some(now);
            }
            if trip.bar_start.is_none() && !done {
                trip.bar_start = Some(now);
            }
            if trip.bar_start.is_some() && trip.bar_done.is_none() && done {
                trip.bar_done = Some(now);
            }
            if trip.bar_done.is_some() && !loading {
                trip.end = Some(now);
                trips += 1;
                let after = snapshot(&api);
                let to = active_scene(&api);
                let head = format!(
                    "trip {trips}: {scene} -> {to}\n  fade {}  save and read back {}  bar {}  restore {}  total {}  longest freeze {:.2}s",
                    secs(trip.start, trip.fade_done),
                    secs(trip.fade_done, trip.bar_start),
                    secs(trip.bar_start, trip.bar_done),
                    secs(trip.bar_done, trip.end),
                    secs(trip.start, trip.end),
                    trip.longest_freeze.as_secs_f64(),
                );
                println!("{head}");
                lines.push(head);
                for row in compare(&before, &after) {
                    println!("{row}");
                    lines.push(row);
                }
                write_results(trips, &lines);
                before = after;
                scene = to;
                trip = Trip::default();
                seen_fading = false;
            }
        }
    }

    release(&api, probe.loading_screen);
    assert!(trips > 0, "no door trip seen in {}s", watch.as_secs());
}

/// Written after every trip, so a stopped watch keeps what it saw.
fn write_results(trips: usize, lines: &[String]) {
    let path = common::output_path("loading-trips.txt");
    let text = format!("{trips} door trips watched\n\n{}\n", lines.join("\n"));
    std::fs::write(&path, text).expect("write the results");
    println!("{trips} trips written to {path}");
}
