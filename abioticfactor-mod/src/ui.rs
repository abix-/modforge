//! The AI players tab in the mod's in-game window: buttons for what the
//! human wants on demand (join, respawn, follow me, stop, eyes, explore,
//! memory, leave) for the named character, and the last reply. Every
//! button dispatches the same op the tests use; nothing here has a second
//! implementation. The window renders on UE4SS's render thread, and every
//! op waits for the game thread, so a button starts the op on its own
//! thread and the tab shows the reply when it lands.
use parking_lot::Mutex;
use serde_json::{Value, json};
use ueforge::ui;

/// The last op started from the tab and its reply, for the status line.
static LAST: Mutex<(String, String)> = Mutex::new((String::new(), String::new()));

/// The character the buttons act on. Sophia first; more names as they join.
const PLAYER: &str = crate::ai_player::DEFAULT_NAME;

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

pub fn render() {
    ui::text(&format!("AI player: {PLAYER}"));
    ui::separator();
    if ui::button("Join") { run("ai_player.start", json!({"name": PLAYER})); }
    ui::same_line();
    if ui::button("Respawn") { run("ai_player.respawn", json!({"player": PLAYER})); }
    ui::same_line();
    if ui::button("Memory") { run("ai_player.memory", json!({"player": PLAYER})); }
    ui::same_line();
    if ui::button("Leave") { run("ai_player.stop", json!({"player": PLAYER})); }
    ui::separator();
    ueforge::ui_ai_orders::render(&crate::orders::snapshot(), |args| run("ai_player.command", args));
    let (op, reply) = LAST.lock().clone();
    if !op.is_empty() {
        ui::text_disabled(&op);
        ui::text(&reply.chars().take(600).collect::<String>());
    }
}
