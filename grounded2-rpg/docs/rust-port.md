# Rust port plan: grounded2mods

> **Authoritative on:** the C++-to-Rust port history. Why we
> ported, the target architecture, the migration sequence, and
> the bugs we hit during testing. The port is complete; this is
> kept as design history. The original C++ tree is preserved at
> [`../archive/winhttp-proxy/`](../archive/winhttp-proxy/) for
> reference.

We ported the native DLL mod toolchain from C++ to Rust ahead of
building out a multi-mod monorepo. This doc captures the target
architecture, the scope of the first port (Grounded 2 - RPG System), and
the migration sequence.

This doc is the spec. The C++ tree under `grounded2-rpg/` stays put as the
reference implementation until the Rust version reaches behavior parity.

## Goals

- **Two Rust crates in a workspace.** One `cdylib` for the mod itself
  (SDK shim + hooks + mod logic, all in modules), and one `bin` crate for
  the injector. Two crates, not three or five. The mod crate stays
  module-internal, we are not building a framework; we are building one
  mod plus the loader that injects it.
- Zero `unsafe` in mod-level modules. All pointer math sits behind safe
  wrappers in an internal `sdk` module.
- Compile-time validation of parms struct layouts (`#[repr(C)]` + offset
  asserts) so a mismatched UFunction parameter layout is a build error, not a
  runtime crash.
- Cargo-native tooling: `cargo fmt`, `cargo clippy`, `cargo test`,
  `cargo doc`. No cmake, no MSBuild.

If we ever build a second mod that wants to share this code, *then* we
extract a crate. Until then, modules.

## Non-goals

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
  Cargo.toml                # [workspace] members = ["grounded2-rpg", "injector"]
  rust-toolchain.toml       # stable + msvc target
  .cargo/config.toml        # target triple, linker flags

  grounded2-rpg/          # cdylib: the mod itself
    Cargo.toml              # crate-type = ["cdylib"]
    src/
      lib.rs                # DllMain + worker entry, top-level wiring
      sdk/
        mod.rs
        uobject.rs          # UObject, UClass, UFunction wrappers
        fstring.rs          # FString <-> String
        tarray.rs           # TArray<T> read-only view
        gobjects.rs         # GObjects walker, IsA, FindClassFast
        process_event.rs    # ProcessEvent invoke + Parms trait
        offsets.rs          # SDK-version-coupled offset constants
      hook/
        mod.rs
        vtable.rs           # vtable slot patcher (VirtualProtect dance)
        process_event.rs    # RAII ProcessEventHook
      log.rs                # console + file logger, batched flush
      patch.rs              # backpack DefaultMaxSize patcher
      inv_hook.rs           # WBP_InventoryInterface_C hook + viewport rebind
      parms.rs              # #[repr(C)] parms structs with layout asserts
    tests/
      layout.rs             # static_assertions for offsets/sizes

  injector/                 # bin: standalone DLL injector
    Cargo.toml              # [[bin]] name = "inject"
    src/
      main.rs               # arg parsing, find/launch process, inject DLL
      inject.rs             # CreateRemoteThread + LoadLibraryW dance

  archive/winhttp-proxy/      # OLD C++ tree, renamed, kept until parity
    (existing files moved here)

  inject-c/                 # OLD inject.c, kept until Rust injector parity
    (existing inject.c moved here)
```

Workspace `Cargo.toml` enables `[profile.release] lto = "fat"`,
`codegen-units = 1`, `panic = "abort"` so the cdylib is small and the hot
path inlines aggressively.

Module visibility (within `grounded2-rpg`): `sdk` and `hook` modules are
`pub(crate)`, exposed to the rest of the crate, not to external consumers
(there are none).

The `injector` crate does **not** depend on `grounded2-rpg`. They share
nothing. The injector takes a path-to-DLL on the CLI and injects it.

## Module boundaries

### `sdk` module

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
`write_field`, the operations whose correctness depends on the caller
knowing the offset and parms layout match the running game binary.
Everything else (FindClassFast, IsA, GetFullName) is safe.

`offsets.rs` is the version-coupled file; one constant per offset we use.
When the game patches and offsets shift, this is the file we update. CI
should ideally diff it against a freshly dumped Dumper-7 header.

### `hook` module

```rust
pub(crate) struct ProcessEventHook { ... }
impl ProcessEventHook {
    pub fn install<F>(class_name: &str, handler: F) -> Result<Self>
    where F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + 'static;
}
impl Drop for ProcessEventHook { fn drop(&mut self) { /* restore vtable slot */ } }
```

The hook handler is a `Fn` so the inv-hook module registers its logic
without us hand-writing one giant function. Calling the original is done via
the `OriginalProcessEvent` arg.

### `log` module

Console + file sink, batched flush from worker. No `fflush` per line.

### `injector` crate (separate)

Standalone Rust binary that replaces `inject.c`. CLI:

```
inject.exe --process Maine-Win64-Shipping.exe --dll path/to/grounded2_rpg.dll
```

Implementation:

- `windows-sys` for `OpenProcess`, `VirtualAllocEx`, `WriteProcessMemory`,
  `CreateRemoteThread`, `GetProcAddress("LoadLibraryW")`.
- Wide-string the DLL path, write it into the target, kick off
  `LoadLibraryW` on a remote thread, wait for thread exit, free the remote
  buffer.
- Optional `--wait` flag to poll for the process if not yet launched.
- Optional `--launch` flag to start the game exe ourselves.
- Exit non-zero on any failure with a clear error message.

Self-contained, no shared deps with `grounded2-rpg`. Builds to
`target/release/inject.exe`.

### `lib.rs` (top level of grounded2-rpg)

DllMain (via `define_dllmain!` macro inside the crate), worker thread entry,
top-level wiring of patch + hook. Should be small, target <150 lines.

```rust
define_dllmain!(worker);

fn worker() -> Result<()> {
    let log = init_log(&temp_path("Grounded2RPG.log"))?;
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
`cfg!(debug_assertions)` or an env var read once at startup, never
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

1. `cargo build --release --target x86_64-pc-windows-msvc` from the
   workspace root builds both crates: `grounded2_rpg.dll` (cdylib) and
   `inject.exe` (binary). Outputs land in
   `target/x86_64-pc-windows-msvc/release/`.
2. `inject.exe --process Maine-Win64-Shipping.exe --dll
   .\grounded2_rpg.dll` injects the DLL.
3. `cargo xtask package` (later) zips both artifacts + README into
   `dist/grounded2-rpg-X.Y.Z.zip` for users.

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
*for our needs*, deviate, but document why in this file or in code
comments.

We are **not** depending on endless as a crate. It's a cross-repo style
guide and reference, not a library.

## Migration sequence

Numbered so we can check them off.

- [x] **1.** Rename current `grounded2-rpg/` -> `archive/winhttp-proxy/`.
  (`inject.c` lives inside that tree, so one rename covered both.)
- [x] **2.** Add workspace `Cargo.toml`, `rust-toolchain.toml`,
  `.cargo/config.toml` (the last overrides a global `target-dir` that was
  redirecting our build into `C:\code\endless\rust\target`).
- [x] **3.** Create `injector/` bin crate. Port `inject.c` to Rust. Build
  green, RAII handle/alloc guards, same exit codes / messaging.
- [x] **4.** Create `grounded2-rpg/` cdylib skeleton with `sdk/` module:
  `UObject`, `UClass`, `UFunction`, `FName` (with `AppendString` resolver),
  `FString`, `TArray`, `GObjectsView`, `Runtime`, `find_class_fast`. Layout
  tests pass; `cargo clippy --all-targets, -D warnings` clean. The lib is
  `cdylib + rlib` so the integration tests can link it.
- [x] **5.** Add `hook/` module: vtable patcher + `ProcessEventHook` RAII
  wrapper (registry-based dispatch by live vtable, `catch_unwind` around
  the user closure so a panic falls through to the engine's original
  ProcessEvent). Add `log` module (file-only at `%TEMP%\Grounded2RPG.log`
  for now, console output deferred). The `define_dllmain!` macro was
  inlined into `lib.rs` since there's only one DllMain to write.
- [x] **6.** Wire up the patch loop. Worker does log init -> platform
  detect (Steam/Xbox by exe name) -> SDK runtime init -> wait for
  GObjects -> initial DefaultMaxSize patch -> 10s rescan loop. **Validated
  in-game**: log shows
  `Default__BP_SurvivalPlayerCharacter_C.InventoryComponent: 40 -> 100,
  verify=100`. AllocConsole brought back so the live mod log surfaces in
  a "Grounded 2 - RPG System" console window the way the C++ build did.
- [x] **7.** Port the inventory-interface hook + viewport rebind in
  `inv_hook.rs` + `parms.rs`. Single hook surface
  (`WBP_InventoryInterface_C`). All function dispatch goes through cached
  `&UFunction` pointer identity, not name compares. Trace logs gated by
  `cfg!(debug_assertions)`, silent in release. **Hook installs in-game**:
  log shows `inv hook: installed on WBP_InventoryInterface_C` once the
  inventory UI loads. (Required two bug fixes during testing, see "Bugs
  found and fixed" below.)
- [x] **8.** Trace surfaces gated under `cfg!(debug_assertions)`. The
  inventory-interface trace lines in `inv_hook.rs` are already debug-only
 , release builds compile them out. The C++ tree's broader BPF / grid /
  menu trace coverage is intentionally **not** ported; the audit found it
  was the dominant source of hot-path overhead and the targeted hook +
  cached `UFunction*` dispatch makes it unnecessary. We can revisit if a
  specific debug session needs it.
- [ ] **9.** Side-by-side test: run C++ DLL one session, Rust DLL the next.
  Check identical patch behavior, identical scroll behavior, lower CPU on a
  sampled frame profile.
- [ ] **10.** Move `archive/winhttp-proxy/` to `archive/` once parity is
  confirmed for two play sessions.
- [x] **11.** `building.md` written at the repo root. Covers
  prerequisites, build, run, quality gates, configuration knobs, and how
  to retarget for a future game patch via `sdk/offsets.rs`.

Each step lands as its own commit.

## What stays C++ (for now)

- The Dumper-7 generated SDK headers we keep as offset reference material.
  Live in `reference/SDK/` or similar; never compiled.

## Bugs found and fixed during testing

1. **GObjects extra indirection** (grounded2-rpg/src/sdk/uobject.rs).
   `GObjectsView::from_image` was treating `image_base + g_objects` as a
   pointer-to-pointer and dereferencing once, so `array` was actually
   `Objects[0]` (the first FUObjectItem) and `num()` read random bytes.
   Symptom: log halted after platform detection because num() returned 0
   (or junk) forever. Fix: use the address directly as the
   `TUObjectArray` struct, matching the C++ wrapper's
   `reinterpret_cast<TUObjectArray*>(addr)`.

2. **find_class_fast missed Blueprint classes** (same file). The
   meta-class filter was `cls.as_object().name() == "Class"`, which only
   matches *native* UClass instances. Blueprint-generated classes like
   `WBP_InventoryInterface_C` have meta-class
   `WidgetBlueprintGeneratedClass`, a subclass of `Class`. Symptom: the
   inventory hook never installed even after the inventory UI was opened.
   Fix: walk the meta-class's `super_class` chain looking for an ancestor
   named `"Class"`.

3. **Injector defaulted to PascalCase DLL name**. Rust cdylib output is
   `grounded2_rpg.dll` (lib name -> snake_case), but the injector's
   default lookup was `Grounded2RPG.dll`, so a flag-less invocation
   loaded the old C++ DLL or failed silently. Fix: injector default
   lowered to match the cdylib output.

4. **Console window for live output**. The C++ build called
   `AllocConsole` from the DLL so users got a live "Grounded 2 - RPG System"
   console window. The first Rust pass dropped this for build simplicity,
   which broke the user's expected debug surface. Fix: AllocConsole +
   `WriteConsoleA` brought back; logs also go to
   `%TEMP%\Grounded2RPG.log` for durability.

5. **Injector closed too fast to read**. Double-clicking inject.exe
   spawned a console that closed when the process exited, making errors
   invisible. Fix: pause-before-exit by default (skip with `--no-pause`)
   and a per-run `inject.log` next to the exe.

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
C++ thiscall layout on the hook-original callback path, I've done it
before but want to validate at step 4 before committing to the design.
