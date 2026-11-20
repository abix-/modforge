//! Every field and method of every Pure Skill class.
//!
//! Read-only. One shim call (Il2CppBridge.AssemblyMembers) reads
//! Assembly-CSharp's classes from the runtime: parent, fields with
//! type and offset, methods with return and parameter types. Prints
//! the whole listing, then the totals.
//!
//! ```text
//! k3sc cargo-lock test -p pureskill-mod --test research_members -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, ping_or_skip};
use unityforge::client::assembly_members;

#[test]
fn game_members() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let start = std::time::Instant::now();
    let Some(text) = assembly_members(&api, "Assembly-CSharp") else {
        return;
    };
    let took = start.elapsed();
    print!("{text}");
    let count = |prefix: &str| text.lines().filter(|l| l.trim_start().starts_with(prefix)).count();
    println!(
        "=== Assembly-CSharp: {} classes, {} fields, {} methods, read in {took:?}",
        count("class "),
        count("field "),
        count("method ")
    );
}
