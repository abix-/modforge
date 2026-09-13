//! Reliable control-channel exchange over the socket established by the handshake.

use crate::bits::{Reader, Writer, invalid};
use crate::handshake::Connected;
use crate::identity::PlayerId;
use std::collections::{BTreeMap, BTreeSet, VecDeque};
use std::io::{self, ErrorKind};
use std::net::UdpSocket;
use std::time::{Duration, Instant};

const PACKET_MASK: u16 = 16383;
const CHANNEL_MASK: u16 = 1023;
const CONTROL_NAME: u32 = 255;
const RETRY: Duration = Duration::from_millis(500);

#[derive(Debug, Default)]
pub struct Progress {
    pub challenged: bool,
    pub welcomed: bool,
    pub join_acknowledged: bool,
    pub actor_bunches: usize,
    pub acknowledged_control_messages: usize,
}

struct Pending {
    channel: u32,
    sequence: u16,
    payload: Writer,
    open: bool,
    join: bool,
    packets: VecDeque<u16>,
    sent: Option<Instant>,
}

struct Connection {
    ids: Connected,
    out_packet: u16,
    in_packet: u16,
    history: [u32; 8],
    out_control: u16,
    out_actor: BTreeMap<u32, u16>,
    in_control: u16,
    pending: VecDeque<Pending>,
    reordered: BTreeMap<u16, Writer>,
    actor_channels: BTreeSet<u32>,
    objects: crate::actors::Objects,
    actor_state: BTreeMap<u32, crate::actors::Channel>,
    controller: crate::actors::Controller,
    spawned: BTreeSet<u32>,
    channel_objects: BTreeMap<u32, u32>,
    progress: Progress,
    player_name: String,
    player_id: PlayerId,
    world: String,
    female: bool,
    customized: bool,
    memory: Option<std::path::PathBuf>,
    remembered: u8,
    commands: Option<std::sync::mpsc::Receiver<String>>,
    status: Option<std::sync::Arc<parking_lot::Mutex<SessionStatus>>>,
    movement_started: Option<Instant>,
    next_move: Instant,
    spawn_positions: BTreeMap<u32, [f64; 3]>,
    location_map: Option<crate::location::LocationMap>,
    reported_position: Option<[f64; 3]>,
    travel: Option<crate::travel::Travel>,
    travel_status: Option<String>,
    /// Receives that Windows reported as still pending instead of timed out.
    pending_receives: u64,
    started: Instant,
}

/// Windows ERROR_IO_PENDING, raised by a short socket read timeout on some setups.
const ERROR_IO_PENDING: i32 = 997;

impl Connection {
    fn new(ids: Connected, name: &str, player_id: PlayerId) -> Self {
        Self {
            out_packet: ids.client_sequence,
            in_packet: ids.server_sequence.wrapping_sub(1) & PACKET_MASK,
            out_control: ids.client_sequence & CHANNEL_MASK,
            out_actor: BTreeMap::new(),
            in_control: ids.server_sequence & CHANNEL_MASK,
            ids,
            history: [0; 8],
            pending: VecDeque::new(),
            reordered: BTreeMap::new(),
            actor_channels: BTreeSet::new(),
            objects: crate::actors::Objects::default(),
            actor_state: BTreeMap::new(),
            controller: crate::actors::Controller::default(),
            spawned: BTreeSet::new(),
            channel_objects: BTreeMap::new(),
            progress: Progress::default(),
            player_name: name.into(),
            player_id,
            world: String::new(),
            female: false,
            customized: false,
            memory: None,
            remembered: 0,
            commands: None,
            status: None,
            movement_started: None,
            next_move: Instant::now(),
            spawn_positions: BTreeMap::new(),
            location_map: None,
            reported_position: None,
            travel: None,
            travel_status: None,
            pending_receives: 0,
            started: Instant::now(),
        }
    }

    /// One line of session state for error messages.
    fn describe(&self) -> String {
        format!("{}s in, welcomed {}, possessed {}, pawn {}, position {:?}, travel {:?}, forward input {}, pending {}, unsent {}",
            self.started.elapsed().as_secs(), self.progress.welcomed, self.controller.initialized, self.controller.pawn,
            self.controller.position, self.travel_status, self.movement_started.is_some(), self.pending.len(),
            self.pending.iter().filter(|p| p.sent.is_none()).count())
    }

    /// Send one datagram; a failure is logged with the session state before it propagates.
    fn transmit(&self, socket: &UdpSocket, bytes: &[u8]) -> io::Result<()> {
        socket.send(bytes).map(|_| ()).map_err(|error| {
            crate::log!("send of {} bytes failed: {error} (kind {:?}, os error {:?}) while {}", bytes.len(), error.kind(), error.raw_os_error(), self.describe());
            error
        })
    }

    fn location(&self) -> io::Result<crate::location::Location> {
        let position = self.controller.position.ok_or_else(|| io::Error::other("no UDP position received yet"))?;
        self.location_map.as_ref().ok_or_else(|| io::Error::other("local map data unavailable"))?
            .locate(&self.world, position)
    }

    fn report_location(&self) {
        match self.location() {
            Ok(location) => crate::log!("last received UDP location: {location} ({})", self.controller.position_source),
            Err(error) => crate::log!("location unavailable: {error}"),
        }
    }

    fn queue(&mut self, payload: Writer, open: bool, join: bool) {
        self.out_control = self.out_control.wrapping_add(1) & CHANNEL_MASK;
        self.pending.push_back(Pending {
            channel: 0,
            sequence: self.out_control,
            payload,
            open,
            join,
            packets: VecDeque::new(),
            sent: None,
        });
    }

    fn header(&mut self) -> Writer {
        let mut packet = Writer::default();
        packet.put(u64::from(self.ids.session), 2);
        packet.put(u64::from(self.ids.client), 3);
        packet.put(0, 1);
        let header = (u32::from(self.out_packet) << 18) | (u32::from(self.in_packet) << 4) | 7;
        packet.put(u64::from(header), 32);
        for word in self.history {
            packet.put(u64::from(word), 32);
        }
        packet.put(0, 1); // No optional jitter/frame-time information.
        self.out_packet = self.out_packet.wrapping_add(1) & PACKET_MASK;
        packet
    }

    fn rpc(&mut self, channel: u32, field: u32, args: Writer) {
        // Shipped controller and player-character network cache bounds.
        let mut fields = Writer::default();
        fields.bounded(field, if self.controller.channel == Some(channel) { 169 } else { 310 });
        fields.packed(args.len() as u32);
        fields.append(&args);
        let mut payload = Writer::default();
        payload.put(0, 1);
        payload.put(1, 1);
        payload.packed(fields.len() as u32);
        payload.append(&fields);
        let sequence = self.out_actor.entry(channel).or_insert(self.ids.client_sequence & CHANNEL_MASK);
        *sequence = sequence.wrapping_add(1) & CHANNEL_MASK;
        self.pending.push_back(Pending { channel, sequence: *sequence, payload, open: false,
            join: false, packets: VecDeque::new(), sent: None });
    }

    fn send(&mut self, socket: &UdpSocket, force_ack: bool) -> io::Result<()> {
        let mut sent_any = false;
        for index in 0..self.pending.len() {
            if self.pending[index]
                .sent
                .is_some_and(|sent| sent.elapsed() < RETRY)
            {
                continue;
            }
            let packet_id = self.out_packet;
            let mut packet = self.header();
            let pending = &mut self.pending[index];
            packet.put(u64::from(pending.open), 1);
            if pending.open {
                packet.put(1, 1);
                packet.put(0, 1);
            }
            packet.put(0, 1); // replication paused
            packet.put(1, 1); // reliable
            packet.packed(pending.channel);
            packet.put(0, 3); // exports, must-map, partial
            packet.put(u64::from(pending.sequence), 10);
            packet.put(1, 1); // hardcoded channel name
            packet.packed(if pending.channel == 0 { CONTROL_NAME } else { 102 });
            packet.put(pending.payload.len() as u64, 13);
            packet.append(&pending.payload);
            packet.put(1, 1); // inner termination
            let bytes = packet.finish();
            self.transmit(socket, &bytes)?;
            let pending = &mut self.pending[index];
            pending.packets.push_back(packet_id);
            if pending.packets.len() > 256 {
                pending.packets.pop_front();
            }
            pending.sent = Some(Instant::now());
            sent_any = true;
        }
        if force_ack && !sent_any {
            let mut packet = self.header();
            packet.put(1, 1);
            let bytes = packet.finish();
            self.transmit(socket, &bytes)?;
        }
        Ok(())
    }

    fn pawn_channel(&self, purpose: &str) -> io::Result<u32> {
        self.channel_objects.iter().find(|(_, guid)| **guid == self.controller.pawn).map(|(&channel, _)| channel)
            .ok_or_else(|| invalid(&format!("{purpose} requires the possessed pawn")))
    }

    fn request_respawn(&mut self) -> io::Result<()> {
        // Decoded W_RespawnOptions player-start button: Request_RespawnPlayerCharacter(false, true, None).
        let channel = self.pawn_channel("respawn")?;
        let mut args = Writer::default();
        args.put(0, 1); // RevivedOnSpot
        args.put(1, 1); // UsePlayerStartOnly
        args.put(0, 1); // DestinationID: presence bit 0, None equals the default so no value follows
        self.rpc(channel, 258, args); // live character RPC cache: Request_RespawnPlayerCharacter
        crate::log!("requested respawn at a player start");
        Ok(())
    }

    /// Halt: drop any timed forward input or travel and send zero acceleration once.
    fn stop_movement(&mut self, socket: &UdpSocket, timestamp: f32) -> io::Result<()> {
        self.movement_started = None;
        if self.travel.take().is_some() { self.travel_status = Some("cancelled".into()); }
        self.movement_input(socket, timestamp, [0.0; 3])
    }

    /// Follow a navigation path given as `x,y,z x,y,z ...` in server coordinates.
    fn start_travel(&mut self, points: &str) -> io::Result<()> {
        if !self.controller.initialized { return Err(invalid("travel requires the possessed pawn")); }
        let travel = crate::travel::Travel::parse(points).map_err(|e| invalid(&e))?;
        crate::log!("travel started over {} path points", travel.len());
        self.movement_started = None;
        self.next_move = Instant::now();
        self.travel_status = Some("starting".into());
        self.travel = Some(travel);
        Ok(())
    }

    fn movement_input(&mut self, socket: &UdpSocket, timestamp: f32, acceleration: [f32; 3]) -> io::Result<()> {
        let channel = self.pawn_channel("movement")?;
        let (field, args) = if let Some(position) = self.controller.position {
            (38, crate::movement::report(timestamp, acceleration, position))
        } else { (39, crate::movement::input(timestamp, acceleration)) };
        let mut fields = Writer::default();
        fields.bounded(field, 310); // live Character movement RPC cache
        fields.packed(args.len() as u32);
        fields.append(&args);
        let mut payload = Writer::default();
        payload.put(0, 1);
        payload.put(1, 1);
        payload.packed(fields.len() as u32);
        payload.append(&fields);
        let mut packet = self.header();
        packet.put(0, 3); // no open/close, replication pause, or reliability
        packet.packed(channel);
        packet.put(0, 3); // no exports, must-map, or fragmentation
        packet.put(payload.len() as u64, 13);
        packet.append(&payload);
        packet.put(1, 1);
        let bytes = packet.finish();
        self.transmit(socket, &bytes)?;
        Ok(())
    }

    fn receive(&mut self, bytes: &[u8]) -> io::Result<()> {
        let mut reader = Reader::packet(bytes)?;
        if reader.get(2)? != u64::from(self.ids.session)
            || reader.get(3)? != u64::from(self.ids.client)
        {
            return Err(invalid("data packet has unexpected session/client ID"));
        }
        if reader.get(1)? != 0 {
            return Err(invalid("unexpected handshake during login"));
        }
        reader.remove_inner_stop()?;
        let header = reader.get(32)? as u32;
        let sequence = (header >> 18) as u16;
        let ack = ((header >> 4) & u32::from(PACKET_MASK)) as u16;
        let words = (header & 15) as usize + 1;
        if words > 8 {
            return Err(invalid("oversized acknowledgement history"));
        }
        let mut ack_history = [0u32; 8];
        for word in &mut ack_history[..words] {
            *word = reader.get(32)? as u32;
        }
        if reader.get(1)? != 0 {
            reader.get(10)?;
            if reader.get(1)? != 0 {
                reader.get(8)?;
            }
        }
        let delta = sequence.wrapping_sub(self.in_packet) & PACKET_MASK;
        if delta == 0 || delta >= 8192 {
            return Ok(());
        }
        // A packet cannot acknowledge a sequence we have not sent.
        let ack_age = self.out_packet.wrapping_sub(ack) & PACKET_MASK;
        if ack_age == 0 || ack_age >= 8192 {
            return Err(invalid("server acknowledged an unsent packet"));
        }
        self.pending.retain(|pending| {
            let delivered = pending.packets.iter().any(|sent| {
                let age = ack.wrapping_sub(*sent) & PACKET_MASK;
                usize::from(age) < words * 32
                    && ack_history[usize::from(age) / 32] & (1 << (age % 32)) != 0
            });
            if delivered && pending.join {
                self.progress.join_acknowledged = true;
            }
            if delivered {
                self.progress.acknowledged_control_messages += 1;
            }
            !delivered
        });
        while reader.remaining() > 0 {
            let flags = reader.get(1)? != 0;
            let open = flags && reader.get(1)? != 0;
            let close = flags && reader.get(1)? != 0;
            let close_reason = if close {
                Some(reader.bounded(15)?)
            } else {
                None
            };
            reader.get(1)?; // replication paused
            let reliable = reader.get(1)? != 0;
            let channel = reader.packed()?;
            if channel >= 16384 {
                return Err(invalid("channel index exceeds limit"));
            }
            let exports = reader.get(1)? != 0;
            let must_map = reader.get(1)? != 0;
            let partial = reader.get(1)? != 0;
            let control_sequence = if reliable { reader.get(10)? as u16 } else { 0 };
            let partial_flags = if partial {
                // Abiotic's UE 5.4 SendRawBunch writes Initial and Final only.
                // The newer UE client reference has an additional flag here.
                reader.get(2)?
            } else { 0 };
            if open || reliable {
                let actor = if reader.get(1)? != 0 {
                    reader.packed()? == 102
                } else {
                    let name = reader.string().map_err(|error| invalid(&format!("channel {channel} name: {error}")))?;
                    reader.get(32)?;
                    name == "Actor"
                };
                if actor {
                    self.actor_channels.insert(channel);
                } else {
                    self.actor_channels.remove(&channel);
                }
            }
            let length = reader.get(13)? as usize;
            let mut payload = reader.take(length)?;
            if channel == 0 {
                if exports || must_map || partial {
                    return Err(invalid(
                        "unsupported control-channel exports or fragmentation",
                    ));
                }
                if reliable {
                    let delta = control_sequence.wrapping_sub(self.in_control) & CHANNEL_MASK;
                    if delta > 0 && delta < 512 {
                        let mut saved = Writer::default();
                        while payload.remaining() > 0 {
                            saved.put(payload.get(1)?, 1);
                        }
                        self.reordered.entry(control_sequence).or_insert(saved);
                        while let Some(next) = self
                            .reordered
                            .remove(&(self.in_control.wrapping_add(1) & CHANNEL_MASK))
                        {
                            self.in_control = self.in_control.wrapping_add(1) & CHANNEL_MASK;
                            let bytes = next.finish();
                            self.control(&mut Reader::packet(&bytes)?)?;
                        }
                    }
                } else {
                    self.control(&mut payload)?;
                }
                if let Some(reason) = close_reason {
                    return Err(invalid(&format!(
                        "server closed control channel (reason {reason})"
                    )));
                }
            } else if self.actor_channels.contains(&channel) {
                self.progress.actor_bunches += 1;
                if exports { self.objects.exports(&mut payload).map_err(|error| invalid(&format!("actor {channel} exports: {error}")))?; }
                let mut saved = Writer::default();
                if !exports || !partial {
                    while payload.remaining() != 0 { saved.put(payload.get(1)?, 1); }
                }
                let bunch = crate::actors::Bunch { payload: saved, open, must_map, partial,
                    initial: partial_flags & 1 != 0, final_part: partial_flags & 2 != 0 };
                let state = self.actor_state.entry(channel).or_insert_with(||
                    crate::actors::Channel::new(self.ids.server_sequence & CHANNEL_MASK));
                let mut ready = Vec::new();
                if reliable {
                    let delta = control_sequence.wrapping_sub(state.sequence) & CHANNEL_MASK;
                    if delta > 0 && delta < 512 {
                        state.waiting.entry(control_sequence).or_insert(bunch);
                        while let Some(next) = state.waiting.remove(&(state.sequence.wrapping_add(1) & CHANNEL_MASK)) {
                            state.sequence = state.sequence.wrapping_add(1) & CHANNEL_MASK;
                            if let Some(assembled) = state.assemble(next)? { ready.push(assembled); }
                        }
                    }
                } else if !partial {
                    ready.push(bunch);
                }
                for bunch in ready {
                    let bytes = bunch.payload.clone().finish();
                    let mut actor_reader = Reader::packet(&bytes)?;
                    if bunch.open && bunch.payload.len() != 0 {
                        let (guid, archetype) = self.objects.spawn(&mut actor_reader, bunch.must_map)?;
                        self.spawned.insert(guid);
                        self.channel_objects.insert(channel, guid);
                        if archetype.contains("Abiotic_Player") {
                            crate::log!("actor channel {channel}, object {guid}, archetype {archetype}");
                        }
                        if archetype == "Default__Abiotic_PlayerController_C" {
                            self.controller.channel = Some(channel);
                            crate::actors::Objects::spawn_body(&mut actor_reader)?;
                            // APlayerController::OnActorChannelOpen reads NetPlayerIndex.
                            if actor_reader.get(8)? != 0 {
                                return Err(invalid("unexpected split-screen player controller"));
                            }
                        } else if archetype == "Default__Abiotic_PlayerCharacter_C" {
                            let position = crate::actors::Objects::spawn_body(&mut actor_reader)?;
                            self.spawn_positions.insert(guid, position);
                        }
                    } else if bunch.must_map {
                        let count = actor_reader.get(16)?;
                        for _ in 0..count { actor_reader.packed()?; }
                    }
                    if self.controller.channel == Some(channel) {
                        self.controller.receive(&mut actor_reader).map_err(|error| invalid(&format!("controller channel {channel}: {error}")))?;
                    } else if self.channel_objects.get(&channel) == Some(&self.controller.pawn) {
                        self.controller.receive_pawn(&mut actor_reader).map_err(|error| invalid(&format!("pawn channel {channel}: {error}")))?;
                    } else if !bunch.open && self.controller.traits_sent
                        && self.channel_objects.get(&channel) == Some(&self.controller.player_state) {
                        self.controller.receive_state(&mut actor_reader).map_err(|error| invalid(&format!("player-state channel {channel}: {error}")))?;
                    }
                }
            }
            if close {
                self.actor_channels.remove(&channel);
                self.actor_state.remove(&channel);
                self.channel_objects.remove(&channel);
            }
        }
        // Only acknowledge after every bunch in the packet was accepted.
        let old = self.history;
        self.history = [0; 8];
        for bit in 0..256usize {
            if bit >= usize::from(delta) {
                let from = bit - usize::from(delta);
                if old[from / 32] & (1 << (from % 32)) != 0 {
                    self.history[bit / 32] |= 1 << (bit % 32);
                }
            }
        }
        self.history[0] |= 1;
        self.in_packet = sequence;
        self.advance_character_setup();
        Ok(())
    }

    fn advance_character_setup(&mut self) {
        if self.controller.position.is_none() {
            if let Some(position) = self.spawn_positions.get(&self.controller.pawn) {
                self.controller.position = Some(*position);
                self.controller.position_source = "actor channel open";
                crate::log!("UDP position {position:?} (actor channel open)");
            }
        }
        if !self.controller.initialized && self.spawned.contains(&self.controller.player_state)
            && self.spawned.contains(&self.controller.pawn) {
            if let Some(channel) = self.controller.channel {
                let mut world = Writer::default();
                world.put(1, 1);
                world.put(0, 1);
                world.string(&self.world);
                world.put(0, 32);
                self.rpc(channel, 80, world);
                let mut pawn = Writer::default();
                pawn.put(1, 1);
                pawn.packed(self.controller.pawn);
                self.rpc(channel, 72, pawn);
                self.rpc(channel, 139, Writer::default());
                // The server's ReceivePossessed continuation initializes its
                // character references, then initiates spawn. See the decoded
                // co-op sequence in abioticfactor-mod/docs/lan-spawn.md (11720..12083).
                self.controller.initialized = true;
                crate::log!("confirmed possession and pawn replication; waiting for server spawn");
            }
        }
        if self.controller.trait_selection_requested {
            if let Some(channel) = self.controller.channel {
                let mut traits = Writer::default();
                traits.put(1, 1); // PhDTrait present
                traits.put(0, 1); // non-hardcoded FName
                traits.string("PhD_Intern");
                traits.put(0, 32); // FName number
                traits.put(1, 1); // TraitRows includes the occupation itself
                traits.put(1, 16); // one array element
                traits.put(0, 1);
                traits.string("PhD_Intern");
                traits.put(0, 32);
                traits.put(0, 1); // default AmnesiaThreshold
                self.rpc(channel, 167, traits);
                self.controller.traits_sent = true;
                self.controller.trait_selection_requested = false;
                crate::log!("selected Intern with no optional traits");
            }
        }
        if self.controller.initialized && self.controller.traits_sent
            && self.controller.skills_ready && !self.controller.spawn_after_traits {
            if let Some(channel) = self.controller.channel {
                let mut state = Writer::default();
                state.put(1, 1);
                state.packed(self.controller.player_state);
                self.rpc(channel, 158, state);
                self.controller.spawn_after_traits = true;
                crate::log!("requested spawn after server skill initialization");
            }
        }
        if self.controller.loading_requested {
            if let Some((&channel, _)) = self.channel_objects.iter().find(|(_, guid)| **guid == self.controller.pawn) {
                if self.female && !self.customized {
                    self.rpc(channel, 300, crate::customization::female());
                    self.customized = true;
                    crate::log!("sent Sophia's female appearance and voice over UDP");
                }
                let mut loaded = Writer::default();
                loaded.put(1, 1); // Request_UpdateOwningLevelLoad(NewState=true)
                self.rpc(channel, 294, loaded);
                self.controller.loading_requested = false;
                crate::log!("sent character loading completion over UDP");
            }
        }
    }

    fn control(&mut self, reader: &mut Reader<'_>) -> io::Result<()> {
        while reader.remaining() > 0 {
            match reader.get(8)? {
                3 => {
                    let response = reader.string()?;
                    if !self.progress.challenged {
                        self.progress.challenged = true;
                        crate::log!("server challenged login");
                        let mut login = Writer::default();
                        login.put(5, 8);
                        login.string(&response);
                        login.string(&format!("?Name={}?ConnectID={}", self.player_name, self.player_id.connection_id()));
                        self.player_id.write(&mut login);
                        login.string("EOSPlus");
                        self.queue(login, false, false);
                    }
                }
                1 => {
                    self.world = reader.string()?;
                    reader.string()?; // game mode
                    reader.string()?; // redirect URL
                    if !self.progress.welcomed {
                        self.progress.welcomed = true;
                        eprintln!(
                            "[abiotic-client] server welcomed login; sending netspeed and join"
                        );
                        let mut speed = Writer::default();
                        speed.put(4, 8);
                        speed.put(100_000, 32);
                        self.queue(speed, false, false);
                        let mut join = Writer::default();
                        join.put(9, 8);
                        self.queue(join, false, true);
                    }
                }
                2 => {
                    return Err(invalid(&format!(
                        "server requires network version {}",
                        reader.get(32)?
                    )));
                }
                6 => {
                    return Err(invalid(&format!(
                        "server rejected login: {}",
                        reader.string()?
                    )));
                }
                23 => {
                    return Err(invalid(&format!(
                        "server close reason: {}",
                        reader.string()?
                    )));
                }
                other => return Err(invalid(&format!("unsupported control message {other}"))),
            }
        }
        Ok(())
    }

    fn close(&mut self, socket: &UdpSocket) -> io::Result<()> {
        let mut packet = self.header();
        packet.put(1, 1); // open/close flags present
        packet.put(0, 1);
        packet.put(1, 1); // close control channel
        packet.put(0, 4); // Destroyed close reason (SerializeInt with maximum 15)
        packet.put(0, 1);
        packet.put(1, 1);
        packet.packed(0);
        packet.put(0, 3);
        packet.put(
            u64::from(self.out_control.wrapping_add(1) & CHANNEL_MASK),
            10,
        );
        packet.put(1, 1);
        packet.packed(CONTROL_NAME);
        packet.put(0, 13);
        packet.put(1, 1);
        let bytes = packet.finish();
        self.transmit(socket, &bytes)?;
        Ok(())
    }
}

/// Run a bounded login/replication session. Progress is not proof of a spawned pawn.
pub fn run(
    socket: &UdpSocket,
    connected: Connected,
    name: &str,
    player_id: PlayerId,
    duration: Duration,
) -> io::Result<Progress> {
    run_configured(socket, connected, name, player_id, duration, None, None)
}

pub fn run_profile(
    socket: &UdpSocket,
    connected: Connected,
    profile: &crate::profile::Profile,
    directory: &std::path::Path,
    duration: Duration,
) -> io::Result<Progress> {
    let id = PlayerId::new(&profile.bot_id)?;
    // Spawn acceptance only: the server rejected RPC 300 with a parameter-read
    // mismatch. Preserve the saved appearance preference until its wire format is fixed.
    run_configured(socket, connected, &profile.name, id, duration, Some((false, directory)), None)
}

#[derive(Clone, Debug, Default, serde::Serialize)]
pub struct SessionStatus {
    pub welcomed: bool,
    pub join_acknowledged: bool,
    pub possession_confirmed: bool,
    pub pawn: u32,
    pub world: String,
    pub position: Option<[f64; 3]>,
    pub travel: Option<String>,
}

/// Commands and observation belong to the caller; no console thread is created.
pub struct SessionControl {
    pub commands: std::sync::mpsc::Receiver<String>,
    pub status: std::sync::Arc<parking_lot::Mutex<SessionStatus>>,
}

pub fn run_controlled(
    socket: &UdpSocket, connected: Connected, profile: &crate::profile::Profile,
    directory: &std::path::Path, control: SessionControl,
) -> io::Result<Progress> {
    run_configured(socket, connected, &profile.name, PlayerId::new(&profile.bot_id)?,
        Duration::MAX, Some((false, directory)), Some(control))
}

fn run_configured(
    socket: &UdpSocket,
    connected: Connected,
    name: &str,
    player_id: PlayerId,
    duration: Duration,
    profile: Option<(bool, &std::path::Path)>,
    control: Option<SessionControl>,
) -> io::Result<Progress> {
    if name.is_empty()
        || name.len() > 32
        || !name.bytes().all(|b| b.is_ascii_alphanumeric() || b == b'_')
    {
        return Err(io::Error::new(
            ErrorKind::InvalidInput,
            "name must be 1-32 ASCII letters, digits or underscores",
        ));
    }
    if duration.is_zero() {
        return Err(io::Error::new(
            ErrorKind::InvalidInput,
            "duration must be positive",
        ));
    }
    let mut connection = Connection::new(connected, name, player_id);
    if let Some((female, directory)) = profile {
        connection.female = female;
        connection.memory = Some(directory.to_path_buf());
        match crate::location::LocationMap::load(directory) {
            Ok(map) => connection.location_map = Some(map),
            Err(error) => crate::log!("local map unavailable: {error}"),
        }
        if control.is_none() {
        let (sender, receiver) = std::sync::mpsc::channel();
        std::thread::spawn(move || {
            for line in std::io::stdin().lines() {
                let Ok(line) = line else { break };
                if sender.send(line).is_err() { break; }
            }
        });
        connection.commands = Some(receiver);
        println!("Commands: where, position, state (last UDP correction), forward (two seconds along +X), stop, respawn (at a player start), quit (UDP logout).");
        }
    }
    if let Some(control) = control {
        connection.commands = Some(control.commands);
        connection.status = Some(control.status);
    }
    let mut hello = Writer::default();
    hello.put(0, 8);
    hello.put(1, 8);
    hello.put(u64::from(connection.ids.network_version), 32);
    hello.string("");
    hello.put(0, 16);
    connection.queue(hello, true, false);
    let result = exchange(socket, &mut connection, duration);
    let closed = connection.close(socket);
    match result {
        Ok(()) => {
            closed?;
            Ok(connection.progress)
        }
        Err(error) => {
            crate::log!("session ending with error: {error} while {}", connection.describe());
            if let Err(close_error) = closed {
                crate::log!("disconnect send failed: {close_error}");
            }
            Err(error)
        }
    }
}

fn exchange(socket: &UdpSocket, connection: &mut Connection, duration: Duration) -> io::Result<()> {
    let started = Instant::now();
    let mut buffer = [0; 65536];
    let mut ack = false;
    while started.elapsed() < duration {
        if connection.status.is_some() {
            match connection.commands.as_ref().expect("controlled session commands").try_recv() {
                Ok(command) if command.trim() == "quit" => return Ok(()),
                Ok(command) if command.trim() == "respawn" => connection.request_respawn()?,
                Ok(command) if command.starts_with("travel ") => connection.start_travel(&command["travel ".len()..])?,
                Ok(command) if command.trim() == "stop" => connection.stop_movement(socket, started.elapsed().as_secs_f32())?,
                Ok(command) => return Err(invalid(&format!("spawn-only session does not accept {command}"))),
                Err(std::sync::mpsc::TryRecvError::Disconnected) => return Ok(()),
                Err(std::sync::mpsc::TryRecvError::Empty) => {},
            }
        }
        while let Some(command) = connection.commands.as_ref().and_then(|rx| rx.try_recv().ok()) {
            match command.trim() {
                "quit" => return Ok(()),
                "where" => connection.report_location(),
                "position" => crate::log!("last received UDP position {:?} ({})", connection.controller.position, connection.controller.position_source),
                "state" => crate::log!("last received UDP correction {:?}", connection.controller.last_correction),
                "forward" if connection.controller.initialized => {
                    connection.movement_started = Some(Instant::now());
                    connection.next_move = Instant::now();
                    crate::log!("forward input started for two seconds (+X)");
                }
                "stop" => connection.stop_movement(socket, started.elapsed().as_secs_f32())?,
                "respawn" => connection.request_respawn()?,
                travel if travel.starts_with("travel ") => connection.start_travel(&travel["travel ".len()..])?,
                _ => crate::log!("command unavailable: use where, position, state, forward after possession, stop, respawn, travel <x,y,z ...>, or quit"),
            }
        }
        if connection.travel.is_some() && Instant::now() >= connection.next_move {
            connection.next_move = Instant::now() + Duration::from_millis(33);
            let timestamp = started.elapsed().as_secs_f32();
            match connection.controller.position {
                None => connection.travel_status = Some("waiting for a UDP position".into()),
                Some(position) => match connection.travel.as_mut().expect("travel checked above").step(position) {
                    crate::travel::Step::Move { index, acceleration } => {
                        connection.travel_status = Some(format!("travelling to point {index}"));
                        connection.movement_input(socket, timestamp, acceleration)?;
                    }
                    crate::travel::Step::Done { status } => {
                        connection.travel = None;
                        connection.travel_status = Some(format!("{status:?}").to_lowercase());
                        connection.movement_input(socket, timestamp, [0.0; 3])?;
                        crate::log!("travel finished: {status:?}");
                    }
                },
            }
        }
        if let Some(movement_started) = connection.movement_started {
            if Instant::now() >= connection.next_move {
                let active = movement_started.elapsed() < Duration::from_secs(2);
                connection.movement_input(socket, started.elapsed().as_secs_f32(), if active { [2048.0, 0.0, 0.0] } else { [0.0; 3] })?;
                connection.next_move = Instant::now() + Duration::from_millis(33);
                if !active {
                    connection.movement_started = None;
                    crate::log!("forward input finished; sent zero acceleration");
                }
            }
        }
        connection.send(socket, ack)?;
        let remaining = duration.saturating_sub(started.elapsed());
        if remaining.is_zero() {
            break;
        }
        socket.set_read_timeout(Some(remaining.min(Duration::from_millis(if connection.movement_started.is_some() || connection.travel.is_some() { 10 } else { 200 }))))?;
        match socket.recv(&mut buffer) {
            Ok(size) => {
                if let Err(error) = connection.receive(&buffer[..size]) {
                    crate::log!("packet of {size} bytes rejected: {error} while {}", connection.describe());
                    return Err(error);
                }
                if let Some(status) = &connection.status {
                    *status.lock() = SessionStatus {
                        welcomed: connection.progress.welcomed,
                        join_acknowledged: connection.progress.join_acknowledged,
                        possession_confirmed: connection.controller.initialized,
                        pawn: connection.controller.pawn,
                        world: connection.world.clone(),
                        position: connection.controller.position,
                        travel: connection.travel_status.clone(),
                    };
                }
                if connection.location_map.is_some() && connection.controller.position != connection.reported_position {
                    connection.report_location();
                    connection.reported_position = connection.controller.position;
                }
                if let Some(directory) = &connection.memory {
                    for (bit, happened, event) in [
                        (1, connection.progress.welcomed, "server_welcomed_me"),
                        (2, connection.controller.initialized, "confirmed_my_pawn_replication"),
                        (4, connection.controller.skills_ready, "server_initialized_my_skills"),
                        (8, connection.customized, "queued_my_female_customization"),
                    ] {
                        if happened && connection.remembered & bit == 0 {
                            crate::profile::remember(directory, event, &socket.peer_addr()?.to_string())?;
                            connection.remembered |= bit;
                        }
                    }
                }
                ack = true;
            }
            Err(error) if matches!(error.kind(), ErrorKind::TimedOut | ErrorKind::WouldBlock) => {
                ack = true; // Keep the established connection alive even without incoming replication.
            }
            // Windows can answer a short read timeout with "overlapped I/O in
            // progress" (ERROR_IO_PENDING) instead of a timeout; nothing is
            // wrong with the connection, so it counts as a missed tick.
            Err(error) if error.raw_os_error() == Some(ERROR_IO_PENDING) => {
                connection.pending_receives += 1;
                if connection.pending_receives == 1 || connection.pending_receives % 100 == 0 {
                    crate::log!("receive reported pending ({}) while {}; continuing", connection.pending_receives, connection.describe());
                }
                ack = true;
            }
            Err(error) => {
                crate::log!("receive failed: {error} (kind {:?}, os error {:?}) while {}", error.kind(), error.raw_os_error(), connection.describe());
                return Err(error);
            }
        }
    }
    if !connection.progress.join_acknowledged {
        return Err(io::Error::new(
            ErrorKind::TimedOut,
            format!("join was not acknowledged: {:?}", connection.progress),
        ));
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn controlled_session_quit_or_owner_drop_sends_udp_close_and_returns() {
        for explicit_quit in [false, true] {
            let server = UdpSocket::bind("127.0.0.1:0").unwrap();
            server.set_read_timeout(Some(Duration::from_secs(2))).unwrap();
            let socket = crate::handshake::socket(server.local_addr().unwrap()).unwrap();
            let directory = std::env::temp_dir().join(format!("sophia-controlled-{:016x}", fastrand::u64(..)));
            let profile = crate::profile::Profile::load_or_create(&directory).unwrap();
            let (commands, receiver) = std::sync::mpsc::channel();
            if explicit_quit { commands.send("quit".into()).unwrap(); }
            drop(commands);
            let control = SessionControl { commands: receiver, status: Default::default() };
            let worker = std::thread::spawn(move || {
                run_controlled(&socket, connection().ids, &profile, &directory, control)
            });
            let mut bytes = [0; 2048];
            let (size, _) = server.recv_from(&mut bytes).expect("UDP close reaches server");
            let mut packet = Reader::packet(&bytes[..size]).unwrap();
            packet.get(6).unwrap();
            packet.get(32).unwrap();
            for _ in 0..8 { packet.get(32).unwrap(); }
            assert_eq!(packet.get(1).unwrap(), 0, "no timing field");
            assert_eq!(packet.get(1).unwrap(), 1, "channel control flags");
            assert_eq!(packet.get(1).unwrap(), 0, "not a channel open");
            assert_eq!(packet.get(1).unwrap(), 1, "UDP channel close");
            assert!(worker.join().unwrap().is_ok(), "controlled session returns without a console reader");
        }
    }

    fn connection() -> Connection {
        Connection::new(
            Connected {
                session: 0,
                client: 0,
                network_version: 123,
                server_sequence: 1023,
                client_sequence: 16383,
            },
            "AIPlayer",
            PlayerId::new("6d6f64666f7267654149506c61796572").unwrap(),
        )
    }

    fn control_packet(packet_sequence: u16, channel_sequence: u16, payload: &Writer) -> Vec<u8> {
        let mut packet = Writer::default();
        packet.put(0, 6);
        packet.put((u64::from(packet_sequence) << 18) | (16383 << 4), 32);
        packet.put(1, 32); // acknowledge the client's packet 16383
        packet.put(0, 1); // no timing
        packet.put(0, 1); // no open/close
        packet.put(0, 1); // unpaused
        packet.put(1, 1); // reliable
        packet.packed(0);
        packet.put(0, 3);
        packet.put(u64::from(channel_sequence), 10);
        packet.put(1, 1);
        packet.packed(CONTROL_NAME);
        packet.put(payload.len() as u64, 13);
        packet.append(payload);
        packet.put(1, 1);
        packet.finish()
    }

    fn challenge() -> Writer {
        let mut payload = Writer::default();
        payload.put(3, 8);
        payload.string("fixture-response");
        payload
    }

    fn controller_rpc_fields(connection: &Connection) -> Vec<u32> {
        connection.pending.iter().map(|pending| {
            let bytes = pending.payload.clone().finish();
            let mut block = Reader::packet(&bytes).unwrap();
            assert_eq!(block.get(1).unwrap(), 0);
            assert_eq!(block.get(1).unwrap(), 1);
            let size = block.packed().unwrap() as usize;
            block.take(size).unwrap().bounded(169).unwrap()
        }).collect()
    }

    #[test]
    fn saved_character_waits_for_server_possession_to_initiate_spawn() {
        let mut connection = connection();
        connection.controller.channel = Some(2);
        connection.controller.pawn = 6;
        connection.controller.player_state = 4;
        connection.controller.skills_ready = true; // Restored save, not new trait completion.
        connection.spawned.extend([4, 6]);
        connection.advance_character_setup();
        assert_eq!(controller_rpc_fields(&connection), [80, 72, 139]);
        connection.advance_character_setup();
        assert_eq!(controller_rpc_fields(&connection), [80, 72, 139]);
        assert!(!connection.controller.spawn_after_traits);
    }

    #[test]
    fn post_creation_spawn_requires_requested_traits_and_server_completion() {
        let mut connection = connection();
        connection.controller.channel = Some(2);
        connection.controller.pawn = 6;
        connection.controller.player_state = 4;
        connection.spawned.extend([4, 6]);
        connection.advance_character_setup();
        connection.pending.clear();
        // Feed the actual controller RPC content-block format for the prompt.
        let mut fields = Writer::default();
        fields.bounded(118, 169);
        fields.packed(0);
        let mut prompt = Writer::default();
        prompt.put(0, 1);
        prompt.put(1, 1);
        prompt.packed(fields.len() as u32);
        prompt.append(&fields);
        let bytes = prompt.finish();
        connection.controller.receive(&mut Reader::packet(&bytes).unwrap()).unwrap();
        connection.advance_character_setup();
        assert_eq!(controller_rpc_fields(&connection), [167]);
        connection.advance_character_setup();
        assert_eq!(controller_rpc_fields(&connection), [167]);
        let mut props = Writer::default();
        props.put(0, 1);
        props.packed(30);
        props.put(1, 1);
        props.packed(0);
        let mut ready = Writer::default();
        ready.put(1, 1);
        ready.put(1, 1);
        ready.packed(props.len() as u32);
        ready.append(&props);
        let bytes = ready.finish();
        connection.controller.receive_state(&mut Reader::packet(&bytes).unwrap()).unwrap();
        connection.advance_character_setup();
        connection.advance_character_setup();
        assert_eq!(controller_rpc_fields(&connection), [167, 158]);
    }

    fn welcome() -> Writer {
        let mut payload = Writer::default();
        payload.put(1, 8);
        payload.string("/Game/TestMap");
        payload.string("/Game/TestMode");
        payload.string("");
        payload
    }

    #[test]
    fn control_sequence_wraps_and_reordered_welcome_waits_for_challenge() {
        let mut connection = connection();
        connection.header(); // client packet 16383 was sent; next packet wraps to 0
        connection
            .receive(&control_packet(1023, 1, &welcome()))
            .unwrap();
        assert!(!connection.progress.welcomed);
        connection
            .receive(&control_packet(1024, 0, &challenge()))
            .unwrap();
        assert!(connection.progress.challenged && connection.progress.welcomed);
        assert_eq!(connection.in_control, 1);
        assert_eq!(connection.pending.len(), 3); // Login, Netspeed, Join
        let login = connection.pending.front().unwrap().payload.clone().finish();
        let mut login = Reader::packet(&login).unwrap();
        assert_eq!(login.get(8).unwrap(), 5);
        assert_eq!(login.string().unwrap(), "fixture-response");
        assert_eq!(login.string().unwrap(), "?Name=AIPlayer?ConnectID=|6d6f64666f7267654149506c61796572");
        assert_eq!(login.get(8).unwrap(), 0xf8);
        assert_eq!(login.string().unwrap(), "EOSPlus");
        assert_eq!(login.string().unwrap(), "|6d6f64666f7267654149506c61796572");
        assert_eq!(login.string().unwrap(), "EOSPlus");
        assert_eq!(login.remaining(), 0);
        connection
            .receive(&control_packet(1025, 0, &challenge()))
            .unwrap();
        assert_eq!(connection.pending.len(), 3); // retransmission cannot trigger another login
    }

    #[test]
    fn unsent_packet_acknowledgement_cannot_advance_login() {
        let mut connection = connection();
        assert!(
            connection
                .receive(&control_packet(1023, 0, &challenge()))
                .is_err()
        );
        assert!(!connection.progress.challenged);
    }

    #[test]
    fn ue54_actor_fragment_has_two_partial_flags() {
        let mut connection = connection();
        connection.header();
        let mut packet = Writer::default();
        packet.put(0, 6);
        packet.put((1023 << 18) | (16383 << 4), 32);
        packet.put(1, 32);
        packet.put(0, 1);
        packet.put(1, 1); // flags present
        packet.put(1, 1); // open
        packet.put(0, 1); // not closed
        packet.put(0, 1);
        packet.put(1, 1); // reliable
        packet.packed(1);
        packet.put(0, 2); // exports/must-map
        packet.put(1, 1); // partial
        packet.put(0, 10);
        packet.put(1, 1); // initial
        packet.put(0, 1); // final
        packet.put(1, 1); // hardcoded channel name immediately follows
        packet.packed(102); // Actor
        packet.put(8, 13);
        packet.put(0, 8);
        packet.put(1, 1);
        connection.receive(&packet.finish()).unwrap();
        assert_eq!(connection.progress.actor_bunches, 1);
        assert!(!connection.progress.join_acknowledged);
    }

    #[test]
    fn server_rejection_is_reported_instead_of_join_success() {
        let mut connection = connection();
        connection.header();
        let mut payload = Writer::default();
        payload.put(6, 8);
        payload.string("fixture rejection");
        let error = connection
            .receive(&control_packet(1023, 0, &payload))
            .unwrap_err();
        assert_eq!(
            error.to_string(),
            "server rejected login: fixture rejection"
        );
        assert!(!connection.progress.join_acknowledged);
    }
}
