# mainsequence-mod

Main Sequence (Steam app 2487190) runtime mod. Rust cdylib loaded by
UE4SS as a CPPMod through the ueforge shim.

- Engine: UE 5.7 (exe carries `++UE5+Release-5.7`; UE4SS reports
  `Found EngineVersion: 5.7`). The first UE 5.7 game in this workspace
  whose control plane came up.
- Game: `C:\Games\Steam\steamapps\common\Main Sequence\Windows`,
  binaries in `MainSequence\Binaries\Win64`.
- UE4SS: experimental-latest (`UE4SS_v3.0.1-1133-gb4cefa18`), copied
  from Alchemy Factory by the restart script. Every hook off except
  EngineTick and ProcessEvent.
- Control plane: port 31320, endpoint `/debug`.
- Deploy: `pwsh -NoProfile -File mainsequence-mod/scripts/restart.ps1`
  (closes the game, deploys, relaunches, waits for the control plane).

Live on 2026-11-15:

```
patternsleuth resolved: g_objects=0x87b5a50 g_names=0x86e79c0 append_string=0x1217de0
ue runtime ready, GObjects = 0x7ff6ba415a50
[HashTables] Self test passed (5850 classes with instances)
```

## Stack size

`src/stacks.rs`. Every item is an `Item` data asset
(`Content/Data/Items/ITEM_*`) with `MaxStackSize`, an int at 0x5C.
Vanilla: most 25, motors and couplings 50, plates 15, missiles 5,
backpacks, exoskeletons and the exosuit 1. Items that stack to 1 stay
at 1; the rest are multiplied, 10x by default.

The multiplier is `stack_multiplier` in `settings.json` next to the
mod's `main.dll`. To change it while the game runs:

```text
MULTIPLIER=20 k3sc cargo-lock test -p mainsequence-mod --test research_stacks stack_size_applied -- --test-threads=1 --nocapture
```

That calls the `stack_size` op, saves the file and re-applies from
vanilla (never compounds), then prints every item's value.

Each inventory also has the game's own `StackMultiplier` (int at 0xB0
on `Inventory`); abandoned-station loot containers hold 2. The mod does
not touch it.

Measured 2026-11-15, at the main menu: 75 item assets loaded (the
manifest ships 97), all 75 changed. One apply takes about 13 to 27 s
on the mod's own thread, not the game thread: `is_a` runs a
VirtualQuery on every super class link of 62,000 objects. Items that
load after the first apply are not yet changed until `stack_size` runs
again; not yet checked whether a save load brings in more.
