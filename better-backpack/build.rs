// better-backpack still ships its own shim.cpp with the RPG tab
// rendering inline. Until that migrates to uespy::ui + ue4ss_mod!,
// skip the default shim so we don't double-export start_mod /
// uninstall_mod / DllMain.
//
// New mods should drop both lines and let uespy-build's defaults
// drive everything.

fn main() {
    uespy_build::CppShim::new()
        .source("cpp/shim.cpp")
        .skip_default_shim()
        .compile();
}
