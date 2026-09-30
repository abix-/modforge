# terrainvicta-mod open issues

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | `terrainvicta-mod` | [x] Create the Cargo.toml as a cdylib depending on modforge and unityforge, and a minimal src/lib.rs that declares a ModDef with on_init registering built-in ops and selectors, wired with unityforge_mod! | `cargo check -p terrainvicta-mod` passes. |
| 2 | `cs-shim-mono` | [ ] Install BepInEx 5 (x64 Mono) into the game directory and deploy the cs-shim-mono plugin so it loads the Rust cdylib at game startup | The game launches with BepInEx and the shim logs "Unityforge.Shim: ready" in the BepInEx log. |
| 3 | `terrainvicta-mod` | [ ] Run scripts/restart.ps1 to build, deploy as terrainvicta_mod.unityforge.dll, launch, and confirm the control plane answers on port 17179 | `TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test smoke` passes both tests against the running game. |
| 4 | `terrainvicta-mod` | [ ] Run walk_class and list_singletons against the live game to map the game's type system and find the entry points for game state | A research doc listing the key classes and singletons exists in terrainvicta-mod/docs/research.md. |
