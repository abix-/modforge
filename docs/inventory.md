# Inventory and backpack

> **Authoritative on:** how the player backpack works in Grounded 2,
> what the mod patches to grow it, and how the inventory UI grid
> renders. Covers the data side (`UInventoryComponent.DefaultMaxSize`)
> and the visible side (`UWBP_InventoryInterface_C` + `UUI_InventoryGrid_C`).
>
> For the build / loader story see [`ue4ss-port.md`](ue4ss-port.md).
> For the user-facing skill that drives slot count see
> [`rpg.md`](rpg.md). For damage / health internals see
> [`damage.md`](damage.md).

## Two-side problem

Grounded 2's backpack capacity is decided by *two* independent
surfaces. Patching one without the other leaves the mod broken in a
visible way:

1. **Data side.** `UInventoryComponent.DefaultMaxSize` (int32) caps
   how many items the inventory accepts. If this stays at vanilla
   40, the player simply cannot pick up anything past slot 40 -- no
   matter how many slots are drawn on screen.
2. **Visible side.** The widget renders `min(component.DefaultMaxSize,
   MaxRows * MaxColumns)` slots. If the widget's `MaxRows * MaxColumns`
   product stays at the vanilla value (4 * 10 = 40), only 40 slots
   are interactive even when the data side accepts more.

Old Bigger Backpack pak mod (broken in current shipping) only
patched the visible side. Old Player Tweaks pak mod only patched the
data side. Neither alone gave more usable slots; running both at once
was the de-facto requirement.

This mod patches both sides at runtime from a single DLL.

## Data side: `UInventoryComponent.DefaultMaxSize`

| Field | Offset | Source |
| ----- | ------ | ------ |
| `UInventoryComponent.DefaultMaxSize` (int32) | `+0x01E0` | `Maine_classes.hpp:29557` |

Vanilla value depends on the owning actor. Patch policy is to leave
non-player containers alone.

| Owner kind | Vanilla `DefaultMaxSize` | Mod policy |
| ---------- | ----------------------- | ---------- |
| `BP_SurvivalPlayerCharacter*` (every concrete subclass) | 40 | Patched to `slot_count` (default 100) |
| `Mount/Saddlebag` (`MountInventoryComponent`) | 30 | Untouched |
| Chests (`BP_Ominent_Chest*`) | 40 | Untouched |
| Loot bags (`BP_LootBag*`, `BP_DeathLootBag*`) | 40 | Untouched |
| Wearable backpack item (`BP_Backpack_Player*`) | 40 | Untouched |

Filter rule: **only patch components whose outer chain string-contains
`BP_SurvivalPlayerCharacter`**. The "skip values that aren't 40" rule
acts as a second guard so the mount (vanilla 30) is never touched
even if the outer-chain filter is wrong.

The patch is applied to:

- Every `Default__BP_SurvivalPlayerCharacter*_C.InventoryComponent`
  CDO. CDOs are templates -- new instances inherit the patched value.
- Every live instance the worker / inv hook walks. Necessary because
  some instances exist before the mod loads (for the active player
  pawn at session start, in particular).

## Visible side: who actually renders the grid

This is the part that surprises every Grounded 2 modder. The candidate
widgets are not equally relevant in shipping:

| Widget | Status in current shipping (`++Augusta+release-0.4.0.2-CL-2673661`) |
| ------ | ------------------------------------------------------------------ |
| `UWBP_InventoryInterface_C` | **The actual renderer**. Owns the live grid. Has its own `UGridPanel ItemGrid` field (`WBP_InventoryInterface_classes.hpp:50`) and a BP-callable `PopulateItemGrid(RowMax, ColumnMax)` method (`WBP_InventoryInterface_classes.hpp:205`). |
| `UUI_InventoryGrid_C` | Exists in `GObjects`, has `MaxRows` (+0x0388) and `MaxColumns` (+0x0390), but **the player inventory does not route through it**. CDO patch is belt-and-braces in case a future build reintroduces it. |
| `UI_Container_BackpackSide` | **Not in `GObjects`** in current shipping (loaded or not). Old Bigger Backpack pak mod patched its `MaxRows`. That is why the pak mod has zero visible effect today. |

The grid the player actually sees is always
`UWBP_InventoryInterface_C.ItemGrid`. The mod calls
`PopulateItemGrid(RowMax, ColumnMax)` via `ProcessEvent` once per live
inventory-interface instance to repopulate the grid at the desired
dimensions.

### `PopulateItemGrid` parm layout

UFunction `PopulateItemGrid(int32 RowMax, int32 ColumnMax)` --
parameters struct from `WBP_InventoryInterface_parameters.hpp`, total
0xB0 bytes (most of it post-call padding for the PE signature).

| Offset  | Type   | Field      |
| ------- | ------ | ---------- |
| `+0x00` | int32  | `RowMax`   |
| `+0x04` | int32  | `ColumnMax`|

For `slot_count = N`, call `PopulateItemGrid(ceil(N / kColumns), kColumns)`
where `kColumns = 10` (vanilla `UI_InventoryGrid` default; not
overridden by the inventory interface widget).

Examples:

| `slot_count` | Call             |
| ------------ | ---------------- |
| 60           | `(6, 10)`        |
| 100          | `(10, 10)`       |
| 500          | `(50, 10)`       |

### Hook architecture

`inv_hook.rs` installs a per-vtable `ProcessEvent` hook on
`WBP_InventoryInterface_C`. When any UFunction fires on the widget
(`Construct`, `OnVisibilityChanged`, etc.), the hook gets a chance to
re-call `PopulateItemGrid` on the same instance with the desired
dimensions. The viewport scroll feature also lives here -- it
manipulates `ItemStartIndex` so the visible 4x10 viewport scrolls
through extra slots without needing the grid to be physically that
tall.

## Settings

`<DLL_dir>/settings.json`:

```json
{ "inventory": { "slot_count": 100 } }
```

Default is 100. Vanilla is 40. The skill catalog in
[`rpg.md`](rpg.md) layers a per-skill bonus on top of this base via
the Backpack skill (`SKILL_BACKPACK`, max +460 slots at level 100).
At level 100 with default settings, target = 100 + 460 = 560.

## Verification (in-game)

Three layers, each with a different failure mode:

1. **DLL loaded.** UE4SS log shows `Starting C++ mod 'BetterBackpack'`.
   Mod log at `<DLL_dir>/better_backpack.log` shows the banner and
   `GObjects` count.
2. **Data-side patched.** `better_backpack.log` shows
   `PATCH InventoryComponent ...: 40 -> N (verify=N)` lines, at least
   one for each player BP class CDO and at least one for the live
   pawn.
3. **Visible-side rendered.** Open the inventory in-game; the grid
   shows `ceil(N / 10)` rows of 10. All slots clickable, hoverable,
   drag-target.

Common failure modes:

- 4 visible rows but `PATCH ... 40 -> 100` lines present: visible-side
  hook did not fire. Open and close the inventory once; the hook
  fires on `WBP_InventoryInterface_C` UFunction calls so the widget
  must construct first.
- `PATCH ... 40 -> 100` lines AND 4 visible rows that are clickable
  past 40 (you can pick up items into invisible slots): visible-side
  is misconfigured but data-side works. Check
  `inv hook: installed on WBP_InventoryInterface_C` in the log.
- No `PATCH` lines: no `UInventoryComponent` had `DefaultMaxSize == 40`
  at scan time. Inject inside an active save (not at the main menu)
  so `BP_SurvivalPlayerCharacter*` CDOs are loaded.

## Why we re-call `PopulateItemGrid` (not just patch a field)

The widget's grid dimensions are not stored as a single mutable field
we can write. The runtime maintains derived state across multiple
sub-widgets (`ItemGrid` slot count, slot click handlers, drag-target
extents, visual highlight overlays). The BP-callable
`PopulateItemGrid` method recomputes all of that consistently. Direct
field writes to `MaxRows`/`MaxColumns` on the inventory interface
widget produce a partially-resized grid where some slots render but
do not wire up clicks.

This is why even the working pak mods historically settled on patching
the host widget's `MaxRows` *plus* relying on `PopulateItemGrid` being
re-invoked by other UI events. The DLL approach calls
`PopulateItemGrid` directly and gets the resize without any timing
race.
