use abioticfactor_client::handshake;
use std::time::Duration;

#[test]
#[ignore = "checks local server log for Sophia logout without printing login data"]
fn sophia_previous_session_logged_out() {
    let local = std::env::var_os("LOCALAPPDATA").expect("LOCALAPPDATA");
    let path = std::path::PathBuf::from(local).join("AbioticFactor/Saved/Logs/AbioticFactor.log");
    let log = std::fs::read_to_string(path).expect("read game log");
    let joined = log.rfind("CHAT LOG:  Sophia has entered the facility.").expect("Sophia join record");
    let left = log.rfind("CHAT LOG:  Sophia has exited the facility.");
    assert!(left.is_some_and(|left| left > joined), "server has not yet logged Sophia leaving");
    println!("Server recorded Sophia leaving after her latest join.");
}

#[test]
#[ignore = "requires Abiotic Factor hosting a LAN game on UDP 7777"]
fn abiotic_accepts_udp_handshake() {
    let server = std::env::var("ABIOTIC_SERVER").unwrap_or_else(|_| "127.0.0.1:7777".into());
    let version = std::env::var("ABIOTIC_NETWORK_VERSION")
        .unwrap_or_else(|_| abioticfactor_client::NETWORK_VERSION.to_string())
        .parse()
        .expect("ABIOTIC_NETWORK_VERSION must be a u32");
    let socket =
        handshake::socket(server.parse().expect("server address")).expect("bind UDP client");
    let connected = handshake::connect(&socket, version, Duration::from_secs(5))
        .expect("Abiotic must return a valid challenge and matching acknowledgement");
    println!(
        "UDP handshake accepted: session {}, client {}, network version {}",
        connected.session, connected.client, connected.network_version
    );
}

#[test]
#[ignore = "requires Abiotic Factor hosting a LAN game on UDP 7777"]
fn abiotic_accepts_login_and_join() {
    let server = std::env::var("ABIOTIC_SERVER").unwrap_or_else(|_| "127.0.0.1:7777".into());
    let version = std::env::var("ABIOTIC_NETWORK_VERSION")
        .unwrap_or_else(|_| abioticfactor_client::NETWORK_VERSION.to_string())
        .parse()
        .expect("network version");
    let socket =
        handshake::socket(server.parse().expect("server address")).expect("bind UDP client");
    let connected =
        handshake::connect(&socket, version, Duration::from_secs(5)).expect("UDP handshake");
    // A synthetic bot identifier for this private LAN test, not an authenticated account.
    let player_id = abioticfactor_client::identity::PlayerId::new("6d6f64666f7267654149506c61796572").unwrap();
    let progress =
        abioticfactor_client::login::run(&socket, connected, "AIPlayer", player_id, Duration::from_secs(30))
            .expect("Abiotic must welcome and acknowledge the joining client");
    println!("Login progress: {progress:?}");
    assert!(progress.welcomed && progress.join_acknowledged);
    assert!(
        progress.actor_bunches > 0,
        "server must start replication after join"
    );
}

#[test]
#[ignore = "reads local Abiotic log event counts; never emits raw log lines"]
fn abiotic_login_log_events() {
    let local = std::env::var_os("LOCALAPPDATA").expect("LOCALAPPDATA");
    let path = std::path::PathBuf::from(local).join("AbioticFactor/Saved/Logs/AbioticFactor.log");
    let log = std::fs::read_to_string(path).expect("read game log");
    for line in log.lines() {
        for prefix in ["Created online subsystem instance for: ", "Loaded subsystem for module ["] {
            if let Some((_, value)) = line.split_once(prefix) {
                for name in ["EOSPlus", "EOS", "STEAM", "NULL"] {
                    if value.trim_start().starts_with(name) {
                        println!("online subsystem event: {name}");
                        break;
                    }
                }
            }
        }
    }
    // Counts only: network logs may contain cookies, account IDs and login URLs.
    for marker in [
        "Login request",
        "Join request",
        "NotifyAcceptingChannel",
        "NotifyAcceptedConnection",
        "AddClientConnection",
        "Login failed",
        "PreLogin",
        "incompatible_unique_net_id",
        "Join_PasswordInvalid",
        "BannedFromServer",
        "ServerFull",
        "InvalidId",
        "Password",
        "password",
        "NMT_Login",
        "Bunch",
        "Auth",
        "LogNetVersion:",
    ] {
        println!(
            "{marker}: {}",
            log.lines().filter(|line| line.contains(marker)).count()
        );
    }
}
