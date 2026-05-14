"""Re-generate per-function docs with the smart classification baked in."""
import re
import json
from collections import defaultdict
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
CLASS_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/classification.json")
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

# Call graph
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
    "trap_stub": "Compiler-emitted trap / halt instruction",
    "thunk": "Tiny wrapper that forwards to another function",
    "getter": "Returns a struct field at a fixed offset",
    "setter": "Writes a struct field at a fixed offset",
    "destructor": "Frees resources",
    "init_struct": "Zero-initializes consecutive struct fields",
    "repeated_call_helper": "Calls one function multiple times",
    "float_math_heavy": "Heavy floating-point math (geometry/physics/genetics)",
    "iterates_horse_list": "Iterates the horse vector at obj+0xb8..obj+0xc0",
    "plays_sound": "Triggers a named sound",
    "switch_dispatcher": "Multi-way switch / dispatch table",
    "iterates_logic": "Large loop-containing function",
    "string_builder": "Builds a string via copy/concat ops",
    "unclassified": "No idiom detected (needs manual reading)",
}


def role_from_strings(strings, name, size):
    s_lower = " ".join(strings).lower()
    if "horse is too tired" in s_lower or "tired looking" in s_lower or "rest your horse" in s_lower:
        return "fatigue/stamina check (gates racing on horse tiredness)"
    if "horse is too old" in s_lower or "too old to race" in s_lower:
        return "age gate"
    if "horse is too young" in s_lower:
        return "age gate (rejects too-young)"
    if "horse is too hungry" in s_lower or "feed it first" in s_lower:
        return "hunger gate"
    if "retired" in s_lower and ("old" in s_lower or "bails" in s_lower or "useless" in s_lower):
        return "retirement handler"
    if "getting old" in s_lower and "offer" in s_lower:
        return "horse sale dialog"
    if "genome copied" in s_lower or "pasting genome" in s_lower:
        return "genome clipboard serializer"
    if "chromomap" in s_lower or "chromosome" in s_lower:
        return "gene/chromosome table"
    if 'save%d.dat' in " ".join(strings):
        return "save file path / loader / writer"
    if "settings.xml" in " ".join(strings):
        return "settings xml read/write"
    if "genes.dat" in " ".join(strings):
        return "genes.dat cache"
    if "simulation paused" in s_lower:
        return "debug: year/sleeps/races status"
    if "click race when ready" in s_lower:
        return "race start prompt"
    if "rand" in s_lower and "nice" in s_lower and "record" in s_lower and "years" in s_lower:
        return "horse price/score formula"
    if "horses: %d" in s_lower and "bails" in s_lower:
        return "debug: horse roster stats"
    if "year %d" in s_lower and "gendiv" in s_lower:
        return "debug: population stats"
    return None


written = 0
for addr in sorted(game_addrs):
    if addr not in funcs:
        continue
    name, size, body = funcs[addr]
    strings = extract_strings(body)

    # Best role: string-based if specific, else category
    role_str = role_from_strings(strings, name, size)
    key = f"0x{addr:x}"
    cls = classification.get(key, {"category": "unclassified", "evidence": ""})
    category = cls["category"]
    evidence = cls["evidence"]

    if role_str:
        role_line = f"**Role**: {role_str}  _(string-anchored)_"
    elif category != "unclassified":
        role_line = f"**Role**: `{category}` - {CAT_DESC[category]}"
        if evidence:
            role_line += f"  _(evidence: {evidence})_"
    else:
        role_line = "**Role**: _unclassified - needs manual reading_"

    game_callers = sorted(callers.get(addr, set()) & game_addrs)
    game_callees = sorted(callees.get(addr, set()) & game_addrs)
    vendor_callees = sorted(callees.get(addr, set()) - game_addrs)

    fname = f"{addr:x}_{re.sub(r'[^A-Za-z0-9_-]', '_', name)[:80]}.md"
    out_path = OUT_DIR / fname

    lines = []
    lines.append(f"# `{name}` @ 0x{addr:x}")
    lines.append("")
    lines.append(f"**Size**: {size} bytes")
    lines.append(role_line)
    lines.append(f"**Pattern category**: `{category}`")
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
        lines.append("**Game callers**: (none - entry point, vendor-called, or only called by vendor)")
    lines.append("")
    if game_callees:
        lines.append(f"**Game callees** ({len(game_callees)}): " +
                     ", ".join(f"[`FUN_{c:x}`]({c:x}_FUN_{c:x}.md)" for c in game_callees[:10]))
        if len(game_callees) > 10:
            lines.append(f"  ... +{len(game_callees)-10} more")
    else:
        lines.append("**Game callees**: (none - leaf function)")
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

print(f"Rewrote {written} per-function docs with classification")
