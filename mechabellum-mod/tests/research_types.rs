//! Which classes are Mechabellum's own?
//!
//! Read-only. For each of the game's own assemblies (the GR* ones
//! from the studio, the config tables, Assembly-CSharp), prints
//! every type grouped by namespace, with a count per namespace
//! first. The map to read before picking any mechanic to study.
//!
//! ```text
//! k3sc cargo-lock test -p mechabellum-mod --test research_types -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, ping_or_skip};
use std::collections::BTreeMap;
use unityforge::client::assembly_type_names;

/// Read from research_load on 2026-11-07: the assemblies that are
/// not Unity, .NET, or a named third-party library.
const GAME_ASSEMBLIES: &[&str] = &[
    "GRCore",
    "GRFight",
    "GRClient",
    "GRServer",
    "GRUtility",
    "ConfigDataProtocol",
    "FightAuth",
    "BinNetwork",
    "Assembly-CSharp",
    "Assembly-CSharp-firstpass",
];

#[test]
fn game_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for assembly in GAME_ASSEMBLIES {
        let Some(names) = assembly_type_names(&api, assembly) else {
            println!("\n=== {assembly}: not loaded");
            continue;
        };
        let mut by_namespace: BTreeMap<String, Vec<String>> = BTreeMap::new();
        for full in names {
            let (ns, short) = match full.rfind('.') {
                Some(p) => (full[..p].to_string(), full[p + 1..].to_string()),
                None => ("(global)".to_string(), full),
            };
            by_namespace.entry(ns).or_default().push(short);
        }
        let total: usize = by_namespace.values().map(Vec::len).sum();
        println!("\n=== {assembly}: {total} types, {} namespaces", by_namespace.len());
        let mut sizes: Vec<(&String, usize)> = by_namespace.iter().map(|(k, v)| (k, v.len())).collect();
        sizes.sort_by(|a, b| b.1.cmp(&a.1).then(a.0.cmp(b.0)));
        for (ns, n) in &sizes {
            println!("  {n:5}  {ns}");
        }
        for (ns, names) in &mut by_namespace {
            names.sort_unstable();
            println!("{assembly} / {ns}:");
            for s in names.iter() {
                println!("  {s}");
            }
        }
    }
}
