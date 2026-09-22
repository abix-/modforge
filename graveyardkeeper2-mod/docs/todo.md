# graveyardkeeper2-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 1 | setup | [x] Install BepInEx 6.0.0-pre.2 into the game directory | `BepInEx/` exists and the game launches with the BepInEx console |
| 1 | setup | [x] Deploy the unityforge C# shim as a BepInEx plugin | The shim loads and prints its init message in the BepInEx log |
| 1 | setup | [x] Build and deploy graveyardkeeper2_mod.unityforge.dll | The Rust cdylib loads and `on_init` runs (confirmed by log) |
| 1 | setup | [x] Verify the control plane answers a ping | Control plane answers on port 17178 |
| 2 | research | [x] Map MainGame singleton and core systems | research.md MainGame section |
| 2 | research | [ ] Map the save/load flow | Save system documented |
| 2 | research | [ ] Map the crafting/recipe system | Crafting flow documented |
| 2 | research | [ ] Map the NPC/AI system (NodeCanvas behavior trees) | AI tree structure documented |
| 2 | research | [ ] Map the graveyard/body processing pipeline | Body pipeline documented |
| 3 | research | [ ] Map the A* pathfinding setup | Nav graph structure documented |
