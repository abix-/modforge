# Items and inventory

> **Authoritative on:** item data (Items.json, `Item`, the `OS.Items`
> action classes), `ItemDatabase` and `RecipeDatabase` loading,
> `ItemStack`, consumables and special effects, and the player's
> `Inventory` (slots, save, item queries, Lua functions).
>
> Index of every game system's doc: [`research.md`](research.md).

## Items.json

`StreamingAssets/Items.json` (UTF-8): `List<Item>`.

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

## ItemDatabase

`public class ItemDatabase : MonoBehaviour` (ItemDatabase.cs). In
`Game_Logic/Game UI`.

| Member | Does |
|---|---|
| `static List<Item> database` | Every item; static, so loaded once per game run |
| `static ItemDatabase instance` | |
| `Awake()` (19-44) | `instance`; if `database` is empty: `File.ReadAllText(Application.dataPath + "/StreamingAssets/Items.json")`, FullSerializer into `List<Item>`; per item `Appearance.LoadSprite()`, `GetColor()`, `LoadItemReferencedAssets` (logs items with no appearance) |
| `OnEnable()` (45-61) | Same when `instance` is null |
| `Reload()` (63-70) | Re-reads Items.json (a mod can edit the file and reload) |
| `static LoadItemReferencedAssets(Item, bool onlyMeta)` (72-) | Loads referenced assets |
| `Item FetchItemByID(int id)`, `FetchItemByID(int, string itemnamespace)` (115-142) | |
| `FindByString(string)`, `FindByString(string, string)`, `ListItemsByID()`, `ListItemsByCategory(string)`, `GetDatabase()` | |
| `static DeSerialize(Type, string)`, `static Serialize(Type, object)` | FullSerializer |

`RecipeDatabase` (RecipeDatabase.cs): reads `Recipes.json` with
`Encoding.Unicode` (UTF-16) into a `RecipesHeader`; `LoadDatabase()`,
`AddRecipe()`, `RemoveRecipe()`, `EditRecipe()`, `Reload()`. In
`Game_Logic/Other`. Characters.json (UTF-16) and NPCBehavior.json
(UTF-8): [`npcs.md`](npcs.md).

## Item data model (OS.Items namespace)

Items are composed of `ItemAction` subclasses on the base `Item`:

| Class | Purpose |
|---|---|
| ItemConsumable | food/drink/medicine stats (below) |
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

## ItemStack

`public class ItemStack` (ItemStack.cs): one slot's contents.

| Member | Meaning |
|---|---|
| `ItemReference itemReference` | The item (rebuilt from `itemId` after load) |
| `int itemAmount` | |
| `itemId` | Item ID (read by Inventory's load; declaration not read) |
| `float refigerated`, `bool spoilDisabled` | |
| `object[] _meta` | Per-stack data (`ItemQualityData`, ammo, wallet, package, stolen, ...); `GetMetaOfType<T>()`, `AddMeta(object)` |
| `IsEmpty()`, `AddItemToPanel(...)` (161-238), `RemoveItemAmount(int)`, `RemoveStack()`, `ChangeItem(ItemReference, int)`, `CopyItemStack()`, `static CreateStackFromItem(Item, amount, ownerId, meta)`, `GetAmmodata()`, `GetQualitydata()`, `GetWalletdata()`, `GetPackagedata()`, `ChangeSkin(int)` | |

## Inventory

`public class Inventory : SavableScript` (Inventory.cs). In
`Game_Logic/Game UI` (rebuilt by every load). Saves into Globals.

| Member | Meaning |
|---|---|
| `static Inventory instance` | Awake (187-190) |
| `SlotController[] Slots` | 35 inventory slots |
| `SlotController[] CharacterSlots` | 8 equipment slots: 3 head, 4 face, 5 backpack, 6 right hand, 7 left hand |
| `SlotController[] _savingSlots`, `_savingCharacterSlots` | Saved copies of the slots |
| `event ItemConsumed(Item, SlotController, int amount, int owner, object[] meta)` | Fired by `OnItemConsumed`; StrictArea and ItemAchievementList listen |
| `OnSavingGame()` (124-137) | Copies the slots into `_savingSlots`, writes its entry |
| `OnLoadingGame()` (139-168) | Reads its entry; each saved non-empty slot: categories, `itemStack`, `itemReference` from `ItemDatabase.FetchItemByID`; `StartInit()`, `ForceCharacterItemsUpdate()` |
| `Start()` (192-) | Lua: `CheckForItemDialogue`, `CheckForItemDialogueAmount`, `CheckForItemDialogueLiquidAmount`, `CheckForItemDialogueOwner`, `SellItemDialogue`, `SellItemDialogueCategory`, `RemoveItemDialogue`, ... |
| `DeltaSeconds(int)` (298-304) | Refreshes slots while the inventory panel is open |
| `AllSlots(bool ignoreBackpack, bool ignoreCharacterSlots)` (170-) | |
| `GiveStartItems()`, `OnItemConsumed(...)`, `CheckForAddedStolenItems(...)` (379-) | |
| `CheckForItem(...)` (1227-1265), `CheckForItemQuality`, `CheckForCategoryItem`, `GetItemAmountInInventory(int id or Item, bool ignoreBackpack)` (1370-1387), `CountItems(...)`, `FindItem(...)`, `IsInventoryEmpty()`, `GetEmptySlotsAmount`, `InventoryIsNotFull(...)` | Queries |
| `RemoveItems(...)` (945-975), `RemoveItem(...)`, `RemoveLiquid(...)`, `RemoveItemQuality(...)`, `RemoveStack(int)` | Removing |
| `SellItems(...)` (824-849), `GetStolenItems(int)`, `GetPlayerItems(...)` | |
| `SwapItems`, `RemoveEquippedItem`, `CheckIfEquipped`, `CheckIfPlayerWieldsItem(...)`, `ForceCharacterItemsUpdate()`, `ForceHandItemUpdate()`, `SortSlots(...)` | Equipment and UI |

## Consumption (OS.Items.ItemConsumable)

Float fields applied on use (`PlayerStats.UpdateValues`, [`player.md`](player.md)):

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
Slaughter, Hygiene. Special effects (`ItemSpecialEffects`, applied over
time by `PlayerStats.ProcessItemSpecialEffects`): Caffeine (reduces
tiredness), Laxative (adds bowel), Methanol (reduces SMV progression),
PiggyBank (spawns money), SleepingPill (adds tiredness), ScratchCard
(gambling), Radiation (dose).

## With areas kept loaded

`Inventory` is the live copy from the area the save loaded (one copy).
`ItemDatabase.database` is static and loaded once.
