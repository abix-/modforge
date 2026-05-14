"""Pattern-based classification of game functions.

We detect common idioms in the decompiled output and emit precise classifications.
For each function we produce a classification + evidence.
"""
import re
from pathlib import Path
from collections import defaultdict, Counter

NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
OUT = Path(r"C:/code/horsey-mods/decompiled/game-funcs/CLASSIFICATION.md")
OUT_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/classification.json")

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


# --- Classifiers ---

def classify(body: str, size: int) -> tuple[str, str]:
    """Return (category, evidence)."""

    # Strip comments/whitespace for some checks
    lines = [ln for ln in body.split("\n") if ln.strip() and not ln.strip().startswith("//") and not ln.strip().startswith("/*")]
    code = "\n".join(lines)

    # 1. Bad-instruction trap stubs
    if "halt_baddata" in body or "Bad instruction" in body:
        return ("trap_stub", "halt_baddata or bad-instruction marker")

    # 2. Returns nothing, only function-call chains => thunk/wrapper
    if size <= 16:
        m_thunk = re.search(r"FUN_(140[0-9a-f]+)\s*\(", code)
        if m_thunk and "return" not in code and code.count("{") <= 2:
            return ("thunk", f"single delegated call -> FUN_{m_thunk.group(1)}")

    # 3. Simple getter: returns *(type*)(this+offset)
    # Detect: function body that's basically `return *(int *)(param_1 + 0xN);`
    m_getter = re.search(r"^\s*return\s+\*\(.*?\)\s*\(\s*param_\d\s*\+\s*(0x[0-9a-f]+|\d+)\s*\)\s*;", code, re.MULTILINE)
    if m_getter and size <= 64:
        return ("getter", f"returns field at offset {m_getter.group(1)}")

    # 4. Simple setter: *(type*)(this+offset) = paramN;
    m_setter = re.search(r"^\s*\*\(.*?\)\s*\(\s*param_\d\s*\+\s*(0x[0-9a-f]+|\d+)\s*\)\s*=\s*param_\d", code, re.MULTILINE)
    if m_setter and size <= 96 and "return" not in code.lower():
        return ("setter", f"writes field at offset {m_setter.group(1)}")

    # 5. Destructor pattern: ~ClassName or 'free'+'delete' calls
    if size <= 256 and ("operator_delete" in body or "destructor" in body.lower()):
        return ("destructor", "deletes resources")

    # 6. Constructor pattern: initializes consecutive fields
    init_count = len(re.findall(r"\*\(.*?\)\s*\(\s*param_\d\s*\+\s*0x[0-9a-f]+\s*\)\s*=\s*0", code))
    if init_count >= 3 and size <= 256:
        return ("init_struct", f"zero-initializes {init_count} fields")

    # 7. std::string / vector helpers (often have specific patterns)
    if "FUN_140" in body:
        callees = re.findall(r"FUN_(140[0-9a-f]+)", body)
        callee_count = Counter(callees)
        if callee_count and size <= 256:
            top_callee, n = callee_count.most_common(1)[0]
            if n >= 3:
                return ("repeated_call_helper", f"calls FUN_{top_callee} x{n}")

    # 8. Floating-point math heavy (>= 8 distinct float ops)
    n_float = len(re.findall(r"\b(fVar\d+|local_res\w+)\b", code))
    if n_float >= 16 and size > 200:
        return ("float_math_heavy", f"{n_float} float vars (geometry/physics/genetics?)")

    # 9. Loops over a vector<>: `*(longlong *)(p+0xb8)` then `*(longlong *)(p+0xc0) - ...`
    if re.search(r"\*\(.*?\*\s*\*\)\(.*?\+\s*0xb8.*?\*\(.*?\*\s*\*\)\(.*?\+\s*0xc0", code, re.DOTALL):
        return ("iterates_horse_list", "iterates vector at param+0xb8..param+0xc0 (the horse list)")

    # 10. References sound system: FUN_xxxx with sound name as 2nd arg
    sound_call_re = re.search(r'FUN_(140[0-9a-f]+)\s*\([^)]*"([A-Z][A-Za-z]+)"', code)
    if sound_call_re:
        return ("plays_sound", f"sound={sound_call_re.group(2)!r}")

    # 11. Pure switch/jump table (lots of `case` or labeled gotos)
    n_case = code.count("case ")
    if n_case >= 5:
        return ("switch_dispatcher", f"{n_case} case branches")

    # 12. Has a big loop, mid-sized
    if "while " in code or "do {" in code or "for " in code:
        if size >= 500:
            return ("iterates_logic", "contains a loop")

    # 13. String/text builder via repeated puts/appends
    n_puts = code.count("strncpy") + code.count("strcat") + code.count("snprintf")
    if n_puts >= 3:
        return ("string_builder", f"{n_puts} string ops")

    return ("unclassified", "")


classifications = {}
for addr in sorted(game_addrs):
    if addr not in funcs:
        continue
    name, size, body = funcs[addr]
    cat, evidence = classify(body, size)
    classifications[addr] = (name, size, cat, evidence)

# Stats
cats = Counter(c[2] for c in classifications.values())
print("Classification distribution:")
for cat, n in cats.most_common():
    print(f"  {n:>4d}  {cat}")

# Write Markdown table and JSON
out_lines = ["# Game function classification", ""]
out_lines.append(f"Total game-logic functions: {len(classifications)}")
out_lines.append("")
out_lines.append("Categories detected by pattern matching on decompiled bodies.")
out_lines.append("")
out_lines.append("| Category | Count | Description |")
out_lines.append("|---|---|---|")
CAT_DESC = {
    "trap_stub": "Compiler-emitted trap / halt instruction",
    "thunk": "Tiny wrapper that forwards to another function",
    "getter": "Returns a struct field at a fixed offset",
    "setter": "Writes a struct field at a fixed offset",
    "destructor": "Frees resources (operator_delete / cleanup)",
    "init_struct": "Zero-initializes consecutive struct fields (constructor-like)",
    "repeated_call_helper": "Calls one function multiple times (vector init, copy)",
    "float_math_heavy": "Heavy floating-point math (geometry / physics / genetics)",
    "iterates_horse_list": "Iterates the horse vector at obj+0xb8..obj+0xc0",
    "plays_sound": "Triggers a named sound by string",
    "switch_dispatcher": "Multi-way switch / dispatch table",
    "iterates_logic": "Large loop-containing function",
    "string_builder": "Builds a string via repeated copy/concat ops",
    "unclassified": "No idiom detected (needs manual reading)",
}
for cat, n in cats.most_common():
    out_lines.append(f"| `{cat}` | {n} | {CAT_DESC.get(cat, '')} |")

out_lines.append("")
out_lines.append("## Sample for each category")
out_lines.append("")
by_cat = defaultdict(list)
for addr, (name, size, cat, ev) in classifications.items():
    by_cat[cat].append((addr, name, size, ev))

for cat in sorted(by_cat):
    items = sorted(by_cat[cat], key=lambda x: -x[2])
    out_lines.append(f"### `{cat}` ({len(items)} functions)")
    out_lines.append("")
    out_lines.append("| Address | Name | Size | Evidence |")
    out_lines.append("|---|---|---|---|")
    for addr, name, size, ev in items[:15]:
        out_lines.append(f"| 0x{addr:x} | `{name}` | {size} | {ev} |")
    if len(items) > 15:
        out_lines.append(f"| ... | ... | ... | +{len(items)-15} more |")
    out_lines.append("")

OUT.write_text("\n".join(out_lines), encoding="utf-8")
print(f"\nWrote {OUT}")

import json
data = {f"0x{a:x}": dict(name=n, size=s, category=c, evidence=e)
        for a, (n, s, c, e) in classifications.items()}
OUT_JSON.write_text(json.dumps(data, indent=2), encoding="utf-8")
print(f"Wrote {OUT_JSON}")
