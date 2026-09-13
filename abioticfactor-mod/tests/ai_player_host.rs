//! Permanent controls for mod-owned UDP AI players. Sophia is the first instance.
use modforge::client::Api;
use serde_json::{Value, json};
use std::time::{Duration, Instant};

fn api() -> Api<Value> {
    Api::at(31260, "/debug").with_timeout(Duration::from_secs(10))
}

#[test]
#[ignore = "starts Sophia once through the installed host mod; leaves her connected for user verification"]
fn ai_player_joins_from_host_mod() {
    let api = api();
    let before = api.op("ai_player.status", json!({}));
    assert!(before.ok, "status: {:?}", before.error);
    assert_eq!(before.result["state"], "stopped", "do not replace an existing session");
    let profile_dir = abioticfactor_client::profile::directory().expect("Sophia instance profile");
    let started = api.op("ai_player.start", json!({"profile_dir":profile_dir}));
    assert!(started.ok, "start: {:?}", started.error);
    let deadline = Instant::now() + Duration::from_secs(45);
    loop {
        let status = api.op("ai_player.status", json!({}));
        assert!(status.ok, "status: {:?}", status.error);
        assert_ne!(status.result["state"], "finished", "UDP session exited: {}", status.result);
        if status.result["udp"]["possession_confirmed"] == true {
            println!("Mod-owned UDP possession confirmed; user verifies spawn: {}", status.result);
            return;
        }
        assert!(Instant::now() < deadline, "no possession confirmation: {}", status.result);
        std::thread::sleep(Duration::from_millis(500));
    }
}

#[test]
#[ignore = "reads the installed mod's Sophia UDP status"]
fn ai_player_host_status() {
    let status = api().op("ai_player.status", json!({}));
    assert!(status.ok, "status: {:?}", status.error);
    println!("{}", status.result);
}

#[test]
#[ignore = "sends Sophia's UDP respawn request through the installed host mod; user verifies her new body"]
fn ai_player_host_respawn() {
    let api = api();
    let before = api.op("ai_player.status", json!({}));
    assert!(before.ok, "status: {:?}", before.error);
    assert_eq!(before.result["state"], "running", "needs a running session: {}", before.result);
    let requested = api.op("ai_player.respawn", json!({}));
    assert!(requested.ok, "respawn: {:?}", requested.error);
    assert_eq!(requested.result["state"], "respawn_requested");
    let deadline = Instant::now() + Duration::from_secs(20);
    loop {
        let status = api.op("ai_player.status", json!({}));
        assert!(status.ok, "status: {:?}", status.error);
        assert_ne!(status.result["state"], "finished", "UDP session exited after respawn request: {}", status.result);
        let changed = status.result["udp"]["pawn"] != before.result["udp"]["pawn"]
            || status.result["udp"]["position"] != before.result["udp"]["position"];
        if changed || Instant::now() >= deadline {
            println!("before: {}\nafter: {}\nobserved pawn/position change: {changed}", before.result, status.result);
            return;
        }
        std::thread::sleep(Duration::from_millis(500));
    }
}

#[test]
#[ignore = "stops Sophia's mod-owned UDP session and waits for its worker"]
fn ai_player_host_stop() {
    let stopped = api().op("ai_player.stop", json!({}));
    assert!(stopped.ok, "stop: {:?}", stopped.error);
    assert_eq!(stopped.result["state"], "stopped");
    println!("{}", stopped.result);
}
