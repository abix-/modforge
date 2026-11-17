//! The `gems` op: socket owned gems into owned pieces inside the game
//! in one request. Operator 2026-11-16: "gems can go inside other
//! itmes. we gotta meke sure bot undestand hwo to use gems proeprly".
//!
//! From the game's code (gem_db.gd): ruby, emerald and sapphire add a
//! share of the piece's own damage, hp or block by the gem's rarity
//! (or a flat amount on a piece without it), so where a gem goes
//! matters; topaz, moonstone, amethyst and citrine add a flat amount;
//! onyx adds thorns; fire opal, jade and bloodstone add a status to the
//! piece's trigger; chronite and hourglass pearl shorten timers; echo
//! makes a trigger fire twice; fletcher adds ammo; the prism of
//! ascension raises the piece a level. GemDB.refusal says why a gem
//! cannot go into a piece. Global.socket_gem is the game's own socket
//! step (what dragging a gem onto a piece does, item_grid_ui.gd).
//!
//! For every owned gem and owned piece the game would take it into,
//! the socketed piece is built by the game's own recipe
//! (GemDB.socketed_spec, EquipmentDB.item_from_spec) without making it,
//! valued by the same judge as arrange.rs, and judged by the packer's
//! best equipment value with the socketed piece in place of the plain
//! one. Mine: the best pairing is socketed when it beats leaving the gem
//! out; one gem per request. A gem whose effect the fight math does not
//! model adds nothing and stays in the bag.

use std::sync::Mutex;
use std::time::Instant;

use godot::builtin::{GString, Variant};
use godot::classes::Object;
use godot::meta::ToGodot;
use godot::obj::Gd;
use godotforge::godot4::{on_main, ops::script_vars};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use crate::arrange;
use crate::fight::{self, Run};
use crate::grid;
use crate::items::stats_from;
use crate::read;

/// The owned items of the last look that socketed nothing, so the same
/// set is not judged again.
static TRIED: Mutex<Vec<i64>> = Mutex::new(Vec::new());

pub fn register_ops() {
    OP_REGISTRY.register_many([OpDef::new(
        "gems",
        "Socket the owned gem that adds the most to the equipment into its best piece, by the game's \
         own preview and socket step; returns the reasoning lines",
        "{force?: false}",
        gems,
    )]);
}

/// What the game would make of `target` with `gem` in it, or why not.
fn socketed(
    gem: &mut Gd<Object>,
    target: &mut Gd<Object>,
) -> Result<Result<Vec<(&'static str, f64)>, String>, String> {
    let mut db: Gd<Object> = read::held(&read::node("/root/LootDB")?, "GemDB")?;
    let (g, t) = (gem.to_variant(), target.to_variant());
    let why = read::call(&mut db, "refusal", &[g.clone(), t.clone()])?.to_string();
    if !why.is_empty() {
        return Ok(Err(why));
    }
    let mut equipment = read::node("/root/EquipmentDB")?;
    let made = if read::call(&mut db, "levels_up", &[g.clone()])?
        .try_to::<bool>()
        .unwrap_or(false)
    {
        // game_state.gd _socket_level_gem: a custom piece levels through
        // ItemForge.level_custom, which the mod does not reach yet.
        if target.get("custom").try_to::<bool>().unwrap_or(false) {
            return Ok(Err(
                "a level gem on a custom piece is not previewed yet".into()
            ));
        }
        let base: GString = read::call(target, "get_base_id", &[])?
            .try_to()
            .map_err(|e| e.to_string())?;
        let level = target.get("level").try_to::<i64>().unwrap_or(0);
        read::call(
            &mut equipment,
            "get_leveled_item",
            &[base.to_variant(), (level + 1).to_variant()],
        )?
    } else {
        let spec = read::call(&mut db, "socketed_spec", &[g, t])?;
        read::call(&mut equipment, "item_from_spec", &[spec])?
    };
    let Ok(item) = made.try_to::<Gd<Object>>() else {
        return Ok(Err("the game made no piece".into()));
    };
    Ok(Ok(stats_from(&script_vars(&item, 0))))
}

fn stats_text(stats: &[(&str, f64)]) -> String {
    stats
        .iter()
        .map(|(k, v)| format!("{k} {}", (v * 1000.0).round() / 1000.0))
        .collect::<Vec<_>>()
        .join(", ")
}

fn gems(args: &Json) -> Result<Json, String> {
    let force = args.get("force").and_then(Json::as_bool).unwrap_or(false);
    let at = Instant::now();
    let (seen, me, foe) = on_main("gems read", || {
        Ok((read::seen()?, read::player()?, read::guardian()))
    })?;
    let gem_ids: Vec<i64> = seen.list.iter().filter(|o| o.gem).map(|o| o.id).collect();
    if gem_ids.is_empty() {
        return Ok(json!({"acted": false, "lines": []}));
    }
    let ids = seen.ids();
    if !force && *TRIED.lock().unwrap_or_else(|e| e.into_inner()) == ids {
        return Ok(json!({"acted": false, "lines": []}));
    }
    let mut lines = Vec::new();
    let foe = match foe {
        Ok(f) => f,
        Err(e) => {
            lines.push(format!(
                "gems: no foe to judge against ({e}); nothing socketed"
            ));
            return Ok(json!({"acted": false, "lines": lines}));
        }
    };
    let squad = vec![foe.clone()];
    let names: Vec<(i64, String)> = seen.list.iter().map(|o| (o.id, o.name.clone())).collect();
    let name = |id: i64| {
        names
            .iter()
            .find(|(i, _)| *i == id)
            .map_or_else(|| id.to_string(), |(_, n)| n.clone())
    };
    let mut list: Vec<read::Owned> = seen.list.into_iter().filter(|o| o.wearable()).collect();
    let bare = arrange::value_all(&mut list, &me, &squad);
    let base = fight::score(&bare, &squad, Run::Campaign).margin;
    // Every gem into every wearable piece, previewed by the game in one
    // main-thread pass.
    let targets: Vec<i64> = list.iter().map(|o| o.id).collect();
    let asks: Vec<(i64, i64)> = gem_ids
        .iter()
        .flat_map(|&g| targets.iter().map(move |&t| (g, t)))
        .collect();
    let asked = asks.clone();
    let made = on_main("gems preview", move || {
        let mut inv = read::inventory()?;
        let mut out = Vec::new();
        for (g, t) in &asked {
            let (Some(gp), Some(tp)) = (read::row_of(&mut inv, *g)?, read::row_of(&mut inv, *t)?)
            else {
                out.push(Err("gone".to_string()));
                continue;
            };
            let (Some(mut gi), Some(mut ti)) = (read::placed_item(&gp), read::placed_item(&tp))
            else {
                out.push(Err("gone".to_string()));
                continue;
            };
            out.push(socketed(&mut gi, &mut ti)?);
        }
        Ok(out)
    })?;
    // Judge: the packer's best equipment value with the socketed piece
    // in place of the plain one.
    let g = grid::Grid {
        w: seen.w,
        h: seen.h,
        open: seen.open.clone(),
    };
    let owned: Vec<grid::Piece> = list.iter().map(|o| o.piece.clone()).collect();
    let mut kept: Vec<(usize, Vec<(&'static str, f64)>, f64)> = Vec::new();
    let mut refused: Vec<(i64, String)> = Vec::new();
    for (k, got) in made.into_iter().enumerate() {
        match got {
            Ok(stats) => {
                let v = arrange::value(&bare, base, &squad, &stats);
                kept.push((k, stats, v));
            }
            Err(why) => refused.push((asks[k].0, why)),
        }
    }
    let swaps: Vec<arrange::Swap> = kept
        .iter()
        .map(|(k, _, v)| {
            let t = targets.iter().position(|&t| t == asks[*k].1).unwrap_or(0);
            let mut add = owned[t].clone();
            add.value = *v;
            arrange::Swap {
                remove: vec![t],
                add,
            }
        })
        .collect();
    let (without, top) = arrange::rank(&g, seen.hands, &owned, &swaps);
    lines.push(format!(
        "gems: {} gems, {} pieces they could go into, {} the game takes; judged against {} (hp {} atk {}); \
         equipment value without a gem {without:.4}. Best pairings:",
        gem_ids.len(),
        targets.len(),
        kept.len(),
        foe.name,
        foe.max_hp,
        foe.atk
    ));
    for &(v, s) in &top {
        let (k, stats, pv) = &kept[s];
        lines.push(format!(
            "  {} into {}: piece value {:.4} (was {:.4}), equipment value {v:.4}  [{}]",
            name(asks[*k].0),
            name(asks[*k].1),
            pv,
            list[swaps[s].remove[0]].piece.value,
            stats_text(stats)
        ));
    }
    for &gid in &gem_ids {
        if !kept.iter().any(|(k, _, _)| asks[*k].0 == gid) {
            let why = refused
                .iter()
                .find(|(g, _)| *g == gid)
                .map_or("no piece", |(_, w)| w.as_str());
            lines.push(format!("  {}: no piece takes it ({why})", name(gid)));
        }
    }
    let best = top.first().filter(|(v, _)| *v > without + 1e-9).copied();
    let Some((v, s)) = best else {
        *TRIED.lock().unwrap_or_else(|e| e.into_inner()) = ids;
        lines.push(
            "gems: no gem adds to the equipment by the fight math (status, timer, echo, ammo and thorns \
             are not valued yet); all stay in the bag"
                .into(),
        );
        return Ok(json!({"acted": false, "lines": lines}));
    };
    let (gid, tid) = asks[kept[s].0];
    let done = on_main("gems socket", move || {
        let mut inv = read::inventory()?;
        let (Some(gp), Some(tp)) = (read::row_of(&mut inv, gid)?, read::row_of(&mut inv, tid)?)
        else {
            return Ok(false);
        };
        let mut global = read::node("/root/Global")?;
        Ok(read::call(
            &mut global,
            "socket_gem",
            &[gp.to_variant(), tp.to_variant(), Variant::from(true)],
        )?
        .try_to::<bool>()
        .unwrap_or(false))
    })?;
    lines.push(format!(
        "gems: socketing {} into {} (equipment value {v:.4} against {without:.4}): {}; {:.2}s in all",
        name(gid),
        name(tid),
        if done { "done" } else { "the game refused" },
        at.elapsed().as_secs_f64()
    ));
    Ok(json!({"acted": done, "lines": lines}))
}
