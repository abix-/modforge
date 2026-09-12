# LAN transport, identity, and admission

[Research index](abiotic-factor.md) | [Todo](todo.md)

The multiplayer section preserves early investigation notes. The transport section contains the later admission findings; see [spawn](lan-spawn.md) for the current lifecycle.

## Transport, identity, and admission

**Observed:** the hosted world listens on UDP 7777, with `listen`,
`bIsLanMatch=1`, and `MaxPlayers=6`. The EOS net driver is in passthrough and the
joining connection is an IpConnection. One socket/source port is retained for
the entire standalone client session. UDP acceptance, login, actor replication,
possession, and playable spawn are separate milestones.

The implemented transport sequence is Initial -> Challenge -> Response -> Ack
for the UE stateless handshake, followed by the reliable control-channel
exchange below. The handshake carries version negotiation and a challenge
cookie; those challenge values are transient and are not written to research
documentation or profile memory. The inspected game network version is
2047383495. A version mismatch is an error, not grounds to continue parsing
with another build's field indices.

| Control message | Direction | Payload / consequence |
|---|---|---|
| Hello (0) | Client -> server | Endianness, network version and negotiated features; starts admission after transport handshake |
| Challenge (3) | Server -> client | Response string; precedes Login |
| Login (5) | Client -> server | Challenge response, travel options with name/ConnectID, serialized unique ID, online-platform name |
| Welcome (1) | Server -> client | World package, game mode, redirect string; not proof of possession |
| Netspeed (4) | Client -> server | int32 rate; current client sends 100000 |
| Join (9) | Client -> server | Requests play actor creation after Welcome |
| Upgrade (2), Failure (6), CloseReason (23) | Server -> client | Report incompatible version or rejection; never treat these as a successful join |

The accepted standalone identity uses a nonempty synthetic ID in the EOSPlus
representation decoded by `identity.rs`. The visible name and durable bot ID
are distinct. Sophia preserves her ID across runs, but the native game-save
key conversion collapses the current representation to numeric zero; see the
[persistence research](persistence.md). Reconnect/session-expiration rules remain open.
The fresh-host freeze proves an old connection is not necessary for
this particular failure; it does not prove all duplicate-session cases are safe.

Wire behavior implemented in `bits.rs`, `handshake.rs`, and `login.rs`:

- Bits are serialized least-significant first. Packet termination and the inner
  termination bit are distinct from payload data.
- Connected headers carry 2-bit session and 3-bit client IDs, a handshake flag,
  14-bit packet sequence and acknowledgment, and acknowledgment history.
- Packet sequences wrap modulo 16384; reliable channel sequences modulo 1024.
  Duplicate packets and retransmitted reliable messages cannot repeat gameplay
  transitions. Acknowledging an unsent packet is rejected.
- Channel zero carries control messages. Actor channels carry export/must-map
  flags, optional partial-bunch flags, network object identity and content blocks.
  UE 5.4 partial bunches have initial and final flags, not an extra guessed bit.
- Network GUIDs and exported archetype names identify Sophia's controller, pawn,
  and player state. Actor allocation is not gameplay initialization.
- RPC content blocks contain a field index, parameter bit count, then parameters.
  The controller field index uses bound 169; the character uses bound 310 in
  this build. An RPC index is class-specific, not globally meaningful.

Prior permanent local tests cover control ordering, wraparound, duplicate
challenge handling, unsent acknowledgments, exports and actor fragments.
**Open:** complete pawn/component property decoding and all RPC parameter types
are not implemented; successful initial actor parsing is not a complete UE client.

## Early multiplayer investigation (historical)

- Spawn investigation 2026-09-12: the permanent `player_spawn_initialization_functions` observer test found reliable server requests on `Abiotic_PlayerController_C`: `Request_SpawnMeInWorld` takes one PlayerState object reference; `Request_ConfirmCharacterReplication` has no parameters. `Server_SetupInitialTraits` takes PhDTrait, TraitRows and AmnesiaThreshold. Names and parameter layouts are verified; the sequence and prerequisites are not. The standalone client must decode the relevant actor replication and send the normal requests over UDP before playable spawn can be claimed.
- The AI player runtime is a standalone Rust executable, `abioticfactor-client`, communicating through the hosted LAN game's UDP port 7777. It does not load or invoke the game's client code. The older uncommitted in-process join experiment is outside this design.
- First acceptance: the host admits a second player controller owned by an IpConnection, with its own character and name. A socket reply, stateless handshake acknowledgement, or mock login alone is insufficient.
- The initial implementation supports UE stateless handshake versions 3 and 4: a 2-bit session ID, 3-bit client ID, handshake and restart bits, four bytes for minimum version/current version/type/count, a 32-bit network version, 16-bit runtime features, 1-bit secret selector, 64-bit timestamp, 20-byte cookie, 8-16 padding bytes, and a final termination bit. Fields are least-significant-bit first. Initial, Challenge, Response and Ack have types 0, 1, 2 and 3. The client echoes the challenge cookie without logging it and validates the acknowledgement before reporting transport acceptance.
- References: [Epic's stateless handshake API](https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/PacketHandlers/StatelessConnectHandlerComponent?application_version=5.5), [UE5 Python protocol reference](https://github.com/Mokocoder/UE5_python_client), and [Killing Floor standalone client](https://github.com/TheBestPlan/killingfloor-bot-client). Killing Floor's UE2.5 control strings are not Abiotic's protocol. The Rust implementation has no dependency on either reference client.
- Verification 2026-09-12: permanent Rust tests completed the live UDP handshake on 127.0.0.1:7777 with network checksum 2047383495, login, welcome and join acknowledgement. The independent host observer confirmed a separate IpConnection-owned controller and pawn for a 65-second session, with the human's ownership unchanged. The user saw the join message but no nearby bot: world-location diagnostics measured bot Z=21608 and human Z=1208. The reason for this elevated position remains unresolved; playable spawn and visible appearance are not claimed.
- Empty IDs are unsafe: offline disassembly confirms an unchecked dereference in approval at RVA 0x4700E51. NULL subsystem IDs were rejected. The accepted encoder uses explicit EOSPlus with an EOS product identifier and matching ConnectID option. The fixture is synthetic and proves LAN admission only, not online authentication. Do not restore the empty identity.
- Eight local tests and Clippy with warnings denied pass. They cover framing, malformed handshakes, loss/retry, acknowledgements, control ordering across sequence wrap, duplicate suppression, rejection, and the nonempty login payload. The client recognizes actor channel names but does not decode replicated world state or implement movement yet.
- Run offline checks with `k3sc cargo-lock test -p abioticfactor-client`. Run the live handshake with `k3sc cargo-lock test -p abioticfactor-client --test lan -- abiotic_accepts_udp_handshake --ignored --nocapture`; the separate `abiotic_accepts_login_and_join` filter exercises the pending full login exchange. Optional `ABIOTIC_SERVER` selects the server address; `ABIOTIC_NETWORK_VERSION` overrides the observed checksum. A mismatch is reported, not silently overridden. Use `CARGO_TARGET_DIR=C:/code/modforge/target/abioticfactor-client` for an isolated build while another workspace build holds the default lock.
- The CLI accepts `handshake <ip:port> <network-version>` or `join <ip:port> <network-version> <name> <seconds> <bot-id-32hex>`. Its bounded login run sends control-channel close on completion or failure. Host-side ownership and visible playable spawn are separate acceptance checks.

- EOS SDK for cross-platform multiplayer
- Custom replication graph (UAbioticReplicationGraph) with:
  - Spatial cells (configurable bias and size)
  - Frequency buckets for actor update rates
  - Fast shared path with cull distance
  - Per-connection always-relevant nodes
  - Player state frequency limiter
- Platforms: Steam, EOS, GOG, Playstation, Xbox (EAbioticPlatform enum)
- Cross-play setting (EAbioticCrossplaySetting)
- Banned player list persistence
