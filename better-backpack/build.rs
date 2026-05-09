// Compile better-backpack's UE4SS C++ shim (cpp/shim.cpp) plus
// vendored ImGui (cpp/imgui/) and link UE4SS.lib (the import
// library generated from the user's installed UE4SS.dll).
//
// All boilerplate (CRT mode, C++ standard, shared uespy headers,
// link-arg routing, UE4SS.lib link) lives in `uespy-build` so
// every UE4SS Rust mod gets the same vetted build pipeline. We
// only declare what's specific to this crate: the source paths
// and the ImGui version we vendor (v1.92.1 to match UE4SS).

fn main() {
    uespy_build::CppShim::new()
        .source("cpp/shim.cpp")
        .imgui_dir("cpp/imgui")
        .ue4ss_lib_dir("ue4ss")
        .compile();
}
