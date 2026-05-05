# Rust port plan: grounded2mods

We're porting the native DLL mod toolchain from C++ to Rust ahead of building
out a multi-mod monorepo. This doc captures the target architecture, the
scope of the first port (Better Backpack), and the migration sequence.

This doc is the spec. The C++ tree under `better-backpack/` stays put as the
reference implementation until the Rust version reaches behavior parity.

## Goals

- One Cargo workspace at the repo root that builds every mod DLL.
- A reusable SDK shim crate so every future mod imports `UObject`, `UFunction`,
  `ProcessEvent` hooking, etc. without re-deriving them.
- Zero `unsafe` in mod-level code. All pointer math sits behind safe wrappers
  in the SDK crate.
- Compile-time validation of parms struct layouts (`#[repr(C)]` + offset
  asserts) so a mismatched UFunction parameter layout is a build error, not a
  runtime crash.
- Cargo-native tooling: `cargo fmt`, `cargo clippy`, `cargo test`,
  `cargo doc`. No cmake, no MSBuild.

## Non-goals

- Replacing the existing C++ injector (`inject.c`). The injector is a tiny
  separate concern and stays in C for now -- it's standalone and works.
- Rewriting Dumper-7. We keep using the C++ headers it generates as a
  *reference* for offsets and struct layouts; we just don't compile against
  them.
- Hot-reloadable mods. Out of scope. DLL injects once per game launch.
- Cross-game abstraction. We will *design* the SDK shim so a future
  `unreal-sdk-core` extraction is feasible, but we are not building it on
  this pass.

## Target repo layout

```
grounded2mods/
  Cargo.toml                # [workspace] members = ["sdk", "hook-core", "better-backpack"]
  rust-toolchain.toml       # pin stable + msvc target

  sdk/                      # crate: grounded2-sdk
    Cargo.toml
    src/
      lib.rs
      uobject.rs            # UObject, UClass, UFunction wrappers
      fstring.rs            # FString <-> String
      tarray.rs             # TArray<T> read-only view
      gobjects.rs           # GObjects walker, IsA, FindClassFast
      process_event.rs      # ProcessEvent invoke + parms struct trait
      offsets.rs            # SDK-version-coupled offset constants
    tests/
      layout.rs             # static_assertions for offsets/sizes

  hook-core/                # crate: grounded2-hook-core
    Cargo.toml
    src/
      lib.rs
      vtable.rs             # vtable slot patcher (VirtualProtect dance)
      process_event_hook.rs # RAII ProcessEventHook<T>
      log.rs                # console + file logger, ring-buffered
      dll_main.rs           # macro: define_dllmain!(worker_fn)

  better-backpack/          # crate: better-backpack (cdylib)
    Cargo.toml              # crate-type = ["cdylib"]
    src/
      lib.rs                # DllMain + worker entry
      patch.rs              # backpack DefaultMaxSize patcher
      hook.rs               # WBP_InventoryInterface_C hook + viewport rebind
      parms.rs              # #[repr(C)] parms structs with layout asserts

  better-backpack-cpp/      # OLD C++ tree, renamed, kept until parity
    (existing files moved here)

  inject/                   # existing inject.c, untouched
```

Workspace `Cargo.toml` enables `[profile.release] lto = "fat"`, `codegen-units = 1`,
`panic = "abort"` so the cdylib is small and the hot path inlines aggressively.

## Crate boundaries

### `grounded2-sdk`

Mirrors the subset of Dumper-7 we actually use. Hand-written, not generated.

Public surface:

```rust
pub struct UObject(NonNull<RawUObject>);
impl UObject {
    pub fn class(&self) -> &UClass;
    pub fn get_full_name(&self) -> String;
    pub fn get_name(&self) -> String;
    pub fn is_a(&self, class: &UClass) -> bool;
    pub fn is_default_object(&self) -> bool;
    pub unsafe fn process_event<P: Parms>(&self, func: &UFunction, parms: &mut P);
    pub unsafe fn read_field<T: Copy>(&self, offset: usize) -> T;
    pub unsafe fn write_field<T: Copy>(&self, offset: usize, value: T);
    pub unsafe fn read_object_ptr(&self, offset: usize) -> Option<&UObject>;
}

pub struct UClass(/* extends UObject */);
impl UClass {
    pub fn class_default_object(&self) -> Option<&UObject>;
    pub fn get_function(&self, owner: &str, name: &str) -> Option<&UFunction>;
}

pub struct UFunction(/* extends UObject */);
impl UFunction {
    pub fn function_flags(&self) -> u32;
    pub fn set_function_flags(&self, flags: u32);  // takes &self, interior mut via UnsafeCell
}

pub fn find_class_fast(name: &str) -> Option<&'static UClass>;
pub fn gobjects() -> &'static GObjects;

pub struct GObjects { ... }
impl GObjects {
    pub fn len(&self) -> usize;
    pub fn iter(&self) -> impl Iterator<Item = &UObject>;
}

pub struct FString { ... }  // owning, drops the engine-side allocation
impl FString {
    pub fn as_str(&self) -> Cow<'_, str>;  // UTF-16 -> UTF-8
}

#[repr(C)]
pub struct TArray<T> { data: *mut T, num: i32, max: i32 }
impl<T> TArray<T> { pub fn as_slice(&self) -> &[T]; pub fn len(&self) -> i32; }

pub trait Parms { /* marker, requires #[repr(C)] */ }
```

The `unsafe` bubbles up only on `process_event`, `read_field`, and
`write_field` -- the operations whose correctness depends on the caller
knowing the offset and parms layout match the running game binary.
Everything else (FindClassFast, IsA, GetFullName) is safe.

`offsets.rs` is the version-coupled file; one constant per offset we use.
When the game patches and offsets shift, this is the file we update. CI
should ideally diff it against a freshly dumped Dumper-7 header.

### `grounded2-hook-core`

```rust
pub struct ProcessEventHook { ... }
impl ProcessEventHook {
    pub fn install<F>(class_name: &str, handler: F) -> Result<Self>
    where F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + 'static;
}
impl Drop for ProcessEventHook { fn drop(&mut self) { /* restore vtable slot */ } }

pub struct LogSink { ... }   // console + file, batched flush from worker
pub fn init_log(path: &Path) -> Result<&'static LogSink>;

#[macro_export]
macro_rules! define_dllmain {
    ($worker:path) => { /* DllMain + CreateThread boilerplate */ };
}
```

The hook handler is a `Fn` so each mod registers its own logic without us
hand-writing `HookedInventoryInterfaceProcessEvent`. Calling the original is
done via the `OriginalProcessEvent` arg, which is safe to call.

### `better-backpack`

The actual cdylib. Pure mod logic on top of the two crates above. Should be
small -- target <300 lines.

```rust
define_dllmain!(worker);

fn worker() -> Result<()> {
    let log = init_log(&temp_path("BetterBackpack.log"))?;
    wait_for_gobjects()?;

    let _hook = ProcessEventHook::install("WBP_InventoryInterface_C", on_inv_iface_event)?;

    patch::patch_player_backpacks_to(SLOT_COUNT)?;

    loop {
        std::thread::sleep(RESCAN_INTERVAL);
        patch::repatch_if_reverted(SLOT_COUNT)?;
    }
}
```

`on_inv_iface_event` does the cached-`UFunction*` pointer compare instead of
the C++ `fnName == "..."` string chain. Trace logging is gated behind a
`cfg!(debug_assertions)` or an env var read once at startup -- never
unconditional.

## Compile-time layout validation

For every parms struct (`RefreshInventoryGridParms`,
`GetItemInItemListSlotParms`, etc.):

```rust
#[repr(C)]
pub struct RefreshInventoryGridParms {
    pub item_list: TArray<*mut UObject>,
    pub grid_panel: *mut UObject,
    pub row_max: i32,
    pub column_max: i32,
    pub item_start_index: i32,
    pub world_context: *mut UObject,
}

const _: () = {
    use memoffset::offset_of;
    assert!(offset_of!(RefreshInventoryGridParms, grid_panel) == 0x10);
    assert!(offset_of!(RefreshInventoryGridParms, item_start_index) == 0x20);
    assert!(std::mem::size_of::<RefreshInventoryGridParms>() == 0x30);
};
```

Offsets cross-checked against the Dumper-7 header. Layout drift after a game
patch becomes a compile error, not a stack smash.

## Build and inject story

1. `cargo build --release --target x86_64-pc-windows-msvc -p better-backpack`
   produces `target/x86_64-pc-windows-msvc/release/better_backpack.dll`.
2. The existing `inject.c` injector points at that path. No changes to the
   injector.
3. `cargo xtask package` (later) zips the DLL + injector + README into
   `dist/better-backpack-X.Y.Z.zip` for users.

## Toolchain

**Rule: latest version of everything.** Latest stable Rust, latest published
release of every crate, latest Windows SDK target. No pinning to old majors
"because that's what some other project uses." If a dep has a 1.x and a 2.x,
we use 2.x. We re-run `cargo update` and bump `Cargo.toml` ranges before
each release.

- `rust-toolchain.toml` pins to current stable channel (auto-updates) with
  target `x86_64-pc-windows-msvc`.
- Crates we'll lean on (always latest at port time, then maintained
  forward):
  - `windows-sys` for WinAPI (VirtualProtect, CreateThread, GetModuleHandleW,
    AllocConsole, GetTempPathA, etc.). No `winapi`.
  - `widestring` for UTF-16 / FString conversions.
  - `memoffset` for compile-time offset asserts.
  - `parking_lot` if we end up needing a mutex anywhere (hopefully not in
    the hot path).
  - `tracing` + `tracing-subscriber` *only* if log volume justifies it; for
    now a simple ring-buffered file sink is fine.
- No `tokio`, no async. All threading is bare `std::thread`.

## Reference: endless repo

We have an existing Rust codebase at `C:/code/endless` (Bevy game) that
already solves a lot of the surrounding problems we'd otherwise re-derive:

- Cargo workspace shape with multiple cdylib + bin crates.
- `windows-sys` usage patterns and target triple setup.
- `tracing` configuration and ring-buffered logging.
- CI / build automation conventions (GitHub Actions, release packaging).
- `xtask` pattern for build/dist/package commands.
- `rust-toolchain.toml` and `.cargo/config.toml` conventions.

When in doubt about layout, dependency choice, or build scripts, **check
endless first** and copy its conventions. Same dotfiles, same lint config,
same `cargo fmt` / `clippy` settings. Where endless is wrong or outdated
*for our needs*, deviate -- but document why in this file or in code
comments.

We are **not** depending on endless as a crate. It's a cross-repo style
guide and reference, not a library.

## Migration sequence

Numbered so we can check them off.

1. Rename current `better-backpack/` -> `better-backpack-cpp/`. Keep building.
2. Add workspace `Cargo.toml` + `rust-toolchain.toml`.
3. Create `sdk/` skeleton: `UObject`, `UClass`, `UFunction`, `FString`,
   `TArray`, `GObjects`, `find_class_fast`. Port enough to compile and pass
   layout tests against a known offset.
4. Create `hook-core/`: vtable patcher + `ProcessEventHook` RAII wrapper +
   `define_dllmain!` macro + log sink.
5. Create `better-backpack/` cdylib with just the patch loop (no hook yet).
   Inject and confirm: backpack grows to 100, log file written, behavior
   matches the C++ baseline minus scrolling.
6. Port the inventory-interface hook + viewport rebind. Cache `UFunction*`
   instead of name compares. Default trace flags off. Confirm scrolling
   parity in-game.
7. Port the BPF / grid / menu trace surfaces only as `cfg!(debug_assertions)`
   helpers. Ship build doesn't compile them in.
8. Side-by-side test: run C++ DLL one session, Rust DLL the next. Check
   identical patch behavior, identical scroll behavior, lower CPU on a
   sampled frame profile.
9. Move `better-backpack-cpp/` to `archive/` once parity is confirmed for two
   play sessions.
10. Write `BUILDING.md` for the Rust path. Retire the C++ build docs.

Each step lands as its own commit. Don't merge the workspace until step 5
runs end-to-end.

## What stays C++ (for now)

- `inject.c` (separate process, doesn't benefit from rewrite).
- The Dumper-7 generated SDK headers we keep as offset reference material.
  Live in `reference/SDK/` or similar; never compiled.

## Open questions

- DllMain TLS hazard: Rust's std spawns thread-local init on first use. If
  any std fn we call inside `DllMain` itself touches TLS, we crash on load.
  Mitigation: do *nothing* in DllMain except `CreateThread` -> our worker.
  The worker does all `std` work. The `define_dllmain!` macro should enforce
  this shape.
- Panic strategy: `panic = "abort"` in release means an unwrap inside a hook
  takes the game down. We need a hook-level `catch_unwind` or strict no-panic
  discipline in hot paths. Decision: every hook closure wraps its body in
  `catch_unwind`, logs, and falls through to the original ProcessEvent.
- Allocator: stick with the system allocator. No mimalloc / jemalloc until
  profiling justifies it.
- Hot reload: explicitly out of scope. The DLL loads once.

## Confidence

Plan confidence: 8/10. The crate split, build target, and migration
sequence are concrete and standard. The two unknowns are (a) how cleanly
`UClass::get_function` translates without pulling in more SDK surface than
expected, and (b) whether `process_event` from Rust correctly matches UE's
C++ thiscall layout on the hook-original callback path -- I've done it
before but want to validate at step 4 before committing to the design.
