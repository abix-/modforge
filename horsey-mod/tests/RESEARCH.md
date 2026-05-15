# Binary research toolkit

These `research_*` tests are env-var-driven generic tools for
investigating the live `Horsey.exe` binary. Use them to find new
data globals, function entries, byte patterns, and xrefs without
writing new one-shot tests. Each tool dumps results to the
harness log; copy the relevant lines into production signatures.

All tools auto-skip when their required env vars are unset, so
they're CI-safe.

## research_scan_pattern

Scan `.text` for every match of one IDA-style signature, decode
each match's disp32 to a CPU-effective target address.

```
MODFORGE_SIG="c6 05 ?? ?? ?? ?? 01" \
MODFORGE_DISP32_OFF=2 MODFORGE_INSTR_LEN=7 \
cargo test -p horsey-mod --test research_scan_pattern -- --nocapture
```

Optional: `MODFORGE_MAX_HITS`, `MODFORGE_CONTEXT_BYTES`.

## research_dump_bytes

Read N bytes from the loaded image at a given RVA or absolute
address. Output is hex; paste into a sig.

```
MODFORGE_RVA=0x1400fd580 MODFORGE_N=48 \
cargo test -p horsey-mod --test research_dump_bytes -- --nocapture
```

`MODFORGE_ADDR` accepts an absolute runtime address instead of RVA.

## research_find_function_entry

When a hardcoded function RVA points mid-function (Ghidra
off-by-N), scan +/-N bytes and list every byte position whose
bytes match a known MSVC prologue, sorted by proximity. The
closest valid prologue is usually the true entry.

```
MODFORGE_STALE_RVA=0x1400dde40 \
cargo test -p horsey-mod --test research_find_function_entry -- --nocapture
```

Optional: `MODFORGE_WINDOW` (default 2048).

## research_find_xrefs

Find every `.text` instruction whose disp32 references a target
address. Wraps `mem.find_xrefs` with env-driven inputs.

```
MODFORGE_TARGET_RVA=0x1403fb0d8 \
cargo test -p horsey-mod --test research_find_xrefs -- --nocapture
```

Accepts `MODFORGE_TARGET_ADDR` as an absolute alternative.

## research_decode_disp32_pair

Scan a sig with TWO RIP-relative disp32s, decode both, optionally
filter by inter-target delta. Use when the discriminator for a
target is the RELATIONSHIP between two refs in one instruction
sequence (e.g. the d-e-b-u-g unlock block's set-1/set-0 pair
where `target2 - target1 == -0x79`).

```
MODFORGE_SIG="c6 05 ?? ?? ?? ?? 01 c6 05 ?? ?? ?? ?? 00" \
MODFORGE_DISP1_OFF=2 MODFORGE_DISP1_NEXT_IP=7 \
MODFORGE_DISP2_OFF=9 MODFORGE_DISP2_NEXT_IP=14 \
MODFORGE_PAIR_DELTA=-0x79 \
cargo test -p horsey-mod --test research_decode_disp32_pair -- --nocapture
```

## Companion ops in the running mod

The research tests rely on these HTTP ops from `horsey-mod/src/ops.rs`:

- `patterns.sleuth.scan_all`. Scan one sig, decode every match's disp32.
- `patterns.sleuth.resolve`. Multi-target resolver (first-match-wins).
- `patterns.read_bytes`. Read N bytes at an absolute address.
- `mem.find_xrefs`. Find RIP-rel references to an address.
- `targets.resolve.gamestate_ptr`. Also exposes the running
  image_base, used by the tests to rebase RVAs.

If a future research workflow needs a new primitive, add it as an
op in `ops.rs` and a new `research_*.rs` consumer; don't fold ad-hoc
logic into one-shot tests.
