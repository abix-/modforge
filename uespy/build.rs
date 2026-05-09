// Compile uespy's bundled C++ that EVERY mod always needs:
// imgui v1.92.1 vendor + uespy_ui.cpp (the ImGui Rust bridge) +
// the ImGui-context bridge to UE4SS.dll. Cargo links the
// resulting static lib into every consumer of this crate.
//
// uespy_shim.cpp (the default UE4SS factory: start_mod /
// uninstall_mod / DllMain plus the UespyMod CppUserModBase
// subclass) is intentionally NOT compiled here. Mods that want
// the default factory call `uespy::build::CppShim::new()
// .compile()` from their build.rs; mods with their own shim
// (better-backpack today) skip the default. Otherwise factory
// symbols would collide.
//
// /DELAYLOAD:UE4SS.dll keeps build-script binaries linkable. The
// only function in uespy_ui.cpp that touches UE4SS is
// `uespy_ui_enable_imgui`; it's never called from a build script
// or test binary, so delay-loaded symbols never resolve there.

fn main() {
    let manifest = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let cpp = manifest.join("cpp");
    let imgui = cpp.join("imgui");
    let ue4ss = manifest.join("ue4ss");

    println!("cargo:rerun-if-changed={}", cpp.display());
    println!("cargo:rerun-if-changed={}", ue4ss.join("UE4SS.lib").display());

    cc::Build::new()
        .cpp(true)
        .std("c++20")
        .include(&imgui)
        .include(&cpp)
        .file(imgui.join("imgui.cpp"))
        .file(imgui.join("imgui_draw.cpp"))
        .file(imgui.join("imgui_tables.cpp"))
        .file(imgui.join("imgui_widgets.cpp"))
        .file(cpp.join("uespy_ui.cpp"))
        .flag_if_supported("/EHsc")
        .static_crt(false)
        .warnings(false)
        .compile("uespy_native");

    // No UE4SS.lib link here. uespy_ui.cpp has no UE4SS deps —
    // the context bridge lives in uespy_shim.cpp, which only the
    // game's cdylib link pulls in (via uespy::build::CppShim).
    let _ = ue4ss; // path silenced; CppShim emits the link.
}
