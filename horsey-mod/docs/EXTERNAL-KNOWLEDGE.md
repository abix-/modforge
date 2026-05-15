# External knowledge from other modders / wiki / community
> **Authoritative on:** facts sourced from the community/wiki/Steam guides (not from our decompilation). Citations attached.

Knowledge not derived from our decompilation but from existing public sources. Cited so we know what's verified-by-other-people vs verified-by-us.

## Source: Steam guide "Editing horsey.tmx" by JumboDS64

URL pattern: Steam Community guides for Horsey Game (posted Apr 22 2026, updated May 5 2026).

Key facts the guide confirms or adds:

### Debug mode unlock (CONFIRMS our decompilation)

> "enable debug mode by spelling d-e-b-u-g in the pause menu, then press 5 while in the hot air balloon"

**This independently confirms our `FUN_140066200` finding** that typing `"debug"` unlocks the cheat menu. Decompilation said the same.

Additional cheat we didn't find: **press 5 while in the hot air balloon** activates x300 game speed.

### pop.xml gene weight semantics (CORRECTS our prior assumption)

> "Place a pop inside the 'default' pop (or whatever pop you want your pop to inherit from), fill it with gene tags... The random chances are **inverse values - a higher value means that allele is more unlikely**!"

**THIS REVERSES what we assumed.** We thought `p0="17"` meant "weight 17 for allele 0". Actually, higher `p` value = LESS likely. So `p0="1"` is the most likely allele.

This also explains why `pop.xml`'s default pop has many `p0="1"` entries: they're the dominant alleles. The high numbers (`p0="17"`, etc.) are RARE.

### pop.xml inheritance

> "Every pop uses both the <gene/> tags within that <pop> </pop> group, as well as the <gene/> tags of the <pop> </pop> group that pop is inside!"

Populations nest. `<pop name="jockey">` inside `<pop name="human">` inherits the human's genes and adds its own. Worth checking our `pop.xml` structure for nesting.

### Tileset .tsx files are not shipped

> "the tilesets originally used to create the map are not included in the folder. It's easy to recreate locs.tsx using the software itself... but weirdly hard to recreate terrain.tsx."

JumboDS64 created `terrain_editing.png` and a working `.tsx` shared on Google Drive. We could pull those if we want to edit the map ourselves. For now: confirms our finding that `.tsx` is baked into / referenced but not shipped.

### Buildings: tile-ID based, one-of-each

> "Even though the default map assigns class names to all the buildings, this is simply for editor convenience - the game only cares about the tile ID. Only one of every building may exist at once, unfortunately, as the game will simply place the first instance of the building it finds and stop looking for new ones."

So the world map has uniqueness constraints baked into the engine for buildings: first instance wins.

### Restart+ spawn point

> "don't forget to place an object using the tile of the little truck if you intend on using Restart+ to skip the intro while testing - that marks your initial spawnpoint in Restart+!"

A "Restart+" feature exists. The truck tile object marks the post-intro spawn.

### CRISPR Lab island = "vial world"

> "the CRISPR Lab requires something else special to be placed: the CRISPR island! ... a little location labeled as 'vial world'! This vial tile marks where Cas9 and all the chromosome horses spawn when you enter CRISPR. ... leaving CRISPR is triggered by driving onto ANY non-purple-chemical tile."

We had no info on the CRISPR mechanic before. Now we know:
- CRISPR lab teleports you to a "vial world" sub-map.
- Inside the vial, the player drives around as if shrunk into a DNA vial.
- The world is purple chemical tiles; touching non-purple exits.
- `Cas9` and "chromosome horses" spawn there - these are the "Found %d/%d chromosomes" we saw in `FUN_1400fd3e0`.

### Buried item ID list (51 items, IDs 0-50)

The "buried" property of a capital-I object holds the item ID. Map (from guide):

| ID | Item |
|---|---|
| 0 | Hay bale |
| 1 | Apple |
| 2 | Beer |
| 3 | Hot sauce |
| 4 | Plutonium |
| 5 | Fossil bone |
| 6 | Carcass |
| 7 | Manure |
| 8 | Regular blue trophy |
| 9 | Championship trophy |
| 10 | VIP card |
| 11 | DNA beaker |
| 12 | Floppy disk |
| 13 | Cash suitcase ($200) |
| 14 | Treasure chest ($5000) |
| 15 | Potted cactus |
| 16 | Flower vase |
| 17 | Treasure map |
| 18 | Guanine (G DNA piece) |
| 19 | Adenine (A DNA piece) |
| 20 | Thymine (T DNA piece) |
| 21 | Cytosine (C DNA piece) |
| 22 | Racing stripes upgrade |
| 23 | Suspension upgrade |
| 24 | Ram bar upgrade |
| 25 | Sneakers |
| 26 | Bowtie |
| 27 | Dress tie |
| 28 | Top hat |
| 29 | Beanie |
| 30 | Doctor's glasses |
| 31 | Sunglasses |
| 32 | Ball n' chain |
| 33 | Back rocket |
| 34 | Balloon |
| 35 | Roller skates |
| 36 | Stilts |
| 37 | Clown nose |
| 38 | Tan boots |
| 39 | Brown boots |
| 40 | Purple boots |
| 41 | Black boots |
| 42 | Diving ribbon (pink) |
| 43 | Stronghorse ribbon (yellow) |
| 44 | Trampoline ribbon (orange) |
| 45 | Acrobat ribbon (green) |
| 46 | Infinite fence bag |
| 47 | 8G RAM upgrade for biohacker |

> "Anything higher will result in a bugged 'single meat' item that is both edible and wearable as an invisible clothing item."

So 48-50 are out-of-bounds and result in undefined behavior.

### Spawner objects

7 animal tile types in vanilla. Spawner needs:
- `class` field: which pop name to spawn (e.g. `"impala"`).
- `count` int property: how many horses to spawn.
- `radius` int property: spawn area = `(2*radius+1) x (2*radius+1)` centered on the spawner.

Also: there are **unused tiles for bunnies and dinosaurs** ("Interestingly, there are unused ones for bunnies and dinosaurs... were they going to spawn naturally at some point?").

### Hot air balloon = special vehicle

The guide mentions "if you've obtained the hot air balloon upgrade". So the balloon is a player-progression unlock that enables aerial map view.

## Source: HorseyGame wiki at horseygame.miraheze.org

JumboDS64 links to this for gene details:

> "Look to the wiki for a list of genes and the values for p0 thru p3, as well as the in-game letters each manifests as."

Not pulled yet. To do.

## Confidence and how to use this

These facts come from another player who reverse-engineered the game (or has dev contact). They CONFIRM what we found from decompilation and EXTEND with player-side knowledge we couldn't have derived from static analysis alone.

Treat the JumboDS64 facts as high confidence where they intersect with our findings (debug unlock - both us and them agree) and medium confidence elsewhere (inverse pop weight - we should verify by reading the gene-spawn code in `FUN_1400a3eb0` or related).

## Things to verify against our decompilation


> **Action items** for this doc are tracked in [`todo.md`](todo.md#external-knowledge-verification-gaps).
