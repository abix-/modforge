// Compile uespy's default factory + ImGui context bridge into the
// cdylib. uespy's own build.rs already compiled the imgui vendor
// + uespy_ui bridge into the static lib that cargo auto-links.
fn main() {
    uespy::build::CppShim::new().compile();
}
