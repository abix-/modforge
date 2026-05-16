# Target Registry. Extend `sleuth` into a declarative resolver

> Promote `modforge::patterns::sleuth::Target` from a transient
> argument-struct into a persistent declarative registry of every
> address a mod resolves. Caching, validators, hint-RVA sanity
> gates layered on top of the already-shipped scanner. Replaces
> each consumer mod's hand-rolled `targets::resolve::*` family.

**Status 2026-05-16: SHIPPED.** All architecture phases (B1, B3,
B5, B6) complete. horsey-mod and grounded2-mod both adopt the
pattern. The legacy `pub mod resolve` block in horsey-mod is
deleted. The remaining work (per-target sig tuning) is data
authorship, not architecture; it lands per-batch with live-game
verification. See the workspace `docs/todo.md` P0 entry for the
phase-by-phase status with commits.

## Why

Today every modforge consumer (horsey-mod, and any future
grounded2-mod / schedule1 / outworld-station-mod) hand-rolls its
own `src/targets.rs` containing:

- ~80 hardcoded `pub const FOO: usize = 0x140...;` RVAs.
- ~30 hand-written `pub fn foo() -> usize { ... }` resolver
  functions, each with its own caching, fallback, and validation
  logic.
- ~10 hand-written R2/R3/R4 integration tests asserting each
  resolver matches its hardcoded counterpart.

For the second game we mod, an author recreates all of this from
scratch. The R2/R3/R4 testing scaffolding gets re-typed. The
0x1000-byte sanity gate gets re-implemented. Plausibility
validators (vtable equality, heap-shape check) get duplicated.
None of this is game-specific. The shapes are universal; only
the data differs.

## What's already there (don't reinvent)

`modforge::patterns::sleuth` already ships these:

```rust
pub struct Target<'a> {
    pub name: &'a str,
    pub sigs: &'a [&'a str],
}

pub struct Resolution {
    pub by_name: HashMap<String, Option<usize>>,
}

pub fn resolve_all(targets: &[Target<'_>]) -> Result<Resolution>;
pub fn scan_all_matches(sig: &str) -> Result<Vec<usize>>;
pub fn scan_data_matches(sig: &str) -> Result<Vec<usize>>;
pub fn scan_rdata_matches(sig: &str) -> Result<Vec<usize>>;
```

`Target` is the proto-Def. `Resolution` is the proto-Instance.
`resolve_all` is the proto-Controller. They were built transient
(constructed per call, no caching, no validators).

**This design extends those types in place.** Nothing new gets
created. `sleuth::Target` grows new fields, gains a `'static`
form, and gets a caching `Resolver` controller alongside the
existing one-shot `resolve_all`.

## CRD shape (after extension)

Follows [`def-registry.md`](def-registry.md). The four roles map
to existing types:

| Role | Existing | After extension |
|---|---|---|
| **Def** | `sleuth::Target<'a>` (transient `{name, sigs}`) | `sleuth::TargetDef` (`'static`, adds `kind`, `hint_rva`, `validators`) |
| **Registry** | (none; callers built `Vec<Target>` ad hoc) | `sleuth::TargetRegistry { name, entries: &'static [&'static TargetDef] }` |
| **Instance** | `sleuth::Resolution` (one-shot HashMap) | `sleuth::ResolvedTarget` cached per-entry in a `Resolver` |
| **Controller** | `sleuth::resolve_all` (transient pass) | `sleuth::Resolver` (persistent, caches, runs validators); delegates the scan to `resolve_all` internally |

K8s slot:

```
// K8s slot: Def=sleuth::TargetDef, Registry=TARGET_REGISTRY,
//           Instance=Resolver.cache, Controller=Resolver::resolve_all
```

## Extension to `sleuth::Target`

Today:

```rust
pub struct Target<'a> {
    pub name: &'a str,
    pub sigs: &'a [&'a str],
}
```

After (renamed to `TargetDef` to match the CRD convention):

```rust
pub struct TargetDef {
    pub name: &'static str,
    pub candidates: &'static [Candidate],
    pub kind: TargetKind,
    pub hint_rva: Option<u64>,
    pub hint_tolerance: u64,
    pub validators: &'static [&'static dyn Validator],
}

pub struct Candidate {
    pub sig: &'static str,
    pub recipe: Recipe,
}

pub enum TargetKind {
    FunctionEntry { signature: Option<&'static crate::vanilla::Signature> },
    DataGlobal,
    FieldOffset { containing_fn: &'static str },
}

pub enum Recipe {
    MatchIsAddress,
    DecodeRipDisp { disp_off: u8, instr_len: u8 },
    DecodeImm { imm_off: u8, imm_size: u8 },
    HistogramDisp { window: u32, predicate: HistPredicate },
}
```

The existing `Target<'a>` stays for callers that want one-shot
resolution without building a registry (today's idiom in horsey-mod's
existing resolver functions). Internally, the `TargetDef` -> raw-sig
conversion happens once and feeds `resolve_all` unchanged.

Backward compat is preserved: `resolve_all(&[Target { name, sigs }])`
still works. `TargetDef` is the new persistent shape.

## Validators

Built-in, declared as unit structs implementing `Validator`:

```rust
pub trait Validator: Sync {
    fn check(&self, addr: u64, ctx: &ValidationCtx) -> Result<(), String>;
}

pub struct HeapShape;            // 0x10000 <= addr <= 0x7fff_ffff_ffff && aligned
pub struct InImage;              // image_base <= addr < image_base + 16 MiB
pub struct VtableAtRva(pub u64); // *(addr) == image_base + rva
pub struct FieldInRange { pub off: usize, pub lo: i64, pub hi: i64 }
pub struct NestedPtrReadable { pub off: usize }
pub struct WithinHintTolerance;  // auto-injected when TargetDef.hint_rva is set
```

Each is `&'static Self` (returned via a `OnceLock` constructor)
so the slice `validators: &'static [&'static dyn Validator]`
const-evaluates. Consumer mods with a custom check write one
struct + impl and use it like the built-ins.

This closes the [HLT-3 / HLT-4 work items](../../horsey-mod/docs/PRIOR-ART-HorseyLiveTweaks.md#work-items-derived-from-this-pass)
as a side effect: every resolver gains best-practice validation
automatically.

## TargetRegistry

```rust
pub struct TargetRegistry {
    pub name: &'static str,        // "horsey-mod", "grounded2-mod"
    pub entries: &'static [&'static TargetDef],
}

impl TargetRegistry {
    pub const fn new(name: &'static str, entries: &'static [&'static TargetDef]) -> Self;
    pub fn def(&self, key: &str) -> Option<&'static TargetDef>;
    pub fn iter(&self) -> impl Iterator<Item = &'static TargetDef>;
}
```

Per-game declaration (horsey-mod example):

```rust
// horsey-mod/src/targets/registry.rs
use modforge::patterns::sleuth::{TargetDef, TargetKind, TargetRegistry,
    Candidate, Recipe, validators::InImage};

static GAMESTATE_PTR: TargetDef = TargetDef {
    name: "GAMESTATE_PTR",
    kind: TargetKind::DataGlobal,
    candidates: &[
        // First candidate: HLT's anchor on the constructor's slot store.
        Candidate {
            sig: "48 89 1D ?? ?? ?? ?? 48 89 BB 70 02 00 00",
            recipe: Recipe::DecodeRipDisp { disp_off: 3, instr_len: 7 },
        },
        // Second candidate: our existing cheat-money anchor.
        Candidate {
            sig: "81 ?? ?? ?? ?? ?? e8 03 00 00",
            recipe: Recipe::DecodeRipDisp { disp_off: 2, instr_len: 6 },
        },
    ],
    hint_rva: Some(0x1403fb0d8),
    hint_tolerance: 0x1000,
    validators: &[&InImage],
};

static APPLY_GENE_TO_HORSE: TargetDef = TargetDef {
    name: "APPLY_GENE_TO_HORSE",
    kind: TargetKind::FunctionEntry { signature: None },
    candidates: &[Candidate {
        sig: "48 89 5C 24 ?? 48 89 6C 24 ??",
        recipe: Recipe::MatchIsAddress,
    }],
    hint_rva: Some(0x14009f670),
    hint_tolerance: 0x1000,
    validators: &[&InImage],
};

pub static HORSEY_TARGETS: TargetRegistry = TargetRegistry::new(
    "horsey-mod",
    &[&GAMESTATE_PTR, &APPLY_GENE_TO_HORSE, /* ... */],
);
```

## Resolver (Controller)

```rust
pub struct Resolver<'r> {
    registry: &'r TargetRegistry,
    cache: OnceLock<HashMap<&'static str, ResolvedTarget>>,
    image_base: u64,
}

pub struct ResolvedTarget {
    pub def: &'static TargetDef,
    pub addr: Option<u64>,        // None when no candidate resolved
    pub candidate_idx: Option<usize>,  // which sig won
    pub validation_log: Vec<String>,    // validators that ran + their verdicts
}

impl<'r> Resolver<'r> {
    pub fn new(registry: &'r TargetRegistry) -> Self;
    pub fn resolve_all(&self) -> &HashMap<&'static str, ResolvedTarget>;
    pub fn resolve(&self, name: &str) -> Option<u64>;
    pub fn diagnostic(&self) -> serde_json::Value;
}
```

Internally `Resolver::resolve_all` builds a `Vec<sleuth::Target>`
from the registry's `TargetDef` entries and delegates to the
existing `sleuth::resolve_all` for the actual SIMD scan. Then it
runs each entry's validators on the result and records the
verdict in `ResolvedTarget.validation_log`. Caches into the
`OnceLock`; subsequent calls are free.

The scanner machinery doesn't get duplicated. The registry
layer is pure declarative-data + cache + validator-runner on top
of what's already shipped.

Consumers replace today's

```rust
crate::targets::resolve::gamestate_ptr()
```

with

```rust
crate::targets::REGISTRY.resolver().resolve("GAMESTATE_PTR")
```

`REGISTRY.resolver()` returns a per-process singleton bound to
the registry. Same caching semantics as the existing
`OnceLock` pattern in `targets::resolve::*`.

## What this replaces

Concrete mapping from today's horsey-mod code to the registry
model. Each row is something currently hand-rolled in horsey-mod
that becomes data after migration.

| Today | After migration |
|---|---|
| `pub const GAMESTATE_PTR: usize = 0x1403fb0d8;` | `static GAMESTATE_PTR: TargetDef { hint_rva: Some(0x1403fb0d8), ... }` |
| `pub fn gamestate_ptr() -> Option<usize> { /* 60 LOC */ }` | first candidate in `GAMESTATE_PTR.candidates` |
| Hand-rolled `OnceLock<usize>` cache per resolver | one `Resolver.cache` for the whole registry |
| Ad-hoc 0x1000-byte sanity gate inside `gamestate_ptr` | `hint_tolerance: 0x1000` on the Def |
| `r2_function_resolvers.rs` | parameterized over `TargetRegistry`; loops over `entries` |
| `r3_gamestate_resolves.rs` | same: drops out as one row in the generic R-tier test |
| `r4_field_offsets.rs` | same |
| `targets.resolve.field_offsets` HTTP cmdlet | replaced by `targets.resolver.diagnostic` (registry-driven) |

Approximate LOC count for horsey-mod after migration: today's
`src/targets.rs` is ~2400 LOC; the registry version drops to
~600 LOC of declarative `TargetDef` entries plus the imports.
The 30 hand-rolled resolver functions disappear into 4 Recipe
variants in `sleuth`.

## Shared testing surface

The biggest payoff. Today every consumer mod re-writes:

- `r2_function_resolvers.rs` (table-driven over an inline target list)
- `r3_*_resolves.rs` (one per global)
- `r4_field_offsets.rs` (walks the `targets.resolve.field_offsets`
  op response and asserts each resolved == hardcoded)

After migration, these become THREE modforge tests parameterized
over a `TargetRegistry`:

```rust
// modforge/tests/registry_resolves.rs
#[test]
fn every_target_resolves_against_image() {
    let game = launch();
    let resolver = sleuth::Resolver::new(&consumer::TARGETS);
    for def in consumer::TARGETS.iter() {
        let r = resolver.resolve_full(def.name);
        if let Some(hint) = def.hint_rva {
            assert!(r.addr.is_some(),
                "{}: no candidate resolved; hint=0x{hint:x}", def.name);
        }
    }
}

#[test]
fn every_target_passes_validators() { /* ... */ }

#[test]
fn every_field_offset_matches_hint() { /* exact-match contract */ }
```

`consumer::TARGETS` is a `TargetRegistry` the consumer mod
exports. The same three tests run against horsey-mod, grounded2-mod,
schedule1, etc.

Plus a `Resolver::diagnostic()` JSON view for the HTTP control
plane:

```
GET /op targets.resolver.diagnostic
{
  "registry": "horsey-mod",
  "entries": [
    {"name": "GAMESTATE_PTR", "resolved": "0x1403fb0d8", "candidate": 0,
     "hint": "0x1403fb0d8", "delta": 0, "validators_run": ["InImage"]},
    ...
  ]
}
```

A single shared HTTP op contract replaces today's per-game
`targets.resolve.*` family.

## Composition with the other primitives

```
modforge::patterns::sleuth   <- scanner + Target/Resolution (shipped) + TargetDef/Resolver (extension, this doc)
modforge::vanilla            <- invoke vanilla functions (peer; see vanilla-invoke.md)
modforge::seh                <- fault-safe wrapper (shipped)
modforge::hook               <- intercept vanilla calls (shipped)
```

The `kind: TargetKind::FunctionEntry { signature }` field is
the seam between target-registry and vanilla-invoke. When a
mod registers a function entry WITH a signature, it becomes
invokable via `modforge::vanilla::Invoker::call_safe(name, args)`.
Without a signature, the entry is still resolvable (for hooks or
plain detours) but not invokable.

Once the registry is the single source of truth for "where is
that vanilla function?", every `seh::call` site references it,
every `hook::install` site references it, every
`vanilla::Invoker::call` references it. A build update that
moves a function is one re-resolve away from being absorbed.

## Composition with patternsleuth

Already there. Recipes route through `sleuth::scan_all_matches` /
`scan_data_matches` / `scan_rdata_matches` exactly as today's
resolvers do. The registry doesn't reinvent the scanner. It
declares "here are the sigs, here's how to decode the operand"
as data; sleuth's existing internals do the work.

## Migration plan

Doing this without breaking horsey-mod is straightforward
because the registry extension ships alongside today's
`targets::resolve::*`. Six independent phases:

1. **Phase 1: Extend `sleuth` in place.** Add `TargetDef`,
   `TargetRegistry`, `Resolver`, `ResolvedTarget`, the 4
   `Recipe` variants, and 6 built-in validators to
   `modforge/src/patterns/sleuth.rs` (or a sibling
   `sleuth/registry.rs` submodule if the file grows). Unit
   tests per validator and per Recipe decoder. ~200-300 LOC
   of additions to an existing module; ZERO consumer changes.

2. **Phase 2: Build the horsey-mod registry beside the existing
   resolvers.** New file `horsey-mod/src/targets/registry.rs`
   declares every existing target as a `TargetDef` with the
   sigs and hint RVAs that already work. Existing
   `targets::resolve::*` functions remain. A new integration
   test asserts `Resolver::resolve_all` agrees with every
   existing resolver byte-for-byte. Catches drift before the
   legacy code gets deleted. ~400 LOC of data + parity tests.

3. **Phase 3: Land the shared R-tier tests in modforge.** Three
   tests in `modforge/tests/registry_*.rs` parameterized over a
   `TargetRegistry`. horsey-mod's `r2_*` / `r3_*` / `r4_*` tests
   call into them. The legacy table-driven horsey tests become
   thin wrappers (or get deleted entirely once the modforge
   tests cover the contract).

4. **Phase 4: Migrate horsey-mod call sites one batch at a time.**
   Replace `crate::targets::gs_offset::money()` etc. with
   `REGISTRY.resolver().resolve("GAMESTATE_MONEY")`. Each batch
   is reviewable, the byte-equality test in Phase 2 catches
   regressions. ~1 day of grind across the 80 RVAs + 30
   resolvers.

5. **Phase 5: Delete the legacy `targets::resolve::*` family.**
   Once every call site is on the registry and Phase 2's parity
   test still passes, the old code goes. `src/targets.rs` drops
   to ~600 LOC of pure `TargetDef` data.

6. **Phase 6: Cross-game adoption proof.** When grounded2-mod
   (or schedule1) adopts the registry, they declare their own
   `TargetRegistry` and inherit modforge's R-tier test suite
   for free. The DoD item from the workspace todo ("one
   additional consumer mod adopts at least one primitive")
   lands as part of this phase.

Each phase is independently shippable. No big-bang cutover.

## Open questions

- **Validator type erasure**. `&'static [&'static dyn Validator]`
  works but requires every Validator impl to expose a `&'static
  Self` via a `OnceLock` constructor. A simpler approach is a
  closed enum (`Validator::HeapShape`, `Validator::VtableAtRva(u64)`,
  ...) which loses extensibility but const-evaluates cleanly.
  Closed enum is probably right for the first cut; consumers
  rarely need custom validators.

- **Recipe extensibility**. Same question. A closed `enum Recipe`
  is simpler; a `trait` allows future Recipe types without
  touching modforge. Start closed.

- **Multi-result candidates**. Some sigs match dozens of times
  and the resolver picks the modal hit (today's
  `decode_imm_in_window`'s histogram-top behavior). The
  `HistogramDisp` Recipe handles this, but the predicate type
  (`HistPredicate`) needs to be either a closed enum or a
  trait. Closed enum for now, with variants for the predicates
  we already use (`disp_in_range`, `delta_to_neighbor`, etc.).

- **Cross-validator dependencies**. Some validators want to
  read a sibling target's address (`VtableAtRva` needs
  `image_base`; a "must be near GAMESTATE_PTR" check needs the
  GAMESTATE_PTR resolution to have run first). The Controller
  resolves targets in registry order; document that order
  matters and offer a `depends_on: &'static [&'static str]`
  field on `TargetDef` if topological resolution becomes
  necessary. Not for Phase 1.

- **Hot-reload semantics**. When a build updates and the
  resolver re-runs, do we invalidate every consumer's cached
  resolution? Today the cache is per-process and re-attach
  fixes it. Probably keep that model; add `Resolver::reset` for
  programmatic invalidation.

- **`unityforge` and `ueforge` consumers**. Their address-resolution
  story is different (they have managed runtimes, not raw PE
  scanning). The registry pattern still applies but the
  Recipes are different (`UEObjectByName`, `MonoTypeByName`).
  Out of scope for this doc; design a parallel
  `ObjectRegistry` when those crates need it. The CRD shape
  carries over cleanly.

## What this does NOT solve

- **Authoring signatures.** The registry consumes sigs; it does
  not generate them. Sig authoring is the
  `modforge::research`-driven workflow documented in
  [`../../horsey-mod/docs/ADDRESS-RESOLUTION.md`](../../horsey-mod/docs/ADDRESS-RESOLUTION.md).
  After the registry lands, sig-authoring sessions still happen
  in research mode; the output is one new `TargetDef`.

- **Detecting that a build moved a function entirely.** A target
  whose every candidate misses with no hint-rva fallback is
  reported `addr: None`. Consumers decide what to do. No magic
  re-derivation; that's R5 territory (auto-decomp on detected
  build change), still future work.

- **Game-specific data shape.** What a target IS (a function, a
  data global, a horse-struct field) is per-game. The registry
  is a uniform shape for declaring them, not a universal data
  model.

## Acceptance criteria

The registry extension is "done" when:

1. `modforge::patterns::sleuth` exposes `TargetDef`,
   `TargetRegistry`, `Resolver`, `ResolvedTarget`, 6 built-in
   validators, 4 Recipe variants. The existing
   `Target`/`Resolution`/`resolve_all` API is unchanged; the
   new types coexist. ~30 unit tests pass in modforge.
2. `horsey-mod/src/targets/registry.rs` declares every existing
   target as a `TargetDef`. The parity test from Phase 2 passes.
3. `modforge/tests/registry_*.rs` provides the three shared R-tier
   tests. horsey-mod's `r2_*` / `r4_*` consume them (or get
   deleted once the contract is covered).
4. At least one additional consumer mod (grounded2-mod most
   likely) has its own `TargetRegistry` for at least one target,
   to prove the abstraction works cross-game. This is the DoD
   item from the workspace `docs/todo.md` for the testkit
   extraction; the registry is its natural home.
5. `horsey-mod/src/targets.rs` legacy resolver code deleted; the
   file is pure `TargetDef` data.
6. `modforge/docs/target-registry.md` (this doc) updated to
   reflect the shipped API rather than the proposed one.

## Naming follow-up

Per [`naming.md`](naming.md), every modforge subject has one
canonical role suffix. The naming here:

- `TargetDef` (the CRD; supersedes the transient `Target<'a>`)
- `TargetRegistry` (the collection)
- `Resolver` (the controller; named for what it does, not
  `TargetController`, because the existing `targets::resolve::*`
  vocabulary in horsey-mod is "resolve")
- `ResolvedTarget` (the instance)

The pre-existing `Target<'a>` and `Resolution` types stay during
the migration as the transient one-shot API. Post-migration,
deprecate them in favor of `TargetDef` + `Resolver` if no caller
still needs the one-shot form.
