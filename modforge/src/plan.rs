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

use crate::house::quarters_for;
use crate::monument::{Roll, WALL, door, spaced, window};
use crate::structure::{LightDef, Opening, Rgb, RoomDef, Side, SolidDef, StructureDef, turned, validate};

/// One place's plan. Columns run west to east, rows front to back (the
/// front +z, toward its street).
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct PlanDef {
    pub name: &'static str,
    /// Whether it stands at the edge of town (else on main street).
    pub edge: bool,
    /// The rooms' interior sizes, metres.
    pub columns: &'static [f32],
    pub rows: &'static [f32],
    /// Each room by (column, row), named.
    pub rooms: &'static [((usize, usize), &'static str)],
    /// The ways between rooms: from a room east or north, with a door
    /// hung or an open way.
    pub ways: &'static [((usize, usize), Side, bool)],
    /// The ways out: a room, its outside wall, and the way's width.
    pub exits: &'static [((usize, usize), Side, f32)],
    /// Furniture by room name: where it sits as a share of the room
    /// (-0.5 to 0.5 across and along), and its size.
    pub furniture: &'static [(&'static str, [f32; 2], [f32; 3])],
    /// The model each piece of `furniture` is drawn as, in its order
    /// (`SolidDef::model`); a piece past the list's end, or named "", is
    /// drawn as a block.
    pub furniture_models: &'static [&'static str],
    /// The things used in it by room name: the thing's name and where it
    /// stands as a share of the room, in the first room of that name.
    pub things: &'static [(&'static str, &'static str, [f32; 2])],
    /// The things standing outside it (a farm's fields, a gas station's
    /// pumps): the thing's name and where, metres from the plan's middle,
    /// +z its front.
    pub outside: &'static [(&'static str, [f32; 2])],
    pub walls: &'static [Rgb],
    pub floor: Rgb,
    pub furniture_color: Rgb,
    pub height: f32,
}

/// Where a room's middle is, from the plan's middle, unturned.
fn room_at(def: &PlanDef, c: usize, r: usize) -> Vec3 {
    let xs = spaced(def.columns, 1.0);
    let zs = spaced(def.rows, -1.0);
    let mid = Vec3::new((xs[0] + xs[xs.len() - 1]) / 2.0, 0.0, (zs[0] + zs[zs.len() - 1]) / 2.0).round();
    Vec3::new(xs[c], 0.0, zs[r]) - mid
}

/// A point of the unturned plan, turned to face `front`, on the ground.
fn turn(p: Vec3, front: Vec2) -> Vec2 {
    (0..quarters_for(front)).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// The place `def` builds, facing `front`, varied by `seed` (its wall
/// colour and its windows).
pub fn build(def: &PlanDef, front: Vec2, seed: u64) -> StructureDef {
    let mut roll = Roll::new(seed);
    let wall_color = *roll.pick(def.walls);
    let (last_col, last_row) = (def.columns.len() - 1, def.rows.len() - 1);
    let mut rooms = Vec::new();
    let mut furniture = Vec::new();
    let mut lights = Vec::new();
    for &((c, r), name) in def.rooms {
        let (w, l) = (def.columns[c], def.rows[r]);
        let origin = room_at(def, c, r);
        let mut openings: Vec<Opening> = Vec::new();
        for &((wc, wr), side, hung) in def.ways {
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
        for &(at, side, width) in def.exits {
            if at == (c, r) {
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
            floor: true,
            ceiling: true,
        });
        for (i, &(_, [fx, fz], [sx, sy, sz])) in def.furniture.iter().enumerate().filter(|(_, f)| f.0 == name) {
            let size = Vec3::new(sx.min(w - 0.4), sy, sz.min(l - 0.4));
            let dx = (fx * w).clamp(-(w / 2.0 - size.x / 2.0 - 0.1), w / 2.0 - size.x / 2.0 - 0.1);
            let dz = (fz * l).clamp(-(l / 2.0 - size.z / 2.0 - 0.1), l / 2.0 - size.z / 2.0 - 0.1);
            let model = def.furniture_models.get(i).filter(|m| !m.is_empty()).map(|m| m.to_string());
            furniture.push(SolidDef { center: origin + Vec3::new(dx, size.y / 2.0, dz), size, color: def.furniture_color, model });
        }
        lights.push(LightDef { position: origin + Vec3::new(0.0, def.height - 0.4, 0.0), color: [1.0, 0.95, 0.85], intensity: 400_000.0 });
    }
    let plan = StructureDef {
        name: def.name.to_string(),
        wall_color,
        floor_color: def.floor,
        rooms,
        stairs: Vec::new(),
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

/// Where each of the place's things stands, from its middle, turned to
/// face `front`.
pub fn things_of(def: &PlanDef, front: Vec2) -> Vec<(&'static str, Vec2)> {
    def.things
        .iter()
        .filter_map(|&(thing, room, [fx, fz])| {
            let &((c, r), _) = def.rooms.iter().find(|(_, n)| *n == room)?;
            let (w, l) = (def.columns[c], def.rows[r]);
            let p = room_at(def, c, r) + Vec3::new((fx * w).clamp(-(w / 2.0 - 0.5), w / 2.0 - 0.5), 0.0, (fz * l).clamp(-(l / 2.0 - 0.5), l / 2.0 - 0.5));
            Some((thing, turn(p, front)))
        })
        .chain(def.outside.iter().map(|&(thing, [x, z])| (thing, turn(Vec3::new(x, 0.0, z), front))))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    const SHOP: PlanDef = PlanDef {
        name: "shop",
        edge: false,
        furniture_models: &[],
        columns: &[8.0, 4.0],
        rows: &[6.0, 4.0],
        rooms: &[((0, 0), "floor"), ((1, 0), "office"), ((0, 1), "stockroom"), ((1, 1), "restroom")],
        ways: &[((0, 0), Side::East, true), ((0, 0), Side::North, true), ((0, 1), Side::East, true)],
        exits: &[((0, 0), Side::South, 2.0)],
        furniture: &[("floor", [0.0, 0.0], [4.0, 1.5, 0.8])],
        things: &[("register", "floor", [0.3, 0.3])],
        outside: &[("sign", [0.0, 6.0])],
        walls: &[[0.8, 0.8, 0.7]],
        floor: [0.5, 0.5, 0.5],
        furniture_color: [0.4, 0.3, 0.2],
        height: 3.0,
    };

    #[test]
    fn a_plan_builds_every_room_and_places_its_things() {
        let built = build(&SHOP, Vec2::new(0.0, 1.0), 7);
        assert_eq!(built.rooms.len(), 4);
        assert!(validate(&built).is_ok());
        assert_eq!(things_of(&SHOP, Vec2::new(0.0, 1.0)).len(), 2);
    }
}
