# Batch annotation 01. Top 16 substantial game functions

Each entry: address, proposed name, 1-paragraph summary based on string anchors
and call-graph evidence.

## 1. `0x14009f680` (14,074 bytes). `apply_gene_to_horse`

Strings: `"Bad GXI %d"` ("Bad Gene Index").

Largest game function. Heavy float math (897 float vars per our classifier).
Called by `FUN_1400c0660` (status / debug roster handler) and a few others.

Hypothesis: this is the **gene expression** function. Takes a horse's raw
genome (allele codons from genes.xml) and computes all derived stats (size,
limb lengths, color, skill modifiers, age modifier, litter size stat). The
"Bad GXI" error fires when a gene index is out of range, consistent with
genome decoding. The 897 float vars match per-trait coefficient math.

This is THE function that decides what a horse "is" from its DNA. Patching
it would let us force traits.

## 2. `0x140107660` (12,134 bytes). `world_action_dispatcher`

Strings: `DestroyMountain, DestroyTree, DigFinish, DigLoop, DungInCart,
FencePlace, LassoArriveWithHorse, "Plain", "centipede"`.

Handles player-issued actions on world tiles: shovel-dig, destroy tree/mountain,
place fence, lasso a horse, dump dung in cart, etc. Mixed with terrain-type
strings ("Plain", "centipede") suggests it iterates over tile types.

## 3. `0x140050ad0` (11,025 bytes). `unclassified_large_handler`

No strings exposed. Heavy struct init + repeated calls. Likely a per-frame
location update function for the active location. Needs deeper reading.

## 4. `0x1400f6fe0` (9,683 bytes). `credits_screen`

Strings: `Big list of thanks coming up`, `Brace Yourself Games and The
Experimental Games Showcase`, `Chevy Ray Johnston`, `Deserves some credit`,
`Game credits`, `Here take it`, `Horse whinnies by`, `Horsey Game`, plus
named contributors: "Aaron Gordon", "Andrew Stewart", "Dakota Bosman-Kennedy",
" Froese", etc.

This is the **end-of-game credits** screen handler. Massive function because
it lays out the entire credits sequence as a per-line animated reveal.

NOTE: confirms publishing by **Brace Yourself Games** (the Crypt of the
NecroDancer studio). "Experimental Games Showcase" is a publisher event.
The studio is the publisher, not the developer alone.

## 5. `0x1400d2ab0` (9,349 bytes). `interact_with_npc_or_item`

Strings: `AttachItem, Chomp, DropHorseFail, GrabHorse, "Have this treasure
map", "I want more beer...", "More beer!", "No thanks I'm working", "Chomp",
"Glug", "High Achiever", "Horse"`.

Handles player interactions with NPCs and items. NPCs say lines like "I want
more beer..." (a beer-fetching quest) and "High Achiever" (probably a horse
name? or NPC quest reward). Chomp/Glug are eating/drinking sounds.

## 6. `0x1400ab3d0` (8,647 bytes). `format_horse_type_label`

Strings: `Abomination, Alligator, Centaur, Giraffe, Horse, Human, Smart`.

Builds the display label for a horse based on its species/traits. Combines
type ("Alligator", "Giraffe", "Centaur") with adjectives ("Smart",
"Abomination"). This is the function that produces "Smart Alligator" or
"Centaur Horse" or "Abomination" labels you see in-game.

## 7. `0x14008ffc0` (8,565 bytes). `process_race_results`

Strings: `TitleCard`, `LongTrack`, `"Oddsmaking error on %s!"`, `"Wild Horse %d"`.

Handles a race outcome / oddsmaking. The "Oddsmaking error on %s!" debug log
fires when something goes wrong with the odds computation. "Wild Horse %d"
suggests fallback naming when no name is set.

## 8. `0x140058480` (7,589 bytes). `goal_progress_handler`

Strings: `BuyItem, "Catastrophe... All the wild horses..."`, `De Horsey Island
was named for A...`, `He distinguished himself in Cana...`, `Horse population
is critically low`, `I did it! My research is complete`, `I dug a hole and
found this plinth`, `I'm doing more research`, `"The world gene pool is only
%d%%"`.

Lots of tutorial/dialog strings. This is the **tutorial / goal-progress
narration** dispatcher. Fires the "research complete" and "gene pool %d%%"
status updates. Probably tied to the Goal 1 / Goal 2 system from the start
of the game.

## 9. `0x1400b0740` (7,483 bytes). `apply_horse_decoration`

Strings: `DecoCrown, DecoGlasses, DecoSunglasses, DecoToque`.

Applies cosmetic decorations to a horse: crown, glasses (regular + sun-),
toque. These are the dress-up items from the item list (crown=trophy items,
glasses/sunglasses=item IDs 30/31, toque=hat).

## 10. `0x1400ba940` (7,179 bytes). `vehicle_engine_handler`

Strings: `ImpactHard, JetEngineLoop`.

Heavy float math (210 float vars). Probably **car/truck physics handler**.
JetEngineLoop suggests vehicle audio. ImpactHard plays on hard crashes.

## 11. `0x140039190` (6,047 bytes). `circus_event_handler`

Strings: `"A mysterious prize appears"`, `Any horse can be a winner`, `Bring
a horse into the tent`, `Bring your horse to the circus`, `Cannon`, `Freak`,
`Freak tent fees help fund the circus`, `LockBreak`.

The **circus location** logic: cannon shot, freak tent, prize appearance,
"any horse can be a winner" entry text. LockBreak suggests opening a locked
prize.

## 12. `0x14007b2e0` (5,750 bytes). `sumo_match_handler`

Strings: `GongWoodLight, LerpHorse, SumoBattle, World, "rabbit"`.

The **sumo location** logic. Gong sound starts the match; LerpHorse animates
horses moving to position; SumoBattle is the active fight. "rabbit" suggests
a specific opponent type (rabbits can fight in sumo).

## 13. `0x140061f40` (5,304 bytes). `track_dialogue_dispatcher`

Strings: `"All the horses are gone, there's..."`, `Better luck next race`,
`Bring a horse here if you wanna race`, `Bring your horses`, `Bring your
winningest horse for the race of champions`, `Congrats! What an exciting race`,
`Congratulations! Open your gift...`, `Don't give up`, `"%s just had a bad
race"`.

Dispatches all the **Race Track location dialog**: pre/post-race compliments,
prizes, encouragement. Fires `"%s just had a bad race"` for a poor performance.

## 14. `0x1400fe2e0` (5,277 bytes). `tmx_map_parser`

Strings: `"Map %s not found"`, `"height"`, `"objectgroup"`, `"offsetx"`,
`"offsety"`, `terrain`.

Parses `horsey.tmx` Tiled map. The XML element/attribute names (`height`,
`objectgroup`, `offsetx`, etc.) are direct Tiled spec. `Map %s not found` is
the file-missing error. This is **THE map loader**.

## 15. `0x14010a5e0` (5,188 bytes). `hot_air_balloon_handler`

Strings: `BalloonDisabled, BalloonDown, BalloonSimFaster, BalloonSimSlower,
BalloonUp, LassoMiss, LiftOff, LiftOn`.

The **hot air balloon controller**. BalloonSimFaster/Slower is the x300
sim-speed cheat (press 5 in balloon per JumboDS64). BalloonUp/Down handle
altitude. LiftOff/LiftOn manage takeoff. LassoMiss = lasso-throw failure
(probably lasso while in balloon).

## 16. `0x140092820` (5,156 bytes). `population_spawner`

Strings: `"alligator", "crazy horse", "dachshund", "fest horse", "freak"`.

References population names from `pop.xml`. This is likely the **pop.xml
spawner dispatcher**. Gets a class name like "alligator", looks up the
population's gene weights, and generates a horse genome matching it.

THIS is the function that implements the inverse-weight allele selection
per JumboDS64's guide. Verifying that claim requires reading this function
in detail (next target).
