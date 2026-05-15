"""Auto-derive struct layouts by scanning every game function for field accesses.

For each `param_N + 0xOFFSET` access in the decompiled bodies, record:
  - which struct (param index)
  - the offset
  - the access type (read int32, write int64, byte, float, etc.)
  - which function touched it

Then cluster by struct identity (heuristic: param_1 is usually the GameState
or the active sub-state struct; horse pointers are usually passed as param_2 or
as elements of horse-list iterations).

Output STRUCTS.md with the most-likely Horse + GameState layouts.
"""
import re
from collections import defaultdict, Counter
from pathlib import Path
import json

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
NAMES_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/function_names.json")
OUT_MD = Path(r"C:/code/horsey-mods/STRUCTS.md")
OUT_JSON = Path(r"C:/code/horsey-mods/decompiled/structs.json")

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

names = json.loads(NAMES_JSON.read_text(encoding="utf-8")) if NAMES_JSON.exists() else {}


# === Patterns ===
# Standard:  *(<type> *)(param_N + 0xOFF)
# or         *(<type> *)((longlong)param_N + 0xOFF)
# or         *(<type> *)(some_local + 0xOFF)   when the local was loaded from param
# We'll capture the simpler form, plus 'horse + 0xOFF' style after assigning
# `horse = horse_list[i]`.

ACCESS_RE = re.compile(
    r"\*\(\s*([A-Za-z0-9_]+)\s*\*\s*\)\s*\(\s*"        # *(type *)(
    r"(?:\(longlong\)\s*)?"                              # optional (longlong) cast
    r"([A-Za-z_][A-Za-z_0-9]*)"                          # var name
    r"\s*\+\s*"
    r"(0x[0-9a-f]+|\d+)"                                # offset (hex or dec)
    r"\s*\)"
)

# Special pattern for `param_1[0xN]` indexing (8-byte stride)
INDEX_RE = re.compile(
    r"\b([A-Za-z_][A-Za-z_0-9]*)\[\s*(0x[0-9a-f]+|\d+)\s*\]"
)


def parse_offset(s):
    return int(s, 16) if s.startswith("0x") else int(s)


# Track per-variable-name accesses across the binary.
# Key: variable name (e.g. "param_1", "lVar1", "puVar21").
#   But we only really care about "param_*" and known horse-pointer locals.

# To get the Horse struct, we use a TRICK: any pointer obtained from the horse
# list (e.g. `*(longlong *)(horse_list_begin + i * 8)`) is a horse. We grep
# for such assignments and follow the variable name.

# For GameState we use param_1 in functions that access offsets like +0x308
# (money), +0x314 (year), +0x318 (sleeps), +0x31c..+0x349 (supplies).

GAME_STATE_OFFSETS = {0x308, 0x314, 0x318, 0x31c, 0x320, 0x321, 0x324, 0x328, 0x329,
                       0x32c, 0x330, 0x331, 0x334, 0x338, 0x339, 0x33c, 0x340, 0x341,
                       0x344, 0x348, 0x349, 0x31c}

HORSE_OFFSETS = {0x1c, 0x1c4, 0x1c8, 0x1f8, 0x1fc, 0x200, 0x204, 0x205, 0x206, 0x207,
                 0x21c, 0x254, 0x2b0, 0x22, 0x40 * 8}  # known from our analyses

# First pass: collect ALL accesses from ALL game functions.
# We'll track per-function which "vars" look like horse pointers (assigned from
# the horse-list array) vs which are game-state.

# Build "is this function clearly a Horse handler?" set: functions that touch
# offset 0x205 or 0x206 or 0x1fc on something that came from a list dereference.

# Strategy: do one pass to find ALL accesses, key them by (offset, type), and
# tally which functions touch each (offset, type).
offset_freq = defaultdict(Counter)   # offset -> Counter(type -> count)
offset_funcs = defaultdict(set)      # offset -> set of function addresses
offset_examples = defaultdict(list)  # offset -> list of (function, snippet)

# Also: separately track accesses where the base var was clearly derived from
# a horse-list dereference (HORSE_VARS_RE pattern below).

HORSE_DEREF_RE = re.compile(
    r"([A-Za-z_][A-Za-z_0-9]*)\s*=\s*\*\(\s*(?:longlong|undefined8)"
    r"\s*\*+\s*\*?\s*\)\s*\("
)

LIST_BEGIN_OFFSETS = {0xb8, 0xc0, 0x130, 0x138, 0x26 * 8, 0x27 * 8, 0x148}

horse_var_in_func = defaultdict(set)   # addr -> set of var names that ARE horses

GAMESTATE_VARS = {"param_1", "DAT_1403fb0d8"}

# Pre-scan to find horse-pointer assignments
HORSE_ASSIGN_RE = re.compile(
    r"\b([A-Za-z_][A-Za-z_0-9]*)\s*=\s*"
    r"\*\(\s*(?:longlong|undefined8|undefined1)\s*\*+\s*\)\s*\("
    r"[^)]*?\+\s*(0x[0-9a-f]+|\d+)\s*\)"
)

for addr, (name, size, body) in funcs.items():
    if addr not in game_addrs:
        continue
    # Identify which vars in this function hold a Horse pointer.
    horse_vars = set()
    # Heuristic: any var assigned from a list iter (offset is one of LIST_BEGIN_OFFSETS or its end)
    for m in HORSE_ASSIGN_RE.finditer(body):
        var = m.group(1)
        off = parse_offset(m.group(2))
        # If the access was a list dereference at the horse-list base...
        # (we can't tell for sure but if the function is "horse-loop" tagged, all such vars are horses)
        # For now: only count it if offset is in LIST_BEGIN_OFFSETS.
        if off in LIST_BEGIN_OFFSETS or off in (0xb8, 0xc0, 0x130, 0x138):
            horse_vars.add(var)
    # Also: standard list-iter pattern `plVar23 = *(longlong*)(lVar9 + uVar24);`
    # where lVar9 was set from `*(longlong *)(param_1 + 0xb8)`.
    # Approximate by: any local var name pattern from horse-loops counts.
    horse_var_in_func[addr] = horse_vars

# Now do the main access scan
for addr, (name, size, body) in funcs.items():
    if addr not in game_addrs:
        continue
    for m in ACCESS_RE.finditer(body):
        access_type, var, off_str = m.group(1), m.group(2), m.group(3)
        off = parse_offset(off_str)
        if off > 0x10000:    # too big to be a struct field
            continue
        # Classify: horse access or gamestate?
        struct_kind = None
        if var in horse_var_in_func.get(addr, set()):
            struct_kind = "Horse"
        elif var in GAMESTATE_VARS and off in GAME_STATE_OFFSETS:
            struct_kind = "GameState"
        elif var == "param_1":
            # could be GameState OR a sub-state. Tag as "param_1@<funcaddr>".
            struct_kind = "MaybeGameStateOrSubState"
        elif var == "DAT_1403fb0d8":
            struct_kind = "GameState"
        else:
            struct_kind = "unknown"

        offset_freq[(struct_kind, off)][access_type] += 1
        offset_funcs[(struct_kind, off)].add(addr)
        if len(offset_examples[(struct_kind, off)]) < 3:
            # snippet: the line containing this match
            line_start = body.rfind("\n", 0, m.start()) + 1
            line_end = body.find("\n", m.start())
            snippet = body[line_start:line_end].strip()[:200]
            offset_examples[(struct_kind, off)].append((addr, snippet))


# === Pre-known field names ===
HORSE_FIELD_NAMES = {
    0x1c:  ("type_or_species",    "int32",  "Horse type/species. Compared to 2, 3, 4, 6."),
    0x1c4: ("delta_int",          "int32",  "Subtracted from +0x8 in some delta calc."),
    0x1c8: ("flag_byte",          "uint8",  "Boolean checked in retirement loop."),
    0x1f8: ("name_id",            "uint32", "Horse name index (resolved via FUN_1400c78c0)."),
    0x1fc: ("age",                "int32",  "Horse age in years."),
    0x200: ("max_age",            "int32",  "Horse lifespan threshold."),
    0x204: ("on_track_flag",      "uint8",  "Set when horse is currently on the track."),
    0x205: ("tired_flag_a",       "uint8",  "Tiredness flag A. Zeroed by Yes Tire cheat."),
    0x206: ("tired_flag_b",       "uint8",  "Tiredness flag B. Zeroed by Yes Tire cheat."),
    0x207: ("breeding_flag",      "uint8",  "Set to 1 on both parents during breeding."),
    0x21c: ("skill",              "int32",  "Skill/fitness counter used by retirement."),
    0x254: ("litter_size_stat",   "int32",  "Litter-size stat (gene-derived). Used in breeding min()."),
    0x2b0: ("position_x_or_data", "?",      "Read in death handler; copied to gamestate +0x288."),
    0x22:  ("flag_22",            "uint8",  "Boolean checked at death-handler start."),
}

GAMESTATE_FIELD_NAMES = {
    0x308: ("money",              "int32",  "Player money. Money cheat adds +1000 here."),
    0x314: ("year",               "int32",  "Current game year, 0-indexed."),
    0x318: ("sleeps",             "int32",  "Sleep counter."),
    0x31c: ("supply1_count",      "int32",  "First supply counter. +20 by Loaded cheat."),
    0x320: ("supply1_flag_a",     "uint8",  "First supply flag A."),
    0x321: ("supply1_flag_b",     "uint8",  "First supply flag B."),
    0x324: ("supply2_count",      "int32",  "Second supply counter (+20 by Loaded)."),
    0x328: ("supply2_flag_a",     "uint8",  ""),
    0x329: ("supply2_flag_b",     "uint8",  ""),
    0x32c: ("supply3_count",      "int32",  ""),
    0x330: ("supply3_flag_a",     "uint8",  ""),
    0x331: ("supply3_flag_b",     "uint8",  ""),
    0x334: ("supply4_count",      "int32",  ""),
    0x338: ("supply4_flag_a",     "uint8",  ""),
    0x339: ("supply4_flag_b",     "uint8",  ""),
    0x33c: ("supply5_count",      "int32",  ""),
    0x340: ("supply5_flag_a",     "uint8",  ""),
    0x341: ("supply5_flag_b",     "uint8",  ""),
    0x344: ("supply6_count",      "int32",  ""),
    0x348: ("supply6_flag_a",     "uint8",  ""),
    0x349: ("supply6_flag_b",     "uint8",  ""),
    0x464: ("last_retire_year",   "int32",  "Year of last retirement (gates 1/year)."),
    0x468: ("retire_attempt_ctr", "int32",  "Incremented every retirement attempt."),
}


def render_struct(name, scope_kind, known):
    """Emit one struct's table."""
    rows = sorted({off for (kind, off) in offset_freq if kind == scope_kind})
    lines = [f"## struct `{name}`", ""]
    lines.append(f"Total observed field offsets: {len(rows)}")
    lines.append("")
    lines.append("| Offset | Type(s) seen | Field name | # funcs | Notes |")
    lines.append("|---|---|---|---|---|")
    for off in rows:
        key = (scope_kind, off)
        types = offset_freq[key]
        types_str = ", ".join(f"{t}({c})" for t, c in types.most_common(3))
        n_funcs = len(offset_funcs[key])
        fname, ftype, fdesc = known.get(off, (f"unknown_field_0x{off:x}", "?", ""))
        lines.append(f"| 0x{off:x} | {types_str} | `{fname}` | {n_funcs} | {fdesc} |")
    lines.append("")
    return "\n".join(lines)


out = []
out.append("# Auto-derived struct layouts")
out.append("")
out.append("Generated by `cluster_structs.py` from all game-logic function bodies.")
out.append("")
out.append("Method: scan every `*(type *)(var + 0xOFF)` access in decompiled")
out.append("output. Variables identified as Horse pointers (assigned from horse-list")
out.append("dereferences) contribute to the Horse struct. `param_1` in functions that")
out.append("touch known GameState offsets contributes to GameState. The known-field")
out.append("names come from our manual annotations; the unknown ones are stub-named.")
out.append("")

out.append(render_struct("Horse", "Horse", HORSE_FIELD_NAMES))
out.append(render_struct("GameState (DAT_1403fb0d8 or main `param_1`)", "GameState", GAMESTATE_FIELD_NAMES))

# Bonus: show top accessed offsets for "MaybeGameStateOrSubState"
sub_rows = sorted({off for (k, off) in offset_freq if k == "MaybeGameStateOrSubState"})
sub_rows = [r for r in sub_rows if len(offset_funcs[("MaybeGameStateOrSubState", r)]) >= 5]
sub_rows.sort(key=lambda r: -len(offset_funcs[("MaybeGameStateOrSubState", r)]))
out.append("## `param_1` accesses (probably GameState or a major sub-state)")
out.append("")
out.append("Offsets accessed by >= 5 distinct game functions through param_1 (likely struct fields):")
out.append("")
out.append("| Offset | Type(s) | # funcs | Sample function |")
out.append("|---|---|---|---|")
for off in sub_rows[:60]:
    types = offset_freq[("MaybeGameStateOrSubState", off)]
    types_str = ", ".join(f"{t}({c})" for t, c in types.most_common(2))
    n_funcs = len(offset_funcs[("MaybeGameStateOrSubState", off)])
    sample_addr = next(iter(offset_funcs[("MaybeGameStateOrSubState", off)]))
    sample_name = names.get(f"0x{sample_addr:x}", {}).get("proposed_name", f"FUN_{sample_addr:x}")
    out.append(f"| 0x{off:x} | {types_str} | {n_funcs} | `{sample_name}` |")
out.append("")

# Persist JSON
output_data = {
    "Horse": {f"0x{off:x}": {
        "types": dict(offset_freq[("Horse", off)]),
        "n_funcs": len(offset_funcs[("Horse", off)]),
        "known": HORSE_FIELD_NAMES.get(off, None),
    } for off in sorted({off for (k, off) in offset_freq if k == "Horse"})},
    "GameState": {f"0x{off:x}": {
        "types": dict(offset_freq[("GameState", off)]),
        "n_funcs": len(offset_funcs[("GameState", off)]),
        "known": GAMESTATE_FIELD_NAMES.get(off, None),
    } for off in sorted({off for (k, off) in offset_freq if k == "GameState"})},
    "param1_substate": {f"0x{off:x}": {
        "types": dict(offset_freq[("MaybeGameStateOrSubState", off)]),
        "n_funcs": len(offset_funcs[("MaybeGameStateOrSubState", off)]),
    } for off in sorted({off for (k, off) in offset_freq if k == "MaybeGameStateOrSubState"}) if len(offset_funcs[("MaybeGameStateOrSubState", off)]) >= 3},
}
OUT_JSON.write_text(json.dumps(output_data, indent=2), encoding="utf-8")

OUT_MD.write_text("\n".join(out), encoding="utf-8")
print(f"Wrote {OUT_MD}")
print(f"Wrote {OUT_JSON}")
print()
print(f"Horse fields detected: {len(output_data['Horse'])}")
print(f"GameState fields detected: {len(output_data['GameState'])}")
print(f"param_1 sub-state offsets (>=3 funcs): {len(output_data['param1_substate'])}")
