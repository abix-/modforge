# Op registry

> Authoritative on the `OpDef` shape, dispatch rules, and
> auto-generated `list_ops` / `list_selectors` ops both
> frameworks ship.

## OpDef

```rust
pub struct OpDef {
    pub name: &'static str,    // exact-match dispatch key
    pub summary: &'static str, // human-readable, surfaced in list_ops
    pub args: &'static str,    // free-form args spec, e.g. "{slot: str, count?: u32}"
    pub handler: OpHandler,    // Arc<dyn Fn(&Json) -> Result<Json, String> + Send + Sync>
}

pub type OpHandler = std::sync::Arc<dyn Fn(&Json) -> Result<Json, String> + Send + Sync>;
```

Lives in `modforge::ops`. Both frameworks use it directly.

## OpRegistry

`OpRegistry` is a `parking_lot::Mutex<Vec<OpDef>>`. Populated
at worker init via `register(OpDef)`. Each framework has a
singleton `OP_REGISTRY: OpRegistry`. Game mods also register
their game-specific ops against the same singleton.

Dispatch:

```rust
OP_REGISTRY.dispatch(name, args) -> Option<Result<Json, String>>
```

- `None`: no op with that name was registered. Caller falls
  through (the embedding crate may have additional dispatch
  paths, though the registry pattern is preferred).
- `Some(Ok(result))`: success; `result` is the per-op payload.
- `Some(Err(msg))`: handler returned an error.

The embedding crate wraps `dispatch` in the envelope:

```rust
let result = OP_REGISTRY.dispatch(&op, &args)
    .unwrap_or_else(|| Err(format!("unknown op '{}'", op)));
OpResponse::from_result(&op, result, build_snapshot())
```

## list_ops (auto-generated)

`POST /op {"op":"list_ops"}` returns every registered op, its
summary, and its args spec. Auto-generated; no manual list to
maintain.

```json
{
  "ops": [
    { "name": "ping", "summary": "...", "args": "" },
    { "name": "snapshot", "summary": "...", "args": "" },
    { "name": "walk_class", "summary": "...", "args": "{class: str}" },
    ...
  ]
}
```

## list_selectors (auto-generated)

Same pattern for the `SelectorRegistry`:

```json
{
  "selectors": [
    { "prefix": "addr:", "summary": "raw object handle" },
    { "prefix": "class:", "summary": "first live instance of class" },
    ...
  ]
}
```

## Telemetry

Each op records `last_called_ms`, `total_calls`, `total_errors`
in modforge::counters. `POST /op {"op":"op_metrics"}` returns
the full table.
