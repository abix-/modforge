# Modforge project state

## Current focus

Sophia now uses Modforge_AIPlayer_C, an actual direct subclass of
NPC_Base_ParentBP_C, with Abiotic_AI_Controller_ParentBP_C. Normal start and
respawn both use this custom type. Ueforge owns native class creation,
configured spawning and deep property copying. Abiotic owns the human mesh,
NPC_Coworker_AnimBP rendering asset, baseline stats and melee assets. The
custom class defaults own the melee map; replacement no longer copies from
the donor Grunt CDO, which became unavailable during repeated-spawn testing.

Release build: 2026-09-13 20:45:42. Verified live: custom class inheritance
(base NPC yes, Grunt no), Follow within 150 units, walk speed 260, knife
attachment and native Sharp damage, Passive, explicit Attack, self-defense,
Recall, saved orders across respawn, destruction/GC and replacement.
The generic derived class contains no Rust callbacks and is rooted for the
process lifetime. Character appearance customization remains deferred.

Remaining acceptance: aggressive sight/chase test fails in the current
multi-level location. The Pest was observed falling about 400 units below
Sophia; a revised same-floor fixture also failed to acquire its intended
enemy, so no final cause or passing aggressive regression is claimed.
Human-protection acceptance is blocked by Abix being dead (IsDead=true,
TotalCombinedHealth=0). Normal bed/origin respawn requests did not complete.
Asked the user what the game currently shows; no answer yet. Do not replace
this with a guessed fix or report all controls accepted. Self-defense through
the new native Actor damage observer passed independently at 20:41:33.

Next: finish a valid sight encounter and human-protection acceptance when the
human is alive. Keep exploration, inventory and skills out of this change.
The general permanent class-cache lifetime assumption is recorded in todo;
the custom type's asset ownership and replacement were verified through GC.

Earlier live fix, 2026-09-13 19:12: Sophia was assigned Follow Abix but blocked
by "Actor.ReceiveAnyDamage unavailable". The damage observer looked for an
inherited event on the concrete Blueprint class; get_function searches only
the declaring class's children. It now resolves Actor first. Release build,
deployment and saved-world restart passed. The focused live follow test passed:
147.4 horizontal units from Abix against a requested radius of 150. Sophia is
left following with her existing Aggressive stance. This proves observer
initialization and following, not the still-pending damage-response acceptance.

The single Sophia readiness table is at the top of abioticfactor-mod/docs/todo.md.
It records category, evidence/gap, done condition and an assessed score out of ten.
Scores distinguish limited historical live proof from pending latest-source
acceptance. Update that table rather than creating another readiness summary.

User requested documentation and code alignment with persistent AI players.
Companion describes Sophia's allied role. After reliable controls, Sophia
should explore and collect resources independently. A later persistent enemy
should reuse the same capabilities, remember encounters and react to the human
and Sophia. Autonomous goals and adaptive decisions are future work.

The shared order module is now modforge/src/ai_orders.rs (OrdersDef and
OrdersTracker). Ueforge owns AiOrderExecution and ui_ai_orders. Threats are
relative to self or the protected player, not an assumed human alliance.
The Abiotic order adapter accepts initial orders; the current allied spawn
operation supplies Follow/Defensive defaults and copies the human faction.
Saved orders and the command API keep their existing format. Persona remains
the persistent identity and observation owner; no second memory system was added.

Verification for this alignment: all six ai_orders decision tests pass,
including defense and return to Hold without a human to protect. The Abiotic
mod development build passes. No live deployment or enemy implementation is
claimed for this refactor. The pending order implementation and unrelated work
remain uncommitted.

Sophia's baseline is the human Grunt NPC with a default kitchen knife and
doubled walking speed (130 to 260). Earlier live tests established Hold,
Passive, explicit Sharp damage, Recall, saved-order respawn, groups, defense,
and aggressive sight/chase limits. Native damage observation and the subsequent
hostile-character/friend filter still need final live acceptance. The last
restart reached HTTP readiness then lost its connection while hosting; its
cause is not established. Earlier cleanup tests passed after garbage collection,
but the historical crashes are not all diagnosed.

Existing npc-ai.md owns the design and evidence; todo.md owns the remaining
work. Finish current controls before autonomous exploration/resource collection,
then implement the recurring enemy. Command eligibility, return-after-defeat
rules and experience-driven progression must be established before enemy release.
Inventory ownership, durability and finite ammunition remain unimplemented.

## Design goals

- Persistent AI players share identity, memory, perception and actions. Ally/enemy relationships and command eligibility are distinct from combat stance. Sophia's autonomy comes first; a recurring, adapting enemy follows using the same capabilities.
- Sophia runs in the host mod with an NPC body and its native combat AI. Preserve her persona; copy the human faction during spawn. UDP/player-body work is superseded for this companion.
- `docs/bot-navigation.md` owns one engine-independent bot-navigation system for both Unreal and Unity. Modforge owns routes, waypoints, the shared path and observation formats, player-input decisions, arrival, failure, and release. Ueforge and Unityforge only return engine paths and observations and inject the selected player input.
- Topside-style fixed-tick journals remain authoritative for simulations Modforge owns.
- Injected games use the same producer and consumer separation, but replay operation actions through the existing control plane and advance only after observable condition gates.
- MISERY is the first proof: record a movement-speed write, wait for the live read, assert it, restore the original value, and replay the saved journal.
- A waypoint is a meaningful stop for arrival, observation, action, or branch selection. Navigation does not record the positions walked between waypoints.
- The first MISERY route is exactly `spawn -> metal-door -> expedition-door`. The metal-door waypoint opens the bunker door only when closed; the expedition-door waypoint interacts and waits until expedition entry is observed.
- There is one pathfinding level. The route or current action selects the next meaningful waypoint. Unreal navigation's A* searches the navigation mesh from the player's current position to that waypoint and returns the detailed path points. Durable waypoints are stops and goals, not A* search nodes.
- A waypoint is usable only when Unreal navigation returns a valid, complete path to it. An unobserved straight line through the 3D world is never assumed walkable.
- MISERY target discovery runs once through Unreal's world actor enumeration and retains actor, inventory, class, function, and widget pointers for the current world. Navigation, interaction, and observation loops never walk the global UObject list or rediscover function layouts.
- Every MISERY bot command runs inside the game process through one registered `InputSurface`. That surface injects virtual W/A/S/D state, relative mouse movement, and `E` press/release into Unreal's normal player input processing. The game applies its existing bindings and performs movement, view rotation, and interaction. Direct movement, look, interaction-handler, navigation-movement, transform, physical mouse, window-focus, and OS-global input paths are forbidden.
- Generation loading, hot reload, rollback, shutdown, and bridge lifetime have one implementation in `cs-shim-common/GenerationLoader.cs`.
- Each C# shim retains only its loader integration, logging, backend bridge, and host-specific frame callback.
- Every Grounded 2 source function explains its player-facing purpose and its verified ownership boundary with Modforge and Ueforge.
- Every Schedule 1 source function explains its player-facing purpose and its verified ownership boundary with Modforge and Unityforge.
- Modforge owns engine-independent coordinate decoding, lowest-level automatic skill spending, timestamped recent-key tracking, and bounded trace storage.
- Unityforge owns managed bridge-value decoding, managed-handle wrapping, and guarded main-thread Effect dispatch.
- Schedule 1 retains its class and field names, NPC identity, timing windows, crash-bisection flag, labels, effect configuration, rewards, and war policy.
- Item definitions have one authority: `ItemDef` and `ItemRegistry`.
- Uniqueness is an `ItemDef` property, not a parallel definition type or registry.
- Per-save entered and holder state belongs to the item ledger in `modforge::item`.
- Survivalist retains entry rules, Unity bindings, prototype and inventory access, delivery, logging, and chronicle text.
- Upgrade levels, policy math, schema, and persistence have one engine-independent authority in `modforge::upgrade`.
- Survivalist retains upgrade applicability, menus, material consumption, Harmony effects, save-path selection, and game-object access.
- Mission lifecycle advancement, explicit stage transitions, timeout dispatch, collection removal, error routing, and guaranteed cleanup belong to `modforge::mission`.
- Mission stage data and all Unity checks, intents, outcomes, voting, judgment, chronicle text, logging, and concrete handle cleanup remain in Survivalist.
- Franchise tallying, strict-majority decisions, mean scores, and voter identity collection belong to `modforge::genome`.
- Trait, voter, and collective reinforcement fan-out belongs to `modforge::genome`.
- Survivalist retains voter eligibility, conscript exclusion, trait projections, thresholds, actions, outcome judgment, trait selection, reinforcement direction, and magnitude.
- Settlement survival rungs and classification from nutrition, population loss, and threat pressure belong to `modforge::survival`.
- Survivalist retains settlement threshold values, Unity reads, voting, and every response to the classified rung.
- Adaptive-pressure target selection, tier resolution, deterministic ring placement, global caps, per-target exclusion, tracking, and pruning belong to `modforge::storyteller`.
- Survivalist retains Unity target observations, threat checks, game handles, zombie spawning, liveness reads, movement commands, content values, logging, and chronicle text.
- Adaptive encounter place tracking, budget rolls, encounter composition, anchor and class selection, scatter placement, and successful-spawn caps belong to `modforge::storyteller`.
- MISERY retains Unreal progression and creature observation, enemy exclusions, tuning values, spawn execution, logging, and controls.
- Phenomenon region tracking, weighted selection, reward guarding, count and cluster rolls, placement requests, successful-spawn caps, and counters belong to `modforge::storyteller`.
- MISERY retains its phenomenon catalog, live-square and progression observation, Blueprint lookup, ground traces, Unreal spawning, logging, and controls.
- Vendor percentage pricing, provisional global assignment, commit-on-success, inventory mirroring, and special-offer rejection belong to `modforge::vendor`.
- MISERY retains vendor and item discovery, category and economy values, offer precedence, sewing-kit policy, and Unreal list mutation.
- Raw TArray capacity checks, engine-allocator growth, template cloning, appended slot writes, and count updates belong to `ueforge::ue::tarray`.
- MISERY retains vendor list offsets, item identifiers, price-array construction, stock and price byte patches, labels, and logging.
- Live non-CDO and transient-object lookup, checked raw UFunction parameter calls, zeroed parameter allocation, and game-thread live-object hook installation and completed-hook teardown belong to Ueforge.
- MISERY retains its autoload save checks, Blueprint names, parameter layouts, notice filtering, re-entry guard, dismissal function, diagnostics, and logs.
- The root README is a concise workspace map with capability tables; detailed framework and decompilation material stays in the owning crate documentation.
- Engine-independent coordinate decoding belongs to Modforge.
- Managed handle ownership, bridge-value decoding, managed-list traversal, synchronous main-thread dispatch, and Rust/C# pointer and string plumbing belong to Unityforge.
- Survivalist retains its game class and field names, object selection, gameplay policy, Unity actions, content, logging, and presentation.
- Rectangular annex geometry and deterministic identity-based selection belong to Modforge; Survivalist retains construction and encounter policy plus game observation and execution.
- Delayed craft-result collection advancement belongs to one small function in `modforge::crafting`; Survivalist retains CraftJob, its queue, timing fields, Harmony observation, Unity result lookup, quality policy, and item replacement.
- First-reachable destination calculation belongs to one small function in `modforge::faction`; Survivalist retains OpenDoor, headroom, destination order, eligibility, Unity observation, member transfer, role updates, and conscript policy.
- The existing goods filter belongs to `modforge::item`; Survivalist retains the valuable-first selection and transfer loops, blocked stores, caps, round-robin distribution, managed inventory discovery, Secure checks, and Take and Add execution.
- Centroid, spread, point-at-angle, and nearest-point calculations belong to small functions in `modforge::storyteller`; Survivalist retains community selection, minimum spread, angle and radius policy, spawning, hostility, movement, and presentation.

## Last session summary

- 2026-09-13: aligned the shared order module, types, threat fields and UI with AI players. Moved Follow/Defensive defaults to the allied spawn operation. Updated npc-ai.md and todo.md with role boundaries and the autonomy/enemy sequence. Six decision tests and the Abiotic development build passed. The live order test target compiles; its five runtime tests remain ignored in this verification run. No deployment or live acceptance of the pending damage observer is claimed.
- 2026-09-13: Grunt companion, allied faction and follow verified live; user confirmed Pest and Exor combat. Documentation now distinguishes accepted behavior from the failed earlier Exor-body test and deferred player features.

- Generic AI player module and profile-selected controls are implemented in the existing AbioticFactorMod. All 27 client tests and the integration-test build pass. Ran the existing restart.ps1 -BuildOnly successfully; it validated the 3074048-byte release DLL at target/x86_64-pc-windows-msvc/release/abioticfactor_mod.dll. No deployment or new join occurred. Live spawn and restart-into-save work remain pending.

- User approved the host-mod UDP design. Updated Abiotic todo with client embedding, connection lifecycle and native navigation acceptance. Kept completed research marked done; local navigation generation and physics-free far movement are superseded. Documentation only, no build/run/deploy performed.

- 2026-09-12: Extended the standalone Abiotic map reader to navigation properties and bounded native headers. Facility parsing, Office1 extraction and read-only runtime generation research pass. Both inspected packages lack saved navigation tiles; 50 live meshes use Dynamic generation. Updated lan-loading.md and the existing todo. No A* path or UDP respawn implemented yet.

- User directed next work toward A* navigation using existing shared project code. Inspected Modforge route.rs and Ueforge nav.rs: reuse path/steering/arrival/stuck behavior, supply a local extracted-navmesh provider for Sophia and UDP movement output. Added owning Abiotic todo row; area volumes do not establish walkability.
- Two-second +X attempt produced no new correction. Permanent named-Sophia research confirms death flag true, not downed or disabled, both loaded flags true, movement mode 1, unchanged server position. Boolean masks verified from shipped PDB. Added death/UDP-respawn row; no further movement or revival attempted. Session 71760 remains the existing connection.

- Added actual convex point containment and a profile-local map/table loader. where reports Sophia's last UDP coordinate and every containing named map region; different world/missing regions remain explicit. Binary build, 25 library tests and standalone location integration pass.
- Ran updated Sophia once after confirming the old process had exited on host closure. Session 71760 remains live. Sent stop (zero acceleration) to obtain a fresh post-spawn correction; where reports Office Sector / Office1 at (-17111.80368023579,13396.1879664876,208.15000039223014). No walking command or HTTP gameplay query used. Exact HUD selection remains an open separate row.

- Retained ordinary UDP correction body inputs instead of discarding them: timestamp, velocity/relative flag, optional rotation/gravity and packed movement mode; added state command. Native compressed-rotation trace, binary build and 24 library tests pass. No new Sophia run or reconnect performed.
- Permanent camera function catalog located Update Head Joint Location Rotation; all 3518 bytes decode. Camera height depends on actual crouch interpolation/falling, sitting, death/downed, emotes and size; rotation uses gravity-relative control rotation, head socket and sway. Exact formula/default inputs and local visibility lifecycle remain required before runtime area reporting. Findings in Abiotic lan-loading.md and lan-rpc.md; completed substeps marked done in todo.

- Updated mod is now live. Permanent sector_pose_snapshot_research and character_attachments_match_same_update_snapshot pass at frame 70043. Both character shapes and every attachment match at strict existing tolerances; normal controller reports V_FOG/Flathill. No Sophia movement or reconnect performed.
- Character capture todo marked done; separate overlap/level capture consistency row remains open. One passing coherent pose does not prove the exact cause of prior failures or full collision parity while moving. Runtime sector reporting still needs Sophia's own UDP/local state.
- User authorized diagnostic installation. Installed the built DLL as AbioticFactorMod/dlls/main.dll and preserved main-before-read-snapshot.dll; both hashes verified. Earlier unknown-op result was before the updated image loaded and is now superseded.

- Decoded World streaming-array serialization, InitializeLevels and demo filtering. Added map reader output and Rust static registration; permanent comparison matches 59 native levels and all 223 registration decisions. Explicit demo/full cases produce 222/223 registered volumes.
- Subsequent normal-player captures fail camera transform reconstruction; translation then rotation differ. Separate reads crossing updates are a hypothesis. Recorded capture consistency work in Abiotic todo; strict collision comparison remains failing for the new captures. No movement, reconnect or mod deployment. Runtime sector integration remains unfinished.

- Implemented local convex collision using pinned Parry 0.27.0, including element/brush transforms, nonuniform brush scaling, capsule hemisphere dimensions and camera-sphere attachment reconstruction. Compared all 223 transforms and overlap booleans against permanent read-only game research; all match for the captured pose.
- Fed computed intersections into the verified native level selector and game table: Office3/The Office Sector matches the normal client. Collision integration and 23 library tests pass. No Sophia reconnect/movement or mod deployment occurred.
- Earlier collision checkpoint recorded Theatre volume _61 among 223 world volumes but absent from 222 registered volumes. Its exclusion is now explained by the demo gate above. Collision boundary/filter semantics, changed character state and Sophia runtime lifecycle inputs remain open in the Abiotic todo.

- Reproduced native level selection in Rust, including exact initial float bits, double-to-float age calculation, native-order ties and found/empty-asset behavior. Permanent HTTP research captures actual world manager entries and pure actor-overlap queries. Rust matches the recorded 59-instance state, Office3 and The Office Sector; two offline sector comparisons and 21 library tests pass.
- Observed two player components in the selected volume: a capsule with unscaled half-height 96/radius 32 and a radius-10 sphere attached to FirstPersonCamera. Captured relative transforms and attachment names; camera parent-chain composition, collision filtering and local overlap production remain unfinished. Sophia's session and the mod installation were preserved.

- Traced the normal Abiotic client sector path through actor overlap, LastTimeVisible selection, DT_Levels, FX overrides and HUD state. Documented decoded functions and remaining local-world inputs in abioticfactor-mod/docs/lan-loading.md.
- Permanent read-only HTTP research exported 64 level/sector/day/night rows and observed the normal controller in Facility_Office3 with The Office Sector. Rust reproduces the table lookup and matches all four observed outputs; offline parity and 20 client library tests pass.
- Sophia's running session was not restarted or driven for this research. The table lookup is not yet integrated into her session because local actor overlap and level loading/visibility history are still missing. The existing mod and its installation were preserved.

- 2026-09-12 position milestone: normal movement report RPC 38 now supplies last received location and receives packed response RPC 31. Shipped code established correction vectors are raw doubles, unlike actor-open packed vectors. Live movement updated coordinates from approximately (-17436.65,13276.37,208.15) to (-17111.93,13396.13,208.15). Build and 19 tests pass. Current live process is exec session 77428 (target/sophia-position); position/forward/stop/quit commands. Final build also exists under target/abioticfactor-client. Old session 12945 had already exited on truncated packet; recorded as unresolved. Later rebuilds used quit and confirmed server logout. Last-received coordinates do not establish idle freshness; relative/root-motion corrections and full prediction remain open.
- 2026-09-12 acceptance: user confirmed Sophia walked with animations after the repeated two-second +X command. Spawn and bounded movement are confirmed; distance, facing-relative movement and full prediction/correction are not. Current process remains in exec session 12945 and accepts forward/stop/quit. User requested documentation and push, then identified incoming UDP state as the next task, starting with Sophia's coordinates.
- 2026-09-12 movement attempt: user confirmed spawning and requested movement. Permanent HTTP research identified Character movement RPC indices (ServerMoveOld=39) and parameters; shipped native old-move handler validates timestamps and calls movement simulation. Added stdin forward/stop/quit and bounded +X acceleration over UDP. Built in target/sophia-movement; 17 local tests pass. Old process stopped; permanent log test confirmed server logout before reconnect. Current binary is exec session 12945; forward command sent at 16:03 local. Await user visible movement verification. Command currently uses world +X, not the pawn's facing. Do not launch a duplicate instance; use this session's stdin.

- 2026-09-12 spawn-only run: user narrowed scope to spawning. Initial launch reached setup but server disconnected for RPC 300 customization parameter-read mismatch, confirmed in server log. Disabled automatic appearance application while preserving profile preference. Build and 16 local tests passed; relaunched Sophia over UDP, reached possession and loading completion, process remains running in exec session 27379. Awaiting user visible-spawn verification. Do not start another instance or resume movement/map research during this acceptance step.

- 2026-09-12 Facility extraction: permanent HTTP research captures current unversioned property declarations and nested types. Standalone Rust map reader builds and parses Facility using that schema. Offline comparison passes for all 223 named volume positions and validates 259 linked convex meshes. Extraction, schema capture, parsing and comparison passed. No Sophia join or mod deployment. Next: establish transformed capsule/volume overlap, collision filtering, prerequisites and headless content readiness before changing UDP loading behavior. Native trailing BSP/cooked collision is not decoded; rotation/scale and overlap equivalence are not yet live-validated.

- 2026-09-12 volume research: the current host is healthy; game-thread ping succeeds and ticks advance, superseding the earlier frozen-host status. Permanent Rust tests read four overlaps on the current player and 223 world volume actors. Parent Blueprint enter/exit handlers update the overlap array locally. Reflected overlap and volume level-reference fields have no CPF_Net flag; shipped PDB resolves native state 6 to LoadedVisible. An offline Rust retoc catalog retained 95 map/bulk chunk rows. Research tests build and pass; no Sophia join or mod deployment. Next: parse local volume geometry/level references, establish collision and content readiness, then implement the verified UDP behavior. Map parsing and remaining creation/intro flow are still open.

- 2026-09-12 loading/creation research: HTTP responds but host tick remains 8537; no Sophia join. Added named-class HTTP Blueprint research independent of frozen stacks, inherited-function selection, and offline native-function disassembly tests. Decoded the 1045-byte overlap loading predicate and 4568-byte trait widget. Loading requires all overlaps after teleport, any otherwise, and returns true for an observed empty list. Normal trait confirmation uses a 0.3s delay before spawn, not replicated skill completion. Topic docs record the evidence and distinction from the bot. Next: establish volume/content inputs for UDP readiness, finish customization/intro tracing, then implement verified behavior. Host restart remains needed for live acceptance.

- Research split: abioticfactor-mod/docs/abiotic-factor.md is now the index for nine topic documents covering engine, progression, character, research method, LAN transport, spawning, loading, RPCs, and persistence. All original sections were copied and verified before replacing the monolith; early notes remain labeled historical. New findings go into the owning topic; unfinished work stays in the existing todo. Next steps and open protocol questions remain unchanged.

- Documentation location: all Abiotic Factor research, its todo, and its changelog now live together under abioticfactor-mod/docs/. The research file was moved with an unchanged content hash; project history rows were copied, verified, then removed from the shared changelog. References point to the project folder.

- 2026-09-12 deep co-op research: permanent HTTP tests decoded complete controller (56333 bytes), pawn (222367), player-state (3018), game-mode (9025), LoadPlayerSaveData (3692), and SavePlayerData (12511) scripts. Detailed lifecycle is in abioticfactor-mod/docs/abiotic-factor.md. Server ReceivePossessed initializes controller character references before its own spawn call; missing state delays 0.2s, missing client confirmation delays 0.5s. Removed the bot's initial spawn RPC and guarded post-trait spawn against restored skills. Build plus 16 local tests pass. Old Sophia exec session 4293 stopped to release the binary; no new join, host mutation, or deployment.
- Save identity finding: the native GetPlayerSaveID helper uses _wtoi64 and decimal formatting on the network ID string. Permanent offline disassembly test confirms the imported conversion; HTTP confirms Sophia's PlayerSaveID is numeric zero without emitting account identifiers. Recorded distinct save identity/preservation as new todo work. Existing ID and saves remain unchanged. Loading readiness, creation-widget completion, save queue flush and reconnect acceptance remain open; no claim that the whole protocol is finished.

- 2026-09-12 root cause: the permanent ignored frozen_game_call_stack diagnostic passes and captures Request_SpawnMeInWorld on Sophia's controller. External reads show PlayerCharacter (+2144) is null, TeleportPlayer returns false, nine world-start actors exist, and PlayerSpawnAttempts (+4544) exceeds 280 million and keeps increasing. Cooked controller bytecode failure branch 5424 -> 8646 increments attempts then jumps 8861 -> 4987 without returning to tick. HTTP still responds; game thread remains inside this RPC. Fresh restart excludes a leftover bot as a necessary trigger. No customization was sent before this hang. The UDP readiness signal needed to avoid the premature request remains to be identified; no client fix or new join was attempted during diagnosis.

- 2026-09-12 fresh retry: no previous bot process was running. Sophia reloaded four journal events, joined, and requested spawn; the user reported another freeze. The user then explicitly authorized HTTP diagnosis. HTTP responds in 0.01s, but game thread 18132 remains at tick 8537 and pe_ping times out after 3s. Frame counter advances. Before diagnosis the mod had drained zero queued jobs. HTTP module samples associate the game thread with the game executable; the endpoint does not provide current function addresses or a call stack. Exact cause remains open. This HTTP permission is for the requested diagnosis, not a change to the bot's UDP-only architecture.

- 2026-09-12: marked UDP joining/spawning done following the user's visible in-game confirmation. Marked Sophia profile, basic event journal, and customization payload implementation done, with in-game customization and reconnect persistence still open. Recorded the suspected same-ID reconnect-before-logout cause separately from established facts. Next run follows the user's game restart.

- 2026-09-12: added the standalone client's UDP response to its own character loading setup messages. Built abioticfactor-client and ran the binary directly for a one-hour session. Its UDP output reported welcome, possession/replication confirmation, Intern selection, server skill readiness, spawn request, and character loading completion sent. The user verifies the in-game result. No host inspection, mod HTTP calls, or deployment occurred for this run.

- Spawn investigation: the permanent player_spawn_initialization_functions test passed against the host. The controller exposes reliable server RPCs Request_SpawnMeInWorld(PlayerState object) and Request_ConfirmCharacterReplication() with no parameters. Server_SetupInitialTraits takes PhDTrait, TraitRows and AmnesiaThreshold. These are candidate normal initialization steps; their ordering and prerequisites still require tracing. The client currently skips actor payloads, so it cannot yet identify replicated object IDs or answer game RPCs. No spawn fix is claimed.
- 2026-09-12 latest: EOSPlus identity encoding passed LAN admission; UE 5.4 partial bunches require two flags. The standalone executable retained its own host controller and pawn for 65 seconds while the human retained theirs. Position diagnostics now print world coordinates; the bot was about 204 metres above the human. This supersedes the earlier blocked-login notes below. Actor replication decoding, initialization and movement remain unfinished.
- Added the independent abioticfactor-client crate with no Ueforge or game-runtime dependency. It implements the UE version 3/4 UDP stateless challenge exchange, bounded retries on one socket, packet bounds checks, and matching-ack validation. Added control-channel hello/login/welcome/join handling, acknowledgements, reliable sequence wrapping, and bounded-session disconnect. Replicated world decoding and movement are not implemented; player admission is not claimed.
- Verified `k3sc cargo-lock test -p abioticfactor-client`: build and eight local tests pass. Verified `k3sc cargo-lock clippy -p abioticfactor-client --all-targets -- -D warnings`: clean. The live UDP handshake passed with checksum 2047383495. The full login test is still incomplete; changes remain uncommitted.
- Corrected the Abiotic todo and owning design document to require the separate Rust UDP executable. Preserved the older uncommitted in-process implementation and unrelated workspace changes.
- After the user hosted the game, the permanent LAN test completed the UDP handshake, received a login challenge, and the game log recorded the login request. Login then timed out. Existing offline research confirms a null-ID dereference in Abiotic's approval code. Corrected the empty ID encoding to a nonempty NULL identity and tested that payload. Its live acceptance attempt could not reach the game port (10054). Asked whether the game froze/crashed; that has not been confirmed by the user. No raw cookies or authentication data were logged.
- Cloned TheBestPlan/killingfloor-bot-client to C:/code/killingfloor-bot-client at 446f90daf4ca9495db7215badc08a33c44a93516. Reviewed UDP framing, login, package metadata, replication, possession, and movement. Its UE2.5 wire protocol is reference material, not an Abiotic-compatible implementation.
- Verified 56 bitstream checks, 20 connection checks, the local mock handshake test, and the local relay smoke test. No live game join was attempted. Reliable control ordering does not handle its 10-bit sequence wrapping; the mock handshake shares the client's codec and does not prove live server compatibility.
- Removed navigation scope creep: generated loot-box approach points, route persistence, walked-position recording, reverse routes, unused route metadata and cost calculation, source-text checks, and live function-discovery probes.
- Loot boxes remain the waypoint while Unreal projection happens only inside the A* request. Bunker-door interaction now happens once at the metal-door stop when interaction is allowed, instead of after movement gets stuck.
- Removed the extra expedition-entry loot waypoint and automatic E retries. Loot navigation now has only the selected box as its waypoint, and expedition-door and loot-box stops each send E once before reporting success or failure.
- Preserved `modforge::client::live_journal` and its MISERY action-journal proof unchanged.
- Verified all 6 shared waypoint-route tests pass and the MISERY navigation test target compiles with only the existing `STACK_TWEAK` warning.
- Added `input.player.unreal`, which reads the retained player's reflected `Controller` and the controller's reflected `PlayerInput` field on the game thread. Both property offsets are cached after their first lookup.
- Restarted MISERY and proved the operation returns `BP_SGKController_C` and `EnhancedPlayerInput`. Two consecutive calls returned identical non-null object addresses and offsets. All 63 Ueforge tests and the workspace check pass.
- Added the permanent live W press-and-release test. It records the starting, moving, released, stopped, and final positions, always attempts movement-key release, and fails unless W moves the player and release stops movement.
- Restarted MISERY with the exact release build and ran only the W test. It recorded the starting position and failed immediately on Ueforge's explicit unavailable error, proving the test is red before the real input implementation.
- A restarted MISERY test proved the Unreal console-command input experiment did not move the player. The player remained at the same position for ten seconds and the route correctly failed as stuck.
- Removed the rejected console-command implementation, its held-state code, its per-tick mouse release, and its shutdown handler. Ueforge now returns an explicit unavailable error for player commands until the real `APlayerController::InputKey` path lands.
- Extended the permanent production-source test to reject all three console-input commands. The test, all 63 Ueforge library tests, and `k3sc cargo-lock check --workspace --all-targets` pass.
- Replaced the waypoint graph and its second A* with one ordered route. `RouteGraph`, `RouteEdge`, and waypoint-graph path search no longer exist.
- Added shared path, path-point, and player-observation types. The observation carries position, yaw, and pitch, and path points are no longer represented as waypoints.
- Replaced bot movement axes and the old path execution code with one shared bot that returns only W/A/S/D key state and relative mouse movement. It releases all movement keys on arrival, stuck detection, and cancellation.
- Migrated the permanent MISERY navigation test to give Unreal path points and player observations to the shared bot, then send the resulting command batch through the registered input surface.
- Removed Ueforge's direct movement and look calls and MISERY's direct interaction handler. The permanent production-source test rejects those bypasses.
- Ueforge observes the player through reflected position and control rotation. Player commands are explicitly unavailable until they enter Unreal through the local player's real input path.
- Added Unityforge main-thread connections for the same shared path, player-observation, and player-command formats. Tests prove path and observation return plus unchanged ordered command delivery. Actual Unity navigation and input bridge calls remain open.
- Applied the workspace Rust formatter consistently at the operator's direction.
- Added permanent red proofs for the shared bot-navigation rewrite. They require one ordered route without waypoint-graph A*, separate path points, player position plus yaw and pitch, bot output containing only virtual keys and mouse movement, identical Unreal and Unity command sequences, release of W/A/S/D on every stop, and source checks against the actual Ueforge and MISERY production files. The focused test build fails on the missing shared types and old axis command API as intended.
- Extended the dedicated bot-navigation design from an Unreal-only MISERY design to one Modforge system for both Unreal and Unity. The shared system owns all bot decisions; Ueforge and Unityforge only connect engine navigation, player observation, and normal player input. Added separate concrete Unity path, input, and live-proof rows to the todo.
- Moved the bot-navigation design out of the synthetic-input prior-art document into dedicated `docs/bot-navigation.md`. The prior-art document now links to it and retains only input research and implementation history.
- Corrected the route design after two implementations bypassed the player's input route and one design revision invented a second A* over semantic waypoints. The route selects the next waypoint, Unreal navigation's single A* determines the detailed path from the player to it, the bot chooses virtual W/A/S/D and mouse controls, `InputSurface` injects those controls into normal game input processing, and the game alone performs movement, aiming, and interaction.
- The exact restarted build retained the player before acceptance and reflected the controller successfully. Live calls then proved MISERY exposes `GetControlRotation` on neither `Controller` nor `Pawn`; Ueforge must read the reflected `AController.ControlRotation` field.
- Two restarted acceptance attempts began before autoload retained the player because `restart.ps1` treated the HTTP listener as full readiness. The mod log proved the player was retained five seconds after the early acceptance failed.
- Live verification resolved `NavigationPath.PathPoints` at `0x38`, found and projected all three route stops, and saved the route. The first bot path tick then failed because MISERY does not expose `Pawn::GetController`; Ueforge must read the reflected `APawn.Controller` field instead.
- The restarted bot path verification failed before movement because MISERY does not expose `NavigationPath::GetPathPoints` as a reflected function. Epic's `UNavigationPath` surface exposes `PathPoints` as a reflected field; the native `GetPathPoints` method belongs to `FNavigationPath` and cannot be called through `ProcessEvent`.
- Added forward and right movement axes plus ordered movement, look, and key dispatch to `modforge::input::InputSurface`.
- Added shared bot path code. It consumes path points and observed poses, emits player axes, advances points, and releases movement on arrival, cancellation, or stuck detection.
- Added two input tests and two bot path tests. The focused suite passes all nine tests.
- Replaced Ueforge's unused OS key helper with a reusable Unreal input adapter. It sends an entire command batch through one game-thread job, uses standard reflected movement and look UFunctions, and leaves game-specific key actions in the consumer.
- Added a serializable strict in-process player-command operation that errors without a registered surface instead of falling back to OS input.
- Registered MISERY's retained player with the Unreal adapter. Navigation look and every current door or crate `E` interaction now use the same command surface. Ten deterministic navigation tests pass and source proof rejects every former OS or direct Unreal input path.
- Replaced MISERY's `SimpleMoveToLocation` executor with reflected `NavigationPath::GetPathPoints` decoding and bot path execution. Eleven deterministic navigation tests pass; live route verification remains open because this environment must not launch the game.
- Added one shared player-pose observation for position and control yaw. Ueforge serves it in one game-thread job and the MISERY bot uses one observation per tick instead of separate location and rotation calls.
- Replaced every OS input dependency in `research_navigation.rs`. Look commands now call `PlayerController::AddYawInput` and `AddPitchInput`, observe control-rotation movement, and fail after ten ignored commands. Interaction calls the retained player's Enhanced Input action directly. The source proof rejects OS mouse, keyboard, focus, foreground, and viewport lookup paths. Ten deterministic navigation tests pass and MISERY checks across all targets; live verification remains open.
- Pushed `b9d41c7f` and deployed that exact clean commit. The restarted cold route passed in 21.32 seconds with three waypoints, two travel steps, one bunker-door interaction, one expedition-door interaction, and zero global UObject scan rows. `ue:actors_of_class` measured 0.50 ms worst and `ue:component_by_class` measured 0.09 ms worst.
- From the entered expedition, the bot rejected two unreachable crates, selected the lowest-cost reachable `BP_StashMid_C`, and traversed to its one target waypoint in about eight seconds. Crate interaction did not start because four seconds of L1 relative mouse input left control rotation unchanged at yaw -90 degrees while the target required yaw 49.3 degrees. The next change must drive and observe the player controller's yaw and pitch input before another live run.
- Stopped the latest live route after confirming it violated `misery-mod/docs/performance.md`: setup still used global player and door searches, stuck handling ran multiple class-chain scans, and expedition entry polled another global player search every 250 ms. No further live acceptance may run until those paths are gone and forbidden timing rows are absent.
- The latest restarted acceptance reached the bunker metal door but three focused `E` attempts did not open it. The player remained 110.3 cm from the door, so reliable player-input delivery is the first remaining loot-flow task.
- The zero-global-scan actor path selected a real `BP_WoodenCrate2_C` through `GetAllActorsOfClass`. Unreal reported a complete 6575.8 cm path, but `SimpleMoveToLocation` stopped 773.5 cm from the approach, proving that observed traversal must invalidate a path blocked by geometry the navmesh does not model.
- Rejected the first loot prototype on performance grounds. It repeatedly walked the 174,000 to 230,000-object global UObject list on the game thread during candidate selection and UI polling, violating `misery-mod/docs/performance.md`. The replacement batch uses one Unreal world-actor enumeration, cached pointers and function layouts, bounded navigation work across frames, event-captured container UI, direct inventory-count observation, and a zero-global-scan acceptance gate.
- The first loot movement proof correctly failed after choosing by straight-line distance: Unreal stopped 672.4 cm from a box enclosed by building geometry. Target selection must reject invalid or partial engine paths and rank reachable boxes by measured navigation-path cost.
- Closed the cold three-stop acceptance gap. From a restarted game, the permanent live test saved exactly three waypoints and two travel steps, opened the bunker metal door once, entered the expedition once, and completed in 23.94 seconds with 75 debug positions outside the route.
- Added a permanent live loot-box discovery test. In the entered expedition it found placed `BP_WoodenBoxResource_C` actors and selected the nearest at `[32192.64, 96474.68, 67.82]`, 3560.9 cm from the player.
- Built and round-tripped the exact `spawn -> metal-door -> expedition-door` route with three waypoints and two travel steps. The live flow saves it under `target/misery-routes`, while one-meter debug positions remain outside the route.
- Added player-like door handling: Unreal supplied the path for each travel step, the bunker metal door received a bounded targeted `E` keypress only after observed blockage, and the expedition door received `E` at arrival.
- Proved expedition entry live from the existing door stop. A targeted `E` keypress moved the player from the safe-area door to `[28643.14, 48716.50, 208.66]` in 0.65 seconds, and the permanent test passed only after observing that transition.
- Hardened viewport focus so it restores the window, joins the relevant Windows input queues, and verifies the exact foreground HWND instead of returning the `SetForegroundWindow` call result.
- Added live UFunction parameter discovery with validation across both observed UE5 FField layouts. MISERY returned exact layouts for navigation projection, simple movement, controller lookup, and Enhanced Input interaction.
- Proved Unreal player-controller navigation can walk the MISERY player automatically. The permanent test projects the player and placed expedition door onto the navmesh, detects lack of progress beside a live metal door, focuses the viewport, performs bounded interaction input, resumes the same navigation controller, and retains debug positions.
- Cold-start acceptance passed from spawn to the expedition entrance in 53.72 seconds with 72 one-meter debug positions and three bounded interaction attempts at one metal door. Movement cleanup runs on success and failure. That proof established movement before the later three-stop route implementation.
- Added a permanent live MISERY navigation test. It found the player at `[19575.10, 24919.65, -273.37]`, distinguished the placed expedition door at `[19248.00, 32776.95, 54.00]` from a zero-position startup instance, and verified that MISERY loads `NavigationSystemV1::FindPathToLocationSynchronously` and `NavigationPath` validity, partial, cost, and length functions.
- The first navigation call built from the assumed stock UE5 parameter layout timed out the game-thread control queue. The next implementation must expose live UFunction parameter offsets and sizes before invoking it again.
- Added `modforge::route` with versioned world-space routes, recorded travel connections, a waypoint-graph A* that is now rejected as MISERY's pathfinding authority, trail reduction, closed-loop yaw steering, arrival checks, and stuck evidence.
- Added relative mouse movement and look-axis operations, registered the generic input catalog in MISERY, and extended Horsey's input surface for relative axes.
- Added five route tests. All five pass, all 327 Modforge library tests pass, and Modforge, MISERY, and Horsey compile across all targets.
- Changed the permanent MISERY route proof so the live journal owns semantic `route.follow` actions and observed-arrival waits, then saves, loads, and replays the journal.
- Cold-started MISERY with the route build and fixed viewport selection for processes that own both a game window and a diagnostics console.
- Verified the live route proof in 9.31 seconds: record a collision-aware local route, save and load it, return, journal-replay outward and back without teleporting, restore facing, release forward input, and wait on the recorded final waypoint.
- Updated the earlier synthetic-input design for MISERY 3D route recording with a waypoint-graph A* that is now rejected as MISERY's pathfinding authority.
- Added `modforge::client::live_journal`, a versioned JSON journal for injected games that records control-plane actions, waits for observed JSON values, and asserts resulting state with precise step and value evidence on failure.
- Added five behavioral tests covering round-trip, ordered replay, condition polling, recording, operation failure, and assertion failure.
- Made MISERY the first live proof without adding a game-specific operation: the permanent test uses the existing `walk_class`, `read_bytes`, and `write_bytes` controls to change player movement speed, wait for observation, assert it, restore it, save and load the journal, replay it, and restore it again.
- Verified the live MISERY proof against the running game on port 17176. It passed in 0.56 seconds and asserted the original movement-speed bytes were restored.
- Updated the installed stable toolchain and workspace minimum to Rust 1.98.
- Refreshed the workspace lockfile and migrated direct dependencies including ureq 3, glam 0.33, zip 8, sha2 0.11, region 4, socket2 0.6, and winreg 0.56.
- Migrated Modforge's blocking HTTP client and harness to the ureq 3 request and response APIs.
- Merged upstream hudhook 0.9.2 into the local Present1 fork, updated its image dependency to 0.25.10, and retained the custom Present1 hook.
- Updated the excluded decomp crate to Rust 1.98, sleigh-config 1.0.1, goblin 0.10.7, and clap 4.6.6. Its documented external r2sleigh Windows build blocker remains unchanged.
- Verified `k3sc cargo-lock check --workspace --all-targets --all-features`, all 53 Ueforge tests, all 6 Unityforge tests, and all hudhook tests. Modforge ran 326 tests with 325 passing and the existing stale `backend_parse_rejects_garbage` assertion still failing because `l3` is a recognized backend.
- Removed four stale priority-1 rows from `docs/todo.md` after verifying their exact Harmony bridge and Ueforge features-builder completions in the existing changelog and current source.
- Cleaned the workspace backlog by moving 30 completed MISERY, Survivalist, and Schedule 1 rows into the dated changelog, verifying nine existing Grounded 2, Ueforge, Modforge documentation, and IL2CPP shim entries, and removing all 39 checked rows from `docs/todo.md`.
- Linked the BepInEx IL2CPP shim to the existing shared `GenerationLoader` and removed its duplicate DLL discovery, symbol resolution, bridge pinning, direct tick delegate, shutdown, and `FreeLibrary` implementation.
- Kept BepInEx logging, Harmony setup, IL2CPP class injection, input polling, and the injected frame driver in the IL2CPP shim.
- The shared loader now supplies initial loading, generation-file hot reload, rollback, ticking, and final shutdown to the IL2CPP shim. No new tests were added.
- Static verification passed: the project file parses as XML, the IL2CPP entry contains no private native-loader implementation, and `git diff --check` is clean. The BepInEx 6 IL2CPP reference set is not installed on this machine, so the target project was not compiled; tests were skipped at the operator's request.
- Marked the IL2CPP generation-loader row complete in `docs/todo.md`.
- Removed the speculative Ueforge DataTable replication and non-primitive-write rows. DataTable rows are not replicated actor properties, and no game mod contains an `FString` or `TArray` DataTable writer to extract.
- Replaced `modforge/docs/vanilla-invoke.md`'s obsolete design and migration plan with concise documentation for the shipped signature, dispatcher, invoker, and operation APIs.
- Corrected the documented safe-call name to `Invoker::call`, matched the current operation request and result shapes, and documented that invocation remains on the caller's current thread.
- Marked the vanilla-invoke documentation row complete in `docs/todo.md`.
- Moved Schedule 1's guarded main-thread effect dispatch and delegation into Unityforge's standard effects.
- Kept the crash-bisection flag and operation, effect labels, two-second timeout, and concrete effect configurations in Schedule 1. Added no tests and made no game behavior changes.
- Verified `k3sc cargo-lock check -p unityforge -p schedule1-mod`.
- Verified `k3sc cargo-lock check -p schedule1-mod --tests`; it retains three existing warnings in research tests.
- Verified `k3sc cargo-lock test -p unityforge --lib`: all 6 existing tests pass.
- Verified `k3sc cargo-lock test -p schedule1-mod --lib`; its library target has zero tests.
- `k3sc cargo-lock fmt -p unityforge -- --check` remains red on existing formatting differences across Unityforge; the changed wrapper code follows the reported format without rewriting unrelated files.
- Replaced Schedule 1's manually capped combat-trace vector with the existing Modforge `Ring`.
- Kept the 512-entry cap, JSON event shape, event recording policy, drop-oldest order, report output, and optional clear behavior in Schedule 1. Added no tests and made no game behavior changes.
- Verified `k3sc cargo-lock check -p modforge -p schedule1-mod`.
- Verified `k3sc cargo-lock check -p schedule1-mod --tests`; it retains three existing warnings in research tests.
- Verified `k3sc cargo-lock test -p schedule1-mod --lib`; its library target has zero tests.
- Replaced Schedule 1's two local timestamped arrays, rotation logic, and recent-window lookup with the existing Modforge `RecentRing`.
- Kept the 32-entry capacity, NPC pointer identity, 15-second hit window, and 60-second credit cooldown in Schedule 1. Added no tests and made no game behavior changes.
- Verified `k3sc cargo-lock check -p modforge -p schedule1-mod`.
- Verified `k3sc cargo-lock check -p schedule1-mod --tests`; it retains three existing warnings in research tests.
- Verified `k3sc cargo-lock test -p schedule1-mod --lib`; its library target has zero tests.
- Replaced Schedule 1's local lowest-level skill selection and one-point spending loop with the existing Modforge RPG tracker operation.
- Kept the decision to auto-spend newly earned points in Schedule 1 and preserved catalog order, max-level filtering, one-point application, early stopping, and tracker persistence behavior. Added no tests and made no game behavior changes.
- Verified `k3sc cargo-lock check -p modforge -p schedule1-mod`.
- Verified `k3sc cargo-lock check -p schedule1-mod --tests`; it retains three existing warnings in research tests.
- Verified `k3sc cargo-lock test -p schedule1-mod --lib`; its library target has zero tests.
- Removed Schedule 1's local managed-handle decoder, unsafe owned-object wrapper, and manual borrowed-object wrappers from loot, farming, kill credit, and combat tracing.
- Routed transient handles through Unityforge's owned-object helper and retained singleton handles through its borrowed-object helper, preserving release and cache lifetimes.
- Kept all Schedule 1 classes, fields, cash spawning, influence behavior, kill attribution, and combat trace policy in the mod. Added no tests and made no game behavior changes.
- Verified `k3sc cargo-lock check -p unityforge -p schedule1-mod`.
- Verified `k3sc cargo-lock check -p schedule1-mod --tests`; it retains three existing warnings in research tests.
- Verified `k3sc cargo-lock test -p unityforge --lib`: all 6 existing tests pass.
- Removed Schedule 1's two duplicate Vector3 parsers and routed production and research callers to the existing `modforge::client::parse_vec3` authority.
- Preserved the accepted string and tagged-string inputs, f64 output, and failure behavior. Added no tests and made no game behavior changes.
- Documented every named function in `schedule1-mod/src` with a concise player-readable purpose and an explicit Modforge or Unityforge ownership boundary.
- Marked Schedule 1's local coordinate decoder as a Modforge extraction candidate and its bridge-handle decoder and owned-handle wrapper as Unityforge extraction candidates.
- Changed comments only. Added no tests and made no behavior changes.
- Verified `k3sc cargo-lock check -p schedule1-mod`.
- `k3sc cargo-lock fmt -p schedule1-mod -- --check` remains red on existing rustfmt differences throughout Schedule 1 source and research tests; no unrelated formatting rewrite was applied.
- Moved Grounded 2's existing parameterized survival-drain effect into Ueforge's standard RPG effect library.
- Grounded 2 now keeps only the SurvivalComponent class reference, hunger and thirst offsets, captured vanilla access, settings access, reduction tuning, and catalog statics.
- Added no tests and preserved the existing settings-first early return, vanilla fallback, reduction curve, target calculation, class-default writes, log text, and effect text.
- Verified `k3sc cargo-lock check -p ueforge -p grounded2-mod`, `k3sc cargo-lock check -p grounded2-mod --tests`, and all 53 existing Ueforge library tests. The Grounded 2 test check retains its existing unused-field warning.
- Moved Grounded 2's existing parameterized fall-damage effect into Ueforge's standard RPG effect library.
- Grounded 2 now keeps only its player and related class references, field offsets, four vanilla caches, minimum-velocity and disable thresholds, maximum reduction, and catalog static.
- Added no tests and preserved the existing vanilla capture rules, reduction curve, write order, target objects, log text, and effect text.
- Verified `k3sc cargo-lock check -p ueforge -p grounded2-mod`, `k3sc cargo-lock check -p grounded2-mod --tests`, and all 53 existing Ueforge library tests. The Grounded 2 test check retains its existing unused-field warning.
- Moved Grounded 2's existing damage-hook event conversion, UNIX timestamp calculation, and DamageRing recording into `ueforge::debug::DamageRing::record_hook_event`.
- Grounded 2 now reads only its `CurrentDamage` field, supplies the observed value and configured function name, and keeps its positive-damage trace log and counters.
- Added no tests and preserved the existing event fields, timestamp fallback, 64-entry ring, snapshot shape, and trace condition.
- Verified `k3sc cargo-lock check -p ueforge -p grounded2-mod`, `k3sc cargo-lock check -p grounded2-mod --tests`, and all 53 existing Ueforge library tests. The Grounded 2 test check retains its existing unused-field warning.
- Moved Grounded 2's existing status-effect component, array, row-handle, FName, data-table, Type, and Value traversal into `ueforge::ue::status_effect::read_active`.
- Grounded 2 now supplies only its six layout values, selects the first live player, and maps the returned entries into its existing debug snapshot view.
- Added no tests and preserved the existing 64-entry cap and all null and unresolved-row behavior.
- Verified `k3sc cargo-lock check -p ueforge -p grounded2-mod`, `k3sc cargo-lock check -p grounded2-mod --tests`, and all 53 existing Ueforge library tests. The Grounded 2 test check retains its existing unused-field warning.
- Moved Grounded 2's existing parameterized ImpactReversalEffect implementation into Ueforge's standard RPG effect library.
- Grounded 2 now keeps only the IMPACT_REVERSAL damage layout, health offset, environmental marker, reduction tuning, and catalog static.
- Added no tests. Verified `k3sc cargo-lock check -p ueforge -p grounded2-mod`, `k3sc cargo-lock check -p grounded2-mod --tests`, and all 53 existing Ueforge library tests. The Grounded 2 test check retains its existing unused-field warning.
- Moved Grounded 2's existing parameterized LifestealEffect implementation into Ueforge's standard RPG effect library.
- Grounded 2 now keeps only the LIFESTEAL player reference, health offsets, maximum fraction, and catalog static.
- Added no tests. Verified `k3sc cargo-lock check -p ueforge -p grounded2-mod`, `k3sc cargo-lock check -p grounded2-mod --tests`, and all 53 existing Ueforge library tests. The Grounded 2 test check retains its existing unused-field warning.
- Documented every function in `grounded2-mod/src` with a concise purpose and a specific reason it remains in the game mod instead of moving to Modforge or Ueforge.
- Confirmed the current Grounded 2 source already delegates most reusable registries, progression, persistence, hooks, polling, Unreal access, debug transport, and effect dispatch to Modforge or Ueforge.
- Recorded four concrete Ueforge lifts in `docs/todo.md`: the existing parameterized Lifesteal and Impact Reversal effects, status-effect inspection traversal, and damage-event conversion and ring recording.
- Verified `k3sc cargo-lock check -p grounded2-mod`. The existing library-test target still cannot link because `ueforge_ui_enable_imgui` is unavailable to the Windows test executable.
- `k3sc cargo-lock fmt -p grounded2-mod -- --check` remains red on existing rustfmt differences across the crate's source and tests; no unrelated formatting rewrite was applied.
- Rechecked the remaining proposed mission selection, raid experiment, incursion escalation, cooldown, and live-key work against the direct-extraction rule.
- Removed those rows from `docs/todo.md`: they were Survivalist policy, standard collection operations, or would require speculative framework abstractions rather than direct code moves.
- The Survivalist source extraction is complete; no further Modforge or Unityforge lift remains from this audit.
- Moved Survivalist's existing centroid, spread, radial point, and nearest-destination arithmetic into three small functions in `modforge::storyteller`.
- Kept all incursion state, random rolls, constants, community observation, spawn behavior, target effects, logging, and chronicle text in Survivalist.
- Added no tests and did not build, following the direct instruction for this extraction work.
- Removed the speculative GoodsTransferPlanner, PopulationPlanner, and CraftResultQueue APIs.
- Kept Survivalist's original CraftJob queue, OpenDoor state, goods transfer loop, caps, blocked-store check, and round-robin counter.
- Moved only the existing engine-independent operations: delayed collection advancement, first-reachable calculation, and the existing goods filter.
- Added no tests and did not build, following the direct instruction for this extraction work.
- Recorded the remaining Survivalist extraction candidates in `docs/todo.md` with explicit Modforge and Survivalist ownership boundaries.
- Initially added a CraftResultQueue wrapper, then removed it in favor of a small collection-advance function while returning CraftJob, CRAFT_JOBS, and timing fields to Survivalist.
- Kept quality tier and sibling rolls in `modforge::quality`; Survivalist still owns hooks, recipe and skill reads, product discovery, workbench bonuses, odds, and item swaps.
- Added no tests and did not build, following the direct instruction for this extraction work.
- Added Unityforge managed-object helpers for owned and borrowed handles, bridge JSON handle decoding, typed managed-list counts and entries, managed-list fields, and Unity coordinate decoding.
- Migrated every Survivalist raw managed-list `get_Count` and `get_Item` call to Unityforge and removed the local handle, borrowed-object, coordinate, and list-count implementations from `common.rs`.
- Preserved Survivalist's existing error propagation, soft-failure defaults, handle ownership, stale-list behavior, game fields, and gameplay policy.
- Added no tests.
- Verified `k3sc cargo-lock test -p unityforge --lib`: all 6 existing tests pass.
- Verified `k3sc cargo-lock test -p survivalist-mod --lib`: build passes with the two existing unused genome-helper warnings; its library target has zero tests.
- Documented every function in `survivalist-mod/src` with a concise purpose and an explicit ownership boundary.
- Marked eleven functions as concrete extraction evidence instead of defending engine-independent or Unity-specific mechanics as game code.
- Recorded five coherent lifts in `docs/todo.md`: managed-object and collection helpers, existing main-thread dispatch adoption, Rust/C# boundary helpers, annex planning, and deterministic identity selection.
- Re-exported the shared mission stage from the courier module so existing bounty and threat status code can name it after the earlier mission extraction.
- Added no tests and made no behavior changes.
- Verified `k3sc cargo-lock check -p survivalist-mod` and `k3sc cargo-lock test -p survivalist-mod --lib`; both pass with the two existing unused genome-helper warnings and the library target has zero tests.

- Added the `unique` property to `ItemDef`.
- Extracted the existing entered set, holder ledger, schema version, lazy JSON restore, and temporary-file-then-rename persistence into `modforge::item::ItemLedger`.
- Migrated `survivalist-mod/src/unique.rs` to the item ledger while preserving its seed-keyed path, JSON field names, entry checks, holder announcements, and write-failure warning.
- Added no tests. Updated existing `ItemDef` test literals with `unique: false` so their behavior remains unchanged.
- Verified `k3sc cargo-lock test -p survivalist-mod --lib`: build passed and its zero-test library target passed.
- Verified `k3sc cargo-lock test -p modforge --lib`: build passed, 274 tests passed, and the existing item tests passed. The full target remains red on unrelated `input::tests::backend_parse_rejects_garbage`, where current input code accepts `l3` but the test expects rejection.
- Added `modforge::upgrade` for scoped entity levels, status aggregation, cost and skill requirements, diminishing returns, schema, and JSON persistence.
- Migrated the Survivalist C# upgrade effects to query the Modforge authority through native exports. Unityforge now notifies consumers whenever a Rust generation becomes active so the delegates rebind after initial load, story re-entry, hot reload, or rollback.
- Removed the duplicate C# level dictionaries and JSON persistence. Existing track applicability, menus, material consumption, effects, save path, JSON fields, and status shape remain in Survivalist.
- Added no tests and did not build, following the direct instruction for this extraction.
- Expanded `modforge::mission` with caller-defined multi-stage missions, explicit transitions, timeout callbacks, owned advancement, and one-stage observation missions.
- Migrated Survivalist courier to the existing go-and-return lifecycle and migrated settler, stranger, and robbery to the one-stage collection driver without moving game behavior into Modforge.
- Added no tests and did not build for the mission extraction, following the direct instruction.
- Expanded `modforge::genome` with a shared ballot accumulator and migrated the duplicated tallies in Survivalist survival, steal, trade, scavenge, murder, and robbery.
- Added no tests and did not build for the ballot extraction, following the direct instruction.
- Expanded `modforge::genome` with shared trait, voter, and collective reinforcement dispatch and migrated the duplicated reinforcement loops in Survivalist survival, steal, trade, scavenge, murder, and robbery.
- Preserved Survivalist's outcome judgment, trait choices, directions, magnitudes, Unity effects, logging, and chronicle text. Added no tests and did not build.
- Moved Survivalist's settlement survival rungs and pressure classification into `modforge::survival` while preserving its threshold values and all Unity-driven responses.
- Added no tests and did not build for the settlement survival extraction, following the direct instruction.
- Expanded `modforge::storyteller` with the complete engine-independent adaptive-pressure selection, tier, placement, and active-event lifecycle used by Survivalist's horde.
- Migrated the horde to the Modforge authority while preserving Unity observation and execution, Survivalist's content values, logging, and chronicle text. Added no tests and did not build.
- Replaced the stale root framework prose with concise capability tables for Modforge, Ueforge, and Unityforge, and moved readers to the existing dedicated decompilation documentation for implementation detail.
- Linked every named framework capability directly to its owning source and normalized the Modforge table so each public system module appears exactly once.
- Reviewed the Modforge capability inventory against every exported module and both binaries, corrected actor knowledge that had been mislabeled as native memory access, and replaced the broad simulation bucket with narrower system groups.
- Compacted each framework inventory into logical categories while retaining exactly one one-word source link per unique capability file.
- Shortened the root README's AI disclaimer to one sentence.
- Replaced the root game table's feature inventories with one-sentence purpose summaries.
- Moved reverse-engineering navigation into the workspace docs index and moved detailed credits into `docs/credits.md`.
- Moved workspace build prerequisites from the root README into `docs/building.md`.
- Reduced the root framework explanation to one sentence covering UE5, Unity, and native games.
- Reduced the root ownership rule to one sentence covering shared, engine-specific, and game-specific code.
- Replaced the root architecture-heavy introduction with a one-sentence description of the toolkit.
- Moved both introductory sentences above a Mermaid dependency graph of Modforge, its engine layers, and current consumers.
- Removed the redundant framework wrapper and promoted each framework capability table to its own root section.
- Replaced private `k3sc` build examples in all nine game-mod READMEs with public `cargo`, `dotnet`, script, or no-build guidance.
- Corrected the game-mod feature inventories after the first README pass summarized systems too aggressively. Expanded Grounded 2, MISERY, Schedule 1, Survivalist, WWM, Horsey, and Scrap Mechanic against their current source while preserving each existing table format.
- Corrected Scrap Mechanic's README to describe its loadable `BetterSurvival` custom game instead of incorrectly calling the directory research-only.
- Reworked every mod feature table so each concise feature name links to its primary implementing source file and a separate description column explains the behavior.
- Documented every function in `misery-mod/src` with a concise player-readable purpose and a specific reason the function remains game-specific instead of moving into Modforge, Ueforge, or Unityforge.
- Audited those function boundaries and recorded the remaining MISERY lifts in `docs/todo.md`: standard asset and game-thread operations, reusable field editing, typed TMap mutation, encounter and phenomenon planning, vendor offer planning, raw TArray append support, checked UFunction calls, transient-object lookup, and live-object hook installation.
- Moved the unchanged `asset_inventory` and `load_asset` handlers into `ueforge::assets`, routed both through `ueforge::game_thread::run`, migrated MISERY registration, and removed its game-local asset wrapper.
- Moved the unchanged `call`, `pe_ping`, and `pe_stats` registration and response construction into `ueforge::game_thread::register_ops`; MISERY now owns only its queue, timeout hint, and installation call.
- Added `FieldEditor` beside Ueforge's existing struct-field access authority and migrated MISERY's cached refresh, numeric sliders, boolean controls, and writes into it; MISERY retains only its catalog, object accessor, ranges, text, and tab wiring.
- Added typed scalar key/value entries and live value mutation to `ueforge::ue::tmap`, then removed MISERY's raw map header, stride, slot lookup, read, and write helpers while preserving its movement keys, baseline speeds, multiplier, and UI.
- Expanded `modforge::storyteller` with adaptive encounter configuration and state, including place lifecycle, copy, escalation, and pack rolls, anchor and class selection, scatter placement, session caps, and successful-spawn accounting.
- Migrated MISERY spawning to supply live Unreal snapshots and game-specific policy, then execute Modforge's requests through Ueforge while preserving its emissions curve, random roll order, caps, exclusions, logs, controls, and spawn behavior.
- Expanded `modforge::storyteller` with phenomenon definitions and planning state for region re-entry, weighted distinct selection, reward-danger pairing, ordered guard placement, count and cluster rolls, class-variant choices, placement requests, caps, and counters.
- Migrated MISERY phenomena to supply its catalog and live Unreal facts, resolve ground and Blueprint classes, and execute Modforge's requests while preserving random roll order, placement, counters, logs, controls, and spawn behavior.
- Verified the MISERY library compiles. Modforge built and 312 tests passed; the full library target remains red only on the existing `input::tests::backend_parse_rejects_garbage` mismatch where `l3` is accepted.
- Added `modforge::vendor::OfferPlanner` for percentage pricing, globally unique provisional assignments, commit-on-success behavior, inventory mirroring, and caller-supplied special offers.
- Migrated MISERY's vendor mirror, ammo, food, and sewing-kit decisions to Modforge while preserving vendor order, item and currency policy, prices, append-failure fallback, and raw Unreal mutation.
- Verified the MISERY library compiles. Modforge built and 312 tests passed; the full library target remains red only on the existing `input::tests::backend_parse_rejects_garbage` mismatch where `l3` is accepted.
- Added raw clone-and-append support to `ueforge::ue::tarray`, including engine-allocator growth, template cloning, slot writes, and count updates.
- Migrated MISERY vendors to provide only item, price, and stock byte patches while preserving its offsets, spare-capacity policy, logging, and failure behavior.
- Verified all 53 Ueforge library tests pass and the MISERY library compiles with its existing unused `STACK_TWEAK` warning.
- Added Ueforge live-object lookup for exact classes and transient class-chain matches, then reused the transient lookup in the engine-tick installer and MISERY autoload.
- Added checked byte-buffer and zeroed-parameter UFunction calls to `ueforge::ue::pe_call`, then removed MISERY's local call helper and raw dismissal call.
- Added game-thread live-object hook installation and completed-hook teardown to Ueforge, then removed MISERY's notice poller, installed flag, raw object cast, hook installation, registration, and post-dismissal lifecycle boilerplate.
- Preserved MISERY's save decisions, exact Blueprint names and parameter layouts, notice class filter, re-entry guard, dismissal behavior, diagnostics, and logs. Added no tests.
- Verified `k3sc cargo-lock check -p ueforge -p misery-mod`; both crates compile with only MISERY's existing unused `STACK_TWEAK` warning.
- Verified `k3sc cargo-lock test -p ueforge --lib`: all 53 existing tests pass. Rechecked `k3sc cargo-lock check -p misery-mod` after the hook-lifecycle completion; it still compiles with only the existing warning.
- Verified the changed Modforge poller through `k3sc cargo-lock test -p modforge --lib`: its existing tests pass within the 312 passing tests. The full target remains red only on the existing `input::tests::backend_parse_rejects_garbage` mismatch where `l3` is accepted.
- Added `MainThreadQueue::run_result` as Unityforge's fallible synchronous main-thread authority and routed Unityforge's own operation adapter through `MainThreadQueue::run`.
- Migrated all 15 Survivalist blocking main-thread operations to Unityforge with the existing five-second timeout and removed Survivalist's local oneshot, polling, sleep, and timeout loop.
- Kept the requested rustfmt normalization in the changed Rust files. Added no tests.
- Verified `k3sc cargo-lock check -p unityforge -p survivalist-mod`.
- Verified `k3sc cargo-lock test -p unityforge --lib`: all 6 existing tests pass.
- Verified `k3sc cargo-lock test -p survivalist-mod --lib`: build passes with the two existing unused genome-helper warnings; its library target has zero tests.
- Added `unityforge::ffi` for checked UTF-8 input, UTF-16 paths, returned C-string allocation and freeing, panic containment, and fallible result fallback.
- Migrated all nine Survivalist upgrade exports to the Unityforge boundary helpers while preserving their exported names, return codes, fallback values, logging, report contents, save-path choice, and C-string ownership contract.
- Added the new Unityforge boundary source to the root capability table. Added no tests.
- Verified `k3sc cargo-lock check -p unityforge -p survivalist-mod`.
- Verified `k3sc cargo-lock test -p unityforge --lib`: all 6 existing tests pass.
- Verified `k3sc cargo-lock test -p survivalist-mod --lib`: build passes with the two existing unused genome-helper warnings; its library target has zero tests.
- Added `modforge::annex` for ordered side selection, rectangular strip expansion, exposed perimeter generation, gate and interior placement, blockage rejection, and claimed-rectangle growth.
- Migrated Survivalist development planning to supply its depth, side order, coordinate floor, blockage limit, and live terrain callback, then execute the unchanged fence, gate, shack, and claim operations through Unity.
- Preserved passability call order, east-south-west-north preference, fence tile order, gate and shack coordinates, blocked-tile behavior, construction order, and logging. Added no tests.
- Added the new Modforge annex source to the root capability table.
- Verified `k3sc cargo-lock check -p modforge -p survivalist-mod`.
- Verified `k3sc cargo-lock test -p survivalist-mod --lib`: build passes with the two existing unused genome-helper warnings; its library target has zero tests.
- Verified `k3sc cargo-lock test -p modforge --lib`: Modforge builds and 312 existing tests pass. The full target remains red only on the existing `input::tests::backend_parse_rejects_garbage` mismatch where `l3` is accepted.
- Added deterministic salted index and identity-based catalog selection to `modforge::roll`, and routed the existing dread-loop random helper through the same hash authority.
- Migrated Survivalist stranger intent, mysterious outcome, announcements, and reveal text to Modforge selection while preserving the exact hash constants, signed identity conversion, floating-point salt bits, bounds, thresholds, catalog order, and selected text.
- Removed Survivalist's local hash and bounded catalog indexing. Added no tests.
- Verified `k3sc cargo-lock check -p modforge -p survivalist-mod`.
- Verified `k3sc cargo-lock test -p survivalist-mod --lib`: build passes with the two existing unused genome-helper warnings; its library target has zero tests.
- Verified `k3sc cargo-lock test -p modforge --lib`: Modforge builds and 312 existing tests pass. The full target remains red only on the existing `input::tests::backend_parse_rejects_garbage` mismatch where `l3` is accepted.

## Next steps

- Finish the pending damage-event and friend-filter live acceptance on Sophia's accepted NPC path. Then pursue independent exploration and resource collection through shared actions, followed by the first persistent enemy. Keep game-specific spawn policy separate from shared orders.

- Complete Sophia's local level selection from real map collision, actor overlap and local loading/visibility history, then integrate the verified sector table lookup. Do not substitute host/controller state or coordinate heuristics. Facing/velocity follows this requested sector work. Preserve Sophia's identity and profile; distinct save identity, owning-level readiness, customization, full correction coverage and save completion remain open.
- Move the current Unreal navigation call and path decoding into Ueforge so MISERY receives the shared path format directly.
- Make Unityforge inject the same virtual W/A/S/D, mouse, and interaction commands through Unity's normal player input.
- Prove one live Unity waypoint trip through the same Modforge bot-navigation code used by MISERY.
- Investigate MISERY's real player keyboard-input implementation, then send W press and release through that exact mechanism.
- Live-verify Unreal A* pathing from the player's current position to each selected waypoint, driven through virtual player input, from spawn through both doors on a restarted local game.
- Aim at the door's colliding-bounds center from the active camera and gate `E` on interaction range.
- Complete ranked crate fallback, retained-state opening, UI transfer, and inventory-count evidence.
- Enforce absent search counters and the 16.7 ms frame budget before running another cold acceptance.
- Compile the BepInEx IL2CPP shim when a BepInEx 6 IL2CPP reference directory is available.
- Namespace Unityforge's managed handle table by generation so stale handles cannot collide after a hot swap.
- Run the existing Grounded 2 in-game smoke checks for the completed extraction batch.
- Exercise Survivalist's Load/Unload re-init path through a live story switch and confirm `ReinitAfterUnload` works.

## Open questions

- Before persistent enemies: what permits return after defeat, what experience changes future decisions, and which relationships permit human commands? These remain design questions, not working behavior.
- What caused the 15:54:33 NPC lifecycle crash, and how should NPC companion respawn and finite ammo work?

- How should a distinct accepted bot identity preserve Sophia's existing save under numeric key zero?
- What headless world-data readiness replaces the current unconditional owning-level-loaded reply, and what proves queued saves reached disk before reconnect?
