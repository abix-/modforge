//! Research: the shortest chain of neighbouring nations from Ukraine to
//! TI_NATION (default Niger), by TINationState.AdjacentNations(false)
//! (any adjacency) and AdjacentNations(true) (the full adjacency an
//! invading army needs).
//!
//! ```text
//! TI_NATION=Niger TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_nation_path -- --nocapture
//! ```

mod common;
use std::collections::{HashMap, VecDeque};

use common::{Api, api_or_skip};
use serde_json::{Value as Json, json};

fn handle(v: &Json) -> Option<i64> {
    v["handle"].as_i64()
}

fn call(api: &Api, h: i64, method: &str, args: Json) -> Json {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    assert!(r.ok, "{method} failed: {:?}", r.error);
    r.result
}

fn name(api: &Api, h: i64) -> String {
    let r = api.op("read_field", json!({"handle": h, "field": "displayName"}));
    let v = if r.ok { r.result } else { call(api, h, "get_displayName", json!([])) };
    v.as_str().unwrap_or("?").to_string()
}

fn path(api: &Api, home: i64, goal: &str, full_only: bool) -> Option<Vec<String>> {
    let mut parent: HashMap<String, Option<String>> = HashMap::from([(name(api, home), None)]);
    let mut queue = VecDeque::from([home]);
    while let Some(n) = queue.pop_front() {
        let here = name(api, n);
        if here == goal {
            let mut chain = vec![here.clone()];
            let mut at = here;
            while let Some(Some(p)) = parent.get(&at) {
                chain.push(p.clone());
                at = p.clone();
            }
            chain.reverse();
            return Some(chain);
        }
        let adjacent = handle(&call(api, n, "AdjacentNations", json!([full_only])))?;
        let count = call(api, adjacent, "get_Count", json!([])).as_i64().unwrap_or(0);
        for i in 0..count {
            let Some(next) = handle(&call(api, adjacent, "get_Item", json!([i]))) else {
                continue;
            };
            let next_name = name(api, next);
            if !parent.contains_key(&next_name) {
                parent.insert(next_name, Some(here.clone()));
                queue.push_back(next);
            }
        }
        if parent.len() > 400 {
            break;
        }
    }
    None
}

#[test]
fn path_from_ukraine() {
    let Some(api) = api_or_skip() else { return };
    let goal = std::env::var("TI_NATION").unwrap_or_else(|_| "Niger".into());
    let r = api.op(
        "invoke_static",
        json!({"class": "PavonisInteractive.TerraInvicta.GameStateManager", "method": "AllNations"}),
    );
    assert!(r.ok, "{:?}", r.error);
    let nations = handle(&r.result).unwrap();
    let n = call(&api, nations, "get_Length", json!([])).as_i64().unwrap();
    let home = (0..n)
        .filter_map(|i| handle(&call(&api, nations, "GetValue", json!([i]))))
        .find(|&h| name(&api, h) == "Ukraine")
        .expect("Ukraine");
    for full_only in [false, true] {
        match path(&api, home, &goal, full_only) {
            Some(chain) => println!(
                "AdjacentNations({full_only}): {} borders: {}",
                chain.len() - 1,
                chain.join(" -> ")
            ),
            None => println!("AdjacentNations({full_only}): no path to {goal}"),
        }
    }
}
