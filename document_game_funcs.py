"""Document every game-logic function with auto-extracted metadata.

For each of the 971 game-logic functions:
- Address, Ghidra name, body size, signature
- Strings it references (game-specific)
- Functions in the game-neighborhood that it CALLS
- Functions in the game-neighborhood that CALL IT
- Inferred role (one-liner from heuristics + string refs)
- The decompiled body itself

Output:
- decompiled/game-funcs/<addr>_<name>.md     (one per function)
- decompiled/game-funcs/INDEX.md             (sortable table)
- decompiled/game-funcs/CALL-GRAPH.md        (top-callers, leaves)
"""
import re
from collections import Counter, defaultdict
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
OUT_DIR = Path(r"C:/code/horsey-mods/decompiled/game-funcs")
OUT_DIR.mkdir(exist_ok=True)

print("Loading...")
text = DECOMP.read_text(encoding="utf-8", errors="replace")
func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) \(size=(\d+)\) ============$", re.MULTILINE)
matches = list(func_re.finditer(text))

# addr -> (name, size, body)
funcs = {}
for i, m in enumerate(matches):
    addr = int(m.group(1), 16)
    name = m.group(2)
    size = int(m.group(3))
    start = m.end()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    body = text[start:end]
    funcs[addr] = (name, size, body)
print(f"  Total functions in binary: {len(funcs)}")

# Game neighborhood
game_addrs = set()
for line in NEIGH.read_text().splitlines():
    parts = line.split("\t")
    if parts and parts[0].startswith("0x"):
        game_addrs.add(int(parts[0], 16))
print(f"  Game-logic functions: {len(game_addrs)}")

# Build call graph (within full binary, then we'll restrict to game)
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

# String extraction patterns. Look for both literal "..." and s_xxx_140xxxxxxx symbols.
LITERAL_RE = re.compile(r'"([^"\\\n]{2,80})"')
SYMBOL_RE = re.compile(r"\bs_([A-Za-z0-9_]{2,80})_140[0-9a-f]+\b")

# Decode s_Foo_Bar_140xxxxxx symbols back into approximate text
def desymbol(s: str) -> str:
    # Underscores in symbol names replace spaces and punctuation.
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


# Heuristic role inference from strings
def infer_role(strings: list[str], name: str, size: int) -> str:
    s_lower = " ".join(strings).lower()
    if "horse is too tired" in s_lower or "tired looking" in s_lower or "rest your horse" in s_lower:
        return "fatigue/stamina check (gates racing on horse tiredness)"
    if "horse is too old" in s_lower or "too old to race" in s_lower:
        return "age gate (rejects too-old horses from action)"
    if "horse is too young" in s_lower:
        return "age gate (rejects too-young horses from action)"
    if "horse is too hungry" in s_lower or "feed it first" in s_lower:
        return "hunger gate (rejects hungry horses)"
    if "retired" in s_lower and ("old" in s_lower or "bails" in s_lower or "useless" in s_lower):
        return "retirement handler (logs retirement reason and removes horse)"
    if "getting old" in s_lower and "offer" in s_lower:
        return "horse sale dialog (offer-by-age)"
    if "genome copied" in s_lower or "pasting genome" in s_lower:
        return "genome clipboard serializer (debug / save sharing)"
    if "chromomap" in s_lower or "chromosome" in s_lower:
        return "gene/chromosome table loader or lookup"
    if 'save%d.dat' in " ".join(strings):
        return "save file path builder / save loader / save writer"
    if "settings.xml" in " ".join(strings):
        return "settings xml read/write"
    if "genes.dat" in " ".join(strings):
        return "genes.dat binary cache read/write"
    if "simulation paused" in s_lower:
        return "debug status print (year/sleeps/races counters)"
    if "click race when ready" in s_lower:
        return "race start prompt / track UI"
    if "rand" in s_lower and "nice" in s_lower and "record" in s_lower and "years" in s_lower:
        return "horse price/score formula (rand+nice+record components, * years multiplier)"
    if "horses: %d" in s_lower and "bails" in s_lower:
        return "debug log of horse roster stats"
    if "year %d" in s_lower and "gendiv" in s_lower:
        return "debug log of population stats"
    if "champion" in s_lower:
        return "championship-related"
    if "ribbon" in s_lower:
        return "ribbon/prize-related"
    if "sampling dna" in s_lower or "startdnaextract" in s_lower or "sampledna" in s_lower:
        return "DNA sampling mechanic"
    if "wakey" in s_lower or "sleepy" in s_lower:
        return "sleep dialog / wakeup handler"
    if "im awake" in s_lower or "i'm awake" in s_lower:
        return "wake-up event"
    if "horses age" in s_lower:
        return "age tick / aging event handler"
    if "wildmating" in s_lower or "mating" in s_lower:
        return "breeding event"
    if "dead" in s_lower and "horse" in s_lower:
        return "horse death handler"
    if "deceased" in s_lower:
        return "death dialog"
    if "horsey" in s_lower and "island" in s_lower:
        return "world/island setup"
    if "race %d" in s_lower:
        return "race state handler"
    # Fallback by size
    if size <= 32:
        return "stub/thunk/getter (unknown specific role)"
    if size <= 128:
        return "small helper (purpose unclear without reading)"
    return "unclassified game logic"


# Strip empty lines and double-spaced output from Ghidra
def compact_body(body: str) -> str:
    # Remove the header comment line - we add our own
    lines = body.split("\n")
    # Drop the "// =====" line and any blank lines immediately after
    while lines and (lines[0].startswith("// =") or not lines[0].strip()):
        lines = lines[1:]
    # Collapse double-blanks
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


# Process each game function
print("Generating per-function docs...")
docs = []
for addr in sorted(game_addrs):
    name, size, body = funcs[addr]
    strings = extract_strings(body)
    role = infer_role(strings, name, size)

    # Callers/callees restricted to game neighborhood
    game_callers = sorted(callers.get(addr, set()) & game_addrs)
    game_callees = sorted(callees.get(addr, set()) & game_addrs)
    other_callers = sorted(callers.get(addr, set()) - game_addrs)
    other_callees = sorted(callees.get(addr, set()) - game_addrs)

    # Write the per-function .md
    fname = f"{addr:x}_{re.sub(r'[^A-Za-z0-9_-]', '_', name)[:80]}.md"
    out_path = OUT_DIR / fname

    lines = []
    lines.append(f"# `{name}` @ 0x{addr:x}")
    lines.append("")
    lines.append(f"**Size**: {size} bytes")
    lines.append(f"**Role**: {role}")
    if strings:
        lines.append("")
        lines.append("**Strings referenced**:")
        for s in strings[:20]:
            lines.append(f"- `{s!r}`")
        if len(strings) > 20:
            lines.append(f"- ... ({len(strings) - 20} more)")
    lines.append("")
    lines.append(f"**Game callers** ({len(game_callers)}): " + (", ".join(f"`FUN_{c:x}`" for c in game_callers[:10]) if game_callers else "(none in game neighborhood)"))
    if len(game_callers) > 10:
        lines.append(f"  ... +{len(game_callers)-10} more")
    lines.append("")
    lines.append(f"**Game callees** ({len(game_callees)}): " + (", ".join(f"`FUN_{c:x}`" for c in game_callees[:10]) if game_callees else "(none in game neighborhood)"))
    if len(game_callees) > 10:
        lines.append(f"  ... +{len(game_callees)-10} more")
    lines.append("")
    lines.append(f"**Vendor callees** ({len(other_callees)}) - SDL/CRT/etc.")
    lines.append("")
    lines.append("## Decompiled")
    lines.append("")
    lines.append("```c")
    lines.append(compact_body(body).rstrip())
    lines.append("```")

    out_path.write_text("\n".join(lines), encoding="utf-8")

    docs.append({
        "addr": addr,
        "name": name,
        "size": size,
        "role": role,
        "n_game_callers": len(game_callers),
        "n_game_callees": len(game_callees),
        "strings": strings[:3],
    })

print(f"  Wrote {len(docs)} per-function docs to {OUT_DIR}")

# Build INDEX.md sorted by size (biggest = most interesting)
index = ["# Game-logic function index", ""]
index.append(f"Total game-logic functions: {len(docs)}")
index.append("")
index.append("Sorted by body size (descending). Largest functions hold the most logic.")
index.append("")
index.append("| # | Address | Name | Size | Callers | Callees | Role |")
index.append("|---|---|---|---|---|---|---|")
for i, d in enumerate(sorted(docs, key=lambda x: -x["size"]), 1):
    addr = d["addr"]
    fname = f"{addr:x}_{re.sub(r'[^A-Za-z0-9_-]', '_', d['name'])[:80]}.md"
    role = d["role"].replace("|", "\\|")
    index.append(f"| {i} | [0x{addr:x}]({fname}) | `{d['name']}` | {d['size']} | {d['n_game_callers']} | {d['n_game_callees']} | {role} |")

(OUT_DIR / "INDEX.md").write_text("\n".join(index), encoding="utf-8")
print(f"  Wrote INDEX.md")

# Role summary
print()
print("Role distribution:")
role_counts = Counter(d["role"] for d in docs)
for role, n in role_counts.most_common():
    print(f"  {n:>4d}  {role}")
