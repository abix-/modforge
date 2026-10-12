//! How StatComponents.GetFinalValue(other) combines two sets of parts.
//!
//! 2026-10-03 (luck_check.rs): luck's live set {base 0, additive 25.9,
//! multiplicative 1.0} gives 0.259 combined with itself and 0.0 combined
//! with a fresh set {0, 0, 0}. Does a base value survive an other set
//! whose multiplier is 0? Only throwaway sets made here are used; nothing
//! in the player's stats is touched.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test luck_math -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn set(api: &Api<Value>, base: f64, additive: f64, mult: f64) -> i64 {
    let made = api.op(
        "invoke_static",
        json!({"class": "System.Activator", "method": "CreateInstance",
               "args": ["Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatComponents, Assembly-CSharp"]}),
    );
    let h = handle_of(&made.result).unwrap_or_else(|| panic!("CreateInstance: {} {:?}", made.result, made.error));
    for (field, v) in [
        ("_baseValue_k__BackingField", base),
        ("_additiveValue_k__BackingField", additive),
        ("_multiplicativeValue_k__BackingField", mult),
    ] {
        let w = api.op("write_field", json!({"handle": h, "field": field, "value": v}));
        assert!(w.ok, "write {field}: {:?}", w.error);
    }
    h
}

#[test]
fn combine() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // (this set, other set), each (base, additive, multiplicative)
    let cases = [
        ((2.0, 0.0, 1.0), (0.0, 0.0, 0.0)),
        ((2.0, 0.0, 1.0), (0.0, 0.0, 1.0)),
        ((0.0, 20.0, 1.0), (0.0, 0.0, 0.0)),
        ((0.0, 20.0, 1.0), (0.0, 0.0, 1.0)),
        ((0.0, 20.0, 0.0), (0.0, 0.0, 1.0)),
        ((2.0, 20.0, 1.0), (0.0, 0.0, 1.0)),
    ];
    for (a, b) in cases {
        let ha = set(&api, a.0, a.1, a.2);
        let hb = set(&api, b.0, b.1, b.2);
        let r = api.op("invoke_method", json!({"handle": ha, "method": "GetFinalValue", "args": [{"$handle": hb}]}));
        println!("this {a:?} with other {b:?} -> {} {:?}", r.result, r.error);
        api.op("release_handle", json!({"handle": ha}));
        api.op("release_handle", json!({"handle": hb}));
    }
}
