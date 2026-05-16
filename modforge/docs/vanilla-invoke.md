# Vanilla Function Invocation. Call any game function on demand

> The third primitive in modforge's mod/game interaction triad.
> `hook` intercepts vanilla calls. `seh` makes vanilla calls
> recoverable on fault. `vanilla` invokes vanilla functions from
> the mod side. Together they cover the three directions of
> mod/game interaction.

This doc defines the design. Implementation is TBD; the goal here
is to lock the API and migration path before any code lands.
Same draft-first convention as
[`target-registry.md`](target-registry.md).

## Why

Today every modforge consumer that calls back into vanilla code
hand-rolls the same pattern:

```rust
type RebuildFn = unsafe extern "system" fn(*mut Horse) -> ();
let f: RebuildFn = unsafe { std::mem::transmute(addr) };
unsafe { f(horse_ptr) };
```

This works but has three sharp edges:

1. **Per-callsite signature boilerplate.** Every distinct function
   the mod wants to invoke needs its own `type Fn = ...` +
   `transmute` + `unsafe` block. After ~10 of these the mod has a
   `pub mod vanilla { ... }` file full of typed wrappers.
2. **No HTTP surface.** External clients (tests, scripts, the
   in-game ImGui overlay) can't invoke vanilla code without
   asking the mod to add a per-function cmdlet wrapper. Every
   new wrapper is ~30 LOC of boilerplate.
3. **No standardized fault handling.** A vanilla call that
   faults takes the process down. [`modforge::seh`](../src/seh)
   solves the fault-handling part, but every consumer has to
   remember to wrap each call site, and most don't.

The leverage win is enormous if we standardize. Every mod's
vanilla-call layer becomes:

- A handful of `Signature` constants registered alongside their
  function entries in the target-registry.
- All call sites go through one `vanilla::call` API that handles
  the calling convention, fault wrapping, and HTTP exposure.
- A single shared `vanilla.invoke` cmdlet turns ANY registered
  function into a remote-controllable surface for free.

Cross-game value: every future modforge consumer (horsey-mod,
grounded2-mod, schedule1, outworld-station-mod, future games)
inherits the entire vanilla-invocation layer from one ~300 LOC
module. Each game just registers signatures in its target-registry;
no per-mod invocation code.

## CRD shape

Follows [`def-registry.md`](def-registry.md). The four roles map
cleanly:

| Role | What | Concrete |
|---|---|---|
| **Def** | One callable function's schema | `sleuth::TargetDef` (extended with a `Signature` on `TargetKind::FunctionEntry`) |
| **Registry** | Collection of callable functions | `sleuth::TargetRegistry`, with `kind: TargetKind::FunctionEntry { signature }` |
| **Instance** | A bound `(addr, sig)` pair ready to invoke | `VanillaFn` returned by `Invoker::bind(name)` |
| **Controller** | Argument marshaller + dispatcher + fault wrapper | `Invoker::call(name, args)` |

K8s slot:

```
// K8s slot: Def=sleuth::TargetDef (Signature on FunctionEntry kind),
//           Registry=TARGET_REGISTRY, Instance=VanillaFn (transient),
//           Controller=Invoker::call
```

The Def doesn't get its own registry. It rides on the existing
`sleuth::TargetRegistry` defined in
[`target-registry.md`](target-registry.md) (itself an extension
of the already-shipped `modforge::patterns::sleuth`) by adding a
`Signature` field to function-entry targets. This is deliberate:
name + address + signature is one fact about one function, not
three separate facts that could drift apart.

## Signature

```rust
// modforge::vanilla::sig

pub enum ArgKind {
    // Win64 GPR-eligible: marshalled into RCX/RDX/R8/R9 then stack.
    I8, I16, I32, I64,
    U8, U16, U32, U64,
    Ptr,
    Bool,
    // XMM-eligible: marshalled into XMM0/1/2/3 then stack.
    F32, F64,
}

pub enum RetKind {
    Void,
    I8, I16, I32, I64,
    U8, U16, U32, U64,
    Ptr,
    Bool,
    F32, F64,
}

pub struct Signature {
    pub args: &'static [ArgKind],
    pub ret: RetKind,
}
```

Declared as `&'static` constants alongside the target:

```rust
pub static HORSE_REBUILD_SIG: Signature = Signature {
    args: &[ArgKind::Ptr],
    ret: RetKind::Void,
};

use modforge::patterns::sleuth::{TargetDef, TargetKind};

static HORSE_REBUILD: TargetDef = TargetDef {
    name: "FUN_horse_rebuild",
    kind: TargetKind::FunctionEntry { signature: Some(&HORSE_REBUILD_SIG) },
    /* candidates, hint_rva, hint_tolerance, validators ... */
};
```

`signature` is `Option` because not every function entry needs to
be callable from outside. Hook targets (functions the mod
intercepts, not invokes) leave it `None`.

## VanillaFn (Instance)

```rust
pub struct VanillaFn<'a> {
    pub name: &'static str,
    pub addr: u64,
    pub sig: &'static Signature,
    invoker: &'a Invoker,
}

impl<'a> VanillaFn<'a> {
    /// Call without SEH wrapping. Faults take the process down.
    pub fn call(&self, args: &[ArgValue]) -> Result<RetValue>;

    /// Call wrapped in `seh::call`. Faults inside vanilla become
    /// `Err(VanillaError::Faulted { code, addr })`.
    pub fn call_safe(&self, args: &[ArgValue]) -> Result<RetValue>;
}

pub enum ArgValue {
    I8(i8), I16(i16), I32(i32), I64(i64),
    U8(u8), U16(u16), U32(u32), U64(u64),
    Ptr(u64),
    Bool(bool),
    F32(f32), F64(f64),
}

pub enum RetValue {
    Void,
    I8(i8), I16(i16), I32(i32), I64(i64),
    U8(u8), U16(u16), U32(u32), U64(u64),
    Ptr(u64),
    Bool(bool),
    F32(f32), F64(f64),
}
```

## Invoker (Controller)

```rust
pub struct Invoker<'r> {
    resolver: &'r Resolver<'r>,
}

impl<'r> Invoker<'r> {
    pub fn new(resolver: &'r Resolver) -> Self;

    /// Look up `name` in the registry. Returns a `VanillaFn` ready
    /// to invoke. `None` if the name isn't registered, if it has
    /// no signature, or if address resolution failed.
    pub fn bind(&'r self, name: &str) -> Option<VanillaFn<'r>>;

    /// One-shot: bind + call. Most call sites use this.
    pub fn call(&self, name: &str, args: &[ArgValue]) -> Result<RetValue>;
    pub fn call_safe(&self, name: &str, args: &[ArgValue]) -> Result<RetValue>;
}
```

Typical consumer code:

```rust
let result = REGISTRY.invoker()
    .call_safe("FUN_horse_rebuild", &[ArgValue::Ptr(horse_ptr as u64)])?;
```

Replaces today's:

```rust
type RebuildFn = unsafe extern "system" fn(*mut Horse) -> ();
let addr = REGISTRY.resolver().resolve("FUN_horse_rebuild")?;
let f: RebuildFn = unsafe { std::mem::transmute(addr) };
seh::call(|| unsafe { f(horse_ptr) })?;
```

## The Win64 dispatcher

The actual call goes through a hand-rolled assembly dispatcher.
Three implementation options ranked:

1. **Hand-rolled `asm!()` dispatcher** (~150 LOC). RIGHT PICK.
   Zero deps. Win64 ABI is rigid (one calling convention, no
   variants on x64 Windows), so a single dispatcher handles
   every signature. The dispatcher iterates the `Signature.args`
   slice, materializes each arg into RCX/RDX/R8/R9 (or
   XMM0-XMM3 for floats) for the first 4, pushes the rest to
   the stack with 32-byte shadow space, calls, captures the
   return per `Signature.ret`. Composes with `seh::call` by
   wrapping the asm block.

2. **libffi**. Battle-tested, handles every calling convention
   on every platform, BUT drags a C dep into a process that has
   to coexist with the game's own runtime + DLLs. Risk of
   collisions, larger DLL, build complexity. Skip.

3. **Per-signature shellcode JIT**. Generate a thunk per unique
   signature at first call, cache forever. Faster (no dispatch
   loop) but overkill for our load (~50 unique signatures per
   game, microseconds of dispatch overhead is irrelevant).

Win64 ABI summary the dispatcher implements:

- First 4 args go in registers by POSITION (not type-grouped):
  - Position 0 -> RCX (or XMM0 if F32/F64)
  - Position 1 -> RDX (or XMM1 if F32/F64)
  - Position 2 -> R8 (or XMM2 if F32/F64)
  - Position 3 -> R9 (or XMM3 if F32/F64)
- Args 5+ pushed right-to-left onto the stack.
- Caller reserves 32 bytes of shadow space below the args.
- Stack must be 16-byte aligned at the CALL.
- Integer/pointer return in RAX. Float return in XMM0.

That's the entire Win64 ABI surface. ~150 LOC of asm + Rust
glue.

## Composition with the existing primitives

```
target-registry  ->  "FUN_horse_rebuild" -> 0x1400b3070 + Signature
        |
        v
modforge::vanilla::Invoker::call_safe(name, args)
        |
        +--- arg marshaller (Signature.args)
        +--- Win64 dispatcher (asm!())
        +--- seh::call (faults -> Result::Err)
        +--- return marshaller (Signature.ret)
        |
        v
RetValue
```

Every primitive plays its part:

- `target-registry` provides the name -> (address, signature) lookup.
- `vanilla::Invoker` provides the typed-call surface and the
  argument marshalling.
- `seh::call` makes faults recoverable.
- `hook` (the third direction) is independent: it intercepts
  calls vanilla makes, not the other way around. But the
  signature data is reusable: a `HookDef` could share the same
  `Signature` for parm decoding, eliminating today's
  per-function parm-decoder code in horsey-mod and ueforge.

## HTTP cmdlet surface

One shared cmdlet covers every consumer:

```
POST /op vanilla.invoke
{
  "target": "FUN_horse_rebuild",
  "args": [
    {"kind": "ptr", "value": "0x1F2A7C8540"}
  ],
  "safe": true                  // default true; use false for hot-path callers
}

response:
{
  "result": {
    "ret": {"kind": "void"},
    "ok": true,
    "elapsed_us": 87
  }
}
```

For functions with a non-void return:

```
{
  "result": {
    "ret": {"kind": "u32", "value": 1303},
    "ok": true,
    "elapsed_us": 12
  }
}
```

For SEH-caught faults:

```
{
  "result": {
    "ok": false,
    "fault": {"code": "0xc0000005", "fault_addr": "0x0", "site": "0x14000b3094"}
  }
}
```

That one cmdlet turns the mod into a **remote-control surface
for any game**. Once a function is registered in the
target-registry with a signature, external clients (tests,
scripts, the in-game ImGui overlay, ad-hoc curl commands) can
invoke it. Function-call equivalent of the byte-poker
discussion from earlier this session.

A companion `vanilla.list` cmdlet enumerates every callable target:

```
POST /op vanilla.list
{
  "result": {
    "targets": [
      {"name": "FUN_horse_rebuild", "addr": "0x1400b3070",
       "sig": {"args": ["ptr"], "ret": "void"}, "safe": true},
      ...
    ]
  }
}
```

Lets external tooling discover what's invokable without reading
source.

## What this replaces

Concrete mapping from today's hand-rolled patterns to the
vanilla-invoke model:

| Today | After |
|---|---|
| `type RebuildFn = unsafe extern "system" fn(*mut Horse);` then `transmute` | `Signature` constant + `Invoker::call_safe` |
| Per-function HTTP cmdlets (`horse.rebuild`, `cheats.money_add`, etc.) for the slice that just calls vanilla | One shared `vanilla.invoke` cmdlet |
| Wrapping each call site in `seh::call` manually | `call_safe` does it automatically |
| `unsafe` blocks scattered across mod code | One `unsafe` block in the dispatcher |
| Per-mod "list of callable functions" docs | `vanilla.list` cmdlet output |

## What this unlocks

For horsey-mod immediately:

- The HLT-style "call into vanilla rebuild after gene write"
  pattern becomes one line per call site. Today this is the
  reason horsey-mod doesn't always rebuild after a gene poke
  (boilerplate friction).
- The watch-tests gain `vanilla.invoke` as the natural
  `HORSEY_WATCH_TRIGGER`. "Call rebuild, watch the horse's
  0x498-byte block for changed offsets" becomes a one-liner.
- The byte-poker discussion gets its missing peer: not just
  twiddle memory, also invoke the game's own setters.
- Save-format investigation becomes interactive: invoke save /
  load / reset functions from a script while watching memory.

For grounded2-mod and future consumers:

- A new mod ships its first useful HTTP surface AS SOON AS its
  target-registry has a few function entries with signatures.
  No per-game invocation boilerplate.
- The byte-poker / function-poker pair becomes the universal
  research interface for any native-PE mod target.

## Migration plan

Same independent-phase shape as the target-registry plan.

1. **Phase 1: Land `modforge::vanilla` primitives.** SHIPPED 2026-05-16.
   `Signature`, `ArgValue`, `RetValue`, the Win64 asm dispatcher
   (global_asm! external function with stable void(Frame*)
   signature). 13 unit tests covering signature const-construction,
   ArgValue/RetValue round-trips, and 8 dispatcher cases against
   `extern "system"` Rust functions (register args, stack args
   5+, pointer deref, two-f64 add, mixed int/float/int, void
   return, arg-count/kind validation errors). All pass. Commit
   `639d8545`.

2. **Phase 2: Extend `sleuth::TargetDef` with optional `Signature`.**
   SHIPPED 2026-05-16 (part of target-registry Phase 1 / B1).
   `kind: TargetKind::FunctionEntry { signature: Option<&'static Signature> }`.
   Backward-compatible.

3. **Phase 3: Land `Invoker` controller + `vanilla.invoke` /
   `vanilla.list` cmdlets in modforge.** SHIPPED 2026-05-16.
   `modforge::vanilla::invoker::Invoker` binds names to
   `(addr, sig)` via the resolver, dispatches inside `seh::guard`
   by default. `modforge::vanilla::ops::register(&OpRegistry,
   &'static Resolver)` registers both HTTP cmdlets. 5 unit tests
   cover arg parsing and JSON encoding. Commits `12dbcaeb`.

4. **Phase 4 (starter): Register horsey-mod's first vanilla function.**
   STARTER SHIPPED 2026-05-16. `APPLY_GENE_TO_HORSE` now carries
   `signature: Some(&APPLY_GENE_SIG)` (takes (Ptr, Ptr), returns
   Void). horsey-mod's worker init calls
   `targets_registry::register_vanilla_ops()` so the cmdlets
   wire against `HORSEY_RESOLVER`. Commits `26938d4e`. **Remaining:
   add the other 4 functions from the original list
   (`FUN_horse_rebuild`, `FUN_rng_next_modulo`,
   `FUN_horse_copy_gene_lane_pairs`, plus 2 more), each with a
   Signature.**

5. **Phase 5: Migrate the rest of horsey-mod's call sites.**
   Every existing `transmute` + vanilla-call disappears. The
   `pub mod vanilla` files inside consumer mods either delete
   entirely or shrink to per-game `Signature` constants.

6. **Phase 6: Cross-game adoption proof.** Same as the target-
   registry's B6: at least one additional consumer mod
   (grounded2-mod or schedule1) registers at least one
   `Signature` and invokes through `Invoker::call_safe`.
   Closes the DoD item from the testkit-extraction entry too.

## Acceptance criteria

The primitive is "done" when:

1. `modforge::vanilla` ships with `Signature`, `ArgValue`,
   `RetValue`, `VanillaFn`, `Invoker`, the Win64 asm dispatcher,
   and ~15 unit tests proving the dispatcher handles each
   `ArgKind` / `RetKind` correctly against test functions.
2. `vanilla.invoke` and `vanilla.list` cmdlets shipped in the
   modforge HTTP surface.
3. horsey-mod has at least 5 vanilla functions registered with
   signatures and at least 5 production call sites going
   through `Invoker::call_safe`.
4. No `unsafe extern "system" fn` transmutes remain in
   horsey-mod (modulo the dispatcher itself).
5. At least one additional consumer mod registers a `Signature`
   and invokes through `Invoker::call_safe`.
6. [`modforge/docs/vanilla-invoke.md`](vanilla-invoke.md) (this
   doc) updated from design-doc to shipped-API doc.

## Open questions

- **Non-primitive arg marshalling.** Passing a fresh-allocated
  buffer (`*mut std::string` for a name, a freshly-constructed
  struct, etc.) is the obvious next ask. v1 supports pointers
  as raw u64 (caller pre-allocates via a separate cmdlet and
  passes the addr). v2 could add `ArgKind::Buffer { bytes:
  Vec<u8>, mode: In | Out | InOut }` that allocates in mod
  memory, calls, optionally reads back. Defer.

- **C++ thiscall / virtual calls.** thiscall on Win64 == normal
  Win64 (this in RCX). For virtual dispatch, the caller resolves
  the vtable slot to an address via the resolver and registers
  the slot like any other function. No new dispatcher work.

- **Variadic functions.** Skip. Decomp-driven signatures we
  register are all fixed-arity. If a real consumer needs a
  variadic, add a `Signature::Variadic { fixed, rest }`
  variant.

- **Return-by-stack-pointer (large structs).** Win64 caller
  allocates space, passes the pointer as an implicit first arg
  in RCX. The dispatcher needs to detect "return type is a
  large struct" and prepend the buffer pointer. v1 doesn't
  support this; defer to v2 with `RetKind::Buffer { bytes:
  usize }`.

- **Calling discipline for hot functions.** `call_safe` adds
  ~few microseconds for the SEH frame setup + teardown.
  Functions called per-frame from a mod hook (e.g. inside a
  render trampoline) probably want the bare `call`. Document
  the cost; the default stays `call_safe` because correctness
  beats microseconds for almost every call site.

- **Async / fire-and-forget.** Some vanilla calls (e.g.
  `enter_scene`) take ms-to-seconds and we don't want the HTTP
  request to block on the result. v1 is synchronous; v2 could
  add a `vanilla.invoke_async` that returns a request handle
  and a `vanilla.poll` for status. Defer.

- **Dispatcher robustness on uninitialized state.** The
  dispatcher itself can't fault (it's pure asm marshalling),
  but the call target can. `call_safe` handles fault recovery.
  What about ABI violations where the callee writes outside its
  parm block? Detected as SEH access violations and caught.

## What this does NOT solve

- **Discovering signatures.** Signatures come from decomp +
  research; the primitive consumes them, it doesn't derive them.
  Same separation as target-registry: research authors sigs,
  registry consumes them.

- **Validating that the signature is correct.** A wrong signature
  (we declared `args: [Ptr]` for a function that takes two ints)
  will dispatch wrong values into RCX/RDX, the vanilla function
  reads garbage, behavior is undefined. SEH catches the
  resulting AV but doesn't catch silent-wrong-result cases.
  v2 could add an optional `validator: fn(&RetValue, &[ArgValue])
  -> bool` on `Signature`.

- **Argument type checking at the API surface.** The Rust API
  takes `&[ArgValue]` which is dynamically typed. A caller
  passing `ArgValue::F32(1.0)` to a function whose signature
  declares `ArgKind::I32` is a runtime error
  (`SignatureMismatch`), not a compile-time error. The HTTP
  cmdlet enforces the same check on the JSON side. A `call!`
  macro could provide compile-time checking for known-at-
  compile-time signatures, but most call sites resolve the
  function by name dynamically; not worth the complexity.

- **Out-of-process invocation.** Calling vanilla code requires
  being in the game's process. The HTTP cmdlet drives
  in-process invocation from outside, but the work happens
  inside the injected DLL.

## Composition summary

After all three docs ship:

```
modforge::patterns::sleuth -> scan loaded image; TargetDef/Registry/Resolver (extended)
modforge::research         -> generic decode recipes over patterns
modforge::seh              -> SEH-wrapped vanilla calls
modforge::hook             -> intercept vanilla calls
modforge::vanilla          -> invoke vanilla functions  <-- this doc
```

Every modforge consumer inherits all five layers. A new
game-mod's setup becomes:

1. Pin patternsleuth sigs for the functions it needs.
2. Declare them in a `TargetRegistry` with `Signature` for each
   callable one.
3. Use `seh::call`, `hook`, and `vanilla::Invoker` as needed.
4. The shared testkit gives R-tier tests, watch tests, and the
   `vanilla.invoke` HTTP surface for free.

Modding any new native-PE game becomes a pure data exercise:
sigs in, behavior out.
