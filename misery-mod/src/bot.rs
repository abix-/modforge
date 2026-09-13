//! MISERY bot navigation ops: find an Unreal A* path and travel it
//! using only player input (W/A/S/D + relative mouse), through the
//! shared `modforge::route` bot and the wired input surface.
//!
//! Performance (misery-mod/docs/performance.md): one A* call per leg
//! (at the start, and again only if blocked). The travel loop does no
//! object-list search: each tick observes the player (cheap reflected
//! reads) and injects input (cheap ProcessEvent). The subsystem and
//! action pointers are resolved once and cached in `ueforge::input`.

use std::time::{Duration, Instant};

use modforge::route::{Path, PlayerObservation, Position, SteeringConfig};
use serde_json::Value as Json;

const FIND_PATH_TIMEOUT: Duration = Duration::from_secs(10);
const TRAVEL_TIMEOUT: Duration = Duration::from_secs(60);
const TICK_INTERVAL: Duration = Duration::from_millis(80);
const GOAL_ARRIVAL: f64 = 150.0;
const STUCK_MIN_PROGRESS: f64 = 40.0;
const STUCK_AFTER_MS: u64 = 4000;

fn arg_pos(args: &Json) -> Result<Position, String> {
    let f = |k: &str| args.get(k).and_then(Json::as_f64).ok_or(format!("missing arg '{k}'"));
    Ok(Position::new(f("x")?, f("y")?, f("z")?))
}

/// Path from the retained player to `end` via Unreal A*. Game thread.
fn find_path_from_player(end: Position) -> Result<Path, String> {
    let player = crate::speed::PLAYER.retained().ok_or("no retained player")?;
    let world_ctx = player as *const ueforge::ue::UObject as u64;
    // SAFETY: the retained player is live on the game thread.
    let (x, y, z) = unsafe { ueforge::ue::transform::world_location(player.as_ptr() as *const u8) }
        .ok_or("could not read player world location")?;
    ueforge::nav::find_path(world_ctx, Position::new(x, y, z), end)
}

/// Steering tuned from the live mouse calibration: dx = 200 turned the
/// view 180 degrees, so about 1.1 mouse units per degree.
fn steering() -> SteeringConfig {
    SteeringConfig {
        mouse_units_per_degree: 1.1,
        max_mouse_delta: 200,
        move_yaw_tolerance_deg: 12.0,
        path_point_radius: 90.0,
    }
}

// Virtual-key codes for the four movement directions.
const VK_W: u16 = 0x57;
const VK_A: u16 = 0x41;
const VK_S: u16 = 0x53;
const VK_D: u16 = 0x44;

/// Which of W/A/S/D should be held to move toward `target` given the
/// player's current facing. MISERY binds forward/back/left/right as
/// separate actions, so the bot strafes to any point without turning
/// the view (view-turn injection does not drive MISERY's look; see
/// research.md section 31). Returns (w, a, s, d).
fn strafe_keys(pose: PlayerObservation, target: Position, tol: f64) -> (bool, bool, bool, bool) {
    let dx = target.x - pose.position.x;
    let dy = target.y - pose.position.y;
    let len = (dx * dx + dy * dy).sqrt();
    if len < 1e-3 {
        return (false, false, false, false);
    }
    let (tx, ty) = (dx / len, dy / len);
    let yaw = pose.yaw_deg.to_radians();
    // Facing at yaw: (cos, sin) (yaw 90 -> +Y, confirmed live).
    let (fx, fy) = (yaw.cos(), yaw.sin());
    // Right of facing (yaw - 90).
    let (rx, ry) = ((yaw - std::f64::consts::FRAC_PI_2).cos(), (yaw - std::f64::consts::FRAC_PI_2).sin());
    let forward = tx * fx + ty * fy;
    let right = tx * rx + ty * ry;
    (
        forward > tol,
        right < -tol,
        forward < -tol,
        right > tol,
    )
}

/// Only the keys whose held state changed, so continuous injection is
/// started once on press and stopped once on release. Re-sending a key
/// every tick re-starts the injection and it never sustains.
fn key_diff(
    held: (bool, bool, bool, bool),
    want: (bool, bool, bool, bool),
) -> modforge::route::PlayerCommands {
    use modforge::input::{Key, PlayerCommand};
    let mut c = modforge::route::PlayerCommands::new();
    for (vk, h, w) in [
        (VK_W, held.0, want.0),
        (VK_A, held.1, want.1),
        (VK_S, held.2, want.2),
        (VK_D, held.3, want.3),
    ] {
        if h != w {
            c.push(PlayerCommand::key(Key(vk), w));
        }
    }
    c
}

fn travel_to(end: Position) -> Result<Json, String> {
    let surface = modforge::input::input_surface().ok_or("no player input surface registered")?;

    // One A* query for the leg.
    let path = ueforge::game_thread::run(
        move || {
            find_path_from_player(end)
                .and_then(|p| serde_json::to_value(&p).map_err(|e| format!("serialize path: {e}")))
        },
        FIND_PATH_TIMEOUT,
    )?;
    let path: Path = serde_json::from_value(path).map_err(|e| format!("decode path: {e}"))?;
    let points: Vec<Position> = path.points().iter().map(|p| p.position).collect();

    let start = Instant::now();
    let mut idx = 0usize;
    let mut best: Option<f64> = None;
    let mut last_progress = Instant::now();
    let mut trace: Vec<Json> = Vec::new();
    let mut held = (false, false, false, false);

    loop {
        let pose = surface.observe_player()?;
        let final_point = idx + 1 >= points.len();
        let radius = if final_point { GOAL_ARRIVAL } else { steering().path_point_radius };
        let target = points[idx];
        let dist = pose.position.distance(target);

        if dist <= radius {
            idx += 1;
            best = None;
            last_progress = Instant::now();
            if idx >= points.len() {
                surface.commands(&key_diff(held, (false, false, false, false)))?;
                return Ok(serde_json::json!({
                    "status": "arrived",
                    "final": pose.position,
                    "elapsed_ms": start.elapsed().as_millis() as u64,
                    "trace": trace,
                }));
            }
            continue;
        }

        let want = strafe_keys(pose, target, 0.35);
        if trace.len() < 20 {
            trace.push(serde_json::json!({
                "yaw": (pose.yaw_deg * 10.0).round() / 10.0,
                "dist": dist as i64,
                "keys": format!("{}{}{}{}",
                    if want.0 {"W"} else {"-"}, if want.1 {"A"} else {"-"},
                    if want.2 {"S"} else {"-"}, if want.3 {"D"} else {"-"}),
            }));
        }
        surface.commands(&key_diff(held, want))?;
        held = want;

        // Stuck: no meaningful progress toward the current target.
        match best {
            Some(b) if b - dist >= STUCK_MIN_PROGRESS => {
                best = Some(dist);
                last_progress = Instant::now();
            }
            None => {
                best = Some(dist);
                last_progress = Instant::now();
            }
            _ => {}
        }
        if last_progress.elapsed().as_millis() as u64 >= STUCK_AFTER_MS {
            surface.commands(&key_diff(held, (false, false, false, false)))?;
            return Ok(serde_json::json!({
                "status": "stuck", "at": pose.position, "path_index": idx, "trace": trace,
            }));
        }
        if start.elapsed() >= TRAVEL_TIMEOUT {
            surface.commands(&key_diff(held, (false, false, false, false)))?;
            return Ok(serde_json::json!({
                "status": "timeout", "at": pose.position, "path_index": idx, "trace": trace,
            }));
        }
        std::thread::sleep(TICK_INTERVAL);
    }
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new(
            "bot.find_path",
            "Find an Unreal A* path from the player to a point (research)",
            "{x: f64, y: f64, z: f64}",
            |args| {
                let end = arg_pos(args)?;
                ueforge::game_thread::run(
                    move || {
                        let path = find_path_from_player(end)?;
                        Ok(serde_json::json!({
                            "points": path
                                .points()
                                .iter()
                                .map(|p| p.position)
                                .collect::<Vec<_>>(),
                            "count": path.points().len(),
                        }))
                    },
                    FIND_PATH_TIMEOUT,
                )
            },
        ),
        ueforge::ops::OpDef::new(
            "bot.travel_to",
            "Travel to a point using only player input (W/A/S/D + mouse)",
            "{x: f64, y: f64, z: f64}",
            |args| {
                let end = arg_pos(args)?;
                travel_to(end)
            },
        ),
    ]);
}
