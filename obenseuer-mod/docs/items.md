# Items and inventory

> **Authoritative on:** the item data (Items.json, the OS.Items classes),
> consumables and special effects, the player's inventory, and how the
> item and recipe databases load.
>
> Index of every game system's doc: [`research.md`](research.md).

## Item structure (from Items.json)

```json
{
    "ID": 0,
    "Title": "Open Sewer Coin",
    "Categories": ["Money"],
    "BaseValue": 1,
    "Description": "It's a local coin",
    "Stackable": 99,
    "Appearance": {
        "Material": "Coins",
        "SpritePath": "Sprites/Items/Open Sewer coin",
        "ColorValue": "",
        "EmissionStrength": 0.0,
        "PrefabPath": "Prefabs/Items/Open Sewer coin",
        "PrefabPathMany": "Prefabs/Items/Open Sewer Coin 50",
        "SkinSpritePaths": []
    },
    "Actions": [],
    "Attachments": { "Name": "", "Attachment1": "none", "Attachment2": "none" },
    "Meta": []
}
```

## Item data model (OS.Items namespace)

Items are composed via ItemAction subclasses attached to the base
Item. The OS.Items namespace holds all data components:

| Class | Purpose |
|---|---|
| ItemConsumable | food/drink/medicine stats (consumption below) |
| ItemPerishabledata | spoilage, age, freshness |
| ItemLiquidData | liquid contents |
| ItemFueldata | fuel value |
| ItemGrowdata | plant growth stages |
| ItemEquipable | wearable equipment |
| ItemReadable | books, notes |
| ItemWritable / ItemWritableData | writable text |
| ItemStolenData | stolen flag, original owner |
| ItemQualityData | quality level |
| ItemFurnitureData | furniture placement data |
| ItemSkinData | appearance variants |
| ItemShopData | shop sale data |
| ItemGroupData | batch/group crafting values |
| ItemAnimalData | animal-related item data |
| ItemElectronic | electronic device data |
| ItemReloadable | ammo/reload data |
| ItemTrapData | trap configuration |

## Item consumption (OS.Items.ItemConsumable)

Items with consumable actions carry these float fields, applied
on use:

| Field | Target stat |
|---|---|
| Food | reduces hunger |
| Drink | reduces thirst |
| Nicotine | smoking addiction |
| Intoxication | alcohol |
| SMV | mushroom high |
| SMVProgressionRate | mushroom disease progression |
| Depression | mental health target |
| Health | HP change |
| Bleeding | bleeding reduction |
| High | mushroom high (green) |
| HighOrange | mushroom high (orange normal) |
| HighOrangeBad | mushroom high (orange bad) |
| Tiredness | tiredness change |
| Hygiene | cleanliness |
| AlcoholAddiction | alcohol addiction level |
| MushroomAddiction | mushroom addiction level |
| SmokingAddiction | smoking addiction level |

ConsumableType: Food, Drink, Smoke, Medicine, Bandage, Container,
Slaughter, Hygiene. Special effects: Coffee (reduces tiredness),
SleepingPills, Laxative, Radiation.

## Special item effects (ItemSpecialEffects)

Caffeine (reduces tiredness), Laxative (adds bowel), Methanol
(reduces SMV progression), PiggyBank (spawns money), SleepingPill
(adds tiredness), ScratchCard (gambling).

## Inventory (Inventory)

Singleton, 35 inventory slots plus 8 character slots (equipped).
Character slots: index 3 = head, 4 = face, 5 = backpack,
6 = right hand, 7 = left hand. Uses `SlotController` for each
slot. Starting items configurable. `ItemDatabase` is the static
item registry loaded from Items.json.

## Data loading

| Data file | Loader class | Method | Encoding |
|---|---|---|---|
| Items.json | ItemDatabase | Awake() / OnEnable() / Reload() | UTF-8 |
| Recipes.json | RecipeDatabase | LoadDatabase() | UTF-16 (Encoding.Unicode) |
| Characters.json | (not traced yet) | | UTF-16 |
| NPCBehavior.json | (not traced yet) | | UTF-8 |

ItemDatabase reads `Application.dataPath + "/StreamingAssets/Items.json"`
using `File.ReadAllText`, deserializes with FullSerializer, loads
sprites and prefabs. Has a public `Reload()` method.

RecipeDatabase reads `Recipes.json` with `Encoding.Unicode`,
wraps in a `RecipesHeader` object. Also has `AddRecipe()`,
`RemoveRecipe()`, `EditRecipe()`, `Reload()`.

Both databases have public `Reload()` methods, so a mod can
modify the JSON and call Reload to hot-swap data.
