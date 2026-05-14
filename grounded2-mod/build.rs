// One-line build script: ueforge ships the C++ shim (CppUserModBase
// mirror, factory exports, DllMain, ImGui bridge), we just compile it
// into our cdylib.

fn main() {
    ueforge::build::CppShim::new().compile();
}
