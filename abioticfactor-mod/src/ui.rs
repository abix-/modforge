//! The Sophia tab in the mod's in-game window: buttons for what the human
//! wants on demand (join, respawn, follow me, stop, eyes, attack) and the
//! last reply. Every button dispatches the same op the tests use; nothing
//! here has a second implementation. The window renders on UE4SS's render
//! thread, and every op waits for the game thread, so a button starts the
//! op on its own thread and the tab shows the reply when it lands.
use parking_lot::Mutex;
use serde_json::{Value, json};
use ueforge::ui;

/// The last op started from the tab and its reply, for the status line.
static LAST: Mutex<(String, String)> = Mutex::new((String::new(), String::new()));

fn run(op: &'static str, args: Value) {
    *LAST.lock() = (op.to_owned(), "...".into());
    std::thread::Builder::new().name("abiotic-ui-op".into()).spawn(move || {
        let reply = match ueforge::ops::OP_REGISTRY.dispatch(op, &args) {
            Some(Ok(value)) => value.to_string(),
            Some(Err(error)) => format!("error: {error}"),
            None => format!("unknown op {op}"),
        };
        *LAST.lock() = (op.to_owned(), reply);
    }).ok();
}

/// The human player's name, the one that is not the AI player, from the players op.
fn human() -> Option<String> {
    let reply = ueforge::ops::OP_REGISTRY.dispatch("players", &json!({}))?.ok()?;
    reply["players"].as_array()?.iter().find(|p| p["name"] != "Sophia")?["name"].as_str().map(str::to_owned)
}

pub fn render() {
    ui::text("Sophia");
    ui::separator();
    if ui::button("Join") {
        match abioticfactor_client::profile::directory() {
            Ok(directory) => run("ai_player.start", json!({"profile_dir": directory.to_string_lossy()})),
            Err(error) => *LAST.lock() = ("ai_player.start".into(), format!("error: {error}")),
        }
    }
    ui::same_line();
    if ui::button("Respawn") { run("ai_player.respawn", json!({})); }
    ui::same_line();
    if ui::button("Follow me") {
        // The players op reads the game thread; resolve the name on the op thread, not here.
        std::thread::Builder::new().name("abiotic-ui-follow".into()).spawn(|| {
            match human() {
                Some(name) => run("ai_player.follow", json!({"player": name})),
                None => *LAST.lock() = ("ai_player.follow".into(), "error: no human player found".into()),
            }
        }).ok();
    }
    ui::same_line();
    if ui::button("Stop following") { run("ai_player.follow", json!({"player": ""})); }
    if ui::button("Eyes") { run("ai_player.perceive", json!({"player": "Sophia"})); }
    ui::same_line();
    if ui::button("What she sees") { run("ai_player.perceived", json!({"player": "Sophia"})); }
    ui::same_line();
    if ui::button("Explore") { run("ai_player.explore", json!({"on": true})); }
    ui::same_line();
    if ui::button("Stop exploring") { run("ai_player.explore", json!({"on": false})); }
    ui::same_line();
    if ui::button("Memory") { run("ai_player.memory", json!({})); }
    ui::same_line();
    if ui::button("Leave") { run("ai_player.stop", json!({})); }
    ui::separator();
    let (op, reply) = LAST.lock().clone();
    if !op.is_empty() {
        ui::text_disabled(&op);
        ui::text(&reply.chars().take(600).collect::<String>());
    }
}
