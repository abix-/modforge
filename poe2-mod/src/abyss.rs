//! Abyss cracks and the abyss pit after GameHelper2's Radar plugin
//! (Radar.cs RecordTrackedNode, ClassifyTrackedPath, RebuildTrackedNodes,
//! IsAbyssNodeReached; RadarSettings.cs AddDefaultAbyssIcons): every
//! crack and pit seen awake or asleep is remembered for the zone, even
//! after the game drops it, until the player comes within
//! [`crate::radar::REACHED_DISTANCE`] cells of it.

use crate::entities::Entity;
use crate::terrain::world_per_cell;
use serde::Serialize;
use std::collections::{BTreeMap, BTreeSet};

/// Radar.TrackedScanIntervalMs: how often sleeping entities are read.
pub const SCAN_MS: u64 = 1000;
/// AddDefaultAbyssIcons: the pit's path colour, 140, 255, 0.
pub const PATH_COLOR: modforge::overlay::Rgb = 0x8CFF00;

#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Serialize)]
pub enum Kind {
    Crack,
    Pit,
}

impl Kind {
    /// AddDefaultAbyssIcons: cracks are hidden, the pit shows with a
    /// path.
    pub fn shown(self) -> bool {
        self == Kind::Pit
    }
}

/// ClassifyTrackedPath.
pub fn classify(path: &str) -> Option<Kind> {
    if path.contains("AbyssCrack") {
        Some(Kind::Crack)
    } else if path.contains("AbyssFinalNodeBase") {
        Some(Kind::Pit)
    } else {
        None
    }
}

/// Kind and whole grid cell: the node's lasting key.
pub type Key = (Kind, i32, i32);

#[derive(Clone, Copy, Debug, PartialEq, Serialize)]
pub struct Node {
    pub kind: Kind,
    pub cell: [f32; 2],
    pub height: f32,
}

/// The cracks and pit of one zone instance.
#[derive(Debug, Default)]
pub struct Tracked {
    pub nodes: BTreeMap<Key, Node>,
    pub reached: BTreeSet<Key>,
}

impl Tracked {
    /// RecordTrackedNode for an entity that is a crack or the pit.
    pub fn record(&mut self, e: &Entity) {
        let (Some(kind), Some([x, y, _])) = (classify(&e.path), e.position) else {
            return;
        };
        let w = world_per_cell();
        let cell = [x / w, y / w];
        let key = (kind, cell[0] as i32, cell[1] as i32);
        let height = e.terrain_height.unwrap_or(0.0);
        self.nodes.insert(key, Node { kind, cell, height });
    }

    /// IsAbyssNodeReached for every node: those the player stands
    /// within `distance` cells of are retired for good.
    pub fn retire_near(&mut self, player: [f32; 2], distance: f32) {
        for (key, n) in &self.nodes {
            let d = (n.cell[0] - player[0]).hypot(n.cell[1] - player[1]);
            if d <= distance {
                self.reached.insert(*key);
            }
        }
    }

    /// The nodes still to draw: shown kinds not reached yet.
    pub fn shown(&self) -> impl Iterator<Item = &Node> {
        self.nodes
            .iter()
            .filter(|(k, n)| n.kind.shown() && !self.reached.contains(k))
            .map(|(_, n)| n)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn entity(path: &str, at: [f32; 2]) -> Entity {
        let w = world_per_cell();
        Entity {
            path: path.into(),
            position: Some([at[0] * w, at[1] * w, 0.0]),
            terrain_height: Some(-3.0),
            ..Default::default()
        }
    }

    #[test]
    fn remembers_the_pit_until_reached() {
        assert_eq!(
            classify("Metadata/MiscellaneousObjects/Abyss/AbyssCrackSpawners/x"),
            Some(Kind::Crack)
        );
        assert_eq!(classify("Metadata/Monsters/x"), None);
        let mut t = Tracked::default();
        t.record(&entity("Metadata/Abyss/AbyssCrackSpawner", [10.0, 10.0]));
        t.record(&entity("Metadata/Abyss/AbyssFinalNodeBase", [300.5, 200.5]));
        t.record(&entity("Metadata/Abyss/AbyssFinalNodeBase", [300.5, 200.5]));
        t.record(&entity("Metadata/Monsters/Rat", [1.0, 1.0]));
        assert_eq!(t.nodes.len(), 2);
        // Cracks are hidden by default; the pit shows.
        let shown: Vec<_> = t.shown().collect();
        assert_eq!(shown.len(), 1);
        assert_eq!(shown[0].kind, Kind::Pit);
        assert_eq!(shown[0].height, -3.0);
        t.retire_near([300.0, 260.0], 50.0);
        assert_eq!(t.shown().count(), 1);
        t.retire_near([300.0, 240.0], 50.0);
        assert_eq!(t.shown().count(), 0);
        // Seen again later, it stays retired.
        t.record(&entity("Metadata/Abyss/AbyssFinalNodeBase", [300.5, 200.5]));
        assert_eq!(t.shown().count(), 0);
    }
}
