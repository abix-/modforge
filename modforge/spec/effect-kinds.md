# Effect kinds

Each Effect kind names a Rust impl of `modforge::rpg::Effect`.
Catalog rows reference kinds by name; each framework binds
the kind to its own list of implementations at load time.

## Universal kinds (modforge ships)

These have pure-Rust implementations in
`modforge::rpg::std_effect_pure` and require no engine access:

| Kind | params | What it does |
|---|---|---|
| `Disabled` | none | No-op. Used to gate a skill off at runtime |
| `LogOnly` | `{ message: str }` | Writes to the logger on every fire. Diagnostic |

Anything that touches engine state is per-framework.

## ueforge kinds

| Kind | params | What it does |
|---|---|---|
| `PlayerFloat` | `{ class, offset, base, max_bonus, format }` | Multiply / add to an f32 on a player CDO |
| `FieldMultiply` | `{ class, offset, base, max_bonus, format }` | Multiply an f32 field on a target class CDO |
| `FieldAdditive` | `{ class, offset, base, max_bonus, format }` | Add to a numeric field |
| `MethodInvoke` | `{ class, function, parm_layout, ... }` | UFunction call with computed parms |
| `StatusApply` | `{ table_path, row_fname, value_offset, ... }` | UDataTable row mutation + status creation |

## unityforge kinds

| Kind | params | What it does |
|---|---|---|
| `MonoFieldMultiply` | `{ type, instance_selector, field, base, max_bonus, format }` | Multiply a numeric field on a Mono object via the bridge |
| `MonoFieldAdditive` | `{ type, instance_selector, field, base, max_bonus, format }` | Add to a numeric field |
| `MonoMethodInvoke` | `{ type, instance_selector, method, args }` | Reflection invoke with computed args |
| `ScriptableObjectFieldMultiply` | `{ asset_path, field, base, max_bonus, format }` | Multiply a numeric field on a ScriptableObject |

## Adding a kind

1. Define a struct with the params as fields.
2. `impl modforge::rpg::Effect for YourEffect`.
3. Register it with `EFFECT_KINDS.register("YourKind", &YOUR_FACTORY)`
   in the framework's worker init (or the game mod's init for
   game-specific effects).
4. Catalog rows can now reference `{"kind":"YourKind", "params":{...}}`.
