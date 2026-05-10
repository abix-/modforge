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

Writes go through temp + rename inside the inner mutex, so
concurrent updates serialize cleanly. POSIX rename semantics
guarantee atomicity; on Windows `std::fs::rename` over an
existing file has been atomic since 1809.

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
}
```

## Hot-reload (`Settings::watch`)

```rust
let settings = Arc::new(Settings::<MySettings>::load("settings.json"));
let _handle = settings.watch(
    Duration::from_secs(2),
    |new: &MySettings| {
        // Push the new snapshot into per-feature atomics, re-apply
        // CDO writes, etc. Runs on the watcher thread.
    },
);
```

`watch` spawns a worker thread that polls the file's mtime
every `interval` and calls `Self::reload()` whenever it
changes. On parse / IO error the in-memory state is left
untouched and a log line is emitted; subsequent successful
reloads recover. Returns a `WatchHandle`; dropping it asks the
poller to stop at its next tick.

### Teardown registry

Every `watch` spawn auto-registers a `(stop_flag, JoinHandle)`
into a static `WATCH_REGISTRY`. The framework's
`ueforge_mod_shutdown` macro path calls
`settings::shutdown_all()` after the HTTP listeners stop and
before the side-file rename:

```
on_shutdown
  -> hook::shutdown_all
  -> server::shutdown_all
  -> settings::shutdown_all   <-- stops + joins every watcher
  -> finalize_hot_reload_swap
```

This matters because UE4SS's Ctrl+R hot-reload calls
`FreeLibrary` after `ueforge_mod_shutdown` returns. A watcher
thread still on a stack inside our DLL when FreeLibrary lands
crashes the game on its next iteration. Auto-registration plugs
the leak that existed when consumers forgot to keep the
`WatchHandle` alive past the spawn.

The handle is still returned for callers that want early stop
(e.g. an op that disables hot-reload at runtime). Drop and
shutdown_all are independent stop knobs operating on the same
flag; the join happens at most once.

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
