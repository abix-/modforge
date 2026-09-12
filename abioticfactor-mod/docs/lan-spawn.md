# LAN possession, character creation, and spawning

[Research index](abiotic-factor.md) | [Todo](todo.md)

## Possession and the first spawn: who does what

The owning client and server each have their own controller/pawn objects. A
locally assigned reference does not initialize the corresponding server field.
The controller's replicated Pawn is also distinct from its gameplay
PlayerCharacter reference.

**Decoded owning-client path:** controller Local_WaitForLocalPlayerReplication
enters bytecode 51640 -> 4201. It calls K2_GetPawn, casts to
Abiotic_PlayerCharacter, calls that pawn's Local_BeginPlay (4322), and only then
sends Request_ConfirmCharacterReplication (4336). Failed casts take a 0.5-second
latent delay back to 4201. Pawn Local_BeginPlay (105114) assigns the owning
controller's MyPlayerCharacter and PlayerCharacter (105243, 105276), binds level
load/unload callbacks, and evaluates owning-level loading. Rendering/UI work in
that routine is local; it is not an instruction to create a host-side player.

**Decoded server path:** pawn ReceivePossessed enters 11354. It validates the
new controller's PlayerState and casts it. If unavailable, 12098 delays 0.2
seconds and resumes at 11373. Once valid, it executes in this order:

1. Assign pawn MyPlayerState (11549) and mark it for replication.
2. Assign pawn MyPlayerController (11672) and mark it for replication.
3. Assign controller MyPlayerCharacter (11720) and PlayerCharacter (11753) to this pawn.
4. Set/replicate the overhead name, refresh the server's player-character list.
5. Call controller Request_SpawnMeInWorld with MyPlayerState (12060).

**The server initiates the first spawn.** The normal client's replication
confirmation is a prerequisite, not a substitute for the server possession
handler. Request_ConfirmCharacterReplication enters controller 51645, sets
ClientHasRecievedCharacter=true, and returns at 51656. It does not assign the
server character references or spawn anything.

The server spawn wrapper enters 38482 -> 4526. If confirmation is still false,
7548 prints a waiting message and 7667 delays 0.5 seconds before retrying 4526.
This is a yielding wait. The client can confirm replication before the server
possession continuation runs; it must not issue a premature independent spawn
request. The server handles the ordering through its own possession path.

Engine possession acknowledgment is separate: ServerAcknowledgePossession
(controller RPC 72) supplies the pawn GUID. Its native implementation stores
AcknowledgedPawn at +832; it does not initialize Abiotic's PlayerCharacter at
+2144. ServerNotifyLoadedWorld (RPC 80) supplies the loaded world name.

## Saved character, new character, and trait completion

| Phase / predicate | Decoded server behavior | Client obligation |
|---|---|---|
| Client replication not confirmed | Yield 0.5 seconds, retry spawn gate | Confirm receipt of the actual possessed pawn |
| Saveable game | LoadPlayerSaveData (4622), inspect returned saved-data state | Preserve durable ID; do not fabricate saved state |
| Eligible saved character | Apply Save Data to Character (4735), Client_SetupCharacter (4865), select saved/world-start position | Process setup and loading messages; do not send another first-spawn RPC |
| No eligible initialized saved character | Client_DoTraitSelectionSequence (6334) | Perform requested character creation, rather than assuming saved skills imply a new creation request |
| Selected traits | Server_SetupInitialTraits enters 38492; sets PhD, validates character, SetTraits and Request_ResetAllSkills; delays 0.2 seconds | Wait for server completion before the post-creation spawn request |
| Trait continuation | 12248 -> InitializeTraits; HasSetUpSkills=true at 12579; SavePlayerData at 13021 | Use replicated completion for the requested creation flow, not an unconditional saved-character spawn trigger |

An early trait RPC can return at the failed character cast (38870); receipt of
the RPC is not completion. A repeated server trait prompt must still receive
a response. The current decoded player-state property handle for
HasSetUpSkills is 30. Its value alone does not distinguish a restored character
from newly completed trait selection.

**Open:** customization, intro completion, and every save-eligibility predicate
still need tracing. The earlier visible run demonstrates the implemented Intern
selection path, not every creation option or reconnect case.

## Decoded trait-widget confirmation (2026-09-12)

The permanent class_blueprint_research HTTP test decoded all 4568 bytes of
ExecuteUbergraph_W_Character_Trait_Selection. Artifacts are
target/abioticfactor-client/trait-widget-trace.txt and trait-complete-trace.txt.
This reads class code; it does not create a widget or submit traits in the host.

1. Controller Client_DoTraitSelectionSequence wraps 38487 -> 23175. It creates
   W_Character_Trait_Selection_C at 23217, sets InitialJobSelect=true, adds it
   to the viewport, selects UI-only input, and sets TraitSelect effects.
2. The confirmation popup binds PopupYesSelected at 1446. Its entry 4119 calls
   CompleteTraitSelection, which wraps 4114. This disables the widget, hides
   the cursor, switches to game-only input, displays progress, and enters 3578.
3. After casting the local controller, Map_Keys at 3712 extracts TraitsAndPoints.
   Server_SetupInitialTraits at 3762 receives Selected_Job, those map keys, and
   EnteredAmnesiaThreshold.
4. EnteredAmnesiaThreshold=true returns without the creation spawn continuation.
   Otherwise Delay at 3818 uses float 0.3 and resumes at 15. That continuation
   obtains PlayerState, calls Request_SpawnMeInWorld at 124, resets effects,
   removes the widget, and calls Try_SpawnIntroSequence at 272.

**Distinction from the bot:** the widget does not wait for HasSetUpSkills
replication. The bot's completion gate is an implementation choice based on
the server trait continuation, not a literal copy of the widget. Re-selection
with an already-true skills flag remains unproved. This property is not an
explicit acknowledgment of a particular trait request.

## Placement and the host-freezing failure

For an eligible saved character, LastSafeWorldLocation is compared exactly with
the zero vector at 4898. A nonzero location branches to 7722 and calls
TeleportPlayer with the saved location at 7917. A zero location enters 4987,
gets Abiotic_WorldStart actors, chooses one with Array_Random, obtains its
location, and calls TeleportPlayer at 5365. HasRecentlyTeleported is set before
placement. Failed world-start placement branches 5424 -> 8646, increments the
attempt count, then jumps 8861 -> 4987 without a latent wait.

This retry assumes the server character reference is valid. Our immediate UDP
spawn request violated that prerequisite and stranded the game thread before
the server possession continuation could run. The next section records the
live proof. A fixed delay, a renamed identity, or disabling the mod would not
implement the game's actual sequence.

## UDP saved-character spawn freeze (2026-09-12)

At the time of the freeze, the standalone client sent possession acknowledgment, replication
confirmation, and Request_SpawnMeInWorld together after receiving its pawn and
player-state actors (`abioticfactor-client/src/login.rs`). Receiving these actors
does not establish that the server controller's PlayerCharacter is initialized.

User-authorized diagnosis of the fresh-session freeze captured game thread 18132
inside Sophia's Request_SpawnMeInWorld, called from FObjectReplicator::ReceivedRPC.
Repeated native stack captures moved through the same controller Blueprint while
the game tick stayed at 8537. HTTP continued responding independently.

The permanent `abioticfactor-mod/tests/http_health.rs` diagnostic unwinds the
thread externally with read-only process access, briefly suspending and resuming
it for the stack capture. `tests/common/spawn_trace.rs` follows the identified
cooked bytecode and reads only named spawn state. The diagnostic passed.

Confirmed state and control flow in this game build:

- Controller PlayerCharacter (+2144) is null; the local TeleportPlayer result is false.
- The world-start actor array contains nine actors, so absent starts are not the cause.
- The saved-location-zero path enters the world-start retry at bytecode 4987.
- Failed teleport branches at 5424 to 8646, increments PlayerSpawnAttempts
  (+4544), then jumps at 8861 back to 4987 without yielding.
- The attempt counter exceeded 280 million and increased during capture.
- The greater-than-ten-attempts input cannot help because the character reference
  through which teleport would be called is null. The host cannot return to tick.

This establishes a premature spawn request triggering an unbounded game retry
loop. A previous connection is not required: a fresh host with no old bot also
froze. Female customization had not been sent. The decoded normal sequence is
documented above. The client now leaves first spawn to the server possession
handler and only requests post-creation spawn after a requested trait flow and
server completion. Build and 16 local tests pass, including both regression
cases. Fresh-host in-game acceptance remains open. No deployed mod change is
part of this fix.
