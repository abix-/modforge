// Compiles the UE4SS C++ shim (cpp/shim.cpp), the vendored ImGui
// (cpp/imgui/), and links them into the cdylib alongside the Rust code.
// Also links UE4SS.lib (the import library generated from the user's
// installed UE4SS.dll). See `UE4SS_PORT_PLAN.md` for the full plan.
//
// We vendor upstream ocornut/imgui v1.92.1 because that's the version
// UE4SS itself uses
// (`RE-UE4SS/deps/third/CMakeLists.txt:GIT_TAG v1.92.1`). The shim's
// register_tab render lambda then uses our locally-compiled ImGui with
// the context pointer + allocator passed in from UE4SS.dll via the
// UE4SS_ENABLE_IMGUI macro. Same imgui version on both sides means the
// context struct layout matches.

use std::path::Path;

fn main() {
    let manifest_dir = std::env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR");
    let cpp_dir = Path::new(&manifest_dir).join("cpp");
    let shim = cpp_dir.join("shim.cpp");
    let imgui_dir = cpp_dir.join("imgui");
    let ue4ss_lib_dir = Path::new(&manifest_dir).join("ue4ss");

    println!("cargo:rerun-if-changed={}", shim.display());
    println!("cargo:rerun-if-changed={}", imgui_dir.display());
    println!(
        "cargo:rerun-if-changed={}",
        ue4ss_lib_dir.join("UE4SS.lib").display()
    );

    // Compile the shim + imgui sources together. cc::Build emits a
    // static lib by default; compile_intermediates() returns the .obj
    // files which we link directly so the linker sees C++ exports
    // (start_mod / uninstall_mod) unconditionally.
    let objs = cc::Build::new()
        .cpp(true)
        .std("c++20")
        .include(&imgui_dir)
        .file(&shim)
        .file(imgui_dir.join("imgui.cpp"))
        .file(imgui_dir.join("imgui_draw.cpp"))
        .file(imgui_dir.join("imgui_tables.cpp"))
        .file(imgui_dir.join("imgui_widgets.cpp"))
        .flag_if_supported("/EHsc")
        // Match UE4SS release CRT (/MD = multi-threaded DLL CRT).
        // Without this we risk std::wstring/vector/shared_ptr layout
        // mismatch vs UE4SS's parent ctor, which would scramble the
        // BetterBackpackMod fields and crash later.
        .static_crt(false)
        // ImGui sources push some warnings we don't want to fix in a
        // vendored dependency.
        .warnings(false)
        .compile_intermediates();
    for obj in &objs {
        println!("cargo:rustc-cdylib-link-arg={}", obj.display());
    }

    // Add the directory containing UE4SS.lib to the linker's search
    // path, then link against it.
    println!(
        "cargo:rustc-link-search=native={}",
        ue4ss_lib_dir.display()
    );
    println!("cargo:rustc-link-lib=UE4SS");
}
