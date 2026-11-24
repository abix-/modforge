//! A place laid out from room pieces (topside todo "Places rolled", the
//! way the operator agreed 2026-11-23, Diablo 2's: "each house gets X
//! number of pieces, and then you're able to connect the pieces
//! together"). A room piece is one room as data: what room it is, its
//! size, the sides it has a door spot on, its furniture and the things
//! used in it. A room has many pieces, its versions, and a rare one is a
//! set piece, the surprise. A brief says which rooms a place has and how
//! many of each; `roll` picks a piece for each room and joins them on a
//! grid from the front room, each joined to one already down through a
//! side both have a door spot on, so the doors line up (Diablo 2's
//! dungeon tiles join where their exits match). What it makes is a
//! `plan::PlanDef`, built by the one `plan::build`. Who is inside is
//! rolled on top of it, elsewhere.

use std::collections::BTreeMap;

use serde::Deserialize;

use crate::monument::Roll;
use crate::plan::{PlanDef, PlanExit, PlanFurniture, PlanRoom, PlanThing, PlanWay};
use crate::structure::{Rgb, Side};

/// One room piece, a version of its room.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct RoomPiece {
    /// The room it is a version of ("kitchen", "bedroom").
    pub room: String,
    /// Its interior, metres: across (west to east) and along (front to
    /// back).
    pub size: [f32; 2],
    /// The sides a door can be on.
    pub doors: Vec<Side>,
    /// How likely it is picked against its room's other pieces; a set
    /// piece's is low.
    #[serde(default = "common")]
    pub weight: u64,
    /// Its furniture: where each sits as a share of the room (-0.5 to 0.5
    /// across and along), its size, and the model it is drawn as.
    #[serde(default)]
    pub furniture: Vec<PieceFurniture>,
    /// The things used in it, each where it stands as a share of the room.
    #[serde(default)]
    pub things: Vec<PieceThing>,
}

fn common() -> u64 {
    1000
}

/// A piece's piece of furniture.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PieceFurniture {
    pub at: [f32; 2],
    pub size: [f32; 3],
    #[serde(default)]
    pub model: Option<String>,
}

/// A thing used in a piece.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PieceThing {
    pub thing: String,
    pub at: [f32; 2],
}

/// What a place of one tier has (topside-town "Every place different":
/// "tier 3 means we're going to have 4 bedrooms and 2 baths and so on...
/// And then based off of that, it generates a random layout off of it").
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Brief {
    /// The kind of place ("house") and its tier.
    pub place: String,
    pub tier: u32,
    /// Its rooms and how many of each, fewest and most; the first is the
    /// front room, with the way in from the street.
    pub rooms: Vec<BriefRoom>,
    /// The way in's width.
    pub entry: f32,
    pub walls: Vec<Rgb>,
    pub floor: Rgb,
    #[serde(rename = "furniture colour")]
    pub furniture_color: Rgb,
    pub height: f32,
    /// The most the place may cover, metres across and along, so it stays
    /// on its lot; a room that would go past it is left out. No limit when
    /// left out.
    #[serde(default)]
    pub lot: Option<[f32; 2]>,
}

/// The grid's size, metres across and along, of the rooms `down` (each
/// column as wide as its widest piece, each row as long as its longest).
fn extent<'a>(down: impl Iterator<Item = ((i32, i32), &'a RoomPiece)>) -> [f32; 2] {
    let mut columns: BTreeMap<i32, f32> = BTreeMap::new();
    let mut rows: BTreeMap<i32, f32> = BTreeMap::new();
    for ((c, r), p) in down {
        let w = columns.entry(c).or_insert(0.0);
        *w = w.max(p.size[0]);
        let l = rows.entry(r).or_insert(0.0);
        *l = l.max(p.size[1]);
    }
    [columns.values().sum(), rows.values().sum()]
}

/// A room a brief asks for.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct BriefRoom {
    pub room: String,
    pub count: (u32, u32),
}

/// The side across from `side`.
fn back(side: Side) -> Side {
    match side {
        Side::North => Side::South,
        Side::South => Side::North,
        Side::East => Side::West,
        Side::West => Side::East,
    }
}

/// The grid cell next to `at` through `side`; north is back from the
/// front.
fn next(at: (i32, i32), side: Side) -> (i32, i32) {
    match side {
        Side::North => (at.0, at.1 + 1),
        Side::South => (at.0, at.1 - 1),
        Side::East => (at.0 + 1, at.1),
        Side::West => (at.0 - 1, at.1),
    }
}

/// One of `room`'s pieces, picked by weight; none when it has none.
fn pick<'a>(pieces: &'a [RoomPiece], room: &str, roll: &mut Roll) -> Option<&'a RoomPiece> {
    let versions: Vec<&RoomPiece> = pieces.iter().filter(|p| p.room == room).collect();
    let total: u64 = versions.iter().map(|p| p.weight).sum();
    if total == 0 {
        return None;
    }
    let mut n = roll.next(total);
    versions.into_iter().find(|p| {
        if n < p.weight {
            return true;
        }
        n -= p.weight;
        false
    })
}

/// The place `brief` asks for, laid out from `pieces` by `seed`: the same
/// every time for a seed, another for another. A room none of whose
/// pieces fits beside the rooms already down is left out.
pub fn roll(brief: &Brief, pieces: &[RoomPiece], seed: u64) -> PlanDef {
    let mut roll = Roll::new(seed);
    // The rooms wanted, the front room first, the rest in rolled order.
    let mut wanted: Vec<String> = Vec::new();
    for BriefRoom { room, count: (lo, hi) } in &brief.rooms {
        for _ in 0..roll.between(*lo, *hi) {
            wanted.push(room.clone());
        }
    }
    if wanted.len() > 2 {
        for i in (2..wanted.len()).rev() {
            let j = 1 + roll.next(i as u64) as usize;
            wanted.swap(i, j);
        }
    }
    // Each room down: its cell, its name (numbered when there are more
    // of one), its piece. The front room has the way in on its south.
    let mut down: BTreeMap<(i32, i32), (String, &RoomPiece)> = BTreeMap::new();
    let mut ways: Vec<((i32, i32), Side)> = Vec::new();
    let mut named: BTreeMap<String, u32> = BTreeMap::new();
    let mut name_of = |room: &str| {
        let n = named.entry(room.to_string()).or_insert(0);
        *n += 1;
        if *n == 1 { room.to_string() } else { format!("{room} {n}") }
    };
    let mut rooms = wanted.iter();
    let Some(front) = rooms.next() else {
        return empty(brief);
    };
    let entry = pieces.iter().filter(|p| p.room == *front && p.doors.contains(&Side::South)).collect::<Vec<_>>();
    let Some(&first) = (if entry.is_empty() { None } else { Some(roll.pick(&entry)) }) else {
        return empty(brief);
    };
    down.insert((0, 0), (name_of(front), first));
    for room in rooms {
        // Up to a few tries of its pieces; each try, every open door spot
        // of a room down whose cell is free and not out front, matched to
        // a door spot of the piece.
        for _ in 0..4 {
            let Some(piece) = pick(pieces, room, &mut roll) else { break };
            let spots: Vec<((i32, i32), Side)> = down
                .iter()
                .flat_map(|(&at, (_, p))| p.doors.iter().map(move |&s| (at, s)))
                .filter(|&(at, s)| {
                    let to = next(at, s);
                    to.1 >= 0 && !down.contains_key(&to) && piece.doors.contains(&back(s))
                })
                .filter(|&(at, s)| {
                    brief.lot.is_none_or(|lot| {
                        let size = extent(down.iter().map(|(&c, (_, p))| (c, *p)).chain([(next(at, s), piece)]));
                        size[0] <= lot[0] && size[1] <= lot[1]
                    })
                })
                .collect();
            if spots.is_empty() {
                continue;
            }
            let &(at, side) = roll.pick(&spots);
            down.insert(next(at, side), (name_of(room), piece));
            ways.push((at, side));
            break;
        }
    }
    // The grid: each column as wide as its widest piece, each row as long
    // as its longest; columns counted from the westmost.
    let west = down.keys().map(|c| c.0).min().unwrap_or(0);
    let east = down.keys().map(|c| c.0).max().unwrap_or(0);
    let north = down.keys().map(|c| c.1).max().unwrap_or(0);
    let mut columns = vec![0.0f32; (east - west + 1) as usize];
    let mut rows = vec![0.0f32; (north + 1) as usize];
    for (&(c, r), (_, p)) in &down {
        let (c, r) = ((c - west) as usize, r as usize);
        columns[c] = columns[c].max(p.size[0]);
        rows[r] = rows[r].max(p.size[1]);
    }
    // An empty cell's column or row keeps the size of the next one, so
    // nothing is built zero wide.
    for size in columns.iter_mut().chain(rows.iter_mut()) {
        if *size <= 0.0 {
            *size = 3.0;
        }
    }
    let cell = |(c, r): (i32, i32)| ((c - west) as usize, r as usize);
    // A way joins two rooms from the west or front one, east or north,
    // a door hung in it.
    let plan_ways = ways
        .iter()
        .map(|&(at, side)| match side {
            Side::East | Side::North => PlanWay { from: cell(at), side, door: true },
            Side::West | Side::South => PlanWay { from: cell(next(at, side)), side: back(side), door: true },
        })
        .collect();
    let mut plan_rooms = Vec::new();
    let mut furniture = Vec::new();
    let mut things = Vec::new();
    for (&at, (name, p)) in &down {
        plan_rooms.push(PlanRoom { at: cell(at), name: name.clone() });
        furniture.extend(p.furniture.iter().map(|f| PlanFurniture { room: name.clone(), at: f.at, size: f.size, model: f.model.clone() }));
        things.extend(p.things.iter().map(|t| PlanThing { thing: t.thing.clone(), room: name.clone(), at: t.at }));
    }
    PlanDef {
        name: brief.place.clone(),
        about: String::new(),
        edge: false,
        columns,
        rows,
        rooms: plan_rooms,
        ways: plan_ways,
        exits: vec![PlanExit { from: cell((0, 0)), side: Side::South, width: brief.entry }],
        furniture,
        things,
        outside: Vec::new(),
        walls: brief.walls.clone(),
        floor: brief.floor,
        furniture_color: brief.furniture_color,
        height: brief.height,
    }
}

/// A place with no pieces for its front room: one bare room with the way
/// in, so a missing piece shows as an empty room, never a missing
/// building.
fn empty(brief: &Brief) -> PlanDef {
    PlanDef {
        name: brief.place.clone(),
        about: String::new(),
        edge: false,
        columns: vec![4.0],
        rows: vec![4.0],
        rooms: vec![PlanRoom { at: (0, 0), name: "room".to_string() }],
        ways: Vec::new(),
        exits: vec![PlanExit { from: (0, 0), side: Side::South, width: brief.entry }],
        furniture: Vec::new(),
        things: Vec::new(),
        outside: Vec::new(),
        walls: brief.walls.clone(),
        floor: brief.floor,
        furniture_color: brief.furniture_color,
        height: brief.height,
    }
}
