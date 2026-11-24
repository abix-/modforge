//! The town's house (topside page topside-town "The houses", operator
//! 2026-11-23: "cookie-cutter houses"): one real floor plan built from the
//! building pieces (rooms, walls, doors, windows, furniture), every room a
//! house has, stood on every house lot, each varied by its colours, the
//! way it turns to face its street and small details (which pieces of
//! furniture it has, which back windows).
//!
//! The plan, front (south, +z) at the bottom, every size whole metres
//! (built in 1 m blocks); the rooms and their sizes are Claude's, for the
//! operator to change:
//!
//! ```text
//!   laundry  | bedroom     | hall | bedroom
//!   kitchen  | dining room | hall | bathroom
//!   garage   | living room | hall | bedroom
//!   (garage door)            (front door)
//! ```

use glam::{Vec2, Vec3};

use crate::monument::{Roll, WALL, door, spaced, window};
use crate::structure::{LightDef, Opening, Rgb, RoomDef, Side, SolidDef, StructureDef, turned, validate};
/// What a house varies by.
#[derive(Clone, Debug, PartialEq)]
pub struct HouseDef {
    /// Outside wall colours, one picked per house.
    pub walls: Vec<Rgb>,
    /// Floor colours, one picked per house.
    pub floors: Vec<Rgb>,
    /// Furniture colours, one picked per piece.
    pub furniture: Vec<Rgb>,
    /// Chance of each piece of furniture a house may go without, and of
    /// each back window, per mille.
    pub extras: u64,
    pub back_windows: u64,
    /// Floor to ceiling, metres.
    pub height: f32,
}

/// The rooms' columns, west to east, and rows, front to back: interior
/// metres.
const COLUMNS: [f32; 4] = [6.0, 4.0, 3.0, 4.0];
/// The front row 8 m deep: the garage the size of a bunker's top room, so
/// on a lot over a bunker (topside-town "The bunkers") the bunker's top
/// room stands in the garage's place.
const ROWS: [f32; 3] = [8.0, 4.0, 4.0];
/// The garage door's width, metres.
const GARAGE_DOOR: f32 = 3.0;

/// Each room of the plan by (column, row), named.
const ROOMS: [((usize, usize), &str); 12] = [
    ((0, 0), "garage"),
    ((1, 0), "living room"),
    ((2, 0), "hall"),
    ((3, 0), "bedroom"),
    ((0, 1), "kitchen"),
    ((1, 1), "dining room"),
    ((2, 1), "hall"),
    ((3, 1), "bathroom"),
    ((0, 2), "laundry"),
    ((1, 2), "bedroom"),
    ((2, 2), "hall"),
    ((3, 2), "bedroom"),
];

/// The ways between rooms, by (column, row) and the way from the first to
/// the second (east or north); with a door hung, or an open way.
const WAYS: [((usize, usize), Side, bool); 12] = [
    ((0, 0), Side::North, true),  // garage to kitchen
    ((0, 1), Side::East, false),  // kitchen to dining room
    ((0, 1), Side::North, true),  // kitchen to laundry
    ((1, 0), Side::North, false), // living room to dining room
    ((1, 0), Side::East, false),  // living room to hall
    ((1, 1), Side::East, false),  // dining room to hall
    ((1, 2), Side::East, true),   // bedroom to hall
    ((2, 0), Side::North, false), // the hall through
    ((2, 1), Side::North, false),
    ((2, 0), Side::East, true), // hall to bedroom
    ((2, 1), Side::East, true), // hall to bathroom
    ((2, 2), Side::East, true), // hall to bedroom
];

/// Each room's furniture: where it sits as a share of the room's width and
/// length from its middle (-0.5 to 0.5), its size, and whether every house
/// has it (else it is an extra).
type Piece = ([f32; 2], [f32; 3], bool);

fn furniture_of(name: &str) -> &'static [Piece] {
    match name {
        "garage" => &[
            ([-0.42, -0.1], [0.6, 0.9, 1.8], true),  // workbench
            ([0.42, -0.35], [0.5, 1.8, 1.2], false), // shelves
        ],
        "living room" => &[
            ([-0.4, 0.0], [0.9, 0.8, 2.0], true),    // couch
            ([0.3, 0.42], [1.4, 0.6, 0.45], true),   // TV stand
            ([0.25, -0.3], [0.8, 0.8, 0.8], false),  // armchair
        ],
        "kitchen" => &[
            ([-0.44, -0.15], [0.6, 0.9, 2.2], true), // counter and sink
            ([-0.44, 0.38], [0.6, 0.9, 0.75], true), // stove
            ([0.4, -0.4], [0.8, 1.8, 0.7], true),    // fridge
        ],
        "dining room" => &[
            ([0.0, -0.2], [1.6, 0.75, 0.9], true),   // table
            ([-0.3, -0.2], [0.45, 0.9, 0.45], false), // chair
            ([0.3, -0.2], [0.45, 0.9, 0.45], false),  // chair
        ],
        "bedroom" => &[
            ([0.15, -0.3], [1.5, 0.6, 2.0], true),   // bed
            ([0.42, 0.3], [0.5, 1.0, 1.2], true),    // dresser
            ([-0.3, -0.42], [0.45, 0.5, 0.45], false), // nightstand
        ],
        "bathroom" => &[
            ([0.3, -0.38], [1.6, 0.6, 0.75], true),  // tub
            ([0.42, 0.3], [0.4, 0.8, 0.65], true),   // toilet
            ([-0.1, 0.42], [0.6, 0.9, 0.45], true),  // sink
        ],
        "laundry" => &[
            ([-0.42, 0.0], [0.65, 0.9, 0.65], true),  // washer
            ([-0.42, 0.3], [0.65, 0.9, 0.65], false), // dryer
        ],
        _ => &[],
    }
}

/// Where a room's middle is, from the plan's middle (the plan unturned,
/// its front +z).
fn room_at(c: usize, r: usize) -> Vec3 {
    let xs = spaced(&COLUMNS, 1.0);
    let zs = spaced(&ROWS, -1.0);
    // The middle to a whole metre, so the garage, and a bunker under it,
    // is whole metres from it.
    let mid = Vec3::new((xs[0] + xs[3]) / 2.0, 0.0, (zs[0] + zs[2]) / 2.0).round();
    Vec3::new(xs[c], 0.0, zs[r]) - mid
}

/// Where the people living in a house stand when it is made: in each of
/// its bedrooms and its living room, toward the room's front, clear of its
/// furniture, from the house's middle, on the ground, turned to face
/// `front` as the house is.
pub fn home_spots(front: Vec2) -> Vec<Vec2> {
    let q = quarters_for(front);
    ROOMS
        .iter()
        .filter(|(_, name)| matches!(*name, "bedroom" | "living room"))
        .map(|&((c, r), _)| {
            let p = room_at(c, r) + Vec3::new(0.0, 0.0, 0.35 * ROWS[r]);
            (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
        })
        .collect()
}

/// A house's water fixtures (topside-town "Everything works": faucets,
/// toilets, showers): each its kind and where it stands from the house's
/// middle, at the furniture it is part of, turned to face `front`. The
/// medicine cabinet hangs over the bathroom sink ("medicine cabinets").
pub fn fixtures(front: Vec2) -> Vec<(&'static str, Vec2)> {
    // The room, the kind, and which of the room's furniture it is.
    const FIXTURES: [(&str, &str, usize); 5] =
        [("kitchen", "sink", 0), ("bathroom", "shower", 0), ("bathroom", "toilet", 1), ("bathroom", "sink", 2), ("bathroom", "medicine cabinet", 2)];
    let q = quarters_for(front);
    FIXTURES
        .iter()
        .filter_map(|&(room, kind, piece)| {
            let &((c, r), _) = ROOMS.iter().find(|(_, name)| *name == room)?;
            let &([fx, fz], [sx, _, sz], _) = furniture_of(room).get(piece)?;
            let (w, l) = (COLUMNS[c], ROWS[r]);
            // Placed as `house` places the furniture.
            let (sx, sz) = (sx.min(w - 0.4), sz.min(l - 0.4));
            let dx = (fx * w).clamp(-(w / 2.0 - sx / 2.0 - 0.1), w / 2.0 - sx / 2.0 - 0.1);
            let dz = (fz * l).clamp(-(l / 2.0 - sz / 2.0 - 0.1), l / 2.0 - sz / 2.0 - 0.1);
            let p = room_at(c, r) + Vec3::new(dx, 0.0, dz);
            Some((kind, (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))))
        })
        .collect()
}

/// A house's wiring (topside-town "Everything works": "breaker boxes,
/// outlets, switches"; Project Zomboid's house power): where its breaker
/// box stands (the front hall, by the door), and each room's switch, by
/// its front wall, with the light it turns on, at the room's middle, each
/// from the house's middle, turned to face `front`. A house over a bunker
/// has no garage, so no garage switch.
pub fn wiring(front: Vec2, over_bunker: bool) -> (Vec2, Vec<(Vec2, Vec2)>) {
    let q = quarters_for(front);
    let turn = |p: Vec3| (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x));
    let breaker = turn(room_at(2, 0) + Vec3::new(-0.4 * COLUMNS[2], 0.0, 0.4 * ROWS[0]));
    let rooms = ROOMS
        .iter()
        .filter(|(_, name)| !(over_bunker && *name == "garage"))
        .map(|&((c, r), _)| (turn(room_at(c, r) + Vec3::new(0.3 * COLUMNS[c], 0.0, 0.45 * ROWS[r])), turn(room_at(c, r))))
        .collect();
    (breaker, rooms)
}

/// A house's heating and cooling (topside-town "Everything works":
/// "furnaces, fireplaces, wood stoves, AC, blankets, thermostats"): each
/// its kind and where it stands from the house's middle, turned to face
/// `front`: a fireplace on the living room's west wall, a wood stove in
/// the kitchen, the furnace in the laundry, the thermostat and the air
/// conditioner in the hall. Where each stands is Claude's.
pub fn heating(front: Vec2) -> Vec<(&'static str, Vec2)> {
    let q = quarters_for(front);
    let turn = |p: Vec3| (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x));
    [
        ("fireplace", (1, 0), [-0.4, 0.0]),
        ("wood stove", (0, 1), [0.3, 0.35]),
        ("furnace", (0, 2), [0.3, -0.35]),
        ("thermostat", (2, 1), [0.4, 0.0]),
        ("air conditioner", (2, 2), [0.0, -0.4]),
    ]
    .iter()
    .map(|&(kind, (c, r), [fx, fz])| (kind, turn(room_at(c, r) + Vec3::new(fx * COLUMNS[c], 0.0, fz * ROWS[r]))))
    .collect()
}

/// A house's kitchen (topside-town "Everything works": food "kept in
/// pantries, fridges and freezers, cooked on stoves"): the pantry, the
/// fridge, the freezer and the stove, each where it stands from the
/// house's middle, turned to face `front`, along the kitchen's east wall.
/// Where each stands is Claude's.
pub fn kitchen(front: Vec2) -> Vec<(&'static str, Vec2)> {
    let q = quarters_for(front);
    let turn = |p: Vec3| (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x));
    [("pantry", -0.3), ("fridge", -0.1), ("freezer", 0.1), ("stove", 0.3)]
        .iter()
        .map(|&(kind, fz)| (kind, turn(room_at(0, 1) + Vec3::new(0.4 * COLUMNS[0], 0.0, fz * ROWS[1]))))
        .collect()
}

/// A house's clothing (topside-town "Everything works": "closets and
/// dressers hold clothes; the washer and dryer clean them"): a closet and
/// a dresser in each bedroom, the washer and dryer in the laundry, each
/// where it stands from the house's middle, turned to face `front`.
/// Where each stands is Claude's.
pub fn clothing(front: Vec2) -> Vec<(&'static str, Vec2)> {
    let q = quarters_for(front);
    let turn = |p: Vec3| (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x));
    let bedrooms = ROOMS.iter().filter(|(_, name)| *name == "bedroom").flat_map(|&((c, r), _)| {
        [("closet", -0.4), ("dresser", 0.4)].map(|(kind, fx)| (kind, room_at(c, r) + Vec3::new(fx * COLUMNS[c], 0.0, -0.35 * ROWS[r])))
    });
    let laundry = [("washer", -0.3), ("dryer", -0.1)].map(|(kind, fx)| (kind, room_at(0, 2) + Vec3::new(fx * COLUMNS[0], 0.0, 0.35 * ROWS[2])));
    bedrooms.chain(laundry).map(|(kind, p)| (kind, turn(p))).collect()
}

/// A house's storage (topside-town "Everything works": "pantries,
/// cabinets, garages, attics and basements hold things"): the kitchen's
/// cabinets on its west wall and the garage's shelves, none when a
/// bunker's top room stands in the garage's place; each where it stands
/// from the house's middle, turned to face `front`. Where each stands is
/// Claude's.
pub fn storage(front: Vec2, over_bunker: bool) -> Vec<(&'static str, Vec2)> {
    let q = quarters_for(front);
    let turn = |p: Vec3| (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x));
    let mut all = vec![("kitchen cabinet", turn(room_at(0, 1) + Vec3::new(-0.4 * COLUMNS[0], 0.0, 0.0)))];
    if !over_bunker {
        all.push(("garage shelf", turn(room_at(0, 0) + Vec3::new(-0.4 * COLUMNS[0], 0.0, -0.3 * ROWS[0]))));
        // The garage's workbench and toolbox ("garage workbenches,
        // toolboxes ... fix and build things").
        all.push(("garage workbench", turn(room_at(0, 0) + Vec3::new(-0.4 * COLUMNS[0], 0.0, 0.1 * ROWS[0]))));
        all.push(("toolbox", turn(room_at(0, 0) + Vec3::new(-0.4 * COLUMNS[0], 0.0, 0.3 * ROWS[0]))));
    }
    all
}

/// Where a vehicle stands in a house's driveway (topside-town
/// "Everything works": "cars in driveways"): before the garage door, 3 m
/// out from the house's front, turned to face `front`. Claude's.
pub fn driveway(front: Vec2) -> Vec2 {
    let q = quarters_for(front);
    let p = room_at(0, 0) + Vec3::new(0.0, 0.0, 0.5 * ROWS[0] + 3.0);
    (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// Where a house's front door stands, its doorway's middle in the hall's
/// south wall, from the house's middle, turned to face `front` (the
/// opening the plan makes for room (2, 0)).
pub fn front_door(front: Vec2) -> Vec2 {
    let q = quarters_for(front);
    let p = room_at(2, 0) + Vec3::new(0.0, 0.0, 0.5 * ROWS[0]);
    (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// Where a house's smoke detector is (topside-town "Everything works":
/// "smoke detectors"): in the front hall, behind its light, turned to
/// face `front`. Claude's.
pub fn smoke_detector(front: Vec2) -> Vec2 {
    let q = quarters_for(front);
    let p = room_at(2, 0) + Vec3::new(0.0, 0.0, -0.3 * ROWS[0]);
    (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// Where a house's TV, radio and phone stand (topside-town "Everything
/// works": "phones, radios, TVs"): the TV and the radio against the
/// living room's back wall, the phone in the hall by the front door;
/// and its mailbox, at the street, 2 m past the driveway's side. Each
/// from the house's middle, turned to face `front`. Claude's.
pub fn den(front: Vec2) -> [(&'static str, Vec2); 5] {
    let q = quarters_for(front);
    let turn = |p: Vec3| (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x));
    let living = room_at(1, 0);
    [
        ("tv", turn(living + Vec3::new(-0.2 * COLUMNS[1], 0.0, -0.4 * ROWS[0]))),
        ("radio", turn(living + Vec3::new(0.2 * COLUMNS[1], 0.0, -0.4 * ROWS[0]))),
        ("phone", turn(room_at(2, 0) + Vec3::new(0.35 * COLUMNS[2], 0.0, 0.3 * ROWS[0]))),
        ("mailbox", turn(room_at(1, 0) + Vec3::new(0.0, 0.0, 0.5 * ROWS[0] + 6.0))),
        // Its trash can beside the mailbox (Works 17).
        ("trash can", turn(room_at(1, 0) + Vec3::new(1.5, 0.0, 0.5 * ROWS[0] + 6.0))),
    ]
}

/// Where a house's garden beds lie (topside-town "Everything works":
/// "gardens"): two in the back yard, 4 m behind the house's back wall,
/// turned to face `front`. Claude's.
pub fn garden(front: Vec2) -> [Vec2; 2] {
    let q = quarters_for(front);
    let back = room_at(1, ROWS.len() - 1) + Vec3::new(0.0, 0.0, -0.5 * ROWS[ROWS.len() - 1] - 4.0);
    [-1.5, 1.5].map(|dx| {
        let p = back + Vec3::new(dx, 0.0, 0.0);
        (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
    })
}

/// Where a house's safe stands (topside-town "Everything works":
/// "safes"): against the first bedroom's back wall, between its closet
/// and its dresser, turned to face `front`. Claude's.
pub fn safe(front: Vec2) -> Vec2 {
    let q = quarters_for(front);
    let (c, r) = ROOMS.iter().find(|(_, name)| *name == "bedroom").map_or((0, 0), |&(at, _)| at);
    let p = room_at(c, r) + Vec3::new(0.0, 0.0, -0.35 * ROWS[r]);
    (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// Where the living room's couch stands, from the house's middle, turned
/// to face `front` (topside-town "Everything works"). Claude's.
pub fn couch(front: Vec2) -> Vec2 {
    let q = quarters_for(front);
    let p = room_at(1, 0) + Vec3::new(0.0, 0.0, -0.35 * ROWS[0]);
    (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// Where the dining table's middle stands, from the house's middle,
/// turned to face `front` (a candle on it, topside-town "Everything
/// works").
pub fn dining_table(front: Vec2) -> Vec2 {
    let q = quarters_for(front);
    let p = room_at(1, 1) + Vec3::new(0.0, 0.0, -0.2 * ROWS[1]);
    (0..q).fold(Vec2::new(p.x, p.z), |p, _| Vec2::new(-p.y, p.x))
}

/// The quarter turns that take the plan's front (+z, the ground's +y) to
/// `front`.
pub fn quarters_for(front: Vec2) -> u32 {
    match (front.x.round() as i32, front.y.round() as i32) {
        (-1, 0) => 1,
        (0, -1) => 2,
        (1, 0) => 3,
        _ => 0,
    }
}

/// Where a bunker's top room stands under a house facing +y (the plan
/// unturned): the garage's middle, from the house's middle, on the ground.
pub fn bunker_offset() -> Vec2 {
    let g = room_at(0, 0);
    Vec2::new(g.x, g.z)
}

/// A house rolled from `seed`: the plan, its colours and small details,
/// its front door facing `front` (a unit vector on the ground, toward its
/// street; the plan's own front faces +z, the ground's +y), the house's
/// middle at the structure's origin. Over a bunker, the house has no
/// garage: the bunker's top room stands there, its own door to the front.
pub fn house(def: &HouseDef, front: Vec2, seed: u64, over_bunker: bool) -> StructureDef {
    let mut roll = Roll::new(seed);
    let wall_color = *roll.pick(&def.walls);
    let floor_color = *roll.pick(&def.floors);
    let (last_col, last_row) = (COLUMNS.len() - 1, ROWS.len() - 1);
    let mut rooms = Vec::new();
    let mut furniture = Vec::new();
    let mut lights = Vec::new();
    let garage = (0, 0);
    for &((c, r), name) in &ROOMS {
        if over_bunker && (c, r) == garage {
            continue;
        }
        let (w, l) = (COLUMNS[c], ROWS[r]);
        let origin = room_at(c, r);
        let mut openings: Vec<Opening> = Vec::new();
        // The ways between rooms: both rooms author the gap, the first
        // hangs the door.
        for &((wc, wr), side, hung) in &WAYS {
            let other = match side {
                Side::East => (wc + 1, wr),
                Side::North => (wc, wr + 1),
                _ => continue,
            };
            if over_bunker && ((wc, wr) == garage || other == garage) {
                continue;
            }
            if (wc, wr) == (c, r) {
                openings.push(Opening { door: hung, ..door(side, 0.0) });
            } else if other == (c, r) {
                let back = if side == Side::East { Side::West } else { Side::South };
                openings.push(Opening { door: false, ..door(back, 0.0) });
            }
        }
        // The ways out: the front door into the hall, the garage door,
        // the back door from the laundry.
        match (c, r) {
            (2, 0) => openings.push(door(Side::South, 0.0)),
            (0, 0) => openings.push(Opening {
                side: Side::South,
                offset: 0.0,
                width: GARAGE_DOOR,
                sill: 0.0,
                door: true,
            }),
            (0, 2) => openings.push(door(Side::North, 0.0)),
            _ => {}
        }
        // Windows on the outside walls a door is not on: the front's
        // always, the back's and sides' by chance; none in the garage's
        // front or the hall.
        let outside = [
            (Side::South, r == 0),
            (Side::North, r == last_row),
            (Side::West, c == 0),
            (Side::East, c == last_col),
        ];
        for (side, out) in outside {
            let taken = openings.iter().any(|o| o.side == side);
            if !out || taken || name == "hall" {
                continue;
            }
            let run = if matches!(side, Side::North | Side::South) { w } else { l };
            let front_wall = side == Side::South;
            if front_wall || roll.chance(def.back_windows) {
                let s = (run / 2.0 - 1.0).max(0.0);
                openings.push(window(side, roll.measure(-s, s)));
            }
        }
        // A bedroom's furniture is laid out for one entered from the west;
        // one entered only from the east has it mirrored, so it is not in
        // the way in.
        let east_only = name == "bedroom"
            && openings.iter().any(|o| o.side == Side::East && o.sill == 0.0)
            && !openings.iter().any(|o| o.side == Side::West && o.sill == 0.0);
        let mirror = if east_only { -1.0 } else { 1.0 };
        rooms.push(RoomDef {
            origin,
            interior: Vec3::new(w, def.height, l),
            wall_thickness: WALL,
            openings,
            floor: true,
            ceiling: true,
        });
        for &([fx, fz], [sx, sy, sz], always) in furniture_of(name) {
            if !always && !roll.chance(def.extras) {
                continue;
            }
            let fx = fx * mirror;
            let size = Vec3::new(sx.min(w - 0.4), sy, sz.min(l - 0.4));
            let dx = (fx * w).clamp(-(w / 2.0 - size.x / 2.0 - 0.1), w / 2.0 - size.x / 2.0 - 0.1);
            let dz = (fz * l).clamp(-(l / 2.0 - size.z / 2.0 - 0.1), l / 2.0 - size.z / 2.0 - 0.1);
            furniture.push(SolidDef {
                center: origin + Vec3::new(dx, size.y / 2.0, dz),
                size,
                color: *roll.pick(&def.furniture),
            });
        }
        lights.push(LightDef {
            position: origin + Vec3::new(0.0, def.height - 0.4, 0.0),
            color: [1.0, 0.9, 0.7],
            intensity: 300_000.0,
        });
    }
    let plan = StructureDef {
        name: "house".to_string(),
        wall_color,
        floor_color,
        rooms,
        stairs: Vec::new(),
        hatches: Vec::new(),
        furniture,
        lights,
        parts: Vec::new(),
    };
    if let Err(e) = validate(&plan) {
        debug_assert!(false, "the house plan is legal: {e}");
    }
    // The plan's front faces +z; a quarter turn takes +z to -x.
    turned(&plan, quarters_for(front))
}
