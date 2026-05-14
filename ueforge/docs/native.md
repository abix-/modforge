# Native (C++) surface

> **Authoritative on:** what C++ is in this repo, why each piece is
> irreducible, and what stays in Rust.

The repo is a Rust workspace. **All framework code, all mod code,
all tools, all tests are Rust.** The only C++ is at the UE4SS /
ImGui boundary. Contracts the engine and its plugin loader
expose as C++ APIs, where there is no Rust escape hatch.

## TL;DR

| | Where | Files | Lines |
|---|---|---|---|
| Dear ImGui v1.92.1 (third-party) | git submodule. NOT in this repo | 10 | 54,645 |
| ueforge shim (ours) | `ueforge/cpp/` | 4 | 502 |
| **First-party C++ in this repo** | | **4** | **502** |

The repo itself contains **502 lines of C++**. The irreducible
shim. ImGui's 54,645 lines live as a git submodule pointing at
[`ocornut/imgui` tag v1.92.1](https://github.com/ocornut/imgui/releases/tag/v1.92.1);
they're checked out into `ueforge/cpp/imgui/` after
`git submodule update --init` but never tracked in this repo.

Every mod, every framework subsystem, every test, every tool is
Rust. The 502-line shim is a fixed cost shared by every Rust mod
in the workspace. It does not grow as we add features.

Everywhere else in the workspace is 100% Rust. There is no game-
specific C++ in any mod crate. There is no RPG-system C++. There
is no inventory C++.

## Dear ImGui via submodule (54,645 lines, third-party, NOT in this repo)

`ueforge/cpp/imgui/` is a **git submodule** pointing at
[`ocornut/imgui`](https://github.com/ocornut/imgui) pinned to
tag `v1.92.1`. Byte-identical to UE4SS's bundled version. The
ImGui sources live in `ocornut/imgui` upstream; our repo carries
only a `.gitmodules` entry + a single commit hash reference. After
`git submodule update --init`, the sources are checked out into
`cpp/imgui/` and `build.rs` compiles them like any other source
file.

Updating to a new ImGui version (e.g. when UE4SS bumps):

```sh
cd ueforge/cpp/imgui
git checkout v1.93.0
cd ../../..
git commit -am "bump imgui to v1.93.0"
```

Forking is one line: change the URL in `.gitmodules` to a fork.

### Why vendor ImGui at all

UE4SS embeds ImGui v1.92.1. To draw on its window we have to call
the ImGui C++ API on the context UE4SS hands us. None of the
existing Rust ImGui crates (`imgui-rs`, `egui`, `dear_imgui`) is
ABI-compatible with a specific UE4SS build. They bundle their
own ImGui or use a different rendering path entirely. Mixing two
ImGui contexts in one process corrupts state.

### Why vendor THIS version exactly

UE4SS exposes ImGui's context to us via two function pointers
(`get_current_imgui_context` / `get_current_imgui_context_io`).
That context's internal representation is a specific layout
defined by ImGui v1.92.1's headers. If our calls were compiled
against a different ImGui version, we'd be writing to wrong
offsets inside the context struct. Result: visual corruption at
best, crashes at worst. Vendor exactly v1.92.1; nothing else.

When UE4SS upstream bumps ImGui, we sync in lockstep. Not
independently.

### What's in there

| File | Role |
|---|---|
| `imgui.cpp` | Core ImGui API (input, layout, drawing) |
| `imgui_draw.cpp` | Drawing primitives |
| `imgui_tables.cpp` | Tables / columns |
| `imgui_widgets.cpp` | Standard widgets (buttons, sliders, etc.) |
| `imgui.h`, `imgui_internal.h`, `imconfig.h` | Headers |
| `imstb_rectpack.h`, `imstb_textedit.h`, `imstb_truetype.h` | Upstream stb_* dependencies |

All compiled by ueforge's `build.rs` into a static lib that
cargo links into every consumer cdylib.

## ueforge shim (502 lines, ours)

`ueforge/cpp/`. Four files. The minimum bridge.

### `ueforge_shim.cpp` (168 lines)

The generic `RC::CppUserModBase` subclass that satisfies UE4SS's
plugin contract. Provides:

- A `start_mod()` factory function UE4SS calls to instantiate the
  mod object.
- A `DllMain` that captures `HMODULE` for `dll_dir()` resolution
  and forwards lifecycle events to Rust.
- A `UespyMod` class deriving from `RC::CppUserModBase` whose
  every virtual override (`on_unreal_init`, `on_shutdown`,
  `register_tabs`, etc.) is a one-liner forwarder into the
  Rust `extern "C"` entry points emitted by
  [`ueforge::ue4ss_mod!`](lifecycle.md).

### `ueforge_ui.cpp` (152 lines)

`extern "C"` wrappers around the ImGui functions Rust mods use
through [`ueforge::ui`](imgui.md). Each wrapper takes
plain-C-ABI types (`const char*`, `bool*`, `float*`) and calls
the underlying ImGui C++ API. Rust binds these via standard
`extern "C"` declarations.

Why a hand-written wrapper layer instead of `bindgen`-ing
ImGui directly: ImGui's C++ API uses `ImVec2`, `ImVec4`,
overloaded calls, default arguments, and namespace-scoped
functions. All of which require a stable C ABI shim to be
callable from Rust. We write that shim once.

### `ueforge_cppusermodbase.hpp` (141 lines)

Vetted mirror of UE4SS's `RC::CppUserModBase` class layout.
just the virtual table and field offsets we need to subclass
properly. Why a mirror instead of including UE4SS's headers
directly: UE4SS's source has its own broken submodule
(`Re-UE4SS/UEPseudo.git` is 404'd) and a complex header
hierarchy, and depending on it pins us to a specific UE4SS
source checkout. The mirror is one-time copy, ~141 LoC, ABI-
stable across UE4SS versions (the class layout doesn't change).

If UE4SS ever does change `CppUserModBase`'s ABI, we update the
mirror; the rest of our shim and all Rust mods stay unchanged.

### `ueforge_imgui_bridge.hpp` (41 lines)

Bridges UE4SS's ImGui context (two function pointers UE4SS
exposes:
`UE4SSProgram::get_current_imgui_context` and
`get_current_imgui_context_io`) into our ImGui calls so we draw
on UE4SS's window, not a separate one. Tiny, header-only.

## Why we can't drop the shim

Rust cdylibs cannot subclass C++ classes directly. There is no
stable C++-Rust ABI for vtables. UE4SS's plugin API requires you
to **derive from `RC::CppUserModBase`** and return a pointer to
that derived object. The loader calls virtual methods on it.
Any approach that doesn't subclass a real C++ class doesn't work
at the engine boundary.

So: we must have at least one C++ class somewhere. We make it
small, generic, and shared by every mod in the workspace.

## What stays in Rust (everything else)

| Domain | Where |
|---|---|
| All framework code | `ueforge/src/**` |
| Grounded 2 mod | `grounded2-mod/src/**` |
| Outworld Station mod | `outworld-station-mod/src/**` |
| Deploy CLI | `ueforge/src/bin/ueforge_deploy.rs` |
| Asset inspection tools | `ueforge::uasset` + `dump-strings` / `read-property` bins |
| All tests | `**/tests/*.rs` and `#[cfg(test)]` modules |
| All docs | `**/*.md` |

There is **zero** game-specific C++ anywhere in any mod crate.
No RPG-system C++, no inventory C++, no damage-hook C++. Every
Rust mod consumes the same 502-line C++ shim from `ueforge/cpp/`
unchanged.

## Adding capabilities without adding C++

When ueforge gains a new feature, the cost in C++ is almost
always zero:

- Add a new ImGui widget: usually one new line in `ueforge_ui.cpp`
  (or none, if existing primitives compose). Rust gets the new
  `ueforge::ui::*` binding.
- Add a new hook surface: pure Rust (`ueforge::hook::*`).
- Add a new RPG primitive, counter, ring, scanner op, settings
  helper: pure Rust.

The only time the shim changes is when UE4SS's `CppUserModBase`
ABI changes (rare; it's been stable for years), or when we want
to expose a new ImGui function (one extra line in
`ueforge_ui.cpp`). Otherwise, the shim is a fixed cost paid once.

## Doctrine: don't grow the C++ surface

The repo rule:

> If you find yourself adding C++ that isn't (a) one more
> ImGui wrapper line in `ueforge_ui.cpp`, or (b) a new
> field/method on the `CppUserModBase` mirror because UE4SS's
> ABI changed. Stop. Find a way to do it in Rust.

Every line of game-specific behavior is Rust. Every line of
RPG / inventory / damage / persistence / HTTP / scanner /
counters / settings is Rust. The bridge stays the bridge.

## Cross-references

- [lifecycle.md](lifecycle.md). How the shim wires UE4SS's
  `CppUserModBase` to Rust callbacks at runtime
- [imgui.md](imgui.md). The Rust `ueforge::ui::*` API the C++
  wrappers serve
- [`../README.md`](../../README.md#ueforge). Crate-level entry
  point + audit table
