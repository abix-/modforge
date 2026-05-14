"""Better classification: size + call graph + comprehensive game-string seeds.

Game neighborhood = transitive closure (callers + callees) of any function that
references a game-specific string. Vendor = everything else.
"""
import re
from collections import Counter, defaultdict
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
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

print(f"Total functions: {len(funcs)}")

# Call graph (game-internal: FUN_140xxxxxx)
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

# Seeds: any function referencing one of these strings is game logic.
GAME_STRING_PATTERNS = [
    # Status / dialog
    r"\bHorse_is_too\b", r"\bHorse is too\b",
    r"\bGenome_copied\b", r"\bGenome copied\b",
    r"\bPasting_genome\b", r"\bPasting genome\b",
    r"\bSimulation_Paused\b", r"\bSimulation Paused\b",
    r"\bClick_Race_when_ready\b", r"\bClick Race\b",
    r"\bGene_%d\b", r"\bGene %d\b",
    r"\bSAMPLING_DNA\b", r"\bSAMPLING DNA\b",
    r"\bStartDNAExtract\b", r"\bSampleDNA\b",
    r"\bchromoMap\b", r"\bGeneEnum\b",
    # File paths (assets)
    r'"save%d\.dat"', r'"genes\.dat"', r'"genes\.xml"', r'"pop\.xml"',
    r'"sound\.xml"', r'"sprites\.xml"', r'"horsey\.tmx"', r'"names\.txt"',
    r'"furniture\.xml"', r'"locs\.xml"', r'"terrain\.xml"', r'"veg\.xml"',
    r'"settings\.xml"',
    # Retirement / aging / death
    r"retired %s", r"retired_old", r"retired_bails", r"retired_useless",
    r"is_getting_old", r"is getting old",
    r"too_old_to_race", r"too old to race",
    r"Horse_is_dead", r"Horse is dead",
    r"is_deceased", r"is deceased",
    r"HorsesAge", r"horses_age",
    # Stamina / sleep
    r"\bI_m_tired\b", r"\bI'm tired\b",
    r"\bI_m_awake\b", r"\bI'm awake\b",
    r"\bSleepy_me\b", r"\bSleepy weepy\b",
    r"\bWakey_wakey\b", r"\bWakey wakey\b",
    r"\bI_require_rest\b", r"\bI require rest\b",
    r"\bI_require_sleep\b", r"\bI require sleep\b",
    r"\bTime_for_a_power_nap\b",
    # Racing / champion / ribbon
    r"\bChampion\b", r"\bRibbon\b", r"\bWonRace\b", r"\bLoseRace\b",
    r"\bRaceGetSet\b", r"\bRaceGo\b", r"\brace_of_champions\b",
    # Breeding
    r"\bWildMating\b", r"\bBarnMating\b", r"\bLet_s_mate\b", r"\bLet's mate\b",
    r"\bMate_two_horses\b",
    # Locations / dialogues
    r"\bChevyRay\b",
    r"\bHorseMart\b", r"\bHorseTouching\b",
    r"\bI'm_a_geneticist\b", r"\bgeneticist\b",
    r"\bHorse population is critically low\b",
    r"\bFound %d/%d chromosomes\b",
    # Save / settings strings
    r'"horsey\.tmx"',
    # Dev cheat tokens
    r"\bdebug\b", r"\bNo_Tire\b", r"\bYes_Tire\b", r"\bNo Tire\b", r"\bYes Tire\b",
    # Format specific to game state
    r"horses: %d", r"year %d  herb", r"Race %d-%s",
    r"%s = \(%d rand",
    # Goal text
    r"\bGoal 1: get the horse population\b", r"\bGoal 2: get genetic diversity\b",
    # Action sounds
    r"\bWhipCrack\b", r"\bBalloonFly\b", r"\bFillHole\b",
    r"\bDestroyTree\b", r"\bDestroyMountain\b", r"\bReclaimLand\b",
    # CRISPR
    r"\bCRISPR\b", r"\bEngaging GENE DRIVE\b", r"\bStartGeneDrive\b",
    r"\bSwitchToGeneDrive\b",
    # Item / world events / UI labels with horse/horse-related semantics
    r"\bAnimSleep\b", r"\bSleepMoon\b", r"\bStatusOld\b", r"\bStatusTired\b",
    r"\bStatusHungry\b", r"\bThoughtTired\b", r"\bThoughtHungry\b", r"\bAgeWord\b",
    # Camera / hot air balloon
    r"\bbig logo\b", r"\bbiglogo\b",
]
game_pat = re.compile("|".join(GAME_STRING_PATTERNS))

# Find seed functions
game_seeds = set()
for addr, (_, _, body) in funcs.items():
    if game_pat.search(body):
        game_seeds.add(addr)
print(f"Game seed functions (reference a game string): {len(game_seeds)}")


# BFS outward through callers AND callees
def transitive_closure(seeds, edges):
    seen = set(seeds)
    frontier = set(seeds)
    while frontier:
        nxt = set()
        for a in frontier:
            for b in edges.get(a, set()):
                if b not in seen:
                    seen.add(b)
                    nxt.add(b)
        frontier = nxt
    return seen


called_by_game = transitive_closure(game_seeds, callees)
calls_into_game = transitive_closure(game_seeds, callers)
game_neighborhood = called_by_game | calls_into_game

print(f"Reachable downward (callees of callees ...): {len(called_by_game)}")
print(f"Reachable upward (callers of callers ...): {len(calls_into_game)}")
print(f"Total game neighborhood: {len(game_neighborhood)}")
print(f"Pure vendor (no path to/from game): {len(funcs) - len(game_neighborhood)}")

# Write outputs
Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt").write_text(
    "\n".join(f"0x{a:x}\t{funcs[a][0]}\t{funcs[a][1]}"
             for a in sorted(game_neighborhood)), encoding="utf-8")
Path(r"C:/code/horsey-mods/decompiled/vendor_funcs.txt").write_text(
    "\n".join(f"0x{a:x}\t{funcs[a][0]}\t{funcs[a][1]}"
             for a in sorted(set(funcs) - game_neighborhood)), encoding="utf-8")
print("Wrote game_neighborhood.txt and vendor_funcs.txt")
