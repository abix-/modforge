"""Regenerate per-function .md docs using deep classification (role + category + domain)."""
import re
import json
from collections import defaultdict
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
CLASS_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/deep_classification.json")
OUT_DIR = Path(r"C:/code/horsey-mods/decompiled/game-funcs")

text = DECOMP.read_text(encoding="utf-8", errors="replace")
func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) \(size=(\d+)\) ============$", re.MULTILINE)
matches = list(func_re.finditer(text))
funcs = {}
for i, m in enumerate(matches):
    addr = int(m.group(1), 16)
    name = m.group(2)
    size = int(m.group(3))
    start = m.end()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    body = text[start:end]
    funcs[addr] = (name, size, body)

game_addrs = set()
for line in NEIGH.read_text().splitlines():
    parts = line.split("\t")
    if parts and parts[0].startswith("0x"):
        game_addrs.add(int(parts[0], 16))

classification = json.loads(CLASS_JSON.read_text(encoding="utf-8"))

call_re = re.compile(r"\bFUN_(140[0-9a-f]+)\s*\(")
callers = defaultdict(set)
callees = defaultdict(set)
for addr, (_, _, body) in funcs.items():
    for m in call_re.finditer(body):
        try:
            t = int(m.group(1), 16)
            if t in funcs:
                callees[addr].add(t)
                callers[t].add(addr)
        except ValueError:
            pass

LITERAL_RE = re.compile(r'"([^"\\\n]{2,80})"')
SYMBOL_RE = re.compile(r"\bs_([A-Za-z0-9_]{2,80})_140[0-9a-f]+\b")


def desymbol(s: str) -> str:
    return s.replace("_", " ").strip()


def extract_strings(body: str) -> list:
    out = []
    seen = set()
    for m in LITERAL_RE.finditer(body):
        s = m.group(1)
        if s not in seen and len(s.strip()) >= 2:
            seen.add(s)
            out.append(s)
    for m in SYMBOL_RE.finditer(body):
        s = desymbol(m.group(1))
        if s not in seen and len(s.strip()) >= 2:
            seen.add(s)
            out.append(s)
    return out


def compact_body(body: str) -> str:
    lines = body.split("\n")
    while lines and (lines[0].startswith("// =") or not lines[0].strip()):
        lines = lines[1:]
    out = []
    blank = 0
    for ln in lines:
        if not ln.strip():
            blank += 1
            if blank <= 1:
                out.append(ln)
        else:
            blank = 0
            out.append(ln)
    return "\n".join(out)


CAT_DESC = {
    "trap_stub": "Trap/halt instruction (unreachable)",
    "empty_stub": "Sub-8-byte stub (typically a `ret` or jmp)",
    "getter": "Returns a struct field at a fixed offset",
    "setter": "Writes a struct field at a fixed offset",
    "simple_return": "Short function whose body is just a return",
    "wrapper": "Tiny wrapper that delegates to one other function",
    "compound_wrapper": "Sequenced calls to a few other functions",
    "struct_init": "Zero-initializes consecutive struct fields (constructor-like)",
    "destructor_like": "Frees / deletes resources",
    "repeated_op": "Calls one function many times (vector init or batch op)",
    "float_math": "Float-heavy math (geometry / physics / genetics)",
    "float_math_complex": "Heavy float math + many constants (likely main calc)",
    "iterates_horse_list_0xb8": "Iterates the horse list at obj+0xb8/+0xc0",
    "iterates_horse_list_0x26": "Iterates a horse list at param[0x26]/param[0x27]",
    "plays_sound_or_event": "Triggers a named sound/event",
    "switch_dispatcher": "Multi-way switch / dispatch",
    "loop_heavy": "Large loop-containing function",
    "medium_loop": "Moderate loop-containing function",
    "string_builder": "Builds a string via repeated copy/concat",
    "struct_handler": "Many field accesses on a struct pointer",
    "helper": "General helper (calls other funcs, no idiom matched)",
    "unclassified": "No idiom matched",
}

DOMAIN_DESC = {
    "fatigue": "fatigue/tiredness mechanic",
    "aging": "aging / retirement / lifecycle",
    "hunger": "hunger / feeding",
    "death": "horse death handling",
    "race": "racing / betting / champion",
    "save_io": "save file IO",
    "settings_io": "settings.xml IO",
    "genetics": "gene / chromosome / DNA / CRISPR",
    "sleep_wake": "sleep cycle",
    "breeding": "breeding / mating / foaling",
    "debug": "debug-mode plumbing",
    "world_event": "world location / event / action",
    "data_loading": "data file loaders",
}


written = 0
for addr in sorted(game_addrs):
    if addr not in funcs:
        continue
    name, size, body = funcs[addr]
    key = f"0x{addr:x}"
    cls = classification.get(key, {})
    role = cls.get("role")
    category = cls.get("category", "unclassified")
    evidence = cls.get("evidence", "")
    domain = cls.get("domain")

    # Compose the "Role" line
    role_parts = []
    if role:
        role_parts.append(f"**Role**: `{role}` (string-anchored)")
    if domain:
        role_parts.append(f"**Domain**: `{domain}` - {DOMAIN_DESC.get(domain, '')}")
    role_parts.append(f"**Pattern**: `{category}` - {CAT_DESC.get(category, '')}")
    if evidence:
        role_parts.append(f"**Evidence**: {evidence}")

    strings = extract_strings(body)
    game_callers = sorted(callers.get(addr, set()) & game_addrs)
    game_callees = sorted(callees.get(addr, set()) & game_addrs)
    vendor_callees = sorted(callees.get(addr, set()) - game_addrs)

    fname = f"{addr:x}_{re.sub(r'[^A-Za-z0-9_-]', '_', name)[:80]}.md"
    out_path = OUT_DIR / fname

    lines = [f"# `{name}` @ 0x{addr:x}", ""]
    lines.append(f"**Size**: {size} bytes")
    for rp in role_parts:
        lines.append(rp)
    if strings:
        lines.append("")
        lines.append("**Strings referenced**:")
        for s in strings[:20]:
            lines.append(f"- `{s!r}`")
        if len(strings) > 20:
            lines.append(f"- ... ({len(strings) - 20} more)")
    lines.append("")
    if game_callers:
        lines.append(f"**Game callers** ({len(game_callers)}): " +
                     ", ".join(f"[`FUN_{c:x}`]({c:x}_FUN_{c:x}.md)" for c in game_callers[:10]))
        if len(game_callers) > 10:
            lines.append(f"  ... +{len(game_callers)-10} more")
    else:
        lines.append("**Game callers**: none (entry point or vendor-called only)")
    lines.append("")
    if game_callees:
        lines.append(f"**Game callees** ({len(game_callees)}): " +
                     ", ".join(f"[`FUN_{c:x}`]({c:x}_FUN_{c:x}.md)" for c in game_callees[:10]))
        if len(game_callees) > 10:
            lines.append(f"  ... +{len(game_callees)-10} more")
    else:
        lines.append("**Game callees**: none (leaf function)")
    lines.append("")
    lines.append(f"**Vendor callees**: {len(vendor_callees)} (SDL/CRT/etc, not shown)")
    lines.append("")
    lines.append("## Decompiled")
    lines.append("")
    lines.append("```c")
    lines.append(compact_body(body).rstrip())
    lines.append("```")

    out_path.write_text("\n".join(lines), encoding="utf-8")
    written += 1

print(f"Rewrote {written} per-function docs with role + category + domain")

# Update INDEX with new info
docs = []
for addr in sorted(game_addrs):
    name, size, body = funcs[addr]
    cls = classification.get(f"0x{addr:x}", {})
    docs.append({
        "addr": addr, "name": name, "size": size,
        "role": cls.get("role"),
        "category": cls.get("category"),
        "domain": cls.get("domain"),
        "n_callers": len(callers.get(addr, set()) & game_addrs),
        "n_callees": len(callees.get(addr, set()) & game_addrs),
    })

# INDEX sorted by size descending
index = ["# Game-logic function index", ""]
index.append(f"Total: {len(docs)} game-logic functions, sorted by body size (largest first).")
index.append("")
index.append("Columns: # | address | name | size (bytes) | callers | callees | role | domain | pattern")
index.append("")
index.append("| # | Addr | Name | Size | C-in | C-out | Role | Domain | Pattern |")
index.append("|---|---|---|---|---|---|---|---|---|")
for i, d in enumerate(sorted(docs, key=lambda x: -x["size"]), 1):
    addr = d["addr"]
    fname = f"{addr:x}_{re.sub(r'[^A-Za-z0-9_-]', '_', d['name'])[:80]}.md"
    role = (d["role"] or "").replace("|", "\\|") or "-"
    domain = d["domain"] or "-"
    cat = d["category"] or "-"
    index.append(f"| {i} | [0x{addr:x}]({fname}) | `{d['name']}` | {d['size']} | {d['n_callers']} | {d['n_callees']} | {role} | {domain} | {cat} |")

(OUT_DIR / "INDEX.md").write_text("\n".join(index), encoding="utf-8")
print("Wrote INDEX.md")
