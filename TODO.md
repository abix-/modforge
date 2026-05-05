# TODO

Current state: UE4SS C++ mod loads cleanly in-game (2026-05-05).
Backpack + hunger/thirst patches working. Distribution path
through UE4SS / Vortex is settled.

**New direction (2026-05-05): turn this into an RPG / level-up
mod.** Inspired by Factorio's RPG-style level-up mods. Grounded 2
has no native leveling system, so we add one: kill enemies -> earn
XP -> level up -> spend points on upgrades that surface as our
existing CDO patches (backpack capacity, hunger/thirst rate, glide
speed, gear durability, etc.). The current "everything is a slider
in settings.json" model becomes the *output* of the level system,
not the user-facing knob.

## 0. RPG / level-up system (NEW HEADLINE FEATURE)

This is now the project. Items 3-7 below (gear durability, enemy
health/damage, glide speed, Player Tweaks ports) become *upgradeable
stat surfaces* that level skills drive, instead of independent
sliders.

### Vision

- Player kills enemies -> XP awarded based on enemy type / difficulty.
- XP threshold per level (curve TBD: linear, polynomial, etc.).
- On level-up, player gets N skill points.
- Spend skill points on upgrades. Each upgrade = a function of level
  applied to one of our existing CDO-patch surfaces:
  - Backpack capacity (40 base, +5 per rank, max rank 12 -> 100).
  - Hunger drain rate (1.0 base, -5%/rank, max rank 10 -> 0.5x).
  - Thirst drain rate (same shape).
  - Glide speed (1.0 base, +5%/rank).
  - Gear durability loss (1.0 base, -5%/rank).
  - Damage dealt by player (later -- needs more research).
  - Damage taken from enemies (later).
  - Stamina regen / sprint speed / swim speed (later, from Player
    Tweaks port queue).
- Persist XP / level / skill allocation per save slot.
- Show level / XP / next-skill in a UE4SS imgui tab (start). Later:
  in-world UMG overlay.

### Research answers (from SDK dump at C:\tools\work\sdk)

All six unknowns answered against the Dumper-7 SDK. File:line
citations are into `C:\tools\work\sdk\SDK\` unless noted.

**R1. Kill detection -- ANSWERED.**

Hook UFunction `Maine.HealthComponent.Kill` via ProcessEvent. It's
declared at `Maine_classes.hpp:42304` (`void Kill(bool bAllowHandleKnockOut)`)
and dispatched through ProcessEvent (`Maine_functions.cpp:138415`).

When fired:
- `this` (UObject*) = the `UHealthComponent` whose owner is dying.
- The dying actor is `this->GetOwner()` (UActorComponent's owner
  field; standard UE5 layout).
- Read `LastDamageInfo` at offset `0x3B0` on the HealthComponent
  (`Maine_classes.hpp:42287`). It's an `FDamageInfo` struct.
- `FDamageInfo.InstigatorController` at offset `0x20`
  (`Maine_structs.hpp:4815`, `TWeakObjectPtr<AController>`) tells
  us who fired the killing blow. Filter to local PlayerController.
- Bonus: `FDamageInfo.Tier` at `0x5C`, `FDamageInfo.OriginAttack`
  at `0x4C` -- usable for XP weighting.

OnDeath delegate (`Maine_classes.hpp:42224`,
`TMulticastInlineDelegate<void(const FDamageInfo&)>`) is
`BlueprintAssignable | BlueprintAuthorityOnly` -- fires on the
server only. Multiplayer: only the host gets kill events.
Acceptable; document and move on.

`UHealthComponent::ServerKill` (`Maine_functions.cpp:138724`) is
the multiplayer-replicated entry point. Hooking `Kill` covers
both single-player and host. Don't double-count -- pick one.

**R2. Enemy class hierarchy -- ANSWERED.**

Inheritance from `Maine_classes.hpp`:
- `ACharacter -> ASurvivalCharacter` (line 5713) -> `ASurvivalCreature`
  (line 6276) -> `ABP_SurvivalCreature_Base_C` and per-species
  blueprints (`ABP_Aphid_C`, `ABP_Spider_Tarantula_Boss_C`, etc).
- Players use the same `ASurvivalCharacter` base, but go through
  `ABP_SurvivalPlayerCharacter_C` -- NOT a subclass of
  `ASurvivalCreature`.

Filter: in the Kill hook, walk the dying actor's class chain. If
it's an `ASurvivalCreature` (or subclass) AND not the player's
character class, award XP. If it's a player, ignore (player
death). Buildings, props, etc. won't fire `HealthComponent.Kill`
the same way -- they have separate damage paths through
`ABuilding::GetHealthComponent` (`Maine_functions.cpp:5884`); we
only want creatures so this filter is correct.

XP weighting: read the dying creature's class name (FName via
`UObject::GetName`) and look up a per-species table (small JSON).
Fallback: use `FDamageInfo.Tier` or the creature's MaxHealth as a
proxy.

**R3. Persistence -- ANSWERED.**

Use `USaveLoadManager.SaveInProgressSaveGameHeaderData` (offset
0x90, `Maine_classes.hpp:1786`). It points to a
`USaveGameHeaderData` (line 42944) with these stable fields:
- `PlaythroughGuid` at `0x48` (`FGuid`, 16 bytes) -- STABLE across
  renames. Use as our filename key.
- `PlaythroughName` at `0xA8` (FString) -- display only.
- `SaveFolderName` at `0x198` (FString) -- the folder Obsidian
  uses; we don't need it.

Find the singleton via GObjects scan: walk for any UObject whose
class is `SaveLoadManager`. Cache the pointer; refresh on world
change.

Storage: `<DLL_dir>/saves/<playthrough-guid>.json`. Schema:
`{ level, xp, skill_ranks: { backpack: 5, hunger: 3, ... } }`.

If `SaveInProgressSaveGameHeaderData` is null (main menu, between
saves), defer load until it's populated. Hook
`USaveLoadManager.OnSaveBegin` (line 1787) and on load via the
existing `on_unreal_init` retry loop.

**R4. Live stat re-application -- ANSWERED.**

`UInventoryComponent.DefaultMaxSize` at offset `0x1E0`
(`Maine_classes.hpp:29557`) is a regular field on every instance,
not just the CDO. Patching the live player's
`InventoryComponent.DefaultMaxSize` directly on level-up changes
the cap immediately for that instance.

Live-instance access path:
```
UWorld::GetWorld()
  -> GameState->PlayerArray[i] (APlayerState*)
  -> PawnPrivate (APawn*) downcast to ABP_SurvivalPlayerCharacter_C*
  -> InventoryComponent (offset 0x13B8 on ASurvivalCharacter,
     line 5797)
  -> DefaultMaxSize (offset 0x1E0)
```

`UInventoryComponent::GetMaxSize()` (line 29635) is the public
read accessor; UI calls that, so writing `DefaultMaxSize` is the
right surface. There's also a per-instance `Items` array
(`TArray<UItem*>` at 0x1C8); the existing `WBP_InventoryInterface_C`
hook already handles viewport rebind for grow/shrink.

Other stats live the same way:
- Hunger / thirst rates: `SurvivalComponent` at offset 0x1448 on
  `ASurvivalCharacter` (line 5815). Existing patch works on CDO;
  swap to instance for level-up.
- Stamina: `StaminaComponent` at 0x1358 (line 5785).
- Max health (player buff skill): `HealthComponent.MaxHealth` at
  offset 0x328 on the live UHealthComponent (line 42263).

Approach: patch BOTH the CDO (so future spawns inherit) AND the
live player instance (so the current run sees it instantly). The
CDO patch is what we already do; add a parallel instance-walk
called from level-up.

**R5. UI -- ANSWERED. We piggyback on UE4SS's existing debug GUI;
we do NOT build a new window.**

UE4SS already ships an ImGui-based debug overlay with built-in
tabs for Console, LiveView, Dumpers, LuaDebugger, Profilers,
SearcherWidget, UFunctionCallerWidget, BPMods (see
`RE-UE4SS/UE4SS/include/GUI/`). Toggle hotkey defaults to the
UE4SS console key (`Insert` per UE4SS-settings.ini).

`register_tab(name, lambda)` adds OUR tab as a peer to those
built-in tabs in the same overlay window. Same window, same
toggle, same ImGui context. From the user's perspective they
press one key and see "Console / LiveView / Dumpers / ... / RPG"
across the top -- our tab is just one of them.

We can NOT extend UE4SS's built-in tabs (their rendering lives
inside UE4SS.dll and isn't exposed). What we have is: register a
new tab next to them. That's the right shape -- the RPG tab is
a distinct view (level / XP / skill grid), not something that
fits under "Live View" or "Dumpers".

Reference implementation:
`RE-UE4SS/CppMods/EventViewerMod/src/EventViewer.cpp:22`:
```cpp
register_tab(STR("RPG"), [](CppUserModBase* mod) {
    UE4SS_ENABLE_IMGUI();
    ImGui::Text("Level: %d", state.level);
    ImGui::ProgressBar(state.xp_ratio);
    if (ImGui::Button("Spend skill")) { rust_spend_skill(...); }
});
```

Plan: keep ImGui rendering in C++ shim. Expose Rust state via
narrow C-ABI getters/setters
(`get_player_state(out_buf, len)`, `spend_skill(skill_id)`, etc.)
so the lambda doesn't need to know Rust types. Avoids dragging
imgui through cxx-style FFI.

In-world UMG overlay (a HUD widget visible without summoning the
UE4SS overlay): deferred. Out of scope for v1.

**R6. XP curve + skill economy (design, no code answer needed).**

Placeholder values until in-game tuning:
- Levels 1-50, quadratic XP curve: level N requires
  `100 * N^1.8` total XP.
- 1 skill point per level.
- Each skill maxes at rank 10.
- Respec: free for now; `settings.json` flag `respec_cost: 0`.
- Per-creature XP: aphid=5, weevil=10, spider=50, boss=500
  (placeholders; tune by playing).

### Architecture sketch (post-research)

Modules (Rust side, all in `better-backpack/src/`):
```
rpg/
  mod.rs            entry: glue init, level-up event loop
  xp.rs             XP awarding, level threshold table, on_kill
  skills.rs          skill catalog, rank -> stat-multiplier function
  state.rs          struct PlayerState { level, xp, skill_ranks }
                    serde, load/save to <DLL_dir>/saves/<slot>.json
  ui.rs             UE4SS imgui tab wiring (level/XP/skills)
  events.rs         hooks: enemy-death ProcessEvent hook,
                    player-load detection
```

Existing modules (`survival.rs`, `inv_hook.rs`, the future
`combat.rs`, `gear.rs`, `movement.rs`) become **stat surfaces**
driven by `skills.rs::current_multipliers(state)`.

Lifecycle:
1. `on_unreal_init`: load PlayerState from disk (key = save slot).
   Apply current multipliers to all CDOs.
2. Install ProcessEvent hook on enemy-death UFunction.
3. On kill: award XP to PlayerState, check threshold, on level-up
   bump skill-points.
4. On skill allocation (UI click): update PlayerState, recompute
   multipliers, re-apply CDO patches, save to disk.
5. On exit / save event: flush PlayerState to disk.

### Build sequence

R1-R5 answered (see above). Each spike below is a concrete
implementation against known field offsets and UFunction names,
not exploratory.

- [x] **Eager state load on world entry DONE (2026-05-05).**
  New `rpg/world_loader.rs` spawns a 1Hz poller from worker
  init that watches `save_slot::current_slot_key()` and drives
  three transitions on the tracker:
    - `None -> Some(s)`: `tracker::activate_slot(s)` (loads
      PlayerState from disk).
    - `Some(a) -> Some(b)` where a != b (player swapped saves
      via main menu): deactivate then activate the new slot.
    - `Some(s) -> None`: deactivate (state already on disk via
      per-kill flush).

  `tracker.rs` was refactored: kill recording no longer
  lazy-resolves the slot; if no slot is bound it logs and
  drops (shouldn't happen in practice since the loader
  activates within 1s of world entry, before the player can
  enter combat).

  `state.rs::load_for_current_slot` collapsed to
  `state::load_one(slot)` -- the loader now owns slot
  resolution; state.rs is just file I/O.

  Future skill-driven CDO/instance reapply hooks into the same
  activation transition: when activate_slot fires, run the
  apply step using the freshly loaded PlayerState's skill
  ranks. Stub for now since skills don't exist yet.

- [x] **Kill attribution + XP math layer DONE (2026-05-05).**
  Attribution confirmed in-game: PLAYER bucket fired correctly
  on Grub kills via `BP_SurvivalPlayerController_Augusta_C`,
  BUGGY bucket fired correctly on Spiderling kill via
  `AIC_AntSoldier_Augusta_Buggy_C`. No false positives observed.
  Three buckets implemented in `kill_hook.rs::classify`:
  - Player: instigator class chain contains "PlayerController".
  - Buggy: instigator (or its possessed Pawn at +0x308) class
    chain contains "Buggy".
  - Other: enemy AIC; logged as skipped, no kill_count bump.

  `rpg/xp.rs` introduced: `100 * N^1.8` cumulative XP curve,
  level cap 50, per-creature XP table (~20 species,
  placeholders -- aphid 5, weevil 15, spider 75, boss 750).

  PlayerState bumped: `xp`, `level`, `skill_points`,
  `skill_ranks: BTreeMap<String, u32>`. Old fields
  (`kill_count`, `last_killed`) retained as diagnostics. All
  new fields use `#[serde(default)]` so existing save files
  load fine.

  `tracker::record_kill` takes `KillSource`, applies
  `rpg.buggy_kill_xp_multiplier` (settings, default 1.0) to
  Buggy-source kills, awards XP, recomputes level, grants skill
  points on level-up.

  In-game test pending. Open question: are AICs that hostile
  bugs use to attack each other classified correctly? Initial
  filter is heuristic (class-name "Buggy"); may need tuning if
  vanilla AIC class names overlap. (In Grounded 2, the
  player's tame mounts are called Buggies.) First Spike B
  in-game test surfaced: when the player's Buggy killed a
  Larva, we credited the kill via the Buggy's AIController
  (`AIC_AntSoldier_Augusta_Buggy_C`). That IS the player's kill
  but Spike A's current filter is "any creature death where the
  InstigatorController is non-null" with no ownership check.

  Real XP rules need three buckets, not two:
  - **Direct player kill** (InstigatorController is local
    PlayerController): full XP.
  - **Buggy kill** (InstigatorController is an AIC whose
    possessed Pawn is the player's Buggy): configurable
    fraction, default 1.0 (100%) per user request. Knob lives
    in `settings.json` under `rpg.buggy_kill_xp_multiplier`.
  - **Enemy-vs-enemy** (some other AIC, no player relationship):
    no XP. Don't even count toward kill_count.

  Detection sketch (research needed in the SDK before coding):
  - From InstigatorController, walk to its possessed Pawn.
  - Check the Pawn for "is tame" -- likely
    `ASurvivalCreature.bInfused` (line 5856) is the wrong flag,
    look at `IsTame()` (line 6313) and `UTameableComponent`
    (5808) / `UPetMasterComponent` (5809).
  - Cross-reference owner against the local
    `BP_SurvivalPlayerCharacter_C`'s `PetMasterComponent` to
    confirm the Buggy belongs to *us*, not another player's
    Buggy in co-op.

  Out of scope for Spike B. Pick up before the XP loop lands.

- [x] **Spike A DONE (2026-05-05).** Option A worked first try.
  Hook on HealthComponent matches
  `MulticastHandleEffectsWithDamageFlags`, reads `DamageFlags`
  parm at offset 0x1C, masks with `EDamageInfoFlags::KillingBlow
  = 2`. On kill: filters to `ASurvivalCreature` subclasses,
  reads `LastDamageInfo.InstigatorController` (FWeakObjectPtr)
  and resolves via GObjects. In-game test: killed a Grub,
  produced one clean line:

  ```
  rpg/kill: BP_Grub_C_2147385918 (BP_Grub_C) killed by
  BP_SurvivalPlayerController_Augusta_C_2147481445
  (BP_SurvivalPlayerController_Augusta_C)
  ```

  Dying actor + class + killer + killer-class. That's the full
  XP source signal. ~80 lines in `better-backpack/src/rpg/kill_hook.rs`.

- [x] Spike A attempt 1 (2026-05-05): hooked
  `Maine.HealthComponent.Kill` via existing per-vtable
  ProcessEvent infra. **Did not fire on enemy deaths.**
  Diagnostic log of every PE call seen on HealthComponent during
  a Weevil kill showed only: `OnStatusEffectChanged`,
  `MulticastHandleEffectsWithDamageFlags`, `OnCombatChanged`. No
  Kill, no OnDeath, no death-shaped event.

  Two reasons:

  1. `UHealthComponent::Kill` is `Final|Native`. The engine calls
     the C++ method directly. The SDK wrapper at
     `Maine_functions.cpp:138415` *does* go through ProcessEvent
     (it's how user code invokes Kill from BP/Lua), but the
     engine's internal damage path bypasses that wrapper.

  2. The `OnDeath` multicast delegate (`Maine_classes.hpp:42224`)
     IS broadcast on death, but its bindings are BP functions
     named `BndEvt__<EnemyClass>_HealthComponent_..._DeathDelegate__DelegateSignature`
     -- one per enemy class. Those PE-dispatch on the **enemy's**
     vtable (`ABP_Aphid_C`, `ABP_Weevil_C`, etc.), NOT on
     HealthComponent's vtable. Our per-vtable hook on
     HealthComponent can't see them.

  Per-vtable hooking is fundamentally wrong for this signal:
  every enemy subclass has its own vtable, so we'd need a hook
  per species (~50+ subclasses).

- [ ] Spike A attempt 2: pick one of three options below. Order
  by leverage, top to bottom.

  ### Option A: read DamageFlags from existing hook (recommended)

  `MulticastHandleEffectsWithDamageFlags` already fires through
  our existing per-vtable HealthComponent hook on every damage
  hit (confirmed in 2026-05-05 log). It carries a `DamageFlags:
  int32` parm (`Maine_parameters.hpp:46227`). UE survival games
  typically expose a `EDamageFlag::KillingBlow` bit set when the
  hit is lethal.

  **5-minute test**: grep `C:\tools\work\sdk\SDK\` for
  `EDamageFlag` / `DamageFlags` constants. If a "killing blow"
  bit exists, the spike is done with zero architectural change.
  Read parms[2] from the existing hook, mask the bit, log only
  on death.

  Cost if it works: ~10 lines. Cost if it doesn't: 5 min.
  Decision criterion: any flag enum that names something like
  Killing/Lethal/Death/Fatal qualifies; missing -> fall through
  to Option B.

  ### Option B: global ProcessEvent hook

  Right architecture long-term. Detour the engine's PE function
  pointer once at startup, filter in the trampoline by function
  name pattern (`*Death*`, `*DeathDelegate*`).

  Two implementation sub-options:

  - (a) Roll our own detour. ~150 lines of asm-aware code in
    `hook/`. Full ownership.
  - (b) Piggyback on UE4SS's existing global PE hook via
    `RegisterProcessEvent[Pre|Post]Callback` in
    `RE-UE4SS/UE4SS/include/Unreal/Hooks.hpp`. C++ shim
    registers a callback that calls into a Rust extern. ~20
    lines of shim, no new Rust hook plumbing. Hard dependency
    on UE4SS internals -- fine because we're already a UE4SS
    C++ mod.

  Pick (b). Right answer for any future PE-only signal we want
  (player level-up, item crafted, dialog finished, etc.) so it's
  an investment we'd make anyway.

  ### Option C: defer kill detection, advance Spike B or C

  Build persistence (Spike B) or live stat re-apply (Spike C)
  first; stub the XP source with a debug imgui button "Give 100
  XP". Lower leverage: we'd be building plumbing without an
  end-to-end testable loop. Also weaker information about what
  state we need to persist (per-kill timestamps for streaks?
  per-species kill counts?). Skip unless A and B both blow up.

  ### Why A first

  SDK already on disk. If the flag exists, we're unblocked in 10
  minutes and can move to Spike B+C immediately. If it doesn't,
  we move to Option B with a confirmed reason -- not guessing.
- [ ] **Future infra: global ProcessEvent hook (Option B,
  retained).** Spike A unblocked us via Option A, but Option B
  is still the right long-term investment. Reasons:

  - **Future signals.** Every other PE-only event we'll want
    later (player level-up confirm, item crafted, recipe
    learned, dialog start/end, save fired, world stream-in)
    needs the same pattern: catch a UFunction call across many
    classes. Per-vtable hooking forces us to enumerate every
    subclass. Global hook + name filter is the canonical UE
    instrumentation pattern.
  - **Lower friction for future work.** When we want a new
    signal, it's `if function.name() == "FooEvent" { ... }`,
    not "find the right class to hook and pray its vtable
    catches all instances."
  - **Already a UE4SS dep.** We're a CPPMod. Pulling in
    `RC::Unreal::Hook::RegisterProcessEvent[Pre|Post]Callback`
    (`RE-UE4SS/UE4SS/include/Unreal/Hooks.hpp`) doesn't add a
    new dependency surface.

  Plan: ~20-line addition to the C++ shim that registers a Pre
  callback and forwards `(this, function, parms)` into a Rust
  extern. Rust side: a tiny dispatch registry (HashMap<UFunction*,
  Box<dyn Fn>>). Replace `kill_hook.rs`'s per-vtable
  ProcessEventHook with a registry entry. Existing `inv_hook.rs`
  can stay on per-vtable -- it's class-specific by design (only
  `WBP_InventoryInterface_C` matters).

  Not blocking anything right now; pick up after Spike B + C
  land and we have multiple PE-only signals to multiplex.

- [ ] Spike B: persistence. Find `USaveLoadManager` in GObjects,
  read `SaveInProgressSaveGameHeaderData->PlaythroughGuid`,
  write/read a JSON file at `<DLL_dir>/saves/<guid>.json`. Handle
  null (main menu) gracefully. **One evening.**
- [ ] Spike C: live stat re-apply. Walk
  `World->GameState->PlayerArray[i]->PawnPrivate->InventoryComponent`,
  bump `DefaultMaxSize` at runtime, confirm the inventory UI
  updates without a save reload. **One evening.**
- [ ] Once A+B+C green: write `state.rs`, `xp.rs`, `skills.rs`
  with the placeholder curve from R6. Wire enemy-kill -> XP
  award -> level threshold -> skill-point grant.
- [ ] UE4SS imgui tab. Add `register_tab(STR("RPG"), ...)` in
  the C++ shim ctor (model:
  `RE-UE4SS/CppMods/EventViewerMod/src/EventViewer.cpp:22`).
  Lambda reads Rust state via C-ABI getters, renders ImGui,
  posts skill-spend via setters.
- [ ] Tune XP curve and skill economy through actual play.
- [ ] Polish: respec, settings.json overrides for the curve,
  per-enemy XP table loaded from JSON.

### What we keep from the old direction

The "stat surfaces" sections below (#3-7) are still the right
implementations -- we just don't ship them as user-facing sliders.
They become the math behind skills. Sequence:
- Get gear durability (#3) and enemy health (#4) found in the SDK
  during R2 anyway, since those CDOs live on the same enemy tree.
- Glide speed (#6) is a pure player-stat, bundled with backpack
  capacity for the player-side skills.

The settings.json schema flips inside out: instead of
`{ "thirst_multiplier": 0.5 }`, we have
`{ "rpg": { "starting_level": 1, "xp_curve": "quadratic" } }`,
and per-skill live values are in `<save-slot>.json`, not user
settings.

## 1. Repackage as a UE4SS CPPMod

Why: see `UE4SS_PORT_PLAN.md` (steelman in 11 points). Short
version: UE4SS is the convention for UE5 game mods, distribution
via Vortex is already solved on that path (UE4SS for Grounded 2 is
Vortex mod #52), and we delete our winhttp proxy forwarders +
setup.ps1 + winhttp_orig.dll dance.

Source language stays Rust. UE4SS's CPPMod ABI is C++ inheritance,
so we add a ~30-line C++ shim that derives from
`RC::CppUserModBase` and forwards lifecycle calls to two
`extern "C"` Rust functions. Mod logic stays Rust.

Earlier drafts of this plan claimed there was a "legacy free-function
CPPMod ABI" we could use to stay 100% Rust. There isn't. The
inheritance ABI is the only path. The 30 lines of C++ are loader
handshake -- they don't compete with the 1500+ lines of Rust mod
logic for any meaningful property.

Sequence (full detail in `UE4SS_PORT_PLAN.md`):

- [x] Step 1: Clone RE-UE4SS to `C:\code\RE-UE4SS` for headers.
  (Submodule attempt blocked by upstream's broken UEPseudo
  reference.)
- [ ] Step 2: Generate `UE4SS.lib` import library from the user's
  installed `UE4SS.dll` via `dumpbin /exports` -> `.def` ->
  `lib /def:`. Verified the DLL exports the symbols we need
  (`??0CppUserModBase@RC@@QEAA@XZ`, virtual destructor, all base
  virtuals).
- [ ] Step 3: Add the C++ shim source. Extend `build.rs` to compile
  it via `cc::Build` against the headers in `C:\code\RE-UE4SS` and
  link against `UE4SS.lib`. Drop the winhttp forwarder generation.
- [ ] Step 4: Rename cdylib output from `winhttp` to `main`. Add
  two `#[no_mangle] extern "C"` Rust entry points
  (`better_backpack_start`, `better_backpack_stop`). Move worker
  startup out of `DllMain` into `better_backpack_start`. Drop
  `wait_for_gobjects` -- UE4SS calls our `on_unreal_init` after
  the engine has finished initializing.
- [ ] Step 5: Rewrite `deploy.ps1` for the UE4SS mod folder layout.
  Default mode produces a zip mirroring
  `Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/`.
- [ ] Step 6: Update `BUILDING.md`, `README.md`, `FEATURES.md`,
  `PERFORMANCE.md` to reflect the UE4SS load model.
- [x] Step 7: In-game smoke test under UE4SS. **Working as of
  2026-05-05.** start_mod returns valid instance, on_unreal_init
  fires, Rust side takes over.
- [ ] Step 8: Archive the winhttp proxy material to
  `archive/winhttp-proxy/`. Keep it as a tested fallback in case
  UE4SS turns out unstable for Grounded 2.

The current winhttp.dll proxy work (already shipped, commits
514e2b1..bfb3447) is **not wasted**: it's the tested fallback.
Archive, not delete.

## 2. Rename the project

`better-backpack` no longer describes what we're building. The new
direction is an RPG / level-up mod (see #0). Pick a name that
reflects "kill stuff -> level up -> skills".

Candidates to consider (final pick TBD):
- `grounded-rpg` -- explicit about the game and the mechanic.
- `g2-rpg` -- short.
- `groundlevel` -- pun: ground level + leveling up.
- `bug-hunter` / `huntmaster` -- emphasizes combat/kills.
- `instar` -- the bug term for a developmental stage between molts;
  thematic with Grounded's "you-are-tiny" framing and matches the
  level-up loop. Niche but fitting.
- `groundwork` -- pun on Grounded, generic enough to cover future
  scope creep.

Old "everything is a slider" candidates archived for context:
~~g2-sandbox, g2-tweaks, grounded2-tweaks, bigger-better~~.

When the rename happens, update:
- Repo name (rename on GitHub, update remote in local clones).
- Crate package name (`Cargo.toml` -> `[package] name`).
- Workspace member dir (`better-backpack/` -> new name).
- Settings file is fine to keep as `settings.json` (next to the DLL).
- Branding strings inside the DLL (`ModName`, console title, log
  header).
- All docs (README, BUILDING, FEATURES, PERFORMANCE, TODO,
  UE4SS_PORT_PLAN, project_state).

## 3. Gear durability tweak

User-facing: a multiplier on how fast equipped gear takes damage from
use. Same shape as the existing thirst / hunger multipliers. Default
0.5 means gear lasts twice as long; 0.0 means gear never breaks.

Lives in `settings.json`:

```json
{
  "survival": {
    "gear_durability_multiplier": 0.5
  }
}
```

Implementation outline:

- Find the relevant CDO field. Search Dumper-7 SDK for "Durability",
  "DurabilityRate", "DurabilityLoss", "WearRate" or similar floats on
  weapon / tool / armor item classes. Likely one of:
  - `UItemComponent` or `UEquipableComponent` with a per-second wear
    rate
  - A multiplier on attack/use that decrements item durability
  - Something in a survival or crafting subsystem
- If the field is a single float on a base class, patch it the same
  way `survival.rs` patches `ThirstSettings.AdjustmentPerSecond`.
- If it's a per-item-type table (each weapon defining its own rate),
  walk every CDO that has the field and apply the multiplier.
- Add a `gear.rs` module mirroring `survival.rs`. Plumb the new
  multiplier through `settings.rs`.

Open question: does the game even use a per-second decay model, or
is durability purely per-use (each swing, each block)? If per-use,
we may need to scale the per-action damage instead of a per-second
rate.

## 4. Enemy health multiplier

User-facing: scale the max health of every enemy in the world.
Default 1.0 = vanilla; 0.5 = half-health (faster kills); 2.0 =
twice as tanky (harder fights). Settings.json key:

```json
{
  "combat": {
    "enemy_health_multiplier": 1.0
  }
}
```

Implementation outline:

- Find the health-component CDO field. Search Dumper-7 SDK for
  "Health", "MaxHealth" floats on enemy character base classes.
  Likely candidates:
  - A `UHealthComponent` or `UDamageComponent` on
    `BP_SurvivalNonPlayerCharacter` (or similar enemy base).
  - `MaxHealth` directly on the character class.
  - A health curve indexed by level.
- Critical decision: scale `MaxHealth` *only*, or also scale
  `CurrentHealth` to keep ratio? Game probably initializes
  `CurrentHealth = MaxHealth` at spawn, so patching CDO's MaxHealth
  is enough for newly-spawned enemies.
- Player must be excluded. Use the same pattern as `patch.rs`'s
  player-only filter: walk only CDOs whose full name does NOT
  contain `BP_SurvivalPlayerCharacter`.
- Add `combat.rs` module. Plumb through `settings.rs`.

Open questions:
- Does enemy health replicate from server? In multiplayer this only
  takes effect for hosts (same caveat as hunger/thirst).
- Does the game scale enemy health by player level / progression? If
  so, our static multiplier interacts non-linearly. May need to
  document or tune.

## 5. Enemy damage multiplier

User-facing: scale how much damage enemies deal to the player.
Default 1.0 = vanilla; 0.5 = enemies hit half as hard (forgiving);
2.0 = enemies hit twice as hard (challenge run). Settings.json key:

```json
{
  "combat": {
    "enemy_damage_multiplier": 1.0
  }
}
```

Implementation outline:

- Find the damage source. Likely candidates:
  - A per-enemy `BaseDamage` or `AttackDamage` float on attack
    components (one per attack type).
  - A per-attack-spec field on attack data tables.
  - A global damage multiplier in a survival config.
- The most surgical approach is a *per-enemy* attack-component CDO
  patch -- walk enemies, find their attack-component CDO, multiply
  the damage field. Keeps player attacks untouched.
- Add to `combat.rs` (same module as enemy health from item #4 -- they
  scan the same CDO tree).

Open questions:
- Some attacks compute damage via the gameplay-ability system rather
  than a static field. Those may need a different approach (e.g.
  hooking the damage application function via ProcessEvent).
- Attribute-vs-flat: most UE games store base damage as a float and
  apply multipliers from buffs / level. Patching base only is the
  cleanest -- multipliers stay vanilla.

## 6. Flying / gliding speed

User-facing: scale how fast the player moves while gliding (the
dandelion / leaf glider mechanic in Grounded 2). Default 1.0 = vanilla;
higher = faster flight; lower = slower. Settings.json key:

```json
{
  "movement": {
    "glide_speed_multiplier": 1.0
  }
}
```

Implementation outline:

- Caites' Player Tweaks already touches `MaxFlySpeed` (1600 -> 1900),
  so the field exists and is reachable. Find it in the SDK:
  - Search Dumper-7 dump for "FlySpeed", "MaxFlySpeed", "GlideSpeed",
    "AirSpeed".
  - Likely on a `UCharacterMovementComponent` subclass owned by the
    player character, OR on a glider-specific component.
- Apply multiplier the same way as the existing patches: walk player
  CDOs, multiply the field, log before/after.
- May need to also touch acceleration / velocity caps if the visible
  effect is gated by something other than the raw speed.
- Add a `movement.rs` module. Plumb through `settings.rs`.

If the field is the same one Caites uses (sprint / walk / swim live
on the same component), tackle this together with the other movement
multipliers from #6 below to avoid scanning the same CDOs twice.

## 7. (later) Port more Player Tweaks features

See `FEATURES.md` for the comparison table and the prioritized list.
Quick wins identified: stamina regen, sprint/walk/swim speed, hauling
stack size, death delay. Each is the same shape as the existing
hunger/thirst patch -- find the offset in the SDK, add a section to
`settings.json`, write a 50-line module. Order them by user demand.

## Out of scope (kept for context)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport. Working.
- Multiplayer correctness for hunger/thirst. Stats almost certainly
  replicate server-authoritatively, so non-host clients won't see the
  effect. Document, don't fight.

## Done

- UE4SS C++ mod load works (2026-05-05). Crash on load was a vtable
  mismatch in `cpp/shim.cpp`'s `RC::CppUserModBase` mirror -- six
  virtuals missing vs upstream header (`on_ui_init`, four `Lua*`
  overloads of `on_lua_start`/`on_lua_stop`, `on_cpp_mods_loaded`).
  UE4SS dispatched past our vtable into garbage. Fixed by mirroring
  the header virtual list verbatim. `on_cpp_mods_loaded` is NOT
  marked `RC_UE4SS_API` because UE4SS.lib doesn't export it; using
  the local inline body works.
- Rust port of the mod (RUST_PORT_PLAN.md steps 1-8, 11).
- Backpack capacity patch -> 100 slots (settings-driven), validated
  in-game.
- `WBP_InventoryInterface_C` ProcessEvent hook + viewport rebind.
- Mouse-wheel scrolling preserves absolute slot positions (empty slots
  stay empty, no upward compaction).
- Worker thread terminates after init -- no recurring overhead.
- `inject.exe` writes its own log, exits without pausing.
- `inject.exe` auto-launches the game via Steam (or fallback exe) when
  it's not already running, then polls until the process appears, then
  injects. `--no-launch` to opt out. Configured via `inject.json` next
  to inject.exe (`inject.example.json` is the schema). Default Steam
  app id: `3104110`.
- `settings.json` next to the DLL controls slot count + thirst/hunger
  multipliers. `better-backpack/settings.example.json` is the schema.
  Defaults: slot_count=100, thirst/hunger multipliers=0.5.
- Hunger and thirst rate patch via `survival.rs` -- patches every
  SurvivalComponent CDO's `HungerSettings.AdjustmentPerSecond` and
  `ThirstSettings.AdjustmentPerSecond` floats by the configured
  multipliers.
- DLL log file moved from `%TEMP%\BetterBackpack.log` to
  `<DLL_dir>\better_backpack.log`. Both binaries now log next to
  themselves.
- `AllocConsole` gated behind a Cargo `console` feature. Default-on so
  development still gets the live window; `cargo build --release
  --no-default-features` produces a console-free shipping build.
- `BUILDING.md` + `PERFORMANCE.md` at repo root.
- ProcessEvent hot path is mutex-free: REGISTRY snapshot is published as
  a leaked `&'static [&'static Entry]` via `AtomicPtr`, trampoline does
  one atomic load + slice scan. `in_synthetic_refresh` is `AtomicBool`.
