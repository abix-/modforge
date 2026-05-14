"""Extract specific functions from the decompiled output into individual files."""
import re
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
OUT_DIR = Path(r"C:/code/horsey-mods/decompiled/key-funcs")
OUT_DIR.mkdir(exist_ok=True)

KEY_FUNCS = [
    ("0x1400dde40", "interact_dispatch_or_status_check"),    # Horse is too tired/old/etc - branching status messages
    ("0x140033a10", "price_or_score_formula"),                 # the rand/nice/record/years formula
    ("0x140038040", "tired_looking_horse_dialog"),
    ("0x140060a80", "rest_your_horse_or_too_young"),
    ("0x1400e0aa0", "none_of_horses_are_tired"),
    ("0x1400df280", "retirement_branch"),                      # retired (old|bails|useless) format strings
    ("0x1400dcab0", "getting_old_buy_horse"),
    ("0x14006dc80", "horse_too_hungry"),
    ("0x14006e480", "save_path_writer_1"),                     # save%d.dat
    ("0x140076a10", "settings_xml_handler"),
    ("0x1400777c0", "settings_xml_handler_2"),
    ("0x1400a36e0", "genes_dat_handler"),
    ("0x1400a3eb0", "chromomap_loader"),
    ("0x140089510", "save_filename_format"),
    ("0x1400fd3e0", "found_chromosomes_log"),
    ("0x140094a20", "click_race_when_ready_dialog"),
    ("0x140066200", "simulation_paused_status"),
    ("0x14008ffc0", "genome_clipboard_copy_paste"),
    ("0x1400c0660", "horse_is_dead_handler"),
    ("0x14010ba40", "horse_is_deceased_handler"),
]

text = DECOMP.read_text(encoding="utf-8", errors="replace")

# Build address->span map
func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) .*?============$", re.MULTILINE)
matches = list(func_re.finditer(text))
spans = {}
for i, m in enumerate(matches):
    addr = "0x" + m.group(1)
    name = m.group(2)
    start = m.start()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    spans[addr] = (name, text[start:end])

for addr, hint in KEY_FUNCS:
    if addr not in spans:
        print(f"  MISS: {addr}")
        continue
    name, body = spans[addr]
    out_path = OUT_DIR / f"{addr}_{hint}.c"
    with out_path.open("w", encoding="utf-8") as f:
        f.write(f"// Hint: {hint}\n")
        f.write(f"// Address: {addr}\n")
        f.write(f"// Ghidra name: {name}\n")
        f.write(body)
    print(f"  wrote {out_path.name}  ({len(body)} bytes)")
