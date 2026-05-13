# Trigger kinds

Each Trigger kind names a Rust impl of `modforge::rpg::Trigger`.
Catalog rows reference kinds by name; each framework binds
the kind to its own list at load time.

## Universal kinds (modforge ships)

| Kind | params | When it fires |
|---|---|---|
| `OnSlotChange` | none | When the Tracker activates / spends / refunds / toggles the skill. Most CDO-write skills use this |
| `Periodic` | `{ hz?: u32 }` | Every N ticks. Default 1 Hz |

`OnSlotChange` is the universal "re-apply when leveling
changes" trigger and lives entirely in modforge. `Periodic` is
driven by a per-framework tick callback.

## ueforge kinds

| Kind | params | When it fires |
|---|---|---|
| `OnDamageDealt` | none | Player-instigator damage hit (Lifesteal, Crit) |
| `OnDamageTaken` | none | Player-target damage hit (Evasion, Thorns) |
| `OnKill` | none | Confirmed kill credit to the player |
| `OnFall` | none | Player fall landing |

These require ueforge's `damage::DamageHook` /
fall hook to be installed.

## unityforge kinds

| Kind | params | When it fires |
|---|---|---|
| `OnMonoEvent` | `{ type, event }` | A `static event` on a Mono type fires. Wraps Mono's event subscription |
| `OnHarmonyPatch` | `{ type, method, when: "prefix" | "postfix" }` | A Harmony-patched method runs |

## Adding a kind

1. Define a struct + `impl Trigger`.
2. Register it via `TRIGGER_KINDS.register("YourKind", &YOUR_FACTORY)`.
3. Catalog rows reference `{"kind":"YourKind", "params":{...}}`.
