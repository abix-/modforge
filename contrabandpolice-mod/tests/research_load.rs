//! Is the mod loaded into Contraband Police, and can it see the
//! game's code?
//!
//! Read-only. Pings the control plane, then walks the IL2CPP
//! AppDomain's assemblies and prints each name, and fails if
//! Assembly-CSharp (the game's own code) is not among them.
//!
//! ```text
//! k3sc cargo-lock test -p contrabandpolice-mod --test research_load -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, count_of, handle_of, ping_or_skip};
use serde_json::json;

#[test]
fn mod_sees_game_code() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let domain = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.AppDomain", "method": "get_CurrentDomain", "args": []}),
    );
    let domain_h = handle_of(&domain.result).unwrap_or_else(|| {
        panic!("AppDomain.get_CurrentDomain carried no handle: {:?}", domain.error)
    });
    let asms = api.op(
        "invoke_method",
        json!({"handle": domain_h, "method": "GetAssemblies", "args": []}),
    );
    let asms_h = handle_of(&asms.result)
        .unwrap_or_else(|| panic!("GetAssemblies carried no handle: {:?}", asms.error));
    let n = count_of(&api, asms_h).expect("assembly list has a length");
    let mut names = Vec::new();
    for i in 0..n {
        let item = api.op(
            "invoke_method",
            json!({"handle": asms_h, "method": "get_Item", "args": [i]}),
        );
        let Some(h) = handle_of(&item.result) else {
            continue;
        };
        let full = api.op(
            "invoke_method",
            json!({"handle": h, "method": "get_FullName", "args": []}),
        );
        names.push(full.result.as_str().unwrap_or("?").to_string());
        api.op("release_handle", json!({"handle": h}));
    }
    api.op("release_handle", json!({"handle": asms_h}));
    api.op("release_handle", json!({"handle": domain_h}));

    names.sort();
    println!("{} assemblies:", names.len());
    for name in &names {
        println!("  {name}");
    }
    assert!(
        names.iter().any(|n| n.starts_with("Assembly-CSharp,")),
        "Assembly-CSharp not among the loaded assemblies"
    );
}
