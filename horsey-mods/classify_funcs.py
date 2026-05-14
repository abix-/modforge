"""Classify decompiled functions into vendor library vs game logic.

Approach:
1. Ghidra recognizes some library functions via FunctionID/PDB matching. These
   get named like '_Init_atexit', 'memcpy', 'CryptUIWizFreePvData'. Names that
   don't start with FUN_ are recognized.
2. Vendor-code heuristics applied to the body:
   - References to SDL_*, cute_sound_*, stb_*, miniaudio, dxgi, d3d* strings.
   - Calls into vendor library functions.
"""
import re
from pathlib import Path
from collections import defaultdict

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
text = DECOMP.read_text(encoding="utf-8", errors="replace")

func_re = re.compile(r"^// ============ 0x([0-9a-f]+) (\S+) \(size=(\d+)\) ============$", re.MULTILINE)
matches = list(func_re.finditer(text))
print(f"Total functions: {len(matches)}")

# Bucket function bodies
funcs = []
for i, m in enumerate(matches):
    addr = int(m.group(1), 16)
    name = m.group(2)
    size = int(m.group(3))
    start = m.end()
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    body = text[start:end]
    funcs.append((addr, name, size, body))

# Library markers that indicate a function is vendor code (not game logic)
LIB_MARKERS = [
    # Visual Studio library markers (Ghidra adds /* Library Function ... */)
    r"Library: Visual Studio",
    r"Library: Visual C\+\+",
    # SDL
    r"SDL_",
    r"SDL\.",
    # cute_sound
    r"CUTE_SOUND_",
    r"cute_sound",
    # stb
    r"stb_image",
    # D3D
    r"D3D11_",
    r"D3D12_",
    # MSVC C++ standard library and CRT
    r"_CxxThrowException",
    r"__CxxFrameHandler",
    r"_invalid_parameter",
    r"_RTC_",
    # JPype/Java
]

LIB_RE = re.compile("|".join(LIB_MARKERS))

# Function-name patterns that are clearly library
LIB_NAME_PREFIXES = [
    "SDL_", "Mix_", "TTF_", "IMG_",
    "cs_", "cute_",
    "ID3D", "IDXGI",
    "Wave", "MS_ADPCM",
    "_Cxx", "_invalid_param", "_RTC_", "_Init_",
    "memcpy", "memmove", "memset", "memcmp", "strcmp", "strcpy", "strncmp",
    "snprintf", "vsnprintf", "fopen", "fclose", "fread", "fwrite", "fseek",
    "malloc", "free", "calloc", "realloc",
]

LIB_NAME_REGEX = re.compile(r"^(" + "|".join(re.escape(p) for p in LIB_NAME_PREFIXES) + r")")

# Classify each function
classified = {"named_recognized": [], "lib_by_body": [], "vendor_by_name": [],
              "fun_unknown": [], "tiny_stub": []}

for addr, name, size, body in funcs:
    if name.startswith("FUN_"):
        # Auto-name, no Ghidra recognition. Could be game logic OR unrecognized vendor.
        if size <= 4:
            classified["tiny_stub"].append((addr, name, size))
        elif LIB_RE.search(body):
            classified["lib_by_body"].append((addr, name, size))
        else:
            classified["fun_unknown"].append((addr, name, size))
    else:
        # Ghidra recognized the function name via FunctionID/PDB.
        if LIB_NAME_REGEX.match(name) or LIB_RE.search(body):
            classified["vendor_by_name"].append((addr, name, size))
        else:
            classified["named_recognized"].append((addr, name, size))

total = len(funcs)
print()
print(f"{'Category':<25s} {'Count':>8s} {'%':>6s}  {'Total size (KB)':>15s}")
print("-" * 70)
for k, v in classified.items():
    pct = len(v) / total * 100
    sz = sum(s for _, _, s in v) / 1024
    print(f"{k:<25s} {len(v):>8d} {pct:>5.1f}%  {sz:>14.1f}")

# Estimate "game logic only" count
game_logic_count = len(classified["fun_unknown"]) + len(classified["named_recognized"])
print()
print(f"Estimated game-logic functions: {game_logic_count}")
print(f"  (FUN_ unknown + named non-vendor)")
print()
print(f"Estimated vendor functions: {len(funcs) - game_logic_count}")

# Show some samples
print()
print("=== Sample of 'fun_unknown' (likely game logic, auto-named): ===")
for addr, name, size in classified["fun_unknown"][:10]:
    print(f"  0x{addr:x}  {name}  size={size}")

print()
print("=== Sample of 'named_recognized' (Ghidra named non-library): ===")
for addr, name, size in classified["named_recognized"][:20]:
    print(f"  0x{addr:x}  {name}  size={size}")
