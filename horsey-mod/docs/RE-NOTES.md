# Horsey.exe - Reverse Engineering Notes

Strings extracted 2026-05-13 from `Horsey.exe` (build mtime 2026-05-08). These are anchors to identify the fatigue / age / lifecycle code in Ghidra (or IDA / Cutter).

Stripped native PE x64. SDL3 + cute_sound + stb_image_write. No PDB. Source filenames leaked: at least `GeneEnum.h`.

## How to use these anchors

In Ghidra:
1. File -> Import -> `Horsey.exe`. Auto-analyze.
2. Window -> Defined Strings. Filter by the keyword.
3. Right-click the string -> References -> Show References to Address. That gives the function(s) that reference the string.
4. Walk those callers backward to find the comparison / counter.
5. The hardcoded threshold is almost always a numeric immediate in a `cmp` or `mov` instruction near the string load.

## Tier 1 anchors - directly tied to user's complaints

### Stamina / fatigue (one race then tired)

Exact match strings in the binary:

```
Horse is too tired!
That's a tired looking horse!
That horse is looking a bit rusty
Go home and rest your horse first
Why not go home and rest your horse
None of your horses are tired
I'm so tired!
I'm tired
I require rest
I require sleep
I require my beauty rest
Sleepy weepy time
Time for a power nap!
Sleep now
Wakey wakey
I'm awake
```

Strategy: find xrefs to `"Horse is too tired!"`. The function showing this dialog is the eligibility-check branch. The OTHER branch (the success path) increments the race counter. Look one level up for the actual fatigue value being compared.

### Lifespan / aging

```
Horse is too old!
Horse is too young!
That horse is too old to race
That horse is too old.
That horse is too old
But then I got stuck with it when it was too old to race
%s retired %s (old) ch %d races %d wins %d%s
%s retired %s (bails) age %d ch %d
%s retired %s (useless) age %d ch %d
%s%s retired %s
%s is getting old. I can only offer you $%d
Horse is dead!
Why that horse is deceased
They'll be fed and sheltered and taken good care of in retirement
HorsesAge
```

Strategy: the retirement format string `%s retired %s (old) ch %d races %d wins %d%s` is referenced exactly once, from the "retire-due-to-age" branch. Walk backward to find the age comparison.

### Hunger

```
Horse is too hungry!
%s is hungry!
That horse isn't hungry!
I'm so hungry!
I'm hungry
All your horses are hungry!
Your horse is hungry! Feed it first
I'm ready to touch grass
```

## Tier 2 anchors - debug / format strings (extremely useful)

These leak the internal data model. The functions that produce them have all the relevant counters as local variables.

```
< Simulation Paused - Year %d  Sleeps %d  Races %d >
< Simulation Paused - Year %d >
Race %d-%s  champs %d  aborts %d  time %d
%s = (%d rand + %d nice + %d record) * %d years + %d deco   gdist=%.3f
horses: %d   bails: %d   errors: %d
year %d  herb %d  %s %d  max %d  gendiv %d
%s%s foaled %s from %s%s and %s%s
```

The first one is decisive: a function exists that prints YEAR, SLEEPS, and RACES counters in one line. Find its xref, and we have the addresses of all three globals (or struct fields).

The third one (`(%d rand + %d nice + %d record) * %d years + %d deco`) is the **horse price/score formula**. The `* %d years` factor proves age is an integer field; the function reading the format string also reads the horse's age field.

## Tier 3 anchors - source identifiers

These prove there's a strict enum and a chromoMap mapping. Names from `genes.xml` line up with enum values internally.

```
GeneEnum.h
Gene %d exists twice in chromoMap
Gene %d not in chromoMap
8gene
log_races
StartGeneDrive
SwitchToGeneDrive
Engaging GENE DRIVE!
Gene Drive must have a target
CRISPR a gene
```

`log_races` is probably a debug flag. Worth checking - if it's a CLI argument or env var, we might enable extra debug logging that exposes the fatigue counter directly.

## Tier 4 anchors - game state / mechanics

```
Goal 1: get the horse population to %d
Goal 2: get genetic diversity to %d%%
Bring a horse here if you wanna race!
Click Race when ready!
Race!
%s ate some hay today
%s had a nice walk today
%s was a good horse today
%s%s is the latest champion horse!
Mate two horses
Biological mating is pointless and obsolete
Let's mate
BarnMating
```

The "%s was a good horse today" / "%s ate some hay today" pattern suggests a per-day per-horse event log. The day-tick handler is here.

## Calling convention and ABI

- Windows x64 MSVC ABI.
- First four integer args: RCX, RDX, R8, R9.
- First four float args: XMM0-XMM3.
- Stack-based for the rest, with shadow space.
- Pointers are 8 bytes. struct fields are commonly read with `mov rax, [rcx+offset]`.

## Hooking strategies (when we get to patching)

1. **Byte patch**: if the fatigue threshold is an immediate (`cmp [horse+0x80], 1` -> `cmp [horse+0x80], 100`). Smallest diff but breaks on every game update.
2. **NOP the check**: if the comparison is a branch we want to skip, NOP out the conditional jump. Quick and dirty.
3. **DLL hook with MinHook**: most flexible. Hijack via:
   - Proxy `steam_api64.dll` (rename real DLL, drop a proxy that loads it and our code).
   - Or delay-load DLL injection.
   - Inside the hook, replace the threshold read or the comparison outcome.
4. **Code cave + jump**: write fresh logic to a code cave, redirect with `jmp`. Most invasive but pattern-matches well across small updates.

## Per-update fragility

The binary is 4.4 MB and stripped. Every patch will shift function addresses. Two mitigations:

- Use **pattern signatures** (byte patterns with wildcards) instead of absolute offsets.
- Anchor on **string xrefs**, not addresses. A hook that finds `"Horse is too tired!"`, follows the xref, and pattern-matches the comparison instruction nearby survives minor refactors.

## Order of operations for Phase 2

1. Load `Horsey.exe` in Ghidra. Wait for analysis (5-15 min on first load).
2. Find the function referencing `"< Simulation Paused - Year %d  Sleeps %d  Races %d >"`. This single function exposes the YEAR, SLEEPS, RACES globals. Document their addresses.
3. Find the function referencing `"Horse is too tired!"`. Identify the field offset within the horse struct that holds the fatigue counter, and the immediate it's compared against.
4. Find the function referencing `"%s retired %s (old) ch %d races %d wins %d%s"`. Identify the age field and the retirement threshold.
5. Decide: byte patch vs DLL hook. Byte patch is fine for a single-user mod that doesn't need to survive patches.
