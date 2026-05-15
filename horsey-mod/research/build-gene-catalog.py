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
    """Return dict gene_idx -> dict with call_lines, direct, gate.

    For each call site, scan forward until either the var is reassigned
    to something unrelated or we have left the function. Inside that
    range:
      - Direct: any slot write whose line text references the var.
      - Gate: any slot write while inside an `if (... var ...) { ... }`
        block. Brace-scoped; nested braces tracked. Reassignment of the
        var to another gene-call clears the gate context.
    """
    lines = ENGINE_C.read_text(encoding="utf-8").splitlines()
    ptr_alias = {}
    for line in lines:
        m = PTR_ALIAS_RE.search(line)
        if m:
            ptr_alias[m.group(1)] = parse_num(m.group(2))

    info = {}
    REASSIGN_RE = lambda v: re.compile(rf"^\s*{re.escape(v)}\s*=")

    for i, line in enumerate(lines):
        m = CALL_RE.search(line)
        if not m:
            continue
        idx = parse_num(m.group(1))
        rec = info.setdefault(idx, {"call_lines": [], "direct": set(), "gate": set()})
        rec["call_lines"].append(i + 1)
        em = EVAL_RE.search(line)
        var = em.group("var") if em else None
        if not var:
            continue

        # Scan forward up to 500 lines. Stop when var is reassigned to
        # a non-gene-call value, or when we exit the function (depth <
        # the initial depth at the call line).
        gate_depths = []  # stack of depths at which gate-opening ifs fired
        depth = 0
        for j in range(i + 1, min(len(lines), i + 500)):
            ln = lines[j]

            # Slot writes
            for rx, kind in ((SLOT_WRITE_RE, "slot"), (BYTE_WRITE_RE, "byte"), (PTR_WRITE_RE, "ptr")):
                sm = rx.search(ln)
                if not sm:
                    continue
                raw = sm.group(1)
                if kind == "ptr":
                    if raw not in ptr_alias:
                        continue
                    slot = ptr_alias[raw]
                elif kind == "byte":
                    slot = parse_num(raw) // 4
                else:
                    slot = parse_num(raw)
                if re.search(rf"\b{re.escape(var)}\b", ln):
                    rec["direct"].add(slot)
                elif gate_depths:
                    rec["gate"].add(slot)
                break

            # Conditional that uses our var
            if re.search(rf"if\s*\([^)]*\b{re.escape(var)}\b", ln):
                gate_depths.append(depth)

            # Brace tracking
            delta = ln.count("{") - ln.count("}")
            depth += delta
            # Close any gate whose anchor depth is now above current depth
            gate_depths = [d for d in gate_depths if d < depth]

            # Stop only if the var is reassigned to a DIFFERENT gene call
            # (carries another gene's value from here). Plain reassign
            # (var = expr without FUN_1400a5*) doesn't immediately revoke
            # existing gates; we still want to credit writes inside those.
            r = REASSIGN_RE(var).match(ln)
            if r and "FUN_1400a5d20" in ln or (r and "FUN_1400a5e00" in ln):
                em2 = EVAL_RE.search(ln)
                if em2 and parse_num(em2.group("idx")) != idx:
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
