"""Search decompiled output for functions referencing key game strings.

Ghidra represents string literals two ways:
  1. inline literal:  "Horse is too tired!"
  2. symbol ref:      s_Horse_is_too_tired__140abcdef
We search for both.
"""
import re
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
OUT = Path(r"C:/code/horsey-mods/decompiled/KEY-FUNCTIONS.md")

# Anchors: (key, regex-fragment that matches either form)
# The regex should match either the inline literal OR the s_xxx symbol.
TARGETS = [
    # Fatigue / stamina
    ("fatigue.horse_too_tired",       r"Horse_is_too_tired|Horse is too tired"),
    ("fatigue.tired_looking",         r"tired_looking_horse|tired looking horse"),
    ("fatigue.rest_your_horse",       r"rest_your_horse|rest your horse"),
    ("fatigue.none_are_tired",        r"None_of_your_horses_are_tired|None of your horses are tired"),
    ("fatigue.im_tired",              r"I_m_tired|I'm tired"),
    # Age
    ("age.too_old",                   r"Horse_is_too_old|Horse is too old"),
    ("age.too_young",                 r"Horse_is_too_young|Horse is too young"),
    ("age.retired_old",               r"retired.*old.*ch.*races.*wins"),
    ("age.retired_bails",             r"retired.*bails.*age.*ch"),
    ("age.retired_useless",           r"retired.*useless.*age.*ch"),
    ("age.too_old_to_race",           r"too_old_to_race|too old to race"),
    ("age.getting_old",               r"is_getting_old|is getting old"),
    ("age.horses_age_sound",          r"\"HorsesAge\""),
    # Hunger
    ("hunger.too_hungry",             r"Horse_is_too_hungry|Horse is too hungry"),
    ("hunger.feed_it_first",          r"Feed_it_first|Feed it first"),
    # Save
    ("save.filename",                 r"save%d\.dat"),
    ("save.settings",                 r"\"settings\.xml\"|settings_xml"),
    # Genes
    ("genes.filename",                r"\"genes\.dat\"|genes_dat"),
    ("genes.not_in_chromomap",        r"not_in_chromoMap|not in chromoMap"),
    ("genes.exists_twice",            r"exists_twice_in_chromoMap|exists twice in chromoMap"),
    ("genes.genome_copied",           r"Genome_copied_to_clipboard|Genome copied to clipboard"),
    ("genes.genome_pasting",          r"Pasting_genome_from_clipboard|Pasting genome from clipboard"),
    ("genes.found_chromosomes",       r"Found.*chromosomes"),
    ("genes.crispr_a_gene",           r"CRISPR_a_gene|CRISPR a gene"),
    # Race
    ("race.click_when_ready",         r"Click_Race_when_ready|Click Race when ready"),
    ("race.simulation_paused",        r"Simulation_Paused|Simulation Paused"),
    ("race.race_format",              r"Race.*champs.*aborts.*time"),
    ("race.what_a_great_race",        r"What_a_great_race|What a great race"),
    # Price formula
    ("price.formula",                 r"rand.*nice.*record.*years.*deco"),
    # Death
    ("death.dead",                    r"Horse_is_dead|Horse is dead"),
    ("death.deceased",                r"is_deceased|is deceased"),
    # Stats
    ("horses_count",                  r"horses.*bails.*errors"),
    ("year_format",                   r"year.*herb.*max.*gendiv"),
    # DNA mechanics
    ("dna.sampling",                  r"SAMPLING_DNA|SAMPLING DNA"),
    ("dna.start_extract",             r"StartDNAExtract"),
    ("dna.sample",                    r"SampleDNA"),
]

print(f"Reading {DECOMP}...")
text = DECOMP.read_text(encoding="utf-8", errors="replace")
size_mb = len(text) / 1024 / 1024
print(f"Loaded {size_mb:.1f} MB of decompiled output")

print("Indexing function boundaries...")
funcs = []
func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) .*?============$", re.MULTILINE)
matches = list(func_re.finditer(text))
for i, m in enumerate(matches):
    addr = int(m.group(1), 16)
    name = m.group(2)
    start = m.start()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    funcs.append((addr, name, start, end))
print(f"Indexed {len(funcs)} function bodies\n")

print("Searching...")
results = []
for key, pattern in TARGETS:
    rx = re.compile(pattern)
    hits = []
    for addr, name, start, end in funcs:
        body = text[start:end]
        if rx.search(body):
            hits.append((addr, name))
    results.append((key, pattern, hits))
    print(f"  {key:<35s} -> {len(hits)} hits")
print()

out_lines = ["# Horsey.exe - key function references", ""]
out_lines.append(f"Source: `decompiled/all_functions.c` ({size_mb:.1f} MB, {len(funcs)} functions)")
out_lines.append("")
out_lines.append("Each section lists the functions that reference the string. These are the entry points for understanding each mechanic.")
out_lines.append("")
out_lines.append("To view a function: open `decompiled/all_functions.c` and search for its address.")
out_lines.append("")

for key, pattern, hits in results:
    out_lines.append(f"## {key}")
    out_lines.append(f"Pattern: `{pattern}`")
    if not hits:
        out_lines.append("**NOT FOUND**")
    else:
        out_lines.append("")
        out_lines.append("| Address | Function |")
        out_lines.append("|---|---|")
        for addr, name in hits:
            out_lines.append(f"| 0x{addr:x} | `{name}` |")
    out_lines.append("")

OUT.write_text("\n".join(out_lines), encoding="utf-8")
print(f"Wrote {OUT}")
