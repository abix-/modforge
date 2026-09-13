//! Mod-owned UDP AI player sessions. Identity and memory come from a profile.
use abioticfactor_client::{handshake, login, profile};
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::{sync::{Arc, mpsc}, thread::JoinHandle, time::Duration};

struct Session {
    name: String,
    commands: mpsc::Sender<String>,
    observation: Arc<Mutex<login::SessionStatus>>,
    worker: JoinHandle<Result<(), String>>,
    /// True while a follow loop owns this session's walking.
    following: Arc<std::sync::atomic::AtomicBool>,
}

static SESSION: Mutex<Option<Session>> = Mutex::new(None);
static SHUTTING_DOWN: std::sync::atomic::AtomicBool = std::sync::atomic::AtomicBool::new(false);

fn start(args: &Value) -> Result<Value, String> {
    let mut session = SESSION.lock();
    if SHUTTING_DOWN.load(std::sync::atomic::Ordering::Relaxed) {
        return Err("mod is shutting down".into());
    }
    if session.is_some() { return Err("an AI player session already exists; stop it before starting another".into()); }
    let directory = std::path::PathBuf::from(args["profile_dir"].as_str().filter(|s| !s.is_empty())
        .ok_or("profile_dir must identify an existing AI player profile")?);
    if !directory.is_absolute() { return Err("profile_dir must be absolute".into()); }
    let guard = profile::lock(&directory).map_err(|e| e.to_string())?;
    let profile = profile::Profile::load(&directory).map_err(|e| e.to_string())?;
    let name = profile.name.clone();
    let (sender, receiver) = mpsc::channel();
    let observation = Arc::new(Mutex::new(login::SessionStatus::default()));
    let control = login::SessionControl { commands: receiver, status: observation.clone() };
    let worker = std::thread::Builder::new().name("abiotic-ai-player-udp".into()).spawn(move || {
        let _guard = guard;
        let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| -> std::io::Result<()> {
            let server = "127.0.0.1:7777".parse().expect("constant LAN address");
            let socket = handshake::socket(server)?;
            let connected = handshake::connect(&socket, abioticfactor_client::NETWORK_VERSION, Duration::from_secs(5))?;
            profile::remember(&directory, "udp_handshake_accepted", &server.to_string())?;
            let result = login::run_controlled(&socket, connected, &profile, &directory, control);
            profile::remember(&directory, if result.is_ok() { "session_ended" } else { "session_failed" }, &server.to_string())?;
            result.map(|_| ())
        })).map_err(|_| "AI player UDP worker panicked".to_string())
            .and_then(|result| result.map_err(|e| e.to_string()));
        ueforge::log!("AI player UDP session ended: {:?}", result);
        result
    }).map_err(|e| e.to_string())?;
    *session = Some(Session { name: name.clone(), commands: sender, observation, worker, following: Arc::new(std::sync::atomic::AtomicBool::new(false)) });
    Ok(json!({"name":name,"state":"starting","transport":"udp","server":"127.0.0.1:7777"}))
}

fn status() -> Result<Value, String> {
    let session = SESSION.lock();
    Ok(match session.as_ref() {
        None => json!({"state":"stopped"}),
        Some(session) => json!({"name":session.name,"state":if session.worker.is_finished() { "finished" } else { "running" },
            "udp": session.observation.lock().clone()}),
    })
}

fn respawn() -> Result<Value, String> {
    let session = SESSION.lock();
    let Some(session) = session.as_ref() else { return Err("no AI player session".into()); };
    if session.worker.is_finished() { return Err("AI player session already finished".into()); }
    session.commands.send("respawn".into()).map_err(|e| e.to_string())?;
    Ok(json!({"name":session.name,"state":"respawn_requested","transport":"udp"}))
}

/// A complete path must end within this distance of the goal; the engine
/// returns a partial path when the goal is off the mesh or unreachable.
const PATH_END_TOLERANCE: f64 = 200.0;

/// Following: re-plan this often, and stand still once this close.
const FOLLOW_PERIOD: Duration = Duration::from_secs(2);
const FOLLOW_DISTANCE: f64 = 300.0;

/// The one walk planner: one game-thread job reads the AI player's start and
/// the goal and asks the host navigation mesh for the path; partial paths are
/// refused; the UDP client follows the points, or stands when already within
/// `stand_within` of the goal.
fn plan_travel(name: &str, commands: &mpsc::Sender<String>, goal: crate::nav::Goal, stand_within: f64) -> Result<Value, String> {
    let plan = crate::nav::plan(name, goal, stand_within)?;
    if plan.points.is_empty() {
        commands.send("stop".into()).map_err(|e| e.to_string())?;
        return Ok(json!({"name":name,"state":"standing","from":plan.from,"to":plan.to}));
    }
    let end = plan.points.last().expect("non-empty path");
    let short = crate::nav::flat_distance(end, &plan.to);
    if short > PATH_END_TOLERANCE {
        return Err(format!("partial path: ends {short:.0} units from the goal ({} points, last {end:?})", plan.points.len()));
    }
    let command = plan.points.iter().map(|p| format!("{},{},{}", p[0], p[1], p[2])).collect::<Vec<_>>().join(" ");
    commands.send(format!("travel {command}")).map_err(|e| e.to_string())?;
    Ok(json!({"name":name,"state":"travel_requested","from":plan.from,"to":plan.to,"points":plan.points}))
}

fn goal(args: &Value) -> Result<crate::nav::Goal, String> {
    if let Some(player) = args["to_player"].as_str().filter(|s| !s.is_empty()) {
        return Ok(crate::nav::Goal::Player(player.to_owned()));
    }
    args["to"].as_array().filter(|v| v.len() == 3)
        .map(|v| [v[0].as_f64(), v[1].as_f64(), v[2].as_f64()])
        .and_then(|v| Some(crate::nav::Goal::Point([v[0]?, v[1]?, v[2]?])))
        .ok_or("give to as [x, y, z] or to_player as a player name".into())
}

/// Walk the AI player to `to` coordinates or to `to_player`'s character.
fn travel(args: &Value) -> Result<Value, String> {
    let session = SESSION.lock();
    let Some(session) = session.as_ref() else { return Err("no AI player session".into()); };
    if session.worker.is_finished() { return Err("AI player session already finished".into()); }
    plan_travel(&session.name, &session.commands, goal(args)?, 0.0)
}

/// Follow a named player: every FOLLOW_PERIOD, walk to them while they are
/// farther than `distance`, otherwise stand still. An empty player name stops.
fn follow(args: &Value) -> Result<Value, String> {
    let target = args["player"].as_str().unwrap_or("").to_owned();
    let distance = args["distance"].as_f64().unwrap_or(FOLLOW_DISTANCE);
    let mut session = SESSION.lock();
    let Some(session) = session.as_mut() else { return Err("no AI player session".into()); };
    if session.worker.is_finished() { return Err("AI player session already finished".into()); }
    session.following.store(false, std::sync::atomic::Ordering::Relaxed);
    if target.is_empty() {
        session.commands.send("stop".into()).map_err(|e| e.to_string())?;
        return Ok(json!({"name":session.name,"following":null}));
    }
    let flag = Arc::new(std::sync::atomic::AtomicBool::new(true));
    session.following = flag.clone();
    let (name, commands) = (session.name.clone(), session.commands.clone());
    let followed = target.clone();
    let reply = json!({"name":name,"following":target,"distance":distance,"period_seconds":FOLLOW_PERIOD.as_secs()});
    std::thread::Builder::new().name("abiotic-ai-player-follow".into()).spawn(move || {
        while flag.load(std::sync::atomic::Ordering::Relaxed) {
            // Following ends with the session; a dead session must not keep scanning for its player.
            let alive = SESSION.lock().as_ref().is_some_and(|s| s.name == name && !s.worker.is_finished());
            if !alive {
                ueforge::log!("AI player {name} stopped following {followed}: session ended");
                break;
            }
            // One game-thread job per cycle: both positions and, if needed, the path.
            if let Err(error) = plan_travel(&name, &commands, crate::nav::Goal::Player(followed.clone()), distance) {
                ueforge::log!("AI player {name} following {followed}: {error}");
            }
            std::thread::sleep(FOLLOW_PERIOD);
        }
    }).map_err(|e| e.to_string())?;
    Ok(reply)
}

fn stop() -> Result<Value, String> {
    // Keep ownership locked until the old worker and its socket are gone.
    let mut session = SESSION.lock();
    let Some(old) = session.take() else { return Ok(json!({"state":"stopped"})); };
    old.following.store(false, std::sync::atomic::Ordering::Relaxed);
    if let Err(error) = old.commands.send("quit".into()) {
        ueforge::log!("AI player command receiver already closed: {error}");
    }
    let result = old.worker.join().map_err(|_| "AI player worker join failed".to_string())?;
    Ok(json!({"state":"stopped","session_error":result.err()}))
}

pub fn register() {
    // Every UDP client message lands in the mod log, not a console nobody sees.
    abioticfactor_client::set_log_sink(|message| ueforge::log!("ai_player udp: {message}"));
    ueforge::shutdown::SHUTDOWN_REGISTRY.register(ueforge::shutdown::ShutdownHandlerDef {
        name: "ai_player::stop", order: 50, run: || {
            SHUTTING_DOWN.store(true, std::sync::atomic::Ordering::Relaxed);
            if let Err(error) = stop() { ueforge::log!("AI player shutdown: {error}"); }
        },
    });
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.start", "Start an AI player's UDP join and spawn session", "{profile_dir: str}", start),
        ueforge::ops::OpDef::new("ai_player.status", "Read the AI player's last UDP session observation", "{}", |_| status()),
        ueforge::ops::OpDef::new("ai_player.respawn", "Send the AI player's UDP respawn request at a player start", "{}", |_| respawn()),
        ueforge::ops::OpDef::new("ai_player.travel", "Walk the AI player over the host's navigation mesh to coordinates or to another player, moving over UDP", "{to?: [x, y, z], to_player?: str}", travel),
        ueforge::ops::OpDef::new("ai_player.follow", "Follow a named player: re-plan the walk every two seconds while farther than distance; empty player stops", "{player: str, distance?: f64}", follow),
        ueforge::ops::OpDef::new("ai_player.stop", "Send UDP logout and join the AI player worker", "{}", |_| stop()),
        ueforge::ops::OpDef::new("ai_player.verbose", "Log every UDP position update (off by default)", "{on: bool}", |args| {
            let on = args["on"].as_bool().ok_or("on must be true or false")?;
            abioticfactor_client::set_verbose(on);
            Ok(json!({"verbose": on}))
        }),
    ]);
}
