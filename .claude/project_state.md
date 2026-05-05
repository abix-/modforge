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
- [ ] 5. Hook module (vtable patcher + RAII ProcessEventHook), log sink,
     define_dllmain! macro, patch loop wired in.
- [ ] 6. Inventory-interface hook + viewport rebind.
- [ ] 7. BPF/grid/menu trace surfaces gated under cfg!(debug_assertions).
- [ ] 8. Side-by-side parity test C++ vs Rust DLL.
- [ ] 9. Archive better-backpack-cpp/.
- [ ] 10. Rust BUILDING.md.

## Build commands
- `cargo build --release` builds both crates.
- `cargo test --release` runs layout tests.
- `cargo clippy --release --all-targets -- -D warnings` lint gate (clean today).
- Outputs: `target/x86_64-pc-windows-msvc/release/{better_backpack.dll, inject.exe}`.

## Open questions
- Step 6 needs validation that calling `original` ProcessEvent from a Rust
  hook closure preserves UE's thiscall expectations on this platform.
- DllMain TLS hazard: keep DllMain to `CreateThread` only; all std work in
  the worker.
- Panic-in-hook: every hook closure wraps body in `catch_unwind`, falls
  through to original on panic.
