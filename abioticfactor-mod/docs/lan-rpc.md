# LAN RPC and property reference

[Research index](abiotic-factor.md) | [Todo](todo.md)

## RPC and property reference for the inspected build

| Target | Index / handle | Name | Direction and role |
|---|---:|---|---|
| Character RPC | 39 | ServerMoveOld | Owner -> server; unreliable timestamp, NetQuantize10 acceleration and compressed flags; exercised for bounded movement |
| Controller RPC | 72 | ServerAcknowledgePossession | Client -> server; own pawn GUID |
| Controller RPC | 80 | ServerNotifyLoadedWorld | Client -> server; world FName |
| Controller RPC | 118 | Client_DoTraitSelectionSequence | Server -> owner; creation requested |
| Controller RPC | 139 | Request_ConfirmCharacterReplication | Client -> server; no parameters; confirms received pawn |
| Controller RPC | 158 | Request_SpawnMeInWorld | PlayerState parameter; first call is made by the server possession path |
| Controller RPC | 167 | Server_SetupInitialTraits | Client -> server; PhDTrait, TraitRows, AmnesiaThreshold |
| Character RPC | 205 | Client_EvaluateLoadingScreen | Server -> owner; reevaluate loading UI |
| Character RPC | 217 | Client_SetupCharacter | Server -> owner; FirstTimeSpawn boolean |
| Character RPC | 294 | Request_UpdateOwningLevelLoad | Owner -> server; NewState boolean |
| Character RPC | 300 | Server_ApplyAllCustomizationData | Owner -> server; full customization parameters, offline schema decoded |
| Controller property | 16 / 17 | PlayerState / Pawn | Network GUID references; not character-readiness signals |
| PlayerState property | 30 | HasSetUpSkills | Completion fact; must be interpreted within the creation flow |

The full customization schema has 15 parameters: voice SoftObjectProperty,
13 named customization selections, and SkinTone as a double. Female assets and
the serializer are recorded by the offline customization research artifacts.
**Observed:** the server rejected customization on the later spawn attempt with
ReceivePropertiesForRPC mismatch. Automatic application is disabled; the saved
female preference is preserved. This is separate from the earlier spawn-loop
freeze. Encoding, application/voice and persistence remain open.

## Confirmed bounded movement

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
