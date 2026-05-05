# grounded2mods - project state

## Current focus
Porting the Better Backpack mod from C++ to a single Rust workspace
(cdylib + injector). C++ tree preserved at `better-backpack-cpp/` until the
Rust port reaches behavior parity. Plan in `RUST_PORT_PLAN.md`.

## Layout

```
grounded2mods/
  Cargo.toml                Workspace: better-backpack + injector
  rust-toolchain.toml       Stable, x86_64-pc-windows-msvc
  .cargo/config.toml        Target triple, target-dir override
  better-backpack/          cdylib + rlib (the mod itself)
    src/
      lib.rs                DllMain + worker entry
      sdk/                  Hand-written UE SDK shim
        offsets.rs          Steam/Xbox offset tables + field offsets
        fname.rs            FName + AppendString resolver
        fstring.rs          FString = TArray<u16>
        tarray.rs           TArray<T>
        uobject.rs          UObject/UClass/UFunction/GObjectsView/Runtime/find_class_fast
    tests/layout.rs         Static layout asserts
  injector/                 bin: standalone DLL injector (Rust port of inject.c)
  better-backpack-cpp/      OLD C++ tree, kept until Rust port hits parity
  RUST_PORT_PLAN.md         Migration plan (11 steps)
  better-backpack-cpp/PERFORMANCE_AUDIT.md   What we found in the C++ hot path
```

## Mod target (carried over from C++ port)
- Player main backpack capacity = `Maine.UInventoryComponent +0x01E0`
  (`int32 DefaultMaxSize`). Vanilla 40; target 100.
- Mount/saddlebag (vanilla 30) is left untouched.
- Viewport stays 4x10 in the live UI; we rebind 40 visible slots against
  shifting `ItemStartIndex` to scroll. The earlier 6-row growth path is
  retired.

## Key facts
- Game exes: Steam = `Grounded2-WinGRTS-Shipping.exe`, Xbox = `Grounded2-WinGDK-Shipping.exe`.
- Steam offsets (image-relative): GObjects=0x09F67028, AppendString=0x01252060, ProcessEventIdx=0x4C.
- Xbox offsets: GObjects=0x09F36F28, AppendString=0x01250F80, ProcessEventIdx=0x4C.
- UObject layout: vtable@0x00, flags@0x08, index@0x0C, class@0x10, name@0x18, outer@0x20, size=0x28.
- UClass: ClassDefaultObject@0x110. UFunction: FunctionFlags@0xB0.
- Build target dir overridden locally (~/.cargo/config.toml redirects to endless).

## Migration progress (RUST_PORT_PLAN.md)
- [x] 1. Rename C++ tree -> better-backpack-cpp.
- [x] 2. Workspace: Cargo.toml + rust-toolchain.toml + .cargo/config.toml.
- [x] 3. Injector crate (Rust port of inject.c). Builds.
- [x] 4. SDK module skeleton (UObject, UClass, UFunction, FName, FString,
     TArray, GObjectsView, Runtime, find_class_fast). Layout tests pass.
- [x] 5. Hook module: vtable.rs (VirtualProtect-guarded slot rewrite) +
     process_event.rs (RAII ProcessEventHook with registry-based dispatch
     and catch_unwind around the closure). Log module (file-only at
     %TEMP%\BetterBackpack.log).
- [x] 6. Patch loop wired in. **Validated in-game**: patch line
     `Default__BP_SurvivalPlayerCharacter_C.InventoryComponent: 40 -> 100,
     verify=100`. AllocConsole brought back so the live mod log surfaces
     in a "Better Backpack" console window the way the C++ build did.
- [x] 7. Inventory-interface hook + viewport rebind. inv_hook.rs +
     parms.rs. Cached UFunction* identity dispatch (no name compares).
     Trace gated by cfg!(debug_assertions). Single hook surface.
     **Hook installs in-game** -- log shows
     `inv hook: installed on WBP_InventoryInterface_C` once inventory UI
     loads.
- [ ] 8. BPF/grid/menu trace surfaces gated under cfg!(debug_assertions).
- [ ] 9. Side-by-side parity test C++ vs Rust DLL.
- [ ] 10. Archive better-backpack-cpp/.
- [ ] 11. Rust BUILDING.md.

## Build commands
- `cargo build --release` builds both crates.
- `cargo test --release` runs layout tests.
- `cargo clippy --release --all-targets -- -D warnings` lint gate (clean today).
- Outputs: `target/x86_64-pc-windows-msvc/release/{better_backpack.dll, inject.exe}`.
- The DLL is locked while the game holds it -- rebuild requires the game to
  be closed (or use a different output dir).
- inject.exe with no args looks for `better_backpack.dll` next to itself
  (matches cdylib output name). Pass an explicit path to override.

## Logs
- Injector: `<inject.exe dir>/inject.log` -- truncated each run, captures
  every line it prints to console. Useful when the console window closes
  too fast to read.
- Mod: `%TEMP%\BetterBackpack.log` -- truncated each DLL load, captures the
  worker thread's log lines. First-line tell for the Rust build is
  `=== Better Backpack DLL (rust) ===`.

## Bugs found and fixed during testing
- **GObjects extra indirection** (2026-05-04): GObjectsView::from_image was
  treating `image_base + g_objects` as a pointer-to-pointer and
  dereferencing once. The address IS the TUObjectArray struct directly.
  Symptom: log halted after platform detection. Fixed in sdk/uobject.rs.
- **find_class_fast missed Blueprint classes** (2026-05-04): meta-class
  filter only matched native `Class`. Blueprint-generated classes have
  meta-class `WidgetBlueprintGeneratedClass` (a subclass of `Class`).
  Symptom: inventory hook never installed. Fix: walk meta-class
  super_class chain.
- **Injector default DLL name PascalCase mismatch**: cdylib output is
  `better_backpack.dll`; injector default was `BetterBackpack.dll`. Fixed
  injector to match cdylib output.
- **Live console missing**: C++ DLL spawned a console via AllocConsole;
  Rust DLL had to too. Re-added with WriteConsoleA + file mirror.
- **Injector closed too fast**: added pause-before-exit (--no-pause to
  skip) and per-run inject.log.

## Known minor issues
- Patch.rs logs "skipped N non-player components" on every rescan tick,
  even when nothing changed. Cleanup pending.
- The CDO patch only reaches inventory instances constructed AFTER the
  DLL loads. If the player's inventory was constructed before injection,
  a save reload may be required to see 100 slots in-game.

## Open questions
- Step 6 needs validation that calling `original` ProcessEvent from a Rust
  hook closure preserves UE's thiscall expectations on this platform.
- DllMain TLS hazard: keep DllMain to `CreateThread` only; all std work in
  the worker.
- Panic-in-hook: every hook closure wraps body in `catch_unwind`, falls
  through to original on panic.
