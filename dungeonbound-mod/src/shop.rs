//! The `shop` op: one buy or sell at the shop stop
//! (shop_encounter.gd) inside the game in one request. Operator
//! 2026-11-17: "we need to do this math much faster", "and DRY", "all
//! the auto mode hsouldbe IN the mod". Ported from the auto-player's
//! shop, on the shared reads and the shared judge.
//!
//! From the game's code: `buy(ware)` pays and puts the piece in the
//! bag, refused when the bag has no spot (first_fit BAG, "No room in
//! your bag"); a ware the inventory absorbs (an owned copy of the same
//! level, inventory.gd absorbs) merges into it one level up
//! (EquipmentDB.get_leveled_item) and takes no new cells.
//! Global.sell_item sells an owned piece.
//!
//! Each ware is judged like a forge or a gem: the packer's best
//! equipment value with the ware added (or, when it merges, with the
//! owned copy one level up). Operator 2026-11-16: "maybe we keep 25% of
//! the gold when shopping": a quarter of the gold held on entry is
//! never spent. Mine: the ware that adds the most is bought when it
//! adds more than 0.00001; with no bag spot, the loose bag piece worth
//! least is sold first when it is worth less than the ware adds, never
//! a gem (gems are the gems step's) or a potion.

use std::sync::Mutex;
use std::time::Instant;

use godot::builtin::{AnyArray, GString};
use godot::classes::Object;
use godot::meta::ToGodot;
use godot::obj::Gd;
use godotforge::godot4::{on_main, target};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use crate::arrange;
use crate::grid;
use crate::read::{self, BAG, EQUIP, TRAY};

/// Operator 2026-11-16: "maybe we keep 25% of the gold when shopping".
const KEEP_GOLD: f64 = 0.25;
/// Shops (stop node ids) done, and the gold held on entering the
/// current one.
static DONE: Mutex<i64> = Mutex::new(0);
static ENTRY: Mutex<(i64, i64)> = Mutex::new((0, 0));
/// Least gain a buy must add. Mine: a piece the fight math does not
/// model is valued at a hair above 0 and is never worth gold.
const MIN_GAIN: f64 = 1e-5;
/// Wares packed with the full budget after the quick pass. Mine.
const FINALISTS: usize = 2;

pub fn register_ops() {
    OP_REGISTRY.register_many([OpDef::new(
        "shop",
        "At a shop: buy the ware that adds the most to the equipment (or sell the weakest loose \
         piece to make room for it), one action per request; returns the reasoning lines",
        "{}",
        shop,
    )]);
}

/// A ware on the counter as the judge sees it.
struct Ware {
    card: i64,
    price: i64,
    item: read::Owned,
    /// The owned copy it merges into, and that copy one level up.
    merges: Option<(i64, read::Owned)>,
    bag_spot: bool,
}

/// A piece's value per square it fills.
pub fn per_cell(o: &read::Owned) -> f64 {
    o.piece.value / o.piece.shapes[0].len().max(1) as f64
}

/// The piece on `grids` worth least per square (operator 2026-11-17:
/// "look at all the slots and figure out whats worth the least per
/// square", "NOT THE BEST STUFF JUST CAUSE ITS IN THE LOO BOX"): the
/// wearable ones by their value (`valued`, from arrange::value_all),
/// the rest (other classes, too high a level) at 0. Where it sits does
/// not change its worth. Never a gem, a potion or a locked piece
/// (mine). On a tie, the loot tray goes first, then the bag, then worn
/// (mine). The one choice of what to sell, for the shop and the loot.
pub fn weakest<'a>(
    valued: &'a [read::Owned],
    seen: &'a read::Seen,
    grids: &[i64],
) -> Option<&'a read::Owned> {
    let keep = |o: &&read::Owned| grids.contains(&o.grid) && !o.gem && !o.consumable && !o.locked;
    let order = |g: i64| match g {
        TRAY => 0,
        BAG => 1,
        _ => 2,
    };
    valued
        .iter()
        .filter(keep)
        .chain(seen.list.iter().filter(keep).filter(|o| !o.wearable()))
        .min_by(|a, b| {
            per_cell(a)
                .total_cmp(&per_cell(b))
                .then(order(a.grid).cmp(&order(b.grid)))
        })
}

/// Sell an owned piece by its object id through the game's own sell
/// (Global.sell_item). Its placement goes too, so the game sells that
/// copy and not the first one with the same id (inventory.gd
/// pick_copy takes the tray, then the bag, then worn).
pub fn sell(id: i64) -> Result<bool, String> {
    on_main("sell", move || {
        let mut inv = read::inventory()?;
        let Some(p) = read::row_of(&mut inv, id)? else {
            return Ok(false);
        };
        let Some(item) = read::placed_item(&p) else {
            return Ok(false);
        };
        let gid = item.get("id");
        Ok(read::call(
            &mut read::node("/root/Global")?,
            "sell_item",
            &[gid, p.to_variant()],
        )?
        .try_to::<bool>()
        .unwrap_or(false))
    })
}

fn stop() -> Result<Option<Gd<Object>>, String> {
    Ok(read::find(&target::node_by_path(read::SCENE)?, "shop_encounter.gd", 4).map(|n| n.upcast()))
}

pub fn shop(_args: &Json) -> Result<Json, String> {
    let at = Instant::now();
    let read_all = on_main("shop read", || {
        let Some(mut s) = stop()? else {
            return Ok(None);
        };
        let sid = s.instance_id().to_i64();
        if *DONE.lock().unwrap_or_else(|e| e.into_inner()) == sid {
            return Ok(None);
        }
        let gold = read::call(&mut s, "_gold", &[])?
            .try_to::<i64>()
            .unwrap_or(0);
        let mut inv = read::inventory()?;
        let mut equipment = read::node("/root/EquipmentDB")?;
        let seen = read::seen()?;
        // Owned copies by the game's item id, for merges.
        let mut copies: Vec<(GString, i64)> = Vec::new();
        for g in [EQUIP, BAG] {
            for p in read::placements(&mut inv, g)? {
                if let Some(i) = read::placed_item(&p) {
                    copies.push((
                        i.get("id").try_to().unwrap_or_default(),
                        i.instance_id().to_i64(),
                    ));
                }
            }
        }
        let cards = s
            .get("_cards")
            .try_to::<AnyArray>()
            .map_err(|e| e.to_string())?;
        let mut wares = Vec::new();
        for c in cards.iter_shared() {
            let Ok(card) = c.try_to::<Gd<Object>>() else {
                continue;
            };
            if card.get("sold").try_to::<bool>().unwrap_or(false) {
                continue;
            }
            let price = card.get("price").try_to::<i64>().unwrap_or(i64::MAX);
            let Ok(mut item) = card.get("item").try_to::<Gd<Object>>() else {
                continue;
            };
            let iv = item.to_variant();
            let merges = if read::call(&mut inv, "absorbs", &[iv.clone()])?
                .try_to::<bool>()
                .unwrap_or(false)
            {
                let gid: GString = item.get("id").try_to().unwrap_or_default();
                let base = read::call(&mut item, "get_base_id", &[])?;
                let level = item.get("level").try_to::<i64>().unwrap_or(1);
                let up = read::call(
                    &mut equipment,
                    "get_leveled_item",
                    &[base, (level + 1).to_variant()],
                )?;
                match (
                    copies.iter().find(|(g, _)| *g == gid),
                    up.try_to::<Gd<Object>>(),
                ) {
                    (Some(&(_, owner)), Ok(mut up)) => Some((
                        owner,
                        read::item_of(&mut inv, &mut up, -1, (0, 0, 0), None)?,
                    )),
                    _ => None,
                }
            } else {
                None
            };
            let bag_spot = read::call(&mut inv, "first_fit", &[iv, BAG.to_variant()])?
                .try_to::<godot::builtin::AnyDictionary>()
                .is_ok_and(|d| !d.is_empty());
            wares.push(Ware {
                card: card.instance_id().to_i64(),
                price,
                item: read::item_of(&mut inv, &mut item, -1, (0, 0, 0), None)?,
                merges,
                bag_spot,
            });
        }
        Ok(Some((sid, gold, wares, seen, read::guardian())))
    })?;
    let Some((sid, gold, wares, seen, foe)) = read_all else {
        return Ok(json!({"acted": false, "lines": []}));
    };
    let entry = {
        let mut e = ENTRY.lock().unwrap_or_else(|e| e.into_inner());
        if e.0 != sid {
            *e = (sid, gold);
        }
        e.1
    };
    let keep = (entry as f64 * KEEP_GOLD).ceil() as i64;
    let mut lines = Vec::new();
    let done = |lines: &mut Vec<String>, why: &str| {
        *DONE.lock().unwrap_or_else(|e| e.into_inner()) = sid;
        lines.push(format!("shop: {why}"));
    };
    let foe = match foe {
        Ok(f) => f,
        Err(e) => {
            done(
                &mut lines,
                &format!("no foe to judge against ({e}); nothing bought"),
            );
            return Ok(json!({"acted": false, "lines": lines}));
        }
    };
    let judge = arrange::Judge::new(&seen.hero, vec![foe.clone()]);
    let mut list: Vec<read::Owned> = seen.list.iter().filter(|o| o.wearable()).cloned().collect();
    judge.value_all(&mut list, &seen.board);
    let owned: Vec<grid::Piece> = list.iter().map(|o| o.piece.clone()).collect();
    // Wares that can be paid for (keeping a quarter) and worn.
    let mut asks: Vec<(usize, arrange::Swap)> = Vec::new();
    for (k, w) in wares.iter().enumerate() {
        if gold - w.price < keep || !w.item.wearable() {
            continue;
        }
        let swap = match &w.merges {
            Some((owner, up)) => {
                let Some(t) = list.iter().position(|o| o.id == *owner) else {
                    continue;
                };
                let mut add = list[t].piece.clone();
                judge.price(&mut add, &up.alone, up.score, &seen.board);
                arrange::Swap {
                    remove: vec![t],
                    add,
                }
            }
            None => {
                let mut add = w.item.piece.clone();
                judge.price(&mut add, &w.item.alone, w.item.score, &seen.board);
                arrange::Swap {
                    remove: vec![],
                    add,
                }
            }
        };
        asks.push((k, swap));
    }
    let swaps: Vec<arrange::Swap> = asks
        .iter()
        .map(|(_, s)| arrange::Swap {
            remove: s.remove.clone(),
            add: s.add.clone(),
        })
        .collect();
    let mut g = seen.grid();
    g.sets = judge.set_table(owned.iter().chain(swaps.iter().map(|s| &s.add)));
    // Operator 2026-11-16: "those upgrad should probagbly the the fIRST
    // things we buy im a shop": wares that merge into an owned copy are
    // judged first and bought when they add anything.
    let merging: Vec<usize> = (0..asks.len())
        .filter(|&s| wares[asks[s].0].merges.is_some())
        .collect();
    let only: Vec<arrange::Swap> = merging
        .iter()
        .map(|&s| arrange::Swap {
            remove: swaps[s].remove.clone(),
            add: swaps[s].add.clone(),
        })
        .collect();
    let (without, up) = arrange::rank(&g, seen.hands, &owned, &only, FINALISTS);
    let top: Vec<(f64, usize)> = if up.first().is_some_and(|(v, _)| *v - without > MIN_GAIN) {
        up.into_iter().map(|(v, k)| (v, merging[k])).collect()
    } else {
        arrange::rank(&g, seen.hands, &owned, &swaps, FINALISTS).1
    };
    lines.push(format!(
        "shop: {} wares, {} affordable keeping {keep} of {gold} gold and wearable; judged against {} \
         (hp {} atk {}); equipment value now {without:.4}",
        wares.len(),
        asks.len(),
        foe.name,
        foe.max_hp,
        foe.atk
    ));
    for &(v, s) in &top {
        let w = &wares[asks[s].0];
        lines.push(format!(
            "  {} for {} gold{}: equipment value {v:.4} (adds {:.5})",
            w.item.name,
            w.price,
            if w.merges.is_some() {
                ", merges into the owned copy one level up"
            } else {
                ""
            },
            v - without
        ));
    }
    let Some(&(v, s)) = top.first().filter(|(v, _)| *v - without > MIN_GAIN) else {
        done(&mut lines, "no ware adds to the equipment; done here");
        return Ok(json!({"acted": false, "lines": lines}));
    };
    let w = &wares[asks[s].0];
    let gain = v - without;
    // Room: a ware that does not merge needs a bag spot.
    if w.merges.is_none() && !w.bag_spot {
        let Some(o) = weakest(&list, &seen, &[BAG]).filter(|o| o.piece.value < gain) else {
            done(
                &mut lines,
                &format!(
                    "no bag spot for {} and nothing loose is worth less; done here",
                    w.item.name
                ),
            );
            return Ok(json!({"acted": false, "lines": lines}));
        };
        let (name, worth) = (o.name.clone(), o.piece.value);
        let sold = sell(o.id)?;
        lines.push(format!(
            "shop: no bag spot for {}: sold {name} (worth {worth:.5} < {gain:.5}): {sold}; {:.2}s",
            w.item.name,
            at.elapsed().as_secs_f64()
        ));
        return Ok(json!({"acted": sold, "lines": lines}));
    }
    let card = w.card;
    let bought = on_main("shop buy", move || {
        let Some(mut s) = stop()? else {
            return Ok(false);
        };
        let cards = s
            .get("_cards")
            .try_to::<AnyArray>()
            .map_err(|e| e.to_string())?;
        for c in cards.iter_shared() {
            let Ok(c) = c.try_to::<Gd<Object>>() else {
                continue;
            };
            if c.instance_id().to_i64() == card {
                read::call(&mut s, "buy", &[c.to_variant()])?;
                return Ok(c.get("sold").try_to::<bool>().unwrap_or(false));
            }
        }
        Ok(false)
    })?;
    lines.push(format!(
        "shop: bought {} for {} gold (adds {gain:.5}): {}; {:.2}s",
        w.item.name,
        w.price,
        if bought { "done" } else { "the game refused" },
        at.elapsed().as_secs_f64()
    ));
    if !bought {
        done(&mut lines, "the game refused the buy; done here");
    }
    Ok(json!({"acted": bought, "lines": lines}))
}
