use std::io;
use std::net::SocketAddr;
use std::time::Duration;

use abioticfactor_client::handshake;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<_> = std::env::args().skip(1).collect();
    if args.first().is_some_and(|arg| arg == "sophia") && args.len() <= 3 {
        let directory = abioticfactor_client::profile::directory()?;
        let profile = abioticfactor_client::profile::Profile::load_or_create(&directory)?;
        let memories = abioticfactor_client::profile::recall(&directory)?;
        println!("{} remembers {} recorded events.", profile.name, memories.len());
        let server: SocketAddr = args.get(1).map_or("127.0.0.1:7777", String::as_str).parse()?;
        let duration = args.get(2).map(|value| value.parse::<u64>().map(Duration::from_secs)).transpose()?.unwrap_or(Duration::MAX);
        let socket = handshake::socket(server)?;
        let connected = handshake::connect(&socket, abioticfactor_client::NETWORK_VERSION, Duration::from_secs(5))?;
        abioticfactor_client::profile::remember(&directory, "udp_handshake_accepted", &server.to_string())?;
        println!("{} connecting over UDP. Profile and memory: {}", profile.name, directory.display());
        let result = abioticfactor_client::login::run_profile(&socket, connected, &profile, &directory, duration);
        abioticfactor_client::profile::remember(&directory, if result.is_ok() { "session_ended" } else { "session_failed" }, &server.to_string())?;
        result?;
        return Ok(());
    }
    let handshake_only = args.len() == 3 && args[0] == "handshake";
    let join = args.len() == 6 && args[0] == "join";
    if !handshake_only && !join {
        return Err(io::Error::new(
            io::ErrorKind::InvalidInput,
            "usage: abioticfactor-client sophia [ip:port] [seconds] OR handshake <ip:port> <network-version> OR join <ip:port> <network-version> <name> <seconds> <bot-id-32hex>",
        )
        .into());
    }
    let server: SocketAddr = args[1].parse()?;
    let version = args[2].parse()?;
    let socket = handshake::socket(server)?;
    let connected = handshake::connect(&socket, version, Duration::from_secs(5))?;
    println!(
        "UDP handshake accepted by {server}: session {}, client {}.",
        connected.session, connected.client
    );
    if join {
        let duration = Duration::from_secs(args[4].parse()?);
        let player_id = abioticfactor_client::identity::PlayerId::new(&args[5])?;
        let progress = abioticfactor_client::login::run(&socket, connected, &args[3], player_id, duration)?;
        println!("UDP session ended: {progress:?}.");
    }
    Ok(())
}
