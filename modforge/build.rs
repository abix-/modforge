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

    // Each program's icon (icons/<program>.res, made by onelog's
    // tools/make-icons), linked into its exe.
    let dir = std::env::var("CARGO_MANIFEST_DIR").unwrap();
    for (program, icon) in [
        ("modforge-deploy", "modforge-deploy"),
        ("modforge-inject", "modforge-inject"),
        ("minidump", "minidump"),
        ("inspect_function", "inspect-function"),
    ] {
        println!("cargo:rerun-if-changed=icons/{icon}.res");
        println!("cargo:rustc-link-arg-bin={program}={dir}/icons/{icon}.res");
    }

    println!("cargo:rerun-if-changed=src/seh.c");
    cc::Build::new()
        .file("src/seh.c")
        .flag_if_supported("/EHa") // enable SEH unwinding through C
        .compile("modforge_seh");
}
