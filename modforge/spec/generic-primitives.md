# Generic primitives

> The op-name surface every framework ships. ueforge and
> unityforge both implement these ops with identical envelope
> shapes; the implementations differ (UE walks UObject; Unity
> walks managed reflection) but the wire contract is the same.

## Universal

| Op | Args | Returns |
|---|---|---|
| `ping` | none | `{ pong: true }` |
| `snapshot` | none | `null` (snapshot is in `state`) |
| `list_ops` | none | `{ ops: [{name, summary, args}, ...] }` |
| `list_selectors` | none | `{ selectors: [{prefix, summary}, ...] }` |
| `op_metrics` | none | `{ entries: [{name, total_calls, total_errors, last_called_ms}, ...] }` |

## Object inspection

| Op | Args | Returns |
|---|---|---|
| `walk_class` | `{ class: str, max?: u32, include_cdo?: bool }` | `{ instances: [{ address, name, full_name }] }` |
| `inspect_address` | `{ addr: str }` | `{ class_name, properties: [{ name, offset?, value }] }` |
| `list_singletons` | none | `{ singletons: [{ name, address, kind }] }` |

`address` is an opaque integer handle. The same `addr:<integer>`
selector resolves back to the object.

## Field / method access

| Op | Args | Returns |
|---|---|---|
| `read_field` | `{ selector: str, field: str }` | `{ value, type }` |
| `write_field` | `{ selector: str, field: str, value }` | `{ written: true }` |
| `invoke_method` | `{ selector: str, method: str, args?: array }` | `{ result }` |

ueforge's older `read_bytes` / `write_bytes` / `exec_call`
primitives accept the same selectors and remain available
under those names for raw-memory ops; `read_field` /
`write_field` / `invoke_method` are the higher-level Unity-
friendly variants.

## Memory scanner

| Op | Args | Returns |
|---|---|---|
| `scan_memory` | `{ type: "f32" | "i32" | ..., value }` | `{ session_id, hits, total }` |
| `scan_rescan` | `{ session_id, mode, value? }` | `{ hits, total }` |
| `scan_session` | `{ session_id }` | `{ hits, total }` |
| `scan_close` | `{ session_id }` | `{ closed: true }` |
| `scan_cancel` | none | `{ cancelled: true }` |
| `freeze` | `{ selector, offset?, field?, type, value, hz?: u32 }` | `{ id }` |
| `unfreeze` | `{ id }` | `{ removed: true }` |
| `freeze_list` | none | `{ freezes: [...] }` |

Both frameworks expose these against the running process
memory via `modforge::scanner` + `modforge::winproc`.

## Op envelope returns full state

Every response includes the framework's `state` snapshot blob
regardless of which op fired. Tests assert against snapshot,
not per-op result. See `op-envelope.json`.
