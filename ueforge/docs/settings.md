# Settings

> **Authoritative on:** `ueforge::settings::Settings<T>` -- the
> JSON config-file pattern every ueforge mod uses for user-
> facing configuration.

ueforge ships a tiny generic settings store. Game crates declare
a serde struct, ueforge handles JSON load + atomic save +
defaults + log lines.

## Settings<T>

```rust
pub struct Settings<T> { /* ... */ }

impl<T: Serialize + DeserializeOwned + Default + Clone> Settings<T> {
    pub fn load(filename: &str) -> Self;
    pub fn get(&self) -> T;             // clone of current value
    pub fn save(&self) -> Result<(), io::Error>;
    pub fn update(&self, f: impl FnOnce(&mut T));
    pub fn replace(&self, new: T);
}
```

### Load

```rust
let settings = ueforge::settings::Settings::<MySettings>::load("settings.json");
```

`load(filename)`:
- Opens `<DLL_dir>/<filename>`.
- If file exists + parses, loads it.
- If file is missing, writes `T::default()` and loads that.
- If file is malformed, logs the error + falls back to
  `T::default()` (does NOT overwrite the bad file -- so the
  user can hand-fix it).

Returns a `Settings<T>` wrapping a `Mutex<T>` + the path. Always
returns; never panics.

### Read

```rust
let cur = settings.get();           // Clone of the current value.
println!("multiplier = {}", cur.survival.hunger_multiplier);
```

`get()` clones the inner T. That keeps the returned value
independent of subsequent updates -- typical pattern is to read
once at slot activation and pass the snapshot to the apply
path.

### Write (atomic)

```rust
settings.update(|s| {
    s.rpg.buggy_kill_xp_multiplier = 0.5;
});
// inner Mutex flipped + atomic temp+rename to disk
```

Writes go through temp + rename. Caveat: no fsync before
rename today (kovarex P0 in flight); a power-cut between rename
and disk-flush leaves a torn file.

### Defaults via serde

The recommended schema shape uses `#[serde(default)]` on every
field so adding new settings doesn't break existing user files:

```rust
#[derive(Serialize, Deserialize, Default, Clone)]
pub struct MySettings {
    #[serde(default)]
    pub inventory: InventorySettings,
    #[serde(default)]
    pub survival: SurvivalSettings,
    #[serde(default)]
    pub debug: DebugSettings,
}

#[derive(Serialize, Deserialize, Default, Clone)]
pub struct InventorySettings {
    #[serde(default = "default_slot_count")]
    pub slot_count: i32,
}

fn default_slot_count() -> i32 { 100 }
```

Every nested struct should `Derive(Default)` so omitting the
key from the user's JSON gives a sensible default.

## On-disk path

`<DLL_dir>/<filename>`. `dll_dir()` resolves to whatever folder
the cdylib loaded from (typically
`<game>\Binaries\Win64\ue4ss\Mods\<mod>\dlls\`).

Files are pretty-printed JSON (indented). User-editable.

## settings.example.json

Convention: ship a `settings.example.json` next to your `Cargo.toml`.
The deploy CLI optionally copies it to the game install on first
deploy. Never overwrite an existing user `settings.json` --
respect their tweaks.

## Loading sequence

In your worker thread:

```rust
unsafe fn worker() {
    let settings = ueforge::settings::Settings::<g2rpg::Settings>::load("settings.json");
    let cur = settings.get();
    cur.log_summary();   // log what we loaded -- helps in support tickets

    // ... use cur for the rest of init ...

    // If you want hot-reload later, you'd watch the file and call
    // settings.replace(new_value) to swap in. Not implemented today.
}
```

## Anti-patterns

- **Don't pass `&Settings<T>` everywhere.** It's a `Mutex<T>`;
  every read locks. Pass the snapshot `T` (clone once) by ref.
- **Don't gate game-thread reads on `settings.get()`.** Each
  `get()` clones. For a hot path, atomic-cache the relevant
  value (e.g. an `AtomicU32` shadowing `settings.rpg.buggy_kill_xp_multiplier.to_bits()`).
- **Don't store secrets.** Settings files are plain-text JSON
  on disk; users will share them.

## Cross-references

- [lifecycle.md](lifecycle.md) -- where in the worker thread
  settings load
- [rpg.md](rpg.md) -- how `GameApplier` stores the settings
  snapshot
- `../README.md` -- `[package.metadata.ueforge]` block + deploy
  flow
