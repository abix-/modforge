"""For each of the 23 horse-struct offsets the consumer FUN_1400ab3d0
writes (the direct-copy slots from extract-consumer-map.py), enumerate
every function in all_functions.c that READS that offset off a
pointer. Output: a per-offset table of (FUN_xxxxx, line, snippet).

Read patterns recognized:
  *(<type> *)(<var> + 0xNN)        as an rvalue
  (<var> + 0xNN) on the RHS of `=` or inside a call argument

Writes excluded:
  *(<type> *)(<var> + 0xNN) = ...

The consumer FUN_1400ab3d0 itself is excluded from output (it's
the writer, not a reader).

Output: docs/FIELD-READERS.md with one section per offset.
"""

from __future__ import annotations

import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SRC = ROOT / "decompiled" / "all_functions.c"
OUT = ROOT.parent / "docs" / "FIELD-READERS.md"

OFFSETS = [
    0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74,
    0x78, 0x7c, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94,
    0x98, 0x9c, 0xa0, 0xa4, 0x200, 0x254, 0x2a8,
]

CONSUMER = "FUN_1400ab3d0"

_HDR = re.compile(r"^// ============ 0x([0-9a-fA-F]+) (FUN_[0-9a-fA-F]+) \(size=(\d+)\)")


def parse_functions(text: str):
    funcs = []
    cur_name = None
    cur_addr = None
    cur_start = None
    for i, line in enumerate(text.splitlines(), start=1):
        m = _HDR.match(line)
        if m:
            if cur_name is not None:
                funcs.append((cur_name, cur_addr, cur_start, i - 1))
            cur_addr = m.group(1)
            cur_name = m.group(2)
            cur_start = i
    if cur_name is not None:
        funcs.append((cur_name, cur_addr, cur_start, len(text.splitlines())))
    return funcs


def build_offset_patterns():
    pats = {}
    for off in OFFSETS:
        hex_l = f"0x{off:x}"
        hex_u = f"0x{off:X}"
        dec = str(off)
        alt = "|".join({hex_l, hex_u, dec})
        read_rx = re.compile(
            r"\*\(\s*[\w\s\*]+\)\s*\(\s*\w+\s*\+\s*(?:" + alt + r")\s*\)"
        )
        write_rx = re.compile(
            r"\*\(\s*[\w\s\*]+\)\s*\(\s*\w+\s*\+\s*(?:" + alt + r")\s*\)\s*="
        )
        pats[off] = (read_rx, write_rx)
    return pats


def main():
    text = SRC.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    funcs = parse_functions(text)
    pats = build_offset_patterns()

    by_offset: dict[int, dict[str, list[tuple[int, str]]]] = defaultdict(lambda: defaultdict(list))

    for name, addr, start, end in funcs:
        if name == CONSUMER:
            continue
        body = lines[start - 1 : end]
        for off, (read_rx, write_rx) in pats.items():
            for lineno_offset, raw in enumerate(body):
                if not read_rx.search(raw):
                    continue
                m_w = write_rx.search(raw)
                if m_w and m_w.start() == read_rx.search(raw).start():
                    continue
                snippet = raw.strip()
                if len(snippet) > 140:
                    snippet = snippet[:137] + "..."
                by_offset[off][name].append((start + lineno_offset, snippet))

    # Build per-function offset coverage. A function that touches
    # multiple of the 23 target offsets in one body is almost
    # certainly a horse-struct handler. Single-offset hits are
    # mostly false positives (0x58 / 0x60 etc are common across
    # the binary).
    func_to_offsets: dict[str, set[int]] = defaultdict(set)
    for off, funcs_for_off in by_offset.items():
        for fname in funcs_for_off:
            func_to_offsets[fname].add(off)

    # Initial v1 fingerprint "touches >= 3 offsets" produced a 218-
    # function list dominated by false positives. The 0x58..0xa4
    # cluster collides with common struct shapes (SDL/Vulkan feature
    # structs, vendor data structs). The high offsets +0x200,
    # +0x254, +0x2a8 are MUCH rarer and the consumer writes them
    # too, so requiring one of those plus low-cluster coverage is
    # a far better filter.
    HIGH_OFFSETS = {0x200, 0x254, 0x2a8}
    HORSE_FP_THRESHOLD = 3
    horse_funcs = {
        f for f, offs in func_to_offsets.items()
        if len(offs) >= HORSE_FP_THRESHOLD
        and (offs & HIGH_OFFSETS)
    }

    out_lines = [
        "# Horse-struct field readers",
        "",
        "Auto-derived from `research/decompiled/all_functions.c` by",
        "`research/extract-field-readers.py`. For each of the 23",
        "direct-copy offsets the consumer `FUN_1400ab3d0` writes,",
        "this lists every other function that reads that offset off",
        "a pointer. Consumer itself excluded.",
        "",
        "Caveat: matches any `*(T*)(var + 0xNN)` pattern, so non-horse",
        "structs with the same offset will produce false positives.",
        f"**Horse-handler fingerprint:** functions that touch >= "
        f"{HORSE_FP_THRESHOLD} of the 23 target offsets in one body "
        f"are very likely real horse-struct handlers; single-offset "
        f"hits are mostly noise.",
        "",
        f"## Likely horse-struct handlers ({len(horse_funcs)} functions)",
        "",
        "Functions touching >= 3 target offsets, sorted by coverage.",
        "These are the candidates worth deep-reading.",
        "",
        "| Function | Offsets touched | Coverage |",
        "|---|---|---|",
    ]
    ordered_horse = sorted(horse_funcs,
                           key=lambda f: (-len(func_to_offsets[f]), f))
    for fname in ordered_horse:
        offs = sorted(func_to_offsets[fname])
        offs_str = ", ".join(f"+0x{o:x}" for o in offs)
        out_lines.append(f"| `{fname}` | {offs_str} | {len(offs)}/23 |")
    out_lines.append("")
    out_lines.append("### Cross-reference with ALL-FUNCTIONS.md")
    out_lines.append("")
    out_lines.append("Manually classified 2026-05-15 by cross-referencing the candidate list against [`ALL-FUNCTIONS.md`](ALL-FUNCTIONS.md):")
    out_lines.append("")
    out_lines.append("**Confirmed horse-handlers (read real horse fields):**")
    out_lines.append("")
    out_lines.append("| Function | Name in ALL-FUNCTIONS | Subsystem |")
    out_lines.append("|---|---|---|")
    out_lines.append("| `FUN_1400df280` | `retire_horse_handler` | gameplay (retirement) |")
    out_lines.append("| `FUN_140089510` | `copy_genome_to_clipboard` | UI / serialization |")
    out_lines.append("| `FUN_14010ba40` | `debug_print_population_stats` | debug print |")
    out_lines.append("| `FUN_140094a20` | `show_race_ready_prompt` | UI prompt |")
    out_lines.append("| `FUN_1400dcab0` | `show_getting_old_sale_dialog` | UI (buyer dialog) |")
    out_lines.append("| `FUN_1400e0aa0` | `show_all_rested_message` | UI message |")
    out_lines.append("")
    out_lines.append("**Likely false positives (regex collision with non-horse structs):**")
    out_lines.append("")
    out_lines.append("| Function | Name | Why noise |")
    out_lines.append("|---|---|---|")
    out_lines.append("| `FUN_1400ba940` | `init_struct` (auto-named) | 7179-byte body iterates a different entity list at `param_1+0x40` stride 0xb8; offsets match inner record, not horse |")
    out_lines.append("| `FUN_140107660` | `init_struct` | sequential field init pattern |")
    out_lines.append("| `FUN_1401c97e0` | `init_struct` | sequential field init pattern |")
    out_lines.append("| `FUN_14007b2e0` | `init_struct` | sequential field init pattern |")
    out_lines.append("| `FUN_140080e40` | `batch_call_080cc0` | loop-call wrapper |")
    out_lines.append("| `FUN_140102060` | `batch_call_0c5c20` | loop-call wrapper |")
    out_lines.append("| `FUN_140106bc0` | `batch_call_2c7088` | loop-call wrapper |")
    out_lines.append("| `FUN_1400d2090` | `float_math_main` | generic math |")
    out_lines.append("| `FUN_140101dc0` | `float_helper` | generic math |")
    out_lines.append("| `FUN_140081600` | `helper_with_2_callees` | generic helper |")
    out_lines.append("")
    out_lines.append("**Unclassified (no entry in ALL-FUNCTIONS.md, need first-look):** `FUN_14003d890`, `FUN_140155130`, `FUN_1401ef800`, `FUN_14003c8c0`, `FUN_1400e25b0`.")
    out_lines.append("")
    out_lines.append("**Key finding:** none of the confirmed horse-handlers are in the renderer call chain. They're all UI / gameplay / debug. The renderer reads the horse-struct fields the consumer wrote, but the regex fingerprint isn't isolating it. Likely the renderer reads through a NESTED pointer (e.g. `horse->render_state->field`) which our `var + 0xNN` regex doesn't capture cleanly, or uses field names after Ghidra struct propagation that strip the offset literal.")
    out_lines.append("")
    out_lines.append("### Consumer call-site forward trace (2026-05-15)")
    out_lines.append("")
    out_lines.append("All 6 known call sites of `FUN_1400ab3d0` in `all_functions.c` are **regeneration events**, not per-frame render calls:")
    out_lines.append("")
    out_lines.append("| Caller | Line | Context |")
    out_lines.append("|---|---|---|")
    out_lines.append("| `FUN_1400b2e30` | 104380 | child-from-parents (calls genome-merge `FUN_1400a2d80` first) |")
    out_lines.append("| `FUN_1400b2ee0` | 104441 | horse init with pop, sets `+0x234` and `+0x1fc=2` after |")
    out_lines.append("| `FUN_1400b3070` | 104585, 104614 | horse regen wrapping CRISPR-style flows; iterates entity list at 0xb8 stride |")
    out_lines.append("| `FUN_1400c1xxx` | 113025, 113052 | CRISPR genome mutate then regen, sets `+0x1fc=2` |")
    out_lines.append("")
    out_lines.append("The consumer's job is **persistent overwrite of horse-struct fields whenever gene-derived attributes change** (birth, CRISPR, respawn). The renderer reads those fields independently, per frame, decoupled from these call sites. Forward-tracing from the consumer's callers leads to event triggers, not the renderer.")
    out_lines.append("")
    out_lines.append("**Conclusion:** don't chase the renderer statically. Finding it cleanly needs Ghidra struct propagation across the horse type. The slot map is good enough to ship with: gene -> slot (per-gene table in GENE-CATALOG.md) + slot -> horse struct offset (consumer map) + working D5 trampoline + one empirically confirmed slot. Per-feature classification of the remaining 22 direct-copy slots will be populated as a side effect of bestiary authoring, not enumerated ahead of demand.")
    out_lines.append("")
    out_lines.append("## Per-offset reader tables (full, unfiltered)")
    out_lines.append("")

    for off in OFFSETS:
        funcs_for_off = by_offset.get(off, {})
        out_lines.append(f"## `+0x{off:x}` ({off} dec)")
        out_lines.append("")
        if not funcs_for_off:
            out_lines.append("_No readers found._")
            out_lines.append("")
            continue
        total_hits = sum(len(v) for v in funcs_for_off.values())
        out_lines.append(f"{len(funcs_for_off)} functions, {total_hits} read sites.")
        out_lines.append("")
        out_lines.append("| Function | Hits | First line | First snippet |")
        out_lines.append("|---|---|---|---|")
        ordered = sorted(funcs_for_off.items(), key=lambda kv: (-len(kv[1]), kv[0]))
        for fname, hits in ordered:
            first_line, first_snip = hits[0]
            esc = first_snip.replace("|", r"\|")
            out_lines.append(f"| `{fname}` | {len(hits)} | {first_line} | `{esc}` |")
        out_lines.append("")

    OUT.write_text("\n".join(out_lines), encoding="utf-8")
    total_funcs = sum(len(v) for v in by_offset.values())
    total_sites = sum(len(h) for v in by_offset.values() for h in v.values())
    print(f"wrote {OUT}")
    print(f"offsets covered: {len(OFFSETS)}")
    print(f"function-occurrences: {total_funcs}")
    print(f"read sites: {total_sites}")


if __name__ == "__main__":
    main()
