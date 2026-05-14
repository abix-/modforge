# Adding content to Horsey Game

What's moddable without writing code, derived from the JumboDS64 Steam guide + our decompilation. This is the "content extension" surface.

## What you CAN add (verified by community + our decompilation)

### 1. New horse species / animal populations (pop.xml)

You can define new "pops" (populations) in `data/pop.xml` and the game will respect them.

How:
- Create a new `<pop name="my_species">` block.
- Nest it inside an existing pop to inherit genes (e.g. inside `<pop name="default">` for default-pop traits).
- Override / add `<gene name="X" p0=".." p1=".." p2=".." p3=".." />` for any gene to customize the species.
- The pop name (case-sensitive, spaces OK) is what you put in a spawner's `class` field.

Gotcha (CORRECTS our prior assumption):
- `p0`/`p1`/`p2`/`p3` are **INVERSE weights**. Higher number = LESS likely the allele is chosen.
- `p0="1"` is the most likely allele. `p0="17"` makes it rare.
- This is confirmed by JumboDS64's guide. Worth verifying directly in our decompilation (next read: `FUN_1400a3eb0` chromomap loader or the spawn function).

Inheritance works:
- `<pop name="jockey">` nested inside `<pop name="human">` inherits all human gene weights and adds its own.

### 2. New spawn points on the map (horsey.tmx)

Edit `data/horsey.tmx` in Tiled (mapeditor.org). Spawners are object placements with these properties:

- **class** (required): pop name to spawn (e.g. `"impala"`, `"my_species"`).
- **count** (int, required): how many to spawn.
- **radius** (int, required): spawn area is `(2*radius+1) x (2*radius+1)` centered on the spawner tile.

7 vanilla animal tile types exist. Two more (bunny, dinosaur) are unused but present in the tileset.

### 3. Buried items (horsey.tmx)

Place a capital-I-shaped object with a `buried` string property set to an item ID (0-47). Items beyond 47 produce a buggy "single meat" item.

Full item-ID list in [`EXTERNAL-KNOWLEDGE.md`](EXTERNAL-KNOWLEDGE.md).

Notable items you can plant:
- ID 4 (Plutonium)
- ID 9 (Championship trophy)
- ID 13 (Cash suitcase $200) / ID 14 (Treasure chest $5000)
- IDs 18-21 (DNA pieces G/A/T/C)
- IDs 22-24 (Car upgrades: stripes, suspension, ram bar)
- IDs 42-45 (Ribbons)
- ID 46 (Infinite fence bag)
- ID 47 (8G RAM upgrade for biohacker)

### 4. Custom map / world

Edit the world tile grid in `horsey.tmx` directly. 400x225 tile grid at 32px. Two tilesets:

- `terrain.tsx` (terrain tiles, firstgid 1)
- `locs.tsx` (building/location tiles, firstgid 97)

Caveats:
- The `.tsx` files are NOT shipped. JumboDS64 reconstructed them and shared on Google Drive (link in his guide). Without working `.tsx` files Tiled won't render the map correctly.
- Building tiles use hardcoded tile IDs. **Only one of each building can exist** - the game finds the first instance of each tile ID and stops.
- The CRISPR Lab building requires a separate `vial world` area placed in the map (a "tiny island" of purple chemical tiles). Cas9 and chromosome horses spawn there. Driving onto any non-purple-chemical tile exits the vial.
- Restart+ (post-intro skip) spawn point is marked by the **little truck tile object**.

### 5. Custom textures

All atlases in `data/` are plain PNGs. Replace them with same-dimension files and they'll be picked up. The `.xml` files alongside each PNG (e.g. `sprites.xml`, `furniture.xml`, `terrain.xml`) define sprite rects within the PNG.

### 6. Custom names

Edit `data/names.txt` to change the pool of random horse names. 4,999 entries currently.

### 7. Custom sounds

Drop replacement `.wav` files in `sound/` with matching filenames. Format: mono/stereo WAV (cute_sound limitation).

Cannot add NEW sound events (the engine references sounds by name in `sound.xml` and code is hardcoded to those names).

## What you CANNOT add (without exe modding)

These are baked into the binary:

### 1. New building / location types

Each building type has hardcoded behaviour in `Horsey.exe`. Locations we know exist: Stable, Track, Sweetie, Hermit, Crispr, Glue, CarLot, Lab, Supply, Ecologist, Hutch, Circus, Zoo, Acres, Saloon, PowerPlant, Paddock, Sumo, Pawn, and more.

The `class` field on building tiles is editor-convenience only - the engine uses the tile ID to find the building.

### 2. New item types beyond ID 47

Item IDs 48+ degrade to a buggy "single meat" item. The item type table is presumably an array in code.

### 3. New genes beyond those in genes.xml

The `chromoMap` is constructed at load time from genes.xml (per `FUN_1400a3eb0`). You can probably tweak existing gene values, but adding entirely new genes will fail because the binary references specific gene indices for each trait (the strings `Gene %d not in chromoMap` confirm a fixed indexed map).

WORTH VERIFYING: does the engine support arbitrary gene names, or only the 242 hardcoded ones? Next decompilation read target.

### 4. New behaviour / mechanics

Breeding, racing, CRISPR, sumo, betting - all hardcoded handlers.

### 5. New world dimensions

400x225 is likely hardcoded in code (read in the tmx parser). Custom maps must match this size or risk crashes.

## Practical content-mod recipe

To add a new species "spaceparrot" that breeds in the existing acres area:

1. Edit `data/pop.xml`. Inside `<pop name="default">` add:
   ```xml
   <pop name="spaceparrot">
       <gene name="BASE_BLUE" p0="20" p2="1" />   <!-- mostly blue (p2=1 is dominant) -->
       <gene name="HEAD_ASPECT" p0="20" p1="20" p3="1" />  <!-- distinctive heads -->
       <gene name="SIZE" p0="20" p1="1" p2="20" />  <!-- small (p1=1) -->
       <!-- ... add as many gene tweaks as you like -->
   </pop>
   ```
2. Edit `data/horsey.tmx`. Place a spawner object somewhere on the map (e.g. near the acres):
   - Use one of the 7 animal tile sprites.
   - Set class = `spaceparrot`.
   - Set count = 5, radius = 8.
3. Delete `data/genes.dat` to force regen of the gene cache.
4. Launch the game. Spawn into the acres. Your spaceparrots should be there.

To add a buried trophy chest behind the saloon:

1. Edit `data/horsey.tmx`. Place a capital-I object on the tile behind the saloon.
2. Add a string property: `buried = "14"` (treasure chest $5000).
3. Launch the game. Dig that spot. Profit.

## Verification gaps

These claims need verification against our decompilation:

- [ ] **`p0..p3` are inverse weights** - read the gene-allele selection code.
- [ ] **Adding new gene NAMES** - read `FUN_1400a3eb0` (chromomap loader). Does it accept arbitrary names or only the 242 enum'd ones?
- [ ] **First-instance-wins building rule** - find the building-placement scan code.
- [ ] **Item ID 48+ bug** - find the item table.
- [ ] **400x225 map size** - find the tmx parser.

Where the guide and our decompilation agree (debug mode unlock), confidence is very high. Where the guide is the only source (e.g. item ID list), treat as community-verified but not engine-verified.
