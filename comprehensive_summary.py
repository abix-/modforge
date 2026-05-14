"""Generate a comprehensive one-line summary for every game function.

For each function:
1. Extract all referenced strings (both literals and Ghidra s_ symbols).
2. Use a large keyword -> domain dictionary to infer the function's purpose.
3. Pick the most specific match. Fall back to body-pattern classification.
4. Write to ALL-FUNCTIONS.md with one row per function.

Goal: every game function has at least a meaningful one-liner.
"""
import re
from collections import Counter, defaultdict
from pathlib import Path
import json

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
CLASS_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/deep_classification.json")
OUT = Path(r"C:/code/horsey-mods/ALL-FUNCTIONS.md")
OUT_JSON = Path(r"C:/code/horsey-mods/decompiled/all_summaries.json")

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

LITERAL_RE = re.compile(r'"([^"\\\n]{2,80})"')
SYMBOL_RE = re.compile(r"\bs_([A-Za-z0-9_]{2,80})_140[0-9a-f]+\b")

def extract_strings(body):
    out = set()
    for m in LITERAL_RE.finditer(body):
        s = m.group(1)
        if len(s.strip()) >= 2:
            out.add(s)
    for m in SYMBOL_RE.finditer(body):
        s = m.group(1).replace("_", " ").strip()
        if len(s) >= 2:
            out.add(s)
    return out

# Massive keyword-to-summary table. We match in order; first match wins.
# Format: (keyword pattern, summary)
KEYWORD_RULES = [
    # === Fatigue / sleep / wake ===
    (r"Horse is too tired", "Eligibility check: rejects too-tired horse"),
    (r"That's a tired looking", "Dialog: visibly tired horse"),
    (r"rest your horse", "Prompt: rest the horse"),
    (r"None of your horses are tired", "Empty-state: all horses rested"),
    (r"I'm so tired|I_m_so_tired", "Horse status: very tired"),
    (r"I'm tired|I_m_tired", "Horse status: tired"),
    (r"I'm awake|I_m_awake", "Horse status: awake (wake event)"),
    (r"Sleepy weepy|Sleepy_weepy", "Sleep status text"),
    (r"Wakey wakey|Wakey_wakey", "Wake-up dialog"),
    (r"Time for a power nap", "Dialog: nap time"),
    (r"I require sleep|I_require_sleep", "Horse status: needs sleep"),
    (r"I require rest|I_require_rest", "Horse status: needs rest"),
    (r"I require my beauty rest", "Horse status: beauty rest"),
    (r"I can sleep forever here", "Sleep dialog: paradise"),
    (r"I prefer to get to sleep at night", "Sleep dialog: nocturnal pref"),

    # === Age / death / retirement ===
    (r"Horse is too old", "Eligibility check: rejects too-old horse"),
    (r"too old to race", "Dialog: horse too old to race"),
    (r"Horse is too young", "Eligibility check: rejects too-young horse"),
    (r"retired %s \(old\)", "Retirement: (old) record-holding horse"),
    (r"retired %s \(bails\)", "Retirement: (bails) gave-up horse"),
    (r"retired %s \(useless\)", "Retirement: (useless) low-skill horse"),
    (r"%s%s retired %s", "Retirement: broadcast message"),
    (r"is getting old", "Sale dialog: discount for old horse"),
    (r"Horse is dead|Horse_is_dead", "Status: horse died"),
    (r"is deceased", "Dialog: explains horse death"),
    (r"HorsesAge|horses_age", "Sound trigger: horse aged"),
    (r"released into the wild", "Action: release horse to wild instead of retire"),

    # === Hunger ===
    (r"Horse is too hungry", "Eligibility check: rejects hungry horse"),
    (r"All your horses are hungry", "Status: all horses hungry"),
    (r"Feed it first", "Prompt: feed the horse first"),
    (r"I'm hungry|I_m_hungry", "Status: horse is hungry"),
    (r"I'm so hungry|I_m_so_hungry", "Status: very hungry"),
    (r"isn't hungry", "Status: horse not hungry"),
    (r"ate some hay today", "Daily event: ate hay"),
    (r"ready to touch grass", "Status: ready to graze"),

    # === Save / load ===
    (r'"save%d\.dat"', "Save file: read/write save<N>.dat"),
    (r"_saving_", "Debug: save in progress marker"),
    (r'"settings\.xml"|"settings_xml"', "Settings.xml IO"),
    (r'"genes\.dat"', "genes.dat cache IO"),

    # === Data file loaders ===
    (r"genes\.xml", "Loader: genes.xml definitions"),
    (r"pop\.xml", "Loader: pop.xml populations"),
    (r"sound\.xml", "Loader: sound.xml registry"),
    (r"sprites\.xml", "Loader: sprites.xml atlas"),
    (r"furniture\.xml", "Loader: furniture.xml atlas"),
    (r"locs\.xml", "Loader: locs.xml atlas"),
    (r"terrain\.xml", "Loader: terrain.xml atlas"),
    (r"veg\.xml", "Loader: veg.xml atlas"),
    (r"biglogo\.xml", "Loader: biglogo.xml"),
    (r"horsey\.tmx", "Loader: tilemap horsey.tmx"),
    (r"names\.txt", "Loader: names.txt pool"),
    (r"Map %s not found", "Error: tilemap file missing"),
    (r"objectgroup", "Tilemap parser: object groups"),

    # === Genetics ===
    (r"Bad GXI", "Error: bad gene index (gene expression)"),
    (r"Gene %d not in chromoMap", "Error: unknown gene in chromoMap"),
    (r"Gene %d exists twice in chromoMap", "Error: duplicate gene in chromoMap"),
    (r"Found %d/%d chromosomes", "Status: chromosome scan progress"),
    (r"Genome copied to clipboard", "Action: serialize genome to clipboard"),
    (r"Pasting genome from clipboard", "Action: paste genome from clipboard"),
    (r"SAMPLING DNA", "Status: sampling DNA animation"),
    (r"StartDNAExtract", "Action: begin DNA extraction"),
    (r"SampleDNA", "Action: take a DNA sample"),
    (r"CRISPR a gene|CRISPR_a_gene", "Action: CRISPR-edit a gene"),
    (r"Engaging GENE DRIVE", "Action: start gene drive"),
    (r"Gene Drive must have a target", "Error: gene drive needs target"),
    (r"StartGeneDrive", "Action: start gene drive"),
    (r"SwitchToGeneDrive", "Action: switch UI to gene drive"),
    (r"the genetic diversity|gendiv", "Stat: genetic diversity"),
    (r"VialZoomIn|VialZoomOut", "CRISPR: vial zoom animation"),
    (r"VialWorld", "CRISPR: vial-world sub-map"),
    (r"ComputerCopy", "Sound: computer copy beep"),

    # === Race / track / champion ===
    (r"Click Race when ready", "Track: race-ready prompt"),
    (r"How much will you bet", "Betting: amount prompt"),
    (r"But the odds are slim", "Betting: long-shot warning"),
    (r"Won race|WonRace", "Sound: won race"),
    (r"Lose race|LoseRace", "Sound: lost race"),
    (r"RaceGetSet", "Sound: get-set signal"),
    (r"RaceGo", "Sound: race-start signal"),
    (r"OnYourMark", "Sound: on-your-mark"),
    (r"What a great race", "Dialog: post-race compliment"),
    (r"\bChampion horse\b", "Status: champion horse"),
    (r"latest champion", "Dialog: announce champion"),
    (r"race of champions", "Mechanic: championship race"),
    (r"% just had a bad race|just had a bad race", "Dialog: bad race comment"),
    (r"Oddsmaking error", "Error: race odds compute failed"),
    (r"Better luck next race", "Dialog: post-race consolation"),
    (r"Bring a horse here if you wanna race", "Dialog: paddock intro"),
    (r"Bring your winningest horse for the race", "Dialog: champion entry"),
    (r"CrossFinishLine", "Sound: finish-line crossed"),
    (r"WinningHorse", "Sprite: winning horse banner"),
    (r"WinningTicket", "Sprite: winning ticket"),

    # === Ribbon / championship ===
    (r"\bRibbon\b", "Mechanic: ribbon award"),
    (r"red stripes", "Ribbon: red stripes ribbon"),
    (r"already won this ribbon", "Check: ribbon dupe"),
    (r"PrizeAppear", "Sound: prize appears"),
    (r"trophy", "Item: trophy"),

    # === Breeding / mating ===
    (r"WildMating", "Sound: wild mating"),
    (r"BarnMating", "Sound: barn mating"),
    (r"Let's mate|Let_s_mate", "Prompt: mate two horses"),
    (r"Mate two horses", "Action: mating"),
    (r"foaled", "Event: foal born"),
    (r"Biological mating is pointless", "Dialog: lab snark about mating"),

    # === Money / market ===
    (r"%d rand.*nice.*record.*years.*deco", "Formula: horse price"),
    (r"LoseMoney|LoseMon", "Sound: lose money"),
    (r"Cash suitcase|Cash_suitcase", "Item: cash"),

    # === Locations ===
    (r"Paddock|paddock", "Location: paddock"),
    (r"Sweetie", "Location: Sweetie's House"),
    (r"Hermit", "Location: Hermit"),
    (r"CRISPR|crispr", "Location: CRISPR Lab"),
    (r"\bGlue\b|GlueFactory", "Location: glue factory"),
    (r"CarLot", "Location: car lot"),
    (r"\bLab\b|Laboratory", "Location: lab"),
    (r"Supply|Supplies", "Location: supply store"),
    (r"Ecologist", "Location: ecologist"),
    (r"Hutch", "Location: hutch"),
    (r"Circus|circus", "Location: circus"),
    (r"\bZoo\b|zoo", "Location: zoo"),
    (r"Acres", "Location: acres"),
    (r"Saloon|saloon", "Location: saloon"),
    (r"PowerPlant|power_plant", "Location: power plant"),
    (r"Sumo|sumo", "Location: sumo arena"),
    (r"Pawn|pawn", "Location: pawn shop"),
    (r"HorseMart", "Location: HorseMart shop"),
    (r"Stable|stable", "Location: stable"),
    (r"Garage|garage", "Location: garage"),

    # === Specific events / actions ===
    (r"FillHole", "Action: fill hole with item"),
    (r"DestroyTree", "Action: destroy tree"),
    (r"DestroyMountain", "Action: destroy mountain"),
    (r"ReclaimLand", "Action: reclaim land (fence water)"),
    (r"WhipCrack", "Action/sound: whip crack"),
    (r"BalloonFly|BalloonUp|BalloonDown", "Vehicle: hot air balloon"),
    (r"Lasso", "Action: lasso"),
    (r"Shovel|TinyGoldenShovel", "Action/item: shovel"),
    (r"DigFinish|DigLoop", "Action: digging"),
    (r"DungInCart", "Action: dump dung in cart"),
    (r"FencePlace", "Action: place fence"),
    (r"Cannon", "Mechanic: cannon (circus)"),
    (r"LockBreak", "Action: break a lock"),
    (r"SumoBattle", "Mechanic: sumo fight"),
    (r"AttachItem", "Action: attach item to horse"),
    (r"Chomp", "Sound: horse eats"),
    (r"Glug", "Sound: drink"),

    # === Sounds ===
    (r"BarnDoorClose", "Sound: barn door close"),
    (r"BarnDoorOpen", "Sound: barn door open"),
    (r"GarageDoorOpen|GarageDoorClose", "Sound: garage door"),
    (r"GongWoodLight", "Sound: light gong tap"),
    (r"JetEngineLoop", "Sound: jet engine loop"),
    (r"ImpactHard", "Sound: hard impact"),
    (r"Clapping", "Sound: crowd clapping"),
    (r"TitleCard", "Sound: title card"),

    # === UI sprites / animations ===
    (r"StatusOld|StatusTired|StatusHungry", "Render: status icon over horse"),
    (r"ThoughtTired|ThoughtHungry", "Render: thought bubble"),
    (r"AnimSleep|SleepMoon", "Render: sleep animation"),
    (r"AgeWord", "Render: 'Age' text label"),
    (r"DecoCrown|DecoGlasses|DecoSunglasses|DecoToque", "Render: horse decoration"),
    (r"GrabHand|PointerInspect|PointerLasso|PointerShoot|PointerDig|PointerTalk|PointerPet|PointerGo", "Render: cursor"),

    # === Debug / dev ===
    (r"Simulation Paused", "Debug: pause status line"),
    (r"horses: %d.*bails.*errors", "Debug: roster stats"),
    (r"year %d.*herb.*gendiv", "Debug: population stats"),
    (r"%s = \(%d rand", "Debug: price formula log"),

    # === Tutorial / narrative ===
    (r"Goal 1: get the horse population", "Tutorial: goal 1 (population)"),
    (r"Goal 2: get genetic diversity", "Tutorial: goal 2 (diversity)"),
    (r"De Horsey Island was named for", "Narrative: De Horsey origin"),
    (r"Did you know", "Tutorial: did-you-know tip"),
    (r"Horse population is critically low", "Warning: population low"),
    (r"Welcome", "Dialog: welcome"),

    # === Items ===
    (r"\bClarence\b", "NPC: Clarence character"),
    (r"\bDale\b", "Horse: default-pop seed name (initial)"),
    (r"Honky Tonk Tonky", "Horse: seed name"),

    # === Misc / event dialogs ===
    (r"Born To Be Wild", "Horse: seed name 'Born To Be Wild'"),
    (r"Engaging|Engage", "Event: engage / activate"),
]

# Compile patterns
COMPILED_RULES = [(re.compile(p, re.IGNORECASE), summary) for p, summary in KEYWORD_RULES]

def summarize(body, name, size, category, evidence):
    # Try string-based first
    s = extract_strings(body)
    all_text = " ".join(s) + " " + body[:5000]  # limit
    for pat, summary in COMPILED_RULES:
        if pat.search(all_text):
            return ("string", summary)
    # Fallback to category-based
    cat_to_summary = {
        "trap_stub": "Compiler trap stub",
        "empty_stub": "Empty stub (likely a ret)",
        "getter": f"Getter; {evidence}",
        "setter": f"Setter; {evidence}",
        "simple_return": "Tiny return-only function",
        "wrapper": f"Wrapper; {evidence}",
        "compound_wrapper": "Compound wrapper (multiple delegated calls)",
        "struct_init": f"Struct initializer; {evidence}",
        "destructor_like": "Destructor / cleanup helper",
        "repeated_op": f"Batch helper; {evidence}",
        "float_math": "Float math helper",
        "float_math_complex": "Heavy float math (likely geometry / genetics expression)",
        "iterates_horse_list_0xb8": "Iterates horse list at obj+0xb8/+0xc0",
        "iterates_horse_list_0x26": "Iterates horse list at param[0x26]/[0x27]",
        "plays_sound_or_event": f"Plays sound; {evidence}",
        "switch_dispatcher": "Multi-way switch dispatcher",
        "loop_heavy": "Large loop-containing handler",
        "medium_loop": "Loop-containing helper",
        "string_builder": "String builder (formats/concatenates)",
        "struct_handler": f"Struct field accessor; {evidence}",
        "helper": "Helper function (calls other game functions)",
        "unclassified": "Unclassified (needs manual reading)",
    }
    return ("pattern", cat_to_summary.get(category, "Unknown"))


# Build the master table
records = []
for addr in sorted(game_addrs):
    if addr not in funcs:
        continue
    name, size, body = funcs[addr]
    cls = classification.get(f"0x{addr:x}", {})
    category = cls.get("category", "unclassified")
    evidence = cls.get("evidence", "")
    domain = cls.get("domain")
    source, summary = summarize(body, name, size, category, evidence)
    records.append({
        "addr": addr, "size": size, "ghidra_name": name,
        "summary": summary, "source": source, "category": category, "domain": domain,
    })

# Save JSON
OUT_JSON.write_text(json.dumps(
    {f"0x{r['addr']:x}": {k: v for k, v in r.items() if k != "addr"} for r in records},
    indent=2), encoding="utf-8")

# Markdown table grouped by source
lines = ["# All game-logic functions (auto-summarized)", ""]
lines.append(f"{len(records)} game-logic functions. Each has a one-line summary.")
lines.append("")
lines.append("**source = string**: summary derived from a recognized in-game string.")
lines.append("**source = pattern**: summary derived from code-shape category.")
lines.append("")

# Stats
src_counts = Counter(r["source"] for r in records)
lines.append("| Source | Count | % |")
lines.append("|---|---|---|")
for s, n in src_counts.most_common():
    lines.append(f"| {s} | {n} | {n/len(records)*100:.1f}% |")
lines.append("")

# Full table, sorted by source then size desc
records.sort(key=lambda r: (r["source"] != "string", -r["size"]))
lines.append("## Functions (string-anchored first, then by size)")
lines.append("")
lines.append("| Addr | Size | Summary | Source | Domain |")
lines.append("|---|---|---|---|---|")
for r in records:
    summary = r["summary"].replace("|", "\\|")
    lines.append(f"| 0x{r['addr']:x} | {r['size']} | {summary} | {r['source']} | {r['domain'] or '-'} |")

OUT.write_text("\n".join(lines), encoding="utf-8")
print(f"Wrote {OUT}")
print()
print(f"String-anchored summaries: {src_counts.get('string', 0)}/{len(records)} ({src_counts.get('string', 0)/len(records)*100:.1f}%)")
print(f"Pattern-fallback summaries: {src_counts.get('pattern', 0)}/{len(records)} ({src_counts.get('pattern', 0)/len(records)*100:.1f}%)")
