# RPG framework

> **Authoritative on:** ueforge's level-up / skill-tree / save-
> persistence framework. The complete RPG system every UE5
> RPG / survival mod needs.

ueforge ships the bones of an RPG mod -- catalog row + lookup,
state schema, persistence layer, slot detection, level math,
skill-spend mechanics, ImGui tab template, vanilla baseline
cache. The game crate supplies only the bones-meat:

- A `SkillEffect` enum naming every kind of skill-write the
  game implements.
- The `CATALOG` content (which skills exist with what numbers).
- An `RpgApplier` impl that dispatches the variants.
- Per-skill format text.
- The kill / damage hook that calls `record_xp`.

That's the irreducibly game-specific surface. Everything else
flows from one of the types in this doc.

## The seam: SkillEffect + RpgApplier

The game declares its `SkillEffect` enum:

```rust
#[derive(Debug, Clone, Copy)]
pub enum SkillEffect {
    BackpackSlots { max_bonus: i32 },
    SurvivalDrain { offset: usize, max_reduction: f32, /* ... */ },
    PlayerHealthCompFloat { offset: usize, base: f32, max_bonus: f32 },
    Runtime { max_bonus: f32 },
    PlayerStatusEffect { row_fname: u64, value_at_max: f32 },
    /* ... */
}
```

And implements `RpgApplier`:

```rust
use ueforge::rpg::{RpgApplier, Skill, SkillsState};

pub struct GameApplier { settings: Settings }

impl RpgApplier for GameApplier {
    type Effect = SkillEffect;

    fn apply_skill(&self, state: &SkillsState, skill: &Skill<SkillEffect>) {
        let level = state.level_of(skill.id);
        match skill.effect {
            SkillEffect::BackpackSlots { max_bonus } => { /* CDO writes */ }
            SkillEffect::SurvivalDrain { /*...*/ } => { /* ... */ }
            // ... per-variant arms ...
        }
    }

    fn format_effect(&self, skill: &Skill<SkillEffect>, level: u32) -> String {
        /* per-skill text for ImGui row */
    }
}
```

The trait has three methods:
- `apply_skill(state, skill)` -- write the skill's effect at the
  current level. Called on spend/refund/toggle/slot-activate.
- `apply_all(state, catalog)` -- defaults to walking catalog
  and calling `apply_skill` per row. Override if dependency
  ordering matters.
- `format_effect(skill, level)` -- pretty text for the ImGui
  row ("+25% damage", "+460 slots", "-50% drain").

ueforge owns persistence, state, dispatch shape; you own the
match arms.

## Skill<E> -- catalog row

```rust
pub struct Skill<E: 'static> {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect: E,
}

pub fn find_skill<'a, E>(catalog: &'a [Skill<E>], id: &str)
    -> Option<&'a Skill<E>>;
```

`E` is parameterized -- the game supplies its own enum. Catalog
is a `&'static [Skill<E>]`:

```rust
pub static CATALOG: &[Skill<SkillEffect>] = &[
    Skill {
        id: "backpack",
        display_name: "Backpack",
        max_level: 100,
        effect: SkillEffect::BackpackSlots { max_bonus: 460 },
    },
    Skill {
        id: "attack_damage",
        display_name: "Attack Damage",
        max_level: 100,
        effect: SkillEffect::PlayerCharFloat { /* ... */ },
    },
    // ...
];
```

`find_skill(CATALOG, id)` is O(N) linear scan; catalogs are tiny
(~25 rows) and lookups are cold-path (button click, snapshot,
ImGui label). No hashmap.

## SkillsState -- on-disk schema

```rust
pub struct SkillsState {
    pub xp: u64,
    pub level: u32,
    pub skill_points: u32,
    pub skill_levels: BTreeMap<String, u32>,
}

impl SkillsState {
    pub fn level_of(&self, skill_id: &str) -> u32;
    pub fn spend(&mut self, skill_id: &str, max_level: u32) -> bool;
    pub fn refund(&mut self, skill_id: &str) -> bool;
}
```

Open shape (`#[serde(default)]` on every field) so adding new
skills doesn't break existing save files. `skill_levels` is a
`BTreeMap<String, u32>` -- string keys are the catalog `id`s,
stable forever.

`spend()` returns `true` on success (had a point + below max).
`refund()` returns `true` on success (had a point spent).
Caller is responsible for persisting via `Tracker::spend` --
direct `SkillsState::spend` mutates only the in-memory copy.

**Don't drive `SkillsState` directly from production code.** Use
`Tracker<A>` -- it owns the (state, applier, store) triple and
makes spend/refund transactional with disk save.

## SlotStore<S> -- per-slot JSON persistence

```rust
pub struct SlotStore<S> { /* ... */ }

impl<S: Serialize + DeserializeOwned + Default> SlotStore<S> {
    pub const fn new(subdir: &'static str) -> Self;
    pub fn path(&self, slot: &str) -> PathBuf;
    pub fn load(&self, slot: &str) -> S;
    pub fn save(&self, slot: &str, state: &S);
}
```

Atomic save: writes `<DLL_dir>/<subdir>/<slot>.json.tmp`, then
`fs::rename` to `<slot>.json`. Loads return `S::default()` on
missing / unparseable file (logged).

Generic over `S` so games can persist extended state alongside
the framework `SkillsState` (achievements, kill counters, run
meta). g2rpg uses `SlotStore<SkillsState>` directly; an extended
mod could use `SlotStore<MyExtendedState>` where
`MyExtendedState` includes a `pub skills: SkillsState` field.

Caveats (kovarex P0s, pending fix):

- `save()` swallows IO errors today. A full disk loses the
  player's points silently. Should return `io::Result`. See
  [PERFORMANCE.md](PERFORMANCE.md) "Memory leak vectors".
- No `fsync` before rename. Power-loss between rename and
  flush leaves a torn file.

Both fixes are queued.

## Curve -- XP math

```rust
pub struct Curve {
    pub base: f64,
    pub exponent: f64,
    pub max_level: u32,
}

impl Curve {
    pub const fn new(base: f64, exponent: f64, max_level: u32) -> Self;
    pub fn cumulative_xp_for_level(&self, level: u32) -> u64;
    pub fn level_for_xp(&self, xp: u64) -> u32;
}

pub const CURVE: Curve = Curve::new(100.0, 1.8, 50);
```

`cumulative_xp_for_level(level) = round(base * level^exponent)`.
`level_for_xp(xp)` is linear scan from `max_level` downward (cheap
for typical caps 50-100; bounded).

Defaults match g2rpg: 100 / 1.8 / 50. Generous early, flat at the
end. Adjust `(base, exponent, max_level)` to retune.

## Bestiary -- per-creature XP table

```rust
pub struct Bestiary {
    pub table: &'static [(&'static str, u32)],
    pub default_xp: u32,
}

impl Bestiary {
    pub const fn new(
        table: &'static [(&'static str, u32)],
        default_xp: u32,
    ) -> Self;
    pub fn lookup(&self, class_name: &str) -> u32;
}
```

UE5 RPG mods award XP based on the dying actor's BP class. Hold
the `(class_name, base_xp)` pairs in a `static Bestiary`, look up
once per kill from the kill hook. Linear scan; realistic
bestiaries are <100 rows so the cost is invisible.

```rust
pub static BESTIARY: Bestiary = Bestiary::new(
    &[
        ("BP_Aphid_C", 5),
        ("BP_Roly_Poly_C", 25),
        ("BP_Spider_C", 75),
    ],
    5, // default for unknown classes
);
```

## sqrt_progress -- diminishing-returns curve

```rust
pub fn sqrt_progress(level: u32, max: u32) -> f32;
```

`sqrt(level / max)`. Level 1 = ~10% of max, level 25 = 50%,
level 100 = 100%. The default skill scaling. Game `apply` arms
multiply `max_bonus * sqrt_progress(level, skill.max_level)` to
get the at-level bonus.

## Tracker<A: RpgApplier>

The runtime entry point. Owns slot binding, in-memory state,
applier instance, persistence. Drives every state change
transactionally with disk save.

```rust
use ueforge::rpg::{Tracker, Curve};

pub static TRACKER: Tracker<GameApplier> = Tracker::new(
    CATALOG,
    Curve::new(100.0, 1.8, 50),
    "saves",
);
```

### Slot lifecycle

```rust
TRACKER.activate_slot(slot_key, GameApplier { settings });
// ... gameplay ...
TRACKER.deactivate_slot();
```

`activate_slot` loads `<DLL_dir>/saves/<slot_key>.json` (or
default if missing), reconciles `level` from `xp` if needed,
calls `applier.apply_all(catalog)` so the world reflects
current skill levels, stores the (slot, state, applier) triple.

`deactivate_slot` drops the in-memory state.

`slot_key` is whatever stable identifier your game's saves use.
For UE5 games with a `PlaythroughGuid` on the GameState, see
[`SlotKeyResolver`](#slotkeyresolver) below.

### Spending / refunding

```rust
let n = TRACKER.spend_skill_points("attack_damage", 1);     // returns spent count
let n = TRACKER.refund_skill_points("attack_damage", 10);   // returns refunded count
```

Both:
- Lock the inner state.
- Validate (skill exists, points available, max-level cap).
- Mutate `SkillsState`.
- Call `applier.apply_skill(state, skill)`.
- Persist via `store.save(slot, state)`.
- Return the actual count (capped by available points / cap).

Atomic: a crash between mutation and save would lose the
point. (kovarex P0 fix in flight.)

### Recording XP

```rust
let result: Option<XpResult> = TRACKER.record_xp(awarded);
```

Awards `awarded` XP, recomputes level via the curve, increments
`skill_points` on level-up, persists. Returns `XpResult`:

```rust
pub struct XpResult {
    pub awarded: u64,
    pub total_xp: u64,
    pub old_level: u32,
    pub new_level: u32,
    pub points_gained: u32,
}

impl XpResult { pub fn levelled(&self) -> bool; }
```

Use `result.levelled()` to drive "LEVEL UP!" feedback (sound,
log, UI flash).

### Reading state

```rust
let snap = TRACKER.with_state(|s| (s.level, s.xp));   // Option<R>
let slot = TRACKER.current_slot();                      // Option<String>
```

`with_state` runs your closure under the inner lock. Don't do
heavy work inside; copy the fields you need and release.

### Reapplying

```rust
TRACKER.reapply_one("move_speed");      // for the on/off toggle
TRACKER.reapply_all();                  // for /debug reload_slot
```

### Debug grants

```rust
TRACKER.debug_grant_skill_points(50);
```

Adds points without earning them. Logs the grant. For dev only.

## SlotKeyResolver -- save-slot detection

```rust
use ueforge::rpg::SlotKeyResolver;

pub static RESOLVER: SlotKeyResolver = SlotKeyResolver::new(
    "InGameGameState",   // class on which the GUID lives
    0x032C,              // FGuid offset
);

let slot: Option<String> = RESOLVER.resolve();
```

Walks GObjects for the first live instance of the configured
class, reads an `FGuid` at the offset, formats as a 32-char hex
filename. Returns None when not in-world (main menu, between
saves) or when the GUID is zero.

Plug into `SlotPoller`:

```rust
SlotPoller::spawn(
    Duration::from_secs(1),
    || RESOLVER.resolve(),
    |slot| TRACKER.activate_slot(slot, GameApplier { settings }),
    || TRACKER.deactivate_slot(),
);
```

## SlotPoller -- 1Hz transition watcher

```rust
SlotPoller::spawn(interval, resolve, on_activate, on_deactivate);
```

Spawns a Win32 worker thread that polls `resolve()` every
`interval`. State machine on the resolver's return value:

| Previous | Current | Action |
|---|---|---|
| `None` | `Some(s)` | `on_activate(s)` |
| `Some(a)` | `Some(b)` where `a != b` | `on_deactivate()` then `on_activate(b)` |
| `Some(_)` | `None` | `on_deactivate()` |
| else | else | nothing |

The worker runs for life of process today (kovarex P0 -- need
`shutdown_handle()`). Panics in the resolver are caught
silently (kovarex P1 -- need logged payload).

## DisabledSkills -- per-skill on/off toggle

```rust
pub static DISABLED_SKILLS: ueforge::rpg::DisabledSkills =
    ueforge::rpg::DisabledSkills::new();

DISABLED_SKILLS.set("attack_damage", true);          // disabled
DISABLED_SKILLS.is_disabled("attack_damage");        // true
DISABLED_SKILLS.snapshot();                          // Vec<&'static str>
```

Process-global. Disabling treats a skill as level 0 in the
apply path without refunding the player's points -- "drop a
buff on demand" toggles in the ImGui tab. Not persisted.

The `RpgApplier::apply_skill` impl decides whether to honor the
disabled flag (for a `Runtime` effect, "disabled" means the
trampoline reads level 0; for a CDO write, "disabled" means
restore vanilla).

## VanillaCache<K, V> -- baseline capture

```rust
use ueforge::rpg::VanillaCache;

pub static MOVEMENT_VANILLA: VanillaCache<usize, f32> = VanillaCache::new();

let baseline = MOVEMENT_VANILLA.get_or_init(offset, current_value);
let new_value = baseline * (1.0 + bonus);
write_field(obj, offset, new_value);
```

Per-key first-write-wins cache. The first apply call captures
the engine's vanilla; subsequent calls return the captured
value (so we always scale from vanilla, not from whatever the
mod has already overwritten).

Methods:

```rust
pub fn get_or_init(&self, k: K, v: V) -> V;     // returns captured baseline
pub fn set_if_unset(&self, k: K, v: V) -> bool; // returns insert flag
pub fn get(&self, k: K) -> Option<V>;
pub fn snapshot(&self) -> Vec<(K, V)>;
pub fn clear(&self);
```

Use one cache per logical-baseline-set (movement, global combat
data, HC masks). Single-baseline values (one f32, one offset)
are simpler with `OnceLock<f32>`.

## tab::render -- ImGui tab template

```rust
use ueforge::rpg::tab::{render as render_rpg_tab, ToggleFns};

const TOGGLES: ToggleFns = ToggleFns {
    is_enabled: |id| !DISABLED_SKILLS.is_disabled(id),
    set_enabled: |id, on| { DISABLED_SKILLS.set(id, !on); },
};

pub fn render() {
    render_rpg_tab(&TRACKER, Some(&TOGGLES));
}
```

`render(tracker, toggle)` draws:

1. **Header** -- "Level N", XP progress bar (current / next),
   "Unspent skill points: K".
2. **Per-skill row** for every catalog entry:
   - `+1` / `+10` buttons (gated on points + below max)
   - `-1` / `-10` buttons (gated on level > 0)
   - Optional `on` checkbox (if `ToggleFns` supplied)
   - Effect text from `applier.format_effect(skill, level)`
   - Next-level preview when below max
3. **Debug footer** -- `+5 / +50 skill points` for testing.

Pass `None` for the `toggle` arg to omit the per-skill on/off
column (some games don't want it).

The render runs on UE4SS's render thread, once per frame while
the tab is visible. It calls `Tracker::with_state` for each
read; the inner lock is held briefly.

## Putting it all together

The full g2rpg-shaped wiring:

```rust
// catalog (game-specific):
pub static CATALOG: &[Skill<SkillEffect>] = &[
    Skill { id: "backpack",       max_level: 100, ... },
    Skill { id: "attack_damage",  max_level: 100, ... },
];

// applier (game-specific):
pub struct GameApplier { settings: Settings }
impl RpgApplier for GameApplier {
    type Effect = SkillEffect;
    fn apply_skill(...) { /* match on skill.effect */ }
    fn format_effect(...) { /* pretty text */ }
}

// tracker (one static, generic):
pub static TRACKER: Tracker<GameApplier> = Tracker::new(
    CATALOG,
    Curve::new(100.0, 1.8, 50),
    "saves",
);

// slot detection (game-specific class + offset):
pub static RESOLVER: SlotKeyResolver =
    SlotKeyResolver::new("InGameGameState", 0x032C);

// world loader: wire SlotPoller to RESOLVER + TRACKER:
SlotPoller::spawn(
    Duration::from_secs(1),
    || RESOLVER.resolve(),
    |slot| TRACKER.activate_slot(slot, GameApplier { settings }),
    || TRACKER.deactivate_slot(),
);

// kill hook: call TRACKER.record_xp on confirmed kills:
fn on_kill(creature_class: &str) {
    let xp = xp_for_creature(creature_class);    // game's bestiary
    let _ = TRACKER.record_xp(xp as u64);
}

// ImGui tab:
ueforge::Tab {
    name: "RPG",
    render: || ueforge::rpg::tab::render(&TRACKER, Some(&TOGGLES)),
}
```

That's a complete RPG mod. The game crate ships ~200-300 LoC
of catalog content + applier dispatch arms + format_effect text
+ kill_hook trampoline. ueforge ships everything else.

## Cross-references

- [lifecycle.md](lifecycle.md) -- how ModInfo wires the tab in
- [hooks.md](hooks.md) -- the kill_hook surface that drives
  `record_xp`
- [ue-sdk.md](ue-sdk.md) -- the ClassRef/TypedField/PlayerRef
  helpers your applier uses for actual writes
- [PERFORMANCE.md](PERFORMANCE.md) -- VanillaCache rationale,
  hot-path discipline for trampolines
