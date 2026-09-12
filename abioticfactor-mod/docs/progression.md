# Skills, recipes, and difficulty

[Research index](abiotic-factor.md) | [Todo](todo.md)

## skill system

Data tables: `DT_Skills` and `DT_SkillPerks`

## skills (ECharacterSkills enum, 17 skills)
- Accuracy (ranged aim)
- Agriculture (farming)
- Blunt Melee (clubs, hammers)
- Construction (building)
- Cooking (food prep)
- Crafting (general crafting)
- Engineering (tech/electrical)
- First Aid (healing)
- Fortitude (health/resistance)
- Reloading (weapon reload speed)
- Repair (fixing items)
- Resilience (damage resistance/survival)
- Sharp Melee (blades, axes)
- Sneaking (stealth)
- Sprinting (movement/stamina)
- Strength (carry weight, melee power)
- Throwing (grenades, throwables)
- NoSkill (default/none)

## SkillData struct (from usmap)
- `DisplayName`: TextProperty
- `DisplayDescription`: TextProperty
- `Icon`: SoftObjectProperty
- `SkillType`: EnumProperty (ECharacterSkills)
- `StatModifierMap`: Map<StatModifierRowHandle, int>
- `Perks`: Array<SkillPerkRowHandle>
- NO MaxLevel field. Level cap (vanilla 20) is a Blueprint constant

## SkillPerk struct (from usmap)
- `DisplayName`: TextProperty
- `DisplayDescription`: TextProperty
- `RequiredLevel`: int (gates perk unlock)
- `BuffDebuff`: BuffDebuffRowHandle

## character skill tracking (AbioticCharacter, native C++ class)
- `SkillLevelMap` at offset 2016: TMap<SkillRowHandle, int32>, 80 bytes
  - TMap entry stride: 48 bytes
  - Entry layout: UDataTable* (8) + FName (8) + ptr (8) + i32,i32 (8) + level i32 (+32) + flags (4) + hash (8)
  - Skill level value at entry offset +32
  - 16 entries for the 15+ active skills
- `StatModifiers` at offset 1840: Array<StatModifierEntry>
- `StatModifierMap` at offset 1856: Map<StatModifierRowHandle, float>, 80 bytes
- `CheatStatModifierMap` at offset 1936: Map<StatModifierRowHandle, int>, 80 bytes
- `BuffComponent` at offset 1824: object pointer

## level cap analysis
- SkillData has no MaxLevel field (confirmed from usmap, all 39128 name entries searched)
- No MaxLevel, LevelCap, XPCurve, or XPNeeded field exists anywhere in the usmap
- The level cap of 20 is a literal constant in Blueprint bytecode
- Raising the cap requires either patching Blueprint bytecode or bypassing the check via PE hook

## function signatures (runtime confirmed)
- `Client_EventDispatch_SkillUp(Skill: u8, NewLevel: i32, GainedPerk: u8)` (9 bytes)
- `DoesAwardSkillXPWhenHit(MeleeXP: u8, RangedXP: u8, XPMultiplier: f64)` (16 bytes)
- `Server_Award XP Based On Recipe Category(Category: u8)` (1 byte)
- `Server_TryAwardSkillXPOnTargetable(6 params, 33 bytes)` (BP params, not decoded)
- `UpdateSkillStat(1 param, 1 byte)` (BP param, not decoded)

## XP system
- XP gained through skill-specific actions (combat, crafting, sneaking, etc.)
- `XPMultiplier` field (f64) on `DoesAwardSkillXPWhenHit` allows scaling
- XP gain can be boosted by traits (Wrinkly Brainmeat), consumables (Brain, Brainpower Tincture, soups)
- XP bonuses stack multiplicatively

## XP curve (vanilla + mod extension)

Levels 1-20: vanilla table. Levels 21-100: flat delta of 10,900 per level.

| Level | Total XP | Delta |
|-------|----------|-------|
| 1 | 200 | 200 |
| 2 | 500 | 300 |
| 3 | 940 | 440 |
| 4 | 1,572 | 632 |
| 5 | 2,464 | 892 |
| 6 | 3,699 | 1,235 |
| 7 | 5,379 | 1,680 |
| 8 | 7,587 | 2,208 |
| 9 | 10,417 | 2,830 |
| 10 | 13,950 | 3,533 |
| 11 | 18,242 | 4,292 |
| 12 | 23,307 | 5,065 |
| 13 | 29,101 | 5,794 |
| 14 | 35,776 | 6,675 |
| 15 | 43,310 | 7,534 |
| 16 | 51,631 | 8,321 |
| 17 | 60,608 | 8,977 |
| 18 | 70,354 | 9,746 |
| 19 | 80,755 | 10,401 |
| 20 | 91,655 | 10,900 |
| 21-100 | +10,900 each | 10,900 |

Level 100 total: ~963,655 XP (about 10.5x level 20).

## research and recipe system

- `GlobalRecipeSet`, `GlobalResearchSet` (server-wide unlocks)
- `PlayerRecipeSet`, `PlayerResearchArray` (per-player progression)
- `PlayerNewestRecipes` (recently unlocked)
- `BlacklistRecipes` (disabled recipes)
- Research unlocks recipes. Research categories exist

## difficulty system

- `bHardcoreMode` boolean flag
- `GameDifficulty` (type unknown, possibly enum or int)
- `FriendlyFireMode` on Abiotic_Survival_GameState_C
- No evidence of named presets (Easy/Normal/Hard) in binary strings
- May use custom server settings sliders instead of fixed presets
- Difficulty settings likely on GameMode or GameInstance, not GameState
