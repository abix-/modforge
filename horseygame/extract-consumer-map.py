"""Extract buf_slot -> horse_struct_offset mappings from FUN_1400ab3d0.

The consumer reads `param_2[slot]` and writes `*(... *)(param_1 + off) = ...`.
Direct one-line copies (`*(float*)(p1 + 0xNN) = param_2[0xMM];`) give
us the cleanest map. Conditional / intermediate slot reads are
recorded as "uses (no direct copy)".
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SRC = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
SLOT_MAP_MD = ROOT / "SLOT-MAP.md"

_DIRECT = re.compile(
    r"\*\((?:undefined\d|float|longlong|int)\s*\*\)\s*\(\s*param_1\s*\+\s*"
    r"(?P<off>0x[0-9a-fA-F]+|\d+)\s*\)\s*=\s*"
    r"(?:\(\s*[\w ]+\s*\)\s*)?\(?(?:\s*\(\s*[\w ]+\s*\)\s*)?"
    r"param_2\[\s*(?P<slot>0x[0-9a-fA-F]+|\d+)\s*\]"
)
_INDIRECT = re.compile(r"param_2\[\s*(?P<slot>0x[0-9a-fA-F]+|\d+)\s*\]")

# Bare `*param_2` reads slot 0 (the dereference shorthand the
# decompiler emits instead of `param_2[0]`). Must be tracked too.
_BARE_DEREF = re.compile(r"\*\s*(?:p\w*\s*=\s*)?param_2(?!\w)")


def parse_num(s):
    s = s.strip()
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def extract():
    text = SRC.read_text(encoding="utf-8")
    # Find FUN_1400ab3d0's body.
    marker = "// ============ 0x1400ab3d0 "
    start = text.find(marker)
    next_hdr = text.find("// ============ 0x1400ad5c0 ", start)
    body = text[start:next_hdr]

    direct = {}  # slot -> set(offset)
    all_slots = set()
    for m in _DIRECT.finditer(body):
        slot = parse_num(m.group("slot"))
        off = parse_num(m.group("off"))
        direct.setdefault(slot, set()).add(off)
        all_slots.add(slot)
    for m in _INDIRECT.finditer(body):
        all_slots.add(parse_num(m.group("slot")))
    # Slot 0 reads via bare `*param_2`. The decompiler emits this
    # form whenever the C code uses `*param_2` (e.g. line 494
    # `fVar60 = *param_2;`) instead of `param_2[0]`.
    if _BARE_DEREF.search(body):
        all_slots.add(0)

    return direct, all_slots


def main():
    direct, all_slots = extract()
    print(f"distinct slots referenced: {len(all_slots)}")
    print(f"direct-copy slots: {len(direct)}")

    rows = ["| Buf slot | Horse struct field(s) | Note |", "|---|---|---|"]
    for slot in sorted(all_slots):
        if slot in direct:
            offs = ", ".join(f"+0x{o:x}" for o in sorted(direct[slot]))
            rows.append(f"| {slot} (0x{slot:x}) | {offs} | direct copy |")
        else:
            rows.append(f"| {slot} (0x{slot:x}) | _(reads only)_ | conditional / intermediate |")
    table = "\n".join(rows)

    md = SLOT_MAP_MD.read_text(encoding="utf-8")
    marker_open = "## Buf-slot -> horse-struct field (consumer reads)"
    marker_close = "## Confirmed visible-effect slots"
    idx_open = md.find(marker_open)
    idx_close = md.find(marker_close)
    if idx_open == -1 or idx_close == -1:
        raise RuntimeError("markers missing in SLOT-MAP.md")
    new_section = (
        f"{marker_open}\n\n"
        f"Auto-derived from `FUN_1400ab3d0` decomp by\n"
        f"`horseygame/extract-consumer-map.py`. Reads {len(all_slots)} distinct\n"
        f"buf slots; {len(direct)} are direct copies to a horse-struct field,\n"
        f"the rest feed conditionals or intermediate math.\n\n"
        f"{table}\n\n"
    )
    md = md[:idx_open] + new_section + md[idx_close:]
    SLOT_MAP_MD.write_text(md, encoding="utf-8")
    print(f"updated {SLOT_MAP_MD}")


if __name__ == "__main__":
    main()
