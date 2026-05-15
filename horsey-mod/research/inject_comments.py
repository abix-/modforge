"""Inject per-function header comments into all_functions.c for EVERY function.

Output: decompiled/all_functions_annotated.c

For game-logic functions, use the proposed_name + description from auto_name.py.
For vendor functions, generate a heuristic VENDOR description based on the name pattern.
"""
import re
import json
from collections import Counter
from pathlib import Path

DECOMP = Path(r"C:/code/horsey-mods/decompiled/all_functions.c")
NAMES_JSON = Path(r"C:/code/horsey-mods/decompiled/game-funcs/function_names.json")
NEIGH = Path(r"C:/code/horsey-mods/decompiled/game_neighborhood.txt")
VENDOR = Path(r"C:/code/horsey-mods/decompiled/vendor_funcs.txt")
OUT = Path(r"C:/code/horsey-mods/decompiled/all_functions_annotated.c")

text = DECOMP.read_text(encoding="utf-8", errors="replace")
print(f"Loaded {len(text)} bytes")

names = json.loads(NAMES_JSON.read_text(encoding="utf-8"))

game_addrs = set()
for line in NEIGH.read_text().splitlines():
    parts = line.split("\t")
    if parts and parts[0].startswith("0x"):
        game_addrs.add(int(parts[0], 16))

vendor_info = {}
for line in VENDOR.read_text().splitlines():
    parts = line.split("\t")
    if len(parts) >= 3:
        addr = int(parts[0], 16)
        ghidra_name = parts[1]
        size = int(parts[2])
        vendor_info[addr] = (ghidra_name, size)


def vendor_description(name, size):
    """Generate a description for vendor (non-game-logic) functions."""
    n = name.lower()
    # Recognized library prefixes
    if n.startswith("sdl_") or n.startswith("sdl3_"):
        return ("sdl_function", "SDL3 library function")
    if n.startswith("mix_"):
        return ("sdl_mixer_function", "SDL_mixer library function")
    if n.startswith("cs_") or n.startswith("cute_"):
        return ("cute_sound_function", "cute_sound library function")
    if n.startswith("stb_"):
        return ("stb_function", "stb_image / stb library function")
    if n.startswith("_cxx") or n.startswith("__cxx") or "cxxframehandler" in n:
        return ("cxx_runtime", "MSVC C++ runtime helper")
    if n.startswith("_rtc_") or n.startswith("__rtc_"):
        return ("crt_runtime_check", "MSVC runtime check helper")
    if n.startswith("_init_") or n.startswith("__init_"):
        return ("crt_init", "MSVC CRT initialization")
    if n in ("memcpy", "memmove", "memset", "memcmp", "strlen", "strcpy", "strcat", "strcmp",
             "strncmp", "strncpy", "snprintf", "vsnprintf", "wcslen", "wcscpy", "wcscmp"):
        return ("crt_string_op", "C runtime string operation")
    if n in ("malloc", "free", "calloc", "realloc", "_malloc", "_free"):
        return ("crt_heap_op", "C runtime heap operation")
    if n in ("fopen", "fclose", "fread", "fwrite", "fseek", "ftell"):
        return ("crt_file_op", "C runtime file IO")
    if "thunk_" in n:
        return ("thunk", "PLT-like thunk forwarder")
    if "guard_check_icall" in n or "guard_dispatch_icall" in n:
        return ("cfg_guard", "Control Flow Guard indirect-call check")
    if "k32" in n or "kernel32" in n:
        return ("win_kernel32", "Windows kernel32 API wrapper")
    if "_invoke_watson" in n:
        return ("crt_fatal", "MSVC fatal-error reporter")
    if "ntdll" in n:
        return ("win_ntdll", "Windows ntdll API wrapper")
    if "advapi32" in n:
        return ("win_advapi", "Windows advapi32 API wrapper")
    if n.startswith("d3d") or n.startswith("idxgi") or n.startswith("id3d"):
        return ("d3d_function", "Direct3D wrapper")
    if "loadlibrary" in n or "getmodulehandle" in n:
        return ("win_dll_loader", "Windows DLL loading")
    if size <= 8:
        return ("vendor_stub", "Vendor stub (likely a `ret` or trap)")
    return ("vendor_unknown", "Unrecognized vendor library function")


# Inject comments. Pattern: for each function header line, prepend a comment block.
func_re = re.compile(r"^(// ============ 0x([0-9a-f]+) (\S+) \(size=(\d+)\) ============)$", re.MULTILINE)


def replace(m):
    full_line = m.group(1)
    addr_hex = m.group(2)
    ghidra_name = m.group(3)
    size = int(m.group(4))
    addr = int(addr_hex, 16)
    key = f"0x{addr:x}"

    if key in names:
        n = names[key]
        nm = n["proposed_name"]
        desc = n["description"]
        src = n["source"]
        domain = n["domain"]
        cat = n["category"]
        nc_in = n["n_callers"]
        nc_out = n["n_callees"]
        block = (
            f"// === GAME LOGIC ===\n"
            f"// proposed_name: {nm}\n"
            f"// description: {desc}\n"
            f"// confidence: {src} ({cat})\n"
            f"// domain: {domain}  |  callers in-game: {nc_in}  |  callees in-game: {nc_out}\n"
            f"// (ghidra name: {ghidra_name})\n"
        )
    elif addr in vendor_info:
        nm, desc = vendor_description(ghidra_name, size)
        block = (
            f"// === VENDOR ===\n"
            f"// category: {nm}\n"
            f"// description: {desc}\n"
            f"// (ghidra name: {ghidra_name})\n"
        )
    else:
        block = (
            f"// === UNKNOWN ===\n"
            f"// (ghidra name: {ghidra_name})\n"
        )

    return f"{block}{full_line}"


new_text = func_re.sub(replace, text)

OUT.write_text(new_text, encoding="utf-8")
print(f"Wrote {OUT} ({len(new_text)} bytes)")

# Stats
g = sum(1 for k in names)
v = len(vendor_info)
print(f"Game functions commented: {g}")
print(f"Vendor functions commented: {v}")
print(f"Total: {g + v}")
