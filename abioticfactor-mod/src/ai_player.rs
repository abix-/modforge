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
    *session = Some(Session { name: name.clone(), commands: sender, observation, worker });
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

fn stop() -> Result<Value, String> {
    // Keep ownership locked until the old worker and its socket are gone.
    let mut session = SESSION.lock();
    let Some(old) = session.take() else { return Ok(json!({"state":"stopped"})); };
    if let Err(error) = old.commands.send("quit".into()) {
        ueforge::log!("AI player command receiver already closed: {error}");
    }
    let result = old.worker.join().map_err(|_| "AI player worker join failed".to_string())?;
    Ok(json!({"state":"stopped","session_error":result.err()}))
}

pub fn register() {
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
        ueforge::ops::OpDef::new("ai_player.stop", "Send UDP logout and join the AI player worker", "{}", |_| stop()),
    ]);
}
