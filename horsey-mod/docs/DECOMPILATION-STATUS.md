# Decompilation status
> **Authoritative on:** the state of the Ghidra decompilation pipeline (toolchain, statistics, output artifacts).

## TL;DR

All 10,332 functions in `Horsey.exe` have been decompiled to C-like pseudocode using Ghidra 12.1 (headless via pyghidra). 20 high-value functions identified via string anchors and extracted to individual files for documentation.

## Pipeline

```
Horsey.exe (4.4 MB stripped PE x64)
   │
   ├─ pyghidra (Ghidra 12.1 headless decompiler)
   │
   ▼
decompiled/all_functions.c (18.3 MB, 10,332 functions)
decompiled/INDEX.md         (function index: address, name, size, sig)
   │
   ├─ search_decomp.py (regex over function bodies)
   │
   ▼
decompiled/KEY-FUNCTIONS.md (anchor strings → function addresses)
   │
   ├─ extract_funcs.py (carves named function out of all_functions.c)
   │
   ▼
decompiled/key-funcs/*.c    (one file per documented function)
```

## Numbers

| Metric | Value |
|---|---|
| Binary size | 4,371,968 bytes (4.17 MiB) |
| Functions discovered by Ghidra | 10,332 |
| Functions decompiled successfully | 10,331 |
| Functions that failed | 1 (a 1-byte stub) |
| Pseudocode output size | 18.3 MB |
| Decompilation wall time | ~5 minutes (~33 funcs/sec) |
| Ghidra auto-analysis time | ~2 minutes |

## Toolchain installed

| Component | Version | Path |
|---|---|---|
| Microsoft OpenJDK | 21.0.11.10 | `C:\Program Files\Microsoft\jdk-21.0.11.10-hotspot` |
| Ghidra | 12.1 (2026-05-13 release) | `C:\code\ghidra_12.1_PUBLIC` |
| pyghidra | 3.0.2 | pip site-packages |
| jpype1 | 1.5.2 | pip site-packages |
| Ghidra project | created | `C:\code\horsey-mods\ghidra-project\horsey.gpr` |

Environment variables (added to `~/.bashrc`):
- `JAVA_HOME=/c/Program Files/Microsoft/jdk-21.0.11.10-hotspot`
- `GHIDRA_INSTALL_DIR=C:/code/ghidra_12.1_PUBLIC`

## What we have

### `decompiled/all_functions.c`

Every function in the binary, in address order, with the format:

```
// ============ 0xADDRESS FUN_NAME (size=N) ============
<C-like pseudocode>
```

Searchable by address or name with grep.

### `decompiled/INDEX.md`

Table of every function: address, name, body size, signature. ~10,332 rows.

### `decompiled/KEY-FUNCTIONS.md`

For each anchor string we care about (e.g. `"Horse is too tired!"`, `"%s retired %s (old) ch %d races %d wins %d%s"`, `"save%d.dat"`), the table of which function(s) reference it. This is the bridge from "thing we care about" to "specific function to read".

### `decompiled/key-funcs/`

One C file per identified function. 20 currently extracted, including:

| Address | Hint | Why it matters |
|---|---|---|
| 0x1400dde40 | interact_dispatch_or_status_check | Central status handler. References "Horse is too tired!", "Horse is too old!", "Horse is too young!" - the eligibility-check function. |
| 0x140033a10 | price_or_score_formula | The `(rand + nice + record) * years + deco` formula. Exposes the age field. |
| 0x140066200 | simulation_paused_status | The `Year/Sleeps/Races` debug line. Holds all three counter globals. |
| 0x14008ffc0 | genome_clipboard_copy_paste | Genome serializer. Tells us the genome format. |
| 0x1400a3eb0 | chromomap_loader | Loads gene table. Defines `genes.xml` semantics. |
| 0x140089510 | save_filename_format | Save file open/write. The save struct layout. |
| 0x1400df280 | retirement_branch | Retired (old/bails/useless). Holds age threshold. |
| 0x1400dcab0 | getting_old_buy_horse | "%s is getting old. I can only offer you $%d" - price-by-age dialog. |

Each file is self-contained: a function header comment with the hint and address, then the decompiled body.

## Quality notes

The decompiled output is real and usable. Ghidra recognized some library functions automatically (`Visual Studio 2019 Release` library matches for things like `~_Init_atexit`). Unrecognized functions get auto-names like `FUN_140xxxxxx`.

Common patterns to expect in the output:
- Variable names are auto-generated (`uVar1`, `local_58`, `param_3`).
- Struct fields show as offsets: `*(int *)(param_1 + 0x350)`.
- String constants resolve to symbols: `s_Horse_is_too_tired_140xxxxxx`.
- Global vars: `DAT_140xxxxxx`.
- Control flow is reconstructed; jumps become `if`/`while`/`do-while`.

## What 100% decompilation does NOT mean

We have 100% of the FUNCTIONS decompiled. We do NOT yet have:

- **100% of functions named.** ~10,300 are still `FUN_140xxxxxx`. Naming each requires reading the body and figuring out what it does.
- **100% of structs reconstructed.** Field offsets are visible as numbers; the types and field names are not. Worked out function-by-function as we read.
- **100% of behavior documented.** We have raw pseudocode; turning it into human-readable behavior summaries is the documentation-writing phase.

The decompilation engine has done its part. The remaining work is human (or AI-driven) reading and documentation.

## Next steps

1. Read and document each of the 20 extracted key functions. Curated names + descriptions land in [`ALL-FUNCTIONS.md`](ALL-FUNCTIONS.md) (the merged function index).
2. From those, reconstruct the `Horse` struct (the offsets like `+0x350`, `+0x39c`, `+0x3a0` from `interact_dispatch_or_status_check` are all fields of the same horse struct).
3. Identify the fatigue counter byte and the age field. These are the targets for our mod.
4. Walk callers and callees of named functions; document those too. Expand outward.
5. Use `Function ID` Ghidra analyzer with public SDL3/MSVC signature databases to bulk-name vendor functions and exclude them from manual work.

## Scripts in this repo

| Script | Purpose |
|---|---|
| `decompile.py` | Drives pyghidra to decompile all functions. One-shot, idempotent (resumes from project cache). |
| `search_decomp.py` | Greps the all_functions.c for anchor strings, writes KEY-FUNCTIONS.md. |
| `extract_funcs.py` | Carves named functions out of all_functions.c into separate files. |
| `parse_save.py` | Walks save1.dat horse roster. |
| `diff_save.py` | Byte-diff two save snapshots. |

## Reproducibility

To rebuild from scratch:

```bash
# Prereqs: Java 21 + Ghidra 12.1 unzipped + pyghidra installed
export JAVA_HOME="/c/Program Files/Microsoft/jdk-21.0.11.10-hotspot"
export GHIDRA_INSTALL_DIR="C:/code/ghidra_12.1_PUBLIC"

py decompile.py        # ~5 minutes
py search_decomp.py    # seconds
py extract_funcs.py    # seconds
```
