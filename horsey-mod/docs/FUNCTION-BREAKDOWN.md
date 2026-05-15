# Function breakdown - why 10,332 isn't crazy

You correctly noticed that 10,332 functions sounds like way too many for a small game. Mostly correct. Here's the breakdown.

## Size distribution

| Bucket | Count | % | Total code |
|---|---|---|---|
| Tiny stubs (1-8 B) | 1,486 | 14.4% | 9.9 KB |
| Small (9-32 B) | 1,465 | 14.2% | 34.9 KB |
| Medium (33-128 B) | 3,115 | 30.2% | 214.7 KB |
| Regular (129-512 B) | 2,898 | 28.1% | 729.6 KB |
| Large (513-2 KB) | 1,170 | 11.3% | 1.1 MB |
| Huge (>2 KB) | 197 | 1.9% | 819.5 KB |

Translation: **58% of functions are under 128 bytes** of compiled code. These are getters, setters, thunks, PLT entries, virtual dispatchers, single-line wrappers. The C++ compiler generates a LOT of these for templates and inlined helpers.

Only the bottom two rows (~1,367 functions) contain code substantial enough to matter, and even there most are still small.

## Vendor vs game-logic

Call-graph analysis: start from functions that reference game-specific strings ("Horse is too tired", "save%d.dat", "genes.dat", "Champion", etc.) and walk outward through call edges.

| Category | Count |
|---|---|
| **Game-logic functions (reachable from game-string seeds)** | **971** |
| Vendor functions (SDL3, cute_sound, MSVC CRT, Windows API wrappers) | 9,360 |
| Total | 10,331 |

So the game itself is ~971 functions. The other ~9,360 are libraries Ghidra picked up because they got compiled into the binary. SDL3 alone has thousands of internal functions (rendering, audio mixer, controller database parsing, file dialogs, GPU API, threading primitives, ...).

This is a much more sensible number for a single-developer indie game. Comparable to:
- ~500-2,000 functions for a typical Stardew-Valley-sized game
- ~50,000+ for AAA titles

971 fits a one-person scope.

## What about the ~9,360 vendor functions?

They're real functions in the binary. They got decompiled like everything else. We just don't need to read them.

Their general makeup (estimated by name pattern + body inspection):
- **SDL3 core** (window, input, threading, file I/O): ~3,000-4,000
- **SDL_GPU + D3D12/D3D11/OpenGL backends**: ~1,500-2,500
- **SDL audio + cute_sound**: ~300-500
- **MSVC C++ Standard Library**: ~1,500-2,000 (string, vector, map, exception machinery, RTTI)
- **MSVC CRT** (printf, malloc, errno, locale): ~500-1,000
- **Windows API wrappers**: ~200-500
- **Misc** (stb_image_write, controller HID parsers, etc.): ~100-200

Realistic numbers, but unverified. Proper vendor identification needs Ghidra's Function ID analyzer with public SDL3 signature databases. That's a one-time setup we can do later if needed.

## Output files

- `decompiled/game_neighborhood.txt`: 971 game-logic addresses + names + sizes
- `decompiled/vendor_funcs.txt`: 9,360 vendor addresses + names + sizes

## Refining the game-logic count

The 971 count came from only 7 "seed" functions (those that literally reference strings like "Horse is too tired" in their decompiled body). Adding more seeds (more game strings, the Tiled map loader, font loader, etc.) would grow the neighborhood. Expect the real game-logic count to settle around **1,000-2,000 functions** once the seeds are exhaustive.

## What to focus on

Of the 971 known game-logic functions, the huge ones (>2 KB) are where game decisions live. There are 197 huge functions overall in the binary; probably 50-150 of them are game logic.

A reasonable reading order:
1. Read the 20 already-extracted key functions in `decompiled/key-funcs/`.
2. Cross-reference their callers/callees within `game_neighborhood.txt`.
3. Iteratively name functions as their purpose becomes clear. Rebuild `game_neighborhood.txt` after each pass; it expands as you find new game strings or rename functions.
