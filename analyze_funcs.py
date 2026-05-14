"""Better classification: size distribution + thunks + call-graph based.

A 'thunk' is a 5-byte jmp wrapper - one function calling another.
Anything <= 8 bytes is functionally a stub/thunk/trap.
Anything in a tight cluster of similar tiny functions is C++ generated boilerplate.

For more nuanced classification we need to look at:
- Which functions call our KNOWN game-logic functions (e.g. anything that calls
  the function that references 'Horse is too tired!' is game code).
- Which functions call SDL_*, cute_*, MSVC CRT functions exclusively.
"""
import re
from collections import Counter
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
text = DECOMP.read_text(encoding="utf-8", errors="replace")

func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) \(size=(\d+)\) ============$", re.MULTILINE)
matches = list(func_re.finditer(text))

# Build address -> (name, size, body)
funcs = {}
for i, m in enumerate(matches):
    addr = int(m.group(1), 16)
    name = m.group(2)
    size = int(m.group(3))
    start = m.end()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    body = text[start:end]
    funcs[addr] = (name, size, body)

print(f"Total functions: {len(funcs)}")

# Size distribution
sizes = [s for _, s, _ in funcs.values()]
print()
print("Size distribution:")
buckets = [
    (1, 8, "tiny stub (1-8B)"),
    (9, 32, "small (9-32B)"),
    (33, 128, "medium (33-128B)"),
    (129, 512, "regular (129-512B)"),
    (513, 2048, "large (513-2KB)"),
    (2049, 99999, "huge (>2KB)"),
]
for lo, hi, label in buckets:
    n = sum(1 for s in sizes if lo <= s <= hi)
    pct = n / len(sizes) * 100
    tot = sum(s for s in sizes if lo <= s <= hi)
    print(f"  {label:<25s} {n:>5d} funcs ({pct:>5.1f}%)  total {tot/1024:>7.1f} KB")

# Extract calls from each function: FUN_140xxxxxx and named-function calls
call_re = re.compile(r"\b(FUN_140[0-9a-f]+|[A-Za-z_][A-Za-z_0-9]*)\s*\(")

callers_of = {}  # addr -> set of addresses that call it
callees_of = {}  # addr -> set of addresses it calls

# First pass: collect every "FUN_xxxx" reference in each body
for addr, (name, size, body) in funcs.items():
    called_funs = set()
    for m in call_re.finditer(body):
        callee_name = m.group(1)
        if callee_name.startswith("FUN_"):
            try:
                callee_addr = int(callee_name[4:], 16)
                if callee_addr in funcs:
                    called_funs.add(callee_addr)
            except ValueError:
                pass
    callees_of[addr] = called_funs
    for callee in called_funs:
        callers_of.setdefault(callee, set()).add(addr)

# Stats
print()
print(f"Avg callees per function: {sum(len(v) for v in callees_of.values())/len(funcs):.1f}")
print(f"Functions with no callees (leaves): {sum(1 for v in callees_of.values() if not v)}")
print(f"Functions never called: {sum(1 for a in funcs if a not in callers_of)}")

# Find "isolated families": functions that are only ever called by similarly
# unrecognized functions, and form a closed sub-graph. These are likely vendor.
# Heuristic: a function is "game logic" if it's reachable from any function
# that references game-specific strings (Horse, gene, race, etc.).

# Find game-marker functions
GAME_STRING_PATTERNS = [
    r"\bHorse_is_too_tired\b", r"\bHorse_is_too_old\b", r"\bHorse_is_too_young\b",
    r"\bHorse_is_too_hungry\b", r"\bGenome_copied\b", r"\bSimulation_Paused\b",
    r"\bclick_race\b", r"\bGene_%d\b", r"\bSAMPLING_DNA\b", r"\bStartDNAExtract\b",
    r'"save%d\.dat"', r'"genes\.dat"', r'"genes\.xml"', r'"pop\.xml"',
    r'"sound\.xml"', r'"sprites\.xml"', r'"horsey\.tmx"', r'"names\.txt"',
    r"\bChampion\b", r"\bRibbon\b", r"\bChevyRay\b",
]
game_pat = re.compile("|".join(GAME_STRING_PATTERNS))

game_seeds = set()
for addr, (name, size, body) in funcs.items():
    if game_pat.search(body):
        game_seeds.add(addr)

print()
print(f"Game-logic SEED functions (reference game strings): {len(game_seeds)}")

# BFS outward from seeds (both callers and callees)
# Functions reachable from game seeds = "game logic neighborhood"
def reachable_from(seeds, edges):
    frontier = set(seeds)
    seen = set(seeds)
    while frontier:
        next_frontier = set()
        for a in frontier:
            for b in edges.get(a, set()):
                if b not in seen:
                    seen.add(b)
                    next_frontier.add(b)
        frontier = next_frontier
    return seen

# Callees from game seeds: functions called by game code
called_by_game = reachable_from(game_seeds, callees_of)
# Callers of game seeds: functions that invoke game code
calls_into_game = reachable_from(game_seeds, callers_of)
game_neighborhood = called_by_game | calls_into_game

print(f"Functions reachable downward from game seeds (callees of callees ...): {len(called_by_game)}")
print(f"Functions reachable upward from game seeds (callers of callers ...): {len(calls_into_game)}")
print(f"Total in 'game neighborhood': {len(game_neighborhood)}")
print(f"Functions OUTSIDE game neighborhood (likely pure vendor): {len(funcs) - len(game_neighborhood)}")

# Of the game neighborhood, how many are FUN_ vs Ghidra-named?
unnamed_game = sum(1 for a in game_neighborhood if funcs[a][0].startswith("FUN_"))
named_game = len(game_neighborhood) - unnamed_game
print()
print(f"In game neighborhood:")
print(f"  Auto-named (FUN_...): {unnamed_game}")
print(f"  Ghidra-named: {named_game}")
print()

# Save the lists
Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt").write_text(
    "\n".join(f"0x{a:x}\t{funcs[a][0]}\t{funcs[a][1]}"
             for a in sorted(game_neighborhood)), encoding="utf-8")
Path(r"C:/code/horsey-mods/decompiled/vendor_funcs.txt").write_text(
    "\n".join(f"0x{a:x}\t{funcs[a][0]}\t{funcs[a][1]}"
             for a in sorted(set(funcs) - game_neighborhood)), encoding="utf-8")
print("Wrote decompiled/game_neighborhood.txt")
print("Wrote decompiled/vendor_funcs.txt")
