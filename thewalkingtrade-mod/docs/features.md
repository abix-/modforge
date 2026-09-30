# The Walking Trade mod: features and status

Game 1.2.5 (Steam app 3398110), IL2CPP, loaded by MelonLoader through
Unityforge.Shim.Melon (bridge v10). Control plane on port 17181.
Deploy and restart: `pwsh -NoProfile -File thewalkingtrade-mod/scripts/restart.ps1`.

Settings: `thewalkingtrade.json` in the game folder (next to the game exe),
written with defaults on first run and watched, so edits apply without a
restart.

Status: **proven** means shown in the live game (see `changelog.md`);
**not proven** means built and deployed, proof still open (see `todo.md`).

| Feature | What it does | How | Setting | Status |
|---|---|---|---|---|
| Crafting reach | A bench takes materials from N times its normal area; building, cleaners and everything else about the bench are unchanged | `craft_bench.rs`: prefix on `ItemObjectProvider.GetConsumableItemsPresentFromBox`/`...FromBoxes` (only benches call them) grows the box for that lookup, a postfix restores it | `craft_bench_multiplier` (50) | Not proven |
| Body disposal at cleaner level 2 | The disposal option opens at level 2 instead of 3 | `cleaner_level.rs`: byte patch 3 to 2 in `GetCurrentPolicy` and `HasAnyValidWork` (patternsleuth, one match each), window perk box lowered in a prefix on `FloorWorkerJobSettingsView.OnEnable` | none | Option selectable proven; disposing in play not proven |
| Hurt hires come back | A hire who flees at low health is healed to full on reaching home and goes back to the same job that day | `flee_return.rs`: prefix on `StaffManager.FleeForDay` saves a copy of the job; prefix on `StaffMobObject.Despawn` heals, reassigns and cancels the despawn | none | Not proven |
| No hire deaths | A killing hit leaves a hire at 1 HP, which starts their low health behaviour | `no_death.rs`: prefix on the hire's own `StaffMobObject.OnDamagedCheckLowHp` (the last `Damaged` handler, before the death check), so only hits on hires reach the mod | none | Not proven |
| Repeatable skill upgrades | An owned multiplier upgrade or +1 hire upgrade can be bought again for a point, stacking once more each time | `skill_repeat.rs`: `CanUnlock` result postfix, unlock button shown after `OnNodePressed`, copy made on `TryUnlockNode`, copies removed on `Skill.Load` and restored after | `skill_repeats` (counts, one set for every save) | Buying and restore proven; +1 hire raising the limit not proven |
| Barbed wire durability | Wire wears out 10 times slower; slow and damage unchanged | `barbed_wire.rs`: `_ownDamagePerTick` 2.0 to 0.2 in a prefix on `BarbedWireDamageTrigger.Awake` | none | Proven on 9 active wires |
| Spiked wall durability | Wall takes a tenth of the damage from each mob it hits; the damage it deals is unchanged | `spiked_wall.rs`: byte patch at startup, the wall's own `ApplyDamage` multiplier load (`movss xmm3`) repointed from the game's 1.0f to its 0.1f, both found by patternsleuth | none | Not proven |
| Cleaners reach high wall shelves | A cleaner sent to a point above the floor (a high wall shelf's front) walks to the floor below it instead of hanging | `nav_snap.rs`: byte patch so the cleaner item step's `SetDestination` passes `useSamplePosition: true`; hires' navigators get a 3 m snap reach (`_offMeshRecoveryRadius`) in a prefix on `RigidbodyNavigator.Awake` | none | Not proven |
| Shop opens each morning | After sleeping, the shop is opened | `store_open.rs`: postfix on `GameController.OnPlayerSleepCompleted` calls `StoreManager.TryToggleStoreOpen` | none | Proven |

## Cost

Measured with `tests/perf.rs` (`perf_window`, modforge named timing) over
60 s of play on 2026-09-30: no frames over 100 ms. The one steady cost
then was the no-death hook on every damage event in the game, about 5 ms
of Rust time per second at about 90 calls a second, worst single call
0.83 ms; it has since moved to a hook only hires trigger (not yet
re-measured). Every other entry point runs only on its event.
Everything is timed under `twt: ...` names.

## Framework pieces this mod added

- unityforge bridge v10 `patch_postfix_result`: postfix on a method of any
  return type, result replaced as JSON (`{"$handle": N}` for an object).
- modforge `patterns::sleuth::scan_module_matches`: patternsleuth scan of a
  named module (`GameAssembly.dll`), not only the main exe.
- modforge `code_patch`: in-memory byte patches with revert, moved out of
  horsey-mod.
