# UE mod formats and the DLL-mod trade-off

> **Authoritative on:** what kinds of UE5 mods exist, what
> each can and can't do at runtime, and why ueforge targets
> the DLL-proxy (UE4SS) shape specifically. Background
> material useful when explaining a UE5 mod's architecture
> to someone new to the ecosystem.
>
> Not Grounded 2 specific. Not ueforge-internals specific.
> Lives here because it's the same reference for any UE5 mod
> built on top of ueforge.

## Six common UE mod shapes

Real-world prevalence runs roughly: pak > DLL proxy (incl.
UE4SS) > Lua-on-UE4SS > injected DLL > loose files > official
plugin. Pak is by far the most common because it's what the
engine natively supports without any modding framework. For
games where pak conflicts hurt (most of them), DLL proxy is
the next most common.

| Format | How it loads | What it can do | Conflicts | Survives game patches | Live config | Vortex-friendly | Anti-cheat risk | Examples |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **`.pak` / `.utoc` / `.ucas` override** | Game's pak loader at startup. Drop in `Paks/~mods/`. Native UE feature. | Replace cooked assets: data tables, Blueprint defaults, meshes, textures, sounds, levels. Cannot run native code. | High. Two paks touching the same asset = last-loaded wins, the other silently does nothing. | Fragile. Any patch that rebuilds the asset breaks the override. | None. Numbers are baked at cook time. To change a value you swap the `.pak`. | Excellent (native install pattern). | Low. Pak loading is a vanilla engine feature. | Most Nexus mods. Player Tweaks (Caites). |
| **DLL proxy** (winhttp.dll, dxgi.dll, dwmapi.dll, etc.) | Windows DLL search order auto-loads our DLL when the game imports the system DLL of that name. Our DLL forwards real exports to System32. | Anything native code can do: read/write engine memory, hook ProcessEvent, install detours. Full programmatic control over runtime state. | Two proxies of the same name fight. Pick a less-common target (e.g. winhttp instead of dxgi) to avoid clashes with ReShade/UE4SS. | Strong. Patches survive game updates as long as offsets don't shift; if they do, update one constants file. | Yes (read JSON / TOML at load time). | Excellent (single file drop). | Medium. Detection-grade anti-cheats often flag DLL-in-game-folder patterns. | UE4SS, ReShade, ENB. |
| **UE4SS Lua mod** | UE4SS itself is a DLL proxy. Once it's installed, Lua mods drop into `Mods/` and UE4SS loads them per its own loader. | Whatever the UE4SS Lua API exposes: BP function calls, Blueprint reflection, hot-reload. Less power than a native DLL but a lot more than a pak. | Per-mod conflict scope is tighter than paks (Lua mods rarely fight unless they touch the same Blueprint), but you depend on UE4SS being installed. | Medium. UE4SS itself needs updates per game patch; Lua mods riding on it benefit from that. | Yes (Lua code reads files / hot-reloads). | Excellent if UE4SS is installed; user has to install UE4SS first. | Same as DLL proxy (UE4SS *is* one). | Many UE4 / UE5 modding scenes. Common for Hogwarts Legacy, Lies of P, Lords of the Fallen, etc. |
| **UE4SS C++ DLL mod** ("CPPMods") | Same as Lua mods but compiled C++ plugged into UE4SS. | Native code + UE4SS reflection helpers + Blueprint introspection. Best of both worlds for a single mod. | Same as Lua mods: scoped to the mod's actual reach. | Medium. Tied to UE4SS's lifecycle. | Possible (read config in C++). | Good with UE4SS installed. | Same as DLL proxy. | **Target shape for every ueforge mod.** Most large UE4SS-based total-conversion projects. |
| **Injected DLL via separate exe** | User runs an injector that calls `LoadLibrary` in the game process. | Same as DLL proxy. | None at the load layer (only one mod runs at a time per session unless the user injects multiple). | Strong (same offsets-only dependency as DLL proxy). | Yes. | Bad. Vortex doesn't model "run an exe before launching the game." | Higher. Tools that look like trainers / cheat injectors trip detection. | Cheat trainers, Cheat Engine tables converted to DLLs. |
| **Loose files / asset replacement** | Game's loose-file fallback (only if the engine was cooked with `bUseIoStore = false` or with loose-asset support). Drop `.uasset` next to the cooked asset path. | Replace individual cooked assets without packaging a pak. | High when multiple loose files target the same path. | Fragile (same as pak). | None. | Possible but unusual. | Low. | Older UE4 games that didn't ship with iostore. Rarely viable on modern UE5 shipping builds. |
| **Official plugin / mod kit** | Game ships with editor + sanctioned mod path; user cooks their own paks via the dev's tooling. | Whatever the dev exposes. Can be deep (custom code + assets) or shallow (asset overrides only). | Dev-defined; often well-managed. | Best of any option, the dev maintains compatibility. | Dev-defined. | Excellent if the dev built a manager. | Lowest. Sanctioned. | ARK, Conan Exiles, Satisfactory's mod kit. |

## Capability comparison: pak vs DLL

The previous table compares *distribution shapes*. This one
compares what each shape can actually do at runtime. Pak
overrides cooked assets at load time. DLL runs native code in
the game process.

| Capability | Pak override | DLL (proxy or injected) | Notes |
| --- | --- | --- | --- |
| Change a numeric field on a CDO (int / float) | ✅ | ✅ | Trivially both. |
| Replace a texture, mesh, sound | ✅ | technically yes but awful | Pak's home turf. DLL would have to intercept the asset loader. |
| Add a new item, recipe, or data table row | ✅ | ✅ via reflection | Pak edits the cooked data table. DLL appends rows at runtime. Pak is more natural here. |
| Modify Blueprint *logic* (not just defaults) | ✅ but fragile | ✅ via ProcessEvent hook | Pak rewrites the Blueprint bytecode, breaks on most game patches and high conflict surface. DLL hooks the function call instead. Cleaner for stable behavior. |
| Hook a Blueprint or native function at runtime | ❌ | ✅ | Pak has no execution surface. This is the hard line: any "intercept what the game does" feature needs a DLL. |
| React to events (OnMouseWheel, OnInventoryChanged, save load) | ❌ unless via BP rewrite | ✅ | Pak can only react via Blueprint logic edits, which inherits the fragility above. DLL hooks the event source directly. |
| Read live game state (current player health, current inventory contents) | ❌ | ✅ | Pak only changes initial / template values. Reading the live world requires running code. |
| Call a Blueprint or native UE function on demand | ❌ | ✅ via ProcessEvent + reflected UFunction lookup | DLL only. |
| Add new UI elements at runtime | limited | ✅ | Pak can replace a UMG widget asset, but inserting a new widget that wasn't in the cooked tree is much harder. DLL can construct widgets in code. |
| Read a config file the user can edit without rebuilding | ❌ | ✅ | Paks bake everything at cook time. To "change a number" with a pak you swap the file. DLL can read JSON / TOML at load. This is the runtime-config gap. |
| Run logic that depends on the current game world / level | ❌ | ✅ | Pak's data is fixed at load. DLL runs every frame if it wants to. |
| Multiple users can install the mod without conflicting with other mods touching the same Blueprint / data table | ❌ | usually ✅ | Pak: two paks editing the same asset, last one loaded wins. DLL: each mod hooks its own functions; conflicts only when two mods hook the *same* slot, which is rare. |
| Survive a game patch that rebuilds the underlying asset | ❌ | usually ✅ | Pak overrides break whenever the cooked asset they target changes. DLL only breaks when the engine offset shifts, much rarer, much smaller fix. |

## Why ueforge targets UE4SS CPPMods specifically

- **DLL proxy is the right answer for any mod that needs more
  than CDO numeric overrides** (live game state reads,
  event hooks, runtime ImGui, settings hot-reload). The
  capability table above is unambiguous on this.
- **UE4SS specifically** is the right CPPMod host because:
  - It's already a DLL proxy (winhttp.dll). Our mod ships
    a single `main.dll` and UE4SS handles loader plumbing.
  - It exposes the UE reflection surface (UObject /
    UFunction / GObjects).
  - Vortex extensions for UE5 games converge on
    UE4SS-aware install paths within the first year of any
    game's mod scene; we ride on that.
  - The lifecycle hooks (`on_unreal_init` / `on_shutdown`
    / hot-reload via Ctrl+R) are stable and battle-tested
    across many games.
- **CPPMod over Lua mod** because we want native performance
  (zero-alloc hot paths) + we already have a Rust toolchain.
  Lua is fine for asset-overlay-style work; for low-level
  hooks Rust is cheaper.

## See also

- [lifecycle.md](lifecycle.md). The ueforge mod lifecycle
  (UE4SS factory exports, `on_unreal_init`, hot-reload).
- [ue-engine.md](ue-engine.md). UE5 engine reference (pak
  format, UObject layout, shipping-build constraints).
- [native.md](native.md). Why C++ is in the repo at all
  (UE4SS plugin ABI + ImGui).
