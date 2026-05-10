# grounded2mods - project state

## ueforge crate extracted; OWS scaffolding queued (2026-05-09 late)

Generic UE-mod control plane factored out of `better-backpack` into
two new workspace crates so the upcoming Outworld Station mod (and
future UE-game mods) reuse the same plumbing. All slices green; 30+
better-backpack tests still compile.

Layout:

```
grounded2mods/
  ueforge/             rlib. UE-mod control plane.
    src/server.rs        tiny_http listener + dispatch
    src/envelope.rs      OpResponse<S>, parse_request
    src/args.rs          arg_str/u64/bool/f64
    src/pe_queue.rs      Queue (Mutex+atomic+re-entrance guard) + DrainStats
    src/ue/              UObject SDK shim (was better-backpack/src/sdk/)
  ueforge-client/      rlib. Shared test client (skeleton only so far).
  outworld-station/  Research folder for the OWS mod (research.md).
```

What moved:
- HTTP server + envelope + arg helpers (~170 LoC) -> ueforge
- PE-thread queue (~150 LoC) -> ueforge::pe_queue (closures, not a fixed cmd enum)
- Entire UE SDK (UObject/UClass/UFunction/FName/FString/TArray/GObjects, ~600 LoC) -> ueforge::ue

What stayed in better-backpack:
- DebugCmd enum (now just AddHealth + SetCurrentHealth — the
  Call variant moved to a closure that calls ueforge::ops::exec_call)
  + execute_on_game_thread (game's command vocabulary)
- Snapshot type + build_snapshot (game-specific state shape)
- Game-specific op handlers: op_skill_*, op_simulate_*,
  op_class_outer_samples, op_sample_thread_modules
- Game-specific selector resolvers (live_player, live_player_hc)
  in resolve_instance, which now calls
  `ueforge::selector::resolve_generic` first
- counters, perf timing, damage ring, fall_hook integration
- `crate::sdk` is now a re-export facade over `ueforge::ue` so existing
  call sites don't churn

Generic primitives also moved (slice 3b, 2026-05-09 late):
- Selector grammar (`addr:0x...`, `first_class:Foo`) -> ueforge::selector
- read_bytes / write_bytes / walk_class -> ueforge::ops (passed
  game's resolve_instance as a closure for read/write)
- exec_call (find UFunction + process_event) -> ueforge::ops::exec_call;
  game's op_call enqueues a closure that calls it on the game thread
- hex_encode/decode -> ueforge::hex

Current crate sizes:
- better-backpack/src/debug.rs: 1286 -> 998 LoC (-288)
- better-backpack/src/counters.rs: 1109 -> 115 LoC (-994)
- better-backpack/src/sdk/: 6 files -> 1 facade (~12 LoC)
- ueforge: ~2033 LoC across 18 files
  (server, envelope, args, pe_queue, selector, hex, ops,
   counters, ring, winproc, ue/{fname, fstring, offsets,
   tarray, uobject, probe, mod})

Slices 4-7 (2026-05-09 late, after slices 1-3):
- Slice 4: counter primitives (bump/observe_peak/time_scope/TimeScope)
  -> ueforge::counters; bounded ring buffer pattern -> ueforge::ring
  (replaces hand-rolled DAMAGE_RING)
- Slice 5: UE introspection (gobjects_population,
  class_outer_samples) -> ueforge::ue::probe
- Slice 6: Win32 process introspection (process_threads_json,
  process_cpu_json, process_regions_json,
  sample_thread_modules_json, process_memory_json, ~770 LoC)
  -> ueforge::winproc. Generic for any Windows process, not just UE.
- Slice 7: test client (Api wrapper, OpResponse<S>, hex codec,
  parm helpers) -> ueforge-client. better-backpack's tests/common
  shrunk from 493 -> 367 LoC; the bbp `Api` is now a newtype over
  `ueforge_client::Api<Snapshot>` with bbp-specific convenience
  methods (`skill_spend`, `simulate_heal`, ...).
- Total moved out of better-backpack: ~2000 LoC.
- ueforge + ueforge-client total: ~2270 LoC of reusable infrastructure.

Slice 8 (2026-05-09 late):
- File + console DLL logger -> ueforge::log. AllocConsole +
  GetModuleFileNameW + timestamped writer. Game's log.rs becomes
  a thin wrapper that calls ueforge::log::set_dll_module from
  DllMain and ueforge::log::init from the worker. ~140 LoC.

## Parity vs research+TDD vision

Vision (per `~/.claude/skills/runtime-control-http/SKILL.md`):
ALL investigative + test infrastructure DRY in ueforge/ueforge-client.
New UE-game mods bring only game-specific Snapshot + handlers.

Done (15 capabilities in ueforge/ueforge-client):
- HTTP server, envelope, arg helpers
- Game-thread queue with re-entrance guard
- 5 generic primitives + selector grammar + hex codec
- Counter primitives + bounded ring buffer
- Full UE SDK + UE introspection (gobjects_population,
  class_outer_samples)
- Win32 process probes (threads, CPU, regions, memory, sampler)
- Test client (Api<S>, OpResponse<S>, parm round-trip)
- File + console DLL logger

Slices 9-11 landed (2026-05-09 late):
- Slice 9: PE/vtable hook framework -> ueforge::hook (vtable
  primitives + ProcessEventHook RAII + leaked-snapshot lock-free
  registry + re-entrance guards). better-backpack/src/hook/ is
  now a 6-line re-export facade.
- Slice 10: UE4SS C++ shim layout-critical mirror -> 
  ueforge/cpp/ueforge_cppusermodbase.hpp + ueforge_imgui_bridge.hpp.
  better-backpack/cpp/shim.cpp drops ~100 LoC of CppUserModBase
  redefinition; build.rs adds the ueforge/cpp/ include path.
  Game-specific shim logic (imgui tab, FFI surface) stays in
  game crate. Future mods just `#include "ueforge_cppusermodbase.hpp"`
  and inherit.
- Slice 11: Test perf-log writer -> ueforge_client::perf.
  better-backpack's open_perf_log is a 6-line wrapper passing
  env!("CARGO_MANIFEST_DIR") so the writer walks up to the
  game's repo root.
- Slice 12: ueforge-build crate (build-dep helper). Provides
  `CppShim::new().source(...).imgui_dir(...).ue4ss_lib_dir(...)
  .compile()`. Embeds the shared ueforge C++ headers via
  include_str! and drops them into OUT_DIR/ueforge_cpp so the
  shim can `#include "ueforge_cppusermodbase.hpp"` regardless of
  ueforge's location (workspace path-dep or future registry pull).
  Game's build.rs is now ~10 LoC (was ~60). Validated end-to-end:
  better-backpack now builds via ueforge-build.

Out of scope:
- Settings JSON loader (game-specific shape; ueforge doesn't enforce).
- Bench harness (not in skill; add when first bench exists).

## Audit candidates landed: settings + FieldTweak + cargo deploy (2026-05-09 night, post-stack-mod)

After the stack mod shipped, ran an audit (ueforge/README.md
"Audit: what's in ueforge vs in game crates") that surfaced
three 🟡 promotion candidates. All landed.

#29 ueforge::settings::Settings<T>:
- Generic settings-as-Rust-struct, JSON-backed at
  <DLL_dir>/settings.json. load-on-construct,
  atomic-save-on-update via temp+rename.
- tweaks::settings defines TweaksSettings { stacks: { multiplier } }.
  Slider position now persists across launches.

#28 ueforge::ue::datatable::FieldTweak<T>:
- Snapshot-vanilla + idempotent re-apply primitive. Generic
  over T: Copy + PartialEq + Send + 'static.
- apply(transform, skip_if): one-shot DT mutation.
- apply_when_ready(timeout, transform, skip_if): bundles
  on_first_sight + apply_to.
- tweaks::stacks::STACK_TWEAK = FieldTweak::new("DT_Materials", 0x48).
  spawn_apply_worker is 3 lines, apply_now is 8.

#30 ueforge-deploy (Rust binary, replaces all per-mod
PowerShell):
- New workspace member ueforge-deploy/ (clap CLI).
- Reads each mod's [package.metadata.ueforge] via `cargo
  metadata --no-deps --format-version 1` + serde_json.
- Steam library walk via winreg + libraryfolders.vdf regex.
- UE4SS-presence check, mods.txt mgmt, locked-DLL friendly
  error, zip packaging via the `zip` crate.
- .cargo/config.toml [alias] gives `cargo deploy install -p
  <mod>` ergonomics.
- All previous PS scripts removed (per-mod and any
  unified-PS-attempt). Single Rust binary owns deploy.
- better-backpack and outworld-station/tweaks both use it via:
    cargo deploy install -p tweaks
    cargo deploy install -p better-backpack

Audit table (ueforge/README.md) updated: rows 28/29/30 marked
done. Backlog (rows 31-34) untouched -- conditional on real
need.

## OWS stack mod live via DLL (2026-05-09 night)

End-to-end victory: outworld-station/tweaks/ ships a 4x
MaxCanStack bump, validated in-game, pure DLL no pak.

Path (compressed because it was a long session):
1. ueforge bootstrapping: HTTP control plane, generic primitives,
   chunked-GObjects support added on the fly when stock UE 5.4
   broke our flat-array assumption (added GObjectsLayout enum)
2. UE4SS install (main HEAD), UE4SS.lib regenerated for OWS
3. SDK dump via Ctrl+H -> CXXHeaderDump/ (956 .hpp, 8.4 MB)
4. Image-base offsets read from UE4SS.log: g_objects 0x07A938D0,
   append_string 0x010DF9D0, process_event 0x012AF540
5. /debug endpoint live, walk_class returns 27 DataTables
6. DT_Materials at 0x29EE796B740, FSMaterialData::MaxCanStack
   at +0x48 from SDK dump's SpaceSalvageStation.hpp
7. First mutation attempt FROM A TEST after save load: DT
   showed 1000 in memory, in-game still showed 250
8. Cache theory + RTFM: UE4SS docs say DataTable reads return
   COPIES; UI widgets (UI_Item.MaterialData at +0x3C0) hold
   the row by value, populated at widget creation. Mutating
   AFTER widgets cached = stale.
9. Fix: tweaks::stacks worker spawned from on_unreal_init.
   Polls for DT_Materials (up to 30s), bumps every row 4x once.
   Skips cur<=1 (equipment).
10. Verified in-game: Titanium_Ore caps at 2000 (was 500).

Findings codified:
- ueforge/README.md gets a "Pattern: DataTable mutation timing"
  section explaining the cache window and the
  on_unreal_init-poll-mutate recipe.
- outworld-station/research.md records the bootstrap status
  table flipping every "NO" to "yes" and the stack mod
  shipping section.

Open items not blocking:
- Fname GNames/GWorld offsets still 0 (not needed for current
  features; ueforge ops work without them).
- UI tooltip rendering with stale FSMaterialData on widgets
  created after mutation propagates fine; widgets created
  BEFORE (e.g. test-time mutation post-save) would not, hence
  the on-init pattern.
- Memory scanner still backlog (would have found the cache
  faster but SDK dump path got us there too).

Slice 13 (2026-05-09 late):
- TMap<K,V> walker -> ueforge::ue::tmap (slots, header,
  find_value_by_fname_key). Layout constants (element stride 24,
  pair-value offset 8, num-i32 offset 8) live in
  ueforge::ue::offsets::tmap; stable through UE 5.0-5.4.
- UDataTable helpers -> ueforge::ue::datatable (find_by_short_name,
  row_value_by_fname, iter_rows). Built on tmap. Row-map offset
  (0x30) lives in ueforge::ue::offsets::datatable.
- better-backpack's lookup_data_table_row is now a 3-line wrapper
  validating the new helpers end-to-end. Build green.

Migration is now 1000% complete vs the parity table including the
DataTable / TMap walking surface needed for the upcoming
outworld-station/tweaks/ multi-mod (stack-size adjustments first,
more tweaks on the same scaffold over time).

Every research / TDD capability the runtime-control-http skill
describes — including the engine-version-stable TMap mechanics
needed for any DataTable mod — lives once in ueforge or ueforge-client.

## Project rule: ueforge is the base for ALL UE4SS Rust mods

Every UE4SS Rust mod in this workspace builds on top of ueforge.
That's not aspirational; it's the codified rule. Game crates
contain ONLY game-specific code:

- PlatformOffsets per UE build / platform
- Snapshot struct + build_snapshot
- Op handler match arms (with handlers calling ueforge primitives)
- Game-specific selectors wrapping selector::resolve_generic
- Drain-site PE trampoline (game picks the hot UFunction)
- Tab render bodies using ueforge::ui::*
- One `ModInfo` static + one `ueforge::ue4ss_mod!` invocation

Everything else — server, envelope, queue, hook framework, UObject
SDK, UE introspection, TMap/DataTable mechanics, platform
detection, counters, ring buffer, file+console logger, Win32 probes,
test client, perf-log writer, ImGui bridge, generic shim, factory
exports, DllMain, ImGui vendor, UE4SS.lib, build glue — comes from
ueforge / ueforge-client / ueforge-build.

Operating principle when extending:
- If something might apply to other UE games -> ueforge.
- Only reach into a game crate after proving it's truly
  game-specific.
- If you find yourself copy-pasting between game crates, the
  copied code belongs in ueforge.

Slice 15 (2026-05-09 late):
- imgui v1.92.1 vendor moved to ueforge/cpp/imgui/ (one shared copy)
- UE4SS.lib + .def moved to ueforge/ue4ss/ (one shared import lib)
- ueforge_build defaults to those paths; games carry neither
- Generic platform detection -> ueforge::ue::platform
  (host_image_base, host_exe_name, detect)
- better-backpack/build.rs: 17 -> 5 LoC
- New mods now have NO cpp/imgui or ue4ss/ directories of their own

Slice 16 (2026-05-09 late):
- ImGui bindings -> ueforge::ui (text, button, checkbox, slider_f32,
  slider_i32, progress_bar, separator, indent, same_line, group,
  tree_node, begin_disabled / end_disabled, RAII guards Disabled
  and Group)
- C++ bridge -> ueforge/cpp/ueforge_ui.cpp (extern "C" wrappers around
  ImGui calls; UTF-8 byte ranges round-trip Rust &str without
  null-term management)
- Generic shim -> ueforge/cpp/ueforge_shim.cpp. Implements
  CppUserModBase subclass, factory exports (start_mod /
  uninstall_mod), DllMain, tab registration via per-tab
  trampolines (up to 16 tabs).
- Mod entry point -> ueforge::ModInfo + ueforge::Tab + ue4ss_mod!
  macro. Game declares one static + one macro invocation; macro
  emits every extern "C" hook the shim calls.
- ueforge_build compiles ueforge_shim.cpp + ueforge_ui.cpp by default.
  skip_default_shim() opt-out for legacy mods that ship their own
  factory (better-backpack until its UI migration lands).
- ImGui context bridge moved into ueforge_ui.cpp so opting out of
  the default shim doesn't break ueforge::ui linkage.

A new mod's project tree is now: Cargo.toml, build.rs (5 LoC),
src/lib.rs (~50 LoC of ModInfo + on_init/shutdown + tab renders),
src/debug.rs, tests/. No cpp/, no DllMain, no factory exports,
no imgui or UE4SS.lib in the mod tree.

Pending follow-up: migrate better-backpack to use ue4ss_mod! +
ueforge::ui (drops cpp/shim.cpp entirely; validates the framework
end-to-end on a real mod with multi-tab UI).

Migration is complete. OWS mod's debug.rs only needs:
1. A `Snapshot` struct + build_snapshot
2. A drain-site PE trampoline calling PE_QUEUE.drain()
3. A resolve_instance fn (ueforge::selector::resolve_generic + any
   game-specific selectors)
4. A handle() match arm dispatcher mapping op strings to either
   ueforge::ops::* or game-specific closures

Everything else is `use ueforge::*`.

Next session for OWS: scaffold `outworld-station/<mod-crate>/`
against ueforge + ueforge-client, supply Snapshot + drain wiring,
get the empty `POST /debug` endpoint up.

## Game-side leak diagnosed, NOT MITIGATED (2026-05-09 night)

User reports the game is unplayable: 80% sustained CPU, RAM
growing into the tens of GB over a session. Confirmed earlier
this is not us (mod = 0.30% of process CPU; symptom persists
with all UE4SS mods disabled).

Extended the in-process mod's debug endpoint with
`process_threads_json`, `game_population_json`,
`process_memory_json`. Ran the 30-second perf test:

- Working set +447 MB / 30s, private usage +452 MB / 30s
- GObjects +2228 / 30s. Top growers: Package +198,
  SoundNodeWavePlayer +190, SoundWave +144, then
  SceneComponent / StaticMeshComponent / Proxy* components
- CPU = ~6 full cores' worth. Hot threads: Foreground Worker
  #0/#1 (~58% wall each, UE5 TaskGraph high-priority workers),
  GameThread (51%), four D3D Background Threads (~47% each)

Verdict: **streaming pipeline (World Partition + audio cache)
loads cells, packages, and sounds without releasing them.**
This is a Grounded 2 / UE5 bug. Reproducible with no mods. We
have diagnosed it; we cannot fix it from the mod side.

CASE NOT CLOSED: game is still unplayable for the user.
Mitigations that exist are all upstream (lower audio, lower
draw distance, restart periodically, file with Obsidian).

Full writeup in `docs/ongoing.md` section 15.

## LEAK NARROWED to private RW + thread-attribution probe landed (2026-05-09 night, runs 5-7)

Two-phase escalation past the initial UObject diagnosis.

### Phase 1.5: VirtualQuery probe (run 5+6)

`process_regions_json` walks the entire user address space,
buckets committed bytes by `(image|mapped|private)` x
`(rwx|rx|rw|r)`, plus a private-region size histogram and
an AllocationBase count.

Result: **+581 MB / 30s growth is 100% in private RW
memory.** Image bytes flat, mapped flat (4 GB NVIDIA shader
cache stable), rx/r flat. Native-heap or D3D-VirtualAlloc'd
buffers, NOT UObject memory, NOT mapped asset packs.

`+6,717 new committed regions / 30s` (224/sec, avg 84 KB)
matches UE FMallocBinned2 page sizes.

Total committed: 16 GB. Total reserved: 58 GB (UE pre-
reserves a giant address slab). Top regions show big static
blocks (4 GB NVIDIA cache, 256/128/64 MB private blocks at
fixed addresses) that don't move -- the leak is in many
new small regions, invisible at top-N.

A second 30s leak_source run between deploys showed
+2,534 MB private and +34,067 committed regions cumulative
(extrapolating ~16 MB/sec sustained idle drip).

### Phase 1.7: per-thread RIP-by-module sampler (built)

`sample_thread_modules_json(duration_ms, interval_ms)`:
SuspendThread + GetThreadContext + module-lookup + 1-level
stack walk via ReadProcessMemory when RIP is in a system
DLL. Returns per-thread histograms of "which module is each
thread spending its time in" and "WHO called the allocator
when the thread was inside ntdll."

Op: `sample_thread_modules`. Test:
`tests/explore_thread_attribution.rs`.

### Output files now persist

`tests/common/mod.rs::open_perf_log(test_name)` returns a
tee writer that mirrors stdout to
`perf-runs/<test_name>-<unix_ts>.txt`. `perf-runs/` is
gitignored. Committed evidence is the summary in
`docs/ongoing.md`; raw run logs stay local.

## LEAK IDENTIFIED (2026-05-09 night, runs 3+4)

Built and deployed Phase-1 instrumentation: per-package bucketing,
loaded-levels enumeration, class outer-chain samples, and a 1Hz
timeseries sampler. The new probes named the leak.

**Source**: World Partition not unloading streaming cells. The
persistent level package `/Game/_Augusta/Levels/Augusta_Main/Augusta_Main`
hosts 143,809 UObjects and grows by ~1247 every 30s of play.
Each cell brings its own ambient audio chain (SoundCue ->
SoundNodeWavePlayer -> SoundWave; one cue alone holds 14+ wave
players) and Proxy* component population. Cells load on
movement, never release.

Audio assets named: ambient zones (Greenhouse, IceCart, FirePit),
character foley (footsteps, swim), creature SFX, resource-node
impacts. Audio paths under `/Game/Audio/Sfx/...`.

UI also leaks: OverlaySlot +102 / Image +75 per 30s, sourcing
from `UI_TierDescription`, `UI_FreshnessTimer`, `UI_DamageTypeIcon`
(inventory tooltips not destructing).

**GC IS running** -- the timeseries caught a -4422 GObjects drop
at t=31.6s of a 91s window. Leak is not "GC never runs"; it's
"GC cannot reclaim what cells still ref."

**Leak shape: BURSTY**, not steady. Idle drip is ~100 obj/30s.
Crossing a streaming boundary loaded +21,531 GObjects in ONE
second at t=67.3, then sustained +1800/sec. Working set grew
4.25 GB in 91 seconds.

CPU is the same leak: ~30k Proxy* components ticking every
frame + ~5500 SoundNodeWavePlayers in the audio graph
explains GameThread + Foreground Worker CPU without
needing stack sampling.

This is a first-party Grounded 2 bug. Mod cannot fix it.
Mitigations: restart game periodically, lower view distance /
streaming pool, file with Obsidian.

Full data + asset paths + cell IDs + verdict in
`docs/ongoing.md` section 15.

## Run 2 finding: paging detected (2026-05-09 night, second run)

User changed display settings, said "feels EVEN WORSE." Re-ran
perf test. CPU actually went DOWN (process wall 620% -> 534%,
all worker/D3D threads lower) but `page_fault_count` showed
**38,477 faults/sec** (delta 1.17M in 30s). Working set was
**9.26 GB -> 9.70 GB** absolute. Diagnosis: display change
increased memory consumption (likely texture pool / view
distance / streaming pool), pushed working set past physical
RAM, OS now paging from disk = the felt "worse." CPU
reduction is irrelevant when every frame can stall on a disk
read.

GObjects growth slowed (+2228 -> +1035 per 30s) but the same
classes dominate (Package, SoundNodeWavePlayer, SoundWave).
The leak is the same; it just bleeds slower under the new
settings while the absolute pressure is higher.

Counter-experiment to suggest to user: lower texture quality /
texture streaming pool / view distance, re-run perf test, look
for page_fault rate to drop. CPU may rise slightly.

Full data in `docs/ongoing.md` section 15 ("Second perf run
after display-settings change").

## Open work next session

The streaming leak source needs to be narrowed from "Package +
SoundNodeWavePlayer + SoundWave" (a class) to a specific
package / asset path / referencing component. Plan in
`docs/ongoing.md` section 15 "Plan for better instrumentation"
in priority order:

1. `game_package_breakdown_json(top_n)` -- group every UObject
   by its Outer-chain UPackage; identify which packages host
   the leaking objects.
2. `game_class_outer_samples_json(class_name, k)` -- sample
   K instances of a class, walk Outer chain, return paths.
   Specifically apply to SoundWave / SoundNodeWavePlayer
   to see if they live under one asset directory or are
   spread across many.
3. `game_loaded_levels_json` -- enumerate ULevelStreaming /
   ULevel instances, confirm or refute "World Partition not
   unloading."
4. GC observation counters -- hook
   FCoreUObjectDelegates::GetPostGarbageCollect or sample
   GObjects total every frame to detect GC. Without this we
   cannot tell if GC runs and reclaims nothing vs GC never
   runs.
5. `tests/explore_perf_timeseries.rs` -- 1-second-cadence
   snapshots over 60s. Distinguishes steady drip from bursty
   load events.
6. Audio-component probe: walk live UAudioComponents, list
   owner + sound-asset path. Tells us if components are
   leaking or sounds are pinning.
7. Per-thread stack sampling on Foreground Worker handles
   (we have HANDLEs from `process_threads_json` already).
   Hardest; do last, only if 1-6 leave the suspect list
   wide.

Other still-open items from before:

- Land OnLanded UFunction warmup at install time so
  `fall_hook_fnname_allocs` initializes without needing the
  player to actually land during the test. (Trivial.
  Resolve UFunction by name at install time, populate the
  AtomicUsize directly.)
- Investigate "force-unload streamed cells" debug op as a
  hack mitigation.
- Search for / file an Obsidian bug report on the
  audio/streaming leak.

## Performance pass + research-to-tests migration (2026-05-09 evening)

Discovered + fixed a 1090-allocations-per-second runaway in
`fall_hook`'s trampoline. Per-fire cost was: drain_pending
mutex acquire + `function.as_object().name()` String allocation
on every player BP UFunction call (~18 per frame × 60Hz).
50% CPU and growing process commit.

Two mitigations + one architectural cleanup:

1. **drain_pending empty-queue bypass**: shadow `AtomicUsize`
   `PE_QUEUE_SIZE` mirrors queue length. Hot path is one
   relaxed atomic load + branch when empty -- no mutex.
2. **Cached OnLanded UFunction pointer**: lazy-resolved on
   first sight, stored in `AtomicUsize`. Per-fire pointer
   compare instead of String alloc. Zero allocations on the
   common path.
3. **All research scaffolding moved out of the mod**: the
   `probe_status_effect_values`, `probe_player_status_effects`,
   `is_collision_relevant`, `read_player_velocity_z`,
   `read_player_current_damage`, and the impact-trace
   before/after-CurrentDamage block were research-only code
   that fired on every player BP UFunction. All purged from
   `fall_hook.rs` (613 -> 347 lines). Reimplemented test-side
   in `tests/research_probes.rs` using the generic endpoint
   primitives (snapshot, call, read_bytes, walk_class).

Architectural rule codified across skills + ongoing.md:

- The mod is the mod; tests are the tests; research lives in
  tests.
- The debug endpoint stays generic (snapshot + call +
  read_bytes + write_bytes + walk_class). No domain ops.
- Hot-path code in the mod follows zero-allocations-unless-
  needed: cache identifiers as pointers, atomic-load + branch
  per fire, allocate / lock only on the slow path.

Counters added (`src/counters.rs`) so future runaways are
diagnosable in 30 seconds:
`tests/explore_perf_counters.rs` snapshots all hot-path
counters at T0, sleeps 30s during gameplay, snapshots at T1,
prints per-second deltas sorted descending.

Pending verification in-game: the new build with mitigations
should drop `fall_hook_fnname_allocs` from 1090/sec to ~0/sec
(only fires on actual player landings).

## Bandage research complete (2026-05-09)

End-to-end via the runtime control plane and research-as-code:

1. AddHealth bypasses the impact_resistance mask (proved via
   generic `call` primitive: heal works regardless of mask state).
2. Bandages are NOT AddHealth: they're a status effect
   `BandageHoTTier1` with `Type=Health (24)`, `Value=1.25` per
   tick, modulated by `HealingReceived (57) = 1.15` for ~1.44
   HP per ~250ms tick over ~3.5 seconds.
3. The mask blocks bandages because the heal-tick goes through
   the same native `ApplyDamage` path that consults
   `RequiredDamageTypeFlags`. With the mask = 0xFFFFFFFF and
   the heal carrying `type_flags=0`, the gate rejects the tick.
4. Discovery test confirmed every stat type we need for the
   migration exists in `Table_StatusEffects`:
   - FallDamage(14): 7 rows
   - DamageReductionMultiplier(30): 4 rows
   - MaxHealth(5): 18 rows
   - Health(24): 116 rows
   - and so on for AttackDamage, DamageReduction, LifeSteal.

## AddHealth result (2026-05-09)

`tests/explore_bandage_path.rs::addhealth_with_mask_on_vs_off`
ran via the new generic `call` primitive (no mod rebuild).
Findings:

- **mask OFF**: AddHealth(20) heals cleanly. `damage_ring`
  captures one entry `fn=AddHealth` -- proving our wider PE
  capture sees AddHealth when it's actually called via PE.
- **mask ON**: call times out at 5s. Game itself NOT crashed.
  Cause: with the mask rejecting type_flags=0 events, the
  multicast traffic that normally fires kill_hook's trampoline
  drops near zero, starving the PE queue drain. Workaround
  during research: drive activity in-world. Proper fix:
  high-frequency drain site (UE4SS RegisterProcessEventPreCallback
  or a Tick hook).

Combined with prior bandage observation:
- bandages don't add a status-effect row (observed)
- bandages don't fire any UFunction on the player's HC (observed)
- AddHealth WOULD show in the ring if bandages called it (proved
  via direct test invocation)

So bandages DON'T call AddHealth on the player's local HC
vtable. They go through something else: ServerAddHealth on
the replicated path, a different component (UConsumableComponent,
UItem subclass), or a native C++ call that bypasses
ProcessEvent. Hypothesis tree refreshed in docs/damage.md.

## Architectural shift: generic `call` primitive (2026-05-09)

The endpoint had been growing a `simulate_<event>` op per
research scenario (simulate_add_health, simulate_apply_damage,
simulate_set_current_health, ...). Every new test idea required
a mod-side rebuild + redeploy + game relaunch. Wrong.

Replaced by a single generic primitive: `call`. Args are
`{class, function, instance_selector, parms_hex}`; tests build
parm structs in Rust matching the SDK's `UFunction` parm
layouts, hex-encode, send. The mod calls `process_event`,
returns the post-call buffer. Tests decode and assert.

Re-entrance guard added to `drain_pending` so calls that
trigger ProcessEvent fan-out (replication, multicast) don't
recurse into the trampoline and hang the game (the original
crash from this session).

Test-side helpers in `tests/common/mod.rs`:
`Api::call_ufunction`, `parms_as_bytes`, `bytes_as_parms`,
`hex_encode`, `hex_decode`. All experiments now live as
`tests/<scenario>.rs` files; the mod stops growing.

This is now codified in
`~/.claude/skills/runtime-control-http/SKILL.md` "Op set:
GENERIC PRIMITIVES, NOT TEST OPS" so future projects don't
make the same mistake.

## Endpoint research findings (2026-05-09)

Built debug HTTP endpoint per the new
`runtime-control-http` skill. First experiment driven as a Rust
test (`tests/explore_apply_damage_gate.rs`) gave two findings:

1. **`AddHealth` bypasses the impact_resistance mask.** Heal of
   +20 applied cleanly with the mask at `0xFFFFFFFF`. Confirms
   that the canonical heal entry point is not gated by
   `RequiredDamageTypeFlags`. Bandages must therefore take a
   DIFFERENT path -- the mask-blocking-bandages bug is real but
   the mechanism is not "bandages call AddHealth and the mask
   blocks them". Hypotheses live in `docs/damage.md` "Research
   finding".

2. **simulate_apply_damage crashes the game.** Calling
   `ApplyDamageFromInfo` via `process_event` from inside the
   `kill_hook` trampoline re-enters ProcessEvent on a
   replication-triggering function and hangs. Tracked in
   `docs/todo.md` "Endpoint parity gap" with remediation options.

Next experiment: watch the snapshot's `status_effects` array
during a real bandage use. If a new row appears mid-bandage we
have direct evidence for hypothesis 1 (status-effect tick path).

## Current focus
RPG / level-up mod for Grounded 2. Loaded by UE4SS as a CPPMod
(C++ shim + Rust cdylib). Skill catalog is the single source of
truth; apply step writes skill values to game CDOs.

For docs see `docs/` (each file is authority on one subject).
Open work in `docs/todo.md`. History in `docs/changelog.md`.

## Project rule: ONE mod, all testing inside it

There is exactly one mod -- `BetterBackpack` (the Rust cdylib +
C++ shim, loaded by UE4SS as a CPPMod). Diagnostics, probes,
traces, and feature work all live inside this single mod. Do
**not** drop side-channel Lua mods or separate probe DLLs into
the game install -- everything routes through our Rust code,
gated behind cargo features, skill levels, or
`cfg!(debug_assertions)` so the user gets exactly one log file
and one place to read what is happening.

Fall Damage Resistance: velocity-stomp on `OnLanded` PE hook
(`fall_hook.rs`). Scales `CharMovementComponent.Velocity.Z` by
`(1 - reduction)`; native `ApplyFallDamage()` reads live. Validated.

Impact Damage Resistance: write
`UHealthComponent.RequiredDamageTypeFlags = 0xFFFFFFFF` (+0x00FC)
on player CDOs + live pawn at any level > 0 (`apply.rs` via the
new `SkillEffect::PlayerHealthCompU32Mask` variant). Native
ApplyDamage gate rejects damage with `type_flags = 0` (fall,
environmental, hazard zones); creature attacks carry non-zero
flags and pass through. Validated in-game: rock collision
multicasts report `damage=0.00`.

Caveat: Impact gate is **binary** (level 1 = full immunity, same
as level 100). The proper mechanism is the engine's status effect
system: `UStatusEffectComponent` at +0x1378 on the player exposes
`GetValueForStatForDamageTypeFlags(StatType, Flags)` which native
damage code consults on every event. `EStatusEffectType` enum has
matching values for nearly every skill we plan to add (FallDamage,
DamageReductionMultiplier, LifeSteal, ReflectDamage, AttackDamage,
CriticalHitChance, CriticalDamage, MaxHealth, ...).

**Active work (A1)**: probe shipped (gated on `impact_resistance >
0`) that calls `GetValueForStat` on the player's component during
OnLanded and logs the readout. First in-game observation confirmed
the system is live: vanilla equipped gear already populates
`AttackDamage=1.210`, `CriticalHitChance=0.060`, `MaxHealth=30.0`,
`FallDamage=1.000`, `DamageReduction=1.000` -- all from existing
items/perks reading through the same surface our skills will use.

Stat semantics differ per type, queryable via
`UUserInterfaceStatics::GetStatusEffectValueType` (returns
`EStatusEffectValueType` = `{None=0, Add=1, Multiply=2}`). Probed
in-game:

- `mul` stats: `FallDamage`, `DamageReduction`, `AttackDamage`.
  Vanilla baseline 1.0. Contribution = `(1 - reduction)` for
  reduction skills, `(1 + bonus)` for buff skills.
- `add` stats: `LifeSteal`, `CriticalHitChance`, `CriticalDamage`,
  `ReflectDamage`, `MaxHealth`, `DamageReductionMultiplier`.
  Vanilla baseline 0.0. Contribution = scaled bonus (e.g. 0.30
  for 30% lifesteal).

Per-skill write formulas in `docs/damage.md` "Stat semantics
table". Vanilla data table identified: every status effect in the
game flows through `/Game/Blueprints/Attacks/Table_StatusEffects`.
Concrete plan in `docs/damage.md` "Implementation plan": resolve
the table (follow any existing row handle), enumerate rows via
`UDataTableFunctionLibrary::GetDataTableRowNames` /
`GetDataTableRowFromName`, mutate or inject one row per skill,
AddEffect via process_event. `UStatusEffect` is row-driven; value
lives in the data-table row, not the instance. Migrate
`fall_resistance` first (lowest-risk; velocity-stomp is the
fallback if anything misbehaves), then expand.

Full Grounded 2 damage internals -- fall path, environmental path,
HealthComponent layout, FDamageInfo offsets, multicast surfaces, kill
detection, what we tried that did not work, the velocity-stomp fix,
UE4SS hooking caveats including issue #626 -- live in
`docs/damage.md` (authoritative subject doc).

## Layout

```
grounded2mods/
  Cargo.toml                Workspace: better-backpack + injector
  rust-toolchain.toml       Stable, x86_64-pc-windows-msvc
  .cargo/config.toml        Target triple, target-dir override
  better-backpack/          cdylib + rlib (the mod itself)
    src/
      lib.rs                DllMain + worker entry
      sdk/                  Hand-written UE SDK shim
        offsets.rs          Steam/Xbox offset tables + field offsets
        fname.rs            FName + AppendString resolver
        fstring.rs          FString = TArray<u16>
        tarray.rs           TArray<T>
        uobject.rs          UObject/UClass/UFunction/GObjectsView/Runtime/find_class_fast
    tests/layout.rs         Static layout asserts
  injector/                 bin: standalone DLL injector (Rust port of inject.c)
  archive/winhttp-proxy/    Old C++ winhttp.dll proxy implementation. Unique Grounded 2 internals already ported to docs/inventory.md and docs/grounded-engine.md. Reference only.
  RUST_PORT_PLAN.md         Migration plan (11 steps)
  archive/winhttp-proxy/PERFORMANCE_AUDIT.md   What we found in the C++ hot path
```

## Mod target (carried over from C++ port)
- Player main backpack capacity = `Maine.UInventoryComponent +0x01E0`
  (`int32 DefaultMaxSize`). Vanilla 40; target 100.
- Mount/saddlebag (vanilla 30) is left untouched.
- Viewport stays 4x10 in the live UI; we rebind 40 visible slots against
  shifting `ItemStartIndex` to scroll. The earlier 6-row growth path is
  retired.

## Key facts
- Game exes: Steam = `Grounded2-WinGRTS-Shipping.exe`, Xbox = `Grounded2-WinGDK-Shipping.exe`.
- Steam offsets (image-relative): GObjects=0x09F67028, AppendString=0x01252060, ProcessEventIdx=0x4C.
- Xbox offsets: GObjects=0x09F36F28, AppendString=0x01250F80, ProcessEventIdx=0x4C.
- UObject layout: vtable@0x00, flags@0x08, index@0x0C, class@0x10, name@0x18, outer@0x20, size=0x28.
- UClass: ClassDefaultObject@0x110. UFunction: FunctionFlags@0xB0.
- Build target dir overridden locally (~/.cargo/config.toml redirects to endless).

## Migration progress (RUST_PORT_PLAN.md)
- [x] 1. Rename C++ tree -> archive/winhttp-proxy.
- [x] 2. Workspace: Cargo.toml + rust-toolchain.toml + .cargo/config.toml.
- [x] 3. Injector crate (Rust port of inject.c). Builds.
- [x] 4. SDK module skeleton (UObject, UClass, UFunction, FName, FString,
     TArray, GObjectsView, Runtime, find_class_fast). Layout tests pass.
- [x] 5. Hook module: vtable.rs (VirtualProtect-guarded slot rewrite) +
     process_event.rs (RAII ProcessEventHook with registry-based dispatch
     and catch_unwind around the closure). Log module (file-only at
     %TEMP%\BetterBackpack.log).
- [x] 6. Patch loop wired in. **Validated in-game**: patch line
     `Default__BP_SurvivalPlayerCharacter_C.InventoryComponent: 40 -> 100,
     verify=100`. AllocConsole brought back so the live mod log surfaces
     in a "Better Backpack" console window the way the C++ build did.
- [x] 7. Inventory-interface hook + viewport rebind. inv_hook.rs +
     parms.rs. Cached UFunction* identity dispatch (no name compares).
     Trace gated by cfg!(debug_assertions). Single hook surface.
     **Hook installs in-game**, log shows
     `inv hook: installed on WBP_InventoryInterface_C` once inventory UI
     loads.
- [x] 8. Trace surfaces in inv_hook.rs are already gated under
     cfg!(debug_assertions). Broader BPF/grid/menu trace coverage from
     the C++ build was intentionally not ported, it was the dominant
     hot-path cost per the audit, and the cached UFunction* identity
     dispatch makes it unnecessary in normal operation.
- [ ] 9. Side-by-side parity test C++ vs Rust DLL.
- [ ] 10. Archive archive/winhttp-proxy/.
- [x] 11. Rust BUILDING.md at repo root. Prerequisites, build, run,
     quality gates, configuration knobs, retargeting via offsets.rs.

## Build commands
- `cargo build --release` builds both crates.
- `cargo test --release` runs layout tests.
- `cargo clippy --release --all-targets, -D warnings` lint gate (clean today).
- Outputs: `target/x86_64-pc-windows-msvc/release/{winhttp.dll, inject.exe}`.
  The mod cdylib is named `winhttp.dll` so it doubles as a Windows DLL
  proxy at install time (drop into game's Binaries\Win64; Windows
  preferentially loads our copy via DLL search order; the 70 forwarder
  exports defined in `better-backpack/winhttp.def` redirect WinHTTP
  calls to `winhttp_orig.dll`, which is a copy of the system winhttp).
- The DLL is locked while the game holds it, rebuild requires the game to
  be closed (or use a different output dir).
- inject.exe with no args looks for `winhttp.dll` next to itself
  (matches cdylib output name). Pass an explicit path to override.

## Logs
- Injector: `<inject.exe dir>/inject.log`, truncated each run.
- Mod: `<DLL_dir>/better_backpack.log`, truncated each DLL load.
  First-line tell for the Rust build is
  `=== Better Backpack DLL (rust) ===`.

## Settings
- `<DLL_dir>/settings.json` (optional; for UE4SS installs this is
  `Mods/BetterBackpack/dlls/settings.json`). Schema in
  `better-backpack/settings.example.json`. Drives slot_count and
  thirst/hunger multipliers. Defaults baked in: slot_count=100,
  thirst_multiplier=0.5, hunger_multiplier=0.5. So out of the box
  (no settings file): 100-slot backpack + half-rate hunger and thirst.
- `<inject.exe dir>/inject.json` (optional). Schema in
  `injector/inject.example.json`. Drives auto-launch behavior:
  Steam app id (default 3104110), optional fallback exe path, poll
  interval and timeout for waiting on the game process.

## Cargo features (better-backpack)
- `console` (default on): spawns the "Better Backpack" console window
  via AllocConsole. Build with `--no-default-features` for a
  console-free shipping DLL. File log unaffected.

## Distribution plan (current, 2026-05-05)

Pivoted twice today. End state: ship as a **UE4SS C++ mod (CPPMod)**
with the source kept in Rust and a tiny C++ shim for UE4SS's
inheritance ABI. Plan + steelman in `UE4SS_PORT_PLAN.md`.

Why UE4SS over the winhttp.dll proxy approach we built earlier:

- UE4SS is the convention for UE5 game mods (UE4SS for Grounded 2 is
  Vortex mod #52, actively maintained). Riding on UE4SS gets us
  Vortex distribution out of the box, central SDK maintenance, and
  network effects with other modders.
- The winhttp proxy works (commits 514e2b1..bfb3447) but Vortex
  doesn't natively model "drop my custom proxy DLL into the game's
  Binaries dir" without a per-game extension.
- Pak distribution inherits the conflict/breakage problems we
  observed on Player Tweaks (Nexus #13).

Approach:

- Rust cdylib exports `better_backpack_start` / `better_backpack_stop`
  as `extern "C"`.
- ~30-line C++ shim derives from `RC::CppUserModBase`, forwards
  `on_unreal_init` and the destructor to the Rust extern functions,
  exports `start_mod` / `uninstall_mod`. Compiled via `cc::Build` and
  linked into the same cdylib.
- Headers consumed from `C:\code\RE-UE4SS` (cloned out-of-band; we
  don't vendor as a submodule because UE4SS's own `.gitmodules`
  references a 404'd repo).
- `UE4SS.lib` import library generated from the user's installed
  `UE4SS.dll` (located via Vortex at
  `<vortex>\grounded2\mods\UE4SS_Grounded2-...\Augusta\Binaries\WinGRTS\ue4ss\UE4SS.dll`)
  using `dumpbin /exports` -> `.def` -> `lib /def:`. Verified the
  DLL exports the symbols we need: `??0CppUserModBase@RC@@QEAA@XZ`
  (constructor), `??1CppUserModBase@RC@@UEAA@XZ` (virtual
  destructor), and every base virtual we'd override or inherit.

Distribution layout:

- Game's UE4SS path is `<game>\Augusta\Binaries\WinGRTS\ue4ss\` --
  note `WinGRTS` (Steam platform identifier in the exe name), not
  `Win64`. Earlier docs had `Win64`; corrected.
- C++ mods go in `ue4ss\Mods\<ModName>\dlls\main.dll`.
- Mod registration is via `ue4ss\Mods\mods.txt` (`ModName : 1` per
  line). Vortex's UE4SS extension merges entries on deploy.
- Our Vortex zip layout:
  ```
  Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/
    dlls/main.dll
    dlls/settings.json
  ```

The earlier winhttp.dll proxy work will be archived to
`archive/winhttp-proxy/` once the UE4SS path lands, kept as a
fallback if UE4SS turns out unstable for Grounded 2.

## Status-effect data-table probe (2026-05-05, latest)

### What we proved this session

Shipped commits b3577bc, ee03b98, 2f2de5d, 98e92ef, 97833be,
725107f, 574a080, plus an unpushed Step 1 stride fix (24 not 16).

- **`Table_StatusEffects` is the single source.** Every active
  effect on the live player traces back to
  `/Game/Blueprints/Attacks/Table_StatusEffects`.
- **`FStatusEffectData` Type at +0x30 and Value at +0x34 are
  correct.** In-game numbers match: `PlayerUpgradeHealth1`
  resolves to `Type=5 Value=20.0` (Type 5 = MaxHealth);
  `MaxHealthSmall` resolves to `Type=5 Value=10.0`. Sum = the
  `MaxHealth(5)=30.0` figure the existing `sfx-probe` already
  reports.
- **`FDataTableRowHandle` layout is `DataTable* (8) + FName (8)`**
  at +0x58 of `UStatusEffect`. Confirmed by reading the row name
  off live effects.
- **The linear TMap walk at stride 16 finds 4 of 13 rows.** Root
  cause identified: UE's `TMap<K,V>` is `TSet<TPair<K,V>>` whose
  element type is `TSetElement { pair: 16, HashNextId: i32,
  HashIndex: i32 }` = 24 bytes, stored in a `TSparseArray` whose
  slot is a union of (TSetElement) and (i32 PrevFreeIndex, i32
  NextFreeIndex) sized to the larger = 24 bytes.

### Where we stopped

Step 1 of the spike plan (in `docs/damage.md` "Concrete spike
plan") landed in `fall_hook.rs::lookup_data_table_row`: stride
bumped from 16 to 24. **Built clean, not yet deployed** -- the
game was holding the DLL when we tried to copy. Pending: user
quits Grounded 2, runs
`pwsh -NoProfile -File scripts/deploy.ps1 -Install -SkipBuild`,
restarts with `impact_resistance >= 1`, takes a fall.

Expectation on next deploy: `rpg/sfx-list` shows Type=N Value=F.FFF
for ALL 13 rows, zero `<row-not-found>`. If a free-list slot ever
collides with a real FName u64 (extremely unlikely), we add the
`AllocationFlags` TBitArray check at `RowMap+16`.

### Next steps (from `docs/damage.md` "Concrete spike plan")

1. (DONE in code, awaiting in-game witness) Stride fix.
2. Mutate one row's `Value`. Test target: write 100.0 to
   `MaxHealthSmall` at +0x34. Linear walk now returns the live
   `uint8*` into the engine's RowMap, not a copy.
3. Resolve `UStatusEffectComponent::CreateAndAddEffect` UFunction,
   build a `FDataTableRowHandle` for `MaxHealthSmall`, call via
   `process_event` on the player's component (+0x1378 on the
   player).
4. Witness via existing `probe_status_effect_values`:
   `MaxHealth(5)=30.0` should jump to `MaxHealth(5)=120.0` after
   a fall.
5. Generalize: add `SkillEffect::PlayerStatusEffect` variant in
   `skills.rs`, migrate `fall_resistance` first (lowest risk;
   velocity-stomp is the fallback), then `impact_resistance`
   (replaces the binary `RequiredDamageTypeFlags = 0xFFFFFFFF`
   hack with a real curve), then `lifesteal`, then the rest.

Docs updated this session: `docs/damage.md` (probe results +
five-step concrete spike plan, commits 725107f and 574a080).

## Skill point refund (2026-05-08)

Added the ability to remove skill points from a skill via the ImGui
tab. Buttons `-1` and `-10` sit next to the existing `+1` / `+10`,
disabled when the skill is at level 0.

- `rpg/tracker.rs`: `refund_skill_point` / `refund_skill_points`.
  Decrements `skill_levels` (removes the map entry at 0), credits
  points back, calls `apply::apply_one`, saves.
- `rpg/ffi.rs`: `bbp_rpg_refund` and `bbp_rpg_refund_many` mirror
  the spend FFI surface.
- `cpp/shim.cpp`: `-1` / `-10` buttons after the existing spend
  buttons, gated `level > 0`.

Release build clean. Pre-existing clippy issues (apply.rs:385,
fall_hook.rs:247/325, skills.rs:88-90) are unrelated to refund and
were not touched.

**Caveat (RESOLVED 2026-05-09)**: previously `apply::apply_skill`
early-returned at level 0, so refunding to 0 left `RequiredDamageTypeFlags`
stale until next world load. Now the mask variant captures vanilla
on first sight and writes either `mask` (active) or vanilla
(disabled / level 0). Toggle off correctly clears the mask.

## Bandage / healing regression from impact_resistance (2026-05-09)

**Confirmed in-game**: enabling `impact_resistance` blocks bandages
and other healing items. Disabling restores healing. The mask gate
`(incoming.type_flags & Required) == 0 -> reject` rejects bandage
heals because the engine routes them through ApplyDamage with
negative damage and `type_flags = 0`, same as fall / environmental
damage. This makes the skill effectively unusable in its current
form -- the player has to keep it toggled off to heal.

The proper fix is the long-tracked status-effect migration: replace
the binary RequiredDamageTypeFlags mask with a type-filtered
`EStatusEffectType::DamageReductionMultiplier` that the engine
consults only on damage events (not heals). See
`docs/damage.md` "Implementation plan" and
`docs/todo.md` "RPG: Status-effect-backed skill rewrite".

Workaround in place: toggle works correctly, mask is restored to
captured vanilla when off. Players retain access to bandages by
disabling impact_resistance temporarily.

## ProcessEvent deadlock removed (2026-05-09)

Toggling fall_resistance off used to freeze the game. The
`USurvivalModeManagerComponent::UpdateCustomSettings` UFunction
call was triggering replication on a Net-flagged field; calling
ProcessEvent on it from any non-game thread (ImGui callback,
world_loader poller) hung on the replication marker.

Reading the SDK + the commit that added it (`6ad1df2`), the call
was dead code -- the original commit's own changelog notes that
fall damage still landed even with the UFunction firing, and the
actual mitigation is the velocity-stomp in `fall_hook.rs` plus the
RequiredDamageTypeFlags mask. Native fall-damage code never reads
FallDamageMultiplier. Deleted the call entirely; field writes
remain harmless.

Next steps:
- Status-effect migration (impact_resistance, lifesteal, fall_resistance).
- Resume `docs/damage.md` "Concrete spike plan" Step 1 in-game
  witness.

## Where we left off (2026-05-05, late-night)

**State (RESOLVED, working in-game 2026-05-05):**
- `main.dll` builds clean, exports `start_mod` / `uninstall_mod` /
  `DllMain` / `better_backpack_start` / `better_backpack_stop`.
- `deploy.ps1 -Install` works against the user's
  `C:\Games\Steam\steamapps\common\Grounded2\` install.
- UE4SS v3.0.1 Beta loads our mod, `on_unreal_init` fires, Rust
  side takes over. cpp_shim.log shows full lifecycle.

**Crash root cause:** vtable mismatch in `cpp/shim.cpp`'s
`RC::CppUserModBase` mirror. Data layout was fine (both shim and
UE4SS report sizeof=192). The vtable was missing six methods vs
`RE-UE4SS/UE4SS/include/Mod/CppUserModBase.hpp`: `on_ui_init`
(slot 4), four newer `on_lua_start`/`on_lua_stop` overloads taking
`Lua*` instead of `vector<Lua*>&` (slots 12-15), and
`on_cpp_mods_loaded` (slot 16). UE4SS dispatched through the later
slots during init -> jumped past our vtable -> crash.

**Fix:**
- Added all six missing virtuals in exact declaration order from
  the upstream header.
- Changed `on_dll_load` parameter from `std::wstring_view` to
  `StringViewType` to match the header verbatim.
- `on_cpp_mods_loaded` is NOT marked `RC_UE4SS_API` (dllimport):
  UE4SS.lib doesn't export this symbol. Using local inline body.

**Next:**
- docs/todo.md item 1 step 8 (archive winhttp proxy material).
- docs/todo.md item 2 (project rename) and items 3-7 (new feature
  multipliers).

## RPG pivot (2026-05-05)

Direction shift: turning the mod into a Factorio-RPG-style
level-up mod. Kills -> XP -> levels -> skills that drive the
existing CDO patches. Research questions R1-R5 answered against
the SDK at `C:\tools\work\sdk\`, see docs/todo.md section 0.

### Spike B: persistence working (2026-05-05)

PlaythroughGuid resolves at runtime. First attempt used
`USaveLoadManager.SaveInProgressSaveGameHeaderData` (+0x90) but
that's null except during an active save operation. Switched to
`AInGameGameState.PlaythroughGuid` at +0x32C
(`Maine_classes.hpp:28544`), populated for the duration of
the active session, exactly what we need.

Files:
- `rpg/save_slot.rs`: walks GObjects for an InGameGameState
  instance (skip CDO), reads PlaythroughGuid as 32-char hex.
- `rpg/state.rs`: PlayerState (kill_count, last_killed) with
  serde JSON load/save under `<DLL_dir>/saves/<guid>.json`.
- `rpg/tracker.rs`: in-process state with lazy slot resolution
  (since the save isn't loaded at worker startup).

In-game test confirmed: kill -> "no prior save for slot=06d9929b"
-> "saved kill #1" -> file written. Reload test pending.

### Eager state load on world entry: DONE (2026-05-05)

`rpg/world_loader.rs` spawns a 1Hz poller from worker init
that watches `save_slot::current_slot_key` and calls
`tracker::activate_slot` / `deactivate_slot` on transitions.
Handles save-swap (Some(a) -> Some(b)) too.

Tracker refactored: kill recording no longer lazy-resolves the
slot. If no slot is bound it logs+drops; in practice the
loader activates within 1s of world entry, well before the
player enters combat. State.rs collapsed to a simple
load_one(slot), loader owns slot resolution.

Future skill-driven CDO/instance reapply will plug into the
activation transition: when activate_slot fires with a freshly
loaded PlayerState, walk the player CDO + live pawn instances
and apply current skill multipliers. Stubbed until skills exist.

### Buggy kill attribution + XP layer: DONE (2026-05-05)

`kill_hook.rs::classify` returns three buckets via class-name
inspection (no UFunction calls; pure pointer-walks):
- Player: instigator class chain contains "PlayerController".
- Buggy: instigator (or its possessed Pawn at +0x308) class
  chain contains "Buggy".
- Other: enemy-vs-enemy AIC; logged + dropped.

Confirmed in-game: PLAYER on Grub kills,
BUGGY on Spiderling killed by `AIC_AntSoldier_Augusta_Buggy_C`,
no false positives. Multiplayer ownership question (other
players' Buggies) deferred, single-player works correctly.

XP layer landed alongside: `rpg/xp.rs` (100 * N^1.8 cumulative
curve, cap 50, ~20-species placeholder table). PlayerState
schema bumped to (xp, level, skill_points, skill_ranks)
backwards-compatibly via `#[serde(default)]`. tracker awards
XP on kill, recomputes level, grants skill points on level-up.
buggy_kill_xp_multiplier setting (default 1.0) scales Buggy
kills.

Open items for the loop:
- Apply step: BUILT 2026-05-05 in `rpg/apply.rs`. Captures
  vanilla survival rates at init; at activate_slot, writes
  skill-layered values (settings_base + skill_bonus, or
  vanilla * settings_mult * skill_mult) to CDOs.
- Skill catalog: BUILT 2026-05-05 in `rpg/skills.rs`. Three
  skills (backpack, hunger, thirst). Per-rank math:
  backpack +5/rank max 12, hunger/thirst -7.5%/rank max 10.
- ImGui tab via `register_tab` in the C++ shim: DONE
  (2026-05-05). Vendored upstream ocornut/imgui v1.92.1 into
  `better-backpack/cpp/imgui/` (matches UE4SS's version), wired
  into build.rs as 4 .cpp sources alongside shim.cpp. Forward-
  declared `RC::UE4SSProgram::get_current_imgui_context` and
  `get_current_imgui_allocator_functions` with `RC_UE4SS_API`
  (dllimport, resolves through UE4SS.lib at link). Lambda calls
  `rpg_enable_imgui()` to point our linked imgui at UE4SS's
  context, then renders Level / XP bar / skill rows with `+1` /
  `+10` buttons.

  C-ABI surface in `better-backpack/src/rpg/ffi.rs`: 8 functions
  the lambda calls (has_active_slot, get_level, get_xp,
  get_xp_for_current_level, get_xp_for_next_level,
  get_skill_points, get_skill_count, get_skill, spend).
  Each wrapped in catch_unwind so a Rust panic can't take down
  UE4SS's render thread.

  Symbol mangling gotcha (resolved): UE4SS exports
  `register_tab` as a *protected* method
  (`CppUserModBase.hpp:212`). MSVC C++ name mangling encodes
  access (Q=public, I=protected). First attempt with public
  caused LNK2019; moved to protected section of our mirror.

  In-game confirmed: tab visible, live XP updates after kills,
  Buggy attribution + persistence loop working across launches.

Settings as base, skills layered on top: settings.json defaults
flipped to vanilla (slot_count=40, hunger/thirst_mult=1.0).
User can override defaults if they want a starter buff. Skill
ranks then layer on top: backpack target = settings.slot_count
+ 5*rank; survival target = vanilla * settings_mult * skill_mult.

### Spike A: DONE (2026-05-05)

Attempt 1 (Kill UFunction) failed because `Kill` is
`Final|Native` and the engine bypasses ProcessEvent on the
internal damage path.

Attempt 2 used Option A from the options doc (NOT the global
PE hook). Key insight: SDK has
`enum class EDamageInfoFlags { KillingBlow = 2, ... }` at
`Maine_structs.hpp:1769`. The
`MulticastHandleEffectsWithDamageFlags` UFunction on
HealthComponent fires via PE on every damage hit and carries
the DamageFlags parm. Mask with KillingBlow bit -> we know if
this hit was lethal.

In-game confirmed: kill a creature -> one log line with dying
actor + class + killer controller + killer class. No global PE
hook needed; per-vtable hook on HealthComponent is sufficient.

Implementation: `better-backpack/src/rpg/kill_hook.rs`. ~80
lines. Filters to `ASurvivalCreature` subclasses to exclude
buildings/props which also fire this function on destruction.

### Side issue noticed

Log shows `initial patch round: scanned=2, patched=0` and
`survival patch: scanned_classes=0, patched=0`, the existing
backpack/hunger/thirst patches may be running before GObjects is
fully populated, or there's been an SDK shape change. Not
related to RPG track. Investigate when convenient.

### Movement skill fix verified

Manual test confirmed Move Speed now works in-game.

Fix was two parts:

- Retarget movement writes to include Grounded-specific fields on
  `UMaineCharMovementComponent`, including
  `CustomGroundSpeedMultiplier` (+0x1198),
  `CustomFlySpeedMultiplier` (+0x119C),
  `CustomSwimSpeedMultiplier` (+0x11A0), and
  `MaxSwimSprintSpeed` (+0x1164).
- Mirror movement writes onto live player pawns, not just player CDOs.

This closes the earlier suspicion that generic UE movement caps alone
were insufficient for Grounded 2 locomotion.

## Bugs found and fixed during testing
- **GObjects extra indirection** (2026-05-04): GObjectsView::from_image was
  treating `image_base + g_objects` as a pointer-to-pointer and
  dereferencing once. The address IS the TUObjectArray struct directly.
  Symptom: log halted after platform detection. Fixed in sdk/uobject.rs.
- **find_class_fast missed Blueprint classes** (2026-05-04): meta-class
  filter only matched native `Class`. Blueprint-generated classes have
  meta-class `WidgetBlueprintGeneratedClass` (a subclass of `Class`).
  Symptom: inventory hook never installed. Fix: walk meta-class
  super_class chain.
- **Injector default DLL name PascalCase mismatch**: cdylib output is
  `better_backpack.dll`; injector default was `BetterBackpack.dll`. Fixed
  injector to match cdylib output.
- **Live console missing**: C++ DLL spawned a console via AllocConsole;
  Rust DLL had to too. Re-added with WriteConsoleA + file mirror.
- **Injector closed too fast**: added pause-before-exit (--no-pause to
  skip) and per-run inject.log.

## Known minor issues
- The CDO patch only reaches inventory instances constructed AFTER the
  DLL loads. If the player's inventory was constructed before injection,
  a save reload may be required to see 100 slots in-game.

## Worker thread lifecycle (revised 2026-05-04)
- Worker patches the CDO once, then installs the inv hook with backoff
  retry, then **exits**. No 10-second rescan loop. CDO patches are
  sticky for the lifetime of the DLL; UE does not re-load CDOs during a
  session. Save loads spawn fresh inventory instances that inherit from
  the patched CDO automatically.
- If a real CDO-revert scenario is ever observed, switch to
  `FUObjectArray::AddUObjectCreateListener` (canonical UE4SS pattern,
  ~100 lines) instead of bringing back the polling loop.

## Open questions
- Step 6 needs validation that calling `original` ProcessEvent from a Rust
  hook closure preserves UE's thiscall expectations on this platform.
- DllMain TLS hazard: keep DllMain to `CreateThread` only; all std work in
  the worker.
- Panic-in-hook: every hook closure wraps body in `catch_unwind`, falls
  through to original on panic.
