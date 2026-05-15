// modforge build script.
//
// On its own, modforge is a pure Rust rlib. The `native-ui` Cargo
// feature is the only build-time wrinkle: when it's on, we compile
// the vendored ImGui (reused from ueforge/cpp/imgui to avoid two
// copies) + the Win32/D3D11 backends + modforge_ui_native.cpp into
// a static lib linked into the consuming cdylib.
//
// Off-by-default; the build script no-ops for consumers (ueforge,
// future BepInEx-side mods) that don't need this backend.

use std::path::PathBuf;

fn main() {
    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-changed=cpp/modforge_ui_native.cpp");

    let native_ui = std::env::var("CARGO_FEATURE_NATIVE_UI").is_ok();
    if !native_ui {
        return;
    }

    let manifest_dir = PathBuf::from(
        std::env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR"),
    );
    let workspace = manifest_dir
        .parent()
        .expect("modforge must live inside the workspace")
        .to_path_buf();
    let imgui_dir = workspace.join("ueforge").join("cpp").join("imgui");
    let imgui_backends = imgui_dir.join("backends");

    if !imgui_dir.join("imgui.cpp").exists() {
        panic!(
            "modforge build.rs: native-ui requires vendored ImGui at {}; \
             missing imgui.cpp",
            imgui_dir.display()
        );
    }

    let mut build = cc::Build::new();
    build
        .cpp(true)
        .std("c++20")
        .include(&imgui_dir)
        .include(&imgui_backends)
        .flag_if_supported("/EHsc")
        .flag_if_supported("/wd4267")
        .flag_if_supported("/wd4244")
        .static_crt(false)
        .warnings(false);

    let sources = [
        imgui_dir.join("imgui.cpp"),
        imgui_dir.join("imgui_draw.cpp"),
        imgui_dir.join("imgui_tables.cpp"),
        imgui_dir.join("imgui_widgets.cpp"),
        imgui_backends.join("imgui_impl_win32.cpp"),
        imgui_backends.join("imgui_impl_dx11.cpp"),
        manifest_dir.join("cpp").join("modforge_ui_native.cpp"),
    ];
    for s in &sources {
        println!("cargo:rerun-if-changed={}", s.display());
        build.file(s);
    }

    // Static lib: cargo emits `cargo:rustc-link-lib=static=modforge_native_ui`
    // which is propagated to any downstream cdylib that depends on
    // modforge with the feature on.
    build.compile("modforge_native_ui");

    // System libs the D3D11 + Win32 paths pull in. Plain link-lib so
    // downstream cdylibs pick them up via Cargo's dependency graph.
    for lib in &["d3d11", "dxgi", "user32", "gdi32", "dwmapi"] {
        println!("cargo:rustc-link-lib=dylib={}", lib);
    }
}
