//! Research: the mega forge stop (mega_forge_encounter.gd). Run at a
//! mega forge. Operator 2026-11-16: "mega forge seems incredible. we
//! can combine up to 4 of our biggest items into one item!!", "so we
//! need to review all the numer and figure out what four items we want
//! comtinbed to be as badass as possible right", "test with research
//! like we've been doing", "sso we dont waste this forge".
//!
//! From the game's code: 2 to 4 touching pieces on the anvil (grid 3,
//! 6x5, no potions) join into one piece shaped like the biggest
//! (item_forge.gd mega_spec, mega_model), with every stat of
//! MEGA_INT_STATS and MEGA_FLOAT_STATS summed, the highest rarity and
//! level, and a forge bonus (_mega_gift). Global.mega_forge_preview
//! shows the result without forging.
//!
//! The test prints every owned piece with its numbers, then for the
//! sets that save the most cells puts the pieces on the anvil with the
//! game's own move_to_grid, reads the game's preview, and puts each
//! piece back where it was. Nothing is forged.

mod common;

use modforge::client::Api;
use serde_json::{Value, json};

const SCENE: &str = "/root/@Control@65/CurrentScene";
const FORGE: i64 = 3;
const ANVIL_CELLS: usize = 6 * 5;
/// Sets previewed through the game.
const PREVIEWS: usize = 40;

/// item_forge.gd MEGA_INT_STATS and MEGA_FLOAT_STATS: the stats a
/// mega forge sums.
const SUMMED: [&str; 34] = [
    "bonus_hp",
    "bonus_atk",
    "bonus_armor",
    "bonus_speed",
    "bonus_thorns",
    "bonus_freeze_turns",
    "below_half_atk",
    "below_half_dr",
    "bonus_luck",
    "bonus_magic_resist",
    "bonus_dodge",
    "bonus_crit",
    "bonus_multistrike",
    "lifesteal",
    "bonus_gold_find",
    "bonus_xp_find",
    "bonus_vs_full_hp",
    "bonus_vs_half_hp",
    "bonus_vs_terrified",
    "bonus_block_chance",
    "bonus_block_regen",
    "bonus_atk_percent_of_base",
    "bonus_hp_percent_of_base",
    "bonus_armor_percent_of_base",
    "bonus_atk_pct",
    "bonus_burn_dmg",
    "bonus_poison_dmg",
    "bonus_bleed_dmg",
    "bonus_stun_dmg",
    "bonus_regen_heal",
    "enemy_lifesteal_cut",
    "bonus_block_pierce",
    "dmg_per_self_burn",
    "dmg_per_self_poison",
];

/// `target` is `{"id": n}` or `{"node": path}`.
fn call(api: &Api<Value>, target: &Value, method: &str, args: Value) -> Value {
    let mut a = target.clone();
    a["method"] = json!(method);
    a["args"] = args;
    a["depth"] = json!(2);
    common::op(api, "call_method", a)["result"].clone()
}

struct Piece {
    item: Value,
    name: String,
    grid: i64,
    x: i64,
    y: i64,
    rot: i64,
    cells: usize,
    consumable: bool,
    stats: Vec<(String, f64)>,
    /// Shape and hole cells for turns 0 to 3.
    shapes: Vec<Vec<(i64, i64)>>,
    holes: Vec<Vec<(i64, i64)>>,
}

fn cells_of(v: &Value) -> Vec<(i64, i64)> {
    v.as_array()
        .into_iter()
        .flatten()
        .map(|c| (c[0].as_i64().unwrap_or(0), c[1].as_i64().unwrap_or(0)))
        .collect()
}

/// A spot and turn on the 6x5 anvil for each piece of `set`, in
/// order, by the game's rules (inventory.gd fits: shape cells inside
/// and free, no shape in another piece's holes, no hole on another
/// piece), every piece touching one already placed (game_state.gd
/// mega_forge_block_reason, "Every piece must touch another"). Mine:
/// the first layout found.
fn layout(pieces: &[Piece], set: &[usize]) -> Option<Vec<(i64, i64, i64)>> {
    fn go(
        pieces: &[Piece],
        set: &[usize],
        taken: &mut Vec<(i64, i64)>,
        body: &mut Vec<(i64, i64)>,
        out: &mut Vec<(i64, i64, i64)>,
    ) -> bool {
        let Some(&i) = set.get(out.len()) else {
            return true;
        };
        let p = &pieces[i];
        for rot in 0..4usize {
            if p.shapes[..rot].contains(&p.shapes[rot]) {
                continue;
            }
            for oy in -5..5i64 {
                for ox in -6..6i64 {
                    let shape: Vec<(i64, i64)> = p.shapes[rot]
                        .iter()
                        .map(|&(x, y)| (ox + x, oy + y))
                        .collect();
                    let holes: Vec<(i64, i64)> = p.holes[rot]
                        .iter()
                        .map(|&(x, y)| (ox + x, oy + y))
                        .collect();
                    let inside = shape
                        .iter()
                        .all(|&(x, y)| (0..6).contains(&x) && (0..5).contains(&y));
                    if !inside || shape.iter().chain(&holes).any(|c| taken.contains(c)) {
                        continue;
                    }
                    let touches = body.is_empty()
                        || shape.iter().any(|&(x, y)| {
                            [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
                                .iter()
                                .any(|n| body.contains(n))
                        });
                    if !touches {
                        continue;
                    }
                    let (t, b) = (taken.len(), body.len());
                    taken.extend(shape.iter().chain(&holes));
                    body.extend(&shape);
                    out.push((ox, oy, rot as i64));
                    if go(pieces, set, taken, body, out) {
                        return true;
                    }
                    out.pop();
                    taken.truncate(t);
                    body.truncate(b);
                }
            }
        }
        false
    }
    let mut out = Vec::new();
    go(pieces, set, &mut Vec::new(), &mut Vec::new(), &mut out).then_some(out)
}

fn stats_text(stats: &[(String, f64)]) -> String {
    stats
        .iter()
        .map(|(k, v)| format!("{}={v}", k.trim_start_matches("bonus_")))
        .collect::<Vec<_>>()
        .join(" ")
}

/// The game's own placement row holding `cell` (inventory.gd
/// placement_at), passed as itself.
fn placement(inv: &Value, grid: i64, cell: (i64, i64)) -> Value {
    json!({"call": {"id": inv["id"], "method": "placement_at",
        "args": [grid, {"vector2i": [cell.0, cell.1]}]}})
}

fn first_cell(api: &Api<Value>, item: &Value, rot: i64) -> (i64, i64) {
    call(api, item, "shape_cells", json!([rot]))
        .as_array()
        .and_then(|c| c.first().cloned())
        .map_or((0, 0), |c| {
            (c[0].as_i64().unwrap_or(0), c[1].as_i64().unwrap_or(0))
        })
}

#[test]
fn research_mega_forge_sets() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    if common::node_with_script(&api, SCENE, "mega_forge_encounter.gd", 8).is_none() {
        eprintln!("SKIP: no mega forge on screen");
        return;
    }
    let global = json!({"node": "/root/Global"});
    let inv = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "inventory", "depth": 0}),
    )["value"]
        .clone();
    let inv = json!({"id": inv["id"]});
    let mut pieces = Vec::new();
    for grid in [0, 1, 2] {
        for p in call(&api, &inv, "placements_in", json!([grid]))
            .as_array()
            .into_iter()
            .flatten()
        {
            let item = json!({"id": p["item"]["id"]});
            let vars = common::script_vars(&api, &item["id"], 0);
            let get = |k: &str| {
                vars.iter()
                    .find(|v| v["name"] == json!(k))
                    .map(|v| v["value"].clone())
                    .unwrap_or(Value::Null)
            };
            let stats = SUMMED
                .iter()
                .filter_map(|k| {
                    let v = get(k).as_f64()?;
                    (v != 0.0).then(|| (k.to_string(), v))
                })
                .collect();
            pieces.push(Piece {
                name: get("display_name").as_str().unwrap_or("?").to_string(),
                grid,
                x: p["x"].as_i64().unwrap_or(0),
                y: p["y"].as_i64().unwrap_or(0),
                rot: p["rot"].as_i64().unwrap_or(0),
                cells: call(&api, &item, "shape_cells", json!([0]))
                    .as_array()
                    .map_or(0, Vec::len),
                consumable: get("item_type") == json!(2),
                stats,
                shapes: (0..4)
                    .map(|r| cells_of(&call(&api, &item, "shape_cells", json!([r]))))
                    .collect(),
                holes: (0..4)
                    .map(|r| cells_of(&call(&api, &item, "hole_cells", json!([r]))))
                    .collect(),
                item,
            });
        }
    }
    println!("== owned pieces (grid 0 worn, 1 bag, 2 tray)");
    for p in &pieces {
        println!(
            "  {:<26} grid {} at ({}, {}) turn {}  {:>2} cells{}  {}",
            p.name,
            p.grid,
            p.x,
            p.y,
            p.rot,
            p.cells,
            if p.consumable {
                "  potion (anvil refuses)"
            } else {
                ""
            },
            stats_text(&p.stats)
        );
    }
    // Every set of 2 to 4 pieces the anvil can hold, most cells saved
    // first (the joined piece takes the biggest one's cells).
    let usable: Vec<usize> = (0..pieces.len())
        .filter(|&i| !pieces[i].consumable)
        .collect();
    let mut sets: Vec<(usize, Vec<usize>)> = Vec::new();
    let n = usable.len();
    for mask in 1u32..(1 << n) {
        let k = mask.count_ones() as usize;
        if !(2..=4).contains(&k) {
            continue;
        }
        let set: Vec<usize> = (0..n)
            .filter(|b| mask & (1 << b) != 0)
            .map(|b| usable[b])
            .collect();
        let total: usize = set.iter().map(|&i| pieces[i].cells).sum();
        if total > ANVIL_CELLS {
            continue;
        }
        let biggest = set.iter().map(|&i| pieces[i].cells).max().unwrap_or(0);
        sets.push((total - biggest, set));
    }
    let counted = sets.len();
    // Biggest first: the game takes the shape from the biggest piece.
    let mut laid: Vec<(usize, Vec<usize>, Vec<(i64, i64, i64)>, f64)> = sets
        .into_iter()
        .filter_map(|(saved, mut set)| {
            set.sort_by(|a, b| pieces[*b].cells.cmp(&pieces[*a].cells));
            let spots = layout(&pieces, &set)?;
            // Mine, to order the previews: summed hp + armor + atk.
            let sum: f64 = set
                .iter()
                .flat_map(|&i| &pieces[i].stats)
                .filter(|(k, _)| matches!(k.as_str(), "bonus_hp" | "bonus_armor" | "bonus_atk"))
                .map(|(_, v)| v)
                .sum();
            Some((saved, set, spots, sum))
        })
        .collect();
    laid.sort_by(|a, b| b.0.cmp(&a.0).then(b.3.total_cmp(&a.3)));
    println!(
        "== {counted} sets fit the anvil by cell count, {} lay out touching by the game's rules; \
         previewing the {PREVIEWS} that save the most cells (ties: most hp + armor + atk)",
        laid.len()
    );
    let sets: Vec<(usize, Vec<usize>, Vec<(i64, i64, i64)>)> = laid
        .into_iter()
        .map(|(s, set, spots, _)| (s, set, spots))
        .collect();
    let mut read: Vec<Value> = SUMMED.iter().map(|k| json!(k)).collect();
    read.push(json!("display_name"));
    read.push(json!({"method": "shape_cells", "args": [0]}));
    for (saved, set, spots) in sets.iter().take(PREVIEWS) {
        let names: Vec<&str> = set.iter().map(|&i| pieces[i].name.as_str()).collect();
        let mut moved = Vec::new();
        let mut refused = None;
        for (&i, &(ox, oy, rot)) in set.iter().zip(spots) {
            let p = &pieces[i];
            let (fx, fy) = first_cell(&api, &p.item, p.rot);
            let row = placement(&inv, p.grid, (p.x + fx, p.y + fy));
            let to = json!([row, FORGE, {"vector2i": [ox, oy]}, rot]);
            if call(&api, &inv, "move", to) == json!(true) {
                moved.push(i);
            } else {
                refused = Some(p.name.clone());
                break;
            }
        }
        let why = call(&api, &global, "mega_forge_block_reason", json!([]));
        let got = if refused.is_none() && why == json!("") {
            common::op(
                &api,
                "call_method",
                json!({"node": "/root/Global", "method": "mega_forge_preview", "args": [],
                    "read": read, "depth": 1}),
            )["read"]
                .clone()
        } else {
            Value::Null
        };
        // Each piece back where it was.
        for &i in &moved {
            let p = &pieces[i];
            let row = call(&api, &inv, "placements_in", json!([FORGE]))
                .as_array()
                .into_iter()
                .flatten()
                .find(|r| r["item"]["id"] == p.item["id"])
                .cloned();
            let Some(row) = row else {
                println!("  !! {} is not on the anvil", p.name);
                continue;
            };
            let rot = row["rot"].as_i64().unwrap_or(0);
            let (fx, fy) = first_cell(&api, &p.item, rot);
            let at = placement(
                &inv,
                FORGE,
                (
                    row["x"].as_i64().unwrap_or(0) + fx,
                    row["y"].as_i64().unwrap_or(0) + fy,
                ),
            );
            let back = call(
                &api,
                &inv,
                "move",
                json!([at, p.grid, {"vector2i": [p.x, p.y]}, p.rot]),
            );
            if back != json!(true) {
                println!("  !! could not put {} back", p.name);
            }
        }
        if let Some(r) = refused {
            println!("-- {names:?}: saves {saved} cells; the anvil refused {r}");
            continue;
        }
        if got.is_null() {
            println!("-- {names:?}: saves {saved} cells; blocked: {why}");
            continue;
        }
        let stats: Vec<(String, f64)> = SUMMED
            .iter()
            .filter_map(|k| {
                let v = got[*k].as_f64()?;
                (v != 0.0).then(|| (k.to_string(), v))
            })
            .collect();
        println!(
            "-- {names:?}: saves {saved} cells -> {} ({} cells)  {}",
            got["display_name"].as_str().unwrap_or("?"),
            got["shape_cells"].as_array().map_or(0, Vec::len),
            stats_text(&stats)
        );
    }
    let left = call(&api, &inv, "placements_in", json!([FORGE]));
    assert!(
        left.as_array().is_none_or(Vec::is_empty),
        "pieces left on the anvil: {left}"
    );
}
