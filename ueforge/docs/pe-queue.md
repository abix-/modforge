# Game-thread queue

> **Authoritative on:** how off-thread code (HTTP listener,
> worker threads, slot poller) gets work onto the game thread,
> how trampolines drain that work, and how `DrainSite` collapses
> the boilerplate.

Many UE engine APIs (`UObject::ProcessEvent`, anything that
triggers replication, blueprint events, network RPCs) are only
safe to call from the game thread. The HTTP listener runs on a
worker thread, so `op` handlers that need to invoke those APIs
**enqueue** a job and **block on a reply channel** until the
game thread drains it.

## Queue

`ueforge::Queue` is the core type. Lock-free empty-check,
mutex-protected push/drain, re-entrance guard, reply channels.

```rust
use ueforge::Queue;

static PE_QUEUE: Queue = Queue::new();
```

### Enqueue (off-thread)

```rust
let result = PE_QUEUE.enqueue(
    move || run_on_game_thread(cmd),
    Duration::from_secs(5),
);
```

`enqueue` returns `Result<Json, String>`:
- `Ok(json)`. The job ran on the game thread, here's its
  result.
- `Err("...timed out...")`. The drain didn't fire within
  the timeout. The job did NOT run.
- `Err("queue closed")`. The reply channel was dropped
  (process shutting down).

The caller blocks on the reply. Pick the timeout based on
how often your drain site fires. A damage multicast fires
every player tick; 5s is generous. A character tick fires every
frame; 1s is plenty. A reload-only drain might need 30s+.

### Drain (game thread)

```rust
let stats = PE_QUEUE.drain();
```

`drain()` semantics:

1. Atomic empty-check. If empty, returns `DrainStats::default()`
   immediately (one load + branch).
2. CAS the `DRAINING` flag. If already set (re-entrance), return
   `DrainStats { reentered: true, .. }`. The outer drain will
   process this work.
3. Take the queue contents, run each job, send the result to its
   reply channel, return `DrainStats { peak, drained, reentered:
   false }`.

Re-entrance: a job itself can trigger ProcessEvent fan-out that
re-enters the same trampoline draining us. The DRAINING flag
prevents recursion. The outer drain finishes the original
batch; the inner returns immediately.

```rust
pub struct DrainStats {
    pub peak: usize,         // queue length before drain
    pub drained: usize,      // jobs run
    pub reentered: bool,     // true if drain skipped due to re-entrance
}
```

### Empty-fast-path

Hot trampolines call `drain()` every fire. The empty path must
be cheap:

```rust
fn drain(&self) -> DrainStats {
    if self.size.load(Ordering::Acquire) == 0 {
        return DrainStats::default();   // one atomic load + branch
    }
    // ... slow path ...
}
```

`size` is an `AtomicUsize` shadow updated on enqueue / drain. No
mutex on the empty path. This means a trampoline draining a
queue that's empty 99% of the time pays ~5ns per fire.

## DrainSite. Queue + counters in one static

`ueforge::pe_queue::DrainSite` wraps `Queue` with the standard
performance-counter quad (drain calls, drained cmds, peak depth,
time_ns spent). One static replaces a `Queue` plus four hand-
declared `counter!` statics plus a 20-line `drain_pending`
wrapper.

```rust
use ueforge::pe_queue::DrainSite;

pub(crate) static PE_QUEUE: DrainSite = DrainSite::new();

// Off-thread: enqueue via .queue()
PE_QUEUE.queue().enqueue(move || work(), Duration::from_secs(5))?;

// Game-thread: drain
PE_QUEUE.drain();   // bumps drain_calls; bumps drained_cmds + peak only on actual drain
```

Counters surfaced through accessors:

```rust
PE_QUEUE.drain_calls()   // u64: total drain calls (including empty fast-paths)
PE_QUEUE.drained_cmds()  // u64: total commands drained
PE_QUEUE.peak()          // usize: highest queue depth observed
PE_QUEUE.time_ns()       // u64: nanoseconds spent inside non-empty drains
```

In your snapshot endpoint:

```rust
"drain_pending_calls": PE_QUEUE.drain_calls(),
"drain_pending_drained_cmds": PE_QUEUE.drained_cmds(),
"pe_queue_peak": PE_QUEUE.peak(),
"time_ns_drain_pending": PE_QUEUE.time_ns(),
```

## Drain-site selection

The "game thread" is whatever thread drains your queue. ueforge
doesn't pick one for you. You choose, by deciding which
ProcessEvent trampoline calls `PE_QUEUE.drain()` at the top.

### Picking a good drain site

The site needs to:

1. **Run on the game thread.** Anything called via `ProcessEvent`
   from native game code does. (NetMulticast trampolines, BP
   event dispatcher targets, tick functions all qualify.)
2. **Fire frequently.** A queue drained once per second has
   1-second-latency ops. A queue drained on every tick has
   per-frame latency. Pick based on what your timeouts tolerate.
3. **Run in foreground gameplay.** A drain site behind a `if
   skill_active` check stalls when the skill is off. Bbp learned
   this when an `impact_resistance` mask blocked multicast
   traffic and starved its drain.

### Common choices

| Drain site | Cadence | Caveat |
|---|---|---|
| Damage multicast (e.g. `MulticastHandleEffectsWithDamageFlags`) | per player damage tick | stalls when player isn't taking/dealing damage |
| Character tick (e.g. `ASurvivalCharacter::ReceiveTick`) | per frame | hooked but rarely targeted |
| Inventory open/close | event-driven | only fires when UI opens |
| Global PE pre-callback (`RegisterProcessEventPreCallback`) | every PE in the process | requires UE4SS shim glue (Wave E1, deferred) |

The global PE pre-callback is the future right answer. Until
that lands, the damage multicast is g2rpg's choice; OWS may pick
the character tick.

### What if I have multiple drain sites?

Multiple `DrainSite` instances, one per drain. They don't share
state. A status-effect snapshot drain might live on a different
site than a debug `call`-op drain. Both work; just don't share
one DrainSite across multiple unrelated workflows.

## Re-entrance scenarios

Re-entrance is real, not theoretical. Examples:

1. **Heal calls into damage trampoline.** A queued `AddHealth`
   call sets `CurrentDamage`, which fires `OnRep_CurrentDamage`,
   which dispatches via PE. Back into the damage hook that's
   draining us.
2. **AddEffect re-enters effect-tick handler.** Adding a status
   effect can fire its initial tick UFunction, which fans out
   into PE.
3. **Inventory mutation triggers UI update.** Setting a slot
   count can fire `OnInventoryChanged`, which dispatches PE on
   the widget you're hooking.

The DRAINING flag handles all of these correctly: the inner
drain returns `reentered: true`, the outer drain finishes its
batch, the recursion never deepens.

If your handler logic depends on whether you're inside a drain,
read `Queue::is_draining` (TODO: add this; right now it's
internal). Usually you don't care. Drain semantics are
self-correcting.

## Performance notes

`Queue::enqueue` allocates: one `Box<dyn FnOnce>` for the job +
one `Sender<Result>` channel half. This is fine; enqueue is the
worker-thread-side cold path. **Don't enqueue from a hot
trampoline. You'll allocate per fire.**

`Queue::drain` allocates: one `Vec<Pending>` to take the queue
contents under the lock and process them outside. The Vec is
the queue's existing buffer (via `mem::take`), not fresh.

Per-job cost is whatever your job closure does + one channel
send. Channel send for a `Result<Json, String>` is one heap
write + one wakeup; ~100ns budget.

## Bounded depth + cancellation

`Queue` is bounded. The default cap is `DEFAULT_MAX_DEPTH = 1024`;
override via `Queue::with_capacity(n)`. `enqueue` past the cap
returns `Err("ueforge: PE queue full ({len} >= cap {cap})")`
without enqueuing. Without the cap a misbehaving HTTP client
(or a stuck drain site) could pile entries until the host
process runs out of memory.

1024 is ~100x the largest realistic burst from our test client
today. Tune down for memory-tight builds; tune up only if a
legitimate workflow brushes the ceiling.

### Cancellation on caller timeout

`enqueue(job, timeout)` blocks the caller on a one-shot reply
channel. If `recv_timeout` fires, the caller used to return
"timed out" while the job stayed queued. The drain ran it
later, the result was dropped (the receiver was gone), and the
client's natural retry **double-executed** non-idempotent ops
like `spend_points`, `write_bytes`, `call`.

Each `Pending` now carries an `Arc<AtomicBool> cancelled`. On
`recv_timeout` the enqueue side flips the flag; on the next
drain, `Queue::drain` skips any pending whose flag is set
**before** invoking the closure. The semantics:

- Caller times out -> job marked cancelled -> never runs.
- Caller times out AFTER the drain already started the closure
  -> closure runs to completion (we don't yank a job
  mid-execution); reply send fails silently because the
  receiver is gone.
- Drain completes within the timeout -> reply delivered, normal
  path.

Cancellation is best-effort. It plugs the common race (client
retried after timeout, original job still queued) but doesn't
make non-idempotent ops magically safe; design for idempotency
where you can.

## Cross-references

- [hooks.md](hooks.md). Where you install the trampoline that
  drains
- [counters.md](counters.md). The counter conventions
  DrainSite uses
- [http.md](http.md). How the HTTP listener uses
  `Queue::enqueue` for game-thread ops
- [PERFORMANCE.md](PERFORMANCE.md). Empty-path discipline rule
