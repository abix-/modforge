//! A 2D world, the Factorio way (topside design.md "2D world
//! generation"): flat ground made chunk by chunk from the seed
//! (`ground`), sites placed region by region (`places`), the bunkers on
//! cleared ground, and roads on the tiles between places people used.
//! Every chunk is decided from the seed and what stands near it, so any
//! chunk can be made in any order, and the world can be any size.

use std::collections::HashMap;

use glam::Vec2;

use crate::biome::BiomeRegistry;
use crate::ground::{Ground, GroundChunk, GroundGen, tile_hash};
use crate::monument::{BuildingRegistry, MonumentRegistry};
use crate::path::{Cell, search};
use crate::places::{Makers, Place, Places};
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
}

/// Tries at a spot for one topside person before they are left out.
const PEOPLE_TRIES: u64 = 64;

impl World2d {
    pub fn new(ground: GroundGen, places: Places, bunkers: Vec<Clearing>) -> Self {
        Self {
            ground,
            places,
            bunkers,
            roads: HashMap::new(),
            people: Vec::new(),
            people_spots: None,
        }
    }

    /// These topside people as well, placed on open land inside the
    /// world's edge. A world with no edge places none this way.
    pub fn with_people(mut self, people: Vec<(String, u32)>) -> Self {
        self.people = people;
        self
    }

    /// Where each topside person stands, by actor def: a tile rolled from
    /// the seed anywhere inside the edge, taken only if it is land with
    /// nothing on it, off every site's ground and every bunker's clearing.
    /// The same every time for a seed.
    pub fn topside_people(&mut self, r: Registries) -> Vec<(String, Vec2)> {
        if let Some(found) = &self.people_spots {
            return found.clone();
        }
        let mut out = Vec::new();
        if let Some((lo, hi)) = self.ground.chunk_range() {
            let (lo, span) = (lo * CHUNK, (hi - lo) * CHUNK);
            for (i, (def, count)) in self.people.clone().into_iter().enumerate() {
                for k in 0..count {
                    for a in 0..PEOPLE_TRIES {
                        let h = tile_hash(self.ground.seed, (i as i32, k as i32), 0x5EED_0000 + a);
                        let t = (lo + (h % span as u64) as i32, lo + ((h >> 32) % span as u64) as i32);
                        let at = centre(t);
                        let key = (t.0.div_euclid(CHUNK), t.1.div_euclid(CHUNK));
                        let chunk = self.chunk(r, key);
                        let open = chunk.ground_at(t).is_land() && !chunk.things.iter().any(|thing| thing.tile == t);
                        let clear = !self.bunkers.iter().any(|c| c.at.distance(at) < c.radius)
                            && self.sites_touching(r, at, at).is_empty();
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

    fn makers<'a>(ground: &'a GroundGen, r: Registries<'a>) -> Makers<'a> {
        Makers {
            ground,
            biomes: r.biomes,
            monuments: r.monuments,
            buildings: r.buildings,
        }
    }

    /// Every site standing in the square from `lo` to `hi`.
    pub fn sites_in(&mut self, r: Registries, lo: Vec2, hi: Vec2) -> Vec<Place> {
        self.places.in_area(Self::makers(&self.ground, r), lo, hi)
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
        let around = self.places.in_area(m, site.position - ROAD_REACH, site.position + ROAD_REACH);
        let to = around
            .iter()
            .filter(|p| !p.rolled.members.is_empty() && p.position.length() < site.position.length())
            .filter(|p| p.position.distance(site.position) <= ROAD_REACH)
            .min_by(|a, b| a.position.distance(site.position).total_cmp(&b.position.distance(site.position)))?
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
        let open = |t: Cell| ground.ground_at(t).is_land() && !others.iter().any(|(c, rad)| c.distance(centre(t)) < *rad);
        let next = |at: Cell| -> Vec<(Cell, f32)> {
            [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
                .into_iter()
                .map(|(dx, dy)| (at.0 + dx, at.1 + dy))
                .filter(|t| *t == goal || open(*t))
                .map(|t| (t, if t.0 != at.0 && t.1 != at.1 { std::f32::consts::SQRT_2 } else { 1.0 }))
                .collect()
        };
        let estimate = |t: Cell| centre(t).distance(centre(goal)) / TILE;
        let found = search(start, next, estimate, |t| t == goal, ROAD_LIMIT).map(|(tiles, _)| tiles);
        self.roads.insert(key, found.clone());
        found
    }

    /// Every road tile in the square from `lo` to `hi` (inclusive tiles).
    fn road_tiles(&mut self, r: Registries, lo: Cell, hi: Cell) -> Vec<Cell> {
        let (a, b) = (centre(lo), centre(hi));
        let sites: Vec<Place> = self
            .sites_in(r, a - ROAD_REACH, b + ROAD_REACH)
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
    /// clearings made dirt and bare, nothing growing or lying on a site's
    /// ground, and the roads laid on land off the sites' ground.
    pub fn chunk(&mut self, r: Registries, key: ChunkKey) -> GroundChunk {
        let mut chunk = self.ground.chunk(key, r.biomes);
        let first = chunk.first();
        let last = (first.0 + CHUNK - 1, first.1 + CHUNK - 1);
        let lo = Vec2::new(first.0 as f32, first.1 as f32) * TILE;
        let hi = lo + Vec2::splat(CHUNK as f32 * TILE);
        let index = |t: Cell| ((t.1 - first.1) * CHUNK + (t.0 - first.0)) as usize;
        let sites = self.sites_touching(r, lo, hi);
        let on_site = |t: Cell| sites.iter().any(|s| s.position.distance(centre(t)) < s.ground);
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
        for c in &self.bunkers {
            for y in 0..CHUNK {
                for x in 0..CHUNK {
                    let t = (first.0 + x, first.1 + y);
                    if centre(t).distance(c.at) < c.radius {
                        chunk.ground[index(t)] = Ground::Dirt;
                    }
                }
            }
        }
        let bunkers = &self.bunkers;
        let ground = chunk.ground.clone();
        chunk.things.retain(|thing| {
            let at = centre(thing.tile);
            !on_site(thing.tile)
                && !bunkers.iter().any(|c| c.at.distance(at) < c.radius)
                && ground[index(thing.tile)] != Ground::Road
        });
        chunk
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::biome::{BiomeDef, ScatterDef};
    use crate::ground::{ClimateRule, GroundDef};
    use crate::monument::{Arrangement, BuildingSize, BuildingSlot, BuildingTypeDef, MonumentTypeDef};
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
                    slots: vec![BuildingSlot { choices: vec!["shed".to_string()], min: 1, max: 1 }],
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
        let bunker = Clearing { at: Vec2::ZERO, radius: 20.0 };
        let places = Places::new(vec![SiteKind { monument: "stop".to_string(), chance: 0.7 }], vec![(bunker.at, bunker.radius)]);
        World2d::new(ground, places, vec![bunker])
    }

    /// The bunker's clearing is bare dirt; nothing grows on a site's
    /// ground; roads are laid, on land; one chunk is the same whenever it
    /// is made.
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
        for y in 0..CHUNK {
            for x in 0..CHUNK {
                let t = (first.0 + x, first.1 + y);
                if centre(t).length() < 20.0 {
                    assert_eq!(home.ground_at(t), Ground::Dirt, "the bunker's clearing");
                }
            }
        }
        assert!(home.things.iter().all(|t| centre(t.tile).length() >= 20.0), "nothing in the clearing");
        let mut roads = 0;
        for cy in -12..12 {
            for cx in -12..12 {
                let chunk = w.chunk(r, (cx, cy));
                roads += chunk.ground.iter().filter(|g| **g == Ground::Road).count();
                let lo = Vec2::new((cx * CHUNK) as f32, (cy * CHUNK) as f32);
                let sites = w.sites_touching(r, lo, lo + Vec2::splat(CHUNK as f32));
                for thing in &chunk.things {
                    assert!(
                        sites.iter().all(|s| s.position.distance(centre(thing.tile)) >= s.ground),
                        "a thing on a site's ground at {:?}",
                        thing.tile
                    );
                }
            }
        }
        assert!(roads > 0, "roads are laid between the sites");
        let mut again = world(&biomes);
        assert_eq!(again.chunk(r, (3, -4)), w.chunk(r, (3, -4)), "the same chunk whenever it is made");
    }
}
