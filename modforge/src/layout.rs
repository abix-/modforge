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
use crate::plan::{PlanDef, PlanExit, PlanFurniture, PlanRoom, PlanStair, PlanThing, PlanWay};
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
    /// Whether the stairs up are in it: a flight up its west wall, front to
    /// back, to the stairwell over it, which opens on the rooms upstairs
    /// through its back.
    #[serde(default)]
    pub stair: bool,
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
    /// Who lives in a place of this brief: each person in it rolled from
    /// these kinds by weight (the game's actor kinds), and how many, fewest
    /// and most. The town's own residents when left out.
    #[serde(default)]
    pub people: Vec<(String, u64)>,
    #[serde(default)]
    pub living: Option<(u32, u32)>,
}

impl Brief {
    /// The `k`th person living in a place of this brief, rolled from
    /// `seed` among `people` by weight; none when it names none.
    pub fn person(&self, seed: u64, k: u64) -> Option<&str> {
        let total: u64 = self.people.iter().map(|(_, w)| w).sum();
        if total == 0 {
            return None;
        }
        let mut n = crate::roll::salted_index(seed, 0x1A_7E00 + k, total);
        self.people.iter().find(|(_, w)| {
            if n < *w {
                return true;
            }
            n -= w;
            false
        }).map(|(who, _)| who.as_str())
    }
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
    /// Whether it is on the second storey ("a tier 3 house, so that means
    /// it would be 2 stories"), over the ground floor's rooms, reached by
    /// the stairs; left out when the ground floor has no stairs.
    #[serde(default)]
    pub upstairs: bool,
}

/// Where `room` joins the rooms down (each cell's door spots in `doors`):
/// the room down, the side, and the piece; a piece goes only on a free
/// cell not out front, through a side both have a door spot on, where
/// `fits`. Up to a few tries of its pieces.
fn grow<'a>(
    pieces: &'a [RoomPiece],
    room: &str,
    roll: &mut Roll,
    doors: &BTreeMap<(i32, i32), Vec<Side>>,
    fits: &dyn Fn((i32, i32), &RoomPiece) -> bool,
) -> Option<((i32, i32), Side, &'a RoomPiece)> {
    for _ in 0..4 {
        let piece = pick(pieces, room, roll)?;
        let spots: Vec<((i32, i32), Side)> = doors
            .iter()
            .flat_map(|(&at, sides)| sides.iter().map(move |&s| (at, s)))
            .filter(|&(at, s)| {
                let to = next(at, s);
                to.1 >= 0 && !doors.contains_key(&to) && piece.doors.contains(&back(s)) && fits(to, piece)
            })
            .collect();
        if spots.is_empty() {
            continue;
        }
        let &(at, side) = roll.pick(&spots);
        return Some((at, side, piece));
    }
    None
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
    let mut wanted: Vec<(String, bool)> = Vec::new();
    for BriefRoom { room, count: (lo, hi), upstairs } in &brief.rooms {
        for _ in 0..roll.between(*lo, *hi) {
            wanted.push((room.clone(), *upstairs));
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
    let Some((front, false)) = wanted.first().cloned() else {
        return empty(brief);
    };
    let entry = pieces.iter().filter(|p| p.room == front && p.doors.contains(&Side::South)).collect::<Vec<_>>();
    let Some(&first) = (if entry.is_empty() { None } else { Some(roll.pick(&entry)) }) else {
        return empty(brief);
    };
    down.insert((0, 0), (name_of(&front), first));
    for (room, _) in wanted.iter().skip(1).filter(|(_, up)| !up) {
        let doors = down.iter().map(|(&c, (_, p))| (c, p.doors.clone())).collect();
        let fits = |to: (i32, i32), piece: &RoomPiece| {
            brief.lot.is_none_or(|lot| {
                let size = extent(down.iter().map(|(&c, (_, p))| (c, *p)).chain([(to, piece)]));
                size[0] <= lot[0] && size[1] <= lot[1]
            })
        };
        if let Some((at, side, piece)) = grow(pieces, room, &mut roll, &doors, &fits) {
            down.insert(next(at, side), (name_of(room), piece));
            ways.push((at, side));
        }
    }
    // The second storey: the stairwell over the stairs, the rooms upstairs
    // joined from it through its back and from each other, each over a
    // room of the ground floor.
    let mut up: BTreeMap<(i32, i32), (String, Option<&RoomPiece>)> = BTreeMap::new();
    let mut up_ways: Vec<((i32, i32), Side)> = Vec::new();
    let stair = down.iter().find(|(_, (_, p))| p.stair).map(|(&c, _)| c);
    if let Some(stair) = stair {
        let upper: Vec<&String> = wanted.iter().filter(|(_, up)| *up).map(|(room, _)| room).collect();
        if !upper.is_empty() {
            up.insert(stair, ("stairwell".to_string(), None));
        }
        for room in upper {
            let doors = up.iter().map(|(&c, (_, p))| (c, p.map_or(vec![Side::North], |p| p.doors.clone()))).collect();
            let fits = |to: (i32, i32), _: &RoomPiece| down.contains_key(&to);
            if let Some((at, side, piece)) = grow(pieces, room, &mut roll, &doors, &fits) {
                up.insert(next(at, side), (name_of(room), Some(piece)));
                up_ways.push((at, side));
            }
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
    let way = |&(at, side): &((i32, i32), Side), level: u32| match side {
        Side::East | Side::North => PlanWay { from: cell(at), side, door: true, level },
        Side::West | Side::South => PlanWay { from: cell(next(at, side)), side: back(side), door: true, level },
    };
    let plan_ways = ways.iter().map(|w| way(w, 0)).chain(up_ways.iter().map(|w| way(w, 1))).collect();
    let mut plan_rooms = Vec::new();
    let mut furniture = Vec::new();
    let mut things = Vec::new();
    for (&at, (name, p)) in &down {
        plan_rooms.push(PlanRoom { at: cell(at), name: name.clone(), level: 0 });
        furniture.extend(p.furniture.iter().map(|f| PlanFurniture { room: name.clone(), at: f.at, size: f.size, model: f.model.clone() }));
        things.extend(p.things.iter().map(|t| PlanThing { thing: t.thing.clone(), room: name.clone(), at: t.at }));
    }
    // Upstairs, the furniture; the things used stand on the ground, so
    // those upstairs are left out until a thing carries its height.
    for (&at, (name, p)) in &up {
        plan_rooms.push(PlanRoom { at: cell(at), name: name.clone(), level: 1 });
        for f in p.iter().flat_map(|p| &p.furniture) {
            furniture.push(PlanFurniture { room: name.clone(), at: f.at, size: f.size, model: f.model.clone() });
        }
    }
    let stairs = stair.filter(|_| !up.is_empty()).map(|s| PlanStair { from: cell(s), level: 0 }).into_iter().collect();
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
        stairs,
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
        rooms: vec![PlanRoom { at: (0, 0), name: "room".to_string(), level: 0 }],
        ways: Vec::new(),
        exits: vec![PlanExit { from: (0, 0), side: Side::South, width: brief.entry }],
        furniture: Vec::new(),
        things: Vec::new(),
        outside: Vec::new(),
        stairs: Vec::new(),
        walls: brief.walls.clone(),
        floor: brief.floor,
        furniture_color: brief.furniture_color,
        height: brief.height,
    }
}
