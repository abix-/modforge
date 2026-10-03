# Crime and police

> **Authoritative on:** the crime system (Crime), prison, and police.
> Police chases through doors (Act_Police) are not researched yet (todo).
>
> Index of every game system's doc: [`research.md`](research.md).

## Crime

Singleton. Crime types: Theft, Violence, Fraud, PrisonEscape,
Administrative, AnimalCruelty, Trespassing, Burglary, Harassment,
Vandalism. Each crime is a `CrimeRecord` with type, victim, and
amount. Fine multiplier = 1.5x. Prison costs 250 per hour.
Max prison time = 100 hours. Bribery is tracked.
`Act_Police` NPCs enforce crimes.

`Crime` is game-wide (saves into Globals); it registers its Lua
functions in Start and unregisters them in OnDestroy (Crime.cs:120-135,
591-); OnLoadingGame clears `arrestInProgress` (100-113). Nothing per
area.

## Prison

`Crime.TeleportToPrison` (Crime.cs:322-330) sends the player to
`info_game_logic.prisonLevelName` with `SaveController.ChangeLevel`, a
normal load (see [`areas.md`](areas.md), area changes other than doors;
each area's prison is in its `info_game_logic`, same doc). Prison lowers
every crime record each second while subscribed to the clock
([`time.md`](time.md)).

## Administrative crimes in areas (StrictArea)

StrictArea subscribes to `Inventory.instance.ItemConsumed` and
`PlayerStats.instance.PlayerDefecatedInPublic` while the player is in it
(OnTriggerStay) and unsubscribes on OnTriggerExit or OnDestroy
(StrictArea.cs); its handlers commit an Administrative crime when
smoking, alcohol, mushrooms or defecation is witnessed. Unity sends no
trigger exit when the object is switched off.
