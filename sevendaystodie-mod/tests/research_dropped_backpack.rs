//! What is left in the backpacks the player dropped on death, and in
//! which slots?
//!
//! A dropped backpack opens windowBagStorage (Entity:
//! XUiC_BagStorageWindowGroup.Open with the entity's bag), which
//! makes one slot per cell of its XML grid (vanilla 11 x 10 = 110),
//! so with a bigger dropped backpack (loot.xml playerBackpack) any
//! item in slot 110 or later cannot be seen or taken. This lists
//! every non-empty slot of every EntityBackpack, flagging the ones
//! at 110+, and how many free slots the player's own bag has (a full
//! bag is the other reason loot stays behind).
//!
//! Read-only: read_field and getter calls only.
//!
//! ```text
//! k3sc cargo-lock test -p sevendaystodie-mod --test research_dropped_backpack -- --nocapture
//! ```

mod common;
use common::{api, call, field_handle, field_value, first_handle, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::{Api, count_of, find_instances};

/// Vanilla dropped-backpack window cell count (windowBagStorage
/// grid 11 x 10).
const VANILLA_LOOT_CELLS: i64 = 110;

/// Every slot of a bag: (index, item name, count), empty slots as None.
fn slots(api: &Api<Value>, owner: i64) -> Vec<Option<(String, Value)>> {
    let Some(bag) = field_handle(api, owner, "bag") else {
        return Vec::new();
    };
    let arr = call(api, bag, "GetSlots", json!([]));
    let Some(arr) = handle_of(&arr) else {
        println!("GetSlots: {arr}");
        return Vec::new();
    };
    let n = count_of(api, arr).unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        let s = call(api, arr, "GetValue", json!([i]));
        let Some(s) = handle_of(&s) else {
            out.push(None);
            continue;
        };
        let empty = call(api, s, "IsEmpty", json!([])).as_bool().unwrap_or(true);
        if empty {
            out.push(None);
        } else {
            let count = field_value(api, s, "count");
            let name = field_handle(api, s, "itemValue")
                .and_then(|iv| {
                    let class = handle_of(&call(api, iv, "get_ItemClass", json!([])));
                    api.op("release_handle", json!({"handle": iv}));
                    class
                })
                .map(|c| {
                    let n = field_value(api, c, "Name");
                    api.op("release_handle", json!({"handle": c}));
                    n.as_str().unwrap_or("?").to_string()
                })
                .unwrap_or_else(|| "?".to_string());
            out.push(Some((name, count)));
        }
        api.op("release_handle", json!({"handle": s}));
    }
    for h in [arr, bag] {
        api.op("release_handle", json!({"handle": h}));
    }
    out
}

#[test]
fn dropped_backpack_slots() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let packs = find_instances(&api, "EntityBackpack", true).unwrap_or_default();
    println!("{} EntityBackpack(s)", packs.len());
    for p in &packs {
        let Some(h) = handle_of(p) else { continue };
        let id = field_value(&api, h, "entityId");
        let s = slots(&api, h);
        let used: Vec<_> = s.iter().enumerate().filter_map(|(i, x)| x.as_ref().map(|v| (i, v))).collect();
        let hidden = used.iter().filter(|(i, _)| *i as i64 >= VANILLA_LOOT_CELLS).count();
        println!(
            "\nbackpack {id}: {} slots, {} used, {hidden} in slot {VANILLA_LOOT_CELLS}+ (not shown by the vanilla 110-cell backpack window)",
            s.len(),
            used.len()
        );
        for (i, (name, count)) in &used {
            let flag = if *i as i64 >= VANILLA_LOOT_CELLS { "  <- hidden" } else { "" };
            println!("  [{i:3}] {name} x{count}{flag}");
        }
        api.op("release_handle", json!({"handle": h}));
    }

    if let Some(player) = first_handle(&api, "EntityPlayerLocal") {
        let s = slots(&api, player);
        let free = s.iter().filter(|x| x.is_none()).count();
        println!("\nplayer bag: {} slots, {free} free", s.len());
        api.op("release_handle", json!({"handle": player}));
    }
}
