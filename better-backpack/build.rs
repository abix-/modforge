// All UE4SS C++ build glue lives in `uespy_build`. ImGui sources
// (v1.92.1 vendor) and UE4SS.lib both come from `uespy/cpp/imgui/`
// and `uespy/ue4ss/` respectively, defaulted in by the helper.

fn main() {
    uespy_build::CppShim::new()
        .source("cpp/shim.cpp")
        .compile();
}
