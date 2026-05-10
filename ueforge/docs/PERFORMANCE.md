# ueforge Performance Doctrine

> **Authoritative on:** how to write a UE4SS Rust mod that doesn't
> steal frames from the host game. What costs CPU. What leaks
> memory. What ueforge already does for you. What the consumer
> still has to do.

Audience: anyone writing a mod on top of ueforge. Read before
adding any hook, any per-frame work, any hot-path code.

## TL;DR

A well-written mod is invisible in a frame profile. Idle = zero
threads / zero CPU. Hooks fire only on the surfaces they need;
their trampolines do constant-time work and never allocate. State
mutation is rare and cold. Long-running work is moved off-thread.

## The 10/10 bar (kovarex)

> A 10/10 codebase runs for 10 years, used daily by 100 people,
> and never needs a code update.

For a mod, "code update" includes "the user noticed it taking a
frame." So:

- Idle session, ImGui closed, no UI events: **zero per-frame CPU
  cost**.
- Idle session, ImGui open: **zero per-frame allocations**, sub-
  microsecond per render.
- Active session under sustained hook traffic: **single-digit
  ms/sec total** at the worst.
- Memory: **bounded** for life-of-process. No unbounded queues,
  no growing maps, no string leaks.

If you can't justify your hook against this bar, don't ship it.

## Hot paths and how to identify them

A hot path is anything called by the engine on its frame loop
without our control over rate. In a UE4SS Rust mod that's:

1. **Every `ProcessEventHook` trampoline.** The engine fires
   `ProcessEvent` thousands of times per second on instances whose
   vtable we patched. Every one of those calls runs our handler
   first.
2. **Every ImGui tab `render` callback.** Runs on UE4SS's render
   thread, ~once per frame while the tab is visible.
3. **Every `Queue::drain` site.** Whatever UFunction we hook to
   drain the PE queue inherits the queue's processing cost on
   every fire, on top of its own.

Cold paths -- never sweat allocations on these:

- Slot activate / deactivate (~once per save load, seconds apart).
- Skill spend / refund / toggle (user click).
- HTTP `/debug` op handlers (test or research only; rare).
- Worker-thread init (one-shot at DLL load).

## Rules for hot-path code

These are non-negotiable. ueforge code follows them; consumer
code must too.

### 1. Zero allocations

Don't allocate `String` / `Vec` / `Box` / formatted strings unless
this specific call needs one. Use `&str` and stack buffers. If
you wrote `format!(...)` on a hot path, you wrote a bug.

ueforge gives you the tools to avoid this:

- Resolve UE objects by name **once** at install time, cache the
  pointer in an `AtomicUsize` or a `OnceLock`, pointer-compare
  per fire. See [`ueforge::hook::function_ptr`] for one-shot,
  [`ueforge::hook::LazyFunctionPtr`] for lazy.
- Resolve classes via [`ueforge::ue::ClassRef`] -- internally
  cached.
- Build [`ueforge::function_table!`] tables at install time so
  trampolines pointer-compare into a struct of `usize` slots
  instead of name-matching.
- Avoid `function.as_object().name()` inside the trampoline. It
  resolves an FName + allocates a `String`. Use identity
  dispatch. Always.

### 2. Bail early; bail fast

Most trampoline fires are not the function we care about. The
fast path should be one atomic load + one branch + tail call to
the engine original.

```rust
fn on_event(this, function, parms, original) {
    if !ON_LANDED.matches(function, "OnLanded") {
        unsafe { original.call(this, function, parms) };
        return;
    }
    // ... only the matching path does real work ...
}
```

`LazyFunctionPtr::matches` populates the cache on the first
matching fire and pointer-compares forever after. Non-matching
fires are 1 atomic load + 1 cmp + branch.

### 3. No mutexes on the hot path unless work is happening

`AtomicBool` / `AtomicUsize` shadow flags for empty-check
fast paths. Take the mutex only when there's actually work to do.

[`ueforge::Queue::drain`] uses an `AtomicUsize` counter -- empty
queues bail in nanoseconds without touching the mutex. The PE hook
registry uses [`arc_swap::ArcSwap`] for the same reason: the
trampoline reads a snapshot via one atomic load + Arc clone.
Install/drop touches the writer mutex; the trampoline does not.

### 4. Bounded everything

Rings, queues, caches, ledgers -- everything is bounded for the
life of the process or it leaks.

- [`ueforge::ring::EventRing<T>`] -- bounded drop-oldest with
  built-in push-counter + peak watermark.
- [`ueforge::ring::Ring<T>`] -- raw bounded ring.
- [`ueforge::Queue`] -- bounded with re-entrance guard.
- [`ueforge::ue::fname::NameResolver`] -- caps the FString leak
  by caching FName u64 -> String per unique FName.

If you build a `HashMap<usize, T>` or `Vec<T>` keyed by something
the engine can grow without bound, you wrote a leak. Either prune
on a timer or bound the structure.

### 5. Cold init path catches bugs that hot path can't afford to

Every property name resolve, every offset validation, every class
match -- do it ONCE at install. The trampoline trusts the cache.
If the install path detected the wrong class, the trampoline
won't notice; you'll just dispatch on a stale function pointer.
Make install bulletproof so the trampoline can be reckless.

### 6. No `expect` / `unwrap` on hot paths

Game crashes from a panic in the trampoline take the whole
process down. The trampoline wraps in `catch_unwind` already,
but a panic costs 100us+ to unwind. Don't panic on data we expect
to receive every fire. Log-and-skip on rare anomalies.

## Hot-path counter conventions

Every hook gets a triple of named counters:

- `<HOOK>_FIRES` -- bumped on every entry to the trampoline.
- `TIME_NS_<HOOK>` -- accumulated wall time spent inside (via
  [`ueforge::counters::time_scope`]).
- `<HOOK>_<KIND>_ALLOCS` -- per heap-alloc site that survives a
  release-build cfg-gate. Trip-wire for performance regressions.

Plus relevant subsetting counters (`KILL_HOOK_PLAYER_FIRES` --
how many of the fires were the case we actually act on).

Diff the counters between two `/debug snapshot` calls to identify
cycle thieves. The biggest delta is the cost.

[`ueforge::counter_json!`] collapses the snapshot block to one
short list per mod. Use it.

## Memory leak vectors specific to UE4SS Rust mods

Real bugs that bbp's perf work hunted down. Every UE-mod consumer
will hit these unless they reach for ueforge's solutions.

### FString leak on every FName -> String

UE returns FString pointers we can't naively free without binding
`FMemory::Free`. Each `name()` / `full_name()` / `is_default_object()`
call leaks a buffer.

**Fix:** [`ueforge::ue::fname::NameResolver`] caches the resolved
String per unique FName u64. Bounded by the engine's FName pool
(stable size for a given game). Use it through the standard
SDK helpers (`UObject::name`, `UFunction::function_flags`, etc.) --
they go through the resolver.

**Don't** call `name()` on the trampoline hot path even with the
cache. Cached or not, identity dispatch via `LazyFunctionPtr` is
strictly cheaper.

### find_class_fast walking GObjects per call

GObjects has ~150K entries on a mid-game player. Walking it on
every selector resolve / class lookup is O(N) per call.

**Fix:** [`ueforge::ue::find_class_fast`] is name-cached internally;
the warm path is O(1). Wrapped statically by
[`ueforge::ue::ClassRef`] which adds a per-static `OnceLock<*const UClass>`
so even the inner `find_class_fast` cache hashmap lookup is
skipped.

### inspect_address allocating per UClass walk

Every property-name introspection used to allocate
`Vec<NativeProperty>` per super-class per call. 20 rows clicked
in the Scanner UI = 100-300 heap allocs on the render thread.

**Fix:** [`ueforge::ue::UClass::cached_native_properties`] returns
`Arc<[NativeProperty]>` -- subsequent calls share the slice.

### inv_hook viewport map growing per session

A `HashMap<*const UObject, i32>` keyed by widget pointer leaked
the same shape in the C++ port. The Rust port still grows it
without pruning.

**Fix:** Bounded by how many distinct widget instances the player
constructs in a session. In practice: a few dozen. Tidy-up
target if it ever shows up.

### Queue with no backpressure

A debug op posting commands faster than the drain site fires
grows the queue forever.

**Fix:** [`ueforge::Queue`] is bounded with a configured
high-water-mark. Pushes past the cap are dropped + counter-bumped.

### PE hook registry leaking entries on install/drop

Old `Box::leak(Vec<...>)` pattern leaked one snapshot per
install/drop cycle.

**Fix:** [`ueforge::hook::process_event`] uses
[`arc_swap::ArcSwap`] -- one well-tested crate, no leak.

## What ueforge already does for you (consume, don't reinvent)

| Concern | API | Why |
|---|---|---|
| Cached UClass | [`ue::ClassRef`] | Lazy resolve + identity cache |
| Cached UFunction at install | [`function_table!`] | One pass, struct of pointer slots |
| Cached UFunction lazily | [`hook::LazyFunctionPtr`] | Hot-path identity dispatch |
| Typed offset reads | [`ue::TypedField<T>`] | Centralized read_unaligned discipline |
| Vanilla baseline capture | [`rpg::VanillaCache<K,V>`] | First-write-wins keyed cache |
| Bounded structured event ring | [`ring::EventRing<T>`] | Push counter + peak built in |
| Bounded game-thread queue | [`Queue`] | Re-entrance guard + empty-fast-path |
| Hot-path timing | [`counters::time_scope`] | RAII ns accumulator |
| Hot-path counter | [`counters::bump`] | Single Relaxed fetch_add |
| Peak high-watermark | [`counters::observe_peak`] | CAS-loop, branch on common path |
| Counter snapshot JSON | [`counter_json!`] | One macro, no boilerplate |
| Hook install retry/backoff | [`hook::install_with_backoff`] | Config + handles late class load |
| Named worker thread | [`worker::spawn`] | catch_unwind + SetThreadDescription |
| Win32 thread sampler | [`winproc`] | CPU / memory / region probes |

If you reached for one of these by hand-rolling it, stop. If you
need something not on this list, file it and add it to ueforge
first -- always change ueforge first, every time.

## What you (the consumer) still have to do

- Pick the smallest possible hook surface. Hooking PanelWidget
  for trace coverage costs ~10x what hooking
  WBP_InventoryInterface_C costs. Don't hook for diagnostics in
  a release build. Use `cfg!(debug_assertions)`.
- Cache UFunction pointers at install (use `function_table!`).
- Bail early in the trampoline before doing anything that
  allocates.
- Bound any data structure that grows over time.
- Run a counter-diff snapshot before/after every meaningful
  change. If a counter you didn't expect went up, you regressed.

## Doctrine summary

1. **Zero allocs on hot paths.** Cache identity once, pointer-
   compare forever.
2. **Bail early, bail fast.** Atomic load + branch + tail call.
3. **No mutexes on the empty path.** Atomic shadows for
   empty-check.
4. **Bounded everything.** Rings, queues, caches, ledgers.
5. **Heavy lifting at install.** Trampoline trusts the cache.
6. **Counter every hot path.** Fires + time_ns + allocs. Diff
   between snapshots.
7. **No `expect` / `unwrap` on hot paths.** Log-and-skip.

This file is the contract. ueforge upholds it. So must every
consumer.
