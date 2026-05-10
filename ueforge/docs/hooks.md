# Hooks

> **Authoritative on:** how ueforge installs ProcessEvent hooks,
> how trampolines work, and the helpers (`function_table!`,
> `LazyFunctionPtr`, `install_with_backoff`, `install_many`) that
> keep hot paths zero-alloc and install paths bulletproof.

ueforge's hook surface is exclusively ProcessEvent vtable
patching. We do not patch native functions (no detours, no
trampolines into game code). The reason: ProcessEvent is the
single funnel through which every Blueprint event, every
NetMulticast RPC, every BP-callable UFunction routes. Hooking it
catches everything that matters; hooking native functions
catches a tiny fraction with much higher risk.

## ProcessEventHook

The core type. Patches a class's vtable slot at
`process_event_idx` with a trampoline that dispatches to your
handler.

```rust
use ueforge::hook::{OriginalProcessEvent, ProcessEventHook};
use ueforge::ue::{UFunction, UObject};
use std::ffi::c_void;

let hook = ProcessEventHook::install("HealthComponent",
    |this: &UObject, function: &UFunction, parms: *mut c_void,
     original: OriginalProcessEvent| {
        // ... your handler ...
        unsafe { original.call(this, function, parms) };
    })?;

std::mem::forget(hook);  // leak so the hook survives worker exit
```

### Lifetime

`ProcessEventHook` is RAII. Its `Drop` impl restores the
original vtable slot. In practice you `std::mem::forget` it so
the hook lives for the process lifetime -- worker threads exit,
the hook keeps firing.

### Trampoline path

When the engine calls `ProcessEvent` on a UObject whose vtable
matches a hooked class:

1. The trampoline reads `this`'s live vtable pointer and looks
   up the matching `Entry` in the hook registry via `ArcSwap`
   snapshot (one atomic load + Arc clone, no mutex).
2. It wraps the original function pointer in
   `OriginalProcessEvent` and calls your handler with
   `(this, function, parms, original)`.
3. Your handler decides whether to forward via
   `original.call(...)`, transform parms first, suppress the
   call entirely, or all of the above.
4. `catch_unwind` wraps the handler so a panic doesn't take the
   game down. On panic, the trampoline falls through to the
   engine original.

### Multiple classes

Multiple hooks can be installed against different classes.
The trampoline matches on the live vtable pointer of `this`,
so different classes don't cross-trigger.

The hook registry is stored as `Mutex<Vec<&'static Entry>>`
(write-rare path) plus `ArcSwap<Vec<&'static Entry>>` (read-hot
path). Trampolines never touch the mutex.

## install_many -- multi-class install

For BP-generated player classes that come in subclasses
(`BP_SurvivalPlayerCharacter_C`, `..._Female02_C`,
`..._Gellarde_C`):

```rust
let hooks = ProcessEventHook::install_many(
    &[
        "BP_SurvivalPlayerCharacter_C",
        "BP_SurvivalPlayerCharacter_Female02_C",
        "BP_SurvivalPlayerCharacter_Gellarde_C",
    ],
    |this, function, parms, original| {
        // ... handler runs for any of the three ...
    })?;
```

Classes that don't resolve are skipped with a log line; classes
that fail at install (null vtable, etc.) propagate as `Err`.
Returns `Err("no classes installed")` if zero classes resolved.

The handler closure must be `Clone` so it can be cloned per
class.

## install_with_backoff -- retry loop

UE classes show up in GObjects on the engine's schedule, not
ours. `on_unreal_init` fires before most BP-generated classes
load (the inventory widget class isn't there until the player
opens the inventory the first time).

```rust
use ueforge::hook::{install_with_backoff, RetryPolicy};

let hook = install_with_backoff(
    "inv hook",                         // log-line tag
    RetryPolicy::default_install(),     // 500ms / 5s / 10min
    || inv_hook::install(slot_count),   // FnMut returning Result
);
match hook {
    Some(h) => { ueforge::log!("installed"); std::mem::forget(h); }
    None    => { ueforge::log!("gave up"); }
}
```

`RetryPolicy::default_install()` ships bbp's battle-tested
tuning (500ms base / 5s cap / 10min total timeout). Custom:

```rust
let policy = RetryPolicy::new(
    Duration::from_millis(100),    // base
    Duration::from_secs(2),        // cap
    Duration::from_secs(60),       // timeout
);
```

The retry logs "pending (<error>), will retry" on each unique
error string transition (so if your install fn returns
`"WBP_X not loaded"` ten times, you get one log line, not ten).

## function_table! -- declared identity dispatch

For hooks that need to identity-dispatch many UFunctions on a
single class, the `function_table!` macro generates a struct of
`usize` slots + an `install(&UClass)` method that resolves them
all in one pass.

```rust
use ueforge::function_table;

function_table! {
    struct InvIfaceFns for "WBP_InventoryInterface_C" {
        required populate_item_grid: "PopulateItemGrid",
        required construct: "Construct",
        required on_mouse_wheel: "OnMouseWheel",
        optional refresh_ui: "RefreshUI",
        optional refresh_menu_page: "RefreshMenuPage",
        // ...
    }
}

// At install:
let fns = InvIfaceFns::install(inv_iface_class)?;

// In the trampoline:
let fp = function as *const UFunction as usize;
if fp == fns.construct {
    // ... handle Construct ...
}
```

`required` slots return `Err(<fn-name>)` if the function isn't
found at install time. `optional` slots land as `0` if missing
-- callers test with `if slot != 0`.

The macro generates a `pub const CLASS_NAME: &'static str` you
can use for diagnostics: `format!("{}::{}", FNS::CLASS_NAME, ...)`.

### When to use this vs LazyFunctionPtr

Use `function_table!` when:

- You hook a class and dispatch on many of its functions
  (kill_hook on HealthComponent dispatches on 3-4; inv_hook
  dispatches on 11).
- You want install-time errors if a required function is missing
  (catches a wrong SDK dump fast).
- You're OK paying a bit of install-time cost for zero hot-path
  cost.

Use `LazyFunctionPtr` when:

- You only care about one or two functions on a class that
  fires *many* others (fall_hook: only OnLanded matters out of
  hundreds of player-class events).
- You'd rather not enumerate the set of functions at install
  time.

## LazyFunctionPtr -- lazily-cached identity

```rust
use ueforge::hook::LazyFunctionPtr;

static ON_LANDED: LazyFunctionPtr = LazyFunctionPtr::new();

fn on_event(this, function, parms, original) {
    if !ON_LANDED.matches(function, "OnLanded") {
        unsafe { original.call(this, function, parms) };
        return;
    }
    // ... only the matching path does real work ...
    unsafe { original.call(this, function, parms) };
}
```

`matches(function, expected_name)`:

- **Warm path** (cache populated, function is the cached
  pointer): 1 atomic load + 1 compare. Returns `true`.
- **Warm path** (cache populated, function is something else):
  1 atomic load + 1 compare. Returns `false`. **No FName
  resolve, no allocation.**
- **Cold path** (cache empty, first matching call): resolves
  the function's FName + string compare. On match, populates
  the cache. Each function sees this at most once.

This is the highest-leverage hot-path tool ueforge ships. A
fall_hook trampoline that fires ~2000 times/sec on a busy player
class spends < 100ns per fire when only OnLanded matters; the
non-matching ~99% bail with one atomic load + branch.

### Why this beats `function.name() == "OnLanded"`

The naive form allocates one `String` + resolves an FName per
fire. At 2000 fires/sec that's 2000 String allocs/sec --
measurable in a profile and a real allocator-pressure source.
LazyFunctionPtr makes the identity check zero-alloc on the warm
path.

### function_ptr / function_ptr_required helpers

Lower-level: resolve a UFunction by `(class_name, function_name)`
once and return its address as `usize`. Useful when you want to
manage the cache yourself.

```rust
use ueforge::hook;

let fp: usize = hook::function_ptr("HealthComponent", "AddHealth")
    .expect("AddHealth not found");

// later, in the trampoline:
if function as *const _ as usize == fp {
    // ...
}
```

`function_ptr_required` is the `Result<usize, &'static str>`
variant that bubbles a missing-function error message.

## Drain site

The trampoline is also where you drain the
[`pe_queue::Queue`](pe-queue.md). Every hook installs near a
known-hot UFunction; that fires often enough to keep the queue
moving.

```rust
fn on_event(this, function, parms, original) {
    PE_QUEUE.drain();   // DrainSite empty-fast-path is one atomic load

    // ... rest of handler ...
}
```

See [pe-queue.md](pe-queue.md) for the full pattern + drain-site
selection rules.

## Vtable internals

`ueforge::hook::vtable::write_slot` is the low-level primitive:

```rust
unsafe fn write_slot(slot: *mut *mut c_void, new: *mut c_void)
    -> Option<*mut c_void>;
```

Flips `VirtualProtect` to writable, swaps the slot, restores
protection. Returns the previous value or None if VirtualProtect
fails. Used by `ProcessEventHook::install` and `Drop`.

You shouldn't need to call this directly; ProcessEventHook owns
the protocol.

## Counter conventions

Every hook installs a triple of named counters (see
[counters.md](counters.md)):

```rust
ueforge::counter!(KILL_HOOK_FIRES);
ueforge::counter!(KILL_HOOK_PLAYER_FIRES);
ueforge::counter!(TIME_NS_KILL_HOOK);
```

Bump `KILL_HOOK_FIRES` on every entry. Bump
`KILL_HOOK_PLAYER_FIRES` after the cheap player-filter check
passes. Wrap the body in `time_scope(&TIME_NS_KILL_HOOK)`.

Diff the counter snapshots before/after to identify cycle
thieves.

## Caveats

### Re-entrance

If your handler invokes `process_event` (e.g. via
`ueforge::ops::exec_call`), that triggers a fresh PE dispatch
that may re-enter your trampoline. The hook framework itself
handles vtable identity correctly, but if you're draining
`Queue` jobs that themselves call into PE, the
`Queue::drain`'s re-entrance guard skips the inner drain --
preventing recursive recursion. See [pe-queue.md](pe-queue.md).

### Vtable identity vs subclass dispatch

`ProcessEventHook::install("Foo")` patches the vtable of `Foo`'s
CDO. Subclasses with their own vtables don't get hooked. If you
need both `Foo` and `BP_Foo_C`, install on both -- the
`install_many` helper exists for exactly this.

### Engine-internal calls bypass ProcessEvent

Some UE5 functions are `Final|Native` -- the engine bypasses
ProcessEvent on the internal damage path. `Kill` is the
classic example. Hooking `Kill` directly won't see player-on-
creature kills; hooking `MulticastHandleEffectsWithDamageFlags`
(the NetMulticast that fires via PE on every damage event) does.

If your target is a `Final|Native` function: hook a related PE
function that runs in the same code path. The SDK headers tag
function flags so you can grep for `Final` to find these.

### Hook before runtime init = unset?

The trampoline reads `try_runtime()` to get
`process_event_idx`. If the runtime isn't initialized yet,
install fails with `"ueforge runtime not initialized; install
hooks AFTER init_runtime"`.

Order in `worker()`:

1. `ueforge::ue::init_runtime(image_base, offsets)`
2. ... hook installs ...

## Cross-references

- [pe-queue.md](pe-queue.md) -- draining game-thread jobs from
  the trampoline
- [counters.md](counters.md) -- the fires / time_ns / allocs
  counter triple
- [PERFORMANCE.md](PERFORMANCE.md) -- hot-path discipline rules
- [ue-sdk.md](ue-sdk.md) -- the UClass / UFunction types you
  hook against
- [lifecycle.md](lifecycle.md) -- where in the worker thread
  hooks install
