# LAN loading and playable readiness

[Research index](abiotic-factor.md) | [Todo](todo.md)

## Decoded overlap predicate (2026-09-12)

The inherited Blueprint IsLevelLoaded is 1045 bytes. The permanent
class_blueprint_research test can read it from Abiotic_PlayerCharacter_C
through HTTP without calling gameplay functions. Its complete trace is in
target/abioticfactor-client/pawn-is-level-loaded.txt.

| Input | Return rule | Bytecode evidence |
|---|---|---|
| OverlappingLevelVolumes is empty | true | Array_IsNotEmpty at 37; false branch 56 -> 450; true at 460 |
| RequireAllOverlapped is true | Every overlap's LevelToLoad must be loaded | Query 394; first false -> 1023; exhaustion -> 933 returns true |
| RequireAllOverlapped is false | At least one overlap's LevelToLoad must be loaded | Query 776; first true -> 827; exhaustion -> 917 returns false |

Both server and owning-player callbacks pass HasRecentlyTeleported as
RequireAllOverlapped (107396 and 107463 in the character graph). Teleport thus
changes the requirement from any overlap to every overlap. An unavailable
overlap list is not evidence that the list is empty.

HTTP function-owner resolution confirms the per-volume query goes to
LevelManagerSubsystem. Shipped symbols and loading_and_creation_native_code
locate ULevelManagerSubsystem::IsLevelLoaded at RVA 0x46E6F40 and
ULevelManagerComponent::IsLevelLoaded at 0x4712D40. The former obtains a
component and delegates to it. The component's matched-entry branch checks
non-null values at entry +0x20 and +0x28, then byte +0xE9 equal to 6 on the
latter object. The shipped PDB now confirms that +0x28 on ULevelManagerInstance
is LevelStreaming, and +0xE9 on ULevelStreaming is CurrentState.
ELevelStreamingState value 6 is LoadedVisible. LoadedNotVisible is 4 and
MakingVisible is 5, so merely reading asset bytes does not satisfy this native
check. The component's fallback path remains open.

## Volume membership and source data (2026-09-12)

**Decoded:** the complete 33903-byte Abiotic_Character_ParentBP graph owns
membership updates. OnLevelVolumeEnter wraps entry 28122: Array_Add at 28162
adds the event's Volume to OverlappingLevelVolumes, then dispatches
LevelStreamingVolumesUpdated at 28190. OnLevelVolumeExit wraps 28210:
Array_RemoveItem at 28242 removes it, then dispatches the same delegate at
28270. The player graph binds server and owning-client reevaluation to this
delegate. Geometry/overlap event generation still needs tracing.

**Observed metadata:** streaming_property_metadata reads class properties over
HTTP and resolves both FProperty.PropertyFlags and CPF_Net from the shipped PDB.
None of the following fields has CPF_Net set:

| Property | Instance offset | Flags |
|---|---:|---|
| Character parent OverlappingLevelVolumes | 4728 | 0x10805 |
| AbioticLevelStreamingVolume.LevelToLoad | 720 | 0x1C000000000005 |
| RequiredParentLevel | 760 | 0x1C000000000005 |
| RequiredEntitlement | 800 | 0x18000000000005 |
| RequiredWorldFlag | 832 | 0x18000000000005 |

These are not ordinary replicated properties that Sophia can wait to receive.
This finding does not prove that no related RPC exists. The normal client has
local map assets and local overlap events; reproducing that path requires local
map content in the Rust client, while gameplay/session state remains UDP.

The native AAbioticLevelStreamingVolume layout is 880 bytes. LevelToLoad and
RequiredParentLevel are TSoftObjectPtr<UWorld>; entitlement/world-flag fields
are row handles. The constructor uses the Trigger collision profile. Exact
brush geometry, transforms, and the entitlement/world-flag loading predicates
must be decoded before choosing a geometric approximation.

**Observed live world:** the game-thread ping succeeded and ticks advanced
30999 -> 31000 in the current session. live_streaming_volumes subsequently
read four overlaps for the current player and enumerated 223 streaming-volume
actors through the player's world. It retained names and locations in
target/abioticfactor-client/live-streaming-volumes.json. These are observations
of the human player's world, not a Sophia readiness or spawn acceptance test.

**Offline source availability:** streaming_asset_catalog invokes the installed
Rust retoc tool to list the shipped container, retaining 95 map-related chunk
rows in target/abioticfactor-client/streaming-asset-paths.json. This includes
map and bulk-data rows, not 95 distinct maps. It does not yet parse volume
exports or load their content into Sophia.

**Implementation gap:** Sophia's loading=true response in
abioticfactor-client/src/login.rs does not reproduce the overlap predicate.
Establish how the bot obtains volume bounds, membership, LevelToLoad, and
required level content before implementing it. HTTP remains research only.

## Facility map extraction

**Verified offline, 2026-09-12:** the standalone Rust reader in
tools/map-reader parses the retoc-converted Facility package. Its 52753 exports
include 223 AbioticLevelStreamingVolume, 237 BrushComponent, 628 BodySetup and
238 Model exports. Selected exports retain their package indices and outer
references, decoded properties, payload offsets and sizes.

The package uses unversioned properties. The published Mappings_v1.0.0 schema
decoded the first volume's LevelToLoad but misaligned later fields. Permanent
HTTP research now captures current declaration order, inheritance, array
dimensions and nested property types, including referenced structs. The reader
uses that schema exclusively. Unknown property types and invalid references
fail instead of prompting guessed payload-offset corrections. This is not an
automatic content/schema version compatibility check; recapture after updates.

The offline facility_volumes_match_observation test resolves each volume's
BrushComponent and BrushBodySetup export references. All 223 volume root
locations match the saved live Facility actor observations within 0.001 game
units (reported maximum difference zero). All have map level references and
convex collision data: 259 convex elements have finite three-coordinate
vertices and triangle indices within their vertex arrays. This checks data
structure, not collision behavior or triangle winding.

Example volume AbioticLevelStreamingVolume_0 references Facility_Office4 and
BrushComponent export 2900, then BodySetup export 1654. Its root position is
approximately (-13571.05148, 18099.62987, 1647.48265), yaw 44.999999 degrees,
and scale (18.73709556, 18.28467017, 6.63628279). Its convex vertices occupy a
local cube from -100 to 100 on each axis. These are decoded asset values;
only the position has been compared against the live observation.

**Limits:** absent properties remain absent; explicitly serialized zero values
are marked separately. Do not assume omitted transforms or collision settings
without establishing their defaults. Native trailing Model/BSP and cooked
BodySetup data are not decoded. Collision filtering, capsule versus volume
overlap, transformed convex membership, prerequisites and owning-level content
readiness still need research before Sophia consumes this data. No gameplay
HTTP dependency or new Sophia join was introduced by these tests.

## Level loading, disabled state, and playable readiness

The server and owning client separately query IsLevelLoaded and maintain
ServerLevelLoaded and OwningLevelLoaded. The pawn's server BeginPlay binds the
level manager's loaded/unloaded events and its streaming-volume event, then
evaluates loading (1393..1852). Owning Local_BeginPlay binds corresponding
owning-client callbacks (105309..105553).

- Server_OnLevelLoadUpdated enters 107342, updates ServerLevelLoaded, then
  evaluates the character's disabled state.
- Owning_OnLevelLoadUpdated enters 107440, updates OwningLevelLoaded. A remote
  owning client sends Request_UpdateOwningLevelLoad at 107556; a local listen
  host evaluates directly. Both evaluate the local loading screen.
- Request_UpdateOwningLevelLoad enters 107932, stores NewState and calls
  EvaluatePlayerFreezeState. Character RPC 294 carries this boolean.
- EvaluatePlayerFreezeState (107584) runs on the server. Modifier.ForceDisable
  has a separate branch. Otherwise the desired disabled state is
  `!((ServerLevelLoaded && OwningLevelLoaded) || HasBuff(Character.NoLoadingFreeze))`.
  When changed, the game marks IsDisabled for replication and invokes its normal
  disabled-state handling. The character's loading freeze is not the same as
  the whole host's non-yielding spawn loop.
- Client_EvaluateLoadingScreen and Client_SetupCharacter are character RPCs
  205 and 217. Setup's FirstTimeSpawn selects local intro/setup branches; it is
  not proof that all level data is already available.

**Open for the headless client:** define owning-level readiness from the world
data Sophia actually consumes, decode the needed server replication, and
verify disabled-state completion. The existing behavior that replies true to
any setup/loading request is an implementation shortcut, not a proved model of
level streaming. Do not report a playable character merely because that reply
was sent. Human verification remains the current visible-spawn acceptance.
