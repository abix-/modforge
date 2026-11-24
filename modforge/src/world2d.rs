//! A 2D world, the Factorio way (topside design.md "2D world
//! generation"): flat ground made chunk by chunk from the seed
//! (`ground`), sites placed region by region (`places`), the bunkers on
//! cleared ground, and roads on the tiles between places people used.
//! Every chunk is decided from the seed and what stands near it, so any
//! chunk can be made in any order, and the world can be any size.

use std::collections::HashMap;

use glam::{Vec2, Vec3};

use crate::biome::BiomeRegistry;
use crate::ground::{Ground, GroundChunk, GroundGen, tile_hash};
use crate::monument::{BuildingRegistry, MonumentRegistry};
use crate::path::{Cell, search};
use crate::places::{Makers, Place, Places};
use crate::memory::GoodFor;
use crate::structure::{MonumentDef, MonumentMember};
use crate::town::Town;
use crate::walk::{CHUNK, ChunkKey, TILE, cell_of, centre};

/// How far a site with buildings looks for the site its road leads to.
pub const ROAD_REACH: f32 = 600.0;
/// Tiles either side of a road's middle.
const ROAD_HALF_WIDTH: i32 = 1;
/// Tiles a road search may look at before giving up.
const ROAD_LIMIT: usize = 200_000;

/// A bunker's ground: where, and how far round it is cleared.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Clearing {
    pub at: Vec2,
    pub radius: f32,
    /// A gap kept clear of things from the clearing toward a point, so the
    /// door opens on the big thing on the horizon (topside design.md "The
    /// first hour": "The way is readable (a gap, a track, a gate)"): the
    /// point it heads for, how far it runs and how wide it is, metres.
    pub gap: Option<(Vec2, f32, f32)>,
}

impl Clearing {
    /// Whether a thing at `p` is kept out: in the clearing or in its gap.
    pub fn clears(&self, p: Vec2) -> bool {
        if self.at.distance(p) < self.radius {
            return true;
        }
        let Some((toward, length, width)) = self.gap else {
            return false;
        };
        let way = (toward - self.at).normalize_or_zero();
        let along = (p - self.at).dot(way);
        (0.0..=length).contains(&along) && (p - self.at - way * along).length() < width / 2.0
    }
}

/// The registries a world reads when it makes chunks and sites.
#[derive(Clone, Copy)]
pub struct Registries<'a> {
    pub biomes: &'a BiomeRegistry,
    pub monuments: &'a MonumentRegistry,
    pub buildings: &'a BuildingRegistry,
}

/// One world: its ground, its sites, its bunkers, its roads.
pub struct World2d {
    pub ground: GroundGen,
    pub places: Places,
    pub bunkers: Vec<Clearing>,
    /// Each road found once, by the positions of the two sites it joins.
    roads: HashMap<(Cell, Cell), Option<Vec<Cell>>>,
    /// Topside people world generation places on open land: an actor def
    /// and how many (topside design.md "The small world first").
    people: Vec<(String, u32)>,
    people_spots: Option<Vec<(String, Vec2)>>,
    /// The planned town, if the world has one (topside-town).
    pub town: Option<Town>,
}

/// Tries at a spot for one topside person before they are left out.
const PEOPLE_TRIES: u64 = 64;

/// The most secrets a world rolls (operator, 2026-08-21: 0 to 5).
pub const SECRETS_MOST: u64 = 5;
/// How far a secret keeps from every road, site and bunker clearing,
/// metres (Claude's, for the operator to change).
pub const SECRET_OFF: f32 = 40.0;
/// Tries at a spot for one secret before it is left out.
const SECRET_TRIES: u64 = 64;
const SECRETS_SALT: u64 = 0x5EC2_E700;

impl World2d {
    pub fn new(ground: GroundGen, places: Places, bunkers: Vec<Clearing>) -> Self {
        Self {
            ground,
            places,
            bunkers,
            roads: HashMap::new(),
            people: Vec::new(),
            people_spots: None,
            town: None,
        }
    }

    /// This town as well: its streets laid as road, its streets and lots
    /// cleared of water and of what grows or lies there.
    pub fn with_town(mut self, town: Town) -> Self {
        self.town = Some(town);
        self
    }

    /// These topside people as well, placed on open land inside the
    /// world's edge. A world with no edge places none this way.
    pub fn with_people(mut self, people: Vec<(String, u32)>) -> Self {
        self.people = people;
        self
    }

    /// Where each topside person stands, by actor def: the town's people in
    /// their houses (`Town::residents`), then each of the rest on a tile rolled from
    /// the seed anywhere inside the edge, taken only if it is land with
    /// nothing on it, off every site's ground and every bunker's clearing.
    /// The same every time for a seed.
    pub fn topside_people(&mut self, r: Registries) -> Vec<(String, Vec2)> {
        if let Some(found) = &self.people_spots {
            return found.clone();
        }
        // The town's people, in their houses.
        let mut out = self.town.as_ref().map(Town::residents).unwrap_or_default();
        if let Some((lo, hi)) = self.ground.chunk_range() {
            let (lo, span) = (lo * CHUNK, (hi - lo) * CHUNK);
            for (i, (def, count)) in self.people.clone().into_iter().enumerate() {
                for k in 0..count {
                    for a in 0..PEOPLE_TRIES {
                        let h = tile_hash(self.ground.seed, (i as i32, k as i32), 0x5EED_0000 + a);
                        let t = (
                            lo + (h % span as u64) as i32,
                            lo + ((h >> 32) % span as u64) as i32,
                        );
                        let at = centre(t);
                        let key = (t.0.div_euclid(CHUNK), t.1.div_euclid(CHUNK));
                        let chunk = self.chunk(r, key);
                        let open = chunk.ground_at(t).is_land()
                            && !chunk.things.iter().any(|thing| thing.tile == t);
                        let clear = !self.bunkers.iter().any(|c| c.at.distance(at) < c.radius)
                            && self.sites_touching(r, at, at).is_empty()
                            && !self.town.as_ref().is_some_and(|t| t.lots.iter().any(|l| l.covers(at)));
                        if open && clear {
                            out.push((def.clone(), at));
                            break;
                        }
                    }
                }
            }
        }
        self.people_spots = Some(out.clone());
        out
    }

    /// Where this world's secrets are (topside design.md "The unknown" rule
    /// 7: "every map should have the possibility to have 0-5 secrets"): 0
    /// to `SECRETS_MOST` rolled from the seed, each a land tile in the
    /// chunks from `lo` to `hi` (chunk keys, both ways) taken only if no
    /// road, site or bunker clearing comes within `SECRET_OFF` of it. A
    /// secret with no such tile in its tries is left out. The same every
    /// time for a seed.
    pub fn secrets(&mut self, r: Registries, (lo, hi): (i32, i32)) -> Vec<Vec2> {
        let seed = self.ground.seed;
        let count = tile_hash(seed, (0, 0), SECRETS_SALT) % (SECRETS_MOST + 1);
        let (lo, span) = (lo * CHUNK, ((hi - lo) * CHUNK).max(1));
        let off = (SECRET_OFF / TILE).ceil() as i32;
        let mut out = Vec::new();
        for k in 0..count as i32 {
            for a in 0..SECRET_TRIES {
                let h = tile_hash(seed, (k, 0), SECRETS_SALT + 1 + a);
                let t = (lo + (h % span as u64) as i32, lo + ((h >> 32) % span as u64) as i32);
                let at = centre(t);
                let chunk = self.chunk(r, (t.0.div_euclid(CHUNK), t.1.div_euclid(CHUNK)));
                let land = chunk.ground_at(t).is_land() && chunk.ground_at(t) != Ground::Road;
                let clear = land
                    && !self.bunkers.iter().any(|c| c.at.distance(at) < c.radius + SECRET_OFF)
                    && self.sites_touching(r, at - SECRET_OFF, at + SECRET_OFF).is_empty()
                    && self.road_tiles(r, (t.0 - off, t.1 - off), (t.0 + off, t.1 + off)).is_empty();
                if clear {
                    out.push(at);
                    break;
                }
            }
        }
        out
    }

    fn makers<'a>(ground: &'a GroundGen, r: Registries<'a>) -> Makers<'a> {
        Makers {
            ground,
            biomes: r.biomes,
            monuments: r.monuments,
            buildings: r.buildings,
        }
    }

    /// Every site standing in the square from `lo` to `hi`: the places,
    /// and the town's houses (topside-town "The houses"), each a site of
    /// one building, the house, on its lot.
    pub fn sites_in(&mut self, r: Registries, lo: Vec2, hi: Vec2) -> Vec<Place> {
        let mut out = self.places.in_area(Self::makers(&self.ground, r), lo, hi);
        out.extend(self.houses_in(lo, hi));
        out
    }

    /// The town's houses standing in the square from `lo` to `hi`.
    fn houses_in(&self, lo: Vec2, hi: Vec2) -> Vec<Place> {
        let Some(town) = &self.town else {
            return Vec::new();
        };
        town.lots
            .iter()
            .enumerate()
            .filter(|(_, l)| l.at.cmpge(lo).all() && l.at.cmplt(hi).all())
            // A house, or a place of the town (plan.rs) on its lot.
            .filter_map(|(i, l)| {
                let structure = if l.house { town.house_on(i) } else { town.place_on(i)? };
                Some((l, structure))
            })
            .map(|(l, structure)| Place {
                monument: structure.name.clone(),
                position: l.at.round(),
                biome: String::new(),
                rolled: MonumentDef {
                    name: structure.name.clone(),
                    kind: structure.name.clone(),
                    members: vec![MonumentMember {
                        structure,
                        offset: Vec3::ZERO,
                    }],
                    loot_spots: Vec::new(),
                    npc_spots: Vec::new(),
                    gates: Vec::new(),
                    props: Vec::new(),
                    good_for: GoodFor::default(),
                },
                ground: l.size.length() / 2.0,
            })
            .collect()
    }

    /// The sites whose ground reaches into the square from `lo` to `hi`.
    pub fn sites_touching(&mut self, r: Registries, lo: Vec2, hi: Vec2) -> Vec<Place> {
        let m = Self::makers(&self.ground, r);
        let widest = self.places.widest(m);
        self.places
            .in_area(m, lo - widest, hi + widest)
            .into_iter()
            .filter(|p| p.position.clamp(lo, hi).distance(p.position) < p.ground)
            .collect()
    }

    /// The road from a site with buildings to the nearest site with
    /// buildings nearer the world's middle, within `ROAD_REACH` (a tree of
    /// roads between places people used; none leads to the bunker). None
    /// when there is no such site or no way for a road. Found once.
    fn road_from(&mut self, r: Registries, site: &Place) -> Option<Vec<Cell>> {
        let m = Self::makers(&self.ground, r);
        let around = self
            .places
            .in_area(m, site.position - ROAD_REACH, site.position + ROAD_REACH);
        let to = around
            .iter()
            .filter(|p| {
                !p.rolled.members.is_empty() && p.position.length() < site.position.length()
            })
            .filter(|p| p.position.distance(site.position) <= ROAD_REACH)
            .min_by(|a, b| {
                a.position
                    .distance(site.position)
                    .total_cmp(&b.position.distance(site.position))
            })?
            .clone();
        let key = (cell_of(site.position), cell_of(to.position));
        if let Some(found) = self.roads.get(&key) {
            return found.clone();
        }
        // Keep off every other site's ground on the way.
        let others: Vec<(Vec2, f32)> = around
            .iter()
            .filter(|p| p.position != site.position && p.position != to.position)
            .map(|p| (p.position, p.ground))
            .collect();
        let (start, goal) = key;
        let ground = &self.ground;
        let open = |t: Cell| {
            ground.ground_at(t).is_land()
                && !others.iter().any(|(c, rad)| c.distance(centre(t)) < *rad)
        };
        let next = |at: Cell| -> Vec<(Cell, f32)> {
            [
                (1, 0),
                (-1, 0),
                (0, 1),
                (0, -1),
                (1, 1),
                (1, -1),
                (-1, 1),
                (-1, -1),
            ]
            .into_iter()
            .map(|(dx, dy)| (at.0 + dx, at.1 + dy))
            .filter(|t| *t == goal || open(*t))
            .map(|t| {
                (
                    t,
                    if t.0 != at.0 && t.1 != at.1 {
                        std::f32::consts::SQRT_2
                    } else {
                        1.0
                    },
                )
            })
            .collect()
        };
        let estimate = |t: Cell| centre(t).distance(centre(goal)) / TILE;
        let found =
            search(start, next, estimate, |t| t == goal, ROAD_LIMIT).map(|(tiles, _)| tiles);
        self.roads.insert(key, found.clone());
        found
    }

    /// Every road tile in the square from `lo` to `hi` (inclusive tiles).
    fn road_tiles(&mut self, r: Registries, lo: Cell, hi: Cell) -> Vec<Cell> {
        let (a, b) = (centre(lo), centre(hi));
        // The places only: the town's houses are on its streets.
        let sites: Vec<Place> = self
            .places
            .in_area(Self::makers(&self.ground, r), a - ROAD_REACH, b + ROAD_REACH)
            .into_iter()
            .filter(|p| !p.rolled.members.is_empty())
            .collect();
        let mut out = Vec::new();
        for site in &sites {
            let Some(road) = self.road_from(r, site) else {
                continue;
            };
            for t in road {
                for dy in -ROAD_HALF_WIDTH..=ROAD_HALF_WIDTH {
                    for dx in -ROAD_HALF_WIDTH..=ROAD_HALF_WIDTH {
                        let w = (t.0 + dx, t.1 + dy);
                        if w.0 >= lo.0 && w.0 <= hi.0 && w.1 >= lo.1 && w.1 <= hi.1 {
                            out.push(w);
                        }
                    }
                }
            }
        }
        out
    }

    /// One chunk of the world: the ground chunk, with the bunkers'
    /// clearings on land and bare, nothing growing or lying on a site's
    /// ground, and the roads laid on land off the sites' ground.
    pub fn chunk(&mut self, r: Registries, key: ChunkKey) -> GroundChunk {
        let mut chunk = self.ground.chunk(key, r.biomes);
        let first = chunk.first();
        let last = (first.0 + CHUNK - 1, first.1 + CHUNK - 1);
        let lo = Vec2::new(first.0 as f32, first.1 as f32) * TILE;
        let hi = lo + Vec2::splat(CHUNK as f32 * TILE);
        let index = |t: Cell| ((t.1 - first.1) * CHUNK + (t.0 - first.0)) as usize;
        let sites = self.sites_touching(r, lo, hi);
        let on_site = |t: Cell| {
            sites
                .iter()
                .any(|s| s.position.distance(centre(t)) < s.ground)
        };
        for t in self.road_tiles(r, first, last) {
            if chunk.ground[index(t)].is_land() && !on_site(t) {
                chunk.ground[index(t)] = Ground::Road;
            }
        }
        // A site's ground is cleared (topside design.md "2D world
        // generation"): a river or a lake under it is dry land.
        for y in 0..CHUNK {
            for x in 0..CHUNK {
                let t = (first.0 + x, first.1 + y);
                if chunk.ground[index(t)] == Ground::Water && on_site(t) {
                    chunk.ground[index(t)] = Ground::Dirt;
                }
            }
        }
        // A bunker stands on land (topside design.md "A valid world"): water
        // or cliff in its clearing is grass; every other tile keeps its own
        // ground, so the clearing is no circle of dirt.
        for c in &self.bunkers {
            for y in 0..CHUNK {
                for x in 0..CHUNK {
                    let t = (first.0 + x, first.1 + y);
                    let g = &mut chunk.ground[index(t)];
                    if centre(t).distance(c.at) < c.radius
                        && matches!(g, Ground::Water | Ground::Cliff)
                    {
                        *g = Ground::Grass;
                    }
                }
            }
        }
        // The town's streets are road, on any ground; a river or a lake
        // under the town is dry land.
        if let Some(town) = &self.town {
            for y in 0..CHUNK {
                for x in 0..CHUNK {
                    let t = (first.0 + x, first.1 + y);
                    let g = &mut chunk.ground[index(t)];
                    if town.is_street(t) {
                        *g = Ground::Road;
                    } else if matches!(g, Ground::Water | Ground::Cliff) && town.covers(centre(t)) {
                        *g = Ground::Grass;
                    }
                }
            }
        }
        let bunkers = &self.bunkers;
        let town = &self.town;
        let ground = chunk.ground.clone();
        chunk.things.retain(|thing| {
            let at = centre(thing.tile);
            !on_site(thing.tile)
                && !bunkers.iter().any(|c| c.clears(at))
                && ground[index(thing.tile)] != Ground::Road
                && !town.as_ref().is_some_and(|t| t.covers(at))
        });
        chunk
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::biome::{BiomeDef, ScatterDef};
    use crate::ground::{ClimateRule, GroundDef};
    use crate::monument::{
        Arrangement, BuildingSize, BuildingSlot, BuildingTypeDef, MonumentTypeDef,
    };
    use crate::places::SiteKind;

    fn registries() -> (BiomeRegistry, MonumentRegistry, BuildingRegistry) {
        let mut biomes = BiomeRegistry::default();
        biomes
            .register(BiomeDef {
                name: "plain".to_string(),
                ground: [0.3, 0.4, 0.2],
                scatter: vec![ScatterDef {
                    size: glam::Vec3::new(1.0, 3.0, 1.0),
                    color: [0.2, 0.4, 0.2],
                    density: 2.0,
                    picture: None,
                    source: None,
                }],
                weather: vec![],
                monuments: vec!["stop".to_string()],
                npcs: vec![],
                wildlife: vec![],
                harvest: vec![],
            })
            .unwrap();
        let mut buildings = BuildingRegistry::default();
        buildings
            .register(BuildingTypeDef {
                name: "shed".to_string(),
                size: BuildingSize::Small,
                columns: (1, 1),
                rows: (1, 1),
                floors: (1, 1),
                basements: (0, 0),
                width: (4.0, 5.0),
                length: (4.0, 5.0),
                height: (2.6, 3.0),
                windows: 0,
                clutter: 0,
                lights: 0,
                damage: 0,
                carve: 0,
                palette: vec![[0.5, 0.5, 0.5]],
            })
            .unwrap();
        let mut monuments = MonumentRegistry::default();
        monuments
            .register(
                MonumentTypeDef {
                    name: "stop".to_string(),
                    slots: vec![BuildingSlot {
                        choices: vec!["shed".to_string()],
                        min: 1,
                        max: 1,
                    }],
                    arrangement: Arrangement::Clustered,
                    danger: 1,
                    gated: false,
                    suffix: "stop".to_string(),
                    spacing: 120.0,
                    props: vec![],
                    good_for: Default::default(),
                    height: 3.0,
                },
                &buildings,
            )
            .unwrap();
        (biomes, monuments, buildings)
    }

    fn world(biomes: &BiomeRegistry) -> World2d {
        let def = GroundDef {
            feature_size: 300.0,
            water_level: -0.5,
            cliff_every: 0.0,
            cliff_gaps: 0.3,
            climate_size: 400.0,
            climate: vec![ClimateRule {
                biome: "plain".to_string(),
                moisture: (0.0, 1.0),
                temperature: (0.0, 1.0),
                land: Ground::Grass,
                patches: Ground::Dirt,
            }],
            beach: 0.05,
            patch_size: 60.0,
            chunks_across: None,
            river_size: 400.0,
            river_width: 0.0,
            river_fords: 0.3,
        };
        let ground = GroundGen::new(def, 9, biomes).unwrap();
        let bunker = Clearing {
            at: Vec2::ZERO,
            radius: 20.0,
            gap: None,
        };
        let places = Places::new(
            vec![SiteKind {
                monument: "stop".to_string(),
                chance: 0.7,
            }],
            vec![(bunker.at, bunker.radius)],
        );
        World2d::new(ground, places, vec![bunker])
    }

    /// A world's secrets are 0 to 5, each on land off every road, site
    /// and bunker clearing, the same every time for the seed.
    #[test]
    fn secrets_are_few_and_off_every_road_and_site() {
        let (biomes, monuments, buildings) = registries();
        let r = Registries {
            biomes: &biomes,
            monuments: &monuments,
            buildings: &buildings,
        };
        let mut w = world(&biomes);
        let found = w.secrets(r, (-6, 6));
        assert!(found.len() as u64 <= SECRETS_MOST);
        for at in &found {
            assert!(at.length() >= 20.0 + SECRET_OFF, "a secret by the bunker at {at}");
            assert!(w.sites_touching(r, *at - SECRET_OFF, *at + SECRET_OFF).is_empty(), "a secret by a site at {at}");
            let t = cell_of(*at);
            let off = (SECRET_OFF / TILE).ceil() as i32;
            assert!(w.road_tiles(r, (t.0 - off, t.1 - off), (t.0 + off, t.1 + off)).is_empty(), "a secret by a road at {at}");
        }
        assert_eq!(world(&biomes).secrets(r, (-6, 6)), found, "the same for the seed");
    }

    #[test]
    fn a_clearings_gap_keeps_clear_only_along_its_way() {
        let c = Clearing {
            at: Vec2::ZERO,
            radius: 10.0,
            gap: Some((Vec2::new(100.0, 0.0), 50.0, 8.0)),
        };
        assert!(c.clears(Vec2::new(5.0, 0.0)), "in the clearing");
        assert!(c.clears(Vec2::new(40.0, 3.0)), "in the gap");
        assert!(!c.clears(Vec2::new(40.0, 5.0)), "beside the gap");
        assert!(!c.clears(Vec2::new(60.0, 0.0)), "past the gap's end");
        assert!(!c.clears(Vec2::new(-30.0, 0.0)), "behind the bunker");
    }

    /// The bunker's clearing is bare land in its own ground, no circle of
    /// dirt; nothing grows on a site's ground; roads are laid, on land;
    /// one chunk is the same whenever it is made.
    #[test]
    fn bunkers_are_cleared_sites_are_bare_and_roads_are_laid() {
        let (biomes, monuments, buildings) = registries();
        let r = Registries {
            biomes: &biomes,
            monuments: &monuments,
            buildings: &buildings,
        };
        let mut w = world(&biomes);
        let home = w.chunk(r, (0, 0));
        let first = home.first();
        let clearing: Vec<Ground> = (0..CHUNK)
            .flat_map(|y| (0..CHUNK).map(move |x| (first.0 + x, first.1 + y)))
            .filter(|t| centre(*t).length() < 20.0)
            .map(|t| home.ground_at(t))
            .collect();
        assert!(
            clearing.iter().all(|g| g.is_land()),
            "the bunker's clearing is land"
        );
        assert!(
            clearing.iter().any(|g| *g != Ground::Dirt),
            "the clearing keeps its own ground, no circle of dirt"
        );
        assert!(
            home.things.iter().all(|t| centre(t.tile).length() >= 20.0),
            "nothing in the clearing"
        );
        let mut roads = 0;
        for cy in -12..12 {
            for cx in -12..12 {
                let chunk = w.chunk(r, (cx, cy));
                roads += chunk.ground.iter().filter(|g| **g == Ground::Road).count();
                let lo = Vec2::new((cx * CHUNK) as f32, (cy * CHUNK) as f32);
                let sites = w.sites_touching(r, lo, lo + Vec2::splat(CHUNK as f32));
                for thing in &chunk.things {
                    assert!(
                        sites
                            .iter()
                            .all(|s| s.position.distance(centre(thing.tile)) >= s.ground),
                        "a thing on a site's ground at {:?}",
                        thing.tile
                    );
                }
            }
        }
        assert!(roads > 0, "roads are laid between the sites");
        let mut again = world(&biomes);
        assert_eq!(
            again.chunk(r, (3, -4)),
            w.chunk(r, (3, -4)),
            "the same chunk whenever it is made"
        );
    }
}
