//! Sites region by region (topside design.md "2D world generation"): in
//! a world made chunk by chunk nothing knows the whole map, so each kind
//! of site has its own grid of cells, one cell per `spacing` metres, and a
//! cell holds at most one site at a spot jittered inside it, standing with
//! the kind's `chance`. A candidate stands only where its monument's whole
//! footprint is on land in a biome that allows it, clear of the bunkers,
//! and clear of any site of an earlier kind (or an earlier cell of its own
//! kind) nearby. All of it is decided from the seed and the cell alone,
//! so any region asked for in any order gets the same sites (Factorio
//! places things per tile by a chance from noise; this is the same at the
//! size of a monument).

use std::collections::HashMap;

use glam::Vec2;

use crate::biome::BiomeRegistry;
use crate::ground::{GroundGen, tile_hash};
use crate::monument::{BuildingRegistry, MonumentRegistry};
use crate::path::Cell;
use crate::structure::{MonumentDef, tile_plan};
use crate::walk::cell_of;

/// One kind of site and how common it is: at most one in each cell of
/// its monument type's `spacing`, standing there with `chance` (0 to 1).
#[derive(Clone, Debug, PartialEq)]
pub struct SiteKind {
    pub monument: String,
    pub chance: f32,
}

/// A site placed in the world, its monument rolled with it.
#[derive(Clone, Debug, PartialEq)]
pub struct Place {
    pub monument: String,
    /// Whole metres: a tile corner.
    pub position: Vec2,
    pub biome: String,
    pub rolled: MonumentDef,
    /// How far from `position` the monument reaches, metres
    /// (`worldgen::monument_ground`): its ground.
    pub ground: f32,
}

impl Place {
    /// Every tile the monument stands on or places someone on: its
    /// buildings' ground floors, its props, its spots for people and
    /// boxes.
    pub fn footprint(&self) -> Vec<Cell> {
        let mut tiles = Vec::new();
        for m in &self.rolled.members {
            let at = (self.position + Vec2::new(m.offset.x, m.offset.z)).round();
            for run in tile_plan(&m.structure) {
                for x in run.from..run.to {
                    tiles.push(cell_of(at + Vec2::new(x as f32 + 0.5, run.row as f32 + 0.5)));
                }
            }
        }
        for p in &self.rolled.props {
            let c = self.position + Vec2::new(p.position.x, p.position.z);
            let half = Vec2::new(p.size.x, p.size.z) / 2.0;
            let (lo, hi) = (cell_of(c - half), cell_of(c + half));
            for y in lo.1..=hi.1 {
                for x in lo.0..=hi.0 {
                    tiles.push((x, y));
                }
            }
        }
        let spots = self.rolled.npc_spots.iter().map(|s| s.position).chain(self.rolled.loot_spots.iter().map(|s| s.position));
        tiles.extend(spots.map(|p| cell_of(self.position + Vec2::new(p.x, p.z))));
        tiles
    }
}

/// What placing sites reads, handed in with each call so a world can own
/// its places: the ground and the registries.
#[derive(Clone, Copy)]
pub struct Makers<'a> {
    pub ground: &'a GroundGen,
    pub biomes: &'a BiomeRegistry,
    pub monuments: &'a MonumentRegistry,
    pub buildings: &'a BuildingRegistry,
}

/// Places sites for one world, remembering each cell once decided.
pub struct Places {
    /// In priority order: an earlier kind's site keeps a later kind away.
    kinds: Vec<SiteKind>,
    /// Ground kept for the bunkers: a point and how far round it.
    keep_clear: Vec<(Vec2, f32)>,
    cache: HashMap<(usize, Cell), Option<Place>>,
}

/// Room left between two sites' grounds, metres.
const BETWEEN: f32 = 8.0;

impl Places {
    pub fn new(kinds: Vec<SiteKind>, keep_clear: Vec<(Vec2, f32)>) -> Self {
        Self {
            kinds,
            keep_clear,
            cache: HashMap::new(),
        }
    }

    fn spacing(&self, m: Makers, k: usize) -> f32 {
        m.monuments.def(&self.kinds[k].monument).map_or(100.0, |d| d.spacing)
    }

    /// The farthest any site's ground reaches from its position: a site's
    /// ground is at most 30% of its spacing (the rule in `roll_cell`).
    pub fn widest(&self, m: Makers) -> f32 {
        (0..self.kinds.len()).map(|k| 0.3 * self.spacing(m, k)).fold(0.0, f32::max)
    }

    /// The site of kind `k` in its grid cell `cell`, if one stands there.
    pub fn in_cell(&mut self, m: Makers, k: usize, cell: Cell) -> Option<Place> {
        if let Some(found) = self.cache.get(&(k, cell)) {
            return found.clone();
        }
        let found = self.roll_cell(m, k, cell);
        self.cache.insert((k, cell), found.clone());
        found
    }

    fn roll_cell(&mut self, m: Makers, k: usize, cell: Cell) -> Option<Place> {
        let kind = self.kinds[k].clone();
        let spacing = self.spacing(m, k);
        let seed = m.ground.seed ^ (k as u64 + 1).wrapping_mul(0xA24B_AED4_963E_E407);
        let h = tile_hash(seed, cell, 0);
        if (h & 0xFFFF) as f32 / 65535.0 >= kind.chance {
            return None;
        }
        // Inside the middle of the cell (30% to 70%), so two sites of one
        // kind are always at least 60% of a spacing apart and no cell
        // needs to ask the cells of its own kind around it.
        let jitter = Vec2::new(((h >> 16) & 0xFFFF) as f32, ((h >> 32) & 0xFFFF) as f32) / 65535.0;
        let at = (Vec2::new(cell.0 as f32, cell.1 as f32) + Vec2::splat(0.3) + jitter * 0.4) * spacing;
        // Whole metres, as every member offset is: buildings then stand on
        // whole tiles with no snapping, and their spots stay where the
        // roll put them in the building.
        let position = at.round();
        let tile = cell_of(position);
        let biome = m.ground.biomes.get(m.ground.biome_at(tile) as usize)?.clone();
        let allowed = m.biomes.def(&biome).is_some_and(|b| b.monuments.iter().any(|x| *x == kind.monument));
        if !allowed {
            return None;
        }
        let rolled = m.monuments.roll(&kind.monument, m.buildings, tile_hash(seed, cell, 1)).ok()?;
        let ground = crate::worldgen::monument_ground(&rolled);
        // Too big for its spacing: it could reach a neighbour of its own
        // kind, so it does not stand here.
        if 2.0 * ground + BETWEEN > 0.6 * spacing {
            return None;
        }
        if self.keep_clear.iter().any(|(c, r)| c.distance(position) < r + ground) {
            return None;
        }
        let place = Place {
            monument: kind.monument,
            position,
            biome,
            rolled,
            ground,
        };
        // The whole footprint on land.
        if place.footprint().iter().any(|t| !m.ground.ground_at(*t).is_land()) {
            return None;
        }
        // Clear of any earlier kind's site nearby (only earlier kinds, so
        // the asking goes at most as deep as there are kinds).
        for j in 0..k {
            let reach = place.ground + BETWEEN + self.spacing(m, j).max(spacing);
            let sp = self.spacing(m, j);
            let (lo, hi) = (((position - reach) / sp).floor(), ((position + reach) / sp).floor());
            for cy in lo.y as i32..=hi.y as i32 {
                for cx in lo.x as i32..=hi.x as i32 {
                    if let Some(other) = self.in_cell(m, j, (cx, cy))
                        && other.position.distance(position) < other.ground + place.ground + BETWEEN
                    {
                        return None;
                    }
                }
            }
        }
        Some(place)
    }

    /// Every site standing in the square from `lo` to `hi` (world metres).
    pub fn in_area(&mut self, m: Makers, lo: Vec2, hi: Vec2) -> Vec<Place> {
        let mut out = Vec::new();
        for k in 0..self.kinds.len() {
            let sp = self.spacing(m, k);
            let (a, b) = ((lo / sp).floor(), (hi / sp).floor());
            for cy in a.y as i32..=b.y as i32 {
                for cx in a.x as i32..=b.x as i32 {
                    if let Some(p) = self.in_cell(m, k, (cx, cy))
                        && p.position.cmpge(lo).all()
                        && p.position.cmplt(hi).all()
                    {
                        out.push(p);
                    }
                }
            }
        }
        out
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::biome::BiomeDef;
    use crate::ground::{ClimateRule, Ground, GroundDef};
    use crate::monument::{Arrangement, BuildingSize, BuildingSlot, BuildingTypeDef, MonumentTypeDef};

    fn registries() -> (BiomeRegistry, MonumentRegistry, BuildingRegistry) {
        let mut biomes = BiomeRegistry::default();
        biomes
            .register(BiomeDef {
                name: "plain".to_string(),
                ground: [0.3, 0.4, 0.2],
                scatter: vec![],
                weather: vec![],
                monuments: vec!["stop".to_string(), "wreck".to_string()],
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
        for (name, slots, spacing) in [("stop", 1, 120.0), ("wreck", 0, 40.0)] {
            monuments
                .register(
                    MonumentTypeDef {
                        name: name.to_string(),
                        slots: (0..slots)
                            .map(|_| BuildingSlot { choices: vec!["shed".to_string()], min: 1, max: 1 })
                            .collect(),
                        arrangement: Arrangement::Clustered,
                        danger: 1,
                        gated: false,
                        suffix: name.to_string(),
                        spacing,
                        props: if slots == 0 {
                            vec![crate::monument::PropDef {
                                size: glam::Vec3::new(3.0, 1.4, 1.8),
                                color: [0.4, 0.2, 0.15],
                                count: (1, 2),
                                radius: 4.0,
                            }]
                        } else {
                            vec![]
                        },
                        good_for: Default::default(),
                        height: 3.0,
                    },
                    &buildings,
                )
                .unwrap();
        }
        (biomes, monuments, buildings)
    }

    fn ground(biomes: &BiomeRegistry) -> GroundGen {
        let def = GroundDef {
            feature_size: 200.0,
            water_level: -0.35,
            cliff_every: 0.25,
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
        };
        GroundGen::new(def, 5, biomes).unwrap()
    }

    fn kinds() -> Vec<SiteKind> {
        vec![
            SiteKind { monument: "stop".to_string(), chance: 0.6 },
            SiteKind { monument: "wreck".to_string(), chance: 0.5 },
        ]
    }

    /// Sites stand only on land, never overlap, and a region gives the
    /// same sites whichever order the world is asked in.
    #[test]
    fn sites_stand_on_land_apart_and_the_same_in_any_order() {
        let (biomes, monuments, buildings) = registries();
        let g = ground(&biomes);
        let m = Makers {
            ground: &g,
            biomes: &biomes,
            monuments: &monuments,
            buildings: &buildings,
        };
        let mut a = Places::new(kinds(), vec![(Vec2::ZERO, 30.0)]);
        let area = a.in_area(m, Vec2::splat(-600.0), Vec2::splat(600.0));
        assert!(area.len() > 10, "{} sites", area.len());
        for p in &area {
            assert!(p.footprint().iter().all(|t| g.ground_at(*t).is_land()), "{} at {} stands off land", p.monument, p.position);
            assert!(p.position.length() >= 30.0 + p.ground, "clear of the bunker");
        }
        for (i, p) in area.iter().enumerate() {
            for q in &area[i + 1..] {
                assert!(p.position.distance(q.position) >= p.ground + q.ground, "{} and {} overlap", p.position, q.position);
            }
        }
        // Asked for a corner first, then the rest: the same sites.
        let mut b = Places::new(kinds(), vec![(Vec2::ZERO, 30.0)]);
        let _ = b.in_area(m, Vec2::splat(300.0), Vec2::splat(600.0));
        assert_eq!(b.in_area(m, Vec2::splat(-600.0), Vec2::splat(600.0)), area);
    }
}
