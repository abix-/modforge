//! How the laboratory works. First question: which crafting stations
//! does the loaded save have, and what state is each in.
//!
//! Access chain (research.md "Craft system"):
//!   CraftSystem.get_CraftSystemData() -> activeCrafts (List<CraftComponent>)
//!   CraftComponent.craftableObject (WgoData) -> id
//!
//! Needs the game running with a save loaded.

mod common;

use common::*;
use serde_json::json;

#[test]
fn research_laboratory_stations() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let data = api.op(
        "invoke_static",
        json!({"class": "CraftSystem", "method": "get_CraftSystemData", "args": []}),
    );
    assert!(data.ok, "get_CraftSystemData: {:?}", data.error);
    let data = handle_of(&data.result).expect("CraftSystemData has no handle");

    let crafts = api.op("read_field", json!({"handle": data, "field": "activeCrafts"}));
    assert!(crafts.ok, "activeCrafts: {:?}", crafts.error);
    let crafts = handle_of(&crafts.result).expect("activeCrafts has no handle");

    let n = count_of(&api, crafts).expect("activeCrafts has no count");
    println!("{n} active craft station(s)");
    assert!(n > 0, "no active craft stations: is a save loaded?");

    for i in 0..n {
        let cc = api.op(
            "invoke_method",
            json!({"handle": crafts, "method": "get_Item", "args": [i]}),
        );
        let Some(cc) = handle_of(&cc.result) else {
            println!("[{i}] get_Item: {:?}", cc.error);
            continue;
        };
        let status = api.op("read_field", json!({"handle": cc, "field": "status"}));
        let wgo = api.op("read_field", json!({"handle": cc, "field": "craftableObject"}));
        let id = handle_of(&wgo.result)
            .map(|w| api.op("read_field", json!({"handle": w, "field": "id"})).result)
            .unwrap_or(json!(null));
        println!("[{i}] {id} status={}", status.result);
    }
}

/// GameBalance's fields, to find the list of world object definitions
/// ("Laboratory I" is a display name; its definition id is not known yet).
#[test]
fn research_laboratory_game_balance_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let gb = api.op(
        "invoke_static",
        json!({"class": "GameBalance", "method": "get_Me", "args": []}),
    );
    assert!(gb.ok, "GameBalance.get_Me: {:?}", gb.error);
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");

    let f = fields(&api, gb).expect("inspect_object GameBalance failed");
    let props = f["properties"].as_array().expect("GameBalance has no properties");
    println!("GameBalance: {} propertie(s)", props.len());
    for p in props {
        let mut value = p["value"].to_string();
        value.truncate(80);
        println!("  {} {} : {} = {value}", p["kind"], p["name"], p["type"]);
    }
}

/// The shape of the lab's recipe data in GameBalance: the alchemy lists,
/// the mix cache, and craftsInCache for the Laboratory I object
/// (alchemy_mix).
#[test]
fn research_laboratory_recipe_data() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gb = api.op(
        "invoke_static",
        json!({"class": "GameBalance", "method": "get_Me", "args": []}),
    );
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");

    for field in ["alchemyFormulaDefs", "alchemyMixSourceDefs", "alchemyMixDefsCache"] {
        let r = api.op("read_field", json!({"handle": gb, "field": field}));
        let Some(h) = handle_of(&r.result) else {
            println!("{field}: {:?}", r.error);
            continue;
        };
        println!("{field}: {:?} entries", count_of(&api, h));
        let first = api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [0]}));
        match handle_of(&first.result) {
            Some(e) => print_fields(&api, &format!("{field}[0]"), e),
            None => println!("{field}[0]: {} {:?}", first.result, first.error),
        }
    }

    let cache = api.op("read_field", json!({"handle": gb, "field": "craftsInCache"}));
    let cache = handle_of(&cache.result).expect("craftsInCache has no handle");
    let crafts = api.op(
        "invoke_method",
        json!({"handle": cache, "method": "get_Item", "args": ["alchemy_mix"]}),
    );
    match handle_of(&crafts.result) {
        Some(h) => println!("craftsInCache[alchemy_mix]: {:?} entries", count_of(&api, h)),
        None => println!("craftsInCache[alchemy_mix]: {} {:?}", crafts.result, crafts.error),
    }
}

/// Every lab recipe: the 29 alchemy formulas (result, runes, tab, stations)
/// and every ingredient combination (alchemyMixSourceDefs) that makes one.
/// The full combination list goes to lab_recipes.csv in
/// CARGO_TARGET_TMPDIR; the path is printed.
#[test]
fn research_laboratory_recipes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let l = |key: &str| -> String {
        if key.is_empty() {
            return String::new();
        }
        let r = api.op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [key]}));
        r.result.as_str().unwrap_or("?").to_string()
    };
    let gb = api.op(
        "invoke_static",
        json!({"class": "GameBalance", "method": "get_Me", "args": []}),
    );
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");

    // Combinations first, to count them per formula.
    let sources = api.op("read_field", json!({"handle": gb, "field": "alchemyMixSourceDefs"}));
    let sources = handle_of(&sources.result).expect("alchemyMixSourceDefs has no handle");
    let n = count_of(&api, sources).expect("alchemyMixSourceDefs has no count");
    let mut combos: Vec<(String, [String; 3])> = Vec::new();
    for i in 0..n {
        let e = api.op("invoke_method", json!({"handle": sources, "method": "get_Item", "args": [i]}));
        let Some(e) = handle_of(&e.result) else {
            continue;
        };
        let f = fields(&api, e).expect("inspect_object failed");
        api.op("release_handle", json!({"handle": e}));
        let get = |name: &str| -> String {
            f["properties"]
                .as_array()
                .and_then(|a| a.iter().find(|p| p["name"] == name))
                .and_then(|p| p["value"].as_str())
                .unwrap_or("")
                .to_string()
        };
        combos.push((
            get("formulaId"),
            [get("ingredient1"), get("ingredient2"), get("ingredient3")],
        ));
    }
    println!("{} combination(s) read of {n}", combos.len());

    // Display names, one lookup per distinct id.
    let mut names = std::collections::HashMap::new();
    for (formula, ings) in &combos {
        for id in std::iter::once(formula).chain(ings) {
            if !names.contains_key(id) {
                names.insert(id.clone(), l(id));
            }
        }
    }

    let formulas = api.op("read_field", json!({"handle": gb, "field": "alchemyFormulaDefs"}));
    let formulas = handle_of(&formulas.result).expect("alchemyFormulaDefs has no handle");
    let m = count_of(&api, formulas).expect("alchemyFormulaDefs has no count");
    println!("{m} formula(s): id = name | runes r/g/b | tab | hiddenAtStart | stations | combinations");
    for i in 0..m {
        let e = api.op("invoke_method", json!({"handle": formulas, "method": "get_Item", "args": [i]}));
        let Some(e) = handle_of(&e.result) else {
            continue;
        };
        let rf = |field: &str| api.op("read_field", json!({"handle": e, "field": field})).result;
        let id = rf("id").as_str().unwrap_or("").to_string();
        let crafts_in = handle_of(&rf("craftsIn"))
            .map(|h| {
                let k = count_of(&api, h).unwrap_or(0);
                (0..k)
                    .map(|j| {
                        api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [j]}))
                            .result
                            .to_string()
                    })
                    .collect::<Vec<_>>()
                    .join(",")
            })
            .unwrap_or_default();
        let count = combos.iter().filter(|(f, _)| *f == id).count();
        println!(
            "  {id} = {} | {}/{}/{} | {} | {} | {crafts_in} | {count}",
            names.get(&id).cloned().unwrap_or_else(|| l(&id)),
            rf("runesRed"),
            rf("runesGreen"),
            rf("runesBlue"),
            rf("tab"),
            rf("hiddenAtStart"),
        );
    }

    let path = std::path::Path::new(env!("CARGO_TARGET_TMPDIR")).join("lab_recipes.csv");
    let mut csv = String::from("result_id,result,ingredient1,ingredient2,ingredient3\n");
    for (formula, ings) in &combos {
        let name = |id: &String| names.get(id).cloned().unwrap_or_default();
        csv.push_str(&format!(
            "{formula},{},{},{},{}\n",
            name(formula),
            name(&ings[0]),
            name(&ings[1]),
            name(&ings[2]),
        ));
    }
    std::fs::write(&path, csv).expect("write lab_recipes.csv");
    println!("wrote {}", path.display());
    assert_eq!(combos.len() as i64, n, "some combinations could not be read");
}

/// Where an item's runes live: the full fields of an ItemDef (the first
/// formula's result, Dream Dust).
#[test]
fn research_laboratory_item_def_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gb = api.op(
        "invoke_static",
        json!({"class": "GameBalance", "method": "get_Me", "args": []}),
    );
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let formulas = api.op("read_field", json!({"handle": gb, "field": "alchemyFormulaDefs"}));
    let formulas = handle_of(&formulas.result).expect("alchemyFormulaDefs has no handle");
    let first = api.op("invoke_method", json!({"handle": formulas, "method": "get_Item", "args": [0]}));
    let first = handle_of(&first.result).expect("alchemyFormulaDefs[0] has no handle");
    let item = api.op("read_field", json!({"handle": first, "field": "ItemDef"}));
    let item = handle_of(&item.result).expect("ItemDef has no handle");
    print_fields(&api, "alchemyFormulaDefs[0].ItemDef", item);
}

/// How the game turns ItemDef.runesRed/Green/Blue (LazyExpression) into a
/// number: the methods on LazyExpression and ItemDef.
#[test]
fn research_laboratory_rune_methods() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    print_declared_methods(&api, "LazyExpression");
    print_declared_methods(&api, "ItemDef");
}

/// Rune data: every item usable in alchemy with its runes
/// (ItemDef.GetRunesAsVector3Int), then a check of every mix: do its
/// ingredients' runes add up to its result's runes (AlchemyFormulaDef
/// runesRed/Green/Blue)?
#[test]
fn research_laboratory_runes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let l = |key: &str| -> String {
        let r = api.op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [key]}));
        r.result.as_str().unwrap_or("?").to_string()
    };
    let item_at = |list: i64, i: i64| -> Option<i64> {
        handle_of(
            &api.op("invoke_method", json!({"handle": list, "method": "get_Item", "args": [i]}))
                .result,
        )
    };
    let gb = api.op(
        "invoke_static",
        json!({"class": "GameBalance", "method": "get_Me", "args": []}),
    );
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let list = |field: &str| -> (i64, i64) {
        let r = api.op("read_field", json!({"handle": gb, "field": field}));
        let h = handle_of(&r.result).unwrap_or_else(|| panic!("{field} has no handle"));
        (h, count_of(&api, h).unwrap_or_else(|| panic!("{field} has no count")))
    };

    // Item runes, keyed by id. Every item is read, so ingredients with
    // canBeUsedInAlchemy false are covered too.
    let (defs, n) = list("itemDefs");
    let mut runes = std::collections::HashMap::new();
    let mut alchemy = Vec::new();
    for i in 0..n {
        let Some(def) = item_at(defs, i) else {
            continue;
        };
        let rf = |field: &str| api.op("read_field", json!({"handle": def, "field": field})).result;
        let id = rf("id").as_str().unwrap_or("").to_string();
        let v = api
            .op("invoke_method", json!({"handle": def, "method": "GetRunesAsVector3Int", "args": []}))
            .result;
        let v = parse_runes(&v);
        if rf("canBeUsedInAlchemy") == json!(true) {
            alchemy.push(id.clone());
        }
        runes.insert(id, v);
        api.op("release_handle", json!({"handle": def}));
    }
    println!("itemDefs: {n}; canBeUsedInAlchemy: {}", alchemy.len());
    println!("alchemy items: id = name | runes r/g/b");
    for id in &alchemy {
        let (r, g, b) = runes[id].unwrap_or((-1, -1, -1));
        println!("  {id} = {} | {r}/{g}/{b}", l(id));
    }

    // Result runes.
    let (formulas, m) = list("alchemyFormulaDefs");
    let mut cost = std::collections::HashMap::new();
    for i in 0..m {
        let Some(f) = item_at(formulas, i) else {
            continue;
        };
        let rf = |field: &str| {
            api.op("read_field", json!({"handle": f, "field": field})).result.as_i64().unwrap_or(-1)
        };
        let id = api.op("read_field", json!({"handle": f, "field": "id"})).result;
        cost.insert(
            id.as_str().unwrap_or("").to_string(),
            (rf("runesRed"), rf("runesGreen"), rf("runesBlue")),
        );
    }

    // Every mix: ingredient runes summed against the result's runes.
    let (sources, k) = list("alchemyMixSourceDefs");
    let (mut matched, mut mismatched, mut unknown) = (0, 0, 0);
    let mut not_alchemy = std::collections::BTreeSet::new();
    for i in 0..k {
        let Some(e) = item_at(sources, i) else {
            continue;
        };
        let f = fields(&api, e).expect("inspect_object failed");
        api.op("release_handle", json!({"handle": e}));
        let get = |name: &str| -> String {
            f["properties"]
                .as_array()
                .and_then(|a| a.iter().find(|p| p["name"] == name))
                .and_then(|p| p["value"].as_str())
                .unwrap_or("")
                .to_string()
        };
        let formula = get("formulaId");
        let ings: Vec<String> = ["ingredient1", "ingredient2", "ingredient3"]
            .iter()
            .map(|n| get(n))
            .filter(|s| !s.is_empty())
            .collect();
        let mut sum = (0, 0, 0);
        let mut known = true;
        for id in &ings {
            if !alchemy.contains(id) {
                not_alchemy.insert(id.clone());
            }
            match runes.get(id).copied().flatten() {
                Some((r, g, b)) => sum = (sum.0 + r, sum.1 + g, sum.2 + b),
                None => known = false,
            }
        }
        let want = cost.get(&formula).copied();
        if !known || want.is_none() {
            unknown += 1;
        } else if Some(sum) == want {
            matched += 1;
        } else {
            mismatched += 1;
            if mismatched <= 20 {
                println!("MISMATCH {formula} {want:?} <- {ings:?} = {sum:?}");
            }
        }
    }
    println!("mixes: {k}; runes add up: {matched}; do not: {mismatched}; unknown: {unknown}");
    println!("ingredients without canBeUsedInAlchemy: {not_alchemy:?}");
}

/// What the player has: the inventory's items (id, count) and the save's
/// alchemy knowledge lists.
#[test]
fn research_laboratory_player_has() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mg = api.op("invoke_static", json!({"class": "MainGame", "method": "get_Instance", "args": []}));
    let mg = handle_of(&mg.result).expect("MainGame has no handle");
    let walk = |start: i64, path: &[&str]| -> i64 {
        path.iter().fold(start, |h, field| {
            let r = api.op("read_field", json!({"handle": h, "field": field}));
            handle_of(&r.result).unwrap_or_else(|| panic!("{field}: {} {:?}", r.result, r.error))
        })
    };

    let items = walk(mg, &["playerController", "playerData", "inventory", "inventoryItem", "inventory"]);
    let n = count_of(&api, items).expect("inventory has no count");
    println!("inventory: {n} item(s)");
    for i in 0..n {
        let it = api.op("invoke_method", json!({"handle": items, "method": "get_Item", "args": [i]}));
        let Some(it) = handle_of(&it.result) else {
            continue;
        };
        let id = api.op("read_field", json!({"handle": it, "field": "id"})).result;
        let count = api.op("invoke_method", json!({"handle": it, "method": "get_Count", "args": []})).result;
        println!("  [{i}] {id} x{count}");
    }

    let ks = walk(mg, &["gameSave", "knowledgeSystem"]);
    for field in ["unlockedAlchemyFormulas", "hiddenAlchemyFormulas", "knownMixCrafts"] {
        let r = api.op("read_field", json!({"handle": ks, "field": field}));
        let Some(h) = handle_of(&r.result) else {
            println!("{field}: {} {:?}", r.result, r.error);
            continue;
        };
        let k = count_of(&api, h).unwrap_or(-1);
        let all: Vec<String> = (0..k)
            .map(|j| {
                api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [j]}))
                    .result
                    .to_string()
            })
            .collect();
        println!("{field}: {k}: {}", all.join(" "));
    }
}

/// What the player can mix right now: every 2 or 3 ingredient mix from the
/// inventory whose runes add up to a result, confirmed against the game's
/// own mix table (GameBalance.alchemyMixSourcesByIdCache, keyed by mixId
/// like "mix:blood:leaf"), grouped by result, unlocked results marked.
#[test]
fn research_laboratory_can_craft() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mg = api.op("invoke_static", json!({"class": "MainGame", "method": "get_Instance", "args": []}));
    let mg = handle_of(&mg.result).expect("MainGame has no handle");
    let walk = |start: i64, path: &[&str]| -> i64 {
        path.iter().fold(start, |h, field| {
            let r = api.op("read_field", json!({"handle": h, "field": field}));
            handle_of(&r.result).unwrap_or_else(|| panic!("{field}: {} {:?}", r.result, r.error))
        })
    };
    let strings = |list: i64| -> Vec<String> {
        let k = count_of(&api, list).unwrap_or(0);
        (0..k)
            .filter_map(|j| {
                api.op("invoke_method", json!({"handle": list, "method": "get_Item", "args": [j]}))
                    .result
                    .as_str()
                    .map(str::to_string)
            })
            .collect()
    };

    // Alchemy ingredients in the inventory: id -> (runes, count).
    let items = walk(mg, &["playerController", "playerData", "inventory", "inventoryItem", "inventory"]);
    let n = count_of(&api, items).expect("inventory has no count");
    let mut have: std::collections::BTreeMap<String, ((i64, i64, i64), i64)> = Default::default();
    for i in 0..n {
        let it = api.op("invoke_method", json!({"handle": items, "method": "get_Item", "args": [i]}));
        let Some(it) = handle_of(&it.result) else {
            continue;
        };
        let def = api.op("invoke_method", json!({"handle": it, "method": "get_Definition", "args": []}));
        let Some(def) = handle_of(&def.result) else {
            continue;
        };
        if api.op("read_field", json!({"handle": def, "field": "canBeUsedInAlchemy"})).result != json!(true) {
            continue;
        }
        let id = api.op("read_field", json!({"handle": it, "field": "id"})).result;
        let id = id.as_str().unwrap_or("").to_string();
        let count = api
            .op("invoke_method", json!({"handle": it, "method": "get_Count", "args": []}))
            .result
            .as_i64()
            .unwrap_or(0);
        let runes = api
            .op("invoke_method", json!({"handle": def, "method": "GetRunesAsVector3Int", "args": []}))
            .result;
        let runes = parse_runes(&runes).expect("runes did not parse");
        have.entry(id).or_insert((runes, 0)).1 += count;
    }
    println!("alchemy ingredients carried: {}", have.len());
    for (id, ((r, g, b), c)) in &have {
        println!("  {id} {r}/{g}/{b} x{c}");
    }

    // Results and their runes; unlocked results.
    let gb = api.op("invoke_static", json!({"class": "GameBalance", "method": "get_Me", "args": []}));
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let formulas = walk(gb, &["alchemyFormulaDefs"]);
    let m = count_of(&api, formulas).expect("alchemyFormulaDefs has no count");
    let mut results = Vec::new();
    for i in 0..m {
        let f = api.op("invoke_method", json!({"handle": formulas, "method": "get_Item", "args": [i]}));
        let f = handle_of(&f.result).expect("formula has no handle");
        let rf = |field: &str| api.op("read_field", json!({"handle": f, "field": field})).result;
        results.push((
            rf("id").as_str().unwrap_or("").to_string(),
            (
                rf("runesRed").as_i64().unwrap_or(-1),
                rf("runesGreen").as_i64().unwrap_or(-1),
                rf("runesBlue").as_i64().unwrap_or(-1),
            ),
        ));
    }
    let unlocked = strings(walk(mg, &["gameSave", "knowledgeSystem", "unlockedAlchemyFormulas"]));
    let known = strings(walk(mg, &["gameSave", "knowledgeSystem", "knownMixCrafts"]));
    let table = walk(gb, &["alchemyMixSourcesByIdCache"]);

    // Every 2 or 3 ingredient multiset the inventory has enough of.
    let ids: Vec<&String> = have.keys().collect();
    let mut mixes: Vec<Vec<&String>> = Vec::new();
    for a in 0..ids.len() {
        for b in a..ids.len() {
            mixes.push(vec![ids[a], ids[b]]);
            for c in b..ids.len() {
                mixes.push(vec![ids[a], ids[b], ids[c]]);
            }
        }
    }
    let enough = |mix: &Vec<&String>| {
        mix.iter().all(|id| have[*id].1 >= mix.iter().filter(|x| *x == id).count() as i64)
    };

    let (mut total, mut not_in_table) = (0, 0);
    for (result, cost) in &results {
        let mut found = Vec::new();
        for mix in mixes.iter().filter(|m| enough(m)) {
            let sum = mix.iter().fold((0, 0, 0), |s, id| {
                let (r, g, b) = have[*id].0;
                (s.0 + r, s.1 + g, s.2 + b)
            });
            if sum != *cost {
                continue;
            }
            let mut sorted: Vec<&str> = mix.iter().map(|s| s.as_str()).collect();
            sorted.sort();
            let key = format!("mix:{}", sorted.join(":"));
            let hit = api.op("invoke_method", json!({"handle": table, "method": "ContainsKey", "args": [key]}));
            if hit.result == json!(true) {
                found.push(key);
            } else {
                not_in_table += 1;
                println!("NOT IN TABLE {result}: {key} {:?}", hit.error);
            }
        }
        if found.is_empty() {
            continue;
        }
        total += found.len();
        let lock = if unlocked.contains(result) { "UNLOCKED" } else { "locked" };
        println!("{result} {cost:?} [{lock}]: {} mix(es)", found.len());
        for key in found {
            let mark = if known.contains(&key) { " (known)" } else { "" };
            println!("  {key}{mark}");
        }
    }
    println!("mixes you can make: {total}; rune sums not in the game's table: {not_in_table}");
}

/// What the growth elixirs do: the game's description and use rules on
/// each elixir's ItemDef.
#[test]
fn research_laboratory_growth_elixirs() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gb = api.op("invoke_static", json!({"class": "GameBalance", "method": "get_Me", "args": []}));
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let formulas = api.op("read_field", json!({"handle": gb, "field": "alchemyFormulaDefs"}));
    let formulas = handle_of(&formulas.result).expect("alchemyFormulaDefs has no handle");
    let m = count_of(&api, formulas).expect("alchemyFormulaDefs has no count");
    for i in 0..m {
        let f = api.op("invoke_method", json!({"handle": formulas, "method": "get_Item", "args": [i]}));
        let f = handle_of(&f.result).expect("formula has no handle");
        let id = api.op("read_field", json!({"handle": f, "field": "id"})).result;
        if !id.as_str().is_some_and(|s| s.ends_with("growing_elixir")) {
            continue;
        }
        let def = api.op("read_field", json!({"handle": f, "field": "ItemDef"}));
        let def = handle_of(&def.result).expect("ItemDef has no handle");
        let call = |m: &str| api.op("invoke_method", json!({"handle": def, "method": m, "args": []})).result;
        println!("== {id}");
        println!("header: {}", call("GetHeader"));
        let desc = call("GetDescription");
        let text = api
            .op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [desc]}))
            .result;
        println!("description: {desc} = {text}");
        for cache in ["craftInItemsCache", "craftInItemsCacheShownInTooltips"] {
            let c = api.op("read_field", json!({"handle": gb, "field": cache}));
            let c = handle_of(&c.result).expect("cache has no handle");
            let r = api.op("invoke_method", json!({"handle": c, "method": "get_Item", "args": [id]}));
            let Some(list) = handle_of(&r.result) else {
                println!("{cache}[{id}]: {} {:?}", r.result, r.error.map(|e| e.chars().take(120).collect::<String>()));
                continue;
            };
            let k = count_of(&api, list).unwrap_or(-1);
            println!("{cache}[{id}]: {k}");
            for j in 0..k {
                let e = api.op("invoke_method", json!({"handle": list, "method": "get_Item", "args": [j]}));
                let Some(e) = handle_of(&e.result) else {
                    println!("  [{j}] {}", e.result);
                    continue;
                };
                let cid = api.op("read_field", json!({"handle": e, "field": "id"})).result;
                let name = api
                    .op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [cid]}))
                    .result;
                println!("  [{j}] {cid} = {name}");
            }
        }
        println!("isFertilizer: {}", api.op("read_field", json!({"handle": def, "field": "isFertilizer"})).result);
        for field in ["itemGroupIds", "canBeUsed", "onUseExpressions", "gameResOnUse"] {
            let r = api.op("read_field", json!({"handle": def, "field": field}));
            let Some(h) = handle_of(&r.result) else {
                println!("{field}: {}", r.result);
                continue;
            };
            match count_of(&api, h) {
                Some(k) => {
                    println!("{field}: {k} entrie(s)");
                    for j in 0..k {
                        let e = api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [j]}));
                        match handle_of(&e.result) {
                            Some(e) => print_fields(&api, &format!("{field}[{j}]"), e),
                            None => println!("{field}[{j}] = {}", e.result),
                        }
                    }
                }
                None => print_fields(&api, field, h),
            }
        }
    }
}

/// Which crafts use a growth elixir: every GameBalance.craftDefs entry whose
/// id or needItems mention "growing_elixir", with its full fields.
#[test]
fn research_laboratory_growth_elixir_crafts() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gb = api.op("invoke_static", json!({"class": "GameBalance", "method": "get_Me", "args": []}));
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let defs = api.op("read_field", json!({"handle": gb, "field": "craftDefs"}));
    let defs = handle_of(&defs.result).expect("craftDefs has no handle");
    let n = count_of(&api, defs).expect("craftDefs has no count");
    println!("craftDefs: {n}");
    for i in 0..n {
        let d = api.op("invoke_method", json!({"handle": defs, "method": "get_Item", "args": [i]}));
        let Some(d) = handle_of(&d.result) else {
            continue;
        };
        let id = api.op("read_field", json!({"handle": d, "field": "id"})).result;
        let mut hit = id.as_str().is_some_and(|s| s.contains("growing_elixir"));
        let need = api.op("read_field", json!({"handle": d, "field": "needItems"}));
        let mut need_text = Vec::new();
        if let Some(need) = handle_of(&need.result) {
            for j in 0..count_of(&api, need).unwrap_or(0) {
                let e = api.op("invoke_method", json!({"handle": need, "method": "get_Item", "args": [j]}));
                let Some(e) = handle_of(&e.result) else {
                    continue;
                };
                let text = fields(&api, e).map(|f| f.to_string()).unwrap_or_default();
                hit |= text.contains("growing_elixir");
                need_text.push(text);
                api.op("release_handle", json!({"handle": e}));
            }
            api.op("release_handle", json!({"handle": need}));
        }
        if hit {
            println!("== [{i}] {id}");
            for (j, t) in need_text.iter().enumerate() {
                println!("  needItems[{j}]: {}", t.chars().take(400).collect::<String>());
            }
            print_fields(&api, "craftDef", d);
        }
        api.op("release_handle", json!({"handle": d}));
    }
}

/// The crafts that use a growth elixir (found by
/// research_laboratory_growth_elixir_crafts): name, stations, needed
/// items with counts, and output.
#[test]
fn research_laboratory_growth_elixir_craft_details() {
    const IDS: [&str; 6] = [
        "create_fertilizer_start_bonus_1",
        "create_fertilizer_start_bonus_2",
        "create_fertilizer_farming_2",
        "create_fertilizer_farming_3",
        "create_fertilizer_farming_5",
        "miracle_growing_elixir",
    ];
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let l = |key: &serde_json::Value| {
        api.op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [key]})).result
    };
    let gb = api.op("invoke_static", json!({"class": "GameBalance", "method": "get_Me", "args": []}));
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let defs = api.op("read_field", json!({"handle": gb, "field": "craftDefs"}));
    let defs = handle_of(&defs.result).expect("craftDefs has no handle");
    // Positions from the scan; each is checked against its id.
    for i in [317, 318, 320, 321, 322, 565] {
        let d = api.op("invoke_method", json!({"handle": defs, "method": "get_Item", "args": [i]}));
        let d = handle_of(&d.result).expect("craftDef has no handle");
        let rf = |h: i64, field: &str| api.op("read_field", json!({"handle": h, "field": field})).result;
        let id = rf(d, "id");
        assert!(IDS.contains(&id.as_str().unwrap_or("")), "craftDefs[{i}] is {id}, not one of the scan's");
        println!("== {id} = {}", l(&id));
        println!("description: {}", l(&rf(d, "description")));
        if let Some(h) = handle_of(&rf(d, "craftsIn")) {
            let k = count_of(&api, h).unwrap_or(0);
            let stations: Vec<String> = (0..k)
                .map(|j| {
                    let s = api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [j]})).result;
                    format!("{s} ({})", l(&s))
                })
                .collect();
            println!("craftsIn: {}", stations.join(", "));
        }
        if let Some(h) = handle_of(&rf(d, "needItems")) {
            for j in 0..count_of(&api, h).unwrap_or(0) {
                let e = api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [j]}));
                let Some(e) = handle_of(&e.result) else { continue };
                let nid = rf(e, "id");
                let count = api.op("invoke_method", json!({"handle": e, "method": "GetCount", "args": [null]}));
                println!("needs: {nid} ({}) x{} {:?}", l(&nid), count.result, count.error.map(|s| s.chars().take(80).collect::<String>()));
            }
        }
        if let Some(h) = handle_of(&rf(d, "outputItems")) {
            print_fields(&api, "outputItems", h);
        }
    }
}

/// What the elixir fertilizers do: each fertilizer craft's output item, and
/// that item's definition with every LazyExpression's formula text. Also
/// the fertilizer methods on the garden classes.
#[test]
fn research_laboratory_fertilizer_effect() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let rf = |h: i64, field: &str| api.op("read_field", json!({"handle": h, "field": field})).result;
    let gb = api.op("invoke_static", json!({"class": "GameBalance", "method": "get_Me", "args": []}));
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let defs = handle_of(&rf(gb, "craftDefs")).expect("craftDefs has no handle");

    // Output item ids of the five fertilizer crafts (positions from the scan).
    let mut outputs = Vec::new();
    for i in [317, 318, 320, 321, 322] {
        let d = api.op("invoke_method", json!({"handle": defs, "method": "get_Item", "args": [i]}));
        let d = handle_of(&d.result).expect("craftDef has no handle");
        let id = rf(d, "id");
        assert!(id.as_str().is_some_and(|s| s.starts_with("create_fertilizer")), "craftDefs[{i}] is {id}");
        let out = handle_of(&rf(d, "outputItems")).expect("no outputItems");
        let list = handle_of(&rf(out, "chanceOutputItems")).expect("no chanceOutputItems");
        for j in 0..count_of(&api, list).unwrap_or(0) {
            let e = api.op("invoke_method", json!({"handle": list, "method": "get_Item", "args": [j]}));
            let Some(e) = handle_of(&e.result) else { continue };
            if j == 0 && outputs.is_empty() {
                print_fields(&api, "chanceOutputItems[0]", e);
            }
            let oid = rf(e, "id");
            println!("{id} -> {oid}");
            if let Some(s) = oid.as_str() {
                if !outputs.iter().any(|o| o == s) {
                    outputs.push(s.to_string());
                }
            }
        }
    }

    // Each output's ItemDef, formulas written out.
    let items = handle_of(&rf(gb, "itemDefs")).expect("itemDefs has no handle");
    let n = count_of(&api, items).expect("itemDefs has no count");
    for i in 0..n {
        let d = api.op("invoke_method", json!({"handle": items, "method": "get_Item", "args": [i]}));
        let Some(d) = handle_of(&d.result) else { continue };
        let id = rf(d, "id");
        if !outputs.iter().any(|o| Some(o.as_str()) == id.as_str()) {
            api.op("release_handle", json!({"handle": d}));
            continue;
        }
        let name = api.op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [id]})).result;
        let desc = api.op("invoke_method", json!({"handle": d, "method": "GetDescription", "args": []})).result;
        let text = api.op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [desc]})).result;
        println!("== {id} = {name}; description {desc} = {text}");
        let f = fields(&api, d).expect("inspect_object failed");
        for p in f["properties"].as_array().expect("no properties") {
            let value = if p["type"] == "LazyExpression" {
                let h = handle_of(&p["value"]).unwrap_or(0);
                let t = rf(h, "expressionStringUnparsed");
                if t == json!("") {
                    continue;
                }
                format!("formula {t}")
            } else if p["type"] == "List`1" {
                let h = handle_of(&p["value"]).unwrap_or(0);
                let k = count_of(&api, h).unwrap_or(0);
                if k == 0 {
                    continue;
                }
                let all: Vec<String> = (0..k)
                    .map(|j| {
                        let e = api.op("invoke_method", json!({"handle": h, "method": "get_Item", "args": [j]})).result;
                        match handle_of(&e) {
                            Some(eh) => fields(&api, eh).map(|x| x.to_string()).unwrap_or_default(),
                            None => e.to_string(),
                        }
                    })
                    .collect();
                format!("[{}]", all.join(", "))
            } else {
                p["value"].to_string()
            };
            let mut value = value;
            value.truncate(600);
            println!("  {} = {value}", p["name"]);
        }
    }

    for class in ["GardenInteractionHandler", "FertilizerSystem", "GardenSystem"] {
        let r = api.op("list_methods", json!({"class": class}));
        if !r.ok {
            println!("list_methods({class}): {:?}", r.error);
            continue;
        }
        println!("{class} methods mentioning fertil/grow:");
        for m in r.result["methods"].as_array().into_iter().flatten() {
            let name = m["name"].as_str().unwrap_or("");
            let low = name.to_lowercase();
            if low.contains("fertil") || low.contains("grow") {
                println!("  {name}({}) -> {}", m["params"], m["return"]);
            }
        }
    }
}

/// "(r, g, b)" from Vector3Int, as the shim prints it.
fn parse_runes(v: &serde_json::Value) -> Option<(i64, i64, i64)> {
    if let (Some(x), Some(y), Some(z)) = (v["x"].as_i64(), v["y"].as_i64(), v["z"].as_i64()) {
        return Some((x, y, z));
    }
    let s = v.as_str()?.trim_matches(|c| c == '(' || c == ')');
    let mut it = s.split(',').map(|p| p.trim().parse::<i64>().ok());
    Some((it.next()??, it.next()??, it.next()??))
}

fn print_fields(api: &unityforge::client::Api<serde_json::Value>, label: &str, h: i64) {
    let f = fields(api, h).expect("inspect_object failed");
    println!("{label}: {}", f["class_name"]);
    for p in f["properties"].as_array().expect("no properties") {
        let mut value = p["value"].to_string();
        value.truncate(80);
        println!("  {} : {} = {value}", p["name"], p["type"]);
    }
}

/// What LLBase.L gives for known station ids, to learn whether a wgo's
/// display name is L(id).
#[test]
fn research_laboratory_localized_names() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for key in ["furnace_2", "crematorium_1", "brick_kiln_1", "builder_alchemy_lab"] {
        let text = api.op(
            "invoke_static",
            json!({"class": "LLBase", "method": "L", "args": [key]}),
        );
        println!("L({key}) = {} {:?}", text.result, text.error);
    }
}

/// Every world object definition (GameBalance.wgoDefs), built or
/// pre-placed, whose display name (LLBase.L(id)) has "aborator" in it, and
/// the full fields of the first one, to find "Laboratory I".
#[test]
fn research_laboratory_wgo_defs() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let gb = api.op(
        "invoke_static",
        json!({"class": "GameBalance", "method": "get_Me", "args": []}),
    );
    let gb = handle_of(&gb.result).expect("GameBalance has no handle");
    let defs = api.op("read_field", json!({"handle": gb, "field": "wgoDefs"}));
    let defs = handle_of(&defs.result).expect("wgoDefs has no handle");
    let n = count_of(&api, defs).expect("wgoDefs has no count");
    println!("wgoDefs: {n}");

    let mut first = None;
    for i in 0..n {
        let def = api.op(
            "invoke_method",
            json!({"handle": defs, "method": "get_Item", "args": [i]}),
        );
        let Some(def) = handle_of(&def.result) else {
            continue;
        };
        let id = api.op("read_field", json!({"handle": def, "field": "id"})).result;
        let name = api
            .op("invoke_static", json!({"class": "LLBase", "method": "L", "args": [id]}))
            .result;
        if name.as_str().is_some_and(|s| s.contains("aborator")) {
            println!("[{i}] {id} = {name}");
            first.get_or_insert(def);
        } else {
            api.op("release_handle", json!({"handle": def}));
        }
    }

    let first = first.expect("no wgoDef display name contains \"aborator\"");
    let f = fields(&api, first).expect("inspect_object failed");
    for p in f["properties"].as_array().expect("no properties") {
        let mut value = p["value"].to_string();
        value.truncate(80);
        println!("  {} : {} = {value}", p["name"], p["type"]);
    }
}
