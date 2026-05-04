# Better Backpack

A standalone Grounded 2 mod that increases the player's main backpack capacity. Configurable slot count via `settings.json`. No dependencies on other mods.

See [REQUIREMENTS.md](REQUIREMENTS.md) for the full design spec.

## Usage

1. Edit `settings.json`. Default is 60 slots.
2. Run `python build.py`. Output is in `dist/`.
3. Install the mod:
   - **With Vortex (recommended):** drag `dist/BetterBackpack-<N>slots.zip` onto the Vortex window, or use Mods -> Install From File. Enable in the mods list, click Deploy.
   - **Manual (no mod manager):** copy the three loose `.pak` + `.ucas` + `.utoc` files in `dist/` into `C:\Games\Steam\steamapps\common\Grounded2\Augusta\Content\Paks\`.
4. Launch the game.

## Prerequisites

The build script needs:

- Python 3.10 or newer.
- `retoc.exe` at `C:\Tools\retoc\retoc.exe` (https://github.com/trumank/retoc).
- `repak.exe` at `C:\Tools\repak\repak.exe` (https://github.com/trumank/repak).
- Cached vanilla extractions at `C:\Tools\work\vanilla_legacy\bp\` and `C:\Tools\work\vanilla_legacy\widget\`. Generate them once with the commands at the top of `build.py`.

If your tool paths differ, edit the constants at the top of `build.py`.

## What it patches

Two assets, single output pak:

- `BP_SurvivalPlayerCharacter`: first `DefaultMaxSize` PropertyTag (the main inventory component) gets set to your `slot_count`. The mount saddlebag value stays at vanilla 30.
- `UI_Container_BackpackSide`: `MaxRows` gets set to `ceil(slot_count / 10)` so the inventory grid renders enough rows to show all slots.

## Settings

```json
{
  "slot_count": 60,
  "target_game_version": "0.4.0.2",
  "load_priority": 99,
  "output_basename": "BetterBackpack"
}
```

| Field                 | Notes |
|-----------------------|-------|
| `slot_count`          | Final main backpack `DefaultMaxSize`. Vanilla is 40. |
| `target_game_version` | Documentation only. |
| `load_priority`       | Embedded in the output filename `<basename>_<priority>_P.{pak,ucas,utoc}`. Higher loads later, wins on chunk-ID conflicts. |
| `output_basename`     | Output filename stem. |

## Compatibility

- **AIO Player Tweaks (or any Player Tweaks variant): conflict.** Both touch `BP_SurvivalPlayerCharacter`. Whichever has higher load priority wins for that asset, completely. With AIO at priority 12 and Better Backpack at 99, Better Backpack wins, meaning AIO's cheats and saddlebag bump will not apply while Better Backpack is installed. Pick one or the other.
- **Bigger Backpack widget mod: redundant.** Better Backpack already includes the widget bump.
- **Multiplayer:** server-authoritative inventory caps may clamp client-side capacity in sessions where the host does not have the mod. Out of scope.

## Caveats

- Hard caps on `DefaultMaxSize` are unknown. Game may silently clamp very large values. The build will accept any int; in-game testing decides what actually works.
- A save with items in the extra slots becomes mostly recoverable but not guaranteed if the mod is uninstalled. Empty extra slots before uninstalling.
