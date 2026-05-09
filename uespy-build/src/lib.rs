//! Build-time helper for UE4SS Rust mods.
//!
//! Use as a `[build-dependencies]` entry. Game's `build.rs`:
//!
//! ```ignore
//! fn main() {
//!     uespy_build::CppShim::new()
//!         .source("cpp/shim.cpp")
//!         .imgui_dir("cpp/imgui")
//!         .ue4ss_lib_dir("ue4ss")
//!         .compile();
//! }
//! ```
//!
//! What `compile()` does:
//! 1. Drops the shared uespy C++ headers
//!    (`uespy_cppusermodbase.hpp`, `uespy_imgui_bridge.hpp`) into
//!    the game's `OUT_DIR` so the shim can `#include` them as if
//!    they live next to its own sources.
//! 2. Runs `cc::Build` with the flags UE4SS requires (C++20,
//!    `/EHsc`, dynamic CRT to match UE4SS's release build).
//! 3. Compiles the game's `shim.cpp` plus the four ImGui sources
//!    (when `imgui_dir` is set).
//! 4. Links the resulting `.obj`s as cdylib link args so UE4SS's
//!    `start_mod` / `uninstall_mod` exports are present
//!    unconditionally.
//! 5. Adds `<ue4ss_lib_dir>` to the linker search path and links
//!    `UE4SS` (when `ue4ss_lib_dir` is set).
//!
//! Headers are embedded at this crate's compile time via
//! `include_str!` so the helper works whether uespy is consumed via
//! workspace path-dep or a future registry release.

use std::path::{Path, PathBuf};

const UESPY_CPPUSERMODBASE_HPP: &str = include_str!("../../uespy/cpp/uespy_cppusermodbase.hpp");
const UESPY_IMGUI_BRIDGE_HPP: &str = include_str!("../../uespy/cpp/uespy_imgui_bridge.hpp");

#[derive(Default)]
pub struct CppShim {
    source: Option<PathBuf>,
    imgui_dir: Option<PathBuf>,
    ue4ss_lib_dir: Option<PathBuf>,
    extra_includes: Vec<PathBuf>,
    extra_sources: Vec<PathBuf>,
}

impl CppShim {
    pub fn new() -> Self {
        Self::default()
    }

    /// Path to the game's `shim.cpp` (typically `cpp/shim.cpp` under
    /// the manifest dir). Required.
    pub fn source<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.source = Some(path.into());
        self
    }

    /// Path to a directory containing vendored ImGui sources
    /// (`imgui.cpp`, `imgui_draw.cpp`, `imgui_tables.cpp`,
    /// `imgui_widgets.cpp`). Optional — omit for shim-only builds
    /// without an ImGui tab.
    pub fn imgui_dir<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.imgui_dir = Some(path.into());
        self
    }

    /// Path to a directory containing `UE4SS.lib` (the import
    /// library generated from the user's installed `UE4SS.dll`).
    /// Optional — omit if the shim doesn't call any
    /// `RC_UE4SS_API` symbols (rare).
    pub fn ue4ss_lib_dir<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.ue4ss_lib_dir = Some(path.into());
        self
    }

    /// Add a directory to the C++ include path. Useful for
    /// game-specific helper headers.
    pub fn extra_include<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.extra_includes.push(path.into());
        self
    }

    /// Add an extra C++ source file to compile and link alongside
    /// `shim.cpp`. Useful when game splits its shim into multiple TUs.
    pub fn extra_source<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.extra_sources.push(path.into());
        self
    }

    /// Run the build. Panics with a clear message if required
    /// inputs are missing or `cc` fails.
    pub fn compile(self) {
        let manifest_dir = std::env::var("CARGO_MANIFEST_DIR")
            .expect("CARGO_MANIFEST_DIR not set (run from a build script)");
        let manifest_dir = PathBuf::from(manifest_dir);
        let out_dir = std::env::var("OUT_DIR").expect("OUT_DIR not set");
        let out_dir = PathBuf::from(out_dir);

        // Drop shared uespy headers into OUT_DIR/uespy_cpp/ so the
        // game's shim can `#include "uespy_cppusermodbase.hpp"`
        // without managing a relative path to uespy/cpp/.
        let uespy_cpp = out_dir.join("uespy_cpp");
        std::fs::create_dir_all(&uespy_cpp)
            .unwrap_or_else(|e| panic!("uespy-build: create {:?}: {e}", uespy_cpp));
        write_if_changed(
            &uespy_cpp.join("uespy_cppusermodbase.hpp"),
            UESPY_CPPUSERMODBASE_HPP,
        );
        write_if_changed(
            &uespy_cpp.join("uespy_imgui_bridge.hpp"),
            UESPY_IMGUI_BRIDGE_HPP,
        );

        let source = self
            .source
            .map(|p| absolutize(&manifest_dir, p))
            .expect("uespy-build: CppShim::source(...) is required");
        println!("cargo:rerun-if-changed={}", source.display());

        let imgui_dir = self.imgui_dir.map(|p| absolutize(&manifest_dir, p));
        if let Some(d) = &imgui_dir {
            println!("cargo:rerun-if-changed={}", d.display());
        }

        let ue4ss_lib_dir = self.ue4ss_lib_dir.map(|p| absolutize(&manifest_dir, p));
        if let Some(d) = &ue4ss_lib_dir {
            println!("cargo:rerun-if-changed={}", d.join("UE4SS.lib").display());
        }

        let mut build = cc::Build::new();
        build
            .cpp(true)
            .std("c++20")
            .include(&uespy_cpp)
            .file(&source)
            .flag_if_supported("/EHsc")
            // UE4SS ships built against the multi-threaded DLL CRT.
            // Mismatched CRT = std::vector / std::wstring layout
            // mismatch across the boundary = crash.
            .static_crt(false)
            .warnings(false);

        if let Some(d) = &imgui_dir {
            build
                .include(d)
                .file(d.join("imgui.cpp"))
                .file(d.join("imgui_draw.cpp"))
                .file(d.join("imgui_tables.cpp"))
                .file(d.join("imgui_widgets.cpp"));
        }

        for inc in &self.extra_includes {
            build.include(absolutize(&manifest_dir, inc.clone()));
        }
        for src in &self.extra_sources {
            let abs = absolutize(&manifest_dir, src.clone());
            println!("cargo:rerun-if-changed={}", abs.display());
            build.file(abs);
        }

        // compile_intermediates returns the .obj files directly so
        // we can pass them as `rustc-cdylib-link-arg` to ensure
        // C++ exports (start_mod / uninstall_mod) land in the
        // final cdylib unconditionally.
        let objs = build.compile_intermediates();
        for obj in &objs {
            println!("cargo:rustc-cdylib-link-arg={}", obj.display());
        }

        if let Some(d) = ue4ss_lib_dir {
            println!("cargo:rustc-link-search=native={}", d.display());
            println!("cargo:rustc-link-lib=UE4SS");
        }
    }
}

fn absolutize(manifest_dir: &Path, p: PathBuf) -> PathBuf {
    if p.is_absolute() {
        p
    } else {
        manifest_dir.join(p)
    }
}

/// Write `contents` to `path`, but only if the existing file is
/// missing or different. Avoids stamping mtime on every build.
fn write_if_changed(path: &Path, contents: &str) {
    let existing = std::fs::read_to_string(path).ok();
    if existing.as_deref() != Some(contents) {
        std::fs::write(path, contents)
            .unwrap_or_else(|e| panic!("uespy-build: write {:?}: {e}", path));
    }
}
