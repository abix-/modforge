# LAN research method and evidence

[Research index](abiotic-factor.md) | [Todo](todo.md)

## LAN co-op protocol research (2026-09-12)

This section owns the protocol used by Sophia. The Rust executable is a remote
UDP client. The mod's HTTP endpoint is the research instrument, not a transport
or gameplay dependency of the bot. No in-process substitute player is involved.

Evidence labels used throughout the topic documents:

- **Observed**: measured from the running host or confirmed by the user.
- **Decoded**: read from this build's native symbols/disassembly, reflected
  network schema, or cooked Blueprint instructions. This establishes code flow,
  not proof that an untested client implements it correctly.
- **Open**: missing behavioral or serialization evidence; do not replace it with
  a guessed field, elapsed-time delay, or invented readiness acknowledgment.

## Research method and reproducibility

`abioticfactor-mod/tests/http_health.rs` contains the permanent ignored
`frozen_game_call_stack` diagnostic. It discovers the stalled thread through
HTTP `pe_stats`, obtains a native stack externally, resumes the thread, and
identifies the actual RPC and Blueprint frame. The stack uses this build's PDB
and unwind information. It does not call a gameplay function or write host memory.

`tests/common/spawn_trace.rs` reads the live UClass/UFunction chains and cooked
scripts through HTTP `read_bytes`, resolves names through `fname_to_string`, and
parses expression tokens recursively. It is a semantic decoder, not a byte-pattern
guess. Cached field names avoid repeated HTTP lookups. Unsupported expressions
fail the research test. A full sequential decode succeeded for the following scripts:

| Blueprint graph | Script bytes | Successful research artifact |
|---|---:|---|
| ExecuteUbergraph_Abiotic_PlayerController | 56,333 | target/abioticfactor-client/controller-full-trace.txt |
| ExecuteUbergraph_Abiotic_PlayerCharacter | 222,367 | target/abioticfactor-client/pawn-full-trace.txt |
| ExecuteUbergraph_Abiotic_PlayerState | 3,018 | target/abioticfactor-client/player-state-trace.txt |
| ExecuteUbergraph_Abiotic_Survival_GameMode | 9,025 | target/abioticfactor-client/game-mode-trace.txt |
| PlayerState.LoadPlayerSaveData | 3,692 | target/abioticfactor-client/player-load-trace.txt |
| PlayerState.SavePlayerData | 12,511 | target/abioticfactor-client/player-save-trace.txt |

These listings include unrelated gameplay branches for future investigation;
complete decoding is not a claim that every branch has been exercised. The
selected UFunction scripts are also retained as JSON under the same target
directory. Runtime addresses in those artifacts belong to the captured process.
Never reuse them after a restart. This document records durable meanings and
bytecode positions for the inspected build instead.

Research invocation from the repository root, using the currently frozen host:

```powershell
$env:CARGO_TARGET_DIR='C:/code/modforge/target/abioticfactor-client'
$env:ABIOTIC_TRACE_RANGES='0:56333'
k3sc cargo-lock test -p abioticfactor-mod --test http_health -- frozen_game_call_stack --exact --ignored --nocapture
# For the possessed pawn graph, set these before the same exact test:
$env:ABIOTIC_TRACE_PAWN='1'
$env:ABIOTIC_TRACE_RANGES='0:222367'
```

Remove `ABIOTIC_TRACE_PAWN` when returning to controller research. An arbitrary
range must start and end on decoded expression boundaries. The stack bootstrap
requires the captured spawn RPC to be active. The test is ignored by default
and does not join a player.

Named class research no longer needs a frozen stack. The permanent ignored
class_blueprint_research test reads the class pointer from its singleton/CDO
through HTTP read_bytes, then reuses the same semantic decoder. It does not
create objects, call gameplay functions, or use external process reads.

```powershell
$env:CARGO_TARGET_DIR='C:/code/modforge/target/abioticfactor-client'
$env:ABIOTIC_TRACE_CLASS='Abiotic_PlayerCharacter_C'
$env:ABIOTIC_TRACE_FUNCTION='IsLevelLoaded'
k3sc cargo-lock test -p abioticfactor-mod --test http_health -- class_blueprint_research --exact --ignored --nocapture
```

Unset ABIOTIC_TRACE_PAWN, ABIOTIC_TRACE_OBJECT_FIELD, and ABIOTIC_TRACE_RANGES
before class research. With no ranges, the entire selected function is decoded.
Explicit function selection searches parent classes while retaining the most
derived implementation. For the trait widget, select class
W_Character_Trait_Selection_C and function
ExecuteUbergraph_W_Character_Trait_Selection (4568 bytes).

The permanent loading_and_creation_native_code test disassembles shipped
functions through modforge::patterns::sleuth. ABIOTIC_NATIVE_QUERY selects a
PDB procedure substring; its default is ULevelManagerSubsystem::IsLevelLoaded.
ABIOTIC_SYMBOL_QUERY similarly permits discovery without guessing the owner.

Streaming research tests in http_health.rs:

| Test | Evidence and execution |
|---|---|
| level_streaming_layouts | Offline PDB: volume, manager instance, streaming object, and state enum |
| streaming_property_metadata | Ignored HTTP test: reflected offsets/flags, with CPF_Net interpreted from the PDB |
| live_streaming_volumes | Ignored healthy-world HTTP test: current player's overlap count and world volume actors/locations |
| streaming_asset_catalog | Ignored offline test: installed Rust retoc lists map-related container chunks; no asset conversion or game action |

Select each with k3sc cargo-lock test -p abioticfactor-mod --test http_health
followed by the exact test filter; ignored tests require --ignored.
The parent character graph is 33903 bytes and is captured in
target/abioticfactor-client/character-parent-trace.txt. Runtime pointers in all
artifacts belong only to the session captured; named class research resolves
them afresh and remains usable after a restart.

### Current map schema and offline geometry

The permanent map_property_schema HTTP test captures current class and nested
struct declarations to target/abioticfactor-client/map-property-schema.json.
It reads metadata and resolves names; it does not invoke gameplay operations.
The standalone tools/map-reader Rust executable consumes this snapshot and
local converted content without HTTP. Its separate Cargo.lock pins compatible
retoc/usmap dependency revisions.

Run from the repository root in PowerShell:

```powershell
$env:CARGO_TARGET_DIR='C:/code/modforge/target/abioticfactor-client'
k3sc cargo-lock test -p abioticfactor-mod --test http_health -- map_property_schema --exact --ignored --nocapture
k3sc cargo-lock test -p abioticfactor-mod --test map_assets -- extract_facility_map --exact --ignored --nocapture
$env:CARGO_TARGET_DIR='C:/code/modforge/target/abioticfactor-client/map-reader'
k3sc cargo-lock build --manifest-path abioticfactor-mod/tools/map-reader/Cargo.toml
$env:CARGO_TARGET_DIR='C:/code/modforge/target/abioticfactor-client'
k3sc cargo-lock test -p abioticfactor-mod --test map_assets -- parse_facility_map --exact --ignored --nocapture
k3sc cargo-lock test -p abioticfactor-mod --test map_assets -- facility_volumes_match_observation --exact --ignored --nocapture
```

The final comparison requires the saved live-streaming-volumes.json produced
by live_streaming_volumes. It compares stable Facility actor names, not saved
process addresses. Schema capture needs the existing HTTP endpoint; extraction
needs installed content and retoc. Parsing needs the built standalone reader.
These are explicit ignored research tests, not default unit-test dependencies.
Their output is facility-parsed.json; see lan-loading.md for verified results
and the remaining collision/readiness gaps.

The HTTP operation catalog is not sufficient authority for arguments/threading:
in this build `read_bytes` actually consumes `instance_selector` and returns
`bytes_hex`. Raw-address reads and FName resolution can respond while the game
thread is stalled. `class_functions`, `function_parameters`, and
`inspect_address` are queued to the game thread and cannot complete in that
state. A responsive HTTP listener is not evidence of a running simulation.

Cooked layouts verified from the shipped PDB and the captured fields:

| Structure | Relevant layout |
|---|---|
| UObject | Class +16; FName +24 |
| UField | Next +40 |
| UStruct | Super +64; Children +72; ChildProperties +80; Script TArray +96 |
| FField | 48-byte header; Next +24; FName +32 |
| FProperty | OffsetInternal +68 in this build; using +76 produces incorrect values |
| FFrame | Node +16; Object +24; Code +32; Locals +40 |

The FProperty interpretation was cross-checked against the independently
discovered controller PlayerSpawnAttempts offset 4544. Bytecode instruction
offsets and RPC indices must be re-established after a game update.
