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

## Client sector selection

**Decoded, 2026-09-12:** the normal client identifies its sector locally using
the shipped map, the level manager, and DT_Levels. Coordinates alone are not
a sector name. The following is the actual controller path, not a proposed
nearest-volume or bounding-box heuristic.

1. The controller graph at 3153..3568 validates PlayerCharacter and calls
   GetLevelFXCharacter. That 89-byte function returns ActiveSpectatorActor when
   valid, otherwise PlayerCharacter. A spectator can therefore see the sector
   of the character being watched.
2. FindLatestLevelPlayerIsIn receives that character. Its subsystem wrapper at
   RVA 0x46CF200 delegates to the component implementation at 0x4707320.
3. The component iterates its level-instance map at +0xC0 in native sparse-map
   order. For each instance, it visits LevelStreamingVolumes at +0x30 until
   one volume reports AActor::IsOverlappingActor(character). PDB research
   identifies that call target as RVA 0x329AC30. This is actor overlap state,
   not an actor-origin point-in-box query.
4. Among matching instances it minimizes the float age computed from double
   world TimeSeconds minus float LastTimeVisible. A greater or equal age does
   not replace the selected entry, so equal ages keep the first native entry.
   The initial comparison constant at RVA 0x636D718 has bytes 9E C9 7F 7F,
   float bits 0x7F7FC99E (approximately 3.4e38, not FLT_MAX). A missing world
   yields age zero; the world asset output can be empty if streaming/outer
   references are missing. Preserve these branches when implementing selection.
5. When the returned level differs from CurrentFXLevel, the controller stores
   it and calls Attempt Level FXChange. If no level is found in a saveable
   game, the previous selection remains. The non-saveable path uses the
   persistent world instead. The controller loop delays 0.2 seconds.

LastTimeVisible is not simply the last time the player entered a volume:

| Native path | Observed writer in decoded code |
|---|---|
| OnLevelLoaded, RVA 0x4716FA0 | Records world time in CreationTime (+0xAC) and LastTimeVisible (+0xB0), clears bWantsToLoad, evaluates level state |
| CheckStreamingState, RVA 0x4702C20 | When transitioning into LoadedVisible (6), records both times and evaluates level state |
| SetLevelVisibility, RVA 0x4724690 | Requires valid loaded streaming state and a changed visibility request; records LastTimeVisible when the previous bLevelVisible was true, before storing the requested visibility |

These writers establish why a standalone client needs its own loading and
visibility history. This is not an exhaustive writer audit or proof that
the host's timestamps can substitute for another client's local history.

Attempt Level FXChange (814 bytes) converts the soft world reference to a
string, splits at the period, and stores the right side as ActiveLevelName.
It enumerates DT_Levels row names in table order. The first row whose
LevelFileName FName equals ActiveLevelName becomes ActiveLevelFXName. It then
calls DetermineCorrectWeatherFX and DetermineCorrectFX. No match supplies no
replacement row.

DetermineCorrectFX (1291 bytes) returns when DisableAutomaticFX is set. Its
first non-None preference is CheatLevelFXName, OverrideLevelFXName,
ActiveWeatherFXName, ActiveSubFXName, then ActiveLevelFXName. When that preference
equals ActiveLevelFXName, DT_Levels supplies LevelFXRow_Day, LevelFXRow_Night,
and the localized SectorName FText. Other preferences use DT_LevelFX names
and an optional `_Night` row. Only a changed day or night row requests
TransitionToNewEnvironmentFX. Therefore a table match alone is not evidence
that the visible HUD text just changed.

SetNewEnvironmentFXVariables (2419 bytes) assigns Location_CurrentSectorName
from its SectorName argument. It compares current and previous sector text
using NotEqual_IgnoreCase_TextText, stores Location_FoundNewSectorName, and
updates the previous name on change. The controller's display event at 2779
passes Location_CurrentSectorName to the HUD. The surrounding graph includes
a four-second retriggerable delay. Transition timing and override behavior
are not yet reproduced by Sophia.

**Observed:** permanent sector_table_research exported 64 DT_Levels rows using
current reflected declarations. Each row retains the level filename, row name,
sector text, and day/night FX row names. The generic table dumper used stale
declarations, so its output was rejected. The test reads the table and calls
only the pure KismetTextLibrary.Conv_TextToString conversion, with its verified
32-byte parameter buffer (16-byte input FText and 16-byte output FString).
The existing mod installation was not changed.

sector_client_research captured the normal controller's ActiveLevelName,
selected FX row, current sector text, and override/day/night fields. The
observed normal path was:

| Field | Observed value |
|---|---|
| ActiveLevelName | Facility_Office3 |
| ActiveLevelFXName | Office3 |
| Location_CurrentSectorName | The Office Sector |
| Day_FX_Row / Night_FX_Row | Office3 / Office3_Night |
| Cheat, explicit override, weather, sub-FX | All None |

The Rust client now contains the table lookup in
abioticfactor-client/src/levels.rs. It preserves table order, matches the
current build's ASCII asset names case-insensitively, and returns no match
instead of inventing a fallback. The offline test in
abioticfactor-client/tests/sector.rs consumes both research exports and matches
the observed row, sector, and day/night settings. It fails if the observation
has a higher-priority override. This is table-lookup parity for the captured
normal-client state, not Sophia's location or complete HUD behavior.

Artifacts under target/abioticfactor-client:

- sector-level-component.txt, sector-overlap-symbol.txt,
  sector-on-loaded.txt, sector-check-streaming.txt, sector-set-visible.txt.
- sector-fx-character.txt, sector-level-change.txt, sector-determine.txt,
  sector-selection.txt, controller-full-trace.txt.
- sector-table.json and sector-client-snapshot.json contain names and values,
  without process addresses. They are current-build research exports, not
  automatically refreshed runtime data.

**Remaining integration:** Sophia does not yet load this table in her session
or select her own level. The Rust selection rule now exists and passes the
captured-input comparison below. Reproduce actor overlap using the shipped volume
collision, transforms, and character collision configuration, then implement
the level manager's loading/visibility history and iteration order. Feed that
selection into the verified table lookup. Do not use the human controller's
selected level as Sophia's, substitute the host's loading history, or treat
missing local world data as an empty overlap list. Runtime position and
gameplay state remain UDP; HTTP remains research only.

### Native level selection reproduced in Rust

**Verified, 2026-09-12:** sector_level_selection_research resolves the normal
controller's world through its outer chain. Native GetComponent at RVA
0x46DD320 identifies the manager through world GameState (+0x160) and its
level-manager component (+0x438). A direct first-class component lookup had
resolved an uninitialized template; it is not used as the world manager.

The permanent test captures initialized LevelArray entries using their actual
sparse-map allocation bits and iteration order. It reads each instance's
LastTimeVisible and world asset, then queries each volume's existing
IsOverlappingActor result for the controller's PlayerCharacter. The reflected
query buffer is nine bytes: Other pointer at zero, return boolean at eight.
The test validates this declaration before issuing the pure query.

The capture contains 59 level instances. In the observed state, only
Facility_Office3 matched, through AbioticLevelStreamingVolume_14. Rust's
find_latest_level in abioticfactor-client/src/levels.rs selects that level
from the captured overlap flags, times and order; the existing table lookup
then yields The Office Sector, matching the normal controller. Two offline
sector comparisons and 21 client library tests pass.

The Rust rule preserves the exact initial constant, double subtraction followed
by float conversion, equal-age first-entry behavior, null-world age zero, and
the distinction between no matching instance and a selected instance with an
empty asset. The regression scenario covers two overlapping levels, later
visibility winning, native-order ties, and different differences rounding to
the same float age. The live capture had one matching level, so that capture
alone does not verify selection among several simultaneous matching levels.

The test rejects a changed map header or changed controller sector snapshot
during capture. HTTP reads and overlap queries span multiple frames; they are
not an atomic engine snapshot. The recorded times and overlaps support an
offline comparison, not a replacement source of Sophia's runtime state.
sector-level-selection.json retains pointer-free inputs and observations.

### Character shapes contributing to level overlap

**Decoded:** AActor::IsOverlappingActor at RVA 0x329AC30 iterates owned
components and consults their maintained overlap state. UPrimitiveComponent's
OverlappingComponents array is at +0x340. This build's FOverlapInfo is 256
bytes, containing its 248-byte FHitResult at +8. The native
ULevelManagerInstance::IsLocationInLevel at 0x47134B0 is a separate point-query
path through the volume's brush; the controller's sector selector does not
use it. Replacing actor overlap with that point query changes the algorithm.

**Observed:** GetOverlappingComponents on volume _14 returned two components
belonging to the observed player, alongside other actors' components. The
permanent capture retains only the observed character's components:

| Component | Shape and attachment |
|---|---|
| CollisionCylinder | Capsule, unscaled half-height 96 and radius 32; no attach parent; scale (1,1,1) |
| OverlapTrigger | Sphere, unscaled radius 10; attached to FirstPersonCamera with zero relative location/rotation and scale (1,1,1) |

UCapsuleComponent's dimensions are at +0x548 and +0x54C, confirmed by PDB.
SphereRadius and scene transforms are read using current reflected fields.
The capture records relative location, rotation, scale, and attachment name;
it does not yet compose the camera's parent chain. The camera-attached sphere
must be accounted for when reproducing this character's actor overlaps.
This observation does not establish that these are its only possible collision
contributors across crouching, vehicles, spectating or other gameplay states.

**Next collision work:** the captured normal-state transforms and convex overlap
comparison now pass as described below. Collision filters, overlap-update
conditions, live boundary and multiple-level comparisons remain required
before treating this as complete Unreal overlap behavior.

### Local Facility collision comparison

**Verified, 2026-09-12:** abioticfactor-client/src/collision.rs loads the
extracted Facility volume/brush/BodySetup references and constructs convex
collision shapes from their vertex data. It uses the existing Rust Parry
collision library, pinned to parry3d-f64 0.27.0. The implementation was checked
against that version's source for convex hull construction, capsule endpoints,
and intersection queries; it does not implement a custom GJK solver.

Element rotation, translation and scale are applied to the convex vertices,
followed by brush scale and rotation. Translation remains in the shape pose
to keep hull coordinates near their origin. This preserves rotated and
nonuniformly scaled convex geometry rather than substituting an axis-aligned
bounding box. The map's scene-property defaults for omitted transforms are
checked against all captured Facility brush transforms.

PDB confirms USceneComponent::ComponentToWorld at +0x1D0 and its 96-byte
TTransform<double> layout: quaternion at +0, translation at +0x20, scale at
+0x40. Permanent HTTP research captures these cached world values, relative
transforms, absolute-transform flags, attachment names and socket names. The
test reconstructs the character shape world transforms from relative values
and compares every step with the engine's cached world transform.

The observed normal attachment chain is:

`CollisionCylinder -> CameraHeadJoint -> FirstPersonCamera -> OverlapTrigger`

The head joint has a relative height of 72 and the observed view pitch.
Camera and overlap sphere have zero local translation/rotation and unit scale.
The sphere center was 72 above the capsule center in the captured state.
This is an observation of that character state, not a universal camera-height
constant. Crouching and other camera changes still require their real inputs.
The supported attachment comparison rejects sockets, absolute transform
overrides and nonuniform parent scale instead of guessing their behavior.

Capsules use the game's radius and half-height, with uniform positive scale.
Unreal's capsule half-height includes its hemispheres; Parry's central segment
half-length is therefore half-height minus radius. The sphere uses its radius.
Unknown shape classes, missing character geometry and unsupported shape scales
fail instead of becoming empty collision results.

**Earlier Office3 comparison:** facility_collision_matches_real_client_overlaps passed
for all 223 volume transforms and all 223 actor-overlap booleans. Two character
shapes reconstructed in Rust overlap only AbioticLevelStreamingVolume_14, the
same result as that captured normal client. That run replaced the saved level
overlap flags with locally computed intersections, ran the verified
level selector with captured registration order and visibility history, then
looked up the table row. Its observed result was:

`local convex collision -> Facility_Office3 -> The Office Sector`

The live level manager contains 222 registered volumes across 59 instances.
The world and map contain 223. AbioticLevelStreamingVolume_61, pointing to
Vignette_Theatre, exists in the world but was absent from this manager's list.
Its map export has bDisabledForDemo=true. Decoded InitializeLevels (0x4712590)
skips such volumes when IsDemoMode returns true; the permanent research query
observed true. This accounts for Theatre's exclusion despite its streaming
entry being present in the world. Research queries its collision separately.

The integration test uses actual cached transforms only for comparison; its
collision inputs use the reconstructed relative attachment chain and the
offline map geometry. Visibility times remain captured inputs; registration
now comes from the map and explicit demo-mode input. All computation after
capture is Rust and offline. No Sophia
movement, reconnect, mod deployment or host transformation was performed.

Verification at the Office3 checkpoint: permanent sector_level_selection_research
and the offline collision-to-sector comparison passed; all 23 client library tests passed,
including rotated-box false-positive rejection and capsule hemisphere height.
Artifacts: sector-scene-layout.txt, sector-transform-layout.txt,
sector-level-selection.json and collision-results.txt under the existing
target/abioticfactor-client research directory. The latest capture replaces
sector-level-selection.json and fails the collision comparison as described
below; this earlier pass does not describe the latest capture.

**Limits:** this is one recorded normal-player pose with one matching volume.
Parry's geometric intersection is not a claim of identical Chaos contact
tolerances, collision filtering, cooked hull internals or overlap-event timing.
Live boundary comparisons, multiple simultaneous levels and changed character
states remain open. Sophia must supply her own poses and local level lifecycle
inputs from assets and UDP before this becomes her runtime sector observation.

### Static level registration from the map

Decoded InitializeLevels iterates World.StreamingLevels (+0x88) in array order,
constructs instances, then enumerates volumes with the demo gate above.
RegisterLevelStreamingVolume (0x471AEF0) assigns each eligible volume to the
first instance with the matching soft world path. Instance registration is
0x471B1A0. Later visibility transitions remain a separate local lifecycle.

The Rust map reader now exports the World's native reference lists after its
properties: four-byte zero prefix, persistent level, extra-object array, then
streaming-level array. This agrees with UWorld::Serialize (0x3DE1F90) and the
existing unreal_asset World reader. Facility consumes all 258 payload bytes,
with 59 streaming references and no trailing bytes. Export-file order differs
from this explicit list and must not substitute for it.

The client registration function reads that list, resolves soft paths and
applies the demo gate. facility_registration_matches_real_client passes:
all 59 names match native order and all 223 volume registration decisions
match the captured manager. Explicit full/demo inputs produce 223/222 entries
respectively, including/excluding Theatre through its flag, not its name.
This removes captured registration from the collision-to-sector computation;
captured visibility times and normal-player pose are still research inputs.

Evidence: sector-initialize-levels.txt, sector-register-component-volume.txt,
sector-world-serialize.txt, facility-parsed.json and sector-level-selection.json
under target/abioticfactor-client. The pure IsDemoMode query is part of the
permanent sector snapshot test; no gameplay call or mod deployment is needed.

**New capture limitation:** subsequent Office1 and Office2 captures fail the
attachment reconstruction comparison (translation, then rotation). Reads of
the chain and cached transforms are separate, so movement during capture is a
possible cause, not yet proved. Do not relax comparison tolerance or claim
current full collision parity. Capture related values together and establish
transform update timing before the next collision acceptance run. Registration
parity is independent of those changing player transforms and passes.

### Consistent character capture, live comparison passed

Source inspection confirmed the old test issues separate read_bytes requests
for each component and attachment. That operation copies memory on the HTTP
thread; the old test cannot establish a common game update for those reads.
This establishes a capture defect, not the cause of every observed mismatch.

Ueforge now provides read_snapshot: 1..64 ranges, at most 1 MiB combined,
read in one game-thread queue job. It refuses an unserved queue instead of
falling back to the HTTP thread. Each range retains read_bytes validation;
the result includes the game frame and game_thread=true. The operation reads
memory only and accepts no gameplay calls or writes.

The permanent sector_pose_snapshot_research test discovers the character's
components, then reads their headers, parents, sockets, local/cached transforms
and shape sizes together. It checks names and attachment links against the
discovery and rejects changed attachments. The output is the distinct research
artifact sector-pose-snapshot.json, retaining the old comparison capture.
character_attachments_match_same_update_snapshot checks every attachment using
the existing strict transform comparison and constructs both character shapes.

**Scope:** only the character pose and shape sizes share the queue job. Level
times, controller sector and actor-overlap queries still come from discovery
reads. Do not feed this artifact into a full collision acceptance as though
all world state were simultaneous. First establish whether coherent character
reads resolve the attachment mismatch; then capture overlap/selection inputs
together if required for movement-time collision comparison.

**Verification:** mod DLL and research test build; the snapshot aggregate-cap
and overflow test passes. Before installation, the live test returned
`unknown op 'read_snapshot'`. After the user's restart, the permanent live
sector_pose_snapshot_research test passes, followed by the offline
character_attachments_match_same_update_snapshot test. Captured frame 70043:
both character shapes and every attachment transform pass the existing strict
comparison. Normal controller reports V_FOG / Flathill. This is the normal
player's research observation, not Sophia's reported location.

The consistent capture resolves the mismatch for this pose. It does not prove
the exact cause of the earlier Office1/Office2 failures, nor establish full
collision parity while moving. No tolerances were relaxed.

The user authorized installation on 2026-09-12. Installed the built DLL as
AbioticFactorMod/dlls/main.dll for the next game restart; preserved the previous
image as main-before-read-snapshot.dll in the same directory. Verified installed
and backup SHA-256 hashes against their source files. New image SHA-256:
F68F7D34478ED980623B7B729E803377B68EF960BD7310D160F4F0D95F1A70FD.
The agent performed no hot reload, game restart or Sophia reconnect. The next
user-requested live run confirms the updated operation is available and works.

### Sophia's own camera inputs

The new UDP correction observation supplies some body-state inputs, documented
in lan-rpc.md. It does not supply a complete camera pose, crouch state or local
visibility history. The earlier observed capsule radius 32/half-height 96 and
head offset 72 must not become unconditional runtime constants.

Permanent character_pose_functions_research exports the actual Blueprint
function catalog to character-pose-functions.json. Targeted class_blueprint_research
fully decodes the 3518-byte Update Head Joint Location Rotation function into
character-head-joint-trace.txt. Both research tests pass. They inspect code;
they do not execute this gameplay function.

Decoded dependencies and branches:

- Bytes 21..453: read FPArms' Head socket rotation and apply camera-shake amount
  to derive HeadRotation.
- 459..500, 1696..1737: death and downed-state camera-height branches.
- 1738..1913: performing-emote row from DT_Emotes can override camera height.
- 2431..2476: sitting uses SittingEyeHeight; the chair-specific branch at
  501..1207 additionally handles the chair actor and camera world rotation.
- 2477..2698: query actual crouching and advance CrouchAlpha with world delta
  seconds and CrouchInterpSpeed. 2699..3514 also uses falling state, crouched
  capsule half-height, BaseEyeHeight and CrouchedEyeHeight to compute HeadLocation.
- 1914..2430: combine camera height with scaled capsule half-height, apply
  Size_Multiply, and clamp using FMin/FMax.
- 1208..1695: ordinary camera rotation uses gravity-relative control rotation,
  sitting-dependent yaw, HeadRotation and GetFinalSwayRotation with ScopeSwayRotation,
  then sets CameraHeadJoint's relative location and rotation.

This identifies why a fixed coordinate offset is insufficient. Exact height
expression constants, default component assets, replication of the branch
inputs and local animation/sway updates still need implementation evidence.
Server body rotation is not itself the camera's control rotation. Native
visibility timestamps also belong to Sophia's local loading lifecycle, not
the human host's observed history. Matching the client's selected HUD area
remains unfinished; the coordinate-based map report below is now operational.

### Sophia's UDP coordinate location report

The standalone binary now loads Facility collision geometry and DT_Levels from
the persistent profile's map directory. The `where` command combines Sophia's
last received UDP position with actual convex-volume point containment and the
game's level-to-sector table. A new position also prints the report automatically.
No HTTP, human-controller observation or fixed camera/body offset participates.

The report names every containing map region, grouped by level, with sector
names where the game table supplies them. It uses the full extracted geometry,
including volumes excluded from a particular local level manager. No matching
region is reported explicitly; multiple regions are all retained without a
guessed winner. A different server world is rejected instead of applying the
Facility geometry to it. This is a geometric coordinate report, not a claim to
reproduce the controller's capsule/camera overlap or selected HUD/FX level.

Map inputs are facility-parsed.json and sector-table.json under
%LOCALAPPDATA%/Modforge/Sophia/map (or SOPHIA_HOME/map). The installed copies
were hash-verified against the researched exports. `locate <world> <x> <y> <z>`
runs the same lookup for explicitly supplied coordinates without connecting.
That output is labeled as supplied coordinates, not a live Sophia observation.

**Live result, 2026-09-12:** old session 77428 had exited with HostClosedConnection.
Started the updated binary once, session 71760, with Sophia's existing profile.
Initial actor-open position (-14157.6,14850.3,21655.3) had no containing volume.
After normal spawn, a zero-acceleration UDP move obtained an absolute correction:
(-17111.80368023579,13396.1879664876,208.15000039223014). Both automatic output
and `where` reported The Office Sector (Facility_Office1). The `state` command
reported zero velocity, absolute velocity flag, omitted rotation/gravity and
packed movement mode 1. No walking command was sent. Sophia remains connected.

This also corrects an earlier test assumption: Sophia's recorded September 12
coordinate is Office1; Office3 belonged to the separately captured human pose.
The actual map query establishes that distinction. The live result concerns
the last server correction, not continuous position freshness while idle.

Verification: binary build, 25 library tests and the standalone location
integration test pass. Tests cover rotated-hull containment instead of axis
aligned bounds, recorded Sophia coordinate-to-sector lookup, unknown world,
nonfinite coordinates, no containing volume and the executable's offline path.
Live join and the location report use UDP only. Moving-base/root-motion
coverage and exact local HUD selection remain open.

### Navigation after coordinate location

User direction: reuse the navigation work from the other projects to find an
A* route and move Sophia along it. Modforge route.rs owns the shared Path,
GameNavigation, steering, arrival, stuck detection and Bot. Ueforge nav.rs
currently asks the running engine for a navigation path. Updated user decision
2026-09-12: run Sophia's Rust UDP client inside the host mod and use the host's
loaded world and dynamic navigation mesh for path queries. This replaces the
standalone local navigation provider plan. One game client remains sufficient;
Sophia still joins as a separate LAN player through the existing UDP protocol.
The shared path follower's control decisions must reach her own UDP movement
messages. HTTP remains a research comparison instrument only.

The extracted sector volumes support coordinate naming, not walkability.
Next work is embedding the existing UDP client with clean connection ownership,
then engine path queries for Sophia's agent and a bounded destination test.
Engine queries run on the game thread; socket work must not block it. A line
through region volumes must never be treated as a traversable path.

**Movement acceptance blocked on death, 2026-09-12:** session 71760 accepted a
two-second +X command and sent the final zero acceleration, but no new server
correction was observed. A subsequent stop also yielded no new correction.
Permanent sophia_movement_state_research identifies the controller by the
PlayerState name Sophia and reads only its character. It confirms IsDead=true,
IsDBNO=false, IsDisabled=false, both loading flags true, movement mode 1 and
unchanged position (-17111.80368023579,13396.1879664876,208.15000039223014).
Boolean values use the actual FBoolProperty mask; PDB layout is FieldSize
+0x70, ByteOffset +0x71, ByteMask +0x72, FieldMask +0x73. Both research tests
pass. Evidence: sophia-movement-state.json and boolean-property-layout.txt.
Death cause is unknown; this does not establish every cause of absent move
responses. Normal death/respawn must be handled through UDP before live path
acceptance. No HTTP revival or transform write was performed.

### Saved navigation data, 2026-09-12

The standalone map reader now decodes the current RecastNavMesh and
NavMeshBoundsVolume properties, including native NavAgentSelector and
SoftClassPath values and static property arrays. Its native navigation summary
reads the UObject GUID flag, cooked actor label, navigation version, bounded
mesh size and tile count. Every mesh size ends exactly at its export boundary.

Facility contains 62 RecastNavMesh exports, all version 26, all with zero saved
tiles. The separately extracted Facility_Office1 package contains neither
RecastNavMesh nor RecastNavMeshDataChunk exports. These packages therefore do
not supply a saved polygon graph for A*. This does not establish the contents
of every other streamed level.

The permanent navigation_generation_research HTTP test reads RuntimeGeneration
using current reflected offsets and resolves its enum through the shipped PDB.
All 50 observed live mesh instances report Dynamic (2). This supports runtime
mesh generation, not loading a complete baked mesh from these two packages.
The test only reads settings; it does not generate a mesh or request a path.

The following local-generation plan is superseded by the host-mod UDP decision
above; retain the package findings as research evidence.
The former next local-data task was to identify the game's navigation geometry inputs,
agent configuration and modifiers, extract them from Office1, and reproduce
walkable mesh generation locally. Office1's streaming transform translates by
(-12000,12500,0); local geometry must use that transform before comparison with
Sophia's world coordinates. Then local A* can feed the shared path follower,
with movement and progress observation over UDP. No A* path is implemented or
accepted yet. Doors and other dynamic obstacles require their own observed
state; empty navigation data must never fall back to an assumed straight line.

Format references inspected through GitHub CLI:
[CUE4Parse UObject](https://github.com/FabianFG/CUE4Parse/blob/master/CUE4Parse/UE4/Assets/Exports/UObject.cs),
[AActor](https://github.com/FabianFG/CUE4Parse/blob/master/CUE4Parse/UE4/Assets/Exports/Actor/AActor.cs),
[ARecastNavMesh](https://github.com/FabianFG/CUE4Parse/blob/master/CUE4Parse/UE4/Assets/Exports/NavigationSystem/ARecastNavMesh.cs),
[FScriptStruct](https://github.com/FabianFG/CUE4Parse/blob/master/CUE4Parse/UE4/Assets/Objects/FScriptStruct.cs).
Permanent checks: parse_facility_map, extract_office1_navigation and
navigation_generation_research. Artifacts under target/abioticfactor-client:
facility-parsed.json, office1-parsed.json, navigation-generation.json.

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
