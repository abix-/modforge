//! The `mega_forge` op: plays the mega forge stop
//! (mega_forge_encounter.gd) inside the game in one request. Operator
//! 2026-11-16: "mega forge seems incredible. we can combine up to 4 of
//! our biggest items into one item!!", "figure out what four items we
//! want comtinbed to be as badass as possible", "bot needs to handle
//! mega forge. do it proeprly first".
//!
//! From the game's code: 2 to 4 touching pieces on the anvil (inventory
//! grid 3, no potions) join into one piece (item_forge.gd mega_spec);
//! Global.mega_forge_preview shows it without forging, Global.mega_forge
//! makes it, the stop's FORGE button is `_forge` and CONTINUE is
//! `finish`, which hands the made piece to the bag.
//!
//! Every set of owned pieces that lays out on the anvil is put there
//! with the game's own move, previewed by the game and put back, all in
//! one main-thread pass so nothing else moves pieces in between. Each
//! made piece is valued by the same judge as arrange.rs, and the set is
//! judged by the packer's best equipment value with the made piece in
//! place of its parts. Mine: the set with the best packed value is
//! forged when it beats packing without forging; otherwise the stop is
//! left with nothing forged. Pieces left on the anvil go back through
//! the game's own return_forge_pieces.

use std::time::Instant;

use godot::builtin::{AnyDictionary, Vector2i};
use godot::classes::Object;
use godot::meta::ToGodot;
use godot::obj::Gd;
use godotforge::godot4::{on_main, on_main_passes, ops::script_vars, target};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use crate::arrange;
use crate::grid::Piece;
use crate::items::stats_from;
use crate::read::{self, FORGE};

pub fn register_ops() {
    OP_REGISTRY.register_many([OpDef::new(
        "mega_forge",
        "At a mega forge: preview every set of owned pieces through the game, forge the set \
         that packs the strongest equipment (or none), and leave the stop; returns the reasoning lines",
        "{}",
        mega_forge,
    )]);
}

/// A spot and turn on the anvil for each piece, in order, by the
/// game's rules (inventory.gd fits: shape cells inside, open and free,
/// no shape on another piece's holes, no hole on another piece), each
/// piece touching one already placed (game_state.gd
/// mega_forge_block_reason: every piece must touch another). Mine: the
/// first layout found, biggest piece first.
pub fn layout(pieces: &[&Piece], w: i32, h: i32, open: &[bool]) -> Option<Vec<(i32, i32, i32)>> {
    fn go(
        pieces: &[&Piece],
        w: i32,
        h: i32,
        open: &[bool],
        taken: &mut Vec<(i32, i32)>,
        body: &mut Vec<(i32, i32)>,
        out: &mut Vec<(i32, i32, i32)>,
    ) -> bool {
        let Some(p) = pieces.get(out.len()) else {
            return true;
        };
        for rot in 0..4usize {
            if p.shapes[..rot].contains(&p.shapes[rot]) {
                continue;
            }
            for oy in -h..h {
                for ox in -w..w {
                    let at = |&(x, y): &(i32, i32)| (ox + x, oy + y);
                    let shape: Vec<(i32, i32)> = p.shapes[rot].iter().map(at).collect();
                    let holes: Vec<(i32, i32)> = p.holes[rot].iter().map(at).collect();
                    let fits = shape.iter().all(|&(x, y)| {
                        (0..w).contains(&x) && (0..h).contains(&y) && open[(y * w + x) as usize]
                    });
                    if !fits || shape.iter().chain(&holes).any(|c| taken.contains(c)) {
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
                    out.push((ox, oy, rot as i32));
                    if go(pieces, w, h, open, taken, body, out) {
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
    go(
        pieces,
        w,
        h,
        open,
        &mut Vec::new(),
        &mut Vec::new(),
        &mut out,
    )
    .then_some(out)
}

/// A piece the game would make.
#[derive(Clone)]
struct Made {
    name: String,
    stats: Vec<(&'static str, f64)>,
    alone: read::Fold,
    /// The game's own score of it (equipment_item.gd stat_score).
    score: f64,
    piece: Piece,
    refusal: String,
}

fn stats_text(stats: &[(&str, f64)]) -> String {
    stats
        .iter()
        .map(|(k, v)| format!("{k} {}", (v * 1000.0).round() / 1000.0))
        .collect::<Vec<_>>()
        .join(", ")
}

use read::row_of;

fn moved(
    inv: &mut Gd<Object>,
    p: &AnyDictionary,
    g: i64,
    x: i32,
    y: i32,
    rot: i32,
) -> Result<bool, String> {
    Ok(read::call(
        inv,
        "move",
        &[
            p.to_variant(),
            g.to_variant(),
            Vector2i::new(x, y).to_variant(),
            (rot as i64).to_variant(),
        ],
    )?
    .try_to::<bool>()
    .unwrap_or(false))
}

/// The set's pieces onto the anvil at their spots; returns each row
/// and where it came from, or why the anvil refused.
fn put_on(
    inv: &mut Gd<Object>,
    ids: &[i64],
    spots: &[(i32, i32, i32)],
) -> Result<(Vec<(AnyDictionary, i64, i32, i32, i32)>, Option<String>), String> {
    let mut rows = Vec::new();
    for (&id, &(x, y, rot)) in ids.iter().zip(spots) {
        let Some(p) = row_of(inv, id)? else {
            return Ok((rows, Some(format!("item {id} is gone"))));
        };
        let int = |k: &str| p.get(k).and_then(|v| v.try_to::<i64>().ok()).unwrap_or(0);
        let from = (
            int("grid"),
            int("x") as i32,
            int("y") as i32,
            int("rot") as i32,
        );
        if !moved(inv, &p, FORGE, x, y, rot)? {
            let name = read::placed_item(&p).map(|i| i.get("display_name").to_string());
            return Ok((
                rows,
                Some(format!("the anvil refused {}", name.unwrap_or_default())),
            ));
        }
        rows.push((p, from.0, from.1, from.2, from.3));
    }
    Ok((rows, None))
}

/// Each row back where it was; false when one would not go.
fn take_off(
    inv: &mut Gd<Object>,
    rows: &[(AnyDictionary, i64, i32, i32, i32)],
) -> Result<bool, String> {
    let mut all = true;
    for (p, g, x, y, rot) in rows.iter().rev() {
        all &= moved(inv, p, *g, *x, *y, *rot)?;
    }
    Ok(all)
}

/// The game's preview of what is on the anvil, or why it would not
/// forge.
fn preview(global: &mut Gd<Object>, inv: &mut Gd<Object>) -> Result<Result<Made, String>, String> {
    let why = read::call(global, "mega_forge_block_reason", &[])?.to_string();
    if !why.is_empty() {
        return Ok(Err(why));
    }
    let Ok(mut item) = read::call(global, "mega_forge_preview", &[])?.try_to::<Gd<Object>>() else {
        return Ok(Err("no preview".into()));
    };
    let (shapes, holes) = read::shapes_of(&mut item)?;
    let iv = item.to_variant();
    Ok(Ok(Made {
        name: item.get("display_name").to_string(),
        stats: stats_from(&script_vars(&item, 0)),
        alone: read::fold(std::slice::from_ref(&item))?,
        score: read::stat_score(&mut item)?,
        piece: Piece {
            value: 0.0,
            shapes,
            holes,
            family: read::call(inv, "equip_family_id", &[iv.clone()])?.to_string(),
            weapon: read::call(&mut item, "is_weapon", &[])?
                .try_to::<bool>()
                .unwrap_or(false),
            place: std::sync::Arc::new(read::place_of(&mut item)?),
        },
        refusal: read::call(inv, "equip_block_reason", &[iv])?.to_string(),
    }))
}

fn stop() -> Result<Option<Gd<Object>>, String> {
    Ok(read::find(
        &target::node_by_path(read::SCENE)?,
        "mega_forge_encounter.gd",
        8,
    )
    .map(|n| n.upcast()))
}

/// Pieces on the anvil go back through the game (game_state.gd
/// return_forge_pieces).
/// The names of the pieces on the anvil now.
fn on_anvil(inv: &mut Gd<Object>) -> Result<Vec<String>, String> {
    Ok(read::placements(inv, FORGE)?
        .iter()
        .filter_map(read::placed_item)
        .map(|i| i.get("display_name").to_string())
        .collect())
}

/// The game sends what is on the anvil to the bag (game_state.gd
/// return_forge_pieces: inventory.stow); says which pieces went.
fn clear_anvil(global: &mut Gd<Object>, inv: &mut Gd<Object>) -> Result<Option<String>, String> {
    let left = on_anvil(inv)?;
    if left.is_empty() {
        return Ok(None);
    }
    read::call(global, "return_forge_pieces", &[])?;
    Ok(Some(format!(
        "mega forge: {} were on the anvil; the game put them in the bag",
        left.join(", ")
    )))
}

/// CONTINUE: the stop hands the made piece (or anything on the anvil)
/// back and closes (mega_forge_encounter.gd finish).
fn leave(s: &mut Gd<Object>) -> Result<(), String> {
    read::call(s, "finish", &[])?;
    Ok(())
}

pub fn mega_forge(_args: &Json) -> Result<Json, String> {
    let at = Instant::now();
    let mut lines = Vec::new();
    // The stop, and nothing left on the anvil from before.
    let found = on_main("mega read", || {
        let mut global = read::node("/root/Global")?;
        let mut inv = read::inventory()?;
        let cleared = clear_anvil(&mut global, &mut inv)?;
        let Some(mut s) = stop()? else {
            return Ok((cleared, None));
        };
        if s.get("_closed").try_to::<bool>().unwrap_or(false) {
            return Ok((cleared, None));
        }
        if !s.get("_held").is_nil() {
            leave(&mut s)?;
            return Ok((cleared, Some(None)));
        }
        let size = read::call(&mut inv, "grid_size", &[FORGE.to_variant()])?
            .try_to::<Vector2i>()
            .map_err(|e| e.to_string())?;
        let mut open = Vec::new();
        for y in 0..size.y {
            for x in 0..size.x {
                open.push(
                    read::call(
                        &mut inv,
                        "cell_open",
                        &[FORGE.to_variant(), Vector2i::new(x, y).to_variant()],
                    )?
                    .try_to::<bool>()
                    .unwrap_or(false),
                );
            }
        }
        Ok((
            cleared,
            Some(Some((
                read::seen()?,
                read::guardian(),
                size.x,
                size.y,
                open,
            ))),
        ))
    })?;
    let (cleared, found) = found;
    lines.extend(cleared);
    let Some(found) = found else {
        return Ok(json!({"acted": !lines.is_empty(), "lines": lines}));
    };
    let Some((seen, foe, w, h, anvil)) = found else {
        lines.push("mega forge: took the forged piece and left".into());
        return Ok(json!({"acted": true, "lines": lines}));
    };
    let foe = match foe {
        Ok(f) => f,
        Err(e) => {
            lines.push(format!(
                "mega forge: no foe to judge against ({e}); left it to you"
            ));
            return Ok(json!({"acted": false, "lines": lines}));
        }
    };
    let judge = arrange::Judge::new(&seen.hero, vec![foe.clone()]);
    let mut list: Vec<read::Owned> = seen.list.iter().filter(|o| o.wearable()).cloned().collect();
    judge.value_all(&mut list, &seen.board);
    // Every set of 2 to 4 pieces the anvil takes that lays out, biggest
    // piece first.
    let forgeable: Vec<usize> = (0..list.len()).filter(|&i| !list[i].consumable).collect();
    let cells = |i: usize| list[i].piece.shapes[0].len();
    let room = anvil.iter().filter(|&&o| o).count();
    let mut sets: Vec<(Vec<usize>, Vec<(i32, i32, i32)>)> = Vec::new();
    let n = forgeable.len().min(24);
    for mask in 1u32..(1 << n) {
        if !(2..=4).contains(&mask.count_ones()) {
            continue;
        }
        let mut set: Vec<usize> = (0..n)
            .filter(|b| mask & (1 << b) != 0)
            .map(|b| forgeable[b])
            .collect();
        if set.iter().map(|&i| cells(i)).sum::<usize>() > room {
            continue;
        }
        set.sort_by_key(|&i| std::cmp::Reverse(cells(i)));
        let pieces: Vec<&Piece> = set.iter().map(|&i| &list[i].piece).collect();
        if let Some(spots) = layout(&pieces, w, h, &anvil) {
            sets.push((set, spots));
        }
    }
    let laid = sets.len();
    // The game's recipe (item_forge.gd mega_spec) gives the made piece
    // the shape of the biggest part and the parts' stats added up. So a
    // set is ranked first by its parts' values in the biggest part's
    // cells (the operator's "max value per inventory/eq slot"), and
    // only the best are previewed by the game (operator 2026-11-17:
    // "this shouldnt take so long").
    let per_cell = |set: &[usize]| {
        let value: f64 = set.iter().map(|&i| list[i].piece.value).sum();
        let biggest = set.iter().map(|&i| cells(i)).max().unwrap_or(1).max(1);
        value / biggest as f64
    };
    arrange::best_first(&mut sets, |s| per_cell(&s.0));
    lines.push(format!(
        "mega forge: {laid} sets of 2 to 4 pieces lay out on the {w}x{h} anvil; the {} with the most value per cell of the made piece go to the game's preview",
        sets.len()
    ));
    // The game's preview of each, in short main-thread passes so the
    // game keeps running between them (operator 2026-11-17: "game ia
    // almost bfrozen").
    let asks: Vec<(Vec<i64>, Vec<(i32, i32, i32)>)> = sets
        .iter()
        .map(|(set, spots)| (set.iter().map(|&i| list[i].id).collect(), spots.clone()))
        .collect();
    let previewed_at = Instant::now();
    let (made, passes) = on_main_passes("mega preview", asks.len(), move |from, deadline| {
        let mut global = read::node("/root/Global")?;
        let mut inv = read::inventory()?;
        let mut out: Vec<Result<Made, String>> = Vec::new();
        for (ids, spots) in &asks[from..] {
            let (rows, refused) = put_on(&mut inv, ids, spots)?;
            let got = match refused {
                Some(r) => Err(r),
                None => preview(&mut global, &mut inv)?,
            };
            if !take_off(&mut inv, &rows)? {
                read::call(&mut global, "return_forge_pieces", &[])?;
                return Err(
                    "a piece would not go back to its spot; the game returned the anvil's pieces"
                        .into(),
                );
            }
            out.push(got);
            if Instant::now() >= deadline {
                break;
            }
        }
        Ok(out)
    })?;
    lines.push(format!(
        "mega forge: previewed by the game in {:.2}s over {passes} passes",
        previewed_at.elapsed().as_secs_f64()
    ));
    // Judge: the packer's best equipment value with the made piece in
    // place of its parts.
    let mut g = seen.grid();
    let owned: Vec<Piece> = list.iter().map(|o| o.piece.clone()).collect();
    let mut kept: Vec<(usize, Made)> = Vec::new();
    for (k, got) in made.into_iter().enumerate() {
        let Ok(mut m) = got else { continue };
        if m.refusal.starts_with("This class") || m.refusal.starts_with("Requires Level") {
            continue;
        }
        judge.price(&mut m.piece, &m.alone, m.score, &seen.board);
        kept.push((k, m));
    }
    let swaps: Vec<arrange::Swap> = kept
        .iter()
        .map(|(k, m)| arrange::Swap {
            remove: sets[*k].0.clone(),
            add: m.piece.clone(),
        })
        .collect();
    g.sets = judge.set_table(owned.iter().chain(swaps.iter().map(|s| &s.add)));
    let (without, top) = arrange::rank(&g, seen.hands, &owned, &swaps, arrange::FINALISTS);
    let scored: Vec<(f64, usize, Made)> = top
        .into_iter()
        .map(|(v, s)| (v, kept[s].0, kept[s].1.clone()))
        .collect();
    lines.push(format!(
        "mega forge: judged against {} (hp {} atk {}); best equipment without forging: value {without:.4}. Best sets:",
        foe.name, foe.max_hp, foe.atk
    ));
    let names = |k: usize| {
        sets[k]
            .0
            .iter()
            .map(|&i| list[i].name.clone())
            .collect::<Vec<_>>()
            .join(" + ")
    };
    for (v, k, m) in &scored {
        lines.push(format!(
            "  {} -> {} ({} cells, value {:.4}): equipment value {v:.4}  [{}]",
            names(*k),
            m.name,
            m.piece.shapes[0].len(),
            m.piece.value,
            stats_text(&m.stats)
        ));
    }
    let best = scored
        .first()
        .filter(|(v, _, _)| *v > without + 1e-9)
        .cloned();
    let Some((v, k, m)) = best else {
        on_main("mega leave", || match stop()? {
            Some(mut s) => leave(&mut s),
            None => Ok(()),
        })?;
        lines.push(
            "mega forge: no set beats packing without forging; left with nothing forged".into(),
        );
        return Ok(json!({"acted": true, "lines": lines}));
    };
    // Forge: the set back on the anvil, the game's preview again, then
    // FORGE and CONTINUE.
    let ids: Vec<i64> = sets[k].0.iter().map(|&i| list[i].id).collect();
    let spots = sets[k].1.clone();
    let want = (m.name.clone(), m.stats.clone());
    let done = on_main("mega forge", move || {
        let mut global = read::node("/root/Global")?;
        let mut inv = read::inventory()?;
        let Some(mut s) = stop()? else {
            return Ok("the stop is gone".to_string());
        };
        let (rows, refused) = put_on(&mut inv, &ids, &spots)?;
        let now = match refused {
            Some(r) => Err(r),
            None => preview(&mut global, &mut inv)?,
        };
        match now {
            Ok(n) if (n.name.clone(), n.stats.clone()) == want => {}
            Ok(n) => {
                take_off(&mut inv, &rows)?;
                read::call(&mut global, "return_forge_pieces", &[])?;
                return Ok(format!(
                    "the preview changed to {} [{}]; nothing forged",
                    n.name,
                    stats_text(&n.stats)
                ));
            }
            Err(e) => {
                let back = take_off(&mut inv, &rows)?;
                let stuck = on_anvil(&mut inv)?;
                read::call(&mut global, "return_forge_pieces", &[])?;
                return Ok(format!(
                    "the anvil would not forge it ({e}); nothing forged; {}; on the anvil before the game cleared it: {}",
                    if back {
                        "the set's pieces went back to their spots"
                    } else {
                        "a set piece would not go back to its spot"
                    },
                    if stuck.is_empty() {
                        "nothing".to_string()
                    } else {
                        format!("{} (now in the bag)", stuck.join(", "))
                    }
                ));
            }
        }
        read::call(&mut s, "_forge", &[])?;
        let held = s.get("_held");
        let made = held
            .try_to::<Gd<Object>>()
            .map(|i| i.get("display_name").to_string())
            .unwrap_or_default();
        leave(&mut s)?;
        Ok(if made.is_empty() {
            "the game did not forge it".to_string()
        } else {
            format!("forged {made}; it is in the bag")
        })
    })?;
    lines.push(format!(
        "mega forge: forging {} -> {} (equipment value {v:.4} against {without:.4}): {done}; {:.2}s in all",
        names(k),
        m.name,
        at.elapsed().as_secs_f64()
    ));
    Ok(json!({"acted": true, "lines": lines}))
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A piece that does not turn (every turn the same cells).
    fn piece(cells: &[(i32, i32)], holes: &[(i32, i32)]) -> Piece {
        Piece {
            value: 0.0,
            shapes: std::array::from_fn(|_| cells.to_vec()),
            holes: std::array::from_fn(|_| holes.to_vec()),
            family: String::new(),
            weapon: false,
            place: Default::default(),
        }
    }

    fn cells_at(p: &Piece, (x, y, r): (i32, i32, i32)) -> Vec<(i32, i32)> {
        p.shapes[r as usize]
            .iter()
            .map(|&(a, b)| (x + a, y + b))
            .collect()
    }

    #[test]
    fn pieces_touch_and_do_not_overlap() {
        let big = piece(&[(0, 0), (1, 0), (2, 0), (0, 1), (1, 1), (2, 1)], &[]);
        let small = piece(&[(0, 0), (1, 0)], &[]);
        let set = [&big, &small, &small];
        let spots = layout(&set, 6, 5, &[true; 30]).expect("lays out");
        let all: Vec<Vec<(i32, i32)>> = set
            .iter()
            .zip(&spots)
            .map(|(p, &s)| cells_at(p, s))
            .collect();
        for (i, a) in all.iter().enumerate() {
            for b in &all[i + 1..] {
                assert!(a.iter().all(|c| !b.contains(c)), "overlap: {spots:?}");
            }
            if i > 0 {
                let before: Vec<(i32, i32)> = all[..i].concat();
                assert!(
                    a.iter()
                        .any(|&(x, y)| [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
                            .iter()
                            .any(|n| before.contains(n))),
                    "piece {i} does not touch: {spots:?}"
                );
            }
        }
    }

    #[test]
    fn too_big_or_closed_does_not_lay_out() {
        let row = piece(
            &[(0, 0), (1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0)],
            &[],
        );
        assert!(layout(&[&row], 6, 5, &[true; 30]).is_none());
        let one = piece(&[(0, 0)], &[]);
        let mut open = [false; 30];
        open[7] = true;
        assert_eq!(layout(&[&one], 6, 5, &open), Some(vec![(1, 1, 0)]));
        assert!(layout(&[&one, &one], 6, 5, &open).is_none());
    }

    #[test]
    fn holes_stay_free() {
        // A ring whose middle is a hole: nothing may sit in it.
        let ring = piece(
            &[
                (0, 0),
                (1, 0),
                (2, 0),
                (0, 1),
                (2, 1),
                (0, 2),
                (1, 2),
                (2, 2),
            ],
            &[(1, 1)],
        );
        let one = piece(&[(0, 0)], &[]);
        let spots = layout(&[&ring, &one], 3, 3, &[true; 9]);
        assert!(spots.is_none(), "the hole was used: {spots:?}");
    }
}
