"""Probe how each gene index is used inside FUN_14009f680.

For every call site `FUN_1400a5d20(_, IDX)` or `FUN_1400a5e00(_, IDX)`
in the engine, capture the surrounding context (line + the assignment
target or conditional it feeds into).

Goal: understand the 74 genes the v2 slot extractor misses. Output is
a TSV per-gene listing every call site + a coarse category label.
"""

import re
import xml.etree.ElementTree as ET
from pathlib import Path

ROOT = Path(__file__).resolve().parent
GENES_XML = ROOT / "../docs/vanilla-genes.xml"
ENGINE_C = ROOT / "decompiled/funcs/14009/14009f680_FUN_14009f680.c"

UNMAPPED = set("""AGOUTI ALT_BLUE ARM_STRETCH ARM_STRETCH2 ASPECT BASE_BLACK BASE_BROWN
BASE_CREAM BASE_GREEN BASE_RED BIPED BONES BONES2 BRAIN_SPASTIC BUGEYE CHEST_SMALL
ELBOW_RANGE EYEBOX_SIZE EYE_HUE FLU_IMMUNITY FOOT_BACKWARDS FOOT_IS_CIRCLE
FOOT_IS_HOOF GREEN_KNOCKOUT HAS_ANTLERS HAS_ELBOW HAS_KNEE HAS_MOUTH HAS_PUPIL
HAT_EXISTS HAT_POM_IS_LID HEAD_ASPECT HEAD_CHIMERA HEAD_JOINTED HEAD_SHRUNK
HEAD_SIZE HEAD_SQUARE HEAD_THICK_SKULL HIGH_INTELLECT KNEE_MAX KNEE_MIN
LEG_IS_CIRCLE LEG_PENCIL LEG_THRUST_BACK LIMP LOCO_SYNC NARCOLEPSY NECK_ONTOP
NECK_SLOUCH NOSE_HUE NOSE_INNY NOSE_SIZE POM_USECOLOR RAMPAGE SIZE SKINNY
SKIN_HANDS SKIN_HEAD SKIN_HUE SKIN_HUE2 SPINAL_LOCO SPOT_YELLOW SWAP_ALT_SPOT
SWAP_BASE_SPOT TAIL_ALT TAIL_BOTTOM TAIL_SEGMENTS TAIL_WAG TEETH_UPPER
TEETH_UPPER2 UPARM_GOOFY UPARM_Y WHITE WHITE_IS_LETHAL""".split())


def load_names():
    root = ET.fromstring(GENES_XML.read_text(encoding="utf-8"))
    return [g.get("name", "?") for g in root.findall("gene")]


CALL_RE = re.compile(
    r"FUN_1400a5(?:d20|e00)\s*\(\s*\w+\s*,\s*(0x[0-9a-fA-F]+|\d+)\s*\)"
)


def parse_num(s):
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def categorize(line, line_above):
    line = line.strip()
    above = line_above.strip()
    if re.match(r"\s*if\s*\(", line) or "?" in line and ":" in line:
        return "conditional"
    if re.match(r"\s*[a-zA-Z_]\w*\s*=\s*\(\s*int\s*\)", line):
        return "int-cast assign"
    if "param_1[" in line or "param_1 +" in line:
        return "direct-or-ptr-write"
    if re.match(r"\s*[a-zA-Z_]\w*\s*=\s*", line):
        return "var-assign"
    return "other"


def main():
    names = load_names()
    name_to_idx = {n: i for i, n in enumerate(names)}
    unmapped_idxs = sorted({name_to_idx[n] for n in UNMAPPED if n in name_to_idx})
    print(f"unmapped indices: {len(unmapped_idxs)}")

    lines = ENGINE_C.read_text(encoding="utf-8").splitlines()

    by_idx = {}
    for i, line in enumerate(lines):
        for m in CALL_RE.finditer(line):
            idx = parse_num(m.group(1))
            cat = categorize(line, lines[i - 1] if i else "")
            by_idx.setdefault(idx, []).append((i + 1, cat, line.strip()))

    print(f"distinct indices called: {len(by_idx)}")

    out = ROOT / "gene-usage-probe.tsv"
    with out.open("w", encoding="utf-8") as f:
        f.write("idx\tname\tunmapped\tcall_count\tcategories\tfirst_line\tfirst_context\n")
        for idx in range(len(names)):
            name = names[idx]
            calls = by_idx.get(idx, [])
            cats = sorted(set(c for _, c, _ in calls))
            first_ln = calls[0][0] if calls else ""
            first_ctx = (calls[0][2][:140] if calls else "").replace("\t", " ")
            f.write(f"{idx}\t{name}\t{'Y' if name in UNMAPPED else ''}\t{len(calls)}\t{','.join(cats)}\t{first_ln}\t{first_ctx}\n")
    print(f"wrote {out}")

    # Detail view: list every site for unmapped genes
    detail = ROOT / "gene-usage-detail.txt"
    with detail.open("w", encoding="utf-8") as f:
        for idx in unmapped_idxs:
            name = names[idx]
            calls = by_idx.get(idx, [])
            f.write(f"\n## {idx:3d}  {name}  ({len(calls)} calls)\n")
            for ln, cat, txt in calls:
                f.write(f"  L{ln}  [{cat}]  {txt}\n")
    print(f"wrote {detail}")


if __name__ == "__main__":
    main()
