//! Fire (topside-town "Everything works": "fire spreads; smoke
//! detectors, extinguishers, hydrants and the fire station fight it";
//! Project Zomboid's fire, which spreads from a burning thing to what is
//! near it and is put out by an extinguisher). A thing set alight burns
//! for a while, catching what burns near it once it has burned a little,
//! then is gone. A smoke detector sounds while a fire burns near it. An
//! extinguisher puts out the fires within its reach, a hydrant's hose
//! those within its own. Engine-free; the game says what burns and where.

use glam::Vec2;
use serde::{Deserialize, Serialize};

/// How fire burns, for one game.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct FireDef {
    /// Seconds a thing burns before it catches what is near it.
    pub spread_after: f32,
    /// How near, metres, a thing catches from a burning one.
    pub spread_reach: f32,
    /// Seconds a thing burns before it is gone.
    pub burns_for: f32,
    /// How near, metres, a smoke detector smells a fire.
    pub smoke_reach: f32,
}

/// One burning thing: how long it has burned.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Fire {
    pub burnt: f32,
}

impl Fire {
    /// `dt` seconds more of burning; true when it has burned away.
    pub fn burn(&mut self, def: &FireDef, dt: f32) -> bool {
        self.burnt += dt;
        self.burnt >= def.burns_for
    }

    /// Whether a thing `distance` away catches from this fire now.
    pub fn catches(&self, def: &FireDef, distance: f32) -> bool {
        self.burnt >= def.spread_after && distance <= def.spread_reach
    }
}

/// Whether a smoke detector at `at` sounds: a fire burns within its
/// reach.
pub fn sounds(def: &FireDef, at: Vec2, fires: impl IntoIterator<Item = Vec2>) -> bool {
    fires.into_iter().any(|f| f.distance(at) <= def.smoke_reach)
}

/// The fires, of `fires`, that something put out from `at` with `reach`
/// puts out: every one within it (an extinguisher's spray, a hose).
pub fn put_out(at: Vec2, reach: f32, fires: &[Vec2]) -> Vec<usize> {
    fires.iter().enumerate().filter(|(_, f)| f.distance(at) <= reach).map(|(i, _)| i).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    const DEF: FireDef = FireDef { spread_after: 10.0, spread_reach: 2.0, burns_for: 60.0, smoke_reach: 8.0 };

    #[test]
    fn a_fire_spreads_once_it_has_burned_and_then_burns_away() {
        let mut fire = Fire::default();
        assert!(!fire.catches(&DEF, 1.0));
        assert!(!fire.burn(&DEF, 10.0));
        assert!(fire.catches(&DEF, 1.0));
        assert!(!fire.catches(&DEF, 3.0));
        assert!(fire.burn(&DEF, 50.0));
    }

    #[test]
    fn a_detector_sounds_and_an_extinguisher_puts_out_what_is_near() {
        let fires = [Vec2::new(1.0, 0.0), Vec2::new(20.0, 0.0)];
        assert!(sounds(&DEF, Vec2::ZERO, fires));
        assert!(!sounds(&DEF, Vec2::new(50.0, 0.0), fires));
        assert_eq!(put_out(Vec2::ZERO, 3.0, &fires), vec![0]);
    }
}
