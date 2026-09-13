//! Travel a navigation path over UDP.
//!
//! The host's navigation mesh supplies the path points (nav.find_path in the
//! mod). The shared route follower (modforge::route::Bot) owns path progress,
//! arrival and stuck detection. Its key and mouse output is not used: Sophia's
//! ServerMove packets carry a world-space acceleration, so each tick this
//! module points that acceleration at the current path point instead.
use modforge::route::{Bot, BotStatus, Path, PathPoint, PlayerObservation, Position, SteeringConfig};

/// Same magnitude the two-second forward command uses.
pub const ACCELERATION: f64 = 2048.0;
const GOAL_ARRIVAL: f64 = 150.0;
const PATH_POINT_RADIUS: f64 = 90.0;
const STUCK_MIN_PROGRESS: f64 = 40.0;
const STUCK_AFTER_MS: u64 = 4000;

pub struct Travel {
    bot: Bot,
    points: Vec<Position>,
    started: std::time::Instant,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Step {
    /// Keep sending this acceleration toward path point `index`.
    Move { index: usize, acceleration: [f32; 3] },
    /// Send zero acceleration once and drop the travel; `status` says why.
    Done { status: BotStatus },
}

impl Travel {
    /// Parse `x,y,z x,y,z ...` as sent by the mod's ai_player.travel operation.
    pub fn parse(text: &str) -> Result<Self, String> {
        let mut points = Vec::new();
        for word in text.split_whitespace() {
            let values: Vec<f64> = word.split(',').map(|v| v.parse::<f64>().map_err(|e| format!("{word}: {e}"))).collect::<Result<_, _>>()?;
            if values.len() != 3 { return Err(format!("{word}: expected x,y,z")); }
            points.push(Position::new(values[0], values[1], values[2]));
        }
        Self::new(points)
    }

    /// Walking is flat: navigation mesh points sit on the floor while the
    /// received position is the capsule centre about a metre above it, so
    /// every distance the follower measures ignores height.
    pub fn new(points: Vec<Position>) -> Result<Self, String> {
        let points: Vec<Position> = points.into_iter().map(|p| Position::new(p.x, p.y, 0.0)).collect();
        let path = Path::new(points.iter().map(|p| PathPoint::new(*p)).collect())?;
        let steering = SteeringConfig { path_point_radius: PATH_POINT_RADIUS, ..SteeringConfig::default() };
        let bot = Bot::new(path, GOAL_ARRIVAL, steering, STUCK_MIN_PROGRESS, STUCK_AFTER_MS)?;
        Ok(Self { bot, points, started: std::time::Instant::now() })
    }

    pub fn len(&self) -> usize { self.points.len() }

    /// One follower tick from the last received UDP position (server coordinates).
    pub fn step(&mut self, position: [f64; 3]) -> Step {
        let observation = PlayerObservation { position: Position::new(position[0], position[1], 0.0), yaw_deg: 0.0, pitch_deg: 0.0 };
        let now_ms = self.started.elapsed().as_millis() as u64;
        match self.bot.tick(observation, now_ms).status {
            BotStatus::Travelling { path_index } => {
                let target = self.points[path_index];
                let (dx, dy) = (target.x - position[0], target.y - position[1]);
                let length = (dx * dx + dy * dy).sqrt();
                let acceleration = if length > 0.0 {
                    [(dx / length * ACCELERATION) as f32, (dy / length * ACCELERATION) as f32, 0.0]
                } else { [0.0; 3] };
                Step::Move { index: path_index, acceleration }
            }
            status => Step::Done { status },
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parses_points_and_walks_toward_the_first() {
        // Mesh points lie on the floor; the received position is the capsule centre 93 units up.
        let mut travel = Travel::parse("0,0,115 1000,0,115").expect("path");
        assert_eq!(travel.len(), 2);
        // Already inside the first point's radius, so the follower advances to the second.
        match travel.step([10.0, 0.0, 208.0]) {
            Step::Move { index, acceleration } => {
                assert_eq!(index, 1);
                assert!((acceleration[0] - ACCELERATION as f32).abs() < 1e-3 && acceleration[1].abs() < 1e-3);
            }
            other => panic!("{other:?}"),
        }
        assert_eq!(travel.step([900.0, 0.0, 0.0]), Step::Done { status: BotStatus::Arrived });
    }

    #[test]
    fn rejects_malformed_points() {
        assert!(Travel::parse("1,2").is_err());
        assert!(Travel::parse("").is_err());
    }
}
