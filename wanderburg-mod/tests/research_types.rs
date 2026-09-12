//! Which classes are Wanderburg's own?
//!
//! Loads the game's Assembly-CSharp through the runtime's own
//! reflection (System.Reflection.Assembly.Load, then GetTypes) over
//! the control plane and prints every type's full name, grouped
//! by namespace with a count per namespace first. No shim change,
//! no hand-parsed metadata: the same walk any research test does,
//! pointed at the type table instead of a game object.
//!
//! ```text
//! k3sc cargo-lock test -p wanderburg-mod --test research_types -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running so
//! the workspace suite stays green.

mod common;
use common::{api, count_of, handle_of, ping_or_skip};
use serde_json::json;
use std::collections::BTreeMap;

#[test]
fn game_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    // Host-side System.Reflection objects come back stringified
    // (the shim only hands out handles for IL2CPP objects), so the
    // walk goes through the IL2CPP side of the runtime: the
    // interop proxy Il2CppSystem.AppDomain, whose assemblies and
    // types are IL2CPP objects and chain like any game object.
    let domain = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.AppDomain", "method": "get_CurrentDomain", "args": []}),
    );
    let Some(domain_h) = handle_of(&domain.result) else {
        println!("AppDomain.get_CurrentDomain carried no handle: ok={} result={} error={:?}", domain.ok, domain.result, domain.error);
        return;
    };
    let asms = api.op("invoke_method", json!({"handle": domain_h, "method": "GetAssemblies", "args": []}));
    let Some(asms_h) = handle_of(&asms.result) else {
        println!("GetAssemblies carried no handle: ok={} result={} error={:?}", asms.ok, asms.result, asms.error);
        return;
    };
    let Some(asm_count) = count_of(&api, asms_h) else {
        println!("GetAssemblies result answered no length");
        return;
    };
    let mut asm_h = None;
    for i in 0..asm_count {
        let item = api.op("invoke_method", json!({"handle": asms_h, "method": "get_Item", "args": [i]}));
        let Some(h) = handle_of(&item.result) else {
            continue;
        };
        let full = api.op("invoke_method", json!({"handle": h, "method": "get_FullName", "args": []}));
        let name = full.result.as_str().unwrap_or("");
        if name.starts_with("Assembly-CSharp,") {
            println!("found {name}");
            asm_h = Some(h);
            break;
        }
        api.op("release_handle", json!({"handle": h}));
    }
    api.op("release_handle", json!({"handle": asms_h}));
    api.op("release_handle", json!({"handle": domain_h}));
    let Some(asm_h) = asm_h else {
        println!("no assembly named Assembly-CSharp among {asm_count} assemblies");
        return;
    };

    let types = api.op("invoke_method", json!({"handle": asm_h, "method": "GetTypes", "args": []}));
    let Some(seq) = handle_of(&types.result) else {
        println!("GetTypes carried no handle: ok={} result={} error={:?}", types.ok, types.result, types.error);
        return;
    };
    let Some(n) = count_of(&api, seq) else {
        println!("GetTypes result answered no length");
        return;
    };
    println!("Assembly-CSharp: {n} types");

    let mut by_namespace: BTreeMap<String, Vec<String>> = BTreeMap::new();
    for i in 0..n {
        let item = api.op("invoke_method", json!({"handle": seq, "method": "get_Item", "args": [i]}));
        let Some(th) = handle_of(&item.result) else {
            continue;
        };
        let name = api.op("invoke_method", json!({"handle": th, "method": "get_FullName", "args": []}));
        api.op("release_handle", json!({"handle": th}));
        let Some(full) = name.result.as_str().map(str::to_string) else {
            continue;
        };
        // Compiler-generated closures and iterators carry '<' in
        // the name; they are noise for a class survey.
        if full.contains('<') {
            continue;
        }
        let (ns, short) = match full.rfind('.') {
            Some(p) => (full[..p].to_string(), full[p + 1..].to_string()),
            None => ("(global)".to_string(), full.clone()),
        };
        by_namespace.entry(ns).or_default().push(short);
    }
    api.op("release_handle", json!({"handle": seq}));
    api.op("release_handle", json!({"handle": asm_h}));

    println!("\nnamespaces ({}), largest first:", by_namespace.len());
    let mut sizes: Vec<(&String, usize)> = by_namespace.iter().map(|(k, v)| (k, v.len())).collect();
    sizes.sort_by(|a, b| b.1.cmp(&a.1).then(a.0.cmp(b.0)));
    for (ns, n) in &sizes {
        println!("  {n:5}  {ns}");
    }
    println!();
    for (ns, names) in &by_namespace {
        let mut names = names.clone();
        names.sort_unstable();
        println!("{ns}:");
        for s in names {
            println!("  {s}");
        }
    }
}
