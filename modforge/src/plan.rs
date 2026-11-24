//! A town place's floor plan (topside-town "What the town has": "a real
//! building with every room it has, everything in it working"): the
//! house's way of building (house.rs: named rooms on a grid of columns
//! and rows, the ways between them, the ways out, windows on the front,
//! each room's furniture and a light), as data, so every place the town
//! has (the grocery store, the diner, the clinic) is one `PlanDef` built
//! by the one `build`. What a place holds that is used (its shelves, its
//! cash register, its stove) are its `things`, put in the world by the
//! game where `things_of` says.

use glam::{Vec2, Vec3};
use serde::Deserialize;

use crate::house::quarters_for;
use crate::monument::{Roll, WALL, door, spaced, window};
use crate::structure::{LightDef, Opening, Rgb, RoomDef, SLAB, Side, SolidDef, StairDef, StructureDef, turned, validate};

/// One place's plan, a blueprint read from the game's content (topside's
/// content/places.yaml). Columns run west to east, rows front to back
/// (the front +z, toward its street).
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanDef {
    /// Its name; the content's key for it, filled in by the reader.
    #[serde(default)]
    pub name: String,
    /// What it is, for whoever reads the content.
    #[serde(default)]
    pub about: String,
    /// Whether it stands at the edge of town (else on main street).
    #[serde(default)]
    pub edge: bool,
    /// The rooms' interior sizes, metres.
    pub columns: Vec<f32>,
    pub rows: Vec<f32>,
    pub rooms: Vec<PlanRoom>,
    #[serde(default)]
    pub ways: Vec<PlanWay>,
    #[serde(default)]
    pub exits: Vec<PlanExit>,
    #[serde(default)]
    pub furniture: Vec<PlanFurniture>,
    #[serde(default)]
    pub things: Vec<PlanThing>,
    #[serde(default)]
    pub outside: Vec<PlanOutside>,
    /// The stairs, each from a room up to the room over it (topside-town
    /// "Every place different": "a tier 3 house, so that means it would
    /// be 2 stories").
    #[serde(default)]
    pub stairs: Vec<PlanStair>,
    pub walls: Vec<Rgb>,
    pub floor: Rgb,
    #[serde(rename = "furniture colour")]
    pub furniture_color: Rgb,
    pub height: f32,
}

/// A room by (column, row), named.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanRoom {
    pub at: (usize, usize),
    pub name: String,
    /// Its storey, 0 the ground floor.
    #[serde(default)]
    pub level: u32,
}

/// A straight flight up the west wall of the room at `from` on `level`,
/// front to back, to the room over it: the stairwell, left with no floor.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanStair {
    pub from: (usize, usize),
    #[serde(default)]
    pub level: u32,
}

/// A stair's width, metres (Claude's).
pub const PLAN_STAIR_WIDTH: f32 = 1.0;

/// A way between rooms: from a room east or north, with a door hung or
/// an open way.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanWay {
    pub from: (usize, usize),
    pub side: Side,
    #[serde(default)]
    pub door: bool,
    /// The storey it is on.
    #[serde(default)]
    pub level: u32,
    /// A hidden way: its door reads as wall and opens from a hidden
    /// switch (topside todo Secrets 1).
    #[serde(default)]
    pub hidden: bool,
}

/// Where each hidden way's door stands, on the ground, the plan turned to
/// face `front` (topside todo Secrets 1): the middle of the wall the way
/// is in.
pub fn hidden_doors(def: &PlanDef, front: Vec2) -> Vec<Vec2> {
    def.ways
        .iter()
        .filter(|w| w.hidden)
        .filter_map(|w| {
            let (c, r) = w.from;
            let other = match w.side {
                Side::East => (c + 1, r),
                Side::North => (c, r + 1),
                _ => return None,
            };
            if other.0 >= def.columns.len() || other.1 >= def.rows.len() {
                return None;
            }
            let (here, there) = (room_at(def, c, r), room_at(def, other.0, other.1));
            let wall = match w.side {
                Side::East => Vec3::new(here.x + (there.x - here.x).signum() * def.columns[c] / 2.0, 0.0, here.z),
                _ => Vec3::new(here.x, 0.0, here.z + (there.z - here.z).signum() * def.rows[r] / 2.0),
            };
            Some(turn(wall, front))
        })
        .collect()
}

/// A way out: a room, its outside wall, and the way's width.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanExit {
    pub from: (usize, usize),
    pub side: Side,
    pub width: f32,
}

/// A piece of furniture in the first room of its name: where it sits as
/// a share of the room (-0.5 to 0.5 across and along), its size, and the
/// model it is drawn as (`SolidDef::model`), none a block.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanFurniture {
    pub room: String,
    pub at: [f32; 2],
    pub size: [f32; 3],
    #[serde(default)]
    pub model: Option<String>,
}

/// A thing used in the place: its name and where it stands as a share of
/// the first room of that name.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanThing {
    pub thing: String,
    pub room: String,
    pub at: [f32; 2],
}

/// A thing standing outside the place (a farm's fields, a gas station's
/// pumps): its name and where, metres from the plan's middle, +z its
/// front.
#[derive(Clone, Debug, PartialEq, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PlanOutside {
    pub thing: String,
    pub at: [f32; 2],
}

/// Where a room's middle is on the ground floor, from the plan's middle,
/// unturned.
fn room_at(def: &PlanDef, c: usize, r: usize) -> Vec3 {
    let xs = spaced(&def.columns, 1.0);
    let zs = spaced(&def.rows, -1.0);
    let mid = Vec3::new((xs[0] + xs[xs.len() - 1]) / 2.0, 0.0, (zs[0] + zs[zs.len() - 1]) / 2.0).round();
    Vec3::new(xs[c], 0.0, zs[r]) - mid
}

/// How high a storey's floor is.
fn level_height(def: &PlanDef, level: u32) -> f32 {
    level as f32 * def.height
}

/// A point of the unturned plan, turned to face `front`, on the ground.
fn turn(p: Vec3, front: Vec2) -> Vec2 {
    (0..quarters_for(front)).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// The place `def` builds, facing `front`, varied by `seed` (its wall
/// colour and its windows).
pub fn build(def: &PlanDef, front: Vec2, seed: u64) -> StructureDef {
    let mut roll = Roll::new(seed);
    let wall_color = *roll.pick(&def.walls);
    let (last_col, last_row) = (def.columns.len() - 1, def.rows.len() - 1);
    let mut rooms = Vec::new();
    let mut furniture = Vec::new();
    let mut lights = Vec::new();
    let mut stairs = Vec::new();
    for PlanRoom { at: (c, r), name, level } in &def.rooms {
        let (c, r, level) = (*c, *r, *level);
        let (w, l) = (def.columns[c], def.rows[r]);
        let origin = room_at(def, c, r) + Vec3::Y * level_height(def, level);
        // A room with one over it has that room's floor for its ceiling;
        // a room a stair comes up into is open over the flight.
        let covered = def.rooms.iter().any(|o| o.at == (c, r) && o.level == level + 1);
        let stair_below = level > 0 && def.stairs.iter().any(|s| s.from == (c, r) && s.level + 1 == level);
        if def.stairs.iter().any(|s| s.from == (c, r) && s.level == level) {
            stairs.push(StairDef {
                base: origin + Vec3::new(-w / 2.0 + PLAN_STAIR_WIDTH / 2.0 + 0.1, SLAB, l / 2.0 - 0.1),
                side: Side::North,
                width: PLAN_STAIR_WIDTH,
                rise: def.height,
                landing: 0.6,
            });
            // The landing upstairs, the stairwell's back across its width,
            // where its way to the rooms upstairs is.
            furniture.push(SolidDef {
                center: origin + Vec3::new(0.0, def.height + SLAB / 2.0, -l / 2.0 + 0.5),
                size: Vec3::new(w, SLAB, 1.0),
                color: def.floor,
                model: None,
            });
        }
        let mut openings: Vec<Opening> = Vec::new();
        for &PlanWay { from: (wc, wr), side, door: hung, level: on, .. } in &def.ways {
            if on != level {
                continue;
            }
            let other = match side {
                Side::East => (wc + 1, wr),
                Side::North => (wc, wr + 1),
                _ => continue,
            };
            if (wc, wr) == (c, r) {
                openings.push(Opening { door: hung, ..door(side, 0.0) });
            } else if other == (c, r) {
                let back = if side == Side::East { Side::West } else { Side::South };
                openings.push(Opening { door: false, ..door(back, 0.0) });
            }
        }
        for &PlanExit { from, side, width } in &def.exits {
            if from == (c, r) && level == 0 {
                openings.push(Opening { width, ..door(side, 0.0) });
            }
        }
        // Windows on the front's outside walls a door is not on, and by
        // chance on the sides.
        let outside = [(Side::South, r == 0), (Side::West, c == 0), (Side::East, c == last_col), (Side::North, r == last_row)];
        for (side, out) in outside {
            if !out || openings.iter().any(|o| o.side == side) {
                continue;
            }
            let run = if matches!(side, Side::North | Side::South) { w } else { l };
            if side == Side::South || (side != Side::North && roll.chance(500)) {
                let s = (run / 2.0 - 1.0).max(0.0);
                openings.push(window(side, roll.measure(-s, s)));
            }
        }
        rooms.push(RoomDef {
            origin,
            interior: Vec3::new(w, def.height, l),
            wall_thickness: WALL,
            openings,
            floor: !stair_below,
            ceiling: !covered,
        });
        for f in def.furniture.iter().filter(|f| &f.room == name) {
            let ([fx, fz], [sx, sy, sz]) = (f.at, f.size);
            let size = Vec3::new(sx.min(w - 0.4), sy, sz.min(l - 0.4));
            let dx = (fx * w).clamp(-(w / 2.0 - size.x / 2.0 - 0.1), w / 2.0 - size.x / 2.0 - 0.1);
            let dz = (fz * l).clamp(-(l / 2.0 - size.z / 2.0 - 0.1), l / 2.0 - size.z / 2.0 - 0.1);
            let model = f.model.clone().filter(|m| !m.is_empty());
            furniture.push(SolidDef { center: origin + Vec3::new(dx, size.y / 2.0, dz), size, color: def.furniture_color, model });
        }
        lights.push(LightDef { position: origin + Vec3::new(0.0, def.height - 0.4, 0.0), color: [1.0, 0.95, 0.85], intensity: 400_000.0 });
    }
    let plan = StructureDef {
        name: def.name.clone(),
        wall_color,
        floor_color: def.floor,
        rooms,
        stairs,
        hatches: Vec::new(),
        furniture,
        lights,
        parts: Vec::new(),
    };
    if let Err(e) = validate(&plan) {
        debug_assert!(false, "the {} plan is legal: {e}", def.name);
    }
    turned(&plan, quarters_for(front))
}

/// Each room's name and where someone stands in it when the place is
/// made: toward its front, from the place's middle, turned to face
/// `front` (as `house::home_spots`).
pub fn room_spots(def: &PlanDef, front: Vec2) -> Vec<(&str, Vec2)> {
    def.rooms
        .iter()
        .map(|room| {
            let (c, r) = room.at;
            (room.name.as_str(), turn(room_at(def, c, r) + Vec3::new(0.0, 0.0, 0.35 * def.rows[r]), front))
        })
        .collect()
}

/// Where each of the place's things stands, from its middle, turned to
/// face `front`.
pub fn things_of(def: &PlanDef, front: Vec2) -> Vec<(&str, Vec2)> {
    def.things
        .iter()
        .filter_map(|t| {
            let [fx, fz] = t.at;
            let (c, r) = def.rooms.iter().find(|room| room.name == t.room)?.at;
            let (w, l) = (def.columns[c], def.rows[r]);
            let p = room_at(def, c, r) + Vec3::new((fx * w).clamp(-(w / 2.0 - 0.5), w / 2.0 - 0.5), 0.0, (fz * l).clamp(-(l / 2.0 - 0.5), l / 2.0 - 0.5));
            Some((t.thing.as_str(), turn(p, front)))
        })
        .chain(def.outside.iter().map(|o| (o.thing.as_str(), turn(Vec3::new(o.at[0], 0.0, o.at[1]), front))))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    const SHOP: &str = r#"{
        "name": "shop",
        "columns": [8.0, 4.0],
        "rows": [6.0, 4.0],
        "rooms": [
            {"at": [0, 0], "name": "floor"}, {"at": [1, 0], "name": "office"},
            {"at": [0, 1], "name": "stockroom"}, {"at": [1, 1], "name": "restroom"}
        ],
        "ways": [
            {"from": [0, 0], "side": "east", "door": true}, {"from": [0, 0], "side": "north", "door": true},
            {"from": [0, 1], "side": "east", "door": true}
        ],
        "exits": [{"from": [0, 0], "side": "south", "width": 2.0}],
        "furniture": [{"room": "floor", "at": [0.0, 0.0], "size": [4.0, 1.5, 0.8]}],
        "things": [{"thing": "register", "room": "floor", "at": [0.3, 0.3]}],
        "outside": [{"thing": "sign", "at": [0.0, 6.0]}],
        "walls": [[0.8, 0.8, 0.7]],
        "floor": [0.5, 0.5, 0.5],
        "furniture colour": [0.4, 0.3, 0.2],
        "height": 3.0
    }"#;

    #[test]
    fn a_plan_builds_every_room_and_places_its_things() {
        let shop: PlanDef = serde_json::from_str(SHOP).unwrap();
        let built = build(&shop, Vec2::new(0.0, 1.0), 7);
        assert_eq!(built.rooms.len(), 4);
        assert!(validate(&built).is_ok());
        assert_eq!(things_of(&shop, Vec2::new(0.0, 1.0)).len(), 2);
    }
}
