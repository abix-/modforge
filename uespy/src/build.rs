//! Build-time helper for UE4SS Rust mods.
//!
//! Activated by the `build` feature (set in your
//! `[build-dependencies]` line:
//! `uespy = { path = "...", default-features = false, features = ["build"] }`).
//!
//! Game's `build.rs`:
//!
//! ```ignore
//! fn main() {
//!     uespy::build::CppShim::new().compile();
//! }
//! ```
//!
//! What `compile()` does:
//! 1. Drops the shared uespy C++ headers
//!    (`uespy_cppusermodbase.hpp`, `uespy_imgui_bridge.hpp`) into
//!    the game's `OUT_DIR/uespy_cpp/` so any custom shim can
//!    `#include` them as if they live next to its own sources.
//! 2. Writes uespy's own `.cpp` sources (the generic
//!    `uespy_shim.cpp` and the ImGui bridge `uespy_ui.cpp`) into
//!    the same OUT_DIR slot.
//! 3. Runs `cc::Build` with the flags UE4SS requires (C++20,
//!    `/EHsc`, dynamic CRT to match UE4SS's release build).
//! 4. Compiles the shipped sources plus uespy's bundled ImGui
//!    vendor (v1.92.1) and any game-specific `source(...)`.
//! 5. Links the resulting `.obj`s as cdylib link args so UE4SS's
//!    `start_mod` / `uninstall_mod` exports are present
//!    unconditionally.
//! 6. Adds the bundled `UE4SS.lib` directory to the linker search
//!    path and links `UE4SS`.

use std::path::{Path, PathBuf};

const UESPY_CPPUSERMODBASE_HPP: &str = include_str!("../cpp/uespy_cppusermodbase.hpp");
const UESPY_IMGUI_BRIDGE_HPP: &str = include_str!("../cpp/uespy_imgui_bridge.hpp");
const UESPY_SHIM_CPP: &str = include_str!("../cpp/uespy_shim.cpp");
const UESPY_UI_CPP: &str = include_str!("../cpp/uespy_ui.cpp");

/// Path to uespy's bundled C++ assets (imgui vendor + UE4SS.lib),
/// resolved at uespy's compile time. Game build.rs scripts don't
/// need to know this path; defaults to it when `imgui_dir` /
/// `ue4ss_lib_dir` aren't supplied.
fn uespy_root() -> PathBuf {
    PathBuf::from(env!("CARGO_MANIFEST_DIR"))
}

fn default_imgui_dir() -> PathBuf {
    uespy_root().join("cpp").join("imgui")
}

fn default_ue4ss_lib_dir() -> PathBuf {
    uespy_root().join("ue4ss")
}

#[derive(Default)]
pub struct CppShim {
    source: Option<PathBuf>,
    imgui_dir: Option<PathBuf>,
    ue4ss_lib_dir: Option<PathBuf>,
    skip_imgui: bool,
    skip_default_shim: bool,
    extra_includes: Vec<PathBuf>,
    extra_sources: Vec<PathBuf>,
}

impl CppShim {
    pub fn new() -> Self {
        Self::default()
    }

    /// Path to a game-specific `shim.cpp`. Optional — by default
    /// `compile()` builds the shipped generic shim
    /// (`uespy_shim.cpp`), which forwards lifecycle + tab rendering
    /// to extern "C" Rust hooks emitted by [`crate::ue4ss_mod`].
    /// Set this only if your mod needs custom C++ alongside (or
    /// instead of) the shipped shim; chain `.skip_default_shim()`
    /// to fully replace.
    pub fn source<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.source = Some(path.into());
        self
    }

    /// Don't compile the shipped `uespy_shim.cpp`. Use only when
    /// your `source` provides its own `start_mod` /
    /// `uninstall_mod` / `DllMain` — otherwise the linker will
    /// complain about duplicate symbols.
    pub fn skip_default_shim(mut self) -> Self {
        self.skip_default_shim = true;
        self
    }

    /// Override the default ImGui sources directory. Defaults to
    /// uespy's bundled v1.92.1 vendor.
    pub fn imgui_dir<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.imgui_dir = Some(path.into());
        self
    }

    /// Skip ImGui vendoring entirely.
    pub fn skip_imgui(mut self) -> Self {
        self.skip_imgui = true;
        self
    }

    /// Override the default `UE4SS.lib` directory. Defaults to
    /// uespy's bundled import lib.
    pub fn ue4ss_lib_dir<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.ue4ss_lib_dir = Some(path.into());
        self
    }

    /// Add a directory to the C++ include path.
    pub fn extra_include<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.extra_includes.push(path.into());
        self
    }

    /// Add an extra C++ source file alongside `shim.cpp`.
    pub fn extra_source<P: Into<PathBuf>>(mut self, path: P) -> Self {
        self.extra_sources.push(path.into());
        self
    }

    pub fn compile(self) {
        let manifest_dir = std::env::var("CARGO_MANIFEST_DIR")
            .expect("CARGO_MANIFEST_DIR not set (run from a build script)");
        let manifest_dir = PathBuf::from(manifest_dir);
        let out_dir = std::env::var("OUT_DIR").expect("OUT_DIR not set");
        let out_dir = PathBuf::from(out_dir);

        let uespy_cpp = out_dir.join("uespy_cpp");
        std::fs::create_dir_all(&uespy_cpp)
            .unwrap_or_else(|e| panic!("uespy::build: create {:?}: {e}", uespy_cpp));
        write_if_changed(
            &uespy_cpp.join("uespy_cppusermodbase.hpp"),
            UESPY_CPPUSERMODBASE_HPP,
        );
        write_if_changed(
            &uespy_cpp.join("uespy_imgui_bridge.hpp"),
            UESPY_IMGUI_BRIDGE_HPP,
        );

        let mut sources_to_compile: Vec<PathBuf> = Vec::new();

        // The UI bridge is always compiled — `uespy::ui` declares
        // these extern "C" symbols and any mod might use them.
        let ui_dst = uespy_cpp.join("uespy_ui.cpp");
        write_if_changed(&ui_dst, UESPY_UI_CPP);
        sources_to_compile.push(ui_dst);

        if !self.skip_default_shim {
            let shim_dst = uespy_cpp.join("uespy_shim.cpp");
            write_if_changed(&shim_dst, UESPY_SHIM_CPP);
            sources_to_compile.push(shim_dst);
        }

        if let Some(p) = self.source {
            let abs = absolutize(&manifest_dir, p);
            println!("cargo:rerun-if-changed={}", abs.display());
            sources_to_compile.push(abs);
        }

        if sources_to_compile.is_empty() {
            panic!(
                "uespy::build: nothing to compile. Either keep the \
                 default shim (don't call skip_default_shim) or \
                 provide a custom source(...)"
            );
        }

        let imgui_dir = if self.skip_imgui {
            None
        } else {
            Some(
                self.imgui_dir
                    .map(|p| absolutize(&manifest_dir, p))
                    .unwrap_or_else(default_imgui_dir),
            )
        };
        if let Some(d) = &imgui_dir {
            println!("cargo:rerun-if-changed={}", d.display());
        }

        let ue4ss_lib_dir = self
            .ue4ss_lib_dir
            .map(|p| absolutize(&manifest_dir, p))
            .or_else(|| {
                let d = default_ue4ss_lib_dir();
                d.join("UE4SS.lib").is_file().then_some(d)
            });
        if let Some(d) = &ue4ss_lib_dir {
            println!("cargo:rerun-if-changed={}", d.join("UE4SS.lib").display());
        }

        let mut build = cc::Build::new();
        build
            .cpp(true)
            .std("c++20")
            .include(&uespy_cpp)
            .flag_if_supported("/EHsc")
            .static_crt(false)
            .warnings(false);
        for src in &sources_to_compile {
            build.file(src);
        }

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

fn write_if_changed(path: &Path, contents: &str) {
    let existing = std::fs::read_to_string(path).ok();
    if existing.as_deref() != Some(contents) {
        std::fs::write(path, contents)
            .unwrap_or_else(|e| panic!("uespy::build: write {:?}: {e}", path));
    }
}
