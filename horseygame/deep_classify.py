"""Aggressive multi-pass classification for all 971 game-logic functions.

Pass 1: pattern-based (every function gets a category)
Pass 2: context propagation (callees inherit parent's domain)
Pass 3: caller-context (functions only called by one known fn inherit its domain)
"""
import re
import json
from collections import defaultdict, Counter
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
OUT_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/deep_classification.json")
OUT_MD = Path(r"C:/code/horsey-mods/decompiled/game-funcs/CLASSIFICATION.md")

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

# Build call graph
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


# ============== PASS 1: pattern-based classification ==============

# Specific role detectors from strings (most specific first)
def detect_role_from_strings(body: str) -> str | None:
    sl = body.lower()
    if "horse_is_too_tired" in sl or "horse is too tired" in sl:
        return "fatigue_eligibility_check"
    if "tired_looking_horse" in sl or "tired looking horse" in sl:
        return "fatigue_dialog"
    if "rest_your_horse" in sl or "rest your horse" in sl:
        return "fatigue_rest_prompt"
    if "none_of_your_horses_are_tired" in sl:
        return "fatigue_all_rested"
    if "horse_is_too_old" in sl or "horse is too old" in sl:
        return "age_too_old_check"
    if "horse_is_too_young" in sl or "horse is too young" in sl:
        return "age_too_young_check"
    if "too_old_to_race" in sl or "too old to race" in sl:
        return "age_race_eligibility"
    if "retired" in sl and ("bails" in sl or "useless" in sl or "ch %d races" in sl):
        return "horse_retirement_handler"
    if "is_getting_old" in sl or "is getting old" in sl:
        return "age_sale_dialog"
    if "horses_age" in sl or "horsesage" in sl:
        return "horse_aging_event"
    if "horse_is_too_hungry" in sl or "horse is too hungry" in sl:
        return "hunger_check"
    if "feed_it_first" in sl:
        return "hunger_feed_prompt"
    if "horse_is_dead" in sl or "is_deceased" in sl:
        return "horse_death_handler"
    if "horse_is_too_young" in sl:
        return "age_check"
    if 'save%d.dat' in body:
        return "save_file_path"
    if "settings.xml" in body or "settings_xml" in body:
        return "settings_xml_io"
    if "genes.dat" in body or '"genes\\.dat"' in body:
        return "genes_dat_cache"
    if "genes.xml" in body:
        return "genes_xml_loader"
    if "pop.xml" in body:
        return "pop_xml_loader"
    if "sound.xml" in body:
        return "sound_xml_loader"
    if "sprites.xml" in body:
        return "sprites_xml_loader"
    if "horsey.tmx" in body:
        return "tilemap_loader"
    if "names.txt" in body:
        return "names_txt_loader"
    if "not_in_chromomap" in sl or "exists_twice_in_chromomap" in sl:
        return "chromomap_lookup"
    if "found.*chromosomes" in sl or "found %d/%d chromosomes" in sl:
        return "chromosome_extractor"
    if "genome_copied" in sl or "genome copied to clipboard" in sl:
        return "genome_clipboard_copy"
    if "pasting_genome" in sl or "pasting genome" in sl:
        return "genome_clipboard_paste"
    if "sampling_dna" in sl:
        return "dna_sampling"
    if "startdnaextract" in sl:
        return "dna_extract_start"
    if "sampledna" in sl:
        return "dna_sample"
    if "simulation_paused" in sl or "simulation paused" in sl:
        return "debug_pause_status"
    if "click_race_when_ready" in sl or "click race when ready" in sl:
        return "race_start_prompt"
    if "what_a_great_race" in sl:
        return "race_post_win_dialog"
    if "wonrace" in sl:
        return "race_won_event"
    if "loserace" in sl:
        return "race_lost_event"
    if 'rand' in body and 'nice' in body and 'record' in body and 'years' in body and 'deco' in body:
        return "horse_price_formula"
    if "wakey" in sl or "i_m_awake" in sl or "im_awake" in sl:
        return "wake_up_event"
    if "sleepy" in sl or "i_require_sleep" in sl or "i_require_rest" in sl:
        return "sleep_dialog"
    if "wildmating" in sl or "barnmating" in sl:
        return "breeding_event"
    if "let_s_mate" in sl or "let s mate" in sl:
        return "mating_prompt"
    if "champion" in sl and "ribbon" in sl:
        return "championship_logic"
    if "champion" in sl:
        return "champion_handling"
    if "ribbon" in sl:
        return "ribbon_handling"
    if "horses__d.*bails.*errors" in sl or "horses: %d" in body:
        return "debug_roster_stats"
    if "year__d.*herb" in sl or "year %d  herb" in body:
        return "debug_population_stats"
    if "crispr_a_gene" in sl or "crispr a gene" in sl:
        return "crispr_lab"
    if "engaging_gene_drive" in sl or "gene drive" in sl:
        return "gene_drive_mechanic"
    if "horse_population_is_critically_low" in sl:
        return "extinction_warning"
    if "feed_poop" in sl or "feed poop" in sl:
        return "manure_feeding"
    if "horsetouchingturbine" in sl:
        return "power_plant_event"
    if "horsemart" in sl:
        return "horsemart_location"
    if "betting_window" in sl or "betmore" in sl or "betmax" in sl:
        return "betting_ui"
    if "barn" in sl:
        return "barn_event"
    if "paddock" in sl:
        return "paddock_event"
    if "stable" in sl:
        return "stable_event"
    if "saloon" in sl:
        return "saloon_location"
    if "sumo" in sl:
        return "sumo_location"
    if "zoo" in sl:
        return "zoo_location"
    if "circus" in sl:
        return "circus_location"
    if "powerplant" in sl or "power_plant" in sl:
        return "power_plant_location"
    if "glue" in sl:
        return "glue_factory"
    if "pawn" in sl:
        return "pawn_shop"
    if "lab" in sl:
        return "lab_location"
    if "ecologist" in sl:
        return "ecologist_location"
    if "hutch" in sl:
        return "hutch_location"
    if "appletree" in sl:
        return "appletree_event"
    if "balloon" in sl:
        return "balloon_event"
    if "fish" in sl:
        return "fishing_event"
    if "treasure" in sl:
        return "treasure_event"
    if "fillhole" in sl or "fill_hole" in sl:
        return "fill_hole_action"
    if "destroytree" in sl:
        return "destroy_tree_action"
    if "destroymountain" in sl:
        return "destroy_mountain_action"
    if "reclaimland" in sl:
        return "reclaim_land_action"
    if "whipcrack" in sl:
        return "whip_event"
    if "garage" in sl:
        return "garage_event"
    if "lasso" in sl:
        return "lasso_action"
    if "shovel" in sl:
        return "shovel_action"
    if "gendrive" in sl:
        return "gene_drive"
    if "gendiv" in sl:
        return "genetic_diversity_calc"
    if "litter" in sl:
        return "litter_handling"
    if "foal" in sl:
        return "foaling_event"
    return None


# Pattern detectors (in priority order)
def classify_pattern(body: str, size: int) -> tuple[str, str]:
    """Return (category, evidence)."""
    code = "\n".join(ln for ln in body.split("\n")
                     if ln.strip() and not ln.lstrip().startswith("//"))

    if "halt_baddata" in body:
        return ("trap_stub", "halt_baddata")

    if size <= 8:
        return ("empty_stub", f"size={size}")

    # Pure getter: short fn with `return *(... *)(param_N + OFF);`
    m = re.search(r"return\s+\*\(\s*\w+\s*\*\s*\)\s*\(\s*param_\d\s*\+\s*(0x[0-9a-f]+|\d+)\s*\)\s*;", code)
    if m and size <= 80:
        return ("getter", f"returns field at +{m.group(1)}")

    # Direct returns a constant or computed value
    if size <= 32 and re.search(r"^\s*return\s+", code, re.MULTILINE):
        return ("simple_return", "small return-only function")

    # Setter
    m = re.search(r"\*\(\s*\w+\s*\*\s*\)\s*\(\s*param_\d\s*\+\s*(0x[0-9a-f]+|\d+)\s*\)\s*=\s*param_\d", code)
    if m and size <= 96 and "return" not in code.lower():
        return ("setter", f"writes field at +{m.group(1)}")

    # Single-call wrapper
    fun_calls = re.findall(r"FUN_(140[0-9a-f]+)\s*\(", code)
    if size <= 32 and len(set(fun_calls)) == 1:
        return ("wrapper", f"single delegated call to FUN_{fun_calls[0]}")

    # Two-call wrapper (call a, then call b)
    if size <= 96 and 2 <= len(set(fun_calls)) <= 3 and "return" not in code.lower():
        return ("compound_wrapper", f"sequenced calls: {','.join(sorted(set(fun_calls))[:3])}")

    # Init/zero-fill struct
    n_zero = len(re.findall(r"\*\([^)]+\)\s*\(\s*param_\d\s*\+\s*0x[0-9a-f]+\s*\)\s*=\s*0\b", code))
    if n_zero >= 3:
        return ("struct_init", f"zero-inits {n_zero} fields")

    # Destructor (operator_delete or free)
    if size <= 400 and ("operator_delete" in body or "FUN_140040ca0" in body or "_invoke_watson" in body):
        if size <= 200:
            return ("destructor_like", "calls delete/free helpers")

    # Repeated identical call - likely vector init or batch op
    callee_counts = Counter(fun_calls)
    if callee_counts:
        top_callee, n = callee_counts.most_common(1)[0]
        if n >= 4:
            return ("repeated_op", f"calls FUN_{top_callee} x{n}")

    # Heavy float math (probably geometry, physics, genetics expression)
    n_float = len(re.findall(r"\b(fVar\d+|local_res\w+|local_\w*f\w*)\b", code))
    n_float_lit = len(re.findall(r"\b(DAT_140[0-9a-f]+)\b", code))
    if n_float >= 20 or n_float_lit >= 30:
        if size > 800:
            return ("float_math_complex", f"{n_float} float vars, {n_float_lit} consts")
        return ("float_math", f"{n_float} float vars, {n_float_lit} consts")

    # Iterates horse list at +0xb8/+0xc0
    if re.search(r"\+\s*0xb8\b", code) and re.search(r"\+\s*0xc0\b", code):
        return ("iterates_horse_list_0xb8", "horse-list iter at +0xb8/+0xc0")

    # Iterates an alternate list at +0x26/+0x27 (horse-list-2)
    if re.search(r"param_1\[0x2[67]\]", code):
        return ("iterates_horse_list_0x26", "horse-list iter at param[0x26]/param[0x27]")

    # Switch / branch-heavy dispatchers
    n_case = code.count("case ") + code.count("switch ")
    if n_case >= 5:
        return ("switch_dispatcher", f"{n_case} case branches")

    # Plays a named sound
    m = re.search(r'FUN_140[0-9a-f]+\s*\(\s*[^,)]+,\s*"([A-Z][A-Za-z0-9_]+)"', code)
    if m:
        return ("plays_sound_or_event", f"trigger={m.group(1)!r}")

    # String builder
    n_str_ops = code.count("strncpy") + code.count("strcat") + code.count("snprintf") + code.count("FUN_14008d760")
    if n_str_ops >= 3:
        return ("string_builder", f"{n_str_ops} string ops")

    # Big loop bodies
    has_loop = ("while " in code) or ("do {" in code) or ("for " in code)
    if has_loop and size >= 1000:
        return ("loop_heavy", "large loop-containing function")
    if has_loop and size >= 300:
        return ("medium_loop", "moderate loop-containing function")

    # Lots of pointer arithmetic on param_1
    n_field_access = len(re.findall(r"param_1\s*\+\s*0x[0-9a-f]+", code))
    if n_field_access >= 8:
        return ("struct_handler", f"{n_field_access} field accesses on param_1")

    # Has at least one fn call → some sort of helper
    if fun_calls:
        return ("helper", f"calls {len(set(fun_calls))} other funcs")

    return ("unclassified", "no idiom matched")


# Run pass 1
pass1 = {}
for addr in sorted(game_addrs):
    if addr not in funcs:
        continue
    name, size, body = funcs[addr]
    role = detect_role_from_strings(body)
    category, evidence = classify_pattern(body, size)
    pass1[addr] = {
        "name": name, "size": size,
        "role": role,
        "category": category,
        "evidence": evidence,
    }

# ============== PASS 2: caller-context propagation ==============
# If a function has a specific role but the function it calls doesn't, and the caller has
# only a few callees, the callee likely shares the caller's domain.

# Build a "domain" tag from role
def role_to_domain(role: str) -> str | None:
    if not role:
        return None
    if "fatigue" in role or "tired" in role: return "fatigue"
    if "age" in role or "old" in role or "young" in role or "retirement" in role or "aging" in role:
        return "aging"
    if "hunger" in role or "feed" in role:
        return "hunger"
    if "death" in role or "deceased" in role:
        return "death"
    if "race" in role or "champion" in role or "ribbon" in role or "betting" in role:
        return "race"
    if "save" in role:
        return "save_io"
    if "gene" in role or "chromosome" in role or "dna" in role or "crispr" in role:
        return "genetics"
    if "settings" in role:
        return "settings_io"
    if "tilemap" in role or "names_txt" in role:
        return "data_loading"
    if "wake" in role or "sleep" in role:
        return "sleep_wake"
    if "breeding" in role or "mating" in role or "foaling" in role or "litter" in role:
        return "breeding"
    if "debug" in role:
        return "debug"
    if "_location" in role or "_event" in role or "_action" in role or "ui" in role:
        return "world_event"
    return None


def role_for_propagation(d: dict) -> str | None:
    return d.get("role")


# Propagation: for each game function with no role, look at its callers.
# If all (or one strong) caller has a role, inherit a "domain" tag.
domain_assignments = {}
for addr in pass1:
    role = pass1[addr]["role"]
    if role:
        d = role_to_domain(role)
        if d:
            domain_assignments[addr] = d

# Iterate propagation a few times to spread domain inwards through callees
for _ in range(5):
    changed = 0
    for addr in pass1:
        if addr in domain_assignments:
            continue
        # Look at callers in game_addrs
        c = callers.get(addr, set()) & game_addrs
        if not c:
            continue
        domains = Counter()
        for caller in c:
            if caller in domain_assignments:
                domains[domain_assignments[caller]] += 1
        if domains:
            # Take the most common parent domain
            top, votes = domains.most_common(1)[0]
            # Only inherit if at least half of game callers agree
            if votes >= max(1, len(c) // 2):
                domain_assignments[addr] = top
                changed += 1
    if changed == 0:
        break

# Also propagate downward: if a function with a role calls a small helper, the helper inherits
for _ in range(3):
    changed = 0
    for addr in pass1:
        if addr in domain_assignments:
            continue
        # callees in game_addrs
        c = callees.get(addr, set()) & game_addrs
        if not c:
            continue
        domains = Counter()
        for callee in c:
            if callee in domain_assignments:
                domains[domain_assignments[callee]] += 1
        if domains:
            top, votes = domains.most_common(1)[0]
            if votes >= max(2, len(c) // 2):
                domain_assignments[addr] = top
                changed += 1
    if changed == 0:
        break

# Final structured data
final = {}
for addr, d in pass1.items():
    final[f"0x{addr:x}"] = {
        **d,
        "domain": domain_assignments.get(addr),
    }

OUT_JSON.write_text(json.dumps(final, indent=2), encoding="utf-8")

# Stats
roles = Counter(d["role"] or "(no role)" for d in pass1.values())
domains = Counter(domain_assignments.get(a, "(no domain)") for a in pass1)
categories = Counter(d["category"] for d in pass1.values())

print("=== Pass 1: roles from strings ===")
for r, n in roles.most_common(30):
    print(f"  {n:>4d}  {r}")
print(f"  TOTAL: {sum(roles.values())}")
print()
print("=== Pass 1: pattern categories ===")
for c, n in categories.most_common():
    print(f"  {n:>4d}  {c}")
print()
print("=== Pass 2/3: domain propagation ===")
for d, n in domains.most_common():
    print(f"  {n:>4d}  {d}")

# Write the classification doc
out_lines = ["# Deep classification of game-logic functions", ""]
out_lines.append(f"Total game-logic functions: {len(final)}")
out_lines.append("")
out_lines.append("Three-pass classification:")
out_lines.append("1. **Role** from referenced strings (most specific)")
out_lines.append("2. **Category** from code patterns (getter, setter, init, math, etc.)")
out_lines.append("3. **Domain** propagated through call graph (fatigue, aging, race, etc.)")
out_lines.append("")

out_lines.append("## Role distribution (string-anchored)")
out_lines.append("")
out_lines.append("| Role | Count |")
out_lines.append("|---|---|")
for r, n in sorted(roles.items(), key=lambda x: -x[1]):
    out_lines.append(f"| `{r}` | {n} |")

out_lines.append("")
out_lines.append("## Pattern category distribution")
out_lines.append("")
out_lines.append("| Category | Count |")
out_lines.append("|---|---|")
for c, n in sorted(categories.items(), key=lambda x: -x[1]):
    out_lines.append(f"| `{c}` | {n} |")

out_lines.append("")
out_lines.append("## Domain propagation (after call-graph spreading)")
out_lines.append("")
out_lines.append("| Domain | Count |")
out_lines.append("|---|---|")
for d, n in sorted(domains.items(), key=lambda x: -x[1]):
    out_lines.append(f"| `{d}` | {n} |")

OUT_MD.write_text("\n".join(out_lines), encoding="utf-8")
print(f"\nWrote {OUT_MD}")
print(f"Wrote {OUT_JSON}")

# Final coverage stats
covered_by_role = sum(1 for d in pass1.values() if d["role"])
covered_by_category = sum(1 for d in pass1.values() if d["category"] != "unclassified")
covered_by_domain = sum(1 for a in pass1 if a in domain_assignments)
fully_unknown = sum(1 for a in pass1 if not pass1[a]["role"] and pass1[a]["category"] == "unclassified" and a not in domain_assignments)

print()
print("=== COVERAGE ===")
print(f"  with specific role:      {covered_by_role}/{len(pass1)} ({covered_by_role/len(pass1)*100:.1f}%)")
print(f"  with pattern category:   {covered_by_category}/{len(pass1)} ({covered_by_category/len(pass1)*100:.1f}%)")
print(f"  with propagated domain:  {covered_by_domain}/{len(pass1)} ({covered_by_domain/len(pass1)*100:.1f}%)")
print(f"  fully unknown:           {fully_unknown}/{len(pass1)} ({fully_unknown/len(pass1)*100:.1f}%)")
