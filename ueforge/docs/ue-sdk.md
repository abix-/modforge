# UE SDK

> **Authoritative on:** how ueforge models UE5's UObject system,
> what types you use to read / write game memory, and the cached
> handles + typed offset wrappers that keep hot paths zero-alloc.

ueforge ships a minimal Unreal Engine SDK shim sufficient for
hooks, patches, and UFunction calls. It does NOT generate
per-class headers from a Dumper-7 / UE4SS dump -- that's the
job of the SDK dump itself, which lives next to your game's
install. We model only the engine-internal layout (UObject /
UClass / UFunction / FName / FString / TArray / TMap /
GObjects), and hand you typed wrappers for accessing fields at
known offsets.

## Runtime initialization

You call this **once** at the top of your worker thread, after
`ueforge::ue::platform::detect`:

```rust
use ueforge::ue::{init_runtime, platform, PlatformOffsets};

const STEAM: PlatformOffsets = PlatformOffsets { /* ... */ };

let image_base = platform::host_image_base();
let offsets = platform::detect(PLATFORMS).unwrap_or(&STEAM);
let _rt = unsafe { init_runtime(image_base, offsets) };
```

After this, every other ueforge function that reads game memory
works. Before this, they return `None` / errors with messages
like `"ueforge: ue runtime not initialized"`.

`init_runtime` is one-shot. Subsequent calls are ignored.

## UObject

`ueforge::ue::UObject` is a `#[repr(transparent)]` zero-sized
type representing a UObject pointer in game memory. You never
construct one; you receive `&UObject` from API calls and hand it
back.

Common methods:

```rust
impl UObject {
    pub fn class(&self) -> Option<&UClass>;       // +0x10 -> UClass*
    pub fn outer(&self) -> Option<&UObject>;      // +0x20 -> UObject*
    pub fn name(&self) -> String;                 // FName at +0x18 -> String
    pub fn full_name(&self) -> String;            // outer chain + name
    pub fn fname(&self) -> FName;                 // raw FName u64
    pub fn index(&self) -> i32;                   // GObjects array index
    pub fn is_a(&self, target: &UClass) -> bool;  // walks super chain
    pub fn is_default_object(&self) -> bool;      // CDO check
    pub fn as_ptr(&self) -> *const u8;
    pub fn as_mut_ptr(&self) -> *mut u8;

    pub unsafe fn read_field<T: Copy>(&self, offset: usize) -> T;
    pub unsafe fn write_field<T: Copy>(&self, offset: usize, value: T);
    pub unsafe fn field_ptr(&self, offset: usize) -> *mut u8;

    pub unsafe fn process_event(&self, func: &UFunction, parms: *mut c_void);
}
```

### Field access

For one-shot reads at known offsets:

```rust
unsafe { obj.read_field::<f32>(0x328) }      // raw read
unsafe { obj.write_field::<u32>(0xFC, mask) } // raw write
```

For declared offsets (best practice -- centralizes the offset +
type pair), use [`TypedField<T>`](#typedfield).

### Performance

`UObject::name` and `full_name` go through ueforge's
[`NameResolver`] cache (FName u64 -> String, capped by the
engine's name pool size). One String allocation per *unique*
FName ever seen, not per call. Still: avoid these on hot paths.
Use [`LazyFunctionPtr`](hooks.md#lazyfunctionptr) for hot-path
identity dispatch.

## UClass / UFunction

`UClass` extends `UObject` (we model the inheritance via
`as_object()`). `UFunction` is a UClass-shaped object too.

```rust
impl UClass {
    pub fn class_default_object(&self) -> Option<&UObject>;
    pub fn properties_size(&self) -> u32;        // bytes per instance
    pub fn super_class(&self) -> Option<&UClass>;
    pub fn get_function(&self, class_name: &str, fn_name: &str) -> Option<&UFunction>;
    pub fn iter_native_properties(&self) -> Vec<NativeProperty>;
    pub fn cached_native_properties(&self) -> Arc<[NativeProperty]>;
}

impl UFunction {
    pub fn as_object(&self) -> &UObject;
    pub fn function_flags(&self) -> u32;
    pub fn set_function_flags(&self, flags: u32);
}
```

`get_function(class_name, fn_name)` walks the class's Children
chain looking for a UFunction whose name matches and whose outer
chain contains the named class -- so you only get the function
if it's declared on the class you intended (not inherited from a
parent with the same function name).

`cached_native_properties` returns an `Arc<[NativeProperty]>`
keyed on the UClass pointer. First call walks the FField chain;
subsequent calls share the slice. This is what the Scanner UI
uses for `inspect_address`.

## ClassRef -- the canonical class handle

`ueforge::ue::ClassRef` is a `const`-friendly handle that
resolves a class lazily on first use and pointer-compares
forever after.

```rust
use ueforge::ue::ClassRef;

static HEALTH: ClassRef = ClassRef::new("HealthComponent");

if let Some(cls) = HEALTH.get() {
    // ... use cls ...
}
```

Internally: `OnceLock<usize>` holding the resolved
`*const UClass`. After first hit, every `get()` is one atomic
load + cast. Zero allocations, no hashmap lookup.

### ClassRef methods

```rust
impl ClassRef {
    pub const fn new(name: &'static str) -> Self;
    pub fn new_dynamic(name: &str) -> Self;       // leaks one heap copy
    pub fn name(&self) -> &'static str;
    pub fn is_cached(&self) -> bool;

    pub fn get(&self) -> Option<&'static UClass>;
    pub fn cdo(&self) -> Option<&'static UObject>;
    pub fn find_function(&self, fn_name: &str) -> Option<&'static UFunction>;

    // Walkers -- iterate matching instances.
    pub fn for_each_instance(&self, f: impl FnMut(&UObject)) -> usize;
    pub fn for_each_matching(&self, pred: impl FnMut(&UObject) -> bool, f: impl FnMut(&UObject)) -> usize;
    pub fn for_each_cdo_subclass(&self, f: impl FnMut(&UObject)) -> usize;
    pub fn for_each_cdo_matching(&self, pred: impl FnMut(&UObject) -> bool, f: impl FnMut(&UObject)) -> usize;
    pub fn for_each_any(&self, f: impl FnMut(&UObject)) -> usize;

    // Closure-takes-first variants.
    pub fn with_cdo<R>(&self, f: impl FnOnce(&UObject) -> R) -> Option<R>;
    pub fn with_first_instance<R>(&self, f: impl FnOnce(&UObject) -> R) -> Option<R>;
    pub fn find_instance(&self, pred: impl FnMut(&UObject) -> bool) -> Option<&'static UObject>;
}
```

### Walker semantics

The five walkers cover every UE5 enumeration pattern:

| Walker | Includes CDO? | Filter | Use |
|---|---|---|---|
| `for_each_instance` | no | none | live instances of class (most common) |
| `for_each_matching` | no | predicate | live instances narrowed by full_name |
| `for_each_cdo_subclass` | yes (only CDOs) | none | walk every CDO of class + subclasses |
| `for_each_cdo_matching` | yes (only CDOs) | predicate | per-player-class CDOs by name |
| `for_each_any` | yes (CDOs + instances) | none | singleton-style data assets where CDO IS data |

Each is `O(GObjects size)` per call. Cold-path acceptable.
For hot paths, cache the resolved `&UClass` once and walk
manually if you need control.

### Why ClassRef vs raw `find_class_fast`

Both work. `find_class_fast` has its own internal name cache, so
the warm path is already O(1). The win from ClassRef is:

- The cached pointer lives in a static you control, not in a
  global hashmap. One less indirection.
- The walker family methods are right there on the handle
  (`HEALTH.for_each_instance(...)` reads cleaner than the
  GObjectsView+filter dance).
- You can `.cdo()` / `.find_function()` ergonomically.

Use `ClassRef` for static-declared class names. Use
`find_class_fast` directly when the class name is computed at
runtime -- or use `ClassRef::new_dynamic` (which leaks one heap
copy of the name).

## TypedField<T>

`ueforge::ue::TypedField<T>` is a `const`-constructible
`(byte_offset, T)` pair. It documents a UObject field at the
declaration site so the offset and type travel together
everywhere.

```rust
use ueforge::ue::TypedField;

const MAX_HEALTH: TypedField<f32> = TypedField::at(0x0328);
const REQUIRED_FLAGS: TypedField<u32> = TypedField::at(0x00FC);

let v = unsafe { MAX_HEALTH.read(hc) };
unsafe { MAX_HEALTH.write(hc, v + 100.0) };
```

### Why this beats raw `field_ptr` casts

Compare:

```rust
// Without TypedField (every call site duplicates the type + cast):
unsafe { (obj.field_ptr(0x328) as *const f32).read_unaligned() }
unsafe { (obj.field_ptr(0x328) as *mut f32).write_unaligned(v) }

// With TypedField (offset + type declared once):
unsafe { MAX_HEALTH.read(hc) }
unsafe { MAX_HEALTH.write(hc, v) }
```

If you accidentally pass `TypedField<u32>` where `TypedField<f32>`
was expected, that's a type error at compile time. The raw cast
form would silently misinterpret the bytes.

### Component pointer follow

For fields that hold `*mut UObject` (component pointers like
`HealthComponent` at `+0x1340`):

```rust
const HEALTH_COMP: TypedField<*mut UObject> = TypedField::at(0x1340);

unsafe {
    if let Some(hc) = HEALTH_COMP.deref(player) {
        // ... read / write fields on hc ...
    }
}
```

`deref()` reads the pointer, returns `Option<&UObject>` (None if
null). Centralizes the `field_ptr + cast + read_unaligned +
as_ref` chain.

### Safety

`read` / `write` / `deref` / `ptr` are all `unsafe`. The
unsafety is the same as raw `field_ptr` -- the caller asserts
the offset + type pair matches the object's class. TypedField
makes this assertion easier to spot review-wise (the const
declaration is the one place to verify).

## ue::field -- untyped byte ops

When the field type or offset is decided at runtime (debug
endpoints reading many shapes through one path, dumpers, ad-hoc
read sites that don't deserve a `static TypedField<T>`), reach
for the safe-typed wrappers in `ueforge::ue::field`:

```rust
use ueforge::ue::field::{
    read_f32, write_f32, read_u32, write_u32,
    read_i32, write_i32, read_bool, write_bool,
    read_component_ptr,
};

let hp = read_f32(hc, 0x0328);
write_f32(hc, 0x0328, hp + 50.0);
let mask = read_u32(hc, 0x00FC);

// Follow a `*mut UObject` slot at a known offset.
if let Some(component) = read_component_ptr(player, 0x1340) {
    // ...
}
```

All functions are unaligned-safe. Pointer validity is the
caller's responsibility (same contract as TypedField). Prefer
TypedField for repeated load-bearing sites; prefer these for
runtime-decided / one-off reads.

## ue::actor -- controller + class-chain helpers

UE5 universals shared across game crates:

```rust
use ueforge::ue::actor::{
    class_chain_contains, controller_pawn, describe,
    A_CONTROLLER_PAWN_OFFSET,
};

if class_chain_contains(controller, "PlayerController") {
    // walks `obj.class()` + every super_class, depth-bounded
}

let pawn: Option<&UObject> = controller_pawn(controller);
// equivalent to: read_component_ptr(controller, A_CONTROLLER_PAWN_OFFSET)

let line = format!("{} killed by {}", describe(victim), describe(killer));
// "<name>(<class-name>)" or "<none>"
```

Used by g2rpg's kill hook to classify killers (player vs buggy
vs other) without duplicating the universal class-chain walk.

## GObjects

`ueforge::ue::GObjectsView` walks the engine's global UObject
array. You usually use `ClassRef::for_each_*` instead, but the
view is exposed for the rare case you need it directly.

```rust
let rt = ueforge::ue::runtime();
let view = unsafe {
    ueforge::ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets)
};
for obj in view.iter() {
    // ...
}
```

UE5 has two GObjects layouts: `FlatFixed` (older) and
`WrappedChunked` (newer). ueforge picks the right one from
`PlatformOffsets::g_objects_layout` and `view.iter()` works
either way.

`view.num()` is the live element count; mid-game on Grounded 2
that's ~150K. A full walk takes ~2-5ms. Don't do this per
frame. The walkers cache nothing internally -- repeated walks
are repeated work.

## find_class_fast

```rust
pub fn find_class_fast(name: &str) -> Option<&'static UClass>;
```

Walks GObjects looking for a UClass with the given short name,
filtering by metaclass to accept native `Class` and BP-generated
classes. Result is cached by name in a `RwLock<HashMap<String,
&'static UClass>>` -- subsequent calls hit the cache. Misses are
NOT cached, so a later call after the class loads still finds
it.

`ClassRef::get` is built on top; prefer `ClassRef` for static
declarations.

## FName

`ueforge::ue::FName` is the engine's interned-string handle.
Layout-stable u64 (`{u32 ComparisonIndex; u32 Number}`).

```rust
pub struct FName { /* opaque, layout = u64 */ }

impl FName {
    pub fn is_none(&self) -> bool;
    // No public constructor; you receive these from UObject::fname / parm structs.
}
```

To resolve an FName to a `String`:

```rust
let rt = ueforge::ue::runtime();
let s: String = rt.name_resolver.to_string(my_fname);
```

The resolver caches FName u64 -> String. First resolve allocates
one String and one FString buffer (the FString leak is
documented in [PERFORMANCE.md](PERFORMANCE.md); the cap is one
buffer per unique FName, not per call). Subsequent resolves
return the cached `String` without allocation.

`UObject::name`/`full_name` go through the resolver
automatically.

## TArray<T> and TMap

```rust
#[repr(C)]
pub struct TArray<T> {
    data: *mut T,
    num: i32,
    max: i32,
}

impl<T> TArray<T> {
    pub fn len(&self) -> usize;
    pub fn is_empty(&self) -> bool;
    pub unsafe fn iter(&self) -> impl Iterator<Item = &T>;
    pub unsafe fn as_slice(&self) -> &[T];
}
```

TArray layout is stable across UE5; ueforge's mirror is byte-
identical. Use it inside parm structs for UFunctions that take
or return arrays.

TMap is more complex (sparse + free-list); ueforge exposes
`tmap::slots(table, off::ROW_MAP)` for raw iteration and
specific helpers like `find_value_by_fname_key`. See
[data-table.md](data-table.md) for the high-level API
(`FieldTweak`, `iter_rows`, `find_by_short_name`).

## PlayerRef

`ueforge::ue::PlayerRef` -- canonical "find the player" surface
for UE5 mods.

```rust
use ueforge::ue::PlayerRef;

static PLAYER: PlayerRef = PlayerRef::new(
    "SurvivalCharacter",                  // base class
    Some("BP_SurvivalPlayerCharacter"),   // BP filter substring
);

PLAYER.for_each_cdo(|cdo| { /* CDO writes */ });
PLAYER.for_each_live(|pawn| { /* live writes */ });
PLAYER.with_first_live(|p| read_stats(p));
PLAYER.with_first_cdo(|c| read_baseline(c));
```

Configure once with `(base_class, Option<bp_filter>)`. The
filter is a substring of the Blueprint subclass's full_name
(e.g. exclude NPC SurvivalCharacters by requiring
"BP_SurvivalPlayerCharacter").

Methods cover the four standard enumeration patterns:

| Method | What |
|---|---|
| `for_each_cdo(f)` | Walk every CDO matching class + filter |
| `for_each_live(f)` | Walk every live (non-CDO) instance |
| `with_first_cdo(f)` | Pass first CDO to f |
| `with_first_live(f)` | Pass first live pawn to f |

Built on `ClassRef::for_each_cdo_matching` /
`for_each_matching`; this is the cohesive abstraction that
captures the (class, filter) pair as one entity.

## core_types

`ueforge::ue::core_types` mirrors stable UE5 POD layouts every
mod redefines locally. Re-exported at module root.

| Type | Layout | Use |
|---|---|---|
| `FGuid` | 4 × u32 (16 bytes) | save GUIDs, asset IDs |
| `FWeakObjectPtr` | 2 × i32 (8 bytes) | UE's "may-be-null" UObject reference |
| `FDataTableRowHandle` | (UDataTable*, FName u64) | UFunction parm for row-driven systems |
| `EStatusEffectValueType` | u8 enum (None=0, Add=1, Multiply=2) | how status-effect rows combine |

Layouts are tested for size (`size_of::<FGuid>() == 16` etc.) so
a UE layout change becomes a build-time test failure.

```rust
use ueforge::ue::{FGuid, FDataTableRowHandle};

let guid: FGuid = unsafe { obj.read_field(0x32C) };
if !guid.is_zero() {
    let key = guid.to_filename();
    // ...
}
```

## NativeProperty

```rust
pub struct NativeProperty {
    pub name: String,        // resolved property name
    pub offset: u32,         // byte offset within instance
    pub element_size: u32,   // size of one element (for arrays)
}
```

Returned from `UClass::iter_native_properties` and
`cached_native_properties`. The Scanner UI's `inspect_address`
op uses these to label memory contents.

## Probes

`ueforge::ue::probe` exposes diagnostic helpers that don't
belong on hot paths but are useful for `/debug` snapshot ops:

```rust
pub fn gobjects_population() -> serde_json::Value;
pub fn class_outer_samples(class_name: &str, max: usize) -> serde_json::Value;
```

`gobjects_population` returns counts per-metaclass (how many
UClasses, UFunctions, BlueprintGeneratedClasses, etc.).
`class_outer_samples` walks the first N instances of a named
class and reports their outer chain (useful for "where does this
get instantiated").

## Cross-references

- [hooks.md](hooks.md) -- ProcessEvent + identity dispatch on
  UFunctions you found via this SDK
- [data-table.md](data-table.md) -- DataTable mutation patterns
- [memory-tools.md](memory-tools.md) -- scanner / freeze /
  inspect_address built on the SDK
- [PERFORMANCE.md](PERFORMANCE.md) -- caching discipline
- `../README.md` -- bootstrapping a new game (which platform
  offsets you need to fill in)
