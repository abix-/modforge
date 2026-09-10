# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 1 | setup | [x] Install BepInEx 5.4.23.5 into the game directory | `BepInEx/` exists and the game launches with the BepInEx console |
| 1 | setup | [x] Deploy the unityforge C# shim as a BepInEx plugin | The shim loads and prints its init message in the BepInEx log |
| 1 | setup | [x] Build and deploy obenseuer_mod.unityforge.dll | The Rust cdylib loads and `on_init` runs (confirmed by log) |
| 1 | setup | [x] Verify the control plane answers a ping | Control plane answers on port 17175 |
| 1 | setup | [x] Restart script | `obenseuer-mod/scripts/restart.ps1` builds, deploys, restarts |
| 2 | research | [x] Decompile Assembly-CSharp.dll and document key classes | research.md section 9 |
| 2 | research | [x] Map how Items.json is loaded | research.md 9.16: ItemDatabase.Awake, File.ReadAllText, FullSerializer |
| 2 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 1 | mod | [x] Decide initial mod goals | bigger inventory, increased stack sizes |
| 1 | mod | [x] Inventory: 70 slots (10 columns x 7 rows), UI panel widened left | Inventory opens with 10x7 grid in-game |
| 1 | mod | [x] Stacks: 10x multiplier on all stackable items (632 items) | Items stack to 990 in-game |
| 3 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 3 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 3 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
