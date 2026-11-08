//! World to screen positions, the way GameHelper2 does
//! (GameOffsets/Objects/States/InGameState/WorldDataOffset.cs
//! CameraStructure; RemoteObjects/States/InGameStateObjects
//! WorldData.cs WorldToScreen).
//!
//! The camera sits inside the world data at 0x98 (the same place the
//! area details pointer is read from), and its world to screen matrix
//! 0x108 into it.

use crate::zone::IN_GAME_WORLD_DATA;
use anyhow::{Context, Result, ensure};
use modforge::process_memory::ProcessMemory;

pub const WORLD_DATA_CAMERA: u64 = 0x98;
pub const CAMERA_MATRIX: u64 = 0x108;

/// A row-major 4x4 matrix, laid out like .NET Matrix4x4 (M11, M12, ...).
pub type Matrix = [[f32; 4]; 4];

/// The world to screen matrix from the in-game state.
pub fn matrix(mem: &ProcessMemory, in_game_state: u64) -> Result<Matrix> {
    let world: u64 = mem
        .read_value(in_game_state + IN_GAME_WORLD_DATA)
        .context("read world data pointer")?;
    ensure!(world != 0, "no world data");
    mem.read_value(world + WORLD_DATA_CAMERA + CAMERA_MATRIX)
        .context("read world to screen matrix")
}

/// GameHelper2 WorldToScreen: the point as a row vector times the
/// matrix, divided by w, then scaled to a window of `width` by
/// `height` with y down. None when w is zero (behind the camera plane).
pub fn world_to_screen(
    m: &Matrix,
    x: f32,
    y: f32,
    height: f32,
    size: (f32, f32),
) -> Option<(f32, f32)> {
    let v = [f64::from(x), f64::from(y), f64::from(height), 1.0];
    let mut out = [0f64; 4];
    for (i, o) in out.iter_mut().enumerate() {
        *o = (0..4).map(|j| f64::from(m[j][i]) * v[j]).sum();
    }
    if out[3] == 0.0 {
        return None;
    }
    let (nx, ny) = (out[0] / out[3], out[1] / out[3]);
    let sx = (nx + 1.0) * f64::from(size.0) / 2.0;
    let sy = (1.0 - ny) * f64::from(size.1) / 2.0;
    Some((sx as f32, sy as f32))
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;

    const IDENTITY: Matrix = [
        [1.0, 0.0, 0.0, 0.0],
        [0.0, 1.0, 0.0, 0.0],
        [0.0, 0.0, 1.0, 0.0],
        [0.0, 0.0, 0.0, 1.0],
    ];

    #[test]
    fn center_and_corners_like_gamehelper2() {
        let size = (1920.0, 1080.0);
        assert_eq!(
            world_to_screen(&IDENTITY, 0.0, 0.0, 5.0, size),
            Some((960.0, 540.0))
        );
        // x = 1 is the right edge, y = 1 the top (screen y runs down).
        assert_eq!(
            world_to_screen(&IDENTITY, 1.0, 1.0, 0.0, size),
            Some((1920.0, 0.0))
        );
        assert_eq!(
            world_to_screen(&IDENTITY, -1.0, -1.0, 0.0, size),
            Some((0.0, 1080.0))
        );
    }

    #[test]
    fn row_vector_times_matrix_with_perspective() {
        // Row 3 (the translation row) moves x by 0.5; column 3 makes
        // w = 2, halving everything.
        let mut m = IDENTITY;
        m[3][0] = 0.5;
        m[3][3] = 2.0;
        let (sx, sy) = world_to_screen(&m, 0.5, 0.0, 0.0, (100.0, 100.0)).unwrap();
        assert_eq!((sx, sy), (75.0, 50.0));
        let mut flat = IDENTITY;
        flat[3][3] = 0.0;
        assert_eq!(world_to_screen(&flat, 0.0, 0.0, 0.0, (100.0, 100.0)), None);
    }

    #[test]
    fn reads_the_matrix_from_world_data() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut m = IDENTITY;
        m[3][0] = 7.0;
        let mut world = [0u8; 0x1E0];
        put(&mut world[..], 0x98 + 0x108, m);
        let mut state = [0u8; 0x370];
        put(&mut state[..], 0x368, world.as_ptr() as u64);
        assert_eq!(matrix(&mem, state.as_ptr() as u64).unwrap(), m);
    }
}
