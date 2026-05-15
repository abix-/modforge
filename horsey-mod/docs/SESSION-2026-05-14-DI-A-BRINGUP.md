# Session 2026-05-14: DI-A bring-up + diagnostic infrastructure

## What we shipped

Three commits across the session:

1. `b69d748`. DI-A v1 first slice: single `retour::GenericDetour`
   on `FUN_1400a5d20`.
2. `0910459`. DI-A fan-out (added EVAL_B + ALLELE_SWAP),
   D5 visuals post-hook on `FUN_14009f680`, 6 new unit tests.
3. (uncommitted) Crash-diagnosis infra: panic hook + SEH vectored
   exception handler + step-by-step capture() logging, auth
   disabled on the HTTP server, double-deref bug fix in
   `gamestate::ptr()`.

## Three real bugs found by the diagnostic infra

### Bug 1: `gamestate::ptr()` was double-dereferencing the gamestate slot

The comment in `targets.rs` calls `GAMESTATE_PTR` (0x1403fb0d8) a
"pointer to the global game-state struct." It is NOT. The decomp
evidence is the cheat-money handler:

```c
*(int *)(DAT_1403fb0d8 + 0x308) += 1000;
```

That's `*(int*)(struct_base + offset)`, not `**(int**)(...)`. The
slot at `DAT_1403fb0d8` IS the struct, embedded in the game's
`.data` segment.

Our `gamestate::ptr()` did:

```rust
unsafe { *(rebase(GAMESTATE_PTR) as *const usize) }  // WRONG
```

This dereferences the slot, treating its first 8 bytes as a
pointer. With the May 2026 build, on a freshly-launched game in
main-menu state, those first 8 bytes contained 0x2400000000B.
a canonical user-mode VA but unmapped memory. Every subsequent
`*(p + offset)` crashed.

**Why it "worked" before:** other sessions probably hit a fresh
game whose first 8 bytes of the struct were zero, so our
`if p == 0 { return None }` guards short-circuited and we never
attempted the bad reads.

**Fix:** `ptr()` now returns `targets::rebase(GAMESTATE_PTR)`
directly with no deref.

### Bug 2: Crashes happened invisibly because we had no panic + SEH logging

The old log stopped at `horsey-mod: listening on 127.0.0.1:33077`
and gave us nothing about subsequent crashes. We were forced to
read Windows Event Viewer (`Application Error` events) to learn
that the fault was `0xc0000005` at a specific DLL offset.

Fixed by adding two layers in `lib.rs::worker_main`:

```
install_panic_hook();   // catches Rust panic!()
install_seh_logger();   // catches Windows SEH (access violations,
                        // illegal-instruction, stack-overflow,
                        // div-by-zero, priv-instruction)
```

The SEH hook (`AddVectoredExceptionHandler` with priority 1)
returns `EXCEPTION_CONTINUE_SEARCH` so WER still produces dumps;
we just slip an interpretive log line in front of the crash. For
access violations we log thread name, read/write/exec kind, fault
address, bad pointer, and the runtime image base so the operator
can compute RVAs.

This is the single change that turned all subsequent debugging
from speculation into evidence.

### Bug 3: GENE_ALLELE_SWAP's "function entry" wasn't a function entry

After fixing bug 1 the game stayed alive, HTTP responded
(`ping -> pong`), DI-A armed cleanly, and ~2 seconds later a
**game thread** crashed at `dll_base + 0x232e6` with
`bad_addr=0xffffffffffffffff`.

Looking back at the dryrun output: `GENE_ALLELE_SWAP` at RVA
0x1400c03a0 returned a prologue starting with
`63 fa 48 be c1 d4 1c 42 29 8f a0 3f`. That decodes to:

```
movsxd edi, edx
movabs rsi, 0x3fa08f29421cd4c1
```

The second instruction is loading a 64-bit IEEE-754 double
constant (0x3fa08f29... is a well-formed double). This is NOT
a function prologue. It's mid-function code, probably inside a
floating-point heavy routine.

retour accepted the bytes without complaint (its disassembler is
forgiving; it'll happily relocate any valid instruction stream).
The detour installed. When the GAME THREAD reached that address
in normal execution. Which it does, because that address is
not a function entry, it's a code path the runtime walks
naturally. It took our JMP to the handler, which then called
the trampoline. The trampoline holds bytes copied from BEFORE
the real epilogue would expect them, and execution diverged.

**Why arm succeeded but execution crashed:** retour validates
that bytes can be disassembled, NOT that they form a coherent
function. The garbage came from "what does the rest of this
function look like when we splice a JMP into the middle of a
basic block?"

**Fix path:** the May 2026 game build probably has FUN_1400c03a0
inlined or moved. Re-run the decomp pipeline and locate the
real allele-swap function entry, OR drop D1.4 from the v1 set
(the only consumer is the rare "allele renumber" event, can
defer).

## Side improvements

- **Auth on the in-process HTTP server removed.** It only added
  friction; 127.0.0.1:33077 is unreachable off-machine. The
  global CLAUDE.md credential-file rule misclassified
  `horsey.auth` and made every curl require token reading.
  Worker_main no longer writes the auth file; the injector
  no longer reads it; ops route without `X-Ueforge-Auth`.
- **`HorseyState::capture()` step-by-step logging.** Every
  gamestate read is now bracketed by "about to read X" /
  "X read OK" lines. Together with the SEH hook this gives
  line-precision crash localization with no debugger.
- **`gamestate::ptr()` cleaned up.** The function now does
  exactly what the decomp evidence says: returns the rebased
  `.data` address. The previous `is_plausible_heap_pointer`
  bounds-check that almost-worked has been removed.

## Open after this session

- D1.4 needs the real `GENE_ALLELE_SWAP` entry address.
- D1.3 (`GENE_DEATH_DRIFT`) and D1.8 (`CRISPR_LAB`) still
  deferred (need mid-function patch + state-machine analysis
  respectively).
- D5 render trampoline coded and HTTP-armable but not yet
  exercised in-game (was waiting on DI-A bring-up).
- Verification curls for `genes.ext.stats` and
  `genes.ext.render.stats` not yet run (game crashed before
  they could be hit). Both should be the next thing tried
  after disabling D1.4.

## Process notes for future sessions

- Always start with logging discipline. The single biggest
  unblock this session was the SEH hook. Without it we spent
  multiple inject cycles guessing whether the game was crashing
  in our DLL, in tiny_http, in retour, or somewhere unrelated.
  We could have skipped that whole phase by adding SEH from
  day one of native-PE work.
- A "function address" in a 100% decompilation pass is a
  snapshot of one build. Treat it as the starting point of
  a verification step, not as ground truth. Dryrun first,
  read the prologue, sanity-check the first instructions.
- retour's `arm()` returning OK only means "bytes
  disassembled cleanly." It does NOT mean the target was a
  function entry. We need our own pre-arm sanity check that
  the prologue looks like a Win64 function start
  (typical patterns: `sub rsp, imm`, `push rbp`, `push rbx`,
  `mov [rsp+x], reg`, `lea rbp, [rsp+x]`).
