# Data tables

> **Authoritative on:** ueforge's UE5 `UDataTable` mutation
> surface -- `FieldTweak<T>`, `ClassFieldTweak<T>`,
> `find_by_short_name`, `iter_rows`, plus the timing rules that
> make data-table mutations actually propagate in-game.

UE5 games use `UDataTable` for almost every catalog: items,
recipes, status effects, materials, weapons, perks, etc. Mods
that want to retune any of these mutate the data table at
runtime. ueforge ships the primitives + the timing doctrine.

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
