# Debugging native-PE crashes in horsey-mod

> **Authoritative.** Steady-state reference for diagnosing crashes
> inside Horsey.exe after the DLL is attached. Living document;
> update when new failure modes or new tooling land.

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

Cause: one of the detours installed via `retour::GenericDetour`
targeted an address that is NOT a function entry. retour
accepts any disassemblable bytes; it does not validate that
the target is a coherent function. When normal game execution
reaches that address as a fall-through (not as a CALL), the
JMP we spliced sends control into the handler. But the
trampoline was built from mid-function bytes, so the
"continuation" after our handler runs broken code.

Tell: in the pre-arm dryrun output the prologue bytes don't
match Win64-typical prologue patterns. See §5 for the rule.

### `0xc0000005` READ at a small constant offset from a deterministic high address

Cause: an integer was misused as a pointer. The offset is
usually a struct-field offset (e.g. 0x308 for MONEY, 0x314 for
YEAR). The high half tells you which integer got picked up:
0 = null deref, 0x240..0x7FF = stale .data byte read as a
ptr, 0xFFFF... = -1 sign-extended.

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
