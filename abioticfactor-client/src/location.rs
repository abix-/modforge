//! Locate received coordinates in map geometry. All containing regions are
//! reported; this does not select the client's HUD level.
use crate::{collision::FacilityCollision, levels::LevelTable};
use serde::Serialize;
use std::{collections::BTreeMap, io, path::Path};

pub struct LocationMap {
    world: String,
    collision: FacilityCollision,
    table: LevelTable,
}

#[derive(Debug, Serialize)]
pub struct Area {
    pub level: String,
    pub sector: Option<String>,
    pub volumes: Vec<String>,
}

#[derive(Debug, Serialize)]
pub struct Location {
    pub world: String,
    pub position: [f64; 3],
    pub containing_regions: Vec<Area>,
}

impl LocationMap {
    pub fn from_json(map: &[u8], table: &[u8]) -> io::Result<Self> {
        let parsed: serde_json::Value = serde_json::from_slice(map)?;
        let exports = parsed["exports"]
            .as_array()
            .ok_or_else(|| io::Error::other("missing map exports"))?;
        let mut worlds = exports.iter().filter(|e| e["class"] == "World");
        let world = worlds
            .next()
            .and_then(|e| e["name"].as_str())
            .ok_or_else(|| io::Error::other("missing map world"))?
            .to_owned();
        if worlds.next().is_some() {
            return Err(io::Error::other("multiple map worlds"));
        }
        Ok(Self {
            world,
            collision: FacilityCollision::from_json(map)?,
            table: LevelTable::from_json(table)?,
        })
    }

    pub fn load(profile: &Path) -> io::Result<Self> {
        let directory = profile.join("map");
        Self::from_json(
            &std::fs::read(directory.join("facility-parsed.json"))?,
            &std::fs::read(directory.join("sector-table.json"))?,
        )
    }

    pub fn locate(&self, world: &str, position: [f64; 3]) -> io::Result<Location> {
        let asset = world
            .split('?')
            .next()
            .unwrap_or(world)
            .rsplit('/')
            .next()
            .unwrap_or(world)
            .split('.')
            .next()
            .unwrap_or(world);
        if !asset.eq_ignore_ascii_case(&self.world) {
            return Err(io::Error::other(format!(
                "loaded map {} does not match server world {world}",
                self.world
            )));
        }
        let mut regions = BTreeMap::<String, Area>::new();
        for volume in &self.collision.volumes {
            if self.collision.contains_position(volume, position)? {
                regions
                    .entry(volume.level.clone())
                    .or_insert_with(|| Area {
                        level: volume.level.clone(),
                        sector: self
                            .table
                            .row_for_level(&volume.level)
                            .map(|row| row.sector.clone()),
                        volumes: Vec::new(),
                    })
                    .volumes
                    .push(volume.name.clone());
            }
        }
        Ok(Location {
            world: self.world.clone(),
            position,
            containing_regions: regions.into_values().collect(),
        })
    }
}

impl std::fmt::Display for Location {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{} coordinates ({:.2}, {:.2}, {:.2}); containing map regions: ",
            self.world, self.position[0], self.position[1], self.position[2]
        )?;
        if self.containing_regions.is_empty() {
            return write!(f, "none in extracted geometry");
        }
        for (index, region) in self.containing_regions.iter().enumerate() {
            if index != 0 {
                write!(f, "; ")?;
            }
            write!(
                f,
                "{} ({})",
                region
                    .sector
                    .as_deref()
                    .unwrap_or("sector name unavailable"),
                region.level
            )?;
        }
        Ok(())
    }
}
