"""Build docs/GENE-CATALOG.md: one row per gene, all 240.

Merges:
  - vanilla-genes.xml (idx, name, m, s, g0..g3, n)
  - SLOT-MAP gene-table data (re-derives via the same regex as
    extract-slot-map.py for the auto-extracted rows)
  - extract-gene-context.py output (nearby slot writes) to fill
    in genes the simple extractor misses
  - cluster table (functional group)
"""
import re
import xml.etree.ElementTree as ET
from pathlib import Path

ROOT = Path(__file__).resolve().parent
GENES_XML = ROOT / "../docs/vanilla-genes.xml"
ENGINE_C = ROOT / "decompiled/funcs/14009/14009f680_FUN_14009f680.c"
OUT = ROOT / "../docs/GENE-CATALOG.md"

# Functional clusters from SLOT-MAP cluster table.
CLUSTERS = [
    (0, 10, "Body fundamentals"),
    (11, 20, "Body shape modifiers"),
    (21, 33, "Tail"),
    (34, 49, "Legs"),
    (50, 66, "Knee + Arm"),
    (67, 71, "Upper arm"),
    (72, 86, "Neck"),
    (87, 96, "Foot + Hand"),
    (97, 117, "Head + Eye + Brow"),
    (118, 126, "Ear + Teeth"),
    (127, 140, "Mouth + Nose + Antler-precursor"),
    (141, 159, "Antlers"),
    (160, 174, "Hat"),
    (175, 188, "Palette / coloration base"),
    (189, 218, "Colors + patterns + behavioral"),
    (219, 239, "Animation signals"),
]


def cluster_for(idx):
    for lo, hi, name in CLUSTERS:
        if lo <= idx <= hi:
            return name
    return "?"


CALL_RE = re.compile(
    r"FUN_1400a5(?:d20|e00)\s*\(\s*\w+\s*,\s*(0x[0-9a-fA-F]+|\d+)\s*\)"
)
SLOT_WRITE_RE = re.compile(r"param_1\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]\s*=")
BYTE_WRITE_RE = re.compile(r"\(\s*param_1\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)\s*=")
PTR_ALIAS_RE = re.compile(r"^\s*([a-zA-Z_]\w*)\s*=\s*param_1\s*\+\s*(0x[0-9a-fA-F]+|\d+)")
PTR_WRITE_RE = re.compile(r"\*\s*([a-zA-Z_]\w*)\s*=")
EVAL_RE = re.compile(
    r"(?P<var>[a-zA-Z_]\w*)\s*=\s*(?:\(\s*(?:float|int)\s*\)\s*)?"
    r"FUN_1400a5(?:d20|e00)\s*\(\s*\w+\s*,\s*(?P<idx>0x[0-9a-fA-F]+|\d+)\s*\)"
)


def parse_num(s):
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def analyse_engine():
    """Return dict gene_idx -> dict with:
        - call_lines: [int]
        - direct_slots: set of slot ints (slot writes in next 30 lines
                        that reference the var that received the gene)
        - gate_slots: set of slot ints (slot writes inside a conditional
                      block opened by the gene's var)
    """
    lines = ENGINE_C.read_text(encoding="utf-8").splitlines()
    ptr_alias = {}
    for line in lines:
        m = PTR_ALIAS_RE.search(line)
        if m:
            ptr_alias[m.group(1)] = parse_num(m.group(2))

    info = {}
    for i, line in enumerate(lines):
        m = CALL_RE.search(line)
        if not m:
            continue
        idx = parse_num(m.group(1))
        rec = info.setdefault(idx, {"call_lines": [], "direct": set(), "gate": set()})
        rec["call_lines"].append(i + 1)
        # Find the var that received the gene
        em = EVAL_RE.search(line)
        var = em.group("var") if em else None
        # Look-ahead window
        depth = 0
        opened_at_window = False
        for j in range(i, min(len(lines), i + 30)):
            ln = lines[j]
            # Slot writes
            sm = SLOT_WRITE_RE.search(ln)
            if sm:
                slot = parse_num(sm.group(1))
                if var and re.search(rf"\b{re.escape(var)}\b", ln):
                    rec["direct"].add(slot)
                elif var and depth > 0 and opened_at_window:
                    rec["gate"].add(slot)
            bm = BYTE_WRITE_RE.search(ln)
            if bm:
                slot = parse_num(bm.group(1)) // 4
                if var and re.search(rf"\b{re.escape(var)}\b", ln):
                    rec["direct"].add(slot)
                elif var and depth > 0 and opened_at_window:
                    rec["gate"].add(slot)
            pm = PTR_WRITE_RE.search(ln)
            if pm and pm.group(1) in ptr_alias:
                slot = ptr_alias[pm.group(1)]
                if var and depth > 0 and opened_at_window:
                    rec["gate"].add(slot)
            # Track conditional blocks gated by our var
            if var and re.search(rf"if\s*\([^)]*\b{re.escape(var)}\b", ln):
                opened_at_window = True
            # Brace tracking
            depth += ln.count("{") - ln.count("}")
            if depth < 0:
                break
    return info


def main():
    root = ET.fromstring(GENES_XML.read_text(encoding="utf-8"))
    genes = list(root.findall("gene"))
    info = analyse_engine()

    out = []
    out.append("# Gene catalog (all 240 vanilla genes)\n")
    out.append("Auto-generated from `vanilla-genes.xml` plus a flow\n")
    out.append("analysis of `FUN_14009f680`. Regenerate via\n")
    out.append("`research/build-gene-catalog.py`.\n\n")
    out.append("Columns:\n")
    out.append("- **idx**: 0-based position in `vanilla-genes.xml`.\n")
    out.append("- **scale**: 1 = discrete int allele, 100 = continuous/percent.\n")
    out.append("- **g0..g3**: the four allele values (vanilla).\n")
    out.append("- **mut**: mutation % from the XML `m` attribute.\n")
    out.append("- **codon**: 4-letter ACGT mapping (XML `n` attribute).\n")
    out.append("- **slots written**: param_1[N] writes that reference\n")
    out.append("  the temp var receiving the gene value (most reliable).\n")
    out.append("- **slots gated**: param_1[N] writes inside an `if`\n")
    out.append("  block whose condition is the gene's temp var. The\n")
    out.append("  gene doesn't supply the value but does decide *whether*\n")
    out.append("  the write happens.\n")
    out.append("- **calls**: line numbers of `FUN_1400a5d20/e00` calls.\n\n")

    counts = {"unread": 0, "direct": 0, "gate_only": 0, "neither": 0}
    for cluster_lo, cluster_hi, cluster_name in CLUSTERS:
        out.append(f"\n## {cluster_lo}..{cluster_hi}: {cluster_name}\n\n")
        out.append("| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |\n")
        out.append("|---|---|---|---|---|---|---|---|---|---|---|---|\n")
        for i in range(cluster_lo, cluster_hi + 1):
            if i >= len(genes):
                break
            g = genes[i]
            name = g.get("name", "?")
            scale = g.get("s", "")
            g0 = g.get("g0", "")
            g1 = g.get("g1", "")
            g2 = g.get("g2", "")
            g3 = g.get("g3", "")
            mut = g.get("m", "")
            codon = g.get("n", "")
            rec = info.get(i)
            if not rec:
                direct = gate = "_unread_"
                calls = "-"
                counts["unread"] += 1
            else:
                direct = ", ".join(str(s) for s in sorted(rec["direct"])) or "-"
                gate = ", ".join(str(s) for s in sorted(rec["gate"])) or "-"
                calls = ", ".join(f"L{n}" for n in rec["call_lines"])
                if rec["direct"]:
                    counts["direct"] += 1
                elif rec["gate"]:
                    counts["gate_only"] += 1
                else:
                    counts["neither"] += 1
            out.append(
                f"| {i} | `{name}` | {scale} | {g0} | {g1} | {g2} | {g3} | {mut} | {codon} | {direct} | {gate} | {calls} |\n"
            )

    out.append("\n## Summary\n\n")
    out.append(f"- {counts['direct']} genes drive a slot directly\n")
    out.append(f"- {counts['gate_only']} genes only gate slot writes\n")
    out.append(f"- {counts['neither']} genes are read but neither (likely flow through 2+ vars)\n")
    out.append(f"- {counts['unread']} genes are never read by FUN_14009f680\n")

    OUT.write_text("".join(out), encoding="utf-8")
    print(f"wrote {OUT}")
    print(counts)


if __name__ == "__main__":
    main()
