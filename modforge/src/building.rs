//! Building the way Rust builds (todo 9f; prior art: Facepunch's Rust).
//! Pieces snap to a grid of square cells: a foundation, a floor, stairs
//! or a roof fills a cell; a wall, doorway or window stands on one of a
//! cell's edges. Every piece has a grade (twig, wood, stone, metal,
//! armored), each grade its health and what it costs to reach. A piece
//! stands only while it is held up: a foundation always is, a wall by
//! the slab under it, a slab by a wall under one of its edges or by a
//! slab next to it, losing strength the farther it reaches; a piece held
//! up by too little falls, and what it held falls with it. A tool
//! cupboard gives its group the right to build within its reach, and
//! nobody else; it takes upkeep for every piece in reach, and pieces it
//! cannot pay for decay. A wall has a soft side, the side it was built
//! from, and a hit from there does more. Every number here is Claude's,
//! for the operator to change.

use std::collections::BTreeMap;

use serde::{Deserialize, Serialize};

/// One cell's size, metres (Rust's foundation is 3 m).
pub const CELL: f32 = 3.0;
/// The height of one level, metres (a wall's height).
pub const LEVEL: f32 = 3.0;
/// What a slab keeps of the strength of the slab beside it that holds it.
pub const REACH_KEEPS: f32 = 0.5;
/// Under this strength a piece falls.
pub const FALLS_UNDER: f32 = 0.1;
/// How far a tool cupboard's right to build reaches, in cells.
pub const CUPBOARD_REACH: i32 = 8;
/// How much more a hit on a wall's soft side does.
pub const SOFT_SIDE: f32 = 2.0;
/// A piece not paid for loses this share of its full health each upkeep.
pub const DECAY_SHARE: f32 = 0.1;

/// What a piece is.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash, Serialize, Deserialize)]
pub enum Kind {
    Foundation,
    Floor,
    Stairs,
    Roof,
    Wall,
    Doorway,
    Window,
    /// Atlas's railing: a waist-high wall on an edge, for a porch or a
    /// balcony; it holds nothing up (todo "Recipes": Atlas's building).
    Railing,
    /// Atlas's pillar: a post filling its cell, on the ground or on a
    /// pillar below, holding up the slab over it, so a floor stands on
    /// stilts with no walls under it.
    Pillar,
}

impl Kind {
    /// Every kind, in the order the building plan offers them.
    pub const ALL: [Kind; 9] = [Kind::Foundation, Kind::Wall, Kind::Doorway, Kind::Window, Kind::Railing, Kind::Pillar, Kind::Floor, Kind::Stairs, Kind::Roof];

    /// Whether it stands on a cell's edge (a wall) or fills the cell.
    pub fn on_edge(self) -> bool {
        matches!(self, Kind::Wall | Kind::Doorway | Kind::Window | Kind::Railing)
    }

    /// Whether it holds up the slab over it from the level below.
    pub fn holds_up(self) -> bool {
        matches!(self, Kind::Wall | Kind::Doorway | Kind::Window | Kind::Pillar)
    }

    pub fn name(self) -> &'static str {
        match self {
            Kind::Foundation => "foundation",
            Kind::Floor => "floor",
            Kind::Stairs => "stairs",
            Kind::Roof => "roof",
            Kind::Wall => "wall",
            Kind::Doorway => "doorway",
            Kind::Window => "window",
            Kind::Railing => "railing",
            Kind::Pillar => "pillar",
        }
    }

    /// The next kind the building plan offers.
    pub fn next(self) -> Kind {
        let at = Kind::ALL.iter().position(|k| *k == self).unwrap_or(0);
        Kind::ALL[(at + 1) % Kind::ALL.len()]
    }
}

/// A piece's grade, weakest first.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash, Serialize, Deserialize)]
pub enum Grade {
    Twig,
    Wood,
    Stone,
    Metal,
    Armored,
}

impl Grade {
    /// Full health at this grade (Rust's foundation numbers).
    pub fn health(self) -> f32 {
        match self {
            Grade::Twig => 10.0,
            Grade::Wood => 250.0,
            Grade::Stone => 500.0,
            Grade::Metal => 1000.0,
            Grade::Armored => 2000.0,
        }
    }

    /// How much of the grade's material it takes to build a piece at it
    /// (the consumer names the material).
    pub fn cost(self) -> u32 {
        match self {
            Grade::Twig => 5,
            Grade::Wood => 20,
            Grade::Stone => 30,
            Grade::Metal => 20,
            Grade::Armored => 25,
        }
    }

    /// The grade a hammer upgrades it to.
    pub fn next(self) -> Option<Grade> {
        match self {
            Grade::Twig => Some(Grade::Wood),
            Grade::Wood => Some(Grade::Stone),
            Grade::Stone => Some(Grade::Metal),
            Grade::Metal => Some(Grade::Armored),
            Grade::Armored => None,
        }
    }

    /// The upkeep each piece at this grade takes, a share of its cost.
    pub fn upkeep(self) -> u32 {
        (self.cost() / 10).max(1)
    }
}

/// The edge of a cell a wall stands on. West and south are kept as the
/// east and north of the cell beside, so one edge has one name.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash, Serialize, Deserialize)]
pub enum Side {
    North,
    East,
    South,
    West,
}

/// Where a piece stands: a cell (x, z, level), and the edge for a wall.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash, Serialize, Deserialize)]
pub struct Slot {
    pub x: i32,
    pub z: i32,
    pub level: i32,
    pub side: Option<Side>,
}

impl Slot {
    pub fn cell(x: i32, z: i32, level: i32) -> Slot {
        Slot { x, z, level, side: None }
    }

    /// An edge, by its one name.
    pub fn edge(x: i32, z: i32, level: i32, side: Side) -> Slot {
        match side {
            Side::South => Slot { x, z: z - 1, level, side: Some(Side::North) },
            Side::West => Slot { x: x - 1, z, level, side: Some(Side::East) },
            _ => Slot { x, z, level, side: Some(side) },
        }
    }

    /// The two cells an edge lies between, or the cell itself.
    pub fn cells(self) -> Vec<(i32, i32)> {
        match self.side {
            Some(Side::North) => vec![(self.x, self.z), (self.x, self.z + 1)],
            Some(Side::East) => vec![(self.x, self.z), (self.x + 1, self.z)],
            _ => vec![(self.x, self.z)],
        }
    }

    /// The four edges of a cell.
    pub fn edges(x: i32, z: i32, level: i32) -> [Slot; 4] {
        [Side::North, Side::East, Side::South, Side::West].map(|s| Slot::edge(x, z, level, s))
    }

    /// Its middle on the ground, metres: (x, height, z).
    pub fn centre(self) -> [f32; 3] {
        let (x, z) = (self.x as f32 * CELL + CELL / 2.0, self.z as f32 * CELL + CELL / 2.0);
        let y = self.level as f32 * LEVEL;
        match self.side {
            Some(Side::North) => [x, y, z + CELL / 2.0],
            Some(Side::East) => [x + CELL / 2.0, y, z],
            _ => [x, y, z],
        }
    }

    /// The slot of a kind nearest a point (x, height, z), metres: the
    /// cell it is over, and for a wall the edge of it nearest.
    pub fn at(kind: Kind, point: [f32; 3]) -> Slot {
        let (fx, fz) = (point[0] / CELL, point[2] / CELL);
        let (x, z) = (fx.floor() as i32, fz.floor() as i32);
        let level = (point[1] / LEVEL).round() as i32;
        if !kind.on_edge() {
            return Slot::cell(x, z, level);
        }
        let (dx, dz) = (fx - fx.floor() - 0.5, fz - fz.floor() - 0.5);
        let side = if dx.abs() > dz.abs() {
            if dx > 0.0 { Side::East } else { Side::West }
        } else if dz > 0.0 {
            Side::North
        } else {
            Side::South
        };
        Slot::edge(x, z, level, side)
    }
}

/// One piece built.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Piece {
    pub kind: Kind,
    pub grade: Grade,
    pub health: f32,
    /// A wall's soft side: the cell it was built from (`Slot::cells`).
    pub soft: (i32, i32),
}

/// A tool cupboard: whose, and the cell it stands in.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct Cupboard {
    pub owner: String,
    pub at: Slot,
}

/// Everything built in the world.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Build {
    pub pieces: BTreeMap<Slot, Piece>,
    pub cupboards: Vec<Cupboard>,
}

/// Why a piece cannot go where it was asked.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Refused {
    Taken,
    NotHeld,
    NotYours,
    NoFoundationHere,
}

impl Build {
    /// How strongly each piece is held up, 0 to 1.
    pub fn strength(&self) -> BTreeMap<Slot, f32> {
        let mut strength: BTreeMap<Slot, f32> = self.pieces.keys().map(|s| (*s, 0.0)).collect();
        // Held up through the strongest way to the ground; a few passes
        // settle it (each pass reaches one piece farther).
        for _ in 0..=self.pieces.len() {
            let mut changed = false;
            for (slot, piece) in &self.pieces {
                let held = self.held_by(*slot, piece.kind, &strength);
                if held > strength[slot] + f32::EPSILON {
                    strength.insert(*slot, held);
                    changed = true;
                }
            }
            if !changed {
                break;
            }
        }
        strength
    }

    fn held_by(&self, slot: Slot, kind: Kind, strength: &BTreeMap<Slot, f32>) -> f32 {
        let of = |s: Slot| strength.get(&s).copied().unwrap_or(0.0);
        match kind {
            Kind::Foundation => 1.0,
            // A wall stands on the slab of either cell it lies between.
            Kind::Wall | Kind::Doorway | Kind::Window | Kind::Railing => {
                slot.cells().into_iter().map(|(x, z)| of(Slot::cell(x, z, slot.level))).fold(0.0, f32::max)
            }
            // A pillar stands on the ground, or on the pillar under it.
            Kind::Pillar if slot.level == 0 => 1.0,
            Kind::Pillar => {
                let under = Slot::cell(slot.x, slot.z, slot.level - 1);
                if self.pieces.get(&under).is_some_and(|p| p.kind == Kind::Pillar) { of(under) } else { 0.0 }
            }
            // Stairs stand on the slab of their own cell.
            Kind::Stairs => of(Slot::cell(slot.x, slot.z, slot.level)).max(self.slab_held(slot, strength)),
            Kind::Floor | Kind::Roof => self.slab_held(slot, strength),
        }
    }

    /// A slab at level L is held by a wall on its edge at L - 1 or a pillar
    /// under it, or by a slab beside it, keeping `REACH_KEEPS` of that
    /// one's strength.
    fn slab_held(&self, slot: Slot, strength: &BTreeMap<Slot, f32>) -> f32 {
        let of = |s: Slot| if self.pieces.get(&s).is_some_and(|p| !p.kind.on_edge() && p.kind != Kind::Stairs && p.kind != Kind::Pillar) { strength.get(&s).copied().unwrap_or(0.0) } else { 0.0 };
        let holding = |s: Slot| if self.pieces.get(&s).is_some_and(|p| p.kind.holds_up()) { strength.get(&s).copied().unwrap_or(0.0) } else { 0.0 };
        let below = Slot::edges(slot.x, slot.z, slot.level - 1)
            .into_iter()
            .chain([Slot::cell(slot.x, slot.z, slot.level - 1)])
            .map(holding)
            .fold(0.0, f32::max);
        let beside = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            .into_iter()
            .map(|(dx, dz)| of(Slot::cell(slot.x + dx, slot.z + dz, slot.level)) * REACH_KEEPS)
            .fold(0.0, f32::max);
        below.max(beside)
    }

    /// Whose cupboard's reach a slot is in, if any.
    pub fn privilege(&self, slot: Slot) -> Option<&str> {
        self.cupboards
            .iter()
            .find(|c| (c.at.x - slot.x).abs() <= CUPBOARD_REACH && (c.at.z - slot.z).abs() <= CUPBOARD_REACH)
            .map(|c| c.owner.as_str())
    }

    /// Whether `group` may build at a slot: nobody else's cupboard reaches it.
    pub fn may_build(&self, group: &str, slot: Slot) -> bool {
        self.privilege(slot).is_none_or(|owner| owner == group)
    }

    /// Place a twig piece, built from the cell `from` (its soft side).
    /// A foundation goes only on the ground level; anything else only
    /// where it would be held up.
    pub fn place(&mut self, group: &str, kind: Kind, slot: Slot, from: (i32, i32)) -> Result<(), Refused> {
        if self.pieces.contains_key(&slot) {
            return Err(Refused::Taken);
        }
        if !self.may_build(group, slot) {
            return Err(Refused::NotYours);
        }
        if kind == Kind::Foundation && slot.level != 0 {
            return Err(Refused::NoFoundationHere);
        }
        let grade = Grade::Twig;
        self.pieces.insert(slot, Piece { kind, grade, health: grade.health(), soft: from });
        if self.strength()[&slot] < FALLS_UNDER {
            self.pieces.remove(&slot);
            return Err(Refused::NotHeld);
        }
        Ok(())
    }

    /// Upgrade a piece to its next grade: the grade it went to, for the
    /// caller to take its cost. Full health at the new grade.
    pub fn upgrade(&mut self, group: &str, slot: Slot) -> Option<Grade> {
        if !self.may_build(group, slot) {
            return None;
        }
        let piece = self.pieces.get_mut(&slot)?;
        let next = piece.grade.next()?;
        piece.grade = next;
        piece.health = next.health();
        Some(next)
    }

    /// Every piece no longer held up falls: taken out, and returned.
    pub fn collapse(&mut self) -> Vec<(Slot, Piece)> {
        let strength = self.strength();
        let falling: Vec<Slot> = strength.iter().filter(|(_, s)| **s < FALLS_UNDER).map(|(slot, _)| *slot).collect();
        falling.into_iter().filter_map(|slot| self.pieces.remove(&slot).map(|p| (slot, p))).collect()
    }

    /// A hit on a piece from the cell `from`: harder on a wall's soft
    /// side. Its health left; at none it is gone, and what it held falls
    /// (`collapse`).
    pub fn hit(&mut self, slot: Slot, amount: f32, from: (i32, i32)) -> Option<f32> {
        let piece = self.pieces.get_mut(&slot)?;
        let soft = piece.kind.on_edge() && piece.soft == from;
        piece.health -= if soft { amount * SOFT_SIDE } else { amount };
        let left = piece.health;
        if left <= 0.0 {
            self.pieces.remove(&slot);
        }
        Some(left)
    }

    /// What a cupboard's upkeep is, per grade: every piece in its reach.
    pub fn upkeep(&self, cupboard: &Cupboard) -> BTreeMap<Grade, u32> {
        let mut cost = BTreeMap::new();
        for (slot, piece) in &self.pieces {
            if (cupboard.at.x - slot.x).abs() <= CUPBOARD_REACH && (cupboard.at.z - slot.z).abs() <= CUPBOARD_REACH {
                *cost.entry(piece.grade).or_insert(0) += piece.grade.upkeep();
            }
        }
        cost
    }

    /// Decay every piece of a grade not paid for, in reach of no paid
    /// cupboard (`paid`: the grades a cupboard paid this upkeep); the
    /// pieces gone.
    pub fn decay(&mut self, paid: &dyn Fn(Slot, Grade) -> bool) -> Vec<Slot> {
        let mut gone = Vec::new();
        for (slot, piece) in self.pieces.iter_mut() {
            if !paid(*slot, piece.grade) {
                piece.health -= piece.grade.health() * DECAY_SHARE;
                if piece.health <= 0.0 {
                    gone.push(*slot);
                }
            }
        }
        for slot in &gone {
            self.pieces.remove(slot);
        }
        gone
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_twig_wall_snaps_upgrades_and_an_unheld_floor_falls() {
        let mut b = Build::default();
        assert_eq!(b.place("us", Kind::Foundation, Slot::cell(0, 0, 0), (0, 0)), Ok(()));
        // A wall snaps to the foundation's nearest edge.
        let wall = Slot::at(Kind::Wall, [2.9, 0.0, 1.5]);
        assert_eq!(wall, Slot::edge(0, 0, 0, Side::East));
        assert_eq!(b.place("us", Kind::Wall, wall, (0, 0)), Ok(()));
        assert_eq!(b.pieces[&wall].grade, Grade::Twig);
        assert_eq!(b.upgrade("us", wall), Some(Grade::Wood));
        assert_eq!(b.pieces[&wall].health, 250.0);
        // A floor on the wall, and one beside it held by the first.
        let up = Slot::cell(0, 0, 1);
        assert_eq!(b.place("us", Kind::Floor, up, (0, 0)), Ok(()));
        assert_eq!(b.place("us", Kind::Floor, Slot::cell(0, 1, 1), (0, 0)), Ok(()));
        // A wall with no slab under it is refused.
        assert_eq!(b.place("us", Kind::Wall, Slot::edge(5, 5, 0, Side::North), (5, 5)), Err(Refused::NotHeld));
        // The wall gone: both floors fall.
        b.hit(wall, 1000.0, (1, 0));
        let fell: Vec<Slot> = b.collapse().into_iter().map(|(s, _)| s).collect();
        assert_eq!(fell, vec![up, Slot::cell(0, 1, 1)]);
    }

    #[test]
    fn a_cupboard_keeps_others_out_and_upkeep_decays_the_unpaid() {
        let mut b = Build::default();
        b.cupboards.push(Cupboard { owner: "us".into(), at: Slot::cell(0, 0, 0) });
        assert_eq!(b.place("them", Kind::Foundation, Slot::cell(1, 1, 0), (1, 1)), Err(Refused::NotYours));
        assert_eq!(b.place("us", Kind::Foundation, Slot::cell(1, 1, 0), (1, 1)), Ok(()));
        assert_eq!(b.upkeep(&b.cupboards[0].clone()).get(&Grade::Twig), Some(&1));
        // Twig at 10 health loses 1 an upkeep unpaid: gone by the eleventh.
        let gone: Vec<Slot> = (0..11).flat_map(|_| b.decay(&|_, _| false)).collect();
        assert_eq!(gone, vec![Slot::cell(1, 1, 0)]);
    }

    #[test]
    fn the_soft_side_takes_more() {
        let mut b = Build::default();
        b.place("us", Kind::Foundation, Slot::cell(0, 0, 0), (0, 0)).unwrap();
        let wall = Slot::edge(0, 0, 0, Side::North);
        b.place("us", Kind::Wall, wall, (0, 0)).unwrap();
        b.upgrade("us", wall);
        assert_eq!(b.hit(wall, 10.0, (0, 1)), Some(240.0));
        assert_eq!(b.hit(wall, 10.0, (0, 0)), Some(220.0));
    }
}
