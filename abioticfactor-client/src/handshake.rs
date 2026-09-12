//! UE stateless handshake versions 3 and 4. Wire field order is documented in
//! abioticfactor-mod/docs/lan-transport.md; game admission is a later control-channel exchange.

use std::io::{self, ErrorKind};
use std::net::{SocketAddr, UdpSocket};
use std::time::{Duration, Instant};

use crate::bits::{Reader, Writer, invalid};

const RETRY: Duration = Duration::from_millis(500);
const COOKIE_SIZE: usize = 20;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
#[repr(u8)]
enum Kind {
    Initial = 0,
    Challenge = 1,
    Response = 2,
    Ack = 3,
    VersionUpgrade = 6,
}

// Deliberately omit Debug: the server's cookie must never enter diagnostics.
#[derive(Clone)]
struct Packet {
    session: u8,
    client: u8,
    version: u8,
    kind: Kind,
    count: u8,
    network_version: u32,
    features: u16,
    secret: u8,
    timestamp: u64,
    cookie: [u8; COOKIE_SIZE],
}

impl Packet {
    fn initial(network_version: u32) -> Self {
        Self {
            session: 0,
            client: 0,
            version: 4,
            kind: Kind::Initial,
            count: 0,
            network_version,
            features: 0,
            secret: 0,
            timestamp: 0,
            cookie: [0; COOKIE_SIZE],
        }
    }

    fn encode(&self) -> Vec<u8> {
        let mut writer = Writer::default();
        writer.put(u64::from(self.session), 2);
        writer.put(u64::from(self.client), 3);
        writer.put(1, 1);
        writer.put(0, 1);
        writer.bytes(&[3, self.version, self.kind as u8, self.count]);
        writer.put(u64::from(self.network_version), 32);
        writer.put(u64::from(self.features), 16);
        writer.put(u64::from(self.secret), 1);
        writer.put(self.timestamp, 64);
        writer.bytes(&self.cookie);
        let mut padding = [0; 16];
        fastrand::fill(&mut padding);
        writer.bytes(&padding);
        writer.finish()
    }

    fn decode(bytes: &[u8]) -> io::Result<Self> {
        let mut reader = Reader::packet(bytes)?;
        let session = reader.get(2)? as u8;
        let client = reader.get(3)? as u8;
        if reader.get(1)? != 1 || reader.get(1)? != 0 {
            return Err(invalid("expected a non-restart handshake packet"));
        }
        let min = reader.get(8)?;
        let version = reader.get(8)? as u8;
        if min > 4 || !(3..=4).contains(&version) || min > u64::from(version) {
            return Err(invalid("unsupported handshake version"));
        }
        let kind = match reader.get(8)? {
            0 => Kind::Initial,
            1 => Kind::Challenge,
            2 => Kind::Response,
            3 => Kind::Ack,
            6 => Kind::VersionUpgrade,
            _ => return Err(invalid("unsupported handshake packet type")),
        };
        let count = reader.get(8)? as u8;
        let network_version = reader.get(32)? as u32;
        let features = reader.get(16)? as u16;
        if kind == Kind::VersionUpgrade {
            return Err(invalid(&format!(
                "server requires network version {network_version}, runtime features {features}"
            )));
        }
        let secret = reader.get(1)? as u8;
        let timestamp = reader.get(64)?;
        let mut cookie = [0; COOKIE_SIZE];
        for byte in &mut cookie {
            *byte = reader.get(8)? as u8;
        }
        if !(64..=128).contains(&reader.remaining()) || !reader.remaining().is_multiple_of(8) {
            return Err(invalid("invalid handshake padding length"));
        }
        Ok(Self {
            session,
            client,
            version,
            kind,
            count,
            network_version,
            features,
            secret,
            timestamp,
            cookie,
        })
    }
}

#[derive(Debug)]
pub struct Connected {
    pub session: u8,
    pub client: u8,
    pub network_version: u32,
    pub server_sequence: u16,
    pub client_sequence: u16,
}

/// Bind one socket and keep its source port for the entire client lifetime.
pub fn socket(server: SocketAddr) -> io::Result<UdpSocket> {
    let socket = UdpSocket::bind(if server.is_ipv4() {
        "0.0.0.0:0"
    } else {
        "[::]:0"
    })?;
    socket.connect(server)?;
    Ok(socket)
}

/// Exchange Initial -> Challenge -> Response -> Ack on the caller's socket.
/// This proves UDP transport acceptance, not login or a spawned player.
pub fn connect(
    socket: &UdpSocket,
    network_version: u32,
    timeout: Duration,
) -> io::Result<Connected> {
    if timeout.is_zero() {
        return Err(io::Error::new(
            ErrorKind::InvalidInput,
            "timeout must be positive",
        ));
    }
    let started = Instant::now();
    let mut pending = Packet::initial(network_version);
    let mut challenge: Option<Packet> = None;
    let mut buffer = [0; 2048];
    let mut next_send = Instant::now();
    while started.elapsed() < timeout {
        if Instant::now() >= next_send {
            socket.send(&pending.encode())?;
            pending.count = pending.count.wrapping_add(1);
            next_send = Instant::now() + RETRY;
        }
        let remaining = timeout.saturating_sub(started.elapsed());
        if remaining.is_zero() {
            break;
        }
        socket.set_read_timeout(Some(
            remaining
                .min(next_send.saturating_duration_since(Instant::now()))
                .max(Duration::from_millis(1)),
        ))?;
        let size = match socket.recv(&mut buffer) {
            Ok(size) => size,
            Err(error) if matches!(error.kind(), ErrorKind::WouldBlock | ErrorKind::TimedOut) => {
                continue;
            }
            Err(error) => return Err(error),
        };
        let packet = Packet::decode(&buffer[..size])?;
        match packet.kind {
            Kind::Challenge => {
                let timestamp = f64::from_bits(packet.timestamp);
                if !timestamp.is_finite() || timestamp <= 0.0 {
                    return Err(invalid("invalid challenge timestamp"));
                }
                if packet.features != 0 {
                    return Err(invalid("server requires unsupported runtime features"));
                }
                if packet.network_version != network_version {
                    return Err(invalid(&format!(
                        "server network version is {}, client is {network_version}",
                        packet.network_version
                    )));
                }
                pending = packet.clone();
                pending.kind = Kind::Response;
                challenge = Some(packet);
                next_send = Instant::now();
            }
            Kind::Ack => {
                let Some(expected) = challenge.as_ref() else {
                    return Err(invalid("handshake ack arrived before challenge"));
                };
                if packet.cookie != expected.cookie
                    || packet.session != expected.session
                    || packet.client != expected.client
                    || packet.version != expected.version
                    || packet.network_version != network_version
                    || packet.features != expected.features
                    || f64::from_bits(packet.timestamp) != -1.0
                {
                    return Err(invalid("handshake ack does not match challenge"));
                }
                return Ok(Connected {
                    session: packet.session,
                    client: packet.client,
                    network_version,
                    server_sequence: u16::from_le_bytes([packet.cookie[0], packet.cookie[1]])
                        & 0x3fff,
                    client_sequence: u16::from_le_bytes([packet.cookie[2], packet.cookie[3]])
                        & 0x3fff,
                });
            }
            _ => return Err(invalid("unexpected handshake message from server")),
        }
    }
    Err(io::Error::new(
        ErrorKind::TimedOut,
        "UDP handshake timed out before a valid acknowledgement",
    ))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn packet_layout_and_truncation() {
        let bytes = Packet::initial(0x12345678).encode();
        // First 88 bits, independently calculated from the documented field order.
        assert_eq!(
            &bytes[..11],
            &[0xa0, 0x01, 0x02, 0, 0, 0x3c, 0x2b, 0x1a, 0x09, 0, 0]
        );
        assert_eq!(bytes.len(), 56);
        for len in 0..47 {
            assert!(
                Packet::decode(&bytes[..len]).is_err(),
                "accepted truncation at {len}"
            );
        }
        assert_eq!(Packet::decode(&bytes).unwrap().network_version, 0x12345678);
    }

    #[test]
    fn udp_handshake_retries_and_retains_source_port() {
        let server = UdpSocket::bind("127.0.0.1:0").unwrap();
        server
            .set_read_timeout(Some(Duration::from_secs(3)))
            .unwrap();
        let client = socket(server.local_addr().unwrap()).unwrap();
        let worker = std::thread::spawn(move || {
            let mut bytes = [0; 2048];
            let (_, first) = server.recv_from(&mut bytes).unwrap(); // drop Initial
            let (size, address) = server.recv_from(&mut bytes).unwrap();
            assert_eq!(first, address);
            let initial = Packet::decode(&bytes[..size]).unwrap();
            assert_eq!(initial.kind, Kind::Initial);
            let mut challenge = initial;
            challenge.kind = Kind::Challenge;
            challenge.session = 2;
            challenge.timestamp = 12.5f64.to_bits();
            challenge.cookie = [42; COOKIE_SIZE];
            server.send_to(&challenge.encode(), address).unwrap();
            let (size, address2) = server.recv_from(&mut bytes).unwrap();
            assert_eq!(address, address2);
            let response = Packet::decode(&bytes[..size]).unwrap();
            assert_eq!(response.kind, Kind::Response);
            assert!(response.cookie == challenge.cookie);
            assert_eq!(response.timestamp, challenge.timestamp);
            challenge.kind = Kind::Ack;
            challenge.timestamp = (-1.0f64).to_bits();
            server.send_to(&challenge.encode(), address).unwrap();
        });
        let result = connect(&client, 123, Duration::from_secs(3));
        worker.join().unwrap();
        let connected = result.unwrap();
        assert_eq!(connected.session, 2);
        assert_eq!(connected.server_sequence, 0x2a2a);
    }

    #[test]
    fn unsolicited_ack_is_not_connection_success() {
        let server = UdpSocket::bind("127.0.0.1:0").unwrap();
        server
            .set_read_timeout(Some(Duration::from_secs(2)))
            .unwrap();
        let client = socket(server.local_addr().unwrap()).unwrap();
        let worker = std::thread::spawn(move || {
            let mut bytes = [0; 2048];
            let (_, address) = server.recv_from(&mut bytes).unwrap();
            let mut ack = Packet::initial(123);
            ack.kind = Kind::Ack;
            ack.timestamp = (-1.0f64).to_bits();
            server.send_to(&ack.encode(), address).unwrap();
        });
        let error = connect(&client, 123, Duration::from_secs(2)).unwrap_err();
        worker.join().unwrap();
        assert_eq!(error.kind(), ErrorKind::InvalidData);
        assert!(error.to_string().contains("before challenge"));
    }

    #[test]
    fn unrelated_ack_cannot_finish_a_handshake() {
        let server = UdpSocket::bind("127.0.0.1:0").unwrap();
        server
            .set_read_timeout(Some(Duration::from_secs(2)))
            .unwrap();
        let client = socket(server.local_addr().unwrap()).unwrap();
        let worker = std::thread::spawn(move || {
            let mut bytes = [0; 2048];
            let (_, address) = server.recv_from(&mut bytes).unwrap();
            let mut challenge = Packet::initial(123);
            challenge.kind = Kind::Challenge;
            challenge.timestamp = 1.0f64.to_bits();
            challenge.cookie = [17; COOKIE_SIZE];
            server.send_to(&challenge.encode(), address).unwrap();
            server.recv_from(&mut bytes).unwrap();
            challenge.kind = Kind::Ack;
            challenge.timestamp = (-1.0f64).to_bits();
            challenge.cookie[0] ^= 1;
            server.send_to(&challenge.encode(), address).unwrap();
        });
        let error = connect(&client, 123, Duration::from_secs(2)).unwrap_err();
        worker.join().unwrap();
        assert!(error.to_string().contains("does not match challenge"));
    }

    #[test]
    fn silent_server_has_a_bounded_deadline() {
        let server = UdpSocket::bind("127.0.0.1:0").unwrap();
        let client = socket(server.local_addr().unwrap()).unwrap();
        let started = Instant::now();
        let error = connect(&client, 123, Duration::from_millis(100)).unwrap_err();
        assert_eq!(error.kind(), ErrorKind::TimedOut);
        assert!(started.elapsed() < Duration::from_secs(2));
    }
}
