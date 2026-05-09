# uespy

Embedded HTTP control plane for Unreal Engine Rust mods. Provides
the platform every UE-mod project needs: a tiny opinionated server,
the engine bindings to introspect / mutate / invoke from the
outside, and the test client to drive it all.

Companion crates in this workspace:

- **uespy** (this crate) — runtime: server, queue, primitives,
  selectors, hex, ring, counters, log, hook framework, UE SDK,
  Win32 process probes, TMap / DataTable mechanics.
- **uespy-client** — blocking test client: `Api<S>`, `OpResponse<S>`,
  hex / parm round-trip, perf-log writer.
- **uespy-build** — build-time helper: `CppShim::new()...compile()`
  for compiling the UE4SS C++ shim into your cdylib.

## Why the design looks the way it does

See `~/.claude/skills/runtime-control-http/SKILL.md` for the
full pattern. In short: a single `POST /<endpoint>` endpoint with a
command-shaped envelope, five generic primitives (`snapshot`,
`read_bytes`, `write_bytes`, `call`, `walk_class`), and a selector
grammar (`addr:0x...`, `first_class:Foo`, `singleton:Bar`). Tests
drive every research question and every feature through that
surface. New experiments are test-file changes, not mod changes —
which compresses the iteration loop from minutes to sub-second.

## Quickstart for a new UE4SS Rust mod

### 1. Workspace layout

```
your-game-mods/
  Cargo.toml         # workspace
  uespy/             # this crate (path-dep until published)
    cpp/imgui/       # vendored v1.92.1 — shared by every mod
    ue4ss/UE4SS.lib  # shared import lib
  uespy-client/
  uespy-build/
  your-mod/
    Cargo.toml
    build.rs         # ~5 LoC, see below
    cpp/shim.cpp     # ~30 LoC, see below
    src/lib.rs
    src/debug.rs
    tests/common/mod.rs
    tests/<scenario>.rs
```

The `imgui` vendor and `UE4SS.lib` live in uespy and are picked up
automatically by `uespy-build` — your mod doesn't carry copies.

### 2. Cargo.toml

```toml
[package]
name = "your-mod"
crate-type = ["cdylib", "rlib"]

[dependencies]
uespy = { path = "../uespy" }
serde = { version = "1", features = ["derive"] }
serde_json = "1"

[build-dependencies]
uespy-build = { path = "../uespy-build" }

[dev-dependencies]
uespy-client = { path = "../uespy-client" }
```

### 3. build.rs

```rust
fn main() {
    uespy_build::CppShim::new()
        .source("cpp/shim.cpp")
        .compile();
}
```

`uespy-build` defaults `imgui_dir` to uespy's vendored copy and
`ue4ss_lib_dir` to uespy's bundled `UE4SS.lib`. Override only if
you need a different ImGui version or a per-game UE4SS lib. Add
`.skip_imgui()` for shim-only builds without a debug tab.

### 4. cpp/shim.cpp

```cpp
#include <Windows.h>
#include "imgui.h"                          // if using ImGui
#include "uespy_cppusermodbase.hpp"
#include "uespy_imgui_bridge.hpp"           // if using ImGui

extern "C" void your_mod_start();
extern "C" void your_mod_stop();

class YourMod : public RC::CppUserModBase {
  public:
    YourMod() : CppUserModBase() {
        ModName    = STR("YourMod");
        ModVersion = STR("0.1.0");
    }
    ~YourMod() override { your_mod_stop(); }

    auto on_unreal_init() -> void override { your_mod_start(); }
};

#define YOUR_MOD_API extern "C" __declspec(dllexport)
YOUR_MOD_API auto start_mod() -> RC::CppUserModBase* { return new YourMod(); }
YOUR_MOD_API auto uninstall_mod(RC::CppUserModBase* mod) -> void { delete mod; }
```

### 5. src/lib.rs

```rust
use windows_sys::Win32::Foundation::{BOOL, HMODULE};
use uespy::ue::{platform, PlatformOffsets};

// Game-specific offsets — fill in via UE4SS CXXHeaderDumper.
const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x0, append_string: 0x0, g_names: 0x0,
    g_world: 0x0, process_event: 0x0, process_event_idx: 0x4C,
};

const PLATFORMS: &[(&str, &PlatformOffsets)] = &[
    ("YourGame-Win64-Shipping.exe", &STEAM),
];

#[unsafe(no_mangle)]
pub extern "system" fn DllMain(hmod: HMODULE, reason: u32, _r: *mut ()) -> BOOL {
    if reason == 1 /* DLL_PROCESS_ATTACH */ {
        uespy::log::set_dll_module(hmod);
    }
    1
}

#[unsafe(no_mangle)]
pub extern "C" fn your_mod_start() {
    uespy::log::init(uespy::log::Config {
        file_name: "your_mod.log",
        console_title: "YourMod",
        console: cfg!(feature = "console"),
    });
    let image_base = platform::host_image_base();
    let offsets = platform::detect(PLATFORMS).unwrap_or(&STEAM);
    let _rt = unsafe { uespy::ue::init_runtime(image_base, offsets) };

    // Spawn worker thread that:
    // - patches whatever you patch
    // - installs PE hooks via uespy::hook::ProcessEventHook
    // - starts the debug server if settings.debug.http_port is set
}

#[unsafe(no_mangle)]
pub extern "C" fn your_mod_stop() {
    uespy::log::log(format_args!("stopping"));
}
```

### 6. src/debug.rs

```rust
use serde::Serialize;
use serde_json::Value as Json;
use uespy::envelope::{OpResponse, parse_request};

#[derive(Serialize)]
pub struct Snapshot {
    // Fields tests assert against. Start empty; grow as needed.
}

static PE_QUEUE: uespy::Queue = uespy::Queue::new();

pub fn spawn(port: u16) {
    uespy::spawn(
        uespy::Config { port, endpoint: "/debug", thread_name: "your-mod-debug" },
        |body| serde_json::to_vec(&handle(body)).unwrap_or_default(),
        |msg| uespy::log::log(format_args!("{msg}")),
    );
}

fn handle(body: &str) -> OpResponse<Snapshot> {
    let (op, args) = match parse_request(body) {
        Ok(v) => v,
        Err(e) => return OpResponse::err("<parse-error>", e, build_snapshot()),
    };
    match op.as_str() {
        "snapshot"    => OpResponse::ok(&op, Json::Null, build_snapshot()),
        "read_bytes"  => OpResponse::from_result(&op, uespy::ops::read_bytes(&args, resolve), build_snapshot()),
        "write_bytes" => OpResponse::from_result(&op, uespy::ops::write_bytes(&args, resolve), build_snapshot()),
        "walk_class"  => OpResponse::from_result(&op, uespy::ops::walk_class(&args), build_snapshot()),
        // "call" is enqueued onto PE_QUEUE — see better-backpack/src/debug.rs
        other => OpResponse::err(other, format!("unknown op '{other}'"), build_snapshot()),
    }
}

fn build_snapshot() -> Snapshot { Snapshot { /* ... */ } }

fn resolve(s: &str) -> Result<&'static uespy::ue::UObject, String> {
    if let Some(r) = uespy::selector::resolve_generic(s) { return r; }
    Err(format!("unknown selector '{s}'"))
}

/// Drain on game thread. Wire from a hot PE trampoline you install
/// in src/lib.rs.
pub fn drain_pending() { PE_QUEUE.drain(); }
```

### 7. tests/common/mod.rs

```rust
use serde::Deserialize;

#[derive(Debug, Deserialize)]
pub struct Snapshot { /* mirror src/debug.rs::Snapshot */ }

pub type Api = uespy_client::Api<Snapshot>;

pub fn api() -> Option<Api> {
    uespy_client::Api::try_connect("YOUR_MOD_DEBUG_PORT", "/debug")
}
```

### 8. tests/smoke.rs

```rust
mod common;

#[test]
fn snapshot_round_trips() {
    let Some(api) = common::api() else {
        eprintln!("YOUR_MOD_DEBUG_PORT unset — skipping");
        return;
    };
    let _snap = api.snapshot();
}
```

## Op set, in 30 seconds

```
POST /<endpoint>
{
  "op":   "<name>",
  "args": { ... }
}

response:
{
  "ok":     bool,
  "op":     "<echoed>",
  "error":  null | string,
  "result": <op-specific JSON>,
  "state":  <Snapshot> // full snapshot, every reply
}
```

Built-in ops (call from tests via `uespy_client::Api::op` or
the convenience wrappers):

- `snapshot` — returns just the snapshot
- `read_bytes  { instance_selector, offset, length }`
- `write_bytes { instance_selector, offset, bytes_hex }`
- `walk_class  { class, max?, include_cdo? }` → `{ instances: [...] }`
- `call        { class, function, instance_selector, parms_hex }` →
  `{ parms_hex_after }` (engine-mutated OUT params returned as hex)

Selectors: `addr:0x<hex>`, `first_class:<Name>`, `class:<Name>`,
`singleton:<Name>` (resolves the class CDO). Game crates can add
shorthands in their `resolve` fn.

## TDD pattern

Every feature, every bug, every research question:

1. Decide the user-observable expectation, concretely.
2. Make sure the snapshot exposes the observable.
3. Write the failing test in `tests/<scenario>.rs`.
4. Use the endpoint to research (`api.snapshot()`,
   `api.op("read_bytes", ...)`) — peek at live state.
5. Implement the op or fix.
6. Test goes green. Land it.

The skill at `~/.claude/skills/runtime-control-http/SKILL.md`
spells this out further. The headline: **research is code, not curl.**
Every experiment lives as a `tests/explore_*.rs` file using the
same `Api<S>` your assertions use, so observations promote directly
to regressions.
