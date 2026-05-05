# grounded2mods - project state

## Current focus
Reverse-engineering and modding Grounded 2 (UE 5.4, build 0.4.0.2). The
"Better Backpack" mod (40 -> 60 main inventory slots) is the lead worked
example. The pak prototype was retired; the mod ships as an injected DLL.

## Layout (post 2026-05-04 doc reorganization)

```
grounded2mods/
  README.md                 Repo landing page + nav.
  better-backpack/          The mod and all its docs.
    README.md               Landing page + nav for the mod.
    INSTALL.md              End-user install/use guide.
    TROUBLESHOOTING.md      Failure modes and fixes.
    BUILDING.md             Build, configuration, internals, porting.
    REQUIREMENTS.md         Design spec, research, verification plan.
    SHIPPING-BUILD-NOTES.md UE5 shipping logging/console quirks.
    inspection-guide.md     Generic UE5 modding methodology + worked
                            examples + SDK research. Moved from repo
                            root because the worked examples + SDK
                            research are inseparable from the mod design.
    dllmain.cpp             DLL: console + log + scan + patch + rescan.
    basic_impl.cpp          Slim Dumper-7 Basic.cpp (avoids Engine_*).
    inject.c                Standalone external injector.
    build.bat               MSVC build (DLL + injector).
  scripts/                  Python utilities for cooked-asset inspection.
```

## Doc split rationale (2026-05-04)
The mod's documentation was a single 185-line README.md mixing user guide,
dev guide, troubleshooting, and design notes. Split for navigability:
- README.md became a thin landing page (3 KB) with a "where to start" table.
- User flows (install, troubleshoot) are in their own docs.
- Dev concerns (build, internals, porting) are in BUILDING.md.
- Design + research stayed in REQUIREMENTS.md (TOC added).
- Logging/console UE5 shipping quirks pulled out of inspection-guide.md
  into SHIPPING-BUILD-NOTES.md so it's referenceable from the mod's docs
  without sending the reader through 1400 lines of methodology.
- inspection-guide.md moved into better-backpack/ since the worked
  examples and SDK research drove the mod's design.

## Key technical facts (verified)
- Player main backpack capacity: `Maine.UInventoryComponent +0x01E0`
  (`int32 DefaultMaxSize`). Confirmed `Maine_classes.hpp:29557`.
- Vanilla values: main = 40, mount = 30. Mod target = 60.
- Widget side: `UI_Container_BackpackSide_C.MaxRows` (4 vanilla, target 6).
  Patched reflectively via FProperty walk so it survives field reorderings
  across game updates.
- UE5 Shipping strips console + file logging. Grounded 2 never writes
  `Augusta.log`. Verification of any mod requires runtime injection. See
  better-backpack/SHIPPING-BUILD-NOTES.md.
- Grounded 2 has no listed anti-cheat as of 0.4.0.2.
- Game executables: Steam = `Grounded2-WinGRTS-Shipping.exe`, Xbox Game
  Pass = `Grounded2-WinGDK-Shipping.exe`.

## Why DLL, not pak, not UE4SS
- Pak: cannot be verified in shipping (no Augusta.log, no console).
- UE4SS: would work, adds an external runtime dependency and a folder
  layout that complicates packaging. Heavier than needed for a single
  mod with no Lua story.
- Manual remote-thread injector (chosen): pattern lifted from
  x0reaxeax/Grounded2Minimal (MIT). Single user step: run inject.exe.
  Game has no anti-cheat so this is safe today.

## Last session
1. Reviewed the original `dllmain.cpp` against SDK headers. Confirmed
   offset 0x01E0 correct.
2. Researched canonical UE5 mod injection paths via WebSearch + GitHub.
3. Repo was reorganized (by parallel session) to consolidate everything
   into `better-backpack/`. Pak prototype retired. `inject.c` and
   `basic_impl.cpp` added. Build is now ~30s.
4. Wrote user guide (INSTALL.md), troubleshooting guide
   (TROUBLESHOOTING.md), build/internals doc (BUILDING.md). Added TOC
   to REQUIREMENTS.md.
5. Moved inspection-guide.md from root into better-backpack/.
6. Extracted UE5 shipping logging/console section from inspection-guide.md
   into SHIPPING-BUILD-NOTES.md and replaced with a one-paragraph stub
   plus a back-reference.
7. Rewrote both READMEs as thin landing pages with TOCs / nav tables.

## Current state
- DLL + injector source complete.
- Docs split into focused files with TOCs.
- `dist/` empty -- needs `build.bat` run to produce binaries.
- No verified end-to-end run captured yet.

## Next steps
- Run `build.bat`, inject into a live game session, verify the 60-slot
  inventory and 6-row widget. Capture log output.
- Optional: settings.json reader so kSlotCount is runtime-configurable.
- Optional: offset sanity check before writing.

## Open questions
- Hard upper bound on `kSlotCount` (does the engine clamp very large
  values?). 60 is the only verified target.
- Multiplayer: server-authoritative cap may clamp client-side. Out of
  scope for v1.
- Re-injection during a single session is undefined. Documented as
  "don't do that" rather than supported.
