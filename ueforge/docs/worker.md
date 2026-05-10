# Workers

> **Authoritative on:** `ueforge::worker::spawn` -- the
> canonical named worker thread with panic catch + logged
> payload.

UE4SS's `on_unreal_init` callback is on the engine init thread.
Doing heavy work there (settings load, GObjects walks, hook
installs) is fine but a panic propagates up into UE4SS and
takes the game down. The pattern: spawn a worker thread off
init, do everything there, let any panic stay contained.

## spawn

```rust
ueforge::worker::spawn("yourmod/init", move || unsafe { worker_body() });
```

That's the API. A named thread (Win32 `SetThreadDescription` via
`std::thread::Builder::name`) with `catch_unwind` wrapping your
body. Panics inside `work` are caught and logged with the panic
payload + thread name; the thread exits cleanly without taking
the host process down.

```rust
pub fn spawn<F>(name: &'static str, work: F)
where
    F: FnOnce() + Send + 'static;
```

`name` is `&'static str` -- typically a string literal. It shows
up in:
- The Windows thread description (visible to debuggers / crash
  dumps).
- The log line on panic: `worker [yourmod/init]: panicked: <msg>`
- The log line on spawn failure: `worker [yourmod/init]: spawn failed: <e>`

## Why not std::thread::spawn?

`std::thread::spawn` works. The reasons to prefer
`ueforge::worker::spawn`:

1. **Named thread.** `Builder::name` sets the OS-visible name.
   Crash dumps from a 10-year deployment will show "yourmod/init"
   instead of `Thread 7: ?? @ 0x...`.
2. **Panic catch + logged payload.** A panic in your worker
   would otherwise abort the thread silently. We catch it, log
   the message string (or "<non-string panic payload>" if it's
   not a `&str` / `String`), and return cleanly.
3. **Spawn failure logging.** If `Builder::spawn` fails (process
   running out of thread handles, etc.), you get a log line
   instead of an unwrapped panic.
4. **Convention.** Every ueforge mod uses this. Crash dumps
   across the workspace are uniformly named. Code review
   recognizes the pattern.

## Use cases

- **Worker thread off `on_unreal_init`.** Never block the engine
  init thread.
- **Async `cargo deploy install` post-step** (if you needed
  one).
- **Background save flush** (if you batched `SlotStore` writes).

What the worker pattern is NOT good for:

- **Polled state machines** -- use `SlotPoller` instead, which
  ships with a built-in 1Hz poll loop and transition detection.
- **Game-thread mutation** -- `worker::spawn` runs off-thread.
  Mutation that needs game-thread access enqueues on `Queue`
  and waits for the trampoline to drain.
- **Recurring tasks** -- `worker::spawn` is single-shot. For
  recurring work, the worker body itself can run a loop
  (`loop { ... sleep ...; }`) or use `SlotPoller`.

## Lifecycle

The thread runs `work()` to completion, then exits. There's no
shutdown signal -- if your body is `loop { ... sleep ...; }`,
the thread runs for life of process. (kovarex P0: the
`SlotPoller` analogue needs an `Arc<AtomicBool>` stop flag for
hot-reload safety. The `worker::spawn` API is one-shot so the
issue doesn't apply at the worker layer; it applies to whatever
LOOPS inside the worker.)

`std::mem::forget` semantics: the spawned thread joins
implicitly when the process exits. There's no `JoinHandle`
returned -- the worker is fire-and-forget by design.

## Panic payload semantics

`std::panic::catch_unwind` returns the panic payload as
`Box<dyn Any + Send>`. ueforge downcasts to `&'static str` and
`String` (the common cases); anything else logs as
`"<non-string panic payload>"`. If you panic with a custom type,
the type is lost in the log -- format the payload as a string
before panicking, or use `panic!("custom: {}", value)`.

## Cross-references

- [lifecycle.md](lifecycle.md) -- how the worker fits into mod
  init
- [rpg.md](rpg.md) -- `SlotPoller` (the recurring-poll variant)
- [pe-queue.md](pe-queue.md) -- enqueueing work to the game
  thread from a worker
