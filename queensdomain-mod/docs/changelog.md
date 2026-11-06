# queensdomain-mod changelog

## 2026-11-05

- New mod for Queens' Domain (Steam app 1799840, UE 4.27, the first UE4 game in the workspace). Minimal: UE4SS loader, control plane on port 31310, builtin ops, no tabs, no watchers.
- `scripts/restart.ps1` builds, installs UE4SS from Alchemy Factory with every hook off except EngineTick, deploys and launches.
- `tests/research_ustruct_layout.rs` measures the UE 4.27 UStruct and FProperty offsets.
- First launch: UE4SS finds EngineVersion 4.27, patternsleuth resolves, discovery walks 52699 objects (9 data tables, 2600 classes, 1829 structs), control plane answers. Measured PropertiesSize +0x58, ChildProperties +0x50, ArrayDim +0x38, ElementSize +0x3C, Offset_Internal +0x4C, all matching UE4SS's tables. Added to ueforge as `StructLayout::UE4_27`.

## 2026-11-06

- Weapon level watcher (`src/weapon_level.rs`): the Azure Torch secondary recharges 3% faster per torch level, re-read every 3 s, vanilla restored on shutdown.
- `src/tweaks.rs`, reapplied on every save load: weapons capped above 5 go to max level 100, air dash 1000. Field lookup now walks the class's own fields; the default-object lookup found none on this game.
- ProcessEvent slot 0x44, measured by `tests/research_engine.rs` (the player's function calls the GameInstance's in that slot). Game-thread queue served from UEngine::Tick (slot 86), with the object.call, get, set and array ops.
- FProperty base is 0x78 bytes on UE 4.27 (0x70 on UE 5.4), measured by `research_ustruct_layout.rs property_extra_slot`; now `StructLayout::property_size` in ueforge. Array element records sit at +0x78 on both.
- `tests/research_path.rs`: the game's own navigation from the player to a point, a mesh map of an area, and a climb route using walking, jumps (1.2 m up), air dashes (10 m) and drops. Found a route to the third beacon's unlit brazier.
- Route markers: `research_path.rs` mark_route, draw_route and clear_route_marks spawn lights, pillars and rods along the route. Terrain hides most of them.
- Screen overlay (`ueforge/src/overlay.rs`, ops overlay.lines and overlay.clear): lines drawn in the HUD pass with the game's own ProjectWorldLocationToScreen and HUD DrawLine, seen through hills. `research_path.rs overlay_route` draws the whole route at head height. Not yet tried in game.
- GPS (`ueforge/src/gps.rs`, ops gps.to, gps.clear and gps.state): a route of waypoints and moves, redrawn from the player once a second with the game's own navigation for walking legs; reached waypoints drop off. `research_path.rs gps_route` sends the beacon route, `gps_state` reads progress. Not yet tried in game.
- Hot reload (Ctrl+R) crashes this game: deploy with it closed and swap main-new.dll in by hand.
