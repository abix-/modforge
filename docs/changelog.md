# Changelog

> **Authoritative on:** chronological history of milestones,
> investigations, and design pivots across every crate in the
> workspace. Things that are DONE.
>
> For what's next see [`todo.md`](todo.md). For per-subject
> deep dives see each crate's `docs/` folder:
> [`../ueforge/docs/`](../ueforge/docs/) for the framework,
> [`../grounded2-rpg/docs/`](../grounded2-rpg/docs/) for the
> Grounded 2 mod.

Newest first.

## 2026-05-10 (Phase 3 wave 2: g2rpg catalog + framework lifts)

### bbp catalog migrated to `Standard(StandardEffect)`

`grounded2-rpg::SkillEffect` shrunk from 11 variants to 4. Nine
of 13 catalog skills now route through `ueforge::rpg::std_effect::
StandardEffect` (Attack Damage, Armor, Move/Jump/Glide/Leap,
Impact Resistance, Lifesteal, Max Health, Health Regen). The four
that stay game-specific are genuine composites: Backpack
(InventoryComponent CDO write), Hunger / Thirst (settings-multiplier
drain), and Fall Damage (multi-component HC ratio + GMS CDO + SMMC
live + UFunction call).

`apply::apply_skill` collapsed from 11 arms to 4. The Standard arm
forwards `e.apply(level, max_level, &PLAYER)` to the framework with
zero game-specific dispatch. `format_effect` followed: `Standard`
delegates to `StandardEffect::format`, the other three arms keep
their tailored format strings. ~570 lines of duplicated apply +
format dispatch deleted.

### Framework lifts (DRY for the next UE-game RPG)

Five extractions to ueforge so a future ows-rpg ships with only
game-specific logic:

- **`ueforge::rpg::Bestiary`** — per-creature XP table keyed by BP
  class short name with a default-fallback. Replaces a per-game
  `OnceLock<Vec<(&str, u32)>>` + linear-scan helper.
- **`ueforge::ue::field`** — generic untyped UObject byte ops:
  `read_f32` / `write_f32` / `read_u32` / `write_u32` / `read_i32` /
  `write_i32` / `read_bool` / `write_bool` / `read_component_ptr`.
  The TypedField counterpart still exists for structured sites;
  these are the escape hatch for runtime-decided offsets.
- **`ueforge::ue::actor`** — kill-hook universals:
  `class_chain_contains(obj, needle)` walks the UClass + super
  chain looking for a class-name substring (depth-bounded);
  `controller_pawn(controller)` reads the stable `AController.
  Pawn` slot at `+0x0308`; `describe(obj)` formats `name(class)`
  for log lines; `A_CONTROLLER_PAWN_OFFSET` constant.
- **`FWeakObjectPtr::read` + `::resolve`** — fold the index
  validation + Runtime + GObjectsView walk into one method on the
  existing struct. Two callers in g2rpg's kill_hook collapsed to
  single-line uses.
- **`ueforge::debug`** — first wave of the debug-endpoint scaffold:
  `PlayerStateView::from_state`, `CatalogEntry`, `catalog_view`,
  `STANDARD_OPS`. Game-specific snapshot collectors stay in the
  game crate; the universal view types and op-list metadata are
  shared.

After these lifts: g2rpg's `apply.rs` is 320 lines (was 814);
`skills.rs` is 460 lines (was 544); `xp.rs` is 53 lines (was 63
including bespoke OnceLock); `kill_hook.rs` shed ~50 lines of
duplicated UE-class-chain + weak-ptr walk; `debug.rs` shed ~30
lines of view-struct boilerplate. All ueforge unit tests
green (62 pass).

### Hardening bundle: HTTP auth + FName size guard

Three kovarex P1/P2 items resolved in one pass:

- **HTTP per-launch auth token** -- `server::Config::auth_token:
  Option<&'static str>`. When `Some(t)`, every request must carry
  `X-Ueforge-Auth: <t>` header or gets a 401. When `None`, no
  auth (back-compat default). `client::Api::with_auth(token)`
  builder method on the test client. Token generation + storage
  stays a consumer concern; one-line at startup.
- **FName size guard** -- `const _: () = assert!(size_of::<FName>()
  == 8 && align_of::<FName>() <= 8)` in `ue::fname.rs`. If UE
  ever changes the layout beneath our `transmute_copy::<u64,
  FName>` sites, this fires at build time instead of silently
  corrupting names at runtime.
- **`process_event_idx`** -- audited; already correctly required
  on `PlatformOffsets` (no Default impl, both STEAM/XBOX consts
  set it explicitly). Todo entry was misadvised; closed.
- **`#[non_exhaustive]` audit** -- correctly skipped. `ModInfo` /
  `Tab` / `PlatformOffsets` / `Config` are literal-constructed
  by every consumer; `#[non_exhaustive]` would break the call
  sites without giving us actual API stability. In a monorepo
  with atomic updates, breaking changes mean "one-line update
  at the call site in the same commit" -- which is fine.
  Documented the rationale in todo.md so future audits don't
  re-litigate.

### Pillar 5: Damage hook framework + Lifesteal live

`ueforge::damage::DamageHook<B>` -- universal damage-event hook,
the fifth pillar. Same shape as the inventory viewport hook:
config struct + binder trait. Owns the multicast UFunction
trampoline + parm decode (Damage / DamageFlags / TypeFlags) +
`FDamageInfo` lookup (instigator resolution via
`DamageInfoLayout`) + Player/Other classification (via
`is_outer_named` + `class_chain_contains`) + `before` /
`after` dispatch (binder mutates damage pre-application or
reacts post-application).

g2rpg-side migration:

- `kill_hook.rs` rewritten as a `DamageBinder` impl. Owns the
  Maine `DamageHookConfig` (component class + UFunction +
  parm offsets), the `KillerKind` classifier (Player /
  Buggy / Other -- buggies are tame G2 mounts), and the
  per-event reactions: damage-trace push, impact-resistance
  reversal, kill credit, Lifesteal heal.
- `damage_trace.rs` (168 lines) and `impact_resistance.rs`
  (79 lines) deleted. Their logic now lives inside the binder
  using the framework's already-decoded `DamageEvent`.
- Total g2rpg damage code: 474 lines (3 files) -> 238 lines
  (1 file).

**Lifesteal landed live**: when an attacker classified as
the player damages a non-player victim, the binder reads the
player's lifesteal level from the live tracker, computes
`heal = damage * 0.90 * sqrt(level/100)`, walks
`PLAYER.first_live_static` to the live HC at +0x1340, and
decrements `CurrentDamage` at +0x32C (clamped to 0). Skill
toggle honored. Catalog row already existed
(`Standard::Runtime` with `max_bonus = 0.90`); previously a
no-op since no live-damage hook was wired. Now functional.

Critical / Evasion / Thorns rows pending; the framework
shape supports them (Critical = `before` returns multiplied
damage on roll; Evasion = `before` returns 0 on roll;
Thorns = `after` walks attacker's HC + applies %).

### Hot-update Phase B complete (B1-B5: safe Ctrl+R with hooks)

Five lifts that close the loop on hot-update -- Ctrl+R is now
safe even with PE hooks installed:

- **B1: `ueforge::hook::registry`** -- `register(hook)` /
  `register_many(hooks)` / `shutdown_all()`. Hook handles live
  in a `static Mutex<Vec<ProcessEventHook>>` instead of being
  `mem::forget`-ed. `shutdown_all` drops every handle in
  registration order.
- **B2: `SHUTTING_DOWN` + `active_calls` drain.**
  `process_event::SHUTTING_DOWN: AtomicBool` short-circuits new
  trampoline fires straight to engine's original ProcessEvent.
  Each `Entry` carries `active_calls: AtomicUsize` incremented
  at trampoline entry, decremented at exit. `Drop` restores the
  vtable slot, then spins (with `thread::yield_now`) up to
  500ms for the counter to hit zero. Logs a warning on timeout.
- **B3: `server::SpawnHandle` + `server::shutdown_all`.**
  `spawn` registers (Server Arc + JoinHandle); `SpawnHandle::stop`
  calls `tiny_http::Server::unblock` then joins. `shutdown_all`
  clears the registry, dropping every handle.
- **B4: `ueforge_mod_shutdown` orchestration.** The macro path
  now runs:
  1. game's `MOD_INFO.on_shutdown`
  2. `hook::shutdown_all` (uninstall + drain)
  3. `server::shutdown_all` (stop listeners + join)
  4. `mod_main::finalize_hot_reload_swap` (side-file rename)
- **B5: g2rpg-side adoption.** `mem::forget` calls in
  `lib.rs::worker` replaced with `ueforge::hook::register` /
  `register_many`. `install_immediate_or_log` (already routes
  through registry) keeps its existing call sites.

Dev loop now end-to-end:

```
1. edit Rust
2. cargo deploy install -p grounded2-rpg     # writes main-new.dll
3. alt-tab to game, Ctrl+R                   # ~1-2s reload
4. test
```

State on disk (save slots, settings, catalog) survives; the new
image reads it on slot activation. From close-to-test cycle of
60-180s down to ~5s.

### Hot-update Phase B0 shipped (side-file deploy)

Implemented the side-file pattern (user's design) for hot-deploy
while the game is running. Two pieces:

- `cargo deploy install` (`ueforge/src/bin/ueforge_deploy.rs`):
  writes to `main-new.dll` when `main.dll` already exists; first
  deploy writes `main.dll` directly. The side-file path is never
  locked (no live image at that path) so `fs::copy` succeeds
  while UE4SS has the running DLL mapped.
- ueforge shim's `ueforge_mod_shutdown`
  (`ueforge/src/mod_main.rs`): after the game's `on_shutdown`,
  the framework's `finalize_hot_reload_swap` checks for
  `main-new.dll` and -- if present -- renames `main.dll` ->
  `main-old.dll` (`SHARE_DELETE` permits the rename of the
  loaded image) then `main-new.dll` -> `main.dll`. Rolls back
  on step 2 failure to leave the dir consistent. Logs the swap.
- ueforge shim's `ueforge_mod_unreal_init` calls
  `cleanup_old_dll` once on the new image's first init --
  best-effort `remove(main-old.dll)`.

Verified empirically (PowerShell test loading `version.dll`
through every step of the swap; all five succeeded -- rename
loaded DLL, rename side-file into place, FreeLibrary, delete
old, LoadLibrary new).

**Workflow today**: edit Rust -> `cargo deploy install` (no
need to close the game) -> close + reopen the game. The
shutdown swap fires on close so the next launch loads the new
image. Net win: you can deploy in parallel with running
sessions instead of having to close first.

Phase B1-B5 (HookRegistry::shutdown_all + active_calls drain +
SpawnHandle::stop) still pending; until they ship, Ctrl+R is
unsafe with PE hooks installed (old DLL's vtable patches point
into freed memory after FreeLibrary). Close + reopen the game
between iterations until then.

### Hot-update: locked-DLL gotcha verified

Earlier hot-update doc claim ("just `cargo deploy install` while
the game runs") was wrong. Verified empirically (PowerShell test
loading `version.dll` then attempting overwrite + rename):

- **Direct overwrite of a loaded DLL: fails** with sharing
  violation. `LoadLibraryExW` opens the file with
  `FILE_SHARE_READ | FILE_SHARE_DELETE` (no SHARE_WRITE), so
  `fs::copy` over a live DLL gets `os error 32`.
- **Rename old -> `.old`, then write new: works.** `SHARE_DELETE`
  permits the rename; the new file lives at the canonical path
  for next `LoadLibraryExW`.

`cargo deploy install` today uses `fs::copy` and reports "file in
use". The fix (Phase B0 in `docs/todo.md`) is rename-and-replace
on sharing-violation. Lifecycle + building docs updated to
reflect reality + flag this as an open blocker.

### Hot-update research (Phase A complete)

Confirmed that UE4SS supports full hot-**update** of cpp mods
natively, not just hot-reload. The flow:

- `Ctrl+R` (default; `EnableHotReloadSystem` + `HotReloadKey` in
  UE4SS-settings.ini) calls `UE4SSProgram::queue_reinstall_mods`.
- `uninstall_mods()` calls each cpp mod's `uninstall_mod` ->
  `~UespyMod()` -> our `ueforge_mod_shutdown` -> game's
  `MOD_INFO.on_shutdown` callback.
- `~CppMod()` calls `FreeLibrary(main.dll)` -- our DLL detaches.
- `setup_mods()` rescans disk and `LoadLibraryExW`-s a **fresh**
  `main.dll`. **This is the hot-update step**: whatever DLL is
  on disk gets loaded, so a `cargo deploy install` between
  build + Ctrl+R lands the new build.
- `start_cpp_mods()` -> `start_mod()` -> fresh `UespyMod` ->
  `on_unreal_init` -> our worker init runs again.

Dev loop becomes:
```
1. edit Rust
2. cargo deploy install -p grounded2-rpg
3. alt-tab to game, press Ctrl+R
4. new version is live in ~1-2s
```

Static state in the DLL resets (intended -- atomics, OnceLocks
reload from disk via `Tracker<A>::activate_slot`). Cached UE
references survive (they point INTO the game process, not into
our DLL); the new image re-resolves on first use.

**Phase B implementation pending.** Until it lands, mods that
install `ProcessEventHook`s (kill / fall / inv) cannot safely
hot-reload -- the old DLL's vtable patches still point into
freed memory after FreeLibrary. The Phase B plan
(`docs/todo.md`):

- B1: `HookRegistry` + `shutdown_all()` (track + drop hook
  handles instead of `mem::forget`).
- B2: `SHUTTING_DOWN` flag + `active_calls` counter per hook;
  Drop waits for trampoline drain.
- B3: `server::SpawnHandle::stop()` for HTTP listener.
- B4: Wire `ueforge_mod_shutdown` to call `shutdown_all`
  before the game callback.
- B5: g2rpg: stop using `mem::forget` on hook handles.

`ueforge/docs/lifecycle.md` updated with full hot-reload section
covering mechanism, dev loop, what survives / resets, and the
Phase B caveat.

### Pillar 4: Inventory viewport-paging framework

`ueforge::inventory::viewport` -- the universal "fixed-size
visible grid over a larger underlying inventory" pattern,
extracted from g2rpg's `inv_hook.rs`. Owns the algorithm + state
+ ProcessEvent hook trampoline + mouse-wheel scroll handling +
per-widget viewport-start map + synthetic-refresh re-entrance
guard + post-refresh rebind + construct-reset.

Game crate writes a [`ViewportConfig`] (class name + UFunction
names + grid offset + page size + scroll step) and a
[`ViewportBinder`] trait impl with two methods (`mouse_wheel_delta`
extraction from the game's `OnMouseWheel` parm bytes, `bind_slot`
calling the game's "initialize visible slot" UFunction) + a
`begin_rebind` associated context for caching per-cycle state
(typically the `GetInventoryItems` TArray result so we don't
re-call it 40x per scroll).

g2rpg's `inv_hook.rs` shrank 396 -> 220 lines (-176). The remaining
220 lines are: Maine-specific class names + UFunction parm `#[repr(C)]`
mirrors + the binder impl that wires the Maine UFunction handles
together. The viewport-start state, mouse-wheel delta dispatch,
re-entrance guard, post-refresh rebind, and the install / log /
class-name lookup machinery are all framework-side.

`grounded2-rpg/src/parms.rs` also shrank: `IntReturnParms`,
`GetChildAtParms`, `SelectedIndexParms`,
`SetSelectedInventorySlotParms` deleted (the framework's
`PanelWidget` helper owns the UMG-side parms; the
selected-slot parms were always unused).

### Heterogeneous-pillar principle (formalized)

ueforge's `lib.rs` doc-header + `README.md` now formalize the
design rule: **each universal pattern is defined ONCE in
ueforge.** Pillars (rpg / stacks / difficulty / inventory) are
independent modules, opt-in via use sites. A pure stack-size mod
only consumes `stacks`. An RPG-only mod only consumes `rpg`. A
mod that uses all four pillars picks one knob from each menu and
ignores the rest. Game crates carry only game-specific knowledge
(UE class names, field offsets, UFunction parm shapes); the
per-game extension surface is `&'static` config + an opt-in
trait impl.

If you find the same scaffolding in two game crates, that's a
missing pillar lift -- file under "Open: more ueforge extraction
candidates" in `docs/todo.md`.

### Settings hot-reload + PE-call + OpRouter PE-ops half

Three more lifts that close out most of the "Open: more ueforge
extraction candidates" list:

- **`Settings::watch(interval, on_reload)`** -- spawns an
  mtime-poller thread that reloads `<DLL_dir>/<file>.json` when
  it changes on disk and fires a game-supplied `on_reload(&T)`
  callback. Drop the returned `WatchHandle` to stop. `reload()`
  available standalone for tab-driven manual reloads / debug
  ops. Tests pass; build clean.
- **`ueforge::ue::pe_call::call_ufunction`** -- folds "find
  UFunction or error -> process_event with parm pointer" into
  one safe-typed call. g2rpg's `exec_add_health` /
  `exec_set_current_health` collapsed to use it; covers every
  future health / inventory / status-effect op shape with one
  primitive instead of a per-fn boilerplate copy.
- **`ueforge::debug::dispatch_pe_ops`** -- the second half of
  the OpRouter lift. Handles `call` / `read_bytes` /
  `write_bytes` (the three standard ops that need a per-game
  instance resolver). Combined with the already-shipped
  `dispatch_standard_op`, every standard op now routes through
  one of two ueforge dispatchers with one line per group.

g2rpg's `debug.rs`: 770 -> 737 lines. The handler is now three
guard arms (snapshot / dispatch_standard_op / dispatch_pe_ops)
+ four game-specific simulate_* arms + the unknown-op error.

### Three pillars: rpg / stacks / difficulty

ueforge now ships opinionated framework modules for the three
most common UE5 mod patterns, each wrapping a low-level primitive
with the universal apply-loop + atomic-knob + status-counter
shape:

- **`ueforge::rpg`** (existing) -- skill catalog, XP curve,
  bestiary, per-slot persistence, ImGui tab, the
  `StandardEffect` 8-variant menu.
- **`ueforge::stacks`** (new) -- inventory stack-size data-table
  tweak. Wraps `FieldTweak<i32>` with multiplier atomic, last-
  applied / ever-applied counters, on-first-sight worker, and
  apply-now / revert helpers. Game crate writes one
  `StackTweak::new(table, offset, default_mult, skip_predicate)`
  static.
- **`ueforge::difficulty`** (new) -- CDO field tweak for
  difficulty knobs (drain rates, damage multipliers, regen,
  etc). Wraps `ClassFieldTweak<f32>` with f32 multiplier atomic
  + apply_to_cdos / apply_to_all / apply_with_filter / revert.
  Game crate writes one `DifficultyKnob::new(class, offset)`
  static per knob and calls `set_multiplier` + `apply_to_cdos`.

Migrations:

- `outworld-station-tweaks/src/stacks.rs`: 86 -> 64 lines (-22).
  The vanilla snapshot, multiplier atomic, status counters, and
  apply worker all moved to `StackTweak`.
- `grounded2-rpg/src/survival.rs`: 85 -> 41 lines (-44). The
  hand-rolled "skip if multiplier == 1.0", `ClassFieldTweak`
  invocations, and stat aggregation all collapsed into
  `DifficultyKnob::apply_to_cdos`.

The framework's design rule going forward: a UE5 game implementing
RPG + stacks + difficulty writes ONLY game-specific knobs (table
names, field offsets, multiplier UI, settings persistence). No
re-implementation of the apply loop, the vanilla cache, or the
counter atomics.

### Bootstrap + class-name lookup helpers

Three more universals lifted to ueforge so each new mod's
boilerplate shrinks:

- **`ueforge::ue::platform::detect_and_init`** -- one-call
  replacement for the 15-line "detect host exe -> pick offsets ->
  log image_base/GObjects -> init_runtime" boilerplate every
  mod's worker thread runs at startup. Falls back to the first
  platform row with a WARN if the host exe doesn't match.
- **`ueforge::ue::with_first_instance_of(class_name, f)`** /
  **`with_first_cdo_of`** -- string-keyed convenience wrappers
  for ad-hoc snapshot / debug call sites. Replaces 4 `apply::*`
  helpers in g2rpg.
- **`PlayerRef::first_live_static`** (unsafe) -- the
  game-thread-only "first live pawn as `&'static UObject`"
  pattern, used by debug-endpoint resolvers that pass refs
  through queued-closure boundaries. Wraps the unsafe-extend-
  lifetime trick in one place with a clear safety contract.
- **`ClassRef::with_first_cdo`** -- symmetric counterpart to
  the existing `with_first_instance`.
- **`ueforge::hook::install_immediate_or_log`** -- the universal
  "install once, log success or failure, leak handle" pattern
  every mod's worker runs per hook. Replaces the hand-rolled
  `match try_install() { Ok(h) => log + forget; Err(e) => log }`
  triplet at every call site.

g2rpg's `lib.rs` shrank 151 -> 136 lines (-15); `debug.rs`
shrank 786 -> 770 (-16); `apply.rs` shrank 398 -> 371 (-27 by
deleting `first_instance_of` / `class_default_object`
wrappers).

### debug.rs scaffolding lift

Promoted four pieces of g2rpg's debug endpoint to ueforge so the
next mod's `debug.rs` doesn't re-implement them:

- **`ueforge::debug::DamageEvent` + `DamageRing`** -- shared event
  shape + EventRing wrapper with the standard accessors. Game
  crates declare `static RING: DamageRing = DamageRing::new(64);`
  and call `record` / `snapshot` / `pushes` / `peak`.
- **`ueforge::debug::ProcessSnapshot`** -- bundles the five
  system-metric JSON fields (counters, process memory, CPU,
  threads, GObjects population, regions) behind a single
  `collect(counters_json, top_classes)` call.
- **`ueforge::debug::dispatch_standard_op`** -- single function
  handling 8 of the 12 standard ops (`skill_*`, `reload_slot`,
  `set_skill_points`, `walk_class`, `class_outer_samples`,
  `sample_thread_modules`). Returns `Option<Result<Json,String>>`;
  game crates fall through to their own ops on `None`.
- **`ueforge::debug::enqueue_pe`** -- generic "queue a closure on
  a DrainSite with timeout + custom hint" wrapper.

g2rpg's `debug.rs` shrank 896 -> 786 lines (-110). The remaining
weight is genuinely game-specific: HcFields/CmcFields/AscFields
view types + Maine class-name CDO collectors + simulate_*
executors with their G2-specific UFunction parm structs.

### kill_hook split + `DamageInfoLayout` lift

Second pass on `kill_hook.rs`. The 604-line file mixed three
concerns -- kill-credit dispatch, diagnostic damage tracing, and
impact-resistance reversal of environmental damage. Split into
three focused modules:

- `rpg/kill_hook.rs` (227 lines) -- kill-credit core only:
  install + on_event + KillerKind classifier + award_kill.
- `rpg/damage_trace.rs` (168 lines) -- per-fn parm decoder,
  damage_ring observer, `LastDamageInfo` log dump.
- `rpg/impact_resistance.rs` (79 lines) -- environmental-damage
  detection + post-application reversal.

Universal pieces lifted to ueforge:

- **`ueforge::ue::damage_info::DamageInfoLayout`** -- per-game
  offset config for the `FDamageInfo` struct (instigator,
  source, damage-type class, damage flags). Methods fold the
  weak-ptr resolve + UClass cast into one call. The shape is
  universal across UE5 RPGs; only the offsets differ.
- **`ueforge::ue::actor::is_outer_named`** -- player-filter
  shorthand (`this.outer().full_name().contains(needle)`).
- **`ueforge::ue::actor::outer_class_name`** -- common log-line
  builder.

g2rpg's kill_hook can now point at the next UE5 game and the
authors clone-and-tweak only the killing-blow parm offset
(`MULTICAST_DAMAGE_FLAGS_OFFSET`), the player-outer string, the
creature-class string, and the per-game `DamageInfoLayout`. Every
other line is universal.

## 2026-05-10 (hardening + ops extraction)

### Kovarex P0 + P1 hardening shipped

All five P0s + four of six P1s closed:

- **`SlotStore::save -> io::Result<()>` + fsync.** Save returns
  `Result`; tracker logs + caches via `last_error()` accessor for
  snapshot surfaces. Atomic save now opens the temp explicitly,
  writes, calls `sync_all()` (durability across power loss),
  then renames. 4 unit tests on save/load/round-trip + parent
  creation.
- **`SlotStore` slot-path validation.** Reject empty / leading
  dot / path separators (`/`, `\`, `:`, `\0`) in slot keys;
  invalid keys route to a sentinel `__invalid__.json` so
  malformed input is visible. Closes the kovarex P1 path-
  injection vector alongside the P0 fixes.
- **`SlotPoller::Handle` + shutdown.** `SlotPoller::spawn`
  returns `PollerHandle` with `stop()` flipping an
  `Arc<AtomicBool>`. Worker is named `ueforge/rpg/slot-poller`
  via `thread::Builder::name` (visible to debuggers).
  `bbp_on_shutdown` now calls `world_loader::shutdown()` so
  the worker doesn't outlive an unloaded DLL on hot-reload.
- **`SlotPoller` panic visibility.** Each tick wraps
  resolve / activate / deactivate in `catch_unwind`. Panics
  are counted (`PollerHandle::panic_count`), the most recent
  payload exposed via `last_panic()`, the worker keeps running.
  bbp surfaces both via `world_loader::panic_count()` /
  `last_panic()`.
- **Spend/refund transactional with persistence.** Removed
  `pub fn spend` / `pub fn refund` from `SkillsState`. The
  only path now is `Tracker<A>::{spend,refund}_skill_points`,
  which mutates state and calls `store.save()` under the
  same lock.
- **`DisabledSkills` -> `ArcSwap`.** Reads are lock-free now;
  writers clone-modify-publish through a writer mutex. ImGui
  per-row + apply per-CDO calls stay on the fast path even
  with frequent toggles. 4 unit tests.
- **`Curve::level_for_xp` upper guard.** Added
  `MAX_LEVEL_LIMIT = 1024` const + `assert!` in `Curve::new`.
  10K-level mistakes become const-eval failures (in `static`
  context) or runtime panics (in dynamic).
- **`schema_version: u32` on `SkillsState`.** Free insurance
  for future migrations. Older save files (which lack the
  field) load as v1 via `#[serde(default)]`.

### `ueforge::rpg::ops` extraction

Five generic op handlers lifted out of bbp's
`grounded2-rpg/src/debug.rs` into the framework:

- `skill_toggle(tracker, disabled, args)` -- flips disabled
  flag + reapplies.
- `skill_spend(tracker, args)` -- spend N points; returns
  `{ id, requested, spent }`.
- `skill_refund(tracker, args)` -- refund N points; returns
  `{ id, requested, refunded }`.
- `reload_slot(tracker)` -- reapply every catalog skill.
- `set_skill_points(tracker, args)` -- debug-grant N points.

Plus `OP_NAMES: &[&str]` for dispatchers that want to
advertise the full op list. bbp's debug.rs lost ~80 LoC of
op boilerplate; any future RPG mod gets the five canonical
ops verbatim for free.

Test count: 56 ueforge unit tests passing (was 45 at the
start of this hardening session).

## 2026-05-10 (post-framework cleanup)

### Repo hygiene + tail-end framework lifts

Final 2026-05-10 cleanups after the major dedup wave. Mostly
file-tree shape + the last few extractions. Each commit is
small but worth a chronological line.

#### Dedup waves not previously listed

Three more waves landed on 2026-05-10 after the "ueforge as full
UE-mod framework" entry below was written:

- **`ueforge::pe_queue::DrainSite`** -- `Queue` paired with the
  standard performance-counter quad (drain calls, drained cmds,
  peak depth, time_ns spent). One static replaces the bbp
  pattern of a static `Queue` + four hand-declared `counter!`
  statics + a 20-LoC `drain_pending` wrapper. Surfaced via
  `drain_calls()` / `drained_cmds()` / `peak()` / `time_ns()`.
  Reference: [`../ueforge/docs/pe-queue.md`](../ueforge/docs/pe-queue.md).
  Commit `0a4aa32`.
- **`ueforge::ue::core_types`** -- POD `#[repr(C)]` mirrors of
  stable UE5 layouts: `FGuid` (16 bytes), `FWeakObjectPtr` (8
  bytes), `FDataTableRowHandle` (UDataTable* + FName u64),
  `EStatusEffectValueType` enum (None/Add/Multiply). Six unit
  tests including size invariants. bbp's local duplicates of
  `FGuid` (in save_slot.rs) and `FWeakObjectPtr` (in
  kill_hook.rs) deleted; both consume `ueforge::ue::*`.
  `FDataTableRowHandle` + `EStatusEffectValueType` ready for the
  pending status-effect migration. Commit `c2b6776`.
- **`ueforge::rpg::SlotKeyResolver`** -- generic save-slot key
  extractor. Configure once with `(class_name, guid_offset)`;
  static `resolve()` walks GObjects for first instance of the
  class, reads `FGuid` at offset, formats as filename. Plug
  into `SlotPoller::spawn` directly. bbp's `save_slot.rs`
  shrunk to a 5-line wrapper. 2 unit tests. Commit `0997f25`.

#### Repo hygiene

- **Per-crate docs/ folders.** Bbp-specific deep dives moved to
  `grounded2-rpg/docs/` (damage, inventory, rpg, performance,
  features, engine, testing, ongoing, port history). ueforge
  doctrine + 12 subsystem reference docs land in
  `ueforge/docs/`. Workspace `docs/` retains only cross-cutting
  files (`README.md`, `todo.md`, `changelog.md`). Skill at
  `~/.claude/skills/grounded2-rpg/SKILL.md` updated to match.
  Commits `b1dc6a7`, `e041e52`.
- **`better-backpack` -> `grounded2-rpg`** rename. Crate name,
  workspace dir, `MOD_INFO.name` (`Grounded2RPG`), log file
  (`grounded2_rpg.log`), mod folder, deploy zip prefix all
  changed. ~93 files touched. Commit `e041e52`.
- **`outworld-station/tweaks/` -> `outworld-station-tweaks/`**
  flattened to match `grounded2-rpg`. Crate renamed; mod
  folder is now `OutworldStationTweaks`; log
  `outworld_station_tweaks.log`. Commit `b0cedb6`.
- **`archive/` deleted.** ~3300 lines of dead C++ winhttp
  proxy code + the standalone DLL injector (~700 LoC, dead
  since UE4SS handles loading). `inspection-guide.md` rescued
  to `grounded2-rpg/docs/inspection.md` -- still useful as
  generic UE5 mod-inspection methodology + worked examples.
  Commits `a1e0be6`, `f222941`.
- **`scripts/*.py` deleted.** Two Python uasset inspection
  tools (`dump_strings.py`, `read_property.py`) ported to
  Rust as `ueforge::uasset` lib + `dump-strings` /
  `read-property` `[[bin]]` targets. Repo is now Rust-only
  except for the irreducible UE4SS / ImGui C++ shim. Commit
  `4866a40`.
- **ImGui as git submodule.** `ueforge/cpp/imgui/` (~55K LoC
  of vendored Dear ImGui v1.92.1) replaced with a git
  submodule pinned to upstream `ocornut/imgui` tag `v1.92.1`.
  First-party C++ in the repo drops to 502 LoC (the shim).
  `build.rs` panics with a clear fix message if the submodule
  isn't initialized. Commit `d7c91b0`.
- **`ueforge-deploy` merged into `ueforge`** as a `[[bin]]`
  target alongside `dump-strings` / `read-property`. Workspace
  member count: 5 -> 4. `cargo deploy` alias updated to
  `run -p ueforge --bin ueforge-deploy --release --quiet --`.
  Commit `a79da15`.

#### Native (C++) surface accounting

Post-cleanup totals:
- First-party C++ in the repo: **502 lines** (the shim:
  `ueforge_shim.cpp`, `ueforge_ui.cpp`, `ueforge_cppusermodbase.hpp`,
  `ueforge_imgui_bridge.hpp`).
- Vendored ImGui: not in repo (submodule).
- Doctrine: [`../ueforge/docs/native.md`](../ueforge/docs/native.md)
  -- "what C++ is in this repo, why each piece is irreducible,
  and what stays in Rust."

## 2026-05-10 (final)

### ueforge as full UE-mod framework

Continued extraction past the initial dedup wave. ueforge now ships
the complete set of systems every UE4SS Rust mod needs.

#### New ueforge surface (continued)

- **`ueforge::ue::ClassRef::for_each_matching` /
  `for_each_cdo_subclass` / `for_each_cdo_matching` /
  `for_each_any`** -- the full walker family. Predicate-filtered
  variants for "live pawns whose full_name contains substring";
  CDO variants for subclass-aware walks; `for_each_any` for
  singleton-style data assets where the CDO IS the real data.
- **`ueforge::ue::ClassRef::new_dynamic(name)`** -- runtime
  constructor for the rare cold-path case where the class name
  is computed (catalog-row apply, debug-op handler).
- **`ueforge::ue::TypedField::deref`** specialized for
  `TypedField<*mut UObject>` -- typed component-pointer follow.
  Closes the `obj.field_ptr(off).cast::<*mut UObject>().read_unaligned()`
  pattern.
- **`ueforge::ring::EventRing<T>`** -- `Ring<T>` paired with
  built-in push counter + peak high-watermark. `record(item)`
  bumps both atomics, then pushes. Eliminates the need to pair
  every event ring with two separately declared `counter!`
  statics.
- **`ueforge::ue::PlayerRef`** -- canonical "find the player"
  surface for any UE5 mod. `(base_class, Option<bp_filter>)`
  config; static methods for `for_each_cdo`, `for_each_live`,
  `with_first_live`, `with_first_cdo`.

#### Doctrine docs

- **`../ueforge/docs/PERFORMANCE.md`** -- hot-path discipline (zero
  allocs, bail early, no mutexes on empty path, bounded
  everything, install-time heavy lifting, counter every hot
  path); memory leak vectors with their named ueforge fixes;
  consume-don't-reinvent table; consumer responsibilities.
- **`../ueforge/docs/RESEARCH.md`** -- TDD investigation methodology
  for UE5 games: research-is-code rule, the seven-step TDD loop,
  five probe types in leverage order, doctrines on status
  effects / data tables / damage paths / instigator resolution
  / install-vs-hook, snapshot-not-log validation, failure-
  injection-test rule, research notebook shape.

After this session ueforge is **the** framework crate. g2rpg
contains only the G2-specific content: offsets, SkillEffect
variants, CATALOG content, GameApplier dispatch arms,
format_effect text, kill_hook / fall_hook / inv_hook trampolines,
parm structs, snapshot/op dispatcher. Everything else is ueforge.

## 2026-05-10 (later)

### Major dedup wave: g2rpg -> ueforge

Six commits in one session promoted the bulk of g2rpg's
infrastructure into ueforge. ueforge is now the framework crate
that gives every UE4SS Rust mod its load-bearing systems; g2rpg
owns only the G2-specific content (offsets, skill effect
variants, catalog rows, hooks, parm structs).

#### New ueforge surface

- **`ueforge::ue::ClassRef`** -- typed cached UClass handle.
  `const`-constructible static; lazy resolve on first `get()`;
  `cdo()`, `find_function()`, `with_first_instance()`,
  `for_each_instance()`, `find_instance()` helpers.
- **`ueforge::function_table!` decl-macro** -- struct-of-`usize`
  table of UFunction-pointer-identity slots with `install(&UClass)
  -> Result<Self, &'static str>` and `required` / `optional`
  field kinds.
- **`ueforge::ue::TypedField<T>`** -- `const`-constructible
  `(offset, T)` pair with `read(obj)`, `write(obj, v)`,
  `ptr(obj)`. Couples offset and type at declaration so accidental
  mismatches become `TypedField<f32>` vs `TypedField<u32>` type
  errors, not runtime corruption.
- **`ueforge::rpg::VanillaCache<K, V>`** -- per-key vanilla
  baseline cache. `get_or_init(k, v)` returns the captured
  baseline forever (first-write wins); `set_if_unset`, `get`,
  `clear`, `snapshot`. `parking_lot::Mutex` internally.
- **`ueforge::counter_json!` decl-macro** -- pairs of
  `(static_ident => "json_key")` collapsed into a
  `serde_json::Value::Object` with `load(Relaxed)` per counter.
- **`ueforge::hook::install_with_backoff(name, RetryPolicy, fn)`**
  -- generic exponential-backoff retry around any
  `FnMut() -> Result<H, &'static str>`. `RetryPolicy::default_install()`
  ships with g2rpg's battle-tested 500ms/5s/10min tuning.
- **`ueforge::worker::spawn(name, FnOnce)`** -- named worker
  thread (Win32 `SetThreadDescription` via `Builder::name`) with
  `catch_unwind` + logged panic payload. Closes the kovarex P1
  "unnamed worker thread" + "silent panic swallow" findings.
- **`ueforge::hook::LazyFunctionPtr`** -- lazily-cached
  `&UFunction` for hot-path identity dispatch. Warm path: 1
  atomic load + 1 branch. Cold path: 1 FName resolve, cache,
  never re-taken.
- **`ueforge::hook::ProcessEventHook::install_many`** --
  multi-class install with skip-on-not-loaded log lines.

#### RPG framework (Phase 3 wave 2)

The whole RPG / level-up system became framework code:

- **`ueforge::rpg::Skill<E>`** + **`find_skill`** -- generic
  catalog row parameterized on the game's effect enum.
- **`ueforge::rpg::RpgApplier`** trait -- the seam where
  ueforge's state/persistence layer meets the game's apply
  dispatch. Methods: `apply_skill(state, skill)`, `apply_all`,
  `format_effect(skill, level)`.
- **`ueforge::rpg::Tracker<A: RpgApplier>`** -- owns slot
  binding, in-memory state, Applier instance, persistence.
  Drives spend/refund/record_xp/reapply transactionally with
  disk save. Returns `XpResult` from `record_xp` so the caller
  can log "LEVEL UP!" feedback.
- **`ueforge::rpg::tab::render(tracker, ToggleFns)`** -- ImGui
  template: header (level + XP bar + skill points), catalog
  rows (+1/+10/-1/-10/optional on-toggle), debug footer
  (+5 / +50 skill points). Game crates supply only the
  `format_effect` closure (via Applier) and the toggle hooks.

#### g2rpg shrinkage

- `tracker.rs` reduced to a thin shim: a static
  `Tracker<GameApplier>` + ~10 wrapper fns that match the
  legacy API surface for kill_hook / world_loader / debug.rs.
- `tab.rs` reduced to a counter-bumping wrapper around
  `ueforge::rpg::tab::render`.
- `inv_hook.rs` lost ~80 LoC of UFunction-resolve boilerplate
  (now `function_table!`).
- `fall_hook.rs` lost ~30 LoC of multi-class install +
  manual UFunction cache (now `install_many` + `LazyFunctionPtr`).
- `lib.rs` lost ~50 LoC of `CreateThread` / retry-loop /
  `HOOK_RETRY_*` consts (now `worker::spawn` +
  `install_with_backoff`).
- `counters.rs::snapshot_json` collapsed to a single
  `counter_json!` invocation.
- `apply.rs` `VanillaTable` struct deleted (now
  `ueforge::rpg::VanillaCache`).

Net: ueforge gained ~2000 LoC of framework surface (+30 unit
tests, all passing); g2rpg lost ~500+ LoC of duplicated
infrastructure. Every crate builds clean release. In-game
smoke test pending.

## 2026-05-10

### Phase 3 (first wave) -- ueforge::rpg generic framework

The RPG-mod-shaped pieces every UE game needs land in ueforge:

- `ueforge::rpg::xp::Curve { base, exponent, max_level }` -- the
  classic `cumulative_xp_for_level` / `level_for_xp` math
  parameterized so any RPG mod plugs its own numbers.
- `ueforge::rpg::progress::sqrt_progress(level, max)` -- generous-
  early diminishing-returns curve.
- `ueforge::rpg::SkillsState` -- on-disk schema (xp / level /
  skill_points / `skill_levels: BTreeMap<String, u32>`) with
  `spend()` / `refund()` / `level_of()` methods.
- `ueforge::rpg::SlotStore<S>` -- per-slot JSON persistence under
  `<DLL_dir>/<subdir>/<slot>.json`. Generic over persisted struct.
  Atomic temp+rename save.
- `ueforge::rpg::DisabledSkills` -- thread-safe toggle set for
  "disable a skill without refunding its points".
- `ueforge::rpg::SlotPoller::spawn(interval, resolve, on_activate,
  on_deactivate)` -- 1Hz worker that drives activate / deactivate
  transitions on a consumer-supplied resolver closure.

5 unit tests on the curve + progress math (xp round-trip, max-level
cap, sqrt endpoints, quarter-is-half) -- the framework's first unit
tests, closes the kovarex P2 "no unit tests on framework
primitives" item.

g2rpg migrations: `src/rpg/state.rs` deleted entirely; `tracker.rs`
keeps a `static STORE: SlotStore<SkillsState>` and routes load /
save / spend / refund through ueforge; `world_loader.rs` shrinks
from 95 LoC of CreateThread plumbing to 30 LoC routed through
`SlotPoller::spawn`; `xp.rs` shrinks to a 3-line curve constant +
the per-creature XP table (game-specific bestiary); `apply.rs`
DISABLED_SKILLS swap; `skills::level_progress` becomes a 1-liner
forwarder. g2rpg's `PlayerState` is gone -- `kill_count` and
`last_killed` (diagnostic-only) dropped per "free to redesign"
scope.

Phase 3 second wave (catalog generic, apply dispatcher, RpgTab
widget) is next session.

### Phase 2 small promotions

Three Phase 2 items land before the big RPG promotion:

- **`ueforge::ue::class_tweak::ClassFieldTweak<T>`** -- live-UObject
  sibling of `FieldTweak<T>` (which is DataTable-row scoped). Two
  closure shape: `filter(&UObject) -> bool` (cheap, runs before
  the vanilla read) and `transform(T) -> Option<T>` (`None` =
  skip writing this instance). Captures vanilla keyed per-instance
  so re-applies don't compound.
- **g2rpg `patch.rs` + `survival.rs` migrated to `ClassFieldTweak<T>`.**
  Hand-rolled GObjects walks deleted; both files are now driven
  by `static SLOTS / HUNGER / THIRST: ClassFieldTweak<...> = ...;`
  and a single `.apply()` call. Net -150 LoC from g2rpg.
- **`ueforge::hook::function_ptr` / `function_ptr_required`** --
  small helper that returns `*const UFunction as usize`. Pattern
  is: stash in an `AtomicUsize` at hook install, dispatch by
  pointer identity in the trampoline.
- **`Queue::drain` canonical-site doc.** The `g2rpg::kill_hook` PE
  trampoline drain pattern (empty-check, re-entrance guard, peak
  counter, time scope) is now in the rustdoc so the next mod
  doesn't have to reverse-engineer it.

### g2rpg consumes ueforge for ALL infra (Phase 1 dedup)

grounded2-rpg lost ~930 lines of duplicated framework. Every piece
of generic UE4SS / SDK / hook / log / settings / counter / ImGui /
build plumbing now lives in ueforge and is consumed (not mirrored)
by the mod.

Deleted from g2rpg:
- `cpp/shim.cpp` (357 LoC) -- CppUserModBase mirror + ImGui render lambda
- `src/rpg/ffi.rs` (340 LoC) -- C-ABI bridges that the shim called
- `src/log.rs` -- duplicate of ueforge::log
- `src/sdk/` -- thin re-export shim of ueforge::ue
- `src/hook/` -- thin re-export shim of ueforge::hook
- `winhttp.def` -- legacy
- Custom `DllMain` + `grounded2_rpg_start` / `grounded2_rpg_stop` exports
- `DLL_HMODULE` static

Replaced with:
- `ueforge::ue4ss_mod!(MOD_INFO)` -- one macro emits every extern "C"
  hook the shim invokes (factory, DllMain forwarding, tab dispatch)
- `src/rpg/tab.rs` -- Rust ImGui render. Calls `tracker` / `skills`
  / `xp` directly; uses ImGui `##id` label suffix instead of
  PushID/PopID for unique button instances per skill row
- 1-line `build.rs`: `ueforge::build::CppShim::new().compile()`

Settings struct shape unchanged on disk (back-compat preserved); IO
routes through `ueforge::settings::Settings<T>`. The legacy parent-dir
fallback for `settings.json` was dropped per "free to redesign"
scope; if anyone has a pre-Rust install pattern, move the file next
to main.dll.

Cumulative shape after Phase 1: g2rpg consumes ueforge for SDK, hook
framework, log, settings IO, ImGui bindings, counter primitives,
ring buffer, HTTP server, op envelope, generic ops, tab
registration, DllMain, factory exports, C++ shim. Zero duplication.

What stays in g2rpg (correct game-side): `inv_hook`, `kill_hook`,
`fall_hook`, `survival`, `patch`, `parms`, `debug`, the `counters`
domain statics, and the entire `rpg/` subsystem (catalog content,
apply dispatcher, persistence layer). `rpg/` is the Phase 2 promotion
candidate -- shape is generic for any UE game with the right
`slot_key()` resolver, so it lands in `ueforge::rpg` next.

### ueforge hardening (kovarex review landed)

Three P0 + six P1 items shipped. Crash vectors closed, FString /
GObjects walks bounded, dev profile unwinds.

**P0:**
- `parking_lot::Mutex` everywhere -- no more poison-then-abort hard
  crashes. `[profile.dev] panic = "unwind"` so research crashes
  leave a backtrace; release stays on abort for size + perf.
- Hot paths use `try_runtime` + soft fallback (empty name, dropped
  PE call + log) instead of `expect()` aborting if a hook fires
  before init_runtime sets the OnceLock.
- Address-validated freezes. `freeze { selector, offset }` resolves
  through `selector::resolve_generic` and re-resolves on staleness;
  `VirtualQuery` validates page protection on every write; 30
  consecutive failed validations stop the writer. Legacy
  `freeze { addr }` still works but has no recovery path.

**P1:**
- `NameResolver` caches FName u64 -> String. Caps the FString leak
  at one buffer per unique FName (was: per call). Bounded by the
  game's name pool (~50K) instead of unbounded.
- `find_class_fast` caches by name. Selector resolution drops from
  O(GObjects walk) -- ~150K objects on OWS -- to O(1) on the warm
  path.
- `UClass::cached_native_properties` returns `Arc<[NativeProperty]>`;
  `inspect_address` allocates zero per click after the first lookup.
- `ops::{read_bytes,write_bytes}` clamp `offset+length` to
  `class.properties_size()` when the class is known. Selectors that
  point at a UObject can no longer read/write past the instance.
- `arc_swap::ArcSwap` replaces hand-rolled `AtomicPtr<&'static [...]>`
  + `Box::leak` snapshot in PE hooks. No leak per install/drop.
- `tmap::MAX_LINEAR_SCAN` 8192 -> 65536 with one-line truncation log.
- `Api::try_op` + `perf::try_open` Result-returning variants
  alongside the panicking convenience wrappers.
- `scan_memory` builds JSON sample before taking sessions lock so
  multi-second scans don't block other ops.

### Three-way feature audit added

`../ueforge/README.md` ships a 62-row matrix mapping every feature
across ueforge, grounded2-rpg, and ows-tweaks. Each cell is
`live here / consumes ueforge / duplicates (delete) / should be
promoted / N/A`. Verdict column names the migration item.
Phase 1 status now marks 30+ rows done.

### Property walker on inspect_address

`ueforge::inspect_address` now resolves field names via the
UClass `ChildProperties` chain. Click an address in the Scanner
tab -> "DataTable::RowMap on DT_Materials" instead of
"DT_Materials @ +0x30 (size 0x60)". Walks the super-class chain.
Adds `ffield`, `fproperty`, and `ustruct::CHILD_PROPERTIES`
constants to `ue::offsets` (UE 5.4 verified; 5.5/5.6 may shift
`OFFSET_INTERNAL` -- track via the offsets-versioning P2 item).

## 2026-05-09 (evening)

### impact_resistance bug fix landed: ApplyDamageFromInfo intercept

Replaced the binary `RequiredDamageTypeFlags = 0xFFFFFFFF` mask
write with a Runtime effect that intercepts
`UHealthComponent::ApplyDamageFromInfo` on the player HC,
identifies environmental damage by
`FDamageInfo.DamageType` class name containing "Environmental",
and scales the `Damage` parm by `(1 - reduction * progress)`
before forwarding.

Why the change: the binary mask blocked bandages (and all
healing) by gating `type_flags=0` events at the native
ApplyDamage level. Bandage HoT applies a `Type=Health (24)`
status effect whose tick goes through that gate and was being
rejected. Research-as-code (`tests/explore_bandage_path.rs`,
`tests/explore_bandage_status_effects.rs`) characterized the
mechanism end-to-end before the fix landed.

The new mechanism uses the same shape as fall_resistance's
velocity-stomp on OnLanded: intercept-and-scale at the PE
surface, gated by a discriminator (DamageType class for
impact_resistance, "is fall" for fall_resistance).

Side-effects:
- Bandages now heal regardless of impact_resistance level
- Creature combat damage is untouched (different DamageType)
- Fall damage is untouched (different surface, handled by
  fall_resistance)
- Per-level sqrt scaling instead of binary all-or-nothing

## 2026-05-09

### Discovered: impact_resistance blocks bandages

Enabling `impact_resistance` at any level prevents bandages and
other healing items from working. Confirmed in-game by binary
isolation (only impact_resistance enabled -> repro; toggled off ->
heals fine). Mechanism: bandages route healing through
`ApplyDamage` with negative damage and `type_flags = 0`. The
`RequiredDamageTypeFlags = 0xFFFFFFFF` mask we set rejects any
event with type_flags=0, so heal events fail the gate before the
HP decrement. Detail in [`damage.md`](damage.md) "Critical
regression: bandages / healing items blocked".

Workaround until the canonical fix lands: keep impact_resistance
toggled off when healing is needed. The status-effect migration
in [`todo.md`](todo.md) replaces the binary mask with a
type-filtered DamageReductionMultiplier that won't touch healing.

### `PlayerHealthCompU32Mask` learned to disable cleanly

Previously the variant only wrote the mask at level > 0 and never
restored vanilla, so refunding the skill or toggling it off left
the mask set (mid-session and beyond). Apply step now captures the
vanilla mask on first sight, runs at level 0 / disabled too, and
writes the captured vanilla back when the skill is inactive. This
is what makes the toggle actually unblock bandages.

### Avoided ProcessEvent deadlock by deleting dead UFunction call

Toggling fall_resistance off used to freeze the game. Root cause:
`apply_skill` for fall_resistance was invoking
`USurvivalModeManagerComponent::UpdateCustomSettings` via
ProcessEvent. That UFunction triggers replication on the Net-flagged
`CustomSettings` field; calling it mid-session from any non-game
thread (ImGui callback, world_loader poller) hangs on the
replication marker.

Reading the SDK + the original commit (`6ad1df2`), the call was
dead code -- the changelog explicitly notes "Player still takes
fall damage" even with the UFunction firing, and the actual
mitigation that works is the velocity-stomp on `Velocity.Z` in
`fall_hook.rs` plus the `RequiredDamageTypeFlags` mask. Native
fall-damage code never reads the FallDamageMultiplier fields the
UFunction was meant to invalidate. Deleted the call and its helper
entirely; the GMS / SMMC field writes remain (harmless).

## 2026-05-08

### Catalog +3 skills (untested in-game)

Three new skills shipped, all using two new `SkillEffect` shapes.
Pending in-game witness.

- **Max Health** -- `PlayerHealthCompAdditive` (new variant). Captures
  the vanilla baseline at `UHealthComponent.MaxHealth` (+0x328) on
  first apply, then writes `vanilla + max_bonus * progress` on
  player CDOs and the live pawn. Additive so HP stacks rather than
  scaling, +200 HP at level 100.
- **Health Regen** -- `GlobalDataMult` (new variant). Walks every
  `UGlobalCombatData` instance and writes per-offset multipliers:
  CombatRegenTickPercentage (0x010C, exponent +1.0) scales up,
  CombatRegenTickRate (0x0110, exponent -1.0) scales down (more
  frequent ticks). Combat-regen delay (0x0108) intentionally
  untouched to preserve the post-combat feel. +500% / 6x at level
  100.
- **Leap Distance** -- existing `PlayerMovementMult` over three
  CharMovementComponent fields: AirControl (0x02C0),
  AirControlBoostMultiplier (0x02C4), AirControlBoostVelocityThreshold
  (0x02C8). Lets the player keep accelerating in their input
  direction through the arc -- a real "leap" feel rather than a
  taller jump. +500% at level 100.

### ImGui tab: refund + per-skill toggle

- `-1` / `-10` refund buttons next to the `+1` / `+10` spend
  buttons. Decrement the level, credit the points back, run the
  apply step, save. Disabled at level 0. Caveat: refund-to-0 on
  `PlayerHealthCompU32Mask` (Impact Damage Resistance) needs a
  reload to take effect because the apply step early-returns at
  level 0 and there is no vanilla mask captured.
- `on` checkbox per row. Disabling treats the skill as level 0
  without refunding the points -- drops a buff (e.g. Leap Distance)
  on demand without losing progress. Process-global, not persisted
  (cheap to reapply on launch). Toggling fires `apply_one`.

New FFI: `bbp_rpg_refund`, `bbp_rpg_refund_many`,
`bbp_rpg_is_skill_enabled`, `bbp_rpg_set_skill_enabled`.

## 2026-05-05 (single big day)

### Impact Damage Resistance (binary)

Landed via `apply.rs` writing
`UHealthComponent.RequiredDamageTypeFlags = 0xFFFFFFFF` (+0x00FC,
uint32) on player CDOs and the live pawn at any
`impact_resistance` level > 0. Native ApplyDamage gate consults
the field; incoming damage with `type_flags = 0` (fall,
environmental, hazard zones) fails the bitwise check and is
rejected before `CurrentDamage` is written. Creature attacks
carry non-zero flags and pass through. Validated in-game: rock
collision multicasts report `damage=0.00`, impact-trace POST line
silent (no `CurrentDamage` change). Same field-write pattern as
Armor's `BaseDamageReduction` write, just on a different gate.

The gate is **binary** (level 1 = full immunity, identical to
level 100). Status-effect-backed migration tracked below.

### Vanilla status-effect data table identified

`fall_hook.rs` extended with a probe that walks the player's
`UStatusEffectComponent.StatusEffects` array and logs each effect's
row handle. Result: every active status effect in the game flows
through one data table:

```
DataTable: /Game/Blueprints/Attacks/Table_StatusEffects.Table_StatusEffects
```

Sample active rows (mid-game player): `PlayerUpgradeHealth1`,
`WeaponClub`, `RogueFinisherCriticals`, `AntRedStaminaAttack`,
`FighterFinisherStun`, `MaxHealthSmall`, `PerkSpearTier1`,
`PerkSpearThrowAttackUpTier1`. Naming convention is
`<Source><Effect><Tier>`. Detail in `../grounded2-rpg/docs/damage.md` "Vanilla data
table identified".

This finalizes the migration plan: resolve the table (follow any
existing row handle), enumerate rows, mutate or inject one per
skill, AddEffect via `process_event`. Implementation step is
concrete now.

### Status Effect combine semantics decoded

Extended the sfx-probe to also call
`UUserInterfaceStatics::GetStatusEffectValueType(StatType)` for each
probed stat. `EStatusEffectValueType` enum is two-state plus None:
`Add=1`, `Multiply=2`. Per-stat semantics observed in-game:

- `FallDamage`, `DamageReduction`, `AttackDamage` -> `mul` (vanilla
  baseline 1.0; effects multiply).
- `LifeSteal`, `CriticalHitChance`, `CriticalDamage`, `ReflectDamage`,
  `MaxHealth`, `DamageReductionMultiplier` -> `add` (vanilla baseline
  0.0; effects sum).

Per-skill write formulas now fully determined; full table in
`damage.md` "Stat semantics table". This finishes the validation
phase of the A1 migration; next is picking an implementation path
(mutate existing row vs inject new row) and building the apply
step.

### Status Effect system validated (probe shipped, in-game readout)

`fall_hook.rs` now ships a probe (gated on `impact_resistance > 0`)
that calls `UStatusEffectComponent::GetValueForStat(StatType,
false)` on the player's component for damage-relevant stat types.
First in-game readout on a mid-game player:

```
FallDamage(14)=1.000  DamageReduction(29)=1.000  AttackDamage(23)=1.210
CriticalHitChance(31)=0.060  MaxHealth(5)=30.000  LifeSteal(38)=0.000
```

Confirmed:
1. The status-effect system is live and queryable.
2. Vanilla equipped gear / perks already populate it (the `+21%`
   attack and `+30` max health values come from existing items).
3. Stat semantics differ (multiplier vs additive vs probability),
   queryable via `USurvivalGameplayStatics::GetStatusEffectValueType`.

This validates the migration target. Next step is to probe the
combine semantic per stat, then implement the apply step using
one of the four implementation paths in `damage.md`.

### Status Effect system identified (canonical extension surface)

SDK review of `UStatusEffectComponent` on `ASurvivalCharacter` at
+0x1378: this is the proper Grounded 2 surface for proportional,
per-stat / per-damage-type modifiers. Native damage code calls
`GetValueForStatForDamageTypeFlags(StatType, Flags)` on every
damage event and uses the float result as a multiplier.
`EStatusEffectType` enum has matching values for nearly every
skill we plan: `FallDamage=14`, `DamageReductionMultiplier=30`,
`LifeSteal=38`, `ReflectDamage=37`, `AttackDamage=23`,
`CriticalHitChance=31`, `CriticalDamage=62`, `MaxHealth=5`, etc.

Current implementations (Armor's `BaseDamageReduction`, Impact's
`RequiredDamageTypeFlags`, Fall's velocity-stomp, Lifesteal's
`Runtime` no-op) are interim. Migration to status-effect-backed
skills gives sqrt-curve scaling, native type filtering, and
stacking with vanilla items / perks. Plan in [`todo.md`](todo.md);
full pipeline reference in [`damage.md`](damage.md).

### Fall Damage Resistance

Landed via velocity-stomp in `fall_hook.rs`'s `OnLanded` PE hook on
the player BP class. See [`damage.md`](damage.md) for the full
pipeline reference.

### Movement skill fix verified

Move Speed was initially wired only through generic UE movement caps and
player CDO writes, which was not enough for Grounded 2. The fix now
also patches Grounded-specific `UMaineCharMovementComponent` fields:

- `CustomGroundSpeedMultiplier` (+0x1198)
- `CustomFlySpeedMultiplier` (+0x119C)
- `CustomSwimSpeedMultiplier` (+0x11A0)
- `MaxSwimSprintSpeed` (+0x1164)

Movement writes are also mirrored onto live player pawns, not just
CDOs, so the effect can be validated immediately in-session. User
retest confirmed the run-speed skill now works.

### Skill registry refactor

`skills.rs` is now the single source of truth. Each skill is one
row in `CATALOG` carrying id, display_name, max_level, and a
`SkillEffect` variant. `apply.rs` is one function `apply_skill`
that pattern-matches on the effect. Adding a new skill of an
existing shape is one CATALOG row, no other code changes. Adding
a new shape is one variant + match arms in apply and format.
Catalog at 9 skills, ready to grow to 25+.

### Vocabulary and curve

Hard rename `rank -> level` everywhere. Schema field
`skill_ranks -> skill_levels`. Every skill now caps at level 100
with a `sqrt(level/100)` diminishing-returns curve.

### Combat + movement skills

- Attack Damage (max +300%): `ASurvivalCharacter.CustomDamageMultiplier` at +0x12B8.
- Armor (max -50% damage taken): `UHealthComponent.BaseDamageReduction` at +0xEC, via the player CDO's HealthComponent pointer.
- Move Speed (max +300% walk + sprint + swim): `MaxWalkSpeed` (+0x288), `MaxSprintSpeed` (+0x10EC), `MaxSwimSpeed` (+0x290), `MaxSwimSprintSpeed` (+0x1164), `CustomGroundSpeedMultiplier` (+0x1198), `CustomSwimSpeedMultiplier` (+0x11A0).
- Jump Height (max +300%): `JumpZVelocity` at +0x1B8.
- Glide Speed (max +300%): `MaxFlySpeed` (+0x294) plus `CustomFlySpeedMultiplier` (+0x119C).
- Lifesteal (max +90% of damage dealt): catalog entry only;
  runtime kill_hook integration was queued and pivoted to the
  registry refactor.

All movement skills capture vanilla baselines via `OnceLock`s on
first apply so re-apply doesn't compound.

### apply optimization

`apply_one(state, settings, skill_id)` runs just one skill. A
`+1` click in the tab now writes one CDO + produces one log
line, not five.

### ImGui tab

UE4SS `register_tab` for the "RPG" tab. Shows level, XP bar,
skills with rank/effect/+1 buttons. Vendored upstream
ocornut/imgui v1.92.1 (matches UE4SS) as
`grounded2-rpg/cpp/imgui/`. Forward-declared
`UE4SSProgram::get_current_imgui_context` and
`get_current_imgui_allocator_functions` with `RC_UE4SS_API`
(dllimport via UE4SS.lib). Symbol mangling gotcha: `register_tab`
is `protected` on the real CppUserModBase. MSVC mangling encodes
access (Q=public, I=protected). First attempt with public failed
LNK2019; moved to a protected section of the mirror.

C-ABI in `rpg/ffi.rs` (8 functions wrapped in `catch_unwind` so
panics can't take down UE4SS's render thread). Lambda reads
state via getters and posts spends via `bbp_rpg_spend`.

UI also shows current effect + next-level preview per skill, e.g.
`Backpack level 5 / 100  +30 slots  (next: +33 slots)`. Debug
footer with `+5` / `+50` skill-point grant buttons for testing.

### Eager state load on world entry

`rpg/world_loader.rs`: 1Hz poller that watches
`save_slot::current_slot_key()` and drives tracker transitions
(`None -> Some(s)` activate, `Some(a) -> Some(b)` save-swap,
`Some -> None` deactivate). Replaces the lazy "load on first
kill" shortcut from Spike B.

### Skill catalog + apply step + settings layering

settings.json defines the BASE values for each stat. RPG skills
layer on top:

- backpack: target = `settings.slot_count + skill_bonus`.
- survival drain: target = `vanilla * settings_mult * skill_mult`.

Defaults flipped to vanilla (`slot_count=40`,
`hunger/thirst_mult=1.0`); user overrides settings.json for a
starter buff. Skill levels then layer.

apply.rs captures vanilla survival rates at init (before the
init-time survival::run modifies them) so re-apply uses a fixed
baseline.

### Buggy kill attribution

Three buckets in `kill_hook.rs::classify`:

- Player: instigator class chain contains "PlayerController".
- Buggy: instigator (or its possessed Pawn at +0x308) class
  chain contains "Buggy".
- Other: enemy AIC; logged + dropped, no kill_count bump.

Confirmed in-game: PLAYER on Grub kills, BUGGY on Spiderling
killed by `AIC_AntSoldier_Augusta_Buggy_C`. Single-player /
host case works; co-op ownership disambiguation deferred.

### XP / level math

`rpg/xp.rs`: cumulative XP curve `100 * N^1.8`, level cap 50,
per-creature XP lookup table (~20 species placeholders).
PlayerState schema bumped to `(xp, level, skill_points,
skill_levels)`.

### Spike A: kill detection

Hook on `Maine.HealthComponent` ProcessEvent slot. Match on
`MulticastHandleEffectsWithDamageFlags`. Read DamageFlags at
+0x1C in the parms struct, mask with `EDamageInfoFlags::KillingBlow = 2`.
On match, read `LastDamageInfo.InstigatorController` from
HealthComponent +0x3B0 (inside FDamageInfo at +0x20). Filter to
ASurvivalCreature subclasses to exclude buildings / props.

#### Attempt 1 (failed)

First attempt hooked the `Kill` UFunction directly. Did not fire:
`Kill` is `Final|Native`, the engine bypasses ProcessEvent on
the internal damage path. Diagnostic logging of all PE calls on
HealthComponent showed only `OnStatusEffectChanged`,
`MulticastHandleEffectsWithDamageFlags`, `OnCombatChanged` during
a Weevil kill.

#### Investigation

`OnDeath` multicast delegate's BP-bound handlers fire via PE on
each enemy's vtable, not HealthComponent's, so a per-vtable hook
on HealthComponent can't see them. Two paths considered: (A)
read `DamageFlags` from `MulticastHandleEffectsWithDamageFlags`
which DOES fire via PE on HealthComponent and includes a
KillingBlow bit, or (B) global ProcessEvent hook via UE4SS's
`RegisterProcessEventPreCallback`. SDK grep found
`EDamageInfoFlags::KillingBlow = 2`, which validated path A.
Implemented in ~10 lines, no architectural change.

Path B retained on the future-infra TODO; it's the right call
for any future PE-only signal we'll need (level-up confirms,
item crafted, dialog events, etc.).

### Spike B: persistence

PlayerState in `<DLL_dir>/saves/<playthrough-guid>.json`. First
attempt used `USaveLoadManager.SaveInProgressSaveGameHeaderData`
(at +0x90), but that's null except during an active save
operation. Switched to `AInGameGameState.PlaythroughGuid` at
+0x32C; populated for the duration of the active session.

### RPG pivot

Direction shift from "configurable tweaks toolkit" (settings.json
flat sliders) to "Factorio-style RPG / level-up mod" (skills earn
points, points buy ranks, ranks change game state). Inspired by
the Factorio
[RPG System](https://mods.factorio.com/mod/RPGsystem) plus
[War3CS / War3FT](https://war3cs2.wiki.gg/) for Counter-Strike.

The "everything is a slider" model became the *output* of the
level system, not the user-facing knob. Settings becomes base
values; skills layer on top.

### UE4SS C++ mod load works

Loader-side bug fixed: our `CppUserModBase` mirror was missing
six virtuals vs the upstream header (`on_ui_init`, four post-1.0
`on_lua_*` overloads, `on_cpp_mods_loaded`). UE4SS dispatched
through later vtable slots into garbage and crashed the game
during init. Mirror now matches the header virtual list verbatim.
`on_cpp_mods_loaded` is NOT marked `RC_UE4SS_API` because
UE4SS.lib doesn't export it; using local inline body works.

## Earlier

The Rust port of the original C++ Grounded 2 - RPG System mod is
documented in [`rust-port.md`](rust-port.md). The pivot to a
UE4SS C++ mod (CPPMod) shape is documented in
[`ue4ss-port.md`](ue4ss-port.md).

The original C++ implementation is preserved at
[`../archive/winhttp-proxy/`](../archive/winhttp-proxy/) for
reference.
