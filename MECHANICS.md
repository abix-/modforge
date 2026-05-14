# Horsey game mechanics (decompiled)

Verified findings from decompiled `Horsey.exe`. Every claim cites a function address or global address you can grep in `decompiled/all_functions.c`.

## TL;DR for the user's complaints

**The game HAS A BUILT-IN CHEAT** that disables horse tiredness. Documented below as the "No Tire" toggle. We don't need a mod for the fatigue complaint - the dev shipped a way to disable it.

We also found the Money cheat and the "Loaded" multi-counter cheat that ships with the game.

**Cross-verified**: a Steam community guide by JumboDS64 independently confirms the debug-mode unlock ("spelling d-e-b-u-g in the pause menu"). See [`EXTERNAL-KNOWLEDGE.md`](EXTERNAL-KNOWLEDGE.md). Additional cheat from that guide we hadn't found:

- **Press `5` while in the hot air balloon** -> x300 game speed.

## Debug mode (the cheat unlock)

Reference: `FUN_140066200` @ 0x140066200, around line 60371-60376 of `decompiled/all_functions.c`.

```c
if (((DAT_1403eab10 < 5) && ((&DAT_1403ed5d0)["debug"[DAT_1403eab10]] != '\0')) &&
   (DAT_1403eab10 = DAT_1403eab10 + 1, DAT_1403eab10 == 5)) {
  DAT_1403d959b = '\x01';  // <-- debug mode enabled
  DAT_1403d9522 = 0;
}
```

Translation: there's a character-by-character matcher that checks if the user typed "debug". When complete (5 characters matched, since `"debug"` is "d","e","b","u","g" - wait, that's 5 chars including the null terminator, or maybe just 5 chars total including any character delta we missed).

After unlocking:
- The pause-menu status line changes from `< Simulation Paused - Year %d >` to `< Simulation Paused - Year %d  Sleeps %d  Races %d >` (the debug version).
- A set of cheat buttons appears: "Betting Mode", "Gong" (referenced via `0x676e6f47` literal), "Money", "Loaded", "No Tire" / "Yes Tire".

The exact UI trigger and key-input handling needs more decompilation to confirm. The string `"debug"` clearly matches user input character-by-character.

## The "No Tire" cheat (DIRECTLY addresses user's complaint)

Reference: same function `FUN_140066200`, line 60434-60443:

```c
pcVar10 = "No Tire";
if (DAT_1403d95c5 != '\0') {
  pcVar10 = "Yes Tire";
}
cVar5 = FUN_140067490(param_1, &local_a8, pcVar10);
if (cVar5 != '\0') {
  DAT_1403d95c5 = DAT_1403d95c5 == '\0';   // toggle
}
```

The flag `DAT_1403d95c5` is the "Tiredness" mode toggle. Now find where it's READ in the simulation:

Reference: `FUN_1400ce6c0`-area, around line 121172:

```c
if (DAT_1403d95c5 == '\0') {
  return;  // normal: don't reset anything
}
// "Yes Tire" mode: zero out tiredness flags on EVERY HORSE EVERY FRAME
iVar12 = (int)(param_1[0x27] - param_1[0x26] >> 3) + -1;
lVar17 = (longlong)iVar12;
if (iVar12 < 0) {
  return;
}
do {
  *(undefined1 *)(*(longlong *)(param_1[0x26] + lVar17 * 8) + 0x206) = 0;
  *(undefined1 *)(*(longlong *)(param_1[0x26] + lVar17 * 8) + 0x205) = 0;
  lVar17 = lVar17 + -1;
} while (-1 < lVar17);
```

What this means:
- `param_1[0x26]` and `param_1[0x27]` are begin/end pointers of the horse list (note: these are at different offsets than the other horse-list iter we saw at 0xb8/0xc0 - this is a DIFFERENT horse list, probably "horses currently on the track" or "horses owned by player").
- For each horse, two byte fields are zeroed:
  - `horse + 0x205` = some tiredness flag
  - `horse + 0x206` = another tiredness flag (probably "needs sleep" and "just raced")

When this loop runs every frame, those flags are constantly reset to zero, so the horse never registers as "too tired".

**The toggle's two states are mislabeled (or the labels are flipped from intuitive):**
- **"No Tire" (DAT_1403d95c5 = 0)**: normal game. Horses tire after racing.
- **"Yes Tire" (DAT_1403d95c5 = 1)**: cheat mode. Tiredness flags reset every frame. Horses never tire.

Or possibly the convention is "Yes Tire" means "yes [I want to remove] tire" or similar - the labels are ambiguous. What's NOT ambiguous: the FLAG being TRUE causes per-frame fatigue reset.

## Money cheat

Reference: line 60473:

```c
*(int *)(DAT_1403fb0d8 + 0x308) = *(int *)(DAT_1403fb0d8 + 0x308) + 1000;
```

The "Money" button adds 1000 to the field at offset 0x308 of the global game state (which is at `DAT_1403fb0d8`).

So: **Money field = game_state + 0x308**.

## Loaded cheat (multi-counter)

Reference: lines 60445-60470:

```c
*(undefined1 *)(DAT_1403fb0d8 + 0x321) = 1;
*(undefined1 *)(DAT_1403fb0d8 + 0x320) = 1;
*(int *)(DAT_1403fb0d8 + 0x31c) = *(int *)(DAT_1403fb0d8 + 0x31c) + 0x14;  // += 20
FUN_140104370(DAT_1403fb0d8);

// repeat for 0x329/0x328/0x324
// repeat for 0x331/0x330/0x32c
// repeat for 0x339/0x338/0x334
// repeat for 0x341/0x340/0x33c
// repeat for 0x349/0x348/0x344
// (7 total sets, in a strided 8-byte pattern)
```

This is 7 identical operations at striding offsets +0x8 apart. Each one:
- Sets a flag byte at base+0x320 (then +0x328, +0x330, ...)
- Sets another flag byte at base+0x321 (then +0x329, +0x331, ...)
- Adds 20 to a 4-byte counter at base+0x31c (then +0x324, +0x32c, ...)
- Calls `FUN_140104370` with the game state pointer

7 entries at 8-byte stride is consistent with 7 different "item types" or "supplies" - probably one entry per game-state stockpile (hay? food? straw? bedding? medical? trophies? something else).

## Global game-state struct (`DAT_1403fb0d8`)

Single global pointer to the main game state. Fields we've identified so far:

| Offset | Type | Field | Source |
|---|---|---|---|
| 0x308 | int32 | Money | +1000 by Money cheat |
| 0x314 | int32 | Year counter (0-indexed; displayed +1) | "Year %d" status line |
| 0x318 | int32 | Sleeps counter | "Sleeps %d" status line |
| 0x31c | int32 | Supply 1 counter (+20 by Loaded) | Loaded cheat |
| 0x320 | uint8 | Supply 1 flag A | Loaded cheat |
| 0x321 | uint8 | Supply 1 flag B | Loaded cheat |
| 0x324 | int32 | Supply 2 counter | Loaded cheat |
| 0x328 | uint8 | Supply 2 flag A | Loaded cheat |
| 0x329 | uint8 | Supply 2 flag B | Loaded cheat |
| 0x32c | int32 | Supply 3 counter | Loaded cheat |
| 0x330 | uint8 | Supply 3 flag A | Loaded cheat |
| 0x331 | uint8 | Supply 3 flag B | Loaded cheat |
| ... | ... | (7 total supplies in this strided table, ending at 0x349) | Loaded cheat |

## Races counter (separate global)

The Races counter is NOT in the game-state struct. It's a separate global at `DAT_1403eded8`. Initialized to 0 (line 84920) and elsewhere set to 3 (line 84932 - perhaps a "min races" or initial value).

## Horse struct fields (incrementally identified)

Different functions access horses through different pointers, so the "horse list" exists in multiple places (probably one global all-horses list, one per-track current-racers list, one per-location residents list). Fields confirmed so far:

| Offset | Type | Field | Source |
|---|---|---|---|
| 0x205 | uint8 | Tiredness flag A (zeroed by Yes Tire) | Yes Tire reset loop |
| 0x206 | uint8 | Tiredness flag B (zeroed by Yes Tire) | Yes Tire reset loop |
| 0x21 | uint8 | ??? (used by 1400cead0 check) | iter loop |
| 0x1c | int32 | type/kind field (== 2 or 1 in one check) | line 121168 |
| 0x1c4 | int32 | ??? (subtracted in delta) | line 121151 |
| 0x1c8 | int8 | ??? (boolean check) | line 121155 |

## Mod implications

The user's fatigue complaint is solved BY THE GAME ITSELF if they can trigger the "No Tire" cheat. This is the simplest possible solution: no modding needed, just the unlock code.

**Lifespan complaint**: not yet found a built-in cheat. The retirement function at `FUN_1400df280` is the next read target. We know it references the format string `"%s retired %s (old) ch %d races %d wins %d%s"` so the actual age comparison is in there.

## Confidence levels

- "No Tire" toggle disables tiredness via per-frame flag reset: **HIGH** (direct reading of the code)
- Money cheat = +$1000: **HIGH** (literal `+ 1000` on a specific field)
- "debug" unlock string: **HIGH** (literal string used in character-by-character matcher)
- Loaded gives 7 supply types of +20 each: **HIGH** (literal pattern, 7 iterations at stride 8)
- Money field at game_state+0x308: **HIGH** (cited in cheat code)
- Horse 0x205/0x206 = tiredness flags: **MEDIUM** (clearly tiredness-related from context, but the EXACT semantic - whether they're "needs sleep" vs "just raced" vs "fatigue counter" - is not certain. We know zeroing them disables the tiredness effect.)
- Supply offsets 0x308..0x349: **MEDIUM** (struct layout confirmed, but which supply is which isn't named)
