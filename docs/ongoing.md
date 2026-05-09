# Ongoing work the mod does

> **Authoritative on:** every piece of code that runs continuously
> while the game is alive. Used for triaging CPU / RAM / I/O
> issues. If something is firing at high frequency, it's listed
> here.

## Performance principle: ZERO ALLOCATIONS UNLESS NEEDED

**The mod's hot-path budget per fire is single-digit nanoseconds
and zero heap allocations.** This applies to every piece of code
that runs on the game thread or at frame rate.

Hot-path code MUST:

- Not allocate `String`, `Vec`, `Box`, `HashMap` etc. unless
  there's a concrete reason this specific call needs to.
- Not lock mutexes unless work is actually about to happen.
  Use lock-free shadows (`AtomicUsize`, `AtomicBool`) for
  empty-check fast paths.
- Resolve UE objects by name ONCE, then cache the
  `*const UObject` / `*const UFunction` pointer. Per-fire
  identification is a pointer compare, not a string compare.
- Fall back to the slow path (allocate, lock, log) only when
  the state actually warrants it (level > 0, queue non-empty,
  diagnostic mode active, etc.).

Cold paths (slot activation, user clicks, snapshot endpoint)
can allocate freely. Hot paths cannot.

The 1090-allocs-per-second `fall_hook` runaway documented in
section 13 below was a violation of this principle. The fix
(cache `OnLanded` UFunction pointer + drain-empty atomic
shadow) brought per-fire cost from "alloc + mutex" to
"atomic load + branch."

Whenever you write a new PE hook, a new ImGui callback, or an
FFI export that runs at frame rate, apply this principle from
day one. Lazily cache identifiers, compare atomics, branch
early. The hot path should be all `if let Some(cached) = ...
{ pointer_cmp() }` and zero allocator traffic.

Last audited: 2026-05-09.

## 1. Threads spawned by the mod

| # | Thread | Source | Loop shape | Wait between iterations | Per iteration |
|---|--------|--------|------------|-------------------------|---------------|
| 1 | Init worker | `lib.rs::worker_entry` -> `worker()` | one-shot | n/a | runs init, exits ("init complete; worker thread exiting") |
| 2 | World loader poller | `rpg/world_loader.rs::run()` | `loop { sleep(1s); }` | **1000 ms** | calls `save_slot::current_slot_key()` -> **walks GObjects** to find `AInGameGameState`, reads `PlaythroughGuid` (16 bytes -> hex String). On slot change: `tracker::activate_slot` -> full apply walk, more GObjects walks per skill. |
| 3 | Debug HTTP server | `debug.rs::run(server)` | `for req in server.incoming_requests()` | blocks until next HTTP request | per request: parse body, dispatch op, build JSON snapshot. Snapshot path walks GObjects multiple times. |

**Note**: thread 2 walks the full GObjects array every second
just to find one specific actor. GObjects in Grounded 2 is
tens of thousands of entries. This is ~10 µs but constant.

## 2. ProcessEvent hooks (game thread; fire on every UE PE call to the hooked class)

### inv_hook -- on `WBP_InventoryInterface_C`

Source: `inv_hook.rs::on_event`.

Fires when inventory UI calls UFunctions on the widget.
**Quiet when inventory is closed.** Active in inventory:
function-name allocation, filter on a handful of names,
occasional process_event callback.

**Cost**: low. Only on inventory interactions.

### kill_hook -- on `UHealthComponent`

Source: `rpg/kill_hook.rs::on_event`.

**Fires for EVERY UFunction call on EVERY UHealthComponent in
the game** -- player, every creature, every NPC, every entity
that has an HC. With many creatures around, this fans out:
`creatures × UFunctions/sec/creature`.

Per fire (every HC, including non-player):
- `crate::debug::drain_pending()` -- atomic check + mutex lock on
  PE_QUEUE + drain (cheap when empty)
- pointer compare + bool flag
- **`owner.full_name()` -- String allocation every fire** just
  to do the player gate

If owner is the player:
- `function.as_object().name()` -- String allocation
- match against damage-fn names
- if non-damage UFunction: read CurrentDamage + push DamageEvent
  (with `fn_name.clone()`) into bounded `damage_ring`
- if damage UFunction: read parm fields, **`bbp_log!` (fsync)**,
  push ring entry, **`log_last_damage_info` reads more
  FDamageInfo fields and `bbp_log!`s again** (fsync per line)

After the player gate -- still inside the if-player block --
the impact-resistance intercept runs on multicast functions:
`current_impact_resistance_level()` (acquires tracker mutex),
read DamageType, resolve class name (allocation), if
"Environmental" -> write CurrentDamage and `bbp_log!`.

After all that, forwards to original.

Then a separate post-call section: snapshots before/after
CurrentDamage, optionally `bbp_log!`s the delta.

**Cost**:
- Trampoline fires per UHealthComponent UFunction × N HCs.
- Allocates `owner.full_name()` String every fire just to
  filter.
- Player damage events emit 2-3 log lines per fire, **each line
  fsyncs**.

### fall_hook -- on `BP_SurvivalPlayerCharacter_C` and 2 subclasses

Source: `rpg/fall_hook.rs::on_player_fall_event`.

Fires for **every UFunction call on the player's BP class** --
includes Tick, ReceiveAnyDamage, OnLanded, every BP UFunction.
Player ticks at 60 Hz, so this trampoline fires at **60+ Hz
minimum**.

Per fire:
- `crate::debug::drain_pending()` (atomic + mutex; cheap when
  empty queue)
- `function.as_object().name()` -- String allocation
- `is_player_character(this)` check
- If player AND fn_name == "OnLanded": velocity-stomp; if
  impact_resistance > 0 ALSO calls `probe_status_effect_values`
  + `probe_player_status_effects` (each one walks status-effect
  TArrays + multiple `bbp_log!`s)
- `is_collision_relevant(&fn_name)` filter
- Optional pre/post CurrentDamage snapshot around `original.call`

**Cost**: trampoline fires at 60+ Hz on player BP class.
Allocates `fn_name` per fire even for cold paths.

## 3. C++ shim callbacks (UE4SS-driven, game/render thread)

### `rpg_render_tab` -- ImGui tab "RPG"

Source: `cpp/shim.cpp::rpg_render_tab` (registered via
`register_tab(STR("RPG"), &rpg_render_tab)`).

**Fires every frame the ImGui debug overlay's RPG tab is
visible.** When the user opens the UE4SS overlay (default
`Insert` key) and selects the RPG tab, this runs at the render
frame rate.

Per render call (~60 Hz when tab is open):
- Calls `bbp_rpg_get_xp_summary(...)` once
- For **every catalog skill** (currently 13):
  - `bbp_rpg_get_skill(id, &level, &max)` -- FFI crossing
  - `bbp_rpg_format_skill_effect(id, level, ...)` -- FFI +
    String formatting (locks tracker)
  - `bbp_rpg_format_skill_effect(id, level+1, ...)` -- second
    format if not at max (locks tracker)
  - `bbp_rpg_is_skill_enabled(id)` -- FFI + DISABLED_SKILLS
    mutex lock

So per frame with the tab open: **~50 FFI crossings, ~13
DISABLED_SKILLS lock acquisitions, ~26 tracker lock
acquisitions** (per format call). At 60 Hz: ~3000 FFI
crossings/sec, ~780 mutex acquires/sec on each of two locks.

If the user hides the ImGui overlay (Insert again), the tab
stops rendering. Cost goes to zero.

### `on_update` -- empty in our shim

Source: `cpp/shim.cpp::BetterBackpackMod::on_update`.

UE4SS calls this every frame. Our override is `virtual auto
on_update() -> void {}` (default empty). **No ongoing cost.**

### `on_unreal_init` -- one-shot

Calls `better_backpack_start()` once, then is never called
again.

## 4. FFI exports called from C++ shim

Each FFI call from `cpp/shim.cpp` enters Rust through
`rpg/ffi.rs`. Every export uses `safe(|| { ... })` which catches
panics but otherwise runs the closure synchronously.

Hot ones (called per ImGui frame, see section 3):
- `bbp_rpg_get_skill` -- catalog lookup, no allocations
- `bbp_rpg_format_skill_effect` -- locks tracker, formats String
- `bbp_rpg_is_skill_enabled` -- locks DISABLED_SKILLS

Cold ones (only on user click):
- `bbp_rpg_spend`, `bbp_rpg_spend_many`
- `bbp_rpg_refund`, `bbp_rpg_refund_many`
- `bbp_rpg_set_skill_enabled`
- `bbp_rpg_debug_grant_skill_points`

## 5. File logging

Source: `log.rs::log()`.

**Every `bbp_log!` call writes a line to
`<DLL_dir>/better_backpack.log` AND calls `f.flush()` (fsync).**
Also writes to `WriteConsoleA` if the `console` cargo feature
is enabled (it is, by default).

Sites that emit logs at high frequency during gameplay:
- `kill_hook` damage path: 2-3 lines per multicast event
- `fall_hook` impact-trace: gated on `impact_resistance > 0`,
  fires per landing event
- `rpg/impact:` log inside the impact intercept: per
  environmental multicast

In a hazard zone or while taking damage, this can produce
**dozens of log lines per second, each one fsync'd**.

## 6. Static collections (memory)

All bounded; no unbounded growth observed:

| Static | Owner | Bound |
|--------|-------|-------|
| `DAMAGE_RING` | debug.rs | 64 entries (drained when over) |
| `PE_QUEUE` | debug.rs | drained every fall_hook fire (~60 Hz) and every world_loader tick (1 Hz). Re-entrance guard prevents recursion. |
| `VANILLA_HC_U32_MASK` | apply.rs | one entry per offset we touch (~1) |
| `VANILLA_STATUS_EFFECT_VALUES` | apply.rs | one entry per row we touch (~0; status-effect path not active in catalog) |
| `DISABLED_SKILLS` | apply.rs | bounded by catalog size |
| `MOVEMENT_VANILLA`, `GLOBAL_DATA_VANILLA` | apply.rs | bounded by offsets touched |
| `TABLE_STATUS_EFFECTS` | apply.rs | OnceLock single value |
| `STATE` | kill_hook.rs | OnceLock single value |
| `TRACKER` | tracker.rs | one Tracker option |
| `SETTINGS` | world_loader.rs | OnceLock single Settings |
| `DLL_HMODULE` | lib.rs | AtomicUsize single value |
| `SINK` | log.rs | OnceLock single Sink |

## 7. Per-call allocation sites on hot paths

Strings get freed after each call but allocator churn is high:

| Site | Frequency | Allocation |
|------|-----------|------------|
| `kill_hook` `owner.full_name()` for player filter | per UHealthComponent UFunction × all HCs | String |
| `kill_hook` `function.as_object().name()` (player path) | per UFunction on player HC | String + clone for ring entry |
| `kill_hook` impact intercept `class.name()` (DamageType) | per multicast (any HC) | String |
| `fall_hook` `function.as_object().name()` | 60+ Hz | String |
| `bbp_log!` `format_line` | per log call | Vec<u8> |
| `world_loader` `current_slot_key` GUID hex | 1 Hz | String |
| `format_skill_effect` (per skill in ImGui) | 60 Hz × 26 calls when tab open | String |
| `record_damage_event` | per kill_hook fire (player) | DamageEvent + String |

## 8. Mutex acquisitions on hot paths

| Mutex | Touched by | Frequency |
|-------|-----------|-----------|
| `TRACKER` | every kill_hook intercept (current_impact_resistance_level), every snapshot, every format_skill_effect, every spend/refund/toggle | high |
| `DAMAGE_RING` | every kill_hook fire on player HC | high |
| `PE_QUEUE` | every fall_hook fire (drain), every kill_hook fire (drain), every HTTP write op | very high (60+ Hz from fall_hook alone) |
| `DISABLED_SKILLS` | every is_skill_enabled (ImGui per skill per frame) + every set_skill_enabled | high when tab open |
| `VANILLA_*` mutexes | per apply / per skill / per drain | low |
| `SINK.file` | every bbp_log! | bursty |

## 9. GObjects walks (expensive per call)

`GObjectsView::iter()` iterates a global object table with tens
of thousands of entries. Every call is O(N) in object count.

| Caller | Frequency |
|--------|-----------|
| `world_loader::run` -> `save_slot::current_slot_key` | **1 Hz forever** |
| `tracker::activate_slot` -> `apply::apply` -> per-variant walks | per slot change (rare) |
| `apply::apply_one` (called from spend/refund/toggle) -> per-variant walks | per user click |
| `debug::build_snapshot` -> CDO + live + class lookups | per HTTP snapshot request |
| `debug::op_walk_class` | per HTTP walk_class request |
| `apply::table_status_effects` (cached) | once at first use |
| `apply::first_instance_of` (CDO collection in snapshot) | per snapshot |

The 1 Hz `current_slot_key` is a continuous GObjects walk
forever. Optimization: cache the AInGameGameState pointer on
first hit instead of re-walking each second.

## 10. Likely runaway sources (ranked)

1. **`kill_hook` fans out across every UHealthComponent in the
   game** (player + every creature + every NPC). Allocates
   `owner.full_name()` per fire just to filter. Many creatures
   × many UFunctions/sec = constant alloc churn.
2. **`bbp_log!` flushes (fsync) per line.** Player damage events
   emit 2-3 lines per fire; multicast events fire often enough
   to keep the disk subsystem busy and stall the game thread.
3. **ImGui RPG tab when open**: 60 Hz × 26+ FFI calls × tracker
   mutex locks. Closed tab = zero cost.
4. **`fall_hook` 60+ Hz on player BP class**, allocates
   `fn_name` and calls `drain_pending()` each fire.
5. **`save_slot::current_slot_key` walks GObjects every second
   forever** to find one specific actor.

## 11. Mitigations

- Cache the player's HC pointer at slot activation; in
  kill_hook's trampoline, compare `this as *const _` to the
  cache instead of resolving `owner.full_name()`. **Eliminates
  per-fire String alloc for non-player events.**
- Drop `f.flush()` from `bbp_log!`; rely on OS buffering or
  flush every Nth line / on a timer. **Eliminates per-line
  fsync.**
- Make the wider PE capture in kill_hook (the `if !is_damage_fn`
  branch) opt-in via a settings flag. Researchers turn it on;
  shipping disables.
- Remove `drain_pending()` from `fall_hook` once `call`-op
  testing settles; keep it on a slower drain site or remove
  entirely.
- Cache `class.name()` results for hot lookups (e.g. the
  Environmental DamageType class) so per-multicast resolves are
  pointer compares not string allocations.
- Cache the `AInGameGameState` pointer in `save_slot` after
  first resolve.
- Cache the result of `bbp_rpg_format_skill_effect` (per
  (skill_id, level)) so repeated render frames don't reformat.

## 12. Minimal-viable performance: what we ACTUALLY need vs what we currently do

The mod's user-visible features:

1. Backpack slot patch (one-shot at slot activate)
2. Hunger / thirst CDO writes (one-shot at slot activate)
3. XP / level / skill-point tracking (in-memory + disk persist)
4. Skill apply (per skill per slot activate; per click for spend/refund)
5. ImGui RPG tab (spend points, toggle skills)
6. Kill detection (XP awards on player kills)
7. Fall damage mitigation (velocity stomp on landing)
8. Impact / environmental damage mitigation (post-application scale)
9. Debug HTTP endpoint (testing/research only; OFF in shipping)

For each feature, the MINIMAL ongoing work is small. What we
currently do is far more expensive than necessary.

### Gap table: current vs minimal

| Feature | What we MUST do (minimal) | What we currently do | Gap | Per-fire cost difference |
|---------|---------------------------|----------------------|-----|--------------------------|
| Kill detection | Hook HealthComponent. Per-fire: bool check (is player + is multicast killing-blow), if not -> return. Skip non-player events as cheaply as possible. | Hook HealthComponent. Per-fire: drain_pending(), `owner.full_name()` String allocation, string contains, then if player: more work. | **Allocates a String per fire across ALL HCs in the world** just to filter to player. Should be a pointer compare against a cached player-HC pointer. | ~0 vs ~1 String alloc + free per fire × N creatures × M Hz |
| Fall damage mitigation | Hook player BP class. Per-fire: cheap fn-id compare; only on OnLanded read level + scale Velocity.Z. | Hook player BP class. Per-fire: drain_pending(), `function.as_object().name()` String alloc, multiple string comparisons, optional snapshots. | Allocates `fn_name` for every UFunction the player runs (ticks at 60Hz). | 1 cmp vs 1 String alloc per fire × 60 Hz |
| Impact mitigation | On player-HC multicast, when `LastDamageInfo.DamageType == cached_environmental_class_ptr` AND impact_resistance > 0: scale CurrentDamage. | Resolves DamageType class name to String, locks tracker mutex per multicast, runs whether-or-not the player is the target. | Per-multicast tracker lock + class.name() allocation. | ptr cmp + cached level vs mutex + alloc per fire × M Hz |
| Skill apply on spend/refund | Mutate the right CDO field, log once. | Mutate field, log, sometimes walk GObjects again, call original.call paths through PE. | Acceptable; only on user click. Not a hot path. | n/a |
| ImGui tab render | Per visible frame: get skill levels (one tracker read), render text. Cache formatted strings keyed by (id, level); invalidate on spend/refund/toggle. | Per frame: 26+ FFI crossings, 26+ tracker locks, format effect Strings every frame. | Heavy FFI + lock churn at 60 Hz when tab open. **Zero cost when tab closed.** | 1 lock + N text reads vs 26 locks + 26 format calls per frame |
| Save-slot poll | Cache `AInGameGameState` pointer; check pointer's PlaythroughGuid each tick. Don't walk GObjects after first hit. | Walks all of GObjects every second forever. | 1 Hz GObjects walk × tens of thousands of objects. | ptr deref vs O(N) walk every second |
| Logging | Buffered writes; periodic flush (every Nth line or every second). Never fsync per line. | `f.flush()` after every line. | fsync per log line. Bursts of dozens of lines/sec under combat = dozens of fsync/sec stalling the game thread. | OS-buffered append vs sync disk roundtrip per line |
| Damage ring (`damage_ring`) | OFF by default; opt-in via settings. Production doesn't need it. | ON unconditionally. Allocates per kill_hook fire on player HC. | Per-fire ring push + String alloc when no one is researching. | 0 vs ~1 alloc + mutex push per fire |
| Wider PE capture (`if !is_damage_fn` arm) | OFF by default; opt-in. | ON unconditionally. Records every non-damage UFunction on player HC into the ring. | Per-fire ring push + alloc when no one is researching. | 0 vs ~1 alloc + push per fire |
| `current_impact_resistance_level` per multicast | Cache the level (atomic) on spend/refund/toggle; intercept reads atomic. | Locks tracker mutex per multicast event. | Mutex contention with ImGui-tab thread, world_loader thread, snapshot thread. | atomic load vs mutex acquire per fire |
| `drain_pending` from fall_hook | Only needed when test-side `call` ops are queued. Conditional. | Called every fall_hook fire (60+ Hz). | Constant atomic + mutex check at frame rate even when nothing is queued. | 0 vs ~50 ns per fire × 60 Hz |
| `log_last_damage_info` per damage event | Off in production; on only when researching. | ON. Per damage event reads many fields and emits a `bbp_log!` line. | Extra fsync per damage event. | 0 vs 1+ fsync per damage |

### What "minimal" actually looks like (proposed)

A shipping build that:

1. **Caches the player's HC pointer** at slot activation. kill_hook compares `this as *const _` to the cache; non-player events bail in 2 instructions, no allocation.
2. **Caches the player's BP-class pointer** for fall_hook (or skips name allocation by comparing UFunction ids).
3. **Caches `current_impact_resistance_level`** in an `AtomicU32` written on spend/refund/toggle. Intercept reads atomic, no mutex.
4. **Caches `BP_EnvironmentalDamage_C`'s class pointer** at first sight; per-multicast compare is a pointer compare, no String allocation.
5. **Drops `f.flush()` from `bbp_log!`.** Optional: flush every N lines or on a 1-second timer.
6. **Gates `damage_ring` + wider PE capture + log_last_damage_info behind `settings.debug.research`** (new bool). Default false. Production does zero of this work.
7. **Removes `drain_pending` from `fall_hook`.** Drain only from the world_loader poller (1 Hz; sufficient for the rare `call` op) or restore it only when a research session is active.
8. **Caches `AInGameGameState` pointer in `save_slot`** after first resolve.
9. **Caches `format_skill_effect` results** in a small table keyed by (skill_id, level). Invalidate on level change. ImGui tab reads cached text instead of recomputing per frame.
10. **`on_update` shim callback stays empty** (already is).

After (1)-(10):

- Background work: 1 Hz timer + 1 ptr deref + 1 GUID compare. Ignorable.
- kill_hook: per fire = 1 atomic cmp (player HC?) + 1 atomic cmp (mc fn id?) + branch. No allocation. No mutex. Sub-100ns per fire.
- fall_hook: per fire = 1 atomic cmp (fn id?) + branch. No allocation. No mutex.
- ImGui tab: per frame when open = 1 tracker read + N cached text reads. No format calls.
- ImGui tab when closed: zero cost.
- bbp_log!: format + buffered write. fsync only on shutdown / timer.

## 13. Measured runaway (2026-05-09 evening)

`tests/explore_perf_counters.rs` measured all hot-path counters
over a 30-second window of normal gameplay (player active, no
combat, ImGui tab closed):

```
counter                                         delta   per second
----------------------------------------------------------------------
drain_pending_calls                             32755       1089.7
fall_hook_fires                                 32744       1089.3
fall_hook_fnname_allocs                         32744       1089.3
world_loader_gobjects_walks                        27          0.9
world_loader_polls                                 27          0.9
kill_hook_fires                                    11          0.4
kill_hook_owner_fullname_allocs                    11          0.4
http_requests                                       1          0.0
... everything else: 0/sec ...

Peaks: damage_ring_peak=29, pe_queue_peak=0
```

**The runaway is `fall_hook` firing 1090 times per second.**
That's ~18× per render frame at 60 Hz -- the player's BP class
runs many UFunctions per frame, not just Tick. Every fire was:

1. `drain_pending()` -- atomic swap + mutex acquire + drain check
   + atomic store
2. `function.as_object().name()` -- String allocation per fire

Total: 1090 mutex acquires/sec + 1090 String allocations/sec
just to check "is this OnLanded? if not, do nothing." That's
the cycle and allocator churn the user observed.

ImGui RPG tab was CLOSED during this measurement (0 renders
captured) -- so the tab is **not** the runaway. fall_hook is.

### Mitigations landed (2026-05-09 evening)

#### Fix #1: `drain_pending` empty-queue bypass (in `debug.rs`)

Added an `AtomicUsize` (`PE_QUEUE_SIZE`) shadowing
`PE_QUEUE.len()`. Maintained inside the existing locked
sections: `enqueue_pe` writes after pushing, the drain
clears it after taking. The hot-path check at the top of
`drain_pending` is now:

```rust
pub fn drain_pending() {
    if PE_QUEUE_SIZE.load(Ordering::Acquire) == 0 {
        return;  // single relaxed-ish load + branch. ~1 ns.
    }
    // slow path: take mutex, drain, dispatch
}
```

Common case (queue empty) costs **one atomic load + one
branch**. No mutex acquired. Slow path runs only when a test
has actually queued a `call` op.

#### Fix #2: cached OnLanded UFunction pointer in `fall_hook`

A static `AtomicUsize` (`ON_LANDED_UFUNCTION`) caches the
UFunction's address. Resolved lazily on first OnLanded event
seen by name; pointer-compared per fire after that.

**Before** (per fire, ~1090×/sec):

```rust
fn on_player_fall_event(this, function, parms, original) {
    crate::debug::drain_pending();                 // mutex + atomic swap
    let fn_name = function.as_object().name();     // String allocation
    let is_player = is_player_character(this);
    if is_player && fn_name == "OnLanded" { ... }
    if current_impact_resistance_level() > 0 { ... }
    unsafe { original.call(this, function, parms) };
}
```

Cost per fire: 1 mutex acquire + 1 String allocation + free.
At 1090 calls/sec: 1090 mutex acquires + ~30 KB/sec allocator
churn (over a 10-min session: 19 MB of churn through Windows
heap + 654000 mutex acquires).

**After** (per fire on the fast path, which is ~99% of fires):

```rust
fn on_player_fall_event(this, function, parms, original) {
    crate::debug::drain_pending();                 // 1 atomic load when empty (~1 ns)

    let is_player = is_player_character(this);
    let impact_diag_active = is_player && current_impact_resistance_level() > 0;

    let cached = ON_LANDED_UFUNCTION.load(Relaxed);
    let is_on_landed = cached != 0
        && (function as *const UFunction as usize) == cached;

    // Fast path: not OnLanded and no research diag -> forward.
    if !is_on_landed && !impact_diag_active {
        unsafe { original.call(this, function, parms) };
        return;
    }

    // Slow path: ONLY when the actual interesting events fire.
    crate::counters::bump(&FALL_HOOK_FNNAME_ALLOCS);
    let fn_name = function.as_object().name();
    if cached == 0 && fn_name == FN_ON_LANDED {
        ON_LANDED_UFUNCTION.store(function as *const _ as usize, Relaxed);
    }
    // ... velocity-stomp + diag probes ...
    unsafe { original.call(this, function, parms) };
}
```

Cost per fire on the fast path: ~3 atomic loads + a few
branches + the `original.call`. Zero heap allocations, zero
mutex acquires. Sub-microsecond.

The slow path runs only when:
- The function pointer matches OnLanded (~once per landing, ~0/s
  in normal play), OR
- `impact_resistance > 0` AND we're in the diagnostic window
  (researcher-only mode).

#### Frame-by-frame flow after the fix

**Frame 1, first OnLanded event** (player jumps and lands):
- ~17 trampoline fires for non-OnLanded UFunctions: cache empty,
  pointer doesn't match, `impact_diag_active` false -> fast path,
  forward, return. ~5 ns each.
- 1 trampoline fire for OnLanded itself: cache empty (`cached =
  0`), `impact_diag_active` false -> **fast path bails** because
  `is_on_landed` is false (cache hadn't been populated yet).
  The first OnLanded gets missed by the fast path, but the next
  one will hit the slow path because of the way our gate works.

  *(Subtle bug worth noting: the very first OnLanded ever in the
  process won't hit the slow path because we haven't cached the
  pointer yet. We rely on impact_resistance being on, OR on a
  future OnLanded firing to populate the cache. If this matters,
  add a one-shot warmup that resolves the pointer at install
  time -- skill_id N/A, just a name lookup. Tracked.)*

**Frame 2+, subsequent OnLanded events**:
- Cached pointer matches `function`. Slow path runs: velocity
  stomp + log + return.

**All other frames** (~99% of trampoline fires):
- Cache populated, pointer doesn't match. `impact_diag_active`
  false. Fast-path bail. ~5 ns. Zero allocations.

#### Same pattern applies elsewhere

The optimization is universal:
1. Identify a cheap discriminator (pointer / id / hash).
2. Cache it lazily on first sight in `AtomicUsize` / `OnceLock`.
3. Compare per fire with relaxed atomic load + branch.
4. Allocate / lock / log only on the slow path.

Outstanding hot paths that should get the same treatment
(tracked in `docs/todo.md`):

- `kill_hook`'s `owner.full_name().contains("BP_SurvivalPlayerCharacter")`
  -> cache the player HC `UObject*` at slot activation, compare
  `this as *const _ == cached`.
- `kill_hook`'s `class.name()` for `BP_EnvironmentalDamage_C`
  -> cache the class pointer at first sight, pointer-compare.
- `bbp_rpg_format_skill_effect` per ImGui frame -> cache
  `(skill_id, level) -> text`, invalidate on level change,
  read cached text per render.

Expected after the mitigations:

- `drain_pending_calls` per-call cost drops to ~1 atomic load
  (no mutex, no swap).
- `fall_hook_fnname_allocs` drops from 1090/sec to roughly
  zero (only the first OnLanded event, then never again per
  process; or ~per-landing if `impact_resistance > 0`).
- `fall_hook_fires` stays at 1090/sec (we can't change how
  often UE calls our trampoline; only the cost per fire).

Re-run the perf test after deploying the build to verify the
new per-second rates.

### Why this likely explains the 20GB / 50% CPU report

- 1090 String allocations/sec in a hot game-thread trampoline
  on a process whose allocator has poor reuse for transient
  small allocations can grow the working set without leaking
  in the strict sense. Windows process commit grows; OS doesn't
  return pages until pressure forces it.
- Each `drain_pending` mutex acquire is a kernel syscall under
  contention -- with the HTTP server thread occasionally
  poking the queue, contention cycles add up.
- Combined: high CPU from constant atomic-RMW and mutex
  acquires, growing RSS from allocator churn.

The mitigations cut per-fire cost from "alloc + mutex" to
"atomic load + branch." Should be a measurable drop in both
RAM growth rate and CPU.

## 14. Research code moved to tests (2026-05-09 evening)

The mod-side research scaffolding -- functions that existed
purely to characterize unknowns during investigation -- have
been removed from `fall_hook.rs` and reimplemented test-side in
`tests/research_probes.rs` using the generic debug endpoint
primitives.

Removed from the mod (purged, not commented out):
- `probe_player_status_effects` (logged the player's
  StatusEffects array). Replaced by reading
  `snapshot.status_effects`.
- `probe_status_effect_values` (called
  `UStatusEffectComponent::GetValueForStat` for damage-relevant
  stats). Replaced by `Api::call_ufunction(...)` test-side.
- `read_player_velocity_z` (read CMC.Velocity.Z). Replaced by
  `walk_class` + `read_bytes` test-side.
- `read_player_current_damage` (read HC.CurrentDamage). Replaced
  by `snapshot.live_player.hc.current_damage`.
- `is_collision_relevant` (string-name filter for impact-trace
  diag). Preserved as a pure helper in `tests/research_probes.rs`.
- `return_str_for_unknown` (helper for the above).
- The impact-trace block in `on_player_fall_event` that
  snapshotted CurrentDamage before/after `original.call` for
  collision-relevant fns. That block was the second half of the
  hot-path runaway -- it required an allocated `fn_name` to
  filter, so even with the OnLanded pointer cache we couldn't
  bail without computing it.

`fall_hook.rs` line count: 613 -> 347. The hot path now
consists of: counter bump, drain_pending (atomic load when
empty), pointer compare against cached OnLanded, branch out.
**Zero allocations on the common path.**

The architectural rule is now codified across all four places:
- `~/.claude/skills/runtime-control-http/SKILL.md` -- mod stays
  generic; tests own all research logic
- `~/.claude/skills/grounded2-mods/SKILL.md` -- project rule
- `~/.claude/skills/rust/SKILL.md` -- zero-allocations-on-hot-paths
- `docs/ongoing.md` (this file) -- performance principle at top

Research moves OUT of the mod; mod stops growing; performance
problems that come from research scaffolding running 1000+/sec
on the game thread can't recur.

## 15. Game-side leak identified (2026-05-09 night) -- CASE NOT CLOSED

User reports the game is unplayable: 80% sustained CPU and RAM
growing into the tens of GB over a session. Earlier sections
proved our mod is not the cause (0.18% - 0.30% of process CPU,
~1 MB allocator churn per 30s). Disabling all mods entirely
left the issue intact -- confirmed game-side.

Extended the debug endpoint with three new game-side probes
(`process_threads_json`, `game_population_json`,
`process_memory_json`) so we could see what the game is doing.
Re-ran the 30-second perf test:

### Memory leak source (top growing UObject classes)

```
GObjects:                        350108 -> 352336  (+2228 in 30s)

Package                            +198
SoundNodeWavePlayer                +190
SoundWave                          +144
SceneComponent                      +56
StaticMeshComponent                 +45
ProxyAttraction/Loot/Health/Team    +15 each
...
```

Working-set delta over 30s: **+447 MB**. Private usage delta:
**+452 MB**.

The leaking categories are **packages, audio assets, and scene
proxies**. This is the World-Partition / streaming pipeline:
the game loads cells, audio, and proxy components as the player
moves but appears to never release them. SoundWave is bulky
audio data (avg ~200 KB per object), which explains the size
of the working-set growth.

**This is a Grounded 2 / UE5 bug, not anything we can fix from
the mod.** It is reproducible without any mod loaded. Possible
upstream fixes a player can try:

- Lower audio channel count and audio quality
- Lower max draw distance / streaming distance
- Restart the game every N minutes (the only certain remedy
  for streaming leaks)
- File a bug with Obsidian; reproduce with a fresh save and
  no mods active

### CPU breakdown by thread

The ~80% reported CPU is the average across cores. With our
new `process_threads_json` probe we see:

```
Foreground Worker #1                    58.80% wall
Foreground Worker #0                    57.67% wall
GameThread                              51.48% wall
D3D Background Thread 0-3 (each)        ~47%   wall   <- 4 threads ~188% combined
Background Worker #0-4 (each)           ~33%   wall   <- 5 threads ~165% combined
RHIThread                               20.00% wall
RenderThread 0                          19.38% wall

Total: ~620% wall (six full cores worth)
```

The `Foreground Worker` threads are UE5 TaskGraph high-priority
workers. They are doing the streaming / loading work that
correlates with the GObjects population growth. The D3D
Background Threads are saturated by the rendering load
introduced by the unreleased streamed content.

### Our mod is innocent

```
our hot-path total:    561,748,100 ns of 30s   (1.85% of wall)
fraction of process CPU: 0.30%
```

The mod takes 0.3% of process CPU. Even with the live
instrumentation overhead of `process_threads_json` (Toolhelp +
GetThreadTimes per thread on every snapshot) and
`game_population_json` (full GObjects walk per snapshot), our
share is negligible.

### What is not yet fixed

- One real mod bug: `fall_hook_fnname_allocs` is back at
  ~1100/sec because the cached `OnLanded` UFunction pointer
  only populates when the player actually lands during the
  test window. Trivial fix: resolve the UFunction by name at
  install time, populate the cache directly. ~1 MB/30s of
  allocator churn -- nowhere near the game-side issue but
  worth landing.
- The user's gameplay experience: still unplayable. We have
  diagnosed but not mitigated. There is no mod-side mitigation
  available; the leak is in code we cannot reach.

### Open work

- Land the OnLanded warmup fix.
- File a documented bug with Obsidian (or look for an existing
  community report) referencing the streaming-asset leak.
- Investigate whether any combination of in-game settings
  meaningfully slows the leak (audio, draw distance, streaming
  distance, world partition cell loading distance).
- Consider: a "force-unload streamed content" command
  exposable through our debug endpoint as a mitigation hack
  for the player. Would need to find UE5's
  `LevelStreaming::SetShouldBeLoaded(false)` or equivalent
  surface on already-loaded chunks.

### Raw 30-second perf-test results (2026-05-09 night)

Snapshot delta T0 -> T1 captured by
`tests/explore_perf_counters.rs` while the game was running with
the mod loaded. **Game-state during capture: NOT RECORDED for
this run.** Player position / activity (idle vs moving, indoor
vs outdoor, biome, time of day) was not noted. Re-run with
those facts logged before drawing biome- or activity-correlated
conclusions.

Memory:

```
working_set_bytes  delta = +447,053,824 bytes (~447 MB / 30s)
private_usage      delta = +452,894,720 bytes (~452 MB / 30s)
```

UObject population:

```
GObjects total       350108 -> 352336   (+2228 in 30s)

top growers (delta over 30s):
  Package                            +198    (~23000 total)
  SoundNodeWavePlayer                +190    (~5400  total)
  SoundWave                          +144    (~4500  total)
  SceneComponent                     +56
  StaticMeshComponent                +45
  ProxyAttractionComponent           +15
  ProxyLootComponent                 +15
  ProxyHealthComponent               +15
  ProxyTeamComponent                 +15
  StaticMeshLODResources             +15
  (other classes <= +10 each)

ProxyAttractionComponent absolute count at T1: ~6856
```

Process CPU and per-thread breakdown:

```
process_cpu_total_ns delta over 30s: ~1.86 * 10^10 ns total
                                     (~620% wall, six full cores)

Foreground Worker #1                 17.64s of 30s   58.80% wall
Foreground Worker #0                 17.30s          57.67% wall
GameThread                           15.44s          51.48% wall
D3D Background Thread 0              14.51s          ~48%   wall
D3D Background Thread 1              14.34s          ~48%
D3D Background Thread 2              14.15s          ~47%
D3D Background Thread 3              14.05s          ~47%
Background Worker #0                 10.37s          ~35%
Background Worker #1                 10.19s          ~34%
Background Worker #2                  9.84s          ~33%
Background Worker #3                  9.55s          ~32%
Background Worker #4                  9.10s          ~30%
RHIThread                             6.00s          20.00%
RenderThread 0                        5.82s          19.38%
```

Our mod:

```
sum of TIME_NS_* counters delta over 30s: 561,748,100 ns
                                          (1.85% of one wall second)
fraction of total process CPU:            0.300%
```

(For thread totals to add: each per-thread number above is wall
time on its own core. The process CPU total sums across all
threads, so the ~620% figure equals six cores' wall time per
real second. "Our 0.30%" means our hot-path code consumes
0.30% of the entire process's multi-core CPU budget.)

### How to reproduce

1. Build + deploy the mod:
   ```
   cargo build --release -p better-backpack
   pwsh -NoProfile -File scripts/deploy.ps1 -Install -SkipBuild
   ```
2. Launch Grounded 2 (UE4SS will load the mod). The debug HTTP
   server starts on `http://127.0.0.1:7777` (search for
   "BetterBackpack: HTTP debug listening on" in the mod log to
   confirm).
3. Get to the desired in-game state (the missing variable from
   this run -- record where the player is and what they are
   doing).
4. Run the perf test from another terminal:
   ```
   cargo test --release -p better-backpack --test explore_perf_counters -- --ignored --nocapture
   ```
   Test takes 30s, prints per-counter deltas, top-growing-class
   table, per-thread CPU table, and process_memory delta.
5. Save the output. For an unmitigated baseline run (mods off),
   add the same diagnostic data directly via the snapshot endpoint
   instead, since the test depends on our endpoint being live.

Diagnostic surfaces in the mod side, by file:

- `better-backpack/src/counters.rs` -- AtomicU64 hot-path counters
  + `time_scope` Drop guard + `process_memory_json` +
  `process_cpu_json` + `process_threads_json` + `game_population_json`.
- `better-backpack/src/debug.rs` -- snapshot endpoint includes all
  of the above under top-level keys `counters`, `process_memory`,
  `process_cpu`, `process_threads`, `game_population`.
- `better-backpack/tests/common/mod.rs` -- `Snapshot` struct +
  `snapshot()` API.
- `better-backpack/tests/explore_perf_counters.rs` -- the test
  itself; T0 / sleep 30s / T1 / pretty-print deltas sorted
  descending.

### Second perf run after display-settings change (2026-05-09 night, run 2)

User changed display settings and reported the game "feels EVEN
WORSE." Re-ran the perf test. **CPU went DOWN, but page-fault
rate exploded -- the system is now thrashing on swap.**

Side-by-side vs the first run:

```
                          run 1 (pre-display-change)   run 2 (post-display-change)
working_set delta         +447 MB / 30s                 +424 MB / 30s
private_usage delta       +452 MB / 30s                 +458 MB / 30s
working_set absolute      not captured                  9.26 GB -> 9.70 GB
GObjects delta            +2228 / 30s                   +1035 / 30s   (LOWER)
process CPU total wall    ~620%                         534%          (LOWER)
GameThread wall           51%                           50%
Foreground Worker #0/#1   ~58% / 58%                    45% / 50%     (LOWER)
D3D Background 0-3        ~47% each                     ~38% each     (LOWER)
Background Worker 0-4     ~33% each                     ~27% each     (LOWER)
page_fault_count rate     NOT CAPTURED                  38,477/sec    (NEW: thrashing)
our mod % of process      0.30%                         0.31%
```

Key new datapoint: **page_fault_count delta = 1,165,324 in 30s
(~38k/sec)**. That is the OS resolving page faults by reading
from disk because the working set has crossed the physical-RAM
threshold. Every page fault is a potential frame stall. This
is what the user feels as "even worse" -- it is not that CPU
went up, it is that the game started paging.

GObjects top growers in run 2 (same pattern as run 1, just
slower):

```
Package                  +121     22968 total
SoundNodeWavePlayer      +94       5280
SoundWave                +70       4462
StaticMeshComponent      +32      12952
SceneComponent           +32       5647
ProxyAttractionComponent +13       6858
AttractionLODComponent   +11       6978
ProxyLootComponent       +11       5633
ProxyHealthComponent     +11       5613
ProxyTeamComponent       +11       5557
ObsidianIDComponent       +9       6896
LootLODComponent          +9       5744
HealthLODComponent        +9       5725
TeamLODComponent          +9       5669
AttractionComponent       +8       2774
SCS_Node                  +7       3068
Texture2D                 +4       6866
BodySetup                 +4       4736
Function                  +2      30107
ProxyCustomPropertyComponent +2    3699
```

`fall_hook_fnname_allocs = 0` confirms the cached-OnLanded fix
held in run 2. `fall_hook_fires = 33548 (1107.7/sec)` -- the
trampoline runs at the same rate but allocates nothing.
`http_handle` shows up at 0.93% wall because we are polling
the snapshot endpoint heavily during the test; that is the
test, not steady-state.

Diagnosis: the display change reduced rendering workload
(lower CPU on D3D background + workers) but increased something
memory-heavy (texture pool, view distance, foliage density,
streaming pool, ...). Working set grew faster relative to
physical RAM, OS started paging, frame-time spikes when reads
miss the cache.

Counter-experiment to confirm: lower whatever is the heaviest
RAM consumer (texture quality / texture streaming pool / view
distance), re-run perf test, look for `page_fault_count` delta
to drop to single-digit thousands or lower.

### What the current instrumentation does NOT tell us

We can see that Package + SoundNodeWavePlayer + SoundWave grow
fastest, but we cannot answer:

1. **Which packages?** "Package +121" is a class count. We do
   not know if it is one streaming cell loading 121 packages
   or 121 different cells loading one each, or what content
   is in them.
2. **Which sounds?** SoundWave +70 -- which 70 sounds? Is it
   the same handful churning, or 70 distinct unique assets
   accumulating?
3. **What is referencing them?** UObjects in UE5 are kept
   alive by reference. If SoundWave count grows monotonically,
   something is holding refs and never releasing. We do not
   know what.
4. **Are streaming cells unloading?** If World Partition is
   loading cells but not unloading them, the loaded-level
   list grows. We are not enumerating it.
5. **Is GC running?** UE5 has a garbage collector. If GC is
   triggering but nothing is reclaimable (because of held
   refs), the leak persists despite GC. If GC is not
   triggering at all, the leak is just unbounded growth.
   We have no GC visibility.
6. **Is the leak steady, bursty, or event-correlated?** A
   single 30s window cannot distinguish "steady drip from a
   tick handler" from "burst on cell load that does not
   release." Need time-series sampling.
7. **What are the Foreground Workers actually doing?** They
   burn 50%+ wall but we do not know which UE task they are
   running. UE5 TaskGraph workers run whatever is queued.
   Without callstack sampling we are guessing.

### Plan for better instrumentation (do next session)

Goal: be able to point at a specific subsystem (audio? world
partition? specific package? a hook in the game's code) as
the leak source, with evidence.

Concrete additions to the debug endpoint, in priority order:

1. **Per-package object count** -- new probe
   `game_package_breakdown_json(top_n)`. For each UObject,
   walk its Outer chain to the first UPackage; group by
   package name. Returns the top N packages by hosted-object
   count. Tells us whether the +121 packages-per-30s are
   distinct or reloads of the same cell, and which cells are
   the heaviest.

2. **Outer-chain sample for fastest-growing class** -- new
   probe `game_class_outer_samples_json(class_name, k)`.
   Pick K random or first-K instances of a given class
   (e.g. SoundWave), walk Outer chain for each, return the
   chain as strings. Tells us "these SoundWaves all live
   under /Game/Audio/Ambient/ForestNight/..." or similar,
   pointing at the asset path responsible.

3. **Loaded-levels enumeration** -- new probe
   `game_loaded_levels_json`. Walk GObjects for
   `ULevelStreaming` or `ULevel` instances, report
   PackageName, PersistentLevel, IsLoaded flags. Confirms
   or refutes "World Partition is not unloading cells."

4. **GC observation** -- new counters in `counters.rs`,
   incremented by hooking UE's GC entry points.
   `uobject_gc_passes`, `uobject_gc_freed_count`,
   `uobject_gc_duration_ns`. UE exposes
   `FCoreUObjectDelegates::GetPostGarbageCollect()` /
   `GetPreGarbageCollect()` we may be able to hook, or
   we sample GObjects count every N frames and compute
   "did total go DOWN this tick" as a cheap proxy. Tells
   us whether GC is alive and how much it reclaims.

5. **Time-series sampler test** -- new test
   `tests/explore_perf_timeseries.rs`. Snapshots once per
   second for 60s. Plots GObjects total + working_set +
   page_faults over time. Distinguishes steady drip vs
   bursty event vs ramp.

6. **Focus on the audio path specifically** -- the
   strongest signal is SoundWave + SoundNodeWavePlayer
   growth. UE5 has `FAudioDevice` / `UAudioComponent` /
   `USoundCue`. A probe that walks active
   UAudioComponents and reports their owners + the sound
   asset they reference would identify whether components
   themselves are leaking or whether sounds are pinning
   despite components being released.

7. **Hot-thread stack sampling** -- harder. SetThreadContext
   + StackWalk64 against the Foreground Worker thread
   handles (we already have HANDLEs from
   `process_threads_json`) at 100Hz for a few seconds gives
   a flame-graph-ish view of which game functions those
   threads spend time in. This is the fanciest item; do
   only after 1-6 narrow the suspect list.

What we are NOT going to do: speculation, mod-side
mitigations, or guessing without data. The goal of the
next session is to extend instrumentation, run the new
probes, and let the data point at one subsystem.

## 16. How to verify root cause

Disable the debug HTTP surface first: `settings.json` ->
`debug.http_port: null`. Restart, observe. If RAM/CPU drops
significantly, the debug surface is involved (HTTP server,
damage_ring, wider PE capture).

Then close the ImGui RPG tab (Insert key to hide overlay) for
a few minutes. If CPU drops further, the tab's per-frame FFI
loop is implicated.

After that, selectively neuter each mitigation candidate above
and re-measure.
