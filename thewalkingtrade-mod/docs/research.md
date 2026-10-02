# The Walking Trade research

Game: The Walking Trade 1.2.5 (updated from 1.2.4 on 2026-09-30),
Unity 6000.0.58f2, IL2CPP, Steam app 3398110. Loaded through MelonLoader
v0.7.3 and Unityforge.Shim.Melon; the mod's control plane is on port
17181. Sections below written before the update were read on 1.2.4.
What the mod does with this research is in `features.md`; proven work
is in `changelog.md`, open proof in `todo.md`.

The game's own code is in the assembly named `Runtime` (2457 types),
not `Assembly-CSharp` (400 types, all Rewired and TextMeshPro). Interop
class names carry an `Il2Cpp` prefix: `Runtime.Item.CraftStationObject`
is `Il2CppRuntime.Item.CraftStationObject`.

Live reads and writes are the tests in `tests/research_crafting.rs`:

```text
k3sc cargo-lock test -p thewalkingtrade-mod --test research_crafting -- <test> --exact --test-threads=1 --nocapture
```

Code reading used the Cpp2IL build MelonLoader downloads
(`MelonLoader/Dependencies/Il2CppAssemblyGenerator/Cpp2IL/Cpp2IL.exe`),
run with `--output-as diffable-cs` (fields and signatures) and
`--output-as isil` (method instructions). The `diffable-cs` output has no
method bodies.

## Crafting table range

Question: how near the crafting table must ingredients be, and can
that be made bigger?

### Found

The range is not a number. `CraftStationObject._itemsCollider` is an
array of Unity `BoxCollider`s; items inside the boxes count for
crafting. Each table level is its own `CraftStationObject` with its own
boxes. Read live by `craft_station_item_boxes`, all at world scale 1:

| Station object | `_level` | Box size (x, y, z) in metres | Box centre |
|---|---|---|---|
| CraftingStationLevel1 | 0 | 0.90, 2.19, 2.37 | 0.00, 0.59, -0.01 |
| CraftingStationLevel2 | 1 | 3.49, 4.00, 6.00 | 1.30, 0.00, 0.00 |
| CraftingStationLevel3 | 2 | 13.93, 6.06, 19.93 | 6.52, 1.03, 3.27 |
| CraftingStationLevel4 | 3 | 13.93, 6.06, 19.93 and 10.93, 6.55, 42.61 | 6.52, 1.03, 3.27 and -5.39, 5.89, 2.23 |
| CraftingStationPrefab | 0 | no box | |

All five station objects are active in the scene at once.

### Written

`craft_station_boxes_write` calls `BoxCollider.set_size` on every box,
setting it to `BOX_FACTOR` (now 10) times the original size in
`BOX_SIZES`. The targets are fixed, so a rerun does not compound. Read
back after the write:

```text
CraftingStationLevel4 box 0: size now "(139.30, 60.60, 199.30)"
CraftingStationLevel4 box 1: size now "(109.30, 65.50, 426.10)"
CraftingStationLevel2 box 0: size now "(34.90, 40.00, 60.00)"
CraftingStationLevel3 box 0: size now "(139.30, 60.60, 199.30)"
CraftingStationLevel1 box 0: size now "(9.00, 21.90, 23.70)"
```

### Not proven

- That crafting actually counts items in the bigger boxes. The code
  that checks items against `_itemsCollider` has not been read, and no
  in-game crafting test has been done.
- Which station object is the one the player uses. Probably one per
  upgrade level with only the current one shown; not checked.
- The write is live only. It is gone after a restart until the mod
  applies it on load.

### Found: how crafting finds its materials (1.2.5 dump, 2026-09-30)

Every material lookup of a bench goes through two static methods of
`ItemObjectProvider`, and nothing but `CraftStationObject` calls them
(its `HasCraftingRequirements`, `StartJob`, `GetAvailableCraftCount`,
`ConsumeCraftingMaterials`, `SetCrafter`):

- `GetConsumableItemsPresentFromBox(BoxCollider)` and
  `GetConsumableItemsPresentFromBoxes(BoxCollider[])`: for each box,
  `Physics.OverlapBox(collider.bounds.center, collider.bounds.extents)`,
  then `GetConsumableItems(colliders, filter)`.
- The filter keeps an item that exists, is not a secured buildable
  (`_buildable` set and `Buildable._secured` true), and has
  `Quantity > 0`.
- `GetConsumableItemsPresentInSphere(origin, radius)` (the gambler's
  lookup) has a looser filter: exists and `Quantity > 0`, so it would
  also count secured buildables such as placed shelves.

### Why resizing the bench boxes was wrong

The same `_itemsCollider` boxes do more than feed the material lookup:

- They sit on a layer the placement rule blocks on, so the 50x boxes
  blocked building everywhere (Player.log: `Placement blocked by
  ItemObjectsContainer` 25801 times).
- They make every item inside them belong to that bench. The game's
  own `ItemObject.DescribeCleanableState` on warehouse bandages:
  `craftStationZoneOwner=CraftingStationLevel2 (non-none = HARD veto,
  never cleanable)`, so cleaners never shelve anything in a bench area.
  Read live with `item_shelving_trace`.

Growing only the material lookup means leaving the boxes at their
original size and changing only the two `ItemObjectProvider` methods,
for example making each box larger for the length of the call (a
prefix that enlarges, a postfix that puts it back, with no physics step
in between), which keeps the game's own filter.

## Cleaner stuck carrying an item

Seen live 2026-09-30 (`stuck_probe`, `hire_action_state`, cleaner
Opal): outside in the car park between spiked walls, not moving for 10
s, navigator idle (`_stuckTimer 0`, path index 0, no repath or
recover), cleaning job in `ProcessItemObjectCleanableMobActionState`
with `_targetItem = KnifeWeaponItemPrefab(Clone)`, no target shelf, no
target pallet. A zombie hit started combat; after it her cleaning job
restarted and she moved on.

### Found (1.2.5 dump)

- `ProcessItemObjectCleanableMobActionState.OnEnter` picks the item up,
  subscribes to the item's `Grabbed` and `IsCleanableChanged`, and
  starts `MoveToMostAppropriatePosition()` fire-and-forget
  (`UniTaskExtensions.Forget`). The step only ends from that task.
- The task picks a destination: dedicated shelf, other shelves and
  pallets (`TrySelectShelf`, `TrySelectPallet`), else
  `GetDefaultWarehousePosition` / `GetDefaultInsidePosition`. No
  destination at all: `MarkNoPlacementAvailable`, step ends.
- With a destination it subscribes to the navigator's
  `DestinationReached` and awaits `BaseNavigator.SetDestination(dest,
  useSamplePosition: false)` (`UniTask<bool>`); the failure path marks
  `MarkAgentUnreachable` / `MarkCleanUnreachable` and ends the step.
- The navigator's own stuck recovery (`RigidbodyNavigator`, live:
  window 0.5 s, min progress 0.1, repath 1.5 s, recover 3 s, give up 6
  s, snap radius 1.5 m) only runs while it is trying to move. An idle
  navigator is never "stuck", so nothing ends the wait.

### Second capture: Caroline (2026-09-30)

`hire_action_state` and `stuck_probe` with `TWT_HIRE=caroline`:

```text
ProcessItemObjectCleanableMobActionState: _targetItem WornClothItemPrefab(Clone), _retryCount 1,
    _targetShelf null, _targetPallet null
nav: calculating true moving false unreachable false reached false
     destination (-103.44, 2.33, -60.21) path corners -1
t=0..9: pos (-90.41, -0.02, -41.57) stuckTimer 0.0 pathIndex 0
```

`nav_manager_state` at the same time:

```text
GetDebugInfo = "Processing: False, QueueOwners: 0, Active: 0"
_maxPathsPerFrame = 2, _requestTimeout = 5.0
```

So the navigator still says it is calculating a path, but the path
queue holds no request for it: the request was removed and her
`SetDestination` never returned a path. (`_dropPosition` read as
`(1.18, -60.21, 0.00)` is the shim misreading a `Nullable<Vector3>`
field; the navigator's `DestinationPosition` is the real target.)

### Found: how a path request can be dropped (1.2.5 dump)

- `RigidbodyNavigator.get_IsCalculatingPath` is a plain flag at `0x1D8`.
- `RigidbodyNavigator.TryCalculateAndApplyPathAsync` awaits
  `NavigationManager.CalculatePathAsync(start, end, owner)`, then
  `IsPathValid` and `ApplyPath`.
- `NavigationManager` queues requests (`PathRequest`: start, end,
  filter, `UniTaskCompletionSource<NavMeshPath>`, owner, creation
  time), keyed by owner in `_activePathRequests`, and works through
  `_maxPathsPerFrame` (2) per frame.
- `CalculatePathAsync`: if the owner already has an active request,
  **the old request's `TrySetCanceled()` is called** and the new one
  replaces it.
- `CancelPathRequest(owner)`: `TrySetCanceled()` and remove.
- `CleanupTimedOutRequests`: after `_requestTimeout` (5 s),
  `TrySetException(new TimeoutException())` and remove.
- `GetDebugInfo()` returns "Processing, QueueOwners, Active";
  `_enableDebugLogs` turns on the manager's own logging.

### Likely cause, not proven

A second path request from the same navigator (Caroline had
`_retryCount 1`) cancels the first. The cancellation travels back up as
an `OperationCanceledException` through `TryCalculateAndApplyPathAsync`
and `SetDestination` into the item step's `MoveToMostAppropriatePosition`,
which was started with `.Forget()`. A forgotten task that throws just
ends: the step never reaches `OnCompleted`, and the navigator's
calculating flag is never cleared, so its stuck recovery (which needs
it to be trying to move) never runs.

Player.log has no `TimeoutException` or `OperationCanceledException`.
UniTask by default does not report cancelled forgotten tasks; that is
from UniTask's documentation, not checked in this game.

Still to see: which second request replaced hers (the step's own
re-plan, the navigator's repath, or another system), and whether the
navigator's path code catches the cancellation (its call list was
read, not its exception handling). Next step: switch on
`NavigationManager._enableDebugLogs` and read Player.log at the next
stuck hire.

### Third capture: Opal, with our cleaner changes off (2026-09-30)

`nav_snap`, `craft_bench` and `cleaner_level` not installed, so the
game's own code only. Opal stood still outside by the car park
(`-91.12, -0.02, -43.09`), holding a beer.

```text
stuck_probe:
nav 140: calculating true moving false unreachable false reached false destination "(0.00, 0.12, 0.00)" path corners -1
t=0..9: pos unchanged, stuckTimer 0.0, pathFailures 0
hire_action_state:
ProcessItemObjectCleanableMobActionState
    _targetItem = "BeerItemPrefab(Clone)"
    _retryCount = 1
    _targetShelf = null
    _lastChosenTransform = null
    _shouldPlaceOnShelf = true
    _failedTargets count = 0
```

Cause (found later the same evening): **the mod's own diagnosis hook**,
not the game. The cleaner trace had a postfix on the item step's
`TrySelectShelf(candidates, out shelf, out front, out position)` from
18:43 (hot reload generation 2). After it, the item step sent cleaners
to `(0.00, y, 0.00)`: the chosen shelf and front were right, but the
`out Vector3 position` the game copies into the trip destination
(`TrySelectShelf` steps 136-137, `MoveToMostAppropriatePosition` steps
1913-1920) came back zero. Trace line:

```text
set destination: mob_name_opal to "(0.00, -0.02, 0.00)" ...; NEAR ORIGIN, item step: item "BeerItemPrefab(Clone)", item zone 1,
  place on shelf true, shelf "FlimsyWoodenShelfItemPrefab(Clone)", front "Front" at "(-91.49, 0.49, -61.57)", retries 0
```

Removing the postfix by hot reload did not stop it; a game restart
without it did: 116 cleaner trips, 0 near the origin
(`set dest 116  near origin 0`). Likely reading (not checked in the
HarmonyX / Il2CppInterop source): patching an IL2CPP method wraps it,
the wrapper does not write an `out` struct back to the caller, and
unpatching leaves the wrapper until restart.

Rule taken from this: never patch an IL2CPP method that has `out` or
`ref` struct parameters; read its results from the caller or from the
fields it sets instead. After removing any patch, restart the game
before trusting what follows.

The 25 shelves found at the world origin are the game's switched-off
furniture templates (`origin_shelves`: `active false`, 0 of 25 in
`StageModel.Shelves`); cleaners never consider them. They had nothing
to do with this.

### Tested since (2026-09-30)

- Replacement, `path_replace_test` on idle Jeremy: two `SetDestination`
  calls, first one after the other, then from two threads at once. Both
  times the navigator cleared "calculating" and walked; whether the two
  requests overlapped in one frame was not shown. The replacement cause
  is not supported.
- Caroline's destination on another hire (`TWT_DEST`): Jeremy accepted
  `(-103.44, 2.33, -60.21)` and did not move for 5 s, not calculating.
  No hire can walk to that point.
- Default drop spots, `cleaner_default_drop`:
  `GetDefaultWarehousePosition` = `(-101.61, 0.00, -65.00)` (warehouse
  floor), `GetDefaultInsidePosition` = `(-100.26, 1.14, -57.14)` (centre
  of the `ShopFloorArea` box). Neither is Caroline's destination.
- At Caroline's destination: 0.5 m under `SF_Ceiling_Mesh`, inside
  `Room1`/`ShopFloorArea`, above a collider named `Top` (centre y 0.81).
  No shelf there.

So the unreachable point came from somewhere else in the item step.

### Found: re-plan and destination sources (1.2.5 dump)

- `TryReplanAfterFailedTarget(failed)`: adds the target to
  `_failedTargets`, unsubscribes `DestinationReached`, and starts a new
  `MoveToMostAppropriatePosition().Forget()`. The previous run is not
  stopped, so two planning tasks can be alive for one cleaner.
  `TryRegrabAndReplan` picks the item up again and calls it.
- `TrySelectPallet`: the pallet's `GetInsideEdgeTransform().position`.
  Live (`pallet_edges`): the two pallets are in the warehouse near
  `(-98, 0, -75)`, 15 m from Caroline's point, so not her destination.
- `TrySelectShelf`: a point from the shelf's `_FrontTransforms`, where
  the cleaner stands to stock it.

### Found: wall shelves send cleaners to a point in the air

`shelf_fronts_near` at Caroline's corner: flimsy wooden shelves mounted
on the wall three high, each with its front point at its own height.

```text
FlimsyWoodenShelf at (-104.87, 0.65, -58.46)  front (-104.46, 0.57, -58.46)
FlimsyWoodenShelf at (-104.87, 1.46, -58.47)  front (-104.46, 1.37, -58.47)
FlimsyWoodenShelf at (-104.87, 2.24, -58.48)  front (-104.46, 2.15, -58.48)
(the same three again at z -56.95)
```

The item step calls `SetDestination(front, useSamplePosition: false)`,
so the point is not moved down to the floor. `path_replace_test` with
`TWT_DEST` on idle Jeremy:

```text
top front    (-104.46, 2.15, -58.48): accepted, no new path, he kept walking away
             x -115.5 -> -119.6 -> -124.6 -> -130.9
bottom front (-104.46, 0.57, -58.46): accepted, new path, he walked toward it
             x -135.1 -> -132.7 -> -127.3 -> -121.2
```

### Cause (proven for high wall shelves)

A cleaner stocking a wall shelf mounted high up is sent to that shelf's
front point in the air. No path can be made to it, the navigator does
not count as stuck (it is not trying to move), so its recovery never
runs and the item step waits forever: the cleaner stands at the wall
holding the item.

### Not proven

- Caroline's exact point `(-103.44, 2.33, -60.21)` is not one shelf
  front (nearest is the 2.15 m one, about 2 m away); Opal's knife case
  was outside by the trap walls. Both may be the same bug with another
  high point; not matched.
- That stocking uses the shelf's own slots, not the front point, so a
  front point on the floor would still let the cleaner stock the shelf.

### Wrong fix: `nav_snap`

`nav_snap` was built on the reading that `useSamplePosition: true` moves
the destination onto the navmesh. It does not: it moves the cleaner's
own start point (see "Cleaners juggling items", `nav_snap` section). So
it does not fix this hang, and it is the change that reaches the item
trip behind the juggling.

### Tests

`shelf_fronts_near`: shelves within 4 m of `TWT_DEST` with their front
points, host, zone, `IsBlockedByObstacle`, `IsBlockedByWall`,
`IsAgentUnreachable`. `item_shelf_candidates` (`TWT_ITEM`, taken from a
cleaner carrying one): every shelf that accepts it with room and its
standing spot. `cleaner_search_log_window` (`TWT_HIRE`, `TWT_SECS`): the
search step's own log for a window. `staff_navigators` (`TWT_NAV`, or
`stuck`): navigator settings and stuck state for any walker.
`nav_manager_state`, `nav_debug_logs_write`, `floor_under_point`:
the path queue, its debug flag, and a downward raycast (results come
back as type names only). `pallet_edges`: pallets and positions.
`cleaner_default_drop`: both default drop spots, plus `TWT_DEST`, with
the colliders around each. `path_replace_test`: two overlapping
`SetDestination` calls on one hire, or one to `TWT_DEST`.
`stuck_probe` (by `TWT_HIRE` or `TWT_POS`): navigator
`IsCalculatingPath`, `IsMoving`, `IsDestinationUnreachable`,
`HasReachedDestination`, `DestinationPosition`, path corners, then 10 s
of stuck timer and position, and colliders within 1 m.
`hire_action_state` (by `TWT_HIRE`): each cleaning step, its target and
the item step's drop position and chosen spot. `nav_manager_state`: the
path queue.

## Cleaners juggling items (2026-09-30)

Seen in play after the crafting reach fix and `nav_snap`: cleaners keep
picking items up and dropping them, all the time.

### Found: the mechanism (1.2.5 dump and live)

- `cleaner_search_state` counters, morning vs after the changes:
  `_dbgNoPlacement` 3 -> about 470, `_dbgFloorNoDest` 387 -> 0,
  `_dbgNotCleanable` 376 -> about 460, `_dbgGenericNoSpace` 73 -> 86.
- What those counters are (`FindMisplacedItem`, steps 229-231 and
  304-316): all six are zeroed at the start of every search pass, then
  each item looked at adds one to the first that fits: not cleanable
  (`_dbgNotCleanable`), `IsCleanUnreachable` (`_dbgUnreachable`),
  `IsNoPlacementAvailable` (`_dbgNoPlacement`). So `_dbgNoPlacement` is
  how many items carry the "no placement" flag right now, not a count
  of drops. The flag is `ItemObject._noPlacementAvailableUntil`
  (`0x150`, a game time, raised by `MarkNoPlacementAvailable(seconds)`),
  and every flagged item is in the static set
  `ItemObject.NoPlacementItems`. 470 means many items were dropped
  within the flag's duration (constant at `0x183648E44`, not read); it
  does not give a drop rate.
- `IsNoPlacementAvailable` is set only by the item step: at the end of
  `MoveToMostAppropriatePosition`, when no shelf and no pallet was
  selected and the item is from Inside or the Warehouse (not Outside,
  not taken off a foreign shelf), the cleaner drops it where they stand,
  calls `MarkNoPlacementAvailable(duration)` (constant at
  `0x183648E44`) and ends the step. Outside items go to a default spot
  instead.
- So an item is juggled when the search thinks it has somewhere to go
  and the item step then finds nowhere.
- Stocking itself does not depend on where the cleaner stands:
  `ShelfObject.TryPlaceShelvable` picks free grid tiles
  (`IsPlacementValid`, ignore transform = the item).
- `TrySelectShelf` skips shelves in `_failedTargets` and needs
  `ShelfObject.GetInsideFrontTransform` to return a spot: filters zone
  Inside or Warehouse, `IsBlockedByObstacle`, one more unnamed check
  (`0x1824C78F0`), same zone as the shelf, nearest wins. Live
  (`shelf_fronts_near`): every wall-shelf spot near the stuck corner is
  zone 0, not blocked, not unreachable.

### Found: what Caroline juggles

`cleaner_search_log_window` (the search step's own `_debugLogging` for
60 s), Player.log:

```text
29  tiers → dedicated=- consolidate=- inference=WornClothItemPrefab
20  tiers → dedicated=- consolidate=- inference=GunpowderItemPrefab
15  tiers → dedicated=- consolidate=- inference=BandageItemPrefab
14  tiers → dedicated=- consolidate=- inference=BeerItemPrefab
 1  tiers → dedicated=GunpowderItemPrefab
(plus 1-2 each of rope, arrow, wine, tins, sleeping bag, scrap)
```

About one search a second, almost always the "inference" candidate:
the dedicated shelves for these items have no room, and the search
believes an accepting shelf or a pallet does (`HasAcceptingShelfWithSpace`
or `AnyPalletHasSpaceForExact`). The item step then finds no place.

### Ruled out (live and dump, 2026-09-30)

- Stocking from where the cleaner stands: `TryPlaceShelvable` has no
  reach or sight check.
- Wall-shelf standing spots: all zone 0, not blocked, not unreachable
  (`shelf_fronts_near`).
- `_failedTargets`: 0 on all three cleaners (`hire_action_state`).
- Pallets: the search (`AnyPalletHasSpaceForExact`) and the item step
  (`StageModel.GetPalletsWithSpaceFor`) both use
  `PalletObject.HasSpaceFor` and the same zone check; the item step
  only adds `_failedTargets` and null checks.
- Missing standing spots: `item_shelf_candidates` for a carried
  gunpowder: about 55 shelves accept it and have room, and every one
  gets a spot from `GetInsideFrontTransform(<carried position>)`
  (`Front`, `FrontL`, `FrontR`, `Edge`). With a null start position the
  method throws `NullReferenceException`.

### Found along the way

- The item step's shelf loop (`MoveToMostAppropriatePosition`, lines
  ~885-1060): config, `AcceptsItem`, `CanFitItem`, own item, not in
  `_failedTargets`, then sorts by zone (Inside / Warehouse) and by
  whether `GetPrimaryItem` matches; zones match the search.
- The gunpowder Andrew and Opal carried came from zone 1, Outside.
  Outside items are never flagged "no placement"; they go to a default
  spot, so that carry may be normal work.
- Among the shelves that "accept with room" are objects named without
  `(Clone)`: `FlimsyWoodenShelfItemPrefab`, `SecureTableItemPrefab`,
  `HighValueCabinetItemPrefab`, `CoffeeTableItemPrefab`,
  `StudyDeskItemPrefab`, `ElegantTableItemPrefab`,
  `SpecialItemShelfItemPrefab`. They look like shop-catalog or template
  objects, not placed shelves. Whether the search counts them, and
  whether the item step can use them, is not checked.
- A class search over every `ItemObject` now fails in the shim:
  `mono_walk_class: buffer too small (cap=65536)`.

### Found: `nav_snap` is the change that reaches the item trip (1.2.5 dump)

Of the three mod changes that touch cleaners, only `nav_snap` is on the
item step's path:

- `cleaner_level` only turns on `FloorWorkerWorkPolicy.CanDisposeCorpses`
  (`GetCurrentPolicy`). `SearchForCleanableMobActionState.SearchForObject`
  reads it (policy byte `[this+89]`, step 029) only to look for bodies
  first; the item search (`FindMisplacedItem`, step 135) and the item
  step are unchanged.
- `craft_bench` runs only inside
  `ItemObjectProvider.GetConsumableItemsPresentFromBox` / `...FromBoxes`
  and puts the box back before the call returns. No cleaner method calls
  them.
- `nav_snap` changes the item step's own `SetDestination` call.

What `useSamplePosition: true` does
(`RigidbodyNavigator.<TryCalculateAndApplyPathAsync>d__150`, steps
083-126): it takes the **cleaner's own position**
(`Component.get_transform`, `Transform.get_position`), moves it to
`NavMesh.SamplePosition` within `_offMeshRecoveryRadius` (`0x114`, which
`nav_snap` raised to 3 m on hires), and uses that as the path start. The
destination (`[state+44]`) goes to `NavigationManager.CalculatePathAsync`
unchanged. So `nav_snap` never moved a high shelf's front point down to
the floor; it moves the start of every item trip to the nearest walkable
point up to 3 m away.

How a failed trip ends in a drop
(`ProcessItemObjectCleanableMobActionState.<MoveToMostAppropriatePosition>d__21`):

- Step 2096 reads the `SetDestination` result. On false: step 2141
  `WorldTransformZoneProvider.MarkAgentUnreachable(seconds)` on the chosen
  front (constant at `0x183648C2C`), step 2149 counts one retry, and under
  10 retries it goes back to choosing a shelf.
- The front marked unreachable is then not offered (the unnamed filter in
  `GetInsideFrontTransform` is the likely reader of `IsAgentUnreachable`;
  not read). No other shelf is chosen, so step 1662 or 1840
  `MarkNoPlacementAvailable` and `OnCompleted`: the item is dropped.
- The search's `HasAcceptingShelfWithSpace` does not check reach, so it
  picks the item again: juggling.
- The mark is timed and on the front itself, which fits
  `shelf_fronts_near` reading "not unreachable" at one moment and
  `_failedTargets` staying 0 (a different list).

### Measured: no item trip failed in 62 s (2026-09-30)

`cleaner_unreachable_window` (`TWT_SECS=60`, game running):

```text
118 fronts, 13 cleaner searches, game time 1077.0653836522108; watching 60 s
game time 1077.0653836522108 -> 1139.6091973497732: 0 front(s) newly marked unreachable
cleaner search 14809: _dbgNoPlacement 353 -> 179
cleaner search 14810: _dbgNoPlacement 354 -> 225
```

No front or pallet edge was marked unreachable, so the `nav_snap` path
to a drop did not happen in that window. The flagged-item counts fell,
so fewer items were being dropped than flags were running out. Whether
cleaners were juggling during the window was not recorded.

### Measured: juggling still happens with our cleaner changes off (2026-09-30)

Game restarted with `nav_snap`, `craft_bench` and `cleaner_level` not
installed (`lib.rs`). The operator saw cleaners working again, and
still juggling. The upgrades repeated by `skill_repeat` were checked
(`thewalkingtrade.json`: death reputation x6, hire limit x2, hire
combat power x1); none touches shelves or items. Nothing else the mod
installs touches cleaners.

### Measured: the cleaner trace (`cleaner_trace.rs`, 2026-09-30)

Three lines per item in Player.log: the game's own reason line
(`[SearchForCleanable:Actions] tiers -> dedicated=... consolidate=...
inference=...`, from `FindMisplacedItem` with `_debugLogging` on; it
does not name the cleaner), then `pick:` (cleaner, item, instance id),
`select shelf:` per `TrySelectShelf` call (list size, result), and
`end:` (cleaner, item, shelf, pallet, retries, dropped).

One run, new copy loaded by hot reload:

```text
gen1 picks 288 ends 266 dropped 249
--- which tier held the dropped item at pick:
272 inference
1 dedicated
```

```text
select shelf: "mob_name_evan" from 0 candidate(s) -> false, shelf "-"   (x7)
end: "mob_name_evan" item "CopperPipeItemPrefab(Clone)" #-1212258 from zone 3: shelf "-", pallet "-", retries 0, dropped with no place true
```

- Almost every drop is an item the search picked as "inference" (no
  dedicated shelf with room; it believes an accepting shelf or a pallet
  has room).
- The item step then hands `TrySelectShelf` empty lists (0 shelves on
  every call) and drops the item without walking anywhere. So its own
  shelf loop (`MoveToMostAppropriatePosition`, steps 899-1059) throws
  out every shelf; the standing spot lookup is never reached.
- `item_shelf_candidates` on a flagged item (from `StageManager.Model
  .Items`): many shelves accept it, fit it, and every front passes all
  four standing spot filters (zone, not blocked, not unreachable, same
  zone as the shelf).
- The game's shelf set `StageModel.Shelves` (what both the search and
  the item step go through) held 45 shelves; a scene search found 93
  `ShelfObject`s, among them the special item units' shelves
  (`SpecialItemShelfItemPrefab`, `TopShelf1`, `Base2`, `MiddleShelf1`,
  ...). Which of the 93 are in the 45 is not checked.

The `select shelf:` lines came from a postfix on `TrySelectShelf`
(generations 2-6) that broke the item step's trip destinations (see
"Third capture: Opal"); the list sizes it read are inputs and are
believed right, but that hook is gone for good. The 249-of-266 drop
count above was measured before it (generation 1).

After a clean game restart without it (19:07): 1 drop in 65 item steps
over about 90 s of play. Too short to say whether the juggling is gone
or comes and goes.

### Found: both steps use the same shelf tests (1.2.5 dump)

- Search, `HasAcceptingShelfWithSpace`: every shelf in
  `StageModel.Shelves` passing `IsUsableShelf` (alive, enabled, has a
  stocking setup, has its own item, that item's zone Inside or
  Warehouse), `AcceptsItem(item data)` and `CanFitItem`. Cached per item
  data (`[info+18]` computed, `[info+19]` result).
- Item step shelf loop: same set, `AcceptsItem(item data)`,
  `CanFitItem(_shelvableComponent)` (the target item's own
  `ShelvableObject`, filled at step 197), shelf has its own item, not in
  `_failedTargets`, zone Inside or Warehouse. It then tries every list
  it built, one after another, with no conditions.
- `GetInsideFrontTransform(startPosition)`: fronts with zone Inside or
  Warehouse, not `IsBlockedByObstacle`, not the unnamed check (likely
  `IsAgentUnreachable`), zone equal to the shelf's own item's zone; the
  start position only sorts by distance.

### Not proven

- Which of the item step's shelf tests empties its lists for a dropped
  item. `cleaner_trace` now counts, at each drop, how many shelves pass
  each test in order; no drop has been counted yet.
- Whether the search's cached answer is stale (it is kept per item
  data), which would explain the search seeing room the item step does
  not.
- Whether the special item units' shelves are in `StageModel.Shelves`.
- That `nav_snap` causes the juggling: it does not (juggling continues
  with it off).
- That the unnamed filter in `GetInsideFrontTransform` is the
  `IsAgentUnreachable` check.

## Staff working hours

Question: what hours do hired staff work, and can they work 24/7?

### Found: staff have no clock hours

Nothing on a staff member stores a start or end hour. Read live by
`staff_hours` and `staff_member`: `StaffMobObject` holds
`_dayLastAssignedJob`, `_LastAssignedJobSnapshot`, `_isHired`, and
`StaffRuntimeData` (wage, per-role levels and XP, morale boost). No
hours.

A job lasts until the day ends, and a day only ends when the player
sleeps.

**The clock** (`Runtime.Day.TimeManager`, fields from the
`diffable-cs` dump, logic from `isil`):

- `UpdateInGameTime` advances minutes and hours from `_elapsedTime`
  and fires `MinutePassed` and `HourPassed`. When the day's time runs
  out it sets `_isPaused` (offset 0x79). It does not roll the day over.
- `Sleep(wakeHour, wakeMinute)` adds 1 to `CurrentDay` (offset 0x50),
  sets the hour and minute to the wake time, fires the day events and
  clears `_isPaused`.
- `FreezeTimeWhenStoreClosed` and `OnStoreOpenChanged` exist: time can
  stop while the store is closed. `RaidFreezeHour = 19` is a constant.

**Each new day** (`StaffManager.OnDayPassed`), for every hired staff
member the game calls, in order:

```text
StaffMobObject.CancelJob
GameObject.SetActive
StaffMobObject.StartNewDay
StaffMobObject.ClearGoals
new AwaitJobAssignmentMobGoal -> StaffMobObject.AddNewGoal
```

So every job is cancelled at the start of each day, and each hire
waits until the player assigns a job again. The game has a "repeat
last assignment" interaction for this (`_repeatJobInteractionData`,
term `gameplay_interaction_repeat_last_assignment`, input
`AlternativeInteract`). A reassign can fail for lack of money
(`gameplay_insufficient_funds_warning`).

**Each hour:**

- `StaffManager.OnHourPassed` clears expired morale boosts
  (`StaffRuntimeData.CheckAndClearExpiredMoraleBoost`), then may send
  a new job-seeker: a roll against
  `ReputationManager.GetNormalizedReputation` and `Random.value`, only
  while `_approachesToday` is below `MaxApproachesPerDay`. It adds 1 to
  `_approachesToday`.
- `SecurityMobGoalState.OnHourPassed` only calls
  `StaffMobObject.AwardJobXP`.

### What 24/7 would take

Staff already work around the clock within a day. What stops them is
the job being cancelled at each new day. Two ways to change that, not
built or tested:

- After `StaffManager.OnDayPassed`, re-assign each hire's
  `_LastAssignedJobSnapshot`, the same thing "repeat last assignment"
  does.
- Stop `OnDayPassed` from calling `CancelJob` for hired staff.

### Not proven

- Whether the wage is charged on each assignment or per day, and so
  what an automatic daily reassign would cost.
- What the two `OnDayPassed` filters (`<OnDayPassed>b__67_0` and
  `b__67_1`) select. The first feeds `HashSet.RemoveWhere`, the second
  `List.RemoveAll`.
- What `FleeForDay` does and when it runs.
- Whether staff behave differently while the store is closed. Nothing
  found in the staff code, but the store's own code was not read.

## Repeatable skill upgrades

Question: can a bought skill upgrade be bought again, Factorio style,
each time stacking its effect?

Read from the game 1.2.5 Cpp2IL dump (the game updated from 1.2.4 on
2026-09-30; everything below was re-read on 1.2.5).

### Found: how an upgrade is bought

- `SkillViewController.OnUnlockButtonClicked` (the tree window's unlock
  button) calls `Skill.TryUnlockNode(selected)`, then
  `UpdateUnspentPoints`, `SkillTreeView.UnlockNode` and
  `SkillTreeView.Refresh`.
- `Skill.TryUnlockNode(node)`: if `UnspentPoints > 0`, the node is not
  null and `node.CanUnlock()`, it calls `node.Unlock()`, takes 1 from
  `UnspentPoints` and raises `OnUnspentPointsChanged`.
- `SkillNode.CanUnlock()`: false if `IsUnlocked`; true if `IsStarter`;
  else true when any neighbour is unlocked. `SkillTreeView.Refresh`
  also asks `CanUnlock` for how each node is drawn.
- `SkillNode.Unlock()`: if not `IsUnlocked`, sets it and raises the
  node's `Unlocked` event. `SkillNode.Reset()` clears `IsUnlocked`.

### Found: how a multiplier upgrade takes effect

A `...MultiplierSkillNode` is a `ScriptableObject` that is itself the
modifier (`IMultiplicativeModifier`, `IModifierProvider`), holding
`Value`. `CraftingSpeedMultiplierSkillNode.Unlock()` runs the base
`Unlock`, then adds itself to the static
`CraftingPlayerState.CraftingSpeedMultiplier`; its `Reset()` removes
itself again.

`ModifiableFloat` keeps `List<IMultiplicativeModifier>`.
`Add(IMultiplicativeModifier)` returns false and adds nothing when the
list already `Contains` the modifier, so the same upgrade cannot count
twice. `ComputeValue` is `(base + additives) * product of multipliers`.

`Skill.Load(level, experience, unspentPoints, nodeData)` first calls
`Skill.OnDisable`, then unlocks each saved node by Guid. The save only
holds unlocked or not per node; there is no repeat count.

### Read live

`multiplier_skill_nodes` lists every multiplier upgrade with
`_IsUnlocked_k__BackingField` and `_Value_k__BackingField` (the interop
field names). Crafting speed on the test save: four nodes of `0.75`,
one unlocked.

`crafting_speed_total` reads the total through
`CraftingPlayerState.get_CraftingSpeedMultiplier`:

```text
CraftingSpeedMultiplier value 0.75 base 1.0
  multiplier 0: IMultiplicativeModifier value 0.75
```

`crafting_speed_repeat_write` (changes game state until restart, not
the save) copies the owned node and adds the copy:

```text
before: 0.75
Instantiate = {"handle":175242,"il2cpp_type":"UnityEngine.Object",...}
AddModifier = true
after: 0.5625
```

- `UnityEngine.Object.Instantiate(node)` through the shim makes a
  separate copy. The copy's handle is typed `UnityEngine.Object`, so
  its own methods (`get_Value`) are not found on it.
- `ModifiableFloat.Add(copy)` fails: the shim picks the
  `IAdditiveModifier` overload. `AddModifier(IModifierProvider)` has
  one overload and works.

### Plan, not built

- Prefix `SkillNode.CanUnlock`: true for an owned multiplier upgrade,
  so the unlock button sells it again for a point.
- On a repeat, `Instantiate` the node and run that node type's own
  `Unlock` on the copy, so each upgrade adds the copy to its own total.
- Keep repeat counts in `thewalkingtrade.json` and add the copies back
  after `Skill.Load`.

### Not proven

- Whether the unlock button shows for an owned node when `CanUnlock`
  returns true.
- How to call the node type's `Unlock` on a copy whose handle is typed
  `UnityEngine.Object`.
- Whether `Skill.OnDisable` (run by `Load`) removes copies the mod
  added. If not, copies from one save stay active after loading another.
- Upgrades other than crafting speed: only its `Unlock` and `Reset`
  were read.

## Cleaner shelving

Question: cleaners do not stock shelves and look idle. How does the
cleaner decide what to pick up and where it goes?

Read from the game 1.2.5 Cpp2IL dump on 2026-09-30, plus live reads.

### Found: the loop

A cleaner (floor worker job) runs `FloorWorkerMobGoalState`, which
cycles three steps: `SearchForCleanableMobActionState` (pick a target),
`MoveToCleanableMobActionState` (walk to it),
`ProcessItemObjectCleanableMobActionState` or
`ProcessRagdollCleanableMobActionState` (deal with it).

`SearchForCleanableMobActionState.Tick` calls `SearchForObject` every
`_searchInterval` (1.0 s):

- If the work policy allows bodies (`CanDisposeCorpses`), the nearest
  body wins: `LeaveQueue`, step done.
- Otherwise `FindMisplacedItem`. An item found: `LeaveQueue`, step
  done. **Nothing found: `JoinQueue`**, which is
  `StaffQueueManager.Join`, and the cleaner walks to its place in the
  staff queue (`UpdateQueuePosition`). This is the "idle" look.

### Found: which item `FindMisplacedItem` picks

It first calls `ShelfObject.RefreshForeignBlockers` on every shelf, then
walks every item and takes the first matching row:

| Item | Result |
|---|---|
| `IsCleanable` false | skip, `_dbgNotCleanable` + 1 |
| `IsCleanUnreachable` | skip, `_dbgUnreachable` + 1 |
| `IsNoPlacementAvailable` | skip, `_dbgNoPlacement` + 1 |
| zone Outside | candidate: "dedicated" if a dedicated shelf has space, else "inference" |
| zone Inside or Warehouse, on a shelf assigned to it (`IsItemAssigned`) | skip, `_dbgHome` + 1 |
| zone Inside or Warehouse, on a dedicated shelf for other items | candidate, "dedicated" |
| zone Inside or Warehouse, on a non-dedicated shelf | candidate "consolidate" only if a dedicated shelf has space, else skip, `_dbgGenericNoSpace` + 1 |
| zone Inside or Warehouse, loose | candidate "dedicated" if a dedicated shelf has space, else "inference" if an accepting shelf or a pallet has space; else skip, `_dbgFloorNoDest` + 1 |
| any other zone (OutOfBounds, Rooftop, Bedroom, ...) | skip, not counted |

The three candidate names are the game's own, from its debug log line.
The nearest item under "dedicated" wins, then "consolidate", then
"inference". `WorldZone`: Inside 0,
Outside 1, OutOfBounds 2, Warehouse 3, RemoveFromExistence 4,
Rooftop 5, Bedroom 6. With `_debugLogging` on, the search writes
`[SearchForCleanable:<name>] tiers → dedicated=... consolidate=...
inference=...` and the counters to Player.log.

### Found: which shelf takes an item

- `HasDedicatedShelfWithSpace`: `StageModel.GetDedicatedShelvesFor(item)`,
  then the first `IsUsableShelf` with `CanFitItem`.
- `HasAcceptingShelfWithSpace`: every shelf that `IsUsableShelf`, whose
  `ShelfStockingConfiguration.AcceptsItem(item)`, and that `CanFitItem`.
- `IsUsableShelf`: exists, enabled, `[shelf+0xC0]` set, and its own
  item is in zone Inside or Warehouse.
- `ShelfStockingConfiguration.AcceptsItem(item)`: if the player
  assigned items or types (a dedicated shelf), only those; else yes if
  the item is already on it; else if an item was inferred from the
  contents, only that item; else if a type was inferred, only that type;
  else (empty, nothing inferred) yes.

So an item already on a non-dedicated shelf (for example stock kept on
storage shelves) is only moved when a shelf dedicated to it has room.
Inference-matching and empty shelves are only used for loose items.

### Read live

`cleaner_search_state`, three cleaners with organise and dispose on:

```text
caroline: _isInQueue true,  _dbgNotCleanable 376, _dbgUnreachable 3, _dbgNoPlacement 3, _dbgHome 0, _dbgGenericNoSpace 73, _dbgFloorNoDest 387
andrew:   _isInQueue true,  same counts
opal:     _isInQueue false, 375, 3, 2, 0, 63, 357
```

Their last searches found no item: of about 840 items, 376 not
cleanable, about 387 loose with nowhere to go, about 73 on non-dedicated
shelves with no dedicated shelf that has room.

`shelf_survey` (84 `ShelfObject`s): about 30 placed shelves in zone
Inside, most of them dedicated (player-assigned) to one item or type;
one shelf (`SecureTableItemPrefab(Clone)`) in the Warehouse; the rest are
store furniture shelves (`Base1`, `TopShelf1`, `MiddleShelf2`, ...) and
prefabs with nothing on them and nothing inferred.

### Not proven

- Why the 387 loose items find no shelf. Empty, non-dedicated store
  shelves accept anything by `AcceptsItem`, so they must fail
  `IsUsableShelf` or `CanFitItem`, or be something other than live
  shelves (for example unplaced furniture). Not checked item by item.
- What `[shelf+0xC0]` is (the `IsUsableShelf` gate).
- Why a cleaner can stand still forever while carrying an item (below).
- The order "dedicated", then "consolidate", then "inference" is taken
  from the log line and the two null checks at the end of
  `FindMisplacedItem`; those last lines were not read one by one.
- What makes an item not `IsCleanable` (376 of them).
- Whether dedicated shelves are full (`CanFitItem` per shelf was not
  read).
