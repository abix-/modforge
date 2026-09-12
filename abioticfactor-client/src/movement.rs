//! Bounded input through the character's native movement RPC.
use crate::bits::Writer;

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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::bits::Reader;

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
