//! Compile the small SEH wrapper C shim. MSVC only; on non-Windows we
//! skip and rely on the Rust-side fallback.

fn main() {
    // Only build the C shim on MSVC. The shim uses __try/__except which
    // is an MSVC language extension. mingw / linux / mac fall through
    // to the stub `seh::guard` in lib.rs that just calls f() directly.
    let target = std::env::var("TARGET").unwrap_or_default();
    if !target.contains("pc-windows-msvc") {
        return;
    }

    println!("cargo:rerun-if-changed=src/seh.c");
    cc::Build::new()
        .file("src/seh.c")
        .flag_if_supported("/EHa") // enable SEH unwinding through C
        .compile("modforge_seh");
}
