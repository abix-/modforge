//! A planned town (topside page topside-town, operator 2026-11-23: "it
//! actually feels like a planned out city, right? Or a planned out town"),
//! laid out as a small town's grid plat is: a main street through the
//! middle with its lots either side, a residential street either side of
//! it with the houses on both its sides (the inner ones back to back with
//! main street's), cul-de-sacs off the residential streets' outer sides,
//! cross streets closing the blocks, and the edge of town along main
//! street past both ends. Laid out as data from a def and a seed; the world
//! lays the streets as road and places what stands on each lot.

use std::collections::BTreeSet;

use glam::Vec2;

use crate::ground::tile_hash;
use crate::house::{HouseDef, bunker_offset, clothing, fixtures, heating, home_spots, house, kitchen, quarters_for, storage, wiring};
use crate::layout::{Brief, RoomPiece};
use crate::plan::PlanDef;
use crate::structure::StructureDef;
use crate::path::Cell;
use crate::walk::{cell_of, centre};

const TOWN_SALT: u64 = 0x70_3E_00;

/// How a town is laid out. Sizes are metres.
#[derive(Clone, Debug, PartialEq)]
pub struct TownDef {
    /// How many houses the town has (operator, 2026-11-23: "let's just
    /// start with 50 houses").
    pub houses: u32,
    /// A house lot: its width along its street, its depth back from it.
    pub lot: Vec2,
    /// A street's width.
    pub street: f32,
    /// Main street's lots on each side, and their size.
    pub main_lots: u32,
    pub main_lot: Vec2,
    /// How many cul-de-sacs, rolled in this range, and the houses on each
    /// side of one's street (one more stands at its end).
    pub cul_de_sacs: (u32, u32),
    pub cul_de_sac_lots: u32,
    /// The edge of town: lots on each side of main street at each end,
    /// and their size.
    pub edge_lots: u32,
    pub edge_lot: Vec2,
    /// The house every house lot stands.
    pub house: HouseDef,
    /// Who lives in the houses with no bunker: an actor def, and how many
    /// a house, fewest and most.
    pub residents: (String, (u32, u32)),
    /// The town's places, each standing on a lot of its part
    /// (topside-town "What the town has").
    pub places: Vec<PlanDef>,
    /// How many tiers the map has, and each kind of place's usual tier
    /// by its name ("house", a plan's name); one not named is tier 1
    /// (topside-town "Tiers").
    pub tiers: u32,
    pub usual_tiers: Vec<(String, u32)>,
    /// The room pieces places are laid out from, and each kind of place's
    /// brief by tier (`layout`; topside todo "Places rolled"). A house
    /// whose tier has a brief is laid out from the pieces, unless a
    /// bunker is under it; a house with none is `house`.
    pub pieces: Vec<RoomPiece>,
    pub briefs: Vec<Brief>,
    /// A house of this tier or above is boarded up and held by armed
    /// people (topside-town "Tiers": "if it's a tier 6 enemy house, maybe
    /// it's all boarded up... and there's people with guns inside"); none
    /// for a town with no such houses.
    pub boarded: Option<Boarded>,
    /// Every this many metres a lot stands out from the town's middle,
    /// its usual tier is one higher, so the town grows harder the farther
    /// out one goes (topside todo Tier 4, operator 2026-11-24: "my
    /// favorite, I think it was Icarus difficulty, right? It gets harder
    /// the closer you get to the sun"); 0 for none.
    pub tier_every: f32,
}

/// A boarded house: the least tier boarded, and who holds it, by actor
/// def.
#[derive(Clone, Debug, PartialEq)]
pub struct Boarded {
    pub tier: u32,
    pub who: String,
}

/// Which part of the town a lot or street is in.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum Part {
    MainStreet,
    Residential,
    CulDeSac,
    Edge,
}

/// One lot: where its middle is, its size (width along its street, depth
/// back from it), the way its front faces (toward its street, a unit
/// vector), and whether a house stands on it (a residential lot left over
/// is empty).
#[derive(Clone, Debug, PartialEq)]
pub struct Lot {
    pub part: Part,
    pub at: Vec2,
    pub size: Vec2,
    pub front: Vec2,
    pub house: bool,
}

impl Lot {
    /// Whether `p` is on the lot.
    pub fn covers(&self, p: Vec2) -> bool {
        let d = p - self.at;
        d.dot(self.front.perp()).abs() <= self.size.x / 2.0 && d.dot(self.front).abs() <= self.size.y / 2.0
    }
}

/// One straight street, from end to end, its width.
#[derive(Clone, Debug, PartialEq)]
pub struct Street {
    pub part: Part,
    pub from: Vec2,
    pub to: Vec2,
    pub width: f32,
}

/// A town laid out: its streets, the turning circles at its cul-de-sacs'
/// ends (a middle and a radius), its lots, and every tile its streets lie
/// on.
#[derive(Clone, Debug, PartialEq)]
pub struct Town {
    pub streets: Vec<Street>,
    pub turnarounds: Vec<(Vec2, f32)>,
    pub lots: Vec<Lot>,
    street_tiles: BTreeSet<Cell>,
    house: HouseDef,
    seed: u64,
    /// The house lots over a bunker, the first the home one.
    over: Vec<usize>,
    residents: (String, (u32, u32)),
    /// The places standing, each by its lot (`places`).
    places: Vec<(usize, PlanDef)>,
    tiers: u32,
    usual_tiers: Vec<(String, u32)>,
    pieces: Vec<RoomPiece>,
    briefs: Vec<Brief>,
    boarded: Option<Boarded>,
    tier_every: f32,
    /// A house lot's width and depth, so a laid out house stays on it.
    lot: Vec2,
}

impl Town {
    /// The town `def` lays out from `seed`, with `bunkers` of its houses
    /// over a bunker, placed so the first bunker, under the house nearest
    /// the town's middle, is at `home`. The same every time for a seed.
    pub fn around(def: &TownDef, home: Vec2, seed: u64, bunkers: u32) -> Self {
        let roll = |k: u64| tile_hash(seed, (0, 0), TOWN_SALT + k);
        let s = def.street;
        let (w, d) = (def.lot.x, def.lot.y);
        let k = def.cul_de_sac_lots;
        // Frontage slots a cul-de-sac takes off its street's outer side:
        // its own street and the depth of a lot either side.
        let slots = ((s + 2.0 * d) / w).ceil() as u32;
        let (lo, hi) = def.cul_de_sacs;
        let mut culs = lo + (roll(0) % u64::from(hi.saturating_sub(lo) + 1)) as u32;
        // Lots on each side of each residential street: four sides, less
        // the outer slots cul-de-sacs take, plus their houses.
        let per = |c: u32| {
            let wanted = i64::from(def.houses) - i64::from(c) * (2 * i64::from(k) + 1) + i64::from(c * slots);
            (wanted.max(4) as u32).div_ceil(4)
        };
        while culs > 0 && per(culs) < slots * culs.div_ceil(2) {
            culs -= 1;
        }
        let n = per(culs);
        let span = n as f32 * w;
        let mut lots = Vec::new();
        let mut streets = Vec::new();
        let mut turnarounds = Vec::new();
        let block = def.main_lot.y + d;
        let yr = s + block;
        let ends = span / 2.0 + s / 2.0;
        // Main street, running out past the cross streets through the edge
        // of town.
        let edge_run = def.edge_lots as f32 * def.edge_lot.x;
        streets.push(Street {
            part: Part::MainStreet,
            from: Vec2::new(-ends - s / 2.0 - edge_run, 0.0),
            to: Vec2::new(ends + s / 2.0 + edge_run, 0.0),
            width: s,
        });
        let m = def.main_lots.min((span / def.main_lot.x) as u32);
        for side in [1.0f32, -1.0] {
            for i in 0..m {
                let x = -(m as f32 * def.main_lot.x) / 2.0 + def.main_lot.x * (i as f32 + 0.5);
                lots.push(Lot {
                    part: Part::MainStreet,
                    at: Vec2::new(x, side * (s / 2.0 + def.main_lot.y / 2.0)),
                    size: def.main_lot,
                    front: Vec2::new(0.0, -side),
                    house: false,
                });
            }
            // The edge of town, at both ends.
            for end in [1.0f32, -1.0] {
                for i in 0..def.edge_lots {
                    let x = end * (ends + s / 2.0 + def.edge_lot.x * (i as f32 + 0.5));
                    lots.push(Lot {
                        part: Part::Edge,
                        at: Vec2::new(x, side * (s / 2.0 + def.edge_lot.y / 2.0)),
                        size: def.edge_lot,
                        front: Vec2::new(0.0, -side),
                        house: false,
                    });
                }
            }
        }
        // The residential streets, and the cross streets closing the blocks.
        for side in [1.0f32, -1.0] {
            streets.push(Street {
                part: Part::Residential,
                from: Vec2::new(-ends - s / 2.0, side * yr),
                to: Vec2::new(ends + s / 2.0, side * yr),
                width: s,
            });
        }
        for end in [1.0f32, -1.0] {
            streets.push(Street {
                part: Part::Residential,
                from: Vec2::new(end * ends, -yr),
                to: Vec2::new(end * ends, yr),
                width: s,
            });
        }
        // Cul-de-sacs, half on each residential street's outer side, each
        // in its own share of the street at a rolled slot.
        let mut taken: Vec<(f32, u32)> = Vec::new();
        for (j, side) in [1.0f32, -1.0].into_iter().enumerate() {
            let here = if j == 0 { culs.div_ceil(2) } else { culs / 2 };
            for c in 0..here {
                let share = n / here;
                let room = share.saturating_sub(slots);
                let first = c * share + (roll(1 + u64::from(c) * 2 + j as u64) % u64::from(room + 1)) as u32;
                taken.push((side, first));
                let x0 = -span / 2.0 + (first as f32 + slots as f32 / 2.0) * w;
                let base = side * (yr + s / 2.0);
                let top = base + side * k as f32 * w;
                streets.push(Street {
                    part: Part::CulDeSac,
                    from: Vec2::new(x0, side * yr),
                    to: Vec2::new(x0, top),
                    width: s,
                });
                turnarounds.push((Vec2::new(x0, top), s));
                for across in [1.0f32, -1.0] {
                    for i in 0..k {
                        lots.push(Lot {
                            part: Part::CulDeSac,
                            at: Vec2::new(x0 + across * (s / 2.0 + d / 2.0), base + side * w * (i as f32 + 0.5)),
                            size: Vec2::new(w, d),
                            front: Vec2::new(-across, 0.0),
                            house: true,
                        });
                    }
                }
                lots.push(Lot {
                    part: Part::CulDeSac,
                    at: Vec2::new(x0, top + side * (s + d / 2.0)),
                    size: Vec2::new(w, d),
                    front: Vec2::new(0.0, -side),
                    house: true,
                });
            }
        }
        // The houses along the residential streets, both sides, but where
        // a cul-de-sac takes the outer side.
        for side in [1.0f32, -1.0] {
            for outer in [false, true] {
                let y = side * (yr + if outer { 1.0 } else { -1.0 } * (s / 2.0 + d / 2.0));
                for i in 0..n {
                    if outer && taken.iter().any(|(sd, first)| *sd == side && (*first..*first + slots).contains(&i)) {
                        continue;
                    }
                    lots.push(Lot {
                        part: Part::Residential,
                        at: Vec2::new(-span / 2.0 + w * (i as f32 + 0.5), y),
                        size: Vec2::new(w, d),
                        front: Vec2::new(0.0, if outer { -side } else { side }),
                        house: true,
                    });
                }
            }
        }
        // More house lots than houses: the rolled few left over stand
        // empty (a cul-de-sac's are always built).
        let mut spare: Vec<(u64, usize)> = lots
            .iter()
            .enumerate()
            .filter(|(_, l)| l.part == Part::Residential)
            .map(|(i, _)| (roll(100 + i as u64), i))
            .collect();
        spare.sort();
        let built = lots.iter().filter(|l| l.house).count();
        for (_, i) in spare.into_iter().take(built.saturating_sub(def.houses as usize)) {
            lots[i].house = false;
        }
        // Turned a rolled quarter, then placed around home.
        let turns = roll(99) % 4;
        let turn = |p: Vec2| (0..turns).fold(p, |p, _| Vec2::new(-p.y, p.x));
        for l in &mut lots {
            l.at = turn(l.at);
            l.front = turn(l.front);
        }
        for st in &mut streets {
            st.from = turn(st.from);
            st.to = turn(st.to);
        }
        for t in &mut turnarounds {
            t.0 = turn(t.0);
        }
        // The bunkers (topside-town "The bunkers"): `bunkers` of the
        // houses stand over one, the first the house nearest the middle.
        // A bunker is never turned, so only a house facing +y (its plan
        // unturned) stands over one; with none, any house.
        let facing: Vec<usize> = {
            let up: Vec<usize> = (0..lots.len()).filter(|&i| lots[i].house && lots[i].front == Vec2::Y).collect();
            if up.is_empty() { (0..lots.len()).filter(|&i| lots[i].house).collect() } else { up }
        };
        let mut over: Vec<usize> = Vec::new();
        if let Some(&first) = facing.iter().min_by(|&&a, &&b| lots[a].at.length().total_cmp(&lots[b].at.length())) {
            over.push(first);
            let mut rest: Vec<(u64, usize)> = facing
                .iter()
                .filter(|&&i| i != first)
                .map(|&i| (roll(200 + i as u64), i))
                .collect();
            rest.sort();
            over.extend(rest.into_iter().take(bunkers.saturating_sub(1) as usize).map(|(_, i)| i));
        }
        let middle = over.first().map_or(Vec2::ZERO, |&i| lots[i].at + bunker_offset());
        let shift = (home - middle).round();
        for l in &mut lots {
            l.at += shift;
        }
        for st in &mut streets {
            st.from += shift;
            st.to += shift;
        }
        for t in &mut turnarounds {
            t.0 += shift;
        }
        let mut town = Self {
            streets,
            turnarounds,
            lots,
            street_tiles: BTreeSet::new(),
            house: def.house.clone(),
            seed,
            over,
            residents: def.residents.clone(),
            places: Vec::new(),
            tiers: def.tiers,
            usual_tiers: def.usual_tiers.clone(),
            pieces: def.pieces.clone(),
            briefs: def.briefs.clone(),
            boarded: def.boarded.clone(),
            tier_every: def.tier_every,
            lot: def.lot,
        };
        town.street_tiles = town.lay_streets();
        // Each place on the next free lot of its part: main street's from
        // the middle out, the edge's from main street out.
        let mut free: Vec<usize> = (0..town.lots.len()).filter(|&i| !town.lots[i].house).collect();
        free.sort_by(|&a, &b| town.lots[a].at.x.abs().total_cmp(&town.lots[b].at.x.abs()).then(a.cmp(&b)));
        for plan in &def.places {
            let part = if plan.edge { Part::Edge } else { Part::MainStreet };
            if let Some(k) = free.iter().position(|&i| town.lots[i].part == part) {
                town.places.push((free.remove(k), plan.clone()));
            }
        }
        town
    }

    /// The same town with its places moved about `times` times (topside
    /// todo "Storm effect 2", the shuffle storm: the same town, the map
    /// wrong): each time, the places of one part (main street's, the
    /// edge's) trade lots among themselves, rolled from the town's seed.
    /// The houses and the bunkers under them stay.
    pub fn shuffled(mut self, times: u32) -> Self {
        for time in 0..times {
            for part in [Part::MainStreet, Part::Edge] {
                let mut lots: Vec<usize> = self.places.iter().map(|(lot, _)| *lot).filter(|&i| self.lots[i].part == part).collect();
                // Fisher-Yates, each pick rolled from the seed and the time.
                for k in (1..lots.len()).rev() {
                    let j = (tile_hash(self.seed, (k as i32, time as i32), TOWN_SALT + 0x5A) % (k as u64 + 1)) as usize;
                    lots.swap(k, j);
                }
                let mut next = lots.into_iter();
                for (lot, _) in self.places.iter_mut().filter(|(lot, _)| self.lots[*lot].part == part) {
                    if let Some(to) = next.next() {
                        *lot = to;
                    }
                }
            }
        }
        self
    }

    /// The places standing in the town (topside-town "What the town
    /// has"), each by its lot.
    pub fn places(&self) -> &[(usize, PlanDef)] {
        &self.places
    }

    /// The place standing on lot `i`, if one does.
    pub fn place_on(&self, i: usize) -> Option<StructureDef> {
        let (_, plan) = self.places.iter().find(|(lot, _)| *lot == i)?;
        let seed = tile_hash(self.seed, (i as i32, 1), TOWN_SALT + 0x41);
        Some(crate::plan::build(plan, self.lots[i].front, seed))
    }

    /// The tier of what stands on lot `i` (topside-town "Tiers"), rolled
    /// once from its kind's usual tier: the same every time for a seed,
    /// and another in another world.
    pub fn tier_of(&self, i: usize) -> u32 {
        let name = if self.lots[i].house { "house" } else { self.places.iter().find(|(lot, _)| *lot == i).map_or("", |(_, p)| p.name.as_str()) };
        let usual = self.usual_tiers.iter().find(|(n, _)| n == name).map_or(1, |(_, t)| *t);
        let out = if self.tier_every > 0.0 { (self.lots[i].at.length() / self.tier_every) as u32 } else { 0 };
        crate::tier::roll(usual + out, self.tiers, tile_hash(self.seed, (i as i32, 2), TOWN_SALT + 0x71))
    }

    /// Who holds the house on lot `i` when it is boarded up (`boarded`):
    /// a house at or above the boarded tier, not over a bunker.
    pub fn boarded_by(&self, i: usize) -> Option<&str> {
        let b = self.boarded.as_ref()?;
        (self.lots[i].house && !self.over.contains(&i) && self.tier_of(i) >= b.tier).then_some(b.who.as_str())
    }

    /// The modifiers on what stands on lot `i` (topside-town "Tiers":
    /// "per building, per monument, per area"): its own, one building in
    /// six, and its area's, one part of the town in four (the parts:
    /// main street, the residential streets, the cul-de-sacs, the edge),
    /// so a whole area can be guarded. The odds are Claude's.
    pub fn modifiers_of(&self, i: usize) -> Vec<crate::tier::Modifier> {
        let part = self.lots[i].part as i32;
        let own = crate::tier::modifier(tile_hash(self.seed, (i as i32, 3), TOWN_SALT + 0x72), 6);
        let area = crate::tier::modifier(tile_hash(self.seed, (part, 4), TOWN_SALT + 0x73), 4);
        own.into_iter().chain(area).collect()
    }

    /// Where every place's things stand, each with its place's name.
    /// The laid out houses' things (`layout`), from their pieces, are
    /// among them, by the name "house".
    pub fn place_things(&self) -> Vec<(&str, String, Vec2)> {
        let places = self.places.iter().flat_map(|(i, plan)| {
            let lot = &self.lots[*i];
            crate::plan::things_of(plan, lot.front).into_iter().map(move |(thing, at)| (plan.name.as_str(), thing.to_string(), lot.at + at))
        });
        let houses = (0..self.lots.len()).filter_map(|i| self.rolled(i).map(|plan| (i, plan))).flat_map(|(i, plan)| {
            let lot = &self.lots[i];
            crate::plan::things_of(&plan, lot.front).into_iter().map(|(thing, at)| ("house", thing.to_string(), lot.at + at)).collect::<Vec<_>>()
        });
        places.chain(houses).collect()
    }

    /// Every tile whose middle lies on a street or a turning circle.
    fn lay_streets(&self) -> BTreeSet<Cell> {
        let mut out = BTreeSet::new();
        for st in &self.streets {
            let half = st.width / 2.0;
            let (lo, hi) = (cell_of(st.from.min(st.to) - half), cell_of(st.from.max(st.to) + half));
            for y in lo.1..=hi.1 {
                for x in lo.0..=hi.0 {
                    let p = centre((x, y));
                    let along = st.to - st.from;
                    let t = ((p - st.from).dot(along) / along.length_squared().max(f32::EPSILON)).clamp(0.0, 1.0);
                    if (st.from + along * t).distance(p) <= half {
                        out.insert((x, y));
                    }
                }
            }
        }
        for (at, radius) in &self.turnarounds {
            let (lo, hi) = (cell_of(*at - *radius), cell_of(*at + *radius));
            for y in lo.1..=hi.1 {
                for x in lo.0..=hi.0 {
                    if centre((x, y)).distance(*at) <= *radius {
                        out.insert((x, y));
                    }
                }
            }
        }
        out
    }

    /// Whether a street lies on tile `t`.
    pub fn is_street(&self, t: Cell) -> bool {
        self.street_tiles.contains(&t)
    }

    /// Whether `p` is in the town: on a street or a lot.
    pub fn covers(&self, p: Vec2) -> bool {
        self.is_street(cell_of(p)) || self.lots.iter().any(|l| l.covers(p))
    }

    /// The houses' lots.
    pub fn houses(&self) -> impl Iterator<Item = &Lot> {
        self.lots.iter().filter(|l| l.house)
    }

    /// The brief the house on lot `i` is laid out from: the house brief of
    /// the highest tier at or below its own, none over a bunker (the
    /// bunker's top room stands in the fixed house's garage).
    fn brief_for(&self, i: usize) -> Option<&Brief> {
        if !self.lots[i].house || self.over.contains(&i) {
            return None;
        }
        let tier = self.tier_of(i);
        self.briefs.iter().filter(|b| b.place == "house" && b.tier <= tier).max_by_key(|b| b.tier)
    }

    /// The house on lot `i` laid out from the pieces, if it is (`layout`):
    /// the same every time for a seed and a lot, another on another lot.
    pub fn rolled(&self, i: usize) -> Option<PlanDef> {
        // Kept a few metres in from the lot's sides and back (Claude's).
        let mut brief = self.brief_for(i)?.clone();
        brief.lot = brief.lot.or(Some([self.lot.x - 2.0, self.lot.y - 4.0]));
        Some(crate::layout::roll(&brief, &self.pieces, tile_hash(self.seed, (i as i32, 5), TOWN_SALT + 0x42)))
    }

    /// Whether lot `i` holds the fixed house (`house`), whose furniture,
    /// fixtures and wiring stand where `house` says.
    fn fixed(&self, i: usize) -> bool {
        self.lots[i].house && self.brief_for(i).is_none()
    }

    /// The lots holding the fixed house, with their index.
    pub fn fixed_houses(&self) -> impl Iterator<Item = (usize, &Lot)> {
        self.lots.iter().enumerate().filter(|(i, _)| self.fixed(*i))
    }

    /// Where the people living on lot `i` stand when it is made, from the
    /// lot's middle: the fixed house's bedrooms and living room, else
    /// the laid out house's (any room when it has none of those).
    pub fn home_spots(&self, i: usize) -> Vec<Vec2> {
        let front = self.lots[i].front;
        let Some(plan) = self.rolled(i) else {
            return home_spots(front);
        };
        let rooms = crate::plan::room_spots(&plan, front);
        let homely: Vec<Vec2> = rooms.iter().filter(|(name, _)| name.starts_with("bedroom") || name.starts_with("living room")).map(|(_, p)| *p).collect();
        if homely.is_empty() { rooms.into_iter().map(|(_, p)| p).collect() } else { homely }
    }

    /// The house standing on lot `i`, facing its street, its middle at
    /// the lot's: the same every time for a seed and a lot.
    pub fn house_on(&self, i: usize) -> StructureDef {
        let seed = tile_hash(self.seed, (i as i32, 0), TOWN_SALT + 0x40);
        match self.rolled(i) {
            Some(plan) => crate::plan::build(&plan, self.lots[i].front, seed),
            None => house(&self.house, self.lots[i].front, seed, self.over.contains(&i)),
        }
    }

    /// Where each bunker is, under its house's garage, the home one first.
    pub fn bunkers(&self) -> Vec<Vec2> {
        let turn = |l: &Lot| {
            // The offset is for a house facing +y; turned as its house is.
            (0..quarters_for(l.front)).fold(bunker_offset(), |p, _| Vec2::new(-p.y, p.x))
        };
        self.over.iter().map(|&i| self.lots[i].at + turn(&self.lots[i])).collect()
    }

    /// Every house's water fixtures (`house::fixtures`): each its kind and
    /// where it stands.
    pub fn fixtures(&self) -> Vec<(&'static str, Vec2)> {
        self.fixed_houses()
            .map(|(_, l)| l)
            .flat_map(|l| fixtures(l.front).into_iter().map(move |(kind, at)| (kind, l.at + at)))
            .collect()
    }

    /// Every house's wiring (`house::wiring`): its breaker box, and each
    /// room's switch with its light, where they stand.
    pub fn wiring(&self) -> Vec<(Vec2, Vec<(Vec2, Vec2)>)> {
        self.fixed_houses()
            .map(|(i, l)| {
                let (breaker, rooms) = wiring(l.front, self.over.contains(&i));
                (l.at + breaker, rooms.into_iter().map(|(s, light)| (l.at + s, l.at + light)).collect())
            })
            .collect()
    }

    /// Every house's heating and cooling (`house::heating`), in the same
    /// order as `wiring`, each its kind and where it stands.
    pub fn heating(&self) -> Vec<Vec<(&'static str, Vec2)>> {
        self.fixed_houses()
            .map(|(_, l)| heating(l.front).into_iter().map(|(kind, at)| (kind, l.at + at)).collect())
            .collect()
    }

    /// Every house's kitchen (`house::kitchen`), in the same order as
    /// `wiring`, each its kind and where it stands.
    pub fn kitchens(&self) -> Vec<Vec<(&'static str, Vec2)>> {
        self.fixed_houses()
            .map(|(_, l)| kitchen(l.front).into_iter().map(|(kind, at)| (kind, l.at + at)).collect())
            .collect()
    }

    /// Every house's clothing (`house::clothing`), in the same order as
    /// `wiring`, each its kind and where it stands.
    pub fn clothing(&self) -> Vec<Vec<(&'static str, Vec2)>> {
        self.fixed_houses()
            .map(|(_, l)| clothing(l.front).into_iter().map(|(kind, at)| (kind, l.at + at)).collect())
            .collect()
    }

    /// Every house's storage (`house::storage`), in the same order as
    /// `wiring`, each its kind and where it stands.
    pub fn storage(&self) -> Vec<Vec<(&'static str, Vec2)>> {
        self.fixed_houses()
            .map(|(i, l)| storage(l.front, self.over.contains(&i)).into_iter().map(|(kind, at)| (kind, l.at + at)).collect())
            .collect()
    }

    /// Where the streetlights stand (topside-town "Everything works"):
    /// along every street, at its edge, one each `apart` metres.
    pub fn streetlights(&self, apart: f32) -> Vec<Vec2> {
        self.streets
            .iter()
            .flat_map(|s| {
                let length = s.from.distance(s.to);
                let along = (s.to - s.from).normalize_or_zero();
                let edge = along.perp() * (s.width / 2.0);
                (0..=(length / apart) as u32).map(move |k| s.from + along * (k as f32 * apart) + edge)
            })
            .collect()
    }

    /// Where the substation stands: the town's south east corner, until it
    /// is a building of its own (Claude's).
    pub fn substation(&self) -> Vec2 {
        self.bounds().1
    }

    /// Where the water tower stands: the town's north west corner, until
    /// the tower is a building of its own (Claude's).
    pub fn water_tower(&self) -> Vec2 {
        self.bounds().0
    }

    /// The people living in the town (topside-town "The houses": up to 4
    /// a house, in the houses with no bunker): each house's count rolled
    /// from the def's range, each person standing in a room of their
    /// house. Who each is and how many are rolled per house from its
    /// brief's people (`Brief::person`), else the town's residents. The same
    /// every time for a seed.
    pub fn residents(&self) -> Vec<(String, Vec2)> {
        let mut out = Vec::new();
        for (i, lot) in self.lots.iter().enumerate() {
            if !lot.house || self.over.contains(&i) {
                continue;
            }
            let brief = self.brief_for(i);
            let (lo, hi) = brief.and_then(|b| b.living).unwrap_or(self.residents.1);
            let count = lo + (tile_hash(self.seed, (i as i32, 1), TOWN_SALT + 0x50) % u64::from(hi.saturating_sub(lo) + 1)) as u32;
            let spots = self.home_spots(i);
            let seed = tile_hash(self.seed, (i as i32, 2), TOWN_SALT + 0x51);
            for k in 0..count as usize {
                if let Some(spot) = spots.get(k % spots.len().max(1)) {
                    // Two in a room stand a metre apart.
                    let apart = Vec2::new((k / spots.len().max(1)) as f32, 0.0);
                    let who = brief.and_then(|b| b.person(seed, k as u64)).unwrap_or(&self.residents.0);
                    out.push((who.to_string(), lot.at + *spot + apart));
                }
            }
        }
        out
    }

    /// The square the town lies in, its lowest corner and its highest.
    pub fn bounds(&self) -> (Vec2, Vec2) {
        let lots = self.lots.iter().flat_map(|l| {
            let half = l.size.length() / 2.0;
            [l.at - half, l.at + half]
        });
        let streets = self
            .streets
            .iter()
            .flat_map(|s| [s.from - s.width / 2.0, s.from + s.width / 2.0, s.to - s.width / 2.0, s.to + s.width / 2.0]);
        lots.chain(streets)
            .fold((Vec2::splat(f32::MAX), Vec2::splat(f32::MIN)), |(lo, hi), p| (lo.min(p), hi.max(p)))
    }
}
