# Counters & rings

> **Authoritative on:** the perf-counter primitives (`bump`,
> `observe_peak`, `time_scope`, `counter!`, `peak!`,
> `counter_json!`) and the structured event ring
> (`Ring<T>`, `EventRing<T>`).

Every UE-mod hot path lives or dies by its counter coverage. If
a hook is consuming frames, the counter delta tells you which
one and where in the body.

## Hot-path counter trio

For every hook, declare three counters:

```rust
ueforge::counter!(KILL_HOOK_FIRES);                       // entry count
ueforge::counter!(KILL_HOOK_PLAYER_FIRES);                // post-filter count
ueforge::counter!(TIME_NS_KILL_HOOK);                     // wall ns inside body
```

Bump on every entry. Bump the subset counter after the cheap
filter. Wrap the body in `time_scope` so wall time accumulates.
Diff snapshots before/after a workload to find cycle thieves.

This pattern is non-negotiable. ueforge ships the primitives;
consumers must use them.

## Primitives

```rust
pub fn bump(c: &AtomicU64);                      // +1, Relaxed
pub fn observe_peak(p: &AtomicUsize, value: usize);  // CAS-update on increase
pub fn time_scope(c: &AtomicU64) -> TimeScope<'_>;   // RAII ns accumulator
```

`bump`: single `fetch_add(1, Relaxed)`. The cheapest legal
counter operation.

`observe_peak`: lock-free CAS retry. On the common case (peak
unchanged) it's one load + one branch.

`time_scope`: returns a `TimeScope` RAII guard. Drop adds
`Instant::now() - start` to the counter as nanoseconds. Use at
function entry:

```rust
fn on_event(this, function, parms, original) {
    let _t = ueforge::counters::time_scope(&TIME_NS_KILL_HOOK);
    ueforge::counters::bump(&KILL_HOOK_FIRES);
    // ... body ...
}
```

The TimeScope drops at `}`, accumulating elapsed ns.

## counter! / peak! macros

Declare statics with the right type at module scope:

```rust
ueforge::counter!(KILL_HOOK_FIRES);
ueforge::counter!(
    FALL_HOOK_FIRES,
    FALL_HOOK_FNNAME_ALLOCS,
    DRAIN_PENDING_CALLS,
);

ueforge::peak!(DAMAGE_RING_PEAK);
ueforge::peak!(PE_QUEUE_PEAK);
```

`counter!` emits `pub static <NAME>: AtomicU64 = AtomicU64::new(0);`.
`peak!` emits `pub static <NAME>: AtomicUsize = AtomicUsize::new(0);`.

Multi-arg form declares many counters at once.

## counter_json! macro

Snapshot all counters into a `serde_json::Value::Object` with
typed keys:

```rust
pub fn snapshot_json() -> serde_json::Value {
    ueforge::counter_json! {
        KILL_HOOK_FIRES         => "kill_hook_fires",
        KILL_HOOK_PLAYER_FIRES  => "kill_hook_player_fires",
        FALL_HOOK_FIRES         => "fall_hook_fires",
        DRAIN_PENDING_CALLS     => "drain_pending_calls",
        DAMAGE_RING_PEAK        => "damage_ring_peak",     // AtomicUsize OK
        TIME_NS_KILL_HOOK       => "time_ns_kill_hook",
    }
}
```

The macro accepts any static whose `.load(Ordering::Relaxed)`
returns a JSON-friendly integer (`AtomicU64`, `AtomicUsize`,
`AtomicI64`). Eliminates the `.load(Ordering::Relaxed)`
boilerplate per counter.

## EventRing<T> -- bounded ring with built-in counters

For structured-event capture (damage trace, kill log, drain log):

```rust
use ueforge::ring::EventRing;

#[derive(Clone, Serialize)]
pub struct DamageEvent {
    pub at_secs: u64,
    pub function: String,
    pub damage: f32,
    /* ... */
}

static DAMAGE_RING: EventRing<DamageEvent> = EventRing::new(64);

// From the trampoline:
DAMAGE_RING.record(DamageEvent { /* ... */ });

// From the snapshot endpoint:
let events = DAMAGE_RING.snapshot();
let pushes = DAMAGE_RING.pushes();
let peak = DAMAGE_RING.peak();
```

`EventRing` is a `Ring<T>` paired with:
- A `pushes: AtomicU64` -- total `record()` calls.
- A `peak: AtomicUsize` -- highest ring length observed.

`record(item)` bumps both atomics, then pushes. Drop-oldest on
overflow keeps memory bounded.

Use `EventRing` instead of pairing a raw `Ring<T>` with two
hand-declared counters. The paired form was the bbp pattern
before the consolidation; EventRing eliminates the boilerplate.

### Ring<T> -- raw bounded ring

If you don't need automatic counters:

```rust
use ueforge::ring::Ring;

static RAW: Ring<MyEvent> = Ring::new(128);

let new_len = RAW.push(ev);
let snap = RAW.snapshot();
```

`push` returns the new length (use this for manual peak
tracking if needed). `snapshot()` clones the contents (cold
path; the typical caller is a `/debug snapshot` op).

`Ring<T>` uses `parking_lot::Mutex`. Push is rare relative to
gameplay; clone is once per snapshot request. If contention
ever shows up in a profile, swap to a lock-free SPSC and
per-frame drain. Hasn't been needed.

## Counter conventions

By tradition:

- `<HOOK_NAME>_FIRES` -- entry to the trampoline.
- `<HOOK_NAME>_<KIND>_FIRES` -- subset (e.g. PLAYER_FIRES).
- `<HOOK_NAME>_<KIND>_ALLOCS` -- per heap-alloc site that
  survives a release-build cfg-gate. Trip-wire for performance
  regressions.
- `TIME_NS_<HOOK_NAME>` -- accumulated ns spent in the body.
- `<RING_NAME>_PUSHES` -- ring `record()` count (for raw `Ring`,
  manual; `EventRing` includes this).
- `<RING_NAME>_PEAK` -- ring high-watermark (manual / `EventRing`).
- `DRAIN_<NAME>_CALLS` / `DRAIN_<NAME>_DRAINED_CMDS` -- queue
  drain stats (`DrainSite` includes these; raw `Queue` users
  declare manually).

These show up in `/debug snapshot` results so the test side can
diff between two calls.

## Anti-patterns

- **Don't allocate inside `bump()`.** It's a single
  `fetch_add`. If you wrap it in something that allocates, the
  whole point is lost.
- **Don't `format!` the counter name.** Counter names are
  static; `counter_json!` accepts string literals only. Stringly-
  typed snapshot field names are fine, but the static must be
  named at compile time.
- **Don't read counters on hot paths.** Reads are cheap but not
  free; `time_scope` accumulators are write-only from the hot
  side. Read them only from snapshot / cold paths.
- **Don't mix `Relaxed` with synchronization.** Counters are
  Relaxed on purpose; they're advisory. If you need a counter
  to gate behavior, you need a different primitive (atomic flag,
  channel).

## Cross-references

- [hooks.md](hooks.md) -- where the counter triple goes
- [pe-queue.md](pe-queue.md) -- DrainSite's built-in counters
- [PERFORMANCE.md](PERFORMANCE.md) -- "Counter every hot path"
  rule
