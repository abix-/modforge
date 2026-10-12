//! Where Megabonk keeps luck.
//!
//! Read-only. Walks the game's Assembly-CSharp types through the
//! runtime's own reflection (the same walk as
//! wanderburg-mod/tests/research_types.rs) and prints every type
//! whose name contains "luck" or "stat", then the declared methods
//! of each luck-named type.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_luck -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, game_type_names, ping_or_skip, print_declared_methods};

#[test]
fn luck_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names = game_type_names(&api);
    names.sort_unstable();

    let luck: Vec<&String> = names
        .iter()
        .filter(|n| n.to_ascii_lowercase().contains("luck"))
        .collect();
    let stat: Vec<&String> = names
        .iter()
        .filter(|n| n.to_ascii_lowercase().contains("stat"))
        .collect();
    println!("\ntypes named after luck ({}):", luck.len());
    for n in &luck {
        println!("  {n}");
    }
    println!("\ntypes named after stat ({}):", stat.len());
    for n in &stat {
        println!("  {n}");
    }
    for n in &luck {
        println!("\n== {n}");
        print_declared_methods(&api, n);
    }
}
