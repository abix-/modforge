# Memory tools

> **Authoritative on:** ueforge's runtime memory inspection
> surface -- the Cheat-Engine-style scanner, address freezes,
> `inspect_address` property walker, and Win32 process probes
> (`winproc`).

These are research / debugging tools, not production features.
Every op is exposed through the HTTP control plane (so the
test side can drive them) and the Scanner ImGui tab consumes
the same ops directly.

## Scanner -- value search

The use case: a field exists in game memory but the SDK dump
doesn't tell you where. Scan for the value (e.g. current HP =
100), narrow on rescan (HP changed to 92), end up at the
address.

### Ops

```
POST /debug { "op": "scan_memory", "args": { "type": "f32", "value": 100.0 } }
POST /debug { "op": "scan_rescan", "args": { "session_id": <id>, "mode": "exact", "value": 92.0 } }
POST /debug { "op": "scan_session", "args": { "session_id": <id> } }
POST /debug { "op": "scan_close",   "args": { "session_id": <id> } }
```

### Type support

| `type` | Width | Note |
|---|---|---|
| `i32` | 4 | signed int |
| `u32` | 4 | unsigned int |
| `f32` | 4 | float (epsilon match) |
| `f64` | 8 | double |
| `i64` | 8 | signed long |
| `u64` | 8 | unsigned long |

### Rescan modes

- `exact` -- match `value` again
- `changed` -- value differs from previous scan
- `unchanged` -- value matches previous scan
- `increased` -- value > previous
- `decreased` -- value < previous

### Region walking

Scanner enumerates committed memory regions via
`VirtualQuery`, filtered to the host process. `MEM_COMMIT |
PAGE_READWRITE` only -- code regions and reserved pages are
skipped. UE5 game heap on Grounded 2 is ~4-8 GB; full scan
takes a few seconds.

### Sessions

Each `scan_memory` returns a `session_id`. Subsequent
`scan_rescan` / `scan_session` / `scan_close` ops reference it.
Sessions hold the hit list in memory; `scan_close` releases it.

The session mutex was once held across the full scan walk
(blocking other scanner ops during a multi-second scan). Fixed:
the snapshot is taken outside the lock; only the session insert
re-acquires.

### Limits

- Max 100K hits in a session. Beyond that the response
  truncates with a flag.
- One session per active scan; opening a fresh `scan_memory`
  doesn't close prior sessions (you have to `scan_close`
  explicitly).

## Address freezes

The use case: hold a field at a chosen value while the game
runs, regardless of what game code writes.

```
POST /debug {
  "op": "freeze",
  "args": {
    "selector": "live_player_hc",
    "offset": "0x32C",
    "type": "f32",
    "value": 0.0,
    "hz": 30
  }
}
```

The freeze worker thread re-resolves the selector every tick,
walks `VirtualQuery` to confirm the page is still mapped + RW,
writes the value. Stale-address protection: if the resolve
fails (the underlying object got recycled), the freeze logs the
miss and skips that tick. No fault.

```
POST /debug { "op": "unfreeze", "args": { "id": <freeze_id> } }
POST /debug { "op": "freeze_list", "args": {} }
```

`freeze_list` returns active freezes with their selectors,
offsets, types, current frequency, and miss count.

### Why selector-relative

Earlier scanner versions accepted `addr:0x...` directly to
freeze. UE recycles allocations: the address that held the HC
at scan time may hold something else 30 seconds later. Writing
at a stale address corrupts whatever moved in.

Selector-relative freezes resolve fresh each tick via
`selector::resolve_generic` and the game's selector handlers.
The selector might miss (`live_player_hc` returns None when no
player exists), but it never writes to the wrong address.

### Hz / overhead

Default freeze frequency is 30 Hz (every ~33ms). Overhead per
tick = one selector resolve (cheap, cached) + one VirtualQuery
+ one `write_unaligned`. Negligible per freeze; with 5+ active
freezes it's still well under one frame's budget.

## inspect_address

```
POST /debug { "op": "inspect_address", "args": { "addr": "0x12345678" } }
```

Resolves the address as a UObject, reads its UClass, walks the
property chain, returns:

```json
{
  "class_name": "UHealthComponent",
  "properties": [
    { "name": "MaxHealth",       "offset": 808,  "value": 100.0 },
    { "name": "CurrentDamage",   "offset": 812,  "value": 0.0 },
    { "name": "DamageReduction", "offset": 236,  "value": 0.0 }
    // ...
  ]
}
```

Property names come from
[`UClass::cached_native_properties`](ue-sdk.md#uclass--ufunction)
-- first call walks the FField chain + resolves FNames; cached
afterward.

The Scanner ImGui tab uses this to label scan hits with their
property names. Click a hit -> `inspect_address` -> see what
field that hit corresponds to.

## winproc -- Win32 process probes

`ueforge::winproc` exposes:

```rust
pub fn process_threads_json() -> Value;
pub fn process_cpu_json() -> Value;
pub fn process_regions_json() -> Value;
pub fn process_memory_json() -> Value;
pub fn sample_thread_modules_json(tid: Option<u32>, samples: u32) -> Value;
```

### process_threads

Per-thread state: TID, suspend count, kernel + user CPU times,
priority, base address, exit code (if exited).

Use to find which thread is burning CPU when the snapshot
counter delta says "something heavy is running."

### process_cpu

Aggregate process CPU: kernel + user microseconds, page faults,
peak working set, working set, peak commit, commit, paged pool,
non-paged pool.

### process_regions

`VirtualQuery` enumeration: every committed region with
size, protection flags, allocation type. Used by the scanner;
also useful for "where's the leak?" analysis.

### process_memory

Working set + private bytes, peak working set + peak private
bytes. Diff between two calls reveals leak rates.

### sample_thread_modules

Sample the instruction pointer of `tid` (or all threads)
`samples` times, classify each sample by which loaded module
the IP is in. Output: `{ module_name: hit_count }`.

This is the cheapest profiler -- no PDB symbols, no DBG help,
just `GetThreadContext` -> map IP to module. For a thread
burning CPU in our DLL, you'll see `main.dll` dominate. In UE
code, `Grounded2-WinGRTS-Shipping.exe`. In ucrt /
KERNELBASE, you've got an OS-API issue.

Use case: the snapshot reports `time_ns_kill_hook` is high,
but you need to know if it's our trampoline or something the
trampoline calls into. Sample 10K times; module hit counts
tell you.

## ImGui consumption

`ueforge::ui_scanner::render` (the built-in Scanner tab) wraps
all of the above behind an interactive UI:

- Selector + offset + type + value -> Scan
- Hit list with addresses, current values, "Inspect" buttons
  (call `inspect_address`)
- Rescan with mode dropdown
- Per-hit "Freeze" -> `freeze` op
- Active freezes list -> `freeze_list` + per-row "Unfreeze"

g2rpg doesn't include the tab today (RPG tab only); ows-tweaks
does as a reference.

## Cross-references

- [http.md](http.md) -- the op envelope every probe rides on
- [ue-sdk.md](ue-sdk.md) -- the UObject / UClass plumbing
  inspect_address consumes
- [imgui.md](imgui.md) -- the Scanner tab integration
- [RESEARCH.md](RESEARCH.md) -- when to reach for the scanner
  vs other probes
