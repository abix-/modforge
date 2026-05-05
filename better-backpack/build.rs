// Compiles the UE4SS C++ shim (cpp/shim.cpp) and links it into the
// cdylib alongside the Rust code, plus the UE4SS.lib import library
// generated from the user's installed UE4SS.dll. See
// `UE4SS_PORT_PLAN.md` for the full plan.

use std::path::Path;

fn main() {
    let manifest_dir = std::env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR");
    let shim = Path::new(&manifest_dir).join("cpp").join("shim.cpp");
    let ue4ss_lib_dir = Path::new(&manifest_dir).join("ue4ss");

    println!("cargo:rerun-if-changed={}", shim.display());
    println!(
        "cargo:rerun-if-changed={}",
        ue4ss_lib_dir.join("UE4SS.lib").display()
    );

    // Compile the shim. cc::Build emits a static lib by default;
    // compile_intermediates() returns the .obj files, which we link
    // directly so the linker sees the C++ exports
    // (start_mod / uninstall_mod) unconditionally.
    let objs = cc::Build::new()
        .cpp(true)
        .std("c++20")
        .file(&shim)
        .flag_if_supported("/EHsc")
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
