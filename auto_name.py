"""Generate a meaningful name + one-sentence description for every game function.

Outputs FUNCTIONS.md: one row per function with proposed name + description.
"""
import re
import json
from collections import Counter, defaultdict
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
CLASS_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/deep_classification.json")
OUT_MD = Path(r"C:/code/horsey-mods/FUNCTIONS.md")
OUT_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/function_names.json")

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


def desymbol(s):
    return s.replace("_", " ").strip()


def extract_strings(body):
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


# Mapping from notable string to a function-name + description
STRING_PROFILES = [
    # (pattern, name, description)
    (r"Horse is too tired", "check_horse_not_tired", "Eligibility check that rejects too-tired horses with a popup message"),
    (r"That's a tired looking horse", "show_tired_horse_dialog", "Show the dialog that comments on a visibly tired horse"),
    (r"Go home and rest your horse", "show_rest_at_home_prompt", "Prompt the player to go home and rest the horse"),
    (r"None of your horses are tired", "show_all_rested_message", "Empty-state message when no horses need rest"),
    (r"Horse is too old", "check_horse_not_old", "Eligibility check that rejects too-old horses"),
    (r"Horse is too young", "check_horse_not_young", "Eligibility check that rejects too-young horses"),
    (r"too old to race", "show_too_old_dialog", "Dialog: 'that horse is too old to race'"),
    (r"retired %s \(old\)", "retire_horse_handler", "Pick-and-retire-one-horse-per-year scanner. Decides retirement reason: (old) had records, (bails) tried but failed, (useless) never had skill"),
    (r"is getting old", "show_getting_old_sale_dialog", "Buyer dialog: offers low price for old horses"),
    (r"Horse is too hungry", "check_horse_not_hungry", "Eligibility check that rejects hungry horses"),
    (r"Feed it first", "show_feed_horse_prompt", "Dialog telling the player to feed the horse first"),
    (r"Horse is dead", "show_horse_dead_message", "Status message for dead horses"),
    (r"is deceased", "show_horse_deceased_dialog", "Dialog explaining a horse is deceased"),
    (r"save%d\.dat", "compute_save_path", "Builds the save file path 'save<N>.dat'"),
    (r'"settings\.xml"', "settings_xml_io", "Read or write settings.xml"),
    (r'"genes\.dat"', "genes_dat_cache_io", "Read or write the genes.dat binary cache"),
    (r"genes\.xml", "genes_xml_loader", "Parse genes.xml gene definitions"),
    (r"pop\.xml", "pop_xml_loader", "Parse pop.xml population/gene-weight definitions"),
    (r"sound\.xml", "sound_xml_loader", "Parse sound.xml sound registry"),
    (r"sprites\.xml", "sprites_xml_loader", "Parse sprites.xml atlas definitions"),
    (r"horsey\.tmx", "tmx_map_loader", "Load the horsey.tmx Tiled world map"),
    (r"names\.txt", "names_txt_loader", "Load horse-name pool from names.txt"),
    (r"Gene %d not in chromoMap", "chromomap_lookup", "Look up a gene by index in chromoMap; aborts if missing"),
    (r"exists twice in chromoMap", "chromomap_dedupe", "Detect and reject duplicate gene entries in chromoMap"),
    (r"Found %d/%d chromosomes", "scan_for_chromosomes", "CRISPR vial: scan environment for collectible chromosome horses"),
    (r"Genome copied to clipboard", "copy_genome_to_clipboard", "Serialize a horse genome to clipboard text"),
    (r"Pasting genome from clipboard", "paste_genome_from_clipboard", "Read a genome from clipboard and apply to a horse"),
    (r"SAMPLING DNA", "show_dna_sampling_animation", "Show 'SAMPLING DNA...' progress animation"),
    (r"StartDNAExtract", "start_dna_extract", "Start the DNA extraction interaction"),
    (r"SampleDNA", "sample_dna", "Take a DNA sample from a horse"),
    (r"Simulation Paused", "draw_pause_status", "Draws the pause-screen status line (year, sleeps, races in debug mode)"),
    (r"Click Race when ready", "show_race_ready_prompt", "Track UI prompt to start the next race"),
    (r"What a great race", "show_post_race_compliment", "Post-race compliment dialog"),
    (r"WonRace", "trigger_won_race_sound", "Play the won-race sound"),
    (r"LoseRace", "trigger_lose_race_sound", "Play the lose-race sound"),
    (r"rand.*nice.*record.*years.*deco", "compute_horse_price", "Compute horse buy/sell price = (rand+nice+record) * years + deco"),
    (r"Wakey wakey", "show_wakey_dialog", "Wake-up dialog"),
    (r"I require sleep", "show_require_sleep_dialog", "Sleep-needed dialog"),
    (r"I require rest", "show_require_rest_dialog", "Rest-needed dialog"),
    (r"WildMating", "trigger_wild_mating_event", "Trigger wild-mating event (sound + breeding)"),
    (r"BarnMating", "trigger_barn_mating_event", "Trigger barn-mating event"),
    (r"Let's mate", "show_mate_prompt", "Player prompt: 'Let's mate' breeding option"),
    (r"Champion horse", "champion_horse_check", "Check whether a horse is a Champion"),
    (r"latest champion", "announce_latest_champion", "Announce the latest champion horse"),
    (r"already won this ribbon", "ribbon_already_won_check", "Check if a horse has already won this ribbon"),
    (r"horses: %d", "debug_print_horse_stats", "Debug: print roster horse stats"),
    (r"year %d.*gendiv", "debug_print_population_stats", "Debug: print population stats (year, herb count, gen diversity)"),
    (r"CRISPR a gene", "crispr_gene_action", "CRISPR-edit a gene on a horse"),
    (r"Engaging GENE DRIVE", "engage_gene_drive", "Activate gene drive (forces gene through population)"),
    (r"Gene Drive must have a target", "gene_drive_target_check", "Validate gene drive has a target gene"),
    (r"StartGeneDrive", "start_gene_drive", "Begin gene drive sequence"),
    (r"SwitchToGeneDrive", "switch_to_gene_drive", "Switch UI to gene-drive mode"),
    (r"Horse population is critically low", "warn_population_extinction", "Warning: horse population near extinction"),
    (r"Feed poop", "feed_manure_prompt", "Player prompt to feed manure"),
    (r"HorseMart", "horsemart_location", "HorseMart shop logic"),
    (r"HorseTouchingTurbine", "horse_touching_turbine", "Power plant: horse-touches-turbine event"),
    (r"Bring a horse here if you wanna race", "show_paddock_intro", "Paddock intro tooltip"),
    (r"Bring your winningest horse for the race of champions", "show_championship_intro", "Championship race intro"),
    (r"Bad GXI", "bad_gene_index_error", "Reports a bad gene index"),
    (r"Aluminium", "aluminum_thing", "Aluminum-related (rare resource?)"),
    (r"Goal 1: get the horse population", "show_population_goal", "Tutorial goal 1: population target"),
    (r"Goal 2: get genetic diversity", "show_diversity_goal", "Tutorial goal 2: diversity target"),
    (r"Did you know", "show_didyouknow_tip", "Tooltip starting with 'Did you know'"),
    (r"Why not go to the Paddock", "suggest_paddock", "Suggestion: go to the Paddock"),
    (r"Why not go home and rest", "suggest_rest_at_home", "Suggestion: rest at home"),
    (r"Why that horse is deceased", "explain_horse_deceased", "Dialog explaining horse death"),
    (r"Born To Be Wild", "born_to_be_wild_event", "References 'Born To Be Wild' (likely horse name or song event)"),
    (r"PrizeAppear", "prize_appear_sound", "Plays prize-appear sound"),
    (r"sells horses at a fair price", "stable_buy_dialog", "Stable: 'sells horses at a fair price'"),
    (r"Welcome", "welcome_dialog", "Welcome dialog"),
    (r"AnimSleep", "render_sleep_animation", "Render sleep animation on horse"),
    (r"SleepMoon", "render_sleep_moon", "Render the moon icon over a sleeping horse"),
    (r"StatusOld", "render_old_status", "Render the 'old' status indicator"),
    (r"StatusTired", "render_tired_status", "Render the tired-status indicator"),
    (r"StatusHungry", "render_hungry_status", "Render the hungry-status indicator"),
    (r"ThoughtTired", "render_tired_thought_bubble", "Render the tired-thought thought bubble"),
    (r"ThoughtHungry", "render_hungry_thought_bubble", "Render the hungry-thought thought bubble"),
    (r"AgeWord", "render_age_text", "Render the 'Age' text label"),
]


def derive_from_strings(body, strings):
    for pattern, nm, desc in STRING_PROFILES:
        if re.search(pattern, body) or any(re.search(pattern, s) for s in strings):
            return nm, desc
    return None, None


# Pattern-based fallback name generators
def derive_from_pattern(body, size, category, evidence, n_callers, n_callees):
    """Generate a name + description from the pattern category."""
    if category == "trap_stub":
        return "noreturn_stub", "Compiler-emitted trap; never executes normally"
    if category == "empty_stub":
        return "empty_stub", "Tiny <=8 byte stub (likely a `ret`)"
    if category == "getter":
        m = re.search(r"\+(0x[0-9a-f]+|\d+)", evidence)
        off = m.group(1) if m else "?"
        return f"get_field_{off}", f"Returns the field at struct offset {off}"
    if category == "setter":
        m = re.search(r"\+(0x[0-9a-f]+|\d+)", evidence)
        off = m.group(1) if m else "?"
        return f"set_field_{off}", f"Writes the field at struct offset {off}"
    if category == "simple_return":
        return "tiny_return_fn", "Tiny function whose body is just a return"
    if category == "wrapper":
        m = re.search(r"FUN_(140[0-9a-f]+)", evidence)
        tgt = m.group(1) if m else "?"
        return f"wrap_{tgt[-6:]}", f"Wrapper that delegates to FUN_{tgt}"
    if category == "compound_wrapper":
        return "compound_wrapper", "Sequenced calls to a few functions (init+call or call+cleanup)"
    if category == "struct_init":
        return "init_struct", f"Zero-initializes consecutive struct fields ({evidence})"
    if category == "destructor_like":
        return "destructor_like", "Calls delete/free helpers; likely a destructor"
    if category == "repeated_op":
        m = re.search(r"FUN_(140[0-9a-f]+)\s*x(\d+)", evidence)
        if m:
            return f"batch_call_{m.group(1)[-6:]}", f"Calls FUN_{m.group(1)} {m.group(2)} times in a loop"
        return "batch_caller", "Batched calls of one helper"
    if category == "float_math":
        return "float_helper", "Heavy float arithmetic (probably geometry or genetics expression)"
    if category == "float_math_complex":
        return "float_math_main", "Heavy float math with many constants (a main computation routine)"
    if category == "iterates_horse_list_0xb8":
        return "iter_horses_0xb8", "Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists)"
    if category == "iterates_horse_list_0x26":
        return "iter_horses_0x26", "Iterates a horse list at param[0x26..0x27]"
    if category == "plays_sound_or_event":
        m = re.search(r"trigger=([A-Za-z0-9_]+)", evidence)
        evt = m.group(1) if m else "event"
        return f"trigger_{evt}", f"Triggers the '{evt}' sound or event"
    if category == "switch_dispatcher":
        return "switch_dispatch", "Multi-way switch; dispatches by enum/state value"
    if category == "loop_heavy":
        return "loop_handler", "Large loop-based handler"
    if category == "medium_loop":
        return "medium_loop_handler", "Moderate loop-based handler"
    if category == "string_builder":
        return "string_builder", "Builds up a string via repeated formatting/concat"
    if category == "struct_handler":
        return "struct_handler", f"Reads/writes many fields on a struct ({evidence})"
    if category == "helper":
        return f"helper_with_{n_callees}_callees", "Generic helper that calls other functions"
    return "unclassified", "Unknown role; needs manual reading"


# Build the master table
records = []
for addr in sorted(game_addrs):
    if addr not in funcs:
        continue
    name, size, body = funcs[addr]
    cls = classification.get(f"0x{addr:x}", {})
    role = cls.get("role")
    category = cls.get("category", "unclassified")
    evidence = cls.get("evidence", "")
    domain = cls.get("domain")
    strings = extract_strings(body)
    n_callers = len(callers.get(addr, set()) & game_addrs)
    n_callees = len(callees.get(addr, set()) & game_addrs)

    # First try string-anchored profile
    proposed_name, description = derive_from_strings(body, strings)
    source = "string"
    if not proposed_name:
        proposed_name, description = derive_from_pattern(body, size, category, evidence, n_callers, n_callees)
        source = "pattern"

    records.append({
        "addr": addr,
        "size": size,
        "ghidra_name": name,
        "proposed_name": proposed_name,
        "description": description,
        "domain": domain or "-",
        "category": category,
        "source": source,
        "n_callers": n_callers,
        "n_callees": n_callees,
    })

# Save JSON
OUT_JSON.write_text(json.dumps(
    {f"0x{r['addr']:x}": {k: v for k, v in r.items() if k != "addr"} for r in records},
    indent=2
), encoding="utf-8")

# Write markdown
lines = ["# Horsey.exe game-function naming table", ""]
lines.append(f"All 971 game-logic functions with a proposed name and description.")
lines.append("")
lines.append("`source = string` means the function was identified by a string it references; high confidence.")
lines.append("`source = pattern` means the function's idiom was matched but the specific purpose is still inferred.")
lines.append("")

# Group by domain
by_domain = defaultdict(list)
for r in records:
    by_domain[r["domain"]].append(r)

# Print in domain order
DOMAIN_ORDER = ["fatigue", "aging", "hunger", "death", "race", "breeding", "sleep_wake",
                "genetics", "save_io", "settings_io", "debug", "world_event", "data_loading", "-"]

for domain in DOMAIN_ORDER:
    if domain not in by_domain:
        continue
    rs = sorted(by_domain[domain], key=lambda x: -x["size"])
    lines.append(f"## domain: `{domain}` ({len(rs)} functions)")
    lines.append("")
    lines.append("| Addr | Size | Proposed name | Description | Source | Category |")
    lines.append("|---|---|---|---|---|---|")
    for r in rs:
        addr = r["addr"]
        link = f"decompiled/game-funcs/{addr:x}_{re.sub(r'[^A-Za-z0-9_-]', '_', r['ghidra_name'])[:80]}.md"
        desc = r["description"].replace("|", "\\|") if r["description"] else "-"
        lines.append(f"| [0x{addr:x}]({link}) | {r['size']} | `{r['proposed_name']}` | {desc} | {r['source']} | {r['category']} |")
    lines.append("")

OUT_MD.write_text("\n".join(lines), encoding="utf-8")
print(f"Wrote {OUT_MD}")

# Stats
print()
print("Source distribution:")
sources = Counter(r["source"] for r in records)
for s, n in sources.most_common():
    print(f"  {s}: {n}/{len(records)} ({n/len(records)*100:.1f}%)")
print()
print("Domain distribution:")
domains_cnt = Counter(r["domain"] for r in records)
for d, n in domains_cnt.most_common():
    print(f"  {d}: {n}")
