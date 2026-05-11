# Offline .uasset / .uexp parsing

> **Authoritative on:** `ueforge::uasset`. The offline UE5 cooked
> asset parser. The counterpart to [`ue-sdk.md`](ue-sdk.md), which
> models the engine's *runtime* memory layout. Use this module
> when you have raw `.uasset` / `.uexp` bytes and no engine.

Tools for inspecting cooked UE5 assets without a running game.
Useful for diffing third-party pak mods, reverse-engineering data
tables ahead of writing a runtime patch, or sanity-checking that a
mod actually touches the field its description claims.

## Library API

```rust
use ueforge::uasset::{
    extract_printable_strings, classify_ue_name, classify_ue_path,
    classify_prose, parse_name_table, find_int_property,
    DEFAULT_MIN_PRINTABLE_LEN,
};
```

### extract_printable_strings

```rust
pub fn extract_printable_strings(bytes: &[u8], min_len: usize) -> Vec<String>;
```

Scan-for-strings dump (`strings`-style). Cheap reconnaissance pass
over an unfamiliar asset. Runs of printable ASCII (`0x20..=0x7E`)
at least `min_len` long, deduped, first-seen order. Use
`DEFAULT_MIN_PRINTABLE_LEN` (4) unless you have a reason.

### Classifiers

```rust
pub fn classify_ue_name(s: &str) -> bool;   // BP_Foo_C, MaxHealth, ...
pub fn classify_ue_path(s: &str) -> bool;   // /Game/Blueprints/...
pub fn classify_prose(s: &str) -> bool;     // sentences with punctuation
```

Filter the strings into useful buckets.

### parse_name_table

```rust
pub fn parse_name_table(uasset: &[u8]) -> Vec<String>;
```

Walk a cooked legacy `.uasset` and return the FName table in
order. Layout:

```text
int32 length          (positive = ASCII, negative = UTF-16; length includes null)
bytes / wchars
uint16 + uint16       (hashes)
```

We don't parse the asset header to find the table; we scan for
the densest run of valid length-prefixed entries and return that
group's names. Currently ASCII only (UTF-16 names skipped).

### find_int_property

```rust
pub struct PropertyHit {
    pub offset: usize,
    pub size: u32,
    pub array_idx: u32,
    pub guid_flag: u8,
    pub value: i32,
}

pub fn find_int_property(
    uasset: &[u8],
    uexp: &[u8],
    property_name: &str,
) -> Result<Vec<PropertyHit>, String>;
```

Search a cooked `.uexp` for every IntProperty tag carrying the
named property and decode the i32 value. Returns one
`PropertyHit` per occurrence.

Cooked property tag layout:

```text
u32 name_idx; u32 name_num;       // FName: target property
u32 type_idx; u32 type_num;       // FName: "IntProperty"
u32 size; u32 array_idx;
u8  has_property_guid;
<value bytes>
```

For IntProperty, the value is `i32` immediately after the GUID
flag (or after a 16-byte GUID when guid_flag is 1).

## CLI binaries

ueforge ships two thin `[[bin]]` wrappers for shell use:

```sh
cargo run -p ueforge --bin dump-strings -- <file> [file ...]
cargo run -p ueforge --bin read-property -- <uasset> <uexp> [property=DefaultMaxSize]
```

Built into `target/release/dump-strings.exe` /
`target/release/read-property.exe` after a release build.

`dump-strings` reads each file, extracts printable strings,
buckets by classifier (UE name / UE path / prose / other), prints
each bucket.

`read-property` parses the `.uasset` for the FName table, finds
the index of `[property]`, scans the `.uexp` for IntProperty tags
matching that index, prints `(offset, size, arr_idx, guid_flag,
value)` per hit.

## Limitations

- Targets UE 5.4+ legacy cooked format as produced by
  `retoc to-legacy`. Unwrapping IoStore containers
  (`.utoc`/`.ucas`) needs `retoc to-legacy` first; this module
  does not parse the IoStore wire format directly.
- IntProperty only. Float/Bool/Name/Object property variants
  would each need a separate decoder; not implemented.
- ASCII names only in `parse_name_table`. UTF-16 names are
  skipped silently.

## Worked examples

The Grounded 2 mod's
[`grounded2-rpg/docs/inspection.md`](../../grounded2-rpg/docs/inspection.md)
walks two real worked examples (Player Tweaks, Bigger Backpack)
using these tools end-to-end. Pak unpack, FName table walk,
property tag scan, asset diff. Recommended reading for anyone
about to investigate an unfamiliar UE5 mod.

## Cross-references

- [ue-sdk.md](ue-sdk.md). The runtime counterpart (same
  concepts, but for live UObjects in a running game)
- [RESEARCH.md](RESEARCH.md). TDD investigation methodology
- [data-table.md](data-table.md). Runtime DataTable mutation
  (the runtime counterpart to inspecting cooked DataTable rows)
