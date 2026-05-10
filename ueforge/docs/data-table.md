# Data tables

> **Authoritative on:** ueforge's UE5 `UDataTable` surface --
> `DataTableDef` + `DataTableRegistry` catalog, the
> `probe::discover_data_tables` bootstrap, `FieldTweak<T>`,
> `ClassFieldTweak<T>`, `find_by_short_name`, `iter_rows`, plus the
> timing rules that make data-table mutations actually propagate
> in-game.

## DataTableDef + DataTableRegistry (Phase 1)

```text
K8s slot: Def=DataTableDef, Registry=DataTableRegistry,
          Instance=live UDataTable + its RowMap rows,
          Controller=DataTableSnapshot::capture +
                     probe::discover_data_tables
```

A `UDataTable` + its row schema is its own first-class subject in
the workspace. Stacks, difficulty, and status effects are all
special cases of "typed-field operations on iterated objects";
`DataTableDef` captures the table itself so a new game's mod can
declare every interesting catalog once and reach EVERY field with
no further plumbing.

```rust
use ueforge::data_table::{DataTableDef, DataTableRegistry, RowField, RowSchema};

static DT_MATERIALS: DataTableDef = DataTableDef {
    id: "materials",
    table_name: "DT_Materials",
    row_struct: RowSchema {
        name: "FMaterialRow",
        fields: &[
            RowField { name: "MaxCanStack", offset: 0x48, element_size: 4 },
        ],
    },
};

pub static DATA_TABLES: DataTableRegistry =
    DataTableRegistry::new(&[&DT_MATERIALS]);
```

The Def is pure data; mirrors `StatusDef` / `StackDef`. The
registry is the slice-of-refs shape used by every Drop-having +
schema-style registry in the workspace (Status, Stack, Difficulty).

### The bootstrap loop

Discovery is the leverage point. For a brand-new UE5 game:

1. Launch the game with ueforge loaded. Call `discover_data_tables`
   (debug op). Get back JSON for every live `UDataTable` -- id,
   short name, row-struct name, every field's name + offset +
   element size.
2. Pick the table + field you want to tweak.
3. Declare one static `FieldTweak<T>` (or a `DataTableDef` catalog
   row when you want it browseable) and a slider.
4. Ship.

No SDK header dive per field. A game patch that shifts offsets is
caught at install time by the same discovery walk, because the
walk reads the live `FProperty` chain rather than baked offsets.

## discovery::run_at_load (the bootstrap)

Discovery lives in [`ueforge::discovery`](../src/discovery.rs):
ONE GObjects pass produces a cached snapshot of every live
`UDataTable`, `UClass`, and `UScriptStruct`. Mods call
`run_at_load()` from their `on_unreal_init` worker; the cache
backs every `discover_*` op and the future ImGui browser tab.

```rust
// In the game crate's on_unreal_init worker, after
// ue::platform::detect_and_init:
let _ = ueforge::discovery::run_at_load();
// logs e.g. "discovery: 412 data_tables, 28341 classes, 1893 structs"
```

No JSON files are written. The cache stays in-process; redirect a
curl if you want a file:

```sh
curl -s -X POST 127.0.0.1:17171/debug \
    -d '{"op":"discover_data_tables"}' > data_tables.json
```

Re-walk after content streams in:

```sh
curl -s -X POST 127.0.0.1:17171/debug \
    -d '{"op":"discover_data_tables","args":{"refresh":true}}'
```

`discover_classes` and `discover_structs` accept the same
`refresh` flag. Each returns the same JSON shape:

```json
{
  "data_tables": [
    {
      "id": "<short name lowercased>",
      "table_name": "DT_Materials",
      "full_path": "DataTable /Game/Items/DT_Materials.DT_Materials",
      "row_struct": {
        "name": "FMaterialRow",
        "path": "ScriptStruct /Game/.../MaterialRow.MaterialRow",
        "fields": [
          { "name": "MaxCanStack", "offset": 72, "element_size": 4 },
          ...
        ]
      }
    },
    ...
  ],
  "scanned_objects": 152341,
  "tables_found": 412
}
```

The walk reads the live `FProperty` chain (NOT baked SDK offsets),
so a game patch that shifts a field is caught here before any
tweak runs.

## Low-level walkers

`ueforge::ue::probe::describe_data_table(obj)` and
`walk_struct_fields(obj)` are the per-object descriptors the
discovery pass uses. They're pub so one-off scripts can build
custom dump shapes (filter by package, etc.) without re-walking
GObjects.

Cost of a full discovery pass: one GObjects iteration + a
`cached_native_properties` lookup per class / struct (cached
after first read) + a one-time FField walk per row struct. Run
from a worker thread; cold path. Subsequent `refresh` calls reuse
the property cache.

UE5 games use `UDataTable` for almost every catalog: items,
recipes, status effects, materials, weapons, perks, etc. Mods
that want to retune any of these mutate the data table at
runtime. ueforge ships the primitives + the timing doctrine.

## NamedFieldTweak<T> -- name-based writes (no offsets in code)

The `FieldTweak<T>` primitive below bakes the offset at declaration
time. For new-game bootstrap that's noise: you don't want every mod
to dump SDK headers and hand-type offsets. `NamedFieldTweak<T>` is
the same primitive, except the offset is resolved from the
in-memory discovery cache on first apply.

```rust
use ueforge::data_table::NamedFieldTweak;

static MAX_STACK: NamedFieldTweak<i32> =
    NamedFieldTweak::new("DT_Materials", "MaxCanStack");

// From on_unreal_init (after discovery::run_at_load):
MAX_STACK.apply(|v| v.saturating_mul(4), |v| v <= 1).ok();
```

If the table or field isn't in the cache yet (content streamed in
late), call `ueforge::discovery::refresh()` and try again. After
a game patch shifts an offset, the new offset is picked up on the
next discovery refresh -- no code change.

Vanilla-snapshot + idempotent re-apply semantics are inherited
verbatim from `FieldTweak<T>`.

## DataTable reads return copies

The single most important fact:

> `UDataTable::GetDataTableRow` (and the BP-callable
> `GetDataTableRowFromName`) return the row struct **by value**.
> Game code calls these and gets a snapshot. Pre-existing actors
> / widgets that already cached the row don't see the new value.

This means:

- **Mutate the DT BEFORE consumers cache the rows.** From
  `on_unreal_init`'s worker thread, before any UI or actor
  loads. Use `on_first_sight` (below) to wait for the DT to
  appear.
- **OR mutate AFTER and re-trigger the consumers.** If a UI
  caches the row, you have to reopen the UI to see the new
  value. Worse, if save data records a per-actor copy of the
  row, mutating doesn't help -- the saved copy wins.
- **OR hook the read** at the `GetDataTableRow` UFunction so
  every read sees your transform. Bulletproof but invasive.

Most "tweak-stack-size" / "tweak-drop-rate" mods get away with
option 1. Status-effect / damage-system mods often need option 3.

See [RESEARCH.md](RESEARCH.md) "Doctrine: status effects and
data tables" for the full pattern + g2rpg's bandage research as
the canonical example.

## find_by_short_name

```rust
pub fn find_by_short_name(name: &str) -> Option<&'static UObject>;
```

Walks GObjects for a non-CDO `UDataTable` instance whose short
name matches. Cold path; one full GObjects pass per call. Use
once at init to grab the table reference; cache the pointer
for subsequent operations.

```rust
let dt = ueforge::ue::datatable::find_by_short_name("DT_StatusEffects")
    .ok_or("DT not loaded yet")?;
```

## on_first_sight

```rust
pub fn on_first_sight<F>(name: &'static str, timeout: Duration, on_ready: F)
where F: FnOnce(&UObject) + Send + 'static;
```

Spawns a worker that polls for the table by name and runs
`on_ready` once. Game DTs typically load with the GameInstance,
shortly after `on_unreal_init` fires -- so polling for ~30s is
the safe default.

```rust
ueforge::ue::datatable::on_first_sight(
    "DT_Materials",
    Duration::from_secs(30),
    |dt| {
        // Mutate the DT here. Worker thread (not game thread).
    },
);
```

The worker exits after one successful run, or after `timeout`
elapses without finding the DT.

## iter_rows

```rust
pub unsafe fn iter_rows(table: &UObject) -> impl Iterator<Item = (u64, *const u8)>;
```

Iterate `(FName-as-u64, row_ptr)` pairs in the table's RowMap.
Free / unallocated slots are filtered out.

```rust
unsafe {
    for (fname_key, row_ptr) in iter_rows(dt) {
        // FName -> string for logging (cold path)
        let name = runtime().name_resolver.to_string(/* FName from u64 */);
        // Read fields at known offsets
        let value: f32 = (row_ptr.add(VALUE_OFFSET) as *const f32).read_unaligned();
        // ...
    }
}
```

## row_value_by_fname

```rust
pub unsafe fn row_value_by_fname(table: &UObject, row_name: FName)
    -> Option<*const u8>;
```

Direct lookup: given a row's FName, return the row pointer.
O(1) hashmap lookup via the underlying TMap -- much faster than
iterating + name-matching.

```rust
let row: *const u8 = unsafe {
    row_value_by_fname(dt, row_fname)?
};
```

## FieldTweak<T> -- per-row field write

The high-level API for "mutate this one field across every row
that matches a predicate":

```rust
use ueforge::ue::datatable::FieldTweak;

static MAX_STACK: FieldTweak<i32> = FieldTweak::new("DT_Materials", 0x48);

let stats = MAX_STACK.apply_when_ready(
    Duration::from_secs(30),     // wait for DT
    |vanilla| Some(vanilla * 4), // transform: 4x stack size
    |row_ptr| { /* skip_if predicate */ false },
);
```

`FieldTweak<T>::apply` walks every row, captures vanilla on
first sight, runs the transform, writes the result.
Idempotent: re-running with the same transform is a no-op
because vanilla is captured once and the captured value drives
the writes.

`apply_when_ready` is the spawn-and-wait variant -- the typical
init-time entry point.

```rust
impl<T: Copy + PartialEq + Send + 'static> FieldTweak<T> {
    pub const fn new(table_name: &'static str, offset: usize) -> Self;

    pub fn apply<F, S>(&self, transform: F, skip_if: S) -> Result<usize, String>
    where F: Fn(T) -> Option<T> + Send + 'static,
          S: Fn(*const u8) -> bool + Send + 'static;

    pub fn apply_to<F, S>(&self, table: &UObject, transform: F, skip_if: S)
        -> Result<usize, String>;

    pub fn apply_when_ready<F, S>(&'static self, timeout: Duration, transform: F, skip_if: S);

    pub fn vanilla_count(&self) -> usize;
    pub fn revert(&self) -> Result<usize, String>;
    pub fn table_name(&self) -> &'static str;
    pub fn offset(&self) -> usize;
}
```

`revert()` writes the captured vanilla back to every row -- for
"toggle this skill off" without restarting the game.

## ClassFieldTweak<T> -- live UObject sibling

```rust
use ueforge::ue::class_tweak::ClassFieldTweak;

static SLOTS: ClassFieldTweak<i32> =
    ClassFieldTweak::new("InventoryComponent", 0x01E0);

let stats = SLOTS.apply(
    |obj| obj.full_name().contains("BP_SurvivalPlayerCharacter"),
    |vanilla| if vanilla < 100 { Some(100) } else { None },
)?;
```

Same shape as `FieldTweak<T>` but for live UObjects (CDOs +
non-CDOs). Walks GObjects for instances of the named class,
filters by the predicate, captures vanilla, transforms, writes.

Use `ClassFieldTweak` when the field lives on a UObject (e.g.
inventory component, character pawn). Use `FieldTweak` when the
field lives on a DataTable row.

## Vanilla snapshot

Both tweaks capture per-row vanilla on first sight. The
captured map persists for life of process; subsequent calls to
`apply` use the captured baseline regardless of what the mod
has overwritten the field with.

This is the same shape as
[`VanillaCache<K, V>`](rpg.md#vanillacachek-v) used by the RPG
apply path -- both ride the "first-write-wins" pattern.

## Mutation timing rules

(From [RESEARCH.md](RESEARCH.md):)

| Scenario | Use |
|---|---|
| Tweak that should affect everything from this point on | `apply_when_ready` from `on_unreal_init`'s worker |
| Tweak that needs to affect actors/UI already loaded | Hook the read UFunction; transform per call |
| Status-effect-style row mutation | Find row by FName, mutate Value, call `CreateAndAddEffect` |
| Per-actor field write | `ClassFieldTweak` (DT-row sibling) |

If `apply_when_ready` looks right but in-game effect doesn't
propagate, you're seeing the cache problem. Switch to hook.

## DT-internal layout

```
UDataTable instance (game-specific class):
  +0x... RowMap : TMap<FName, RowStruct*>
```

The RowMap offset (`off::ROW_MAP`) is platform-stable across
UE5 builds. ueforge's `tmap::slots` knows how to walk it.

Each row is a `#[repr(C)]` struct whose layout is per-DT (the
DT references a `UScriptStruct` describing the row schema).
Field offsets are game-specific -- read them from the SDK
headers.

## Cross-references

- [ue-sdk.md](ue-sdk.md) -- TMap walker, FName resolver
- [RESEARCH.md](RESEARCH.md) -- mutation timing doctrine
- [rpg.md](rpg.md) -- VanillaCache (same first-write pattern)
- [PERFORMANCE.md](PERFORMANCE.md) -- DT mutation runs at init,
  not on hot paths
