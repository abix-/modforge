# Crafting, trade, storage, banks and locks

> **Authoritative on:** crafting stations, traders, storages, banks and
> currencies, and locks and lockpicking.
>
> Index of every game system's doc: [`research.md`](research.md).

## Crafting (CraftingBase)

All crafting stations inherit from `CraftingBase`, which is an
`Interactable` requiring a `Storage` component. Key fields:
`EquipmentQuality` (affects batch success), `Recipes` (array of
RecipeType), `Modifiers` (conditions like power, water),
`SkillGainFactor`, power/fuel settings. Recipes reference items
by ID with input amounts and output definitions.

## Trade (Trade)

Traders are `Interactable` components with `Storage`. They have
money ranges (`traderMoneyAmountMin`/`Max`, defaults 5000/10000),
opening times (`autoOpenClose`), price mode (Real Money only or
Open Sewer Coins only), and spawn settings for restocking.

## Storage (Storage)

`Interactable` with NPC ownership, lock support, permissions
(PermissionToTake, PermissionToUse), power state, refrigeration
level (0..1 = fridge, >1 = freezer), and spawn settings for
restocking. Taking from a locked/owned storage without permission
triggers the crime system ([`crime.md`](crime.md)).

## Banking (Bank)

Two currencies: OC (Open Sewer Coins, local) and RM (Real Money).
Exchange rates: OC to RM = 0.06, RM to OC = 9.8.
Banks track total supply, daily income/spending averages,
corruption, interest rate (1.5%), and lending confidence.

## Locks and lockpicking (Lock)

Locks have difficulty (0..2): effortless = 0.1, easy = 0.2,
moderate = 0.3, challenging = 0.8, difficult = 1.9.
`Lockpickable` flag controls whether the player can attempt it.
`increaseLockDifficulty` makes re-locking harder after a pick.
Difficulty increase amount = 0.33.
