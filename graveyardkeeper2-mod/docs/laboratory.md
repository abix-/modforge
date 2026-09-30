# Laboratory

Source: `tests/research_laboratory.rs`, run against the live game on
2026-09-25. Rerun the tests after a game patch; they are the authority,
this page is their output.

## The stations

"Laboratory I/II/III" are world objects in `GameBalance.wgoDefs`. The
display name is `LLBase.L(id)`.

| id | Name in game |
|---|---|
| `alchemy_mix_place` | Laboratory I |
| `alchemy_mix` | Laboratory I |
| `alchemy_mix_2_place` | Laboratory II |
| `alchemy_mix_2` | Laboratory II |
| `alchemy_mix_3` | Laboratory III |

`alchemy_mix_place`: interaction `Work`, hp 3, `transferDataToNewWgo`
true, tech points 5/5/5, talent `talent_orange`, `MasteryLock` 2. Not yet
verified: that it is the spot worked to build `alchemy_mix`.

## Where the recipes live

Two lists on `GameBalance`:

- `alchemyFormulaDefs` (29 entries, `AlchemyFormulaDef`): the results.
  Fields: `id`, `runesRed`, `runesGreen`, `runesBlue`, `tab`,
  `hiddenAtStart`, `craftsIn` (station ids), `onCraftEndExpressions`,
  `ItemDef`.
- `alchemyMixSourceDefs` (6960 entries, `AlchemyMixSourceDef`): every
  valid ingredient combination. Fields: `mixId` (e.g.
  `mix:seed_oil:stick`), `formulaId` (the result), `ingredient1`,
  `ingredient2`, `ingredient3` (empty when the mix has two).

Example: Stick + Seed oil makes Dream Dust (`powder_dreams`).

## How a mix works: runes

Every item has red, green and blue runes (`ItemDef.runesRed`,
`runesGreen`, `runesBlue`, as `LazyExpression`; the game reads them with
`ItemDef.GetRunesAsVector3Int()`). Every result has a rune cost
(`AlchemyFormulaDef.runesRed/Green/Blue`).

A mix is two or three ingredients whose runes add up exactly to a
result's cost. Checked by `research_laboratory_runes` on all 6960 mixes:

    mixes: 6960; runes add up: 6960; do not: 0; unknown: 0
    ingredients without canBeUsedInAlchemy: {}

Example: Stick (0/1/0) + Seed oil (0/0/1) = 0/1/1 = Dream Dust.

Every ingredient in every mix has `canBeUsedInAlchemy` true.

Not yet checked:

- whether the 6960 are every rune combination that adds up, or the game
  leaves some out;
- which results the player has unlocked
  (`KnowledgeSystem.unlockedAlchemyFormulas`, `hiddenAlchemyFormulas`,
  `knownMixCrafts`);
- how a hidden result is revealed, and whether a mix costs time or
  energy.

## Results

Every result below has `hiddenAtStart` true and `craftsIn`
`alchemy_mix`, `alchemy_mix_2`: all 29 can be made at Laboratory I and
Laboratory II. None lists `alchemy_mix_3`.

| id | Result | Runes red/green/blue | Tab | Combinations |
|---|---|---|---|---:|
| `powder_dreams` | Dream Dust | 0/1/1 | Hard | 23 |
| `quest_paint` | Paint | 0/2/0 | Simple | 21 |
| `lacquer` | Lacquer | 0/0/2 | Simple | 14 |
| `heal_potion` | Healing Potion | 2/0/0 | Medium | 13 |
| `heal_potion_2` | Healing Potion II | 4/0/0 | Medium | 52 |
| `heal_potion_3` | Healing Potion III | 5/0/0 | Medium | 76 |
| `damage_potion` | Damage Potion | 1/1/0 | Medium | 23 |
| `damage_potion_2` | Damage Potion II | 2/2/0 | Medium | 216 |
| `damage_potion_3` | Damage Potion III | 3/3/0 | Medium | 471 |
| `motivator_potion` | Zombie Motivator Potion | 1/0/1 | Medium | 17 |
| `motivator_potion_2` | Zombie Motivator Potion II | 1/0/2 | Medium | 64 |
| `motivator_potion_3` | Zombie Motivator Potion III | 3/0/3 | Medium | 253 |
| `berserk_potion` | Berserker Potion | 1/1/1 | Medium | 112 |
| `berserk_potion_2` | Berserker Potion II | 2/1/1 | Medium | 204 |
| `berserk_potion_3` | Berserker Potion III | 3/2/2 | Medium | 887 |
| `weak_growing_elixir` | Weak growth elixir | 1/2/0 | Hard | 102 |
| `rich_growing_elixir` | Rich growth elixir | 1/3/0 | Hard | 218 |
| `miracle_growing_elixir` | Miracle growth elixir | 1/5/0 | Hard | 363 |
| `preservative` | Preservative | 0/3/0 | Heroic | 70 |
| `organ_improver_red` | Organ Improver (red skull) | 4/1/0 | Heroic | 197 |
| `organ_improver_white` | Organ Improver (white skull) | 0/4/0 | Heroic | 136 |
| `resurrection_liquid` | Reanimation Liquid | 2/1/4 | Heroic | 556 |
| `liquid_harden` | Tannin Liquid | 4/2/1 | Simple | 512 |
| `alkali` | Alkali | 1/4/2 | Simple | 945 |
| `dust_explosive` | Explosive Dust | 2/0/2 | Epic | 123 |
| `quality_food_silver` | Spices | 0/2/2 | Epic | 250 |
| `quality_food_gold` | Umami | 0/4/4 | Epic | 440 |
| `philosopher_stone` | Philosopher Stone | 3/3/3 | Epic | 432 |
| `third_eye_salt` | Third Eye Salt | 1/0/5 | Epic | 170 |

## Ingredients

The 70 items with `canBeUsedInAlchemy` true (of 814 in
`GameBalance.itemDefs`), with their runes. "Alchemic Powder" names show
their runes as icons in game; the colour is written out here.

| id | Name | Runes red/green/blue |
|---|---|---|
| `stick` | Stick | 0/1/0 |
| `1h_stone` | Stone | 2/0/0 |
| `1h_marble` | Marble | 3/0/0 |
| `clay` | Clay | 1/0/0 |
| `sand` | Sand | 1/0/0 |
| `cheese` | Cheese | 1/1/1 |
| `water` | Water | 0/1/0 |
| `seed_oil` | Seed oil | 0/0/1 |
| `flour` | Flour | 0/2/0 |
| `minced_meat` | Minced Meat | 0/0/2 |
| `lead` | Tin | 2/0/1 |
| `nugget_copper` | Copper Nugget | 2/1/0 |
| `iron_ore` | Iron Ore | 3/0/0 |
| `coal` | Coal | 1/2/0 |
| `leaf` | Leaf | 0/1/0 |
| `fertilizer:peat` | Peat | 0/1/1 |
| `onion:1` | Onion | 0/2/0 |
| `onion:2` | Onion | 0/2/0 |
| `onion:3` | Onion | 0/2/0 |
| `pumpkin:1` | Pumpkin | 0/3/0 |
| `pumpkin:2` | Pumpkin | 0/3/0 |
| `pumpkin:3` | Pumpkin | 0/3/0 |
| `hop` | Hops | 0/2/1 |
| `flax` | Flax | 1/1/0 |
| `berry` | Berry | 0/1/0 |
| `berry_blue` | Blueberry | 0/0/1 |
| `flower_night` | Night flower | 0/0/2 |
| `mushroom_red` | Red Mushroom | 2/0/0 |
| `mushroom_green` | Swamp mushroom | 0/2/0 |
| `tooth` | Tooth | 1/1/0 |
| `zombie_goo` | Zombie goo | 0/0/2 |
| `powder_r` | Alchemic Powder (red) | 1/0/0 |
| `powder_r_r` | Alchemic Powder (red, red) | 2/0/0 |
| `powder_r_r_r` | Alchemic Powder (red, red, red) | 3/0/0 |
| `powder_g` | Alchemic Powder (green) | 0/1/0 |
| `powder_g_g` | Alchemic Powder (green, green) | 0/2/0 |
| `powder_g_g_g` | Alchemic Powder (green, green, green) | 0/3/0 |
| `powder_b` | Alchemic Powder (blue) | 0/0/1 |
| `powder_b_b` | Alchemic Powder (blue, blue) | 0/0/2 |
| `powder_b_b_b` | Alchemic Powder (blue, blue, blue) | 0/0/3 |
| `powder_r_g` | Alchemic Powder (red, green) | 1/1/0 |
| `powder_r_b` | Alchemic Powder (red, blue) | 1/0/1 |
| `powder_g_b` | Alchemic Powder (green, blue) | 0/1/1 |
| `powder_r_r_g` | Alchemic Powder (red, red, green) | 2/1/0 |
| `powder_r_g_g` | Alchemic Powder (red, green, green) | 1/2/0 |
| `powder_r_r_b` | Alchemic Powder (red, red, blue) | 2/0/1 |
| `powder_r_b_b` | Alchemic Powder (red, blue, blue) | 1/0/2 |
| `powder_g_g_b` | Alchemic Powder (green, green, blue) | 0/2/1 |
| `powder_g_b_b` | Alchemic Powder (green, blue, blue) | 0/1/2 |
| `powder_r_g_b` | Alchemic Powder (red, green, blue) | 1/1/1 |
| `melted_fat` | Melted Fat | 3/0/0 |
| `alcohol` | Alcohol | 0/0/3 |
| `fragrance` | Fragrance | 0/3/0 |
| `crystal_goddess` | Blue Crystal | 0/1/2 |
| `ash` | Ash | 0/1/1 |
| `salt` | Salt | 1/1/1 |
| `heart_0_3:3` | Heart | 1/0/2 |
| `heart_3_1:3` | Heart | 1/0/2 |
| `brain_3_1:3` | Brain | 0/0/3 |
| `brain_0_3:3` | Brain | 0/0/3 |
| `guts_3_0:3` | Guts | 0/1/2 |
| `guts_1_3:3` | Guts | 0/1/2 |
| `flesh` | Flesh | 1/0/0 |
| `blood` | Blood | 0/0/1 |
| `fish_goldfish` | Goldfish | 0/2/1 |
| `cacao` | Cacao | 0/2/1 |
| `gold_nugget` | Golden nugget | 2/1/0 |
| `beeswax` | Beeswax | 1/2/0 |
| `honey` | Honey | 0/2/1 |
| `fireflight` | Firefly | 1/0/2 |

## Every combination

`research_laboratory_recipes` writes all 6960 combinations, with display
names, to `lab_recipes.csv` in the test temp folder
(`target/x86_64-pc-windows-msvc/tmp/`). Columns: `result_id`, `result`,
`ingredient1`, `ingredient2`, `ingredient3`.
