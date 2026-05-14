"""Extract EVERY function in Horsey.exe into its own file.

Filenames: <address>_<sanitized_name>.c
Sharded into subdirs by address prefix to keep any one dir manageable.
"""
import re
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
OUT_DIR = Path(r"C:/code/horsey-mods/decompiled/funcs")
OUT_DIR.mkdir(exist_ok=True)

WIN_BAD = set(r'<>:"/\|?*')  # illegal Windows filename chars


def sanitize(name: str) -> str:
    out = []
    for c in name:
        if c in WIN_BAD or ord(c) < 32:
            out.append("_")
        else:
            out.append(c)
    s = "".join(out).strip(". ")  # Windows: trailing dot/space not allowed
    return s[:120] if len(s) > 120 else s  # cap length


text = DECOMP.read_text(encoding="utf-8", errors="replace")
print(f"Loaded {len(text)} bytes")

func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) .*?============$", re.MULTILINE)
matches = list(func_re.finditer(text))
print(f"Found {len(matches)} functions")

# Shard by top byte of address (e.g. 0x14001xxxx -> shard "14001")
written = 0
collisions = 0
for i, m in enumerate(matches):
    addr_hex = m.group(1)
    name = m.group(2)
    start = m.start()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    body = text[start:end]

    # Shard dir: first 5 hex chars of address (covers 0x14001..0x14030 etc)
    shard = addr_hex[:5] if len(addr_hex) >= 5 else addr_hex
    shard_dir = OUT_DIR / shard
    shard_dir.mkdir(exist_ok=True)

    safe_name = sanitize(name)
    filename = f"{addr_hex}_{safe_name}.c"
    out_path = shard_dir / filename

    if out_path.exists():
        collisions += 1
        # Use the index to disambiguate (shouldn't happen but be safe)
        out_path = shard_dir / f"{addr_hex}_{safe_name}_{i}.c"

    with out_path.open("w", encoding="utf-8") as f:
        f.write(f"// Address: 0x{addr_hex}\n")
        f.write(f"// Ghidra name: {name}\n")
        f.write(body)
    written += 1

    if (i + 1) % 1000 == 0:
        print(f"  written {i + 1}/{len(matches)}")

print()
print(f"DONE.")
print(f"  Total written: {written}")
print(f"  Filename collisions resolved: {collisions}")
print(f"  Output: {OUT_DIR}")

# Count shards
shards = sorted(OUT_DIR.iterdir())
print(f"  Shards: {len(shards)}")
for s in shards:
    if s.is_dir():
        n = len(list(s.iterdir()))
        print(f"    {s.name}: {n} files")
