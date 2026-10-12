# Megabonk: shrines and other things you interact with

What every interactable in a Megabonk run is, read from the live game
over the mod's control plane (port 17183) on 2026-10-03, and which ones
give the most value.

Source: `tests/research_shrines.rs` lists every Assembly-CSharp type
named after shrines, interactables, statues, altars, pots or portals,
counts the live ones in the current map, and prints the first one's own
fields. The counts below are from one map (one run, one stage); other
maps roll different counts. "What it is" comes from the class's fields
where they say something; rows marked (guess) are from the class name
only and still need a test.

## Shrines

| Thing (class) | In the map | What it is |
|---|---|---|
| Charge shrine (`ChargeShrine`) | 16 | Stand in it for 5 seconds (`chargeTime=5.0`) for a reward. 0.8% chance to be golden (`goldChance=0.008`). |
| Greed shrine (`InteractableShrineGreed`) | 9 | (guess) more gold or loot for a cost or a risk. |
| Challenge shrine (`InteractableShrineChallenge`) | 5 | Spawns enemies (`enemies`); a reward when they are beaten (`hasGivenReward`). |
| Magnet shrine (`InteractableShrineMagnet`) | 5 | (guess) pulls every pickup on the map to you. |
| Moai shrine (`InteractableShrineMoai`) | 4 | Gives items (`isItemSource=true`). Tied to the upgrade screen's moai luck (`UpgradePicker.SetMoaiLuck`, `moaiLuckMode`). |
| Cursed shrine (`InteractableShrineCursed`) | 3 | (guess) a curse for a reward: harder enemies, more loot. |
| Balance shrine (`InteractableShrineBalance`) | 1 | (guess) matches the Balance tome, "Gain +2% in every stat". The game has `EncounterUtility.GetBalanceShrineOffers`. |

## Loot

| Thing (class) | In the map | What it is |
|---|---|---|
| Chest (`InteractableChest`) | 67 | Costs gold (`isHoveringAndCantAfford`); the item's rarity is rolled by `Rarity.GetItemRarity(luck)`. |
| Pot (`InteractablePot`) | 130 | Break for luck: `luckPerPot=0.005`, added to a temporary stat named `PotLuck`. Big and silver pots exist (`isBig`, `isSilver`). |
| Microwave (`InteractableMicrowave`) | 2 | Gives items (`isItemSource=true`), 3 uses (`usesLeft=3`), cooks for a while (`isCooking`, `readyAtTime`), has a rarity. |
| Shady Guy (`InteractableShadyGuy`) | 2 | Merchant; sells items with a rarity (`Rarity.GetShadyGuyRarity`). |
| Unlock (`InteractableUnlock`) | 7 | Gives items or unlocks (`isItemSource=true`, `useUnlock=true`). |
| Gift (`InteractableGift`) | 1 | (guess) a free reward. |
| Cage and cage keys (`InteractableCage`, `InteractableCageKey`) | 1 cage, 2 keys | The key is item 81 (`eItem=81`); it opens the cage. |

## Fights and bosses

| Thing (class) | In the map | What it is |
|---|---|---|
| Boss spawner (`InteractableBossSpawner`) | 3 | Starts a boss fight (`numBossesDefeated`). |
| Final boss spawner (`InteractableBossSpawnerFinal`) | 1 | The stage's final boss. |
| Character fight (`InteractableCharacterFight`) | 3 | Fight one enemy (`myEnemy`). |
| Desert grave (`InteractableDesertGrave`) | 4 | Spawns a buffed enemy (`sizeMultiplier=2.5`, `speedMultiplier=1.5`). |
| Skeleton King statue (`InteractableSkeletonKingStatue`) | 1 | Summons the skeleton king (`myEnemy`). |
| Egg (`InteractableEgg`) | 3 | Releases frogs that run from you (`frogEnemies`, `frogTargets`). |
| Crypt, coffin, crypt exit (`InteractableCrypt`, `InteractableCoffin`, `InteractableCryptLeave`) | 1, 1, 2 | A crypt dungeon with a boss and fog; the exits take you back. |
| Ghost boss exit (`InteractableGhostBossLeave`) | 1 | The way out after the ghost boss. |

## Odd things and travel

| Thing (class) | In the map | What it is |
|---|---|---|
| Portal (`InteractablePortal`, `SpawnPlayerPortal`) | 3 | To the next stage or area. |
| Tumbleweed (`InteractableTumbleWeed`) | 24 | Rolls across the map; can be broken (`broken`). |
| Bananarang, Boombox, Gravestone | 1 each | (guess) one-off secrets; the fields only say `done`. |

## How a map is filled

`SpawnInteractables`: world 960 x 960 (`worldArea`), chest density
0.00012, a 5% chance for a free chest (`chanceForFreeChest=0.05`),
shrine density 0.000042.

## The game's own names

`GetInteractString` / `GetDebugName` on a live one (2026-10-03):
Charge Shrines; Greed Shrine; "Summon the Challenge!" (Challenges);
"Shrine of Succ" (Magnet Shrines); "Consult the Moai" (Moais); "Boss
Curse" (Boss Curses); "Shrine of Balance" (Bald Heads); "Use Microwave"
(39 gold); Chests (115 gold); "Talk to Shady Guy".

## How rewards are made

Amounts are not stored on a shrine; they are rolled when it is used
(`tests/research_rewards.rs`, `research_reward_samples.rs`):

- Encounters (`EEncounter`): Levelup, RandomStats, GreedAltar,
  ChestNormal, ChestFree, ChestEvil, Moai, ShadyGuy, BalanceShrine,
  Microwave, ChestFreeCrypt, ChestGhost. A charge shrine opens the
  ChargeShrine reward window (`ERewardWindowType`).
- Rarity of an offer: `Rarity.GetEncounterOfferRarity(luck)`. 200 rolls
  each:
  - luck 0: Common 162, Uncommon 24, Rare 11, Epic 3, Legendary 0
  - luck 5 (the mod's 500%): Common 56, Uncommon 24, Rare 51, Epic 39,
    Legendary 30
- Size by rarity, `Rarity.GetMultiplier`: Common 1.0, Uncommon 1.2,
  Rare 1.4, Epic 1.6, Legendary 2.0.
- Charge shrine offers, `EncounterUtility.GetRandomStatOffers(3, false,
  true)`: pick 1 of 3, each one stat. Sampled: +5 to +15% to a stat
  (damage 0.144, attack speed 0.084, crit damage 0.14, XP 0.09 to 0.15,
  gold 0.09 to 0.15), or flat (+15 max health, +7 shield, +5 thorns,
  +0.05 to 0.08 luck, +1.6 projectiles, +2 extra jumps), and sometimes
  a bad one (+0.15 elite spawns, +0.16 difficulty).
- Balance shrine offers, `GetBalanceShrineOffers(3)`: pick 1 of 3,
  always Rare, each one stat x2.0 and another x0.5 (Multiplication).
- Greed shrine offers, fixed in `EncounterData` (GreedAltar): one is
  +0.1 Difficulty plus gold 0.5, the other gold 1.0 (EGold effect).
  What the gold value buys in coins is not read yet.

## Which ones give the most value, and in what order

Ranked from the numbers above; rows marked (unmeasured) still need a
test.

1. Luck. It sets every offer's rarity: at luck 5, 35% of offers are Epic
   or Legendary (worth 1.6x to 2.0x); at luck 0 it is 1.5%. The mod gives
   the luck tome and 500% at the start of each run (src/luck.rs), so
   pots (0.005 luck each) are not needed while it runs.
2. Balance shrine, the moment you find it (1 per map). x2.0 to one stat
   is the biggest single change any shrine offers. Pick an offer that
   doubles a stat you use (damage, crit chance, attack speed, XP) and
   halves one you do not (fall damage reduction, knockback, pickup
   range).
3. Charge shrines, every one you pass (16 in the map read): free, 5
   seconds, permanent, and the most of any shrine. Each is one stat
   +5 to +15%, scaled 1.0x to 2.0x by rarity; with the mod's luck many
   roll Epic or Legendary. Skip the bad offers (elite spawns,
   difficulty).
4. Item sources with your gold: chests (115 gold), microwaves (39 gold,
   3 uses), Shady Guy, Moai. Item rarity also comes from luck.
   (unmeasured: item value against stat value)
5. Greed shrine only when short on gold: it trades difficulty for gold.
6. Challenge shrines, Boss Curses, desert graves, character fights,
   bosses: rewards for a fight. (unmeasured)
7. Magnet shrine: collects pickups; use it when the map is full of XP
   or gold.
