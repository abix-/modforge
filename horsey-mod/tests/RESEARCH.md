# Binary research toolkit

The algorithm library is in [`modforge::research`](../../modforge/src/research.rs)
so any mod (horsey-mod, ueforge, schedule1, ...) can reuse it.
The per-mod `research_*.rs` tests here are thin env-driven
wrappers that launch the harness and call into the library.

All algorithms route through patternsleuth via the HTTP ops:

- `mem.scan_rdata` -> `modforge::patterns::sleuth::scan_rdata_matches`
- `mem.find_xrefs` -> `sleuth::scan_all_matches` with `X<addr>` xref constraint
- `patterns.sleuth.scan_all` -> `sleuth::scan_all_matches`
- `patterns.read_bytes` -> direct memory read (no pattern)

All tools auto-skip when their required env vars are unset, so
they're CI-safe.

## research_scan_pattern

Scan `.text` for every match of one IDA-style signature; decode
each match's disp32.

```
MODFORGE_SIG="c6 05 ?? ?? ?? ?? 01" \
MODFORGE_DISP32_OFF=2 MODFORGE_INSTR_LEN=7 \
cargo test -p horsey-mod --test research_scan_pattern -- --nocapture
```

## research_scan_section

Scan `.text`, `.data`, or `.rdata` for raw bytes.

```
MODFORGE_SIG="72 65 74 69 72 65 64 20 25 73" \
MODFORGE_SECTION=rdata \
cargo test -p horsey-mod --test research_scan_section -- --nocapture
```

## research_scan_in_window

Scan `.text` but restrict to a `[start, start+len)` byte window.
Use to scope a search to one function's body.

```
MODFORGE_SIG="48 81 c1 ?? ?? ?? ??" \
MODFORGE_WINDOW_START=0x14006f031 MODFORGE_WINDOW_LEN=0x200 \
cargo test -p horsey-mod --test research_scan_in_window -- --nocapture
```

## research_dump_bytes

Read N bytes from a runtime addr or RVA.

```
MODFORGE_RVA=0x1400fd580 MODFORGE_N=48 \
cargo test -p horsey-mod --test research_dump_bytes -- --nocapture
```

## research_decode_operand

Read at an addr+offset and decode as signed/unsigned 1/2/4/8 bytes.

```
MODFORGE_ADDR=0x7ff7517a5b4f MODFORGE_OFFSET=3 MODFORGE_SIZE=4 MODFORGE_SIGNED=1 \
cargo test -p horsey-mod --test research_decode_operand -- --nocapture
```

## research_find_function_entry

Probe-and-classify around a stale function RVA: list every byte
position whose bytes match an MSVC prologue, sorted by proximity.

```
MODFORGE_STALE_RVA=0x1400dde40 \
cargo test -p horsey-mod --test research_find_function_entry -- --nocapture
```

## research_find_xrefs

Find every `.text` instruction whose disp32 references a target
address.

```
MODFORGE_TARGET_RVA=0x1403fb0d8 \
cargo test -p horsey-mod --test research_find_xrefs -- --nocapture
```

## research_decode_disp32_pair

Scan a sig with two disp32s, decode both, optionally filter by
inter-target delta. Used for the d-e-b-u-g unlock block.

```
MODFORGE_SIG="c6 05 ?? ?? ?? ?? 01 c6 05 ?? ?? ?? ?? 00" \
MODFORGE_DISP1_OFF=2 MODFORGE_DISP1_NEXT_IP=7 \
MODFORGE_DISP2_OFF=9 MODFORGE_DISP2_NEXT_IP=14 \
MODFORGE_PAIR_DELTA=-0x79 \
cargo test -p horsey-mod --test research_decode_disp32_pair -- --nocapture
```

## research_decode_field_offset (R4)

End-to-end struct-field-offset finder: scan `.rdata` for a string
literal, xref to the `lea` that loads it, decode the
field-load `mov reg, [base+disp]` near the xref, histogram the
disp values, report the top.

```
MODFORGE_STRING_HEX="3c 20 53 69 6d 75 6c 61 74 69 6f 6e 20 50 61 75 73 65 64 20 2d 20 59 65 61 72 20 25 64 20 3e" \
MODFORGE_DISP_OPCODE="8b 91" MODFORGE_DISP_OFF=2 MODFORGE_WINDOW=128 \
cargo test -p horsey-mod --test research_decode_field_offset -- --nocapture
```

## research_decode_imm_at_call_site (R4)

For every `e8 X<target>` call, walk backward looking for the imm
load (`b9` mov ecx imm32, `ba` mov edx imm32, `68` push imm32, ...)
and histogram the decoded values. Use to find struct sizes passed
to allocators.

```
MODFORGE_TARGET_FN=0x1402c704c MODFORGE_IMM_OPCODE="b9" \
cargo test -p horsey-mod --test research_decode_imm_at_call_site -- --nocapture
```

## Companion HTTP ops

The library calls these ops:

- `patterns.sleuth.scan_all`. Scan one sig in `.text`, decode disp32.
- `patterns.sleuth.resolve`. Multi-target resolver (first-match-wins).
- `patterns.read_bytes`. Read N bytes at an absolute address.
- `mem.find_xrefs`. Find RIP-rel references to an address.
- `mem.scan_rdata`. Search `.rdata` for raw bytes.
- `mem.scan_data`. Search `.data` for raw bytes.
- `targets.resolve.gamestate_ptr`. Also exposes image_base for RVA rebasing.

If a future research workflow needs a new primitive, add it as a
function on `modforge::research` (and an op on the per-mod
`ops.rs` if it needs new HTTP surface); don't fold ad-hoc logic
into one-shot tests.
