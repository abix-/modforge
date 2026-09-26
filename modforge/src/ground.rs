//! Flat 2D ground, the Factorio way (topside design.md "2D world
//! generation"): the base world is flat; every tile has a ground kind
//! and a biome from noise; water, cliffs, trees, and rocks are what stop
//! a body. A hidden elevation noise is used only to place water (below a
//! level) and cliffs (along its contour lines, with gaps), the way
//! Factorio's cliffs follow contours; nothing is shown as height.
//!
//! The world is made chunk by chunk (32 by 32 tiles, pathing.md "One
//! grid"), each from the seed and its position alone, so any chunk can be
//! made in any order and neighbours join without seams: every tile is
//! decided from its world position.

use glam::Vec2;
use noise::{NoiseFn, Simplex};

use crate::biome::BiomeRegistry;
use crate::path::Cell;
use crate::structure::Rgb;
use crate::walk::{CHUNK, ChunkKey, Rect, TILE};

/// Which biome a tile is, by its climate: moisture and temperature, each
/// 0 to 1. The first rule that holds wins. Its land is `land`, with
/// patches of `patches` where a detail noise says so.
#[derive(Clone, Debug, PartialEq)]
pub struct ClimateRule {
    pub biome: String,
    pub moisture: (f32, f32),
    pub temperature: (f32, f32),
    pub land: Ground,
    pub patches: Ground,
}

/// How to make the ground: the shape and the rules, never a result.
#[derive(Clone, Debug, PartialEq)]
pub struct GroundDef {
    /// Metres per period of the elevation noise (lakes and cliff lines).
    pub feature_size: f32,
    /// Elevation (-1 to 1) below which a tile is water.
    pub water_level: f32,
    /// Elevation between cliff contours; 0 for no cliffs.
    pub cliff_every: f32,
    /// Share of a cliff line left open as gaps, 0 to 1.
    pub cliff_gaps: f32,
    /// Metres per period of the climate noise (biomes).
    pub climate_size: f32,
    pub climate: Vec<ClimateRule>,
    /// Elevation above the water level that is beach (sand).
    pub beach: f32,
    /// Metres per period of the patch noise (a biome's patches).
    pub patch_size: f32,
}

/// What a tile's ground is (topside design.md "2D world generation").
/// Water and cliffs stop a body; every other kind is walked on.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum Ground {
    Grass,
    Dirt,
    Sand,
    ForestFloor,
    Rubble,
    /// A road laid between places people used.
    Road,
    Water,
    Cliff,
}

impl Ground {
    pub fn blocks(self) -> bool {
        matches!(self, Ground::Water | Ground::Cliff)
    }

    /// Walked on.
    pub fn is_land(self) -> bool {
        !self.blocks()
    }
}

/// Something growing or lying on a tile (a tree, a rock), from its
/// biome's scatter: it stops a body.
#[derive(Clone, Debug, PartialEq)]
pub struct Thing {
    pub tile: Cell,
    /// Its footprint in metres, centred on the tile.
    pub size: Vec2,
    pub color: Rgb,
}

impl Thing {
    pub fn rect(&self) -> Rect {
        Rect::around(crate::walk::centre(self.tile), self.size)
    }
}

/// One chunk of ground, made from the seed.
#[derive(Clone, Debug, PartialEq)]
pub struct GroundChunk {
    pub key: ChunkKey,
    /// Per tile, row by row from the chunk's first tile.
    pub ground: Vec<Ground>,
    /// Per tile, the biome as an index into `GroundGen::biomes`.
    pub biome: Vec<u16>,
    pub things: Vec<Thing>,
}

impl GroundChunk {
    /// The first tile of the chunk.
    pub fn first(&self) -> Cell {
        (self.key.0 * CHUNK, self.key.1 * CHUNK)
    }

    pub fn ground_at(&self, tile: Cell) -> Ground {
        let f = self.first();
        self.ground[((tile.1 - f.1) * CHUNK + (tile.0 - f.0)) as usize]
    }

    /// Everything of this chunk that stops a body, as rectangles: runs of
    /// water or cliff along each row, and every thing.
    pub fn solids(&self) -> Vec<Rect> {
        let f = self.first();
        let mut out = Vec::new();
        for y in 0..CHUNK {
            let mut x = 0;
            while x < CHUNK {
                let g = self.ground[(y * CHUNK + x) as usize];
                if !g.blocks() {
                    x += 1;
                    continue;
                }
                let start = x;
                while x < CHUNK && self.ground[(y * CHUNK + x) as usize] == g {
                    x += 1;
                }
                let min = Vec2::new((f.0 + start) as f32, (f.1 + y) as f32) * TILE;
                let max = Vec2::new((f.0 + x) as f32, (f.1 + y + 1) as f32) * TILE;
                out.push(Rect { min, max });
            }
        }
        out.extend(self.things.iter().map(Thing::rect));
        out
    }
}

/// Makes chunks of ground for one world: the def, the seed, the noises.
pub struct GroundGen {
    pub def: GroundDef,
    pub seed: u64,
    /// The biome names the chunks' indices point at, in rule order.
    pub biomes: Vec<String>,
    elevation: Simplex,
    moisture: Simplex,
    temperature: Simplex,
    gaps: Simplex,
    patches: Simplex,
}

/// A tile's (or a cell's) own roll, from the seed and its position: the
/// same every time, different for every place and every `k`.
pub fn tile_hash(seed: u64, t: Cell, k: u64) -> u64 {
    // The seed is mixed in its own round: XORed straight onto the first
    // position, seed s at x and seed s ^ 1 at x ^ 1 were the same roll.
    let mut h = 0xD6E8_FEB8_6659_FD93;
    for v in [seed, t.0 as i64 as u64, t.1 as i64 as u64, k] {
        h ^= v.wrapping_add(0x9E37_79B9_7F4A_7C15);
        h = h.wrapping_mul(0xBF58_476D_1CE4_E5B9);
        h ^= h >> 31;
    }
    h
}

/// Fractal noise in -1 to 1: three octaves, each twice as fine and half
/// as strong (Red Blob Games, "Making maps with noise").
fn fbm(noise: &Simplex, p: Vec2) -> f32 {
    let (mut sum, mut amp, mut freq, mut norm) = (0.0, 1.0, 1.0, 0.0);
    for _ in 0..3 {
        sum += amp * noise.get([(p.x * freq) as f64, (p.y * freq) as f64]) as f32;
        norm += amp;
        amp *= 0.5;
        freq *= 2.0;
    }
    sum / norm
}

impl GroundGen {
    /// A generator for `seed`; errors when a climate rule names a biome
    /// the registry does not have.
    pub fn new(def: GroundDef, seed: u64, biomes: &BiomeRegistry) -> Result<Self, String> {
        for rule in &def.climate {
            if biomes.def(&rule.biome).is_none() {
                return Err(format!("climate rule names unknown biome '{}'", rule.biome));
            }
        }
        let names = def.climate.iter().map(|r| r.biome.clone()).collect();
        let part = |shift: u32| Simplex::new((seed.rotate_left(shift) & 0xffff_ffff) as u32);
        Ok(Self {
            biomes: names,
            elevation: part(0),
            moisture: part(16),
            temperature: part(32),
            gaps: part(48),
            patches: part(8),
            def,
            seed,
        })
    }

    /// The hidden elevation at a tile, -1 to 1.
    fn elevation(&self, t: Cell) -> f32 {
        fbm(&self.elevation, crate::walk::centre(t) / self.def.feature_size)
    }

    /// The ground kind of one tile, from its position alone.
    pub fn ground_at(&self, t: Cell) -> Ground {
        let e = self.elevation(t);
        if e < self.def.water_level {
            return Ground::Water;
        }
        if self.def.cliff_every > 0.0 {
            // A cliff where a contour line passes between this tile and the
            // one east or north of it, except in the gaps.
            let level = |e: f32| (e / self.def.cliff_every).floor();
            let here = level(e);
            let crosses = [(t.0 + 1, t.1), (t.0, t.1 + 1)]
                .into_iter()
                .any(|n| level(self.elevation(n)) != here);
            if crosses {
                let gap = fbm(&self.gaps, crate::walk::centre(t) / (self.def.feature_size * 0.1));
                if (gap + 1.0) / 2.0 >= self.def.cliff_gaps {
                    return Ground::Cliff;
                }
            }
        }
        if e < self.def.water_level + self.def.beach {
            return Ground::Sand;
        }
        let Some(rule) = self.def.climate.get(self.biome_at(t) as usize) else {
            return Ground::Grass;
        };
        let patch = fbm(&self.patches, crate::walk::centre(t) / self.def.patch_size);
        if patch > 0.3 { rule.patches } else { rule.land }
    }

    /// The biome of one tile, as an index into `biomes`.
    pub fn biome_at(&self, t: Cell) -> u16 {
        let p = crate::walk::centre(t) / self.def.climate_size;
        let m = (fbm(&self.moisture, p) + 1.0) / 2.0;
        let h = (fbm(&self.temperature, p) + 1.0) / 2.0;
        self.def
            .climate
            .iter()
            .position(|r| m >= r.moisture.0 && m <= r.moisture.1 && h >= r.temperature.0 && h <= r.temperature.1)
            .unwrap_or(self.def.climate.len().saturating_sub(1)) as u16
    }

    /// One chunk, from the seed and its position alone. Scatter: each of
    /// the biome's scatter kinds stands on a land tile by its density,
    /// given per 16 square metres (the old 4 m ground cell), so per tile
    /// it is a sixteenth.
    pub fn chunk(&self, key: ChunkKey, biomes: &BiomeRegistry) -> GroundChunk {
        let first = (key.0 * CHUNK, key.1 * CHUNK);
        let n = (CHUNK * CHUNK) as usize;
        let mut ground = Vec::with_capacity(n);
        let mut biome = Vec::with_capacity(n);
        let mut things = Vec::new();
        for y in 0..CHUNK {
            for x in 0..CHUNK {
                let t = (first.0 + x, first.1 + y);
                let g = self.ground_at(t);
                let b = self.biome_at(t);
                ground.push(g);
                biome.push(b);
                if !g.is_land() {
                    continue;
                }
                let Some(def) = self.biomes.get(b as usize).and_then(|name| biomes.def(name)) else {
                    continue;
                };
                for (k, spec) in def.scatter.iter().enumerate() {
                    let roll = (tile_hash(self.seed, t, k as u64) & 0xFFFF) as f32 / 65535.0;
                    if roll < spec.density / 16.0 {
                        things.push(Thing {
                            tile: t,
                            size: Vec2::new(spec.size.x, spec.size.z).min(Vec2::splat(TILE)),
                            color: spec.color,
                        });
                        break;
                    }
                }
            }
        }
        GroundChunk {
            key,
            ground,
            biome,
            things,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::biome::{BiomeDef, ScatterDef};

    fn biomes() -> BiomeRegistry {
        let mut reg = BiomeRegistry::default();
        for (name, density) in [("forest", 4.0), ("plain", 0.5)] {
            reg.register(BiomeDef {
                name: name.to_string(),
                ground: [0.3, 0.4, 0.2],
                scatter: vec![ScatterDef {
                    size: glam::Vec3::new(1.0, 3.0, 1.0),
                    color: [0.2, 0.4, 0.2],
                    density,
                }],
                weather: vec![],
                monuments: vec![],
                npcs: vec![],
                wildlife: vec![],
                harvest: vec![],
            })
            .unwrap();
        }
        reg
    }

    fn def() -> GroundDef {
        GroundDef {
            feature_size: 200.0,
            water_level: -0.35,
            cliff_every: 0.25,
            cliff_gaps: 0.3,
            climate_size: 400.0,
            climate: vec![
                ClimateRule {
                    biome: "forest".to_string(),
                    moisture: (0.55, 1.0),
                    temperature: (0.0, 1.0),
                    land: Ground::ForestFloor,
                    patches: Ground::Grass,
                },
                ClimateRule {
                    biome: "plain".to_string(),
                    moisture: (0.0, 1.0),
                    temperature: (0.0, 1.0),
                    land: Ground::Grass,
                    patches: Ground::Dirt,
                },
            ],
            beach: 0.05,
            patch_size: 60.0,
        }
    }

    #[test]
    fn the_same_seed_makes_the_same_chunk_in_any_order() {
        let reg = biomes();
        let a = GroundGen::new(def(), 7, &reg).unwrap();
        let b = GroundGen::new(def(), 7, &reg).unwrap();
        let (first, second) = (a.chunk((3, -2), &reg), a.chunk((0, 0), &reg));
        assert_eq!(b.chunk((0, 0), &reg), second, "made second or first, the same");
        assert_eq!(b.chunk((3, -2), &reg), first);
        let c = GroundGen::new(def(), 8, &reg).unwrap();
        assert_ne!(c.chunk((0, 0), &reg), second, "another seed, another chunk");
    }

    /// Neighbouring chunks join: a tile's ground is the same whichever
    /// chunk it is read through, since both come from its position.
    #[test]
    fn chunks_join_without_seams() {
        let reg = biomes();
        let maker = GroundGen::new(def(), 3, &reg).unwrap();
        let (a, b) = (maker.chunk((0, 0), &reg), maker.chunk((1, 0), &reg));
        for y in 0..CHUNK {
            assert_eq!(a.ground_at((CHUNK - 1, y)), maker.ground_at((CHUNK - 1, y)));
            assert_eq!(b.ground_at((CHUNK, y)), maker.ground_at((CHUNK, y)));
        }
    }

    /// Over a wide area there is land, water, and cliffs, and the cliffs
    /// have gaps: a line of cliff tiles is broken somewhere along it.
    #[test]
    fn the_ground_has_water_cliffs_with_gaps_and_trees() {
        let reg = biomes();
        let maker = GroundGen::new(def(), 11, &reg).unwrap();
        let (mut land, mut water, mut cliff, mut things) = (0, 0, 0, 0);
        let mut kinds = std::collections::HashSet::new();
        for cy in -8..8 {
            for cx in -8..8 {
                let chunk = maker.chunk((cx, cy), &reg);
                for g in &chunk.ground {
                    kinds.insert(*g);
                    match g {
                        Ground::Water => water += 1,
                        Ground::Cliff => cliff += 1,
                        _ => land += 1,
                    }
                }
                things += chunk.things.len();
            }
        }
        assert!(land > water && water > 0 && cliff > 0 && things > 0, "land {land}, water {water}, cliff {cliff}, things {things}");
        for kind in [Ground::Grass, Ground::Dirt, Ground::Sand, Ground::ForestFloor] {
            assert!(kinds.contains(&kind), "no {kind:?} anywhere: {kinds:?}");
        }
        // Gaps: with the gaps turned off there are more cliff tiles.
        let solid = GroundGen::new(GroundDef { cliff_gaps: 0.0, ..def() }, 11, &reg).unwrap();
        let solid_cliffs: usize = (-8..8)
            .flat_map(|cy| (-8..8).map(move |cx| (cx, cy)))
            .map(|k| solid.chunk(k, &reg).ground.iter().filter(|g| **g == Ground::Cliff).count())
            .sum();
        assert!(solid_cliffs > cliff, "gaps open the cliff lines: {solid_cliffs} without, {cliff} with");
    }

    #[test]
    fn an_unknown_biome_is_refused() {
        let mut bad = def();
        bad.climate[0].biome = "swamp".to_string();
        assert!(GroundGen::new(bad, 1, &biomes()).is_err());
    }
}
