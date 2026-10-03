# The tenement

> **Authoritative on:** the player's tenement building (TenementController,
> TenementEventController, residents, contractors, tenement events) and
> what of it is per area.
>
> Index of every game system's doc: [`research.md`](research.md).

## TenementController

Singleton. Manages the player's tenement building. Contains
`TenementGeneral` (building-wide state), list of
`TenementApartment` (individual units), upgrade progress tracking.
Uses `TenementContractor` for renovations, `TenementResident`
for tenants. Upgrade types cover electricity, water, bathroom,
heating, wall type, balcony, kitchen (all in `UpgradeType` enums).
`TenementResourceStorage` tracks building materials.

## What is per area (2026-10-03, from the code)

TenementController and TenementEventController are game-wide managers in
Game_Logic ([`areas.md`](areas.md)) and sign up to the clock in Start
(TenementController.cs:230-234, TenementEventController.cs:71-74), the
same with kept areas.

- The contractor in use (`currentSceneContractor`) is the one whose menu
  the player last opened (TenementContractor.ShowMenu, :58;
  TenementController.cs:454-459); nothing per area.
- `currentSceneResidents` (resident to its NPC object): NPCInfo adds its
  object when it is a resident not spawned in an apartment (ResidentCheck,
  NPCInfo.cs:374-380, called from 173, 283, 367) and removes it only in
  OnDestroy (318-324). In the game leaving an area destroys its NPCs, so
  it holds the current area's residents only. With kept areas the left
  area's NPC objects are switched off, not destroyed, and stay in it.
  Used by renting a resident (RentFade, TenementController.cs:804-815),
  which hides the resident's object found there; the loop over its count
  in TenementEventController.DeltaSeconds (101-103) is empty.
- Tenement scene events: each `TenementSceneEvents` adds itself to the
  manager's list in Start (TenementSceneEvents.cs:23-26), never removed.
  A tenement event looks up the first entry for its NPC (no area check)
  and runs it: its relay's outputs, and one of its spawners' `TrySpawn`
  (TenementEventController.cs:159-168, TenementSceneEvents.cs:28-56). In
  the game every visit adds a new entry and the old ones are destroyed
  objects. With kept areas there is one entry per object, live but
  switched off when its area is left: the relay does nothing then
  (Relay.cs:106) but `TrySpawn` has no switched-off check
  (Spawner.cs:206-), so it can spawn into the area left.
