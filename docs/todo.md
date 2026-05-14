# TODO

!!! info "Scope"
    Authoritative on open work across the workspace. What's NEXT,
    not what's done. Completed milestones live in
    [`changelog.md`](changelog.md). Per-subject deep dives live in
    each crate's `docs/` folder ([`../ueforge/docs/`](../ueforge/docs/)
    for the framework, [`../grounded2-mod/docs/`](../grounded2-mod/docs/)
    for the Grounded 2 mod). Read those FIRST when investigating a
    subject.

!!! tip "How to use"
    Roughly ordered by leverage. Pick from the top of the list when
    starting a new session.

---

## Next up (2026-05-14+)

WWM put down for now. Demo-end blocked successfully;
the rest of the in-flight WWM work is captured below.
Pick up another front (Endless / ueforge / Outworld)
in the next session unless the user redirects.

0. **~~Unblock the user's demo-end stall~~** SOLVED
   2026-05-14 attempt 7. Harmony prefix returning false
   on `TutorialManager.CompleteDemo` +
   `CompleteDemoCoroutine`. Lives in
   `unityforge/cs-shim-mono/Plugin.cs`
   `InstallDemoCompleteBlock`. Full lessons doc in
   [`wild-west-miner-research.md` §7.7](wild-west-miner-research.md#77-demo-end-block-2026-05-14-solved-on-attempt-7).
   Methodology takeaway: `list_methods` against the
   most-obvious manager class as the FIRST move, not the
   last.

0b. **~~Plot Enlargement / Land Surveyor "buy" feature~~**
    INVESTIGATED 2026-05-14, NOT PURSUING. The Bank's
    Land Surveyor board (`Bank / .../ WoodenBoard /
    PlotOffer{,(1),(2),(3)}`) is a demo-cut feature.
    Visual assets shipped (4 PlotOffer GameObjects with
    labels + prices), but ZERO managed code references
    them across ANY DLL in `Managed/`. Not wired into
    the game's `BuyPopup` / `BuySection` system either.
    Making it work would mean writing the
    `PlotPurchase` MonoBehaviour from scratch + deciding
    what "unlock a plot" means (no reference behavior
    in the demo to copy). Content development, not
    modding. Full evidence in
    [`wild-west-miner-research.md` §7.8](wild-west-miner-research.md#78-plot-enlargement--land-surveyor-search-2026-05-14-partial).

0a. **Fix the silently broken Harmony bridge in
    `cs-shim-common/HarmonyBridge.cs`.** PatchPrefix +
    PatchPostfix both construct the Harmony target from
    `new Action(() => del(...))`. An instance-method
    lambda which HarmonyLib rejects. Every Rust-side
    `patch_prefix` / `patch_postfix` call in the workspace
    has been silently failing for the whole session
    (`DigManager.Dig` and `PlayerManager.AddPlayerCurrency`
    postfixes wwm-mod relies on for XP also never fire).
    Replace with a static dispatcher keyed by patch
    handle. Until this lands, Rust-side Harmony patching
    does nothing.
1. **Verify the hot-reload cycle works in-game.** Launch
   WWM, observe `Unityforge.Shim: ready (generation 0)`,
   then run `build_and_deploy.ps1 -Hot` from a separate
   terminal, watch BepInEx log for `hot reload generation
   0 -> 1`. Confirm curl ops still answer after the swap.
   If it works, mark Phase 4 verified in
   [§6.5](unityforge-plan.md#65-hot-reload-phase-4).
2. **Fix the janky jump.** The current `Translate(0,3,0) +
   isGrounded=false` is unreliable. Investigate
   `PlayerController` per-frame movement to find what
   clobbers our position/velocity. Likely needs a Harmony
   prefix on the per-frame movement method to inject a
   jump-velocity boost.
3. **Ship `UnitySkillProxyEffect`** + repoint Strong Back
   at `SkillsManager.SetSkillLevel("Bag", N)`. The game
   already grows the slot list when you call this. A way
   bigger payoff than fighting raw fields. Verified live
   in the 2026-05-13 session (5 -> 12 slots).
4. **Verify Greedy Miner in-save.** Load a save in WWM,
   `walk_class MineDataSO` to confirm field names. Repoint
   the catalog if needed.
5. **Mirror generation-loader into IL2CPP shim** before
   shipping the IL2CPP smoke target end-to-end.
6. **horsey-mod: `sleep_safe_no_tire` patch site
   discovery.** wip in [`a31246f`](.). The patch infra
   works (VirtualProtect / write / FlushInstructionCache /
   revert on detach), but `find_patch_site` cannot
   uniquely identify the `+0x206` zero-store inside the
   no_tire loop at `FUN_1400ceb60`. Three iterations
   tried (RAX-only, all-regs / 2 candidates, proximity
   to `+0x205` sibling within 64 bytes); none uniquely
   match. Next idea: walk back from the
   `DAT_1403d95c5` read inside the function and pick
   the FIRST `+0x206` zero-store that follows it. If
   that also ambiguates, fall back to a hand-disassembled
   offset baked into a per-build constant. Until this
   lands, the split-flag suppressor (zero `+0x205` from a
   Rust worker thread) is the shipping path.

The detailed checkboxes below cover everything else, but
those five are the immediate path forward.

---

## Naming standardization: `<game>-mod`

User direction 2026-05-14: per-game mod crates standardize
on `<game>-mod`. Boring, consistent, future-proof. Renames
to land in one commit per crate so it bisects clean.

| Current                     | New                       | Status |
|-----------------------------|---------------------------|--------|
| `grounded2-rpg`             | `grounded2-mod`           | DONE   |
| `wwm-rpg`                   | `wwm-mod`                 | DONE   |
| `outworld-station-tweaks`   | `outworld-station-mod`    | DONE   |
| `horseyforge`               | `horsey-mod`              | DONE   |

`il2cpp-smoke` is a smoke target, not a per-game mod.
Name unchanged.

Open call: keep RPG-shape advertised in the name?
Default is the pure `<game>-mod` form above. The alternative
`<game>-mod-rpg` is on the table if losing the RPG hint
hurts readability. Decide before the rename starts.

What touches:
- Directory rename for each crate.
- Workspace `Cargo.toml` member list.
- Each crate's `[package].name` and `[lib].name` (Rust
  identifier flips from e.g. `grounded2_rpg` to
  `grounded2_mod`).
- `[package.metadata.ueforge]` (deploy paths, log
  filenames, mod name registered in `mods.txt`). Deployed
  log file changes from `grounded2_rpg.log` to
  `grounded2_mod.log` etc; old DLLs in user installs need
  a one-shot uninstall step or a documented manual
  cleanup.
- Every `use grounded2_rpg::` / `use wwm_rpg::` site
  (tests + scripts).
- Sweep workspace docs (`README.md`, `docs/changelog.md`,
  `docs/todo.md`, `docs/wild-west-miner-research.md`).
- Each renamed crate's own `docs/` and `README.md`.
- `.claude/project_state.md` (gitignored, but kept in sync).
- `~/.claude/skills/grounded2/SKILL.md` references
  `grounded2-rpg`; update there too. Same for any other
  skill files that name the old crates.
- PowerShell scripts (`wwm-rpg/scripts/build_and_deploy.ps1`
  becomes `wwm-mod/scripts/build_and_deploy.ps1`).
- Horseygame docs reference deployed `horseyforge.dll` /
  `horseyforge-inject.exe` / `horseyforge.log` /
  `horseyforge.injstate`; those become `horsey.dll` /
  `horsey-inject.exe` / `horsey.log` / `horsey.injstate`.
- GitHub Actions / CI YAML if any (none today; check
  before assuming).

Order: do `horseyforge` last, since the binary rename
churns the user-visible deploy artifacts the most. Start
with `outworld-station-tweaks -> outworld-station-mod`
(smallest blast radius) to validate the rename pattern.

---

## Future: absorb the C# mod repos (Timberbot + Schedule 1)

User direction 2026-05-14: this repo is the home for ALL
game modding. The two outstanding C# repos eventually move
in:

- [`abix-/TimberbornMods`](https://github.com/abix-/TimberbornMods).
  Timberborn (Unity, IL2CPP). C# with Bindito DI +
  publicizer + Timberbot. Sister Python client.
- [`abix-/Schedule1Mods`](https://github.com/abix-/Schedule1Mods).
  Schedule 1 (Unity, IL2CPP). C# with MelonLoader +
  Harmony + Il2CppInterop.

This is a bigger lift than the horseygame subtree-merge
because the Rust forge model doesn't fit C#-only mods
end-to-end:
- Cargo workspace can't host C# projects directly. Either
  the C# stays in `<game>-mod/csharp/*.csproj` outside the
  workspace manifest with a separate build script, or we
  add a top-level `dotnet/` directory next to the Rust
  crates with its own `.sln`.
- The IL2CPP forge path (`unityforge` + Il2CppInterop) is
  the natural Rust analogue, but Timberbot + Schedule 1
  already use mature C# stacks (Bindito / MelonLoader)
  with their own ergonomics. Forcing them onto unityforge
  would be a rewrite, not an integration. Likely we keep
  them C# and just colocate the source.
- Build / deploy: Timberbot has `build.py`, Schedule 1 has
  its own MelonLoader pipeline. Both need to keep working
  after the move.
- Skills (`~/.claude/skills/timberborn`, `timberbot`,
  `schedule1`) reference the source repos by URL; those
  pointers update on the move.

When the move happens, decide between:
1. **Subtree-merge** (preserves history, mirror of how
   horseygame landed). One subtree per source repo:
   `dotnet/timberbot/`, `dotnet/schedule1/` (or kept under
   their existing repo structure inside this one).
2. **Fresh import** with a one-shot history snapshot. Less
   git overhead, loses authoring history.

Strong default: subtree-merge, same as horseygame.

Not pursuing now. Schedule for after the
`<game>-mod` rename standardization lands and the
horsey-mod `sleep_safe_no_tire` patch is unstuck.

---

## RE-to-Rust pipeline (`rustforge`)

Moved 2026-05-14 to its own doc:
[`rustforge.md`](rustforge.md).

TL;DR: Falcon 0.6 based binary-to-Rust spike. **88.8%
lift rate** on 10,332 Horsey functions. 11 sample
artifacts in `horseygame/decompiled/rust/`. Spike crate
at `rustforge-spike/`.

Full plan, survey of alternatives, pipeline diagram,
and remaining polish ladder live in the new doc.


---

## P0. Unityforge: generation-versioned hot reload (Phase 4)

Naive FreeLibrary hot reload crashed WWM 2026-05-13.
Replaced with generation-versioned loading after rtfm
research: never `FreeLibrary`, each reload `LoadLibrary`s a
new image with a unique filename. Deep-dive:
[`unityforge-plan.md` §6.5](unityforge-plan.md#65-hot-reload-phase-4).

Built + deployed 2026-05-13 (awaiting in-game verification
of the first hot-swap cycle).

- [x] **Cdylib: `unityforge_shutdown` actually joins
  background threads.** `modforge::server::shutdown_all`
  (already wired) calls `Server::unblock` + thread join.
  `modforge::rpg::poller::shutdown_all` (new) uses a
  `Condvar` to wake the sleeping poller immediately and
  joins the thread. Both registered in
  `modforge::shutdown::SHUTDOWN_REGISTRY` at order 200/250.
- [x] **Shim: generation pointers + per-gen state.**
  `cs-shim-mono/Plugin.cs` rewrote `UnityforgeShimPlugin`
  around a `Generation` class (module handle, init/tick/
  shutdown delegates, pinned bridge table). One `_active`
  + a `_quiesced` list. Per-gen tick dispatch.
- [x] **Shim: watcher routes to LoadLibrary, never
  FreeLibrary.** Per-second scan for
  `*.unityforge.gen<N>.dll`; highest N > active triggers
  `HotSwap`. `NativeLibrary.Free` removed from the helper
  entirely.
- [x] **HTTP port + Harmony lifecycle on swap.** Old
  generation's `unityforge_shutdown` joins HTTP listener
  (port released) + unpatches Harmony patches via
  `HOOK_REGISTRY.shutdown_all` before new gen's `init`
  fires. Shared C# `Harmony` instance + per-gen patch sets
  in the `_patches` dictionary; cross-gen patches don't
  collide because old gen removes its own first.
- [x] **Deploy script: `-Hot` writes `gen<N>.dll`.**
  `build_and_deploy.ps1 -Hot` scans the plugin dir for the
  highest existing `gen<N>.dll`, writes the build as N+1.

Known follow-up (not blocking the reload cycle):

- [ ] **Handle-table namespace per generation.** Currently
  shared across generations via `MonoBridge._handles`.
  Old gen's still-held handles are stale references after
  swap. Harmless in practice (old gen has shut down +
  exited threads) but worth high-bit-encoding the
  generation if collision matters later.
- [ ] **Periodic GC of quiesced generations.** The
  `_quiesced` list grows forever in the current shim. Once
  a gen's threads have exited, we could free its
  GCHandle. Detecting "threads exited" reliably without
  hard joins is tricky; defer.
- [ ] **IL2CPP shim also needs the gen-loader.** Only Mono
  shim got rewritten. Mirror the change into
  `cs-shim-il2cpp/Plugin.cs` before shipping IL2CPP smoke.

## P0. Unityforge: finish the modforge extraction (Phase 0b remainder)

Phase 0b lifts ~12k Rust lines out of ueforge into the engine-agnostic
`modforge` crate. Most rows shipped (ring, counters, log, args,
envelope, settings, shutdown, selector grammar, ops registry, server,
scanner, winproc, hot_reload, RPG traits, RPG pure math, tracker,
poller, slot store, vanilla, disabled). Deep-dive:
[`unityforge-plan.md` §6 Phases 0a/0b](unityforge-plan.md#phases).

What's open:

- [x] **Phase 0a: specs + docs**. `modforge/spec/*` and
  `modforge/docs/*` exist (op-envelope, selector-grammar,
  op-registry, generic-primitives, skill-catalog, rpg-persistence,
  xp-curve, effect-kinds, trigger-kinds; methodology,
  composition-model, def-registry, naming).
- [x] **Phase 0b rows 1-15**. Engine-agnostic infrastructure +
  rpg traits + rpg pure math + tracker all migrated.
- [x] **Phase 0b row 16: generic `std_effect`**. `RuntimeEffect`
  lifted to `modforge::rpg::std_effect` with blanket
  `impl<E: Engine> Effect<E>`.

## P0. Unityforge: IL2CPP support + Rust SDK unification (Phase 1 remainder)

Plan revised 2026-05-13: unityforge ships Mono AND IL2CPP from day
one as first-class peers (north star: any random UE5 or Unity game).
Currently only the Mono shim exists; the IL2CPP shim and the
backend-agnostic Rust SDK are not built yet. Deep-dive:
[`unityforge-plan.md` §6 Phase 1](unityforge-plan.md#phase-1-unityforge-skeleton--both-c-shims--http-control-plane-10-12-days).

- [x] **Phase 1a: Cargo crate + workspace wiring**.
- [x] **Phase 1b: C# Mono shim** at
  `unityforge/cs-shim-mono/Unityforge.Shim.Mono.csproj` (BepInEx 5).
- [x] **Phase 1b: shim split into `cs-shim-mono/` +
  `cs-shim-common/`**. Shared `Bridge.cs`, `HarmonyBridge.cs`,
  `Logger.cs` live in `cs-shim-common/` and are linked from
  both backend csprojs.
- [x] **Phase 1b-il2cpp: C# IL2CPP shim** at
  `unityforge/cs-shim-il2cpp/Unityforge.Shim.Il2Cpp.csproj`
  (BepInEx 6 IL2CPP + Il2CppInterop). Same bridge ABI as Mono;
  `Il2CppBridge.cs` implements the surface against
  `Il2CppInterop.Runtime`.
- [x] **Phase 1c: Rust `unity::*` SDK**. Backend-agnostic
  surface at `unityforge::unity::*` (`Type`, `Object`,
  `runtime_kind`). Bridge ABI v2 carries `RuntimeKind` tag;
  `mono::*` and `il2cpp::*` are backend-specific escape
  hatches.
- [x] **Phase 1d: HTTP control plane**.
- [x] **Phase 1e: Hook bridge**.

## P1. Unityforge::rpg: framework completeness (Phase 2 remainder)

Skeleton shipped 2026-05-13: `UnityEngine`, `UnityEvent`,
`UnitySlotKey`, `UnityField{Additive,Multiply}Effect`,
`UnityMethodInvokeEffect`, `Tracker` / `SkillDef` /
`SkillRegistry` aliases. Deep-dive:
[`unityforge-plan.md` §6 Phase 2](unityforge-plan.md#phase-2-unityforgerpg-3-4-days).

- [x] **Phase 2: slot_key_unity + vanilla cache + std_effect
  (3 effects) + tracker/skill type aliases**.
- [x] **Phase 2: `trigger_harmony` + `OnUnityEvent`**. Shipped
  `ON_HARMONY_POST`, `ON_HARMONY_PRE`, `ON_UNITY_EVENT`
  TriggerDefs in `unityforge::rpg::trigger_harmony` plus
  `fire_post` / `fire_pre` / `fire_event` helpers
  game-side trampolines call to push events through
  `Tracker::fire`.
- [x] **Phase 2: `ops_register` for RPG ops**. Lifted
  `ueforge::rpg::ops` to `modforge::rpg::ops` generic over
  `E: Engine`. Both frameworks call
  `modforge::rpg::ops::register(&TRACKER)` (or the
  `unityforge::rpg::ops::register` / `ueforge::rpg::ops::register`
  re-exports) to add the standard five-op set.

## P1. wwm-mod: complete the Mono proof (Phase 3a remainder)

Catalog now declarative through `modforge::rpg::Tracker` with
two skills. Plan calls for 5-8 skills + ImGui tab + save/load
persistence. Save/load is done (via Tracker + slot store).
Deep-dive:
[`unityforge-plan.md` §6 Phase 3a](unityforge-plan.md#3a-wwm-mod-mono).

- [x] **Strong Back + Greedy Miner**. Both declarative via
  `UnityFieldAdditiveEffect` and `UnityFieldMultiplyEffect`.
- [x] **Slot poller + UnitySlotKey wiring**. Polls
  `GameSerializationSystem._currentLoadedSaveNumber`.
- [x] **Save/load via `modforge::rpg::store`**. JSON under
  `<DLL_dir>/wwm-mod/<slot>.json` written atomically by the
  Tracker.
- [x] **Quick Pickaxe** (UnityFieldMultiply on
  `DigManager._digRange`). **VERIFIED IN-GAME 2026-05-13**:
  spending 10 points mutated `_digRange` 3.0 -> 4.5 exactly;
  save persisted to `<WWM>/wwm-mod/0.json`.
- [x] **Lucky** (RuntimeEffect: format-only Effect; hot-path
  probability scaling lives in a future Harmony postfix
  callback that reads the level on every fire).
- [ ] **Ship `UnitySkillProxyEffect`** + repoint Strong Back
  at the game's built-in `Bag` skill. Major finding from the
  2026-05-13 session: the game ships `SkillsManager` with a
  full RPG API (`SetSkillLevel`, `LevelUpSkill`,
  `GetCurrentSkillLevel`, etc.) and four built-in skills
  (`Bag`, `Energy`, `Rope`, `Speed`). Calling
  `SetSkillLevel("Bag", 4)` via `invoke_method` grew the
  player's backpack from 5 to 12 slots live in-game (no save
  reload). The right framework shape is a proxy Effect that
  maps our level to a game-skill level and lets the game
  handle the live mutation. See
  [`docs/wild-west-miner-research.md` §7.5](wild-west-miner-research.md#75-in-game-findings-2026-05-13-session).
- [ ] **Research Charisma + Resilient mappings**. Neither has
  an obvious built-in game-skill match. Either find a custom
  proxy through the existing four (Energy regen for
  Resilient?) or write a raw-field Effect against
  `GameDataSO._jetpackEnergyConsumeAmount` /
  `_moneyEnergyRestoreCost`. The latter needs a one-hop
  indirection Effect (singleton -> SO field -> target field)
  since GameDataSO is reached via `GameplayManager._gameData`.
- [ ] **Verify Greedy Miner in-save**. `MineDataSO` has zero
  instances at main menu (SOs instantiate with a save). The
  game has no built-in skill for ore value either, so this
  is the one case where raw-field Effects on
  `MineDataSO._oreValue` (verified field name TBD) is the
  right path. Defer to an in-save test session.
- [x] **Declarative UI tab**. `ModDef.tabs` field added on
  the unityforge side; `register_ui_ops` exposes `list_tabs`
  + `render_tab` via HTTP. `wwm-mod::skills::render_tab`
  logs a catalog + state snapshot through the BepInEx sink.
  Full in-process ImGui rendering is deferred until a
  bundled imgui binding lands on unityforge (the plan
  carve-out: "OnGUI fallback is always available").

## P1. Unityforge: IL2CPP proof-point (Phase 3b)

Demonstrates the same Rust SDK drives an IL2CPP game.
Smaller in scope than wwm-mod: smoke checklist only, not a
full RPG mod. Deep-dive:
[`unityforge-plan.md` §6 Phase 3b](unityforge-plan.md#3b-il2cpp-proof-point).

- [x] **Pick IL2CPP smoke target**. Default Harmony target is
  `UnityEngine.Time::get_realtimeSinceStartup` (every Unity
  game ships it) so the smoke crate loads against any IL2CPP
  game. Override via `IL2CPP_SMOKE_TARGET_CLASS` /
  `IL2CPP_SMOKE_TARGET_METHOD` env vars to point at a
  specific game.
- [x] **Build smoke cdylib** at `grounded2mods/il2cpp-smoke/`.
  Crate-type `cdylib`, three `unityforge_*` exports verified
  via dumpbin.
- [x] **Smoke checklist code**: ops `smoke_state` (runtime
  tag + postfix counter), `smoke_read` (read_field through
  the bridge), `smoke_write` (write_field through the
  bridge); one Harmony postfix wired through
  `patch_postfix`. Curl verification still requires a
  running game (out of scope for "ignore testing").

## P2. Modforge: framework-wide subsystem migration (Phase 0b rows 17-22)

Lower-leverage extractions; rows that no unityforge consumer
demands yet. Pull in when a consumer surfaces. Deep-dive:
[`unityforge-plan.md` §6 Phase 0b](unityforge-plan.md#phase-0-modforge-extraction-4-5-days).

- [x] **Row 17: `client`** -> `modforge/client/`. ueforge's
  HTTP client + scenario DSL + diff/perf/research submodules
  moved wholesale; `crate::parms` coupling inlined as direct
  zerocopy calls in `call_ufunction_typed`.
- [x] **Row 18: `bin/ueforge-deploy`** -> `modforge-deploy`
  bin in modforge. `.cargo/config.toml` alias repointed.
  Functionality still UE4SS-specific; a unityforge deploy
  story can be added when needed.
- [x] **Row 19: `debug` glue** -> `modforge/src/debug.rs`.
  Pure half (`PlayerStateView`, `CatalogEntry`,
  `catalog_view` generic over `E`) moved. UE-specific
  helpers (ProcessSnapshot, DamageRing, enqueue_pe) stay
  in ueforge::debug.
- [x] **Row 20: `snapshots` generics** ->
  `modforge/src/snapshots/`. Stub module declared; concrete
  ProjectionSnapshot types follow the first consumer.
- [x] **Row 21: `ui` declarative shape** -> `modforge/src/ui.rs`.
  `TabDef { name, render }` moved; ueforge + unityforge both
  re-export. Rendering stays per-framework.
- [x] **Row 22: `worker` shape** -> `modforge/src/worker.rs`.
  `spawn(name, work)` with panic-guard moved wholesale.

---

## P0. In-game smoke test

The full 2026-05-10 wave is build-clean and unit-tested but not
yet validated in-game.

!!! warning "Acceptance gate"
    Drive from your machine. All checks must pass:

    - Game launches; `grounded2_mod.log` shows `ueforge` init lines.
    - ImGui tab opens on `Insert`; RPG content renders.
    - Load a save -> slot activate fires; tracker loads
      `<guid>.json`; backpack capacity reflects skill levels.
    - Kill a creature -> kill_hook fires; XP increments; save updates.
    - HTTP `/debug` endpoint responds to `op:snapshot` with non-empty
      state.

    If any of that fails, triage from the log lines.

---

## P0. DataTable write surface (remaining)

The Phase 1 / Phase 2 surface shipped (see
[`../ueforge/docs/data-table.md`](../ueforge/docs/data-table.md)).
Two open follow-ups gated on real consumers:

- [ ] **Replicated-field respect**. Some row fields are
  replicated to clients; writes during a server's authority
  drop get desynced. Defer until we hit a real case.
- [ ] **Non-primitive field types**. Writing `FString` /
  `TArray` rows needs the engine's `FMemory` allocator (ABI
  work). Defer until a real consumer needs it.

## P1. Registry alignment (remaining)

- [ ] **`simulate_apply_damage` lift** (gated on Wave E1).
  `ApplyDamageFromInfo` from inside any current PE trampoline
  re-enters ProcessEvent through the engine's damage-replication
  path and crashes the host. Lift to `ueforge::rpg::health` once
  the safe drain site lands.

### Deferred (large lifts)

- [ ] **Parm decoders**. Every PE-hooking module knows
  "for UFunction X, the parm block has shape Y". Currently
  scattered across kill_hook / inv_hook / fall_hook as bespoke
  code. Could lift to `ParmDecoderDef { function_name, decode_fn
  }` + a per-class registry. Biggest payoff: a generic
  `walk_parms` debug op. Defer until a second consumer needs
  it.
- [ ] **`ClassRef` registry**. Every declared `static FOO:
  ClassRef = ClassRef::new("Foo")` could feed a workspace-wide
  `class_refs_list` op. Marginal; defer.

## P1. Ueforge durability (kovarex review wave 2, remaining)

Wave 2 keepers (patternsleuth, zerocopy first wave, schema
versioning, SAFETY annotation status, crate-shopping verdicts)
shipped; see [`../ueforge/docs/architecture.md`](../ueforge/docs/architecture.md)
"Wave 2 durability adoptions".

### Pending crate adoptions (ordered by gain)

Sorted by leverage, not alphabetical. Maintenance status
confirmed via `gh api` 2026-05-12.

1. **`zerocopy`** (IN PROGRESS). First wave shipped; still open
   are the dynamic-offset / dynamic-type sites where one zerocopy
   struct doesn't fit all callers:
   - `damage/mod.rs::on_event` (offsets configured at runtime
     via `DamageHookConfig`).
   - `data_table.rs::decode_field` (T chosen at runtime by
     FProperty class string).
   - kill_hook / fall_hook / inv_hook parm decoders (each could
     define one `#[repr(C)]` + zerocopy struct per UFunction
     shape; ~6 structs total).
   - `FDataTableRowHandle` (has a `*const UObject`; pointer
     rejects FromBytes; would need a split type).

2. **`proptest`** (IN PROGRESS). MEDIUM-HIGH gain. Property
   tests landed on TArray garbage headers, TMap
   `find_value_by_fname_key` correctness, and `Val::from_json`
   round-trips for all 10 scanner value types. Still open:
   FieldTweak decoder + `inspect_address` byte slabs.

3. **`insta`** (IN PROGRESS). MEDIUM gain. Wired as dev-dep
   with four envelope-shape snapshots in `envelope.rs`
   (`OpResponse::ok` / `err` / `from_result` x ok/err). Run
   `cargo insta review` to accept future shape changes. Still
   open: per-op snapshots for the standard debug-op set
   (`skill_toggle` / `spend` / `refund` / etc.). Gated on
   building a stateless test fixture for those.

### Open durability follow-ups

- [/] **Annotate the existing unsafe blocks**. Down to 50 from
  271; the remaining 50 are spread thinly across `ue/probe.rs`,
  `ue/status_effect.rs`, `ue/class_tweak.rs`, `ue/core_types.rs`,
  `ue/typed_field.rs`, `ue/fname.rs`, `ue/platform.rs`,
  `ue/player.rs`, `discovery.rs`, `selector.rs`,
  `damage_info.rs`, `pe_call.rs`, `parms.rs`, `fstring.rs`, and
  single-block files. Chip away during normal edits; bump the
  lint to `deny` when the count reaches zero.
- [ ] **Hot-reload torture test**. 1000x Ctrl+R loop with hooks
  installed; assert no thread leak, hook leak, slot regression.
  Path is "tested once" today. Requires running game; gated on
  in-game test harness.

## P2. Ueforge grooming (remaining)

- [ ] **UE-version-aware `ffield` / `fproperty` / `ustruct`
  offsets**. Hardcoded for UE 5.4 in `ue/offsets.rs`. UE 5.5+
  silently returns wrong names. Pair with the sig-scan work.
- [/] **Property tests on walkers**. Boundary tests shipped (5
  on `tarray`, 7 on `tmap`). Proptests landed on TArray
  (garbage headers), TMap (find_value correctness), and
  `Val::from_json` (10 types). Still open: FieldTweak
  decoder + `inspect_address` byte slabs.
- [ ] **`tiny_http` / `ureq 2` migration window**. Both on a 2-5
  year support horizon.
- [ ] **PE hook trampoline linear search**. Index by vtable
  pointer when 6+ hooks are installed.

## ueforge framework. Wave E (deferred until needed)

- [ ] **Global ProcessEvent pre-callback**.
  `RegisterProcessEventPreCallback` wrapper +
  `Queue::install_drain` helper. Land when status-effect
  migration needs a guaranteed drain site.
- [ ] **`AddUObjectCreateListener` integration**. Land when
  ows-tweaks or g2rpg's CDO-revert-replay scenario asks. ~100 LoC.

## ueforge framework. Still-open extractions

- [ ] **Leak-source helpers**. `explore_leak_source.rs` (350
  lines) uses g2-extension `top_packages` / `loaded_levels` /
  `process_regions` fields not in the framework's
  `gobjects_population` helper today. Lift those as separate
  `ueforge::ue::probe::*` extensions when a second consumer
  needs them.

Deferred extractions (no second consumer yet):

- Damage-hook framework scaffold beyond `DamageBinder`. Maine-
  specific KillerKind / FDamageInfo parsing stays game-side.
- Status-effect discovery enumerators (`fall_hook` row-walking).
  `StandardEffect::StatusEffect` covers the apply path.
- HUD overlay drawing (DX11 hook for in-world rendering). Big
  lift, no second consumer.
- Inventory CRUD ops (add / remove / count / list). Module shape
  exists; CRUD lands when a second game's UFunction names drive
  the trait surface.

---

## ueforge buildings module (planned, not started)

The next opinionated module. Lets a mod add custom content
(buildings, structures, placeables) to a UE5 game via UE4SS,
not via paks. Player-placeable buildings that yield resources,
tick logic, persist across saves, integrate with the host
game's build menu where one exists.

The sixth module after `rpg / stacks / difficulty / inventory /
damage`. Splits framework from game-specific surface: future
mods ship a new building with ~30 lines of catalog config + ~50
lines of game-side wiring.

### What's universal (-> `ueforge::buildings`)

| Surface | Why universal |
|---|---|
| `BuildingDef<S, C>` catalog row. Id + display_name + description + default per-instance state `S` + game-specific config `C` | Every game's mod-added buildings have the same shape: a typed catalog. Same pattern as `rpg::Skill<E>`. |
| `BuildingRegistry: &'static [BuildingDef<S, C>]` + lookup-by-id | One source of truth, same as RPG catalog. |
| Per-instance state store (`HashMap<Handle, S>`) | Every game tracks "what state is this placed building in". Stored items, level, last-tick timestamp. Shape `S` is game-supplied. |
| Per-slot JSON persistence (`<DLL_dir>/buildings/<playthrough-guid>.json`) | Same `SlotStore<S>` pattern from `ueforge::rpg`. Reuse, don't reinvent. |
| Tick scheduler (closure fires per-instance every `interval`) | Auto-farm, regen, decay. All "advance state by dt" patterns. Owned by the framework; rides on the existing `SlotPoller` shape. |
| Standard debug ops (`buildings_list` / `buildings_place` / `buildings_destroy` / `buildings_get` / `buildings_set_state`) | Same shape as `rpg::ops`. Universal testing surface. |
| ImGui tab template (catalog + placed-instance list + per-instance state viewer) | Same shape as `rpg::tab::render`. |

### What's game-specific (-> game crate via trait)

| Surface | Why game-specific |
|---|---|
| The UE5 game's build-menu data table / widget | Each game has its own UI; some have no native build mode at all. |
| Spawning a placed instance (BP class name + spawn UFunction + cost-charge logic + location/rotation parms) | Per-game BP classes + per-game economy system. |
| Resolving a handle to a live UObject for state reads | Per-game inventory / storage class shapes. |
| Yield-to-storage logic (find nearest storage, transfer items via game's inventory API) | Per-game storage class + per-game item-transfer UFunction. |
| Net authority / replication (which side owns yields) | Per-game multiplayer model. |

The seam: a `BuildingSpawner` trait similar in shape to
`DamageBinder` / `ViewportBinder`.

### Module surface (proposed)

??? example "Proposed Rust module surface"

    ```rust
    // ueforge::buildings (planned, not yet implemented)

    pub struct BuildingDef<S, C> {
        pub id: &'static str,
        pub display_name: &'static str,
        pub description: &'static str,
        pub default_state: S,
        pub config: C,
    }

    pub trait BuildingSpawner: Send + Sync + 'static {
        type Config: Copy + 'static;
        type Handle: Eq + std::hash::Hash + Clone + Send + 'static;

        fn spawn(&self, cfg: &Self::Config, loc: WorldLocation)
            -> Result<Self::Handle, String>;

        fn destroy(&self, handle: &Self::Handle) -> Result<(), String>;

        fn register_in_build_menu(&self, buildings: &[(&'static str, &'static str)])
            -> Result<(), String> { Ok(()) }
    }

    pub struct BuildingsTracker<S, C, Sp: BuildingSpawner> {
        catalog: &'static [BuildingDef<S, C>],
        spawner: Sp,
        instances: Mutex<HashMap<Sp::Handle, Instance<S>>>,
        store: SlotStore<PersistedState<S, Sp::Handle>>,
    }

    pub struct Instance<S> {
        pub building_id: &'static str,
        pub state: S,
        pub spawned_at: SystemTime,
        pub last_tick: Option<SystemTime>,
    }
    ```

Plus `ueforge::buildings::ops` (standard debug-op set),
`ueforge::buildings::tab::render` (ImGui template), and
`ueforge::buildings::tick::SchedulerHandle` (riding the
SlotPoller shape).

### Phased plan

#### Phase A: research (no code)

- [ ] **A1: Grounded 2**. Find the build system entry points
  via the SDK. Likely candidates: `UProductionBuilding`,
  `BP_Building*`, `UBuildingPlacementComponent`,
  `UCraftingComponent`. Identify which UClass defines a
  "placeable building", which UFunction spawns one, how the
  cost is charged, whether there's a build-menu data table to
  extend, how instance state replicates / persists, and the
  save shape.
- [ ] **A2: Outworld Station**. Same audit. The trait surface
  needs to fit both.
- [ ] **A3: Storage / inventory transfer**. For auto-farming
  to land items into a chest, identify the game's "add item to
  inventory" UFunction.

#### Phase B: design lock-in

Trait surface against the two games' constraints. Pick the
handle type (UObject address vs mod-generated FGuid), storage
location, tick model.

#### Phase C: framework implementation

- [ ] C1: `ueforge::buildings::BuildingDef<S, C>` + catalog row.
- [ ] C2: `BuildingsTracker<S, C, Sp>` with `activate_slot` /
  `deactivate_slot` + persistence via `SlotStore`.
- [ ] C3: `BuildingSpawner` trait + game-impl skeleton.
- [ ] C4: Tick scheduler.
- [ ] C5: `ueforge::buildings::ops` standard debug ops.
- [ ] C6: `ueforge::buildings::tab::render` ImGui template.

#### Phase D: g2rpg consumer (proof of concept)

- [ ] D1: One concrete buildable. The
  **auto-fiber-harvester** (yields plant fibers at a configured
  rate, per-instance `{accumulated_units, last_yield}` state,
  transfers to nearest storage on threshold).
- [ ] D2: Catalog row in `grounded2-mod/src/buildings/catalog.rs`.
- [ ] D3: G2 spawner impl.
- [ ] D4: ImGui "Buildings" tab.

#### Phase E: tests

Pester-style scenario DSL extended for buildings (e.g.
`scenario::for_building(api, "auto_harvester").placed_at(loc).advanced_time(60s).should_yield_at_least(10, "plant_fiber")`).

### Open design questions (decide during Phase A/B)

- **Handle type**. UObject address (stable while game is running,
  invalid across saves) vs mod-generated FGuid (stable across
  saves, requires translation). Likely: FGuid for persistence +
  separate live UObject cache.
- **Asset references**. v1 reuses vanilla assets (less moving
  parts); pak-side custom assets land later.
- **Build-mode integration**. v1 ships ImGui-only spawn (lower
  risk). Vanilla-menu integration is Phase D+1.
- **Multiplayer**. Out of scope for v1. Single-player / host-only.
- **Tick clock**. Game-time vs real-time. Save-and-quit
  shouldn't run the farm for 8 hours when you reload. Use
  game-time OR clamp dt to `min(real_dt, configured_max_dt)`.
- **Network authority**. Yields go through the game's
  authoritative inventory API, not direct field writes.

### Estimated scope

Phase A: ~1 session per game. Phase B: 1 session.
Phase C: ~3-4 sessions (~500-700 lines). Phase D: ~2-3 sessions.
Phase E: ~1 session. Total: ~8-10 sessions. The framework piece
is the leverage point.

---

## g2rpg. Catalog expansion

Each entry is one [`skills::CATALOG`](../grounded2-mod/src/rpg/skills.rs)
row of an existing `SkillEffect` shape unless noted.

- [ ] **Critical Chance + Critical Damage**. `before` callback
  on the live damage hook returns `Some(damage * (1 + crit))` on
  roll. RNG needs a per-mod seed; reuse `rand` crate.
- [ ] **Evasion / Dodge**. `before` returns `Some(0.0)` on roll
  for player-taken hits.
- [ ] **Thorns**. `after` resolves the attacker's HC (instigator
  -> controller -> possessed pawn -> HC at +0x1340) and writes
  `event.damage * thorns_fraction` to its CurrentDamage. Same
  healing pattern proven via Lifesteal.
- [ ] **Leap Distance**. LANDED untested
  (`PlayerMovementMult` over AirControl trio).
- [ ] **Auto-pickup (range)**. Per-frame proximity scan picks up
  loose items. Open design: mechanism (existing proximity-pickup
  field vs per-frame scan), filter (which items qualify),
  throttle, multiplayer authority.
- [ ] **Stamina Pool + Stamina Regen**. `UStaminaComponent` on
  ASurvivalCharacter at +0x1358; offsets need a Dumper-7 dive.
- [ ] **Gear Hardiness**. Find durability-loss-per-use field;
  per-item durability scaling.
- [ ] **Climb Speed**. May or may not exist as a separate
  CharMovement field; check before adding.
- [ ] **Collision / Impact Damage Resistance**. Reduce / negate
  the lethal self-damage from slamming into plants / terrain.
  Likely home: live damage hook surface.

!!! tip "Catalog target"
    ~25 skills. Today: 13.

## g2rpg. Live-instance writes

Some combat-side skills still write only to player CDOs.
Movement now mirrors onto the live player pawn; remaining
combat effects need the same. Each `SkillEffect` variant grows a
"live walk" arm analogous to its CDO walk.

## g2rpg. Pkg(0) instigator bug

!!! bug "Repro"
    Some legitimate player kills attribute to
    `/Script/CoreUObject (Package)` because
    `LastDamageInfo.InstigatorController` is an unset
    `FWeakObjectPtr` (index=0 -> Package). User loses XP.

Investigation:

1. Sample more kills with different weapons. Identify which
   attack types fail vs succeed.
2. Hook `ApplyDamageFromInfo` to read `FDamageInfo` parm at
   function entry and cache the instigator per HC. When
   multicast fires with KillingBlow, use cached value if
   `LastDamageInfo` is null.
3. Failing that, fall back heuristically (player in attack range
   + recently swung).

## g2rpg. Status-effect migration (in progress)

Migrate Impact Damage Resistance and Lifesteal to the canonical
status-effect surface first; rest of catalog follows. Detail in
[`../grounded2-mod/docs/damage.md`](../grounded2-mod/docs/damage.md).

Concrete next steps:

- [ ] **Optimize the discovery test**.
  `tests/explore_status_effect_rows.rs`. Batch read_bytes (one
  big chunk) so it runs in seconds. Capture FName for each row.
- [ ] **Pick target row per stat type**.
- [ ] **Implement `SkillEffect::PlayerStatusEffect` variant** in
  `skills.rs`.
- [ ] **One generic apply arm in `apply.rs`** that resolves the
  table, looks up row by FName, mutates Value, calls
  `UStatusEffectComponent::CreateAndAddEffect` via process_event.
- [ ] **Migrate `impact_resistance` first** as proof of concept.
- [ ] **Validate via the regression test**: bandages must heal
  even with impact_resistance enabled.
- [ ] **Migrate the rest** row-by-row:
    - `health_regen` -> `Type=Health (24)`, drop UGlobalCombatData
      mutation
    - `max_health` -> `Type=MaxHealth (5)`, drop direct HC.MaxHealth
    - `lifesteal` -> `Type=LifeSteal (38)`, drop Runtime no-op
    - `attack_damage` -> `Type=AttackDamage (23)`
    - `armor` -> `Type=DamageReduction (29)` or
      `DamageReductionMultiplier (30)`
    - `fall_resistance` -> ALSO apply `Type=FallDamage (14)` for
      consistency (keep velocity-stomp as the validated mechanism)

Movement skills stay on direct CMC field writes. The
status-effect surface doesn't expose movement parameters with
the granularity we use. Survival drains stay on
SurvivalComponent CDO writes.

## g2rpg. RPG tuning

Open until we play more.

- XP curve: is `100 * N^1.8` (cap 50) too steep / flat?
- Per-creature XP table: ~20 species with placeholder values.
  Expand and balance.
- Skill `max_bonus`: are the level-100 caps right?
- Level-up frequency vs catalog size: 50 levels = 50 points;
  catalog max-everything = ~225 points (9 skills x 25 avg).

## g2rpg. Distribution

- [ ] **Vortex / Nexus packaging**. `cargo deploy package`
  produces the right zip layout. Need a Nexus listing
  (description, screenshots, mod page).
- [x] **Project rename**. Standardized on `<game>-mod` form.
  Crate is now `grounded2-mod` per the workspace rename pass
  (see "Naming standardization" earlier in this file).

## g2rpg. Feature ideas (not yet scoped)

- [ ] **Auto-farming buildings**. First concrete consumer of the
  buildings module above. Plant-fiber / resin auto-harvester as
  the first building.

---

## g2rpg. Integration testing

Reference design + test coverage principle:
[`../grounded2-mod/docs/testing.md`](../grounded2-mod/docs/testing.md)
+ [`../ueforge/docs/RESEARCH.md`](../ueforge/docs/RESEARCH.md)
"Test coverage principle".

### Read surface (snapshot fields)

- [ ] **dmg-trace ring buffer in snapshot**. Last N multicast
  events. Currently log-only.
- [ ] **player world location + equipped weapon** (context for
  fall / item-use simulation).

### Drive surface

- [ ] **High-frequency drain site for the PE queue**.
  `kill_hook`'s trampoline only fires on player HC vtable
  events. With `impact_resistance` mask = 0xFFFFFFFF, multicast
  traffic drops near zero, starving the drain. `call` ops time
  out at 5s. Land Wave E1 (global ProcessEvent pre-callback)
  to fix permanently.
- [~] **simulate_consume_item**. Via `call` once we know
  TryUseItem signature on the player controller.
- [~] **simulate_kill / simulate_fall**. Test-side via `call`.
  Doable today.
- [~] **simulate_status_effect_add / _remove**. Via `call` on
  `UStatusEffectComponent::CreateAndAddEffect` once row handle
  layout is captured in a `#[repr(C)]` struct.
- [~] **set_xp / set_level**. Via `call` if a setter UFunction
  exists, or via direct field-write.
- [~] **clear_status_effects**. Via `call` or direct TArray
  write.

### Test coverage (per-skill principle)

For EACH catalog skill (x13):

- [ ] refund -> reverts (only ~half tested explicitly)
- [ ] toggle off -> reverts to vanilla (only for variants that
  honor the flag)
- [ ] toggle on -> effect restored (move_speed only; fill in)
- [ ] persist across slot reload (NOT covered for any skill)
- [ ] level 0 -> no effect (make explicit per skill)

Interaction matrix:

- [ ] armor + heal
- [ ] max_health + fall onto rocks
- [ ] fall_resistance + impact_resistance + rock collision
- [ ] every other pair touching HC fields, damage gate, regen

Error paths:

- [ ] op while no slot (only reload_slot covers this today)
- [ ] malformed args (wrong type)
- [ ] port collision / second instance

---

## Out of scope (kept for reference)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport
  with mouse-wheel scroll. Working.
- Multiplayer correctness for hunger/thirst. Stats almost
  certainly replicate server-authoritatively, so non-host
  clients won't see the effect. Document, don't fight.
- In-world UMG HUD overlay (always-visible XP bar). Out of v1
  scope; would need a custom DX11 hook or BPModLoader-shipped
  widget. ImGui tab is sufficient.

## Open: hot-reload follow-ups

Phase B (in-DLL teardown of hooks / servers / settings watchers
+ side-file rename) shipped 2026-05-10. See
[`../ueforge/docs/lifecycle.md`](../ueforge/docs/lifecycle.md)
"Hot-reload (Ctrl+R)" for the implemented surface.

Optional follow-ups (defer until needed):

- [ ] **Phase B+: programmatic Ctrl+R from `cargo deploy install
  --hot`**. Mod watches a sentinel file; on change, synthesizes
  Ctrl+R via UE4SS's `register_keydown_event`.
- [ ] **Phase B++: HTTP `reload` op** that calls
  `UE4SSProgram::queue_reinstall_mods` directly. Smaller side
  trip.
