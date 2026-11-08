//! Ritual wisp range after GameHelper2's RitualWispAlert plugin
//! (RitualWispAlertCore.cs): every awake ritual wisp, whether the player
//! stands within its range, and the circle of its range on the ground.

use crate::entities::Entity;
use crate::terrain::world_per_cell;
use serde::Serialize;

/// RitualWispAlertCore.WispMetadataPath, matched ignoring case.
pub const WISP_PATH: &str = "metadata/monsters/leagueritual/ritualwispdaemon";
/// RitualWispAlertSettings.RadiusMeters.
pub const RADIUS_METERS: f32 = 3.0;
/// RitualWispAlertCore.GridUnitsPerMeter.
pub const CELLS_PER_METER: f32 = 10.0;
/// RitualWispAlertCore.CircleSegments.
pub const CIRCLE_SEGMENTS: usize = 36;

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Wisp {
    pub address: u64,
    pub position: [f32; 3],
    /// Grid cells from the player, whole cells as Entity.DistanceFrom.
    pub distance: i32,
    pub inside: bool,
    /// The range on the ground, world positions at the wisp's ground
    /// height.
    pub circle: Vec<[f32; 3]>,
}

/// Entity.DistanceFrom: the grid distance between two world positions,
/// cut to whole cells.
pub fn cells_apart(a: [f32; 3], b: [f32; 3]) -> i32 {
    let w = world_per_cell();
    let (dx, dy) = ((a[0] - b[0]) / w, (a[1] - b[1]) / w);
    (dx * dx + dy * dy).sqrt() as i32
}

/// The circle of `radius` world units around `centre` at `height`.
pub fn circle(centre: [f32; 3], height: f32, radius: f32) -> Vec<[f32; 3]> {
    (0..CIRCLE_SEGMENTS)
        .map(|i| {
            let angle = i as f32 * std::f32::consts::TAU / CIRCLE_SEGMENTS as f32;
            [
                centre[0] + radius * angle.cos(),
                centre[1] + radius * angle.sin(),
                height,
            ]
        })
        .collect()
}

/// The valid wisps among `entities` with the player at `player`, for a
/// range of `radius_meters`.
pub fn wisps(player: [f32; 3], entities: &[Entity], radius_meters: f32) -> Vec<Wisp> {
    let range = radius_meters * CELLS_PER_METER;
    entities
        .iter()
        .filter(|e| e.valid && e.path.to_lowercase().contains(WISP_PATH))
        .filter_map(|e| {
            let position = e.position?;
            let distance = cells_apart(player, position);
            Some(Wisp {
                address: e.address,
                position,
                distance,
                inside: distance as f32 <= range,
                circle: circle(
                    position,
                    e.terrain_height.unwrap_or(position[2]),
                    range * world_per_cell(),
                ),
            })
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn entity(path: &str, position: [f32; 3]) -> Entity {
        Entity {
            valid: true,
            path: path.into(),
            position: Some(position),
            terrain_height: Some(-5.0),
            ..Entity::default()
        }
    }

    #[test]
    fn the_player_is_inside_a_near_wisp_only() {
        let w = world_per_cell();
        let near = entity(
            "Metadata/Monsters/LeagueRitual/RitualWispDaemon@70",
            [w * 29.0, 0.0, 1.0],
        );
        let far = entity(
            "Metadata/Monsters/LeagueRitual/RitualWispDaemon",
            [0.0, w * 31.5, 1.0],
        );
        let wolf = entity("Metadata/Monsters/Wolf/Wolf", [0.0, 0.0, 0.0]);
        let found = wisps([0.0, 0.0, 0.0], &[near, far, wolf], RADIUS_METERS);
        assert_eq!(found.len(), 2);
        assert_eq!((found[0].distance, found[0].inside), (29, true));
        assert_eq!((found[1].distance, found[1].inside), (31, false));
        let c = &found[0].circle;
        assert_eq!(c.len(), CIRCLE_SEGMENTS);
        assert!(c.iter().all(|p| p[2] == -5.0));
        let r = cells_apart(found[0].position, c[9]);
        assert!((29..=30).contains(&r), "{r}");
    }
}
