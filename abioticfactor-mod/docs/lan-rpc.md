# LAN RPC and property reference

[Research index](abiotic-factor.md) | [Todo](todo.md)

## RPC and property reference for the inspected build

| Target | Index / handle | Name | Direction and role |
|---|---:|---|---|
| Character RPC | 31 | ClientMoveResponsePacked | Server -> owner; good-move acknowledgement or position correction, decoded for ordinary absolute corrections |
| Character RPC | 38 | ServerMoveNoBase | Owner -> server; normal movement report with timestamp, acceleration, last reported position, flags, view and movement mode |
| Character RPC | 39 | ServerMoveOld | Owner -> server; unreliable timestamp, NetQuantize10 acceleration and compressed flags; exercised for bounded movement |
| Controller RPC | 72 | ServerAcknowledgePossession | Client -> server; own pawn GUID |
| Controller RPC | 80 | ServerNotifyLoadedWorld | Client -> server; world FName |
| Controller RPC | 118 | Client_DoTraitSelectionSequence | Server -> owner; creation requested |
| Controller RPC | 139 | Request_ConfirmCharacterReplication | Client -> server; no parameters; confirms received pawn |
| Controller RPC | 158 | Request_SpawnMeInWorld | PlayerState parameter; first call is made by the server possession path |
| Controller RPC | 167 | Server_SetupInitialTraits | Client -> server; PhDTrait, TraitRows, AmnesiaThreshold |
| Character RPC | 205 | Client_EvaluateLoadingScreen | Server -> owner; reevaluate loading UI |
| Character RPC | 217 | Client_SetupCharacter | Server -> owner; FirstTimeSpawn boolean |
| Character RPC | 258 | Request_RespawnPlayerCharacter | Owner -> server; RevivedOnSpot bool, UsePlayerStartOnly bool, DestinationID FName. W_RespawnOptions buttons: player start (false, true, None), bed (false, false, None), sector entrance (false, false, TerminalRespawnID), vignette (false, false, Entrance Teleporter). Live: player-start form respawned Sophia |
| Character RPC | 294 | Request_UpdateOwningLevelLoad | Owner -> server; NewState boolean |
| Character RPC | 300 | Server_ApplyAllCustomizationData | Owner -> server; full customization parameters, offline schema decoded |
| Controller property | 16 / 17 | PlayerState / Pawn | Network GUID references; not character-readiness signals |
| PlayerState property | 30 | HasSetUpSkills | Completion fact; must be interpreted within the creation flow |

RPC parameter encoding, confirmed live by the respawn request: a bool parameter
is one bit. Every other parameter starts with a presence bit; when the value
equals the default (DestinationID None) that bit is 0 and nothing follows.
Sending None as a hardcoded name after a presence bit of 1 made the server close
the connection with ObjectReplicatorReceivedBunchFail.

The full customization schema has 15 parameters: voice SoftObjectProperty,
13 named customization selections, and SkinTone as a double. Female assets and
the serializer are recorded by the offline customization research artifacts.
**Observed:** the server rejected customization on the later spawn attempt with
ReceivePropertiesForRPC mismatch. Automatic application is disabled; the saved
female preference is preserved. This is separate from the earlier spawn-loop
freeze. Encoding, application/voice and persistence remain open.

## Confirmed bounded movement

The first implementation below used RPC 39. The position-observation milestone
now uses RPC 38 when an initial position is known, allowing the server to send
RPC 31 corrections. The earlier RPC remains the fallback when no position is
available. This is still not a complete prediction implementation.

On 2026-09-12 the user confirmed Sophia spawning, then walking with animations
after repeated two-second movement commands through the standalone Rust binary.
The current `forward` command applies world +X acceleration of 2048 for two
seconds at roughly 30 updates per second, followed by zero acceleration. It is
not yet relative to Sophia's facing. No host input, transform write or HTTP
gameplay operation supplies this movement.

movement_rpc_schema in tests/http_health.rs reads the live character network
cache and reflected parameters: RPC 39 has OldTimeStamp (float), OldAccel
(24-byte reflected vector) and OldMoveFlags (byte). Shipped native
UCharacterMovementComponent::ServerMoveOld_Implementation at RVA 0x34EC890
validates timestamps and advances movement simulation. This legacy old-move
path provides a verified first movement step, not complete modern packed-move
prediction, correction handling, or a full client movement implementation.

The Rust payload uses parameter-presence bits, a float timestamp, packed-vector
float escape encoding for acceleration, and default jump/crouch flags. Actor
content uses character bound 310; the movement bunch is unreliable and travels
on Sophia's existing pawn channel and UDP socket. Stop sends zero acceleration;
quit leaves the exchange loop through its existing control-channel close path.
The final zero-acceleration datagram can be lost; reliable release and long-run
timestamp/reset handling remain open.

Build with `k3sc cargo-lock build -p abioticfactor-client`, launch
`abioticfactor-client.exe sophia`, then enter `forward`, `stop`, or `quit` on
that process's stdin. Keep one Sophia process. The movement acceptance binary
was built under target/sophia-movement using CARGO_TARGET_DIR; its executable
is x86_64-pc-windows-msvc/debug/abioticfactor-client.exe beneath that directory.

## Own position received over UDP

**Observed 2026-09-12:** actor-channel opening supplied Sophia's initial
placement (-13403.9, 15289.7, 21655.3). After normal movement reporting, the
server corrected this to her gameplay position. During a two-second +X input,
corrections progressed from (-17436.65078175383, 13276.37136559606,
208.14999551063738) to (-17111.929358970614, 13396.128366994613,
208.1500003922302). These values came from incoming UDP, not HTTP or elapsed
movement-time estimates. Initial actor allocation position is not final spawn
position. `position` prints the last received coordinates and their source.

**Decoded:** the actor-open vector has optional serialization and quantization
bits. Its packed form uses a seven-bit width/scaling header, signed components,
or float/double escape encoding. Opening positions are retained by network GUID
and selected using the possessed pawn GUID, avoiding another player's position.

The normal move uses the last known server position as ClientLoc; it does not
predict local physics. The server's packed correction parameter contains a
presence bit, packed bit-count and an inner response. The inner response begins
with bAckGoodMove and a float timestamp. Corrections then carry four flags for
base, rotation and root-motion variants; position and velocity are three
64-bit values each, followed by optional gravity, rotation, base and bone,
movement mode, and relative-position/velocity flags. These correction vectors
are not the actor-open packed-vector encoding.

Shipped-code evidence: FCharacterMoveResponseDataContainer::Serialize at RVA
0x34E9F60, packed-bit envelope NetSerialize at 0x34DE080, and vector serializer
at 0x100CF90. Permanent native research captures these under target's
movement-response, movement-packed-envelope and movement-response-vector text
artifacts. The shipped PDB identifies NewLoc, NewVel and relative flags in
FClientAdjustment. Rust tests cover signed/scaled vectors, double precision,
truncation and refusing relative coordinates as absolute world positions.

**Limits:** ordinary absolute corrections update Sophia's position. Relative
or root-motion corrections are recognized but not applied. Good-move replies
do not contain a new position. Idle updates, world-origin rebasing, moving bases,
teleports and pawn replacement still need complete handling. General pawn
property decoding remains unfinished. The interactive command is a last-received
observation, not proof that the stored value is current while idle.

### Body-state inputs retained from corrections

The client now retains one complete ordinary absolute correction observation:
timestamp, position, velocity, relative-velocity flag, optional body rotation,
optional serialized gravity vector and packed movement-mode byte. The `state`
command reports this last received correction; it does not predict current
state. Relative positions and root-motion variants still do not update it.
Absent rotation/gravity fields remain explicitly absent in this wire observation;
an absent gravity field is not a zero-gravity measurement. Applying native
defaults and maintaining a complete local body pose remain separate work.

Rotation serializer TRotator<double>::SerializeCompressedShort at 0x10123E0
reads a presence bit and optional unsigned 16-bit value for each axis, then
multiplies by 360/65536. Absent axes within a present rotator become zero;
an entirely absent rotator remains distinct. The native constant at 0x636D620
is recorded in movement-rotation-decode.txt. The movement-mode field's omitted
default is byte 1, as supplied by Serialize at 0x34EA209.

Verification: binary build and all 24 client library tests pass. A test feeds
a complete pawn RPC block through the receiver and checks position, timestamp,
rotation (90,0,270), gravity, nondefault mode and relative velocity retention.
Existing tests retain the missing-field, relative-position and truncation checks.
The later location-report run exercised this decoder live: Sophia's state
reported zero absolute velocity, mode 1 and omitted rotation/gravity fields.
The location work adds one library test, bringing the passing total to 25.
