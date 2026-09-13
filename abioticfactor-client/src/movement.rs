//! Bounded input through the character's native movement RPC, and the
//! client-side prediction of what that input does to the body.
//!
//! Position authority (see abioticfactor-mod/docs/lan-rpc.md, "Where Sophia
//! is"): the owning client computes its own position from the moves it
//! sends; the server only creates bodies and corrects. So every move sent
//! passes through `step` before it leaves, and the reported position is the
//! predicted one, exactly what the real client reports.
use crate::bits::Writer;

/// Player character movement values read from the live game on 2026-09-13
/// (research_ai_player character_movement_values): MaxWalkSpeed 500,
/// MaxAcceleration 4096, BrakingDecelerationWalking 2048.
pub const MAX_WALK_SPEED: f64 = 500.0;
pub const BRAKING_DECELERATION: f64 = 2048.0;

/// Advance walking velocity by `dt` seconds of `acceleration` the way the
/// character movement component does on flat ground: speed up along the
/// acceleration, capped at walk speed; with no acceleration, brake to a stop.
pub fn step(velocity: [f64; 3], acceleration: [f32; 3], dt: f64) -> [f64; 3] {
    let accel = [f64::from(acceleration[0]), f64::from(acceleration[1])];
    let magnitude = (accel[0] * accel[0] + accel[1] * accel[1]).sqrt();
    if magnitude == 0.0 {
        let speed = (velocity[0] * velocity[0] + velocity[1] * velocity[1]).sqrt();
        let braked = (speed - BRAKING_DECELERATION * dt).max(0.0);
        if speed == 0.0 { return [0.0; 3]; }
        return [velocity[0] / speed * braked, velocity[1] / speed * braked, 0.0];
    }
    let mut next = [velocity[0] + accel[0] * dt, velocity[1] + accel[1] * dt];
    let speed = (next[0] * next[0] + next[1] * next[1]).sqrt();
    if speed > MAX_WALK_SPEED {
        next = [next[0] / speed * MAX_WALK_SPEED, next[1] / speed * MAX_WALK_SPEED];
    }
    [next[0], next[1], 0.0]
}

/// ServerMoveOld takes a timestamp, NetQuantize10 acceleration and flags.
/// The engine validates timestamps and simulates acceleration with MoveAutonomous.
pub(crate) fn input(timestamp: f32, acceleration: [f32; 3]) -> Writer {
    let mut args = Writer::default();
    args.put(1, 1);
    args.put(u64::from(timestamp.to_bits()), 32);
    args.put(1, 1);
    // Packed-vector escape: width zero, float precision, unscaled components.
    args.put(0, 7);
    for value in acceleration { args.put(u64::from(value.to_bits()), 32); }
    args.put(0, 1); // default compressed flags: no jump or crouch
    args
}

/// The move's View parameter: pitch and yaw each compressed to 16 bits
/// (FRotator::CompressAxisToShort, 65536 per turn), pitch in the high half.
/// The server decompresses it into the controller's control rotation, so this
/// is where Sophia faces.
pub fn view(yaw_degrees: f64, pitch_degrees: f64) -> u32 {
    let axis = |degrees: f64| ((degrees.rem_euclid(360.0) * 65536.0 / 360.0).round() as u32) & 0xFFFF;
    (axis(pitch_degrees) << 16) | axis(yaw_degrees)
}

/// Normal move reporting supplies the last server position for error correction
/// and the view the character faces.
pub(crate) fn report(timestamp: f32, acceleration: [f32; 3], position: [f64; 3], view: u32) -> Writer {
    let mut args = Writer::default();
    args.put(1, 1);
    args.put(u64::from(timestamp.to_bits()), 32);
    args.put(1, 1);
    args.put(0, 7);
    for value in acceleration { args.put(u64::from(value.to_bits()), 32); }
    args.put(1, 1);
    args.put(64, 7); // packed-vector double escape
    for value in position { args.put(value.to_bits(), 64); }
    args.put(0, 1); // compressed flags
    args.put(0, 1); // roll
    if view == 0 { args.put(0, 1); } else { args.put(1, 1); args.put(u64::from(view), 32); }
    args.put(1, 1);
    args.put(1, 8); // walking movement mode
    args
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::bits::Reader;

    #[test]
    fn view_compresses_yaw_and_pitch_to_shorts() {
        assert_eq!(view(0.0, 0.0), 0);
        assert_eq!(view(90.0, 0.0), 16384);
        assert_eq!(view(-90.0, 0.0), 49152);
        assert_eq!(view(180.0, 45.0), (8192 << 16) | 32768);
    }

    #[test]
    fn prediction_ramps_to_walk_speed_and_brakes_to_a_stop() {
        let mut velocity = [0.0; 3];
        for _ in 0..30 { velocity = step(velocity, [2048.0, 0.0, 0.0], 1.0 / 30.0); }
        assert!((velocity[0] - MAX_WALK_SPEED).abs() < 1e-9, "{velocity:?}");
        assert_eq!(velocity[1], 0.0);
        for _ in 0..30 { velocity = step(velocity, [0.0; 3], 1.0 / 30.0); }
        assert_eq!(velocity, [0.0; 3]);
    }

    #[test]
    fn movement_parameters_preserve_timestamp_acceleration_and_release() {
        for acceleration in [[2048.0, 0.0, 0.0], [0.0; 3]] {
            let bytes = input(1.25, acceleration).finish();
            let mut read = Reader::packet(&bytes).unwrap();
            assert_eq!(read.get(1).unwrap(), 1);
            assert_eq!(read.get(32).unwrap(), u64::from(1.25f32.to_bits()));
            assert_eq!(read.get(1).unwrap(), 1);
            assert_eq!(read.get(7).unwrap(), 0);
            for value in acceleration { assert_eq!(read.get(32).unwrap(), u64::from(value.to_bits())); }
            assert_eq!(read.get(1).unwrap(), 0);
            assert_eq!(read.remaining(), 0);
        }
    }
}
