# Building

> Build prereqs, env vars, and the common failure modes. Both
> system deps are one-time installs.

## Toolchain

Whatever Rust toolchain the workspace uses (see
`../../rust-toolchain.toml`). The crate is a normal workspace
member; `cargo build -p falcon_printer` works from anywhere
inside the workspace.

## System deps

Two C-toolchain components are required because Falcon's
dep graph compiles bundled C sources:

### LLVM (provides libclang.dll)

Needed by `bad64-sys` (Falcon's ARM64 decoder, transitively
pulled in) which uses bindgen.

Install:
```powershell
winget install --id LLVM.LLVM --silent `
    --accept-source-agreements --accept-package-agreements
```

After install, set the path Cargo uses:
```powershell
$env:LIBCLANG_PATH = "C:/Program Files/LLVM/bin"
```

Persist by adding to your PowerShell profile or system
environment variables; otherwise every fresh shell needs
the line above.

### CMake (Capstone bundled source)

Needed by `falcon_capstone` which builds Capstone via cmake.

Install:
```powershell
winget install --id Kitware.CMake --silent `
    --accept-source-agreements --accept-package-agreements
```

Add to PATH:
```powershell
$env:PATH += ";C:/Program Files/CMake/bin"
```

Same persistence note as LLVM.

## Build

Cold:
```powershell
$env:LIBCLANG_PATH = "C:/Program Files/LLVM/bin"
$env:PATH += ";C:/Program Files/CMake/bin"
cargo build --release -p falcon_printer
```

Wall time: ~2 minutes the first time (capstone C build + bindgen
+ Falcon compile). Incremental rebuilds of the printer itself
are seconds.

Single binary:
```powershell
cargo build --release --bin falcon-printer -p falcon_printer
```

## Common failures

### `couldn't find any valid shared libraries matching: ['clang.dll', 'libclang.dll']`

LLVM not installed or `LIBCLANG_PATH` not set. Run the LLVM
install and the env-var line above.

### `failed to execute command: program not found  is cmake not installed?`

CMake not installed or not in PATH. Run the CMake install
and add `C:/Program Files/CMake/bin` to PATH.

### `error: failed to select a version for the requirement falcon = "0.6"`

Old Cargo.lock pinning. Run `cargo update -p falcon` or
delete the lock and rebuild.

### bad64-sys build script fails on missing host triple

Bindgen edge case on some Windows configs. Workaround: set
`TARGET=x86_64-pc-windows-msvc` before building. If it
persists, file upstream against `bad64-sys` (not Falcon).

### "linker `link.exe` not found"

MSVC build tools not installed. Run `rustup default
stable-x86_64-pc-windows-msvc` and let it pull what it
needs, or install the Visual Studio Build Tools manually.

## CI

Not wired yet. Two requirements before adding to a workflow:

1. Cache LLVM + CMake installs so each run doesn't re-download.
2. Provide a synthetic test binary (~1 MB PE built from a
   small C file) since we obviously can't ship Horsey.exe in
   CI. Lift a known function, snapshot the output with
   `insta`, fail if it changes unexpectedly.

Both are achievable but not a priority while the printer
output is still rapidly evolving.

## Workspace integration

The crate is a normal `[workspace] members` entry in
`../../Cargo.toml`. Other crates can depend on it, though no
crate does today: falcon-printer is a tool, not a library.
The `falcon` dep is at `Cargo.toml` v0.6; pin a higher version
when upstream ships the SSE semantics we're missing.

## Target dir

Workspace target dir is `../../target/`. Spike binaries land
at `../../target/release/<binname>.exe` and
`../../target/x86_64-pc-windows-msvc/release/<binname>.exe`
on this Windows box. PowerShell snippets in
[`usage.md`](usage.md) assume the former path.
