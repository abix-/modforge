# humanitz-mod open issues

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | `ueforge` | [ ] Deploy UE4SS into the game and confirm the mod DLL loads, the console opens, and the log file appears | Console window opens with "humanitz_mod init" in the log. |
| 1 | `engine` | [ ] Launch the game once and locate config/save paths (likely `%LOCALAPPDATA%/HumanitZ/Saved/`) | Paths documented in engine.md. |
| 1 | `research` | [ ] Browse UObject/UClass trees via the Tables/Classes/Structs tabs to map the game's class hierarchy | A first pass of key gameplay classes (player, inventory, zombies, crafting, vehicles) written into a research doc. |
| 2 | `research` | [ ] Identify the player controller and character classes, find health/stamina/hunger/thirst properties | Property names and offsets documented. |
| 2 | `research` | [ ] Identify the inventory system: container class, item struct, stack size property | Property names documented, one live read confirmed. |
| 2 | `research` | [ ] Identify the crafting system: recipe data table or class, unlock mechanism | Class names and data table paths documented. |
| 3 | `research` | [ ] Identify zombie/NPC spawning: spawner class, spawn rate properties, difficulty scaling | Class names and tuning properties documented. |
| 3 | `research` | [ ] Identify vehicle system: vehicle class, fuel property, speed/handling properties | Class names documented. |
