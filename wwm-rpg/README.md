# wwm-rpg

Wild West Miner Simulator (Demo) RPG mod. Rust cdylib loaded
into the game by the Unityforge.Shim BepInEx plugin.

## Status

**Phase 3 v0:** builds, exports the three `unityforge_*`
entry points, ships a two-skill catalog skeleton
(Strong Back + Greedy Miner), and registers Harmony hooks on
`DigManager.Dig` + `PlayerManager.AddPlayerCurrency`. Once
loaded in-game, the HTTP debug surface (default port 17172)
accepts `ping`, `walk_class`, `inspect_object`, `read_field`,
`write_field`, `invoke_method`, `list_singletons`,
`skill_state`, `skill_add_xp`, `skill_levelup` ops.

What's not done yet (this v0 is the path to "ready to test",
not "feature complete"):

- Effect application (FieldMultiply on
  `PlayerCarryingController.MaxCapacity` etc) is stubbed.
  The Harmony postfixes increment XP but don't apply
  field-mutation effects yet. Once `walk_class` confirms the
  game's field offsets in-running, wire them into the
  postfixes.
- modforge::rpg Tracker / Skill / Effect traits are not in
  place; this v0 keeps state in atomics. Once they migrate,
  this mod will declaratively compose Effects + Triggers.
- Thread safety: the HTTP listener spawns a background
  thread. Ops that touch Unity types (`walk_class`,
  `read_field` on a UnityEngine.Object, `invoke_method`)
  may not be thread-safe; the framework's `write_field` /
  `invoke_method` already route through MAIN_QUEUE, but
  reads currently do not. Add main-thread routing for reads
  if you see Unity-side asserts in the log.

## Build

```sh
# From repo root:
cargo build --release -p wwm-rpg
```

Output: `target/x86_64-pc-windows-msvc/release/wwm_rpg.dll`.

The C# shim is built separately (see
`../unityforge/cs-shim/`). It needs BepInEx + Unity reference
DLLs:

```sh
cd ../unityforge/cs-shim
# Adjust paths to your WWM install:
dotnet build -c Release \
  -p:BepInExDir="C:\Games\Steam\steamapps\common\Wild West Miner Simulator Demo\BepInEx" \
  -p:UnityDir="C:\Games\Steam\steamapps\common\Wild West Miner Simulator Demo\Wild West Miner - Gold Rush_Data\Managed"
```

Output: `bin/Release/netstandard2.1/Unityforge.Shim.dll`.

## Deploy

1. Install BepInEx 5.x (Mono) into Wild West Miner if you
   haven't already. Drop the BepInEx distribution into the
   game folder, run the game once to bootstrap; quit.
2. Copy these files into
   `<WWM>/BepInEx/plugins/wwm-rpg/`:
   - `Unityforge.Shim.dll`
   - `wwm_rpg.unityforge.dll` (rename from `wwm_rpg.dll`)
3. Launch the game. The BepInEx console should show:
   ```
   [Info] Unityforge.Shim: loading <path>\wwm_rpg.unityforge.dll
   [Info] Unityforge.Shim: ready
   [Info] wwm-rpg: ready (ops + selectors + skills installed)
   ```

The shim auto-detects `*.unityforge.dll`; override with the
`UNITYFORGE_TARGET` env var pointing to a different path if
needed.

## Test surface (once HTTP shim lands)

```sh
# Health check
curl -s -XPOST http://localhost:17172/op \
  -d '{"op":"ping"}' | jq

# Find PlayerManager
curl -s -XPOST http://localhost:17172/op \
  -d '{"op":"list_singletons","args":{"types":["PlayerManager"]}}' | jq

# Read the player's money
curl -s -XPOST http://localhost:17172/op \
  -d '{"op":"inspect_object","args":{"handle":<from above>}}' | jq

# Manually add XP
curl -s -XPOST http://localhost:17172/op \
  -d '{"op":"skill_add_xp","args":{"amount":1000}}' | jq

# Level up Strong Back
curl -s -XPOST http://localhost:17172/op \
  -d '{"op":"skill_levelup","args":{"id":"strong_back"}}' | jq

# State
curl -s -XPOST http://localhost:17172/op \
  -d '{"op":"skill_state"}' | jq
```
