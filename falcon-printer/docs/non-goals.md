# Non-goals

> What falcon-printer is explicitly NOT trying to be. Read
> this when scope creep tempts.

## Not a compilable-output transpiler

Output is **notation** for human reading. We do not:

- Reconstruct ownership / lifetimes.
- Infer struct types from usage.
- Produce Rust that the borrow checker accepts.
- Hide unsafe operations behind safe wrappers.

`let mut rax: u64 = ...` is fine even if it's shadowed
seven times in one block. `core::ptr::write(addr as *mut
u64, val)` is fine even if `addr` is a raw `wrapping_add`
chain. The user reads the output, understands what the
function does, then writes the mod against the patterns
they saw. Not by piping our output back into rustc.

## Not a decompiler

Falcon does the heavy lifting: PE loading, disassembly,
x86-64 instruction lift, IR, basic analyses. We add a
small middle-end (8 passes) and a Rust printer.

Without Falcon, falcon-printer doesn't exist. If you find
yourself wanting to rewrite the lifter, you're in the wrong
codebase; contribute to Falcon upstream instead.

## Not a Ghidra replacement

Ghidra stays installed. We use its C output as ground truth
when sanity-checking Falcon's lift. We use its INDEX.md and
key-funcs/ filenames to name our functions. We rely on its
function discovery (`ghidra_addrs.txt`).

If a function lifts correctly in Falcon but the Rust output
looks wrong, the FIRST debugging step is to compare against
`horsey-mod/research/decompiled/all_functions.c` to see what Ghidra
made of the same bytes.

## Not multi-architecture (yet)

Today: x86-64 only, because Horsey is x86-64 PE.

Falcon also ships ARM64, MIPS, and 32-bit x86 lifters.
Adding those would mean:
- A different `Pe` / `Elf` loader call site per arch.
- The middle-end passes need a sanity check: most are
  arch-agnostic (the IL is uniform), but `pass_call_recovery`
  and `pass_ret_recovery` pattern-match x86 sequences and
  would need ARM-specific variants.
- The printer might need to know which arch produced the
  IL when rendering calling conventions, sizes, etc.

When a target binary in another arch comes up (e.g., a Mac
game on ARM64), add it then. Not now.

## Not a general-purpose product

Optimizing for our RE workflow on game binaries. Specifically:

- We assume the target is a PE binary (no ELF helpers in
  `print` today, even though Falcon supports them).
- We assume function discovery comes from Ghidra (we read
  `ghidra_addrs.txt`); we don't try to discover from the
  binary alone.
- We assume the workspace stays Rust-heavy and the user is
  reading Rust idioms (raw pointers, `unsafe fn`, etc.) all
  day.

If someone else wants a "binary to Rust" tool for their
non-game project, falcon-printer might be a useful seed, but
it's not designed to be that product. The
`abix-/grounded2mods` workspace is the home; lift code out
to a standalone repo only when there's a concrete consumer.

## Not handling protected / packed / obfuscated binaries

If a game ships VMProtect or similar, the lift output will
be either gibberish (the unpacker) or simply wrong (the
unpacked code lives in memory, not on disk). Targeting
those is its own multi-month project (memory snapshots,
dynamic unpacking). Out of scope.

Horsey ships unprotected. UE4/UE5 games (Outworld, Grounded
2) ship unprotected. That's the universe we work in.

## Not a security tool

falcon-printer reads code. It does not flag vulnerabilities,
classify malware, find ROP gadgets, or detect anti-debug
tricks. If you need those, use something built for them
(retdec, Ghidra itself, IDA, Binary Ninja).
