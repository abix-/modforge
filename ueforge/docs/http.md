# HTTP control plane

> **Authoritative on:** the `/debug` HTTP endpoint, the
> command-shaped op envelope, the selector grammar for naming
> game objects, the builtin generic primitives, and the
> `Api<S>` test client.

The HTTP control plane is the single most important debugging /
research surface ueforge ships. Every behavior the mod can
perform internally is exposed through one POST endpoint. Tests
drive the live game from outside; research questions become
test files; regressions become assertions that fail loudly.

Read [RESEARCH.md](RESEARCH.md) for the cross-project
methodology this enables. This doc covers the API surface.

## The envelope

```
POST 127.0.0.1:<port>/debug
Body:    { "op": "<name>", "args": { ... } }
Returns: { "ok": bool, "op": "<name>", "error": "...", "result": ..., "state": <Snapshot> }
```

Single endpoint. Every operation is identified by `op` name +
free-form `args` JSON. Every response carries:

- `ok`. Success flag.
- `op`. Echo of the requested op (or `<missing>` /
  `<parse-error>`).
- `error`. The error message on failure; otherwise empty.
- `result`. Op-specific payload on success.
- `state`. The **full game-state snapshot** the mod chose to
  expose, regardless of which op fired. Tests assert against
  the snapshot, not against `result`.

The "always return state" rule is load-bearing. It means the
test side never has to decide whether to call snapshot
separately; every interaction reads as "did X work, and what's
the world look like now."

## server::spawn

Mods start the server from their worker thread:

```rust
use ueforge::{server, Config};

server::spawn(
    Config {
        port: 17171,
        endpoint: "/debug",
        thread_name: "yourmod-debug-http",
    },
    |body| handle(body),                      // Vec<u8> result
    |msg| ueforge::log!("server: {}", msg),   // log sink
);
```

`spawn` runs `tiny_http::Server::http` on a named worker thread.
Every POST to `/debug` calls your `handle` closure with the
request body; whatever bytes you return become the response
body. JSON serialization is your call. Typically you build a
`OpResponse<Snapshot>` and `serde_json::to_vec` it.

The listener thread:
- Accepts only POST.
- Returns 405 for other methods.
- Returns 400 for malformed JSON.
- Reads body up to a fixed cap (1 MiB).
- Catches panics in `handle` so a buggy op doesn't take the
  listener down.

## OpResponse<S>

```rust
pub struct OpResponse<S: Serialize> {
    pub ok: bool,
    pub op: String,
    pub error: String,
    pub result: serde_json::Value,
    pub state: S,
}

impl<S: Serialize> OpResponse<S> {
    pub fn ok(op: &str, result: Value, state: S) -> Self;
    pub fn error(op: &str, error: String, state: S) -> Self;
    pub fn from_result(op: &str, r: Result<Value, String>, state: S) -> Self;
}

pub fn parse_request(body: &str) -> Result<(String, Value), String>;
```

`parse_request(body)` returns `(op, args)`. Use the convenience
`from_result` to wrap any `Result<Json, String>` into an
`OpResponse` with the right `ok`/`error` fields set.

## Builtin ops

ueforge ships generic ops that work on any UE5 game once the
runtime is initialized. Wire them via
`ueforge::ops::handle_builtin` in your dispatcher:

```rust
fn handle(body: &str) -> OpResponse<Snapshot> {
    let (op, args) = match parse_request(body) {
        Ok(v) => v,
        Err(e) => return OpResponse::error("<parse-error>", e, build_snapshot()),
    };

    // Try ueforge built-ins first.
    if let Some(result) = ueforge::ops::handle_builtin(&op, &args) {
        return OpResponse::from_result(&op, result, build_snapshot());
    }

    // Fall through to game-specific ops.
    let result = match op.as_str() {
        "snapshot" => Ok(Json::Null),
        "skill_spend" => op_skill_spend(&args),
        // ...
        other => Err(format!("unknown op '{}'", other)),
    };
    OpResponse::from_result(&op, result, build_snapshot())
}
```

### Generic primitives

| Op | Args | Returns |
|---|---|---|
| `snapshot` |. | `Null` (snapshot is in `state`) |
| `read_bytes` | `instance_selector`, `offset`, `length` | `{ bytes_hex, address, len }` |
| `write_bytes` | `instance_selector`, `offset`, `bytes_hex` | `{ written }` |
| `walk_class` | `class`, `max?`, `include_cdo?` | `{ instances: [{ address, name, full_name }] }` |
| `inspect_address` | `addr` | `{ class_name, properties: [{ name, offset, value }] }` |
| `fname_to_string` | `fname` | `{ string }` |
| `exec_call` | `class`, `function`, `instance_selector`, `parms_hex` | `{ parms_hex_after }` |

`exec_call` invokes any UFunction on any object with arbitrary
parm bytes. Replaces the temptation to add per-scenario
`simulate_*` ops. Tests build their own `#[repr(C)]` parm
struct, hex-encode it, send. Engine-mutated OUT params come
back in `parms_hex_after`.

### Memory tools

| Op | Args | Returns |
|---|---|---|
| `scan_memory` | `type`, `value` | `{ session_id, hits, total }` |
| `scan_rescan` | `session_id`, `mode`, `value?` | `{ hits, total }` |
| `scan_session` | `session_id` | `{ hits, total }` |
| `scan_close` | `session_id` | `{ closed }` |
| `freeze` | `selector`, `offset`, `type`, `value`, `hz?` | `{ id }` |
| `unfreeze` | `id` | `{ removed }` |
| `freeze_list` |. | `{ freezes: [...] }` |

See [memory-tools.md](memory-tools.md) for the full scanner /
freeze story.

### Win32 process probes

| Op | Args | Returns |
|---|---|---|
| `process_threads` |. | per-thread CPU + state |
| `process_cpu` |. | aggregate CPU metrics |
| `process_regions` |. | committed memory regions |
| `process_memory` |. | working set + private bytes |
| `sample_thread_modules` | `tid?`, `samples?` | per-instruction module hits |

See [memory-tools.md](memory-tools.md).

## Selector grammar

Many ops take an `instance_selector` arg naming a UObject.
ueforge resolves these via `selector::resolve_generic`:

| Form | Example | Meaning |
|---|---|---|
| `addr:<hex>` | `addr:0x1234ABCD` | raw object pointer |
| `class:<Name>` | `class:HealthComponent` | first instance of class |
| `first_class:<Name>` | `first_class:HealthComponent` | alias for above |
| `singleton:<Name>` | `singleton:HealthComponent` | the class default object (CDO) |
| game-specific | `live_player_hc` | game-defined shorthand |

Game-specific selectors are the game's escape hatch: the game
crate provides a `resolve` callback that handles names ueforge
doesn't know. g2rpg adds `live_player`, `live_player_hc`,
`live_player_cmc` for the player pawn / HealthComponent /
MovementComponent shortcuts.

```rust
// Game-side resolve hook (in your op dispatcher):
fn resolve_instance(selector: &str) -> Result<&'static UObject, String> {
    if let Some(obj) = ueforge::selector::resolve_generic(selector) {
        return Ok(obj);
    }
    match selector {
        "live_player" => find_live_player(),
        "live_player_hc" => find_live_player_hc(),
        // ...
        _ => Err(format!("unknown selector '{}'", selector)),
    }
}
```

## Api<S> test client

ueforge ships a test-side client over `ureq`:

```rust
use ueforge::client::Api;

let api: Api<Snapshot> = Api::connect();   // honors BBP_DEBUG_PORT env var

let snap: Snapshot = api.snapshot().player.hp;
let response = api.op("skill_spend", json!({"id": "attack_damage", "count": 1}));
api.op_unwrap("reload_slot", json!({}));
```

Methods:

```rust
impl<S: DeserializeOwned> Api<S> {
    pub fn connect() -> Option<Self>;  // reads $BBP_DEBUG_PORT or similar
    pub fn snapshot(&self) -> S;         // shorthand for op("snapshot", null)
    pub fn op(&self, name: &str, args: Value) -> OpResponse<S>;
    pub fn try_op(&self, name: &str, args: Value) -> Result<OpResponse<S>, String>;
    pub fn call_ufunction<T: AsBytes, R: FromBytes>(...) -> /* OUT params */;
}
```

`Api::connect()` returns None when the debug port env var is
unset (so `cargo test` stays green for CI / smoke checks). Tests
should early-return with a clear note instead of asserting:

```rust
#[test]
fn impact_resistance_does_not_block_bandages() {
    let Some(api) = Api::<Snapshot>::connect() else {
        eprintln!("BBP_DEBUG_PORT not set; skipping");
        return;
    };
    api.op("skill_spend", json!({"id": "impact_resistance", "count": 100}));
    /* ... */
}
```

Tests share global game state. Always run with
`--test-threads=1`.

## Test methodology

Read [RESEARCH.md](RESEARCH.md) for the full TDD loop. The
short version:

1. Phrase the user-observable expectation. "If I do X then Y
   must happen."
2. Add a snapshot field for Y if not already there.
3. Write a failing `tests/explore_<name>.rs` that drives X,
   asserts Y.
4. Probe through the endpoint to find what the game is doing.
5. Form a hypothesis the test can verify.
6. Implement the fix.
7. Test goes green. Land test + fix together.

Every bug is a missing test. The test goes in BEFORE the fix.

## Safety / production

The HTTP server binds 127.0.0.1 only, so it's not reachable from
the network. But anything else on the same host can hit it.
and ops like `write_bytes` can corrupt arbitrary game memory.
Don't ship the debug port enabled in a release build.

Bbp gates the port behind `settings.debug.http_port: Option<u16>`
(default `None`). Production users get the port off; dev /
research builds turn it on locally.

### Per-launch auth token

`server::Config::auth_token: Option<&'static str>`. When `Some(t)`,
every request must carry `X-Ueforge-Auth: <t>` or the listener
returns 401. When `None`, no auth (the historical default; safe
for closed-loop dev where tests are the only client).

Token generation is a consumer concern: typically
`format!("{:032x}", rand::random::<u128>())` at startup,
`Box::leak`-ed to satisfy `&'static str`, written to a file the
test client reads. The convenience builder is `Api::with_auth(t)`.

The header check uses a constant-time byte compare (`ct_eq`) so
there's no early-exit timing signal that would let a co-resident
process narrow the token byte-by-byte. Localhost weakens the
attacker model, but the fix is ~5 LoC. No excuse to skip.

### Body size cap

`MAX_BODY_BYTES = 1 MiB`. Reads use
`req.as_reader().take(cap + 1).read_to_end(&mut buf)`; if `buf`
exceeds the cap, the listener returns 413 (Payload Too Large).
Without the cap a misbehaving client could send 4 GB into
`read_to_string` and OOM the host process.

The cap is ~1000x the largest legitimate op payload we ship.
generous enough that no real op ever brushes it. Bump only if a
legitimate snapshot grows past 1 MiB; large dumps belong on a
separate streaming endpoint, not in a JSON body.

## Cross-references

- [RESEARCH.md](RESEARCH.md). TDD methodology
- [memory-tools.md](memory-tools.md). Scanner + freeze ops
- [pe-queue.md](pe-queue.md). Ops that need game-thread access
  enqueue jobs here
- [PERFORMANCE.md](PERFORMANCE.md). The listener doesn't
  belong on hot paths
