"""Extract gene_idx -> buf_slot mappings from FUN_14009f680's decomp.

Reads:
  - vanilla-genes.xml      (gene names by index)
  - decompiled/all_functions.c (the engine source)

Writes:
  - SLOT-MAP.md table rows showing which gene index drives
    which `param_1[N]` write, and through what arithmetic.

Strategy: light flow analysis of the decompiler's
generated C. We track each `fVarN = ... FUN_1400a5d20(local_X, K)`
or `FUN_1400a5e00(local_X, K)` assignment, then any
`param_1[N] = expr` where `expr` mentions the tracked var.

Limitations:
  - Misses multi-step expressions where the gene value
    flows through > 1 temp variable
  - Misses indirect writes (e.g. `*(float*)(param_1 + offset*4)`)
  - Doesn't handle conditional writes well; reports all
    writes regardless of branch

These are acceptable for the v1 map. Borderline cases get
flagged as `(complex)` in the "How combined" column and are
worth a manual re-read.
"""

import re
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

ROOT = Path(__file__).resolve().parent
GENES_XML = ROOT / "vanilla-genes.xml"
ALL_FUNCS = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
SLOT_MAP_MD = ROOT / "SLOT-MAP.md"


def load_gene_names():
    """Return list of gene names in index order from genes.xml."""
    text = GENES_XML.read_text(encoding="utf-8")
    # The XML root element is `<exp>` with 240 `<gene>` children.
    # ElementTree handles the structure fine.
    root = ET.fromstring(text)
    names = []
    for g in root.findall("gene"):
        names.append(g.get("name", "?"))
    return names


def extract_function_body(path, fn_addr):
    """Pull a single function's body out of the all-functions C file.

    Returns the lines between the function's `// ============` header
    and the next function's header, exclusive.
    """
    text = path.read_text(encoding="utf-8")
    lines = text.splitlines()
    start_marker = f"// ============ 0x{fn_addr:x} "
    start = None
    for i, line in enumerate(lines):
        if line.startswith(start_marker):
            start = i
            break
    if start is None:
        raise RuntimeError(f"function 0x{fn_addr:x} not found in {path}")
    # Next function header.
    end = start + 1
    while end < len(lines) and not lines[end].startswith("// ============"):
        end += 1
    return lines[start:end]


_HEX = r"0x[0-9a-fA-F]+"
_INT = r"\d+"
_NUM = rf"(?:{_HEX}|{_INT})"

# fVar99 = (float)FUN_1400a5d20(local_508, 0x53);
_EVAL_RE = re.compile(
    rf"^\s*(?P<var>[a-zA-Z_][\w]*)\s*=\s*"
    rf"(?:\(\s*float\s*\)\s*|\(\s*int\s*\)\s*)?"
    rf"FUN_1400a5(?:d20|e00)\s*\(\s*\w+\s*,\s*(?P<idx>{_NUM})\s*\)\s*;"
)

# `var = expr;` where expr might combine other tracked vars.
# Used to propagate gene-derived values through temp-var chains.
_VAR_ASSIGN_RE = re.compile(
    rf"^\s*(?P<var>[a-zA-Z_][\w]*)\s*=\s*(?P<rhs>[^;]+);"
)

# param_1[N] = something_that_might_reference_var;
_PARAM1_WRITE_RE = re.compile(
    rf"^\s*param_1\[\s*(?P<slot>{_NUM})\s*\]\s*=\s*(?P<rhs>.+?);"
)

# `*pfVar24 = expr;`. Write via a pointer alias we've already
# observed as `pfVar24 = param_1 + N;`.
_POINTER_WRITE_RE = re.compile(
    rf"^\s*\*\s*(?P<ptr>[a-zA-Z_][\w]*)\s*=\s*(?P<rhs>[^;]+);"
)

# `pfVar24 = param_1 + N;` pointer alias.
_POINTER_ALIAS_RE = re.compile(
    rf"^\s*(?P<ptr>[a-zA-Z_][\w]*)\s*=\s*param_1\s*\+\s*(?P<slot>{_NUM})\s*;"
)

# Byte-level write into a slot: `*(undefined1*)(param_1 + 0xMM) = expr;`
# Maps to slot floor(0xMM / 4).
_BYTE_WRITE_RE = re.compile(
    rf"^\s*\*\(\s*(?:undefined\d|bool|char|int|float)\s*\*\s*\)\s*"
    rf"\(\s*param_1\s*\+\s*(?P<byte_off>{_NUM})\s*\)\s*=\s*(?P<rhs>[^;]+);"
)

# direct one-liner: param_1[N] = (float)FUN_1400a5d20(local_X, K);
_DIRECT_RE = re.compile(
    rf"^\s*param_1\[\s*(?P<slot>{_NUM})\s*\]\s*=\s*"
    rf"(?:\(\s*float\s*\)\s*)?FUN_1400a5(?:d20|e00)\s*\(\s*\w+\s*,\s*(?P<idx>{_NUM})\s*\)\s*;"
)


def parse_num(s):
    s = s.strip()
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def extract_mappings(body_lines):
    """Return list of (gene_idx, slot, how_combined) tuples.

    v2: tracks multi-step variable mutations, pointer aliases
    `pfVarN = param_1 + N`, and byte-level writes.

    For each tracked variable we keep a set of gene indices that
    have contributed to its current value. When the var is mutated
    (`var = var + something`), the set persists. When the var is
    reassigned without referencing itself, the set is replaced.
    """
    var_genes = {}  # var_name -> set of gene_idx that contributed
    ptr_to_slot = {}  # ptr_name -> slot index (from pfVar = param_1 + N)
    mappings = []

    def record(slot, rhs_text, hits_iterable, slot_repr=None):
        if not hits_iterable:
            return
        hits = list(hits_iterable)
        s = slot_repr if slot_repr is not None else slot
        if len(hits) == 1:
            idx = hits[0]
            style = (
                "via var"
                if rhs_text.strip().isidentifier()
                else f"via expr: {rhs_text.strip()[:60]}"
            )
            mappings.append((idx, s, style))
        else:
            for idx in hits:
                mappings.append(
                    (idx, s, f"combined-with-others ({rhs_text.strip()[:60]})")
                )

    def hits_in_rhs(rhs):
        out = set()
        for v, idxs in var_genes.items():
            if re.search(rf"\b{re.escape(v)}\b", rhs):
                out.update(idxs)
        return out

    for line in body_lines:
        # Direct write first.
        m = _DIRECT_RE.search(line)
        if m:
            mappings.append(
                (parse_num(m.group("idx")), parse_num(m.group("slot")), "direct")
            )
            continue
        # Track temp-var assignments from gene calls.
        m = _EVAL_RE.search(line)
        if m:
            var_genes[m.group("var")] = {parse_num(m.group("idx"))}
            continue
        # Pointer aliases.
        m = _POINTER_ALIAS_RE.search(line)
        if m:
            ptr_to_slot[m.group("ptr")] = parse_num(m.group("slot"))
            continue
        # Byte-level write.
        m = _BYTE_WRITE_RE.search(line)
        if m:
            byte_off = parse_num(m.group("byte_off"))
            slot = byte_off // 4
            rhs = m.group("rhs")
            record(
                slot,
                rhs,
                hits_in_rhs(rhs),
                slot_repr=f"{slot} (byte-offset 0x{byte_off:x})",
            )
            continue
        # Param writes.
        m = _PARAM1_WRITE_RE.search(line)
        if m:
            slot = parse_num(m.group("slot"))
            rhs = m.group("rhs")
            # If the RHS references the var being assigned (var = var + other),
            # we handle that below in the var-assign branch. Otherwise normal.
            record(slot, rhs, hits_in_rhs(rhs))
            continue
        # Pointer-deref write.
        m = _POINTER_WRITE_RE.search(line)
        if m:
            ptr = m.group("ptr")
            if ptr in ptr_to_slot:
                slot = ptr_to_slot[ptr]
                rhs = m.group("rhs")
                record(slot, rhs, hits_in_rhs(rhs))
            continue
        # Generic var assignment: ONLY use to CLEAR stale tracking
        # when a var is reassigned. We do NOT propagate gene credit
        # through multi-step var chains. Pilot runs showed that
        # creates huge false positives: any gene that ever touched
        # fVar33 gets credited to every slot that ever used fVar33,
        # even after fVar33 was overwritten.
        #
        # Trade-off: we miss real multi-step dependencies (gene 3
        # feeds slot 0 via the SQRT formula). Those are documented
        # narratively in "Engine internals" instead.
        m = _VAR_ASSIGN_RE.search(line)
        if m:
            dest = m.group("var")
            rhs = m.group("rhs")
            self_ref = bool(re.search(rf"\b{re.escape(dest)}\b", rhs))
            if not self_ref and dest in var_genes:
                hits = hits_in_rhs(rhs)
                if hits:
                    var_genes[dest] = set(hits)
                else:
                    del var_genes[dest]

    return mappings


def main():
    names = load_gene_names()
    print(f"loaded {len(names)} gene names")

    body = extract_function_body(ALL_FUNCS, 0x14009F680)
    print(f"extracted FUN_14009f680: {len(body)} lines")

    mappings = extract_mappings(body)
    print(f"found {len(mappings)} (gene_idx -> slot) mappings")

    # Dedupe + sort by gene_idx, slot.
    seen = set()
    unique = []
    for idx, slot, how in mappings:
        key = (idx, slot, how)
        if key in seen:
            continue
        seen.add(key)
        unique.append(key)
    unique.sort(key=lambda t: (t[0], str(t[1]), t[2]))
    print(f"after dedupe: {len(unique)} rows")

    # Group by gene_idx so we can show all slots a gene drives.
    by_gene = {}
    for idx, slot, how in unique:
        by_gene.setdefault(idx, []).append((slot, how))
    print(f"distinct genes referenced: {len(by_gene)} / {len(names)}")

    # Emit markdown table.
    lines = []
    lines.append("| Gene idx | Gene name | Buf slot(s) | How |")
    lines.append("|---|---|---|---|")
    for idx in sorted(by_gene):
        name = names[idx] if 0 <= idx < len(names) else "?"
        slots_str = ", ".join(f"{s} ({h})" for s, h in by_gene[idx])
        lines.append(f"| {idx} | `{name}` | {slots_str} | |")
    table = "\n".join(lines)

    # Patch into SLOT-MAP.md replacing the placeholder.
    md = SLOT_MAP_MD.read_text(encoding="utf-8")
    marker_open = "## Gene-index -> buf-slot map (engine writes)"
    marker_close = "## Buf-slot -> horse-struct field (consumer reads)"
    idx_open = md.find(marker_open)
    idx_close = md.find(marker_close)
    if idx_open == -1 or idx_close == -1:
        raise RuntimeError("markers not found in SLOT-MAP.md")
    new_section = (
        f"{marker_open}\n\n"
        f"Auto-derived from `FUN_14009f680` decomp by\n"
        f"`horsey-mod/research/extract-slot-map.py`. {len(by_gene)} of "
        f"{len(names)} vanilla genes drive at least one buf slot.\n"
        f"`(via fVarX)` means the gene's value passes through a\n"
        f"temp variable. `(combined-with-others ...)` means the\n"
        f"slot's value is a multi-gene expression; the row is\n"
        f"a candidate, manual re-read recommended.\n\n"
        f"{table}\n\n"
    )
    md = md[:idx_open] + new_section + md[idx_close:]
    SLOT_MAP_MD.write_text(md, encoding="utf-8")
    print(f"updated {SLOT_MAP_MD}")


if __name__ == "__main__":
    main()
