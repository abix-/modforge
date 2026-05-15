# Debugging native-PE crashes in horsey-mod

> **Authoritative on:** diagnosing crashes inside Horsey.exe after the DLL is attached. Living document; update when new failure modes or new tooling land.

## Table of contents

- [1. Where the logs live](#1-where-the-logs-live)
- [2. Always-on instrumentation](#2-always-on-instrumentation)
- [3. The standard crash-diagnosis loop](#3-the-standard-crash-diagnosis-loop)
- [4. Known-good crash-signature patterns](#4-known-good-crash-signature-patterns)
- [4b. Handler discipline rules (codified after the EVAL_A bring-up)](#4b-handler-discipline-rules-codified-after-the-eval_a-bring-up)
- [5. Pre-arm verification (mandatory before any new detour)](#5-pre-arm-verification-mandatory-before-any-new-detour)
- [6. Per-detour first-call markers](#6-per-detour-first-call-markers)
- [7. Auth on the HTTP control plane](#7-auth-on-the-http-control-plane)

---

## 1. Where the logs live

| File | Source | Purpose |
|---|---|---|
| `<dll_dir>/horsey.log` | `modforge::log` (configured in `lib.rs::worker_main`) | Every `modforge::log!(...)` line from our DLL. Wall-clock timestamps in UTC, format `[HH:MM:SS]`. |
| Windows Event Viewer / `Application` log | OS | Faulting module + offset for any process that crashes hard. Filter `Source = Application Error` (event id 1000) and `Windows Error Reporting` (event id 1001). |
| `%PROGRAMDATA%\Microsoft\Windows\WER\Temp\WER*.tmp.dmp` | WER | Full minidumps. Open in WinDbg or Visual Studio if RIP-only isn't enough. |

The `horsey.log` is rotated by overwrite at every DLL load (init
opens the file with truncate). If you need to compare two runs,
copy the log somewhere before re-injecting.

## 2. Always-on instrumentation

Three permanent hooks installed in `lib.rs::worker_main` before
any patches or detours go in:

1. **Rust panic hook** (`install_panic_hook`). Logs thread,
   panic location, payload, and a forced backtrace. Without it,
   under our `panic = "abort"` release profile, a panic in
   any horsey-mod thread terminates Horsey.exe silently with
   `0xc0000409` and no breadcrumb.
2. **SEH vectored exception handler** (`install_seh_logger`).
   `AddVectoredExceptionHandler` priority 1. Logs thread name,
   exception code, RIP, and (for access violations) the
   read/write/exec kind plus the bad address. Returns
   `EXCEPTION_CONTINUE_SEARCH` so WER still produces a dump.
   Filtered to interesting codes only (AV, illegal-instruction,
   stack-overflow, div-by-zero, priv-instruction).
3. **Step-by-step `HorseyState::capture()` logging.** Each game
   state read is bracketed by `capture: about to read X` /
   `capture: X read OK`. Combined with SEH this gives line-
   precision crash localization with no debugger.

Removing or weakening any of these in a refactor is forbidden
without replacement. They're cheap and pay for themselves the
first time something faults.

## 3. The standard crash-diagnosis loop

When the game crashes with our DLL attached:

1. Read `<dll_dir>/horsey.log`. The LAST line before silence is
   the floor on what we executed successfully. The first SEH
   line (if present) is the crash signature.
2. From the SEH line, note: thread name, RIP, bad_addr, kind.
3. Compute RVA in our DLL: `rva = rip - dll_base`. The DLL base
   is shown in the inject success line
   (`OK; hmod=0x<base>`).
4. If you need a symbol for the RVA, run dumpbin / windbg with
   the PDB at `target/.../release/horsey.pdb`.
5. If thread is `horsey-http`, the crash is inside our HTTP
   handler closure (lib.rs) or the per-op handler. If thread
   is unnamed, the game's own threads (render, audio, AI,
   main) entered our DLL via a detour or a callback.

## 4. Known-good crash-signature patterns

These show up across sessions; recognize them on sight.

### "Capture stops at `reading X`" then SEH

Cause: a `gamestate::*` read dereferenced a `.data` address that
isn't actually a pointer slot. Fix: re-read the decomp evidence
for that symbol. Treat it as a struct base, not a pointer to a
struct, unless the decompiler shows `**` indirection in the
write paths.

Historical example: `gamestate::ptr()` used to `*deref` the
`GAMESTATE_PTR` slot. The slot IS the struct. We were reading
the first 8 bytes of the struct, treating them as a pointer,
and dereferencing again. Which crashed when the first 8 bytes
held a canonical-but-unmapped value
(0x2400000000B in the May 2026 build, main-menu state).

### Game thread crashes with `bad_addr=0xffffffffffffffff` shortly after `arm`

This bad-address shape has shown up for **two distinct
root causes**. Check both.

**Cause A: handler stack frame too big.**
The handler runs on the game's threads, often nested deep
inside vanilla call chains where remaining stack budget is
small. If the Rust handler allocates more stack than is
free in the current page, the first `MOVAPS [rsp+disp], xmm`
write (callee-saved register spill) faults. The crash RIP
points inside the handler body, typically at the FIRST
memory write after a `sub rsp, imm`.

Tell: SEH log shows `rip` inside our DLL within the first
~16 bytes of the handler's body, kind=READ (alignment
fault) with all-ones bad_addr.

Fix: strip the handler to **atomics + integer math + at
most one indirect call**. NO `format!`, NO `modforge::log!`,
NO stack-buffered `OutputDebugStringA`, NO `parking_lot`
Mutex lock taken at handler entry. Push logging into the
`arm()` path that runs on the HTTP thread; expose live
state via atomic counters and HTTP polling.

**Cause B: parking_lot Mutex / TLS on a foreign thread.**
The handler initially took `static OnceLock<Mutex<...>>::lock()`
to find the detour. `parking_lot` uses thread-local state
for its parking queue; game threads (created by the game's
C++ runtime, not Rust) don't have Rust-style TLS set up
properly. The lock fault is reported as access violation
~0x4E0 bytes past the handler entry. Inside parking_lot's
TLS-touching code.

Tell: SEH log shows `rip` inside our DLL but well past the
handler body, RIP not in the obvious atomic-only handler
range.

Fix: handlers must not touch parking_lot, `OnceLock` init,
or anything else that uses TLS-implicitly. Use lock-free
`AtomicPtr<GenericDetour<T>>` cells published via
`Box::into_raw` + `AtomicPtr::store(Release)` at arm time;
handlers `load(Acquire)` then call. See
`patches/ext_genes.rs` for the pattern.

**Cause C (the original): detour target was not a function entry.**
One of the detours installed via `retour::GenericDetour`
targeted an address that is NOT a function entry. retour
accepts any disassemblable bytes; it does not validate that
the target is a coherent function. When normal game execution
reaches that address as a fall-through (not as a CALL), the
JMP we spliced sends control into the handler. But the
trampoline was built from mid-function bytes, so the
"continuation" after our handler runs broken code.

Tell: in the pre-arm dryrun output the prologue bytes don't
match Win64-typical prologue patterns. See §5 for the rule.

**The common upstream cause of (C): the game updated.** Steam
silently pushes new builds. Functions move, get inlined, get
renamed. Our `targets::fn_addr::*` constants are tied to one
specific build. When `Horsey.exe`'s mtime is newer than the
generation date in `horsey-mod/research/decompiled/INDEX.md`, assume
every address is suspect until verified by §5 prologue checks
or by re-running `horsey-mod/research/decompile.py`.

The 2026-05-14 session hit this: the May 2026 build moved
`FUN_14009f680` and `FUN_1400c03a0` between two decomp runs
~4 hours apart. EVAL_A/EVAL_B addresses happened to still
land at function entries; ALLELE_SWAP and APPLY_GENE_TO_HORSE
did not. Refusing to arm at a non-entry is enforced now in
`patches/render_trampoline.rs::arm()` and the equivalent
skip in `patches/ext_genes.rs::arm()`.

### Ghidra-indexed entry is 16 bytes INTO the function

**Discovered 2026-05-14, after wasting half a session blaming a
nonexistent game update.** Our pyghidra decomp pass indexes
function entries off-by-16 for the MSVC-compiled Horsey.exe.
Every `0x14XXXXXX` address in `horsey-mod/research/decompiled/INDEX.md`
points 16 bytes INSIDE the function body, past the register-save
prologue.

Two real-prologue shapes appear at `ghidra_addr - 16`:

1. **Big functions** (`APPLY_GENE_TO_HORSE`, `GENE_DEATH_DRIFT`,
   `GENE_ENGINE_CONSUMER`):
   ```
   48 8b c4              ; mov rax, rsp
   55 53 56 57           ; push rbp, rbx, rsi, rdi
   41 54 41 55 41 56 41 57   ; push r12..r15
   ```
   16 bytes; this is MSVC's frame-pointer-omission prologue
   that saves the original rsp in rax for later use by
   `lea rbp, [rax-X]` at offset +16.

2. **Small functions** (`EVAL_DIPLOID_BLEND_A`, `EVAL_DIPLOID_BLEND_B`,
   `GENE_ALLELE_SWAP`):
   ```
   48 89 5c 24 08    ; mov [rsp+8], rbx
   48 89 6c 24 10    ; mov [rsp+0x10], rbp
   48 89 74 24 18    ; mov [rsp+0x18], rsi
   57                ; push rdi
   ```
   16 bytes; shadow-space stores of callee-saved registers
   plus one push.

**Why this matters for hooking.** retour's trampoline copies
the first N bytes of the target into a relocated page. If the
true prologue includes `mov rax, rsp`, our handler's normal
Rust code clobbers RAX before the trampoline runs (RAX is
volatile in Win64 ABI). The relocated `lea rbp, [rax-X]` then
computes garbage. Crash signature: SEH READ at
`bad_addr=0xFFFFFFFFFFFFFFFF` inside the vanilla function
body, ~13 bytes after the JMP we installed.

**Why some functions "worked" at the wrong address.** EVAL_A
and EVAL_B have a shadow-space-saves prologue. After 16 bytes,
the next instructions (`sub rsp, 0x20; movsxd rbx, edx`) don't
depend on any preserved register state. retour copies those
into the trampoline; trampoline jumps back; vanilla continues
normally. The address was wrong but the failure was masked.

**Fix.** Every address in `targets::fn_addr::*` has been
adjusted by -16. Verification: at the corrected address, the
first 16 bytes must match one of the two prologue shapes
above. New addresses MUST be verified before adding.

**Why this isn't `pad_count` / alignment.** Ghidra didn't find
extra padding at the true entries; the previous function ends
with `RET` + `INT3 cc` padding to align to 16 bytes, then the
NEXT function starts. Ghidra just decided the NEXT function
starts 16 bytes later than it does. Likely a quirk of how
Ghidra's analyzer walks call targets vs structured-exception
data; we didn't chase down the root cause inside Ghidra.

### `0xc0000005` READ at a small constant offset from a deterministic high address

Cause: an integer was misused as a pointer. The offset is
usually a struct-field offset (e.g. 0x308 for MONEY, 0x314 for
YEAR). The high half tells you which integer got picked up:
0 = null deref, 0x240..0x7FF = stale .data byte read as a
ptr, 0xFFFF... = -1 sign-extended.

## 4b. Handler discipline rules (codified after the EVAL_A bring-up)

Every `extern "system"` detour handler ships under these rules.
They are NOT optional. Violating any one of them is a known
crash trigger.

1. **No Rust-TLS dependencies.** No `parking_lot::Mutex::lock`,
   no `OnceLock::get_or_init` on the hot path, no `thread_local!`
   reads, no `RefCell`, no anything that touches per-thread
   state. Game threads were not created by Rust's runtime;
   they don't have Rust TLS set up. Lock-free `AtomicPtr`,
   `AtomicU64`, etc. are fine.
2. **No formatting on the hot path.** No `format!`, no
   `modforge::log!`, no `write!` to a `String`. These allocate
   on the stack (Arguments<'_>, fmt machinery) and use 100+
   bytes of frame that the game's nested call chain may not
   have free.
3. **No stack-buffered output.** No `let mut buf = [0u8; 256]`
   patterns. The OutputDebugStringA "minimal trace" idea fails
   for the same reason as #2. The buffer eats stack we can't
   spare.
4. **Atomics-only stats.** Counters live in `static`
   `AtomicU64`. Surface them via HTTP polling
   (`genes.ext.stats`) instead of logging on first call.
5. **At most one indirect call.** The handler may load an
   `AtomicPtr<GenericDetour<T>>` and call `(*p).call(...)` to
   chain into the trampoline. That's it. Heavier work
   (`evaluate_ext_gene`, etc.) is fine but must itself observe
   rule 1.

Mnemonic: think of the handler as **interrupt-handler-grade code**.
The fact that it runs on the game's thread, not ours, means it
inherits the constraints of an interrupt context for our
purposes. Minimal stack, no thread-affined services.

The reference implementation is `eval_a_handler` in
`patches/ext_genes.rs`. Copy its shape for every new handler.

## 5. Pre-arm verification (mandatory before any new detour)

Before adding a new `GenericDetour::new(...)` install call:

1. Confirm the address is correct in the CURRENT game build by
   running the corresponding `*.dryrun` HTTP op and reading the
   first 16 prologue bytes.
2. The prologue MUST match a recognizable Win64 function entry.
   Typical patterns:
   - `48 83 ec XX` -- `sub rsp, imm8`
   - `48 81 ec XX XX XX XX` -- `sub rsp, imm32`
   - `40 53` / `40 55` / `40 56` / `40 57` -- `push rbx/rbp/rsi/rdi`
   - `48 89 5c 24 XX` -- `mov [rsp+disp8], rbx` (param spill)
   - `4c 89 4c 24 XX` -- `mov [rsp+disp8], r9` (param spill)
   - `4c 8b dc` -- `mov r11, rsp` (forwarding thunk)
3. RED FLAGS that mean "this is mid-function, do not detour":
   - `48 be XX XX XX XX XX XX XX XX` (`movabs rsi, imm64`)
     near the top. Function entries don't load 64-bit
     immediates immediately.
   - Any FP move (`f3 0f 11`, `0f 29`, `0f 28`) before a
     stack frame is set up.
   - A direct `MOVSXD` of a parameter register (e.g.
     `63 fa` -- `movsxd edi, edx`) without an enclosing
     prologue. Vanilla functions sign-extend params AFTER
     the stack frame is set up; if it's the FIRST byte,
     you're inside a function, not at its entry.
4. If the prologue looks wrong, re-decompile the function and
   re-derive the address. The 100% decomp pass is a snapshot
   of one build; addresses drift across versions.

We don't enforce this in code today. Treat it as a checklist
item in PRs that add detours. If it gets violated twice we'll
codify it as a `is_plausible_function_entry(prologue: &[u8])`
pre-check inside `GenericDetour::new` callers.

## 6. Per-detour first-call markers

Every detour handler logs ONE line on first invocation and ONE
line after the first successful trampoline return:

```
DI-A: FIRST CALL eval_a (FUN_1400a5d20) genome=0x... idx=N
DI-A: FIRST TRAMPOLINE OK eval_a (returned X for idx=N)
```

If you see "FIRST CALL X" but never "FIRST TRAMPOLINE OK X",
that detour's trampoline is corrupt. The target address was
not a real function entry, even though `arm()` returned OK.
That's the signal §4 covers.

These markers are one-shot via `AtomicBool::swap(true, Relaxed)`,
so a hot-path handler (~233 calls per horse per frame) does NOT
flood the log.

## 7. Auth on the HTTP control plane

The localhost HTTP server on `127.0.0.1:33077` runs WITHOUT
authentication. The port binds to localhost only, so it is not
reachable from off the machine; the per-launch token added no
real security and added friction (the global Claude policy
treated `horsey.auth` as a credential file). If the port ever
gets exposed off-localhost, re-enable auth in
`modforge::server::Config::auth_token`.
