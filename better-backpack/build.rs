// Generates a tiny C file containing one
// `#pragma comment(linker, "/EXPORT:Name=winhttp_orig.Name")` per
// WinHTTP export, and compiles it as part of the cdylib. The pragma
// writes the directive into the object file's `.drectve` section,
// which the MSVC linker processes as a forwarder (unlike a top-level
// /EXPORT command-line arg, which it treats as a symbol-resolve
// request and fails on).
//
// The export list is read from `winhttp.def`. Regenerate with
// `dumpbin /exports C:\Windows\System32\winhttp.dll`.

use std::fs;
use std::path::Path;

fn main() {
    let manifest_dir = std::env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR");
    let def_path = Path::new(&manifest_dir).join("winhttp.def");
    println!("cargo:rerun-if-changed={}", def_path.display());

    let text = fs::read_to_string(&def_path).expect("read winhttp.def");
    let mut pragmas = String::new();
    for raw in text.lines() {
        let line = raw.trim();
        if line.is_empty() || line.starts_with(';') {
            continue;
        }
        let upper = line.to_ascii_uppercase();
        if upper.starts_with("LIBRARY") || upper == "EXPORTS" {
            continue;
        }
        let Some((lhs, rhs)) = line.split_once('=') else {
            continue;
        };
        let name = lhs.trim();
        let target = rhs.trim();
        if name.is_empty() || target.is_empty() {
            continue;
        }
        pragmas.push_str(&format!(
            "#pragma comment(linker, \"/EXPORT:{}={}\")\n",
            name, target
        ));
    }

    let out_dir = std::env::var("OUT_DIR").expect("OUT_DIR");
    let c_path = Path::new(&out_dir).join("winhttp_forwarders.c");
    fs::write(&c_path, pragmas).expect("write forwarders.c");

    // Compile the .c file but link the object directly (not via the
    // wrapper static lib). MSVC only processes a .lib's .drectve
    // section when the lib pulls in a referenced symbol. Our object
    // has no code -- only #pragma directives -- so a static-lib
    // wrapping would silently swallow it. Linking the .obj as a raw
    // input forces the linker to read its directives unconditionally.
    let objs = cc::Build::new()
        .file(&c_path)
        .compile_intermediates();
    for obj in &objs {
        println!("cargo:rustc-cdylib-link-arg={}", obj.display());
    }
}
